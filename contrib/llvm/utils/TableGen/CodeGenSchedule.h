begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CodeGenSchedule.h - Scheduling Machine Models ------------*- C++ -*-===//
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
comment|// This file defines structures to encapsulate the machine model as decribed in
end_comment

begin_comment
comment|// the target description.
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
name|CODEGEN_SCHEDULE_H
end_ifndef

begin_define
define|#
directive|define
name|CODEGEN_SCHEDULE_H
end_define

begin_include
include|#
directive|include
file|"llvm/TableGen/Record.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CodeGenTarget
decl_stmt|;
comment|// Scheduling class.
comment|//
comment|// Each instruction description will be mapped to a scheduling class. It may be
comment|// an explicitly defined itinerary class, or an inferred class in which case
comment|// ItinClassDef == NULL.
struct|struct
name|CodeGenSchedClass
block|{
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|unsigned
name|Index
decl_stmt|;
name|Record
modifier|*
name|ItinClassDef
decl_stmt|;
name|CodeGenSchedClass
argument_list|()
operator|:
name|Index
argument_list|(
literal|0
argument_list|)
operator|,
name|ItinClassDef
argument_list|(
literal|0
argument_list|)
block|{}
name|CodeGenSchedClass
argument_list|(
name|Record
operator|*
name|rec
argument_list|)
operator|:
name|Index
argument_list|(
literal|0
argument_list|)
operator|,
name|ItinClassDef
argument_list|(
argument|rec
argument_list|)
block|{
name|Name
operator|=
name|rec
operator|->
name|getName
argument_list|()
block|;   }
block|}
struct|;
comment|// Processor model.
comment|//
comment|// ModelName is a unique name used to name an instantiation of MCSchedModel.
comment|//
comment|// ModelDef is NULL for inferred Models. This happens when a processor defines
comment|// an itinerary but no machine model. If the processer defines neither a machine
comment|// model nor itinerary, then ModelDef remains pointing to NoModel. NoModel has
comment|// the special "NoModel" field set to true.
comment|//
comment|// ItinsDef always points to a valid record definition, but may point to the
comment|// default NoItineraries. NoItineraries has an empty list of InstrItinData
comment|// records.
comment|//
comment|// ItinDefList orders this processor's InstrItinData records by SchedClass idx.
struct|struct
name|CodeGenProcModel
block|{
name|std
operator|::
name|string
name|ModelName
expr_stmt|;
name|Record
modifier|*
name|ModelDef
decl_stmt|;
name|Record
modifier|*
name|ItinsDef
decl_stmt|;
comment|// Array of InstrItinData records indexed by CodeGenSchedClass::Index.
comment|// The list is empty if the subtarget has no itineraries.
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
name|ItinDefList
expr_stmt|;
name|CodeGenProcModel
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|,
name|Record
operator|*
name|MDef
argument_list|,
name|Record
operator|*
name|IDef
argument_list|)
operator|:
name|ModelName
argument_list|(
name|Name
argument_list|)
operator|,
name|ModelDef
argument_list|(
name|MDef
argument_list|)
operator|,
name|ItinsDef
argument_list|(
argument|IDef
argument_list|)
block|{}
block|}
struct|;
comment|// Top level container for machine model data.
name|class
name|CodeGenSchedModels
block|{
name|RecordKeeper
modifier|&
name|Records
decl_stmt|;
specifier|const
name|CodeGenTarget
modifier|&
name|Target
decl_stmt|;
comment|// List of unique SchedClasses.
name|std
operator|::
name|vector
operator|<
name|CodeGenSchedClass
operator|>
name|SchedClasses
expr_stmt|;
comment|// Map SchedClass name to itinerary index.
comment|// These are either explicit itinerary classes or inferred classes.
name|StringMap
operator|<
name|unsigned
operator|>
name|SchedClassIdxMap
expr_stmt|;
comment|// SchedClass indices 1 up to and including NumItineraryClasses identify
comment|// itinerary classes that are explicitly used for this target's instruction
comment|// definitions. NoItinerary always has index 0 regardless of whether it is
comment|// explicitly referenced.
comment|//
comment|// Any inferred SchedClass have a index greater than NumItineraryClasses.
name|unsigned
name|NumItineraryClasses
decl_stmt|;
comment|// List of unique processor models.
name|std
operator|::
name|vector
operator|<
name|CodeGenProcModel
operator|>
name|ProcModels
expr_stmt|;
comment|// Map Processor's MachineModel + ProcItin fields to a CodeGenProcModel index.
typedef|typedef
name|DenseMap
operator|<
name|std
operator|::
name|pair
operator|<
name|Record
operator|*
operator|,
name|Record
operator|*
operator|>
operator|,
name|unsigned
operator|>
name|ProcModelMapTy
expr_stmt|;
name|ProcModelMapTy
name|ProcModelMap
decl_stmt|;
comment|// True if any processors have nonempty itineraries.
name|bool
name|HasProcItineraries
decl_stmt|;
name|public
label|:
name|CodeGenSchedModels
argument_list|(
name|RecordKeeper
operator|&
name|RK
argument_list|,
specifier|const
name|CodeGenTarget
operator|&
name|TGT
argument_list|)
expr_stmt|;
comment|// Check if any instructions are assigned to an explicit itinerary class other
comment|// than NoItinerary.
name|bool
name|hasItineraryClasses
argument_list|()
specifier|const
block|{
return|return
name|NumItineraryClasses
operator|>
literal|0
return|;
block|}
comment|// Return the number of itinerary classes in use by this target's instruction
comment|// descriptions, not including "NoItinerary".
name|unsigned
name|numItineraryClasses
argument_list|()
specifier|const
block|{
return|return
name|NumItineraryClasses
return|;
block|}
comment|// Get a SchedClass from its index.
specifier|const
name|CodeGenSchedClass
modifier|&
name|getSchedClass
parameter_list|(
name|unsigned
name|Idx
parameter_list|)
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|SchedClasses
operator|.
name|size
argument_list|()
operator|&&
literal|"bad SchedClass index"
argument_list|)
expr_stmt|;
return|return
name|SchedClasses
index|[
name|Idx
index|]
return|;
block|}
comment|// Get an itinerary class's index. Value indices are '0' for NoItinerary up to
comment|// and including numItineraryClasses().
name|unsigned
name|getItinClassIdx
argument_list|(
name|Record
operator|*
name|ItinDef
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|SchedClassIdxMap
operator|.
name|count
argument_list|(
name|ItinDef
operator|->
name|getName
argument_list|()
argument_list|)
operator|&&
literal|"missing ItinClass"
argument_list|)
expr_stmt|;
name|unsigned
name|Idx
init|=
name|SchedClassIdxMap
operator|.
name|lookup
argument_list|(
name|ItinDef
operator|->
name|getName
argument_list|()
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|Idx
operator|<=
name|NumItineraryClasses
operator|&&
literal|"bad ItinClass index"
argument_list|)
expr_stmt|;
return|return
name|Idx
return|;
block|}
name|bool
name|hasProcessorItineraries
argument_list|()
specifier|const
block|{
return|return
name|HasProcItineraries
return|;
block|}
comment|// Get an existing machine model for a processor definition.
specifier|const
name|CodeGenProcModel
modifier|&
name|getProcModel
argument_list|(
name|Record
operator|*
name|ProcDef
argument_list|)
decl|const
block|{
name|unsigned
name|idx
init|=
name|getProcModelIdx
argument_list|(
name|ProcDef
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|idx
operator|<
name|ProcModels
operator|.
name|size
argument_list|()
operator|&&
literal|"missing machine model"
argument_list|)
expr_stmt|;
return|return
name|ProcModels
index|[
name|idx
index|]
return|;
block|}
comment|// Iterate over the unique processor models.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CodeGenProcModel
operator|>
operator|::
name|const_iterator
name|ProcIter
expr_stmt|;
name|ProcIter
name|procModelBegin
argument_list|()
specifier|const
block|{
return|return
name|ProcModels
operator|.
name|begin
argument_list|()
return|;
block|}
name|ProcIter
name|procModelEnd
argument_list|()
specifier|const
block|{
return|return
name|ProcModels
operator|.
name|end
argument_list|()
return|;
block|}
name|private
label|:
comment|// Get a key that can uniquely identify a machine model.
name|ProcModelMapTy
operator|::
name|key_type
name|getProcModelKey
argument_list|(
argument|Record *ProcDef
argument_list|)
specifier|const
block|{
name|Record
operator|*
name|ModelDef
operator|=
name|ProcDef
operator|->
name|getValueAsDef
argument_list|(
literal|"SchedModel"
argument_list|)
block|;
name|Record
operator|*
name|ItinsDef
operator|=
name|ProcDef
operator|->
name|getValueAsDef
argument_list|(
literal|"ProcItin"
argument_list|)
block|;
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|ModelDef
argument_list|,
name|ItinsDef
argument_list|)
return|;
block|}
comment|// Get the unique index of a machine model.
name|unsigned
name|getProcModelIdx
argument_list|(
name|Record
operator|*
name|ProcDef
argument_list|)
decl|const
block|{
name|ProcModelMapTy
operator|::
name|const_iterator
name|I
operator|=
name|ProcModelMap
operator|.
name|find
argument_list|(
name|getProcModelKey
argument_list|(
name|ProcDef
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|I
operator|==
name|ProcModelMap
operator|.
name|end
argument_list|()
condition|)
return|return
name|ProcModels
operator|.
name|size
argument_list|()
return|;
return|return
name|I
operator|->
name|second
return|;
block|}
comment|// Initialize a new processor model if it is unique.
name|void
name|addProcModel
parameter_list|(
name|Record
modifier|*
name|ProcDef
parameter_list|)
function_decl|;
name|void
name|CollectSchedClasses
parameter_list|()
function_decl|;
name|void
name|CollectProcModels
parameter_list|()
function_decl|;
name|void
name|CollectProcItin
argument_list|(
name|CodeGenProcModel
operator|&
name|ProcModel
argument_list|,
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
name|ItinRecords
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

