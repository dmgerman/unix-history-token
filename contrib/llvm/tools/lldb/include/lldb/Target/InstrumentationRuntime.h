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
file|<vector>
end_include

begin_include
include|#
directive|include
file|<map>
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
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
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
name|virtual
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
name|virtual
name|bool
name|IsActive
parameter_list|()
function_decl|;
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

