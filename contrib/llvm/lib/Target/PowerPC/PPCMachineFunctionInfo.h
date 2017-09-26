begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCMachineFunctionInfo.h - Private data used for PowerPC --*- C++ -*-=//
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
comment|// This file declares the PowerPC specific subclass of MachineFunctionInfo.
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
name|LLVM_LIB_TARGET_POWERPC_PPCMACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_POWERPC_PPCMACHINEFUNCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// PPCFunctionInfo - This class is derived from MachineFunction private
comment|/// PowerPC target-specific information for each MachineFunction.
name|class
name|PPCFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// FramePointerSaveIndex - Frame index of where the old frame pointer is
comment|/// stored.  Also used as an anchor for instructions that need to be altered
comment|/// when using frame pointers (dyna_add, dyna_sub.)
name|int
name|FramePointerSaveIndex
operator|=
literal|0
block|;
comment|/// ReturnAddrSaveIndex - Frame index of where the return address is stored.
comment|///
name|int
name|ReturnAddrSaveIndex
operator|=
literal|0
block|;
comment|/// Frame index where the old base pointer is stored.
name|int
name|BasePointerSaveIndex
operator|=
literal|0
block|;
comment|/// Frame index where the old PIC base pointer is stored.
name|int
name|PICBasePointerSaveIndex
operator|=
literal|0
block|;
comment|/// MustSaveLR - Indicates whether LR is defined (or clobbered) in the current
comment|/// function.  This is only valid after the initial scan of the function by
comment|/// PEI.
name|bool
name|MustSaveLR
block|;
comment|/// Does this function have any stack spills.
name|bool
name|HasSpills
operator|=
name|false
block|;
comment|/// Does this function spill using instructions with only r+r (not r+i)
comment|/// forms.
name|bool
name|HasNonRISpills
operator|=
name|false
block|;
comment|/// SpillsCR - Indicates whether CR is spilled in the current function.
name|bool
name|SpillsCR
operator|=
name|false
block|;
comment|/// Indicates whether VRSAVE is spilled in the current function.
name|bool
name|SpillsVRSAVE
operator|=
name|false
block|;
comment|/// LRStoreRequired - The bool indicates whether there is some explicit use of
comment|/// the LR/LR8 stack slot that is not obvious from scanning the code.  This
comment|/// requires that the code generator produce a store of LR to the stack on
comment|/// entry, even though LR may otherwise apparently not be used.
name|bool
name|LRStoreRequired
operator|=
name|false
block|;
comment|/// This function makes use of the PPC64 ELF TOC base pointer (register r2).
name|bool
name|UsesTOCBasePtr
operator|=
name|false
block|;
comment|/// MinReservedArea - This is the frame size that is at least reserved in a
comment|/// potential caller (parameter+linkage area).
name|unsigned
name|MinReservedArea
operator|=
literal|0
block|;
comment|/// TailCallSPDelta - Stack pointer delta used when tail calling. Maximum
comment|/// amount the stack pointer is adjusted to make the frame bigger for tail
comment|/// calls. Used for creating an area before the register spill area.
name|int
name|TailCallSPDelta
operator|=
literal|0
block|;
comment|/// HasFastCall - Does this function contain a fast call. Used to determine
comment|/// how the caller's stack pointer should be calculated (epilog/dynamicalloc).
name|bool
name|HasFastCall
operator|=
name|false
block|;
comment|/// VarArgsFrameIndex - FrameIndex for start of varargs area.
name|int
name|VarArgsFrameIndex
operator|=
literal|0
block|;
comment|/// VarArgsStackOffset - StackOffset for start of stack
comment|/// arguments.
name|int
name|VarArgsStackOffset
operator|=
literal|0
block|;
comment|/// VarArgsNumGPR - Index of the first unused integer
comment|/// register for parameter passing.
name|unsigned
name|VarArgsNumGPR
operator|=
literal|0
block|;
comment|/// VarArgsNumFPR - Index of the first unused double
comment|/// register for parameter passing.
name|unsigned
name|VarArgsNumFPR
operator|=
literal|0
block|;
comment|/// CRSpillFrameIndex - FrameIndex for CR spill slot for 32-bit SVR4.
name|int
name|CRSpillFrameIndex
operator|=
literal|0
block|;
comment|/// If any of CR[2-4] need to be saved in the prologue and restored in the
comment|/// epilogue then they are added to this array. This is used for the
comment|/// 64-bit SVR4 ABI.
name|SmallVector
operator|<
name|unsigned
block|,
literal|3
operator|>
name|MustSaveCRs
block|;
comment|/// Hold onto our MachineFunction context.
name|MachineFunction
operator|&
name|MF
block|;
comment|/// Whether this uses the PIC Base register or not.
name|bool
name|UsesPICBase
operator|=
name|false
block|;
comment|/// True if this function has a subset of CSRs that is handled explicitly via
comment|/// copies
name|bool
name|IsSplitCSR
operator|=
name|false
block|;
name|public
operator|:
name|explicit
name|PPCFunctionInfo
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
name|int
name|getFramePointerSaveIndex
argument_list|()
specifier|const
block|{
return|return
name|FramePointerSaveIndex
return|;
block|}
name|void
name|setFramePointerSaveIndex
argument_list|(
argument|int Idx
argument_list|)
block|{
name|FramePointerSaveIndex
operator|=
name|Idx
block|; }
name|int
name|getReturnAddrSaveIndex
argument_list|()
specifier|const
block|{
return|return
name|ReturnAddrSaveIndex
return|;
block|}
name|void
name|setReturnAddrSaveIndex
argument_list|(
argument|int idx
argument_list|)
block|{
name|ReturnAddrSaveIndex
operator|=
name|idx
block|; }
name|int
name|getBasePointerSaveIndex
argument_list|()
specifier|const
block|{
return|return
name|BasePointerSaveIndex
return|;
block|}
name|void
name|setBasePointerSaveIndex
argument_list|(
argument|int Idx
argument_list|)
block|{
name|BasePointerSaveIndex
operator|=
name|Idx
block|; }
name|int
name|getPICBasePointerSaveIndex
argument_list|()
specifier|const
block|{
return|return
name|PICBasePointerSaveIndex
return|;
block|}
name|void
name|setPICBasePointerSaveIndex
argument_list|(
argument|int Idx
argument_list|)
block|{
name|PICBasePointerSaveIndex
operator|=
name|Idx
block|; }
name|unsigned
name|getMinReservedArea
argument_list|()
specifier|const
block|{
return|return
name|MinReservedArea
return|;
block|}
name|void
name|setMinReservedArea
argument_list|(
argument|unsigned size
argument_list|)
block|{
name|MinReservedArea
operator|=
name|size
block|; }
name|int
name|getTailCallSPDelta
argument_list|()
specifier|const
block|{
return|return
name|TailCallSPDelta
return|;
block|}
name|void
name|setTailCallSPDelta
argument_list|(
argument|int size
argument_list|)
block|{
name|TailCallSPDelta
operator|=
name|size
block|; }
comment|/// MustSaveLR - This is set when the prolog/epilog inserter does its initial
comment|/// scan of the function. It is true if the LR/LR8 register is ever explicitly
comment|/// defined/clobbered in the machine function (e.g. by calls and movpctolr,
comment|/// which is used in PIC generation), or if the LR stack slot is explicitly
comment|/// referenced by builtin_return_address.
name|void
name|setMustSaveLR
argument_list|(
argument|bool U
argument_list|)
block|{
name|MustSaveLR
operator|=
name|U
block|; }
name|bool
name|mustSaveLR
argument_list|()
specifier|const
block|{
return|return
name|MustSaveLR
return|;
block|}
name|void
name|setHasSpills
argument_list|()
block|{
name|HasSpills
operator|=
name|true
block|; }
name|bool
name|hasSpills
argument_list|()
specifier|const
block|{
return|return
name|HasSpills
return|;
block|}
name|void
name|setHasNonRISpills
argument_list|()
block|{
name|HasNonRISpills
operator|=
name|true
block|; }
name|bool
name|hasNonRISpills
argument_list|()
specifier|const
block|{
return|return
name|HasNonRISpills
return|;
block|}
name|void
name|setSpillsCR
argument_list|()
block|{
name|SpillsCR
operator|=
name|true
block|; }
name|bool
name|isCRSpilled
argument_list|()
specifier|const
block|{
return|return
name|SpillsCR
return|;
block|}
name|void
name|setSpillsVRSAVE
argument_list|()
block|{
name|SpillsVRSAVE
operator|=
name|true
block|; }
name|bool
name|isVRSAVESpilled
argument_list|()
specifier|const
block|{
return|return
name|SpillsVRSAVE
return|;
block|}
name|void
name|setLRStoreRequired
argument_list|()
block|{
name|LRStoreRequired
operator|=
name|true
block|; }
name|bool
name|isLRStoreRequired
argument_list|()
specifier|const
block|{
return|return
name|LRStoreRequired
return|;
block|}
name|void
name|setUsesTOCBasePtr
argument_list|()
block|{
name|UsesTOCBasePtr
operator|=
name|true
block|; }
name|bool
name|usesTOCBasePtr
argument_list|()
specifier|const
block|{
return|return
name|UsesTOCBasePtr
return|;
block|}
name|void
name|setHasFastCall
argument_list|()
block|{
name|HasFastCall
operator|=
name|true
block|; }
name|bool
name|hasFastCall
argument_list|()
specifier|const
block|{
return|return
name|HasFastCall
return|;
block|}
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
name|int
name|getVarArgsStackOffset
argument_list|()
specifier|const
block|{
return|return
name|VarArgsStackOffset
return|;
block|}
name|void
name|setVarArgsStackOffset
argument_list|(
argument|int Offset
argument_list|)
block|{
name|VarArgsStackOffset
operator|=
name|Offset
block|; }
name|unsigned
name|getVarArgsNumGPR
argument_list|()
specifier|const
block|{
return|return
name|VarArgsNumGPR
return|;
block|}
name|void
name|setVarArgsNumGPR
argument_list|(
argument|unsigned Num
argument_list|)
block|{
name|VarArgsNumGPR
operator|=
name|Num
block|; }
name|unsigned
name|getVarArgsNumFPR
argument_list|()
specifier|const
block|{
return|return
name|VarArgsNumFPR
return|;
block|}
name|void
name|setVarArgsNumFPR
argument_list|(
argument|unsigned Num
argument_list|)
block|{
name|VarArgsNumFPR
operator|=
name|Num
block|; }
name|int
name|getCRSpillFrameIndex
argument_list|()
specifier|const
block|{
return|return
name|CRSpillFrameIndex
return|;
block|}
name|void
name|setCRSpillFrameIndex
argument_list|(
argument|int idx
argument_list|)
block|{
name|CRSpillFrameIndex
operator|=
name|idx
block|; }
specifier|const
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|getMustSaveCRs
argument_list|()
specifier|const
block|{
return|return
name|MustSaveCRs
return|;
block|}
name|void
name|addMustSaveCR
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|MustSaveCRs
operator|.
name|push_back
argument_list|(
name|Reg
argument_list|)
block|; }
name|void
name|setUsesPICBase
argument_list|(
argument|bool uses
argument_list|)
block|{
name|UsesPICBase
operator|=
name|uses
block|; }
name|bool
name|usesPICBase
argument_list|()
specifier|const
block|{
return|return
name|UsesPICBase
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
name|MCSymbol
operator|*
name|getPICOffsetSymbol
argument_list|()
specifier|const
block|;
name|MCSymbol
operator|*
name|getGlobalEPSymbol
argument_list|()
specifier|const
block|;
name|MCSymbol
operator|*
name|getLocalEPSymbol
argument_list|()
specifier|const
block|;
name|MCSymbol
operator|*
name|getTOCOffsetSymbol
argument_list|()
specifier|const
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
comment|// LLVM_LIB_TARGET_POWERPC_PPCMACHINEFUNCTIONINFO_H
end_comment

end_unit

