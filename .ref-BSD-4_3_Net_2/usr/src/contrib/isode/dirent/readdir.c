begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	readdir -- read next entry from a directory stream  	last edit:	25-Apr-1987	D A Gwyn */
end_comment

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"usr.dirent.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|GETDENTS
end_ifndef

begin_function_decl
specifier|extern
name|int
name|getdents
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* SVR3 system call, or emulation */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|struct
name|dirent
modifier|*
name|readdir
parameter_list|(
name|dirp
parameter_list|)
specifier|register
name|DIR
modifier|*
name|dirp
decl_stmt|;
comment|/* stream from opendir() */
block|{
specifier|register
name|struct
name|dirent
modifier|*
name|dp
decl_stmt|;
comment|/* -> directory data */
if|if
condition|(
name|dirp
operator|==
name|NULL
operator|||
name|dirp
operator|->
name|dd_buf
operator|==
name|NULL
condition|)
block|{
name|errno
operator|=
name|EFAULT
expr_stmt|;
return|return
name|NULL
return|;
comment|/* invalid pointer */
block|}
do|do
block|{
if|if
condition|(
name|dirp
operator|->
name|dd_loc
operator|>=
name|dirp
operator|->
name|dd_size
condition|)
comment|/* empty or obsolete */
name|dirp
operator|->
name|dd_loc
operator|=
name|dirp
operator|->
name|dd_size
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|dirp
operator|->
name|dd_size
operator|==
literal|0
comment|/* need to refill buffer */
operator|&&
operator|(
name|dirp
operator|->
name|dd_size
operator|=
name|getdents
argument_list|(
name|dirp
operator|->
name|dd_fd
argument_list|,
name|dirp
operator|->
name|dd_buf
argument_list|,
operator|(
name|unsigned
operator|)
name|DIRBUF
argument_list|)
operator|)
operator|<=
literal|0
condition|)
return|return
name|NULL
return|;
comment|/* EOF or error */
name|dp
operator|=
operator|(
expr|struct
name|dirent
operator|*
operator|)
operator|&
name|dirp
operator|->
name|dd_buf
index|[
name|dirp
operator|->
name|dd_loc
index|]
expr_stmt|;
name|dirp
operator|->
name|dd_loc
operator|+=
name|dp
operator|->
name|d_reclen
expr_stmt|;
block|}
do|while
condition|(
name|dp
operator|->
name|d_ino
operator|==
literal|0L
condition|)
do|;
comment|/* don't rely on getdents() */
return|return
name|dp
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|_readdir_stub
parameter_list|()
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

