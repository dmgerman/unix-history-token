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
literal|"@(#)UNWIND.c 1.2 3/7/81"
decl_stmt|;
end_decl_stmt

begin_macro
name|UNWIND
argument_list|(
argument|frame
argument_list|)
end_macro

begin_decl_stmt
name|long
modifier|*
name|frame
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|PCLOSE
argument_list|(
operator|*
name|frame
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

