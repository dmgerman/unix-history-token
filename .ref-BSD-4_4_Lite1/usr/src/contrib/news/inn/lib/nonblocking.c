begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.6 $ ** */
end_comment

begin_include
include|#
directive|include
file|"configdata.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NBIO_IOCTL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_comment
comment|/* **  Enable or disable non-blocking I/O mode. */
end_comment

begin_function
name|int
name|SetNonBlocking
parameter_list|(
name|fd
parameter_list|,
name|flag
parameter_list|)
name|int
name|fd
decl_stmt|;
name|BOOL
name|flag
decl_stmt|;
block|{
name|int
name|state
decl_stmt|;
name|state
operator|=
name|flag
condition|?
literal|1
else|:
literal|0
expr_stmt|;
return|return
name|ioctl
argument_list|(
name|fd
argument_list|,
name|FIONBIO
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|state
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(NBIO_IOCTL) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NBIO_FCNTL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

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
name|FNDELAY
argument_list|)
end_if

begin_define
define|#
directive|define
name|FNDELAY
value|O_NDELAY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(FNDELAY) */
end_comment

begin_comment
comment|/* **  Enable or disable non-blocking I/O mode. */
end_comment

begin_function
name|int
name|SetNonBlocking
parameter_list|(
name|fd
parameter_list|,
name|flag
parameter_list|)
name|int
name|fd
decl_stmt|;
name|BOOL
name|flag
decl_stmt|;
block|{
name|int
name|mode
decl_stmt|;
if|if
condition|(
operator|(
name|mode
operator|=
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_GETFL
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
name|flag
condition|)
name|mode
operator||=
name|FNDELAY
expr_stmt|;
else|else
name|mode
operator|&=
operator|~
name|FNDELAY
expr_stmt|;
return|return
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_SETFL
argument_list|,
name|mode
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(NBIO_FCNTL) */
end_comment

end_unit

