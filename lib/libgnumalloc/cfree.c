begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * cfree.c  */
end_comment

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

begin_function
name|void
name|cfree
parameter_list|(
name|void
modifier|*
name|foo
parameter_list|)
block|{
name|free
argument_list|(
name|foo
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

