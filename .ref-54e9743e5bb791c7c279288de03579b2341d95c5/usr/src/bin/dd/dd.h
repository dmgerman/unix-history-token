begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego and Lance  * Visser of Convex Computer Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)dd.h	8.2 (Berkeley) %G%  */
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
name|u_long
name|dbcnt
decl_stmt|;
comment|/* current buffer byte count */
name|int
name|dbrcnt
decl_stmt|;
comment|/* last read byte count */
name|u_long
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
comment|/* pipe (not truncatable) */
define|#
directive|define
name|ISTAPE
value|0x04
comment|/* tape (not seekable) */
define|#
directive|define
name|NOREAD
value|0x08
comment|/* not readable */
name|u_int
name|flags
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name */
name|int
name|fd
decl_stmt|;
comment|/* file descriptor */
name|u_long
name|offset
decl_stmt|;
comment|/* # of blocks to skip */
name|u_long
name|f_stats
decl_stmt|;
comment|/* # of full blocks processed */
name|u_long
name|p_stats
decl_stmt|;
comment|/* # of partial blocks processed */
name|u_long
name|s_stats
decl_stmt|;
comment|/* # of odd swab blocks */
name|u_long
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
name|u_long
name|in_full
decl_stmt|;
comment|/* # of full input blocks */
name|u_long
name|in_part
decl_stmt|;
comment|/* # of partial input blocks */
name|u_long
name|out_full
decl_stmt|;
comment|/* # of full output blocks */
name|u_long
name|out_part
decl_stmt|;
comment|/* # of partial output blocks */
name|u_long
name|trunc
decl_stmt|;
comment|/* # of truncated records */
name|u_long
name|swab
decl_stmt|;
comment|/* # of odd-length swab blocks */
name|u_long
name|bytes
decl_stmt|;
comment|/* # of bytes written */
name|time_t
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

end_unit

