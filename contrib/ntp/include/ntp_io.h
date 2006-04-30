begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
operator|!
name|defined
name|_NTP_IO_H
end_if

begin_define
define|#
directive|define
name|_NTP_IO_H
end_define

begin_comment
comment|/*  * POSIX says use<fnct.h> to get O_* symbols and   * SEEK_SET symbol form<unistd.h>.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TYPES_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FILE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_FCNTL_H
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_WINNT
end_ifdef

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_include
include|#
directive|include
file|"win32_io.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define FNDELAY and FASYNC using O_NONBLOCK and O_ASYNC if we need  * to (and can).  This is here initially for QNX, but may help for  * others as well...  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FNDELAY
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|O_NONBLOCK
end_ifdef

begin_define
define|#
directive|define
name|FNDELAY
value|O_NONBLOCK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FASYNC
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|O_ASYNC
end_ifdef

begin_define
define|#
directive|define
name|FASYNC
value|O_ASYNC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

