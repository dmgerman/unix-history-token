begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nec765.h	8.1 (Berkeley) 6/11/93  */
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

