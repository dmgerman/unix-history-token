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
literal|"@(#)NAM.c 1.3 6/10/81"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_function
name|char
modifier|*
name|NAM
parameter_list|(
name|val
parameter_list|,
name|name
parameter_list|)
name|long
name|val
decl_stmt|;
comment|/* internal enumerated type value */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* ptr to enumerated type name descriptor */
block|{
specifier|register
name|int
name|value
init|=
name|val
decl_stmt|;
specifier|register
name|short
modifier|*
name|sptr
decl_stmt|;
name|sptr
operator|=
operator|(
name|short
operator|*
operator|)
name|name
expr_stmt|;
if|if
condition|(
name|value
operator|<
literal|0
operator|||
name|value
operator|>=
operator|*
name|sptr
condition|)
block|{
name|ERROR
argument_list|(
literal|"Enumerated type value of %D is out of range on output\n"
argument_list|,
name|val
argument_list|)
expr_stmt|;
return|return;
block|}
name|sptr
operator|++
expr_stmt|;
return|return
name|name
operator|+
literal|2
operator|+
name|sptr
index|[
name|value
index|]
return|;
block|}
end_function

end_unit

