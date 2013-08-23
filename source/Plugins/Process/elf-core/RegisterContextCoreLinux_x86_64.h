begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextCoreLinux_x86_64.h ----------------------*- C++ -*-===//
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
comment|//===---------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_RegisterContextCoreLinux_x86_64_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextCoreLinux_x86_64_H_
end_define

begin_include
include|#
directive|include
file|"Plugins/Process/POSIX/RegisterContextLinux_x86_64.h"
end_include

begin_decl_stmt
name|using
name|namespace
name|lldb_private
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|RegisterContextCoreLinux_x86_64
range|:
name|public
name|RegisterContextLinux_x86_64
block|{
name|public
operator|:
name|RegisterContextCoreLinux_x86_64
argument_list|(
name|Thread
operator|&
name|thread
argument_list|,
specifier|const
name|DataExtractor
operator|&
name|gpregset
argument_list|,
specifier|const
name|DataExtractor
operator|&
name|fpregset
argument_list|)
block|;
operator|~
name|RegisterContextCoreLinux_x86_64
argument_list|()
block|;
name|virtual
name|bool
name|ReadRegister
argument_list|(
specifier|const
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
name|RegisterValue
operator|&
name|value
argument_list|)
block|;
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
name|WriteRegister
argument_list|(
specifier|const
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
specifier|const
name|RegisterValue
operator|&
name|value
argument_list|)
block|;
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
name|bool
name|HardwareSingleStep
argument_list|(
argument|bool enable
argument_list|)
block|;
name|bool
name|UpdateAfterBreakpoint
argument_list|()
block|;
name|protected
operator|:
name|bool
name|ReadFPR
argument_list|()
block|{
name|assert
argument_list|(
literal|0
argument_list|)
block|;     }
name|private
operator|:
name|uint8_t
operator|*
name|m_gpregset
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_RegisterContextCoreLinux_x86_64_H_
end_comment

end_unit

