begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NWFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NWFS_H_
end_define

begin_include
include|#
directive|include
file|<netncp/ncp.h>
end_include

begin_include
include|#
directive|include
file|<nwfs/nwfs_mount.h>
end_include

begin_define
define|#
directive|define
name|NR_OPEN
value|0
end_define

begin_define
define|#
directive|define
name|NW_NSB_DOS
value|(1<< NW_NS_DOS)
end_define

begin_define
define|#
directive|define
name|NW_NSB_MAC
value|(1<< NW_NS_MAC)
end_define

begin_define
define|#
directive|define
name|NW_NSB_NFS
value|(1<< NW_NS_NFS)
end_define

begin_define
define|#
directive|define
name|NW_NSB_FTAM
value|(1<< NW_NS_FTAM)
end_define

begin_define
define|#
directive|define
name|NW_NSB_OS2
value|(1<< NW_NS_OS2)
end_define

begin_define
define|#
directive|define
name|NWFSIOC_GETCONN
value|_IOR('n',1,int)
end_define

begin_define
define|#
directive|define
name|NWFSIOC_GETEINFO
value|_IOR('n',2,struct nw_entry_info)
end_define

begin_define
define|#
directive|define
name|NWFSIOC_GETNS
value|_IOR('n',3,int)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_struct_decl
struct_decl|struct
name|nwfsnode
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|nwmount
block|{
name|struct
name|nwfs_args
name|m
decl_stmt|;
name|struct
name|mount
modifier|*
name|mp
decl_stmt|;
name|struct
name|ncp_handle
modifier|*
name|connh
decl_stmt|;
name|int
name|name_space
decl_stmt|;
name|struct
name|nwnode
modifier|*
name|n_root
decl_stmt|;
name|u_int32_t
name|n_volume
decl_stmt|;
name|ncpfid
name|n_rootent
decl_stmt|;
name|int
name|n_id
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VFSTONWFS
parameter_list|(
name|mntp
parameter_list|)
value|((struct nwmount *)((mntp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|NWFSTOVFS
parameter_list|(
name|mnp
parameter_list|)
value|((struct mount *)((mnp)->mount))
end_define

begin_define
define|#
directive|define
name|VTOVFS
parameter_list|(
name|vp
parameter_list|)
value|((vp)->v_mount)
end_define

begin_define
define|#
directive|define
name|VTONWFS
parameter_list|(
name|vp
parameter_list|)
value|(VFSTONWFS(VTOVFS(vp)))
end_define

begin_define
define|#
directive|define
name|NWFSTOCONN
parameter_list|(
name|nmp
parameter_list|)
value|((nmp)->connh->nh_conn)
end_define

begin_function_decl
name|int
name|ncp_conn_logged_in
parameter_list|(
name|struct
name|nwmount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nwfs_ioctl
parameter_list|(
name|struct
name|vop_ioctl_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nwfs_doio
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|struct
name|ucred
modifier|*
name|cr
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nwfs_vinvalbuf
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|intrflg
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
comment|/* _NWFS_H_ */
end_comment

end_unit

