begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextMacOSXFrameBackchain.h -------------------*- C++ -*-===//
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
name|lldb_RegisterContextMacOSXFrameBackchain_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_RegisterContextMacOSXFrameBackchain_h_
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
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/RegisterContext.h"
end_include

begin_include
include|#
directive|include
file|"UnwindMacOSXFrameBackchain.h"
end_include

begin_decl_stmt
name|class
name|RegisterContextMacOSXFrameBackchain
range|:
name|public
name|lldb_private
operator|::
name|RegisterContext
block|{
name|public
operator|:
name|RegisterContextMacOSXFrameBackchain
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|,
argument|const UnwindMacOSXFrameBackchain::Cursor&cursor
argument_list|)
block|;
operator|~
name|RegisterContextMacOSXFrameBackchain
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
name|lldb_private
operator|::
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
name|lldb_private
operator|::
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
name|uint32_t
name|ConvertRegisterKindToRegisterNumber
argument_list|(
argument|lldb::RegisterKind kind
argument_list|,
argument|uint32_t num
argument_list|)
name|override
block|;
name|private
operator|:
name|UnwindMacOSXFrameBackchain
operator|::
name|Cursor
name|m_cursor
block|;
name|bool
name|m_cursor_is_valid
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|RegisterContextMacOSXFrameBackchain
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_RegisterContextMacOSXFrameBackchain_h_
end_comment

end_unit

