#include <iostream>
#include <vector>
#include <queue>


// 43/100 score


int main() {

    int N, M, I, S;
    std::cin >> N >> M >> I >> S;

    struct meeting {
        int person1;
        int person2;
        int day;
        bool operator()(meeting& a, meeting& b) {
            return a.day > b.day;
        }
    };

    std::priority_queue<meeting, std::vector<meeting>, meeting> meetings;

    for (int i = 0; i < M; i++) {
        meeting inp;
        std::cin >> inp.person1 >> inp.person2 >> inp.day;
        meetings.push(inp);
    }


    int maxSickPeople = 0; 
    int currentSickPeople = 0; 

    std::vector<bool> incubating(N, false);
    std::vector<bool> sick(N, false);
    std::vector<bool> immune(N, false);

    struct event {
        int person;
        int day;
        bool operator()(event& a, event& b) {
            return a.day > b.day;
        }
    };

    std::priority_queue<event, std::vector<event>, event> incubatingQueue;
    std::priority_queue<event, std::vector<event>, event> sickQueue;

    incubatingQueue.push({0, I});
    meetings.push({0, 0, 2147483647});

    while (!meetings.empty() || !incubatingQueue.empty()) {

        int person1 = meetings.top().person1;
        int person2 = meetings.top().person2;
        int day = meetings.top().day;

        while (!incubatingQueue.empty() && incubatingQueue.top().day <= day) {

            while (!sickQueue.empty() && sickQueue.top().day <= incubatingQueue.top().day) {
                
                immune[sickQueue.top().person] = true;
                sick[sickQueue.top().person] = false;

                currentSickPeople--;
                sickQueue.pop();
            }

            sick[incubatingQueue.top().person] = true;
            sickQueue.push({incubatingQueue.top().person, incubatingQueue.top().day + S});

            currentSickPeople++;
            maxSickPeople = std::max(maxSickPeople, currentSickPeople);

            incubating[incubatingQueue.top().person] = false;
            incubatingQueue.pop();
        }

        if (sick[person1] && !incubating[person2] && !sick[person2] && !immune[person2]) {
            incubatingQueue.push({person2, day + I});
            incubating[person2] = true;
        }
        else if (sick[person2] && !incubating[person1] && !sick[person1] && !immune[person1]) {
            incubatingQueue.push({person1, day + I});
            incubating[person1] = true;
        }

        meetings.pop();
    }

    std::cout << maxSickPeople;

    return 0;
}