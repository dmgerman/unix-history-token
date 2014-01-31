begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<endian.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<libkern/OSByteOrder.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|u_int64_t
name|hostorder
decl_stmt|;
name|u_int64_t
name|bigendian
init|=
literal|1
decl_stmt|;
name|hostorder
operator|=
name|betoh64
argument_list|(
name|bigendian
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

