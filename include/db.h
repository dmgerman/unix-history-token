begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)db.h	8.7 (Berkeley) 6/16/94  * $FreeBSD$  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
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
value|0xffffffff
end_define

begin_comment
comment|/*>= # of pages in a file */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|pgno_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_PAGE_OFFSET
value|65535
end_define

begin_comment
comment|/*>= # of bytes in a page */
end_comment

begin_typedef
typedef|typedef
name|u_int16_t
name|indx_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_REC_NUMBER
value|0xffffffff
end_define

begin_comment
comment|/*>= # of records in a tree */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
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
name|R_CURSOR
value|1
end_define

begin_comment
comment|/* del, put, seq */
end_comment

begin_define
define|#
directive|define
name|__R_UNUSED
value|2
end_define

begin_comment
comment|/* UNUSED */
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

begin_define
define|#
directive|define
name|R_SETCURSOR
value|10
end_define

begin_comment
comment|/* put (RECNO) */
end_comment

begin_define
define|#
directive|define
name|R_RECNOSYNC
value|11
end_define

begin_comment
comment|/* sync (RECNO) */
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
comment|/*  * !!!  * The following flags are included in the dbopen(3) call as part of the  * open(2) flags.  In order to avoid conflicts with the open flags, start  * at the top of the 16 or 32-bit number space and work our way down.  If  * the open flags were significantly expanded in the future, it could be  * a problem.  Wish I'd left another flags word in the dbopen call.  *  * !!!  * None of this stuff is implemented yet.  The only reason that it's here  * is so that the access methods can skip copying the key/data pair when  * the DB_LOCK flag isn't set.  */
end_comment

begin_if
if|#
directive|if
name|UINT_MAX
operator|>
literal|65535
end_if

begin_define
define|#
directive|define
name|DB_LOCK
value|0x20000000
end_define

begin_comment
comment|/* Do locking. */
end_comment

begin_define
define|#
directive|define
name|DB_SHMEM
value|0x40000000
end_define

begin_comment
comment|/* Use shared memory. */
end_comment

begin_define
define|#
directive|define
name|DB_TXN
value|0x80000000
end_define

begin_comment
comment|/* Do transactions. */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DB_LOCK
value|0x2000
end_define

begin_comment
comment|/* Do locking. */
end_comment

begin_define
define|#
directive|define
name|DB_SHMEM
value|0x4000
end_define

begin_comment
comment|/* Use shared memory. */
end_comment

begin_define
define|#
directive|define
name|DB_TXN
value|0x8000
end_define

begin_comment
comment|/* Do transactions. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Underlying db type. */
name|int
function_decl|(
modifier|*
name|close
function_decl|)
parameter_list|(
name|struct
name|__db
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|del
function_decl|)
parameter_list|(
specifier|const
name|struct
name|__db
modifier|*
parameter_list|,
specifier|const
name|DBT
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|get
function_decl|)
parameter_list|(
specifier|const
name|struct
name|__db
modifier|*
parameter_list|,
specifier|const
name|DBT
modifier|*
parameter_list|,
name|DBT
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|put
function_decl|)
parameter_list|(
specifier|const
name|struct
name|__db
modifier|*
parameter_list|,
name|DBT
modifier|*
parameter_list|,
specifier|const
name|DBT
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|seq
function_decl|)
parameter_list|(
specifier|const
name|struct
name|__db
modifier|*
parameter_list|,
name|DBT
modifier|*
parameter_list|,
name|DBT
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sync
function_decl|)
parameter_list|(
specifier|const
name|struct
name|__db
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|void
modifier|*
name|internal
decl_stmt|;
comment|/* Access method private. */
name|int
function_decl|(
modifier|*
name|fd
function_decl|)
parameter_list|(
specifier|const
name|struct
name|__db
modifier|*
parameter_list|)
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
name|u_int
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
name|u_int
name|psize
decl_stmt|;
comment|/* page size */
name|int
function_decl|(
modifier|*
name|compare
function_decl|)
comment|/* comparison function */
parameter_list|(
specifier|const
name|DBT
modifier|*
parameter_list|,
specifier|const
name|DBT
modifier|*
parameter_list|)
function_decl|;
name|size_t
function_decl|(
modifier|*
name|prefix
function_decl|)
comment|/* prefix function */
parameter_list|(
specifier|const
name|DBT
modifier|*
parameter_list|,
specifier|const
name|DBT
modifier|*
parameter_list|)
function_decl|;
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
value|2
end_define

begin_comment
comment|/* Structure used to pass parameters to the hashing routines. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|bsize
decl_stmt|;
comment|/* bucket size */
name|u_int
name|ffactor
decl_stmt|;
comment|/* fill factor */
name|u_int
name|nelem
decl_stmt|;
comment|/* number of elements */
name|u_int
name|cachesize
decl_stmt|;
comment|/* bytes to cache */
name|u_int32_t
comment|/* hash function */
function_decl|(
modifier|*
name|hash
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
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
name|u_int
name|cachesize
decl_stmt|;
comment|/* bytes to cache */
name|u_int
name|psize
decl_stmt|;
comment|/* page size */
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
name|char
modifier|*
name|bfname
decl_stmt|;
comment|/* btree file name */
block|}
name|RECNOINFO
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__DBINTERFACE_PRIVATE
end_ifdef

begin_comment
comment|/*  * Little endian<==> big endian 32-bit swap macros.  *	M_32_SWAP	swap a memory location  *	P_32_SWAP	swap a referenced memory location  *	P_32_COPY	swap from one location to another  */
end_comment

begin_define
define|#
directive|define
name|M_32_SWAP
parameter_list|(
name|a
parameter_list|)
value|{							\ 	u_int32_t _tmp = a;						\ 	((char *)&a)[0] = ((char *)&_tmp)[3];				\ 	((char *)&a)[1] = ((char *)&_tmp)[2];				\ 	((char *)&a)[2] = ((char *)&_tmp)[1];				\ 	((char *)&a)[3] = ((char *)&_tmp)[0];				\ }
end_define

begin_define
define|#
directive|define
name|P_32_SWAP
parameter_list|(
name|a
parameter_list|)
value|{							\ 	u_int32_t _tmp = *(u_int32_t *)a;				\ 	((char *)a)[0] = ((char *)&_tmp)[3];				\ 	((char *)a)[1] = ((char *)&_tmp)[2];				\ 	((char *)a)[2] = ((char *)&_tmp)[1];				\ 	((char *)a)[3] = ((char *)&_tmp)[0];				\ }
end_define

begin_define
define|#
directive|define
name|P_32_COPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{						\ 	((char *)&(b))[0] = ((char *)&(a))[3];				\ 	((char *)&(b))[1] = ((char *)&(a))[2];				\ 	((char *)&(b))[2] = ((char *)&(a))[1];				\ 	((char *)&(b))[3] = ((char *)&(a))[0];				\ }
end_define

begin_comment
comment|/*  * Little endian<==> big endian 16-bit swap macros.  *	M_16_SWAP	swap a memory location  *	P_16_SWAP	swap a referenced memory location  *	P_16_COPY	swap from one location to another  */
end_comment

begin_define
define|#
directive|define
name|M_16_SWAP
parameter_list|(
name|a
parameter_list|)
value|{							\ 	u_int16_t _tmp = a;						\ 	((char *)&a)[0] = ((char *)&_tmp)[1];				\ 	((char *)&a)[1] = ((char *)&_tmp)[0];				\ }
end_define

begin_define
define|#
directive|define
name|P_16_SWAP
parameter_list|(
name|a
parameter_list|)
value|{							\ 	u_int16_t _tmp = *(u_int16_t *)a;				\ 	((char *)a)[0] = ((char *)&_tmp)[1];				\ 	((char *)a)[1] = ((char *)&_tmp)[0];				\ }
end_define

begin_define
define|#
directive|define
name|P_16_COPY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{						\ 	((char *)&(b))[0] = ((char *)&(a))[1];				\ 	((char *)&(b))[1] = ((char *)&(a))[0];				\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__BEGIN_DECLS
name|DB
modifier|*
name|dbopen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|DBTYPE
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__DBINTERFACE_PRIVATE
end_ifdef

begin_function_decl
name|DB
modifier|*
name|__bt_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|BTREEINFO
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DB
modifier|*
name|__hash_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|HASHINFO
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DB
modifier|*
name|__rec_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|RECNOINFO
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__dbpanic
parameter_list|(
name|DB
modifier|*
name|dbp
parameter_list|)
function_decl|;
end_function_decl

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

