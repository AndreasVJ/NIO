#include <iostream>
#include <vector>


// 66/100


struct department {
    int personalaties;
    int leaders;
};


int main() {

    int N, M;
    std::cin >> N >> M;

    std::string S;
    std::cin >> S;

    std::vector<int> compatibility(26, 0b11111111111111111111111111);

    for (int i = 0; i < M; i++) {
        char O, U;
        std::cin >> O >> U;
        compatibility[U - 'A'] -= 1 << (O - 'A');
    }

    std::vector<department> company;

    for (int c : S) {
        
        int personality = 1 << (c - 'A');
        company.push_back({personality, compatibility[c - 'A']});
        
        while (company.size() > 1 && ((company.back().personalaties | company[company.size() - 2].personalaties) & company.back().leaders & company[company.size() - 2].leaders)) {
            company[company.size() - 2].personalaties |= company.back().personalaties;
            company[company.size() - 2].leaders &= company.back().leaders;
            company.pop_back();
        }
    }

    std::cout << company.size();

    return 0;
}