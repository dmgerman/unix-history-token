begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)db.h	5.13 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DB_H_
end_ifndef

begin_define
define|#
directive|define
name|_DB_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|RET_ERROR
value|-1
end_define

begin_comment
comment|/* Return values. */
end_comment

begin_define
define|#
directive|define
name|RET_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|RET_SPECIAL
value|1
end_define

begin_define
define|#
directive|define
name|MAX_PAGE_NUMBER
value|ULONG_MAX
end_define

begin_comment
comment|/*>= # of pages in a file */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|pgno_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_PAGE_OFFSET
value|USHRT_MAX
end_define

begin_comment
comment|/*>= # of bytes in a page */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|index_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_REC_NUMBER
value|ULONG_MAX
end_define

begin_comment
comment|/*>= # of records in a tree */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|recno_t
typedef|;
end_typedef

begin_comment
comment|/* Key/data structure -- a Data-Base Thang. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|data
decl_stmt|;
comment|/* data */
name|size_t
name|size
decl_stmt|;
comment|/* data length */
block|}
name|DBT
typedef|;
end_typedef

begin_comment
comment|/* Routine flags. */
end_comment

begin_define
define|#
directive|define
name|R_APPEND
value|1
end_define

begin_comment
comment|/* put (RECNO) */
end_comment

begin_define
define|#
directive|define
name|R_CURSOR
value|2
end_define

begin_comment
comment|/* del, put, seq */
end_comment

begin_define
define|#
directive|define
name|R_FIRST
value|3
end_define

begin_comment
comment|/* seq */
end_comment

begin_define
define|#
directive|define
name|R_IAFTER
value|4
end_define

begin_comment
comment|/* put (RECNO) */
end_comment

begin_define
define|#
directive|define
name|R_IBEFORE
value|5
end_define

begin_comment
comment|/* put (RECNO) */
end_comment

begin_define
define|#
directive|define
name|R_LAST
value|6
end_define

begin_comment
comment|/* seq (BTREE, RECNO) */
end_comment

begin_define
define|#
directive|define
name|R_NEXT
value|7
end_define

begin_comment
comment|/* seq */
end_comment

begin_define
define|#
directive|define
name|R_NOOVERWRITE
value|8
end_define

begin_comment
comment|/* put */
end_comment

begin_define
define|#
directive|define
name|R_PREV
value|9
end_define

begin_comment
comment|/* seq (BTREE, RECNO) */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|DB_BTREE
block|,
name|DB_HASH
block|,
name|DB_RECNO
block|}
name|DBTYPE
typedef|;
end_typedef

begin_comment
comment|/* Access method description structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__db
block|{
name|DBTYPE
name|type
decl_stmt|;
comment|/* type of underlying db */
name|void
modifier|*
name|internal
decl_stmt|;
comment|/* access method private */
name|int
argument_list|(
argument|*close
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|__db
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*del
argument_list|)
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|__db
operator|*
operator|,
specifier|const
name|DBT
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*get
argument_list|)
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|__db
operator|*
operator|,
specifier|const
name|DBT
operator|*
operator|,
name|DBT
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*put
argument_list|)
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|__db
operator|*
operator|,
specifier|const
name|DBT
operator|*
operator|,
specifier|const
name|DBT
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*seq
argument_list|)
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|__db
operator|*
operator|,
name|DBT
operator|*
operator|,
name|DBT
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*sync
argument_list|)
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|__db
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
name|DB
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BTREEMAGIC
value|0x053162
end_define

begin_define
define|#
directive|define
name|BTREEVERSION
value|3
end_define

begin_comment
comment|/* Structure used to pass parameters to the btree routines. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
define|#
directive|define
name|R_DUP
value|0x01
comment|/* duplicate keys */
name|u_long
name|flags
decl_stmt|;
name|int
name|cachesize
decl_stmt|;
comment|/* bytes to cache */
name|int
name|maxkeypage
decl_stmt|;
comment|/* maximum keys per page */
name|int
name|minkeypage
decl_stmt|;
comment|/* minimum keys per page */
name|int
name|psize
decl_stmt|;
comment|/* page size */
comment|/* comparison, prefix functions */
name|int
argument_list|(
argument|*compare
argument_list|)
name|__P
argument_list|(
operator|(
specifier|const
name|DBT
operator|*
operator|,
specifier|const
name|DBT
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*prefix
argument_list|)
name|__P
argument_list|(
operator|(
specifier|const
name|DBT
operator|*
operator|,
specifier|const
name|DBT
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
name|lorder
decl_stmt|;
comment|/* byte order */
block|}
name|BTREEINFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HASHMAGIC
value|0x061561
end_define

begin_define
define|#
directive|define
name|HASHVERSION
value|1
end_define

begin_comment
comment|/* Structure used to pass parameters to the hashing routines. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|bsize
decl_stmt|;
comment|/* bucket size */
name|int
name|ffactor
decl_stmt|;
comment|/* fill factor */
name|int
name|nelem
decl_stmt|;
comment|/* number of elements */
name|int
name|cachesize
decl_stmt|;
comment|/* bytes to cache */
name|int
function_decl|(
modifier|*
name|hash
function_decl|)
parameter_list|()
function_decl|;
comment|/* hash function */
name|int
name|lorder
decl_stmt|;
comment|/* byte order */
block|}
name|HASHINFO
typedef|;
end_typedef

begin_comment
comment|/* Structure used to pass parameters to the record routines. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
define|#
directive|define
name|R_FIXEDLEN
value|0x01
comment|/* fixed-length records */
define|#
directive|define
name|R_NOKEY
value|0x02
comment|/* key not required */
define|#
directive|define
name|R_SNAPSHOT
value|0x04
comment|/* snapshot the input */
name|u_long
name|flags
decl_stmt|;
name|int
name|cachesize
decl_stmt|;
comment|/* bytes to cache */
name|int
name|lorder
decl_stmt|;
comment|/* byte order */
name|size_t
name|reclen
decl_stmt|;
comment|/* record length (fixed-length records) */
name|u_char
name|bval
decl_stmt|;
comment|/* delimiting byte (variable-length records */
block|}
name|RECNOINFO
typedef|;
end_typedef

begin_comment
comment|/* Key structure for the record routines. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_long
name|number
decl_stmt|;
name|u_long
name|offset
decl_stmt|;
name|u_long
name|length
decl_stmt|;
define|#
directive|define
name|R_LENGTH
value|0x01
comment|/* length is valid */
define|#
directive|define
name|R_NUMBER
value|0x02
comment|/* record number is valid */
define|#
directive|define
name|R_OFFSET
value|0x04
comment|/* offset is valid */
name|u_char
name|valid
decl_stmt|;
block|}
name|RECNOKEY
typedef|;
end_typedef

begin_comment
comment|/*  * Little endian<==> big endian long swap macros.  *	BLSWAP		swap a memory location  *	BLPSWAP		swap a referenced memory location  *	BLSWAP_COPY	swap from one location to another  */
end_comment

begin_define
define|#
directive|define
name|BLSWAP
parameter_list|(
name|a
parameter_list|)
value|{ \ 	u_long _tmp = a; \ 	((char *)&a)[0] = ((char *)&_tmp)[3]; \ 	((char *)&a)[1] = ((char *)&_tmp)[2]; \ 	((char *)&a)[2] = ((char *)&_tmp)[1]; \ 	((char *)&a)[3] = ((char *)&_tmp)[0]; \ }
end_define

begin_define
define|#
directive|define
name|BLPSWAP
parameter_list|(
name|a
parameter_list|)
value|{ \ 	u_long _tmp = *(u_long *)a; \ 	((char *)a)[0] = ((char *)&_tmp)[3]; \ 	((char *)a)[1] = ((char *)&_tmp)[2]; \ 	((char *)a)[2] = ((char *)&_tmp)[1]; \ 	((char *)a)[3] = ((char *)&_tmp)[0]; \ }
end_define

begin_define
define|#
directive|define
name|BLSWAP_COPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{ \ 	((char *)&(b))[0] = ((char *)&(a))[3]; \ 	((char *)&(b))[1] = ((char *)&(a))[2]; \ 	((char *)&(b))[2] = ((char *)&(a))[1]; \ 	((char *)&(b))[3] = ((char *)&(a))[0]; \ }
end_define

begin_comment
comment|/*  * Little endian<==> big endian short swap macros.  *	BSSWAP		swap a memory location  *	BSPSWAP		swap a referenced memory location  *	BSSWAP_COPY	swap from one location to another  */
end_comment

begin_define
define|#
directive|define
name|BSSWAP
parameter_list|(
name|a
parameter_list|)
value|{ \ 	u_short _tmp = a; \ 	((char *)&a)[0] = ((char *)&_tmp)[1]; \ 	((char *)&a)[1] = ((char *)&_tmp)[0]; \ }
end_define

begin_define
define|#
directive|define
name|BSPSWAP
parameter_list|(
name|a
parameter_list|)
value|{ \ 	u_short _tmp = *(u_short *)a; \ 	((char *)a)[0] = ((char *)&_tmp)[1]; \ 	((char *)a)[1] = ((char *)&_tmp)[0]; \ }
end_define

begin_define
define|#
directive|define
name|BSSWAP_COPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{ \ 	((char *)&(b))[0] = ((char *)&(a))[1]; \ 	((char *)&(b))[1] = ((char *)&(a))[0]; \ }
end_define

begin_decl_stmt
name|__BEGIN_DECLS
name|DB
modifier|*
name|dbopen
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|DBTYPE
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__DBINTERFACE_PRIVATE
end_ifdef

begin_decl_stmt
name|DB
modifier|*
name|__bt_open
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
specifier|const
name|BTREEINFO
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DB
modifier|*
name|__hash_open
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
specifier|const
name|HASHINFO
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DB
modifier|*
name|__rec_open
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
specifier|const
name|RECNOINFO
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__dbpanic
name|__P
argument_list|(
operator|(
name|DB
operator|*
name|dbp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DB_H_ */
end_comment

end_unit

