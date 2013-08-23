begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContext_i386.h ------------------------------*- C++ -*-===//
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
name|liblldb_RegisterContext_i386_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContext_i386_h_
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
file|"lldb/Core/Log.h"
end_include

begin_include
include|#
directive|include
file|"RegisterContextPOSIX.h"
end_include

begin_decl_stmt
name|class
name|RegisterContext_i386
range|:
name|public
name|RegisterContextPOSIX
block|{
name|public
operator|:
name|RegisterContext_i386
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|uint32_t concreate_frame_idx
argument_list|)
block|;
operator|~
name|RegisterContext_i386
argument_list|()
block|;
name|void
name|Invalidate
argument_list|()
block|;
name|void
name|InvalidateAllRegisters
argument_list|()
block|;
name|size_t
name|GetRegisterCount
argument_list|()
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
block|;
name|size_t
name|GetRegisterSetCount
argument_list|()
block|;
specifier|const
name|lldb_private
operator|::
name|RegisterSet
operator|*
name|GetRegisterSet
argument_list|(
argument|size_t set
argument_list|)
block|;
name|unsigned
name|GetRegisterIndexFromOffset
argument_list|(
argument|unsigned offset
argument_list|)
block|;
specifier|const
name|char
operator|*
name|GetRegisterName
argument_list|(
argument|unsigned reg
argument_list|)
block|;
name|bool
name|ReadRegisterValue
argument_list|(
argument|uint32_t reg
argument_list|,
argument|lldb_private::Scalar&value
argument_list|)
block|;
name|bool
name|ReadRegisterBytes
argument_list|(
argument|uint32_t reg
argument_list|,
argument|lldb_private::DataExtractor&data
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
name|bool
name|WriteRegisterValue
argument_list|(
argument|uint32_t reg
argument_list|,
argument|const lldb_private::Scalar&value
argument_list|)
block|;
name|bool
name|WriteRegisterBytes
argument_list|(
argument|uint32_t reg
argument_list|,
argument|lldb_private::DataExtractor&data
argument_list|,
argument|uint32_t data_offset =
literal|0
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
name|uint32_t
name|ConvertRegisterKindToRegisterNumber
argument_list|(
argument|uint32_t kind
argument_list|,
argument|uint32_t num
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
block|;      struct
name|GPR
block|{
name|uint32_t
name|ebx
block|;
name|uint32_t
name|ecx
block|;
name|uint32_t
name|edx
block|;
name|uint32_t
name|esi
block|;
name|uint32_t
name|edi
block|;
name|uint32_t
name|ebp
block|;
name|uint32_t
name|eax
block|;
name|uint32_t
name|ds
block|;
name|uint32_t
name|es
block|;
name|uint32_t
name|fs
block|;
name|uint32_t
name|gs
block|;
name|uint32_t
name|orig_ax
block|;
name|uint32_t
name|eip
block|;
name|uint32_t
name|cs
block|;
name|uint32_t
name|eflags
block|;
name|uint32_t
name|esp
block|;
name|uint32_t
name|ss
block|;     }
block|;      struct
name|MMSReg
block|{
name|uint8_t
name|bytes
index|[
literal|8
index|]
block|;     }
block|;      struct
name|XMMReg
block|{
name|uint8_t
name|bytes
index|[
literal|16
index|]
block|;     }
block|;      struct
name|FPU
block|{
name|uint16_t
name|fcw
block|;
name|uint16_t
name|fsw
block|;
name|uint16_t
name|ftw
block|;
name|uint16_t
name|fop
block|;
name|uint32_t
name|ip
block|;
name|uint32_t
name|cs
block|;
name|uint32_t
name|foo
block|;
name|uint32_t
name|fos
block|;
name|uint32_t
name|mxcsr
block|;
name|uint32_t
name|reserved
block|;
name|MMSReg
name|stmm
index|[
literal|8
index|]
block|;
name|XMMReg
name|xmm
index|[
literal|8
index|]
block|;
name|uint32_t
name|pad
index|[
literal|56
index|]
block|;     }
block|;
comment|// A user area like this no longer exists on FreeBSD
comment|// making this a Linux artifact. Nonetheless, it is safe
comment|// leaving it here while the code is being cleaned up and generalized.
block|struct
name|UserArea
block|{
name|GPR
name|regs
block|;
comment|// General purpose registers.
name|int32_t
name|fpvalid
block|;
comment|// True if FPU is being used.
name|FPU
name|i387
block|;
comment|// FPU registers.
name|uint32_t
name|tsize
block|;
comment|// Text segment size.
name|uint32_t
name|dsize
block|;
comment|// Data segment size.
name|uint32_t
name|ssize
block|;
comment|// Stack segment size.
name|uint32_t
name|start_code
block|;
comment|// VM address of text.
name|uint32_t
name|start_stack
block|;
comment|// VM address of stack bottom (top in rsp).
name|int32_t
name|signal
block|;
comment|// Signal causing core dump.
name|int32_t
name|reserved
block|;
comment|// Unused.
name|uint32_t
name|ar0
block|;
comment|// Location of GPR's.
name|FPU
operator|*
name|fpstate
block|;
comment|// Location of FPR's.
name|uint32_t
name|magic
block|;
comment|// Identifier for core dumps.
name|char
name|u_comm
index|[
literal|32
index|]
block|;
comment|// Command causing core dump.
name|uint32_t
name|u_debugreg
index|[
literal|8
index|]
block|;
comment|// Debug registers (DR0 - DR7).
block|}
block|;
name|private
operator|:
name|UserArea
name|user
block|;
name|ProcessMonitor
operator|&
name|GetMonitor
argument_list|()
block|;
name|void
name|LogGPR
argument_list|(
specifier|const
name|char
operator|*
name|title
argument_list|)
block|;
name|bool
name|ReadGPR
argument_list|()
block|;
name|bool
name|ReadFPR
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_RegisterContext_i386_h_
end_comment

end_unit

