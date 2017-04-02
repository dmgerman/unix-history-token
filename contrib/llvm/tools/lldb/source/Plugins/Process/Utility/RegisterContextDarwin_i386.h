begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegisterContextDarwin_i386.h ----------------------------*- C++ -*-===//
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
name|liblldb_RegisterContextDarwin_i386_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegisterContextDarwin_i386_h_
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
file|"lldb/Target/RegisterContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|class
name|RegisterContextDarwin_i386
range|:
name|public
name|lldb_private
operator|::
name|RegisterContext
block|{
name|public
operator|:
name|RegisterContextDarwin_i386
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|uint32_t concrete_frame_idx
argument_list|)
block|;
operator|~
name|RegisterContextDarwin_i386
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
argument|size_t set
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
name|bool
name|HardwareSingleStep
argument_list|(
argument|bool enable
argument_list|)
name|override
block|;    struct
name|GPR
block|{
name|uint32_t
name|eax
block|;
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
name|edi
block|;
name|uint32_t
name|esi
block|;
name|uint32_t
name|ebp
block|;
name|uint32_t
name|esp
block|;
name|uint32_t
name|ss
block|;
name|uint32_t
name|eflags
block|;
name|uint32_t
name|eip
block|;
name|uint32_t
name|cs
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
block|;   }
block|;    struct
name|MMSReg
block|{
name|uint8_t
name|bytes
index|[
literal|10
index|]
block|;
name|uint8_t
name|pad
index|[
literal|6
index|]
block|;   }
block|;    struct
name|XMMReg
block|{
name|uint8_t
name|bytes
index|[
literal|16
index|]
block|;   }
block|;    struct
name|FPU
block|{
name|uint32_t
name|pad
index|[
literal|2
index|]
block|;
name|uint16_t
name|fcw
block|;
name|uint16_t
name|fsw
block|;
name|uint8_t
name|ftw
block|;
name|uint8_t
name|pad1
block|;
name|uint16_t
name|fop
block|;
name|uint32_t
name|ip
block|;
name|uint16_t
name|cs
block|;
name|uint16_t
name|pad2
block|;
name|uint32_t
name|dp
block|;
name|uint16_t
name|ds
block|;
name|uint16_t
name|pad3
block|;
name|uint32_t
name|mxcsr
block|;
name|uint32_t
name|mxcsrmask
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
name|uint8_t
name|pad4
index|[
literal|14
operator|*
literal|16
index|]
block|;
name|int
name|pad5
block|;   }
block|;    struct
name|EXC
block|{
name|uint32_t
name|trapno
block|;
name|uint32_t
name|err
block|;
name|uint32_t
name|faultvaddr
block|;   }
block|;
name|protected
operator|:
expr|enum
block|{
name|GPRRegSet
operator|=
literal|1
block|,
name|FPURegSet
operator|=
literal|2
block|,
name|EXCRegSet
operator|=
literal|3
block|}
block|;    enum
block|{
name|GPRWordCount
operator|=
sizeof|sizeof
argument_list|(
name|GPR
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
block|,
name|FPUWordCount
operator|=
sizeof|sizeof
argument_list|(
name|FPU
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
block|,
name|EXCWordCount
operator|=
sizeof|sizeof
argument_list|(
name|EXC
argument_list|)
operator|/
expr|sizeof
operator|(
name|uint32_t
operator|)
block|}
block|;    enum
block|{
name|Read
operator|=
literal|0
block|,
name|Write
operator|=
literal|1
block|,
name|kNumErrors
operator|=
literal|2
block|}
block|;
name|GPR
name|gpr
block|;
name|FPU
name|fpu
block|;
name|EXC
name|exc
block|;
name|int
name|gpr_errs
index|[
literal|2
index|]
block|;
comment|// Read/Write errors
name|int
name|fpu_errs
index|[
literal|2
index|]
block|;
comment|// Read/Write errors
name|int
name|exc_errs
index|[
literal|2
index|]
block|;
comment|// Read/Write errors
name|void
name|InvalidateAllRegisterStates
argument_list|()
block|{
name|SetError
argument_list|(
name|GPRRegSet
argument_list|,
name|Read
argument_list|,
operator|-
literal|1
argument_list|)
block|;
name|SetError
argument_list|(
name|FPURegSet
argument_list|,
name|Read
argument_list|,
operator|-
literal|1
argument_list|)
block|;
name|SetError
argument_list|(
name|EXCRegSet
argument_list|,
name|Read
argument_list|,
operator|-
literal|1
argument_list|)
block|;   }
name|int
name|GetError
argument_list|(
argument|int flavor
argument_list|,
argument|uint32_t err_idx
argument_list|)
specifier|const
block|{
if|if
condition|(
name|err_idx
operator|<
name|kNumErrors
condition|)
block|{
switch|switch
condition|(
name|flavor
condition|)
block|{
comment|// When getting all errors, just OR all values together to see if
comment|// we got any kind of error.
case|case
name|GPRRegSet
case|:
return|return
name|gpr_errs
index|[
name|err_idx
index|]
return|;
case|case
name|FPURegSet
case|:
return|return
name|fpu_errs
index|[
name|err_idx
index|]
return|;
case|case
name|EXCRegSet
case|:
return|return
name|exc_errs
index|[
name|err_idx
index|]
return|;
default|default:
break|break;
block|}
block|}
return|return
operator|-
literal|1
return|;
block|}
name|bool
name|SetError
argument_list|(
argument|int flavor
argument_list|,
argument|uint32_t err_idx
argument_list|,
argument|int err
argument_list|)
block|{
if|if
condition|(
name|err_idx
operator|<
name|kNumErrors
condition|)
block|{
switch|switch
condition|(
name|flavor
condition|)
block|{
case|case
name|GPRRegSet
case|:
name|gpr_errs
index|[
name|err_idx
index|]
operator|=
name|err
expr_stmt|;
return|return
name|true
return|;
case|case
name|FPURegSet
case|:
name|fpu_errs
index|[
name|err_idx
index|]
operator|=
name|err
expr_stmt|;
return|return
name|true
return|;
case|case
name|EXCRegSet
case|:
name|exc_errs
index|[
name|err_idx
index|]
operator|=
name|err
expr_stmt|;
return|return
name|true
return|;
default|default:
break|break;
block|}
block|}
return|return
name|false
return|;
block|}
name|bool
name|RegisterSetIsCached
argument_list|(
argument|int set
argument_list|)
specifier|const
block|{
return|return
name|GetError
argument_list|(
name|set
argument_list|,
name|Read
argument_list|)
operator|==
literal|0
return|;
block|}
name|void
name|LogGPR
argument_list|(
name|lldb_private
operator|::
name|Log
operator|*
name|log
argument_list|,
specifier|const
name|char
operator|*
name|title
argument_list|)
block|;
name|int
name|ReadGPR
argument_list|(
argument|bool force
argument_list|)
block|;
name|int
name|ReadFPU
argument_list|(
argument|bool force
argument_list|)
block|;
name|int
name|ReadEXC
argument_list|(
argument|bool force
argument_list|)
block|;
name|int
name|WriteGPR
argument_list|()
block|;
name|int
name|WriteFPU
argument_list|()
block|;
name|int
name|WriteEXC
argument_list|()
block|;
comment|// Subclasses override these to do the actual reading.
name|virtual
name|int
name|DoReadGPR
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|GPR&gpr
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|DoReadFPU
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|FPU&fpu
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|DoReadEXC
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|EXC&exc
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|DoWriteGPR
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|const GPR&gpr
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|DoWriteFPU
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|const FPU&fpu
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|int
name|DoWriteEXC
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|int flavor
argument_list|,
argument|const EXC&exc
argument_list|)
operator|=
literal|0
block|;
name|int
name|ReadRegisterSet
argument_list|(
argument|uint32_t set
argument_list|,
argument|bool force
argument_list|)
block|;
name|int
name|WriteRegisterSet
argument_list|(
argument|uint32_t set
argument_list|)
block|;
specifier|static
name|uint32_t
name|GetRegisterNumber
argument_list|(
argument|uint32_t reg_kind
argument_list|,
argument|uint32_t reg_num
argument_list|)
block|;
specifier|static
name|int
name|GetSetForNativeRegNum
argument_list|(
argument|int reg_num
argument_list|)
block|;
specifier|static
name|size_t
name|GetRegisterInfosCount
argument_list|()
block|;
specifier|static
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfos
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_RegisterContextDarwin_i386_h_
end_comment

end_unit

