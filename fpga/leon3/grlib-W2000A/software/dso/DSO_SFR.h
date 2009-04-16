#ifndef DSO_SFR_H
#define DSO_SFR_H
#include "DSO_Main.h"
/* TODO make this doxygen conform*/

#define DEVICEADDR               (DSO_SFR_BASE_ADDR+ 4*0)
#define INTERRUPTADDR            (DSO_SFR_BASE_ADDR+ 4*1)
#define INTERRUPTMASKADDR        (DSO_SFR_BASE_ADDR+ 4*2)
#define SAMPLINGFREQADDR         (DSO_SFR_BASE_ADDR+ 4*4)
#define FILTERENABLEADDR         (DSO_SFR_BASE_ADDR+ 4*5)
#define EXTTRIGGERSRCADDR        (DSO_SFR_BASE_ADDR+ 4*6)
#define EXTTRIGGERPWMADDR        (DSO_SFR_BASE_ADDR+ 4*7)
#define INPUTCH0ADDR             (DSO_SFR_BASE_ADDR+ 4*8)
#define INPUTCH1ADDR             (DSO_SFR_BASE_ADDR+ 4*9)
#define INPUTCH2ADDR             (DSO_SFR_BASE_ADDR+ 4*10)
#define INPUTCH3ADDR             (DSO_SFR_BASE_ADDR+ 4*11)
#define TRIGGERONCHADDR          (DSO_SFR_BASE_ADDR+ 4*12)
#define TRIGGERONCEADDR          (DSO_SFR_BASE_ADDR+ 4*13)
#define TRIGGERPREFETCHADDR      (DSO_SFR_BASE_ADDR+ 4*14)
#define TRIGGERSTORAGEMODEADDR   (DSO_SFR_BASE_ADDR+ 4*15)
#define TRIGGERREADOFFSETADDR    (DSO_SFR_BASE_ADDR+ 4*16)
#define TRIGGERTYPEADDR          (DSO_SFR_BASE_ADDR+ 4*17)
#define TRIGGERLOWVALUEADDR      (DSO_SFR_BASE_ADDR+ 4*18)
#define TRIGGERLOWTIMEADDR       (DSO_SFR_BASE_ADDR+ 4*19)
#define TRIGGERHIGHVALUEADDR     (DSO_SFR_BASE_ADDR+ 4*20)
#define TRIGGERHIGHTIMEADDR      (DSO_SFR_BASE_ADDR+ 4*21)
#define TRIGGERSTATUSREGISTER    (DSO_SFR_BASE_ADDR+ 4*22)
#define TRIGGERCURRENTADDR       (DSO_SFR_BASE_ADDR+ 4*23)
#define CONFIGADCENABLE          (DSO_SFR_BASE_ADDR+ 4*24)
#define LEDADDR                  (DSO_SFR_BASE_ADDR+ 4*25)
#define KEYADDR0                 (DSO_SFR_BASE_ADDR+ 4*26)
#define KEYADDR1                 (DSO_SFR_BASE_ADDR+ 4*27)
#define ANALOGSETTINGSPWMADDR    (DSO_SFR_BASE_ADDR+ 4*28)
/* If you wish, the following 3 Addresses can be merged to one addr*/
/* look for this to the analog_inputs.png and */
/* registers_for_control_inputs.png*/
#define ANALOGSETTINGSBANK7      (DSO_SFR_BASE_ADDR+ 4*29) 
#define ANALOGSETTINGSBANK6      (DSO_SFR_BASE_ADDR+ 4*30) 
#define ANALOGSETTINGSBANK5      (DSO_SFR_BASE_ADDR+ 4*31) 
#define LASTADDR                 (DSO_SFR_BASE_ADDR+ 4*32)
#define DSO_REG_SIZE             4*32

/* DEVICEADDR*/
#define WELEC2012   (2012)
#define WELEC2014   (2014)
#define WELEC2022   (2022)
#define WELEC2024   (2024)
#define SANDBOXX    (1014)
#define CURRENTDEVICE   (WELEC2022)

#define WELECMAXFS	1000000000
/* The first decimator is for the parallel input data (eg. 1Gs @ 125 MHz)*/
/* If this is not used the max fs must be set 10 times higher! */
#define SANDBOXXFS   (100000000*10)
/*int ERRUPTADDR*/
/* TODO*/


/* SAMPLINGFREQADDR*/
/* write the sampling frequence as decimal number in Hz*/
/* unsupported sampling frequencys are set to 1 GS!*/

/* FILTERENABLEADDR*/
/* Digital Anti Aliasing Filter Enable*/
/* For now on the W2000A*/
#define D1GHZTO100MHZ  0
#define D100MHZTO10MHZ 1
#define D10MHZTO1MHZ   2
#define D1MHZTO100KHZ  3

/* EXTTRIGGERSRCADDR*/
#define FORCETOGGE  0
#define EXTTRIGGER1 1
/* Note that most devices have none only one Exttrigger input!*/
/* Welec W20xx devices have 1*/
/* SandboxX has also only 1*/
#define EXTTRIGGER2 2
#define EXTTRIGGER3 3
#define EXTTRIGGER4 4
/* ...*/

/* EXTTRIGGERPWMADDR*/
#define EXTTRIGGERPWM0_STARTBIT 0 
#define EXTTRIGGERPWM1_STARTBIT 8
#define EXTTRIGGERPWM2_STARTBIT 16
#define EXTTRIGGERPWM3_STARTBIT 24


/* INPUTCH0ADDR INPUTCH0ADDR INPUTCH1ADDR INPUTCH2ADDR*/
/* Signal Selector: The trigger does always have on each device 4 channels with each 8 bits*/
/* For the lower 8 bits from a 16 bit signal use CHxLOWER */
#define CH0UPPER 0
#define CH1UPPER 1
#define CH2UPPER 2
#define CH3UPPER 3
#define CH0LOWER 4
#define CH1LOWER 5
#define CH2LOWER 6
#define CH3LOWER 7

/* TRIGGERONCHADDR*/
/* Trigger on Channel out of the SignalSelector*/
#define INCH0ADDR 0
#define INCH1ADDR 1
#define INCH2ADDR 2
#define INCH3ADDR 3

/* TRIGGERONCEADDR*/
/* start trigger one time, no continious triggering on the hardware (because it's stupid)*/
/* write 1 to start and 0 to stop the trigger*/

/* TRIGGERPREFETCHADDR*/
/* Here you can set the frame start address for the triggered buffer.*/
/* When the trigger is started, it first writes  TRIGGERPREFETCHADDR */
/* samplesint o the trigger data RAM before the trigger starts triggering.*/
/* It is simply the data offset of the triggered sample, so post triggering is possible!*/

/* TRIGGERSTORAGEMODEADDR*/
/* Data of the TRIGGER_MEM address range */
/* Data(i)(j) data bits from ((i+1)*8)+j-1 (i*8)+j*/
/* chx(k) is the sample offset */
/* TODO: Correct it + 4*This may change, too!*/
#define TRIGGERSTORAGEMODE4CH 0
/* "00" :     4 CH each  8 KB*/
/* Data(0)(0) = ch0(0), Data(1)(0) = ch1(0), Data(2)(0) = ch2(0), Data(3)(0) = ch3(0)*/
#define TRIGGERSTORAGEMODE2CH 1
/* "01" :     2 CH each 16 KB*/
/*#define 0)(0) = ch0(0), Data(1)(0) = ch1(0), Data(2)(0) = ch0(8192), Data(3)(0) = ch1(8192)*/
#define TRIGGERSTORAGEMODE1CH 3
/* "11" :     1 CH with 32 KB*/
/* Data(0)(0) = ch0(0),#define (1)(0) = ch0(8192),#define (2)(0) = ch0(16384),#define (3)(0) = ch0(24576)*/

/* TRIGGERREADOFFSETADDR*/
/* start and stop address for the trigger */
/* write on it and the trigger sample capture size can be extended easily by software*/
/* but take care about the TRIGGERCURRENTADDR and the sampling speed to avoid race conditions*/
/* TRIGGERTYPEADDR*/
/* Choose the trigger type here */
#define EXTTRIGGER_LH    0
#define EXTTRIGGER_HL    1
#define NORMALTRIGGER_LH 2 
#define NORMALTRIGGER_HL 3 
/* TODO add more trigger types*/


/* NORMALTRIGGER is an 8 bit trigger*/
/* The NORMALTRIGGER is a schmitt trigger with an stable counter.*/
/* TRIGGERLOWVALUEADDR  is the low reference level.*/
/* TRIGGERLOWTIMEADDR   is the minimum stable time for the low level in samples.*/
/* TRIGGERHIGHVALUEADDR is the high reference level.*/
/* TRIGGERHIGHTIMEADDR  is the minimum stable time for the high level in samples.*/

/* TRIGGERSTATUSREGISTER   */
#define TRIGGERBUSYBIT      0
#define TRIGGERRECORDINGBIT 1

/* TRIGGERCURRENTADDR  */
/* read only */

/* CONFIGADCENABLE */
/* for SandboxX and possible other boards which using a seperate microprocessor to 
 * make the analog settings now this is a wake up legacy interrupt to enable the uart
 * communication */
#define ADC0 0
#define ADC1 1
/* ... */

/* LEDADDR*/
/* switch on the led by setting the corresponding bit to 1*/
/* TODO solve many bugs and make a good read and write algorithm (hw+sw)*/
#define LED_BTN_CH3         0
#define LED_Beam1On         1
#define LED_BTN_MATH        2
#define LED_Beam2On         3
#define LED_BTN_QUICKMEAS   4
#define LED_CURSORS         5
#define LED_BTN_F1          6
#define LED_BTN_CH2         7
#define LED_BTN_PULSEWIDTH  8
#define LED_EDGE            9
#define LED_RUNSTOP         10
#define LED_BTN_F2          11
#define LED_BTN_F3          12
#define LED_SINGLE          13

/* KEYADDR0 */
/* (read only)*/
#define BTN_F1           0
#define BTN_F2           1
#define BTN_F3           2
#define BTN_F4           3
#define BTN_F5           4
#define BTN_F6           5
#define BTN_MATH         6
#define BTN_CH0          7
#define BTN_CH1          8
#define BTN_CH2          9
#define BTN_CH3         10
#define BTN_MAINDEL     11
#define BTN_RUNSTOP     12
#define BTN_SINGLE      13
#define BTN_CURSORS     14
#define BTN_QUICKMEAS   15
#define BTN_ACQUIRE     16
#define BTN_DISPLAY     17
#define BTN_EDGE        18
#define BTN_MODECOUPLING 19
#define BTN_AUTOSCALE   20
#define BTN_SAVERECALL  21
#define BTN_QUICKPRint  22
#define BTN_UTILITY     23
#define BTN_PULSEWIDTH  24 
#define BTN_X1          25
#define BTN_X2          26
#define ENX_TIME_DIV    27
#define ENY_TIME_DIV    28
#define ENX_F           29
#define ENY_F           30

/* KEYADDR1 */
/* (read only)*/
#define ENX_LEFT_RIGHT  0
#define ENY_LEFT_RIGHT  1
#define ENX_LEVEL       2
#define ENY_LEVEL       3
#define ENX_CH0_UPDN    4
#define ENY_CH0_UPDN    5
#define ENX_CH1_UPDN    6
#define ENY_CH1_UPDN    7
#define ENX_CH2_UPDN    8
#define ENY_CH2_UPDN    9
#define ENX_CH3_UPDN   10
#define ENY_CH3_UPDN   11
#define ENX_CH0_VDIV   12
#define ENY_CH0_VDIV   13
#define ENX_CH1_VDIV   14
#define ENY_CH1_VDIV   15
#define ENX_CH2_VDIV   16
#define ENY_CH2_VDIV   17
#define ENX_CH3_VDIV   18
#define ENY_CH3_VDIV   19

/* ANALOGSETTINGSBANK7 */
#define CH0_K1_ON     0
#define CH0_K1_OFF    1
#define CH0_K2_ON     2
#define CH0_K2_OFF    3
#define CH0_OPA656    4
#define CH0_BW_Limit  5
#define CH0_U14       6
#define CH0_U13       7
#define CH0_DC        8
#define CH1_DC        9
#define CH2_DC       10
#define CH3_DC       11
#define	ANALOGSETTINGSBUSY 31

/* ANALOGSETTINGSBANK6*/
#define DAC_OFFSET 0
#define DAC_CH_OFFSET 16
#define	ANALOGSETTINGSBUSY 31

/* ANALOGSETTINGSBANK5 */
#define CH1_K1_ON      0
#define CH1_K1_OFF     1
#define CH1_K2_ON      2
#define CH1_K2_OFF     3
#define CH1_OPA656     4
#define CH1_BW_Limit   5
#define CH1_U14        6
#define CH1_U13        7
#define CH0_SRC2_ADDR  8
#define CH1_SRC2_ADDR 10
#define CH2_SRC2_ADDR 12
#define CH3_SRC2_ADDR 14
#define	ANALOGSETTINGSBUSY 31

/* CHX_SRC2_ADDR*/
#define SRC2_NONE    0
#define SRC2_PWM     1
#define SRC2_GND     2
#define SRC2_LOWPASS 3

typedef struct { 
	volatile int DeviceAddr;
	volatile int InterruptAddr;
	volatile int InterruptMaskAddr;
	volatile int Reseverd3;
	volatile int Decimator;
	volatile int FilterEnable;
	volatile int InputCh0Addr;
	volatile int InputCh1Addr;
	volatile int InputCh2Addr;
	volatile int InputCh3Addr;
	volatile int ExtTriggerSrcAddr;
	volatile int ExtTriggerPWMAddr;
} volatile CaptureRegs;

typedef struct {
	volatile int TriggerOnChAddr;
	volatile int TriggerOnceAddr;
	volatile int TriggerPrefetchAddr;
	volatile int TriggerStorageModeAddr;
	volatile int TriggerReadOffSetAddr;
	volatile int TriggerTypeAddr;
	volatile int TriggerLowValueAddr;
	volatile int TriggerLowTimeAddr;
	volatile int TriggerHighValueAddr;
	volatile int TriggerHighTimeAddr;
	volatile int TriggerStatusRegister;
	volatile int TriggerCurrentAddr;
	volatile int ExtTriggerSrcAddr;
	volatile int ExtTriggerPWMAddr;
} volatile TriggerRegs;

typedef struct {	
	volatile int cLedAddr;
	volatile int cKeyAddr0;
	volatile int cKeyAddr1;
} volatile Frontpanel;

typedef struct {
	volatile int Bank7;
        volatile int Bank6;
	volatile int Bank5;
} volatile AnalogSettings;

/*int Uart16550Addr          40;*/
/*int Uart16550Data          41;*/

#endif
