begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)nec765.h	7.1 (Berkeley) 5/9/91  *	$Id: nec765.h,v 1.6 1997/02/22 09:38:04 peter Exp $  */
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
value|"\020\010invld\007abnrml\006seek_cmplt\005equ_chck\004drive_notrdy\003top_head"
end_define

begin_define
define|#
directive|define
name|NE7_ST0_IC
value|0xc0
end_define

begin_comment
comment|/* interrupt completion code */
end_comment

begin_define
define|#
directive|define
name|NE7_ST0_IC_RC
value|0xc0
end_define

begin_comment
comment|/* terminated due to ready changed, n/a */
end_comment

begin_define
define|#
directive|define
name|NE7_ST0_IC_IV
value|0x80
end_define

begin_comment
comment|/* invalid command; must reset FDC */
end_comment

begin_define
define|#
directive|define
name|NE7_ST0_IC_AT
value|0x40
end_define

begin_comment
comment|/* abnormal termination, check error stat */
end_comment

begin_define
define|#
directive|define
name|NE7_ST0_IC_NT
value|0x00
end_define

begin_comment
comment|/* normal termination */
end_comment

begin_define
define|#
directive|define
name|NE7_ST0_SE
value|0x20
end_define

begin_comment
comment|/* seek end */
end_comment

begin_define
define|#
directive|define
name|NE7_ST0_EC
value|0x10
end_define

begin_comment
comment|/* equipment check, recalibrated but no trk0 */
end_comment

begin_define
define|#
directive|define
name|NE7_ST0_NR
value|0x08
end_define

begin_comment
comment|/* not ready (n/a) */
end_comment

begin_define
define|#
directive|define
name|NE7_ST0_HD
value|0x04
end_define

begin_comment
comment|/* upper head selected */
end_comment

begin_define
define|#
directive|define
name|NE7_ST0_DR
value|0x03
end_define

begin_comment
comment|/* drive code */
end_comment

begin_comment
comment|/* Status register ST1 */
end_comment

begin_define
define|#
directive|define
name|NE7_ST1BITS
value|"\020\010end_of_cyl\006bad_crc\005data_overrun\003sec_not_fnd\002write_protect\001no_am"
end_define

begin_define
define|#
directive|define
name|NE7_ST1_EN
value|0x80
end_define

begin_comment
comment|/* end of cylinder, access past last record */
end_comment

begin_define
define|#
directive|define
name|NE7_ST1_DE
value|0x20
end_define

begin_comment
comment|/* data error, CRC fail in ID or data */
end_comment

begin_define
define|#
directive|define
name|NE7_ST1_OR
value|0x10
end_define

begin_comment
comment|/* DMA overrun, DMA failed to do i/o quickly */
end_comment

begin_define
define|#
directive|define
name|NE7_ST1_ND
value|0x04
end_define

begin_comment
comment|/* no data, sector not found or CRC in ID f. */
end_comment

begin_define
define|#
directive|define
name|NE7_ST1_NW
value|0x02
end_define

begin_comment
comment|/* not writeable, attempt to violate WP */
end_comment

begin_define
define|#
directive|define
name|NE7_ST1_MA
value|0x01
end_define

begin_comment
comment|/* missing address mark (in ID or data field)*/
end_comment

begin_comment
comment|/* Status register ST2 */
end_comment

begin_define
define|#
directive|define
name|NE7_ST2BITS
value|"\020\007ctrl_mrk\006bad_crc\005wrong_cyl\004scn_eq\003scn_not_fnd\002bad_cyl\001no_dam"
end_define

begin_define
define|#
directive|define
name|NE7_ST2_CM
value|0x40
end_define

begin_comment
comment|/* control mark; found deleted data */
end_comment

begin_define
define|#
directive|define
name|NE7_ST2_DD
value|0x20
end_define

begin_comment
comment|/* data error in data field, CRC fail */
end_comment

begin_define
define|#
directive|define
name|NE7_ST2_WC
value|0x10
end_define

begin_comment
comment|/* wrong cylinder, ID field mismatches cmd */
end_comment

begin_define
define|#
directive|define
name|NE7_ST2_SH
value|0x08
end_define

begin_comment
comment|/* scan equal hit */
end_comment

begin_define
define|#
directive|define
name|NE7_ST2_SN
value|0x04
end_define

begin_comment
comment|/* scan not satisfied */
end_comment

begin_define
define|#
directive|define
name|NE7_ST2_BC
value|0x02
end_define

begin_comment
comment|/* bad cylinder, cylinder marked 0xff */
end_comment

begin_define
define|#
directive|define
name|NE7_ST2_MD
value|0x01
end_define

begin_comment
comment|/* missing address mark in data field */
end_comment

begin_comment
comment|/* Status register ST3 */
end_comment

begin_define
define|#
directive|define
name|NE7_ST3BITS
value|"\020\010fault\007write_protect\006drdy\005tk0\004two_side\003side_sel\002"
end_define

begin_define
define|#
directive|define
name|NE7_ST3_FT
value|0x80
end_define

begin_comment
comment|/* fault; PC: n/a */
end_comment

begin_define
define|#
directive|define
name|NE7_ST3_WP
value|0x40
end_define

begin_comment
comment|/* write protected */
end_comment

begin_define
define|#
directive|define
name|NE7_ST3_RD
value|0x20
end_define

begin_comment
comment|/* ready; PC: always true */
end_comment

begin_define
define|#
directive|define
name|NE7_ST3_T0
value|0x10
end_define

begin_comment
comment|/* track 0 */
end_comment

begin_define
define|#
directive|define
name|NE7_ST3_TS
value|0x08
end_define

begin_comment
comment|/* two-sided; PC: n/a */
end_comment

begin_define
define|#
directive|define
name|NE7_ST3_HD
value|0x04
end_define

begin_comment
comment|/* upper head select */
end_comment

begin_define
define|#
directive|define
name|NE7_ST3_US
value|0x03
end_define

begin_comment
comment|/* unit select */
end_comment

begin_comment
comment|/* Commands */
end_comment

begin_comment
comment|/*  * the top three bits -- where appropriate -- are set as follows:  *  * 0x80 - MT  multi-track; allow both sides to be handled in single cmd  * 0x40 - MFM modified frequency modulation; use MFM encoding  * 0x20 - SK  skip; skip sectors marked as "deleted"  */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_READTRK
value|0x42
end_define

begin_comment
comment|/*  read whole track */
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
name|NE7CMD_SENSED
value|4
end_define

begin_comment
comment|/*  sense drive - requires unit select byte */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_WRITE
value|0xc5
end_define

begin_comment
comment|/*  write - requires eight additional bytes */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_READ
value|0xe6
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
name|NE7CMD_WRITEDEL
value|0xc9
end_define

begin_comment
comment|/*  write deleted data */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_READID
value|0x4a
end_define

begin_comment
comment|/*  read ID field */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_READDEL
value|0xec
end_define

begin_comment
comment|/*  read deleted data */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_FORMAT
value|0x4d
end_define

begin_comment
comment|/*  format - requires five additional bytes */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_SEEK
value|0x0f
end_define

begin_comment
comment|/*  seek drive - requires unit select byte 					and new cyl byte */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_SCNEQU
value|0xf1
end_define

begin_comment
comment|/*  scan equal */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_SCNLE
value|0xf9
end_define

begin_comment
comment|/*  scan less or equal */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_SCNGE
value|0xfd
end_define

begin_comment
comment|/*  scan greater or equal */
end_comment

begin_comment
comment|/*  * Enhanced controller commands:  */
end_comment

begin_define
define|#
directive|define
name|NE7CMD_VERSION
value|0x10
end_define

begin_comment
comment|/*  version (ok for all controllers) */
end_comment

begin_define
define|#
directive|define
name|I8207X_CONFIGURE
value|0x13
end_define

begin_comment
comment|/*  configure enhanced features */
end_comment

begin_comment
comment|/*  * "specify" definitions  *  * acronyms (times are relative to a FDC clock of 8 MHz):  * srt - step rate; PC usually 3 ms  * hut - head unload time; PC usually maximum of 240 ms  * hlt - head load time; PC usually minimum of 2 ms  * nd  - no DMA flag; PC usually not set (0)  */
end_comment

begin_define
define|#
directive|define
name|NE7_SPEC_1
parameter_list|(
name|srt
parameter_list|,
name|hut
parameter_list|)
value|(((16 - (srt))<< 4) | (((hut) / 16)))
end_define

begin_define
define|#
directive|define
name|NE7_SPEC_2
parameter_list|(
name|hlt
parameter_list|,
name|nd
parameter_list|)
value|(((hlt)& 0xFE) | ((nd)& 1))
end_define

end_unit

