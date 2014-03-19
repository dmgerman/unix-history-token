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
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/DataExtractor.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/RegisterContext.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/Utility/DynamicRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"GDBRemoteCommunicationClient.h"
end_include

begin_decl_stmt
name|class
name|ThreadGDBRemote
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ProcessGDBRemote
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|StringExtractor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
block|{     }
operator|~
name|GDBRemoteDynamicRegisterInfo
argument_list|()
block|{     }
name|void
name|HardcodeARMRegisters
argument_list|(
argument|bool from_scratch
argument_list|)
block|;  }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|GDBRemoteRegisterContext
range|:
name|public
name|lldb_private
operator|::
name|RegisterContext
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
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
name|virtual
operator|~
name|GDBRemoteRegisterContext
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// Subclasses must override these functions
comment|//------------------------------------------------------------------
name|virtual
name|void
name|InvalidateAllRegisters
argument_list|()
block|;
name|virtual
name|size_t
name|GetRegisterCount
argument_list|()
block|;
name|virtual
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfoAtIndex
argument_list|(
argument|size_t reg
argument_list|)
block|;
name|virtual
name|size_t
name|GetRegisterSetCount
argument_list|()
block|;
name|virtual
specifier|const
name|lldb_private
operator|::
name|RegisterSet
operator|*
name|GetRegisterSet
argument_list|(
argument|size_t reg_set
argument_list|)
block|;
name|virtual
name|bool
name|ReadRegister
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
name|lldb_private
operator|::
name|RegisterValue
operator|&
name|value
argument_list|)
block|;
name|virtual
name|bool
name|WriteRegister
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
specifier|const
name|lldb_private
operator|::
name|RegisterValue
operator|&
name|value
argument_list|)
block|;
name|virtual
name|bool
name|ReadAllRegisterValues
argument_list|(
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_sp
argument_list|)
block|;
name|virtual
name|bool
name|WriteAllRegisterValues
argument_list|(
specifier|const
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_sp
argument_list|)
block|;
name|virtual
name|uint32_t
name|ConvertRegisterKindToRegisterNumber
argument_list|(
argument|uint32_t kind
argument_list|,
argument|uint32_t num
argument_list|)
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
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|)
block|;
name|bool
name|WriteRegisterBytes
argument_list|(
argument|const lldb_private::RegisterInfo *reg_info
argument_list|,
argument|lldb_private::DataExtractor&data
argument_list|,
argument|uint32_t data_offset
argument_list|)
block|;
name|bool
name|PrivateSetRegisterValue
argument_list|(
argument|uint32_t reg
argument_list|,
argument|StringExtractor&response
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
end_decl_stmt

begin_decl_stmt
name|void
name|SetRegisterIsValid
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
name|bool
name|valid
argument_list|)
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
end_decl_stmt

begin_function
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
end_function

begin_decl_stmt
name|void
name|SyncThreadState
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Assumes the sequence mutex has already been acquired.
end_comment

begin_decl_stmt
name|GDBRemoteDynamicRegisterInfo
modifier|&
name|m_reg_info
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|bool
operator|>
name|m_reg_valid
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|DataExtractor
name|m_reg_data
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|m_read_all_at_once
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// Helper function for ReadRegisterBytes().
end_comment

begin_decl_stmt
name|bool
name|GetPrimordialRegister
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
name|GDBRemoteCommunicationClient
operator|&
name|gdb_comm
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Helper function for WriteRegisterBytes().
end_comment

begin_decl_stmt
name|bool
name|SetPrimordialRegister
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
name|GDBRemoteCommunicationClient
operator|&
name|gdb_comm
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// For GDBRemoteRegisterContext only
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|GDBRemoteRegisterContext
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_GDBRemoteRegisterContext_h_
end_comment

end_unit

