begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.5 $ ** */
end_comment

begin_include
include|#
directive|include
file|"configdata.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"clibrary.h"
end_include

begin_escape
end_escape

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CLX_IOCTL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_comment
comment|/* **  Mark a file close-on-exec so that it doesn't get shared with our **  children.  Ignore any error codes. */
end_comment

begin_function
name|void
name|CloseOnExec
parameter_list|(
name|fd
parameter_list|,
name|flag
parameter_list|)
name|int
name|fd
decl_stmt|;
name|int
name|flag
decl_stmt|;
block|{
name|int
name|oerrno
decl_stmt|;
name|oerrno
operator|=
name|errno
expr_stmt|;
operator|(
name|void
operator|)
name|ioctl
argument_list|(
name|fd
argument_list|,
name|flag
condition|?
name|FIOCLEX
else|:
name|FIONCLEX
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
name|errno
operator|=
name|oerrno
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(CLX_IOCTL) */
end_comment

begin_escape
end_escape

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CLX_FCNTL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_comment
comment|/* **  Mark a file close-on-exec so that it doesn't get shared with our **  children.  Ignore any error codes. */
end_comment

begin_function
name|void
name|CloseOnExec
parameter_list|(
name|fd
parameter_list|,
name|flag
parameter_list|)
name|int
name|fd
decl_stmt|;
name|int
name|flag
decl_stmt|;
block|{
name|int
name|oerrno
decl_stmt|;
name|oerrno
operator|=
name|errno
expr_stmt|;
operator|(
name|void
operator|)
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETFD
argument_list|,
name|flag
condition|?
literal|1
else|:
literal|0
argument_list|)
expr_stmt|;
name|errno
operator|=
name|oerrno
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(CLX_FCNTL) */
end_comment

end_unit

