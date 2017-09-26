begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- InstrumentationRuntimeStopInfo.h ------------------------*- C++ -*-===//
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
name|liblldb_InstrumentationRuntimeStopInfo_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_InstrumentationRuntimeStopInfo_h_
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
file|<string>
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
file|"lldb/Target/StopInfo.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StructuredData.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|InstrumentationRuntimeStopInfo
range|:
name|public
name|StopInfo
block|{
name|public
operator|:
operator|~
name|InstrumentationRuntimeStopInfo
argument_list|()
name|override
block|{}
name|lldb
operator|::
name|StopReason
name|GetStopReason
argument_list|()
specifier|const
name|override
block|{
return|return
name|lldb
operator|::
name|eStopReasonInstrumentation
return|;
block|}
specifier|const
name|char
operator|*
name|GetDescription
argument_list|()
name|override
block|;
name|bool
name|DoShouldNotify
argument_list|(
argument|Event *event_ptr
argument_list|)
name|override
block|{
return|return
name|true
return|;
block|}
specifier|static
name|lldb
operator|::
name|StopInfoSP
name|CreateStopReasonWithInstrumentationData
argument_list|(
argument|Thread&thread
argument_list|,
argument|std::string description
argument_list|,
argument|StructuredData::ObjectSP additional_data
argument_list|)
block|;
name|private
operator|:
name|InstrumentationRuntimeStopInfo
argument_list|(
argument|Thread&thread
argument_list|,
argument|std::string description
argument_list|,
argument|StructuredData::ObjectSP additional_data
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
comment|// liblldb_InstrumentationRuntimeStopInfo_h_
end_comment

end_unit

