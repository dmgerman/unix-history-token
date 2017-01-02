begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Time.h --------------------------------------------------*- C++ -*-===//
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
comment|// Include system time headers, adding missing functions as necessary
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_Host_Time_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Host_Time_h_
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

begin_include
include|#
directive|include
file|<time64.h>
end_include

begin_function_decl
specifier|extern
name|time_t
name|timegm
parameter_list|(
name|struct
name|tm
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Host_Time_h_
end_comment

end_unit

