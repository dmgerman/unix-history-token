begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, 2000 Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NWFS_NODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NWFS_NODE_H_
end_define

begin_define
define|#
directive|define
name|NWFS_ROOT_INO
value|0x7ffffffd
end_define

begin_define
define|#
directive|define
name|NWFS_ROOTVOL
value|"#.ROOT"
end_define

begin_comment
comment|/* Bits for nwnode.n_flag */
end_comment

begin_define
define|#
directive|define
name|NFLUSHINPROG
value|0x0001
end_define

begin_define
define|#
directive|define
name|NFLUSHWANT
value|0x0002
end_define

begin_comment
comment|/* they should gone ... */
end_comment

begin_define
define|#
directive|define
name|NMODIFIED
value|0x0004
end_define

begin_comment
comment|/* bogus, until async IO implemented */
end_comment

begin_define
define|#
directive|define
name|NNEW
value|0x0008
end_define

begin_comment
comment|/* vnode has been allocated */
end_comment

begin_define
define|#
directive|define
name|NVOLUME
value|0x0010
end_define

begin_comment
comment|/* vnode references a volume */
end_comment

begin_define
define|#
directive|define
name|NSHOULDFREE
value|0x0020
end_define

begin_comment
comment|/* vnode should be removed from hash */
end_comment

begin_struct
struct|struct
name|nwnode
block|{
name|struct
name|lock
name|n_lock
decl_stmt|;
comment|/* Keep this first */
name|LIST_ENTRY
argument_list|(
argument|nwnode
argument_list|)
name|n_hash
expr_stmt|;
name|struct
name|vnode
modifier|*
name|n_vnode
decl_stmt|;
name|struct
name|vattr
name|n_vattr
decl_stmt|;
name|struct
name|nwmount
modifier|*
name|n_mount
decl_stmt|;
name|time_t
name|n_atime
decl_stmt|;
comment|/* attributes cache time*/
name|time_t
name|n_ctime
decl_stmt|;
name|time_t
name|n_mtime
decl_stmt|;
name|int
name|n_flag
decl_stmt|;
name|ncpfid
name|n_parent
decl_stmt|;
name|ncpfid
name|n_fid
decl_stmt|;
name|int
name|n_refparent
decl_stmt|;
name|u_long
name|n_attr
decl_stmt|;
comment|/* LH */
name|u_long
name|n_size
decl_stmt|;
name|u_long
name|n_dosfid
decl_stmt|;
name|int
name|opened
decl_stmt|;
comment|/*	int 			access;*/
name|u_long
name|n_origfh
decl_stmt|;
name|ncp_fh
name|n_fh
decl_stmt|;
name|struct
name|nw_search_seq
name|n_seq
decl_stmt|;
name|u_char
name|n_nmlen
decl_stmt|;
name|u_char
name|n_name
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VTONW
parameter_list|(
name|vp
parameter_list|)
value|((struct nwnode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|NWTOV
parameter_list|(
name|np
parameter_list|)
value|((struct vnode *)(np)->n_vnode)
end_define

begin_define
define|#
directive|define
name|NWCMPF
parameter_list|(
name|f1
parameter_list|,
name|f2
parameter_list|)
value|((f1)->f_parent == (f2)->f_parent&& \ 			 (f1)->f_id == (f2)->f_id)
end_define

begin_define
define|#
directive|define
name|NWCMPN
parameter_list|(
name|np1
parameter_list|,
name|np2
parameter_list|)
value|NWCMPF(&(np1)->n_fid,&(np2)->n_fid)
end_define

begin_define
define|#
directive|define
name|NWCMPV
parameter_list|(
name|vp1
parameter_list|,
name|vp2
parameter_list|)
value|NWCMPN(VTONW(vp1),VTONW(vp2))
end_define

begin_struct_decl
struct_decl|struct
name|vop_getpages_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_inactive_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_putpages_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vop_reclaim_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|nwfs_hash_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nwfs_hash_free
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nwfs_allocvp
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|ncpfid
name|fid
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nwfs_lookupnp
parameter_list|(
name|struct
name|nwmount
modifier|*
name|nmp
parameter_list|,
name|ncpfid
name|fid
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|nwnode
modifier|*
modifier|*
name|npp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nwfs_inactive
parameter_list|(
name|struct
name|vop_inactive_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nwfs_reclaim
parameter_list|(
name|struct
name|vop_reclaim_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nwfs_nget
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|ncpfid
name|fid
parameter_list|,
name|struct
name|nw_entry_info
modifier|*
name|fap
parameter_list|,
name|struct
name|vnode
modifier|*
name|dvp
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nwfs_getpages
parameter_list|(
name|struct
name|vop_getpages_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nwfs_putpages
parameter_list|(
name|struct
name|vop_putpages_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nwfs_readvnode
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|uio
modifier|*
name|uiop
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nwfs_writevnode
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|uio
modifier|*
name|uiop
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|ioflag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nwfs_attr_cacheenter
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|nw_entry_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nwfs_attr_cachelookup
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|vattr
modifier|*
name|va
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|nwfs_attr_cacheremove
parameter_list|(
name|vp
parameter_list|)
value|VTONW(vp)->n_atime = 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NWFS_NODE_H_ */
end_comment

end_unit

