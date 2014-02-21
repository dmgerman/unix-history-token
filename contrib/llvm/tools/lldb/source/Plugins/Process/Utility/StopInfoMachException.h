begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StopInfoMachException.h ---------------------------------*- C++ -*-===//
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
name|liblldb_StopInfoMachException_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_StopInfoMachException_h_
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

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|StopInfoMachException
range|:
name|public
name|StopInfo
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|StopInfoMachException
argument_list|(
argument|Thread&thread
argument_list|,
argument|uint32_t exc_type
argument_list|,
argument|uint32_t exc_data_count
argument_list|,
argument|uint64_t exc_code
argument_list|,
argument|uint64_t exc_subcode
argument_list|)
operator|:
name|StopInfo
argument_list|(
name|thread
argument_list|,
name|exc_type
argument_list|)
block|,
name|m_exc_data_count
argument_list|(
name|exc_data_count
argument_list|)
block|,
name|m_exc_code
argument_list|(
name|exc_code
argument_list|)
block|,
name|m_exc_subcode
argument_list|(
argument|exc_subcode
argument_list|)
block|{     }
name|virtual
operator|~
name|StopInfoMachException
argument_list|()
block|{     }
name|virtual
name|lldb
operator|::
name|StopReason
name|GetStopReason
argument_list|()
specifier|const
block|{
return|return
name|lldb
operator|::
name|eStopReasonException
return|;
block|}
name|virtual
specifier|const
name|char
operator|*
name|GetDescription
argument_list|()
block|;
comment|// Since some mach exceptions will be reported as breakpoints, signals,
comment|// or trace, we use this static accessor which will translate the mach
comment|// exception into the correct StopInfo.
specifier|static
name|lldb
operator|::
name|StopInfoSP
name|CreateStopReasonWithMachException
argument_list|(
argument|Thread&thread
argument_list|,
argument|uint32_t exc_type
argument_list|,
argument|uint32_t exc_data_count
argument_list|,
argument|uint64_t exc_code
argument_list|,
argument|uint64_t exc_sub_code
argument_list|,
argument|uint64_t exc_sub_sub_code
argument_list|,
argument|bool pc_already_adjusted = true
argument_list|,
argument|bool adjust_pc_if_needed = false
argument_list|)
block|;
name|protected
operator|:
name|uint32_t
name|m_exc_data_count
block|;
name|uint64_t
name|m_exc_code
block|;
name|uint64_t
name|m_exc_subcode
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
comment|// liblldb_StopInfoMachException_h_
end_comment

end_unit

