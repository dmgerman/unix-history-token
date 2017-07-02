begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- InstrumentationRuntime.h --------------------------------*- C++ -*-===//
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
name|liblldb_InstrumentationRuntime_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_InstrumentationRuntime_h_
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
file|<map>
end_include

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
file|"lldb/Utility/StructuredData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|InstrumentationRuntimeType
operator|,
name|lldb
operator|::
name|InstrumentationRuntimeSP
operator|>
name|InstrumentationRuntimeCollection
expr_stmt|;
name|class
name|InstrumentationRuntime
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|InstrumentationRuntime
operator|>
decl_stmt|,
name|public
name|PluginInterface
block|{
comment|/// The instrumented process.
name|lldb
operator|::
name|ProcessWP
name|m_process_wp
expr_stmt|;
comment|/// The module containing the instrumentation runtime.
name|lldb
operator|::
name|ModuleSP
name|m_runtime_module
expr_stmt|;
comment|/// The breakpoint in the instrumentation runtime.
name|lldb
operator|::
name|user_id_t
name|m_breakpoint_id
expr_stmt|;
comment|/// Indicates whether or not breakpoints have been registered in the
comment|/// instrumentation runtime.
name|bool
name|m_is_active
decl_stmt|;
name|protected
label|:
name|InstrumentationRuntime
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|)
operator|:
name|m_process_wp
argument_list|()
operator|,
name|m_runtime_module
argument_list|()
operator|,
name|m_breakpoint_id
argument_list|(
literal|0
argument_list|)
operator|,
name|m_is_active
argument_list|(
argument|false
argument_list|)
block|{
if|if
condition|(
name|process_sp
condition|)
name|m_process_wp
operator|=
name|process_sp
expr_stmt|;
block|}
name|lldb
operator|::
name|ProcessSP
name|GetProcessSP
argument_list|()
block|{
return|return
name|m_process_wp
operator|.
name|lock
argument_list|()
return|;
block|}
name|lldb
operator|::
name|ModuleSP
name|GetRuntimeModuleSP
argument_list|()
block|{
return|return
name|m_runtime_module
return|;
block|}
name|void
name|SetRuntimeModuleSP
argument_list|(
name|lldb
operator|::
name|ModuleSP
name|module_sp
argument_list|)
block|{
name|m_runtime_module
operator|=
name|module_sp
expr_stmt|;
block|}
name|lldb
operator|::
name|user_id_t
name|GetBreakpointID
argument_list|()
specifier|const
block|{
return|return
name|m_breakpoint_id
return|;
block|}
name|void
name|SetBreakpointID
argument_list|(
name|lldb
operator|::
name|user_id_t
name|ID
argument_list|)
block|{
name|m_breakpoint_id
operator|=
name|ID
expr_stmt|;
block|}
name|void
name|SetActive
parameter_list|(
name|bool
name|IsActive
parameter_list|)
block|{
name|m_is_active
operator|=
name|IsActive
expr_stmt|;
block|}
comment|/// Return a regular expression which can be used to identify a valid version
comment|/// of the runtime library.
name|virtual
specifier|const
name|RegularExpression
modifier|&
name|GetPatternForRuntimeLibrary
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// Check whether \p module_sp corresponds to a valid runtime library.
name|virtual
name|bool
name|CheckIfRuntimeIsValid
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
name|module_sp
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// Register a breakpoint in the runtime library and perform any other
comment|/// necessary initialization. The runtime library
comment|/// is guaranteed to be loaded.
name|virtual
name|void
name|Activate
parameter_list|()
init|=
literal|0
function_decl|;
name|public
label|:
specifier|static
name|void
name|ModulesDidLoad
argument_list|(
name|lldb_private
operator|::
name|ModuleList
operator|&
name|module_list
argument_list|,
name|Process
operator|*
name|process
argument_list|,
name|InstrumentationRuntimeCollection
operator|&
name|runtimes
argument_list|)
decl_stmt|;
comment|/// Look for the instrumentation runtime in \p module_list. Register and
comment|/// activate the runtime if this hasn't already
comment|/// been done.
name|void
name|ModulesDidLoad
argument_list|(
name|lldb_private
operator|::
name|ModuleList
operator|&
name|module_list
argument_list|)
decl_stmt|;
name|bool
name|IsActive
argument_list|()
specifier|const
block|{
return|return
name|m_is_active
return|;
block|}
name|virtual
name|lldb
operator|::
name|ThreadCollectionSP
name|GetBacktracesFromExtendedStopInfo
argument_list|(
argument|StructuredData::ObjectSP info
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
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
comment|// liblldb_InstrumentationRuntime_h_
end_comment

end_unit

