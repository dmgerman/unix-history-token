begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Jan-Simon Pendry  * Copyright (c) 1995  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)misc-bsd44l.h	8.1 (Berkeley) 5/10/95  *  */
end_comment

begin_define
define|#
directive|define
name|NFS_NPROCS
value|26
end_define

begin_struct_decl
struct_decl|struct
name|nfs_fattr
struct_decl|;
end_struct_decl

begin_union_decl
union_decl|union
name|nfsfh
union_decl|;
end_union_decl

begin_typedef
typedef|typedef
name|union
name|nfsfh
name|nfsfh_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_define
define|#
directive|define
name|mount
value|__kern_mount
end_define

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_undef
undef|#
directive|undef
name|mount
end_undef

begin_include
include|#
directive|include
file|<nfs/rpcv2.h>
end_include

begin_define
define|#
directive|define
name|KERNEL
end_define

begin_define
define|#
directive|define
name|nfs_init
value|__kern_nfs_init
end_define

begin_include
include|#
directive|include
file|<nfs/nfs.h>
end_include

begin_undef
undef|#
directive|undef
name|nfs_init
end_undef

begin_undef
undef|#
directive|undef
name|KERNEL
end_undef

begin_include
include|#
directive|include
file|<ufs/ufs/ufsmount.h>
end_include

end_unit

