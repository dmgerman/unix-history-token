begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Rick Macklem, University of Guelph  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_MOUNTCOMMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_MOUNTCOMMON_H_
end_define

begin_comment
comment|/*  * The common fields of the nfsmount structure for the two clients  * used by the nlm. It includes a function pointer that provides  * a mechanism for getting the client specific info for an nfs vnode.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|nfs_getinfofromvp_ftype
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|off_t
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|nfs_vinvalbuf_ftype
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|nfsmount_common
block|{
name|struct
name|mtx
name|nmcom_mtx
decl_stmt|;
name|int
name|nmcom_flag
decl_stmt|;
comment|/* Flags for soft/hard... */
name|int
name|nmcom_state
decl_stmt|;
comment|/* Internal state flags */
name|struct
name|mount
modifier|*
name|nmcom_mountp
decl_stmt|;
comment|/* Vfs structure for this filesystem */
name|int
name|nmcom_timeo
decl_stmt|;
comment|/* Init timer for NFSMNT_DUMBTIMR */
name|int
name|nmcom_retry
decl_stmt|;
comment|/* Max retries */
name|char
name|nmcom_hostname
index|[
name|MNAMELEN
index|]
decl_stmt|;
comment|/* server's name */
name|nfs_getinfofromvp_ftype
modifier|*
name|nmcom_getinfo
decl_stmt|;
comment|/* Get info from nfsnode */
name|nfs_vinvalbuf_ftype
modifier|*
name|nmcom_vinvalbuf
decl_stmt|;
comment|/* Invalidate buffers */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NFS_MOUNTCOMMON_H_ */
end_comment

end_unit

