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
literal|"@(#)RANDOM.c 1.3 %G%"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_function_decl
specifier|extern
name|long
name|RAND
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|double
name|RANDOM
parameter_list|()
block|{
comment|/* 	 * div by maxint to get 0..1 	 */
name|_seed
operator|=
name|RAND
argument_list|(
name|_seed
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|double
operator|)
name|_seed
operator|/
literal|0x7fffffff
operator|)
return|;
block|}
end_function

end_unit

