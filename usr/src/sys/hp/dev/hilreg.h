begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: hilreg.h 1.8 89/08/24$  *  *	@(#)hilreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|hil_dev
block|{
name|char
name|hil_pad0
decl_stmt|;
specifier|volatile
name|char
name|hil_data
decl_stmt|;
name|char
name|hil_pad1
decl_stmt|;
specifier|volatile
name|char
name|hil_cmd
decl_stmt|;
define|#
directive|define
name|hil_stat
value|hil_cmd
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HILADDR
value|((struct hil_dev *)IOV(0x428000))
end_define

begin_define
define|#
directive|define
name|BBCADDR
value|((struct hil_dev *)IOV(0x420000))
end_define

begin_define
define|#
directive|define
name|splhil
value|spl1
end_define

begin_define
define|#
directive|define
name|HIL_BUSY
value|0x02
end_define

begin_define
define|#
directive|define
name|HIL_DATA_RDY
value|0x01
end_define

begin_define
define|#
directive|define
name|HILWAIT
parameter_list|(
name|hil_dev
parameter_list|)
value|while ((hil_dev->hil_stat& HIL_BUSY))
end_define

begin_define
define|#
directive|define
name|HILDATAWAIT
parameter_list|(
name|hil_dev
parameter_list|)
value|while ((hil_dev->hil_stat& HIL_DATA_RDY) == 0)
end_define

begin_comment
comment|/* HIL status bits */
end_comment

begin_define
define|#
directive|define
name|HIL_POLLDATA
value|0x10
end_define

begin_comment
comment|/* HIL poll data follows */
end_comment

begin_define
define|#
directive|define
name|HIL_COMMAND
value|0x08
end_define

begin_comment
comment|/* Start of original command */
end_comment

begin_define
define|#
directive|define
name|HIL_ERROR
value|0x080
end_define

begin_comment
comment|/* HIL error */
end_comment

begin_define
define|#
directive|define
name|HIL_RECONFIG
value|0x080
end_define

begin_comment
comment|/* HIL has reconfigured */
end_comment

begin_define
define|#
directive|define
name|HIL_STATMASK
value|(HIL_DATA | HIL_COMMAND)
end_define

begin_define
define|#
directive|define
name|HIL_SSHIFT
value|4
end_define

begin_comment
comment|/* Bits to shift status over */
end_comment

begin_define
define|#
directive|define
name|HIL_SMASK
value|0xF
end_define

begin_comment
comment|/* Service request status mask */
end_comment

begin_define
define|#
directive|define
name|HIL_DEVMASK
value|0x07
end_define

begin_comment
comment|/* HIL status types */
end_comment

begin_define
define|#
directive|define
name|HIL_STATUS
value|0x5
end_define

begin_comment
comment|/* HIL status in data register */
end_comment

begin_define
define|#
directive|define
name|HIL_DATA
value|0x6
end_define

begin_comment
comment|/* HIL data in data register */
end_comment

begin_define
define|#
directive|define
name|HIL_CTRLSHIFT
value|0x8
end_define

begin_comment
comment|/* key + CTRL + SHIFT */
end_comment

begin_define
define|#
directive|define
name|HIL_CTRL
value|0x9
end_define

begin_comment
comment|/* key + CTRL */
end_comment

begin_define
define|#
directive|define
name|HIL_SHIFT
value|0xA
end_define

begin_comment
comment|/* key + SHIFT */
end_comment

begin_define
define|#
directive|define
name|HIL_KEY
value|0xB
end_define

begin_comment
comment|/* key only */
end_comment

begin_define
define|#
directive|define
name|HIL_68K
value|0x4
end_define

begin_comment
comment|/* Data from the 68k is ready */
end_comment

begin_comment
comment|/* HIL commands */
end_comment

begin_define
define|#
directive|define
name|HIL_SETARD
value|0xA0
end_define

begin_comment
comment|/* set auto-repeat delay */
end_comment

begin_define
define|#
directive|define
name|HIL_SETARR
value|0xA2
end_define

begin_comment
comment|/* set auto-repeat rate */
end_comment

begin_define
define|#
directive|define
name|HIL_SETTONE
value|0xA3
end_define

begin_comment
comment|/* set tone generator */
end_comment

begin_define
define|#
directive|define
name|HIL_CNMT
value|0xB2
end_define

begin_comment
comment|/* clear nmi */
end_comment

begin_define
define|#
directive|define
name|HIL_INTON
value|0x5C
end_define

begin_comment
comment|/* Turn on interrupts. */
end_comment

begin_define
define|#
directive|define
name|HIL_INTOFF
value|0x5D
end_define

begin_comment
comment|/* Turn off interrupts. */
end_comment

begin_define
define|#
directive|define
name|HIL_TRIGGER
value|0xC5
end_define

begin_comment
comment|/* trigger command */
end_comment

begin_define
define|#
directive|define
name|HIL_STARTCMD
value|0xE0
end_define

begin_comment
comment|/* start loop command */
end_comment

begin_define
define|#
directive|define
name|HIL_TIMEOUT
value|0xFE
end_define

begin_comment
comment|/* timeout */
end_comment

begin_define
define|#
directive|define
name|HIL_READTIME
value|0x13
end_define

begin_comment
comment|/* Read real time register */
end_comment

begin_comment
comment|/* Read/write various registers on the 8042. */
end_comment

begin_define
define|#
directive|define
name|HIL_READBUSY
value|0x02
end_define

begin_comment
comment|/* internal "busy" register */
end_comment

begin_define
define|#
directive|define
name|HIL_READKBDLANG
value|0x12
end_define

begin_comment
comment|/* read keyboard language code */
end_comment

begin_define
define|#
directive|define
name|HIL_READKBDSADR
value|0xF9
end_define

begin_define
define|#
directive|define
name|HIL_WRITEKBDSADR
value|0xE9
end_define

begin_define
define|#
directive|define
name|HIL_READLPSTAT
value|0xFA
end_define

begin_define
define|#
directive|define
name|HIL_WRITELPSTAT
value|0xEA
end_define

begin_define
define|#
directive|define
name|HIL_READLPCTRL
value|0xFB
end_define

begin_define
define|#
directive|define
name|HIL_WRITELPCTRL
value|0xEB
end_define

begin_comment
comment|/* BUSY bits */
end_comment

begin_define
define|#
directive|define
name|BSY_LOOPBUSY
value|0x04
end_define

begin_comment
comment|/* LPCTRL bits */
end_comment

begin_define
define|#
directive|define
name|LPC_AUTOPOLL
value|0x01
end_define

begin_comment
comment|/* enable auto-polling */
end_comment

begin_define
define|#
directive|define
name|LPC_NOERROR
value|0x02
end_define

begin_comment
comment|/* don't report errors */
end_comment

begin_define
define|#
directive|define
name|LPC_NORECONF
value|0x04
end_define

begin_comment
comment|/* don't report reconfigure */
end_comment

begin_define
define|#
directive|define
name|LPC_KBDCOOK
value|0x10
end_define

begin_comment
comment|/* cook all keyboards */
end_comment

begin_define
define|#
directive|define
name|LPC_RECONF
value|0x80
end_define

begin_comment
comment|/* reconfigure the loop */
end_comment

begin_comment
comment|/* LPSTAT bits */
end_comment

begin_define
define|#
directive|define
name|LPS_DEVMASK
value|0x07
end_define

begin_comment
comment|/* number of loop devices */
end_comment

begin_define
define|#
directive|define
name|LPS_CONFGOOD
value|0x08
end_define

begin_comment
comment|/* reconfiguration worked */
end_comment

begin_define
define|#
directive|define
name|LPS_CONFFAIL
value|0x80
end_define

begin_comment
comment|/* reconfiguration failed */
end_comment

begin_comment
comment|/* HIL packet headers */
end_comment

begin_define
define|#
directive|define
name|HIL_MOUSEDATA
value|0x2
end_define

begin_define
define|#
directive|define
name|HIL_KBDDATA
value|0x40
end_define

begin_define
define|#
directive|define
name|HIL_MOUSEMOTION
value|0x02
end_define

begin_comment
comment|/* mouse movement event */
end_comment

begin_define
define|#
directive|define
name|HIL_KBDBUTTON
value|0x40
end_define

begin_comment
comment|/* keyboard button event */
end_comment

begin_define
define|#
directive|define
name|HIL_MOUSEBUTTON
value|0x40
end_define

begin_comment
comment|/* mouse button event */
end_comment

begin_define
define|#
directive|define
name|HIL_BUTTONBOX
value|0x60
end_define

begin_comment
comment|/* button box event */
end_comment

begin_define
define|#
directive|define
name|HIL_TABLET
value|0x02
end_define

begin_comment
comment|/* tablet motion event */
end_comment

begin_define
define|#
directive|define
name|HIL_KNOBBOX
value|0x03
end_define

begin_comment
comment|/* knob box motion data */
end_comment

begin_comment
comment|/* Magic */
end_comment

begin_define
define|#
directive|define
name|KBDNMISTAT
value|((volatile char *)IOV(0x478005))
end_define

begin_define
define|#
directive|define
name|KBDNMI
value|0x04
end_define

begin_comment
comment|/* For setting auto repeat on the keyboard */
end_comment

begin_define
define|#
directive|define
name|ar_format
parameter_list|(
name|x
parameter_list|)
value|~((x - 10) / 10)
end_define

begin_define
define|#
directive|define
name|KBD_ARD
value|400
end_define

begin_comment
comment|/* initial delay in msec (10 - 2560) */
end_comment

begin_define
define|#
directive|define
name|KBD_ARR
value|60
end_define

begin_comment
comment|/* rate (10 - 2550 msec, 2551 == off)*/
end_comment

end_unit

