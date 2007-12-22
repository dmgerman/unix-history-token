begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"thr_private.h"
end_include

begin_expr_stmt
name|LT10_COMPAT_PRIVATE
argument_list|(
name|_vfork
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LT10_COMPAT_DEFAULT
argument_list|(
name|vfork
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|_vfork
argument_list|,
name|vfork
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|_vfork
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|fork
argument_list|()
operator|)
return|;
block|}
end_function

end_unit

