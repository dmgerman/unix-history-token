begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/* **  ACCESS.H -- definitions relating to the access methods. ** **	Version: **		@(#)access.h	7.1	2/5/81 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PGSIZE
end_ifndef

begin_comment
comment|/* **	PGSIZE is the physical size of a page. **	MAXTUP is the maximum size of a tuple, assuming only one **		tuple on the page.  This is PGSIZE-hdrsize, where **		hdrsize is the size of the page header (12 bytes). **	MAXLINENO is the maximum number of tuples on a page **		assuming minimum size tuples (1 byte).  This is **		constrained by the size of the lineid field of **		the tid. */
end_comment

begin_define
define|#
directive|define
name|PGSIZE
value|1024
end_define

begin_comment
comment|/* size of page */
end_comment

begin_define
define|#
directive|define
name|MAXTUP
value|1010
end_define

begin_comment
comment|/* max size of a tuple */
end_comment

begin_define
define|#
directive|define
name|MAXLINENO
value|254
end_define

begin_comment
comment|/* max tuples per page */
end_comment

begin_define
define|#
directive|define
name|PGPTRSIZ
value|4
end_define

begin_comment
comment|/* size of a tid */
end_comment

begin_define
define|#
directive|define
name|MAXTUPS
value|100
end_define

begin_comment
comment|/* maximum number of tups */
end_comment

begin_comment
comment|/* storage structure flags;< 0 means compressed */
end_comment

begin_define
define|#
directive|define
name|M_HEAP
value|5
end_define

begin_comment
comment|/* paged heap */
end_comment

begin_define
define|#
directive|define
name|M_ISAM
value|11
end_define

begin_comment
comment|/* indexed sequential */
end_comment

begin_define
define|#
directive|define
name|M_HASH
value|21
end_define

begin_comment
comment|/* random hash */
end_comment

begin_define
define|#
directive|define
name|M_BTREE
value|31
end_define

begin_comment
comment|/* BTREES */
end_comment

begin_define
define|#
directive|define
name|M_TRUNC
value|99
end_define

begin_comment
comment|/* internal pseudo-mode: truncated */
end_comment

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
comment|/* error flags */
end_comment

begin_define
define|#
directive|define
name|AMREAD_ERR
value|-1
end_define

begin_define
define|#
directive|define
name|AMWRITE_ERR
value|-2
end_define

begin_define
define|#
directive|define
name|AMNOFILE_ERR
value|-3
end_define

begin_comment
comment|/* can't open file for a relation */
end_comment

begin_define
define|#
directive|define
name|AMREL_ERR
value|-4
end_define

begin_comment
comment|/* can't open relation relation */
end_comment

begin_define
define|#
directive|define
name|AMATTR_ERR
value|-5
end_define

begin_comment
comment|/* can't open attribute relation */
end_comment

begin_define
define|#
directive|define
name|AMNOATTS_ERR
value|-6
end_define

begin_comment
comment|/* attribute missing or xtra in att-rel */
end_comment

begin_define
define|#
directive|define
name|AMCLOSE_ERR
value|-7
end_define

begin_comment
comment|/* can't close relation */
end_comment

begin_define
define|#
directive|define
name|AMFIND_ERR
value|-8
end_define

begin_comment
comment|/* unidentifiable stora  Petructure in find */
end_comment

begin_define
define|#
directive|define
name|AMINVL_ERR
value|-9
end_define

begin_comment
comment|/* invalid TID */
end_comment

begin_define
define|#
directive|define
name|AMOPNVIEW_ERR
value|-10
end_define

begin_comment
comment|/* attempt to open a view for rd or wr */
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
comment|/* **  ADMIN file struct ** **	The ADMIN struct describes the initial part of the ADMIN file **	which exists in each database.  This file is used to initially **	create the database, to maintain some information about the **	database, and to access the RELATION and ATTRIBUTE relations **	on OPENR calls. */
end_comment

begin_struct
struct|struct
name|adminhdr
block|{
name|char
name|adowner
index|[
literal|2
index|]
decl_stmt|;
comment|/* user code of data base owner */
name|short
name|adflags
decl_stmt|;
comment|/* database flags */
name|short
name|adlength
decl_stmt|;
comment|/* length of adminhdr */
name|short
name|adversion
decl_stmt|;
comment|/* database format stamp */
name|short
name|adreldsz
decl_stmt|;
comment|/* length of relation descriptor */
name|short
name|adattdsz
decl_stmt|;
comment|/* length of attribute descriptor */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|admin
block|{
name|struct
name|adminhdr
name|adhdr
decl_stmt|;
name|struct
name|descriptor
name|adreld
decl_stmt|;
name|struct
name|descriptor
name|adattd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* **  Admin status bits ** **	These bits define the status of the database.  They are **	contained in the adflags field of the admin struct. */
end_comment

begin_define
define|#
directive|define
name|A_DBCONCUR
value|0000001
end_define

begin_comment
comment|/* set database concurrency */
end_comment

begin_define
define|#
directive|define
name|A_QRYMOD
value|0000002
end_define

begin_comment
comment|/* database uses query modification */
end_comment

begin_define
define|#
directive|define
name|A_NEWFMT
value|0000004
end_define

begin_comment
comment|/* database is post-6.2 */
end_comment

begin_comment
comment|/* following is buffer space for data from admin file */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|admin
name|Admin
decl_stmt|;
end_decl_stmt

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
comment|/* ** global counters for the number of UNIX read and write **  requests issued by the access methods. */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|Accuread
decl_stmt|,
name|Accuwrite
decl_stmt|;
end_decl_stmt

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

begin_extern
extern|extern		Accerror;
end_extern

begin_comment
comment|/* error no for fatal errors */
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

begin_endif
endif|#
directive|endif
endif|PGSIZE
end_endif

end_unit

