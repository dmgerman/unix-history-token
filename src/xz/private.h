begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       private.h
end_comment

begin_comment
comment|/// \brief      Common includes, definions, and prototypes
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_include
include|#
directive|include
file|"sysdefs.h"
end_include

begin_include
include|#
directive|include
file|"mythread.h"
end_include

begin_include
include|#
directive|include
file|"lzma.h"
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
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"tuklib_gettext.h"
end_include

begin_include
include|#
directive|include
file|"tuklib_progname.h"
end_include

begin_include
include|#
directive|include
file|"tuklib_exit.h"
end_include

begin_include
include|#
directive|include
file|"tuklib_mbstr.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_define
define|#
directive|define
name|WIN32_LEAN_AND_MEAN
end_define

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDIN_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDIN_FILENO
value|(fileno(stdin))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDOUT_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|(fileno(stdout))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STDERR_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDERR_FILENO
value|(fileno(stderr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"main.h"
end_include

begin_include
include|#
directive|include
file|"mytime.h"
end_include

begin_include
include|#
directive|include
file|"coder.h"
end_include

begin_include
include|#
directive|include
file|"message.h"
end_include

begin_include
include|#
directive|include
file|"args.h"
end_include

begin_include
include|#
directive|include
file|"hardware.h"
end_include

begin_include
include|#
directive|include
file|"file_io.h"
end_include

begin_include
include|#
directive|include
file|"options.h"
end_include

begin_include
include|#
directive|include
file|"signals.h"
end_include

begin_include
include|#
directive|include
file|"suffix.h"
end_include

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_include
include|#
directive|include
file|"list.h"
end_include

end_unit

