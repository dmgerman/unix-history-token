begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SubtargetEmitter.h - Generate subtarget enumerations -----*- C++ -*-===//
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
comment|// This tablegen backend emits subtarget enumerations.
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
name|SUBTARGET_EMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_EMITTER_H
end_define

begin_include
include|#
directive|include
file|"TableGenBackend.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrItineraries.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<map>
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
name|SubtargetEmitter
range|:
name|public
name|TableGenBackend
block|{
name|RecordKeeper
operator|&
name|Records
block|;
name|std
operator|::
name|string
name|Target
block|;
name|bool
name|HasItineraries
block|;
name|void
name|Enumeration
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const char *ClassName
argument_list|,
argument|bool isBits
argument_list|)
block|;
name|void
name|FeatureKeyValues
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|void
name|CPUKeyValues
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|unsigned
name|CollectAllItinClasses
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
argument_list|,
name|unsigned
operator|>
operator|&
name|ItinClassesMap
argument_list|)
block|;
name|void
name|FormItineraryStageString
argument_list|(
name|Record
operator|*
name|ItinData
argument_list|,
name|std
operator|::
name|string
operator|&
name|ItinString
argument_list|,
name|unsigned
operator|&
name|NStages
argument_list|)
block|;
name|void
name|FormItineraryOperandCycleString
argument_list|(
name|Record
operator|*
name|ItinData
argument_list|,
name|std
operator|::
name|string
operator|&
name|ItinString
argument_list|,
name|unsigned
operator|&
name|NOperandCycles
argument_list|)
block|;
name|void
name|EmitStageAndOperandCycleData
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|unsigned NItinClasses
argument_list|,
argument|std::map<std::string
argument_list|,
argument|unsigned>&ItinClassesMap
argument_list|,
argument|std::vector<std::vector<InstrItinerary>>&ProcList
argument_list|)
block|;
name|void
name|EmitProcessorData
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|vector
operator|<
name|InstrItinerary
operator|>
expr|>
operator|&
name|ProcList
argument_list|)
block|;
name|void
name|EmitProcessorLookup
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|void
name|EmitData
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|void
name|ParseFeaturesFunction
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|public
operator|:
name|SubtargetEmitter
argument_list|(
name|RecordKeeper
operator|&
name|R
argument_list|)
operator|:
name|Records
argument_list|(
name|R
argument_list|)
block|,
name|HasItineraries
argument_list|(
argument|false
argument_list|)
block|{}
comment|// run - Output the subtarget enumerations, returning true on failure.
name|void
name|run
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|)
block|;  }
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

