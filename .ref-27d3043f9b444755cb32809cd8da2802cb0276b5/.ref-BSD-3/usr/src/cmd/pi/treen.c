begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_comment
comment|/*      *	is there some reason why these aren't #defined?      */
end_comment

begin_macro
name|tree1
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
name|tree
argument_list|(
literal|1
argument_list|,
name|arg1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|tree2
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
name|tree
argument_list|(
literal|2
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|tree3
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
name|tree
argument_list|(
literal|3
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|tree4
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
name|tree
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
expr_stmt|;
block|}
end_block

begin_macro
name|tree5
argument_list|(
argument|arg1
argument_list|,
argument|arg2
argument_list|,
argument|arg3
argument_list|,
argument|arg4
argument_list|,
argument|arg5
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
decl_stmt|,
name|arg5
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|tree
argument_list|(
literal|5
argument_list|,
name|arg1
argument_list|,
name|arg2
argument_list|,
name|arg3
argument_list|,
name|arg4
argument_list|,
name|arg5
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

