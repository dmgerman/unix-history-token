begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 2004,2005 Joerg Wunsch  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)sun_disklabel.h	8.1 (Berkeley) 6/11/93  *	$NetBSD: disklabel.h,v 1.2 1998/08/22 14:55:28 mrg Exp $  *  * $FreeBSD$   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SUN_DISKLABEL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SUN_DISKLABEL_H_
end_define

begin_comment
comment|/*  * SunOS/Solaris disk label layout (partial).  *   * Suns disk label format contains a lot of historical baggage which we   * ignore entirely.  The structure below contains the relevant bits and the  * _enc/_dec functions encode/decode only these fields.  */
end_comment

begin_define
define|#
directive|define
name|SUN_DKMAGIC
value|55998
end_define

begin_define
define|#
directive|define
name|SUN_NPART
value|8
end_define

begin_define
define|#
directive|define
name|SUN_RAWPART
value|2
end_define

begin_define
define|#
directive|define
name|SUN_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|SUN_VTOC_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|SUN_VTOC_SANE
value|0x600DDEEE
end_define

begin_comment
comment|/* SVR4-compatible VTOC is "sane". */
end_comment

begin_define
define|#
directive|define
name|SUN_VOLNAME_LEN
value|8
end_define

begin_comment
comment|/*  * XXX: I am actually not sure if this should be "16 sectors" or "8192 bytes".  * XXX: Considering that Sun went to the effort of getting 512 byte compatible  * XXX: CDROM drives produced my guess is that Sun computers stand little or  * XXX: even no chance of running, much less booting on !=512 byte media.  * XXX: Define this is in terms of bytes since that is easier for us.  */
end_comment

begin_define
define|#
directive|define
name|SUN_BOOTSIZE
value|8192
end_define

begin_comment
comment|/* partition info */
end_comment

begin_struct
struct|struct
name|sun_dkpart
block|{
name|u_int32_t
name|sdkp_cyloffset
decl_stmt|;
comment|/* starting cylinder */
name|u_int32_t
name|sdkp_nsectors
decl_stmt|;
comment|/* number of sectors */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sun_vtoc_info
block|{
name|u_int16_t
name|svtoc_tag
decl_stmt|;
comment|/* partition tag */
name|u_int16_t
name|svtoc_flag
decl_stmt|;
comment|/* partition flags */
block|}
struct|;
end_struct

begin_comment
comment|/* known partition tag values */
end_comment

begin_define
define|#
directive|define
name|VTOC_UNASSIGNED
value|0x00
end_define

begin_define
define|#
directive|define
name|VTOC_BOOT
value|0x01
end_define

begin_define
define|#
directive|define
name|VTOC_ROOT
value|0x02
end_define

begin_define
define|#
directive|define
name|VTOC_SWAP
value|0x03
end_define

begin_define
define|#
directive|define
name|VTOC_USR
value|0x04
end_define

begin_define
define|#
directive|define
name|VTOC_BACKUP
value|0x05
end_define

begin_comment
comment|/* "c" partition, covers entire disk */
end_comment

begin_define
define|#
directive|define
name|VTOC_STAND
value|0x06
end_define

begin_define
define|#
directive|define
name|VTOC_VAR
value|0x07
end_define

begin_define
define|#
directive|define
name|VTOC_HOME
value|0x08
end_define

begin_define
define|#
directive|define
name|VTOC_ALTSCTR
value|0x09
end_define

begin_comment
comment|/* alternate sector partition */
end_comment

begin_define
define|#
directive|define
name|VTOC_CACHE
value|0x0a
end_define

begin_comment
comment|/* Solaris cachefs partition */
end_comment

begin_define
define|#
directive|define
name|VTOC_VXVM_PUB
value|0x0e
end_define

begin_comment
comment|/* VxVM public region */
end_comment

begin_define
define|#
directive|define
name|VTOC_VXVM_PRIV
value|0x0f
end_define

begin_comment
comment|/* VxVM private region */
end_comment

begin_comment
comment|/* VTOC partition flags */
end_comment

begin_define
define|#
directive|define
name|VTOC_UNMNT
value|0x01
end_define

begin_comment
comment|/* unmountable partition */
end_comment

begin_define
define|#
directive|define
name|VTOC_RONLY
value|0x10
end_define

begin_comment
comment|/* partition is read/only */
end_comment

begin_struct
struct|struct
name|sun_disklabel
block|{
name|char
name|sl_text
index|[
literal|128
index|]
decl_stmt|;
comment|/* SVR4 VTOC information */
name|u_int32_t
name|sl_vtoc_vers
decl_stmt|;
comment|/* == SUN_VTOC_VERSION */
name|char
name|sl_vtoc_volname
index|[
name|SUN_VOLNAME_LEN
index|]
decl_stmt|;
name|u_int16_t
name|sl_vtoc_nparts
decl_stmt|;
comment|/* == SUN_NPART */
name|struct
name|sun_vtoc_info
name|sl_vtoc_map
index|[
name|SUN_NPART
index|]
decl_stmt|;
comment|/* partition tag/flag */
name|u_int32_t
name|sl_vtoc_sane
decl_stmt|;
comment|/* == SUN_VTOC_SANE */
comment|/* Sun label information */
name|u_int16_t
name|sl_rpm
decl_stmt|;
comment|/* rotational speed */
name|u_int16_t
name|sl_pcylinders
decl_stmt|;
comment|/* number of physical cyls */
name|u_int16_t
name|sl_sparespercyl
decl_stmt|;
comment|/* spare sectors per cylinder */
name|u_int16_t
name|sl_interleave
decl_stmt|;
comment|/* interleave factor */
name|u_int16_t
name|sl_ncylinders
decl_stmt|;
comment|/* data cylinders */
name|u_int16_t
name|sl_acylinders
decl_stmt|;
comment|/* alternate cylinders */
name|u_int16_t
name|sl_ntracks
decl_stmt|;
comment|/* tracks per cylinder */
name|u_int16_t
name|sl_nsectors
decl_stmt|;
comment|/* sectors per track */
name|struct
name|sun_dkpart
name|sl_part
index|[
name|SUN_NPART
index|]
decl_stmt|;
comment|/* partition layout */
name|u_int16_t
name|sl_magic
decl_stmt|;
comment|/* == SUN_DKMAGIC */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|sunlabel_dec
parameter_list|(
name|void
specifier|const
modifier|*
name|pp
parameter_list|,
name|struct
name|sun_disklabel
modifier|*
name|sl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sunlabel_enc
parameter_list|(
name|void
modifier|*
name|pp
parameter_list|,
name|struct
name|sun_disklabel
modifier|*
name|sl
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SUN_DISKLABEL_H_ */
end_comment

end_unit

