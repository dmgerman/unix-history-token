begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ufsmount.h	7.10 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The root inode is the root of the file system.  Inode 0 can't be used for  * normal purposes and historically bad blocks were linked to inode 1, thus  * the root inode is 2. (inode 1 is no longer used for this purpose, however  * numerous dump tapes make this assumption, so we are stuck with it).  */
end_comment

begin_define
define|#
directive|define
name|ROOTINO
value|((ino_t)2)
end_define

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nameidata
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|timeval
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

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_comment
comment|/* This structure describes the UFS specific mount structure data. */
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
comment|/* filesystem vfs structure */
name|dev_t
name|um_dev
decl_stmt|;
comment|/* device mounted */
name|struct
name|vnode
modifier|*
name|um_devvp
decl_stmt|;
comment|/* block device mounted vnode */
union|union
block|{
comment|/* pointer to superblock */
name|struct
name|lfs
modifier|*
name|lfs
decl_stmt|;
comment|/* LFS */
name|struct
name|fs
modifier|*
name|fs
decl_stmt|;
comment|/* FFS */
block|}
name|ufsmount_u
union|;
define|#
directive|define
name|um_fs
value|ufsmount_u.fs
define|#
directive|define
name|um_lfs
value|ufsmount_u.lfs
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
comment|/* quota file access cred */
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
comment|/* quota specific flags */
comment|/* 	 * The following is the inode switch.  It is intended to provide 	 * the interface between the Unix File System semantics and the 	 * on-disk allocation, layout and I/O. 	 */
name|int
argument_list|(
argument|*um_blkatoff
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|inode
operator|*
name|ip
operator|,
name|off_t
name|offset
operator|,
name|char
operator|*
operator|*
name|res
operator|,
expr|struct
name|buf
operator|*
operator|*
name|bpp
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*um_write
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
name|int
name|ioflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*um_iget
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|inode
operator|*
name|pip
operator|,
name|ino_t
name|ino
operator|,
expr|struct
name|inode
operator|*
operator|*
name|ipp
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*um_ialloc
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|inode
operator|*
name|pip
operator|,
name|int
name|mode
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|inode
operator|*
operator|*
name|ipp
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*um_ifree
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|inode
operator|*
name|pip
operator|,
name|ino_t
name|ino
operator|,
name|int
name|mode
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*um_itrunc
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|inode
operator|*
name|oip
operator|,
name|u_long
name|length
operator|,
name|int
name|flags
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*um_iupdat
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|inode
operator|*
name|ip
operator|,
expr|struct
name|timeval
operator|*
name|ta
operator|,
expr|struct
name|timeval
operator|*
name|tm
operator|,
name|int
name|waitfor
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*um_bwrite
argument_list|)
comment|/* XXX changes */
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
name|bp
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*um_bmap
argument_list|)
comment|/* XXX changes */
name|__P
argument_list|(
operator|(
expr|struct
name|inode
operator|*
name|ip
operator|,
name|daddr_t
name|bn
operator|,
name|daddr_t
operator|*
name|bnp
operator|)
argument_list|)
expr_stmt|;
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

begin_comment
comment|/* Convert mount ptr to ufsmount ptr. */
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

end_unit

