begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NWFS_MOUNT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NWFS_MOUNT_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_NCP_NCP_NLS_H_
end_ifndef

begin_include
include|#
directive|include
file|<netncp/ncp_nls.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NWFS_VERMAJ
value|1
end_define

begin_define
define|#
directive|define
name|NWFS_VERMIN
value|3400
end_define

begin_define
define|#
directive|define
name|NWFS_VERSION
value|(NWFS_VERMAJ*100000 + NWFS_VERMIN)
end_define

begin_comment
comment|/* Values for flags */
end_comment

begin_define
define|#
directive|define
name|NWFS_MOUNT_SOFT
value|0x0001
end_define

begin_define
define|#
directive|define
name|WNFS_MOUNT_INTR
value|0x0002
end_define

begin_define
define|#
directive|define
name|NWFS_MOUNT_STRONG
value|0x0004
end_define

begin_define
define|#
directive|define
name|NWFS_MOUNT_NO_OS2
value|0x0008
end_define

begin_define
define|#
directive|define
name|NWFS_MOUNT_NO_NFS
value|0x0010
end_define

begin_define
define|#
directive|define
name|NWFS_MOUNT_NO_LONG
value|0x0020
end_define

begin_define
define|#
directive|define
name|NWFS_MOUNT_GET_SYSENT
value|0x0040
end_define

begin_comment
comment|/* special case, look to vfsops :) */
end_comment

begin_define
define|#
directive|define
name|NWFS_MOUNT_HAVE_NLS
value|0x0080
end_define

begin_define
define|#
directive|define
name|NWFS_VOLNAME_LEN
value|48
end_define

begin_comment
comment|/* Layout of the mount control block for a netware file system. */
end_comment

begin_struct
struct|struct
name|nwfs_args
block|{
name|int
name|connRef
decl_stmt|;
comment|/* connection reference */
name|char
name|mount_point
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
name|u_char
name|mounted_vol
index|[
name|NWFS_VOLNAME_LEN
operator|+
literal|1
index|]
decl_stmt|;
name|u_char
name|root_path
index|[
literal|512
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|version
decl_stmt|;
name|uid_t
name|uid
decl_stmt|;
name|gid_t
name|gid
decl_stmt|;
name|mode_t
name|file_mode
decl_stmt|;
name|mode_t
name|dir_mode
decl_stmt|;
name|struct
name|ncp_nlstables
name|nls
decl_stmt|;
name|int
name|tz
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NWFSMNT
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/* !_NWFS_MOUNT_H_ */
end_comment

end_unit

