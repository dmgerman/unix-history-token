begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|SYS_ENDIAN
end_ifdef

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<endian.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|htobe32
argument_list|(
name|be32toh
argument_list|(
literal|0x3a7d0cdb
argument_list|)
argument_list|)
operator|!=
literal|0x3a7d0cdb
return|;
block|}
end_function

end_unit

