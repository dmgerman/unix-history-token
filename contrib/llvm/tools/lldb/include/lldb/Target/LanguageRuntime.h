begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LanguageRuntime.h ---------------------------------------------------*- C++ -*-===//
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
name|liblldb_LanguageRuntime_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_LanguageRuntime_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Breakpoint/BreakpointResolver.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Breakpoint/BreakpointResolverName.h"
end_include

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
file|"lldb/Core/ValueObject.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Value.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContextScope.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|LanguageRuntime
range|:
name|public
name|PluginInterface
block|{
name|public
operator|:
name|virtual
operator|~
name|LanguageRuntime
argument_list|()
block|;
specifier|static
name|LanguageRuntime
operator|*
name|FindPlugin
argument_list|(
argument|Process *process
argument_list|,
argument|lldb::LanguageType language
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|LanguageType
name|GetLanguageType
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|GetObjectDescription
argument_list|(
name|Stream
operator|&
name|str
argument_list|,
name|ValueObject
operator|&
name|object
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|GetObjectDescription
argument_list|(
name|Stream
operator|&
name|str
argument_list|,
name|Value
operator|&
name|value
argument_list|,
name|ExecutionContextScope
operator|*
name|exe_scope
argument_list|)
operator|=
literal|0
block|;
comment|// this call should return true if it could set the name and/or the type
name|virtual
name|bool
name|GetDynamicTypeAndAddress
argument_list|(
argument|ValueObject&in_value
argument_list|,
argument|lldb::DynamicValueType use_dynamic
argument_list|,
argument|TypeAndOrName&class_type_or_name
argument_list|,
argument|Address&address
argument_list|)
operator|=
literal|0
block|;
comment|// This should be a fast test to determine whether it is likely that this value would
comment|// have a dynamic type.
name|virtual
name|bool
name|CouldHaveDynamicValue
argument_list|(
name|ValueObject
operator|&
name|in_value
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|SetExceptionBreakpoints
argument_list|()
block|{     }
name|virtual
name|void
name|ClearExceptionBreakpoints
argument_list|()
block|{     }
name|virtual
name|bool
name|ExceptionBreakpointsAreSet
argument_list|()
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|ExceptionBreakpointsExplainStop
argument_list|(
argument|lldb::StopInfoSP stop_reason
argument_list|)
block|{
return|return
name|false
return|;
block|}
specifier|static
name|lldb
operator|::
name|BreakpointSP
name|CreateExceptionBreakpoint
argument_list|(
argument|Target&target
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|bool catch_bp
argument_list|,
argument|bool throw_bp
argument_list|,
argument|bool is_internal = false
argument_list|)
block|;
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
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetNameForLanguageType
argument_list|(
argument|lldb::LanguageType language
argument_list|)
block|;
name|Process
operator|*
name|GetProcess
argument_list|()
block|{
return|return
name|m_process
return|;
block|}
name|virtual
name|lldb
operator|::
name|BreakpointResolverSP
name|CreateExceptionResolver
argument_list|(
argument|Breakpoint *bkpt
argument_list|,
argument|bool catch_bp
argument_list|,
argument|bool throw_bp
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|SearchFilterSP
name|CreateExceptionSearchFilter
argument_list|()
block|;
name|protected
operator|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from LanguageRuntime can see and modify these
comment|//------------------------------------------------------------------
name|LanguageRuntime
argument_list|(
name|Process
operator|*
name|process
argument_list|)
block|;
name|Process
operator|*
name|m_process
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|LanguageRuntime
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
comment|// liblldb_LanguageRuntime_h_
end_comment

end_unit

