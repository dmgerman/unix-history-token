begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
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
name|SUPPORT_SET_WINDOWS_CRT_REPORT_MODE_H
end_ifndef

begin_define
define|#
directive|define
name|SUPPORT_SET_WINDOWS_CRT_REPORT_MODE_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_DEBUG
end_ifndef

begin_error
error|#
directive|error
error|_DEBUG must be defined when using this header
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32
end_ifndef

begin_error
error|#
directive|error
error|This header can only be used when targeting Windows
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<crtdbg.h>
end_include

begin_comment
comment|// On Windows in debug builds the default assertion handler opens a new dialog
end_comment

begin_comment
comment|// window which must be dismissed manually by the user. This function overrides
end_comment

begin_comment
comment|// that setting and instead changes the assertion handler to log to stderr
end_comment

begin_comment
comment|// instead.
end_comment

begin_function
specifier|inline
name|int
name|init_crt_report_mode
parameter_list|()
block|{
name|_CrtSetReportMode
argument_list|(
name|_CRT_WARN
argument_list|,
name|_CRTDBG_MODE_DEBUG
argument_list|)
expr_stmt|;
name|_CrtSetReportMode
argument_list|(
name|_CRT_ERROR
argument_list|,
name|_CRTDBG_MODE_DEBUG
argument_list|)
expr_stmt|;
name|_CrtSetReportMode
argument_list|(
name|_CRT_ASSERT
argument_list|,
name|_CRTDBG_MODE_DEBUG
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|int
name|init_crt_anchor
init|=
name|init_crt_report_mode
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SUPPORT_SET_WINDOWS_CRT_REPORT_MODE_H
end_comment

end_unit

