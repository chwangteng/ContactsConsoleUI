#ifndef _COLOR_H_
#define _COLOR_H_
//������ɫ
#define Bwhite_Dblue    FOREGROUND_RED|\
						FOREGROUND_GREEN|\
						FOREGROUND_BLUE|		BACKGROUND_BLUE|\
						FOREGROUND_INTENSITY						               //�����֣�������

#define Bwhite_Bblue    FOREGROUND_RED|\
						FOREGROUND_GREEN|\
						FOREGROUND_BLUE|        BACKGROUND_BLUE|\
						FOREGROUND_INTENSITY|	BACKGROUND_INTENSITY			   //�����֣�������

#define Bwhite_Bred     FOREGROUND_RED|         BACKGROUND_RED|\
						FOREGROUND_GREEN|\
						FOREGROUND_BLUE|\
						FOREGROUND_INTENSITY|	BACKGROUND_INTENSITY			   //�����֣������

#define Dgreen_Dwhite                           BACKGROUND_RED|\
						FOREGROUND_GREEN|       BACKGROUND_GREEN|\
						                        BACKGROUND_BLUE                    //�����֣����׵�

#define Bwhite_Dgreen   FOREGROUND_RED|\
						FOREGROUND_GREEN |     BACKGROUND_GREEN | \
					    FOREGROUND_BLUE|\
						FOREGROUND_INTENSITY			                           //�����֣����̵�

#define Bred_Bwhite     FOREGROUND_RED|         BACKGROUND_RED|\
						                        BACKGROUND_GREEN|\
						                        BACKGROUND_BLUE|\
						FOREGROUND_INTENSITY|	BACKGROUND_INTENSITY			   //�����֣����׵�
#endif