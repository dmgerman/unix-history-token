begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)glue2.c	4.1 (Berkeley) 5/6/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
name|refdir
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_macro
name|savedir
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|refdir
index|[
literal|0
index|]
operator|==
literal|0
condition|)
name|corout
argument_list|(
literal|""
argument_list|,
name|refdir
argument_list|,
literal|"/bin/pwd"
argument_list|,
literal|""
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|trimnl
argument_list|(
name|refdir
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|restodir
argument_list|()
end_macro

begin_block
block|{
name|chdir
argument_list|(
name|refdir
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

