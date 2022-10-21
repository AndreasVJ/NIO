#include <iostream>
#include <vector>
#include <queue>

//----------------------------------------------------------------
// Not correct output

int main() {

    int N, M, I, S;
    std::cin >> N >> M >> I >> S;

    int lastMeetingDay;
    int maxSickPeople = 0; 

    std::vector<bool> incubating(N, false);
    std::vector<bool> sick(N, false);
    std::vector<bool> immune(N, false);

    std::queue<int> infections;

    std::queue<std::pair<int, int>> incubatingQueue;
    std::queue<std::pair<int, int>> sickQueue;

    incubatingQueue.push({0, 0});
    infections.push(I);

    for (int i = 0; i < M; i++) {
        int A, B, D;
        std::cin >> A >> B >> D;

        // Make people done incubating sick
        while (D - incubatingQueue.front().second >= I && !incubatingQueue.empty()) {

            incubating[incubatingQueue.front().first] = false;
            sick[incubatingQueue.front().first] = true;
            sickQueue.push({incubatingQueue.front().first, incubatingQueue.front().second + I});

            std::cout << "sick " << incubatingQueue.front().first << std::endl;

            incubatingQueue.pop();
        }

        // Check if people have become healthy
        while (D - sickQueue.front().second >= S && !sickQueue.empty()) {
            sick[sickQueue.front().first] = false;
            immune[sickQueue.front().first] = true;
            std::cout << "healthy " << sickQueue.front().first << std::endl;
            sickQueue.pop();
        }

        // Check if someone gets infected from meeting
        if (!immune[A] && !immune[B]) {
            if (sick[A] && (!sick[B] || !incubating[B])) {
                incubatingQueue.push({B, D});
                infections.push({D + I});
                std::cout << "infect " << D << std::endl;
            }
            else if (sick[B] && (!sick[A] || !incubating[A])) {
                incubatingQueue.push({A, D});
                infections.push({D + I});
                std::cout << "infect " << D << std::endl;
            }
        }

        if (i == M-1) {
            lastMeetingDay = D;
        }
    }

    std::vector<int> day(lastMeetingDay + I + S, 0);

    while (!infections.empty()) {
        for (int i = 0; i < S; i++) {
            day[infections.front() + i]++;
        }
        infections.pop();
    }

    for (int i = 0; i < lastMeetingDay + I + S; i++) {
        std::cout << day[i] << " " << i << std::endl;
        if (day[i] > maxSickPeople) {
            maxSickPeople = day[i];
        }
    }

    std::cout << maxSickPeople << std::endl;

    return 0;
}