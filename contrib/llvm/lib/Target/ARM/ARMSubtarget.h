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
comment|// This file declares the ARM specific subclass of TargetSubtargetInfo.
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
file|"MCTargetDesc/ARMMCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetSubtargetInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrItineraries.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
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
file|"ARMGenSubtargetInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|ARMSubtarget
range|:
name|public
name|ARMGenSubtargetInfo
block|{
name|protected
operator|:
expr|enum
name|ARMProcFamilyEnum
block|{
name|Others
block|,
name|CortexA8
block|,
name|CortexA9
block|}
block|;
comment|/// ARMProcFamily - ARM processor family: Cortex-A8, Cortex-A9, and others.
name|ARMProcFamilyEnum
name|ARMProcFamily
block|;
comment|/// HasV4TOps, HasV5TOps, HasV5TEOps, HasV6Ops, HasV6T2Ops, HasV7Ops -
comment|/// Specify whether target support specific ARM ISA variants.
name|bool
name|HasV4TOps
block|;
name|bool
name|HasV5TOps
block|;
name|bool
name|HasV5TEOps
block|;
name|bool
name|HasV6Ops
block|;
name|bool
name|HasV6T2Ops
block|;
name|bool
name|HasV7Ops
block|;
comment|/// HasVFPv2, HasVFPv3, HasNEON - Specify what floating point ISAs are
comment|/// supported.
name|bool
name|HasVFPv2
block|;
name|bool
name|HasVFPv3
block|;
name|bool
name|HasNEON
block|;
comment|/// UseNEONForSinglePrecisionFP - if the NEONFP attribute has been
comment|/// specified. Use the method useNEONForSinglePrecisionFP() to
comment|/// determine if NEON should actually be used.
name|bool
name|UseNEONForSinglePrecisionFP
block|;
comment|/// SlowFPVMLx - If the VFP2 / NEON instructions are available, indicates
comment|/// whether the FP VML[AS] instructions are slow (if so, don't use them).
name|bool
name|SlowFPVMLx
block|;
comment|/// HasVMLxForwarding - If true, NEON has special multiplier accumulator
comment|/// forwarding to allow mul + mla being issued back to back.
name|bool
name|HasVMLxForwarding
block|;
comment|/// SlowFPBrcc - True if floating point compare + branch is slow.
name|bool
name|SlowFPBrcc
block|;
comment|/// InThumbMode - True if compiling for Thumb, false for ARM.
name|bool
name|InThumbMode
block|;
comment|/// HasThumb2 - True if Thumb2 instructions are supported.
name|bool
name|HasThumb2
block|;
comment|/// NoARM - True if subtarget does not support ARM mode execution.
name|bool
name|NoARM
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
comment|/// HasD16 - True if subtarget is limited to 16 double precision
comment|/// FP registers for VFPv3.
name|bool
name|HasD16
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
comment|/// HasDataBarrier - True if the subtarget supports DMB / DSB data barrier
comment|/// instructions.
name|bool
name|HasDataBarrier
block|;
comment|/// Pref32BitThumb - If true, codegen would prefer 32-bit Thumb instructions
comment|/// over 16-bit ones.
name|bool
name|Pref32BitThumb
block|;
comment|/// AvoidCPSRPartialUpdate - If true, codegen would avoid using instructions
comment|/// that partially update CPSR and add false dependency on the previous
comment|/// CPSR setting instruction.
name|bool
name|AvoidCPSRPartialUpdate
block|;
comment|/// HasMPExtension - True if the subtarget supports Multiprocessing
comment|/// extension (ARMv7 only).
name|bool
name|HasMPExtension
block|;
comment|/// FPOnlySP - If true, the floating point unit only supports single
comment|/// precision.
name|bool
name|FPOnlySP
block|;
comment|/// AllowsUnalignedMem - If true, the subtarget allows unaligned memory
comment|/// accesses for some types.  For details, see
comment|/// ARMTargetLowering::allowsUnalignedMemoryAccesses().
name|bool
name|AllowsUnalignedMem
block|;
comment|/// Thumb2DSP - If true, the subtarget supports the v7 DSP (saturating arith
comment|/// and such) instructions in Thumb2 code.
name|bool
name|Thumb2DSP
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
comment|/// TargetTriple - What processor and OS we're targeting.
name|Triple
name|TargetTriple
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
specifier|const
name|std
operator|::
name|string
operator|&
name|TT
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|CPU
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|FS
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
name|void
name|ParseSubtargetFeatures
argument_list|(
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|)
block|;
name|void
name|computeIssueWidth
argument_list|()
block|;
name|bool
name|hasV4TOps
argument_list|()
specifier|const
block|{
return|return
name|HasV4TOps
return|;
block|}
name|bool
name|hasV5TOps
argument_list|()
specifier|const
block|{
return|return
name|HasV5TOps
return|;
block|}
name|bool
name|hasV5TEOps
argument_list|()
specifier|const
block|{
return|return
name|HasV5TEOps
return|;
block|}
name|bool
name|hasV6Ops
argument_list|()
specifier|const
block|{
return|return
name|HasV6Ops
return|;
block|}
name|bool
name|hasV6T2Ops
argument_list|()
specifier|const
block|{
return|return
name|HasV6T2Ops
return|;
block|}
name|bool
name|hasV7Ops
argument_list|()
specifier|const
block|{
return|return
name|HasV7Ops
return|;
block|}
name|bool
name|isCortexA8
argument_list|()
specifier|const
block|{
return|return
name|ARMProcFamily
operator|==
name|CortexA8
return|;
block|}
name|bool
name|isCortexA9
argument_list|()
specifier|const
block|{
return|return
name|ARMProcFamily
operator|==
name|CortexA9
return|;
block|}
name|bool
name|hasARMOps
argument_list|()
specifier|const
block|{
return|return
operator|!
name|NoARM
return|;
block|}
name|bool
name|hasVFP2
argument_list|()
specifier|const
block|{
return|return
name|HasVFPv2
return|;
block|}
name|bool
name|hasVFP3
argument_list|()
specifier|const
block|{
return|return
name|HasVFPv3
return|;
block|}
name|bool
name|hasNEON
argument_list|()
specifier|const
block|{
return|return
name|HasNEON
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
name|hasDataBarrier
argument_list|()
specifier|const
block|{
return|return
name|HasDataBarrier
return|;
block|}
name|bool
name|useFPVMLx
argument_list|()
specifier|const
block|{
return|return
operator|!
name|SlowFPVMLx
return|;
block|}
name|bool
name|hasVMLxForwarding
argument_list|()
specifier|const
block|{
return|return
name|HasVMLxForwarding
return|;
block|}
name|bool
name|isFPBrccSlow
argument_list|()
specifier|const
block|{
return|return
name|SlowFPBrcc
return|;
block|}
name|bool
name|isFPOnlySP
argument_list|()
specifier|const
block|{
return|return
name|FPOnlySP
return|;
block|}
name|bool
name|prefers32BitThumb
argument_list|()
specifier|const
block|{
return|return
name|Pref32BitThumb
return|;
block|}
name|bool
name|avoidCPSRPartialUpdate
argument_list|()
specifier|const
block|{
return|return
name|AvoidCPSRPartialUpdate
return|;
block|}
name|bool
name|hasMPExtension
argument_list|()
specifier|const
block|{
return|return
name|HasMPExtension
return|;
block|}
name|bool
name|hasThumb2DSP
argument_list|()
specifier|const
block|{
return|return
name|Thumb2DSP
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
name|hasD16
argument_list|()
specifier|const
block|{
return|return
name|HasD16
return|;
block|}
specifier|const
name|Triple
operator|&
name|getTargetTriple
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
return|;
block|}
name|bool
name|isTargetDarwin
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|isOSDarwin
argument_list|()
return|;
block|}
name|bool
name|isTargetELF
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isTargetDarwin
argument_list|()
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
name|InThumbMode
return|;
block|}
name|bool
name|isThumb1Only
argument_list|()
specifier|const
block|{
return|return
name|InThumbMode
operator|&&
operator|!
name|HasThumb2
return|;
block|}
name|bool
name|isThumb2
argument_list|()
specifier|const
block|{
return|return
name|InThumbMode
operator|&&
name|HasThumb2
return|;
block|}
name|bool
name|hasThumb2
argument_list|()
specifier|const
block|{
return|return
name|HasThumb2
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
name|bool
name|allowsUnalignedMem
argument_list|()
specifier|const
block|{
return|return
name|AllowsUnalignedMem
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
name|unsigned
name|getMispredictionPenalty
argument_list|()
specifier|const
block|;
comment|/// enablePostRAScheduler - True at 'More' optimization.
name|bool
name|enablePostRAScheduler
argument_list|(
argument|CodeGenOpt::Level OptLevel
argument_list|,
argument|TargetSubtargetInfo::AntiDepBreakMode& Mode
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

