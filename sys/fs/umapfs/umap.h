begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software donated to Berkeley by  * the UCLA Ficus project.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)umap.h	8.4 (Berkeley) 8/20/94  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|MAPFILEENTRIES
value|64
end_define

begin_define
define|#
directive|define
name|GMAPFILEENTRIES
value|16
end_define

begin_define
define|#
directive|define
name|NOBODY
value|32767
end_define

begin_define
define|#
directive|define
name|NULLGROUP
value|65534
end_define

begin_struct
struct|struct
name|umap_args
block|{
name|char
modifier|*
name|target
decl_stmt|;
comment|/* Target of loopback  */
name|int
name|nentries
decl_stmt|;
comment|/* # of entries in user map array */
name|int
name|gnentries
decl_stmt|;
comment|/* # of entries in group map array */
name|u_long
argument_list|(
operator|*
name|mapdata
argument_list|)
index|[
literal|2
index|]
expr_stmt|;
comment|/* pointer to array of user mappings */
name|u_long
argument_list|(
operator|*
name|gmapdata
argument_list|)
index|[
literal|2
index|]
expr_stmt|;
comment|/* pointer to array of group mappings */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|umap_mount
block|{
name|struct
name|mount
modifier|*
name|umapm_vfs
decl_stmt|;
name|struct
name|vnode
modifier|*
name|umapm_rootvp
decl_stmt|;
comment|/* Reference to root umap_node */
name|int
name|info_nentries
decl_stmt|;
comment|/* number of uid mappings */
name|int
name|info_gnentries
decl_stmt|;
comment|/* number of gid mappings */
name|u_long
name|info_mapdata
index|[
name|MAPFILEENTRIES
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|/* mapping data for 	    user mapping in ficus */
name|u_long
name|info_gmapdata
index|[
name|GMAPFILEENTRIES
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|/*mapping data for 	    group mapping in ficus */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * A cache of vnode references  */
end_comment

begin_struct
struct|struct
name|umap_node
block|{
name|LIST_ENTRY
argument_list|(
argument|umap_node
argument_list|)
name|umap_hash
expr_stmt|;
comment|/* Hash list */
name|struct
name|vnode
modifier|*
name|umap_lowervp
decl_stmt|;
comment|/* Aliased vnode - VREFed once */
name|struct
name|vnode
modifier|*
name|umap_vnode
decl_stmt|;
comment|/* Back pointer to vnode/umap_node */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|umapfs_init
parameter_list|(
name|struct
name|vfsconf
modifier|*
name|vfsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|umap_node_create
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|vnode
modifier|*
name|target
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
specifier|extern
name|u_long
name|umap_reverse_findid
parameter_list|(
name|u_long
name|id
parameter_list|,
name|u_long
name|map
index|[]
index|[
literal|2
index|]
parameter_list|,
name|int
name|nentries
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|umap_mapids
parameter_list|(
name|struct
name|mount
modifier|*
name|v_mount
parameter_list|,
name|struct
name|ucred
modifier|*
name|credp
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MOUNTTOUMAPMOUNT
parameter_list|(
name|mp
parameter_list|)
value|((struct umap_mount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|VTOUMAP
parameter_list|(
name|vp
parameter_list|)
value|((struct umap_node *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|UMAPTOV
parameter_list|(
name|xp
parameter_list|)
value|((xp)->umap_vnode)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DIAGNOSTIC
end_ifdef

begin_function_decl
specifier|extern
name|struct
name|vnode
modifier|*
name|umap_checkvp
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|char
modifier|*
name|fil
parameter_list|,
name|int
name|lno
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|UMAPVPTOLOWERVP
parameter_list|(
name|vp
parameter_list|)
value|umap_checkvp((vp), __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UMAPVPTOLOWERVP
parameter_list|(
name|vp
parameter_list|)
value|(VTOUMAP(vp)->umap_lowervp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|umap_vnodeop_p
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

end_unit

