begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HexagonSubtarget.h - Define Subtarget for the Hexagon ---*- C++ -*-===//
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
comment|// This file declares the Hexagon specific subclass of TargetSubtarget.
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
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONSUBTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONSUBTARGET_H
end_define

begin_include
include|#
directive|include
file|"HexagonFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"HexagonISelLowering.h"
end_include

begin_include
include|#
directive|include
file|"HexagonInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"HexagonSelectionDAGInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
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
file|"HexagonGenSubtargetInfo.inc"
end_include

begin_define
define|#
directive|define
name|Hexagon_SMALL_DATA_THRESHOLD
value|8
end_define

begin_define
define|#
directive|define
name|Hexagon_SLOTS
value|4
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|HexagonSubtarget
range|:
name|public
name|HexagonGenSubtargetInfo
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|bool
name|UseMemOps
block|;
name|bool
name|ModeIEEERndNear
block|;
name|public
operator|:
expr|enum
name|HexagonArchEnum
block|{
name|V1
block|,
name|V2
block|,
name|V3
block|,
name|V4
block|,
name|V5
block|}
block|;
name|HexagonArchEnum
name|HexagonArchVersion
block|;
name|private
operator|:
name|std
operator|::
name|string
name|CPUString
block|;
specifier|const
name|DataLayout
name|DL
block|;
comment|// Calculates type size& alignment.
name|HexagonInstrInfo
name|InstrInfo
block|;
name|HexagonTargetLowering
name|TLInfo
block|;
name|HexagonSelectionDAGInfo
name|TSInfo
block|;
name|HexagonFrameLowering
name|FrameLowering
block|;
name|InstrItineraryData
name|InstrItins
block|;
name|public
operator|:
name|HexagonSubtarget
argument_list|(
argument|StringRef TT
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetMachine&TM
argument_list|)
block|;
comment|/// getInstrItins - Return the instruction itineraries based on subtarget
comment|/// selection.
specifier|const
name|InstrItineraryData
operator|*
name|getInstrItineraryData
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|InstrItins
return|;
block|}
specifier|const
name|HexagonInstrInfo
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
name|HexagonRegisterInfo
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
name|HexagonTargetLowering
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
name|HexagonFrameLowering
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
name|HexagonSelectionDAGInfo
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
name|HexagonSubtarget
operator|&
name|initializeSubtargetDependencies
argument_list|(
argument|StringRef CPU
argument_list|,
argument|StringRef FS
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
name|hasV2TOps
argument_list|()
specifier|const
block|{
return|return
name|HexagonArchVersion
operator|>=
name|V2
return|;
block|}
name|bool
name|hasV2TOpsOnly
argument_list|()
specifier|const
block|{
return|return
name|HexagonArchVersion
operator|==
name|V2
return|;
block|}
name|bool
name|hasV3TOps
argument_list|()
specifier|const
block|{
return|return
name|HexagonArchVersion
operator|>=
name|V3
return|;
block|}
name|bool
name|hasV3TOpsOnly
argument_list|()
specifier|const
block|{
return|return
name|HexagonArchVersion
operator|==
name|V3
return|;
block|}
name|bool
name|hasV4TOps
argument_list|()
specifier|const
block|{
return|return
name|HexagonArchVersion
operator|>=
name|V4
return|;
block|}
name|bool
name|hasV4TOpsOnly
argument_list|()
specifier|const
block|{
return|return
name|HexagonArchVersion
operator|==
name|V4
return|;
block|}
name|bool
name|useMemOps
argument_list|()
specifier|const
block|{
return|return
name|HexagonArchVersion
operator|>=
name|V4
operator|&&
name|UseMemOps
return|;
block|}
name|bool
name|hasV5TOps
argument_list|()
specifier|const
block|{
return|return
name|HexagonArchVersion
operator|>=
name|V5
return|;
block|}
name|bool
name|hasV5TOpsOnly
argument_list|()
specifier|const
block|{
return|return
name|HexagonArchVersion
operator|==
name|V5
return|;
block|}
name|bool
name|modeIEEERndNear
argument_list|()
specifier|const
block|{
return|return
name|ModeIEEERndNear
return|;
block|}
name|bool
name|isSubtargetV2
argument_list|()
specifier|const
block|{
return|return
name|HexagonArchVersion
operator|==
name|V2
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
comment|// Threshold for small data section
name|unsigned
name|getSmallDataThreshold
argument_list|()
specifier|const
block|{
return|return
name|Hexagon_SMALL_DATA_THRESHOLD
return|;
block|}
specifier|const
name|HexagonArchEnum
operator|&
name|getHexagonArchVersion
argument_list|()
specifier|const
block|{
return|return
name|HexagonArchVersion
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

