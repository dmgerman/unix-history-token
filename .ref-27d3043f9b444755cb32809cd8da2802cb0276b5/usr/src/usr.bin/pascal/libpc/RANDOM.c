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
literal|"@(#)RANDOM.c 1.1 %G%"
decl_stmt|;
end_decl_stmt

begin_function
name|double
name|RANDOM
parameter_list|()
block|{
comment|/* 	 * div by maxint to get 0..1 	 */
return|return
operator|(
name|rand
argument_list|()
operator|/
literal|2.147483647e+09
operator|)
return|;
block|}
end_function

end_unit

