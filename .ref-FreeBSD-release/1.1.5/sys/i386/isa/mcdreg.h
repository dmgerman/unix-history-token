begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1993 by Holger Veit (data part)  * Copyright 1993 by Brian Moore (audio part)  * Changes Copyright 1993 by Gary Clark II   * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This software was developed by Holger Veit and Brian Moore  *	for use with "386BSD" and similar operating systems.  *    "Similar operating systems" includes mainly non-profit oriented  *    systems for research and education, including but not restricted to  *    "NetBSD", "FreeBSD", "Mach" (by CMU).  * 4. Neither the name of the developer(s) nor the name "386BSD"  *    may be used to endorse or promote products derived from this  *    software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE DEVELOPER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE DEVELOPER(S) BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * This file contains definitions for some cdrom control commands  * and status codes. This info was "inherited" from the DOS MTMCDE.SYS  * driver, and is thus not complete (and may even be wrong). Some day  * the manufacturer or anyone else might provide better documentation,  * so this file (and the driver) will then have a better quality.  *  *	$Id: mcdreg.h,v 1.2 1994/01/16 23:34:17 jkh Exp $  */
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
name|mcd_xfer
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
name|STATUS_AVAIL
value|0xB
end_define

begin_define
define|#
directive|define
name|DATA_AVAIL
value|0xF
end_define

begin_comment
comment|/* New Flags */
end_comment

begin_define
define|#
directive|define
name|M_STATUS_AVAIL
value|0xFB
end_define

begin_define
define|#
directive|define
name|M_DATA_AVAIL
value|0xFD
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
name|MCD_CMDGETQCHN
value|0x20
end_define

begin_comment
comment|/* gets mcd_qchninfo */
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
name|MCD_MD_RAW
value|0x60
end_define

begin_define
define|#
directive|define
name|MCD_MD_COOKED
value|0x01
end_define

begin_define
define|#
directive|define
name|MCD_MD_TOC
value|0x05
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
name|MCD_CMDGETVOLUME
value|0x8E
end_define

begin_comment
comment|/* gets mcd_volume */
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
name|MCD_CMDREAD2
value|0xC0
end_define

begin_comment
comment|/* read from-to */
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
name|ctrl_adr
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MCD_H */
end_comment

end_unit

