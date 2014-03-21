begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/Unix/Unix.h - Common Unix Include File -------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines things specific to Unix implementations.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SYSTEM_UNIX_UNIX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEM_UNIX_UNIX_H
end_define

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//=== WARNING: Implementation here must contain only generic UNIX code that
end_comment

begin_comment
comment|//===          is guaranteed to work on all UNIX variants.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"llvm/Config/config.h"
end_include

begin_comment
comment|// Get autoconf configuration settings
end_comment

begin_include
include|#
directive|include
file|"llvm/Support/Errno.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<cerrno>
end_include

begin_include
include|#
directive|include
file|<cstdio>
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIME_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_WAIT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_DLFCN_H
end_ifdef

begin_include
include|#
directive|include
file|<dlfcn.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WEXITSTATUS
end_ifndef

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|stat_val
parameter_list|)
value|((unsigned)(stat_val)>> 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WIFEXITED
end_ifndef

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|stat_val
parameter_list|)
value|(((stat_val)& 255) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// This function builds an error message into \p ErrMsg using the \p prefix
end_comment

begin_comment
comment|/// string and the Unix error number given by \p errnum. If errnum is -1, the
end_comment

begin_comment
comment|/// default then the value of errno is used.
end_comment

begin_comment
comment|/// @brief Make an error message
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If the error number can be converted to a string, it will be
end_comment

begin_comment
comment|/// separated from prefix by ": ".
end_comment

begin_decl_stmt
specifier|static
specifier|inline
name|bool
name|MakeErrMsg
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrMsg
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|prefix
argument_list|,
name|int
name|errnum
operator|=
operator|-
literal|1
argument_list|)
block|{
if|if
condition|(
operator|!
name|ErrMsg
condition|)
return|return
name|true
return|;
if|if
condition|(
name|errnum
operator|==
operator|-
literal|1
condition|)
name|errnum
operator|=
name|errno
expr_stmt|;
operator|*
name|ErrMsg
operator|=
name|prefix
operator|+
literal|": "
operator|+
name|llvm
operator|::
name|sys
operator|::
name|StrError
argument_list|(
name|errnum
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

