begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GDBRemoteRegisterContext.h ------------------------------*- C++ -*-===//
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
name|lldb_GDBRemoteRegisterContext_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_GDBRemoteRegisterContext_h_
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

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"Plugins/Process/Utility/DynamicRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/RegisterContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/DataExtractor.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"GDBRemoteCommunicationClient.h"
end_include

begin_decl_stmt
name|class
name|StringExtractor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_gdb_remote
block|{
name|class
name|ThreadGDBRemote
decl_stmt|;
name|class
name|ProcessGDBRemote
decl_stmt|;
name|class
name|GDBRemoteDynamicRegisterInfo
range|:
name|public
name|DynamicRegisterInfo
block|{
name|public
operator|:
name|GDBRemoteDynamicRegisterInfo
argument_list|()
operator|:
name|DynamicRegisterInfo
argument_list|()
block|{}
operator|~
name|GDBRemoteDynamicRegisterInfo
argument_list|()
name|override
operator|=
expr|default
block|;
name|void
name|HardcodeARMRegisters
argument_list|(
argument|bool from_scratch
argument_list|)
block|; }
decl_stmt|;
name|class
name|GDBRemoteRegisterContext
range|:
name|public
name|RegisterContext
block|{
name|public
operator|:
name|GDBRemoteRegisterContext
argument_list|(
argument|ThreadGDBRemote&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|,
argument|GDBRemoteDynamicRegisterInfo&reg_info
argument_list|,
argument|bool read_all_at_once
argument_list|)
block|;
operator|~
name|GDBRemoteRegisterContext
argument_list|()
name|override
block|;
name|void
name|InvalidateAllRegisters
argument_list|()
name|override
block|;
name|size_t
name|GetRegisterCount
argument_list|()
name|override
block|;
specifier|const
name|RegisterInfo
operator|*
name|GetRegisterInfoAtIndex
argument_list|(
argument|size_t reg
argument_list|)
name|override
block|;
name|size_t
name|GetRegisterSetCount
argument_list|()
name|override
block|;
specifier|const
name|RegisterSet
operator|*
name|GetRegisterSet
argument_list|(
argument|size_t reg_set
argument_list|)
name|override
block|;
name|bool
name|ReadRegister
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|,
argument|RegisterValue&value
argument_list|)
name|override
block|;
name|bool
name|WriteRegister
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|,
argument|const RegisterValue&value
argument_list|)
name|override
block|;
name|bool
name|ReadAllRegisterValues
argument_list|(
argument|lldb::DataBufferSP&data_sp
argument_list|)
name|override
block|;
name|bool
name|WriteAllRegisterValues
argument_list|(
argument|const lldb::DataBufferSP&data_sp
argument_list|)
name|override
block|;
name|bool
name|ReadAllRegisterValues
argument_list|(
argument|RegisterCheckpoint&reg_checkpoint
argument_list|)
name|override
block|;
name|bool
name|WriteAllRegisterValues
argument_list|(
argument|const RegisterCheckpoint&reg_checkpoint
argument_list|)
name|override
block|;
name|uint32_t
name|ConvertRegisterKindToRegisterNumber
argument_list|(
argument|lldb::RegisterKind kind
argument_list|,
argument|uint32_t num
argument_list|)
name|override
block|;
name|protected
operator|:
name|friend
name|class
name|ThreadGDBRemote
block|;
name|bool
name|ReadRegisterBytes
argument_list|(
specifier|const
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
name|DataExtractor
operator|&
name|data
argument_list|)
block|;
name|bool
name|WriteRegisterBytes
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|,
argument|DataExtractor&data
argument_list|,
argument|uint32_t data_offset
argument_list|)
block|;
name|bool
name|PrivateSetRegisterValue
argument_list|(
argument|uint32_t reg
argument_list|,
argument|llvm::ArrayRef<uint8_t> data
argument_list|)
block|;
name|bool
name|PrivateSetRegisterValue
argument_list|(
argument|uint32_t reg
argument_list|,
argument|uint64_t val
argument_list|)
block|;
name|void
name|SetAllRegisterValid
argument_list|(
argument|bool b
argument_list|)
block|;
name|bool
name|GetRegisterIsValid
argument_list|(
argument|uint32_t reg
argument_list|)
specifier|const
block|{
if|#
directive|if
name|defined
argument_list|(
name|LLDB_CONFIGURATION_DEBUG
argument_list|)
name|assert
argument_list|(
name|reg
operator|<
name|m_reg_valid
operator|.
name|size
argument_list|()
argument_list|)
block|;
endif|#
directive|endif
if|if
condition|(
name|reg
operator|<
name|m_reg_valid
operator|.
name|size
argument_list|()
condition|)
return|return
name|m_reg_valid
index|[
name|reg
index|]
return|;
return|return
name|false
return|;
block|}
name|void
name|SetRegisterIsValid
parameter_list|(
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|,
name|bool
name|valid
parameter_list|)
block|{
if|if
condition|(
name|reg_info
condition|)
return|return
name|SetRegisterIsValid
argument_list|(
name|reg_info
operator|->
name|kinds
index|[
name|lldb
operator|::
name|eRegisterKindLLDB
index|]
argument_list|,
name|valid
argument_list|)
return|;
block|}
name|void
name|SetRegisterIsValid
parameter_list|(
name|uint32_t
name|reg
parameter_list|,
name|bool
name|valid
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|LLDB_CONFIGURATION_DEBUG
argument_list|)
name|assert
argument_list|(
name|reg
operator|<
name|m_reg_valid
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|reg
operator|<
name|m_reg_valid
operator|.
name|size
argument_list|()
condition|)
name|m_reg_valid
index|[
name|reg
index|]
operator|=
name|valid
expr_stmt|;
block|}
name|GDBRemoteDynamicRegisterInfo
modifier|&
name|m_reg_info
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|bool
operator|>
name|m_reg_valid
expr_stmt|;
name|DataExtractor
name|m_reg_data
decl_stmt|;
name|bool
name|m_read_all_at_once
decl_stmt|;
name|private
label|:
comment|// Helper function for ReadRegisterBytes().
name|bool
name|GetPrimordialRegister
parameter_list|(
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|,
name|GDBRemoteCommunicationClient
modifier|&
name|gdb_comm
parameter_list|)
function_decl|;
comment|// Helper function for WriteRegisterBytes().
name|bool
name|SetPrimordialRegister
parameter_list|(
specifier|const
name|RegisterInfo
modifier|*
name|reg_info
parameter_list|,
name|GDBRemoteCommunicationClient
modifier|&
name|gdb_comm
parameter_list|)
function_decl|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|GDBRemoteRegisterContext
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace process_gdb_remote
end_comment

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_GDBRemoteRegisterContext_h_
end_comment

end_unit

