begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_msan -std=c99 -O0 -g %s -o %t&& %run %t
end_comment

begin_comment
comment|// strerror_r under a weird set of circumstances can be redirected to
end_comment

begin_comment
comment|// __xpg_strerror_r. Test that MSan handles this correctly.
end_comment

begin_define
define|#
directive|define
name|_POSIX_C_SOURCE
value|200112
end_define

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|char
name|buf
index|[
literal|1000
index|]
decl_stmt|;
name|int
name|res
init|=
name|strerror_r
argument_list|(
name|EINVAL
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|)
decl_stmt|;
name|assert
argument_list|(
operator|!
name|res
argument_list|)
expr_stmt|;
specifier|volatile
name|int
name|z
init|=
name|strlen
argument_list|(
name|buf
argument_list|)
decl_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

