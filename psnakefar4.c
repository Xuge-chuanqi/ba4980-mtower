#include 	"inc\dictsys.h"
#include	"mtower.h"


extern U8	g_GameMTNearEnd,g_GameMTDeadLine,g_GameMTEnd,g_GameMTGameOver,g_GameMTInit,g_GameMTQuit;
extern U8	g_GameMTReadKey,g_GameMTTimeOut,g_GameMTTopFloor,g_GameMTHeroLv,g_GameMTCurTime;
extern U16	g_GameMTKBState;
extern U8	g_GameMTMapX,g_GameMTMapY,g_GameMTHeroX,g_GameMTHeroY,g_GameMTJuidgeX,g_GameMTJuidgeY;
extern U8	g_GameMTBuf[1920],g_GameMTKey[3],g_GameMTCheck[7];
extern U16	g_GameMTHeroDamige,g_GameMTHeroDefence,g_GameMTHeroMoney,g_GameMTHeroExp;
extern U8	g_GameMTHeroDir,g_GameMTFloor,*g_GameMTCurMap;
extern U32 g_GameMTHeroLife;
extern U8	*g_GameMTJuidgeNow;

extern	U8	GameMTUnitPic[][32];
extern	U8	GameMTWorkPad[];
extern	U8	GameMTTalkData[][20];
extern	U8	GameMTTalkSide[];
extern	U8	GameMTTalkDown[];
extern	U8	GameMTTalkUp[];
extern	U8	GameMTTalkSigh[][26];
extern	U8	GameMTHeroPic[][32];
extern	U8	GameMTNum39[];
extern	U8	GameMTNum35[];
extern	U8	GameMTNum78[];
extern	U8	GameMTCeng[];
extern	U8	GameMTDi[];
extern	U8	GameMTLiKai[];
extern	U8	GameMTBattlePad[];
extern	U8	GameMTChar[][20];
extern	U8	GameMTNotice[];
extern	U16	GameMTMonData[][5];
extern	U8	GameMTVictory[];
extern	U8	GameMTStartPoint[][4];
extern	U8	GameMTUnknown[];
extern	U8	GameMTMonName[];
extern	U8	GameMTMainFace[];
extern	U8	GameMTHappyEnd[];
extern	U8	GameMTEagle[];




/***********************************************************************
 * 函数名:	GameMTEventEx()
 * 说明:		游戏事件处理主函数附加
 * 输入参数:	无
 * 返回值  :	无
 * 修改历史:
 *              姓名              日期             说明
 *             ------          ----------      -------------
 *             旭哥传奇           2026.3.4        完成基本功能
***********************************************************************/
FAR void	GameMTEventEx()
{
    

		U8	temp[20];
		U8	*g_GameMTJuidgeNow;
		GameMTGetInput();
		if(g_GameMTQuit)return;

		g_GameMTJuidgeNow=&g_GameMTCurMap[(U16)g_GameMTFloor*121+g_GameMTJuidgeY*11+g_GameMTJuidgeX];
		switch(*g_GameMTJuidgeNow)
		{
			
                                               case	72:                   /*增加旭哥的事件=====可用*/

                                                               GameMTTalk(3, 500, 0);
                                                               GameMTTalk(2, 503, 0);
                                                              *g_GameMTJuidgeNow = 0;
                                                               GameMTxu(1);
                                                             /*  g_GameMTCurMap[180]=0;
                                                               g_GameMTCurMap[182]=0;*/
                                                               
                                                               
                                                                break;

			default:
					GameMTMove();
		}
		GameMTRefresh();
		/*if(g_GameMTReadKey!=16)GameMTRefresh();*/
			   
			
}


/***********************************************************************
 * 函数名:	GameMTxu(U8 kind)
 * 说明:		各种商店购买函数
 * 输入参数:	无 
 * 返回值  :	无
 * 修改历史:
 *              姓名              日期             说明
 *             ------          ----------      -------------
 *             旭哥传奇           2026.3.6        完成基本功能
***********************************************************************/
FAR	void GameMTxu(U8 kind)/*旭哥*/
{
	U8	choice,temp[20],flag;
	choice=0;
	switch(kind)
	{
		case 1:
		
	}
	SysSaveScreen(0,5,158,89,g_GameMTBuf);
	SysLcdPartClear(0,5,158,89);
	SysRect(0,5,158,89);
	SysRect(2,7,156,87);
	switch(kind)
	{
		
		case 1:   /*旭哥*/
			GameMTGetTalk(505,temp);SysPrintString(6,11,temp);
			GameMTGetTalk(506,temp);SysPrintString(6,30,temp);
			GameMTGetTalk(507,temp);SysPrintString(6,49,temp);
	}
	GameMTGetTalk(454,temp);SysPrintString(6,68,temp);
	SysRect(4,9,154,28);
	while(1)
	{
		GameMTGetInput();if(g_GameMTQuit)break;

		if(g_GameMTReadKey==16)continue;
		if(g_GameMTReadKey==7)break;

		if(g_GameMTReadKey==3&&choice+1>1)
		{
			SysRectClear(4,9+choice*19,154,28+choice*19);
			choice--;
			SysRect(4,9+choice*19,154,28+choice*19);
		}
		if(g_GameMTReadKey==4&&choice<3)
		{
			SysRectClear(4,9+choice*19,154,28+choice*19);
			choice++;
			SysRect(4,9+choice*19,154,28+choice*19);
		}
		if(g_GameMTReadKey==6)
		{
			flag=0;
			if(choice+1==1)
			{
				switch(kind)
				{
					
					case 1:   /*旭哥*/

							g_GameMTCurMap[180]=0;
							flag=1;
                                                                                            

				}
			}
			if(choice==1)
			{
				switch(kind)
				{
					
					case 1:   /*旭哥*/

							g_GameMTCurMap[182]=0;
							flag=2;
                                                                                            
				}
			}
			if(choice==2)
			{
				switch(kind)
				{
					
					case 1:   /*旭哥*/
							g_GameMTCurMap[180]=0;
							g_GameMTCurMap[182]=0;
							flag=3;
                                                                                            
				}
			}
			if(choice==3)break;
			switch(flag)
			{
				
				case 1:
					SysMemcpy(temp," 攻击之门打开!\0",14);
					GuiMsgBox(temp,50);
					break;
				case 2:
					SysMemcpy(temp," 防御之门打开!\0",14);
					GuiMsgBox(temp,50);
					break;
				case 3:
					SysMemcpy(temp,"   攻防门皆开!\0",14);
					GuiMsgBox(temp,50);
					break;
			}
                                                if(flag == 1 || flag == 2 || flag == 3)
                                                {
                                                SysMemcpy(temp,"   旭哥：拜拜!\0",14);
			GuiMsgBox(temp,50);
                                                break; 
                                                }
		}
	}
                SysMemcpy(temp,"   旭哥：拜拜!\0",14);
	GuiMsgBox(temp,50);
	SysRestoreScreen(0,5,158,89,g_GameMTBuf);
	GameMTReNewR();
}

/***********************************************************************
 * 函数名:	GameMTGetMapData()
 * 说明:		将地图数据装入内存
 * 输入参数:	无 
 * 返回值  :	无
 * 修改历史:
 *              姓名              日期             说明
 *             ------          ----------      -------------
 *             罗博明           2005.1.25        完成基本功能
***********************************************************************/
FAR void GameMTGetMapData()
{
	SysMemcpy(g_GameMTCurMap,"32222,2222332222(2222332222(2222332222(2222332222(2222332222(2222333222(2223333333)33333m3m3(8(3m3mmmmmm(mmmmmmmmmm(mmmmm22223,322222???3(3>>>22???3(3>>>22???3(3>>>22???3(3>>>22???npn>>>22???3(3>>>22???3(3>>>22???3(3>>>22???3(3>>>222223132222,(IkQk(((((3333333333(E([)(3EIE3(I[?3(3EIE3(3)33(333U3(I2(3()jki3(>(J3(33333(3)33((((((((2(33+333)3E9I3K((3IeJE@I3(1(3III13(X(3?>IK3(3>393?>IJ3(3I3I3?>IY3(3I3I3333)3(3(3((()((3(3)33)33)33(n((((3(Y(((3)33*30303(3I39E3(3(3(3I39E3(3(3,3?39E37363CQI3/.-3333QI(3(((3(i(I[(33)33(3(3)33([(3I3Q(((333(3I3ik3(iQi(3I3Qk33333(((3((((((33)33(3333i3Q(Q3(3((((3>iI3(1(3333?9I3,(U(3(5(3(U()3)3(((3)3)(3(33033(3((3[3PhP3[3(i3E3>P>3E3ii3E33+33E3iQ3E3eOe3E3Q(3(3?e?3(3((3(33*33(3((3(3I(I3(3(,3(U(((U(31L3E39j((jIJ(3?3j((((jIP3(32(33)33()j3B23(e26P3(3333(((2?3(((i[((((>33U3333((((73U3(((eO(333i3)3*3)3((3(3i3>)(31(i(((3I3,3DZ3>3ITo399ZI3?3(IT3d9Ih*(*h(I3(d((3O3(((3f(333+33333)3((R(III(R(((3333333333(3P)P(((((3(3)3)3333*3(3P3((33((3(((3,())(13,(((((((33333(h3*3Z(333(h>3N3?Z(3((3330333((((*N0H0N*(((333303333((3E?3N3>E3((3IE3*3EI3((33JJ9JJ33(((333+333((3(()1(()((313((((3(IZ((3(33)3)33((3(3((*((3?(3(3_333P3UP3(3E3,((3Uh3>3E33333(P3U3(((3(h((3U333O3)33(3(Z(3Z3((((333)3(333(((_((3(TNT(:I(333(((3(I(f)(((3()Z3)33(333(3I(((3(3(((3I(((+(313(3E3*33(333(33>V?3_3,3(3E3)33((()(3IZEZ33*33(3I*ZE3d_d3()Z<*Z)9d93(3((33>f3f?33(((33)3)33(d(((((3(((d9(3(33333(33P3((III((3Ih3(3333)33IP3(0(13()h((333333)33((3E>?3(h(3I(3E>?+_3_3I,3E>?3J3J3EE3I3J3K39;9E3I3J3K3OOOE3I3J3K3(O()3)3)3)33*3(((((3((((()33*333*33)>3(b9g9b(3?>3f33333f3?>3f3/.-3f3?33+3E(E3+331(((((((((,6>3(YXY(39G?(3(3)3(3(9((3(3X3(3(((g3(3I3(3^(gc3(3I3(3]^3*3(3E3(3*3((((3E3((((333(333(333>g)ccScc)g?33333*33333,(((((((((1(g(((((3(c((33333)3(3((3((b((3(3(93+333(3(3(Y3((c3b3?3(X3(`03S3?3(Y3c073b3?3>(33333(3(3>(Y(3(((c(3>33(3933333(1((*(,3M`)(3(^L,(((((33(9333339(33(3333333(33(333A333(33(3330333(33(E33c33E(33(223`322(33(223c322(33(223*322(33bSb*(*bSb333333133333((((12,(((((222222222((223333322((233736332((233>3>332((233?3?332((223(3(322((223)3)322((222(((222((2222+2222((((((((((((22222(1222222222(2222222222(2222222223+3222222233(3322222233W3322222233(3322222233,332222222333222222222222222222222222222^`(((((((^2`22222222(2(2^((((((^2(2(22222222(2(2^(((^22(2^((222(22(22222^(^22`22212(2222^`(l(2^((^2222222222(,(l(((((((^22222222222222222222222222222222222223332222222334332222223303322222233+3322222223+3222222222222222222222222221((((((((((((((((((((((2(22222(2((2(22222(2((2(22,22(2((2(22(22(2((2W22(22W2((2022a2202((2F22(22=2((2222(2222((2222(2222(((((((((((1l?NE`K`EN?l92I2J2J2I292>N(^(^(N>2E2I2(1(2I2E`J^(((((^J`K2(2(2(2(2K`J^(((((^J`E2I2(,(2I2E2>N(^(^(N>292I2J2J2I29l?NE`K`EN?l2222222222222(42a25(222((22]22((22(((2]2(((222(((((((2222(((((((22222((2((2222222n1n2222222222222222222222222222222222222",2783);
	g_GameMTCurMap[298]=92;
	g_GameMTCurMap[331]=92;
	g_GameMTCurMap[752]=92;
	g_GameMTCurMap[764]=92;
	g_GameMTCurMap[768]=92;
	g_GameMTCurMap[780]=92;
}


