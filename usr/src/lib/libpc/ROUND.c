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
literal|"@(#)ROUND.c 1.1 10/29/80"
decl_stmt|;
end_decl_stmt

begin_macro
name|ROUND
argument_list|(
argument|value
argument_list|)
end_macro

begin_decl_stmt
name|double
name|value
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
call|(
name|long
call|)
argument_list|(
name|value
operator|+
literal|0.5
argument_list|)
return|;
block|}
end_block

end_unit

