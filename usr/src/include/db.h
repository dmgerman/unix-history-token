begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)db.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* flags for DB.put() call */
end_comment

begin_define
define|#
directive|define
name|R_IBEFORE
value|1
end_define

begin_comment
comment|/* RECNO */
end_comment

begin_define
define|#
directive|define
name|R_IAFTER
value|2
end_define

begin_comment
comment|/* RECNO */
end_comment

begin_define
define|#
directive|define
name|R_NOOVERWRITE
value|3
end_define

begin_comment
comment|/* BTREE, HASH, RECNO */
end_comment

begin_define
define|#
directive|define
name|R_PUT
value|4
end_define

begin_comment
comment|/* flags for DB.seq() call */
end_comment

begin_define
define|#
directive|define
name|R_CURSOR
value|1
end_define

begin_comment
comment|/* BTREE, RECNO */
end_comment

begin_define
define|#
directive|define
name|R_FIRST
value|2
end_define

begin_comment
comment|/* BTREE, HASH, RECNO */
end_comment

begin_define
define|#
directive|define
name|R_LAST
value|3
end_define

begin_comment
comment|/* BTREE, RECNO */
end_comment

begin_define
define|#
directive|define
name|R_NEXT
value|4
end_define

begin_comment
comment|/* BTREE, HASH, RECNO */
end_comment

begin_define
define|#
directive|define
name|R_PREV
value|5
end_define

begin_comment
comment|/* BTREE, RECNO */
end_comment

begin_comment
comment|/* key/data structure -- a data-base thang */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|data
decl_stmt|;
name|int
name|size
decl_stmt|;
block|}
name|DBT
typedef|;
end_typedef

begin_comment
comment|/* access method description structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|internal
decl_stmt|;
comment|/* access method private; really void * */
name|int
function_decl|(
modifier|*
name|close
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|delete
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|get
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|put
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|seq
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|sync
function_decl|)
parameter_list|()
function_decl|;
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

begin_comment
comment|/* structure used to pass parameters to the btree routines */
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
name|psize
decl_stmt|;
comment|/* page size */
name|int
function_decl|(
modifier|*
name|compare
function_decl|)
parameter_list|()
function_decl|;
comment|/* compare function */
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

begin_comment
comment|/* structure used to pass parameters to the hashing routines */
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
name|ncached
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
block|}
name|HASHINFO
typedef|;
end_typedef

begin_comment
comment|/* structure used to pass parameters to the record routines */
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
name|u_long
name|flags
decl_stmt|;
name|int
name|cachesize
decl_stmt|;
comment|/* bytes to cache */
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
comment|/* key structure for the record routines */
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

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

begin_function_decl
name|DB
modifier|*
name|btree_open
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|mode
parameter_list|,
specifier|const
name|BTREEINFO
modifier|*
name|private
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DB
modifier|*
name|hash_open
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|mode
parameter_list|,
specifier|const
name|HASHINFO
modifier|*
name|private
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DB
modifier|*
name|recno_open
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|mode
parameter_list|,
specifier|const
name|RECNOINFO
modifier|*
name|private
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|DB
modifier|*
name|btree_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|DB
modifier|*
name|hash_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|DB
modifier|*
name|recno_open
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

