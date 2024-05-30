#include<iostream>
#include <Windows.h>
#include<vector>
#include<fstream>
#include<algorithm>
#include"queue.h"

using namespace std;

int main() {
    queue a1(9, 3, 30);
    int Nofpackets[120], ni, NI, no, NO, k = 10, lost = 0, capacity, a = 0, lossRate = 0;
    float averageQueue, fullnessQueue[120];
    NI = a1.NI;
    NO = a1.NO;
    capacity = a1.capacity;
    vector<int> packetQueue; // 패킷을 담는 큐 벡터
    cout << " RANDMAX  " << RAND_MAX << endl;
    packetQueue.reserve(30);
    for (int i = 0; i < 120; i++) {
        ni = rand() % NI;//0-8
        for (int j = 0; j < ni; j++) { // 들어오는 패킷 생성
            if (packetQueue.size() < capacity) {
                packetQueue.push_back(rand() % 10);
                cout << packetQueue[packetQueue.size() - 1] << " in " << packetQueue.size() << endl;
            }
        }
        no = rand() % NO;
        for (int j = 0; j < no; j++) { // 나가는 패킷 처리
            if (!packetQueue.empty()) {
                int packet = packetQueue[0];
                cout << packet << " out " << packetQueue.size() << endl;
                packetQueue.erase(packetQueue.begin());
            }
        }
        Nofpackets[i] = packetQueue.size(); // 큐 크기 저장

        // 매 초마다 queue에 저장된 패킷 개수 출력
        Sleep(1000); // 1초 대기
        cout << "Queue에 저장된 패킷 개수: " << packetQueue.size() << endl;
        a += Nofpackets[i];
        fullnessQueue[i] = packetQueue.size() * 100 / capacity;
        if (packetQueue.size() > capacity) {
            int overflow_packets = packetQueue.size() - capacity;
            lossRate += overflow_packets;
        }
    }
    averageQueue = a / 120;
    cout << " Queue에 저장된 패킷 개수의 평균: " << averageQueue << endl;
    int max = *max_element(begin(Nofpackets), end(Nofpackets));
    cout << " Queue에 저장된 패킷 개수의 최고치: " << max << endl;
    cout << " 오버플로우로 버려진 패킷 개수: " << lossRate << endl;

    ofstream zz("개수.txt", ios::binary | ios::out);
    if (!zz) return 666;
    for (int i = 0; i < 120; i++) {
        zz << Nofpackets[i] << endl;
    }
    zz.close();
    ofstream xx("충족.txt", ios::binary | ios::out);
    if (!xx) return 333;
    for (int i = 0; i < 120; i++) {
        xx << fullnessQueue[i] << endl;
    }
    xx.close();

    return 0; // 프로그램 종료
}
