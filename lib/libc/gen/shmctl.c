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
name|shmctl
parameter_list|(
name|int
name|shmid
parameter_list|,
name|int
name|cmd
parameter_list|,
name|struct
name|shmid_ds
modifier|*
name|buf
parameter_list|)
else|#
directive|else
function|int shmctl
parameter_list|(
name|shmid
parameter_list|,
name|cmd
parameter_list|,
name|buf
parameter_list|)
name|int
name|shmid
decl_stmt|;
name|int
name|cmd
decl_stmt|;
name|struct
name|shmid_ds
modifier|*
name|buf
decl_stmt|;
endif|#
directive|endif
block|{
return|return
operator|(
name|shmsys
argument_list|(
literal|4
argument_list|,
name|shmid
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

