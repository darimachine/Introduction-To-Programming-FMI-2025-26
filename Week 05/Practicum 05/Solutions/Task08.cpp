#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int maxEndTime = 0; // will store the latest ending time in minutes

    for (int i = 0; i < n; i++) {
        int hour, minute, duration;
        std::cin >> hour >> minute >> duration;

        int startTime = hour * 60 + minute; // convert start time to minutes
        int endTime = startTime + duration; // calculate end time in minutes

        // update maxEndTime if this show ends later
        if (endTime > maxEndTime) {
            maxEndTime = endTime;
        }
    }

    // convert the latest ending time back to hours and minutes
    int endHour = maxEndTime / 60;
    int endMinute = maxEndTime % 60;

    std::cout << endHour << " " << endMinute << std::endl;

    return 0;
}
