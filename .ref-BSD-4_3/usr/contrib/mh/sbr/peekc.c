begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* peekc.c - peek at the next character in a stream */
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

begin_function
name|int
name|peekc
parameter_list|(
name|ib
parameter_list|)
specifier|register
name|FILE
modifier|*
name|ib
decl_stmt|;
block|{
specifier|register
name|int
name|c
decl_stmt|;
name|c
operator|=
name|getc
argument_list|(
name|ib
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|ungetc
argument_list|(
name|c
argument_list|,
name|ib
argument_list|)
expr_stmt|;
return|return
name|c
return|;
block|}
end_function

end_unit

