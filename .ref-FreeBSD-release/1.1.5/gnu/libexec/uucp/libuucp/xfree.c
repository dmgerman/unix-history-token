begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xfree.c    Some versions of free (like the one in SCO Unix 3.2.2) don't handle    null pointers correctly, so we go through our own routine.  */
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
name|void
name|xfree
parameter_list|(
name|p
parameter_list|)
name|pointer
name|p
decl_stmt|;
block|{
if|if
condition|(
name|p
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

