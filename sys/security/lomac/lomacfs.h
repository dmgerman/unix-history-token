begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by NAI Labs, the  * Security Research Division of Network Associates, Inc. under  * DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA  * CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOMACFS_H
end_ifndef

begin_define
define|#
directive|define
name|LOMACFS_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

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

begin_include
include|#
directive|include
file|"kernel_interface.h"
end_include

begin_struct
struct|struct
name|lomac_mount
block|{
name|struct
name|vnode
modifier|*
name|lm_rootvp
decl_stmt|;
comment|/* singly-ref'd root after mount() */
define|#
directive|define
name|LM_TOOKROOT
value|0x0001
name|unsigned
name|int
name|lm_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is the structure associated with v_data on all LOMACFS vnodes.  */
end_comment

begin_struct
struct|struct
name|lomac_node
block|{
name|struct
name|vnode
modifier|*
name|ln_vp
decl_stmt|;
comment|/* vnode back-pointer */
name|struct
name|vnode
modifier|*
name|ln_lowervp
decl_stmt|;
comment|/* shadowed vnode (ref'd or NULL) */
define|#
directive|define
name|LN_LEVEL_MASK
value|0x0003
define|#
directive|define
name|LN_LOWEST_LEVEL
value|0x0001
define|#
directive|define
name|LN_SUBJ_LEVEL
value|0x0002
comment|/* placeholder before inheriting */
define|#
directive|define
name|LN_HIGHEST_LEVEL
value|0x0003
define|#
directive|define
name|LN_INHERIT_MASK
value|0x001c
define|#
directive|define
name|LN_INHERIT_LOW
value|0x0004
comment|/* children start with a low level */
define|#
directive|define
name|LN_INHERIT_HIGH
value|0x0008
comment|/* children start with a high level */
define|#
directive|define
name|LN_INHERIT_SUBJ
value|0x0010
comment|/* children inherit subject's level */
define|#
directive|define
name|LN_ATTR_MASK
value|0x01e0
define|#
directive|define
name|LN_ATTR_LOWWRITE
value|0x0020
comment|/* lower levels may write to */
define|#
directive|define
name|LN_ATTR_LOWNOOPEN
value|0x0040
comment|/* lower levels may not open */
define|#
directive|define
name|LN_ATTR_NONETDEMOTE
value|0x0080
comment|/* will not demote on net read */
define|#
directive|define
name|LN_ATTR_NODEMOTE
value|0x0100
comment|/* subject won't demote on other read */
name|u_int
name|ln_flags
decl_stmt|;
comment|/* What's the last node explicitly specifying policy for this? */
name|struct
name|lomac_node_entry
modifier|*
name|ln_underpolicy
decl_stmt|;
comment|/* If non-NULL, this corresponds 1:1 to a specific PLM node entry. */
name|struct
name|lomac_node_entry
modifier|*
name|ln_entry
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|LOMAC_DEBUG_INCNAME
argument_list|)
name|char
name|ln_name
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
comment|/* final component name */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is the "placeholder" structure initialized from the PLM that  * holds the level information for all named objects.  */
end_comment

begin_struct
struct|struct
name|lomac_node_entry
block|{
name|SLIST_HEAD
argument_list|(
argument|lomac_node_entry_head
argument_list|,
argument|lomac_node_entry
argument_list|)
name|ln_children
expr_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|lomac_node_entry
argument_list|)
name|ln_chain
expr_stmt|;
comment|/* chain of current level */
comment|/* continuing with the LN_* flags above */
define|#
directive|define
name|LN_CHILD_ATTR_SHIFT
value|4
comment|/* lshift from attr -> child attr */
define|#
directive|define
name|LN_CHILD_ATTR_MASK
value|0x1e00
define|#
directive|define
name|LN_CHILD_ATTR_LOWWRITE
value|0x0200
comment|/* lower levels may write to */
define|#
directive|define
name|LN_CHILD_ATTR_LOWNOOPEN
value|0x0400
comment|/* lower levels may not open */
define|#
directive|define
name|LN_CHILD_ATTR_NONETDEMOTE
value|0x0800
comment|/* will not demote on net read */
define|#
directive|define
name|LN_CHILD_ATTR_NODEMOTE
value|0x1000
comment|/* subject won't demote on other read */
name|u_int
name|ln_flags
decl_stmt|;
name|char
modifier|*
name|ln_name
decl_stmt|;
comment|/* last component name (to search) */
specifier|const
name|char
modifier|*
name|ln_path
decl_stmt|;
comment|/* in "stable" storage */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VTOLOMAC
parameter_list|(
name|vp
parameter_list|)
value|((struct lomac_node *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|VTOLVP
parameter_list|(
name|vp
parameter_list|)
value|VTOLOMAC(vp)->ln_lowervp
end_define

begin_define
define|#
directive|define
name|VFSTOLOMAC
parameter_list|(
name|mp
parameter_list|)
value|((struct lomac_mount *)mp->mnt_data)
end_define

begin_define
define|#
directive|define
name|VISLOMAC
parameter_list|(
name|vp
parameter_list|)
value|(vp->v_op == lomacfs_vnodeop_p)
end_define

begin_function_decl
name|int
name|lomacfs_node_alloc
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|componentname
modifier|*
name|cnp
parameter_list|,
name|struct
name|vnode
modifier|*
name|dvp
parameter_list|,
name|struct
name|vnode
modifier|*
name|lowervp
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_LOMACFS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|lomacfs_vnodeop_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|lomac_node_entry
name|lomac_node_entry_root
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOMACFS_H */
end_comment

end_unit

