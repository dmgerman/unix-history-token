begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1982 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)EXP.c 1.1 2/8/82"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function
name|double
name|EXP
parameter_list|(
name|value
parameter_list|)
name|double
name|value
decl_stmt|;
block|{
name|double
name|result
decl_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
name|result
operator|=
name|exp
argument_list|(
name|value
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
operator|!=
literal|0
condition|)
block|{
name|ERROR
argument_list|(
literal|"exp(%e) yields a result that is out of the range of reals\n"
argument_list|,
name|value
argument_list|)
expr_stmt|;
return|return;
block|}
return|return
name|result
return|;
block|}
end_function

end_unit

