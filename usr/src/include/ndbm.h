begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	ndbm.h	4.5	85/01/09	*/
end_comment

begin_comment
comment|/*  * Hashed key data base library.  */
end_comment

begin_define
define|#
directive|define
name|PBLKSIZ
value|1024
end_define

begin_define
define|#
directive|define
name|DBLKSIZ
value|4096
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|dbm_dirf
decl_stmt|;
comment|/* open directory file */
name|int
name|dbm_pagf
decl_stmt|;
comment|/* open page file */
name|int
name|dbm_flags
decl_stmt|;
comment|/* flags, see below */
name|long
name|dbm_maxbno
decl_stmt|;
comment|/* last ``bit'' in dir file */
name|long
name|dbm_bitno
decl_stmt|;
comment|/* current bit number */
name|long
name|dbm_hmask
decl_stmt|;
comment|/* hash mask */
name|long
name|dbm_blkptr
decl_stmt|;
comment|/* current block for dbm_nextkey */
name|int
name|dbm_keyptr
decl_stmt|;
comment|/* current key for dbm_nextkey */
name|long
name|dbm_blkno
decl_stmt|;
comment|/* current page to read/write */
name|long
name|dbm_pagbno
decl_stmt|;
comment|/* current page in pagbuf */
name|char
name|dbm_pagbuf
index|[
name|PBLKSIZ
index|]
decl_stmt|;
comment|/* page file block buffer */
name|long
name|dbm_dirbno
decl_stmt|;
comment|/* current block in dirbuf */
name|char
name|dbm_dirbuf
index|[
name|DBLKSIZ
index|]
decl_stmt|;
comment|/* directory file block buffer */
block|}
name|DBM
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_DBM_RDONLY
value|0x1
end_define

begin_comment
comment|/* data base open read-only */
end_comment

begin_define
define|#
directive|define
name|_DBM_IOERR
value|0x2
end_define

begin_comment
comment|/* data base I/O error */
end_comment

begin_define
define|#
directive|define
name|dbm_rdonly
parameter_list|(
name|db
parameter_list|)
value|((db)->dbm_flags& _DBM_RDONLY)
end_define

begin_define
define|#
directive|define
name|dbm_error
parameter_list|(
name|db
parameter_list|)
value|((db)->dbm_flags& _DBM_IOERR)
end_define

begin_comment
comment|/* use this one at your own risk! */
end_comment

begin_define
define|#
directive|define
name|dbm_clearerr
parameter_list|(
name|db
parameter_list|)
value|((db)->dbm_flags&= ~_DBM_IOERR)
end_define

begin_comment
comment|/* for flock(2) and fstat(2) */
end_comment

begin_define
define|#
directive|define
name|dbm_dirfno
parameter_list|(
name|db
parameter_list|)
value|((db)->dbm_dirf)
end_define

begin_define
define|#
directive|define
name|dbm_pagfno
parameter_list|(
name|db
parameter_list|)
value|((db)->dbm_pagf)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|dptr
decl_stmt|;
name|int
name|dsize
decl_stmt|;
block|}
name|datum
typedef|;
end_typedef

begin_comment
comment|/*  * flags to dbm_store()  */
end_comment

begin_define
define|#
directive|define
name|DBM_INSERT
value|0
end_define

begin_define
define|#
directive|define
name|DBM_REPLACE
value|1
end_define

begin_function_decl
name|DBM
modifier|*
name|dbm_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbm_close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|dbm_fetch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|dbm_firstkey
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|dbm_nextkey
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|dbm_forder
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dbm_delete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dbm_store
parameter_list|()
function_decl|;
end_function_decl

end_unit

