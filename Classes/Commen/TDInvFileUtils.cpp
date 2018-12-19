#include "TDInvFileUtils.h"

string TDInvFileUtils::getFileByName(string pFileName){  
    //第一先获取文件的路径  
	string path = CCFileUtils::sharedFileUtils()->getWritablePath() + pFileName;  
    log("path = %s",path.c_str());  
      
    //创建一个文件指针   
    FILE* file = fopen(path.c_str(), "r");  
      
    if (file) {  
        char* buf;  //要获取的字符串  
        int len;    //获取的长度  
        /*获取长度*/  
        fseek(file, 0, SEEK_END);   //移到尾部  
        len = ftell(file);          //提取长度  
        rewind(file);               //回归原位  
        log("count the file content len = %d",len);  
        //分配buf空间  
        buf = (char*)malloc(sizeof(char) * len + 1);  
        if (!buf) {  
            log("malloc space is not enough.");  
            return NULL;  
        }  
          
        //读取文件  
        //读取进的buf，单位大小，长度，文件指针  
        int rLen = fread(buf, sizeof(char), len, file);  
        buf[rLen] = '\0';  
        log("has read Length = %d",rLen);  
        log("has read content = %s",buf);  
          
        string result = buf;  
        fclose(file);  
        free(buf);  
        return result;  
    }  
    else  
        log("open file error.");  
      
    return NULL;  
}  
  
bool TDInvFileUtils::saveFile(char *pContent, string pFileName){  
    //第一获取储存的文件路径  
    string path = CCFileUtils::sharedFileUtils()->getWritablePath() + pFileName;  
    log("wanna save file path = %s",path.c_str());  
      
    //创建一个文件指针  
    //路径、模式  
    FILE* file = fopen(path.c_str(), "w");  
    if (file) {  
        fputs(pContent, file);  
        fclose(file);  
    }  
    else  
        log("save file error.");  
      
    return false;  
}  

