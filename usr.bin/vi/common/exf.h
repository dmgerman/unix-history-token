begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)exf.h	8.35 (Berkeley) 8/4/94  */
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
name|enum
name|direction
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
name|struct
name|timeval
name|rcv_tod
decl_stmt|;
comment|/* ITIMER_REAL: recovery time-of-day. */
define|#
directive|define
name|F_FIRSTMODIFY
value|0x001
comment|/* File not yet modified. */
define|#
directive|define
name|F_MODIFIED
value|0x002
comment|/* File is currently dirty. */
define|#
directive|define
name|F_MULTILOCK
value|0x004
comment|/* Multiple processes running, lock. */
define|#
directive|define
name|F_NOLOG
value|0x008
comment|/* Logging turned off. */
define|#
directive|define
name|F_RCV_NORM
value|0x010
comment|/* Don't delete recovery files. */
define|#
directive|define
name|F_RCV_ON
value|0x020
comment|/* Recovery is possible. */
define|#
directive|define
name|F_UNDO
value|0x040
comment|/* No change since last undo. */
name|u_int8_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GETLINE_ERR
parameter_list|(
name|sp
parameter_list|,
name|lno
parameter_list|)
value|{						\ 	msgq(sp, M_ERR,							\ 	    "Error: %s/%d: unable to retrieve line %u",			\ 	    tail(__FILE__), __LINE__, lno);				\ }
end_define

begin_comment
comment|/* EXF routines. */
end_comment

begin_decl_stmt
name|FREF
modifier|*
name|file_add
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|CHAR_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|file_end
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|file_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|FREF
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|file_m1
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|file_m2
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|file_m3
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|lockt
block|{
name|LOCK_FAILED
block|,
name|LOCK_SUCCESS
block|,
name|LOCK_UNAVAIL
block|}
enum|;
end_enum

begin_decl_stmt
name|enum
name|lockt
name|file_lock
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FS_ALL
value|0x01
end_define

begin_comment
comment|/* Write the entire file. */
end_comment

begin_define
define|#
directive|define
name|FS_APPEND
value|0x02
end_define

begin_comment
comment|/* Append to the file. */
end_comment

begin_define
define|#
directive|define
name|FS_FORCE
value|0x04
end_define

begin_comment
comment|/* Force is set. */
end_comment

begin_define
define|#
directive|define
name|FS_POSSIBLE
value|0x08
end_define

begin_comment
comment|/* Force could be set. */
end_comment

begin_decl_stmt
name|int
name|file_write
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|MARK
operator|*
operator|,
name|MARK
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Recovery routines. */
end_comment

begin_decl_stmt
name|int
name|rcv_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rcv_list
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rcv_on
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rcv_read
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|FREF
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|int
name|rcv_sync
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rcv_tmp
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DB interface routines */
end_comment

begin_decl_stmt
name|int
name|file_aline
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|int
operator|,
name|recno_t
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|file_dline
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|recno_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|file_gline
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|recno_t
operator|,
name|size_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|file_iline
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|recno_t
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|file_lline
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|recno_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|file_rline
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|recno_t
operator|,
name|size_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|file_sline
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|,
name|recno_t
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

