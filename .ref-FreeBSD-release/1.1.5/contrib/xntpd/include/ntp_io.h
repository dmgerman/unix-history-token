begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * POSIX says use<fnct.h> to get O_* symbols and   * SEEK_SET symbol form<untisd.h>.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NTP_POSIX_SOURCE
argument_list|)
end_if

begin_comment
comment|/*  * POSIX way  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SIGNALED_IO
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|SYS_AUX2
argument_list|)
operator|||
name|defined
argument_list|(
name|SYS_AUX3
argument_list|)
operator|||
name|defined
argument_list|(
name|SYS_PTX
argument_list|)
operator|)
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

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * BSD way  */
end_comment

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
name|SEEK_SET
argument_list|)
operator|&&
name|defined
argument_list|(
name|L_SET
argument_list|)
end_if

begin_define
define|#
directive|define
name|SEEK_SET
value|L_SET
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

