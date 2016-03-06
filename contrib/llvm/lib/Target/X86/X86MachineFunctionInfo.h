begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86MachineFunctionInfo.h - X86 machine function info ----*- C++ -*-===//
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
comment|// This file declares X86-specific per-machine-function information.
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
name|LLVM_LIB_TARGET_X86_X86MACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_X86_X86MACHINEFUNCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/CallingConvLower.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineValueType.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// X86MachineFunctionInfo - This class is derived from MachineFunction and
comment|/// contains private X86 target-specific information for each MachineFunction.
name|class
name|X86MachineFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// ForceFramePointer - True if the function is required to use of frame
comment|/// pointer for reasons other than it containing dynamic allocation or
comment|/// that FP eliminatation is turned off. For example, Cygwin main function
comment|/// contains stack pointer re-alignment code which requires FP.
name|bool
name|ForceFramePointer
operator|=
name|false
block|;
comment|/// RestoreBasePointerOffset - Non-zero if the function has base pointer
comment|/// and makes call to llvm.eh.sjlj.setjmp. When non-zero, the value is a
comment|/// displacement from the frame pointer to a slot where the base pointer
comment|/// is stashed.
name|signed
name|char
name|RestoreBasePointerOffset
operator|=
literal|0
block|;
comment|/// CalleeSavedFrameSize - Size of the callee-saved register portion of the
comment|/// stack frame in bytes.
name|unsigned
name|CalleeSavedFrameSize
operator|=
literal|0
block|;
comment|/// BytesToPopOnReturn - Number of bytes function pops on return (in addition
comment|/// to the space used by the return address).
comment|/// Used on windows platform for stdcall& fastcall name decoration
name|unsigned
name|BytesToPopOnReturn
operator|=
literal|0
block|;
comment|/// ReturnAddrIndex - FrameIndex for return slot.
name|int
name|ReturnAddrIndex
operator|=
literal|0
block|;
comment|/// \brief FrameIndex for return slot.
name|int
name|FrameAddrIndex
operator|=
literal|0
block|;
comment|/// TailCallReturnAddrDelta - The number of bytes by which return address
comment|/// stack slot is moved as the result of tail call optimization.
name|int
name|TailCallReturnAddrDelta
operator|=
literal|0
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
comment|/// RegSaveFrameIndex - X86-64 vararg func register save area.
name|int
name|RegSaveFrameIndex
operator|=
literal|0
block|;
comment|/// VarArgsGPOffset - X86-64 vararg func int reg offset.
name|unsigned
name|VarArgsGPOffset
operator|=
literal|0
block|;
comment|/// VarArgsFPOffset - X86-64 vararg func fp reg offset.
name|unsigned
name|VarArgsFPOffset
operator|=
literal|0
block|;
comment|/// ArgumentStackSize - The number of bytes on stack consumed by the arguments
comment|/// being passed on the stack.
name|unsigned
name|ArgumentStackSize
operator|=
literal|0
block|;
comment|/// NumLocalDynamics - Number of local-dynamic TLS accesses.
name|unsigned
name|NumLocalDynamics
operator|=
literal|0
block|;
comment|/// HasPushSequences - Keeps track of whether this function uses sequences
comment|/// of pushes to pass function parameters.
name|bool
name|HasPushSequences
operator|=
name|false
block|;
comment|/// True if the function recovers from an SEH exception, and therefore needs
comment|/// to spill and restore the frame pointer.
name|bool
name|HasSEHFramePtrSave
operator|=
name|false
block|;
comment|/// The frame index of a stack object containing the original frame pointer
comment|/// used to address arguments in a function using a base pointer.
name|int
name|SEHFramePtrSaveIndex
operator|=
literal|0
block|;
comment|/// True if this function has a subset of CSRs that is handled explicitly via
comment|/// copies.
name|bool
name|IsSplitCSR
operator|=
name|false
block|;
name|private
operator|:
comment|/// ForwardedMustTailRegParms - A list of virtual and physical registers
comment|/// that must be forwarded to every musttail call.
name|SmallVector
operator|<
name|ForwardedRegister
block|,
literal|1
operator|>
name|ForwardedMustTailRegParms
block|;
name|public
operator|:
name|X86MachineFunctionInfo
argument_list|()
operator|=
expr|default
block|;
name|explicit
name|X86MachineFunctionInfo
argument_list|(
argument|MachineFunction&MF
argument_list|)
block|{}
name|bool
name|getForceFramePointer
argument_list|()
specifier|const
block|{
return|return
name|ForceFramePointer
return|;
block|}
name|void
name|setForceFramePointer
argument_list|(
argument|bool forceFP
argument_list|)
block|{
name|ForceFramePointer
operator|=
name|forceFP
block|; }
name|bool
name|getHasPushSequences
argument_list|()
specifier|const
block|{
return|return
name|HasPushSequences
return|;
block|}
name|void
name|setHasPushSequences
argument_list|(
argument|bool HasPush
argument_list|)
block|{
name|HasPushSequences
operator|=
name|HasPush
block|; }
name|bool
name|getRestoreBasePointer
argument_list|()
specifier|const
block|{
return|return
name|RestoreBasePointerOffset
operator|!=
literal|0
return|;
block|}
name|void
name|setRestoreBasePointer
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
name|int
name|getRestoreBasePointerOffset
argument_list|()
specifier|const
block|{
return|return
name|RestoreBasePointerOffset
return|;
block|}
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
name|getBytesToPopOnReturn
argument_list|()
specifier|const
block|{
return|return
name|BytesToPopOnReturn
return|;
block|}
name|void
name|setBytesToPopOnReturn
argument_list|(
argument|unsigned bytes
argument_list|)
block|{
name|BytesToPopOnReturn
operator|=
name|bytes
block|;}
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
name|getFAIndex
argument_list|()
specifier|const
block|{
return|return
name|FrameAddrIndex
return|;
block|}
name|void
name|setFAIndex
argument_list|(
argument|int Index
argument_list|)
block|{
name|FrameAddrIndex
operator|=
name|Index
block|; }
name|int
name|getTCReturnAddrDelta
argument_list|()
specifier|const
block|{
return|return
name|TailCallReturnAddrDelta
return|;
block|}
name|void
name|setTCReturnAddrDelta
argument_list|(
argument|int delta
argument_list|)
block|{
name|TailCallReturnAddrDelta
operator|=
name|delta
block|;}
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
name|unsigned
name|getGlobalBaseReg
argument_list|()
specifier|const
block|{
return|return
name|GlobalBaseReg
return|;
block|}
name|void
name|setGlobalBaseReg
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|GlobalBaseReg
operator|=
name|Reg
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
argument|int Idx
argument_list|)
block|{
name|VarArgsFrameIndex
operator|=
name|Idx
block|; }
name|int
name|getRegSaveFrameIndex
argument_list|()
specifier|const
block|{
return|return
name|RegSaveFrameIndex
return|;
block|}
name|void
name|setRegSaveFrameIndex
argument_list|(
argument|int Idx
argument_list|)
block|{
name|RegSaveFrameIndex
operator|=
name|Idx
block|; }
name|unsigned
name|getVarArgsGPOffset
argument_list|()
specifier|const
block|{
return|return
name|VarArgsGPOffset
return|;
block|}
name|void
name|setVarArgsGPOffset
argument_list|(
argument|unsigned Offset
argument_list|)
block|{
name|VarArgsGPOffset
operator|=
name|Offset
block|; }
name|unsigned
name|getVarArgsFPOffset
argument_list|()
specifier|const
block|{
return|return
name|VarArgsFPOffset
return|;
block|}
name|void
name|setVarArgsFPOffset
argument_list|(
argument|unsigned Offset
argument_list|)
block|{
name|VarArgsFPOffset
operator|=
name|Offset
block|; }
name|unsigned
name|getArgumentStackSize
argument_list|()
specifier|const
block|{
return|return
name|ArgumentStackSize
return|;
block|}
name|void
name|setArgumentStackSize
argument_list|(
argument|unsigned size
argument_list|)
block|{
name|ArgumentStackSize
operator|=
name|size
block|; }
name|unsigned
name|getNumLocalDynamicTLSAccesses
argument_list|()
specifier|const
block|{
return|return
name|NumLocalDynamics
return|;
block|}
name|void
name|incNumLocalDynamicTLSAccesses
argument_list|()
block|{
operator|++
name|NumLocalDynamics
block|; }
name|bool
name|getHasSEHFramePtrSave
argument_list|()
specifier|const
block|{
return|return
name|HasSEHFramePtrSave
return|;
block|}
name|void
name|setHasSEHFramePtrSave
argument_list|(
argument|bool V
argument_list|)
block|{
name|HasSEHFramePtrSave
operator|=
name|V
block|; }
name|int
name|getSEHFramePtrSaveIndex
argument_list|()
specifier|const
block|{
return|return
name|SEHFramePtrSaveIndex
return|;
block|}
name|void
name|setSEHFramePtrSaveIndex
argument_list|(
argument|int Index
argument_list|)
block|{
name|SEHFramePtrSaveIndex
operator|=
name|Index
block|; }
name|SmallVectorImpl
operator|<
name|ForwardedRegister
operator|>
operator|&
name|getForwardedMustTailRegParms
argument_list|()
block|{
return|return
name|ForwardedMustTailRegParms
return|;
block|}
name|bool
name|isSplitCSR
argument_list|()
specifier|const
block|{
return|return
name|IsSplitCSR
return|;
block|}
name|void
name|setIsSplitCSR
argument_list|(
argument|bool s
argument_list|)
block|{
name|IsSplitCSR
operator|=
name|s
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

