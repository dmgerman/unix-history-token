begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MemorySSA.h - Build Memory SSA ---------------------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file exposes an interface to building/using memory SSA to
end_comment

begin_comment
comment|/// walk memory instructions using a use/def graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory SSA class builds an SSA form that links together memory access
end_comment

begin_comment
comment|/// instructions such as loads, stores, atomics, and calls. Additionally, it
end_comment

begin_comment
comment|/// does a trivial form of "heap versioning" Every time the memory state changes
end_comment

begin_comment
comment|/// in the program, we generate a new heap version. It generates
end_comment

begin_comment
comment|/// MemoryDef/Uses/Phis that are overlayed on top of the existing instructions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// As a trivial example,
end_comment

begin_comment
comment|/// define i32 @main() #0 {
end_comment

begin_comment
comment|/// entry:
end_comment

begin_comment
comment|///   %call = call noalias i8* @_Znwm(i64 4) #2
end_comment

begin_comment
comment|///   %0 = bitcast i8* %call to i32*
end_comment

begin_comment
comment|///   %call1 = call noalias i8* @_Znwm(i64 4) #2
end_comment

begin_comment
comment|///   %1 = bitcast i8* %call1 to i32*
end_comment

begin_comment
comment|///   store i32 5, i32* %0, align 4
end_comment

begin_comment
comment|///   store i32 7, i32* %1, align 4
end_comment

begin_comment
comment|///   %2 = load i32* %0, align 4
end_comment

begin_comment
comment|///   %3 = load i32* %1, align 4
end_comment

begin_comment
comment|///   %add = add nsw i32 %2, %3
end_comment

begin_comment
comment|///   ret i32 %add
end_comment

begin_comment
comment|/// }
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Will become
end_comment

begin_comment
comment|/// define i32 @main() #0 {
end_comment

begin_comment
comment|/// entry:
end_comment

begin_comment
comment|///   ; 1 = MemoryDef(0)
end_comment

begin_comment
comment|///   %call = call noalias i8* @_Znwm(i64 4) #3
end_comment

begin_comment
comment|///   %2 = bitcast i8* %call to i32*
end_comment

begin_comment
comment|///   ; 2 = MemoryDef(1)
end_comment

begin_comment
comment|///   %call1 = call noalias i8* @_Znwm(i64 4) #3
end_comment

begin_comment
comment|///   %4 = bitcast i8* %call1 to i32*
end_comment

begin_comment
comment|///   ; 3 = MemoryDef(2)
end_comment

begin_comment
comment|///   store i32 5, i32* %2, align 4
end_comment

begin_comment
comment|///   ; 4 = MemoryDef(3)
end_comment

begin_comment
comment|///   store i32 7, i32* %4, align 4
end_comment

begin_comment
comment|///   ; MemoryUse(3)
end_comment

begin_comment
comment|///   %7 = load i32* %2, align 4
end_comment

begin_comment
comment|///   ; MemoryUse(4)
end_comment

begin_comment
comment|///   %8 = load i32* %4, align 4
end_comment

begin_comment
comment|///   %add = add nsw i32 %7, %8
end_comment

begin_comment
comment|///   ret i32 %add
end_comment

begin_comment
comment|/// }
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Given this form, all the stores that could ever effect the load at %8 can be
end_comment

begin_comment
comment|/// gotten by using the MemoryUse associated with it, and walking from use to
end_comment

begin_comment
comment|/// def until you hit the top of the function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Each def also has a list of users associated with it, so you can walk from
end_comment

begin_comment
comment|/// both def to users, and users to defs. Note that we disambiguate MemoryUses,
end_comment

begin_comment
comment|/// but not the RHS of MemoryDefs. You can see this above at %7, which would
end_comment

begin_comment
comment|/// otherwise be a MemoryUse(4). Being disambiguated means that for a given
end_comment

begin_comment
comment|/// store, all the MemoryUses on its use lists are may-aliases of that store
end_comment

begin_comment
comment|/// (but the MemoryDefs on its use list may not be).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// MemoryDefs are not disambiguated because it would require multiple reaching
end_comment

begin_comment
comment|/// definitions, which would require multiple phis, and multiple memoryaccesses
end_comment

begin_comment
comment|/// per instruction.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_MEMORYSSA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_MEMORYSSA_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/GraphTraits.h"
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
file|"llvm/ADT/ilist.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/MemoryLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/PHITransAddr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DerivedUser.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Dominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/OperandTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Use.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/User.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|MemoryAccess
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|namespace
name|MSSAHelpers
block|{
struct|struct
name|AllAccessTag
block|{}
struct|;
struct|struct
name|DefsOnlyTag
block|{}
struct|;
block|}
enum|enum
block|{
comment|// Used to signify what the default invalid ID is for MemoryAccess's
comment|// getID()
name|INVALID_MEMORYACCESS_ID
init|=
literal|0
block|}
enum|;
name|template
operator|<
name|class
name|T
operator|>
name|class
name|memoryaccess_def_iterator_base
expr_stmt|;
name|using
name|memoryaccess_def_iterator
init|=
name|memoryaccess_def_iterator_base
operator|<
name|MemoryAccess
operator|>
decl_stmt|;
name|using
name|const_memoryaccess_def_iterator
init|=
name|memoryaccess_def_iterator_base
operator|<
specifier|const
name|MemoryAccess
operator|>
decl_stmt|;
comment|// \brief The base for all memory accesses. All memory accesses in a block are
comment|// linked together using an intrusive list.
name|class
name|MemoryAccess
range|:
name|public
name|DerivedUser
decl_stmt|,
name|public
name|ilist_node
decl|<
name|MemoryAccess
decl_stmt|,
name|ilist_tag
decl|<
name|MSSAHelpers
decl|::
name|AllAccessTag
decl|>>
decl_stmt|,
name|public
name|ilist_node
decl|<
name|MemoryAccess
decl_stmt|,
name|ilist_tag
decl|<
name|MSSAHelpers
decl|::
name|DefsOnlyTag
decl|>>
block|{
name|public
label|:
name|using
name|AllAccessType
init|=
name|ilist_node
operator|<
name|MemoryAccess
decl_stmt|,
name|ilist_tag
decl|<
name|MSSAHelpers
decl|::
name|AllAccessTag
decl|>>
decl_stmt|;
name|using
name|DefsOnlyType
init|=
name|ilist_node
operator|<
name|MemoryAccess
decl_stmt|,
name|ilist_tag
decl|<
name|MSSAHelpers
decl|::
name|DefsOnlyTag
decl|>>
decl_stmt|;
comment|// Methods for support type inquiry through isa, cast, and
comment|// dyn_cast
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
name|unsigned
name|ID
init|=
name|V
operator|->
name|getValueID
argument_list|()
decl_stmt|;
return|return
name|ID
operator|==
name|MemoryUseVal
operator|||
name|ID
operator|==
name|MemoryPhiVal
operator|||
name|ID
operator|==
name|MemoryDefVal
return|;
block|}
name|MemoryAccess
argument_list|(
specifier|const
name|MemoryAccess
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|MemoryAccess
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MemoryAccess
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|size_t
parameter_list|)
init|=
name|delete
function_decl|;
name|BasicBlock
operator|*
name|getBlock
argument_list|()
specifier|const
block|{
return|return
name|Block
return|;
block|}
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief The user iterators for a memory access
typedef|typedef
name|user_iterator
name|iterator
typedef|;
typedef|typedef
name|const_user_iterator
name|const_iterator
typedef|;
comment|/// \brief This iterator walks over all of the defs in a given
comment|/// MemoryAccess. For MemoryPhi nodes, this walks arguments. For
comment|/// MemoryUse/MemoryDef, this walks the defining access.
name|memoryaccess_def_iterator
name|defs_begin
parameter_list|()
function_decl|;
name|const_memoryaccess_def_iterator
name|defs_begin
argument_list|()
specifier|const
expr_stmt|;
name|memoryaccess_def_iterator
name|defs_end
parameter_list|()
function_decl|;
name|const_memoryaccess_def_iterator
name|defs_end
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Get the iterators for the all access list and the defs only list
comment|/// We default to the all access list.
name|AllAccessType
operator|::
name|self_iterator
name|getIterator
argument_list|()
block|{
return|return
name|this
operator|->
name|AllAccessType
operator|::
name|getIterator
argument_list|()
return|;
block|}
name|AllAccessType
operator|::
name|const_self_iterator
name|getIterator
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|AllAccessType
operator|::
name|getIterator
argument_list|()
return|;
block|}
name|AllAccessType
operator|::
name|reverse_self_iterator
name|getReverseIterator
argument_list|()
block|{
return|return
name|this
operator|->
name|AllAccessType
operator|::
name|getReverseIterator
argument_list|()
return|;
block|}
name|AllAccessType
operator|::
name|const_reverse_self_iterator
name|getReverseIterator
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|AllAccessType
operator|::
name|getReverseIterator
argument_list|()
return|;
block|}
name|DefsOnlyType
operator|::
name|self_iterator
name|getDefsIterator
argument_list|()
block|{
return|return
name|this
operator|->
name|DefsOnlyType
operator|::
name|getIterator
argument_list|()
return|;
block|}
name|DefsOnlyType
operator|::
name|const_self_iterator
name|getDefsIterator
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|DefsOnlyType
operator|::
name|getIterator
argument_list|()
return|;
block|}
name|DefsOnlyType
operator|::
name|reverse_self_iterator
name|getReverseDefsIterator
argument_list|()
block|{
return|return
name|this
operator|->
name|DefsOnlyType
operator|::
name|getReverseIterator
argument_list|()
return|;
block|}
name|DefsOnlyType
operator|::
name|const_reverse_self_iterator
name|getReverseDefsIterator
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|DefsOnlyType
operator|::
name|getReverseIterator
argument_list|()
return|;
block|}
name|protected
label|:
name|friend
name|class
name|MemorySSA
decl_stmt|;
name|friend
name|class
name|MemoryUseOrDef
decl_stmt|;
name|friend
name|class
name|MemoryUse
decl_stmt|;
name|friend
name|class
name|MemoryDef
decl_stmt|;
name|friend
name|class
name|MemoryPhi
decl_stmt|;
comment|/// \brief Used by MemorySSA to change the block of a MemoryAccess when it is
comment|/// moved.
name|void
name|setBlock
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
name|Block
operator|=
name|BB
expr_stmt|;
block|}
comment|/// \brief Used for debugging and tracking things about MemoryAccesses.
comment|/// Guaranteed unique among MemoryAccesses, no guarantees otherwise.
specifier|inline
name|unsigned
name|getID
argument_list|()
specifier|const
expr_stmt|;
name|MemoryAccess
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned Vty
argument_list|,
argument|DeleteValueTy DeleteValue
argument_list|,
argument|BasicBlock *BB
argument_list|,
argument|unsigned NumOperands
argument_list|)
block|:
name|DerivedUser
argument_list|(
name|Type
operator|::
name|getVoidTy
argument_list|(
name|C
argument_list|)
argument_list|,
name|Vty
argument_list|,
name|nullptr
argument_list|,
name|NumOperands
argument_list|,
name|DeleteValue
argument_list|)
operator|,
name|Block
argument_list|(
argument|BB
argument_list|)
block|{}
name|private
operator|:
name|BasicBlock
operator|*
name|Block
expr_stmt|;
block|}
empty_stmt|;
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
name|MemoryAccess
operator|&
name|MA
operator|)
block|{
name|MA
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
comment|/// \brief Class that has the common methods + fields of memory uses/defs. It's
comment|/// a little awkward to have, but there are many cases where we want either a
comment|/// use or def, and there are many cases where uses are needed (defs aren't
comment|/// acceptable), and vice-versa.
comment|///
comment|/// This class should never be instantiated directly; make a MemoryUse or
comment|/// MemoryDef instead.
name|class
name|MemoryUseOrDef
range|:
name|public
name|MemoryAccess
block|{
name|public
operator|:
name|void
operator|*
name|operator
name|new
argument_list|(
name|size_t
argument_list|)
operator|=
name|delete
block|;
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|MemoryAccess
argument_list|)
block|;
comment|/// \brief Get the instruction that this MemoryUse represents.
name|Instruction
operator|*
name|getMemoryInst
argument_list|()
specifier|const
block|{
return|return
name|MemoryInst
return|;
block|}
comment|/// \brief Get the access that produces the memory state used by this Use.
name|MemoryAccess
operator|*
name|getDefiningAccess
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *MA
argument_list|)
block|{
return|return
name|MA
operator|->
name|getValueID
argument_list|()
operator|==
name|MemoryUseVal
operator|||
name|MA
operator|->
name|getValueID
argument_list|()
operator|==
name|MemoryDefVal
return|;
block|}
comment|// Sadly, these have to be public because they are needed in some of the
comment|// iterators.
specifier|inline
name|bool
name|isOptimized
argument_list|()
specifier|const
block|;
specifier|inline
name|MemoryAccess
operator|*
name|getOptimized
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|setOptimized
argument_list|(
name|MemoryAccess
operator|*
argument_list|)
block|;
comment|/// \brief Reset the ID of what this MemoryUse was optimized to, causing it to
comment|/// be rewalked by the walker if necessary.
comment|/// This really should only be called by tests.
specifier|inline
name|void
name|resetOptimized
argument_list|()
block|;
name|protected
operator|:
name|friend
name|class
name|MemorySSA
block|;
name|friend
name|class
name|MemorySSAUpdater
block|;
name|MemoryUseOrDef
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|MemoryAccess *DMA
argument_list|,
argument|unsigned Vty
argument_list|,
argument|DeleteValueTy DeleteValue
argument_list|,
argument|Instruction *MI
argument_list|,
argument|BasicBlock *BB
argument_list|)
operator|:
name|MemoryAccess
argument_list|(
name|C
argument_list|,
name|Vty
argument_list|,
name|DeleteValue
argument_list|,
name|BB
argument_list|,
literal|1
argument_list|)
block|,
name|MemoryInst
argument_list|(
argument|MI
argument_list|)
block|{
name|setDefiningAccess
argument_list|(
name|DMA
argument_list|)
block|;   }
name|void
name|setDefiningAccess
argument_list|(
argument|MemoryAccess *DMA
argument_list|,
argument|bool Optimized = false
argument_list|)
block|{
if|if
condition|(
operator|!
name|Optimized
condition|)
block|{
name|setOperand
argument_list|(
literal|0
argument_list|,
name|DMA
argument_list|)
expr_stmt|;
return|return;
block|}
name|setOptimized
argument_list|(
name|DMA
argument_list|)
expr_stmt|;
block|}
name|private
operator|:
name|Instruction
operator|*
name|MemoryInst
block|; }
decl_stmt|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|MemoryUseOrDef
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
name|MemoryUseOrDef
operator|,
literal|1
operator|>
block|{}
expr_stmt|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|MemoryUseOrDef
argument_list|,
argument|MemoryAccess
argument_list|)
comment|/// \brief Represents read-only accesses to memory
comment|///
comment|/// In particular, the set of Instructions that will be represented by
comment|/// MemoryUse's is exactly the set of Instructions for which
comment|/// AliasAnalysis::getModRefInfo returns "Ref".
name|class
name|MemoryUse
name|final
range|:
name|public
name|MemoryUseOrDef
block|{
name|public
operator|:
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|MemoryAccess
argument_list|)
block|;
name|MemoryUse
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|MemoryAccess
operator|*
name|DMA
argument_list|,
name|Instruction
operator|*
name|MI
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|)
operator|:
name|MemoryUseOrDef
argument_list|(
name|C
argument_list|,
name|DMA
argument_list|,
name|MemoryUseVal
argument_list|,
name|deleteMe
argument_list|,
name|MI
argument_list|,
name|BB
argument_list|)
block|,
name|OptimizedID
argument_list|(
literal|0
argument_list|)
block|{}
comment|// allocate space for exactly one operand
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|)
block|{
return|return
name|User
operator|::
name|operator
name|new
argument_list|(
name|s
argument_list|,
literal|1
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *MA
argument_list|)
block|{
return|return
name|MA
operator|->
name|getValueID
argument_list|()
operator|==
name|MemoryUseVal
return|;
block|}
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
name|void
name|setOptimized
argument_list|(
argument|MemoryAccess *DMA
argument_list|)
block|{
name|OptimizedID
operator|=
name|DMA
operator|->
name|getID
argument_list|()
block|;
name|setOperand
argument_list|(
literal|0
argument_list|,
name|DMA
argument_list|)
block|;   }
name|bool
name|isOptimized
argument_list|()
specifier|const
block|{
return|return
name|getDefiningAccess
argument_list|()
operator|&&
name|OptimizedID
operator|==
name|getDefiningAccess
argument_list|()
operator|->
name|getID
argument_list|()
return|;
block|}
name|MemoryAccess
operator|*
name|getOptimized
argument_list|()
specifier|const
block|{
return|return
name|getDefiningAccess
argument_list|()
return|;
block|}
name|void
name|resetOptimized
argument_list|()
block|{
name|OptimizedID
operator|=
name|INVALID_MEMORYACCESS_ID
block|;   }
name|protected
operator|:
name|friend
name|class
name|MemorySSA
block|;
name|private
operator|:
specifier|static
name|void
name|deleteMe
argument_list|(
name|DerivedUser
operator|*
name|Self
argument_list|)
block|;
name|unsigned
name|int
name|OptimizedID
block|; }
decl_stmt|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|MemoryUse
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
name|MemoryUse
operator|,
literal|1
operator|>
block|{}
expr_stmt|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|MemoryUse
argument_list|,
argument|MemoryAccess
argument_list|)
comment|/// \brief Represents a read-write access to memory, whether it is a must-alias,
comment|/// or a may-alias.
comment|///
comment|/// In particular, the set of Instructions that will be represented by
comment|/// MemoryDef's is exactly the set of Instructions for which
comment|/// AliasAnalysis::getModRefInfo returns "Mod" or "ModRef".
comment|/// Note that, in order to provide def-def chains, all defs also have a use
comment|/// associated with them. This use points to the nearest reaching
comment|/// MemoryDef/MemoryPhi.
name|class
name|MemoryDef
name|final
range|:
name|public
name|MemoryUseOrDef
block|{
name|public
operator|:
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|MemoryAccess
argument_list|)
block|;
name|MemoryDef
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|MemoryAccess *DMA
argument_list|,
argument|Instruction *MI
argument_list|,
argument|BasicBlock *BB
argument_list|,
argument|unsigned Ver
argument_list|)
operator|:
name|MemoryUseOrDef
argument_list|(
name|C
argument_list|,
name|DMA
argument_list|,
name|MemoryDefVal
argument_list|,
name|deleteMe
argument_list|,
name|MI
argument_list|,
name|BB
argument_list|)
block|,
name|ID
argument_list|(
name|Ver
argument_list|)
block|,
name|Optimized
argument_list|(
name|nullptr
argument_list|)
block|,
name|OptimizedID
argument_list|(
argument|INVALID_MEMORYACCESS_ID
argument_list|)
block|{}
comment|// allocate space for exactly one operand
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|)
block|{
return|return
name|User
operator|::
name|operator
name|new
argument_list|(
name|s
argument_list|,
literal|1
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *MA
argument_list|)
block|{
return|return
name|MA
operator|->
name|getValueID
argument_list|()
operator|==
name|MemoryDefVal
return|;
block|}
name|void
name|setOptimized
argument_list|(
argument|MemoryAccess *MA
argument_list|)
block|{
name|Optimized
operator|=
name|MA
block|;
name|OptimizedID
operator|=
name|getDefiningAccess
argument_list|()
operator|->
name|getID
argument_list|()
block|;   }
name|MemoryAccess
operator|*
name|getOptimized
argument_list|()
specifier|const
block|{
return|return
name|Optimized
return|;
block|}
name|bool
name|isOptimized
argument_list|()
specifier|const
block|{
return|return
name|getOptimized
argument_list|()
operator|&&
name|getDefiningAccess
argument_list|()
operator|&&
name|OptimizedID
operator|==
name|getDefiningAccess
argument_list|()
operator|->
name|getID
argument_list|()
return|;
block|}
name|void
name|resetOptimized
argument_list|()
block|{
name|OptimizedID
operator|=
name|INVALID_MEMORYACCESS_ID
block|;   }
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
name|friend
name|class
name|MemorySSA
block|;
name|unsigned
name|getID
argument_list|()
specifier|const
block|{
return|return
name|ID
return|;
block|}
name|private
operator|:
specifier|static
name|void
name|deleteMe
argument_list|(
name|DerivedUser
operator|*
name|Self
argument_list|)
block|;
specifier|const
name|unsigned
name|ID
block|;
name|MemoryAccess
operator|*
name|Optimized
block|;
name|unsigned
name|int
name|OptimizedID
block|; }
decl_stmt|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|MemoryDef
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
name|MemoryDef
operator|,
literal|1
operator|>
block|{}
expr_stmt|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|MemoryDef
argument_list|,
argument|MemoryAccess
argument_list|)
comment|/// \brief Represents phi nodes for memory accesses.
comment|///
comment|/// These have the same semantic as regular phi nodes, with the exception that
comment|/// only one phi will ever exist in a given basic block.
comment|/// Guaranteeing one phi per block means guaranteeing there is only ever one
comment|/// valid reaching MemoryDef/MemoryPHI along each path to the phi node.
comment|/// This is ensured by not allowing disambiguation of the RHS of a MemoryDef or
comment|/// a MemoryPhi's operands.
comment|/// That is, given
comment|/// if (a) {
comment|///   store %a
comment|///   store %b
comment|/// }
comment|/// it *must* be transformed into
comment|/// if (a) {
comment|///    1 = MemoryDef(liveOnEntry)
comment|///    store %a
comment|///    2 = MemoryDef(1)
comment|///    store %b
comment|/// }
comment|/// and *not*
comment|/// if (a) {
comment|///    1 = MemoryDef(liveOnEntry)
comment|///    store %a
comment|///    2 = MemoryDef(liveOnEntry)
comment|///    store %b
comment|/// }
comment|/// even if the two stores do not conflict. Otherwise, both 1 and 2 reach the
comment|/// end of the branch, and if there are not two phi nodes, one will be
comment|/// disconnected completely from the SSA graph below that point.
comment|/// Because MemoryUse's do not generate new definitions, they do not have this
comment|/// issue.
name|class
name|MemoryPhi
name|final
range|:
name|public
name|MemoryAccess
block|{
comment|// allocate space for exactly zero operands
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|)
block|{
return|return
name|User
operator|::
name|operator
name|new
argument_list|(
name|s
argument_list|)
return|;
block|}
name|public
operator|:
comment|/// Provide fast operand accessors
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|MemoryAccess
argument_list|)
block|;
name|MemoryPhi
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|BasicBlock *BB
argument_list|,
argument|unsigned Ver
argument_list|,
argument|unsigned NumPreds =
literal|0
argument_list|)
operator|:
name|MemoryAccess
argument_list|(
name|C
argument_list|,
name|MemoryPhiVal
argument_list|,
name|deleteMe
argument_list|,
name|BB
argument_list|,
literal|0
argument_list|)
block|,
name|ID
argument_list|(
name|Ver
argument_list|)
block|,
name|ReservedSpace
argument_list|(
argument|NumPreds
argument_list|)
block|{
name|allocHungoffUses
argument_list|(
name|ReservedSpace
argument_list|)
block|;   }
comment|// Block iterator interface. This provides access to the list of incoming
comment|// basic blocks, which parallels the list of incoming values.
typedef|typedef
name|BasicBlock
modifier|*
modifier|*
name|block_iterator
typedef|;
typedef|typedef
name|BasicBlock
modifier|*
specifier|const
modifier|*
name|const_block_iterator
typedef|;
name|block_iterator
name|block_begin
parameter_list|()
block|{
name|auto
operator|*
name|Ref
operator|=
name|reinterpret_cast
operator|<
name|Use
operator|::
name|UserRef
operator|*
operator|>
operator|(
name|op_begin
argument_list|()
operator|+
name|ReservedSpace
operator|)
expr_stmt|;
return|return
name|reinterpret_cast
operator|<
name|block_iterator
operator|>
operator|(
name|Ref
operator|+
literal|1
operator|)
return|;
block|}
name|const_block_iterator
name|block_begin
argument_list|()
specifier|const
block|{
specifier|const
name|auto
operator|*
name|Ref
operator|=
name|reinterpret_cast
operator|<
specifier|const
name|Use
operator|::
name|UserRef
operator|*
operator|>
operator|(
name|op_begin
argument_list|()
operator|+
name|ReservedSpace
operator|)
block|;
return|return
name|reinterpret_cast
operator|<
name|const_block_iterator
operator|>
operator|(
name|Ref
operator|+
literal|1
operator|)
return|;
block|}
name|block_iterator
name|block_end
parameter_list|()
block|{
return|return
name|block_begin
argument_list|()
operator|+
name|getNumOperands
argument_list|()
return|;
block|}
name|const_block_iterator
name|block_end
argument_list|()
specifier|const
block|{
return|return
name|block_begin
argument_list|()
operator|+
name|getNumOperands
argument_list|()
return|;
block|}
name|iterator_range
operator|<
name|block_iterator
operator|>
name|blocks
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|block_begin
argument_list|()
argument_list|,
name|block_end
argument_list|()
argument_list|)
return|;
block|}
name|iterator_range
operator|<
name|const_block_iterator
operator|>
name|blocks
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|block_begin
argument_list|()
argument_list|,
name|block_end
argument_list|()
argument_list|)
return|;
block|}
name|op_range
name|incoming_values
parameter_list|()
block|{
return|return
name|operands
argument_list|()
return|;
block|}
name|const_op_range
name|incoming_values
argument_list|()
specifier|const
block|{
return|return
name|operands
argument_list|()
return|;
block|}
comment|/// \brief Return the number of incoming edges
name|unsigned
name|getNumIncomingValues
argument_list|()
specifier|const
block|{
return|return
name|getNumOperands
argument_list|()
return|;
block|}
comment|/// \brief Return incoming value number x
name|MemoryAccess
modifier|*
name|getIncomingValue
argument_list|(
name|unsigned
name|I
argument_list|)
decl|const
block|{
return|return
name|getOperand
argument_list|(
name|I
argument_list|)
return|;
block|}
name|void
name|setIncomingValue
parameter_list|(
name|unsigned
name|I
parameter_list|,
name|MemoryAccess
modifier|*
name|V
parameter_list|)
block|{
name|assert
argument_list|(
name|V
operator|&&
literal|"PHI node got a null value!"
argument_list|)
expr_stmt|;
name|setOperand
argument_list|(
name|I
argument_list|,
name|V
argument_list|)
expr_stmt|;
block|}
specifier|static
name|unsigned
name|getOperandNumForIncomingValue
parameter_list|(
name|unsigned
name|I
parameter_list|)
block|{
return|return
name|I
return|;
block|}
specifier|static
name|unsigned
name|getIncomingValueNumForOperand
parameter_list|(
name|unsigned
name|I
parameter_list|)
block|{
return|return
name|I
return|;
block|}
comment|/// \brief Return incoming basic block number @p i.
name|BasicBlock
modifier|*
name|getIncomingBlock
argument_list|(
name|unsigned
name|I
argument_list|)
decl|const
block|{
return|return
name|block_begin
argument_list|()
index|[
name|I
index|]
return|;
block|}
comment|/// \brief Return incoming basic block corresponding
comment|/// to an operand of the PHI.
name|BasicBlock
modifier|*
name|getIncomingBlock
argument_list|(
specifier|const
name|Use
operator|&
name|U
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|this
operator|==
name|U
operator|.
name|getUser
argument_list|()
operator|&&
literal|"Iterator doesn't point to PHI's Uses?"
argument_list|)
expr_stmt|;
return|return
name|getIncomingBlock
argument_list|(
name|unsigned
argument_list|(
operator|&
name|U
operator|-
name|op_begin
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
comment|/// \brief Return incoming basic block corresponding
comment|/// to value use iterator.
name|BasicBlock
modifier|*
name|getIncomingBlock
argument_list|(
name|MemoryAccess
operator|::
name|const_user_iterator
name|I
argument_list|)
decl|const
block|{
return|return
name|getIncomingBlock
argument_list|(
name|I
operator|.
name|getUse
argument_list|()
argument_list|)
return|;
block|}
name|void
name|setIncomingBlock
parameter_list|(
name|unsigned
name|I
parameter_list|,
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
name|assert
argument_list|(
name|BB
operator|&&
literal|"PHI node got a null basic block!"
argument_list|)
expr_stmt|;
name|block_begin
argument_list|()
index|[
name|I
index|]
operator|=
name|BB
expr_stmt|;
block|}
comment|/// \brief Add an incoming value to the end of the PHI list
name|void
name|addIncoming
parameter_list|(
name|MemoryAccess
modifier|*
name|V
parameter_list|,
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
if|if
condition|(
name|getNumOperands
argument_list|()
operator|==
name|ReservedSpace
condition|)
name|growOperands
argument_list|()
expr_stmt|;
comment|// Get more space!
comment|// Initialize some new operands.
name|setNumHungOffUseOperands
argument_list|(
name|getNumOperands
argument_list|()
operator|+
literal|1
argument_list|)
expr_stmt|;
name|setIncomingValue
argument_list|(
name|getNumOperands
argument_list|()
operator|-
literal|1
argument_list|,
name|V
argument_list|)
expr_stmt|;
name|setIncomingBlock
argument_list|(
name|getNumOperands
argument_list|()
operator|-
literal|1
argument_list|,
name|BB
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Return the first index of the specified basic
comment|/// block in the value list for this PHI.  Returns -1 if no instance.
name|int
name|getBasicBlockIndex
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
for|for
control|(
name|unsigned
name|I
init|=
literal|0
init|,
name|E
init|=
name|getNumOperands
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
if|if
condition|(
name|block_begin
argument_list|()
index|[
name|I
index|]
operator|==
name|BB
condition|)
return|return
name|I
return|;
return|return
operator|-
literal|1
return|;
block|}
name|Value
modifier|*
name|getIncomingValueForBlock
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
name|int
name|Idx
init|=
name|getBasicBlockIndex
argument_list|(
name|BB
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|Idx
operator|>=
literal|0
operator|&&
literal|"Invalid basic block argument!"
argument_list|)
expr_stmt|;
return|return
name|getIncomingValue
argument_list|(
name|Idx
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|MemoryPhiVal
return|;
block|}
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|getID
argument_list|()
specifier|const
block|{
return|return
name|ID
return|;
block|}
name|protected
label|:
name|friend
name|class
name|MemorySSA
decl_stmt|;
comment|/// \brief this is more complicated than the generic
comment|/// User::allocHungoffUses, because we have to allocate Uses for the incoming
comment|/// values and pointers to the incoming blocks, all in one allocation.
name|void
name|allocHungoffUses
parameter_list|(
name|unsigned
name|N
parameter_list|)
block|{
name|User
operator|::
name|allocHungoffUses
argument_list|(
name|N
argument_list|,
comment|/* IsPhi */
name|true
argument_list|)
expr_stmt|;
block|}
name|private
label|:
comment|// For debugging only
specifier|const
name|unsigned
name|ID
decl_stmt|;
name|unsigned
name|ReservedSpace
decl_stmt|;
comment|/// \brief This grows the operand list in response to a push_back style of
comment|/// operation.  This grows the number of ops by 1.5 times.
name|void
name|growOperands
parameter_list|()
block|{
name|unsigned
name|E
init|=
name|getNumOperands
argument_list|()
decl_stmt|;
comment|// 2 op PHI nodes are VERY common, so reserve at least enough for that.
name|ReservedSpace
operator|=
name|std
operator|::
name|max
argument_list|(
name|E
operator|+
name|E
operator|/
literal|2
argument_list|,
literal|2u
argument_list|)
expr_stmt|;
name|growHungoffUses
argument_list|(
name|ReservedSpace
argument_list|,
comment|/* IsPhi */
name|true
argument_list|)
expr_stmt|;
block|}
specifier|static
name|void
name|deleteMe
parameter_list|(
name|DerivedUser
modifier|*
name|Self
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
specifier|inline
name|unsigned
name|MemoryAccess
operator|::
name|getID
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|isa
operator|<
name|MemoryDef
operator|>
operator|(
name|this
operator|)
operator|||
name|isa
operator|<
name|MemoryPhi
operator|>
operator|(
name|this
operator|)
operator|)
operator|&&
literal|"only memory defs and phis have ids"
argument_list|)
block|;
if|if
condition|(
specifier|const
specifier|auto
modifier|*
name|MD
init|=
name|dyn_cast
operator|<
name|MemoryDef
operator|>
operator|(
name|this
operator|)
condition|)
return|return
name|MD
operator|->
name|getID
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|cast
operator|<
name|MemoryPhi
operator|>
operator|(
name|this
operator|)
operator|->
name|getID
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}  inline
name|bool
name|MemoryUseOrDef
operator|::
name|isOptimized
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
specifier|auto
modifier|*
name|MD
init|=
name|dyn_cast
operator|<
name|MemoryDef
operator|>
operator|(
name|this
operator|)
condition|)
return|return
name|MD
operator|->
name|isOptimized
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|cast
operator|<
name|MemoryUse
operator|>
operator|(
name|this
operator|)
operator|->
name|isOptimized
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}  inline
name|MemoryAccess
operator|*
name|MemoryUseOrDef
operator|::
name|getOptimized
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
specifier|auto
modifier|*
name|MD
init|=
name|dyn_cast
operator|<
name|MemoryDef
operator|>
operator|(
name|this
operator|)
condition|)
return|return
name|MD
operator|->
name|getOptimized
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|cast
operator|<
name|MemoryUse
operator|>
operator|(
name|this
operator|)
operator|->
name|getOptimized
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}  inline
name|void
name|MemoryUseOrDef
operator|::
name|setOptimized
argument_list|(
argument|MemoryAccess *MA
argument_list|)
block|{
if|if
condition|(
name|auto
operator|*
name|MD
operator|=
name|dyn_cast
operator|<
name|MemoryDef
operator|>
operator|(
name|this
operator|)
condition|)
name|MD
operator|->
name|setOptimized
argument_list|(
name|MA
argument_list|)
expr_stmt|;
else|else
name|cast
operator|<
name|MemoryUse
operator|>
operator|(
name|this
operator|)
operator|->
name|setOptimized
argument_list|(
name|MA
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|void
name|MemoryUseOrDef
operator|::
name|resetOptimized
argument_list|()
block|{
if|if
condition|(
name|auto
operator|*
name|MD
operator|=
name|dyn_cast
operator|<
name|MemoryDef
operator|>
operator|(
name|this
operator|)
condition|)
name|MD
operator|->
name|resetOptimized
argument_list|()
expr_stmt|;
else|else
name|cast
operator|<
name|MemoryUse
operator|>
operator|(
name|this
operator|)
operator|->
name|resetOptimized
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|MemoryPhi
operator|>
operator|:
name|public
name|HungoffOperandTraits
operator|<
literal|2
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_macro
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|MemoryPhi
argument_list|,
argument|MemoryAccess
argument_list|)
end_macro

begin_decl_stmt
name|class
name|MemorySSAWalker
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Encapsulates MemorySSA, including all data associated with memory
end_comment

begin_comment
comment|/// accesses.
end_comment

begin_decl_stmt
name|class
name|MemorySSA
block|{
name|public
label|:
name|MemorySSA
argument_list|(
name|Function
operator|&
argument_list|,
name|AliasAnalysis
operator|*
argument_list|,
name|DominatorTree
operator|*
argument_list|)
expr_stmt|;
operator|~
name|MemorySSA
argument_list|()
expr_stmt|;
name|MemorySSAWalker
modifier|*
name|getWalker
parameter_list|()
function_decl|;
comment|/// \brief Given a memory Mod/Ref'ing instruction, get the MemorySSA
comment|/// access associated with it. If passed a basic block gets the memory phi
comment|/// node that exists for that block, if there is one. Otherwise, this will get
comment|/// a MemoryUseOrDef.
name|MemoryUseOrDef
modifier|*
name|getMemoryAccess
argument_list|(
specifier|const
name|Instruction
operator|*
argument_list|)
decl|const
decl_stmt|;
name|MemoryPhi
modifier|*
name|getMemoryAccess
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if \p MA represents the live on entry value
comment|///
comment|/// Loads and stores from pointer arguments and other global values may be
comment|/// defined by memory operations that do not occur in the current function, so
comment|/// they may be live on entry to the function. MemorySSA represents such
comment|/// memory state by the live on entry definition, which is guaranteed to occur
comment|/// before any other memory access in the function.
specifier|inline
name|bool
name|isLiveOnEntryDef
argument_list|(
specifier|const
name|MemoryAccess
operator|*
name|MA
argument_list|)
decl|const
block|{
return|return
name|MA
operator|==
name|LiveOnEntryDef
operator|.
name|get
argument_list|()
return|;
block|}
specifier|inline
name|MemoryAccess
operator|*
name|getLiveOnEntryDef
argument_list|()
specifier|const
block|{
return|return
name|LiveOnEntryDef
operator|.
name|get
argument_list|()
return|;
block|}
comment|// Sadly, iplists, by default, owns and deletes pointers added to the
comment|// list. It's not currently possible to have two iplists for the same type,
comment|// where one owns the pointers, and one does not. This is because the traits
comment|// are per-type, not per-tag.  If this ever changes, we should make the
comment|// DefList an iplist.
name|using
name|AccessList
init|=
name|iplist
operator|<
name|MemoryAccess
decl_stmt|,
name|ilist_tag
decl|<
name|MSSAHelpers
decl|::
name|AllAccessTag
decl|>>
decl_stmt|;
name|using
name|DefsList
init|=
name|simple_ilist
operator|<
name|MemoryAccess
decl_stmt|,
name|ilist_tag
decl|<
name|MSSAHelpers
decl|::
name|DefsOnlyTag
decl|>>
decl_stmt|;
comment|/// \brief Return the list of MemoryAccess's for a given basic block.
comment|///
comment|/// This list is not modifiable by the user.
specifier|const
name|AccessList
modifier|*
name|getBlockAccesses
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
name|getWritableBlockAccesses
argument_list|(
name|BB
argument_list|)
return|;
block|}
comment|/// \brief Return the list of MemoryDef's and MemoryPhi's for a given basic
comment|/// block.
comment|///
comment|/// This list is not modifiable by the user.
specifier|const
name|DefsList
modifier|*
name|getBlockDefs
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
name|getWritableBlockDefs
argument_list|(
name|BB
argument_list|)
return|;
block|}
comment|/// \brief Given two memory accesses in the same basic block, determine
comment|/// whether MemoryAccess \p A dominates MemoryAccess \p B.
name|bool
name|locallyDominates
argument_list|(
specifier|const
name|MemoryAccess
operator|*
name|A
argument_list|,
specifier|const
name|MemoryAccess
operator|*
name|B
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Given two memory accesses in potentially different blocks,
comment|/// determine whether MemoryAccess \p A dominates MemoryAccess \p B.
name|bool
name|dominates
argument_list|(
specifier|const
name|MemoryAccess
operator|*
name|A
argument_list|,
specifier|const
name|MemoryAccess
operator|*
name|B
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Given a MemoryAccess and a Use, determine whether MemoryAccess \p A
comment|/// dominates Use \p B.
name|bool
name|dominates
argument_list|(
specifier|const
name|MemoryAccess
operator|*
name|A
argument_list|,
specifier|const
name|Use
operator|&
name|B
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Verify that MemorySSA is self consistent (IE definitions dominate
comment|/// all uses, uses appear in the right places).  This is used by unit tests.
name|void
name|verifyMemorySSA
argument_list|()
specifier|const
expr_stmt|;
comment|/// Used in various insertion functions to specify whether we are talking
comment|/// about the beginning or end of a block.
enum|enum
name|InsertionPlace
block|{
name|Beginning
block|,
name|End
block|}
enum|;
name|protected
label|:
comment|// Used by Memory SSA annotater, dumpers, and wrapper pass
name|friend
name|class
name|MemorySSAAnnotatedWriter
decl_stmt|;
name|friend
name|class
name|MemorySSAPrinterLegacyPass
decl_stmt|;
name|friend
name|class
name|MemorySSAUpdater
decl_stmt|;
name|void
name|verifyDefUses
argument_list|(
name|Function
operator|&
name|F
argument_list|)
decl|const
decl_stmt|;
name|void
name|verifyDomination
argument_list|(
name|Function
operator|&
name|F
argument_list|)
decl|const
decl_stmt|;
name|void
name|verifyOrdering
argument_list|(
name|Function
operator|&
name|F
argument_list|)
decl|const
decl_stmt|;
comment|// This is used by the use optimizer and updater.
name|AccessList
modifier|*
name|getWritableBlockAccesses
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
name|auto
name|It
init|=
name|PerBlockAccesses
operator|.
name|find
argument_list|(
name|BB
argument_list|)
decl_stmt|;
return|return
name|It
operator|==
name|PerBlockAccesses
operator|.
name|end
argument_list|()
condition|?
name|nullptr
else|:
name|It
operator|->
name|second
operator|.
name|get
argument_list|()
return|;
block|}
comment|// This is used by the use optimizer and updater.
name|DefsList
modifier|*
name|getWritableBlockDefs
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
name|auto
name|It
init|=
name|PerBlockDefs
operator|.
name|find
argument_list|(
name|BB
argument_list|)
decl_stmt|;
return|return
name|It
operator|==
name|PerBlockDefs
operator|.
name|end
argument_list|()
condition|?
name|nullptr
else|:
name|It
operator|->
name|second
operator|.
name|get
argument_list|()
return|;
block|}
comment|// These is used by the updater to perform various internal MemorySSA
comment|// machinsations.  They do not always leave the IR in a correct state, and
comment|// relies on the updater to fixup what it breaks, so it is not public.
name|void
name|moveTo
argument_list|(
name|MemoryUseOrDef
operator|*
name|What
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|,
name|AccessList
operator|::
name|iterator
name|Where
argument_list|)
decl_stmt|;
name|void
name|moveTo
parameter_list|(
name|MemoryUseOrDef
modifier|*
name|What
parameter_list|,
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|InsertionPlace
name|Point
parameter_list|)
function_decl|;
comment|// Rename the dominator tree branch rooted at BB.
name|void
name|renamePass
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|,
name|MemoryAccess
operator|*
name|IncomingVal
argument_list|,
name|SmallPtrSetImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|Visited
argument_list|)
block|{
name|renamePass
argument_list|(
name|DT
operator|->
name|getNode
argument_list|(
name|BB
argument_list|)
argument_list|,
name|IncomingVal
argument_list|,
name|Visited
argument_list|,
name|true
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
name|void
name|removeFromLookups
parameter_list|(
name|MemoryAccess
modifier|*
parameter_list|)
function_decl|;
name|void
name|removeFromLists
parameter_list|(
name|MemoryAccess
modifier|*
parameter_list|,
name|bool
name|ShouldDelete
init|=
name|true
parameter_list|)
function_decl|;
name|void
name|insertIntoListsForBlock
parameter_list|(
name|MemoryAccess
modifier|*
parameter_list|,
specifier|const
name|BasicBlock
modifier|*
parameter_list|,
name|InsertionPlace
parameter_list|)
function_decl|;
name|void
name|insertIntoListsBefore
argument_list|(
name|MemoryAccess
operator|*
argument_list|,
specifier|const
name|BasicBlock
operator|*
argument_list|,
name|AccessList
operator|::
name|iterator
argument_list|)
decl_stmt|;
name|MemoryUseOrDef
modifier|*
name|createDefinedAccess
parameter_list|(
name|Instruction
modifier|*
parameter_list|,
name|MemoryAccess
modifier|*
parameter_list|)
function_decl|;
name|private
label|:
name|class
name|CachingWalker
decl_stmt|;
name|class
name|OptimizeUses
decl_stmt|;
name|CachingWalker
modifier|*
name|getWalkerImpl
parameter_list|()
function_decl|;
name|void
name|buildMemorySSA
parameter_list|()
function_decl|;
name|void
name|optimizeUses
parameter_list|()
function_decl|;
name|void
name|verifyUseInDefs
argument_list|(
name|MemoryAccess
operator|*
argument_list|,
name|MemoryAccess
operator|*
argument_list|)
decl|const
decl_stmt|;
name|using
name|AccessMap
init|=
name|DenseMap
operator|<
specifier|const
name|BasicBlock
operator|*
decl_stmt|,
name|std
decl|::
name|unique_ptr
decl|<
name|AccessList
decl|>>
decl_stmt|;
name|using
name|DefsMap
init|=
name|DenseMap
operator|<
specifier|const
name|BasicBlock
operator|*
decl_stmt|,
name|std
decl|::
name|unique_ptr
decl|<
name|DefsList
decl|>>
decl_stmt|;
name|void
name|determineInsertionPoint
argument_list|(
specifier|const
name|SmallPtrSetImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|DefiningBlocks
argument_list|)
decl_stmt|;
name|void
name|markUnreachableAsLiveOnEntry
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|bool
name|dominatesUse
argument_list|(
specifier|const
name|MemoryAccess
operator|*
argument_list|,
specifier|const
name|MemoryAccess
operator|*
argument_list|)
decl|const
decl_stmt|;
name|MemoryPhi
modifier|*
name|createMemoryPhi
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|MemoryUseOrDef
modifier|*
name|createNewAccess
parameter_list|(
name|Instruction
modifier|*
parameter_list|)
function_decl|;
name|MemoryAccess
modifier|*
name|findDominatingDef
parameter_list|(
name|BasicBlock
modifier|*
parameter_list|,
name|enum
name|InsertionPlace
parameter_list|)
function_decl|;
name|void
name|placePHINodes
argument_list|(
specifier|const
name|SmallPtrSetImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
argument_list|,
specifier|const
name|DenseMap
operator|<
specifier|const
name|BasicBlock
operator|*
argument_list|,
name|unsigned
name|int
operator|>
operator|&
argument_list|)
decl_stmt|;
name|MemoryAccess
modifier|*
name|renameBlock
parameter_list|(
name|BasicBlock
modifier|*
parameter_list|,
name|MemoryAccess
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
name|void
name|renameSuccessorPhis
parameter_list|(
name|BasicBlock
modifier|*
parameter_list|,
name|MemoryAccess
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
name|void
name|renamePass
argument_list|(
name|DomTreeNode
operator|*
argument_list|,
name|MemoryAccess
operator|*
name|IncomingVal
argument_list|,
name|SmallPtrSetImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|Visited
argument_list|,
name|bool
name|SkipVisited
operator|=
name|false
argument_list|,
name|bool
name|RenameAllUses
operator|=
name|false
argument_list|)
decl_stmt|;
name|AccessList
modifier|*
name|getOrCreateAccessList
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
parameter_list|)
function_decl|;
name|DefsList
modifier|*
name|getOrCreateDefsList
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
parameter_list|)
function_decl|;
name|void
name|renumberBlock
argument_list|(
specifier|const
name|BasicBlock
operator|*
argument_list|)
decl|const
decl_stmt|;
name|AliasAnalysis
modifier|*
name|AA
decl_stmt|;
name|DominatorTree
modifier|*
name|DT
decl_stmt|;
name|Function
modifier|&
name|F
decl_stmt|;
comment|// Memory SSA mappings
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
operator|,
name|MemoryAccess
operator|*
operator|>
name|ValueToMemoryAccess
expr_stmt|;
comment|// These two mappings contain the main block to access/def mappings for
comment|// MemorySSA. The list contained in PerBlockAccesses really owns all the
comment|// MemoryAccesses.
comment|// Both maps maintain the invariant that if a block is found in them, the
comment|// corresponding list is not empty, and if a block is not found in them, the
comment|// corresponding list is empty.
name|AccessMap
name|PerBlockAccesses
decl_stmt|;
name|DefsMap
name|PerBlockDefs
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryAccess
operator|>
name|LiveOnEntryDef
expr_stmt|;
comment|// Domination mappings
comment|// Note that the numbering is local to a block, even though the map is
comment|// global.
name|mutable
name|SmallPtrSet
operator|<
specifier|const
name|BasicBlock
operator|*
operator|,
literal|16
operator|>
name|BlockNumberingValid
expr_stmt|;
name|mutable
name|DenseMap
operator|<
specifier|const
name|MemoryAccess
operator|*
operator|,
name|unsigned
name|long
operator|>
name|BlockNumbering
expr_stmt|;
comment|// Memory SSA building info
name|std
operator|::
name|unique_ptr
operator|<
name|CachingWalker
operator|>
name|Walker
expr_stmt|;
name|unsigned
name|NextID
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Internal MemorySSA utils, for use by MemorySSA classes and walkers
end_comment

begin_decl_stmt
name|class
name|MemorySSAUtil
block|{
name|protected
label|:
name|friend
name|class
name|MemorySSAWalker
decl_stmt|;
name|friend
name|class
name|GVNHoist
decl_stmt|;
comment|// This function should not be used by new passes.
specifier|static
name|bool
name|defClobbersUseOrDef
parameter_list|(
name|MemoryDef
modifier|*
name|MD
parameter_list|,
specifier|const
name|MemoryUseOrDef
modifier|*
name|MU
parameter_list|,
name|AliasAnalysis
modifier|&
name|AA
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// This pass does eager building and then printing of MemorySSA. It is used by
end_comment

begin_comment
comment|// the tests to be able to build, dump, and verify Memory SSA.
end_comment

begin_decl_stmt
name|class
name|MemorySSAPrinterLegacyPass
range|:
name|public
name|FunctionPass
block|{
name|public
operator|:
name|MemorySSAPrinterLegacyPass
argument_list|()
block|;
name|bool
name|runOnFunction
argument_list|(
argument|Function&
argument_list|)
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|char
name|ID
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// An analysis that produces \c MemorySSA for a function.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|MemorySSAAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|MemorySSAAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|MemorySSAAnalysis
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
comment|// Wrap MemorySSA result to ensure address stability of internal MemorySSA
comment|// pointers after construction.  Use a wrapper class instead of plain
comment|// unique_ptr<MemorySSA> to avoid build breakage on MSVC.
expr|struct
name|Result
block|{
name|Result
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemorySSA
operator|>
operator|&&
name|MSSA
argument_list|)
operator|:
name|MSSA
argument_list|(
argument|std::move(MSSA)
argument_list|)
block|{}
name|MemorySSA
operator|&
name|getMSSA
argument_list|()
block|{
return|return
operator|*
name|MSSA
operator|.
name|get
argument_list|()
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|MemorySSA
operator|>
name|MSSA
block|;   }
block|;
name|Result
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Printer pass for \c MemorySSA.
end_comment

begin_decl_stmt
name|class
name|MemorySSAPrinterPass
range|:
name|public
name|PassInfoMixin
operator|<
name|MemorySSAPrinterPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|explicit
name|MemorySSAPrinterPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
operator|:
name|OS
argument_list|(
argument|OS
argument_list|)
block|{}
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Verifier pass for \c MemorySSA.
end_comment

begin_decl_stmt
name|struct
name|MemorySSAVerifierPass
range|:
name|PassInfoMixin
operator|<
name|MemorySSAVerifierPass
operator|>
block|{
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Legacy analysis pass which computes \c MemorySSA.
end_comment

begin_decl_stmt
name|class
name|MemorySSAWrapperPass
range|:
name|public
name|FunctionPass
block|{
name|public
operator|:
name|MemorySSAWrapperPass
argument_list|()
block|;
specifier|static
name|char
name|ID
block|;
name|bool
name|runOnFunction
argument_list|(
argument|Function&
argument_list|)
name|override
block|;
name|void
name|releaseMemory
argument_list|()
name|override
block|;
name|MemorySSA
operator|&
name|getMSSA
argument_list|()
block|{
return|return
operator|*
name|MSSA
return|;
block|}
specifier|const
name|MemorySSA
operator|&
name|getMSSA
argument_list|()
specifier|const
block|{
return|return
operator|*
name|MSSA
return|;
block|}
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
name|void
name|verifyAnalysis
argument_list|()
specifier|const
name|override
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module *M = nullptr
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|MemorySSA
operator|>
name|MSSA
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief This is the generic walker interface for walkers of MemorySSA.
end_comment

begin_comment
comment|/// Walkers are used to be able to further disambiguate the def-use chains
end_comment

begin_comment
comment|/// MemorySSA gives you, or otherwise produce better info than MemorySSA gives
end_comment

begin_comment
comment|/// you.
end_comment

begin_comment
comment|/// In particular, while the def-use chains provide basic information, and are
end_comment

begin_comment
comment|/// guaranteed to give, for example, the nearest may-aliasing MemoryDef for a
end_comment

begin_comment
comment|/// MemoryUse as AliasAnalysis considers it, a user mant want better or other
end_comment

begin_comment
comment|/// information. In particular, they may want to use SCEV info to further
end_comment

begin_comment
comment|/// disambiguate memory accesses, or they may want the nearest dominating
end_comment

begin_comment
comment|/// may-aliasing MemoryDef for a call or a store. This API enables a
end_comment

begin_comment
comment|/// standardized interface to getting and using that info.
end_comment

begin_decl_stmt
name|class
name|MemorySSAWalker
block|{
name|public
label|:
name|MemorySSAWalker
argument_list|(
name|MemorySSA
operator|*
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|MemorySSAWalker
argument_list|()
operator|=
expr|default
expr_stmt|;
name|using
name|MemoryAccessSet
init|=
name|SmallVector
operator|<
name|MemoryAccess
operator|*
decl_stmt|, 8>;
comment|/// \brief Given a memory Mod/Ref/ModRef'ing instruction, calling this
comment|/// will give you the nearest dominating MemoryAccess that Mod's the location
comment|/// the instruction accesses (by skipping any def which AA can prove does not
comment|/// alias the location(s) accessed by the instruction given).
comment|///
comment|/// Note that this will return a single access, and it must dominate the
comment|/// Instruction, so if an operand of a MemoryPhi node Mod's the instruction,
comment|/// this will return the MemoryPhi, not the operand. This means that
comment|/// given:
comment|/// if (a) {
comment|///   1 = MemoryDef(liveOnEntry)
comment|///   store %a
comment|/// } else {
comment|///   2 = MemoryDef(liveOnEntry)
comment|///   store %b
comment|/// }
comment|/// 3 = MemoryPhi(2, 1)
comment|/// MemoryUse(3)
comment|/// load %a
comment|///
comment|/// calling this API on load(%a) will return the MemoryPhi, not the MemoryDef
comment|/// in the if (a) branch.
name|MemoryAccess
modifier|*
name|getClobberingMemoryAccess
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|I
parameter_list|)
block|{
name|MemoryAccess
modifier|*
name|MA
init|=
name|MSSA
operator|->
name|getMemoryAccess
argument_list|(
name|I
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|MA
operator|&&
literal|"Handed an instruction that MemorySSA doesn't recognize?"
argument_list|)
expr_stmt|;
return|return
name|getClobberingMemoryAccess
argument_list|(
name|MA
argument_list|)
return|;
block|}
comment|/// Does the same thing as getClobberingMemoryAccess(const Instruction *I),
comment|/// but takes a MemoryAccess instead of an Instruction.
name|virtual
name|MemoryAccess
modifier|*
name|getClobberingMemoryAccess
parameter_list|(
name|MemoryAccess
modifier|*
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Given a potentially clobbering memory access and a new location,
comment|/// calling this will give you the nearest dominating clobbering MemoryAccess
comment|/// (by skipping non-aliasing def links).
comment|///
comment|/// This version of the function is mainly used to disambiguate phi translated
comment|/// pointers, where the value of a pointer may have changed from the initial
comment|/// memory access. Note that this expects to be handed either a MemoryUse,
comment|/// or an already potentially clobbering access. Unlike the above API, if
comment|/// given a MemoryDef that clobbers the pointer as the starting access, it
comment|/// will return that MemoryDef, whereas the above would return the clobber
comment|/// starting from the use side of  the memory def.
name|virtual
name|MemoryAccess
modifier|*
name|getClobberingMemoryAccess
parameter_list|(
name|MemoryAccess
modifier|*
parameter_list|,
specifier|const
name|MemoryLocation
modifier|&
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Given a memory access, invalidate anything this walker knows about
comment|/// that access.
comment|/// This API is used by walkers that store information to perform basic cache
comment|/// invalidation.  This will be called by MemorySSA at appropriate times for
comment|/// the walker it uses or returns.
name|virtual
name|void
name|invalidateInfo
parameter_list|(
name|MemoryAccess
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|verify
parameter_list|(
specifier|const
name|MemorySSA
modifier|*
name|MSSA
parameter_list|)
block|{
name|assert
argument_list|(
name|MSSA
operator|==
name|this
operator|->
name|MSSA
argument_list|)
expr_stmt|;
block|}
name|protected
label|:
name|friend
name|class
name|MemorySSA
decl_stmt|;
comment|// For updating MSSA pointer in MemorySSA move
comment|// constructor.
name|MemorySSA
modifier|*
name|MSSA
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A MemorySSAWalker that does no alias queries, or anything else. It
end_comment

begin_comment
comment|/// simply returns the links as they were constructed by the builder.
end_comment

begin_decl_stmt
name|class
name|DoNothingMemorySSAWalker
name|final
range|:
name|public
name|MemorySSAWalker
block|{
name|public
operator|:
comment|// Keep the overrides below from hiding the Instruction overload of
comment|// getClobberingMemoryAccess.
name|using
name|MemorySSAWalker
operator|::
name|getClobberingMemoryAccess
block|;
name|MemoryAccess
operator|*
name|getClobberingMemoryAccess
argument_list|(
argument|MemoryAccess *
argument_list|)
name|override
block|;
name|MemoryAccess
operator|*
name|getClobberingMemoryAccess
argument_list|(
argument|MemoryAccess *
argument_list|,
argument|const MemoryLocation&
argument_list|)
name|override
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|using
name|MemoryAccessPair
init|=
name|std
operator|::
name|pair
operator|<
name|MemoryAccess
operator|*
decl_stmt|,
name|MemoryLocation
decl|>
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|using
name|ConstMemoryAccessPair
init|=
name|std
operator|::
name|pair
operator|<
specifier|const
name|MemoryAccess
operator|*
decl_stmt|,
name|MemoryLocation
decl|>
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Iterator base class used to implement const and non-const iterators
end_comment

begin_comment
comment|/// over the defining accesses of a MemoryAccess.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|memoryaccess_def_iterator_base
operator|:
name|public
name|iterator_facade_base
operator|<
name|memoryaccess_def_iterator_base
operator|<
name|T
operator|>
operator|,
name|std
operator|::
name|forward_iterator_tag
operator|,
name|T
operator|,
name|ptrdiff_t
operator|,
name|T
operator|*
operator|,
name|T
operator|*
operator|>
block|{
name|using
name|BaseT
operator|=
name|typename
name|memoryaccess_def_iterator_base
operator|::
name|iterator_facade_base
block|;
name|public
operator|:
name|memoryaccess_def_iterator_base
argument_list|(
name|T
operator|*
name|Start
argument_list|)
operator|:
name|Access
argument_list|(
argument|Start
argument_list|)
block|{}
name|memoryaccess_def_iterator_base
argument_list|()
operator|=
expr|default
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|memoryaccess_def_iterator_base
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Access
operator|==
name|Other
operator|.
name|Access
operator|&&
operator|(
operator|!
name|Access
operator|||
name|ArgNo
operator|==
name|Other
operator|.
name|ArgNo
operator|)
return|;
block|}
comment|// This is a bit ugly, but for MemoryPHI's, unlike PHINodes, you can't get the
comment|// block from the operand in constant time (In a PHINode, the uselist has
comment|// both, so it's just subtraction). We provide it as part of the
comment|// iterator to avoid callers having to linear walk to get the block.
comment|// If the operation becomes constant time on MemoryPHI's, this bit of
comment|// abstraction breaking should be removed.
name|BasicBlock
operator|*
name|getPhiArgBlock
argument_list|()
specifier|const
block|{
name|MemoryPhi
operator|*
name|MP
operator|=
name|dyn_cast
operator|<
name|MemoryPhi
operator|>
operator|(
name|Access
operator|)
block|;
name|assert
argument_list|(
name|MP
operator|&&
literal|"Tried to get phi arg block when not iterating over a PHI"
argument_list|)
block|;
return|return
name|MP
operator|->
name|getIncomingBlock
argument_list|(
name|ArgNo
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|typename
name|BaseT
operator|::
name|iterator
operator|::
name|pointer
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Access
operator|&&
literal|"Tried to access past the end of our iterator"
argument_list|)
block|;
comment|// Go to the first argument for phis, and the defining access for everything
comment|// else.
if|if
condition|(
name|MemoryPhi
modifier|*
name|MP
init|=
name|dyn_cast
operator|<
name|MemoryPhi
operator|>
operator|(
name|Access
operator|)
condition|)
return|return
name|MP
operator|->
name|getIncomingValue
argument_list|(
name|ArgNo
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|cast
operator|<
name|MemoryUseOrDef
operator|>
operator|(
name|Access
operator|)
operator|->
name|getDefiningAccess
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}   using
name|BaseT
operator|::
name|operator
operator|++
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|memoryaccess_def_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|assert
argument_list|(
name|Access
operator|&&
literal|"Hit end of iterator"
argument_list|)
block|;
if|if
condition|(
name|MemoryPhi
modifier|*
name|MP
init|=
name|dyn_cast
operator|<
name|MemoryPhi
operator|>
operator|(
name|Access
operator|)
condition|)
block|{
if|if
condition|(
operator|++
name|ArgNo
operator|>=
name|MP
operator|->
name|getNumIncomingValues
argument_list|()
condition|)
block|{
name|ArgNo
operator|=
literal|0
expr_stmt|;
name|Access
operator|=
name|nullptr
expr_stmt|;
block|}
end_expr_stmt

begin_block
unit|} else
block|{
name|Access
operator|=
name|nullptr
expr_stmt|;
block|}
end_block

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_decl_stmt
unit|}  private:
name|T
modifier|*
name|Access
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|ArgNo
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
specifier|inline
name|memoryaccess_def_iterator
name|MemoryAccess
operator|::
name|defs_begin
argument_list|()
block|{
return|return
name|memoryaccess_def_iterator
argument_list|(
name|this
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|const_memoryaccess_def_iterator
name|MemoryAccess
operator|::
name|defs_begin
argument_list|()
specifier|const
block|{
return|return
name|const_memoryaccess_def_iterator
argument_list|(
name|this
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|memoryaccess_def_iterator
name|MemoryAccess
operator|::
name|defs_end
argument_list|()
block|{
return|return
name|memoryaccess_def_iterator
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|const_memoryaccess_def_iterator
name|MemoryAccess
operator|::
name|defs_end
argument_list|()
specifier|const
block|{
return|return
name|const_memoryaccess_def_iterator
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief GraphTraits for a MemoryAccess, which walks defs in the normal case,
end_comment

begin_comment
comment|/// and uses in the inverse case.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|MemoryAccess
operator|*
operator|>
block|{
name|using
name|NodeRef
operator|=
name|MemoryAccess
operator|*
block|;
name|using
name|ChildIteratorType
operator|=
name|memoryaccess_def_iterator
block|;
specifier|static
name|NodeRef
name|getEntryNode
argument_list|(
argument|NodeRef N
argument_list|)
block|{
return|return
name|N
return|;
block|}
specifier|static
name|ChildIteratorType
name|child_begin
argument_list|(
argument|NodeRef N
argument_list|)
block|{
return|return
name|N
operator|->
name|defs_begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeRef
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|defs_end
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|Inverse
operator|<
name|MemoryAccess
operator|*
operator|>>
block|{
name|using
name|NodeRef
operator|=
name|MemoryAccess
operator|*
block|;
name|using
name|ChildIteratorType
operator|=
name|MemoryAccess
operator|::
name|iterator
block|;
specifier|static
name|NodeRef
name|getEntryNode
argument_list|(
argument|NodeRef N
argument_list|)
block|{
return|return
name|N
return|;
block|}
specifier|static
name|ChildIteratorType
name|child_begin
argument_list|(
argument|NodeRef N
argument_list|)
block|{
return|return
name|N
operator|->
name|user_begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeRef
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|user_end
argument_list|()
return|;
block|}
end_function

begin_comment
unit|};
comment|/// \brief Provide an iterator that walks defs, giving both the memory access,
end_comment

begin_comment
comment|/// and the current pointer location, updating the pointer location as it
end_comment

begin_comment
comment|/// changes due to phi node translation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This iterator, while somewhat specialized, is what most clients actually
end_comment

begin_comment
comment|/// want when walking upwards through MemorySSA def chains. It takes a pair of
end_comment

begin_comment
comment|///<MemoryAccess,MemoryLocation>, and walks defs, properly translating the
end_comment

begin_comment
comment|/// memory location through phi nodes for the user.
end_comment

begin_decl_stmt
name|class
name|upward_defs_iterator
range|:
name|public
name|iterator_facade_base
operator|<
name|upward_defs_iterator
decl_stmt|,
name|std
decl|::
name|forward_iterator_tag
decl_stmt|,                                   const
name|MemoryAccessPair
decl|>
block|{
name|using
name|BaseT
init|=
name|upward_defs_iterator
operator|::
name|iterator_facade_base
decl_stmt|;
name|public
label|:
name|upward_defs_iterator
argument_list|(
specifier|const
name|MemoryAccessPair
operator|&
name|Info
argument_list|)
operator|:
name|DefIterator
argument_list|(
name|Info
operator|.
name|first
argument_list|)
operator|,
name|Location
argument_list|(
name|Info
operator|.
name|second
argument_list|)
operator|,
name|OriginalAccess
argument_list|(
argument|Info.first
argument_list|)
block|{
name|CurrentPair
operator|.
name|first
operator|=
name|nullptr
block|;
name|WalkingPhi
operator|=
name|Info
operator|.
name|first
operator|&&
name|isa
operator|<
name|MemoryPhi
operator|>
operator|(
name|Info
operator|.
name|first
operator|)
block|;
name|fillInCurrentPair
argument_list|()
block|;   }
name|upward_defs_iterator
argument_list|()
block|{
name|CurrentPair
operator|.
name|first
operator|=
name|nullptr
block|; }
name|bool
name|operator
operator|==
operator|(
specifier|const
name|upward_defs_iterator
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|DefIterator
operator|==
name|Other
operator|.
name|DefIterator
return|;
block|}
name|BaseT
operator|::
name|iterator
operator|::
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|DefIterator
operator|!=
name|OriginalAccess
operator|->
name|defs_end
argument_list|()
operator|&&
literal|"Tried to access past the end of our iterator"
argument_list|)
block|;
return|return
name|CurrentPair
return|;
block|}
name|using
name|BaseT
operator|::
name|operator
operator|++
expr_stmt|;
name|upward_defs_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|assert
argument_list|(
name|DefIterator
operator|!=
name|OriginalAccess
operator|->
name|defs_end
argument_list|()
operator|&&
literal|"Tried to access past the end of the iterator"
argument_list|)
block|;
operator|++
name|DefIterator
block|;
if|if
condition|(
name|DefIterator
operator|!=
name|OriginalAccess
operator|->
name|defs_end
argument_list|()
condition|)
name|fillInCurrentPair
argument_list|()
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|BasicBlock
operator|*
name|getPhiArgBlock
argument_list|()
specifier|const
block|{
return|return
name|DefIterator
operator|.
name|getPhiArgBlock
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_function
name|void
name|fillInCurrentPair
parameter_list|()
block|{
name|CurrentPair
operator|.
name|first
operator|=
operator|*
name|DefIterator
expr_stmt|;
if|if
condition|(
name|WalkingPhi
operator|&&
name|Location
operator|.
name|Ptr
condition|)
block|{
name|PHITransAddr
name|Translator
argument_list|(
name|const_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|Location
operator|.
name|Ptr
operator|)
argument_list|,
name|OriginalAccess
operator|->
name|getBlock
argument_list|()
operator|->
name|getModule
argument_list|()
operator|->
name|getDataLayout
argument_list|()
argument_list|,
name|nullptr
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|Translator
operator|.
name|PHITranslateValue
argument_list|(
name|OriginalAccess
operator|->
name|getBlock
argument_list|()
argument_list|,
name|DefIterator
operator|.
name|getPhiArgBlock
argument_list|()
argument_list|,
name|nullptr
argument_list|,
name|false
argument_list|)
condition|)
if|if
condition|(
name|Translator
operator|.
name|getAddr
argument_list|()
operator|!=
name|Location
operator|.
name|Ptr
condition|)
block|{
name|CurrentPair
operator|.
name|second
operator|=
name|Location
operator|.
name|getWithNewPtr
argument_list|(
name|Translator
operator|.
name|getAddr
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
name|CurrentPair
operator|.
name|second
operator|=
name|Location
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|MemoryAccessPair
name|CurrentPair
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|memoryaccess_def_iterator
name|DefIterator
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MemoryLocation
name|Location
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MemoryAccess
modifier|*
name|OriginalAccess
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|WalkingPhi
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
unit|};
specifier|inline
name|upward_defs_iterator
name|upward_defs_begin
parameter_list|(
specifier|const
name|MemoryAccessPair
modifier|&
name|Pair
parameter_list|)
block|{
return|return
name|upward_defs_iterator
argument_list|(
name|Pair
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|upward_defs_iterator
name|upward_defs_end
parameter_list|()
block|{
return|return
name|upward_defs_iterator
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
specifier|inline
name|iterator_range
operator|<
name|upward_defs_iterator
operator|>
name|upward_defs
argument_list|(
argument|const MemoryAccessPair&Pair
argument_list|)
block|{
return|return
name|make_range
argument_list|(
name|upward_defs_begin
argument_list|(
name|Pair
argument_list|)
argument_list|,
name|upward_defs_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Walks the defining accesses of MemoryDefs. Stops after we hit something that
end_comment

begin_comment
comment|/// has no defining use (e.g. a MemoryPhi or liveOnEntry). Note that, when
end_comment

begin_comment
comment|/// comparing against a null def_chain_iterator, this will compare equal only
end_comment

begin_comment
comment|/// after walking said Phi/liveOnEntry.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The UseOptimizedChain flag specifies whether to walk the clobbering
end_comment

begin_comment
comment|/// access chain, or all the accesses.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Normally, MemoryDef are all just def/use linked together, so a def_chain on
end_comment

begin_comment
comment|/// a MemoryDef will walk all MemoryDefs above it in the program until it hits
end_comment

begin_comment
comment|/// a phi node.  The optimized chain walks the clobbering access of a store.
end_comment

begin_comment
comment|/// So if you are just trying to find, given a store, what the next
end_comment

begin_comment
comment|/// thing that would clobber the same memory is, you want the optimized chain.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|bool
name|UseOptimizedChain
operator|=
name|false
operator|>
expr|struct
name|def_chain_iterator
operator|:
name|public
name|iterator_facade_base
operator|<
name|def_chain_iterator
operator|<
name|T
operator|,
name|UseOptimizedChain
operator|>
operator|,
name|std
operator|::
name|forward_iterator_tag
operator|,
name|MemoryAccess
operator|*
operator|>
block|{
name|def_chain_iterator
argument_list|()
operator|:
name|MA
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|def_chain_iterator
argument_list|(
argument|T MA
argument_list|)
operator|:
name|MA
argument_list|(
argument|MA
argument_list|)
block|{}
name|T
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|MA
return|;
block|}
name|def_chain_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// N.B. liveOnEntry has a null defining access.
if|if
condition|(
name|auto
operator|*
name|MUD
operator|=
name|dyn_cast
operator|<
name|MemoryUseOrDef
operator|>
operator|(
name|MA
operator|)
condition|)
block|{
if|if
condition|(
name|UseOptimizedChain
operator|&&
name|MUD
operator|->
name|isOptimized
argument_list|()
condition|)
name|MA
operator|=
name|MUD
operator|->
name|getOptimized
argument_list|()
expr_stmt|;
else|else
name|MA
operator|=
name|MUD
operator|->
name|getDefiningAccess
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
name|MA
operator|=
name|nullptr
expr_stmt|;
block|}
end_else

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}    bool
name|operator
operator|==
operator|(
specifier|const
name|def_chain_iterator
operator|&
name|O
operator|)
specifier|const
block|{
return|return
name|MA
operator|==
name|O
operator|.
name|MA
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|T
name|MA
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|iterator_range
operator|<
name|def_chain_iterator
operator|<
name|T
operator|>>
name|def_chain
argument_list|(
argument|T MA
argument_list|,
argument|MemoryAccess *UpTo = nullptr
argument_list|)
block|{
ifdef|#
directive|ifdef
name|EXPENSIVE_CHECKS
name|assert
argument_list|(
operator|(
operator|!
name|UpTo
operator|||
name|find
argument_list|(
name|def_chain
argument_list|(
name|MA
argument_list|)
argument_list|,
name|UpTo
argument_list|)
operator|!=
name|def_chain_iterator
operator|<
name|T
operator|>
operator|(
operator|)
operator|)
operator|&&
literal|"UpTo isn't in the def chain!"
argument_list|)
block|;
endif|#
directive|endif
return|return
name|make_range
argument_list|(
name|def_chain_iterator
operator|<
name|T
operator|>
operator|(
name|MA
operator|)
argument_list|,
name|def_chain_iterator
operator|<
name|T
operator|>
operator|(
name|UpTo
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|iterator_range
operator|<
name|def_chain_iterator
operator|<
name|T
operator|,
name|true
operator|>>
name|optimized_def_chain
argument_list|(
argument|T MA
argument_list|)
block|{
return|return
name|make_range
argument_list|(
name|def_chain_iterator
operator|<
name|T
argument_list|,
name|true
operator|>
operator|(
name|MA
operator|)
argument_list|,
name|def_chain_iterator
operator|<
name|T
argument_list|,
name|true
operator|>
operator|(
name|nullptr
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ANALYSIS_MEMORYSSA_H
end_comment

end_unit

