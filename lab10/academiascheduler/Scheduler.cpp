//
// Created by Piotrek on 20.05.2017.
//

#include <algorithm>
#include <iostream>
#include "Scheduler.h"

namespace academia {
    bool Contains(std::vector<int> v, int val) {
        return std::find(v.begin(), v.end(), val) != v.end();
    }

    SchedulingItem::SchedulingItem(int course, int teacher, int room, int time_slot, int year) {
        course_id_ = course;
        teacher_id_ = teacher;
        room_id_ = room;
        time_slot_ = time_slot;
        year_ = year;
    }

    void Schedule::InsertScheduleItem(SchedulingItem s) {
        int i = 0;
        while (i < schedule_.size()) {
            if (schedule_[i].TimeSlot() > s.TimeSlot())
                break;
            i++;
        }
        schedule_.insert(i + schedule_.begin(), s);
    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule ret;
        for (auto scheduleItem: schedule_) {
            if (scheduleItem.TeacherId() == teacher_id)
                ret.InsertScheduleItem(scheduleItem);
        }
        return ret;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule ret;
        for (auto scheduleItem: schedule_) {
            if (scheduleItem.RoomId() == room_id)
                ret.InsertScheduleItem(scheduleItem);
        }
        return ret;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule ret;
        for (auto scheduleItem: schedule_) {
            if (scheduleItem.Year() == year)
                ret.InsertScheduleItem(scheduleItem);
        }
        return ret;
    }


    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> notAvailable;
        for (auto scheduleItem: schedule_)
            notAvailable.emplace_back(scheduleItem.TimeSlot());
        std::vector<int> result;
        for (int i = 1; i <= n_time_slots; i++) {
            if (!Contains(notAvailable, i))
                result.emplace_back(i);
        }
        return result;
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        Schedule ret;
        std::map<int, std::vector<int>> teachersDB = teacher_courses_assignment;
        unsigned long MaximumSize;
        unsigned long Size = teacher_courses_assignment.size();
        std::vector<std::pair<int, std::vector<int>>> teachersDataBase;
        std::map<int, std::vector<int>>::iterator biggest;
        for (unsigned long i = 0; i < Size; i++) {
            MaximumSize = 0;
            for (auto j = teachersDB.begin(); j != teachersDB.end(); j++) {
                if (j->second.size() > MaximumSize) {
                    MaximumSize = j->second.size();
                    biggest = j;
                }
            }
            teachersDataBase.push_back(std::make_pair(biggest->first, biggest->second));
            teachersDB.erase(biggest);
        }

        bool noRooms, skipTeacher;
        for (int currentTime = 1; currentTime <= n_time_slots; currentTime++) {
            std::map<int, std::set<int>> remainingCourses = courses_of_year;
            std::vector<int> availableRooms = rooms;
            noRooms = false;
            for (auto teacher = teachersDataBase.begin(); teacher != teachersDataBase.end(); teacher++) {
                std::vector<int> teacherCourses = teacher->second;
                skipTeacher = false;
                int i = 0;
                for (int courseId: teacherCourses) {
                    for (auto course = remainingCourses.begin(); course != remainingCourses.end(); course++) {
                        std::set<int>::iterator isMatching = course->second.find(courseId);
                        if (isMatching != course->second.end()) {
                            if (availableRooms.size() > 0) {
                                ret.InsertScheduleItem(
                                        SchedulingItem(courseId, teacher->first, availableRooms[0], currentTime,
                                                       course->first));
                                availableRooms.erase(availableRooms.begin());
                                remainingCourses.erase(course);
                                teacher->second.erase(teacher->second.begin() + i);
                                skipTeacher = true;
                            } else
                                noRooms = true;
                            break;
                        }
                    }
                    if (noRooms || skipTeacher)
                        break;
                    i++;
                }
                if (noRooms)
                    break;
            }
        }
        bool left = false;
        for (auto i = teachersDataBase.begin(); i != teachersDataBase.end(); i++) {
            if (i->second.size() > 0) {
                left = true;
                break;
            }
        }
        if (left)
            throw NoViableSolutionFound("No viable solution found");
        return ret;
    }
}