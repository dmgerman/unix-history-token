begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	closedir -- close a directory stream  	last edit:	25-Apr-1987	D A Gwyn */
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

begin_typedef
typedef|typedef
name|char
modifier|*
name|pointer
typedef|;
end_typedef

begin_comment
comment|/* (void *) if you have it */
end_comment

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|close
parameter_list|()
function_decl|;
end_function_decl

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
name|int
name|closedir
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
name|int
name|fd
decl_stmt|;
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
operator|-
literal|1
return|;
comment|/* invalid pointer */
block|}
name|fd
operator|=
name|dirp
operator|->
name|dd_fd
expr_stmt|;
name|free
argument_list|(
operator|(
name|pointer
operator|)
name|dirp
operator|->
name|dd_buf
argument_list|)
expr_stmt|;
name|free
argument_list|(
operator|(
name|pointer
operator|)
name|dirp
argument_list|)
expr_stmt|;
return|return
name|close
argument_list|(
name|fd
argument_list|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|_closedir_stub
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

