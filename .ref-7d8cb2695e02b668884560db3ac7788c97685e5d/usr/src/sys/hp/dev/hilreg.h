begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: hilreg.h 1.10 92/01/21$  *  *	@(#)hilreg.h	7.5 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<hp/dev/iotypes.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|hp300
end_ifdef

begin_struct
struct|struct
name|hil_dev
block|{
name|char
name|hil_pad0
decl_stmt|;
name|vu_char
name|hil_data
decl_stmt|;
name|char
name|hil_pad1
decl_stmt|;
name|vu_char
name|hil_cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HILADDR
value|((struct hil_dev *)IIOV(0x428000))
end_define

begin_define
define|#
directive|define
name|BBCADDR
value|((struct hil_dev *)IIOV(0x420000))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|hp800
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|hp700
end_ifdef

begin_struct
struct|struct
name|hil_dev
block|{
name|vu_char
name|hil_rsthold
decl_stmt|;
comment|/* (WO) reset hold (and Serial #3) */
name|vu_char
name|hil_resv1
index|[
literal|2047
index|]
decl_stmt|;
name|vu_char
name|hil_data
decl_stmt|;
comment|/* send/receive data to/from 8042 */
name|vu_char
name|hil_cmd
decl_stmt|;
comment|/* status/control to/from 8042 */
name|vu_char
name|hil_resv2
index|[
literal|1022
index|]
decl_stmt|;
name|vu_char
name|hil_rstrel
decl_stmt|;
comment|/* (WO) reset release (and Serial #3) */
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|hil_dev
block|{
name|vu_int
name|hil_data
decl_stmt|;
name|vu_int
name|hil_pad
decl_stmt|;
name|vu_int
name|hil_cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|hil_stat
value|hil_cmd
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hp300
argument_list|)
operator|||
name|defined
argument_list|(
name|hp700
argument_list|)
end_if

begin_define
define|#
directive|define
name|READHILDATA
parameter_list|(
name|x
parameter_list|)
value|((x)->hil_data)
end_define

begin_define
define|#
directive|define
name|READHILSTAT
parameter_list|(
name|x
parameter_list|)
value|((x)->hil_stat)
end_define

begin_define
define|#
directive|define
name|READHILCMD
parameter_list|(
name|x
parameter_list|)
value|((x)->hil_cmd)
end_define

begin_define
define|#
directive|define
name|WRITEHILDATA
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)->hil_data = (y))
end_define

begin_define
define|#
directive|define
name|WRITEHILSTAT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)->hil_stat = (y))
end_define

begin_define
define|#
directive|define
name|WRITEHILCMD
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)->hil_cmd  = (y))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|READHILDATA
parameter_list|(
name|x
parameter_list|)
value|((x)->hil_data>> 24)
end_define

begin_define
define|#
directive|define
name|READHILSTAT
parameter_list|(
name|x
parameter_list|)
value|((x)->hil_stat>> 24)
end_define

begin_define
define|#
directive|define
name|READHILCMD
parameter_list|(
name|x
parameter_list|)
value|((x)->hil_cmd>> 24)
end_define

begin_define
define|#
directive|define
name|WRITEHILDATA
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)->hil_data = ((y)<< 24))
end_define

begin_define
define|#
directive|define
name|WRITEHILSTAT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)->hil_stat = ((y)<< 24))
end_define

begin_define
define|#
directive|define
name|WRITEHILCMD
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)->hil_cmd  = ((y)<< 24))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|hp300
end_ifdef

begin_define
define|#
directive|define
name|splhil
parameter_list|()
value|spl1()
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|hilspl
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|splhil
parameter_list|()
value|splx(hilspl)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|while ((READHILSTAT(hil_dev)& HIL_BUSY))
end_define

begin_define
define|#
directive|define
name|HILDATAWAIT
parameter_list|(
name|hil_dev
parameter_list|)
value|while (!(READHILSTAT(hil_dev)& HIL_DATA_RDY))
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
comment|/* rate (10 - 2550 msec, 2551 == off) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|hp300
end_ifdef

begin_comment
comment|/* Magic */
end_comment

begin_define
define|#
directive|define
name|KBDNMISTAT
value|((volatile char *)IIOV(0x478005))
end_define

begin_define
define|#
directive|define
name|KBDNMI
value|0x04
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

