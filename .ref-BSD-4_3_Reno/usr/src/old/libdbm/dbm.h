begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	dbm.h	4.1	83/05/03	*/
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

begin_define
define|#
directive|define
name|BYTESIZ
value|8
end_define

begin_define
define|#
directive|define
name|NULL
value|((char *) 0)
end_define

begin_decl_stmt
name|long
name|bitno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|maxbno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|blkno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|hmask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|pagbuf
index|[
name|PBLKSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|dirbuf
index|[
name|DBLKSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dirf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pagf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dbrdonly
decl_stmt|;
end_decl_stmt

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
name|fetch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|makdatum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|firstkey
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|nextkey
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|firsthash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|calchash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|hashinc
parameter_list|()
function_decl|;
end_function_decl

end_unit

