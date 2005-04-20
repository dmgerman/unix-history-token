begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * =======================================================================  *	title		: define  *	company		: YAMAHA  *	author		: Taichi Sugiyama  *	create Data     : 28/Sep/99  * =======================================================================  * $FreeBSD$  */
end_comment

begin_comment
comment|/* ----- YAMAHA DS-XG Devices -------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|YAMAHA
value|0x1073
end_define

begin_define
define|#
directive|define
name|YMF724
value|0x0004
end_define

begin_define
define|#
directive|define
name|YMF724F
value|0x000d
end_define

begin_define
define|#
directive|define
name|YMF734
value|0x0005
end_define

begin_define
define|#
directive|define
name|YMF737
value|0x0008
end_define

begin_define
define|#
directive|define
name|YMF738
value|0x0020
end_define

begin_define
define|#
directive|define
name|YMF740
value|0x000a
end_define

begin_define
define|#
directive|define
name|YMF740C
value|0x000c
end_define

begin_define
define|#
directive|define
name|YMF744
value|0x0010
end_define

begin_define
define|#
directive|define
name|YMF754
value|0x0012
end_define

begin_define
define|#
directive|define
name|YMF738_TEG
value|0x0006
end_define

begin_define
define|#
directive|define
name|DEVICE4CH
parameter_list|(
name|x
parameter_list|)
value|((x == YMF738) || (x == YMF744) || (x == YMF754))
end_define

begin_define
define|#
directive|define
name|PCIR_DSXGCTRL
value|0x48
end_define

begin_comment
comment|/* ----- interrupt flag -------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|YDSXG_DEFINT
value|0x01
end_define

begin_define
define|#
directive|define
name|YDSXG_TIMERINT
value|0x02
end_define

begin_comment
comment|/* ----- AC97 ------------------------------------------------------------ */
end_comment

begin_define
define|#
directive|define
name|YDSXG_AC97TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|YDSXG_AC97READCMD
value|0x8000
end_define

begin_define
define|#
directive|define
name|YDSXG_AC97WRITECMD
value|0x0000
end_define

begin_define
define|#
directive|define
name|YDSXG_AC97READFALSE
value|0xFFFF
end_define

begin_comment
comment|/* ----- AC97 register map _---------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|AC97R_GPIOSTATUS
value|0x54
end_define

begin_comment
comment|/* ----- work buffer ----------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|DEF_WORKBUFFLENGTH
value|0x0400
end_define

begin_comment
comment|/* ----- register size --------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|YDSXG_MAPLENGTH
value|0x8000
end_define

begin_define
define|#
directive|define
name|YDSXG_DSPLENGTH
value|0x0080
end_define

begin_define
define|#
directive|define
name|YDSXG_CTRLLENGTH
value|0x3000
end_define

begin_comment
comment|/* ----- register map ---------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|YDSXGR_INTFLAG
value|0x0004
end_define

begin_define
define|#
directive|define
name|YDSXGR_ACTIVITY
value|0x0006
end_define

begin_define
define|#
directive|define
name|YDSXGR_GLOBALCTRL
value|0x0008
end_define

begin_define
define|#
directive|define
name|YDSXGR_ZVCTRL
value|0x000A
end_define

begin_define
define|#
directive|define
name|YDSXGR_TIMERCTRL
value|0x0010
end_define

begin_define
define|#
directive|define
name|YDSXGR_TIMERCOUNT
value|0x0012
end_define

begin_define
define|#
directive|define
name|YDSXGR_SPDIFOUTCTRL
value|0x0018
end_define

begin_define
define|#
directive|define
name|YDSXGR_SPDIFOUTSTATUS
value|0x001C
end_define

begin_define
define|#
directive|define
name|YDSXGR_EEPROMCTRL
value|0x0020
end_define

begin_define
define|#
directive|define
name|YDSXGR_SPDIFINCTRL
value|0x0034
end_define

begin_define
define|#
directive|define
name|YDSXGR_SPDIFINSTATUS
value|0x0038
end_define

begin_define
define|#
directive|define
name|YDSXGR_DSPPROGRAMDL
value|0x0048
end_define

begin_define
define|#
directive|define
name|YDSXGR_DLCNTRL
value|0x004C
end_define

begin_define
define|#
directive|define
name|YDSXGR_GPIOININTFLAG
value|0x0050
end_define

begin_define
define|#
directive|define
name|YDSXGR_GPIOININTENABLE
value|0x0052
end_define

begin_define
define|#
directive|define
name|YDSXGR_GPIOINSTATUS
value|0x0054
end_define

begin_define
define|#
directive|define
name|YDSXGR_GPIOOUTCTRL
value|0x0056
end_define

begin_define
define|#
directive|define
name|YDSXGR_GPIOFUNCENABLE
value|0x0058
end_define

begin_define
define|#
directive|define
name|YDSXGR_GPIOTYPECONFIG
value|0x005A
end_define

begin_define
define|#
directive|define
name|YDSXGR_AC97CMDDATA
value|0x0060
end_define

begin_define
define|#
directive|define
name|YDSXGR_AC97CMDADR
value|0x0062
end_define

begin_define
define|#
directive|define
name|YDSXGR_PRISTATUSDATA
value|0x0064
end_define

begin_define
define|#
directive|define
name|YDSXGR_PRISTATUSADR
value|0x0066
end_define

begin_define
define|#
directive|define
name|YDSXGR_SECSTATUSDATA
value|0x0068
end_define

begin_define
define|#
directive|define
name|YDSXGR_SECSTATUSADR
value|0x006A
end_define

begin_define
define|#
directive|define
name|YDSXGR_SECCONFIG
value|0x0070
end_define

begin_define
define|#
directive|define
name|YDSXGR_LEGACYOUTVOL
value|0x0080
end_define

begin_define
define|#
directive|define
name|YDSXGR_LEGACYOUTVOLL
value|0x0080
end_define

begin_define
define|#
directive|define
name|YDSXGR_LEGACYOUTVOLR
value|0x0082
end_define

begin_define
define|#
directive|define
name|YDSXGR_NATIVEDACOUTVOL
value|0x0084
end_define

begin_define
define|#
directive|define
name|YDSXGR_NATIVEDACOUTVOLL
value|0x0084
end_define

begin_define
define|#
directive|define
name|YDSXGR_NATIVEDACOUTVOLR
value|0x0086
end_define

begin_define
define|#
directive|define
name|YDSXGR_SPDIFOUTVOL
value|0x0088
end_define

begin_define
define|#
directive|define
name|YDSXGR_SPDIFOUTVOLL
value|0x0088
end_define

begin_define
define|#
directive|define
name|YDSXGR_SPDIFOUTVOLR
value|0x008A
end_define

begin_define
define|#
directive|define
name|YDSXGR_AC3OUTVOL
value|0x008C
end_define

begin_define
define|#
directive|define
name|YDSXGR_AC3OUTVOLL
value|0x008C
end_define

begin_define
define|#
directive|define
name|YDSXGR_AC3OUTVOLR
value|0x008E
end_define

begin_define
define|#
directive|define
name|YDSXGR_PRIADCOUTVOL
value|0x0090
end_define

begin_define
define|#
directive|define
name|YDSXGR_PRIADCOUTVOLL
value|0x0090
end_define

begin_define
define|#
directive|define
name|YDSXGR_PRIADCOUTVOLR
value|0x0092
end_define

begin_define
define|#
directive|define
name|YDSXGR_LEGACYLOOPVOL
value|0x0094
end_define

begin_define
define|#
directive|define
name|YDSXGR_LEGACYLOOPVOLL
value|0x0094
end_define

begin_define
define|#
directive|define
name|YDSXGR_LEGACYLOOPVOLR
value|0x0096
end_define

begin_define
define|#
directive|define
name|YDSXGR_NATIVEDACLOOPVOL
value|0x0098
end_define

begin_define
define|#
directive|define
name|YDSXGR_NATIVEDACLOOPVOLL
value|0x0098
end_define

begin_define
define|#
directive|define
name|YDSXGR_NATIVEDACLOOPVOLR
value|0x009A
end_define

begin_define
define|#
directive|define
name|YDSXGR_SPDIFLOOPVOL
value|0x009C
end_define

begin_define
define|#
directive|define
name|YDSXGR_SPDIFLOOPVOLL
value|0x009E
end_define

begin_define
define|#
directive|define
name|YDSXGR_SPDIFLOOPVOLR
value|0x009E
end_define

begin_define
define|#
directive|define
name|YDSXGR_AC3LOOPVOL
value|0x00A0
end_define

begin_define
define|#
directive|define
name|YDSXGR_AC3LOOPVOLL
value|0x00A0
end_define

begin_define
define|#
directive|define
name|YDSXGR_AC3LOOPVOLR
value|0x00A2
end_define

begin_define
define|#
directive|define
name|YDSXGR_PRIADCLOOPVOL
value|0x00A4
end_define

begin_define
define|#
directive|define
name|YDSXGR_PRIADCLOOPVOLL
value|0x00A4
end_define

begin_define
define|#
directive|define
name|YDSXGR_PRIADCLOOPVOLR
value|0x00A6
end_define

begin_define
define|#
directive|define
name|YDSXGR_NATIVEADCINVOL
value|0x00A8
end_define

begin_define
define|#
directive|define
name|YDSXGR_NATIVEADCINVOLL
value|0x00A8
end_define

begin_define
define|#
directive|define
name|YDSXGR_NATIVEADCINVOLR
value|0x00AA
end_define

begin_define
define|#
directive|define
name|YDSXGR_NATIVEDACINVOL
value|0x00AC
end_define

begin_define
define|#
directive|define
name|YDSXGR_NATIVEDACINVOLL
value|0x00AC
end_define

begin_define
define|#
directive|define
name|YDSXGR_NATIVEDACINVOLR
value|0x00AE
end_define

begin_define
define|#
directive|define
name|YDSXGR_BUF441OUTVOL
value|0x00B0
end_define

begin_define
define|#
directive|define
name|YDSXGR_BUF441OUTVOLL
value|0x00B0
end_define

begin_define
define|#
directive|define
name|YDSXGR_BUF441OUTVOLR
value|0x00B2
end_define

begin_define
define|#
directive|define
name|YDSXGR_BUF441LOOPVOL
value|0x00B4
end_define

begin_define
define|#
directive|define
name|YDSXGR_BUF441LOOPVOLL
value|0x00B4
end_define

begin_define
define|#
directive|define
name|YDSXGR_BUF441LOOPVOLR
value|0x00B6
end_define

begin_define
define|#
directive|define
name|YDSXGR_SPDIFOUTVOL2
value|0x00B8
end_define

begin_define
define|#
directive|define
name|YDSXGR_SPDIFOUTVOL2L
value|0x00B8
end_define

begin_define
define|#
directive|define
name|YDSXGR_SPDIFOUTVOL2R
value|0x00BA
end_define

begin_define
define|#
directive|define
name|YDSXGR_SPDIFLOOPVOL2
value|0x00BC
end_define

begin_define
define|#
directive|define
name|YDSXGR_SPDIFLOOPVOL2L
value|0x00BC
end_define

begin_define
define|#
directive|define
name|YDSXGR_SPDIFLOOPVOL2R
value|0x00BE
end_define

begin_define
define|#
directive|define
name|YDSXGR_ADCSLOTSR
value|0x00C0
end_define

begin_define
define|#
directive|define
name|YDSXGR_RECSLOTSR
value|0x00C4
end_define

begin_define
define|#
directive|define
name|YDSXGR_ADCFORMAT
value|0x00C8
end_define

begin_define
define|#
directive|define
name|YDSXGR_RECFORMAT
value|0x00CC
end_define

begin_define
define|#
directive|define
name|YDSXGR_P44SLOTSR
value|0x00D0
end_define

begin_define
define|#
directive|define
name|YDSXGR_STATUS
value|0x0100
end_define

begin_define
define|#
directive|define
name|YDSXGR_CTRLSELECT
value|0x0104
end_define

begin_define
define|#
directive|define
name|YDSXGR_MODE
value|0x0108
end_define

begin_define
define|#
directive|define
name|YDSXGR_SAMPLECOUNT
value|0x010C
end_define

begin_define
define|#
directive|define
name|YDSXGR_NUMOFSAMPLES
value|0x0110
end_define

begin_define
define|#
directive|define
name|YDSXGR_CONFIG
value|0x0114
end_define

begin_define
define|#
directive|define
name|YDSXGR_PLAYCTRLSIZE
value|0x0140
end_define

begin_define
define|#
directive|define
name|YDSXGR_RECCTRLSIZE
value|0x0144
end_define

begin_define
define|#
directive|define
name|YDSXGR_EFFCTRLSIZE
value|0x0148
end_define

begin_define
define|#
directive|define
name|YDSXGR_WORKSIZE
value|0x014C
end_define

begin_define
define|#
directive|define
name|YDSXGR_MAPOFREC
value|0x0150
end_define

begin_define
define|#
directive|define
name|YDSXGR_MAPOFEFFECT
value|0x0154
end_define

begin_define
define|#
directive|define
name|YDSXGR_PLAYCTRLBASE
value|0x0158
end_define

begin_define
define|#
directive|define
name|YDSXGR_RECCTRLBASE
value|0x015C
end_define

begin_define
define|#
directive|define
name|YDSXGR_EFFCTRLBASE
value|0x0160
end_define

begin_define
define|#
directive|define
name|YDSXGR_WORKBASE
value|0x0164
end_define

begin_define
define|#
directive|define
name|YDSXGR_DSPINSTRAM
value|0x1000
end_define

begin_define
define|#
directive|define
name|YDSXGR_CTRLINSTRAM
value|0x4000
end_define

begin_comment
comment|/* ----- time out -------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|YDSXG_WORKBITTIMEOUT
value|250000
end_define

end_unit

