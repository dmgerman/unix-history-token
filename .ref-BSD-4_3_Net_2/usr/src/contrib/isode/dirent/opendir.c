begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	opendir -- open a directory stream  	last edit:	16-Jun-1987	D A Gwyn */
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
file|<sys/stat.h>
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

begin_ifdef
ifdef|#
directive|ifdef
name|BSD_SYSV
end_ifdef

begin_define
define|#
directive|define
name|open
value|_open
end_define

begin_comment
comment|/* avoid emulation overhead */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
name|pointer
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|open
argument_list|()
decl_stmt|,
name|close
argument_list|()
decl_stmt|,
name|fstat
argument_list|()
decl_stmt|;
end_decl_stmt

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
name|O_RDONLY
end_ifndef

begin_define
define|#
directive|define
name|O_RDONLY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_comment
comment|/* macro to test for directory file */
end_comment

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|DIR
modifier|*
name|opendir
parameter_list|(
name|dirname
parameter_list|)
name|char
modifier|*
name|dirname
decl_stmt|;
comment|/* name of directory */
block|{
specifier|register
name|DIR
modifier|*
name|dirp
decl_stmt|;
comment|/* -> malloc'ed storage */
specifier|register
name|int
name|fd
decl_stmt|;
comment|/* file descriptor for read */
name|struct
name|stat
name|sbuf
decl_stmt|;
comment|/* result of fstat() */
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|dirname
argument_list|,
name|O_RDONLY
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
name|NULL
return|;
comment|/* errno set by open() */
if|if
condition|(
name|fstat
argument_list|(
name|fd
argument_list|,
operator|&
name|sbuf
argument_list|)
operator|!=
literal|0
operator|||
operator|!
name|S_ISDIR
argument_list|(
name|sbuf
operator|.
name|st_mode
argument_list|)
condition|)
block|{
operator|(
name|void
operator|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|errno
operator|=
name|ENOTDIR
expr_stmt|;
return|return
name|NULL
return|;
comment|/* not a directory */
block|}
if|if
condition|(
operator|(
name|dirp
operator|=
operator|(
name|DIR
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|DIR
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
operator|||
operator|(
name|dirp
operator|->
name|dd_buf
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
operator|(
name|unsigned
operator|)
name|DIRBUF
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
specifier|register
name|int
name|serrno
init|=
name|errno
decl_stmt|;
comment|/* errno set to ENOMEM by sbrk() */
if|if
condition|(
name|dirp
operator|!=
name|NULL
condition|)
name|free
argument_list|(
operator|(
name|pointer
operator|)
name|dirp
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|errno
operator|=
name|serrno
expr_stmt|;
return|return
name|NULL
return|;
comment|/* not enough memory */
block|}
name|dirp
operator|->
name|dd_fd
operator|=
name|fd
expr_stmt|;
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
comment|/* refill needed */
return|return
name|dirp
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|_opendir_stub
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

