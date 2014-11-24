begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- AArch64Subtarget.h - Define Subtarget for the AArch64 -*- C++ -*--===//
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
comment|// This file declares the AArch64 specific subclass of TargetSubtarget.
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
name|AArch64SUBTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|AArch64SUBTARGET_H
end_define

begin_include
include|#
directive|include
file|"AArch64InstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"AArch64FrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"AArch64ISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"AArch64RegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"AArch64SelectionDAGInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
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
file|"AArch64GenSubtargetInfo.inc"
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
name|AArch64Subtarget
range|:
name|public
name|AArch64GenSubtargetInfo
block|{
name|protected
operator|:
expr|enum
name|ARMProcFamilyEnum
block|{
name|Others
block|,
name|CortexA53
block|,
name|CortexA57
block|,
name|Cyclone
block|}
block|;
comment|/// ARMProcFamily - ARM processor family: Cortex-A53, Cortex-A57, and others.
name|ARMProcFamilyEnum
name|ARMProcFamily
block|;
name|bool
name|HasFPARMv8
block|;
name|bool
name|HasNEON
block|;
name|bool
name|HasCrypto
block|;
name|bool
name|HasCRC
block|;
comment|// HasZeroCycleRegMove - Has zero-cycle register mov instructions.
name|bool
name|HasZeroCycleRegMove
block|;
comment|// HasZeroCycleZeroing - Has zero-cycle zeroing instructions.
name|bool
name|HasZeroCycleZeroing
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
specifier|const
name|DataLayout
name|DL
block|;
name|AArch64FrameLowering
name|FrameLowering
block|;
name|AArch64InstrInfo
name|InstrInfo
block|;
name|AArch64SelectionDAGInfo
name|TSInfo
block|;
name|AArch64TargetLowering
name|TLInfo
block|;
name|private
operator|:
comment|/// initializeSubtargetDependencies - Initializes using CPUString and the
comment|/// passed in feature string so that we can use initializer lists for
comment|/// subtarget initialization.
name|AArch64Subtarget
operator|&
name|initializeSubtargetDependencies
argument_list|(
argument|StringRef FS
argument_list|)
block|;
name|public
operator|:
comment|/// This constructor initializes the data members to match that
comment|/// of the specified triple.
name|AArch64Subtarget
argument_list|(
argument|const std::string&TT
argument_list|,
argument|const std::string&CPU
argument_list|,
argument|const std::string&FS
argument_list|,
argument|TargetMachine&TM
argument_list|,
argument|bool LittleEndian
argument_list|)
block|;
specifier|const
name|AArch64SelectionDAGInfo
operator|*
name|getSelectionDAGInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|TSInfo
return|;
block|}
specifier|const
name|AArch64FrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
block|{
return|return
operator|&
name|FrameLowering
return|;
block|}
specifier|const
name|AArch64TargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
operator|&
name|TLInfo
return|;
block|}
specifier|const
name|AArch64InstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
block|{
return|return
operator|&
name|InstrInfo
return|;
block|}
specifier|const
name|DataLayout
operator|*
name|getDataLayout
argument_list|()
specifier|const
block|{
return|return
operator|&
name|DL
return|;
block|}
name|bool
name|enableMachineScheduler
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|hasZeroCycleRegMove
argument_list|()
specifier|const
block|{
return|return
name|HasZeroCycleRegMove
return|;
block|}
name|bool
name|hasZeroCycleZeroing
argument_list|()
specifier|const
block|{
return|return
name|HasZeroCycleZeroing
return|;
block|}
name|bool
name|hasFPARMv8
argument_list|()
specifier|const
block|{
return|return
name|HasFPARMv8
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
name|hasCrypto
argument_list|()
specifier|const
block|{
return|return
name|HasCrypto
return|;
block|}
name|bool
name|hasCRC
argument_list|()
specifier|const
block|{
return|return
name|HasCRC
return|;
block|}
name|bool
name|isLittleEndian
argument_list|()
specifier|const
block|{
return|return
name|DL
operator|.
name|isLittleEndian
argument_list|()
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
name|TargetTriple
operator|.
name|isOSBinFormatELF
argument_list|()
return|;
block|}
name|bool
name|isTargetMachO
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
operator|.
name|isOSBinFormatMachO
argument_list|()
return|;
block|}
name|bool
name|isCyclone
argument_list|()
specifier|const
block|{
return|return
name|CPUString
operator|==
literal|"cyclone"
return|;
block|}
comment|/// getMaxInlineSizeThreshold - Returns the maximum memset / memcpy size
comment|/// that still makes it profitable to inline the call.
name|unsigned
name|getMaxInlineSizeThreshold
argument_list|()
specifier|const
block|{
return|return
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
comment|/// ClassifyGlobalReference - Find the target operand flags that describe
comment|/// how a global value should be referenced for the current subtarget.
name|unsigned
name|char
name|ClassifyGlobalReference
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
comment|/// This function returns the name of a function which has an interface
comment|/// like the non-standard bzero function, if such a function exists on
comment|/// the current subtarget and it is considered prefereable over
comment|/// memset with zero passed as the second argument. Otherwise it
comment|/// returns null.
specifier|const
name|char
operator|*
name|getBZeroEntry
argument_list|()
specifier|const
block|;
name|void
name|overrideSchedPolicy
argument_list|(
argument|MachineSchedPolicy&Policy
argument_list|,
argument|MachineInstr *begin
argument_list|,
argument|MachineInstr *end
argument_list|,
argument|unsigned NumRegionInstrs
argument_list|)
specifier|const
name|override
block|;
name|bool
name|enableEarlyIfConversion
argument_list|()
specifier|const
name|override
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
comment|// AArch64SUBTARGET_H
end_comment

end_unit

