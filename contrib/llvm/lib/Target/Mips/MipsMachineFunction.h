begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsMachineFunctionInfo.h - Private data used for Mips ----*- C++ -*-=//
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
name|MIPS_MACHINE_FUNCTION_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|MIPS_MACHINE_FUNCTION_INFO_H
end_define

begin_include
include|#
directive|include
file|"MipsSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ValueMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFrameInfo.h"
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
file|"llvm/CodeGen/PseudoSourceValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief A class derived from PseudoSourceValue that represents a GOT entry
comment|/// resolved by lazy-binding.
name|class
name|MipsCallEntry
range|:
name|public
name|PseudoSourceValue
block|{
name|public
operator|:
name|explicit
name|MipsCallEntry
argument_list|(
specifier|const
name|StringRef
operator|&
name|N
argument_list|)
block|;
name|explicit
name|MipsCallEntry
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|V
argument_list|)
block|;
name|virtual
name|bool
name|isConstant
argument_list|(
argument|const MachineFrameInfo *
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isAliased
argument_list|(
argument|const MachineFrameInfo *
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|mayAlias
argument_list|(
argument|const MachineFrameInfo *
argument_list|)
specifier|const
block|;
name|private
operator|:
name|virtual
name|void
name|printCustom
argument_list|(
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
ifndef|#
directive|ifndef
name|NDEBUG
name|std
operator|::
name|string
name|Name
block|;
specifier|const
name|GlobalValue
operator|*
name|Val
block|;
endif|#
directive|endif
block|}
decl_stmt|;
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
name|MF
argument_list|)
block|,
name|SRetReturnReg
argument_list|(
literal|0
argument_list|)
block|,
name|GlobalBaseReg
argument_list|(
literal|0
argument_list|)
block|,
name|Mips16SPAliasReg
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsFrameIndex
argument_list|(
literal|0
argument_list|)
block|,
name|CallsEhReturn
argument_list|(
argument|false
argument_list|)
block|{}
operator|~
name|MipsFunctionInfo
argument_list|()
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
name|bool
name|mips16SPAliasRegSet
argument_list|()
specifier|const
block|;
name|unsigned
name|getMips16SPAliasReg
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
comment|/// \brief Create a MachinePointerInfo that has a MipsCallEntr object
comment|/// representing a GOT entry for an external function.
name|MachinePointerInfo
name|callPtrInfo
argument_list|(
specifier|const
name|StringRef
operator|&
name|Name
argument_list|)
block|;
comment|/// \brief Create a MachinePointerInfo that has a MipsCallEntr object
comment|/// representing a GOT entry for a global function.
name|MachinePointerInfo
name|callPtrInfo
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|Val
argument_list|)
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
block|;
comment|/// GlobalBaseReg - keeps track of the virtual register initialized for
comment|/// use as the global base register. This is used for PIC in some PIC
comment|/// relocation models.
name|unsigned
name|GlobalBaseReg
block|;
comment|/// Mips16SPAliasReg - keeps track of the virtual register initialized for
comment|/// use as an alias for SP for use in load/store of halfword/byte from/to
comment|/// the stack
name|unsigned
name|Mips16SPAliasReg
block|;
comment|/// VarArgsFrameIndex - FrameIndex for start of varargs area.
name|int
name|VarArgsFrameIndex
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
block|;
comment|/// Frame objects for spilling eh data registers.
name|int
name|EhDataRegFI
index|[
literal|4
index|]
block|;
comment|/// MipsCallEntry maps.
name|StringMap
operator|<
specifier|const
name|MipsCallEntry
operator|*
operator|>
name|ExternalCallEntries
block|;
name|ValueMap
operator|<
specifier|const
name|GlobalValue
operator|*
block|,
specifier|const
name|MipsCallEntry
operator|*
operator|>
name|GlobalCallEntries
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// MIPS_MACHINE_FUNCTION_INFO_H
end_comment

end_unit

