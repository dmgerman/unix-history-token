begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xmalloc.c    Allocate a block of memory without fail.  */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|"uudefs.h"
end_include

begin_function
name|pointer
name|xmalloc
parameter_list|(
name|c
parameter_list|)
name|size_t
name|c
decl_stmt|;
block|{
name|pointer
name|pret
decl_stmt|;
name|pret
operator|=
name|malloc
argument_list|(
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|pret
operator|==
name|NULL
operator|&&
name|c
operator|!=
literal|0
condition|)
name|ulog
argument_list|(
name|LOG_FATAL
argument_list|,
literal|"Out of memory"
argument_list|)
expr_stmt|;
return|return
name|pret
return|;
block|}
end_function

end_unit

