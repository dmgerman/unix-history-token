begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1993 by Holger Veit (data part)  * Copyright 1993 by Brian Moore (audio part)  * Changes Copyright 1993 by Gary Clark II  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This software was developed by Holger Veit and Brian Moore  *	for use with "386BSD" and similar operating systems.  *    "Similar operating systems" includes mainly non-profit oriented  *    systems for research and education, including but not restricted to  *    "NetBSD", "FreeBSD", "Mach" (by CMU).  * 4. Neither the name of the developer(s) nor the name "386BSD"  *    may be used to endorse or promote products derived from this  *    software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE DEVELOPER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE DEVELOPER(S) BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * This file contains definitions for some cdrom control commands  * and status codes. This info was "inherited" from the DOS MTMCDE.SYS  * driver, and is thus not complete (and may even be wrong). Some day  * the manufacturer or anyone else might provide better documentation,  * so this file (and the driver) will then have a better quality.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MCD_H
end_ifndef

begin_define
define|#
directive|define
name|MCD_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|2
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|char
name|bcd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|M_msf
parameter_list|(
name|msf
parameter_list|)
value|msf[0]
end_define

begin_define
define|#
directive|define
name|S_msf
parameter_list|(
name|msf
parameter_list|)
value|msf[1]
end_define

begin_define
define|#
directive|define
name|F_msf
parameter_list|(
name|msf
parameter_list|)
value|msf[2]
end_define

begin_comment
comment|/* io lines used */
end_comment

begin_define
define|#
directive|define
name|MCD_IO_BASE
value|0x300
end_define

begin_define
define|#
directive|define
name|mcd_command
value|0
end_define

begin_define
define|#
directive|define
name|mcd_status
value|0
end_define

begin_define
define|#
directive|define
name|mcd_rdata
value|0
end_define

begin_define
define|#
directive|define
name|mcd_reset
value|1
end_define

begin_define
define|#
directive|define
name|mcd_ctl2
value|2
end_define

begin_comment
comment|/* XXX Is this right? */
end_comment

begin_define
define|#
directive|define
name|mcd_config
value|3
end_define

begin_define
define|#
directive|define
name|MCD_MASK_DMA
value|0x07
end_define

begin_comment
comment|/* bits 2-0 = DMA channel */
end_comment

begin_define
define|#
directive|define
name|MCD_MASK_IRQ
value|0x70
end_define

begin_comment
comment|/* bits 6-4 = INT number */
end_comment

begin_comment
comment|/* 001 = int 2,9 */
end_comment

begin_comment
comment|/* 010 = int 3 */
end_comment

begin_comment
comment|/* 011 = int 5 */
end_comment

begin_comment
comment|/* 100 = int 10 */
end_comment

begin_comment
comment|/* 101 = int 11 */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|MFL_DATA_NOT_AVAIL
value|0x02
end_define

begin_define
define|#
directive|define
name|MFL_STATUS_NOT_AVAIL
value|0x04
end_define

begin_comment
comment|/* New Commands */
end_comment

begin_define
define|#
directive|define
name|M_RESET
value|0x00
end_define

begin_define
define|#
directive|define
name|M_PICKLE
value|0x04
end_define

begin_comment
comment|/* ports */
end_comment

begin_define
define|#
directive|define
name|MCD_DATA
value|0
end_define

begin_define
define|#
directive|define
name|MCD_FLAGS
value|1
end_define

begin_define
define|#
directive|define
name|MCD_CTRL
value|2
end_define

begin_define
define|#
directive|define
name|CHANNEL
value|3
end_define

begin_comment
comment|/* XXX ??? */
end_comment

begin_comment
comment|/* Status bits */
end_comment

begin_define
define|#
directive|define
name|MCD_ST_DOOROPEN
value|0x80
end_define

begin_define
define|#
directive|define
name|MCD_ST_DSKIN
value|0x40
end_define

begin_define
define|#
directive|define
name|MCD_ST_DSKCHNG
value|0x20
end_define

begin_define
define|#
directive|define
name|MCD_ST_SPINNING
value|0x10
end_define

begin_define
define|#
directive|define
name|MCD_ST_AUDIODISK
value|0x08
end_define

begin_comment
comment|/* Audio Disk is in */
end_comment

begin_define
define|#
directive|define
name|MCD_ST_BUSY
value|0x04
end_define

begin_define
define|#
directive|define
name|MCD_ST_AUDIOBSY
value|0x02
end_define

begin_comment
comment|/* Audio Disk is Playing */
end_comment

begin_define
define|#
directive|define
name|MCD_ST_CMDCHECK
value|0x01
end_define

begin_comment
comment|/* Command error */
end_comment

begin_comment
comment|/* commands known by the controller */
end_comment

begin_define
define|#
directive|define
name|MCD_CMDRESET
value|0x00
end_define

begin_define
define|#
directive|define
name|MCD_CMDGETVOLINFO
value|0x10
end_define

begin_comment
comment|/* gets mcd_volinfo */
end_comment

begin_define
define|#
directive|define
name|MCD_CMDGETDISKINFO
value|0x11
end_define

begin_comment
comment|/* gets	mcd_disk information */
end_comment

begin_define
define|#
directive|define
name|MCD_CMDGETQCHN
value|0x20
end_define

begin_comment
comment|/* gets mcd_qchninfo */
end_comment

begin_define
define|#
directive|define
name|MCD_CMDGETSENSE
value|0x30
end_define

begin_comment
comment|/* gets	sense info */
end_comment

begin_define
define|#
directive|define
name|MCD_CMDGETSTAT
value|0x40
end_define

begin_comment
comment|/* gets a byte of status */
end_comment

begin_define
define|#
directive|define
name|MCD_CMDSETMODE
value|0x50
end_define

begin_comment
comment|/* set transmission mode, needs byte */
end_comment

begin_define
define|#
directive|define
name|MCD_MDBIT_TESTMODE
value|0x80
end_define

begin_comment
comment|/* 0 = DATALENGTH setting is valid */
end_comment

begin_define
define|#
directive|define
name|MCD_MDBIT_DATALENGTH
value|0x40
end_define

begin_comment
comment|/* 0 = Read User Data Only */
end_comment

begin_comment
comment|/* 1 = Read Raw	sectors	(2352 bytes) */
end_comment

begin_define
define|#
directive|define
name|MCDBLK
value|2048
end_define

begin_comment
comment|/* for cooked mode */
end_comment

begin_define
define|#
directive|define
name|MCDRBLK
value|sizeof(struct mcd_rawsector)
end_define

begin_comment
comment|/* for raw mode	*/
end_comment

begin_define
define|#
directive|define
name|MCD_MDBIT_ECCMODE
value|0x20
end_define

begin_comment
comment|/* 0 = Use secondary correction	*/
end_comment

begin_comment
comment|/* 1 = Don't use secondary ECC */
end_comment

begin_define
define|#
directive|define
name|MCD_MDBIT_SPINDOWN
value|0x08
end_define

begin_comment
comment|/* 0 = Spin Up,	1 = Spin Down */
end_comment

begin_define
define|#
directive|define
name|MCD_MDBIT_GET_TOC
value|0x04
end_define

begin_comment
comment|/* 0 = Get UPC on next GETQCHAN	*/
end_comment

begin_comment
comment|/* 1 = Get TOC on GETQCHAN */
end_comment

begin_define
define|#
directive|define
name|MCD_MDBIT_MUTEDATA
value|0x01
end_define

begin_comment
comment|/* 1 = Don't play back Data as audio */
end_comment

begin_define
define|#
directive|define
name|MCD_MD_RAW
value|(MCD_MDBIT_DATALENGTH|MCD_MDBIT_ECCMODE|MCD_MDBIT_MUTEDATA)
end_define

begin_define
define|#
directive|define
name|MCD_MD_COOKED
value|(MCD_MDBIT_MUTEDATA)
end_define

begin_define
define|#
directive|define
name|MCD_MD_TOC
value|(MCD_MDBIT_GET_TOC|MCD_MDBIT_MUTEDATA)
end_define

begin_define
define|#
directive|define
name|MCD_CMDSTOPAUDIO
value|0x70
end_define

begin_define
define|#
directive|define
name|MCD_CMDSTOPAUDIOTIME
value|0x80
end_define

begin_define
define|#
directive|define
name|MCD_CMDGETVOLUME
value|0x8E
end_define

begin_comment
comment|/* gets mcd_volume */
end_comment

begin_define
define|#
directive|define
name|MCD_CMDSETDRIVEMODE
value|0xA0
end_define

begin_comment
comment|/* Set drive mode */
end_comment

begin_define
define|#
directive|define
name|MCD_READUPC
value|0xA2
end_define

begin_comment
comment|/* Get UPC info	*/
end_comment

begin_define
define|#
directive|define
name|MCD_CMDSETVOLUME
value|0xAE
end_define

begin_comment
comment|/* sets mcd_volume */
end_comment

begin_define
define|#
directive|define
name|MCD_CMDREAD1
value|0xB0
end_define

begin_comment
comment|/* read n sectors */
end_comment

begin_define
define|#
directive|define
name|MCD_CMDSINGLESPEEDREAD
value|0xC0
end_define

begin_comment
comment|/* read	from-to	*/
end_comment

begin_define
define|#
directive|define
name|MCD_CMDSTARTAUDIOMSF
value|0xC1
end_define

begin_comment
comment|/* read	audio data */
end_comment

begin_define
define|#
directive|define
name|MCD_CMDDOUBLESPEEDREAD
value|0xC1
end_define

begin_comment
comment|/* Read	lots of	data from the drive */
end_comment

begin_define
define|#
directive|define
name|MCD_CMDGETDRIVEMODE
value|0xC2
end_define

begin_comment
comment|/* Get the drive mode */
end_comment

begin_define
define|#
directive|define
name|MCD_CMDREAD
value|0xC3
end_define

begin_comment
comment|/* Read	data from the drive */
end_comment

begin_define
define|#
directive|define
name|MCD_CMDSETINTERLEAVE
value|0xC8
end_define

begin_comment
comment|/* Adjust the interleave */
end_comment

begin_define
define|#
directive|define
name|MCD_CMDCONTINFO
value|0xDC
end_define

begin_comment
comment|/* Get controller info */
end_comment

begin_define
define|#
directive|define
name|MCD_CMDSTOP
value|0xF0
end_define

begin_comment
comment|/* Stop	everything */
end_comment

begin_define
define|#
directive|define
name|MCD_CMDEJECTDISK
value|0xF6
end_define

begin_define
define|#
directive|define
name|MCD_CMDCLOSETRAY
value|0xF8
end_define

begin_define
define|#
directive|define
name|MCD_CMDLOCKDRV
value|0xFE
end_define

begin_comment
comment|/* needs byte */
end_comment

begin_define
define|#
directive|define
name|MCD_LK_UNLOCK
value|0x00
end_define

begin_define
define|#
directive|define
name|MCD_LK_LOCK
value|0x01
end_define

begin_define
define|#
directive|define
name|MCD_LK_TEST
value|0x02
end_define

begin_comment
comment|/* DMA Enable Stuff */
end_comment

begin_define
define|#
directive|define
name|MCD_DMA_IRQFLAGS
value|0x10
end_define

begin_comment
comment|/* Set data0 for IRQ click */
end_comment

begin_define
define|#
directive|define
name|MCD_DMA_PREIRQ
value|0x01
end_define

begin_comment
comment|/* All of these	are for	*/
end_comment

begin_define
define|#
directive|define
name|MCD_DMA_POSTIRQ
value|0x02
end_define

begin_comment
comment|/* MCD_DMA_IRQFLAG...	*/
end_comment

begin_define
define|#
directive|define
name|MCD_DMA_ERRIRQ
value|0x04
end_define

begin_comment
comment|/*			*/
end_comment

begin_define
define|#
directive|define
name|MCD_DMA_TIMEOUT
value|0x08
end_define

begin_comment
comment|/* Set data0 for DMA timeout */
end_comment

begin_define
define|#
directive|define
name|MCD_DMA_UPCFLAG
value|0x04
end_define

begin_comment
comment|/* 1 = Next command will be READUPC */
end_comment

begin_define
define|#
directive|define
name|MCD_DMA_DMAMODE
value|0x02
end_define

begin_comment
comment|/* 1 = Data uses DMA */
end_comment

begin_define
define|#
directive|define
name|MCD_DMA_TRANSFERLENGTH
value|0x01
end_define

begin_comment
comment|/* data0 = MSB,	data1 =	LSB of block length */
end_comment

begin_struct
struct|struct
name|mcd_dma_mode
block|{
name|u_char
name|dma_mode
decl_stmt|;
name|u_char
name|data0
decl_stmt|;
comment|/* If dma_mode& 0x10: Use IRQ settings	*/
name|u_char
name|data1
decl_stmt|;
comment|/* Used	if dma_mode& 0x01 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mcd_volinfo
block|{
name|bcd_t
name|trk_low
decl_stmt|;
name|bcd_t
name|trk_high
decl_stmt|;
name|bcd_t
name|vol_msf
index|[
literal|3
index|]
decl_stmt|;
name|bcd_t
name|trk1_msf
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mcd_qchninfo
block|{
name|u_char
name|addr_type
range|:
literal|4
decl_stmt|;
name|u_char
name|control
range|:
literal|4
decl_stmt|;
name|u_char
name|trk_no
decl_stmt|;
name|u_char
name|idx_no
decl_stmt|;
name|bcd_t
name|trk_size_msf
index|[
literal|3
index|]
decl_stmt|;
name|u_char
label|:
literal|8
expr_stmt|;
name|bcd_t
name|hd_pos_msf
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mcd_volume
block|{
name|u_char
name|v0l
decl_stmt|;
name|u_char
name|v0rs
decl_stmt|;
name|u_char
name|v0r
decl_stmt|;
name|u_char
name|v0ls
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mcd_holdtime
block|{
name|u_char
name|units_of_ten_seconds
decl_stmt|;
comment|/* If this is 0, the default (12) is used */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mcd_read1
block|{
name|bcd_t
name|start_msf
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|nsec
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mcd_read2
block|{
name|bcd_t
name|start_msf
index|[
literal|3
index|]
decl_stmt|;
name|bcd_t
name|end_msf
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mcd_rawsector
block|{
name|u_char
name|sync1
index|[
literal|12
index|]
decl_stmt|;
name|u_char
name|header
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|subheader1
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|subheader2
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|data
index|[
name|MCDBLK
index|]
decl_stmt|;
name|u_char
name|ecc_bits
index|[
literal|280
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|2
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|4
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MCD_H */
end_comment

end_unit

