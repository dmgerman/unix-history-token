begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SparcSubtarget.h - Define Subtarget for the SPARC -------*- C++ -*-===//
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
comment|// This file declares the SPARC specific subclass of TargetSubtargetInfo.
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
name|LLVM_LIB_TARGET_SPARC_SPARCSUBTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_SPARC_SPARCSUBTARGET_H
end_define

begin_include
include|#
directive|include
file|"SparcFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"SparcISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"SparcInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGTargetInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetFrameLowering.h"
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
file|"SparcGenSubtargetInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|class
name|SparcSubtarget
range|:
name|public
name|SparcGenSubtargetInfo
block|{
name|Triple
name|TargetTriple
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|bool
name|UseSoftMulDiv
block|;
name|bool
name|IsV9
block|;
name|bool
name|IsLeon
block|;
name|bool
name|V8DeprecatedInsts
block|;
name|bool
name|IsVIS
block|,
name|IsVIS2
block|,
name|IsVIS3
block|;
name|bool
name|Is64Bit
block|;
name|bool
name|HasHardQuad
block|;
name|bool
name|UsePopc
block|;
name|bool
name|UseSoftFloat
block|;
comment|// LEON features
name|bool
name|HasUmacSmac
block|;
name|bool
name|HasLeonCasa
block|;
name|bool
name|InsertNOPLoad
block|;
name|bool
name|FixFSMULD
block|;
name|bool
name|ReplaceFMULS
block|;
name|bool
name|FixAllFDIVSQRT
block|;
name|bool
name|DetectRoundChange
block|;
name|bool
name|PerformSDIVReplace
block|;
name|SparcInstrInfo
name|InstrInfo
block|;
name|SparcTargetLowering
name|TLInfo
block|;
name|SelectionDAGTargetInfo
name|TSInfo
block|;
name|SparcFrameLowering
name|FrameLowering
block|;
name|public
operator|:
name|SparcSubtarget
argument_list|(
argument|const Triple&TT
argument_list|,
argument|const std::string&CPU
argument_list|,
argument|const std::string&FS
argument_list|,
argument|const TargetMachine&TM
argument_list|,
argument|bool is64bit
argument_list|)
block|;
specifier|const
name|SparcInstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|InstrInfo
return|;
block|}
specifier|const
name|TargetFrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|FrameLowering
return|;
block|}
specifier|const
name|SparcRegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|InstrInfo
operator|.
name|getRegisterInfo
argument_list|()
return|;
block|}
specifier|const
name|SparcTargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|TLInfo
return|;
block|}
specifier|const
name|SelectionDAGTargetInfo
operator|*
name|getSelectionDAGInfo
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|TSInfo
return|;
block|}
name|bool
name|enableMachineScheduler
argument_list|()
specifier|const
name|override
block|;
name|bool
name|useSoftMulDiv
argument_list|()
specifier|const
block|{
return|return
name|UseSoftMulDiv
return|;
block|}
name|bool
name|isV9
argument_list|()
specifier|const
block|{
return|return
name|IsV9
return|;
block|}
name|bool
name|isLeon
argument_list|()
specifier|const
block|{
return|return
name|IsLeon
return|;
block|}
name|bool
name|isVIS
argument_list|()
specifier|const
block|{
return|return
name|IsVIS
return|;
block|}
name|bool
name|isVIS2
argument_list|()
specifier|const
block|{
return|return
name|IsVIS2
return|;
block|}
name|bool
name|isVIS3
argument_list|()
specifier|const
block|{
return|return
name|IsVIS3
return|;
block|}
name|bool
name|useDeprecatedV8Instructions
argument_list|()
specifier|const
block|{
return|return
name|V8DeprecatedInsts
return|;
block|}
name|bool
name|hasHardQuad
argument_list|()
specifier|const
block|{
return|return
name|HasHardQuad
return|;
block|}
name|bool
name|usePopc
argument_list|()
specifier|const
block|{
return|return
name|UsePopc
return|;
block|}
name|bool
name|useSoftFloat
argument_list|()
specifier|const
block|{
return|return
name|UseSoftFloat
return|;
block|}
comment|// Leon options
name|bool
name|hasUmacSmac
argument_list|()
specifier|const
block|{
return|return
name|HasUmacSmac
return|;
block|}
name|bool
name|performSDIVReplace
argument_list|()
specifier|const
block|{
return|return
name|PerformSDIVReplace
return|;
block|}
name|bool
name|hasLeonCasa
argument_list|()
specifier|const
block|{
return|return
name|HasLeonCasa
return|;
block|}
name|bool
name|insertNOPLoad
argument_list|()
specifier|const
block|{
return|return
name|InsertNOPLoad
return|;
block|}
name|bool
name|fixFSMULD
argument_list|()
specifier|const
block|{
return|return
name|FixFSMULD
return|;
block|}
name|bool
name|replaceFMULS
argument_list|()
specifier|const
block|{
return|return
name|ReplaceFMULS
return|;
block|}
name|bool
name|fixAllFDIVSQRT
argument_list|()
specifier|const
block|{
return|return
name|FixAllFDIVSQRT
return|;
block|}
name|bool
name|detectRoundChange
argument_list|()
specifier|const
block|{
return|return
name|DetectRoundChange
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
name|SparcSubtarget
operator|&
name|initializeSubtargetDependencies
argument_list|(
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|)
block|;
name|bool
name|is64Bit
argument_list|()
specifier|const
block|{
return|return
name|Is64Bit
return|;
block|}
comment|/// The 64-bit ABI uses biased stack and frame pointers, so the stack frame
comment|/// of the current function is the area from [%sp+BIAS] to [%fp+BIAS].
name|int64_t
name|getStackPointerBias
argument_list|()
specifier|const
block|{
return|return
name|is64Bit
argument_list|()
operator|?
literal|2047
operator|:
literal|0
return|;
block|}
comment|/// Given a actual stack size as determined by FrameInfo, this function
comment|/// returns adjusted framesize which includes space for register window
comment|/// spills and arguments.
name|int
name|getAdjustedFrameSize
argument_list|(
argument|int stackSize
argument_list|)
specifier|const
block|;
name|bool
name|isTargetLinux
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|isOSLinux
argument_list|()
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

