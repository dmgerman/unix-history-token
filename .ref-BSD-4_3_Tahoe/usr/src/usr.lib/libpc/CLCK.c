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
literal|"@(#)CLCK.c 1.2 3/7/81"
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|CLCK
parameter_list|()
block|{
name|long
name|tim
index|[
literal|4
index|]
decl_stmt|;
name|times
argument_list|(
name|tim
argument_list|)
expr_stmt|;
return|return
operator|(
name|tim
index|[
literal|0
index|]
operator|*
literal|50
operator|)
operator|/
literal|3
return|;
block|}
end_function

end_unit

