begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_NODE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_NODE_H__
end_define

begin_comment
comment|/*  * Save one allocation on FreeBSD and always allocate both inode and  * xfs_vnode struct as a single memory block.  */
end_comment

begin_struct
struct|struct
name|xfs_node
block|{
name|struct
name|xfs_inode
name|n_inode
decl_stmt|;
name|struct
name|xfs_vnode
name|n_vnode
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XFS_CAST_IP2VP
parameter_list|(
name|ip
parameter_list|)
value|(&((struct xfs_node *)(ip))->n_vnode)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_NODE_H__ */
end_comment

end_unit

