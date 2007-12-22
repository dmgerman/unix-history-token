begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_include
include|#
directive|include
file|"libc_private.h"
end_include

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_getprogname
argument_list|,
name|getprogname
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|const
name|char
modifier|*
name|_getprogname
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__progname
operator|)
return|;
block|}
end_function

end_unit

