begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)sun_disklabel.h	8.1 (Berkeley) 6/11/93  *	$NetBSD: disklabel.h,v 1.2 1998/08/22 14:55:28 mrg Exp $  *  * $FreeBSD$   */
end_comment

begin_comment
comment|/*  * SunOS disk label layout (only relevant portions discovered here).  */
end_comment

begin_define
define|#
directive|define
name|SUN_DKMAGIC
value|55998
end_define

begin_comment
comment|/* geometry info */
end_comment

begin_struct
struct|struct
name|sun_dkgeom
block|{
name|u_short
name|sdkc_ncylinders
decl_stmt|;
comment|/* data cylinders */
name|u_short
name|sdkc_acylinders
decl_stmt|;
comment|/* alternate cylinders */
name|u_short
name|sdkc_xxx1
decl_stmt|;
name|u_short
name|sdkc_ntracks
decl_stmt|;
comment|/* tracks per cylinder */
name|u_short
name|sdkc_xxx2
decl_stmt|;
name|u_short
name|sdkc_nsectors
decl_stmt|;
comment|/* sectors per track */
name|u_short
name|sdkc_interleave
decl_stmt|;
comment|/* interleave factor */
name|u_short
name|sdkc_xxx3
decl_stmt|;
name|u_short
name|sdkc_xxx4
decl_stmt|;
name|u_short
name|sdkc_sparespercyl
decl_stmt|;
comment|/* spare sectors per cylinder */
name|u_short
name|sdkc_rpm
decl_stmt|;
comment|/* rotational speed */
name|u_short
name|sdkc_pcylinders
decl_stmt|;
comment|/* physical cylinders */
name|u_short
name|sdkc_xxx5
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* controller info */
end_comment

begin_struct
struct|struct
name|sun_dkctlr
block|{
name|int
name|sdkc_addr
decl_stmt|;
comment|/* controller address */
name|short
name|sdkc_unit
decl_stmt|;
comment|/* unit (slave) address */
name|short
name|sdkc_type
decl_stmt|;
comment|/* controller type */
name|short
name|sdkc_flags
decl_stmt|;
comment|/* flags */
block|}
struct|;
end_struct

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
name|sun_disklabel
block|{
comment|/* total size = 512 bytes */
name|char
name|sl_text
index|[
literal|128
index|]
decl_stmt|;
name|char
name|sl_xxx1
index|[
literal|292
index|]
decl_stmt|;
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
name|char
name|sl_xxx3
index|[
literal|4
index|]
decl_stmt|;
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
name|char
name|sl_xxx4
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|sun_dkpart
name|sl_part
index|[
literal|8
index|]
decl_stmt|;
comment|/* partition layout */
name|u_int16_t
name|sl_magic
decl_stmt|;
comment|/* == SUN_DKMAGIC */
name|u_int16_t
name|sl_cksum
decl_stmt|;
comment|/* xor checksum of all shorts */
block|}
struct|;
end_struct

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|sun_disklabel
argument_list|)
operator|==
literal|512
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

