begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include

begin_include
include|#
directive|include
file|<sys/msg.h>
end_include

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function
name|int
name|msgget
parameter_list|(
name|key_t
name|key
parameter_list|,
name|int
name|msgflg
parameter_list|)
else|#
directive|else
function|int msgget
parameter_list|(
name|key
parameter_list|,
name|msgflg
parameter_list|)
name|key_t
name|key
decl_stmt|;
name|int
name|msgflg
decl_stmt|;
endif|#
directive|endif
block|{
return|return
operator|(
name|msgsys
argument_list|(
literal|1
argument_list|,
name|key
argument_list|,
name|msgflg
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

