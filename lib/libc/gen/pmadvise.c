begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The contents of this file are in the public domain.  * Written by Garrett A. Wollman, 2000-10-07.  *  */
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

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_function
name|int
function|(
name|posix_madvise
function|)
parameter_list|(
name|void
modifier|*
name|address
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
name|how
parameter_list|)
block|{
return|return
name|posix_madvise
argument_list|(
name|address
argument_list|,
name|size
argument_list|,
name|how
argument_list|)
return|;
block|}
end_function

end_unit

