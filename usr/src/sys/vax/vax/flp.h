begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)flp.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_if
if|#
directive|if
name|VAX780
end_if

begin_comment
comment|/*  * Console floppy command/status and sectoring information.  */
end_comment

begin_define
define|#
directive|define
name|FL_FFC
value|0x200
end_define

begin_comment
comment|/* floppy function complete */
end_comment

begin_define
define|#
directive|define
name|FL_ERR
value|0x80
end_define

begin_comment
comment|/* error bit in floppy status byte */
end_comment

begin_define
define|#
directive|define
name|FL_PERR
value|0x905
end_define

begin_comment
comment|/* floppy protocol error */
end_comment

begin_define
define|#
directive|define
name|FL_DATA
value|0x100
end_define

begin_comment
comment|/* floppy data select code */
end_comment

begin_define
define|#
directive|define
name|FL_RS
value|0x900
end_define

begin_comment
comment|/* floppy read sector command */
end_comment

begin_define
define|#
directive|define
name|FL_WS
value|0x901
end_define

begin_comment
comment|/* floppy write sector command*/
end_comment

begin_define
define|#
directive|define
name|FL_STAT
value|0x902
end_define

begin_comment
comment|/* floppy get status command*/
end_comment

begin_define
define|#
directive|define
name|FL_CANCEL
value|0x904
end_define

begin_comment
comment|/* cancel floppy function */
end_comment

begin_define
define|#
directive|define
name|RXFTRK
value|77
end_define

begin_comment
comment|/* tracks/floppy */
end_comment

begin_define
define|#
directive|define
name|RXSTRK
value|26
end_define

begin_comment
comment|/* sectors/track */
end_comment

begin_define
define|#
directive|define
name|RXBYSEC
value|128
end_define

begin_comment
comment|/* bytes/sector */
end_comment

begin_define
define|#
directive|define
name|MAXSEC
value|(RXFTRK*RXSTRK)
end_define

begin_comment
comment|/* sectors/floppy */
end_comment

begin_comment
comment|/*  * In the floppy driver routines, the device active byte is used  * not as a boolean, but as an indicator of the state we are in.  * That is, it contains what to do on the next interrupt.  */
end_comment

begin_define
define|#
directive|define
name|FL_IDLE
value|0
end_define

begin_comment
comment|/* floppy idle */
end_comment

begin_define
define|#
directive|define
name|FL_MAND
value|1
end_define

begin_comment
comment|/* about to send read/write command */
end_comment

begin_define
define|#
directive|define
name|FL_SEC
value|2
end_define

begin_comment
comment|/* about to send sector # to LSI */
end_comment

begin_define
define|#
directive|define
name|FL_TRACK
value|3
end_define

begin_comment
comment|/* about to send track # to LSI */
end_comment

begin_define
define|#
directive|define
name|FL_DAX
value|4
end_define

begin_comment
comment|/* transmitting data */
end_comment

begin_define
define|#
directive|define
name|FL_DAR
value|5
end_define

begin_comment
comment|/* receiving data */
end_comment

begin_define
define|#
directive|define
name|FL_COM
value|6
end_define

begin_comment
comment|/* completing transmission */
end_comment

begin_define
define|#
directive|define
name|FL_CAN
value|7
end_define

begin_comment
comment|/* give cancel order - we had an error, 				   and are to restart */
end_comment

begin_define
define|#
directive|define
name|FLERRS
value|5
end_define

begin_comment
comment|/* number of retries before quitting */
end_comment

begin_comment
comment|/*  * The state byte is used to retain exclusivity,  * and contains the busy flag.  */
end_comment

begin_define
define|#
directive|define
name|FL_OPEN
value|1
end_define

begin_define
define|#
directive|define
name|FL_BUSY
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

