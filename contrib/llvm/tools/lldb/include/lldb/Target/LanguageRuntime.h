begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LanguageRuntime.h ---------------------------------------------------*-
end_comment

begin_comment
comment|// C++ -*-===//
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
file|"lldb/Core/Value.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ValueObject.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/LLVMUserExpression.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContextScope.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TargetOptions.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ExceptionSearchFilter
range|:
name|public
name|SearchFilter
block|{
name|public
operator|:
name|ExceptionSearchFilter
argument_list|(
argument|const lldb::TargetSP&target_sp
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|bool update_module_list = true
argument_list|)
block|;
operator|~
name|ExceptionSearchFilter
argument_list|()
name|override
operator|=
expr|default
block|;
name|bool
name|ModulePasses
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|)
name|override
block|;
name|bool
name|ModulePasses
argument_list|(
argument|const FileSpec&spec
argument_list|)
name|override
block|;
name|void
name|Search
argument_list|(
argument|Searcher&searcher
argument_list|)
name|override
block|;
name|void
name|GetDescription
argument_list|(
argument|Stream *s
argument_list|)
name|override
block|;
specifier|static
name|SearchFilter
operator|*
name|CreateFromStructuredData
argument_list|(
name|Target
operator|&
name|target
argument_list|,
specifier|const
name|StructuredData
operator|::
name|Dictionary
operator|&
name|data_dict
argument_list|,
name|Status
operator|&
name|error
argument_list|)
block|;
name|StructuredData
operator|::
name|ObjectSP
name|SerializeToStructuredData
argument_list|()
name|override
block|;
name|protected
operator|:
name|lldb
operator|::
name|LanguageType
name|m_language
block|;
name|LanguageRuntime
operator|*
name|m_language_runtime
block|;
name|lldb
operator|::
name|SearchFilterSP
name|m_filter_sp
block|;
name|lldb
operator|::
name|SearchFilterSP
name|DoCopyForBreakpoint
argument_list|(
argument|Breakpoint&breakpoint
argument_list|)
name|override
block|;
name|void
name|UpdateModuleListIfNeeded
argument_list|()
block|; }
decl_stmt|;
name|class
name|LanguageRuntime
range|:
name|public
name|PluginInterface
block|{
name|public
operator|:
operator|~
name|LanguageRuntime
argument_list|()
name|override
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
specifier|static
name|void
name|InitializeCommands
argument_list|(
name|CommandObject
operator|*
name|parent
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
argument_list|,
argument|Value::ValueType&value_type
argument_list|)
operator|=
literal|0
block|;
comment|// This call should return a CompilerType given a generic type name
comment|// and an ExecutionContextScope in which one can actually fetch
comment|// any specialization information required.
name|virtual
name|CompilerType
name|GetConcreteType
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|ConstString abstract_type_name
argument_list|)
block|{
return|return
name|CompilerType
argument_list|()
return|;
block|}
comment|// This should be a fast test to determine whether it is likely that this
comment|// value would
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
comment|// The contract for GetDynamicTypeAndAddress() is to return a "bare-bones"
comment|// dynamic type
comment|// For instance, given a Base* pointer, GetDynamicTypeAndAddress() will return
comment|// the type of
comment|// Derived, not Derived*. The job of this API is to correct this misalignment
comment|// between the
comment|// static type and the discovered dynamic type
name|virtual
name|TypeAndOrName
name|FixUpDynamicType
argument_list|(
specifier|const
name|TypeAndOrName
operator|&
name|type_and_or_name
argument_list|,
name|ValueObject
operator|&
name|static_value
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|SetExceptionBreakpoints
argument_list|()
block|{}
name|virtual
name|void
name|ClearExceptionBreakpoints
argument_list|()
block|{}
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
name|Breakpoint
operator|::
name|BreakpointPreconditionSP
name|CreateExceptionPrecondition
argument_list|(
argument|lldb::LanguageType language
argument_list|,
argument|bool catch_bp
argument_list|,
argument|bool throw_bp
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
name|Target
operator|&
name|GetTargetRef
argument_list|()
block|{
return|return
name|m_process
operator|->
name|GetTarget
argument_list|()
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
name|virtual
name|bool
name|GetTypeBitSize
argument_list|(
argument|const CompilerType&compiler_type
argument_list|,
argument|uint64_t&size
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|IsRuntimeSupportValue
argument_list|(
argument|ValueObject&valobj
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|void
name|ModulesDidLoad
argument_list|(
argument|const ModuleList&module_list
argument_list|)
block|{}
comment|// Called by the Clang expression evaluation engine to allow runtimes to alter
comment|// the set of target options provided to
comment|// the compiler.
comment|// If the options prototype is modified, runtimes must return true, false
comment|// otherwise.
name|virtual
name|bool
name|GetOverrideExprOptions
argument_list|(
argument|clang::TargetOptions&prototype
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|// Called by ClangExpressionParser::PrepareForExecution to query for any
comment|// custom LLVM IR passes
comment|// that need to be run before an expression is assembled and run.
name|virtual
name|bool
name|GetIRPasses
argument_list|(
argument|LLVMUserExpression::IRPasses&custom_passes
argument_list|)
block|{
return|return
name|false
return|;
block|}
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

