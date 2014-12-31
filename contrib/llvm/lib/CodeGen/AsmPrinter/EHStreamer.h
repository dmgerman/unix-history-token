begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- EHStreamer.h - Exception Handling Directive Streamer ---*- C++ -*--===//
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
comment|// This file contains support for writing exception info into assembly files.
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
name|LLVM_CODEGEN_ASMPRINTER_EHSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_ASMPRINTER_EHSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"AsmPrinterHandler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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
name|MachineInstr
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|AsmPrinter
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
comment|/// Emits exception handling directives.
name|class
name|EHStreamer
range|:
name|public
name|AsmPrinterHandler
block|{
name|protected
operator|:
comment|/// Target of directive emission.
name|AsmPrinter
operator|*
name|Asm
block|;
comment|/// Collected machine module information.
name|MachineModuleInfo
operator|*
name|MMI
block|;
comment|/// How many leading type ids two landing pads have in common.
specifier|static
name|unsigned
name|sharedTypeIDs
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
comment|/// Structure holding a try-range and the associated landing pad.
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
name|MCSymbol
operator|*
operator|,
name|PadRange
operator|>
name|RangeMapType
expr_stmt|;
comment|/// Structure describing an entry in the actions table.
block|struct
name|ActionEntry
block|{
name|int
name|ValueForTypeID
block|;
comment|// The value to write - may not be equal to the type id.
name|int
name|NextAction
block|;
name|unsigned
name|Previous
block|;   }
decl_stmt|;
comment|/// Structure describing an entry in the call-site table.
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
comment|/// Compute the actions table and gather the first action index for each
comment|/// landing pad site.
name|unsigned
name|computeActionsTable
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
comment|/// Return `true' if this is a call to a function marked `nounwind'. Return
comment|/// `false' otherwise.
name|bool
name|callToNoUnwindFunction
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// Compute the call-site table.  The entry for an invoke has a try-range
comment|/// containing the call, a non-zero landing pad and an appropriate action.
comment|/// The entry for an ordinary call has a try-range containing the call and
comment|/// zero for the landing pad and the action.  Calls marked 'nounwind' have
comment|/// no entry and must not be contained in the try-range of any entry - they
comment|/// form gaps in the table.  Entries must be ordered by try-range address.
name|void
name|computeCallSiteTable
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
comment|/// Emit landing pads and actions.
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
name|emitExceptionTable
parameter_list|()
function_decl|;
name|virtual
name|void
name|emitTypeInfos
parameter_list|(
name|unsigned
name|TTypeEncoding
parameter_list|)
function_decl|;
name|public
label|:
name|EHStreamer
argument_list|(
name|AsmPrinter
operator|*
name|A
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|EHStreamer
argument_list|()
expr_stmt|;
comment|/// Emit all exception information that should come after the content.
name|void
name|endModule
argument_list|()
name|override
expr_stmt|;
comment|/// Gather pre-function exception information.  Assumes being emitted
comment|/// immediately after the function entry point.
name|void
name|beginFunction
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
name|override
decl_stmt|;
comment|/// Gather and emit post-function exception information.
name|void
name|endFunction
argument_list|(
specifier|const
name|MachineFunction
operator|*
argument_list|)
name|override
decl_stmt|;
comment|// Unused.
name|void
name|setSymbolSize
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Sym
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
function|override
block|{}
name|void
name|beginInstruction
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function|override
block|{}
name|void
name|endInstruction
parameter_list|()
function|override
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

