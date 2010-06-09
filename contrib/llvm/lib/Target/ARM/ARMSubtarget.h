begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=====---- ARMSubtarget.h - Define Subtarget for the ARM -----*- C++ -*--====//
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
comment|// This file declares the ARM specific subclass of TargetSubtarget.
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
name|ARMSUBTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|ARMSUBTARGET_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrItineraries.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"ARMBaseRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
name|class
name|ARMSubtarget
range|:
name|public
name|TargetSubtarget
block|{
name|protected
operator|:
expr|enum
name|ARMArchEnum
block|{
name|V4
block|,
name|V4T
block|,
name|V5T
block|,
name|V5TE
block|,
name|V6
block|,
name|V6T2
block|,
name|V7A
block|,
name|V7M
block|}
block|;    enum
name|ARMFPEnum
block|{
name|None
block|,
name|VFPv2
block|,
name|VFPv3
block|,
name|NEON
block|}
block|;    enum
name|ThumbTypeEnum
block|{
name|Thumb1
block|,
name|Thumb2
block|}
block|;
comment|/// ARMArchVersion - ARM architecture version: V4, V4T (base), V5T, V5TE,
comment|/// V6, V6T2, V7A, V7M.
name|ARMArchEnum
name|ARMArchVersion
block|;
comment|/// ARMFPUType - Floating Point Unit type.
name|ARMFPEnum
name|ARMFPUType
block|;
comment|/// UseNEONForSinglePrecisionFP - if the NEONFP attribute has been
comment|/// specified. Use the method useNEONForSinglePrecisionFP() to
comment|/// determine if NEON should actually be used.
name|bool
name|UseNEONForSinglePrecisionFP
block|;
comment|/// SlowVMLx - If the VFP2 instructions are available, indicates whether
comment|/// the VML[AS] instructions are slow (if so, don't use them).
name|bool
name|SlowVMLx
block|;
comment|/// IsThumb - True if we are in thumb mode, false if in ARM mode.
name|bool
name|IsThumb
block|;
comment|/// ThumbMode - Indicates supported Thumb version.
name|ThumbTypeEnum
name|ThumbMode
block|;
comment|/// PostRAScheduler - True if using post-register-allocation scheduler.
name|bool
name|PostRAScheduler
block|;
comment|/// IsR9Reserved - True if R9 is a not available as general purpose register.
name|bool
name|IsR9Reserved
block|;
comment|/// UseMovt - True if MOVT / MOVW pairs are used for materialization of 32-bit
comment|/// imms (including global addresses).
name|bool
name|UseMovt
block|;
comment|/// HasFP16 - True if subtarget supports half-precision FP (We support VFP+HF
comment|/// only so far)
name|bool
name|HasFP16
block|;
comment|/// HasHardwareDivide - True if subtarget supports [su]div
name|bool
name|HasHardwareDivide
block|;
comment|/// HasT2ExtractPack - True if subtarget supports thumb2 extract/pack
comment|/// instructions.
name|bool
name|HasT2ExtractPack
block|;
comment|/// stackAlignment - The minimum alignment known to hold of the stack frame on
comment|/// entry to the function and which must be maintained by every function.
name|unsigned
name|stackAlignment
block|;
comment|/// CPUString - String name of used CPU.
name|std
operator|::
name|string
name|CPUString
block|;
comment|/// Selected instruction itineraries (one entry per itinerary class.)
name|InstrItineraryData
name|InstrItins
block|;
name|public
operator|:
expr|enum
block|{
name|isELF
block|,
name|isDarwin
block|}
name|TargetType
block|;    enum
block|{
name|ARM_ABI_APCS
block|,
name|ARM_ABI_AAPCS
comment|// ARM EABI
block|}
name|TargetABI
block|;
comment|/// This constructor initializes the data members to match that
comment|/// of the specified triple.
comment|///
name|ARMSubtarget
argument_list|(
argument|const std::string&TT
argument_list|,
argument|const std::string&FS
argument_list|,
argument|bool isThumb
argument_list|)
block|;
comment|/// getMaxInlineSizeThreshold - Returns the maximum memset / memcpy size
comment|/// that still makes it profitable to inline the call.
name|unsigned
name|getMaxInlineSizeThreshold
argument_list|()
specifier|const
block|{
comment|// FIXME: For now, we don't lower memcpy's to loads / stores for Thumb1.
comment|// Change this once Thumb1 ldmia / stmia support is added.
return|return
name|isThumb1Only
argument_list|()
operator|?
literal|0
operator|:
literal|64
return|;
block|}
comment|/// ParseSubtargetFeatures - Parses features string setting specified
comment|/// subtarget options.  Definition of function is auto generated by tblgen.
name|std
operator|::
name|string
name|ParseSubtargetFeatures
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|FS
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|CPU
argument_list|)
block|;
name|bool
name|hasV4TOps
argument_list|()
specifier|const
block|{
return|return
name|ARMArchVersion
operator|>=
name|V4T
return|;
block|}
name|bool
name|hasV5TOps
argument_list|()
specifier|const
block|{
return|return
name|ARMArchVersion
operator|>=
name|V5T
return|;
block|}
name|bool
name|hasV5TEOps
argument_list|()
specifier|const
block|{
return|return
name|ARMArchVersion
operator|>=
name|V5TE
return|;
block|}
name|bool
name|hasV6Ops
argument_list|()
specifier|const
block|{
return|return
name|ARMArchVersion
operator|>=
name|V6
return|;
block|}
name|bool
name|hasV6T2Ops
argument_list|()
specifier|const
block|{
return|return
name|ARMArchVersion
operator|>=
name|V6T2
return|;
block|}
name|bool
name|hasV7Ops
argument_list|()
specifier|const
block|{
return|return
name|ARMArchVersion
operator|>=
name|V7A
return|;
block|}
name|bool
name|hasVFP2
argument_list|()
specifier|const
block|{
return|return
name|ARMFPUType
operator|>=
name|VFPv2
return|;
block|}
name|bool
name|hasVFP3
argument_list|()
specifier|const
block|{
return|return
name|ARMFPUType
operator|>=
name|VFPv3
return|;
block|}
name|bool
name|hasNEON
argument_list|()
specifier|const
block|{
return|return
name|ARMFPUType
operator|>=
name|NEON
return|;
block|}
name|bool
name|useNEONForSinglePrecisionFP
argument_list|()
specifier|const
block|{
return|return
name|hasNEON
argument_list|()
operator|&&
name|UseNEONForSinglePrecisionFP
return|;
block|}
name|bool
name|hasDivide
argument_list|()
specifier|const
block|{
return|return
name|HasHardwareDivide
return|;
block|}
name|bool
name|hasT2ExtractPack
argument_list|()
specifier|const
block|{
return|return
name|HasT2ExtractPack
return|;
block|}
name|bool
name|useVMLx
argument_list|()
specifier|const
block|{
return|return
name|hasVFP2
argument_list|()
operator|&&
operator|!
name|SlowVMLx
return|;
block|}
name|bool
name|hasFP16
argument_list|()
specifier|const
block|{
return|return
name|HasFP16
return|;
block|}
name|bool
name|isTargetDarwin
argument_list|()
specifier|const
block|{
return|return
name|TargetType
operator|==
name|isDarwin
return|;
block|}
name|bool
name|isTargetELF
argument_list|()
specifier|const
block|{
return|return
name|TargetType
operator|==
name|isELF
return|;
block|}
name|bool
name|isAPCS_ABI
argument_list|()
specifier|const
block|{
return|return
name|TargetABI
operator|==
name|ARM_ABI_APCS
return|;
block|}
name|bool
name|isAAPCS_ABI
argument_list|()
specifier|const
block|{
return|return
name|TargetABI
operator|==
name|ARM_ABI_AAPCS
return|;
block|}
name|bool
name|isThumb
argument_list|()
specifier|const
block|{
return|return
name|IsThumb
return|;
block|}
name|bool
name|isThumb1Only
argument_list|()
specifier|const
block|{
return|return
name|IsThumb
operator|&&
operator|(
name|ThumbMode
operator|==
name|Thumb1
operator|)
return|;
block|}
name|bool
name|isThumb2
argument_list|()
specifier|const
block|{
return|return
name|IsThumb
operator|&&
operator|(
name|ThumbMode
operator|==
name|Thumb2
operator|)
return|;
block|}
name|bool
name|hasThumb2
argument_list|()
specifier|const
block|{
return|return
name|ThumbMode
operator|>=
name|Thumb2
return|;
block|}
name|bool
name|isR9Reserved
argument_list|()
specifier|const
block|{
return|return
name|IsR9Reserved
return|;
block|}
name|bool
name|useMovt
argument_list|()
specifier|const
block|{
return|return
name|UseMovt
operator|&&
name|hasV6T2Ops
argument_list|()
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getCPUString
argument_list|()
specifier|const
block|{
return|return
name|CPUString
return|;
block|}
comment|/// enablePostRAScheduler - True at 'More' optimization.
name|bool
name|enablePostRAScheduler
argument_list|(
argument|CodeGenOpt::Level OptLevel
argument_list|,
argument|TargetSubtarget::AntiDepBreakMode& Mode
argument_list|,
argument|RegClassVector& CriticalPathRCs
argument_list|)
specifier|const
block|;
comment|/// getInstrItins - Return the instruction itineraies based on subtarget
comment|/// selection.
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
comment|/// getStackAlignment - Returns the minimum alignment known to hold of the
comment|/// stack frame on entry to the function and which must be maintained by every
comment|/// function for this subtarget.
name|unsigned
name|getStackAlignment
argument_list|()
specifier|const
block|{
return|return
name|stackAlignment
return|;
block|}
comment|/// GVIsIndirectSymbol - true if the GV will be accessed via an indirect
comment|/// symbol.
name|bool
name|GVIsIndirectSymbol
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|Reloc::Model RelocM
argument_list|)
specifier|const
block|; }
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

begin_comment
comment|// ARMSUBTARGET_H
end_comment

end_unit

