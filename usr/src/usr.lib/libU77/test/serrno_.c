begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_macro
name|serrno_
argument_list|(
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|long
modifier|*
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|errno
operator|=
operator|*
name|n
expr_stmt|;
block|}
end_block

end_unit

