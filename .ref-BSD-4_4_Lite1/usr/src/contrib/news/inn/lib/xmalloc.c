begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.6 $ ** */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"configdata.h"
end_include

begin_include
include|#
directive|include
file|"libinn.h"
end_include

begin_include
include|#
directive|include
file|"clibrary.h"
end_include

begin_include
include|#
directive|include
file|"macros.h"
end_include

begin_comment
comment|/* **  Allocate some memory or call the memory failure handler. */
end_comment

begin_function
name|ALIGNPTR
name|xmalloc
parameter_list|(
name|i
parameter_list|)
name|unsigned
name|int
name|i
decl_stmt|;
block|{
name|POINTER
name|new
decl_stmt|;
while|while
condition|(
operator|(
name|new
operator|=
name|malloc
argument_list|(
name|i
argument_list|)
operator|)
operator|==
name|NULL
condition|)
call|(
modifier|*
name|xmemfailure
call|)
argument_list|(
literal|"malloc"
argument_list|,
name|i
argument_list|)
expr_stmt|;
return|return
name|CAST
argument_list|(
name|ALIGNPTR
argument_list|,
name|new
argument_list|)
return|;
block|}
end_function

end_unit

