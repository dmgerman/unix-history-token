begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AppleObjCRuntime.h --------------------------------------*- C++ -*-===//
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
name|liblldb_AppleObjCRuntime_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_AppleObjCRuntime_h_
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

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

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
file|"lldb/Target/LanguageRuntime.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ObjCLanguageRuntime.h"
end_include

begin_include
include|#
directive|include
file|"AppleObjCTrampolineHandler.h"
end_include

begin_include
include|#
directive|include
file|"AppleThreadPlanStepThroughObjCTrampoline.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|AppleObjCRuntime
range|:
name|public
name|lldb_private
operator|::
name|ObjCLanguageRuntime
block|{
name|public
operator|:
operator|~
name|AppleObjCRuntime
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Static Functions
comment|//------------------------------------------------------------------
comment|// Note there is no CreateInstance, Initialize& Terminate functions here, because
comment|// you can't make an instance of this generic runtime.
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCLanguageRuntime* runtime
argument_list|)
block|{
switch|switch
condition|(
name|runtime
operator|->
name|GetRuntimeVersion
argument_list|()
condition|)
block|{
case|case
name|ObjCRuntimeVersions
operator|::
name|eAppleObjC_V1
case|:
case|case
name|ObjCRuntimeVersions
operator|::
name|eAppleObjC_V2
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
comment|// These are generic runtime functions:
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
name|CouldHaveDynamicValue
argument_list|(
argument|ValueObject&in_value
argument_list|)
name|override
block|;
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
name|TypeAndOrName
name|FixUpDynamicType
argument_list|(
argument|const TypeAndOrName& type_and_or_name
argument_list|,
argument|ValueObject& static_value
argument_list|)
name|override
block|;
comment|// These are the ObjC specific functions.
name|bool
name|IsModuleObjCLibrary
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|)
name|override
block|;
name|bool
name|ReadObjCLibrary
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|)
name|override
block|;
name|bool
name|HasReadObjCLibrary
argument_list|()
name|override
block|{
return|return
name|m_read_objc_library
return|;
block|}
name|lldb
operator|::
name|ThreadPlanSP
name|GetStepThroughTrampolinePlan
argument_list|(
argument|Thread&thread
argument_list|,
argument|bool stop_others
argument_list|)
name|override
block|;
comment|// Get the "libobjc.A.dylib" module from the current target if we can find
comment|// it, also cache it once it is found to ensure quick lookups.
name|lldb
operator|::
name|ModuleSP
name|GetObjCModule
argument_list|()
block|;
comment|// Sync up with the target
name|void
name|ModulesDidLoad
argument_list|(
argument|const ModuleList&module_list
argument_list|)
name|override
block|;
name|void
name|SetExceptionBreakpoints
argument_list|()
name|override
block|;
name|void
name|ClearExceptionBreakpoints
argument_list|()
name|override
block|;
name|bool
name|ExceptionBreakpointsAreSet
argument_list|()
name|override
block|;
name|bool
name|ExceptionBreakpointsExplainStop
argument_list|(
argument|lldb::StopInfoSP stop_reason
argument_list|)
name|override
block|;
name|lldb
operator|::
name|SearchFilterSP
name|CreateExceptionSearchFilter
argument_list|()
name|override
block|;
name|uint32_t
name|GetFoundationVersion
argument_list|()
block|;
name|protected
operator|:
comment|// Call CreateInstance instead.
name|AppleObjCRuntime
argument_list|(
name|Process
operator|*
name|process
argument_list|)
block|;
name|bool
name|CalculateHasNewLiteralsAndIndexing
argument_list|()
name|override
block|;
specifier|static
name|bool
name|AppleIsModuleObjCLibrary
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
block|;
specifier|static
name|ObjCRuntimeVersions
name|GetObjCVersion
argument_list|(
name|Process
operator|*
name|process
argument_list|,
name|lldb
operator|::
name|ModuleSP
operator|&
name|objc_module_sp
argument_list|)
block|;
name|void
name|ReadObjCLibraryIfNeeded
argument_list|(
specifier|const
name|ModuleList
operator|&
name|module_list
argument_list|)
block|;
name|Address
operator|*
name|GetPrintForDebuggerAddr
argument_list|()
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|Address
operator|>
name|m_PrintForDebugger_addr
block|;
name|bool
name|m_read_objc_library
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|AppleObjCTrampolineHandler
operator|>
name|m_objc_trampoline_handler_ap
block|;
name|lldb
operator|::
name|BreakpointSP
name|m_objc_exception_bp_sp
block|;
name|lldb
operator|::
name|ModuleWP
name|m_objc_module_wp
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|FunctionCaller
operator|>
name|m_print_object_caller_up
block|;
name|llvm
operator|::
name|Optional
operator|<
name|uint32_t
operator|>
name|m_Foundation_major
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
comment|// liblldb_AppleObjCRuntime_h_
end_comment

end_unit

