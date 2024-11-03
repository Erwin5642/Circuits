#include "FileManager.h"

FileManager::FileManager(LogicManager &logic_manager) : logicManagerRef(logic_manager){
    fileName.clear();
}
FileManager::~FileManager() {
    fileName.clear();
}
void FileManager::setFileName(const string& name) {
    fileName = name;
}
string FileManager::getFileName() {
    return fileName;
}
void FileManager::readFile() {
    ifstream arquivo(fileName);
    if(arquivo.is_open()) {
        string line;
        while (getline(arquivo, line)) {

        }
    }
    else {
        cerr << "Error opening file " << fileName << endl;
    }
}
void FileManager::writeFile() {
    ofstream arquivo(fileName);
    if(arquivo.is_open()) {
        string line;
        line.clear();
        for(int i=0; i<logicManagerRef.getSize(); i++) {
            line += logicManagerRef.getComponent(i);
        }
    }
    else {
        cerr << "Error opening file " << fileName << endl;
    }
}