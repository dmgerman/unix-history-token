begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== MSP430MachineFunctionInfo.h - MSP430 machine function info -*- C++ -*-==//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file declares MSP430-specific per-machine-function information.
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
name|LLVM_LIB_TARGET_MSP430_MSP430MACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MSP430_MSP430MACHINEFUNCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MSP430MachineFunctionInfo - This class is derived from MachineFunction and
comment|/// contains private MSP430 target-specific information for each MachineFunction.
name|class
name|MSP430MachineFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// CalleeSavedFrameSize - Size of the callee-saved register portion of the
comment|/// stack frame in bytes.
name|unsigned
name|CalleeSavedFrameSize
block|;
comment|/// ReturnAddrIndex - FrameIndex for return slot.
name|int
name|ReturnAddrIndex
block|;
comment|/// VarArgsFrameIndex - FrameIndex for start of varargs area.
name|int
name|VarArgsFrameIndex
block|;
comment|/// SRetReturnReg - Some subtargets require that sret lowering includes
comment|/// returning the value of the returned struct in a register. This field
comment|/// holds the virtual register into which the sret argument is passed.
name|unsigned
name|SRetReturnReg
block|;
name|public
operator|:
name|MSP430MachineFunctionInfo
argument_list|()
operator|:
name|CalleeSavedFrameSize
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|MSP430MachineFunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|:
name|CalleeSavedFrameSize
argument_list|(
literal|0
argument_list|)
block|,
name|ReturnAddrIndex
argument_list|(
literal|0
argument_list|)
block|,
name|SRetReturnReg
argument_list|(
literal|0
argument_list|)
block|{}
name|unsigned
name|getCalleeSavedFrameSize
argument_list|()
specifier|const
block|{
return|return
name|CalleeSavedFrameSize
return|;
block|}
name|void
name|setCalleeSavedFrameSize
argument_list|(
argument|unsigned bytes
argument_list|)
block|{
name|CalleeSavedFrameSize
operator|=
name|bytes
block|; }
name|unsigned
name|getSRetReturnReg
argument_list|()
specifier|const
block|{
return|return
name|SRetReturnReg
return|;
block|}
name|void
name|setSRetReturnReg
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|SRetReturnReg
operator|=
name|Reg
block|; }
name|int
name|getRAIndex
argument_list|()
specifier|const
block|{
return|return
name|ReturnAddrIndex
return|;
block|}
name|void
name|setRAIndex
argument_list|(
argument|int Index
argument_list|)
block|{
name|ReturnAddrIndex
operator|=
name|Index
block|; }
name|int
name|getVarArgsFrameIndex
argument_list|()
specifier|const
block|{
return|return
name|VarArgsFrameIndex
return|;
block|}
name|void
name|setVarArgsFrameIndex
argument_list|(
argument|int Index
argument_list|)
block|{
name|VarArgsFrameIndex
operator|=
name|Index
block|; }
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

