begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	rewinddir -- rewind a directory stream  	last edit:	25-Apr-1987	D A Gwyn  	This is not simply a call to seekdir(), because seekdir() 	will use the current buffer whenever possible and we need 	rewinddir() to forget about buffered data. */
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
name|off_t
name|lseek
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

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|rewinddir
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
return|return;
comment|/* invalid pointer */
block|}
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
comment|/* invalidate buffer */
operator|(
name|void
operator|)
name|lseek
argument_list|(
name|dirp
operator|->
name|dd_fd
argument_list|,
operator|(
name|off_t
operator|)
literal|0
argument_list|,
name|SEEK_SET
argument_list|)
expr_stmt|;
comment|/* may set errno */
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|_rewinddir_stub
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

