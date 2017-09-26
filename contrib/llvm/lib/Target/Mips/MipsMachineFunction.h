begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MipsMachineFunctionInfo.h - Private data used for Mips ---*- C++ -*-===//
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
comment|// This file declares the Mips specific subclass of MachineFunctionInfo.
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
name|LLVM_LIB_TARGET_MIPS_MIPSMACHINEFUNCTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MIPSMACHINEFUNCTION_H
end_define

begin_include
include|#
directive|include
file|"Mips16HardFloatInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineMemOperand.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MipsFunctionInfo - This class is derived from MachineFunction private
comment|/// Mips target-specific information for each MachineFunction.
name|class
name|MipsFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
name|public
operator|:
name|MipsFunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|:
name|MF
argument_list|(
argument|MF
argument_list|)
block|{}
operator|~
name|MipsFunctionInfo
argument_list|()
name|override
block|;
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
name|bool
name|globalBaseRegSet
argument_list|()
specifier|const
block|;
name|unsigned
name|getGlobalBaseReg
argument_list|()
block|;
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
name|bool
name|hasByvalArg
argument_list|()
specifier|const
block|{
return|return
name|HasByvalArg
return|;
block|}
name|void
name|setFormalArgInfo
argument_list|(
argument|unsigned Size
argument_list|,
argument|bool HasByval
argument_list|)
block|{
name|IncomingArgSize
operator|=
name|Size
block|;
name|HasByvalArg
operator|=
name|HasByval
block|;   }
name|unsigned
name|getIncomingArgSize
argument_list|()
specifier|const
block|{
return|return
name|IncomingArgSize
return|;
block|}
name|bool
name|callsEhReturn
argument_list|()
specifier|const
block|{
return|return
name|CallsEhReturn
return|;
block|}
name|void
name|setCallsEhReturn
argument_list|()
block|{
name|CallsEhReturn
operator|=
name|true
block|; }
name|void
name|createEhDataRegsFI
argument_list|()
block|;
name|int
name|getEhDataRegFI
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|{
return|return
name|EhDataRegFI
index|[
name|Reg
index|]
return|;
block|}
name|bool
name|isEhDataRegFI
argument_list|(
argument|int FI
argument_list|)
specifier|const
block|;
comment|/// Create a MachinePointerInfo that has an ExternalSymbolPseudoSourceValue
comment|/// object representing a GOT entry for an external function.
name|MachinePointerInfo
name|callPtrInfo
argument_list|(
specifier|const
name|char
operator|*
name|ES
argument_list|)
block|;
comment|// Functions with the "interrupt" attribute require special prologues,
comment|// epilogues and additional spill slots.
name|bool
name|isISR
argument_list|()
specifier|const
block|{
return|return
name|IsISR
return|;
block|}
name|void
name|setISR
argument_list|()
block|{
name|IsISR
operator|=
name|true
block|; }
name|void
name|createISRRegFI
argument_list|()
block|;
name|int
name|getISRRegFI
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|{
return|return
name|ISRDataRegFI
index|[
name|Reg
index|]
return|;
block|}
name|bool
name|isISRRegFI
argument_list|(
argument|int FI
argument_list|)
specifier|const
block|;
comment|/// Create a MachinePointerInfo that has a GlobalValuePseudoSourceValue object
comment|/// representing a GOT entry for a global function.
name|MachinePointerInfo
name|callPtrInfo
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|)
block|;
name|void
name|setSaveS2
argument_list|()
block|{
name|SaveS2
operator|=
name|true
block|; }
name|bool
name|hasSaveS2
argument_list|()
specifier|const
block|{
return|return
name|SaveS2
return|;
block|}
name|int
name|getMoveF64ViaSpillFI
argument_list|(
specifier|const
name|TargetRegisterClass
operator|*
name|RC
argument_list|)
block|;
name|std
operator|::
name|map
operator|<
specifier|const
name|char
operator|*
block|,
specifier|const
name|Mips16HardFloatInfo
operator|::
name|FuncSignature
operator|*
operator|>
name|StubsNeeded
block|;
name|private
operator|:
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|MachineFunction
operator|&
name|MF
block|;
comment|/// SRetReturnReg - Some subtargets require that sret lowering includes
comment|/// returning the value of the returned struct in a register. This field
comment|/// holds the virtual register into which the sret argument is passed.
name|unsigned
name|SRetReturnReg
operator|=
literal|0
block|;
comment|/// GlobalBaseReg - keeps track of the virtual register initialized for
comment|/// use as the global base register. This is used for PIC in some PIC
comment|/// relocation models.
name|unsigned
name|GlobalBaseReg
operator|=
literal|0
block|;
comment|/// VarArgsFrameIndex - FrameIndex for start of varargs area.
name|int
name|VarArgsFrameIndex
operator|=
literal|0
block|;
comment|/// True if function has a byval argument.
name|bool
name|HasByvalArg
block|;
comment|/// Size of incoming argument area.
name|unsigned
name|IncomingArgSize
block|;
comment|/// CallsEhReturn - Whether the function calls llvm.eh.return.
name|bool
name|CallsEhReturn
operator|=
name|false
block|;
comment|/// Frame objects for spilling eh data registers.
name|int
name|EhDataRegFI
index|[
literal|4
index|]
block|;
comment|/// ISR - Whether the function is an Interrupt Service Routine.
name|bool
name|IsISR
operator|=
name|false
block|;
comment|/// Frame objects for spilling C0_STATUS, C0_EPC
name|int
name|ISRDataRegFI
index|[
literal|2
index|]
block|;
comment|// saveS2
name|bool
name|SaveS2
operator|=
name|false
block|;
comment|/// FrameIndex for expanding BuildPairF64 nodes to spill and reload when the
comment|/// O32 FPXX ABI is enabled. -1 is used to denote invalid index.
name|int
name|MoveF64ViaSpillFI
operator|=
operator|-
literal|1
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_MIPS_MIPSMACHINEFUNCTION_H
end_comment

end_unit

