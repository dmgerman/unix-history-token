begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_include
include|#
directive|include
file|"../linux_spinlock.h"
end_include

begin_include
include|#
directive|include
file|"validate.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Unsupported.\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

