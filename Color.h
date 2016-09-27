#ifndef _COLOR_H_
#define _COLOR_H_
//¶¨ÒåÑÕÉ«
#define Bwhite_Dblue    FOREGROUND_RED|\
						FOREGROUND_GREEN|\
						FOREGROUND_BLUE|		BACKGROUND_BLUE|\
						FOREGROUND_INTENSITY						               //ÁÁ°××Ö£¬°µÀ¶µ×

#define Bwhite_Bblue    FOREGROUND_RED|\
						FOREGROUND_GREEN|\
						FOREGROUND_BLUE|        BACKGROUND_BLUE|\
						FOREGROUND_INTENSITY|	BACKGROUND_INTENSITY			   //ÁÁ°××Ö£¬ÁÁÀ¶µ×

#define Bwhite_Bred     FOREGROUND_RED|         BACKGROUND_RED|\
						FOREGROUND_GREEN|\
						FOREGROUND_BLUE|\
						FOREGROUND_INTENSITY|	BACKGROUND_INTENSITY			   //ÁÁ°××Ö£¬ÁÁºìµ×

#define Dgreen_Dwhite                           BACKGROUND_RED|\
						FOREGROUND_GREEN|       BACKGROUND_GREEN|\
						                        BACKGROUND_BLUE                    //°µÂÌ×Ö£¬°µ°×µ×

#define Bwhite_Dgreen   FOREGROUND_RED|\
						FOREGROUND_GREEN |     BACKGROUND_GREEN | \
					    FOREGROUND_BLUE|\
						FOREGROUND_INTENSITY			                           //ÁÁ°××Ö£¬°µÂÌµ×

#define Bred_Bwhite     FOREGROUND_RED|         BACKGROUND_RED|\
						                        BACKGROUND_GREEN|\
						                        BACKGROUND_BLUE|\
						FOREGROUND_INTENSITY|	BACKGROUND_INTENSITY			   //ÁÁºì×Ö£¬ÁÁ°×µ×
#endif