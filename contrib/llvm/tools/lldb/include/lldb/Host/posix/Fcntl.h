begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Fcntl.h -------------------------------------------------*- C++ -*-===//
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
comment|// This file defines fcntl functions& structures
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_Host_posix_Fcntl_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Host_posix_Fcntl_h_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__ANDROID__
end_ifdef

begin_include
include|#
directive|include
file|<android/api-level.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ANDROID_API__
argument_list|)
operator|&&
name|__ANDROID_API__
operator|<
literal|21
end_if

begin_define
define|#
directive|define
name|F_DUPFD_CLOEXEC
value|(F_LINUX_SPECIFIC_BASE + 6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Host_posix_Fcntl_h_
end_comment

end_unit

