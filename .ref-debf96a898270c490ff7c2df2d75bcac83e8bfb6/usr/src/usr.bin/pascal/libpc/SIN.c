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
literal|"@(#)SIN.c 1.2 %G%"
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
name|SIN
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
name|sin
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
literal|"Cannot compute sin(%e)\n"
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function

end_unit

