begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OsLogger.h ----------------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|OsLogger_h
end_ifndef

begin_define
define|#
directive|define
name|OsLogger_h
end_define

begin_include
include|#
directive|include
file|"DNBDefs.h"
end_include

begin_decl_stmt
name|class
name|OsLogger
block|{
name|public
label|:
specifier|static
name|DNBCallbackLog
name|GetLogFunction
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OsLogger_h */
end_comment

end_unit

