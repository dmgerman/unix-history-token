begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ItaniumABILanguageRuntime.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_ItaniumABILanguageRuntime_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ItaniumABILanguageRuntime_h_
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
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Breakpoint/BreakpointResolver.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/LanguageRuntime.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/CPPLanguageRuntime.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Value.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ItaniumABILanguageRuntime
range|:
name|public
name|lldb_private
operator|::
name|CPPLanguageRuntime
block|{
name|public
operator|:
operator|~
name|ItaniumABILanguageRuntime
argument_list|()
block|{ }
name|virtual
name|bool
name|IsVTableName
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
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
block|;
name|virtual
name|bool
name|CouldHaveDynamicValue
argument_list|(
name|ValueObject
operator|&
name|in_value
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Static Functions
comment|//------------------------------------------------------------------
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|LanguageRuntime
operator|*
name|CreateInstance
argument_list|(
argument|Process *process
argument_list|,
argument|lldb::LanguageType language
argument_list|)
block|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
block|;
name|virtual
name|uint32_t
name|GetPluginVersion
argument_list|()
block|;
name|virtual
name|void
name|SetExceptionBreakpoints
argument_list|()
block|;
name|virtual
name|void
name|ClearExceptionBreakpoints
argument_list|()
block|;
name|virtual
name|bool
name|ExceptionBreakpointsAreSet
argument_list|()
block|;
name|virtual
name|bool
name|ExceptionBreakpointsExplainStop
argument_list|(
argument|lldb::StopInfoSP stop_reason
argument_list|)
block|;
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
argument_list|,
argument|bool for_expressions
argument_list|)
block|;
name|lldb
operator|::
name|BreakpointSP
name|CreateExceptionBreakpoint
argument_list|(
argument|bool catch_bp
argument_list|,
argument|bool throw_bp
argument_list|,
argument|bool for_expressions
argument_list|,
argument|bool is_internal
argument_list|)
block|;
name|private
operator|:
name|ItaniumABILanguageRuntime
argument_list|(
name|Process
operator|*
name|process
argument_list|)
operator|:
name|lldb_private
operator|::
name|CPPLanguageRuntime
argument_list|(
argument|process
argument_list|)
block|{ }
comment|// Call CreateInstance instead.
name|lldb
operator|::
name|BreakpointSP
name|m_cxx_exception_bp_sp
block|;     }
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
comment|// liblldb_ItaniumABILanguageRuntime_h_
end_comment

end_unit

