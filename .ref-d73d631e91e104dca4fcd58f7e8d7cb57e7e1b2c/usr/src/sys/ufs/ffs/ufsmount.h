begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ufsmount.h	7.7 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Mount structure.  * One allocated on every mount.  * Used to find the super block.  */
end_comment

begin_struct
struct|struct
name|ufsmount
block|{
name|struct
name|mount
modifier|*
name|um_mountp
decl_stmt|;
comment|/* vfs structure for this filesystem */
name|dev_t
name|um_dev
decl_stmt|;
comment|/* device mounted */
name|struct
name|vnode
modifier|*
name|um_devvp
decl_stmt|;
comment|/* vnode for block device mounted */
name|struct
name|fs
modifier|*
name|um_fs
decl_stmt|;
comment|/* pointer to superblock */
name|struct
name|vnode
modifier|*
name|um_quotas
index|[
name|MAXQUOTAS
index|]
decl_stmt|;
comment|/* pointer to quota files */
name|struct
name|ucred
modifier|*
name|um_cred
index|[
name|MAXQUOTAS
index|]
decl_stmt|;
comment|/* cred for access to quota file */
name|time_t
name|um_btime
index|[
name|MAXQUOTAS
index|]
decl_stmt|;
comment|/* block quota time limit */
name|time_t
name|um_itime
index|[
name|MAXQUOTAS
index|]
decl_stmt|;
comment|/* inode quota time limit */
name|char
name|um_qflags
index|[
name|MAXQUOTAS
index|]
decl_stmt|;
comment|/* quota specific flags, see below */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags describing the state of quotas.  */
end_comment

begin_define
define|#
directive|define
name|QTF_OPENING
value|0x01
end_define

begin_comment
comment|/* Q_QUOTAON in progress */
end_comment

begin_define
define|#
directive|define
name|QTF_CLOSING
value|0x02
end_define

begin_comment
comment|/* Q_QUOTAOFF in progress */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Convert mount ptr to ufsmount ptr.  */
end_comment

begin_define
define|#
directive|define
name|VFSTOUFS
parameter_list|(
name|mp
parameter_list|)
value|((struct ufsmount *)((mp)->mnt_data))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

