begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m_name.c - return a message number as a string */
end_comment

begin_include
include|#
directive|include
file|"../h/mh.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|static
name|char
name|name
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|m_name
parameter_list|(
name|num
parameter_list|)
specifier|register
name|int
name|num
decl_stmt|;
block|{
if|if
condition|(
name|num
operator|<=
literal|0
condition|)
return|return
literal|"?"
return|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|name
argument_list|,
literal|"%d"
argument_list|,
name|num
argument_list|)
expr_stmt|;
return|return
name|name
return|;
block|}
end_function

end_unit

