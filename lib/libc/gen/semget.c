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
file|<sys/sem.h>
end_include

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function
name|int
name|semget
parameter_list|(
name|key_t
name|key
parameter_list|,
name|int
name|nsems
parameter_list|,
name|int
name|semflg
parameter_list|)
else|#
directive|else
function|int semget
parameter_list|(
name|key
parameter_list|,
name|nsems
parameter_list|,
name|semflg
parameter_list|)
name|key_t
name|key
decl_stmt|;
name|int
name|nsems
decl_stmt|;
name|int
name|semflg
decl_stmt|;
endif|#
directive|endif
block|{
return|return
operator|(
name|semsys
argument_list|(
literal|1
argument_list|,
name|key
argument_list|,
name|nsems
argument_list|,
name|semflg
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

