begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)putn.c 1.1 8/27/80"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	put[1234]      *	these sort of replace the assembler code      *	which used to mung the stack inserting 1, 2, 3, or 4 and then      *	jmp ( not jsr ) to put.  these are more portable,      *	but since they can only receive integer arguments,  calls      *	to one of these with long or real arguments must be changed      *	to call put directly.      */
end_comment

begin_comment
comment|/*      *	is there some reason why these aren't #defined?      */
end_comment

begin_macro
name|put1
argument_list|(
argument|arg1
argument_list|)
end_macro

begin_decl_stmt
name|int
name|arg1
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|put
argument_list|(
literal|1
argument_list|,
name|arg1
argument_list|)
operator|)
return|;
block|}
end_block

begin_macro
name|put2
argument_list|(
argument|arg1
argument_list|,
argument|arg2
argument_list|)
end_macro

begin_decl_stmt
name|int
name|arg1
decl_stmt|,
name|arg2
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|put
argument_list|(
literal|2
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|)
operator|)
return|;
block|}
end_block

begin_macro
name|put3
argument_list|(
argument|arg1
argument_list|,
argument|arg2
argument_list|,
argument|arg3
argument_list|)
end_macro

begin_decl_stmt
name|int
name|arg1
decl_stmt|,
name|arg2
decl_stmt|,
name|arg3
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|put
argument_list|(
literal|3
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|)
operator|)
return|;
block|}
end_block

begin_macro
name|put4
argument_list|(
argument|arg1
argument_list|,
argument|arg2
argument_list|,
argument|arg3
argument_list|,
argument|arg4
argument_list|)
end_macro

begin_decl_stmt
name|int
name|arg1
decl_stmt|,
name|arg2
decl_stmt|,
name|arg3
decl_stmt|,
name|arg4
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|put
argument_list|(
literal|4
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|,
name|arg4
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

