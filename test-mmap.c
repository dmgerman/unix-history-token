begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|MAP_FAILED
operator|!=
name|mmap
argument_list|(
name|NULL
argument_list|,
literal|1
argument_list|,
name|PROT_READ
argument_list|,
name|MAP_SHARED
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

