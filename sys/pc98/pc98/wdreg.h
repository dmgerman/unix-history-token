begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)wdreg.h	7.1 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * modified for PC9801 by F.Ukai  *			Kyoto University Microcomputer Club (KMC)  */
end_comment

begin_comment
comment|/*  * Disk Controller register definitions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

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
value|0x2
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
name|wd_features
value|wd_error
end_define

begin_comment
comment|/* features register (W) */
end_comment

begin_define
define|#
directive|define
name|wd_seccnt
value|0x4
end_define

begin_comment
comment|/* sector count (R/W) */
end_comment

begin_define
define|#
directive|define
name|wd_sector
value|0x6
end_define

begin_comment
comment|/* first sector number (R/W) */
end_comment

begin_define
define|#
directive|define
name|wd_cyl_lo
value|0x8
end_define

begin_comment
comment|/* cylinder address, low byte (R/W) */
end_comment

begin_define
define|#
directive|define
name|wd_cyl_hi
value|0xa
end_define

begin_comment
comment|/* cylinder address, high byte (R/W)*/
end_comment

begin_define
define|#
directive|define
name|wd_sdh
value|0xc
end_define

begin_comment
comment|/* sector size/drive/head (R/W)*/
end_comment

begin_define
define|#
directive|define
name|wd_command
value|0xe
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
name|wd_altsts_nec
value|0x10c
end_define

begin_comment
comment|/*alternate fixed disk status(via 1015) (R)*/
end_comment

begin_define
define|#
directive|define
name|wd_ctlr_nec
value|0x10c
end_define

begin_comment
comment|/*fixed disk controller control(via 1015) (W)*/
end_comment

begin_define
define|#
directive|define
name|wd_altsts_epson
value|0x3
end_define

begin_comment
comment|/*alternate fixed disk status(via 1015) (R)*/
end_comment

begin_define
define|#
directive|define
name|wd_ctlr_epson
value|0x3
end_define

begin_comment
comment|/*fixed disk controller control(via 1015) (W)*/
end_comment

begin_define
define|#
directive|define
name|wd_altsts
value|wd_altsts_nec
end_define

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
value|0x10e
end_define

begin_comment
comment|/* disk controller input(via 1015) (R)*/
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IBM-PC */
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
name|wd_features
value|wd_error
end_define

begin_comment
comment|/* features register (W) */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PC98 */
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
value|"\020\010busy\007rdy\006wrtflt\005seekdone\004drq\003ecc_cor\002index\001err"
end_define

begin_define
define|#
directive|define
name|WDERR_ABORT
value|0x04
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
name|WDCC_READ_MULTI
value|0xC4
end_define

begin_comment
comment|/* read multiple */
end_comment

begin_define
define|#
directive|define
name|WDCC_WRITE_MULTI
value|0xC5
end_define

begin_comment
comment|/* write multiple */
end_comment

begin_define
define|#
directive|define
name|WDCC_SET_MULTI
value|0xC6
end_define

begin_comment
comment|/* set multiple count */
end_comment

begin_define
define|#
directive|define
name|WDCC_READ_DMA
value|0xC8
end_define

begin_comment
comment|/* read using DMA */
end_comment

begin_define
define|#
directive|define
name|WDCC_WRITE_DMA
value|0xCA
end_define

begin_comment
comment|/* write using DMA */
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
name|WDCC_FEATURES
value|0xEF
end_define

begin_comment
comment|/* features control */
end_comment

begin_define
define|#
directive|define
name|WDCC_DEFECT
value|0xF0
end_define

begin_comment
comment|/* read defect list */
end_comment

begin_define
define|#
directive|define
name|WDFEA_NORCACHE
value|0x55
end_define

begin_comment
comment|/* read cache disable */
end_comment

begin_define
define|#
directive|define
name|WDFEA_RCACHE
value|0xAA
end_define

begin_comment
comment|/* read cache enable */
end_comment

begin_define
define|#
directive|define
name|WDFEA_NOWCACHE
value|0x82
end_define

begin_comment
comment|/* write cache disable */
end_comment

begin_define
define|#
directive|define
name|WDFEA_WCACHE
value|0x02
end_define

begin_comment
comment|/* write cache enable */
end_comment

begin_define
define|#
directive|define
name|WDFEA_SETXFER
value|0x03
end_define

begin_comment
comment|/* set transfer mode */
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

begin_define
define|#
directive|define
name|WDSD_LBA
value|0x40
end_define

begin_comment
comment|/* use Logical Block Adressing */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * read parameters command returns this:  */
end_comment

begin_struct
struct|struct
name|wdparams
block|{
comment|/* 	 * XXX partly based on DRAFT X3T13/1153D rev 14.   	 * by the time you read this it will have changed. 	 * Offsets in words 	 * (as that's how they are usually presented in tables 	 * e.g. QUANTUM Product manuals) 	 */
comment|/* drive info */
name|short
name|wdp_config
decl_stmt|;
comment|/*0 general configuration bits */
name|u_short
name|wdp_cylinders
decl_stmt|;
comment|/*1 number of cylinders */
name|short
name|wdp_reserved2
decl_stmt|;
comment|/*2*/
name|u_short
name|wdp_heads
decl_stmt|;
comment|/*3 number of heads */
name|short
name|wdp_unfbytespertrk
decl_stmt|;
comment|/*4 number of unformatted bytes/track */
name|short
name|wdp_unfbytes
decl_stmt|;
comment|/*5 number of unformatted bytes/sec */
name|u_short
name|wdp_sectors
decl_stmt|;
comment|/*6 number of sectors per track */
name|short
name|wdp_vendorunique
index|[
literal|3
index|]
decl_stmt|;
comment|/*7,8,9*/
comment|/* controller info */
name|char
name|wdp_serial
index|[
literal|20
index|]
decl_stmt|;
comment|/*10-19 serial number */
name|short
name|wdp_buffertype
decl_stmt|;
comment|/*20 buffer type */
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
name|wdp_buffersize
decl_stmt|;
comment|/*21 buffer size, in 512-byte units */
name|short
name|wdp_necc
decl_stmt|;
comment|/*22 ecc bytes appended */
name|char
name|wdp_rev
index|[
literal|8
index|]
decl_stmt|;
comment|/*23-26 firmware revision */
name|char
name|wdp_model
index|[
literal|40
index|]
decl_stmt|;
comment|/*27-46 model name */
name|char
name|wdp_nsecperint
decl_stmt|;
comment|/*47L sectors per interrupt */
name|char
name|wdp_vendorunique1
decl_stmt|;
comment|/*47H*/
name|short
name|wdp_usedmovsd
decl_stmt|;
comment|/*48 can use double word read/write? */
name|char
name|wdp_vendorunique2
decl_stmt|;
comment|/*49L*/
name|char
name|wdp_capability
decl_stmt|;
comment|/*49H various capability bits */
name|short
name|wdp_cap_validate
decl_stmt|;
comment|/*50 validation for above */
name|char
name|wdp_vendorunique3
decl_stmt|;
comment|/*51L*/
name|char
name|wdp_opiomode
decl_stmt|;
comment|/*51H PIO modes 0-2 */
name|char
name|wdp_vendorunique4
decl_stmt|;
comment|/*52*/
name|char
name|wdp_odmamode
decl_stmt|;
comment|/*52 old DMA modes, not in ATA-3 */
name|short
name|wdp_atavalid
decl_stmt|;
comment|/*53 validation for newer fields */
name|short
name|wdp_currcyls
decl_stmt|;
comment|/*54 */
name|short
name|wdp_currheads
decl_stmt|;
comment|/*55 */
name|short
name|wdp_currsectors
decl_stmt|;
comment|/*56 */
name|short
name|wdp_currsize0
decl_stmt|;
comment|/*57 CHS size*/
name|short
name|wdp_currsize1
decl_stmt|;
comment|/*58 CHS size*/
name|char
name|wdp_currmultsect
decl_stmt|;
comment|/*59L */
name|char
name|wdp_multsectvalid
decl_stmt|;
comment|/*59H */
name|int
name|wdp_lbasize
decl_stmt|;
comment|/*60,61*/
name|short
name|wdp_dmasword
decl_stmt|;
comment|/*62 obsolete in ATA-3 */
name|short
name|wdp_dmamword
decl_stmt|;
comment|/*63 multiword DMA modes */
name|short
name|wdp_eidepiomodes
decl_stmt|;
comment|/*64 advanced PIO modes */
name|short
name|wdp_eidedmamin
decl_stmt|;
comment|/*65 fastest possible DMA timing */
name|short
name|wdp_eidedmanorm
decl_stmt|;
comment|/*66 recommended DMA timing */
name|short
name|wdp_eidepioblind
decl_stmt|;
comment|/*67 fastest possible blind PIO */
name|short
name|wdp_eidepioacked
decl_stmt|;
comment|/*68 fastest possible IORDY PIO */
name|short
name|wdp_reserved69
decl_stmt|;
comment|/*69*/
name|short
name|wdp_reserved70
decl_stmt|;
comment|/*70*/
name|short
name|wdp_reserved71
decl_stmt|;
comment|/*71*/
name|short
name|wdp_reserved72
decl_stmt|;
comment|/*72*/
name|short
name|wdp_reserved73
decl_stmt|;
comment|/*73*/
name|short
name|wdp_reserved74
decl_stmt|;
comment|/*74*/
name|short
name|wdp_queuelen
decl_stmt|;
comment|/*75*/
name|short
name|wdp_reserved76
decl_stmt|;
comment|/*76*/
name|short
name|wdp_reserved77
decl_stmt|;
comment|/*77*/
name|short
name|wdp_reserved78
decl_stmt|;
comment|/*78*/
name|short
name|wdp_reserved79
decl_stmt|;
comment|/*79*/
name|short
name|wdp_versmaj
decl_stmt|;
comment|/*80*/
name|short
name|wdp_versmin
decl_stmt|;
comment|/*81*/
name|short
name|wdp_featsupp1
decl_stmt|;
comment|/*82*/
name|short
name|wdp_featsupp2
decl_stmt|;
comment|/*83*/
name|short
name|wdp_featsupp3
decl_stmt|;
comment|/*84*/
name|short
name|wdp_featenab1
decl_stmt|;
comment|/*85*/
name|short
name|wdp_featenab2
decl_stmt|;
comment|/*86*/
name|short
name|wdp_featenab3
decl_stmt|;
comment|/*87*/
name|short
name|wdp_udmamode
decl_stmt|;
comment|/*88 UltraDMA modes */
name|short
name|wdp_erasetime
decl_stmt|;
comment|/*89*/
name|short
name|wdp_enherasetime
decl_stmt|;
comment|/*90*/
name|short
name|wdp_apmlevel
decl_stmt|;
comment|/*91*/
name|short
name|wdp_reserved92
index|[
literal|34
index|]
decl_stmt|;
comment|/*92*/
name|short
name|wdp_rmvcap
decl_stmt|;
comment|/*93*/
name|short
name|wdp_securelevel
decl_stmt|;
comment|/*94*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * IDE DMA support.  * This is based on what is needed for the IDE DMA function of the Intel  * Triton chipset; hopefully it's general enough to be used for other  * chipsets as well.  *  * To use this:  *	For each drive which you might want to do DMA on, call wdd_candma()  *	to get a cookie.  If it returns a null pointer, then the drive  *	can't do DMA.  Then call wdd_dmainit() to initialize the controller  *	and drive.  wdd_dmainit should leave PIO modes operational, though  *	perhaps with suboptimal performance.  *  *	Check the transfer by calling wdd_dmaverify().  The cookie is what  *	you got before; vaddr is the virtual address of the buffer to be  *	written; len is the length of the buffer; and direction is either  *	B_READ or B_WRITE. This function verifies that the DMA hardware is  *	capable of handling the request you've made.  *  *	Setup the transfer by calling wdd_dmaprep().  This takes the same  *	paramaters as wdd_dmaverify().  *  *	Send a read/write DMA command to the drive.  *  *	Call wdd_dmastart().  *  *	Wait for an interrupt.  Multi-sector transfers will only interrupt  *	at the end of the transfer.  *  *	Call wdd_dmadone().  It will return the status as defined by the  *	WDDS_* constants below.  */
end_comment

begin_struct
struct|struct
name|wddma
block|{
name|void
modifier|*
function_decl|(
modifier|*
name|wdd_candma
function_decl|)
comment|/* returns a cookie if PCI */
parameter_list|(
name|int
name|iobase_wd
parameter_list|,
name|int
name|ctlr
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|wdd_dmaverify
function_decl|)
comment|/* verify that request is DMA-able */
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|,
name|char
modifier|*
name|vaddr
parameter_list|,
name|u_long
name|len
parameter_list|,
name|int
name|direction
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|wdd_dmaprep
function_decl|)
comment|/* prepare DMA hardware */
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|,
name|char
modifier|*
name|vaddr
parameter_list|,
name|u_long
name|len
parameter_list|,
name|int
name|direction
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|wdd_dmastart
function_decl|)
comment|/* begin DMA transfer */
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|wdd_dmadone
function_decl|)
comment|/* DMA transfer completed */
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|wdd_dmastatus
function_decl|)
comment|/* return status of DMA */
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|wdd_dmainit
function_decl|)
comment|/* initialize controller and drive */
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|,
name|struct
name|wdparams
modifier|*
name|wp
parameter_list|,
name|int
function_decl|(
name|wdcmd
function_decl|)
parameter_list|(
name|int
name|mode
parameter_list|,
name|void
modifier|*
name|wdinfo
parameter_list|)
parameter_list|,
name|void
modifier|*
name|wdinfo
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|wdd_iobase
function_decl|)
comment|/* returns iobase address */
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|wdd_altiobase
function_decl|)
comment|/* returns altiobase address */
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* logical status bits returned by wdd_dmastatus */
end_comment

begin_define
define|#
directive|define
name|WDDS_ACTIVE
value|0x0001
end_define

begin_define
define|#
directive|define
name|WDDS_ERROR
value|0x0002
end_define

begin_define
define|#
directive|define
name|WDDS_INTERRUPT
value|0x0004
end_define

begin_define
define|#
directive|define
name|WDDS_BITS
value|"\20\4interrupt\2error\1active"
end_define

begin_comment
comment|/* defines for ATA timing modes */
end_comment

begin_define
define|#
directive|define
name|WDDMA_GRPMASK
value|0xf8
end_define

begin_define
define|#
directive|define
name|WDDMA_MODEMASK
value|0x07
end_define

begin_comment
comment|/* flow-controlled PIO modes */
end_comment

begin_define
define|#
directive|define
name|WDDMA_PIO
value|0x10
end_define

begin_define
define|#
directive|define
name|WDDMA_PIO3
value|0x10
end_define

begin_define
define|#
directive|define
name|WDDMA_PIO4
value|0x11
end_define

begin_comment
comment|/* multi-word DMA timing modes */
end_comment

begin_define
define|#
directive|define
name|WDDMA_MDMA
value|0x20
end_define

begin_define
define|#
directive|define
name|WDDMA_MDMA0
value|0x20
end_define

begin_define
define|#
directive|define
name|WDDMA_MDMA1
value|0x21
end_define

begin_define
define|#
directive|define
name|WDDMA_MDMA2
value|0x22
end_define

begin_comment
comment|/* Ultra DMA timing modes */
end_comment

begin_define
define|#
directive|define
name|WDDMA_UDMA
value|0x40
end_define

begin_define
define|#
directive|define
name|WDDMA_UDMA0
value|0x40
end_define

begin_define
define|#
directive|define
name|WDDMA_UDMA1
value|0x41
end_define

begin_define
define|#
directive|define
name|WDDMA_UDMA2
value|0x42
end_define

begin_define
define|#
directive|define
name|Q_CMD640B
value|0x00000001
end_define

begin_comment
comment|/* CMD640B quirk: serialize IDE channels */
end_comment

begin_function_decl
name|void
name|wdc_pci
parameter_list|(
name|int
name|quirks
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|wddma
name|wddma
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|wdintr
parameter_list|(
name|void
modifier|*
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

end_unit

