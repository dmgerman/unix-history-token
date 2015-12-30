begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GoLanguageRuntime.h -------------------------------------*- C++ -*-===//
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
name|liblldb_GoLanguageRuntime_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_GoLanguageRuntime_h_
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
file|"lldb/Core/Value.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|GoLanguageRuntime
range|:
name|public
name|lldb_private
operator|::
name|LanguageRuntime
block|{
name|public
operator|:
operator|~
name|GoLanguageRuntime
argument_list|()
name|override
operator|=
expr|default
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
name|eLanguageTypeGo
return|;
block|}
name|bool
name|GetObjectDescription
argument_list|(
argument|Stream&str
argument_list|,
argument|ValueObject&object
argument_list|)
name|override
block|{
comment|// TODO(ribrdb): Maybe call String() method?
return|return
name|false
return|;
block|}
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
block|{
return|return
name|false
return|;
block|}
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
argument_list|,
argument|Value::ValueType&value_type
argument_list|)
name|override
block|;
name|bool
name|CouldHaveDynamicValue
argument_list|(
argument|ValueObject&in_value
argument_list|)
name|override
block|;
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
name|override
block|{
return|return
name|lldb
operator|::
name|BreakpointResolverSP
argument_list|()
return|;
block|}
name|TypeAndOrName
name|FixUpDynamicType
argument_list|(
argument|const TypeAndOrName&type_and_or_name
argument_list|,
argument|ValueObject&static_value
argument_list|)
name|override
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|;
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|;
name|private
operator|:
name|GoLanguageRuntime
argument_list|(
name|Process
operator|*
name|process
argument_list|)
operator|:
name|lldb_private
operator|::
name|LanguageRuntime
argument_list|(
argument|process
argument_list|)
block|{ }
comment|// Call CreateInstance instead.
block|}
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
comment|// liblldb_GoLanguageRuntime_h_
end_comment

end_unit

