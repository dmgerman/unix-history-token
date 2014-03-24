begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: bat.h,v 1.2 1999/12/18 01:36:06 thorpej Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_BAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_BAT_H_
end_define

begin_struct
struct|struct
name|bat
block|{
name|u_int32_t
name|batu
decl_stmt|;
name|u_int32_t
name|batl
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Lower BAT bits (all but PowerPC 601): */
end_comment

begin_define
define|#
directive|define
name|BAT_PBS
value|0xfffe0000
end_define

begin_comment
comment|/* physical block start */
end_comment

begin_define
define|#
directive|define
name|BAT_W
value|0x00000040
end_define

begin_comment
comment|/* 1 = write-through, 0 = write-back */
end_comment

begin_define
define|#
directive|define
name|BAT_I
value|0x00000020
end_define

begin_comment
comment|/* cache inhibit */
end_comment

begin_define
define|#
directive|define
name|BAT_M
value|0x00000010
end_define

begin_comment
comment|/* memory coherency enable */
end_comment

begin_define
define|#
directive|define
name|BAT_G
value|0x00000008
end_define

begin_comment
comment|/* guarded region */
end_comment

begin_define
define|#
directive|define
name|BAT_PP_NONE
value|0x00000000
end_define

begin_comment
comment|/* no access permission */
end_comment

begin_define
define|#
directive|define
name|BAT_PP_RO_S
value|0x00000001
end_define

begin_comment
comment|/* read-only (soft) */
end_comment

begin_define
define|#
directive|define
name|BAT_PP_RW
value|0x00000002
end_define

begin_comment
comment|/* read/write */
end_comment

begin_define
define|#
directive|define
name|BAT_PP_RO
value|0x00000003
end_define

begin_comment
comment|/* read-only */
end_comment

begin_comment
comment|/* Upper BAT bits (all but PowerPC 601): */
end_comment

begin_define
define|#
directive|define
name|BAT_EBS
value|0xfffe0000
end_define

begin_comment
comment|/* effective block start */
end_comment

begin_define
define|#
directive|define
name|BAT_BL
value|0x00001ffc
end_define

begin_comment
comment|/* block length */
end_comment

begin_define
define|#
directive|define
name|BAT_Vs
value|0x00000002
end_define

begin_comment
comment|/* valid in supervisor mode */
end_comment

begin_define
define|#
directive|define
name|BAT_Vu
value|0x00000001
end_define

begin_comment
comment|/* valid in user mode */
end_comment

begin_define
define|#
directive|define
name|BAT_V
value|(BAT_Vs|BAT_Vu)
end_define

begin_comment
comment|/* Block Length encoding (all but PowerPC 601): */
end_comment

begin_define
define|#
directive|define
name|BAT_BL_128K
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BAT_BL_256K
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BAT_BL_512K
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|BAT_BL_1M
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|BAT_BL_2M
value|0x0000003c
end_define

begin_define
define|#
directive|define
name|BAT_BL_4M
value|0x0000007c
end_define

begin_define
define|#
directive|define
name|BAT_BL_8M
value|0x000000fc
end_define

begin_define
define|#
directive|define
name|BAT_BL_16M
value|0x000001fc
end_define

begin_define
define|#
directive|define
name|BAT_BL_32M
value|0x000003fc
end_define

begin_define
define|#
directive|define
name|BAT_BL_64M
value|0x000007fc
end_define

begin_define
define|#
directive|define
name|BAT_BL_128M
value|0x00000ffc
end_define

begin_define
define|#
directive|define
name|BAT_BL_256M
value|0x00001ffc
end_define

begin_define
define|#
directive|define
name|BATU
parameter_list|(
name|va
parameter_list|,
name|len
parameter_list|,
name|v
parameter_list|)
define|\
value|(((va)& BAT_EBS) | ((len)& BAT_BL) | ((v)& BAT_V))
end_define

begin_define
define|#
directive|define
name|BATL
parameter_list|(
name|pa
parameter_list|,
name|wimg
parameter_list|,
name|pp
parameter_list|)
define|\
value|(((pa)& BAT_PBS) | (wimg) | (pp))
end_define

begin_comment
comment|/* Lower BAT bits (PowerPC 601): */
end_comment

begin_define
define|#
directive|define
name|BAT601_PBN
value|0xfffe0000
end_define

begin_comment
comment|/* physical block number */
end_comment

begin_define
define|#
directive|define
name|BAT601_V
value|0x00000040
end_define

begin_comment
comment|/* valid */
end_comment

begin_define
define|#
directive|define
name|BAT601_BSM
value|0x0000003f
end_define

begin_comment
comment|/* block size mask */
end_comment

begin_comment
comment|/* Upper BAT bits (PowerPC 601): */
end_comment

begin_define
define|#
directive|define
name|BAT601_BLPI
value|0xfffe0000
end_define

begin_comment
comment|/* block logical page index */
end_comment

begin_define
define|#
directive|define
name|BAT601_W
value|0x00000040
end_define

begin_comment
comment|/* 1 = write-through, 0 = write-back */
end_comment

begin_define
define|#
directive|define
name|BAT601_I
value|0x00000020
end_define

begin_comment
comment|/* cache inhibit */
end_comment

begin_define
define|#
directive|define
name|BAT601_M
value|0x00000010
end_define

begin_comment
comment|/* memory coherency enable */
end_comment

begin_define
define|#
directive|define
name|BAT601_Ks
value|0x00000008
end_define

begin_comment
comment|/* key-supervisor */
end_comment

begin_define
define|#
directive|define
name|BAT601_Ku
value|0x00000004
end_define

begin_comment
comment|/* key-user */
end_comment

begin_comment
comment|/*  * Permission bits on the PowerPC 601 are modified by the appropriate  * Key bit:  *  *	Key	PP	Access  *	0	NONE	read/write  *	0	RO_S	read/write  *	0	RW	read/write  *	0	RO	read-only  *  *	1	NONE	none  *	1	RO_S	read-only  *	1	RW	read/write  *	1	RO	read-only  */
end_comment

begin_define
define|#
directive|define
name|BAT601_PP_NONE
value|0x00000000
end_define

begin_comment
comment|/* no access permission */
end_comment

begin_define
define|#
directive|define
name|BAT601_PP_RO_S
value|0x00000001
end_define

begin_comment
comment|/* read-only (soft) */
end_comment

begin_define
define|#
directive|define
name|BAT601_PP_RW
value|0x00000002
end_define

begin_comment
comment|/* read/write */
end_comment

begin_define
define|#
directive|define
name|BAT601_PP_RO
value|0x00000003
end_define

begin_comment
comment|/* read-only */
end_comment

begin_comment
comment|/* Block Size Mask encoding (PowerPC 601): */
end_comment

begin_define
define|#
directive|define
name|BAT601_BSM_128K
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BAT601_BSM_256K
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BAT601_BSM_512K
value|0x00000003
end_define

begin_define
define|#
directive|define
name|BAT601_BSM_1M
value|0x00000007
end_define

begin_define
define|#
directive|define
name|BAT601_BSM_2M
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|BAT601_BSM_4M
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|BAT601_BSM_8M
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|BATU601
parameter_list|(
name|va
parameter_list|,
name|wim
parameter_list|,
name|key
parameter_list|,
name|pp
parameter_list|)
define|\
value|(((va)& BAT601_BLPI) | (wim) | (key) | (pp))
end_define

begin_define
define|#
directive|define
name|BATL601
parameter_list|(
name|pa
parameter_list|,
name|size
parameter_list|,
name|v
parameter_list|)
define|\
value|(((pa)& BAT601_PBN) | (v) | (size))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|bat
name|battable
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_BAT_H_ */
end_comment

end_unit

