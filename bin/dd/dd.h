begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego and Lance  * Visser of Convex Computer Corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dd.h	8.3 (Berkeley) 4/2/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Input/output stream state. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
modifier|*
name|db
decl_stmt|;
comment|/* buffer address */
name|u_char
modifier|*
name|dbp
decl_stmt|;
comment|/* current buffer I/O address */
comment|/* XXX ssize_t? */
name|size_t
name|dbcnt
decl_stmt|;
comment|/* current buffer byte count */
name|size_t
name|dbrcnt
decl_stmt|;
comment|/* last read byte count */
name|size_t
name|dbsz
decl_stmt|;
comment|/* buffer size */
define|#
directive|define
name|ISCHR
value|0x01
comment|/* character device (warn on short) */
define|#
directive|define
name|ISPIPE
value|0x02
comment|/* pipe-like (see position.c) */
define|#
directive|define
name|ISTAPE
value|0x04
comment|/* tape */
define|#
directive|define
name|ISSEEK
value|0x08
comment|/* valid to seek on */
define|#
directive|define
name|NOREAD
value|0x10
comment|/* not readable */
define|#
directive|define
name|ISTRUNC
value|0x20
comment|/* valid to ftruncate() */
name|u_int
name|flags
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name */
name|int
name|fd
decl_stmt|;
comment|/* file descriptor */
name|off_t
name|offset
decl_stmt|;
comment|/* # of blocks to skip */
name|u_quad_t
name|f_stats
decl_stmt|;
comment|/* # of full blocks processed */
name|u_quad_t
name|p_stats
decl_stmt|;
comment|/* # of partial blocks processed */
name|u_quad_t
name|s_stats
decl_stmt|;
comment|/* # of odd swab blocks */
name|u_quad_t
name|t_stats
decl_stmt|;
comment|/* # of truncations */
block|}
name|IO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_quad_t
name|in_full
decl_stmt|;
comment|/* # of full input blocks */
name|u_quad_t
name|in_part
decl_stmt|;
comment|/* # of partial input blocks */
name|u_quad_t
name|out_full
decl_stmt|;
comment|/* # of full output blocks */
name|u_quad_t
name|out_part
decl_stmt|;
comment|/* # of partial output blocks */
name|u_quad_t
name|trunc
decl_stmt|;
comment|/* # of truncated records */
name|u_quad_t
name|swab
decl_stmt|;
comment|/* # of odd-length swab blocks */
name|u_quad_t
name|bytes
decl_stmt|;
comment|/* # of bytes written */
name|double
name|start
decl_stmt|;
comment|/* start time of dd */
block|}
name|STAT
typedef|;
end_typedef

begin_comment
comment|/* Flags (in ddflags). */
end_comment

begin_define
define|#
directive|define
name|C_ASCII
value|0x00001
end_define

begin_define
define|#
directive|define
name|C_BLOCK
value|0x00002
end_define

begin_define
define|#
directive|define
name|C_BS
value|0x00004
end_define

begin_define
define|#
directive|define
name|C_CBS
value|0x00008
end_define

begin_define
define|#
directive|define
name|C_COUNT
value|0x00010
end_define

begin_define
define|#
directive|define
name|C_EBCDIC
value|0x00020
end_define

begin_define
define|#
directive|define
name|C_FILES
value|0x00040
end_define

begin_define
define|#
directive|define
name|C_IBS
value|0x00080
end_define

begin_define
define|#
directive|define
name|C_IF
value|0x00100
end_define

begin_define
define|#
directive|define
name|C_LCASE
value|0x00200
end_define

begin_define
define|#
directive|define
name|C_NOERROR
value|0x00400
end_define

begin_define
define|#
directive|define
name|C_NOTRUNC
value|0x00800
end_define

begin_define
define|#
directive|define
name|C_OBS
value|0x01000
end_define

begin_define
define|#
directive|define
name|C_OF
value|0x02000
end_define

begin_define
define|#
directive|define
name|C_SEEK
value|0x04000
end_define

begin_define
define|#
directive|define
name|C_SKIP
value|0x08000
end_define

begin_define
define|#
directive|define
name|C_SWAB
value|0x10000
end_define

begin_define
define|#
directive|define
name|C_SYNC
value|0x20000
end_define

begin_define
define|#
directive|define
name|C_UCASE
value|0x40000
end_define

begin_define
define|#
directive|define
name|C_UNBLOCK
value|0x80000
end_define

begin_define
define|#
directive|define
name|C_OSYNC
value|0x100000
end_define

begin_define
define|#
directive|define
name|C_SPARSE
value|0x200000
end_define

end_unit

