begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsSubtarget.h - Define Subtarget for the Mips ---------*- C++ -*-===//
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
comment|// This file declares the Mips specific subclass of TargetSubtargetInfo.
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
name|MIPSSUBTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSSUBTARGET_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/MipsReginfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrItineraries.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetSubtargetInfo.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"MipsGenSubtargetInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|class
name|MipsTargetMachine
decl_stmt|;
name|class
name|MipsSubtarget
range|:
name|public
name|MipsGenSubtargetInfo
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
comment|// NOTE: O64 will not be supported.
expr|enum
name|MipsABIEnum
block|{
name|UnknownABI
block|,
name|O32
block|,
name|N32
block|,
name|N64
block|,
name|EABI
block|}
block|;
name|protected
operator|:
expr|enum
name|MipsArchEnum
block|{
name|Mips32
block|,
name|Mips32r2
block|,
name|Mips64
block|,
name|Mips64r2
block|}
block|;
comment|// Mips architecture version
name|MipsArchEnum
name|MipsArchVersion
block|;
comment|// Mips supported ABIs
name|MipsABIEnum
name|MipsABI
block|;
comment|// IsLittle - The target is Little Endian
name|bool
name|IsLittle
block|;
comment|// IsSingleFloat - The target only supports single precision float
comment|// point operations. This enable the target to use all 32 32-bit
comment|// floating point registers instead of only using even ones.
name|bool
name|IsSingleFloat
block|;
comment|// IsFP64bit - The target processor has 64-bit floating point registers.
name|bool
name|IsFP64bit
block|;
comment|// IsFP64bit - General-purpose registers are 64 bits wide
name|bool
name|IsGP64bit
block|;
comment|// HasVFPU - Processor has a vector floating point unit.
name|bool
name|HasVFPU
block|;
comment|// isLinux - Target system is Linux. Is false we consider ELFOS for now.
name|bool
name|IsLinux
block|;
comment|// UseSmallSection - Small section is used.
name|bool
name|UseSmallSection
block|;
comment|/// Features related to the presence of specific instructions.
comment|// HasSEInReg - SEB and SEH (signext in register) instructions.
name|bool
name|HasSEInReg
block|;
comment|// HasCondMov - Conditional mov (MOVZ, MOVN) instructions.
name|bool
name|HasCondMov
block|;
comment|// HasSwap - Byte and half swap instructions.
name|bool
name|HasSwap
block|;
comment|// HasBitCount - Count leading '1' and '0' bits.
name|bool
name|HasBitCount
block|;
comment|// HasFPIdx -- Floating point indexed load/store instructions.
name|bool
name|HasFPIdx
block|;
comment|// InMips16 -- can process Mips16 instructions
name|bool
name|InMips16Mode
block|;
comment|// Mips16 hard float
name|bool
name|InMips16HardFloat
block|;
comment|// PreviousInMips16 -- the function we just processed was in Mips 16 Mode
name|bool
name|PreviousInMips16Mode
block|;
comment|// InMicroMips -- can process MicroMips instructions
name|bool
name|InMicroMipsMode
block|;
comment|// HasDSP, HasDSPR2 -- supports DSP ASE.
name|bool
name|HasDSP
block|,
name|HasDSPR2
block|;
comment|// Allow mixed Mips16 and Mips32 in one source file
name|bool
name|AllowMixed16_32
block|;
comment|// Optimize for space by compiling all functions as Mips 16 unless
comment|// it needs floating point. Functions needing floating point are
comment|// compiled as Mips32
name|bool
name|Os16
block|;
comment|// HasMSA -- supports MSA ASE.
name|bool
name|HasMSA
block|;
name|InstrItineraryData
name|InstrItins
block|;
comment|// The instance to the register info section object
name|MipsReginfo
name|MRI
block|;
comment|// Relocation Model
name|Reloc
operator|::
name|Model
name|RM
block|;
comment|// We can override the determination of whether we are in mips16 mode
comment|// as from the command line
block|enum
block|{
name|NoOverride
block|,
name|Mips16Override
block|,
name|NoMips16Override
block|}
name|OverrideMode
block|;
name|MipsTargetMachine
operator|*
name|TM
block|;
name|public
operator|:
name|virtual
name|bool
name|enablePostRAScheduler
argument_list|(
argument|CodeGenOpt::Level OptLevel
argument_list|,
argument|AntiDepBreakMode& Mode
argument_list|,
argument|RegClassVector& CriticalPathRCs
argument_list|)
specifier|const
block|;
comment|/// Only O32 and EABI supported right now.
name|bool
name|isABI_EABI
argument_list|()
specifier|const
block|{
return|return
name|MipsABI
operator|==
name|EABI
return|;
block|}
name|bool
name|isABI_N64
argument_list|()
specifier|const
block|{
return|return
name|MipsABI
operator|==
name|N64
return|;
block|}
name|bool
name|isABI_N32
argument_list|()
specifier|const
block|{
return|return
name|MipsABI
operator|==
name|N32
return|;
block|}
name|bool
name|isABI_O32
argument_list|()
specifier|const
block|{
return|return
name|MipsABI
operator|==
name|O32
return|;
block|}
name|unsigned
name|getTargetABI
argument_list|()
specifier|const
block|{
return|return
name|MipsABI
return|;
block|}
comment|/// This constructor initializes the data members to match that
comment|/// of the specified triple.
name|MipsSubtarget
argument_list|(
argument|const std::string&TT
argument_list|,
argument|const std::string&CPU
argument_list|,
argument|const std::string&FS
argument_list|,
argument|bool little
argument_list|,
argument|Reloc::Model RM
argument_list|,
argument|MipsTargetMachine *TM
argument_list|)
block|;
comment|/// ParseSubtargetFeatures - Parses features string setting specified
comment|/// subtarget options.  Definition of function is auto generated by tblgen.
name|void
name|ParseSubtargetFeatures
argument_list|(
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|)
block|;
name|bool
name|hasMips32
argument_list|()
specifier|const
block|{
return|return
name|MipsArchVersion
operator|>=
name|Mips32
return|;
block|}
name|bool
name|hasMips32r2
argument_list|()
specifier|const
block|{
return|return
name|MipsArchVersion
operator|==
name|Mips32r2
operator|||
name|MipsArchVersion
operator|==
name|Mips64r2
return|;
block|}
name|bool
name|hasMips64
argument_list|()
specifier|const
block|{
return|return
name|MipsArchVersion
operator|>=
name|Mips64
return|;
block|}
name|bool
name|hasMips64r2
argument_list|()
specifier|const
block|{
return|return
name|MipsArchVersion
operator|==
name|Mips64r2
return|;
block|}
name|bool
name|isLittle
argument_list|()
specifier|const
block|{
return|return
name|IsLittle
return|;
block|}
name|bool
name|isFP64bit
argument_list|()
specifier|const
block|{
return|return
name|IsFP64bit
return|;
block|}
name|bool
name|isNotFP64bit
argument_list|()
specifier|const
block|{
return|return
operator|!
name|IsFP64bit
return|;
block|}
name|bool
name|isGP64bit
argument_list|()
specifier|const
block|{
return|return
name|IsGP64bit
return|;
block|}
name|bool
name|isGP32bit
argument_list|()
specifier|const
block|{
return|return
operator|!
name|IsGP64bit
return|;
block|}
name|bool
name|isSingleFloat
argument_list|()
specifier|const
block|{
return|return
name|IsSingleFloat
return|;
block|}
name|bool
name|isNotSingleFloat
argument_list|()
specifier|const
block|{
return|return
operator|!
name|IsSingleFloat
return|;
block|}
name|bool
name|hasVFPU
argument_list|()
specifier|const
block|{
return|return
name|HasVFPU
return|;
block|}
name|bool
name|inMips16Mode
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|OverrideMode
condition|)
block|{
case|case
name|NoOverride
case|:
return|return
name|InMips16Mode
return|;
case|case
name|Mips16Override
case|:
return|return
name|true
return|;
case|case
name|NoMips16Override
case|:
return|return
name|false
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Unexpected mode"
argument_list|)
expr_stmt|;
block|}
name|bool
name|inMips16ModeDefault
argument_list|()
specifier|const
block|{
return|return
name|InMips16Mode
return|;
block|}
name|bool
name|inMips16HardFloat
argument_list|()
specifier|const
block|{
return|return
name|inMips16Mode
argument_list|()
operator|&&
name|InMips16HardFloat
return|;
block|}
name|bool
name|inMicroMipsMode
argument_list|()
specifier|const
block|{
return|return
name|InMicroMipsMode
return|;
block|}
name|bool
name|hasDSP
argument_list|()
specifier|const
block|{
return|return
name|HasDSP
return|;
block|}
name|bool
name|hasDSPR2
argument_list|()
specifier|const
block|{
return|return
name|HasDSPR2
return|;
block|}
name|bool
name|hasMSA
argument_list|()
specifier|const
block|{
return|return
name|HasMSA
return|;
block|}
name|bool
name|isLinux
argument_list|()
specifier|const
block|{
return|return
name|IsLinux
return|;
block|}
name|bool
name|useSmallSection
argument_list|()
specifier|const
block|{
return|return
name|UseSmallSection
return|;
block|}
name|bool
name|hasStandardEncoding
argument_list|()
specifier|const
block|{
return|return
operator|!
name|inMips16Mode
argument_list|()
return|;
block|}
name|bool
name|mipsSEUsesSoftFloat
argument_list|()
specifier|const
block|;
name|bool
name|enableLongBranchPass
argument_list|()
specifier|const
block|{
return|return
name|hasStandardEncoding
argument_list|()
operator|||
name|allowMixed16_32
argument_list|()
return|;
block|}
comment|/// Features related to the presence of specific instructions.
name|bool
name|hasSEInReg
argument_list|()
specifier|const
block|{
return|return
name|HasSEInReg
return|;
block|}
name|bool
name|hasCondMov
argument_list|()
specifier|const
block|{
return|return
name|HasCondMov
return|;
block|}
name|bool
name|hasSwap
argument_list|()
specifier|const
block|{
return|return
name|HasSwap
return|;
block|}
name|bool
name|hasBitCount
argument_list|()
specifier|const
block|{
return|return
name|HasBitCount
return|;
block|}
name|bool
name|hasFPIdx
argument_list|()
specifier|const
block|{
return|return
name|HasFPIdx
return|;
block|}
name|bool
name|hasExtractInsert
argument_list|()
specifier|const
block|{
return|return
operator|!
name|inMips16Mode
argument_list|()
operator|&&
name|hasMips32r2
argument_list|()
return|;
block|}
specifier|const
name|InstrItineraryData
operator|&
name|getInstrItineraryData
argument_list|()
specifier|const
block|{
return|return
name|InstrItins
return|;
block|}
name|bool
name|allowMixed16_32
argument_list|()
specifier|const
block|{
return|return
name|inMips16ModeDefault
argument_list|()
operator||
name|AllowMixed16_32
return|;
block|}
name|bool
name|os16
argument_list|()
specifier|const
block|{
return|return
name|Os16
return|;
block|}
block|;
comment|// for now constant islands are on for the whole compilation unit but we only
comment|// really use them if in addition we are in mips16 mode
comment|//
specifier|static
name|bool
name|useConstantIslands
argument_list|()
block|;
name|unsigned
name|stackAlignment
argument_list|()
specifier|const
block|{
return|return
name|hasMips64
argument_list|()
operator|?
literal|16
operator|:
literal|8
return|;
block|}
comment|// Grab MipsRegInfo object
specifier|const
name|MipsReginfo
operator|&
name|getMReginfo
argument_list|()
specifier|const
block|{
return|return
name|MRI
return|;
block|}
comment|// Grab relocation model
name|Reloc
operator|::
name|Model
name|getRelocationModel
argument_list|()
specifier|const
block|{
return|return
name|RM
return|;
block|}
comment|/// \brief Reset the subtarget for the Mips target.
name|void
name|resetSubtarget
argument_list|(
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

