begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|MAXFILES
value|15
end_define

begin_struct
struct|struct
name|fileps
block|{
name|char
modifier|*
name|buff
decl_stmt|;
comment|/* beginning of buffer */
name|char
modifier|*
name|bptr
decl_stmt|;
comment|/* current position */
name|int
name|nchars
decl_stmt|;
comment|/* number of characters internal */
name|int
name|bsize
decl_stmt|;
comment|/* size of buffer */
name|char
name|eoferr
decl_stmt|;
comment|/* end of file flag */
name|char
name|wrflag
decl_stmt|;
comment|/* mode flag */
name|char
modifier|*
name|pbuff
decl_stmt|;
comment|/* bottom of peek buffer */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|fileps
name|__filehdr
index|[
name|MAXFILES
index|]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|param
block|{
name|int
name|bufsize
decl_stmt|;
comment|/* initial buffer size */
name|int
name|peeksize
decl_stmt|;
comment|/* initial peek size */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|param
name|__param
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__statbuf
index|[
name|MAXFILES
index|]
decl_stmt|;
end_decl_stmt

end_unit

