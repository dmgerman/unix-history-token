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
literal|"$Id: shmat.c,v 1.1 1993/09/27 00:57:45 rgrimes Exp $"
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
name|void
modifier|*
name|shmat
parameter_list|(
name|int
name|shmid
parameter_list|,
name|void
modifier|*
name|shmaddr
parameter_list|,
name|int
name|shmflg
parameter_list|)
else|#
directive|else
function|void *shmat
parameter_list|(
name|shmid
parameter_list|,
name|shmaddr
parameter_list|,
name|shmflg
parameter_list|)
name|int
name|shmid
decl_stmt|;
name|void
modifier|*
name|shmaddr
decl_stmt|;
name|int
name|shmflg
decl_stmt|;
endif|#
directive|endif
block|{
return|return
operator|(
operator|(
name|void
operator|*
operator|)
name|shmsys
argument_list|(
literal|0
argument_list|,
name|shmid
argument_list|,
name|shmaddr
argument_list|,
name|shmflg
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

