begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"EXTERN.h"
end_include

begin_include
include|#
directive|include
file|"perl.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|userinit
parameter_list|()
block|{
name|install_null
argument_list|()
expr_stmt|;
comment|/* install device /dev/null or NUL: */
return|return
literal|0
return|;
block|}
end_function

end_unit

