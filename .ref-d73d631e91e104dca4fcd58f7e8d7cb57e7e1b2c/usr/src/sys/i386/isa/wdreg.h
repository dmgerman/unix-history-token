begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.noredist.c%  *  *	@(#)wdreg.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Disk Controller register definitions.  */
end_comment

begin_define
define|#
directive|define
name|wd_data
value|0x0
end_define

begin_comment
comment|/* data register (R/W - 16 bits) */
end_comment

begin_define
define|#
directive|define
name|wd_error
value|0x1
end_define

begin_comment
comment|/* error register (R) */
end_comment

begin_define
define|#
directive|define
name|wd_precomp
value|wd_error
end_define

begin_comment
comment|/* write precompensation (W) */
end_comment

begin_define
define|#
directive|define
name|wd_seccnt
value|0x2
end_define

begin_comment
comment|/* sector count (R/W) */
end_comment

begin_define
define|#
directive|define
name|wd_sector
value|0x3
end_define

begin_comment
comment|/* first sector number (R/W) */
end_comment

begin_define
define|#
directive|define
name|wd_cyl_lo
value|0x4
end_define

begin_comment
comment|/* cylinder address, low byte (R/W) */
end_comment

begin_define
define|#
directive|define
name|wd_cyl_hi
value|0x5
end_define

begin_comment
comment|/* cylinder address, high byte (R/W)*/
end_comment

begin_define
define|#
directive|define
name|wd_sdh
value|0x6
end_define

begin_comment
comment|/* sector size/drive/head (R/W)*/
end_comment

begin_define
define|#
directive|define
name|wd_command
value|0x7
end_define

begin_comment
comment|/* command register (W)	 */
end_comment

begin_define
define|#
directive|define
name|wd_status
value|wd_command
end_define

begin_comment
comment|/* immediate status (R)	 */
end_comment

begin_define
define|#
directive|define
name|wd_altsts
value|0x206
end_define

begin_comment
comment|/*alternate fixed disk status(via 1015) (R)*/
end_comment

begin_define
define|#
directive|define
name|wd_ctlr
value|0x206
end_define

begin_comment
comment|/*fixed disk controller control(via 1015) (W)*/
end_comment

begin_define
define|#
directive|define
name|wd_digin
value|0x207
end_define

begin_comment
comment|/* disk controller input(via 1015) (R)*/
end_comment

begin_comment
comment|/*  * Status Bits.  */
end_comment

begin_define
define|#
directive|define
name|WDCS_BUSY
value|0x80
end_define

begin_comment
comment|/* Controller busy bit. */
end_comment

begin_define
define|#
directive|define
name|WDCS_READY
value|0x40
end_define

begin_comment
comment|/* Selected drive is ready */
end_comment

begin_define
define|#
directive|define
name|WDCS_WRTFLT
value|0x20
end_define

begin_comment
comment|/* Write fault */
end_comment

begin_define
define|#
directive|define
name|WDCS_SEEKCMPLT
value|0x10
end_define

begin_comment
comment|/* Seek complete */
end_comment

begin_define
define|#
directive|define
name|WDCS_DRQ
value|0x08
end_define

begin_comment
comment|/* Data request bit. */
end_comment

begin_define
define|#
directive|define
name|WDCS_ECCCOR
value|0x04
end_define

begin_comment
comment|/* ECC correction made in data */
end_comment

begin_define
define|#
directive|define
name|WDCS_INDEX
value|0x02
end_define

begin_comment
comment|/* Index pulse from selected drive */
end_comment

begin_define
define|#
directive|define
name|WDCS_ERR
value|0x01
end_define

begin_comment
comment|/* Error detect bit. */
end_comment

begin_define
define|#
directive|define
name|WDCS_BITS
value|"\020\010busy\006rdy\006wrtflt\005seekdone\004drq\003ecc_cor\002index\001err"
end_define

begin_define
define|#
directive|define
name|WDERR_BITS
value|"\020\010badblk\007uncorr\006id_crc\005no_id\003abort\002tr000\001no_dam"
end_define

begin_comment
comment|/*  * Commands for Disk Controller.  */
end_comment

begin_define
define|#
directive|define
name|WDCC_READ
value|0x20
end_define

begin_comment
comment|/* disk read code */
end_comment

begin_define
define|#
directive|define
name|WDCC_WRITE
value|0x30
end_define

begin_comment
comment|/* disk write code */
end_comment

begin_define
define|#
directive|define
name|WDCC_RESTORE
value|0x10
end_define

begin_comment
comment|/* disk restore code -- resets cntlr */
end_comment

begin_define
define|#
directive|define
name|WDCC_FORMAT
value|0x50
end_define

begin_comment
comment|/* disk format code */
end_comment

begin_define
define|#
directive|define
name|WD_STEP
value|0
end_define

begin_comment
comment|/* winchester- default 35us step */
end_comment

begin_define
define|#
directive|define
name|WDSD_IBM
value|0xa0
end_define

begin_comment
comment|/* forced to 512 byte sector, ecc */
end_comment

end_unit

