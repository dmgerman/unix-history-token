begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)nec765.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Nec 765 floppy disc controller definitions  */
end_comment

begin_comment
comment|/* Main status register */
end_comment

begin_define
define|#
directive|define
name|NE7_DAB
value|0x01
end_define

begin_comment
comment|/* Diskette drive A is seeking, thus busy */
end_comment

begin_define
define|#
directive|define
name|NE7_DBB
value|0x02
end_define

begin_comment
comment|/* Diskette drive B is seeking, thus busy */
end_comment

begin_define
define|#
directive|define
name|NE7_CB
value|0x10
end_define

begin_comment
comment|/* Diskette Controller Busy */
end_comment

begin_define
define|#
directive|define
name|NE7_NDM
value|0x20
end_define

begin_comment
comment|/* Diskette Controller in Non Dma Mode */
end_comment

begin_define
define|#
directive|define
name|NE7_DIO
value|0x40
end_define

begin_comment
comment|/* Diskette Controller Data register I/O */
end_comment

begin_define
define|#
directive|define
name|NE7_RQM
value|0x80
end_define

begin_comment
comment|/* Diskette Controller ReQuest for Master */
end_comment

begin_comment
comment|/* Status register ST0 */
end_comment

begin_define
define|#
directive|define
name|NE7_ST0BITS
value|"\020\010invalid\007abnormal\006seek complete\005drive check\004drive_rdy\003top head\002unit_sel1\001unit_sel0"
end_define

begin_comment
comment|/* Status register ST1 */
end_comment

begin_define
define|#
directive|define
name|NE7_ST1BITS
value|"\020\010end_of_cyl\006bad_crc\005data_overrun\003sec_not_fnd\002write_protect\001no_am"
end_define

begin_comment
comment|/* Status register ST2 */
end_comment

begin_define
define|#
directive|define
name|NE7_ST2BITS
value|"\020\007control_mark\006bad_crc\005wrong_cyl\004scan_equal\003scan_not_found\002bad_cyl\001no_dam"
end_define

begin_comment
comment|/* Status register ST3 */
end_comment

begin_define
define|#
directive|define
name|NE7_ST3BITS
value|"\020\010fault\007write_protect\006drdy\005tk0\004two_side\003side_sel\002unit_sel1\0012unit_sel0"
end_define

begin_comment
comment|/* Commands */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_SENSED
value|2
end_define

begin_comment
comment|/*  sense drive - requires unit select byte */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_SPECIFY
value|3
end_define

begin_comment
comment|/*  specify drive parameters - requires unit 					parameters byte */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_WRITE
value|5
end_define

begin_comment
comment|/*  write - requires eight additional bytes */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_READ
value|6
end_define

begin_comment
comment|/*  read - requires eight additional bytes */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_RECAL
value|7
end_define

begin_comment
comment|/*  recalibrate drive - requires 					unit select byte */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_SENSEI
value|8
end_define

begin_comment
comment|/*  sense controller interrupt status */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_SEEK
value|15
end_define

begin_comment
comment|/*  seek drive - requires unit select byte 					and new cyl byte */
end_comment

end_unit

