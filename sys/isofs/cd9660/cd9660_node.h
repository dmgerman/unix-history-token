begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley  * by Pace Willisson (pace@blitz.com).  The Rock Ridge Extension  * Support code is derived from software contributed to Berkeley  * by Atsushi Murai (amurai@spec.co.jp).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)cd9660_node.h	8.2 (Berkeley) 1/23/94  * $Id: cd9660_node.h,v 1.3 1994/09/15 19:46:00 bde Exp $  */
end_comment

begin_comment
comment|/*  * Theoretically, directories can be more than 2Gb in length,  * however, in practice this seems unlikely. So, we define  * the type doff_t as a long to keep down the cost of doing  * lookup on a 32-bit machine. If you are porting to a 64-bit  * architecture, you should make doff_t the same as off_t.  */
end_comment

begin_define
define|#
directive|define
name|doff_t
value|long
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|timespec
name|iso_atime
decl_stmt|;
comment|/* time of last access */
name|struct
name|timespec
name|iso_mtime
decl_stmt|;
comment|/* time of last modification */
name|struct
name|timespec
name|iso_ctime
decl_stmt|;
comment|/* time file changed */
name|u_short
name|iso_mode
decl_stmt|;
comment|/* files access mode and type */
name|uid_t
name|iso_uid
decl_stmt|;
comment|/* owner user id */
name|gid_t
name|iso_gid
decl_stmt|;
comment|/* owner group id */
name|short
name|iso_links
decl_stmt|;
comment|/* links of file */
name|dev_t
name|iso_rdev
decl_stmt|;
comment|/* Major/Minor number for special */
block|}
name|ISO_RRIP_INODE
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|ISODEVMAP
end_ifdef

begin_comment
comment|/*  * FOr device# (major,minor) translation table  */
end_comment

begin_struct
struct|struct
name|iso_dnode
block|{
name|struct
name|iso_dnode
modifier|*
name|d_chain
index|[
literal|2
index|]
decl_stmt|;
comment|/* hash chain, MUST be first */
name|dev_t
name|i_dev
decl_stmt|;
comment|/* device where dnode resides */
name|ino_t
name|i_number
decl_stmt|;
comment|/* the identity of the inode */
name|dev_t
name|d_dev
decl_stmt|;
comment|/* device # for translation */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|d_forw
value|d_chain[0]
end_define

begin_define
define|#
directive|define
name|d_back
value|d_chain[1]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|iso_node
block|{
name|struct
name|iso_node
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
comment|/* we use the actual starting block of the file */
name|struct
name|iso_mnt
modifier|*
name|i_mnt
decl_stmt|;
comment|/* filesystem associated with this inode */
name|struct
name|lockf
modifier|*
name|i_lockf
decl_stmt|;
comment|/* head of byte-level lock list */
name|doff_t
name|i_endoff
decl_stmt|;
comment|/* end of useful stuff in directory */
name|doff_t
name|i_diroff
decl_stmt|;
comment|/* offset in dir, where we found last entry */
name|doff_t
name|i_offset
decl_stmt|;
comment|/* offset of free space in directory */
name|ino_t
name|i_ino
decl_stmt|;
comment|/* inode number of found directory */
name|long
name|i_spare0
decl_stmt|;
name|long
name|i_spare1
decl_stmt|;
name|long
name|iso_extent
decl_stmt|;
comment|/* extent of file */
name|long
name|i_size
decl_stmt|;
name|long
name|iso_start
decl_stmt|;
comment|/* actual start of data of file (may be different */
comment|/* from iso_extent, if file has extended attributes) */
name|ISO_RRIP_INODE
name|inode
decl_stmt|;
block|}
struct|;
end_struct

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
name|IACC
value|0x0020
end_define

begin_comment
comment|/* inode access time to be updated */
end_comment

begin_define
define|#
directive|define
name|VTOI
parameter_list|(
name|vp
parameter_list|)
value|((struct iso_node *)(vp)->v_data)
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

begin_define
define|#
directive|define
name|ISO_ILOCK
parameter_list|(
name|ip
parameter_list|)
value|iso_ilock(ip)
end_define

begin_define
define|#
directive|define
name|ISO_IUNLOCK
parameter_list|(
name|ip
parameter_list|)
value|iso_iunlock(ip)
end_define

begin_comment
comment|/*  * Prototypes for ISOFS vnode operations  */
end_comment

begin_decl_stmt
name|int
name|cd9660_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lookup_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_open
name|__P
argument_list|(
operator|(
expr|struct
name|vop_open_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_close
name|__P
argument_list|(
operator|(
expr|struct
name|vop_close_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_access
name|__P
argument_list|(
operator|(
expr|struct
name|vop_access_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_getattr
name|__P
argument_list|(
operator|(
expr|struct
name|vop_getattr_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_read
name|__P
argument_list|(
operator|(
expr|struct
name|vop_read_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|vop_ioctl_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_select
name|__P
argument_list|(
operator|(
expr|struct
name|vop_select_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_mmap
name|__P
argument_list|(
operator|(
expr|struct
name|vop_mmap_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_seek
name|__P
argument_list|(
operator|(
expr|struct
name|vop_seek_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_readdir
name|__P
argument_list|(
operator|(
expr|struct
name|vop_readdir_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_abortop
name|__P
argument_list|(
operator|(
expr|struct
name|vop_abortop_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_inactive
name|__P
argument_list|(
operator|(
expr|struct
name|vop_inactive_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_reclaim
name|__P
argument_list|(
operator|(
expr|struct
name|vop_reclaim_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_bmap
name|__P
argument_list|(
operator|(
expr|struct
name|vop_bmap_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_lock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_unlock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_unlock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_strategy
name|__P
argument_list|(
operator|(
expr|struct
name|vop_strategy_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_print
name|__P
argument_list|(
operator|(
expr|struct
name|vop_print_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_islocked
name|__P
argument_list|(
operator|(
expr|struct
name|vop_islocked_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cd9660_defattr
name|__P
argument_list|(
operator|(
expr|struct
name|iso_directory_record
operator|*
operator|,
expr|struct
name|iso_node
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|,
expr|enum
name|ISO_FTYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cd9660_deftstamp
name|__P
argument_list|(
operator|(
expr|struct
name|iso_directory_record
operator|*
operator|,
expr|struct
name|iso_node
operator|*
operator|,
expr|struct
name|buf
operator|*
operator|,
expr|enum
name|ISO_FTYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_tstamp_conv7
name|__P
argument_list|(
operator|(
name|char
operator|*
name|pi
operator|,
expr|struct
name|timespec
operator|*
name|pu
operator|,
expr|enum
name|ISO_FTYPE
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cd9660_tstamp_conv17
name|__P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
name|pi
operator|,
expr|struct
name|timespec
operator|*
name|pu
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|isodirino
name|__P
argument_list|(
operator|(
name|ino_t
operator|*
name|inump
operator|,
expr|struct
name|iso_directory_record
operator|*
name|isodir
operator|,
expr|struct
name|iso_mnt
operator|*
name|imp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ISODEVMAP
end_ifdef

begin_decl_stmt
name|struct
name|iso_dnode
modifier|*
name|iso_dmap
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
name|ino_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|iso_dunmap
name|__P
argument_list|(
operator|(
name|dev_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

