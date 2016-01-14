begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CPPLanguageRuntime.h ---------------------------------------------------*- C++ -*-===//
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
name|liblldb_CPPLanguageRuntime_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CPPLanguageRuntime_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/LanguageRuntime.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CPPLanguageRuntime
range|:
name|public
name|LanguageRuntime
block|{
name|public
operator|:
operator|~
name|CPPLanguageRuntime
argument_list|()
name|override
block|;
name|lldb
operator|::
name|LanguageType
name|GetLanguageType
argument_list|()
specifier|const
name|override
block|{
return|return
name|lldb
operator|::
name|eLanguageTypeC_plus_plus
return|;
block|}
name|virtual
name|bool
name|IsVTableName
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
operator|=
literal|0
block|;
name|bool
name|GetObjectDescription
argument_list|(
argument|Stream&str
argument_list|,
argument|ValueObject&object
argument_list|)
name|override
block|;
name|bool
name|GetObjectDescription
argument_list|(
argument|Stream&str
argument_list|,
argument|Value&value
argument_list|,
argument|ExecutionContextScope *exe_scope
argument_list|)
name|override
block|;
name|protected
operator|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from CPPLanguageRuntime can see and modify these
comment|//------------------------------------------------------------------
name|CPPLanguageRuntime
argument_list|(
name|Process
operator|*
name|process
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|CPPLanguageRuntime
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_CPPLanguageRuntime_h_
end_comment

end_unit

