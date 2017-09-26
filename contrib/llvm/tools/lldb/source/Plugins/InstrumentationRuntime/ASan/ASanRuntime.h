begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AddressSanitizerRuntime.h -------------------------------*- C++ -*-===//
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
name|liblldb_AddressSanitizerRuntime_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_AddressSanitizerRuntime_h_
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
file|"lldb/Target/InstrumentationRuntime.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StructuredData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|AddressSanitizerRuntime
range|:
name|public
name|lldb_private
operator|::
name|InstrumentationRuntime
block|{
name|public
operator|:
operator|~
name|AddressSanitizerRuntime
argument_list|()
name|override
block|;
specifier|static
name|lldb
operator|::
name|InstrumentationRuntimeSP
name|CreateInstance
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|)
block|;
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
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
specifier|static
name|lldb
operator|::
name|InstrumentationRuntimeType
name|GetTypeStatic
argument_list|()
block|;
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|{
return|return
name|GetPluginNameStatic
argument_list|()
return|;
block|}
name|virtual
name|lldb
operator|::
name|InstrumentationRuntimeType
name|GetType
argument_list|()
block|{
return|return
name|GetTypeStatic
argument_list|()
return|;
block|}
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|{
return|return
literal|1
return|;
block|}
name|private
operator|:
name|AddressSanitizerRuntime
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|)
operator|:
name|lldb_private
operator|::
name|InstrumentationRuntime
argument_list|(
argument|process_sp
argument_list|)
block|{}
specifier|const
name|RegularExpression
operator|&
name|GetPatternForRuntimeLibrary
argument_list|()
name|override
block|;
name|bool
name|CheckIfRuntimeIsValid
argument_list|(
argument|const lldb::ModuleSP module_sp
argument_list|)
name|override
block|;
name|void
name|Activate
argument_list|()
name|override
block|;
name|void
name|Deactivate
argument_list|()
block|;
specifier|static
name|bool
name|NotifyBreakpointHit
argument_list|(
argument|void *baton
argument_list|,
argument|StoppointCallbackContext *context
argument_list|,
argument|lldb::user_id_t break_id
argument_list|,
argument|lldb::user_id_t break_loc_id
argument_list|)
block|;
name|StructuredData
operator|::
name|ObjectSP
name|RetrieveReportData
argument_list|()
block|;
name|std
operator|::
name|string
name|FormatDescription
argument_list|(
argument|StructuredData::ObjectSP report
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
comment|// liblldb_AddressSanitizerRuntime_h_
end_comment

end_unit

