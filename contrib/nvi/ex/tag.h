begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  * Copyright (c) 1994, 1996  *	Rob Mayoff.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)tag.h	10.5 (Berkeley) 5/15/96  */
end_comment

begin_comment
comment|/*  * Cscope connection information.  One of these is maintained per cscope  * connection, linked from the EX_PRIVATE structure.  */
end_comment

begin_struct
struct|struct
name|_csc
block|{
name|LIST_ENTRY
argument_list|(
argument|_csc
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of cscope connections. */
name|char
modifier|*
name|dname
decl_stmt|;
comment|/* Base directory of this cscope connection. */
name|size_t
name|dlen
decl_stmt|;
comment|/* Length of base directory. */
name|pid_t
name|pid
decl_stmt|;
comment|/* PID of the connected cscope process. */
name|time_t
name|mtime
decl_stmt|;
comment|/* Last modification time of cscope database. */
name|FILE
modifier|*
name|from_fp
decl_stmt|;
comment|/* from cscope: FILE. */
name|int
name|from_fd
decl_stmt|;
comment|/* from cscope: file descriptor. */
name|FILE
modifier|*
name|to_fp
decl_stmt|;
comment|/* to cscope: FILE. */
name|int
name|to_fd
decl_stmt|;
comment|/* to cscope: file descriptor. */
name|char
modifier|*
modifier|*
name|paths
decl_stmt|;
comment|/* Array of search paths for this cscope. */
name|char
modifier|*
name|pbuf
decl_stmt|;
comment|/* Search path buffer. */
name|size_t
name|pblen
decl_stmt|;
comment|/* Search path buffer length. */
name|char
name|buf
index|[
literal|1
index|]
decl_stmt|;
comment|/* Variable length buffer. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Tag file information.  One of these is maintained per tag file, linked  * from the EXPRIVATE structure.  */
end_comment

begin_struct
struct|struct
name|_tagf
block|{
comment|/* Tag files. */
name|TAILQ_ENTRY
argument_list|(
argument|_tagf
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of tag files. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Tag file name. */
name|int
name|errnum
decl_stmt|;
comment|/* Errno. */
define|#
directive|define
name|TAGF_ERR
value|0x01
comment|/* Error occurred. */
define|#
directive|define
name|TAGF_ERR_WARN
value|0x02
comment|/* Error reported. */
name|u_int8_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Tags are structured internally as follows:  *  * +----+    +----+	+----+     +----+  * | EP | -> | Q1 |<-- | T1 |<-- | T2 |  * +----+    +----+ --> +----+ --> +----+  *	     |  *	     +----+     +----+  *	     | Q2 |<-- | T1 |  *	     +----+ --> +----+  *	     |  *	     +----+	+----+  *	     | Q3 |<-- | T1 |  *	     +----+ --> +----+  *  * Each Q is a TAGQ, or tag "query", which is the result of one tag or cscope  * command.  Each Q references one or more TAG's, or tagged file locations.  *  * tag:		put a new Q at the head	(^])  * tagnext:	T1 -> T2 inside Q	(^N)  * tagprev:	T2 -> T1 inside Q	(^P)  * tagpop:	discard Q		(^T)  * tagtop:	discard all Q  */
end_comment

begin_struct
struct|struct
name|_tag
block|{
comment|/* Tag list. */
name|CIRCLEQ_ENTRY
argument_list|(
argument|_tag
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of tags. */
comment|/* Tag pop/return information. */
name|FREF
modifier|*
name|frp
decl_stmt|;
comment|/* Saved file. */
name|recno_t
name|lno
decl_stmt|;
comment|/* Saved line number. */
name|size_t
name|cno
decl_stmt|;
comment|/* Saved column number. */
name|char
modifier|*
name|fname
decl_stmt|;
comment|/* Filename. */
name|size_t
name|fnlen
decl_stmt|;
comment|/* Filename length. */
name|recno_t
name|slno
decl_stmt|;
comment|/* Search line number. */
name|char
modifier|*
name|search
decl_stmt|;
comment|/* Search string. */
name|size_t
name|slen
decl_stmt|;
comment|/* Search string length. */
name|char
name|buf
index|[
literal|1
index|]
decl_stmt|;
comment|/* Variable length buffer. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_tagq
block|{
comment|/* Tag queue. */
name|CIRCLEQ_ENTRY
argument_list|(
argument|_tagq
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of tag queues. */
comment|/* This queue's tag list. */
name|CIRCLEQ_HEAD
argument_list|(
argument|_tagqh
argument_list|,
argument|_tag
argument_list|)
name|tagq
expr_stmt|;
name|TAG
modifier|*
name|current
decl_stmt|;
comment|/* Current TAG within the queue. */
name|char
modifier|*
name|tag
decl_stmt|;
comment|/* Tag string. */
name|size_t
name|tlen
decl_stmt|;
comment|/* Tag string length. */
define|#
directive|define
name|TAG_CSCOPE
value|0x01
comment|/* Cscope tag. */
name|u_int8_t
name|flags
decl_stmt|;
name|char
name|buf
index|[
literal|1
index|]
decl_stmt|;
comment|/* Variable length buffer. */
block|}
struct|;
end_struct

end_unit

