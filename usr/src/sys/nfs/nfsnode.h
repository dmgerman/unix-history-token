begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)nfsnode.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The nfsnode is the nfs equivalent to ufs's inode. Any similarity  * is purely coincidental.  * There is a unique nfsnode allocated for each active file,  * each current directory, each mounted-on file, text file, and the root.  * An nfsnode is 'named' by its file handle. (nget/nfs_node.c)  */
end_comment

begin_struct
struct|struct
name|nfsnode
block|{
name|struct
name|nfsnode
modifier|*
name|n_chain
index|[
literal|2
index|]
decl_stmt|;
comment|/* must be first */
name|nfsv2fh_t
name|n_fh
decl_stmt|;
comment|/* NFS File Handle */
name|long
name|n_flag
decl_stmt|;
comment|/* Flag for locking.. */
name|long
name|n_id
decl_stmt|;
comment|/* unique identifier */
name|struct
name|vnode
name|n_vnode
decl_stmt|;
comment|/* vnode associated with this nfsnode */
name|long
name|n_attrstamp
decl_stmt|;
comment|/* Time stamp (sec) for attributes */
name|struct
name|vattr
name|n_vattr
decl_stmt|;
comment|/* Vnode attribute cache */
name|struct
name|sillyrename
modifier|*
name|n_sillyrename
decl_stmt|;
comment|/* Ptr to silly rename struct */
name|struct
name|nfsnode
modifier|*
name|n_freef
decl_stmt|;
comment|/* free list forward */
name|struct
name|nfsnode
modifier|*
modifier|*
name|n_freeb
decl_stmt|;
comment|/* free list back */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|n_forw
value|n_chain[0]
end_define

begin_define
define|#
directive|define
name|n_back
value|n_chain[1]
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|nfsnode
modifier|*
name|nfsnode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the nfsnode table itself */
end_comment

begin_decl_stmt
name|struct
name|nfsnode
modifier|*
name|nfsnodeNNFSNODE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the end of the nfsnode table */
end_comment

begin_decl_stmt
name|int
name|nnfsnode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of slots in the table */
end_comment

begin_decl_stmt
name|long
name|nextnfsnodeid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* unique id generator */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vnodeops
name|nfsv2_vnodeops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vnode operations for nfsv2 */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vnodeops
name|nfsv2chr_vnodeops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vnode operations for chr devices */
end_comment

begin_comment
comment|/*  * Convert between nfsnode pointers and vnode pointers  */
end_comment

begin_define
define|#
directive|define
name|VTONFS
parameter_list|(
name|vp
parameter_list|)
value|((struct nfsnode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|NFSTOV
parameter_list|(
name|np
parameter_list|)
value|((struct vnode *)&(np)->n_vnode)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Flags for n_flag  */
end_comment

begin_define
define|#
directive|define
name|NLOCKED
value|0x1
end_define

begin_define
define|#
directive|define
name|NWANT
value|0x2
end_define

end_unit

