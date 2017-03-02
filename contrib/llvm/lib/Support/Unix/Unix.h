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
name|LLVM_LIB_SUPPORT_UNIX_UNIX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_SUPPORT_UNIX_UNIX_H
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
file|"llvm/Support/Chrono.h"
end_include

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

begin_include
include|#
directive|include
file|<sys/wait.h>
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|/// Convert a struct timeval to a duration. Note that timeval can be used both
comment|/// as a time point and a duration. Be sure to check what the input represents.
specifier|inline
name|std
operator|::
name|chrono
operator|::
name|microseconds
name|toDuration
argument_list|(
argument|const struct timeval&TV
argument_list|)
block|{
return|return
name|std
operator|::
name|chrono
operator|::
name|seconds
argument_list|(
name|TV
operator|.
name|tv_sec
argument_list|)
operator|+
name|std
operator|::
name|chrono
operator|::
name|microseconds
argument_list|(
name|TV
operator|.
name|tv_usec
argument_list|)
return|;
block|}
comment|/// Convert a time point to struct timespec.
specifier|inline
name|struct
name|timespec
name|toTimeSpec
argument_list|(
name|TimePoint
operator|<
operator|>
name|TP
argument_list|)
block|{
name|using
name|namespace
name|std
operator|::
name|chrono
expr_stmt|;
name|struct
name|timespec
name|RetVal
decl_stmt|;
name|RetVal
operator|.
name|tv_sec
operator|=
name|toTimeT
argument_list|(
name|TP
argument_list|)
expr_stmt|;
name|RetVal
operator|.
name|tv_nsec
operator|=
operator|(
name|TP
operator|.
name|time_since_epoch
argument_list|()
operator|%
name|seconds
argument_list|(
literal|1
argument_list|)
operator|)
operator|.
name|count
argument_list|()
expr_stmt|;
return|return
name|RetVal
return|;
block|}
comment|/// Convert a time point to struct timeval.
specifier|inline
name|struct
name|timeval
name|toTimeVal
argument_list|(
name|TimePoint
operator|<
name|std
operator|::
name|chrono
operator|::
name|microseconds
operator|>
name|TP
argument_list|)
block|{
name|using
name|namespace
name|std
operator|::
name|chrono
expr_stmt|;
name|struct
name|timeval
name|RetVal
decl_stmt|;
name|RetVal
operator|.
name|tv_sec
operator|=
name|toTimeT
argument_list|(
name|TP
argument_list|)
expr_stmt|;
name|RetVal
operator|.
name|tv_usec
operator|=
operator|(
name|TP
operator|.
name|time_since_epoch
argument_list|()
operator|%
name|seconds
argument_list|(
literal|1
argument_list|)
operator|)
operator|.
name|count
argument_list|()
expr_stmt|;
return|return
name|RetVal
return|;
block|}
block|}
comment|// namespace sys
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

