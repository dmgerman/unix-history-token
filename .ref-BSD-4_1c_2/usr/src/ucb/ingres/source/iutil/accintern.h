begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  ACCINTERN.H -- internal declarations for the access methods ** **	Nothing in here should be needed for the outside world. ** **	Version: **		@(#)accintern.h	7.1	2/5/81 */
end_comment

begin_include
include|#
directive|include
file|<access.h>
end_include

begin_define
define|#
directive|define
name|NACCBUFS
value|3
end_define

begin_comment
comment|/* number of access method buffers */
end_comment

begin_comment
comment|/* the following is the access methods buffer */
end_comment

begin_struct
struct|struct
name|accbuf
block|{
comment|/* this stuff is actually stored in the relation */
name|long
name|mainpg
decl_stmt|;
comment|/* next main page (0 - eof) */
name|long
name|ovflopg
decl_stmt|;
comment|/* next ovflo page (0 - none) */
name|short
name|nxtlino
decl_stmt|;
comment|/* next avail line no for this page */
name|char
name|firstup
index|[
name|PGSIZE
operator|-
literal|12
index|]
decl_stmt|;
comment|/* tuple space */
name|short
name|linetab
index|[
literal|1
index|]
decl_stmt|;
comment|/* line table at end of buffer - grows down */
comment|/* linetab[lineno] is offset into 					** the buffer for that line; linetab[nxtlino] 					** is free space pointer */
comment|/* this stuff is not stored in the relation */
name|long
name|rel_tupid
decl_stmt|;
comment|/* unique relation id */
name|long
name|thispage
decl_stmt|;
comment|/* page number of the current page */
name|int
name|filedesc
decl_stmt|;
comment|/* file descriptor for this reln */
name|struct
name|accbuf
modifier|*
name|modf
decl_stmt|;
comment|/* use time link list forward pointer */
name|struct
name|accbuf
modifier|*
name|modb
decl_stmt|;
comment|/* back pointer */
name|int
name|bufstatus
decl_stmt|;
comment|/* various bits defined below */
block|}
struct|;
end_struct

begin_comment
comment|/* The following assignments are status bits for accbuf.bufstatus */
end_comment

begin_define
define|#
directive|define
name|BUF_DIRTY
value|001
end_define

begin_comment
comment|/* page has been changed */
end_comment

begin_define
define|#
directive|define
name|BUF_LOCKED
value|002
end_define

begin_comment
comment|/* page has a page lock on it */
end_comment

begin_define
define|#
directive|define
name|BUF_DIRECT
value|004
end_define

begin_comment
comment|/* this is a page from isam direct */
end_comment

begin_comment
comment|/* access method buffer typed differently for various internal operations */
end_comment

begin_struct
struct|struct
block|{
name|char
name|acc_buf
index|[
name|NACCBUFS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* pointers to maintain the buffer */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|accbuf
modifier|*
name|Acc_head
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of the LRU list */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|accbuf
modifier|*
name|Acc_tail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tail of the LRU list */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|accbuf
name|Acc_buf
index|[
name|NACCBUFS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the buffers themselves */
end_comment

begin_comment
comment|/* **  PGTUPLE -- btree index key (a tid and an index key) */
end_comment

begin_struct
struct|struct
name|pgtuple
block|{
name|struct
name|tup_id
name|childtid
decl_stmt|;
comment|/* the pointer comes before */
name|char
name|childtup
index|[
name|MAXTUP
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* **	Global values used by everything */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Acctuple
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to canonical tuple */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|Accanon
index|[
name|MAXTUP
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* canonical tuple buffer */
end_comment

begin_comment
comment|/* **  In-line expansion of trace flags. */
end_comment

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|tT
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|PDP11
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|tTf
end_ifndef

begin_define
define|#
directive|define
name|tTf
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((b< 0) ? tT[a] : (tT[a]& (1<< b)))
end_define

begin_endif
endif|#
directive|endif
endif|tTf
end_endif

begin_endif
endif|#
directive|endif
endif|PDP11
end_endif

end_unit

