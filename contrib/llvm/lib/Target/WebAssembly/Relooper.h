begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Relooper.h - Top-level interface for WebAssembly  ----*- C++ -*-===//
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
comment|//===-------------------------------------------------------------------===//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This defines an optimized C++ implemention of the Relooper
end_comment

begin_comment
comment|/// algorithm, originally developed as part of Emscripten, which
end_comment

begin_comment
comment|/// generates a structured AST from arbitrary control flow.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===-------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdarg>
end_include

begin_include
include|#
directive|include
file|<cstdio>
end_include

begin_include
include|#
directive|include
file|<deque>
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|Relooper
block|{
struct_decl|struct
name|Block
struct_decl|;
struct_decl|struct
name|Shape
struct_decl|;
comment|///
comment|/// Info about a branching from one block to another
comment|///
struct|struct
name|Branch
block|{
enum|enum
name|FlowType
block|{
name|Direct
init|=
literal|0
block|,
comment|// We will directly reach the right location through other
comment|// means, no need for continue or break
name|Break
init|=
literal|1
block|,
name|Continue
init|=
literal|2
block|,
name|Nested
init|=
literal|3
comment|// This code is directly reached, but we must be careful to
comment|// ensure it is nested in an if - it is not reached
comment|// unconditionally, other code paths exist alongside it that we need to make
comment|// sure do not intertwine
block|}
enum|;
name|Shape
modifier|*
name|Ancestor
decl_stmt|;
comment|// If not nullptr, this shape is the relevant one for purposes
comment|// of getting to the target block. We break or continue on it
name|Branch
operator|::
name|FlowType
name|Type
expr_stmt|;
comment|// If Ancestor is not nullptr, this says whether to break or
comment|// continue
name|bool
name|Labeled
decl_stmt|;
comment|// If a break or continue, whether we need to use a label
specifier|const
name|char
modifier|*
name|Condition
decl_stmt|;
comment|// The condition for which we branch. For example,
comment|// "my_var == 1". Conditions are checked one by one.
comment|// One of the conditions should have nullptr as the
comment|// condition, in which case it is the default
comment|// FIXME: move from char* to LLVM data structures
specifier|const
name|char
modifier|*
name|Code
decl_stmt|;
comment|// If provided, code that is run right before the branch is
comment|// taken. This is useful for phis
comment|// FIXME: move from char* to LLVM data structures
name|Branch
argument_list|(
specifier|const
name|char
operator|*
name|ConditionInit
argument_list|,
specifier|const
name|char
operator|*
name|CodeInit
operator|=
name|nullptr
argument_list|)
expr_stmt|;
operator|~
name|Branch
argument_list|()
expr_stmt|;
block|}
struct|;
typedef|typedef
name|SetVector
operator|<
name|Block
operator|*
operator|>
name|BlockSet
expr_stmt|;
typedef|typedef
name|MapVector
operator|<
name|Block
operator|*
operator|,
name|Branch
operator|*
operator|>
name|BlockBranchMap
expr_stmt|;
typedef|typedef
name|MapVector
operator|<
name|Block
operator|*
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|Branch
operator|>>
name|OwningBlockBranchMap
expr_stmt|;
comment|///
comment|/// Represents a basic block of code - some instructions that end with a
comment|/// control flow modifier (a branch, return or throw).
comment|///
struct|struct
name|Block
block|{
comment|// Branches become processed after we finish the shape relevant to them. For
comment|// example, when we recreate a loop, branches to the loop start become
comment|// continues and are now processed. When we calculate what shape to generate
comment|// from a set of blocks, we ignore processed branches. Blocks own the Branch
comment|// objects they use, and destroy them when done.
name|OwningBlockBranchMap
name|BranchesOut
decl_stmt|;
name|BlockSet
name|BranchesIn
decl_stmt|;
name|OwningBlockBranchMap
name|ProcessedBranchesOut
decl_stmt|;
name|BlockSet
name|ProcessedBranchesIn
decl_stmt|;
name|Shape
modifier|*
name|Parent
decl_stmt|;
comment|// The shape we are directly inside
name|int
name|Id
decl_stmt|;
comment|// A unique identifier, defined when added to relooper. Note that this
comment|// uniquely identifies a *logical* block - if we split it, the two
comment|// instances have the same content *and* the same Id
specifier|const
name|char
modifier|*
name|Code
decl_stmt|;
comment|// The string representation of the code in this block.
comment|// Owning pointer (we copy the input)
comment|// FIXME: move from char* to LLVM data structures
specifier|const
name|char
modifier|*
name|BranchVar
decl_stmt|;
comment|// A variable whose value determines where we go; if
comment|// this is not nullptr, emit a switch on that variable
comment|// FIXME: move from char* to LLVM data structures
name|bool
name|IsCheckedMultipleEntry
decl_stmt|;
comment|// If true, we are a multiple entry, so reaching
comment|// us requires setting the label variable
name|Block
argument_list|(
specifier|const
name|char
operator|*
name|CodeInit
argument_list|,
specifier|const
name|char
operator|*
name|BranchVarInit
argument_list|)
expr_stmt|;
operator|~
name|Block
argument_list|()
expr_stmt|;
name|void
name|AddBranchTo
parameter_list|(
name|Block
modifier|*
name|Target
parameter_list|,
specifier|const
name|char
modifier|*
name|Condition
parameter_list|,
specifier|const
name|char
modifier|*
name|Code
init|=
name|nullptr
parameter_list|)
function_decl|;
block|}
struct|;
comment|///
comment|/// Represents a structured control flow shape
comment|///
struct|struct
name|Shape
block|{
name|int
name|Id
decl_stmt|;
comment|// A unique identifier. Used to identify loops, labels are Lx where x
comment|// is the Id. Defined when added to relooper
name|Shape
modifier|*
name|Next
decl_stmt|;
comment|// The shape that will appear in the code right after this one
name|Shape
modifier|*
name|Natural
decl_stmt|;
comment|// The shape that control flow gets to naturally (if there is
comment|// Next, then this is Next)
comment|/// Discriminator for LLVM-style RTTI (dyn_cast<> et al.)
enum|enum
name|ShapeKind
block|{
name|SK_Simple
block|,
name|SK_Multiple
block|,
name|SK_Loop
block|}
enum|;
name|private
label|:
name|ShapeKind
name|Kind
decl_stmt|;
name|public
label|:
name|ShapeKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|Shape
argument_list|(
argument|ShapeKind KindInit
argument_list|)
block|:
name|Id
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|Next
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Kind
argument_list|(
argument|KindInit
argument_list|)
block|{}
block|}
struct|;
comment|///
comment|/// Simple: No control flow at all, just instructions.
comment|///
name|struct
name|SimpleShape
range|:
name|public
name|Shape
block|{
name|Block
operator|*
name|Inner
block|;
name|SimpleShape
argument_list|()
operator|:
name|Shape
argument_list|(
name|SK_Simple
argument_list|)
block|,
name|Inner
argument_list|(
argument|nullptr
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Shape *S
argument_list|)
block|{
return|return
name|S
operator|->
name|getKind
argument_list|()
operator|==
name|SK_Simple
return|;
block|}
expr|}
block|;
comment|///
comment|/// A shape that may be implemented with a labeled loop.
comment|///
block|struct
name|LabeledShape
operator|:
name|public
name|Shape
block|{
name|bool
name|Labeled
block|;
comment|// If we have a loop, whether it needs to be labeled
name|LabeledShape
argument_list|(
argument|ShapeKind KindInit
argument_list|)
operator|:
name|Shape
argument_list|(
name|KindInit
argument_list|)
block|,
name|Labeled
argument_list|(
argument|false
argument_list|)
block|{}
block|}
block|;
comment|// Blocks with the same id were split and are identical, so we just care about
comment|// ids in Multiple entries
typedef|typedef
name|std
operator|::
name|map
operator|<
name|int
operator|,
name|Shape
operator|*
operator|>
name|IdShapeMap
expr_stmt|;
comment|///
comment|/// Multiple: A shape with more than one entry. If the next block to
comment|///           be entered is among them, we run it and continue to
comment|///           the next shape, otherwise we continue immediately to the
comment|///           next shape.
comment|///
block|struct
name|MultipleShape
operator|:
name|public
name|LabeledShape
block|{
name|IdShapeMap
name|InnerMap
block|;
comment|// entry block ID -> shape
name|int
name|Breaks
block|;
comment|// If we have branches on us, we need a loop (or a switch). This
comment|// is a counter of requirements,
comment|// if we optimize it to 0, the loop is unneeded
name|bool
name|UseSwitch
block|;
comment|// Whether to switch on label as opposed to an if-else chain
name|MultipleShape
argument_list|()
operator|:
name|LabeledShape
argument_list|(
name|SK_Multiple
argument_list|)
block|,
name|Breaks
argument_list|(
literal|0
argument_list|)
block|,
name|UseSwitch
argument_list|(
argument|false
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Shape *S
argument_list|)
block|{
return|return
name|S
operator|->
name|getKind
argument_list|()
operator|==
name|SK_Multiple
return|;
block|}
expr|}
block|;
comment|///
comment|/// Loop: An infinite loop.
comment|///
block|struct
name|LoopShape
operator|:
name|public
name|LabeledShape
block|{
name|Shape
operator|*
name|Inner
block|;
name|LoopShape
argument_list|()
operator|:
name|LabeledShape
argument_list|(
name|SK_Loop
argument_list|)
block|,
name|Inner
argument_list|(
argument|nullptr
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Shape *S
argument_list|)
block|{
return|return
name|S
operator|->
name|getKind
argument_list|()
operator|==
name|SK_Loop
return|;
block|}
expr|}
block|;  }
comment|// namespace Relooper
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

end_unit

