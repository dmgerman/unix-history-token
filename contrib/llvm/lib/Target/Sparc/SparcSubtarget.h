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
file|"SparcInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"SparcISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"SparcSelectionDAGInfo.h"
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
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|bool
name|IsV9
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
specifier|const
name|DataLayout
name|DL
block|;
comment|// Calculates type size& alignment
name|SparcInstrInfo
name|InstrInfo
block|;
name|SparcTargetLowering
name|TLInfo
block|;
name|SparcSelectionDAGInfo
name|TSInfo
block|;
name|SparcFrameLowering
name|FrameLowering
block|;
name|public
operator|:
name|SparcSubtarget
argument_list|(
argument|const std::string&TT
argument_list|,
argument|const std::string&CPU
argument_list|,
argument|const std::string&FS
argument_list|,
argument|TargetMachine&TM
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
name|SparcSelectionDAGInfo
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
specifier|const
name|DataLayout
operator|*
name|getDataLayout
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|DL
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
block|;  }
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

end_unit

