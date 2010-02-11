begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFSCLIENT_NFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFSCLIENT_NFS_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_TPRINTF_INITIAL_DELAY
end_ifndef

begin_define
define|#
directive|define
name|NFS_TPRINTF_INITIAL_DELAY
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_TPRINTF_DELAY
end_ifndef

begin_define
define|#
directive|define
name|NFS_TPRINTF_DELAY
value|30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Nfs version macros.  */
end_comment

begin_define
define|#
directive|define
name|NFS_ISV3
parameter_list|(
name|v
parameter_list|)
define|\
value|(VFSTONFS((v)->v_mount)->nm_flag& NFSMNT_NFSV3)
end_define

begin_define
define|#
directive|define
name|NFS_ISV4
parameter_list|(
name|v
parameter_list|)
define|\
value|(VFSTONFS((v)->v_mount)->nm_flag& NFSMNT_NFSV4)
end_define

begin_define
define|#
directive|define
name|NFS_ISV34
parameter_list|(
name|v
parameter_list|)
define|\
value|(VFSTONFS((v)->v_mount)->nm_flag& (NFSMNT_NFSV3 | NFSMNT_NFSV4))
end_define

begin_comment
comment|/*  * NFS iod threads can be in one of these three states once spawned.  * NFSIOD_NOT_AVAILABLE - Cannot be assigned an I/O operation at this time.  * NFSIOD_AVAILABLE - Available to be assigned an I/O operation.  * NFSIOD_CREATED_FOR_NFS_ASYNCIO - Newly created for nfs_asyncio() and  *	will be used by the thread that called nfs_asyncio().  */
end_comment

begin_enum
enum|enum
name|nfsiod_state
block|{
name|NFSIOD_NOT_AVAILABLE
init|=
literal|0
block|,
name|NFSIOD_AVAILABLE
init|=
literal|1
block|,
name|NFSIOD_CREATED_FOR_NFS_ASYNCIO
init|=
literal|2
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Function prototypes.  */
end_comment

begin_function_decl
name|int
name|ncl_meta_setsize
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|,
name|u_quad_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncl_doio_directwrite
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_bioread
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_biowrite
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_vinvalbuf
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
end_function_decl

begin_function_decl
name|int
name|ncl_asyncio
parameter_list|(
name|struct
name|nfsmount
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_doio
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncl_nhinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncl_nhuninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncl_nodelock
parameter_list|(
name|struct
name|nfsnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncl_nodeunlock
parameter_list|(
name|struct
name|nfsnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_getattrcache
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|vattr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_readrpc
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_writerpc
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_readlinkrpc
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_readdirrpc
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_readdirplusrpc
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_writebp
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_commit
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|u_quad_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncl_clearcommit
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_fsinfo
parameter_list|(
name|struct
name|nfsmount
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_init
parameter_list|(
name|struct
name|vfsconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_uninit
parameter_list|(
name|struct
name|vfsconf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_mountroot
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncl_nfsiodnew
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NFSCLIENT_NFS_H_ */
end_comment

end_unit

