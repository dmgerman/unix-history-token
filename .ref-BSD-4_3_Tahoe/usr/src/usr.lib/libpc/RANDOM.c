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
literal|"@(#)RANDOM.c 1.4 1/10/83"
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
name|double
name|d
decl_stmt|;
name|long
name|l
decl_stmt|;
comment|/* 	 * calculate (1103515245 * seed) mod 2^31-1 	 */
name|d
operator|=
literal|1103515245.0
operator|*
name|_seed
operator|/
literal|2147483647.0
expr_stmt|;
name|l
operator|=
name|d
expr_stmt|;
name|d
operator|=
name|d
operator|-
name|l
expr_stmt|;
name|_seed
operator|=
name|d
operator|*
literal|2147483647.0
expr_stmt|;
comment|/* 	 * want a value in the range 0..1 	 */
return|return
operator|(
name|d
operator|)
return|;
block|}
end_function

end_unit

