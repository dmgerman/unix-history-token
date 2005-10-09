begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_undef
undef|#
directive|undef
name|abs
end_undef

begin_undef
undef|#
directive|undef
name|min
end_undef

begin_undef
undef|#
directive|undef
name|max
end_undef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|static
name|integer
name|memfailure
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function_decl
specifier|extern
name|void
name|G77_exit_0
parameter_list|(
name|integer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|char
modifier|*
name|F77_aloc
parameter_list|(
name|integer
name|Len
parameter_list|,
name|char
modifier|*
name|whence
parameter_list|)
block|{
name|char
modifier|*
name|rv
decl_stmt|;
name|unsigned
name|int
name|uLen
init|=
operator|(
name|unsigned
name|int
operator|)
name|Len
decl_stmt|;
comment|/* for K&R C */
if|if
condition|(
operator|!
operator|(
name|rv
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|uLen
argument_list|)
operator|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"malloc(%u) failure in %s\n"
argument_list|,
name|uLen
argument_list|,
name|whence
argument_list|)
expr_stmt|;
name|G77_exit_0
argument_list|(
operator|&
name|memfailure
argument_list|)
expr_stmt|;
block|}
return|return
name|rv
return|;
block|}
end_function

end_unit

