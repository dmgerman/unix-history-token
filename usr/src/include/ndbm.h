begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      ndbm.h     4.1     83/12/02     */
end_comment

begin_comment
comment|/*  * (New) Hashed key data base library (-lndbm).  */
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
name|db_dirf
decl_stmt|;
comment|/* open directory file */
name|int
name|db_pagf
decl_stmt|;
comment|/* open page file */
name|int
name|db_flags
decl_stmt|;
define|#
directive|define
name|_DB_RDONLY
value|0x1
comment|/* data base open read-only */
name|long
name|db_maxbno
decl_stmt|;
comment|/* last ``block'' in page file */
name|long
name|db_bitno
decl_stmt|;
name|long
name|db_hmask
decl_stmt|;
name|long
name|db_blkno
decl_stmt|;
comment|/* current page to read/write */
name|long
name|db_pagbno
decl_stmt|;
comment|/* current page in pagbuf */
name|char
name|db_pagbuf
index|[
name|PBLKSIZ
index|]
decl_stmt|;
comment|/* page file block buffer */
name|long
name|db_dirbno
decl_stmt|;
comment|/* current block in dirbuf */
name|char
name|db_dirbuf
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
name|dbrdonly
parameter_list|(
name|db
parameter_list|)
value|((db)->db_flags&_DB_RDONLY) != 0
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

begin_function_decl
name|datum
name|dbmfetch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|dbmfirstkey
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|dbmnextkey
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|dbmforder
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dbmdelete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dbmstore
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|DBM
modifier|*
name|ndbmopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ndbmclose
parameter_list|()
function_decl|;
end_function_decl

end_unit

