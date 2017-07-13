begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsTargetStreamer.h - Mips Target Streamer ------------*- C++ -*--===//
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
name|LLVM_LIB_TARGET_MIPS_MIPSTARGETSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MIPSTARGETSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/MipsABIFlagsSection.h"
end_include

begin_include
include|#
directive|include
file|"MCTargetDesc/MipsABIInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCELFStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct_decl|struct
name|MipsABIFlagsSection
struct_decl|;
name|class
name|MipsTargetStreamer
range|:
name|public
name|MCTargetStreamer
block|{
name|public
operator|:
name|MipsTargetStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|)
block|;
name|virtual
name|void
name|setPic
argument_list|(
argument|bool Value
argument_list|)
block|{}
name|virtual
name|void
name|emitDirectiveSetMicroMips
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetNoMicroMips
argument_list|()
block|;
name|virtual
name|void
name|setUsesMicroMips
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMips16
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetNoMips16
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetReorder
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetNoReorder
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMacro
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetNoMacro
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMsa
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetNoMsa
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMt
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetNoMt
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetAt
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetAtWithArg
argument_list|(
argument|unsigned RegNo
argument_list|)
block|;
name|virtual
name|void
name|emitDirectiveSetNoAt
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveEnd
argument_list|(
argument|StringRef Name
argument_list|)
block|;
name|virtual
name|void
name|emitDirectiveEnt
argument_list|(
specifier|const
name|MCSymbol
operator|&
name|Symbol
argument_list|)
block|;
name|virtual
name|void
name|emitDirectiveAbiCalls
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveNaN2008
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveNaNLegacy
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveOptionPic0
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveOptionPic2
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveInsn
argument_list|()
block|;
name|virtual
name|void
name|emitFrame
argument_list|(
argument|unsigned StackReg
argument_list|,
argument|unsigned StackSize
argument_list|,
argument|unsigned ReturnReg
argument_list|)
block|;
name|virtual
name|void
name|emitMask
argument_list|(
argument|unsigned CPUBitmask
argument_list|,
argument|int CPUTopSavedRegOff
argument_list|)
block|;
name|virtual
name|void
name|emitFMask
argument_list|(
argument|unsigned FPUBitmask
argument_list|,
argument|int FPUTopSavedRegOff
argument_list|)
block|;
name|virtual
name|void
name|emitDirectiveSetArch
argument_list|(
argument|StringRef Arch
argument_list|)
block|;
name|virtual
name|void
name|emitDirectiveSetMips0
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMips1
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMips2
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMips3
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMips4
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMips5
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMips32
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMips32R2
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMips32R3
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMips32R5
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMips32R6
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMips64
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMips64R2
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMips64R3
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMips64R5
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetMips64R6
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetDsp
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetNoDsp
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetPop
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetPush
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetSoftFloat
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetHardFloat
argument_list|()
block|;
comment|// PIC support
name|virtual
name|void
name|emitDirectiveCpLoad
argument_list|(
argument|unsigned RegNo
argument_list|)
block|;
name|virtual
name|bool
name|emitDirectiveCpRestore
argument_list|(
argument|int Offset
argument_list|,
argument|function_ref<unsigned()> GetATReg
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|virtual
name|void
name|emitDirectiveCpsetup
argument_list|(
argument|unsigned RegNo
argument_list|,
argument|int RegOrOffset
argument_list|,
argument|const MCSymbol&Sym
argument_list|,
argument|bool IsReg
argument_list|)
block|;
name|virtual
name|void
name|emitDirectiveCpreturn
argument_list|(
argument|unsigned SaveLocation
argument_list|,
argument|bool SaveLocationIsRegister
argument_list|)
block|;
comment|// FP abiflags directives
name|virtual
name|void
name|emitDirectiveModuleFP
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveModuleOddSPReg
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveModuleSoftFloat
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveModuleHardFloat
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveModuleMT
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetFp
argument_list|(
argument|MipsABIFlagsSection::FpABIKind Value
argument_list|)
block|;
name|virtual
name|void
name|emitDirectiveSetOddSPReg
argument_list|()
block|;
name|virtual
name|void
name|emitDirectiveSetNoOddSPReg
argument_list|()
block|;
name|void
name|emitR
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned Reg0
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|emitII
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|int16_t Imm1
argument_list|,
argument|int16_t Imm2
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|emitRX
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned Reg0
argument_list|,
argument|MCOperand Op1
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|emitRI
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned Reg0
argument_list|,
argument|int32_t Imm
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|emitRR
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned Reg0
argument_list|,
argument|unsigned Reg1
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|emitRRX
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned Reg0
argument_list|,
argument|unsigned Reg1
argument_list|,
argument|MCOperand Op2
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|emitRRR
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned Reg0
argument_list|,
argument|unsigned Reg1
argument_list|,
argument|unsigned Reg2
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|emitRRI
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned Reg0
argument_list|,
argument|unsigned Reg1
argument_list|,
argument|int16_t Imm
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|emitRRIII
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned Reg0
argument_list|,
argument|unsigned Reg1
argument_list|,
argument|int16_t Imm0
argument_list|,
argument|int16_t Imm1
argument_list|,
argument|int16_t Imm2
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|emitAddu
argument_list|(
argument|unsigned DstReg
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|unsigned TrgReg
argument_list|,
argument|bool Is64Bit
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|emitDSLL
argument_list|(
argument|unsigned DstReg
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|int16_t ShiftAmount
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|emitEmptyDelaySlot
argument_list|(
argument|bool hasShortDelaySlot
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|emitNop
argument_list|(
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
comment|/// Emit a store instruction with an offset. If the offset is out of range
comment|/// then it will be synthesized using the assembler temporary.
comment|///
comment|/// GetATReg() is a callback that can be used to obtain the current assembler
comment|/// temporary and is only called when the assembler temporary is required. It
comment|/// must handle the case where no assembler temporary is available (typically
comment|/// by reporting an error).
name|void
name|emitStoreWithImmOffset
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|int64_t Offset
argument_list|,
argument|function_ref<unsigned()> GetATReg
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|emitStoreWithSymOffset
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned SrcReg
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|MCOperand&HiOperand
argument_list|,
argument|MCOperand&LoOperand
argument_list|,
argument|unsigned ATReg
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|emitLoadWithImmOffset
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned DstReg
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|int64_t Offset
argument_list|,
argument|unsigned TmpReg
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|emitLoadWithSymOffset
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|unsigned DstReg
argument_list|,
argument|unsigned BaseReg
argument_list|,
argument|MCOperand&HiOperand
argument_list|,
argument|MCOperand&LoOperand
argument_list|,
argument|unsigned ATReg
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|emitGPRestore
argument_list|(
argument|int Offset
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
block|;
name|void
name|forbidModuleDirective
argument_list|()
block|{
name|ModuleDirectiveAllowed
operator|=
name|false
block|; }
name|void
name|reallowModuleDirective
argument_list|()
block|{
name|ModuleDirectiveAllowed
operator|=
name|true
block|; }
name|bool
name|isModuleDirectiveAllowed
argument_list|()
block|{
return|return
name|ModuleDirectiveAllowed
return|;
block|}
comment|// This method enables template classes to set internal abi flags
comment|// structure values.
name|template
operator|<
name|class
name|PredicateLibrary
operator|>
name|void
name|updateABIInfo
argument_list|(
argument|const PredicateLibrary&P
argument_list|)
block|{
name|ABI
operator|=
name|P
operator|.
name|getABI
argument_list|()
block|;
name|ABIFlagsSection
operator|.
name|setAllFromPredicates
argument_list|(
name|P
argument_list|)
block|;   }
name|MipsABIFlagsSection
operator|&
name|getABIFlagsSection
argument_list|()
block|{
return|return
name|ABIFlagsSection
return|;
block|}
specifier|const
name|MipsABIInfo
operator|&
name|getABI
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|ABI
operator|.
name|hasValue
argument_list|()
operator|&&
literal|"ABI hasn't been set!"
argument_list|)
block|;
return|return
operator|*
name|ABI
return|;
block|}
name|protected
operator|:
name|llvm
operator|::
name|Optional
operator|<
name|MipsABIInfo
operator|>
name|ABI
block|;
name|MipsABIFlagsSection
name|ABIFlagsSection
block|;
name|bool
name|GPRInfoSet
block|;
name|unsigned
name|GPRBitMask
block|;
name|int
name|GPROffset
block|;
name|bool
name|FPRInfoSet
block|;
name|unsigned
name|FPRBitMask
block|;
name|int
name|FPROffset
block|;
name|bool
name|FrameInfoSet
block|;
name|int
name|FrameOffset
block|;
name|unsigned
name|FrameReg
block|;
name|unsigned
name|ReturnReg
block|;
name|private
operator|:
name|bool
name|ModuleDirectiveAllowed
block|; }
decl_stmt|;
comment|// This part is for ascii assembly output
name|class
name|MipsTargetAsmStreamer
range|:
name|public
name|MipsTargetStreamer
block|{
name|formatted_raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|MipsTargetAsmStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|,
name|formatted_raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|void
name|emitDirectiveSetMicroMips
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetNoMicroMips
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips16
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetNoMips16
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetReorder
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetNoReorder
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMacro
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetNoMacro
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMsa
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetNoMsa
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMt
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetNoMt
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetAt
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetAtWithArg
argument_list|(
argument|unsigned RegNo
argument_list|)
name|override
block|;
name|void
name|emitDirectiveSetNoAt
argument_list|()
name|override
block|;
name|void
name|emitDirectiveEnd
argument_list|(
argument|StringRef Name
argument_list|)
name|override
block|;
name|void
name|emitDirectiveEnt
argument_list|(
argument|const MCSymbol&Symbol
argument_list|)
name|override
block|;
name|void
name|emitDirectiveAbiCalls
argument_list|()
name|override
block|;
name|void
name|emitDirectiveNaN2008
argument_list|()
name|override
block|;
name|void
name|emitDirectiveNaNLegacy
argument_list|()
name|override
block|;
name|void
name|emitDirectiveOptionPic0
argument_list|()
name|override
block|;
name|void
name|emitDirectiveOptionPic2
argument_list|()
name|override
block|;
name|void
name|emitDirectiveInsn
argument_list|()
name|override
block|;
name|void
name|emitFrame
argument_list|(
argument|unsigned StackReg
argument_list|,
argument|unsigned StackSize
argument_list|,
argument|unsigned ReturnReg
argument_list|)
name|override
block|;
name|void
name|emitMask
argument_list|(
argument|unsigned CPUBitmask
argument_list|,
argument|int CPUTopSavedRegOff
argument_list|)
name|override
block|;
name|void
name|emitFMask
argument_list|(
argument|unsigned FPUBitmask
argument_list|,
argument|int FPUTopSavedRegOff
argument_list|)
name|override
block|;
name|void
name|emitDirectiveSetArch
argument_list|(
argument|StringRef Arch
argument_list|)
name|override
block|;
name|void
name|emitDirectiveSetMips0
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips1
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips2
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips3
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips4
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips5
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips32
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips32R2
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips32R3
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips32R5
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips32R6
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips64
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips64R2
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips64R3
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips64R5
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips64R6
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetDsp
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetNoDsp
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetPop
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetPush
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetSoftFloat
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetHardFloat
argument_list|()
name|override
block|;
comment|// PIC support
name|void
name|emitDirectiveCpLoad
argument_list|(
argument|unsigned RegNo
argument_list|)
name|override
block|;
comment|/// Emit a .cprestore directive.  If the offset is out of range then it will
comment|/// be synthesized using the assembler temporary.
comment|///
comment|/// GetATReg() is a callback that can be used to obtain the current assembler
comment|/// temporary and is only called when the assembler temporary is required. It
comment|/// must handle the case where no assembler temporary is available (typically
comment|/// by reporting an error).
name|bool
name|emitDirectiveCpRestore
argument_list|(
argument|int Offset
argument_list|,
argument|function_ref<unsigned()> GetATReg
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
name|override
block|;
name|void
name|emitDirectiveCpsetup
argument_list|(
argument|unsigned RegNo
argument_list|,
argument|int RegOrOffset
argument_list|,
argument|const MCSymbol&Sym
argument_list|,
argument|bool IsReg
argument_list|)
name|override
block|;
name|void
name|emitDirectiveCpreturn
argument_list|(
argument|unsigned SaveLocation
argument_list|,
argument|bool SaveLocationIsRegister
argument_list|)
name|override
block|;
comment|// FP abiflags directives
name|void
name|emitDirectiveModuleFP
argument_list|()
name|override
block|;
name|void
name|emitDirectiveModuleOddSPReg
argument_list|()
name|override
block|;
name|void
name|emitDirectiveModuleSoftFloat
argument_list|()
name|override
block|;
name|void
name|emitDirectiveModuleHardFloat
argument_list|()
name|override
block|;
name|void
name|emitDirectiveModuleMT
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetFp
argument_list|(
argument|MipsABIFlagsSection::FpABIKind Value
argument_list|)
name|override
block|;
name|void
name|emitDirectiveSetOddSPReg
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetNoOddSPReg
argument_list|()
name|override
block|; }
decl_stmt|;
comment|// This part is for ELF object output
name|class
name|MipsTargetELFStreamer
range|:
name|public
name|MipsTargetStreamer
block|{
name|bool
name|MicroMipsEnabled
block|;
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
block|;
name|bool
name|Pic
block|;
name|public
operator|:
name|bool
name|isMicroMipsEnabled
argument_list|()
specifier|const
block|{
return|return
name|MicroMipsEnabled
return|;
block|}
name|MCELFStreamer
operator|&
name|getStreamer
argument_list|()
block|;
name|MipsTargetELFStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|,
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
argument_list|)
block|;
name|void
name|setPic
argument_list|(
argument|bool Value
argument_list|)
name|override
block|{
name|Pic
operator|=
name|Value
block|; }
name|void
name|emitLabel
argument_list|(
argument|MCSymbol *Symbol
argument_list|)
name|override
block|;
name|void
name|emitAssignment
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|const MCExpr *Value
argument_list|)
name|override
block|;
name|void
name|finish
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMicroMips
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetNoMicroMips
argument_list|()
name|override
block|;
name|void
name|setUsesMicroMips
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetMips16
argument_list|()
name|override
block|;
name|void
name|emitDirectiveSetNoReorder
argument_list|()
name|override
block|;
name|void
name|emitDirectiveEnd
argument_list|(
argument|StringRef Name
argument_list|)
name|override
block|;
name|void
name|emitDirectiveEnt
argument_list|(
argument|const MCSymbol&Symbol
argument_list|)
name|override
block|;
name|void
name|emitDirectiveAbiCalls
argument_list|()
name|override
block|;
name|void
name|emitDirectiveNaN2008
argument_list|()
name|override
block|;
name|void
name|emitDirectiveNaNLegacy
argument_list|()
name|override
block|;
name|void
name|emitDirectiveOptionPic0
argument_list|()
name|override
block|;
name|void
name|emitDirectiveOptionPic2
argument_list|()
name|override
block|;
name|void
name|emitDirectiveInsn
argument_list|()
name|override
block|;
name|void
name|emitFrame
argument_list|(
argument|unsigned StackReg
argument_list|,
argument|unsigned StackSize
argument_list|,
argument|unsigned ReturnReg
argument_list|)
name|override
block|;
name|void
name|emitMask
argument_list|(
argument|unsigned CPUBitmask
argument_list|,
argument|int CPUTopSavedRegOff
argument_list|)
name|override
block|;
name|void
name|emitFMask
argument_list|(
argument|unsigned FPUBitmask
argument_list|,
argument|int FPUTopSavedRegOff
argument_list|)
name|override
block|;
comment|// PIC support
name|void
name|emitDirectiveCpLoad
argument_list|(
argument|unsigned RegNo
argument_list|)
name|override
block|;
name|bool
name|emitDirectiveCpRestore
argument_list|(
argument|int Offset
argument_list|,
argument|function_ref<unsigned()> GetATReg
argument_list|,
argument|SMLoc IDLoc
argument_list|,
argument|const MCSubtargetInfo *STI
argument_list|)
name|override
block|;
name|void
name|emitDirectiveCpsetup
argument_list|(
argument|unsigned RegNo
argument_list|,
argument|int RegOrOffset
argument_list|,
argument|const MCSymbol&Sym
argument_list|,
argument|bool IsReg
argument_list|)
name|override
block|;
name|void
name|emitDirectiveCpreturn
argument_list|(
argument|unsigned SaveLocation
argument_list|,
argument|bool SaveLocationIsRegister
argument_list|)
name|override
block|;
name|void
name|emitMipsAbiFlags
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

