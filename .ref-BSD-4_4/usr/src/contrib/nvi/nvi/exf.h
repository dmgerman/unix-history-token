begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)exf.h	8.1 (Berkeley) 6/9/93  */
end_comment

begin_comment
comment|/* Undo direction. */
end_comment

begin_enum
enum|enum
name|udirection
block|{
name|UBACKWARD
block|,
name|UFORWARD
block|}
enum|;
end_enum

begin_comment
comment|/*  * exf --  *	The file structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_exf
block|{
name|struct
name|_exf
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
comment|/* Linked list of files. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* File name. */
name|char
modifier|*
name|tname
decl_stmt|;
comment|/* Temporary file name. */
name|size_t
name|nlen
decl_stmt|;
comment|/* File name length. */
name|u_char
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
name|struct
name|_mark
name|l_cursor
decl_stmt|;
comment|/* Log cursor position. */
name|enum
name|udirection
name|lundo
decl_stmt|;
comment|/* Last undo direction. */
name|struct
name|_mark
name|getc_m
decl_stmt|;
comment|/* Getc mark. */
name|char
modifier|*
name|getc_bp
decl_stmt|;
comment|/* Getc buffer. */
name|size_t
name|getc_blen
decl_stmt|;
comment|/* Getc buffer length. */
name|struct
name|_mark
name|absmark
decl_stmt|;
comment|/* Saved absolute mark. */
comment|/* File marks. */
name|struct
name|_mark
name|marks
index|[
name|UCHAR_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|char
modifier|*
name|icommand
decl_stmt|;
comment|/* Initial command. */
name|char
modifier|*
name|rcv_path
decl_stmt|;
comment|/* Recover file name. */
define|#
directive|define
name|F_ICOMMAND
value|0x0001
comment|/* Initial command set. */
define|#
directive|define
name|F_IGNORE
value|0x0002
comment|/* File to be ignored. */
define|#
directive|define
name|F_FIRSTMODIFY
value|0x0004
comment|/* File not yet modified. */
define|#
directive|define
name|F_MODIFIED
value|0x0008
comment|/* File is currently dirty. */
define|#
directive|define
name|F_NAMECHANGED
value|0x0010
comment|/* File name was changed. */
define|#
directive|define
name|F_NOLOG
value|0x0020
comment|/* Logging turned off. */
define|#
directive|define
name|F_NONAME
value|0x0040
comment|/* File has no name. */
define|#
directive|define
name|F_NOSETPOS
value|0x0080
comment|/* No line position. */
define|#
directive|define
name|F_RDONLY
value|0x0100
comment|/* File is read-only. */
define|#
directive|define
name|F_RCV_ALRM
value|0x0200
comment|/* File should be synced. */
define|#
directive|define
name|F_RCV_NORM
value|0x0400
comment|/* Don't remove the recovery file. */
define|#
directive|define
name|F_RCV_ON
value|0x0800
comment|/* File is recoverable. */
define|#
directive|define
name|F_UNDO
value|0x1000
comment|/* No change since last undo. */
define|#
directive|define
name|F_CLOSECLR
comment|/* Flags to clear on close. */
define|\
value|(F_MODIFIED | F_NAMECHANGED | F_NOLOG | F_RDONLY | F_RCV_NORM |	\ 	    F_RCV_ON | F_UNDO)
name|u_int
name|flags
decl_stmt|;
block|}
name|EXF
typedef|;
end_typedef

begin_comment
comment|/* Flags to file_write(). */
end_comment

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

begin_define
define|#
directive|define
name|GETLINE_ERR
parameter_list|(
name|sp
parameter_list|,
name|lno
parameter_list|)
value|{						\ 	msgq((sp), M_ERR,						\ 	    "Error: %s/%d: unable to retrieve line %u.",		\ 	    tail(__FILE__), __LINE__, (lno));				\ }
end_define

begin_comment
comment|/* File routines. */
end_comment

begin_decl_stmt
name|int
name|file_aline
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
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
expr|struct
name|_scr
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
name|EXF
modifier|*
name|file_first
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXF
modifier|*
name|file_get
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
name|EXF
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
name|char
modifier|*
name|file_gline
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
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
expr|struct
name|_scr
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
expr|struct
name|_scr
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
name|EXF
modifier|*
name|file_next
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
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
name|EXF
modifier|*
name|file_prev
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
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
name|char
modifier|*
name|file_rline
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
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
name|file_set
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
name|int
operator|,
name|char
operator|*
index|[]
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
expr|struct
name|_scr
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
name|EXF
modifier|*
name|file_start
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
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

begin_decl_stmt
name|int
name|file_stop
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
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
name|file_write
name|__P
argument_list|(
operator|(
expr|struct
name|_scr
operator|*
operator|,
name|EXF
operator|*
operator|,
expr|struct
name|_mark
operator|*
operator|,
expr|struct
name|_mark
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

end_unit

