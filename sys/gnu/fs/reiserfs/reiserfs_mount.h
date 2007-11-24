begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2000 Hans Reiser  * See README for licensing and copyright details  *   * Ported to FreeBSD by Jean-Sébastien Pédron<jspedron@club-internet.fr>  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_REISERFS_REISERFS_MOUNT_H
end_ifndef

begin_define
define|#
directive|define
name|_GNU_REISERFS_REISERFS_MOUNT_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_REISERFSMNT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_REISERFSPATH
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_REISERFSNODE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_REISERFSCOOKIES
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This structure describes the ReiserFS specific mount structure data. */
end_comment

begin_struct
struct|struct
name|reiserfs_mount
block|{
name|struct
name|mount
modifier|*
name|rm_mountp
decl_stmt|;
name|struct
name|cdev
modifier|*
name|rm_dev
decl_stmt|;
name|struct
name|vnode
modifier|*
name|rm_devvp
decl_stmt|;
name|struct
name|reiserfs_sb_info
modifier|*
name|rm_reiserfs
decl_stmt|;
name|struct
name|g_consumer
modifier|*
name|rm_cp
decl_stmt|;
name|struct
name|bufobj
modifier|*
name|rm_bo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Convert mount ptr to reiserfs_mount ptr. */
end_comment

begin_define
define|#
directive|define
name|VFSTOREISERFS
parameter_list|(
name|mp
parameter_list|)
value|((struct reiserfs_mount *)((mp)->mnt_data))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_KERNEL) */
end_comment

begin_comment
comment|/* Arguments to mount ReiserFS filesystems. */
end_comment

begin_struct
struct|struct
name|reiserfs_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
comment|/* blocks special holding the fs to mount */
name|struct
name|export_args
name|export
decl_stmt|;
comment|/* network export information */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined _GNU_REISERFS_REISERFS_MOUNT_H */
end_comment

end_unit

