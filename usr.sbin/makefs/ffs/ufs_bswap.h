begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ufs_bswap.h,v 1.13 2003/10/05 17:48:50 bouyer Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 Manuel Bouyer.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Manuel Bouyer.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_UFS_BSWAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_UFS_UFS_BSWAP_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL_OPT
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_ffs.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|"makefs.h"
end_include

begin_comment
comment|/* Macros to access UFS flags */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FFS_EI
end_ifdef

begin_define
define|#
directive|define
name|UFS_MPNEEDSWAP
parameter_list|(
name|mp
parameter_list|)
value|(VFSTOUFS(mp)->um_flags& UFS_NEEDSWAP)
end_define

begin_define
define|#
directive|define
name|UFS_FSNEEDSWAP
parameter_list|(
name|fs
parameter_list|)
value|((fs)->fs_flags& FS_SWAPPED)
end_define

begin_define
define|#
directive|define
name|UFS_IPNEEDSWAP
parameter_list|(
name|ip
parameter_list|)
value|UFS_MPNEEDSWAP(ITOV(ip)->v_mount)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UFS_MPNEEDSWAP
parameter_list|(
name|mp
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|UFS_FSNEEDSWAP
parameter_list|(
name|fs
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|UFS_IPNEEDSWAP
parameter_list|(
name|ip
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|FFS_EI
argument_list|)
end_if

begin_comment
comment|/* inlines for access to swapped data */
end_comment

begin_decl_stmt
specifier|static
name|__inline
name|u_int16_t
name|ufs_rw16
name|__P
argument_list|(
operator|(
name|u_int16_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|u_int32_t
name|ufs_rw32
name|__P
argument_list|(
operator|(
name|u_int32_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|u_int64_t
name|ufs_rw64
name|__P
argument_list|(
operator|(
name|u_int64_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|u_int16_t
name|ufs_rw16
parameter_list|(
name|u_int16_t
name|a
parameter_list|,
name|int
name|ns
parameter_list|)
block|{
return|return
operator|(
operator|(
name|ns
operator|)
condition|?
name|bswap16
argument_list|(
name|a
argument_list|)
else|:
operator|(
name|a
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int32_t
name|ufs_rw32
parameter_list|(
name|u_int32_t
name|a
parameter_list|,
name|int
name|ns
parameter_list|)
block|{
return|return
operator|(
operator|(
name|ns
operator|)
condition|?
name|bswap32
argument_list|(
name|a
argument_list|)
else|:
operator|(
name|a
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int64_t
name|ufs_rw64
parameter_list|(
name|u_int64_t
name|a
parameter_list|,
name|int
name|ns
parameter_list|)
block|{
return|return
operator|(
operator|(
name|ns
operator|)
condition|?
name|bswap64
argument_list|(
name|a
argument_list|)
else|:
operator|(
name|a
operator|)
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ufs_rw16
parameter_list|(
name|a
parameter_list|,
name|ns
parameter_list|)
value|((uint16_t)(a))
end_define

begin_define
define|#
directive|define
name|ufs_rw32
parameter_list|(
name|a
parameter_list|,
name|ns
parameter_list|)
value|((uint32_t)(a))
end_define

begin_define
define|#
directive|define
name|ufs_rw64
parameter_list|(
name|a
parameter_list|,
name|ns
parameter_list|)
value|((uint64_t)(a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ufs_add16
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|ns
parameter_list|)
define|\
value|(a) = ufs_rw16(ufs_rw16((a), (ns)) + (b), (ns))
end_define

begin_define
define|#
directive|define
name|ufs_add32
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|ns
parameter_list|)
define|\
value|(a) = ufs_rw32(ufs_rw32((a), (ns)) + (b), (ns))
end_define

begin_define
define|#
directive|define
name|ufs_add64
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|ns
parameter_list|)
define|\
value|(a) = ufs_rw64(ufs_rw64((a), (ns)) + (b), (ns))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_UFS_UFS_BSWAP_H_ */
end_comment

end_unit

