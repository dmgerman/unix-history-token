begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998, 1999 Semen Ustimenko  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: ntfs_inode.h,v 1.8 1999/02/02 01:54:54 semen Exp $  */
end_comment

begin_comment
comment|/* These flags are kept in i_flag. */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|300000
end_if

begin_define
define|#
directive|define
name|IN_ACCESS
value|0x0001
end_define

begin_comment
comment|/* Access time update request. */
end_comment

begin_define
define|#
directive|define
name|IN_CHANGE
value|0x0002
end_define

begin_comment
comment|/* Inode change time update request. */
end_comment

begin_define
define|#
directive|define
name|IN_UPDATE
value|0x0004
end_define

begin_comment
comment|/* Modification time update request. */
end_comment

begin_define
define|#
directive|define
name|IN_MODIFIED
value|0x0008
end_define

begin_comment
comment|/* Inode has been modified. */
end_comment

begin_define
define|#
directive|define
name|IN_RENAME
value|0x0010
end_define

begin_comment
comment|/* Inode is being renamed. */
end_comment

begin_define
define|#
directive|define
name|IN_SHLOCK
value|0x0020
end_define

begin_comment
comment|/* File has shared lock. */
end_comment

begin_define
define|#
directive|define
name|IN_EXLOCK
value|0x0040
end_define

begin_comment
comment|/* File has exclusive lock. */
end_comment

begin_define
define|#
directive|define
name|IN_HASHED
value|0x0080
end_define

begin_comment
comment|/* Inode is on hash list */
end_comment

begin_define
define|#
directive|define
name|IN_LAZYMOD
value|0x0100
end_define

begin_comment
comment|/* Modified, but don't write yet. */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IN_ACCESS
value|0x0001
end_define

begin_comment
comment|/* Access time update request. */
end_comment

begin_define
define|#
directive|define
name|IN_CHANGE
value|0x0002
end_define

begin_comment
comment|/* Inode change time update request. */
end_comment

begin_define
define|#
directive|define
name|IN_EXLOCK
value|0x0004
end_define

begin_comment
comment|/* File has exclusive lock. */
end_comment

begin_define
define|#
directive|define
name|IN_LOCKED
value|0x0008
end_define

begin_comment
comment|/* Inode lock. */
end_comment

begin_define
define|#
directive|define
name|IN_LWAIT
value|0x0010
end_define

begin_comment
comment|/* Process waiting on file lock. */
end_comment

begin_define
define|#
directive|define
name|IN_MODIFIED
value|0x0020
end_define

begin_comment
comment|/* Inode has been modified. */
end_comment

begin_define
define|#
directive|define
name|IN_RENAME
value|0x0040
end_define

begin_comment
comment|/* Inode is being renamed. */
end_comment

begin_define
define|#
directive|define
name|IN_SHLOCK
value|0x0080
end_define

begin_comment
comment|/* File has shared lock. */
end_comment

begin_define
define|#
directive|define
name|IN_UPDATE
value|0x0100
end_define

begin_comment
comment|/* Modification time update request. */
end_comment

begin_define
define|#
directive|define
name|IN_WANTED
value|0x0200
end_define

begin_comment
comment|/* Inode is wanted by a process. */
end_comment

begin_define
define|#
directive|define
name|IN_RECURSE
value|0x0400
end_define

begin_comment
comment|/* Recursion expected */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IN_LOADED
value|0x8000
end_define

begin_comment
comment|/* ntvattrs loaded */
end_comment

begin_define
define|#
directive|define
name|IN_PRELOADED
value|0x4000
end_define

begin_comment
comment|/* loaded from directory entry */
end_comment

begin_define
define|#
directive|define
name|IN_AATTRNAME
value|0x2000
end_define

begin_comment
comment|/* spaec allocated for i_defattrname */
end_comment

begin_struct
struct|struct
name|ntnode
block|{
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|300000
name|struct
name|lock
name|i_lock
decl_stmt|;
comment|/* Must be first */
endif|#
directive|endif
name|LIST_ENTRY
argument_list|(
argument|ntnode
argument_list|)
name|i_hash
expr_stmt|;
name|struct
name|ntnode
modifier|*
name|i_next
decl_stmt|;
name|struct
name|ntnode
modifier|*
modifier|*
name|i_prev
decl_stmt|;
name|struct
name|vnode
modifier|*
name|i_vnode
decl_stmt|;
name|struct
name|vnode
modifier|*
name|i_devvp
decl_stmt|;
name|struct
name|ntfsmount
modifier|*
name|i_mp
decl_stmt|;
name|enum
name|vtype
name|i_type
decl_stmt|;
name|dev_t
name|i_dev
decl_stmt|;
name|ino_t
name|i_number
decl_stmt|;
name|u_int32_t
name|i_flag
decl_stmt|;
name|long
name|i_nlink
decl_stmt|;
comment|/* MFR */
name|ino_t
name|i_mainrec
decl_stmt|;
comment|/* MFR */
name|u_int32_t
name|i_frflag
decl_stmt|;
comment|/* MFR */
name|ntfs_times_t
name|i_times
decl_stmt|;
comment|/* $NAME/dirinfo */
name|ino_t
name|i_pnumber
decl_stmt|;
comment|/* $NAME/dirinfo */
name|u_int32_t
name|i_fflag
decl_stmt|;
comment|/* $NAME/dirinfo */
name|u_int64_t
name|i_size
decl_stmt|;
comment|/* defattr/dirinfo: */
name|u_int64_t
name|i_allocated
decl_stmt|;
comment|/* defattr/dirinfo */
name|u_int32_t
name|i_lastdattr
decl_stmt|;
name|u_int32_t
name|i_lastdblnum
decl_stmt|;
name|u_int32_t
name|i_lastdoff
decl_stmt|;
name|u_int32_t
name|i_lastdnum
decl_stmt|;
name|caddr_t
name|i_dirblbuf
decl_stmt|;
name|u_int32_t
name|i_dirblsz
decl_stmt|;
name|uid_t
name|i_uid
decl_stmt|;
name|gid_t
name|i_gid
decl_stmt|;
name|mode_t
name|i_mode
decl_stmt|;
name|u_int32_t
name|i_defattr
decl_stmt|;
name|char
modifier|*
name|i_defattrname
decl_stmt|;
name|struct
name|ntvattr
modifier|*
name|i_vattrp
decl_stmt|;
name|int
name|i_lockcount
decl_stmt|;
comment|/* Process lock count (recursion) */
name|pid_t
name|i_lockholder
decl_stmt|;
comment|/* DEBUG: holder of ntnode lock. */
name|pid_t
name|i_lockwaiter
decl_stmt|;
comment|/* DEBUG: waiter of ntnode lock. */
block|}
struct|;
end_struct

end_unit

