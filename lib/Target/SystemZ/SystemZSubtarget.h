begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemZSubtarget.h - SystemZ subtarget information -----*- C++ -*--===//
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
comment|// This file declares the SystemZ specific subclass of TargetSubtargetInfo.
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
name|LLVM_LIB_TARGET_SYSTEMZ_SYSTEMZSUBTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_SYSTEMZ_SYSTEMZSUBTARGET_H
end_define

begin_include
include|#
directive|include
file|"SystemZFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"SystemZISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"SystemZInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"SystemZRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"SystemZSelectionDAGInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
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
file|"SystemZGenSubtargetInfo.inc"
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
name|SystemZSubtarget
range|:
name|public
name|SystemZGenSubtargetInfo
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|protected
operator|:
name|bool
name|HasDistinctOps
block|;
name|bool
name|HasLoadStoreOnCond
block|;
name|bool
name|HasHighWord
block|;
name|bool
name|HasFPExtension
block|;
name|bool
name|HasPopulationCount
block|;
name|bool
name|HasMessageSecurityAssist4
block|;
name|bool
name|HasFastSerialization
block|;
name|bool
name|HasInterlockedAccess1
block|;
name|bool
name|HasMiscellaneousExtensions
block|;
name|bool
name|HasExecutionHint
block|;
name|bool
name|HasLoadAndTrap
block|;
name|bool
name|HasTransactionalExecution
block|;
name|bool
name|HasProcessorAssist
block|;
name|bool
name|HasDFPZonedConversion
block|;
name|bool
name|HasVector
block|;
name|bool
name|HasLoadStoreOnCond2
block|;
name|bool
name|HasLoadAndZeroRightmostByte
block|;
name|bool
name|HasMessageSecurityAssist5
block|;
name|bool
name|HasDFPPackedConversion
block|;
name|private
operator|:
name|Triple
name|TargetTriple
block|;
name|SystemZInstrInfo
name|InstrInfo
block|;
name|SystemZTargetLowering
name|TLInfo
block|;
name|SystemZSelectionDAGInfo
name|TSInfo
block|;
name|SystemZFrameLowering
name|FrameLowering
block|;
name|SystemZSubtarget
operator|&
name|initializeSubtargetDependencies
argument_list|(
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|)
block|;
name|public
operator|:
name|SystemZSubtarget
argument_list|(
specifier|const
name|Triple
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
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
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
name|SystemZInstrInfo
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
name|SystemZRegisterInfo
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
name|SystemZTargetLowering
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
comment|// This is important for reducing register pressure in vector code.
name|bool
name|useAA
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
comment|// Always enable the early if-conversion pass.
name|bool
name|enableEarlyIfConversion
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
comment|// Automatically generated by tblgen.
name|void
name|ParseSubtargetFeatures
argument_list|(
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|)
block|;
comment|// Return true if the target has the distinct-operands facility.
name|bool
name|hasDistinctOps
argument_list|()
specifier|const
block|{
return|return
name|HasDistinctOps
return|;
block|}
comment|// Return true if the target has the load/store-on-condition facility.
name|bool
name|hasLoadStoreOnCond
argument_list|()
specifier|const
block|{
return|return
name|HasLoadStoreOnCond
return|;
block|}
comment|// Return true if the target has the load/store-on-condition facility 2.
name|bool
name|hasLoadStoreOnCond2
argument_list|()
specifier|const
block|{
return|return
name|HasLoadStoreOnCond2
return|;
block|}
comment|// Return true if the target has the high-word facility.
name|bool
name|hasHighWord
argument_list|()
specifier|const
block|{
return|return
name|HasHighWord
return|;
block|}
comment|// Return true if the target has the floating-point extension facility.
name|bool
name|hasFPExtension
argument_list|()
specifier|const
block|{
return|return
name|HasFPExtension
return|;
block|}
comment|// Return true if the target has the population-count facility.
name|bool
name|hasPopulationCount
argument_list|()
specifier|const
block|{
return|return
name|HasPopulationCount
return|;
block|}
comment|// Return true if the target has the message-security-assist
comment|// extension facility 4.
name|bool
name|hasMessageSecurityAssist4
argument_list|()
specifier|const
block|{
return|return
name|HasMessageSecurityAssist4
return|;
block|}
comment|// Return true if the target has the fast-serialization facility.
name|bool
name|hasFastSerialization
argument_list|()
specifier|const
block|{
return|return
name|HasFastSerialization
return|;
block|}
comment|// Return true if the target has interlocked-access facility 1.
name|bool
name|hasInterlockedAccess1
argument_list|()
specifier|const
block|{
return|return
name|HasInterlockedAccess1
return|;
block|}
comment|// Return true if the target has the miscellaneous-extensions facility.
name|bool
name|hasMiscellaneousExtensions
argument_list|()
specifier|const
block|{
return|return
name|HasMiscellaneousExtensions
return|;
block|}
comment|// Return true if the target has the execution-hint facility.
name|bool
name|hasExecutionHint
argument_list|()
specifier|const
block|{
return|return
name|HasExecutionHint
return|;
block|}
comment|// Return true if the target has the load-and-trap facility.
name|bool
name|hasLoadAndTrap
argument_list|()
specifier|const
block|{
return|return
name|HasLoadAndTrap
return|;
block|}
comment|// Return true if the target has the transactional-execution facility.
name|bool
name|hasTransactionalExecution
argument_list|()
specifier|const
block|{
return|return
name|HasTransactionalExecution
return|;
block|}
comment|// Return true if the target has the processor-assist facility.
name|bool
name|hasProcessorAssist
argument_list|()
specifier|const
block|{
return|return
name|HasProcessorAssist
return|;
block|}
comment|// Return true if the target has the DFP zoned-conversion facility.
name|bool
name|hasDFPZonedConversion
argument_list|()
specifier|const
block|{
return|return
name|HasDFPZonedConversion
return|;
block|}
comment|// Return true if the target has the load-and-zero-rightmost-byte facility.
name|bool
name|hasLoadAndZeroRightmostByte
argument_list|()
specifier|const
block|{
return|return
name|HasLoadAndZeroRightmostByte
return|;
block|}
comment|// Return true if the target has the message-security-assist
comment|// extension facility 5.
name|bool
name|hasMessageSecurityAssist5
argument_list|()
specifier|const
block|{
return|return
name|HasMessageSecurityAssist5
return|;
block|}
comment|// Return true if the target has the DFP packed-conversion facility.
name|bool
name|hasDFPPackedConversion
argument_list|()
specifier|const
block|{
return|return
name|HasDFPPackedConversion
return|;
block|}
comment|// Return true if the target has the vector facility.
name|bool
name|hasVector
argument_list|()
specifier|const
block|{
return|return
name|HasVector
return|;
block|}
comment|// Return true if GV can be accessed using LARL for reloc model RM
comment|// and code model CM.
name|bool
name|isPC32DBLSymbol
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|CodeModel::Model CM
argument_list|)
specifier|const
block|;
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
expr|}
block|; }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

