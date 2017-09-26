begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PtrUseVisitor.h - InstVisitors over a pointers uses ------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// This file provides a collection of visitors which walk the (instruction)
end_comment

begin_comment
comment|/// uses of a pointer. These visitors all provide the same essential behavior
end_comment

begin_comment
comment|/// as an InstVisitor with similar template-based flexibility and
end_comment

begin_comment
comment|/// implementation strategies.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These can be used, for example, to quickly analyze the uses of an alloca,
end_comment

begin_comment
comment|/// global variable, or function argument.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: Provide a variant which doesn't track offsets and is cheaper.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_PTRUSEVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_PTRUSEVISITOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InstVisitor.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IntrinsicInst.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|detail
block|{
comment|/// \brief Implementation of non-dependent functionality for \c PtrUseVisitor.
comment|///
comment|/// See \c PtrUseVisitor for the public interface and detailed comments about
comment|/// usage. This class is just a helper base class which is not templated and
comment|/// contains all common code to be shared between different instantiations of
comment|/// PtrUseVisitor.
name|class
name|PtrUseVisitorBase
block|{
name|public
label|:
comment|/// \brief This class provides information about the result of a visit.
comment|///
comment|/// After walking all the users (recursively) of a pointer, the basic
comment|/// infrastructure records some commonly useful information such as escape
comment|/// analysis and whether the visit completed or aborted early.
name|class
name|PtrInfo
block|{
name|public
label|:
name|PtrInfo
argument_list|()
operator|:
name|AbortedInfo
argument_list|(
name|nullptr
argument_list|,
name|false
argument_list|)
operator|,
name|EscapedInfo
argument_list|(
argument|nullptr
argument_list|,
argument|false
argument_list|)
block|{}
comment|/// \brief Reset the pointer info, clearing all state.
name|void
name|reset
argument_list|()
block|{
name|AbortedInfo
operator|.
name|setPointer
argument_list|(
name|nullptr
argument_list|)
block|;
name|AbortedInfo
operator|.
name|setInt
argument_list|(
name|false
argument_list|)
block|;
name|EscapedInfo
operator|.
name|setPointer
argument_list|(
name|nullptr
argument_list|)
block|;
name|EscapedInfo
operator|.
name|setInt
argument_list|(
name|false
argument_list|)
block|;     }
comment|/// \brief Did we abort the visit early?
name|bool
name|isAborted
argument_list|()
specifier|const
block|{
return|return
name|AbortedInfo
operator|.
name|getInt
argument_list|()
return|;
block|}
comment|/// \brief Is the pointer escaped at some point?
name|bool
name|isEscaped
argument_list|()
specifier|const
block|{
return|return
name|EscapedInfo
operator|.
name|getInt
argument_list|()
return|;
block|}
comment|/// \brief Get the instruction causing the visit to abort.
comment|/// \returns a pointer to the instruction causing the abort if one is
comment|/// available; otherwise returns null.
name|Instruction
operator|*
name|getAbortingInst
argument_list|()
specifier|const
block|{
return|return
name|AbortedInfo
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// \brief Get the instruction causing the pointer to escape.
comment|/// \returns a pointer to the instruction which escapes the pointer if one
comment|/// is available; otherwise returns null.
name|Instruction
operator|*
name|getEscapingInst
argument_list|()
specifier|const
block|{
return|return
name|EscapedInfo
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// \brief Mark the visit as aborted. Intended for use in a void return.
comment|/// \param I The instruction which caused the visit to abort, if available.
name|void
name|setAborted
parameter_list|(
name|Instruction
modifier|*
name|I
init|=
name|nullptr
parameter_list|)
block|{
name|AbortedInfo
operator|.
name|setInt
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|AbortedInfo
operator|.
name|setPointer
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Mark the pointer as escaped. Intended for use in a void return.
comment|/// \param I The instruction which escapes the pointer, if available.
name|void
name|setEscaped
parameter_list|(
name|Instruction
modifier|*
name|I
init|=
name|nullptr
parameter_list|)
block|{
name|EscapedInfo
operator|.
name|setInt
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|EscapedInfo
operator|.
name|setPointer
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Mark the pointer as escaped, and the visit as aborted. Intended
comment|/// for use in a void return.
comment|/// \param I The instruction which both escapes the pointer and aborts the
comment|/// visit, if available.
name|void
name|setEscapedAndAborted
parameter_list|(
name|Instruction
modifier|*
name|I
init|=
name|nullptr
parameter_list|)
block|{
name|setEscaped
argument_list|(
name|I
argument_list|)
expr_stmt|;
name|setAborted
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
name|private
label|:
name|PointerIntPair
operator|<
name|Instruction
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|AbortedInfo
operator|,
name|EscapedInfo
expr_stmt|;
block|}
empty_stmt|;
name|protected
label|:
specifier|const
name|DataLayout
modifier|&
name|DL
decl_stmt|;
comment|/// \name Visitation infrastructure
comment|/// @{
comment|/// \brief The info collected about the pointer being visited thus far.
name|PtrInfo
name|PI
decl_stmt|;
comment|/// \brief A struct of the data needed to visit a particular use.
comment|///
comment|/// This is used to maintain a worklist fo to-visit uses. This is used to
comment|/// make the visit be iterative rather than recursive.
struct|struct
name|UseToVisit
block|{
typedef|typedef
name|PointerIntPair
operator|<
name|Use
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|UseAndIsOffsetKnownPair
expr_stmt|;
name|UseAndIsOffsetKnownPair
name|UseAndIsOffsetKnown
decl_stmt|;
name|APInt
name|Offset
decl_stmt|;
block|}
struct|;
comment|/// \brief The worklist of to-visit uses.
name|SmallVector
operator|<
name|UseToVisit
operator|,
literal|8
operator|>
name|Worklist
expr_stmt|;
comment|/// \brief A set of visited uses to break cycles in unreachable code.
name|SmallPtrSet
operator|<
name|Use
operator|*
operator|,
literal|8
operator|>
name|VisitedUses
expr_stmt|;
comment|/// @}
comment|/// \name Per-visit state
comment|/// This state is reset for each instruction visited.
comment|/// @{
comment|/// \brief The use currently being visited.
name|Use
modifier|*
name|U
decl_stmt|;
comment|/// \brief True if we have a known constant offset for the use currently
comment|/// being visited.
name|bool
name|IsOffsetKnown
decl_stmt|;
comment|/// \brief The constant offset of the use if that is known.
name|APInt
name|Offset
decl_stmt|;
comment|/// @}
comment|/// Note that the constructor is protected because this class must be a base
comment|/// class, we can't create instances directly of this class.
name|PtrUseVisitorBase
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
operator|:
name|DL
argument_list|(
argument|DL
argument_list|)
block|{}
comment|/// \brief Enqueue the users of this instruction in the visit worklist.
comment|///
comment|/// This will visit the users with the same offset of the current visit
comment|/// (including an unknown offset if that is the current state).
name|void
name|enqueueUsers
argument_list|(
name|Instruction
operator|&
name|I
argument_list|)
expr_stmt|;
comment|/// \brief Walk the operands of a GEP and adjust the offset as appropriate.
comment|///
comment|/// This routine does the heavy lifting of the pointer walk by computing
comment|/// offsets and looking through GEPs.
name|bool
name|adjustOffsetForGEP
parameter_list|(
name|GetElementPtrInst
modifier|&
name|GEPI
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
comment|// end namespace detail
comment|/// \brief A base class for visitors over the uses of a pointer value.
comment|///
comment|/// Once constructed, a user can call \c visit on a pointer value, and this
comment|/// will walk its uses and visit each instruction using an InstVisitor. It also
comment|/// provides visit methods which will recurse through any pointer-to-pointer
comment|/// transformations such as GEPs and bitcasts.
comment|///
comment|/// During the visit, the current Use* being visited is available to the
comment|/// subclass, as well as the current offset from the original base pointer if
comment|/// known.
comment|///
comment|/// The recursive visit of uses is accomplished with a worklist, so the only
comment|/// ordering guarantee is that an instruction is visited before any uses of it
comment|/// are visited. Note that this does *not* mean before any of its users are
comment|/// visited! This is because users can be visited multiple times due to
comment|/// multiple, different uses of pointers derived from the same base.
comment|///
comment|/// A particular Use will only be visited once, but a User may be visited
comment|/// multiple times, once per Use. This visits may notably have different
comment|/// offsets.
comment|///
comment|/// All visit methods on the underlying InstVisitor return a boolean. This
comment|/// return short-circuits the visit, stopping it immediately.
comment|///
comment|/// FIXME: Generalize this for all values rather than just instructions.
name|template
operator|<
name|typename
name|DerivedT
operator|>
name|class
name|PtrUseVisitor
operator|:
name|protected
name|InstVisitor
operator|<
name|DerivedT
operator|>
operator|,
name|public
name|detail
operator|::
name|PtrUseVisitorBase
block|{
name|friend
name|class
name|InstVisitor
operator|<
name|DerivedT
operator|>
block|;
typedef|typedef
name|InstVisitor
operator|<
name|DerivedT
operator|>
name|Base
expr_stmt|;
name|public
operator|:
name|PtrUseVisitor
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
operator|:
name|PtrUseVisitorBase
argument_list|(
argument|DL
argument_list|)
block|{
name|static_assert
argument_list|(
name|std
operator|::
name|is_base_of
operator|<
name|PtrUseVisitor
argument_list|,
name|DerivedT
operator|>
operator|::
name|value
argument_list|,
literal|"Must pass the derived type to this template!"
argument_list|)
block|;   }
comment|/// \brief Recursively visit the uses of the given pointer.
comment|/// \returns An info struct about the pointer. See \c PtrInfo for details.
name|PtrInfo
name|visitPtr
argument_list|(
argument|Instruction&I
argument_list|)
block|{
comment|// This must be a pointer type. Get an integer type suitable to hold
comment|// offsets on this pointer.
comment|// FIXME: Support a vector of pointers.
name|assert
argument_list|(
name|I
operator|.
name|getType
argument_list|()
operator|->
name|isPointerTy
argument_list|()
argument_list|)
block|;
name|IntegerType
operator|*
name|IntPtrTy
operator|=
name|cast
operator|<
name|IntegerType
operator|>
operator|(
name|DL
operator|.
name|getIntPtrType
argument_list|(
name|I
operator|.
name|getType
argument_list|()
argument_list|)
operator|)
block|;
name|IsOffsetKnown
operator|=
name|true
block|;
name|Offset
operator|=
name|APInt
argument_list|(
name|IntPtrTy
operator|->
name|getBitWidth
argument_list|()
argument_list|,
literal|0
argument_list|)
block|;
name|PI
operator|.
name|reset
argument_list|()
block|;
comment|// Enqueue the uses of this pointer.
name|enqueueUsers
argument_list|(
name|I
argument_list|)
block|;
comment|// Visit all the uses off the worklist until it is empty.
while|while
condition|(
operator|!
name|Worklist
operator|.
name|empty
argument_list|()
condition|)
block|{
name|UseToVisit
name|ToVisit
init|=
name|Worklist
operator|.
name|pop_back_val
argument_list|()
decl_stmt|;
name|U
operator|=
name|ToVisit
operator|.
name|UseAndIsOffsetKnown
operator|.
name|getPointer
argument_list|()
expr_stmt|;
name|IsOffsetKnown
operator|=
name|ToVisit
operator|.
name|UseAndIsOffsetKnown
operator|.
name|getInt
argument_list|()
expr_stmt|;
if|if
condition|(
name|IsOffsetKnown
condition|)
name|Offset
operator|=
name|std
operator|::
name|move
argument_list|(
name|ToVisit
operator|.
name|Offset
argument_list|)
expr_stmt|;
name|Instruction
modifier|*
name|I
init|=
name|cast
operator|<
name|Instruction
operator|>
operator|(
name|U
operator|->
name|getUser
argument_list|()
operator|)
decl_stmt|;
name|static_cast
operator|<
name|DerivedT
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|visit
argument_list|(
name|I
argument_list|)
expr_stmt|;
if|if
condition|(
name|PI
operator|.
name|isAborted
argument_list|()
condition|)
break|break;
block|}
return|return
name|PI
return|;
block|}
name|protected
label|:
name|void
name|visitStoreInst
parameter_list|(
name|StoreInst
modifier|&
name|SI
parameter_list|)
block|{
if|if
condition|(
name|SI
operator|.
name|getValueOperand
argument_list|()
operator|==
name|U
operator|->
name|get
argument_list|()
condition|)
name|PI
operator|.
name|setEscaped
argument_list|(
operator|&
name|SI
argument_list|)
expr_stmt|;
block|}
name|void
name|visitBitCastInst
parameter_list|(
name|BitCastInst
modifier|&
name|BC
parameter_list|)
block|{
name|enqueueUsers
argument_list|(
name|BC
argument_list|)
expr_stmt|;
block|}
name|void
name|visitPtrToIntInst
parameter_list|(
name|PtrToIntInst
modifier|&
name|I
parameter_list|)
block|{
name|PI
operator|.
name|setEscaped
argument_list|(
operator|&
name|I
argument_list|)
expr_stmt|;
block|}
name|void
name|visitGetElementPtrInst
parameter_list|(
name|GetElementPtrInst
modifier|&
name|GEPI
parameter_list|)
block|{
if|if
condition|(
name|GEPI
operator|.
name|use_empty
argument_list|()
condition|)
return|return;
comment|// If we can't walk the GEP, clear the offset.
if|if
condition|(
operator|!
name|adjustOffsetForGEP
argument_list|(
name|GEPI
argument_list|)
condition|)
block|{
name|IsOffsetKnown
operator|=
name|false
expr_stmt|;
name|Offset
operator|=
name|APInt
argument_list|()
expr_stmt|;
block|}
comment|// Enqueue the users now that the offset has been adjusted.
name|enqueueUsers
argument_list|(
name|GEPI
argument_list|)
expr_stmt|;
block|}
comment|// No-op intrinsics which we know don't escape the pointer to to logic in
comment|// some other function.
name|void
name|visitDbgInfoIntrinsic
parameter_list|(
name|DbgInfoIntrinsic
modifier|&
name|I
parameter_list|)
block|{}
name|void
name|visitMemIntrinsic
parameter_list|(
name|MemIntrinsic
modifier|&
name|I
parameter_list|)
block|{}
name|void
name|visitIntrinsicInst
parameter_list|(
name|IntrinsicInst
modifier|&
name|II
parameter_list|)
block|{
switch|switch
condition|(
name|II
operator|.
name|getIntrinsicID
argument_list|()
condition|)
block|{
default|default:
return|return
name|Base
operator|::
name|visitIntrinsicInst
argument_list|(
name|II
argument_list|)
return|;
case|case
name|Intrinsic
operator|::
name|lifetime_start
case|:
case|case
name|Intrinsic
operator|::
name|lifetime_end
case|:
return|return;
comment|// No-op intrinsics.
block|}
block|}
comment|// Generically, arguments to calls and invokes escape the pointer to some
comment|// other function. Mark that.
name|void
name|visitCallSite
parameter_list|(
name|CallSite
name|CS
parameter_list|)
block|{
name|PI
operator|.
name|setEscaped
argument_list|(
name|CS
operator|.
name|getInstruction
argument_list|()
argument_list|)
expr_stmt|;
name|Base
operator|::
name|visitCallSite
argument_list|(
name|CS
argument_list|)
expr_stmt|;
block|}
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

