begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DwarfException.h - Dwarf Exception Framework -----------*- C++ -*--===//
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
comment|// This file contains support for writing dwarf exception info into asm files.
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
name|LLVM_CODEGEN_ASMPRINTER_DWARFEXCEPTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_ASMPRINTER_DWARFEXCEPTION_H
end_define

begin_include
include|#
directive|include
file|"DIE.h"
end_include

begin_include
include|#
directive|include
file|"DwarfPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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
struct_decl|struct
name|LandingPadInfo
struct_decl|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|Timer
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// DwarfException - Emits Dwarf exception handling directives.
comment|///
name|class
name|DwarfException
range|:
name|public
name|Dwarf
block|{   struct
name|FunctionEHFrameInfo
block|{
name|std
operator|::
name|string
name|FnName
block|;
name|unsigned
name|Number
block|;
name|unsigned
name|PersonalityIndex
block|;
name|bool
name|hasCalls
block|;
name|bool
name|hasLandingPads
block|;
name|std
operator|::
name|vector
operator|<
name|MachineMove
operator|>
name|Moves
block|;
specifier|const
name|Function
operator|*
name|function
block|;
name|FunctionEHFrameInfo
argument_list|(
argument|const std::string&FN
argument_list|,
argument|unsigned Num
argument_list|,
argument|unsigned P
argument_list|,
argument|bool hC
argument_list|,
argument|bool hL
argument_list|,
argument|const std::vector<MachineMove>&M
argument_list|,
argument|const Function *f
argument_list|)
operator|:
name|FnName
argument_list|(
name|FN
argument_list|)
block|,
name|Number
argument_list|(
name|Num
argument_list|)
block|,
name|PersonalityIndex
argument_list|(
name|P
argument_list|)
block|,
name|hasCalls
argument_list|(
name|hC
argument_list|)
block|,
name|hasLandingPads
argument_list|(
name|hL
argument_list|)
block|,
name|Moves
argument_list|(
name|M
argument_list|)
block|,
name|function
argument_list|(
argument|f
argument_list|)
block|{ }
block|}
block|;
name|std
operator|::
name|vector
operator|<
name|FunctionEHFrameInfo
operator|>
name|EHFrames
block|;
comment|/// UsesLSDA - Indicates whether an FDE that uses the CIE at the given index
comment|/// uses an LSDA. If so, then we need to encode that information in the CIE's
comment|/// augmentation.
name|DenseMap
operator|<
name|unsigned
block|,
name|bool
operator|>
name|UsesLSDA
block|;
comment|/// shouldEmitTable - Per-function flag to indicate if EH tables should
comment|/// be emitted.
name|bool
name|shouldEmitTable
block|;
comment|/// shouldEmitMoves - Per-function flag to indicate if frame moves info
comment|/// should be emitted.
name|bool
name|shouldEmitMoves
block|;
comment|/// shouldEmitTableModule - Per-module flag to indicate if EH tables
comment|/// should be emitted.
name|bool
name|shouldEmitTableModule
block|;
comment|/// shouldEmitFrameModule - Per-module flag to indicate if frame moves
comment|/// should be emitted.
name|bool
name|shouldEmitMovesModule
block|;
comment|/// ExceptionTimer - Timer for the Dwarf exception writer.
name|Timer
operator|*
name|ExceptionTimer
block|;
comment|/// SizeOfEncodedValue - Return the size of the encoding in bytes.
name|unsigned
name|SizeOfEncodedValue
argument_list|(
argument|unsigned Encoding
argument_list|)
block|;
comment|/// EmitCIE - Emit a Common Information Entry (CIE). This holds information
comment|/// that is shared among many Frame Description Entries.  There is at least
comment|/// one CIE in every non-empty .debug_frame section.
name|void
name|EmitCIE
argument_list|(
argument|const Function *Personality
argument_list|,
argument|unsigned Index
argument_list|)
block|;
comment|/// EmitFDE - Emit the Frame Description Entry (FDE) for the function.
name|void
name|EmitFDE
argument_list|(
specifier|const
name|FunctionEHFrameInfo
operator|&
name|EHFrameInfo
argument_list|)
block|;
comment|/// EmitExceptionTable - Emit landing pads and actions.
comment|///
comment|/// The general organization of the table is complex, but the basic concepts
comment|/// are easy.  First there is a header which describes the location and
comment|/// organization of the three components that follow.
comment|///  1. The landing pad site information describes the range of code covered
comment|///     by the try.  In our case it's an accumulation of the ranges covered
comment|///     by the invokes in the try.  There is also a reference to the landing
comment|///     pad that handles the exception once processed.  Finally an index into
comment|///     the actions table.
comment|///  2. The action table, in our case, is composed of pairs of type ids
comment|///     and next action offset.  Starting with the action index from the
comment|///     landing pad site, each type Id is checked for a match to the current
comment|///     exception.  If it matches then the exception and type id are passed
comment|///     on to the landing pad.  Otherwise the next action is looked up.  This
comment|///     chain is terminated with a next action of zero.  If no type id is
comment|///     found the the frame is unwound and handling continues.
comment|///  3. Type id table contains references to all the C++ typeinfo for all
comment|///     catches in the function.  This tables is reversed indexed base 1.
comment|/// SharedTypeIds - How many leading type ids two landing pads have in common.
specifier|static
name|unsigned
name|SharedTypeIds
argument_list|(
specifier|const
name|LandingPadInfo
operator|*
name|L
argument_list|,
specifier|const
name|LandingPadInfo
operator|*
name|R
argument_list|)
block|;
comment|/// PadLT - Order landing pads lexicographically by type id.
specifier|static
name|bool
name|PadLT
argument_list|(
specifier|const
name|LandingPadInfo
operator|*
name|L
argument_list|,
specifier|const
name|LandingPadInfo
operator|*
name|R
argument_list|)
block|;    struct
name|KeyInfo
block|{
specifier|static
specifier|inline
name|unsigned
name|getEmptyKey
argument_list|()
block|{
return|return
operator|-
literal|1U
return|;
block|}
specifier|static
specifier|inline
name|unsigned
name|getTombstoneKey
argument_list|()
block|{
return|return
operator|-
literal|2U
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
argument|const unsigned&Key
argument_list|)
block|{
return|return
name|Key
return|;
block|}
specifier|static
name|bool
name|isEqual
argument_list|(
argument|unsigned LHS
argument_list|,
argument|unsigned RHS
argument_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
specifier|static
name|bool
name|isPod
argument_list|()
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// PadRange - Structure holding a try-range and the associated landing pad.
block|struct
name|PadRange
block|{
comment|// The index of the landing pad.
name|unsigned
name|PadIndex
block|;
comment|// The index of the begin and end labels in the landing pad's label lists.
name|unsigned
name|RangeIndex
block|;   }
block|;
typedef|typedef
name|DenseMap
operator|<
name|unsigned
operator|,
name|PadRange
operator|,
name|KeyInfo
operator|>
name|RangeMapType
expr_stmt|;
comment|/// ActionEntry - Structure describing an entry in the actions table.
block|struct
name|ActionEntry
block|{
name|int
name|ValueForTypeID
block|;
comment|// The value to write - may not be equal to the type id.
name|int
name|NextAction
block|;     struct
name|ActionEntry
operator|*
name|Previous
block|;   }
block|;
comment|/// CallSiteEntry - Structure describing an entry in the call-site table.
block|struct
name|CallSiteEntry
block|{
comment|// The 'try-range' is BeginLabel .. EndLabel.
name|unsigned
name|BeginLabel
block|;
comment|// zero indicates the start of the function.
name|unsigned
name|EndLabel
block|;
comment|// zero indicates the end of the function.
comment|// The landing pad starts at PadLabel.
name|unsigned
name|PadLabel
block|;
comment|// zero indicates that there is no landing pad.
name|unsigned
name|Action
block|;   }
block|;
comment|/// ComputeActionsTable - Compute the actions table and gather the first
comment|/// action index for each landing pad site.
name|unsigned
name|ComputeActionsTable
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
specifier|const
name|LandingPadInfo
operator|*
operator|>
operator|&
name|LPs
argument_list|,
name|SmallVectorImpl
operator|<
name|ActionEntry
operator|>
operator|&
name|Actions
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|FirstActions
argument_list|)
block|;
comment|/// CallToNoUnwindFunction - Return `true' if this is a call to a function
comment|/// marked `nounwind'. Return `false' otherwise.
name|bool
name|CallToNoUnwindFunction
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
comment|/// ComputeCallSiteTable - Compute the call-site table.  The entry for an
comment|/// invoke has a try-range containing the call, a non-zero landing pad and an
comment|/// appropriate action.  The entry for an ordinary call has a try-range
comment|/// containing the call and zero for the landing pad and the action.  Calls
comment|/// marked 'nounwind' have no entry and must not be contained in the try-range
comment|/// of any entry - they form gaps in the table.  Entries must be ordered by
comment|/// try-range address.
name|void
name|ComputeCallSiteTable
argument_list|(
name|SmallVectorImpl
operator|<
name|CallSiteEntry
operator|>
operator|&
name|CallSites
argument_list|,
specifier|const
name|RangeMapType
operator|&
name|PadMap
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
specifier|const
name|LandingPadInfo
operator|*
operator|>
operator|&
name|LPs
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|FirstActions
argument_list|)
block|;
name|void
name|EmitExceptionTable
argument_list|()
block|;
comment|/// CreateLabelDiff - Emit a label and subtract it from the expression we
comment|/// already have.  This is equivalent to emitting "foo - .", but we have to
comment|/// emit the label for "." directly.
specifier|const
name|MCExpr
operator|*
name|CreateLabelDiff
argument_list|(
argument|const MCExpr *ExprRef
argument_list|,
argument|const char *LabelName
argument_list|,
argument|unsigned Index
argument_list|)
block|;
name|public
operator|:
comment|//===--------------------------------------------------------------------===//
comment|// Main entry points.
comment|//
name|DwarfException
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|AsmPrinter
operator|*
name|A
argument_list|,
specifier|const
name|MCAsmInfo
operator|*
name|T
argument_list|)
block|;
name|virtual
operator|~
name|DwarfException
argument_list|()
block|;
comment|/// BeginModule - Emit all exception information that should come prior to the
comment|/// content.
name|void
name|BeginModule
argument_list|(
argument|Module *m
argument_list|,
argument|MachineModuleInfo *mmi
argument_list|)
block|{
name|this
operator|->
name|M
operator|=
name|m
block|;
name|this
operator|->
name|MMI
operator|=
name|mmi
block|;   }
comment|/// EndModule - Emit all exception information that should come after the
comment|/// content.
name|void
name|EndModule
argument_list|()
block|;
comment|/// BeginFunction - Gather pre-function exception information.  Assumes being
comment|/// emitted immediately after the function entry point.
name|void
name|BeginFunction
argument_list|(
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
comment|/// EndFunction - Gather and emit post-function exception information.
name|void
name|EndFunction
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

