begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Loads.h - Local load analysis --------------------------------------===//
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
comment|// This file declares simple local analyses for load instructions.
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
name|LLVM_ANALYSIS_LOADS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LOADS_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AliasAnalysis
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
comment|/// isSafeToLoadUnconditionally - Return true if we know that executing a load
comment|/// from this value cannot trap.  If it is not obviously safe to load from the
comment|/// specified pointer, we do a quick local scan of the basic block containing
comment|/// ScanFrom, to determine if the address is already accessed.
name|bool
name|isSafeToLoadUnconditionally
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
name|Instruction
modifier|*
name|ScanFrom
parameter_list|,
name|unsigned
name|Align
parameter_list|,
specifier|const
name|DataLayout
modifier|*
name|TD
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// FindAvailableLoadedValue - Scan the ScanBB block backwards (starting at
comment|/// the instruction before ScanFrom) checking to see if we have the value at
comment|/// the memory address *Ptr locally available within a small number of
comment|///  instructions. If the value is available, return it.
comment|///
comment|/// If not, return the iterator for the last validated instruction that the
comment|/// value would be live through.  If we scanned the entire block and didn't
comment|/// find something that invalidates *Ptr or provides it, ScanFrom would be
comment|/// left at begin() and this returns null.  ScanFrom could also be left
comment|///
comment|/// MaxInstsToScan specifies the maximum instructions to scan in the block.
comment|/// If it is set to 0, it will scan the whole block. You can also optionally
comment|/// specify an alias analysis implementation, which makes this more precise.
comment|///
comment|/// If TBAATag is non-null and a load or store is found, the TBAA tag from the
comment|/// load or store is recorded there.  If there is no TBAA tag or if no access
comment|/// is found, it is left unmodified.
name|Value
modifier|*
name|FindAvailableLoadedValue
argument_list|(
name|Value
operator|*
name|Ptr
argument_list|,
name|BasicBlock
operator|*
name|ScanBB
argument_list|,
name|BasicBlock
operator|::
name|iterator
operator|&
name|ScanFrom
argument_list|,
name|unsigned
name|MaxInstsToScan
operator|=
literal|6
argument_list|,
name|AliasAnalysis
operator|*
name|AA
operator|=
name|nullptr
argument_list|,
name|MDNode
operator|*
operator|*
name|TBAATag
operator|=
name|nullptr
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

