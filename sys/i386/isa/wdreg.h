begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)wdreg.h	7.1 (Berkeley) 5/9/91  */
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
name|WDCTL_4BIT
value|0x8
end_define

begin_comment
comment|/* use four head bits (wd1003) */
end_comment

begin_define
define|#
directive|define
name|WDCTL_RST
value|0x4
end_define

begin_comment
comment|/* reset the controller */
end_comment

begin_define
define|#
directive|define
name|WDCTL_IDS
value|0x2
end_define

begin_comment
comment|/* disable controller interrupts */
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
name|WDCC_RESTORE
value|0x10
end_define

begin_comment
comment|/* disk restore code -- resets cntlr */
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
name|WDCC__LONG
value|0x02
end_define

begin_comment
comment|/* modifier -- access ecc bytes */
end_comment

begin_define
define|#
directive|define
name|WDCC__NORETRY
value|0x01
end_define

begin_comment
comment|/* modifier -- no retrys */
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
name|WDCC_DIAGNOSE
value|0x90
end_define

begin_comment
comment|/* controller diagnostic */
end_comment

begin_define
define|#
directive|define
name|WDCC_IDC
value|0x91
end_define

begin_comment
comment|/* initialize drive command */
end_comment

begin_define
define|#
directive|define
name|WDCC_EXTDCMD
value|0xE0
end_define

begin_comment
comment|/* send extended command */
end_comment

begin_define
define|#
directive|define
name|WDCC_READP
value|0xEC
end_define

begin_comment
comment|/* read parameters from controller */
end_comment

begin_define
define|#
directive|define
name|WDCC_CACHEC
value|0xEF
end_define

begin_comment
comment|/* cache control */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * read parameters command returns this:  */
end_comment

begin_struct
struct|struct
name|wdparams
block|{
comment|/* drive info */
name|short
name|wdp_config
decl_stmt|;
comment|/* general configuration */
name|short
name|wdp_fixedcyl
decl_stmt|;
comment|/* number of non-removable cylinders */
name|short
name|wdp_removcyl
decl_stmt|;
comment|/* number of removable cylinders */
name|short
name|wdp_heads
decl_stmt|;
comment|/* number of heads */
name|short
name|wdp_unfbytespertrk
decl_stmt|;
comment|/* number of unformatted bytes/track */
name|short
name|wdp_unfbytes
decl_stmt|;
comment|/* number of unformatted bytes/sector */
name|short
name|wdp_sectors
decl_stmt|;
comment|/* number of sectors */
name|short
name|wdp_minisg
decl_stmt|;
comment|/* minimum bytes in inter-sector gap*/
name|short
name|wdp_minplo
decl_stmt|;
comment|/* minimum bytes in postamble */
name|short
name|wdp_vendstat
decl_stmt|;
comment|/* number of words of vendor status */
comment|/* controller info */
name|char
name|wdp_cnsn
index|[
literal|20
index|]
decl_stmt|;
comment|/* controller serial number */
name|short
name|wdp_cntype
decl_stmt|;
comment|/* controller type */
define|#
directive|define
name|WDTYPE_SINGLEPORTSECTOR
value|1
comment|/* single port, single sector buffer */
define|#
directive|define
name|WDTYPE_DUALPORTMULTI
value|2
comment|/* dual port, multiple sector buffer */
define|#
directive|define
name|WDTYPE_DUALPORTMULTICACHE
value|3
comment|/* above plus track cache */
name|short
name|wdp_cnsbsz
decl_stmt|;
comment|/* sector buffer size, in sectors */
name|short
name|wdp_necc
decl_stmt|;
comment|/* ecc bytes appended */
name|char
name|wdp_rev
index|[
literal|8
index|]
decl_stmt|;
comment|/* firmware revision */
name|char
name|wdp_model
index|[
literal|40
index|]
decl_stmt|;
comment|/* model name */
name|short
name|wdp_nsecperint
decl_stmt|;
comment|/* sectors per interrupt */
name|short
name|wdp_usedmovsd
decl_stmt|;
comment|/* can use double word read/write? */
block|}
struct|;
end_struct

begin_comment
comment|/*  * wd driver entry points  */
end_comment

begin_function_decl
name|int
name|wdprobe
parameter_list|(
name|struct
name|isa_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wdattach
parameter_list|(
name|struct
name|isa_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wdstrategy
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wdintr
parameter_list|(
name|struct
name|intrframe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wdopen
parameter_list|(
name|dev_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wdclose
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|fmt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wdioctl
parameter_list|(
name|dev_t
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* int wdformat(struct buf *bp); */
end_comment

begin_function_decl
name|int
name|wdsize
parameter_list|(
name|dev_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wddump
parameter_list|(
name|dev_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

end_unit

