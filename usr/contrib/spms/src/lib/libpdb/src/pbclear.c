begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pbclear() clears the current database buffer CURPBUF.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CURPBUF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current database buffer */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|FP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next non-key field */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|KP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next key field */
end_comment

begin_function
name|void
name|pbclear
parameter_list|()
block|{
name|CURPBUF
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
name|FP
operator|=
name|KP
operator|=
name|CURPBUF
expr_stmt|;
block|}
end_function

end_unit

