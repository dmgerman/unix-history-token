begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextPOSIXCore_powerpc.h ----------------------*- C++ -*-===//
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
name|liblldb_RegisterContextCorePOSIX_powerpc_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextCorePOSIX_powerpc_h_
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
file|"Plugins/Process/Utility/RegisterContextPOSIX_powerpc.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/DataExtractor.h"
end_include

begin_decl_stmt
name|class
name|RegisterContextCorePOSIX_powerpc
range|:
name|public
name|RegisterContextPOSIX_powerpc
block|{
name|public
operator|:
name|RegisterContextCorePOSIX_powerpc
argument_list|(
name|lldb_private
operator|::
name|Thread
operator|&
name|thread
argument_list|,
name|lldb_private
operator|::
name|RegisterInfoInterface
operator|*
name|register_info
argument_list|,
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|gpregset
argument_list|,
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|fpregset
argument_list|,
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|vregset
argument_list|)
block|;
operator|~
name|RegisterContextCorePOSIX_powerpc
argument_list|()
name|override
block|;
name|bool
name|ReadRegister
argument_list|(
argument|const lldb_private::RegisterInfo *reg_info
argument_list|,
argument|lldb_private::RegisterValue&value
argument_list|)
name|override
block|;
name|bool
name|WriteRegister
argument_list|(
argument|const lldb_private::RegisterInfo *reg_info
argument_list|,
argument|const lldb_private::RegisterValue&value
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
name|HardwareSingleStep
argument_list|(
argument|bool enable
argument_list|)
name|override
block|;
name|protected
operator|:
name|bool
name|ReadGPR
argument_list|()
name|override
block|;
name|bool
name|ReadFPR
argument_list|()
name|override
block|;
name|bool
name|ReadVMX
argument_list|()
name|override
block|;
name|bool
name|WriteGPR
argument_list|()
name|override
block|;
name|bool
name|WriteFPR
argument_list|()
name|override
block|;
name|bool
name|WriteVMX
argument_list|()
name|override
block|;
name|private
operator|:
name|lldb
operator|::
name|DataBufferSP
name|m_gpr_buffer
block|;
name|lldb
operator|::
name|DataBufferSP
name|m_fpr_buffer
block|;
name|lldb
operator|::
name|DataBufferSP
name|m_vec_buffer
block|;
name|lldb_private
operator|::
name|DataExtractor
name|m_gpr
block|;
name|lldb_private
operator|::
name|DataExtractor
name|m_fpr
block|;
name|lldb_private
operator|::
name|DataExtractor
name|m_vec
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_RegisterContextCorePOSIX_powerpc_h_
end_comment

end_unit

