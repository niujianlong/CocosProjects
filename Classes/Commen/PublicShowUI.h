#include "cocos2d.h"  
#include <vector>
using namespace cocos2d;  

class PublicShowUI
{
public:
	PublicShowUI(void);
	~PublicShowUI(void);

	CCLabelTTF* label;
	CCLabelTTF* labelback;
	CCArray* p_ui_talkabout;
	CCArray* p_ui_talkabout_back;
	/** 白底黑边 **/
	void setGameText(CCLayer* layer,CCString* str,CCPoint cp,int size);

	/** 对话内容 **/
	void setGameTalkAbout(CCLayer* layer,CCPoint cp,int size,CCArray *stringArray,int zindex);

	void updataGameText(CCPoint cp);
	void moveGameText(bool endflag,int uestime,CCPoint newpoint);
	//void movetGameTalkAbout(CCLayer* layer,bool endflag,int uestime,CCPoint newpoint);

private:
	  CCActionInterval* act_moveto_label;
	  CCActionInterval* act_moveto_labelback;
};

