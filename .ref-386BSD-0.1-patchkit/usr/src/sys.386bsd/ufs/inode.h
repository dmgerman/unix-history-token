begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)inode.h	7.17 (Berkeley) 5/8/91  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"../ufs/dinode.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<ufs/dinode.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The inode is used to describe each active (or recently active)  * file in the UFS filesystem. It is composed of two types of  * information. The first part is the information that is needed  * only while the file is active (such as the identity of the file  * and linkage to speed its lookup). The second part is the   * permannent meta-data associated with the file which is read  * in from the permanent dinode from long term storage when the  * file becomes active, and is put back when the file is no longer  * being used.  */
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
comment|/* hash chain, MUST be first */
name|struct
name|vnode
modifier|*
name|i_vnode
decl_stmt|;
comment|/* vnode associated with this inode */
name|struct
name|vnode
modifier|*
name|i_devvp
decl_stmt|;
comment|/* vnode for block I/O */
name|u_long
name|i_flag
decl_stmt|;
comment|/* see below */
name|dev_t
name|i_dev
decl_stmt|;
comment|/* device where inode resides */
name|ino_t
name|i_number
decl_stmt|;
comment|/* the identity of the inode */
name|struct
name|fs
modifier|*
name|i_fs
decl_stmt|;
comment|/* filesystem associated with this inode */
name|struct
name|dquot
modifier|*
name|i_dquot
index|[
name|MAXQUOTAS
index|]
decl_stmt|;
comment|/* pointer to dquot structures */
name|struct
name|lockf
modifier|*
name|i_lockf
decl_stmt|;
comment|/* head of byte-level lock list */
name|long
name|i_diroff
decl_stmt|;
comment|/* offset in dir, where we found last entry */
name|off_t
name|i_endoff
decl_stmt|;
comment|/* end of useful stuff in directory */
name|long
name|i_spare0
decl_stmt|;
name|long
name|i_spare1
decl_stmt|;
name|struct
name|dinode
name|i_din
decl_stmt|;
comment|/* the on-disk dinode */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|i_mode
value|i_din.di_mode
end_define

begin_define
define|#
directive|define
name|i_nlink
value|i_din.di_nlink
end_define

begin_define
define|#
directive|define
name|i_uid
value|i_din.di_uid
end_define

begin_define
define|#
directive|define
name|i_gid
value|i_din.di_gid
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_comment
comment|/* ugh! -- must be fixed */
end_comment

begin_define
define|#
directive|define
name|i_size
value|i_din.di_qsize.val[0]
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BYTE_ORDER == BIG_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|i_size
value|i_din.di_qsize.val[1]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|i_db
value|i_din.di_db
end_define

begin_define
define|#
directive|define
name|i_ib
value|i_din.di_ib
end_define

begin_define
define|#
directive|define
name|i_atime
value|i_din.di_atime
end_define

begin_define
define|#
directive|define
name|i_mtime
value|i_din.di_mtime
end_define

begin_define
define|#
directive|define
name|i_ctime
value|i_din.di_ctime
end_define

begin_define
define|#
directive|define
name|i_blocks
value|i_din.di_blocks
end_define

begin_define
define|#
directive|define
name|i_rdev
value|i_din.di_db[0]
end_define

begin_define
define|#
directive|define
name|i_flags
value|i_din.di_flags
end_define

begin_define
define|#
directive|define
name|i_gen
value|i_din.di_gen
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

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|ILOCKED
value|0x0001
end_define

begin_comment
comment|/* inode is locked */
end_comment

begin_define
define|#
directive|define
name|IWANT
value|0x0002
end_define

begin_comment
comment|/* some process waiting on lock */
end_comment

begin_define
define|#
directive|define
name|IRENAME
value|0x0004
end_define

begin_comment
comment|/* inode is being renamed */
end_comment

begin_define
define|#
directive|define
name|IUPD
value|0x0010
end_define

begin_comment
comment|/* file has been modified */
end_comment

begin_define
define|#
directive|define
name|IACC
value|0x0020
end_define

begin_comment
comment|/* inode access time to be updated */
end_comment

begin_define
define|#
directive|define
name|ICHG
value|0x0040
end_define

begin_comment
comment|/* inode has been changed */
end_comment

begin_define
define|#
directive|define
name|IMOD
value|0x0080
end_define

begin_comment
comment|/* inode has been modified */
end_comment

begin_define
define|#
directive|define
name|ISHLOCK
value|0x0100
end_define

begin_comment
comment|/* file has shared lock */
end_comment

begin_define
define|#
directive|define
name|IEXLOCK
value|0x0200
end_define

begin_comment
comment|/* file has exclusive lock */
end_comment

begin_define
define|#
directive|define
name|ILWAIT
value|0x0400
end_define

begin_comment
comment|/* someone waiting on file lock */
end_comment

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
value|((ip)->i_vnode)
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
value|(iftovt_tab[((mode)& IFMT)>> 12])
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

begin_decl_stmt
name|u_long
name|nextgennumber
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next generation number to assign */
end_comment

begin_function_decl
specifier|extern
name|ino_t
name|dirpref
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Lock and unlock inodes.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ILOCK
parameter_list|(
name|ip
parameter_list|)
value|ilock(ip)
end_define

begin_define
define|#
directive|define
name|IUNLOCK
parameter_list|(
name|ip
parameter_list|)
value|iunlock(ip)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* length of structure */
name|u_short
name|ufid_pad
decl_stmt|;
comment|/* force long alignment */
name|ino_t
name|ufid_ino
decl_stmt|;
comment|/* file number (ino) */
name|long
name|ufid_gen
decl_stmt|;
comment|/* generation number */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Prototypes for UFS vnode operations  */
end_comment

begin_decl_stmt
name|int
name|ufs_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_create
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|vattr
operator|*
name|vap
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_mknod
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|vattr
operator|*
name|vap
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_open
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
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
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_close
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|fflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_access
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
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
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_getattr
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|vattr
operator|*
name|vap
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_setattr
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|vattr
operator|*
name|vap
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_read
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_write
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|command
operator|,
name|caddr_t
name|data
operator|,
name|int
name|fflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_select
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|which
operator|,
name|int
name|fflags
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_mmap
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|fflags
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_fsync
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|fflags
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
name|int
name|waitfor
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_seek
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|off_t
name|oldoff
operator|,
name|off_t
name|newoff
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_remove
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_link
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_rename
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|fndp
operator|,
expr|struct
name|nameidata
operator|*
name|tdnp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_mkdir
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|vattr
operator|*
name|vap
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_rmdir
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_symlink
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|vattr
operator|*
name|vap
operator|,
name|char
operator|*
name|target
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_readdir
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
expr|struct
name|ucred
operator|*
name|cred
operator|,
name|int
operator|*
name|eofflagp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_readlink
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
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_abortop
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
name|ndp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_inactive
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_reclaim
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_lock
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_unlock
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_bmap
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|daddr_t
name|bn
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|,
name|daddr_t
operator|*
name|bnp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_strategy
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
name|bp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_print
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_islocked
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_advlock
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|caddr_t
name|id
operator|,
name|int
name|op
operator|,
expr|struct
name|flock
operator|*
name|fl
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

