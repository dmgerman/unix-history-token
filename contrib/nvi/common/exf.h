begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)exf.h	10.7 (Berkeley) 7/9/96  */
end_comment

begin_comment
comment|/* Undo direction. */
end_comment

begin_comment
comment|/*  * exf --  *	The file structure.  */
end_comment

begin_struct
struct|struct
name|_exf
block|{
name|int
name|refcnt
decl_stmt|;
comment|/* Reference count. */
comment|/* Underlying database state. */
name|DB
modifier|*
name|db
decl_stmt|;
comment|/* File db structure. */
name|char
modifier|*
name|c_lp
decl_stmt|;
comment|/* Cached line. */
name|size_t
name|c_len
decl_stmt|;
comment|/* Cached line length. */
name|recno_t
name|c_lno
decl_stmt|;
comment|/* Cached line number. */
name|recno_t
name|c_nlines
decl_stmt|;
comment|/* Cached lines in the file. */
name|DB
modifier|*
name|log
decl_stmt|;
comment|/* Log db structure. */
name|char
modifier|*
name|l_lp
decl_stmt|;
comment|/* Log buffer. */
name|size_t
name|l_len
decl_stmt|;
comment|/* Log buffer length. */
name|recno_t
name|l_high
decl_stmt|;
comment|/* Log last + 1 record number. */
name|recno_t
name|l_cur
decl_stmt|;
comment|/* Log current record number. */
name|MARK
name|l_cursor
decl_stmt|;
comment|/* Log cursor position. */
name|dir_t
name|lundo
decl_stmt|;
comment|/* Last undo direction. */
name|LIST_HEAD
argument_list|(
argument|_markh
argument_list|,
argument|_lmark
argument_list|)
name|marks
expr_stmt|;
comment|/* Linked list of file MARK's. */
comment|/* 	 * XXX 	 * Mtime should be a struct timespec, but time_t is more portable. 	 */
name|dev_t
name|mdev
decl_stmt|;
comment|/* Device. */
name|ino_t
name|minode
decl_stmt|;
comment|/* Inode. */
name|time_t
name|mtime
decl_stmt|;
comment|/* Last modification time. */
name|int
name|fcntl_fd
decl_stmt|;
comment|/* Fcntl locking fd; see exf.c. */
comment|/* 	 * Recovery in general, and these fields specifically, are described 	 * in recover.c. 	 */
define|#
directive|define
name|RCV_PERIOD
value|120
comment|/* Sync every two minutes. */
name|char
modifier|*
name|rcv_path
decl_stmt|;
comment|/* Recover file name. */
name|char
modifier|*
name|rcv_mpath
decl_stmt|;
comment|/* Recover mail file name. */
name|int
name|rcv_fd
decl_stmt|;
comment|/* Locked mail file descriptor. */
define|#
directive|define
name|F_DEVSET
value|0x001
comment|/* mdev/minode fields initialized. */
define|#
directive|define
name|F_FIRSTMODIFY
value|0x002
comment|/* File not yet modified. */
define|#
directive|define
name|F_MODIFIED
value|0x004
comment|/* File is currently dirty. */
define|#
directive|define
name|F_MULTILOCK
value|0x008
comment|/* Multiple processes running, lock. */
define|#
directive|define
name|F_NOLOG
value|0x010
comment|/* Logging turned off. */
define|#
directive|define
name|F_RCV_NORM
value|0x020
comment|/* Don't delete recovery files. */
define|#
directive|define
name|F_RCV_ON
value|0x040
comment|/* Recovery is possible. */
define|#
directive|define
name|F_UNDO
value|0x080
comment|/* No change since last undo. */
name|u_int8_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Flags to db_get(). */
end_comment

begin_define
define|#
directive|define
name|DBG_FATAL
value|0x001
end_define

begin_comment
comment|/* If DNE, error message. */
end_comment

begin_define
define|#
directive|define
name|DBG_NOCACHE
value|0x002
end_define

begin_comment
comment|/* Ignore the front-end cache. */
end_comment

begin_comment
comment|/* Flags to file_init() and file_write(). */
end_comment

begin_define
define|#
directive|define
name|FS_ALL
value|0x001
end_define

begin_comment
comment|/* Write the entire file. */
end_comment

begin_define
define|#
directive|define
name|FS_APPEND
value|0x002
end_define

begin_comment
comment|/* Append to the file. */
end_comment

begin_define
define|#
directive|define
name|FS_FORCE
value|0x004
end_define

begin_comment
comment|/* Force is set. */
end_comment

begin_define
define|#
directive|define
name|FS_OPENERR
value|0x008
end_define

begin_comment
comment|/* Open failed, try it again. */
end_comment

begin_define
define|#
directive|define
name|FS_POSSIBLE
value|0x010
end_define

begin_comment
comment|/* Force could have been set. */
end_comment

begin_define
define|#
directive|define
name|FS_SETALT
value|0x020
end_define

begin_comment
comment|/* Set alternate file name. */
end_comment

begin_comment
comment|/* Flags to rcv_sync(). */
end_comment

begin_define
define|#
directive|define
name|RCV_EMAIL
value|0x01
end_define

begin_comment
comment|/* Send the user email, IFF file modified. */
end_comment

begin_define
define|#
directive|define
name|RCV_ENDSESSION
value|0x02
end_define

begin_comment
comment|/* End the file session. */
end_comment

begin_define
define|#
directive|define
name|RCV_PRESERVE
value|0x04
end_define

begin_comment
comment|/* Preserve backup file, IFF file modified. */
end_comment

begin_define
define|#
directive|define
name|RCV_SNAPSHOT
value|0x08
end_define

begin_comment
comment|/* Snapshot the recovery, and send email. */
end_comment

end_unit

