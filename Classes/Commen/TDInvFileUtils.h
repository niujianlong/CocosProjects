#include <iostream>  
#include "cocos2d.h"  
using namespace cocos2d;  
using namespace std;  
/** ��������ļ�����Ͷ�ȡ 
 */  
  
class TDInvFileUtils {  
public:  
    /** ��ȡ�����ļ����������� */  
    static string getFileByName(string pFileName);  
      
    /** �������ݵ��ļ� */  
    static bool saveFile(char* pContent,string pFileName);  
      


};  
  

