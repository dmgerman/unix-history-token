begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

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
file|<sys/shm.h>
end_include

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function
name|int
name|shmget
parameter_list|(
name|key_t
name|key
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|shmflg
parameter_list|)
else|#
directive|else
function|int shmget
parameter_list|(
name|key
parameter_list|,
name|size
parameter_list|,
name|shmflg
parameter_list|)
name|key_t
name|key
decl_stmt|;
name|int
name|size
decl_stmt|;
name|int
name|shmflg
decl_stmt|;
endif|#
directive|endif
block|{
return|return
operator|(
name|shmsys
argument_list|(
literal|3
argument_list|,
name|key
argument_list|,
name|size
argument_list|,
name|shmflg
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

