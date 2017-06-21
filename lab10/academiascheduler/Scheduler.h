//
// Created by Piotrek on 20.05.2017.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H


#include <stdexcept>
#include <vector>
#include <set>
#include <map>

namespace academia {

    class Schedule;
    class Scheduler;
    class GreedyScheduler;

    class SchedulingItem{
    public:
        SchedulingItem() {};
        SchedulingItem(int course,int teacher,int room, int time_slot, int year);
        int CourseId() const {return course_id_;}
        int TeacherId() const {return teacher_id_;}
        int RoomId() const {return room_id_;}
        int TimeSlot() const {return time_slot_;}
        int Year() const {return year_;}

    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;
    };

    class Schedule{
    public:
        Schedule(){}
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(SchedulingItem s);
        size_t Size() const { return schedule_.size(); };
        SchedulingItem operator[](int i) const { return schedule_[i]; };

    private:
        std::vector<SchedulingItem> schedule_;

    };

    class Scheduler{
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                            const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                            const std::map<int, std::set<int>> &courses_of_year,
                                            int n_time_slots) =0;
    };

    class GreedyScheduler: public Scheduler {
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year,
                                    int n_time_slots) override ;
    };

    class NoViableSolutionFound: public std::runtime_error{
    public:
        NoViableSolutionFound(std::string s):std::runtime_error(s){}
    };
}


#endif //JIMP_EXERCISES_SCHEDULER_H
