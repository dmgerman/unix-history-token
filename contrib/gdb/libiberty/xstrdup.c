begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xstrdup.c -- Duplicate a string in memory, using xmalloc.    This trivial function is in the public domain.    Ian Lance Taylor, Cygnus Support, December 1995.  */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_function
name|char
modifier|*
name|xstrdup
parameter_list|(
name|s
parameter_list|)
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|char
modifier|*
name|ret
decl_stmt|;
name|ret
operator|=
name|xmalloc
argument_list|(
name|strlen
argument_list|(
name|s
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|ret
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

end_unit

