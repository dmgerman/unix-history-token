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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
struct_decl|struct
name|LandingPadInfo
struct_decl|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|ARMTargetStreamer
decl_stmt|;
name|class
name|AsmPrinter
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// DwarfException - Emits Dwarf exception handling directives.
comment|///
name|class
name|DwarfException
block|{
name|protected
label|:
comment|/// Asm - Target of Dwarf emission.
name|AsmPrinter
modifier|*
name|Asm
decl_stmt|;
comment|/// MMI - Collected machine module information.
name|MachineModuleInfo
modifier|*
name|MMI
decl_stmt|;
comment|/// SharedTypeIds - How many leading type ids two landing pads have in common.
specifier|static
name|unsigned
name|SharedTypeIds
parameter_list|(
specifier|const
name|LandingPadInfo
modifier|*
name|L
parameter_list|,
specifier|const
name|LandingPadInfo
modifier|*
name|R
parameter_list|)
function_decl|;
comment|/// PadLT - Order landing pads lexicographically by type id.
specifier|static
name|bool
name|PadLT
parameter_list|(
specifier|const
name|LandingPadInfo
modifier|*
name|L
parameter_list|,
specifier|const
name|LandingPadInfo
modifier|*
name|R
parameter_list|)
function_decl|;
comment|/// PadRange - Structure holding a try-range and the associated landing pad.
struct|struct
name|PadRange
block|{
comment|// The index of the landing pad.
name|unsigned
name|PadIndex
decl_stmt|;
comment|// The index of the begin and end labels in the landing pad's label lists.
name|unsigned
name|RangeIndex
decl_stmt|;
block|}
struct|;
typedef|typedef
name|DenseMap
operator|<
name|MCSymbol
operator|*
operator|,
name|PadRange
operator|>
name|RangeMapType
expr_stmt|;
comment|/// ActionEntry - Structure describing an entry in the actions table.
struct|struct
name|ActionEntry
block|{
name|int
name|ValueForTypeID
decl_stmt|;
comment|// The value to write - may not be equal to the type id.
name|int
name|NextAction
decl_stmt|;
name|unsigned
name|Previous
decl_stmt|;
block|}
struct|;
comment|/// CallSiteEntry - Structure describing an entry in the call-site table.
struct|struct
name|CallSiteEntry
block|{
comment|// The 'try-range' is BeginLabel .. EndLabel.
name|MCSymbol
modifier|*
name|BeginLabel
decl_stmt|;
comment|// zero indicates the start of the function.
name|MCSymbol
modifier|*
name|EndLabel
decl_stmt|;
comment|// zero indicates the end of the function.
comment|// The landing pad starts at PadLabel.
name|MCSymbol
modifier|*
name|PadLabel
decl_stmt|;
comment|// zero indicates that there is no landing pad.
name|unsigned
name|Action
decl_stmt|;
block|}
struct|;
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
decl_stmt|;
comment|/// CallToNoUnwindFunction - Return `true' if this is a call to a function
comment|/// marked `nounwind'. Return `false' otherwise.
name|bool
name|CallToNoUnwindFunction
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
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
decl_stmt|;
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
comment|///     found the frame is unwound and handling continues.
comment|///  3. Type id table contains references to all the C++ typeinfo for all
comment|///     catches in the function.  This tables is reversed indexed base 1.
name|void
name|EmitExceptionTable
parameter_list|()
function_decl|;
name|virtual
name|void
name|EmitTypeInfos
parameter_list|(
name|unsigned
name|TTypeEncoding
parameter_list|)
function_decl|;
name|public
label|:
comment|//===--------------------------------------------------------------------===//
comment|// Main entry points.
comment|//
name|DwarfException
argument_list|(
name|AsmPrinter
operator|*
name|A
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|DwarfException
argument_list|()
expr_stmt|;
comment|/// EndModule - Emit all exception information that should come after the
comment|/// content.
name|virtual
name|void
name|EndModule
parameter_list|()
function_decl|;
comment|/// BeginFunction - Gather pre-function exception information.  Assumes being
comment|/// emitted immediately after the function entry point.
name|virtual
name|void
name|BeginFunction
parameter_list|(
specifier|const
name|MachineFunction
modifier|*
name|MF
parameter_list|)
function_decl|;
comment|/// EndFunction - Gather and emit post-function exception information.
name|virtual
name|void
name|EndFunction
parameter_list|()
function_decl|;
block|}
empty_stmt|;
name|class
name|DwarfCFIException
range|:
name|public
name|DwarfException
block|{
comment|/// shouldEmitPersonality - Per-function flag to indicate if .cfi_personality
comment|/// should be emitted.
name|bool
name|shouldEmitPersonality
block|;
comment|/// shouldEmitLSDA - Per-function flag to indicate if .cfi_lsda
comment|/// should be emitted.
name|bool
name|shouldEmitLSDA
block|;
comment|/// shouldEmitMoves - Per-function flag to indicate if frame moves info
comment|/// should be emitted.
name|bool
name|shouldEmitMoves
block|;
name|AsmPrinter
operator|::
name|CFIMoveType
name|moveTypeModule
block|;
name|public
operator|:
comment|//===--------------------------------------------------------------------===//
comment|// Main entry points.
comment|//
name|DwarfCFIException
argument_list|(
name|AsmPrinter
operator|*
name|A
argument_list|)
block|;
name|virtual
operator|~
name|DwarfCFIException
argument_list|()
block|;
comment|/// EndModule - Emit all exception information that should come after the
comment|/// content.
name|virtual
name|void
name|EndModule
argument_list|()
block|;
comment|/// BeginFunction - Gather pre-function exception information.  Assumes being
comment|/// emitted immediately after the function entry point.
name|virtual
name|void
name|BeginFunction
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
comment|/// EndFunction - Gather and emit post-function exception information.
name|virtual
name|void
name|EndFunction
argument_list|()
block|; }
decl_stmt|;
name|class
name|ARMException
range|:
name|public
name|DwarfException
block|{
name|void
name|EmitTypeInfos
argument_list|(
argument|unsigned TTypeEncoding
argument_list|)
block|;
name|ARMTargetStreamer
operator|&
name|getTargetStreamer
argument_list|()
block|;
name|public
operator|:
comment|//===--------------------------------------------------------------------===//
comment|// Main entry points.
comment|//
name|ARMException
argument_list|(
name|AsmPrinter
operator|*
name|A
argument_list|)
block|;
name|virtual
operator|~
name|ARMException
argument_list|()
block|;
comment|/// EndModule - Emit all exception information that should come after the
comment|/// content.
name|virtual
name|void
name|EndModule
argument_list|()
block|;
comment|/// BeginFunction - Gather pre-function exception information.  Assumes being
comment|/// emitted immediately after the function entry point.
name|virtual
name|void
name|BeginFunction
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
comment|/// EndFunction - Gather and emit post-function exception information.
name|virtual
name|void
name|EndFunction
argument_list|()
block|; }
decl_stmt|;
name|class
name|Win64Exception
range|:
name|public
name|DwarfException
block|{
comment|/// shouldEmitPersonality - Per-function flag to indicate if personality
comment|/// info should be emitted.
name|bool
name|shouldEmitPersonality
block|;
comment|/// shouldEmitLSDA - Per-function flag to indicate if the LSDA
comment|/// should be emitted.
name|bool
name|shouldEmitLSDA
block|;
comment|/// shouldEmitMoves - Per-function flag to indicate if frame moves info
comment|/// should be emitted.
name|bool
name|shouldEmitMoves
block|;
name|public
operator|:
comment|//===--------------------------------------------------------------------===//
comment|// Main entry points.
comment|//
name|Win64Exception
argument_list|(
name|AsmPrinter
operator|*
name|A
argument_list|)
block|;
name|virtual
operator|~
name|Win64Exception
argument_list|()
block|;
comment|/// EndModule - Emit all exception information that should come after the
comment|/// content.
name|virtual
name|void
name|EndModule
argument_list|()
block|;
comment|/// BeginFunction - Gather pre-function exception information.  Assumes being
comment|/// emitted immediately after the function entry point.
name|virtual
name|void
name|BeginFunction
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
comment|/// EndFunction - Gather and emit post-function exception information.
name|virtual
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

