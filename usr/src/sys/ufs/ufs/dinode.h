begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)dinode.h	7.5 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The I node is the focus of all file activity in UNIX.  * There is a unique inode allocated for each active file,  * each current directory, each mounted-on file, text file, and the root.  * An inode is 'named' by its dev/inumber pair. (iget/iget.c)  * Data in icommon is read in from permanent inode on volume.  */
end_comment

begin_define
define|#
directive|define
name|NDADDR
value|12
end_define

begin_comment
comment|/* direct addresses in inode */
end_comment

begin_define
define|#
directive|define
name|NIADDR
value|3
end_define

begin_comment
comment|/* indirect addresses in inode */
end_comment

begin_struct
struct|struct
name|inode
block|{
name|struct
name|inode
modifier|*
name|i_chain
index|[
literal|2
index|]
decl_stmt|;
comment|/* must be first */
name|struct
name|vnode
name|i_vnode
decl_stmt|;
comment|/* vnode associated with this inode */
name|struct
name|vnode
modifier|*
name|i_devvp
decl_stmt|;
comment|/* vnode for block I/O */
name|u_short
name|i_flag
decl_stmt|;
name|dev_t
name|i_dev
decl_stmt|;
comment|/* device where inode resides */
name|ino_t
name|i_number
decl_stmt|;
comment|/* i number, 1-to-1 with device address */
name|long
name|i_id
decl_stmt|;
comment|/* unique identifier */
name|long
name|i_diroff
decl_stmt|;
comment|/* offset in dir, where we found last entry */
name|struct
name|fs
modifier|*
name|i_fs
decl_stmt|;
comment|/* file sys associated with this inode */
name|struct
name|dquot
modifier|*
name|i_dquot
decl_stmt|;
comment|/* quota structure controlling this file */
name|struct
name|text
modifier|*
name|i_text
decl_stmt|;
comment|/* text entry, if any (should be region) */
name|struct
name|inode
modifier|*
name|i_devlst
decl_stmt|;
comment|/* list of block device inodes */
name|off_t
name|i_endoff
decl_stmt|;
comment|/* end of useful stuff in directory */
name|long
name|i_spare
index|[
literal|4
index|]
decl_stmt|;
union|union
block|{
name|daddr_t
name|if_lastr
decl_stmt|;
comment|/* last read (read-ahead) */
name|struct
name|socket
modifier|*
name|is_socket
decl_stmt|;
struct|struct
block|{
name|struct
name|inode
modifier|*
name|if_freef
decl_stmt|;
comment|/* free list forward */
name|struct
name|inode
modifier|*
modifier|*
name|if_freeb
decl_stmt|;
comment|/* free list back */
block|}
name|i_fr
struct|;
block|}
name|i_un
union|;
struct|struct
name|icommon
block|{
name|u_short
name|ic_mode
decl_stmt|;
comment|/*  0: mode and type of file */
name|short
name|ic_nlink
decl_stmt|;
comment|/*  2: number of links to file */
name|uid_t
name|ic_uid
decl_stmt|;
comment|/*  4: owner's user id */
name|gid_t
name|ic_gid
decl_stmt|;
comment|/*  6: owner's group id */
name|quad
name|ic_size
decl_stmt|;
comment|/*  8: number of bytes in file */
name|time_t
name|ic_atime
decl_stmt|;
comment|/* 16: time last accessed */
name|long
name|ic_atspare
decl_stmt|;
name|time_t
name|ic_mtime
decl_stmt|;
comment|/* 24: time last modified */
name|long
name|ic_mtspare
decl_stmt|;
name|time_t
name|ic_ctime
decl_stmt|;
comment|/* 32: last time inode changed */
name|long
name|ic_ctspare
decl_stmt|;
name|daddr_t
name|ic_db
index|[
name|NDADDR
index|]
decl_stmt|;
comment|/* 40: disk block addresses */
name|daddr_t
name|ic_ib
index|[
name|NIADDR
index|]
decl_stmt|;
comment|/* 88: indirect blocks */
name|long
name|ic_flags
decl_stmt|;
comment|/* 100: status, currently unused */
name|long
name|ic_blocks
decl_stmt|;
comment|/* 104: blocks actually held */
name|long
name|ic_gen
decl_stmt|;
comment|/* 108: generation number */
name|long
name|ic_spare
index|[
literal|4
index|]
decl_stmt|;
comment|/* 112: reserved, currently unused */
block|}
name|i_ic
struct|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dinode
block|{
union|union
block|{
name|struct
name|icommon
name|di_icom
decl_stmt|;
name|char
name|di_size
index|[
literal|128
index|]
decl_stmt|;
block|}
name|di_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|i_mode
value|i_ic.ic_mode
end_define

begin_define
define|#
directive|define
name|i_nlink
value|i_ic.ic_nlink
end_define

begin_define
define|#
directive|define
name|i_uid
value|i_ic.ic_uid
end_define

begin_define
define|#
directive|define
name|i_gid
value|i_ic.ic_gid
end_define

begin_comment
comment|/* ugh! -- must be fixed */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_define
define|#
directive|define
name|i_size
value|i_ic.ic_size.val[0]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|i_db
value|i_ic.ic_db
end_define

begin_define
define|#
directive|define
name|i_ib
value|i_ic.ic_ib
end_define

begin_define
define|#
directive|define
name|i_atime
value|i_ic.ic_atime
end_define

begin_define
define|#
directive|define
name|i_mtime
value|i_ic.ic_mtime
end_define

begin_define
define|#
directive|define
name|i_ctime
value|i_ic.ic_ctime
end_define

begin_define
define|#
directive|define
name|i_blocks
value|i_ic.ic_blocks
end_define

begin_define
define|#
directive|define
name|i_rdev
value|i_ic.ic_db[0]
end_define

begin_define
define|#
directive|define
name|i_flags
value|i_ic.ic_flags
end_define

begin_define
define|#
directive|define
name|i_gen
value|i_ic.ic_gen
end_define

begin_define
define|#
directive|define
name|i_lastr
value|i_un.if_lastr
end_define

begin_define
define|#
directive|define
name|i_socket
value|i_un.is_socket
end_define

begin_define
define|#
directive|define
name|i_forw
value|i_chain[0]
end_define

begin_define
define|#
directive|define
name|i_back
value|i_chain[1]
end_define

begin_define
define|#
directive|define
name|i_freef
value|i_un.i_fr.if_freef
end_define

begin_define
define|#
directive|define
name|i_freeb
value|i_un.i_fr.if_freeb
end_define

begin_define
define|#
directive|define
name|di_ic
value|di_un.di_icom
end_define

begin_define
define|#
directive|define
name|di_mode
value|di_ic.ic_mode
end_define

begin_define
define|#
directive|define
name|di_nlink
value|di_ic.ic_nlink
end_define

begin_define
define|#
directive|define
name|di_uid
value|di_ic.ic_uid
end_define

begin_define
define|#
directive|define
name|di_gid
value|di_ic.ic_gid
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_define
define|#
directive|define
name|di_size
value|di_ic.ic_size.val[0]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|di_db
value|di_ic.ic_db
end_define

begin_define
define|#
directive|define
name|di_ib
value|di_ic.ic_ib
end_define

begin_define
define|#
directive|define
name|di_atime
value|di_ic.ic_atime
end_define

begin_define
define|#
directive|define
name|di_mtime
value|di_ic.ic_mtime
end_define

begin_define
define|#
directive|define
name|di_ctime
value|di_ic.ic_ctime
end_define

begin_define
define|#
directive|define
name|di_rdev
value|di_ic.ic_db[0]
end_define

begin_define
define|#
directive|define
name|di_blocks
value|di_ic.ic_blocks
end_define

begin_define
define|#
directive|define
name|di_flags
value|di_ic.ic_flags
end_define

begin_define
define|#
directive|define
name|di_gen
value|di_ic.ic_gen
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|inode
modifier|*
name|inode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the inode table itself */
end_comment

begin_decl_stmt
name|struct
name|inode
modifier|*
name|inodeNINODE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the end of the inode table */
end_comment

begin_decl_stmt
name|int
name|ninode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of slots in the table */
end_comment

begin_decl_stmt
name|u_long
name|nextgennumber
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next generation number to assign */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vnodeops
name|ufs_vnodeops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vnode operations for ufs */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vnodeops
name|blk_vnodeops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vnode operations for blk devices */
end_comment

begin_function_decl
specifier|extern
name|ino_t
name|dirpref
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|ILOCKED
value|0x1
end_define

begin_comment
comment|/* inode is locked */
end_comment

begin_define
define|#
directive|define
name|IUPD
value|0x2
end_define

begin_comment
comment|/* file has been modified */
end_comment

begin_define
define|#
directive|define
name|IACC
value|0x4
end_define

begin_comment
comment|/* inode access time to be updated */
end_comment

begin_define
define|#
directive|define
name|IWANT
value|0x8
end_define

begin_comment
comment|/* some process waiting on lock */
end_comment

begin_define
define|#
directive|define
name|ICHG
value|0x10
end_define

begin_comment
comment|/* inode has been changed */
end_comment

begin_define
define|#
directive|define
name|ISHLOCK
value|0x20
end_define

begin_comment
comment|/* file has shared lock */
end_comment

begin_define
define|#
directive|define
name|IEXLOCK
value|0x40
end_define

begin_comment
comment|/* file has exclusive lock */
end_comment

begin_define
define|#
directive|define
name|ILWAIT
value|0x80
end_define

begin_comment
comment|/* someone waiting on file lock */
end_comment

begin_define
define|#
directive|define
name|IMOD
value|0x100
end_define

begin_comment
comment|/* inode has been modified */
end_comment

begin_define
define|#
directive|define
name|IRENAME
value|0x200
end_define

begin_comment
comment|/* inode is being renamed */
end_comment

begin_comment
comment|/* modes */
end_comment

begin_define
define|#
directive|define
name|IFMT
value|0170000
end_define

begin_comment
comment|/* type of file */
end_comment

begin_define
define|#
directive|define
name|IFCHR
value|0020000
end_define

begin_comment
comment|/* character special */
end_comment

begin_define
define|#
directive|define
name|IFDIR
value|0040000
end_define

begin_comment
comment|/* directory */
end_comment

begin_define
define|#
directive|define
name|IFBLK
value|0060000
end_define

begin_comment
comment|/* block special */
end_comment

begin_define
define|#
directive|define
name|IFREG
value|0100000
end_define

begin_comment
comment|/* regular */
end_comment

begin_define
define|#
directive|define
name|IFLNK
value|0120000
end_define

begin_comment
comment|/* symbolic link */
end_comment

begin_define
define|#
directive|define
name|IFSOCK
value|0140000
end_define

begin_comment
comment|/* socket */
end_comment

begin_define
define|#
directive|define
name|ISUID
value|04000
end_define

begin_comment
comment|/* set user id on execution */
end_comment

begin_define
define|#
directive|define
name|ISGID
value|02000
end_define

begin_comment
comment|/* set group id on execution */
end_comment

begin_define
define|#
directive|define
name|ISVTX
value|01000
end_define

begin_comment
comment|/* save swapped text even after use */
end_comment

begin_define
define|#
directive|define
name|IREAD
value|0400
end_define

begin_comment
comment|/* read, write, execute permissions */
end_comment

begin_define
define|#
directive|define
name|IWRITE
value|0200
end_define

begin_define
define|#
directive|define
name|IEXEC
value|0100
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Convert between inode pointers and vnode pointers  */
end_comment

begin_define
define|#
directive|define
name|VTOI
parameter_list|(
name|vp
parameter_list|)
value|((struct inode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|ITOV
parameter_list|(
name|ip
parameter_list|)
value|(&(ip)->i_vnode)
end_define

begin_comment
comment|/*  * Convert between vnode types and inode formats  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|vtype
name|iftovt_tab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vttoif_tab
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IFTOVT
parameter_list|(
name|mode
parameter_list|)
value|(iftovt_tab[((mode)& IFMT)>> 13])
end_define

begin_define
define|#
directive|define
name|VTTOIF
parameter_list|(
name|indx
parameter_list|)
value|(vttoif_tab[(int)(indx)])
end_define

begin_define
define|#
directive|define
name|MAKEIMODE
parameter_list|(
name|indx
parameter_list|,
name|mode
parameter_list|)
value|(int)(VTTOIF(indx) | (mode))
end_define

begin_comment
comment|/*  * Lock and unlock inodes.  */
end_comment

begin_define
define|#
directive|define
name|ILOCK
parameter_list|(
name|ip
parameter_list|)
value|{ \ 	while ((ip)->i_flag& ILOCKED) { \ 		(ip)->i_flag |= IWANT; \ 		(void) sleep((caddr_t)(ip), PINOD); \ 	} \ 	(ip)->i_flag |= ILOCKED; \ }
end_define

begin_define
define|#
directive|define
name|IUNLOCK
parameter_list|(
name|ip
parameter_list|)
value|{ \ 	(ip)->i_flag&= ~ILOCKED; \ 	if ((ip)->i_flag&IWANT) { \ 		(ip)->i_flag&= ~IWANT; \ 		wakeup((caddr_t)(ip)); \ 	} \ }
end_define

begin_define
define|#
directive|define
name|IUPDAT
parameter_list|(
name|ip
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|,
name|waitfor
parameter_list|)
value|{ \ 	if (ip->i_flag&(IUPD|IACC|ICHG|IMOD)) \ 		(void) iupdat(ip, t1, t2, waitfor); \ }
end_define

begin_define
define|#
directive|define
name|ITIMES
parameter_list|(
name|ip
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|)
value|{ \ 	if ((ip)->i_flag&(IUPD|IACC|ICHG)) { \ 		(ip)->i_flag |= IMOD; \ 		if ((ip)->i_flag&IACC) \ 			(ip)->i_atime = (t1)->tv_sec; \ 		if ((ip)->i_flag&IUPD) \ 			(ip)->i_mtime = (t2)->tv_sec; \ 		if ((ip)->i_flag&ICHG) \ 			(ip)->i_ctime = time.tv_sec; \ 		(ip)->i_flag&= ~(IACC|IUPD|ICHG); \ 	} \ }
end_define

begin_comment
comment|/*  * This overlays the fid sturcture (see mount.h)  */
end_comment

begin_struct
struct|struct
name|ufid
block|{
name|u_short
name|ufid_len
decl_stmt|;
name|ino_t
name|ufid_ino
decl_stmt|;
name|long
name|ufid_gen
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

