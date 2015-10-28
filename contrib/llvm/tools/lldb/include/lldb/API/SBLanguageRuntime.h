begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBLanguageRuntime.h -------------------------------------*- C++ -*-===//
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
name|LLDB_SBLanguageRuntime_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBLanguageRuntime_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBLanguageRuntime
block|{
name|public
label|:
specifier|static
name|lldb
operator|::
name|LanguageType
name|GetLanguageTypeFromString
argument_list|(
specifier|const
name|char
operator|*
name|string
argument_list|)
expr_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|GetNameForLanguageType
argument_list|(
name|lldb
operator|::
name|LanguageType
name|language
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBLanguageRuntime_h_
end_comment

end_unit

