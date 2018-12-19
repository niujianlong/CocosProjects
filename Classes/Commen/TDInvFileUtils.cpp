#include "TDInvFileUtils.h"

string TDInvFileUtils::getFileByName(string pFileName){  
    //��һ�Ȼ�ȡ�ļ���·��  
	string path = CCFileUtils::sharedFileUtils()->getWritablePath() + pFileName;  
    log("path = %s",path.c_str());  
      
    //����һ���ļ�ָ��   
    FILE* file = fopen(path.c_str(), "r");  
      
    if (file) {  
        char* buf;  //Ҫ��ȡ���ַ���  
        int len;    //��ȡ�ĳ���  
        /*��ȡ����*/  
        fseek(file, 0, SEEK_END);   //�Ƶ�β��  
        len = ftell(file);          //��ȡ����  
        rewind(file);               //�ع�ԭλ  
        log("count the file content len = %d",len);  
        //����buf�ռ�  
        buf = (char*)malloc(sizeof(char) * len + 1);  
        if (!buf) {  
            log("malloc space is not enough.");  
            return NULL;  
        }  
          
        //��ȡ�ļ�  
        //��ȡ����buf����λ��С�����ȣ��ļ�ָ��  
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
    //��һ��ȡ������ļ�·��  
    string path = CCFileUtils::sharedFileUtils()->getWritablePath() + pFileName;  
    log("wanna save file path = %s",path.c_str());  
      
    //����һ���ļ�ָ��  
    //·����ģʽ  
    FILE* file = fopen(path.c_str(), "w");  
    if (file) {  
        fputs(pContent, file);  
        fclose(file);  
    }  
    else  
        log("save file error.");  
      
    return false;  
}  

