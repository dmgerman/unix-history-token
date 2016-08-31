begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2003 Ion Badulescu  * Copyright (c) 1997-2014 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/conf/autofs/autofs_linux.h  *  */
end_comment

begin_comment
comment|/*  * Automounter filesystem headers for Linux  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_LINUX_AUTO_FS_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_LINUX_AUTO_FS4_H
argument_list|)
end_if

begin_comment
comment|/* We didn't find the headers, so we can't compile in the autofs support */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_FS_AUTOFS
end_undef

begin_undef
undef|#
directive|undef
name|MNTTAB_TYPE_AUTOFS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_LINUX_AUTO_FS_H&& !HAVE_LINUX_AUTO_FS4_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FS_AUTOFS
end_ifdef

begin_struct
struct|struct
name|autofs_pending_mount
block|{
name|unsigned
name|long
name|wait_queue_token
decl_stmt|;
comment|/* Associated kernel wait token */
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|autofs_pending_mount
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|autofs_pending_umount
block|{
name|unsigned
name|long
name|wait_queue_token
decl_stmt|;
comment|/* Associated kernel wait token */
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|autofs_pending_umount
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|fd
decl_stmt|;
name|int
name|kernelfd
decl_stmt|;
name|int
name|ioctlfd
decl_stmt|;
name|int
name|version
decl_stmt|;
name|struct
name|autofs_pending_mount
modifier|*
name|pending_mounts
decl_stmt|;
name|struct
name|autofs_pending_umount
modifier|*
name|pending_umounts
decl_stmt|;
block|}
name|autofs_fh_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_LINUX_AUTO_FS4_H
end_ifndef

begin_union
union|union
name|autofs_packet_union
block|{
name|struct
name|autofs_packet_hdr
name|hdr
decl_stmt|;
name|struct
name|autofs_packet_missing
name|missing
decl_stmt|;
name|struct
name|autofs_packet_expire
name|expire
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* typedef unsigned long autofs_wqt_t; */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_LINUX_AUTO_FS4_H */
end_comment

begin_define
define|#
directive|define
name|AUTOFS_AUTO_FS_FLAGS
value|(FS_AMQINFO | FS_DIRECTORY | FS_AUTOFS | FS_ON_AUTOFS)
end_define

begin_define
define|#
directive|define
name|AUTOFS_DIRECT_FS_FLAGS
value|(FS_DIRECT | FS_MKMNT | FS_NOTIMEOUT | FS_BACKGROUND | FS_AMQINFO)
end_define

begin_define
define|#
directive|define
name|AUTOFS_ERROR_FS_FLAGS
value|(FS_DISCARD)
end_define

begin_define
define|#
directive|define
name|AUTOFS_HOST_FS_FLAGS
value|(FS_MKMNT | FS_BACKGROUND | FS_AMQINFO)
end_define

begin_define
define|#
directive|define
name|AUTOFS_LINK_FS_FLAGS
value|(FS_MBACKGROUND)
end_define

begin_define
define|#
directive|define
name|AUTOFS_LINKX_FS_FLAGS
value|(FS_MBACKGROUND)
end_define

begin_define
define|#
directive|define
name|AUTOFS_NFSL_FS_FLAGS
value|(FS_BACKGROUND | FS_AMQINFO | FS_ON_AUTOFS)
end_define

begin_define
define|#
directive|define
name|AUTOFS_NFSX_FS_FLAGS
value|(
comment|/* FS_UBACKGROUND| */
value|FS_AMQINFO )
end_define

begin_define
define|#
directive|define
name|AUTOFS_PROGRAM_FS_FLAGS
value|(FS_BACKGROUND | FS_AMQINFO)
end_define

begin_define
define|#
directive|define
name|AUTOFS_ROOT_FS_FLAGS
value|(FS_NOTIMEOUT | FS_AMQINFO | FS_DIRECTORY)
end_define

begin_define
define|#
directive|define
name|AUTOFS_TOPLVL_FS_FLAGS
value|(FS_MKMNT | FS_NOTIMEOUT | FS_BACKGROUND | FS_AMQINFO | FS_DIRECTORY | FS_AUTOFS)
end_define

begin_define
define|#
directive|define
name|AUTOFS_UNION_FS_FLAGS
value|(FS_NOTIMEOUT | FS_BACKGROUND | FS_AMQINFO | FS_DIRECTORY | FS_ON_AUTOFS)
end_define

begin_define
define|#
directive|define
name|AUTOFS_CACHEFS_FS_FLAGS
value|(FS_NOTIMEOUT | FS_UBACKGROUND | FS_AMQINFO | FS_ON_AUTOFS)
end_define

begin_define
define|#
directive|define
name|AUTOFS_CDFS_FS_FLAGS
value|(FS_UBACKGROUND | FS_AMQINFO | FS_ON_AUTOFS)
end_define

begin_define
define|#
directive|define
name|AUTOFS_UDF_FS_FLAGS
value|(FS_UBACKGROUND | FS_AMQINFO | FS_ON_AUTOFS)
end_define

begin_define
define|#
directive|define
name|AUTOFS_LUSTRE_FS_FLAGS
value|(FS_UBACKGROUND | FS_AMQINFO | FS_ON_AUTOFS)
end_define

begin_define
define|#
directive|define
name|AUTOFS_EFS_FS_FLAGS
value|(FS_NOTIMEOUT | FS_UBACKGROUND | FS_AMQINFO | FS_ON_AUTOFS)
end_define

begin_define
define|#
directive|define
name|AUTOFS_LOFS_FS_FLAGS
value|(FS_NOTIMEOUT | FS_UBACKGROUND | FS_AMQINFO | FS_ON_AUTOFS)
end_define

begin_define
define|#
directive|define
name|AUTOFS_NFS_FS_FLAGS
value|(FS_BACKGROUND | FS_AMQINFO | FS_ON_AUTOFS)
end_define

begin_define
define|#
directive|define
name|AUTOFS_PCFS_FS_FLAGS
value|(FS_UBACKGROUND | FS_AMQINFO | FS_ON_AUTOFS)
end_define

begin_define
define|#
directive|define
name|AUTOFS_UFS_FS_FLAGS
value|(FS_NOTIMEOUT | FS_UBACKGROUND | FS_AMQINFO | FS_ON_AUTOFS)
end_define

begin_define
define|#
directive|define
name|AUTOFS_XFS_FS_FLAGS
value|(FS_NOTIMEOUT | FS_UBACKGROUND | FS_AMQINFO | FS_ON_AUTOFS)
end_define

begin_define
define|#
directive|define
name|AUTOFS_EXT_FS_FLAGS
value|(FS_NOTIMEOUT | FS_UBACKGROUND | FS_AMQINFO | FS_ON_AUTOFS)
end_define

begin_define
define|#
directive|define
name|AUTOFS_TMPFS_FS_FLAGS
value|(FS_NOTIMEOUT | FS_UBACKGROUND | FS_AMQINFO | FS_ON_AUTOFS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FS_AUTOFS */
end_comment

end_unit

