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
name|msgctl
parameter_list|(
name|int
name|msqid
parameter_list|,
name|int
name|cmd
parameter_list|,
name|struct
name|msqid_ds
modifier|*
name|buf
parameter_list|)
else|#
directive|else
function|int msgctl
parameter_list|(
name|msqid
parameter_list|,
name|cmd
parameter_list|,
name|buf
parameter_list|)
name|int
name|msqid
decl_stmt|;
name|int
name|cmd
decl_stmt|;
name|caddr_t
name|buf
decl_stmt|;
endif|#
directive|endif
block|{
return|return
operator|(
name|msgsys
argument_list|(
literal|0
argument_list|,
name|msqid
argument_list|,
name|cmd
argument_list|,
name|buf
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

