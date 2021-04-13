//
//  LeaderboardManager.hpp
//  DungeonRebuild
//
//  Created by Pavel Bibichenko on 24/05/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef LeaderboardManager_hpp
#define LeaderboardManager_hpp

#include <iostream>
#include <fstream>

extern const char* workingDirectory;

class LeaderboardManager {
public:
    struct Save {
        char name[20];
        int hours;
        int minutes;
        int rupies;
    };
    
    static Save *createFile(const char* name) {
        Save scores[10];
        
        Save newSave;
        for (int i=0; i<20; i++)
            newSave.name[i] = 0;
        newSave.name[0] = 0;
        newSave.rupies = 0;
        newSave.hours = 0;
        newSave.minutes = 0;
        
        for (int i=0; i<10; i++)
            scores[i] = newSave;
        
        char *fullPath = new char[255];
        strcpy(fullPath, workingDirectory);
        strcat(fullPath, "/Resources/Assets/Settings/");
        strcat(fullPath, name);
        strcat(fullPath, ".erh");
        
        std::cout << "[LeaderboardManager] Create leaderboard file " << name << std::endl;
        
        std::ofstream saveFile(fullPath, std::ios::binary);
        
        std::cout << "WRITE:\n";
        for (int i=0; i<10; i++) {
            std::cout << "[" << i << "]: " << scores[i].name << " : " << scores[i].hours << "/" << scores[i].minutes << " () " << scores[i].rupies << std::endl;
            saveFile.write((char *)&newSave, sizeof(Save));
        }
        
        saveFile.close();
        
        return nullptr;
        //return scores[0];
    }
    
    static Save *loadFile(const char* name) {
        Save *scores = new Save[10];
        Save tmpSave;
        
        char *fullPath = new char[255];
        strcpy(fullPath, workingDirectory);
        strcat(fullPath, "/Resources/Assets/Settings/");
        strcat(fullPath, name);
        strcat(fullPath, ".erh");
        
        std::cout << "[LeaderboardManager] Loading leaderboard file " << name << std::endl;
        
        //createFile("leaders");
        
        std::ifstream saveFile(fullPath, std::ios::binary);
        if (!(saveFile.is_open())) {
            createFile(name);
            saveFile.open(fullPath, std::ios::binary);
        }
        
        std::cout << "READ:\n";
        for (int i=0; i<10; i++) {
            saveFile.read((char*)&tmpSave, sizeof(tmpSave));
            scores[i] = tmpSave;
            std::cout << "[" << i << "]: " << tmpSave.name << " : " << tmpSave.hours << "/" << tmpSave.minutes << " () " << tmpSave.rupies << std::endl;
        }
        
        saveFile.close();
        
        return scores;
    }
    
    static void addScore(Save save) {
        Save *scores = loadFile("leaders");
        Save *newScores = new Save[10];
        
        char *fullPath = new char[255];
        strcpy(fullPath, workingDirectory);
        strcat(fullPath, "/Resources/Assets/Settings/");
        strcat(fullPath, "leaders");
        strcat(fullPath, ".erh");
        
        std::cout << "[LeaderboardManager] Adding to leaderboard file " << "leaders" << std::endl;
        
        std::ofstream saveFile(fullPath, std::ios::binary);
        
        bool saveInserted = false;
        for (int i=0, count=0; i<9; i++) {
            if (scores[i].rupies > save.rupies && !saveInserted) {
                newScores[count] = scores[i];
                count++;
            } else if (scores[i].rupies <= save.rupies && !saveInserted) {
                std::cout << "There.";
                
                newScores[count] = save;
                count++;
                i--;
                saveInserted = true;
            } else {
                if (count <= 9) {
                    newScores[count] = scores[i];
                    count++;
                }
            }
        }
        
        std::cout << "WRITE:\n";
        for (int i=0; i<10; i++) {
            saveFile.write((char *)(&newScores[i]), sizeof(Save));
            std::cout << "[" << i << "]: " << newScores[i].name << " : " << newScores[i].hours << "/" << newScores[i].minutes << " () " << newScores[i].rupies << std::endl;
        }
            
        saveFile.close();
    }
    
    static void print() {
        Save *scores = loadFile("leaders");
        
        char *fullPath = new char[255];
        strcpy(fullPath, workingDirectory);
        strcat(fullPath, "/Resources/Assets/Settings/");
        strcat(fullPath, "leaders");
        strcat(fullPath, ".txt");
        
        std::ofstream out(fullPath);
        
        for (int i=0; i<10; i++) {
            out << scores[i].name;
            out << " - ";
            out << scores[i].hours;
            out << ":";
            out << scores[i].minutes;
            out << " / ";
            out << scores[i].rupies;
            out << "\n";
        }
        
        out.close();
    }
};
#endif /* LeaderboardManager_hpp */
