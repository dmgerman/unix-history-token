begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Streamer tape driver for 386bsd and FreeBSD.  * Supports Archive and Wangtek compatible QIC-02/QIC-36 boards.  *  * Copyright (C) 1993 by:  *      Sergey Ryzhkov<sir@kiae.su>  *      Serge Vakulenko<vak@zebub.msk.su>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organizations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * This driver is derived from the old 386bsd Wangtek streamer tape driver,  * made by Robert Baron at CMU, based on Intel sources.  * Authors thank Robert Baron, CMU and Intel and retain here  * the original CMU copyright notice.  *  * Version 1.3, Thu Nov 11 12:09:13 MSK 1993  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1989 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Robert Baron  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/* internal QIC-02 commands */
end_comment

begin_define
define|#
directive|define
name|QIC_ERASE
value|0x22
end_define

begin_comment
comment|/* erase the tape */
end_comment

begin_define
define|#
directive|define
name|QIC_RETENS
value|0x24
end_define

begin_comment
comment|/* retension the tape */
end_comment

begin_define
define|#
directive|define
name|QIC_RDDATA
value|0x80
end_define

begin_comment
comment|/* read data */
end_comment

begin_define
define|#
directive|define
name|QIC_READFM
value|0xa0
end_define

begin_comment
comment|/* read file mark */
end_comment

begin_define
define|#
directive|define
name|QIC_WRTDATA
value|0x40
end_define

begin_comment
comment|/* write data */
end_comment

begin_define
define|#
directive|define
name|QIC_WRITEFM
value|0x60
end_define

begin_comment
comment|/* write file mark */
end_comment

begin_define
define|#
directive|define
name|QIC_RDSTAT
value|0xc0
end_define

begin_comment
comment|/* read status command */
end_comment

begin_define
define|#
directive|define
name|QIC_REWIND
value|0x21
end_define

begin_comment
comment|/* rewind command (position+bot) */
end_comment

begin_define
define|#
directive|define
name|QIC_FMT11
value|0x26
end_define

begin_comment
comment|/* set format QIC-11 */
end_comment

begin_define
define|#
directive|define
name|QIC_FMT24
value|0x27
end_define

begin_comment
comment|/* set format QIC-24 */
end_comment

begin_define
define|#
directive|define
name|QIC_FMT120
value|0x28
end_define

begin_comment
comment|/* set format QIC-120 */
end_comment

begin_define
define|#
directive|define
name|QIC_FMT150
value|0x29
end_define

begin_comment
comment|/* set format QIC-150 */
end_comment

begin_define
define|#
directive|define
name|QIC_FMT300
value|0x2a
end_define

begin_comment
comment|/* set format QIC-300/QIC-2100 */
end_comment

begin_define
define|#
directive|define
name|QIC_FMT600
value|0x2b
end_define

begin_comment
comment|/* set format QIC-600/QIC-2200 */
end_comment

begin_comment
comment|/* tape driver flags */
end_comment

begin_define
define|#
directive|define
name|TPINUSE
value|0x0001
end_define

begin_comment
comment|/* tape is already open */
end_comment

begin_define
define|#
directive|define
name|TPREAD
value|0x0002
end_define

begin_comment
comment|/* tape is only open for reading */
end_comment

begin_define
define|#
directive|define
name|TPWRITE
value|0x0004
end_define

begin_comment
comment|/* tape is only open for writing */
end_comment

begin_define
define|#
directive|define
name|TPSTART
value|0x0008
end_define

begin_comment
comment|/* tape must be rewound and reset */
end_comment

begin_define
define|#
directive|define
name|TPRMARK
value|0x0010
end_define

begin_comment
comment|/* read file mark command outstanding */
end_comment

begin_define
define|#
directive|define
name|TPWMARK
value|0x0020
end_define

begin_comment
comment|/* write file mark command outstanding */
end_comment

begin_define
define|#
directive|define
name|TPREW
value|0x0040
end_define

begin_comment
comment|/* rewind command outstanding */
end_comment

begin_define
define|#
directive|define
name|TPEXCEP
value|0x0080
end_define

begin_comment
comment|/* i/o exception flag */
end_comment

begin_define
define|#
directive|define
name|TPVOL
value|0x0100
end_define

begin_comment
comment|/* read file mark or hit end of tape */
end_comment

begin_define
define|#
directive|define
name|TPWO
value|0x0200
end_define

begin_comment
comment|/* write command outstanding */
end_comment

begin_define
define|#
directive|define
name|TPRO
value|0x0400
end_define

begin_comment
comment|/* read command outstanding */
end_comment

begin_define
define|#
directive|define
name|TPWANY
value|0x0800
end_define

begin_comment
comment|/* write command requested */
end_comment

begin_define
define|#
directive|define
name|TPRANY
value|0x1000
end_define

begin_comment
comment|/* read command requested */
end_comment

begin_define
define|#
directive|define
name|TPWP
value|0x2000
end_define

begin_comment
comment|/* write protect error seen */
end_comment

begin_define
define|#
directive|define
name|TPTIMER
value|0x4000
end_define

begin_comment
comment|/* timer() is active */
end_comment

begin_define
define|#
directive|define
name|TPACTIVE
value|0x8000
end_define

begin_comment
comment|/* dma i/o active */
end_comment

begin_comment
comment|/* controller error register bits */
end_comment

begin_define
define|#
directive|define
name|TP_FIL
value|0x0001
end_define

begin_comment
comment|/* File mark detected */
end_comment

begin_define
define|#
directive|define
name|TP_BNL
value|0x0002
end_define

begin_comment
comment|/* Block not located */
end_comment

begin_define
define|#
directive|define
name|TP_UDA
value|0x0004
end_define

begin_comment
comment|/* Unrecoverable data error */
end_comment

begin_define
define|#
directive|define
name|TP_EOM
value|0x0008
end_define

begin_comment
comment|/* End of media */
end_comment

begin_define
define|#
directive|define
name|TP_WRP
value|0x0010
end_define

begin_comment
comment|/* Write protected cartridge */
end_comment

begin_define
define|#
directive|define
name|TP_USL
value|0x0020
end_define

begin_comment
comment|/* Unselected drive */
end_comment

begin_define
define|#
directive|define
name|TP_CNI
value|0x0040
end_define

begin_comment
comment|/* Cartridge not in place */
end_comment

begin_define
define|#
directive|define
name|TP_ST0
value|0x0080
end_define

begin_comment
comment|/* Status byte 0 bits */
end_comment

begin_define
define|#
directive|define
name|TP_ST0MASK
value|0x00ff
end_define

begin_comment
comment|/* Status byte 0 mask */
end_comment

begin_define
define|#
directive|define
name|TP_POR
value|0x0100
end_define

begin_comment
comment|/* Power on/reset occurred */
end_comment

begin_define
define|#
directive|define
name|TP_ERM
value|0x0200
end_define

begin_comment
comment|/* Reserved for end of recorded media */
end_comment

begin_define
define|#
directive|define
name|TP_BPE
value|0x0400
end_define

begin_comment
comment|/* Reserved for bus parity error */
end_comment

begin_define
define|#
directive|define
name|TP_BOM
value|0x0800
end_define

begin_comment
comment|/* Beginning of media */
end_comment

begin_define
define|#
directive|define
name|TP_MBD
value|0x1000
end_define

begin_comment
comment|/* Marginal block detected */
end_comment

begin_define
define|#
directive|define
name|TP_NDT
value|0x2000
end_define

begin_comment
comment|/* No data detected */
end_comment

begin_define
define|#
directive|define
name|TP_ILL
value|0x4000
end_define

begin_comment
comment|/* Illegal command - should not happen! */
end_comment

begin_define
define|#
directive|define
name|TP_ST1
value|0x8000
end_define

begin_comment
comment|/* Status byte 1 bits */
end_comment

begin_define
define|#
directive|define
name|TP_ST1MASK
value|0xff00
end_define

begin_comment
comment|/* Status byte 1 mask */
end_comment

begin_comment
comment|/* device minor number */
end_comment

begin_define
define|#
directive|define
name|WT_BSIZE
value|0100
end_define

begin_comment
comment|/* long block flag */
end_comment

begin_define
define|#
directive|define
name|WT_DENSEL
value|0070
end_define

begin_comment
comment|/* density select mask */
end_comment

begin_define
define|#
directive|define
name|WT_DENSDFLT
value|0000
end_define

begin_comment
comment|/* default density */
end_comment

begin_define
define|#
directive|define
name|WT_QIC11
value|0010
end_define

begin_comment
comment|/* 11 megabytes? */
end_comment

begin_define
define|#
directive|define
name|WT_QIC24
value|0020
end_define

begin_comment
comment|/* 60 megabytes */
end_comment

begin_define
define|#
directive|define
name|WT_QIC120
value|0030
end_define

begin_comment
comment|/* 120 megabytes */
end_comment

begin_define
define|#
directive|define
name|WT_QIC150
value|0040
end_define

begin_comment
comment|/* 150 megabytes */
end_comment

begin_define
define|#
directive|define
name|WT_QIC300
value|0050
end_define

begin_comment
comment|/* 300 megabytes? */
end_comment

begin_define
define|#
directive|define
name|WT_QIC600
value|0060
end_define

begin_comment
comment|/* 600 megabytes? */
end_comment

end_unit

