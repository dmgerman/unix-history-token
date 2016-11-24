begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SafeStackColoring.h - SafeStack frame coloring ---------*- C++ -*--===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_CODEGEN_SAFESTACKCOLORING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_SAFESTACKCOLORING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_os_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AllocaInst
decl_stmt|;
name|namespace
name|safestack
block|{
comment|/// Compute live ranges of allocas.
comment|/// Live ranges are represented as sets of "interesting" instructions, which are
comment|/// defined as instructions that may start or end an alloca's lifetime. These
comment|/// are:
comment|/// * lifetime.start and lifetime.end intrinsics
comment|/// * first instruction of any basic block
comment|/// Interesting instructions are numbered in the depth-first walk of the CFG,
comment|/// and in the program order inside each basic block.
name|class
name|StackColoring
block|{
comment|/// A class representing liveness information for a single basic block.
comment|/// Each bit in the BitVector represents the liveness property
comment|/// for a different stack slot.
struct|struct
name|BlockLifetimeInfo
block|{
comment|/// Which slots BEGINs in each basic block.
name|BitVector
name|Begin
decl_stmt|;
comment|/// Which slots ENDs in each basic block.
name|BitVector
name|End
decl_stmt|;
comment|/// Which slots are marked as LIVE_IN, coming into each basic block.
name|BitVector
name|LiveIn
decl_stmt|;
comment|/// Which slots are marked as LIVE_OUT, coming out of each basic block.
name|BitVector
name|LiveOut
decl_stmt|;
block|}
struct|;
name|public
label|:
comment|/// This class represents a set of interesting instructions where an alloca is
comment|/// live.
struct|struct
name|LiveRange
block|{
name|BitVector
name|bv
decl_stmt|;
name|void
name|SetMaximum
parameter_list|(
name|int
name|size
parameter_list|)
block|{
name|bv
operator|.
name|resize
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
name|void
name|AddRange
parameter_list|(
name|unsigned
name|start
parameter_list|,
name|unsigned
name|end
parameter_list|)
block|{
name|bv
operator|.
name|set
argument_list|(
name|start
argument_list|,
name|end
argument_list|)
expr_stmt|;
block|}
name|bool
name|Overlaps
argument_list|(
specifier|const
name|LiveRange
operator|&
name|Other
argument_list|)
decl|const
block|{
return|return
name|bv
operator|.
name|anyCommon
argument_list|(
name|Other
operator|.
name|bv
argument_list|)
return|;
block|}
name|void
name|Join
parameter_list|(
specifier|const
name|LiveRange
modifier|&
name|Other
parameter_list|)
block|{
name|bv
operator||=
name|Other
operator|.
name|bv
expr_stmt|;
block|}
block|}
struct|;
name|private
label|:
name|Function
modifier|&
name|F
decl_stmt|;
comment|/// Maps active slots (per bit) for each basic block.
typedef|typedef
name|DenseMap
operator|<
name|BasicBlock
operator|*
operator|,
name|BlockLifetimeInfo
operator|>
name|LivenessMap
expr_stmt|;
name|LivenessMap
name|BlockLiveness
decl_stmt|;
comment|/// Number of interesting instructions.
name|int
name|NumInst
decl_stmt|;
comment|/// Numeric ids for interesting instructions.
name|DenseMap
operator|<
name|Instruction
operator|*
operator|,
name|unsigned
operator|>
name|InstructionNumbering
expr_stmt|;
comment|/// A range [Start, End) of instruction ids for each basic block.
comment|/// Instructions inside each BB have monotonic and consecutive ids.
name|DenseMap
operator|<
specifier|const
name|BasicBlock
operator|*
operator|,
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>>
name|BlockInstRange
expr_stmt|;
name|ArrayRef
operator|<
name|AllocaInst
operator|*
operator|>
name|Allocas
expr_stmt|;
name|unsigned
name|NumAllocas
decl_stmt|;
name|DenseMap
operator|<
name|AllocaInst
operator|*
operator|,
name|unsigned
operator|>
name|AllocaNumbering
expr_stmt|;
comment|/// LiveRange for allocas.
name|SmallVector
operator|<
name|LiveRange
operator|,
literal|8
operator|>
name|LiveRanges
expr_stmt|;
comment|/// The set of allocas that have at least one lifetime.start. All other
comment|/// allocas get LiveRange that corresponds to the entire function.
name|BitVector
name|InterestingAllocas
decl_stmt|;
name|SmallVector
operator|<
name|Instruction
operator|*
operator|,
literal|8
operator|>
name|Markers
expr_stmt|;
struct|struct
name|Marker
block|{
name|unsigned
name|AllocaNo
decl_stmt|;
name|bool
name|IsStart
decl_stmt|;
block|}
struct|;
comment|/// List of {InstNo, {AllocaNo, IsStart}} for each BB, ordered by InstNo.
name|DenseMap
operator|<
name|BasicBlock
operator|*
operator|,
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|Marker
operator|>
operator|,
literal|4
operator|>>
name|BBMarkers
expr_stmt|;
name|void
name|dumpAllocas
parameter_list|()
function_decl|;
name|void
name|dumpBlockLiveness
parameter_list|()
function_decl|;
name|void
name|dumpLiveRanges
parameter_list|()
function_decl|;
name|bool
name|readMarker
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
name|bool
modifier|*
name|IsStart
parameter_list|)
function_decl|;
name|void
name|collectMarkers
parameter_list|()
function_decl|;
name|void
name|calculateLocalLiveness
parameter_list|()
function_decl|;
name|void
name|calculateLiveIntervals
parameter_list|()
function_decl|;
name|public
label|:
name|StackColoring
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|ArrayRef
operator|<
name|AllocaInst
operator|*
operator|>
name|Allocas
argument_list|)
operator|:
name|F
argument_list|(
name|F
argument_list|)
operator|,
name|NumInst
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|Allocas
argument_list|(
name|Allocas
argument_list|)
operator|,
name|NumAllocas
argument_list|(
argument|Allocas.size()
argument_list|)
block|{}
name|void
name|run
argument_list|()
expr_stmt|;
name|void
name|removeAllMarkers
parameter_list|()
function_decl|;
comment|/// Returns a set of "interesting" instructions where the given alloca is
comment|/// live. Not all instructions in a function are interesting: we pick a set
comment|/// that is large enough for LiveRange::Overlaps to be correct.
specifier|const
name|LiveRange
modifier|&
name|getLiveRange
parameter_list|(
name|AllocaInst
modifier|*
name|AI
parameter_list|)
function_decl|;
comment|/// Returns a live range that represents an alloca that is live throughout the
comment|/// entire function.
name|LiveRange
name|getFullLiveRange
parameter_list|()
block|{
name|assert
argument_list|(
name|NumInst
operator|>=
literal|0
argument_list|)
expr_stmt|;
name|LiveRange
name|R
decl_stmt|;
name|R
operator|.
name|SetMaximum
argument_list|(
name|NumInst
argument_list|)
expr_stmt|;
name|R
operator|.
name|AddRange
argument_list|(
literal|0
argument_list|,
name|NumInst
argument_list|)
expr_stmt|;
return|return
name|R
return|;
block|}
block|}
empty_stmt|;
specifier|static
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|BitVector
operator|&
name|V
operator|)
block|{
name|OS
operator|<<
literal|"{"
block|;
name|int
name|idx
operator|=
name|V
operator|.
name|find_first
argument_list|()
block|;
name|bool
name|first
operator|=
name|true
block|;
while|while
condition|(
name|idx
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
operator|!
name|first
condition|)
block|{
name|OS
operator|<<
literal|", "
expr_stmt|;
block|}
name|first
operator|=
name|false
expr_stmt|;
name|OS
operator|<<
name|idx
expr_stmt|;
name|idx
operator|=
name|V
operator|.
name|find_next
argument_list|(
name|idx
argument_list|)
expr_stmt|;
block|}
name|OS
operator|<<
literal|"}"
expr_stmt|;
return|return
name|OS
return|;
block|}
specifier|static
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|StackColoring
operator|::
name|LiveRange
operator|&
name|R
operator|)
block|{
return|return
name|OS
operator|<<
name|R
operator|.
name|bv
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace safestack
end_comment

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_CODEGEN_SAFESTACKCOLORING_H
end_comment

end_unit

