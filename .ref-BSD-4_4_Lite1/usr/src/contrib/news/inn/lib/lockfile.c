begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.4 $ ** */
end_comment

begin_include
include|#
directive|include
file|"configdata.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LOCK_NONE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(LOCK_NONE) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LOCK_FLOCK
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(LOCK_FLOCK) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LOCK_LOCKF
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DO_HAVE_UNISTD
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(DO_HAVE_UNISTD) */
end_comment

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(LOCK_LOCKF) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LOCK_FCNTL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SEEK_SET
argument_list|)
end_if

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

begin_comment
comment|/* !defined(SEEK_SET) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(LOCK_FCNTL) */
end_comment

begin_comment
comment|/* **  Try to lock a file descriptor. */
end_comment

begin_function
name|int
name|LockFile
parameter_list|(
name|fd
parameter_list|,
name|Block
parameter_list|)
name|int
name|fd
decl_stmt|;
name|BOOL
name|Block
decl_stmt|;
block|{
if|#
directive|if
name|defined
argument_list|(
name|LOCK_NONE
argument_list|)
name|struct
name|stat
name|Sb
decl_stmt|;
return|return
name|fstat
argument_list|(
name|fd
argument_list|,
operator|&
name|Sb
argument_list|)
return|;
endif|#
directive|endif
comment|/* defined(LOCK_NONE) */
if|#
directive|if
name|defined
argument_list|(
name|LOCK_FLOCK
argument_list|)
return|return
name|flock
argument_list|(
name|fd
argument_list|,
name|Block
condition|?
name|LOCK_EX
else|:
name|LOCK_EX
operator||
name|LOCK_NB
argument_list|)
return|;
endif|#
directive|endif
comment|/* defined(LOCK_FLOCK) */
if|#
directive|if
name|defined
argument_list|(
name|LOCK_LOCKF
argument_list|)
return|return
name|lockf
argument_list|(
name|fd
argument_list|,
name|Block
condition|?
name|F_LOCK
else|:
name|F_TLOCK
argument_list|,
literal|0L
argument_list|)
return|;
endif|#
directive|endif
comment|/* defined(LOCK_LOCKF) */
if|#
directive|if
name|defined
argument_list|(
name|LOCK_FCNTL
argument_list|)
name|struct
name|flock
name|fl
decl_stmt|;
name|fl
operator|.
name|l_type
operator|=
name|F_WRLCK
expr_stmt|;
name|fl
operator|.
name|l_whence
operator|=
name|SEEK_SET
expr_stmt|;
name|fl
operator|.
name|l_start
operator|=
literal|0
expr_stmt|;
name|fl
operator|.
name|l_len
operator|=
literal|0
expr_stmt|;
return|return
name|fcntl
argument_list|(
name|fd
argument_list|,
name|Block
condition|?
name|F_SETLKW
else|:
name|F_SETLK
argument_list|,
operator|&
name|fl
argument_list|)
return|;
endif|#
directive|endif
comment|/* defined(LOCK_FCNTL) */
block|}
end_function

end_unit

