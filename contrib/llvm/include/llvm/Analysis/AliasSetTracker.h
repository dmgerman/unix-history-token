begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/AliasSetTracker.h - Build Alias Sets -------*- C++ -*-===//
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
comment|// This file defines two classes: AliasSetTracker and AliasSet.  These interface
end_comment

begin_comment
comment|// are used to classify a collection of pointer references into a maximal number
end_comment

begin_comment
comment|// of disjoint sets.  Each AliasSet object constructed by the AliasSetTracker
end_comment

begin_comment
comment|// object refers to memory disjoint from the other sets.
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
name|LLVM_ANALYSIS_ALIASSETTRACKER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_ALIASSETTRACKER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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
file|"llvm/IR/Metadata.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
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
name|class
name|AliasAnalysis
decl_stmt|;
name|class
name|LoadInst
decl_stmt|;
name|class
name|StoreInst
decl_stmt|;
name|class
name|VAArgInst
decl_stmt|;
name|class
name|AliasSetTracker
decl_stmt|;
name|class
name|AliasSet
decl_stmt|;
name|class
name|AliasSet
range|:
name|public
name|ilist_node
operator|<
name|AliasSet
operator|>
block|{
name|friend
name|class
name|AliasSetTracker
block|;
name|class
name|PointerRec
block|{
name|Value
operator|*
name|Val
block|;
comment|// The pointer this record corresponds to.
name|PointerRec
operator|*
operator|*
name|PrevInList
block|,
operator|*
name|NextInList
block|;
name|AliasSet
operator|*
name|AS
block|;
name|uint64_t
name|Size
block|;
name|AAMDNodes
name|AAInfo
block|;
name|public
operator|:
name|PointerRec
argument_list|(
name|Value
operator|*
name|V
argument_list|)
operator|:
name|Val
argument_list|(
name|V
argument_list|)
block|,
name|PrevInList
argument_list|(
name|nullptr
argument_list|)
block|,
name|NextInList
argument_list|(
name|nullptr
argument_list|)
block|,
name|AS
argument_list|(
name|nullptr
argument_list|)
block|,
name|Size
argument_list|(
literal|0
argument_list|)
block|,
name|AAInfo
argument_list|(
argument|DenseMapInfo<AAMDNodes>::getEmptyKey()
argument_list|)
block|{}
name|Value
operator|*
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Val
return|;
block|}
name|PointerRec
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
name|NextInList
return|;
block|}
name|bool
name|hasAliasSet
argument_list|()
specifier|const
block|{
return|return
name|AS
operator|!=
name|nullptr
return|;
block|}
name|PointerRec
operator|*
operator|*
name|setPrevInList
argument_list|(
argument|PointerRec **PIL
argument_list|)
block|{
name|PrevInList
operator|=
name|PIL
block|;
return|return
operator|&
name|NextInList
return|;
block|}
name|void
name|updateSizeAndAAInfo
argument_list|(
argument|uint64_t NewSize
argument_list|,
argument|const AAMDNodes&NewAAInfo
argument_list|)
block|{
if|if
condition|(
name|NewSize
operator|>
name|Size
condition|)
name|Size
operator|=
name|NewSize
expr_stmt|;
if|if
condition|(
name|AAInfo
operator|==
name|DenseMapInfo
operator|<
name|AAMDNodes
operator|>
operator|::
name|getEmptyKey
argument_list|()
condition|)
comment|// We don't have a AAInfo yet. Set it to NewAAInfo.
name|AAInfo
operator|=
name|NewAAInfo
expr_stmt|;
elseif|else
if|if
condition|(
name|AAInfo
operator|!=
name|NewAAInfo
condition|)
comment|// NewAAInfo conflicts with AAInfo.
name|AAInfo
operator|=
name|DenseMapInfo
operator|<
name|AAMDNodes
operator|>
operator|::
name|getTombstoneKey
argument_list|()
expr_stmt|;
block|}
name|uint64_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
comment|/// getAAInfo - Return the AAInfo, or null if there is no
comment|/// information or conflicting information.
name|AAMDNodes
name|getAAInfo
argument_list|()
specifier|const
block|{
comment|// If we have missing or conflicting AAInfo, return null.
if|if
condition|(
name|AAInfo
operator|==
name|DenseMapInfo
operator|<
name|AAMDNodes
operator|>
operator|::
name|getEmptyKey
argument_list|()
operator|||
name|AAInfo
operator|==
name|DenseMapInfo
operator|<
name|AAMDNodes
operator|>
operator|::
name|getTombstoneKey
argument_list|()
condition|)
return|return
name|AAMDNodes
argument_list|()
return|;
return|return
name|AAInfo
return|;
block|}
name|AliasSet
modifier|*
name|getAliasSet
parameter_list|(
name|AliasSetTracker
modifier|&
name|AST
parameter_list|)
block|{
name|assert
argument_list|(
name|AS
operator|&&
literal|"No AliasSet yet!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|AS
operator|->
name|Forward
condition|)
block|{
name|AliasSet
modifier|*
name|OldAS
init|=
name|AS
decl_stmt|;
name|AS
operator|=
name|OldAS
operator|->
name|getForwardedTarget
argument_list|(
name|AST
argument_list|)
expr_stmt|;
name|AS
operator|->
name|addRef
argument_list|()
expr_stmt|;
name|OldAS
operator|->
name|dropRef
argument_list|(
name|AST
argument_list|)
expr_stmt|;
block|}
return|return
name|AS
return|;
block|}
name|void
name|setAliasSet
parameter_list|(
name|AliasSet
modifier|*
name|as
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|AS
operator|&&
literal|"Already have an alias set!"
argument_list|)
expr_stmt|;
name|AS
operator|=
name|as
expr_stmt|;
block|}
name|void
name|eraseFromList
parameter_list|()
block|{
if|if
condition|(
name|NextInList
condition|)
name|NextInList
operator|->
name|PrevInList
operator|=
name|PrevInList
expr_stmt|;
operator|*
name|PrevInList
operator|=
name|NextInList
expr_stmt|;
if|if
condition|(
name|AS
operator|->
name|PtrListEnd
operator|==
operator|&
name|NextInList
condition|)
block|{
name|AS
operator|->
name|PtrListEnd
operator|=
name|PrevInList
expr_stmt|;
name|assert
argument_list|(
operator|*
name|AS
operator|->
name|PtrListEnd
operator|==
name|nullptr
operator|&&
literal|"List not terminated right!"
argument_list|)
expr_stmt|;
block|}
name|delete
name|this
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|PointerRec
modifier|*
name|PtrList
decl_stmt|,
modifier|*
modifier|*
name|PtrListEnd
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Doubly linked list of nodes.
end_comment

begin_decl_stmt
name|AliasSet
modifier|*
name|Forward
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Forwarding pointer.
end_comment

begin_comment
comment|// All instructions without a specific address in this alias set.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|AssertingVH
operator|<
name|Instruction
operator|>
expr|>
name|UnknownInsts
expr_stmt|;
end_expr_stmt

begin_comment
comment|// RefCount - Number of nodes pointing to this AliasSet plus the number of
end_comment

begin_comment
comment|// AliasSets forwarding to it.
end_comment

begin_decl_stmt
name|unsigned
name|RefCount
range|:
literal|28
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// AccessType - Keep track of whether this alias set merely refers to the
end_comment

begin_comment
comment|/// locations of memory, whether it modifies the memory, or whether it does
end_comment

begin_comment
comment|/// both.  The lattice goes from "NoModRef" to either Refs or Mods, then to
end_comment

begin_comment
comment|/// ModRef as necessary.
end_comment

begin_comment
comment|///
end_comment

begin_enum
enum|enum
name|AccessType
block|{
name|NoModRef
init|=
literal|0
block|,
name|Refs
init|=
literal|1
block|,
comment|// Ref = bit 1
name|Mods
init|=
literal|2
block|,
name|ModRef
init|=
literal|3
comment|// Mod = bit 2
block|}
enum|;
end_enum

begin_decl_stmt
name|unsigned
name|AccessTy
range|:
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// AliasType - Keep track the relationships between the pointers in the set.
end_comment

begin_comment
comment|/// Lattice goes from MustAlias to MayAlias.
end_comment

begin_comment
comment|///
end_comment

begin_enum
enum|enum
name|AliasType
block|{
name|MustAlias
init|=
literal|0
block|,
name|MayAlias
init|=
literal|1
block|}
enum|;
end_enum

begin_decl_stmt
name|unsigned
name|AliasTy
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Volatile - True if this alias set contains volatile loads or stores.
end_comment

begin_decl_stmt
name|bool
name|Volatile
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|addRef
parameter_list|()
block|{
operator|++
name|RefCount
expr_stmt|;
block|}
end_function

begin_function
name|void
name|dropRef
parameter_list|(
name|AliasSetTracker
modifier|&
name|AST
parameter_list|)
block|{
name|assert
argument_list|(
name|RefCount
operator|>=
literal|1
operator|&&
literal|"Invalid reference count detected!"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|--
name|RefCount
operator|==
literal|0
condition|)
name|removeFromTracker
argument_list|(
name|AST
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|Instruction
modifier|*
name|getUnknownInst
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|UnknownInsts
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|UnknownInsts
index|[
name|i
index|]
return|;
block|}
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Accessors...
end_comment

begin_expr_stmt
name|bool
name|isRef
argument_list|()
specifier|const
block|{
return|return
name|AccessTy
operator|&
name|Refs
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isMod
argument_list|()
specifier|const
block|{
return|return
name|AccessTy
operator|&
name|Mods
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isMustAlias
argument_list|()
specifier|const
block|{
return|return
name|AliasTy
operator|==
name|MustAlias
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isMayAlias
argument_list|()
specifier|const
block|{
return|return
name|AliasTy
operator|==
name|MayAlias
return|;
block|}
end_expr_stmt

begin_comment
comment|// isVolatile - Return true if this alias set contains volatile loads or
end_comment

begin_comment
comment|// stores.
end_comment

begin_expr_stmt
name|bool
name|isVolatile
argument_list|()
specifier|const
block|{
return|return
name|Volatile
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isForwardingAliasSet - Return true if this alias set should be ignored as
end_comment

begin_comment
comment|/// part of the AliasSetTracker object.
end_comment

begin_expr_stmt
name|bool
name|isForwardingAliasSet
argument_list|()
specifier|const
block|{
return|return
name|Forward
return|;
block|}
end_expr_stmt

begin_comment
comment|/// mergeSetIn - Merge the specified alias set into this alias set...
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|mergeSetIn
parameter_list|(
name|AliasSet
modifier|&
name|AS
parameter_list|,
name|AliasSetTracker
modifier|&
name|AST
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Alias Set iteration - Allow access to all of the pointer which are part of
end_comment

begin_comment
comment|// this alias set...
end_comment

begin_decl_stmt
name|class
name|iterator
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|(
name|PtrList
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|PtrList
operator|==
name|nullptr
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Define an iterator for alias sets... this is just a forward iterator.
end_comment

begin_decl_stmt
name|class
name|iterator
range|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
decl_stmt|,
name|PointerRec
decl_stmt|,
name|ptrdiff_t
decl|>
block|{
name|PointerRec
modifier|*
name|CurNode
decl_stmt|;
name|public
label|:
name|explicit
name|iterator
argument_list|(
name|PointerRec
operator|*
name|CN
operator|=
name|nullptr
argument_list|)
operator|:
name|CurNode
argument_list|(
argument|CN
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|CurNode
operator|==
name|x
operator|.
name|CurNode
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|x
operator|)
return|;
block|}
specifier|const
name|iterator
modifier|&
name|operator
init|=
operator|(
specifier|const
name|iterator
operator|&
name|I
operator|)
block|{
name|CurNode
operator|=
name|I
operator|.
name|CurNode
block|;
return|return
operator|*
name|this
return|;
block|}
name|value_type
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|CurNode
operator|&&
literal|"Dereferencing AliasSet.end()!"
argument_list|)
block|;
return|return
operator|*
name|CurNode
return|;
block|}
name|value_type
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
name|operator
operator|*
operator|(
operator|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|Value
operator|*
name|getPointer
argument_list|()
specifier|const
block|{
return|return
name|CurNode
operator|->
name|getValue
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|uint64_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|CurNode
operator|->
name|getSize
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|AAMDNodes
name|getAAInfo
argument_list|()
specifier|const
block|{
return|return
name|CurNode
operator|->
name|getAAInfo
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
name|assert
argument_list|(
name|CurNode
operator|&&
literal|"Advancing past AliasSet.end()!"
argument_list|)
block|;
name|CurNode
operator|=
name|CurNode
operator|->
name|getNext
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|iterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_label
unit|};
name|private
label|:
end_label

begin_comment
comment|// Can only be created by AliasSetTracker. Also, ilist creates one
end_comment

begin_comment
comment|// to serve as a sentinel.
end_comment

begin_macro
name|friend
end_macro

begin_expr_stmt
unit|struct
name|ilist_sentinel_traits
operator|<
name|AliasSet
operator|>
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|AliasSet
argument_list|()
operator|:
name|PtrList
argument_list|(
name|nullptr
argument_list|)
operator|,
name|PtrListEnd
argument_list|(
operator|&
name|PtrList
argument_list|)
operator|,
name|Forward
argument_list|(
name|nullptr
argument_list|)
operator|,
name|RefCount
argument_list|(
literal|0
argument_list|)
operator|,
name|AccessTy
argument_list|(
name|NoModRef
argument_list|)
operator|,
name|AliasTy
argument_list|(
name|MustAlias
argument_list|)
operator|,
name|Volatile
argument_list|(
argument|false
argument_list|)
block|{   }
name|AliasSet
argument_list|(
argument|const AliasSet&AS
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|operator
init|=
operator|(
specifier|const
name|AliasSet
operator|&
name|AS
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|PointerRec
operator|*
name|getSomePointer
argument_list|()
specifier|const
block|{
return|return
name|PtrList
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getForwardedTarget - Return the real alias set this represents.  If this
end_comment

begin_comment
comment|/// has been merged with another set and is forwarding, return the ultimate
end_comment

begin_comment
comment|/// destination set.  This also implements the union-find collapsing as well.
end_comment

begin_function
name|AliasSet
modifier|*
name|getForwardedTarget
parameter_list|(
name|AliasSetTracker
modifier|&
name|AST
parameter_list|)
block|{
if|if
condition|(
operator|!
name|Forward
condition|)
return|return
name|this
return|;
name|AliasSet
modifier|*
name|Dest
init|=
name|Forward
operator|->
name|getForwardedTarget
argument_list|(
name|AST
argument_list|)
decl_stmt|;
if|if
condition|(
name|Dest
operator|!=
name|Forward
condition|)
block|{
name|Dest
operator|->
name|addRef
argument_list|()
expr_stmt|;
name|Forward
operator|->
name|dropRef
argument_list|(
name|AST
argument_list|)
expr_stmt|;
name|Forward
operator|=
name|Dest
expr_stmt|;
block|}
return|return
name|Dest
return|;
block|}
end_function

begin_function_decl
name|void
name|removeFromTracker
parameter_list|(
name|AliasSetTracker
modifier|&
name|AST
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addPointer
parameter_list|(
name|AliasSetTracker
modifier|&
name|AST
parameter_list|,
name|PointerRec
modifier|&
name|Entry
parameter_list|,
name|uint64_t
name|Size
parameter_list|,
specifier|const
name|AAMDNodes
modifier|&
name|AAInfo
parameter_list|,
name|bool
name|KnownMustAlias
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addUnknownInst
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
name|AliasAnalysis
modifier|&
name|AA
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|removeUnknownInst
parameter_list|(
name|AliasSetTracker
modifier|&
name|AST
parameter_list|,
name|Instruction
modifier|*
name|I
parameter_list|)
block|{
name|bool
name|WasEmpty
init|=
name|UnknownInsts
operator|.
name|empty
argument_list|()
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|,
name|e
init|=
name|UnknownInsts
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|UnknownInsts
index|[
name|i
index|]
operator|==
name|I
condition|)
block|{
name|UnknownInsts
index|[
name|i
index|]
operator|=
name|UnknownInsts
operator|.
name|back
argument_list|()
expr_stmt|;
name|UnknownInsts
operator|.
name|pop_back
argument_list|()
expr_stmt|;
operator|--
name|i
expr_stmt|;
operator|--
name|e
expr_stmt|;
comment|// Revisit the moved entry.
block|}
if|if
condition|(
operator|!
name|WasEmpty
operator|&&
name|UnknownInsts
operator|.
name|empty
argument_list|()
condition|)
name|dropRef
argument_list|(
name|AST
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setVolatile
parameter_list|()
block|{
name|Volatile
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_comment
comment|/// aliasesPointer - Return true if the specified pointer "may" (or must)
end_comment

begin_comment
comment|/// alias one of the members in the set.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|bool
name|aliasesPointer
argument_list|(
specifier|const
name|Value
operator|*
name|Ptr
argument_list|,
name|uint64_t
name|Size
argument_list|,
specifier|const
name|AAMDNodes
operator|&
name|AAInfo
argument_list|,
name|AliasAnalysis
operator|&
name|AA
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|aliasesUnknownInst
argument_list|(
name|Instruction
operator|*
name|Inst
argument_list|,
name|AliasAnalysis
operator|&
name|AA
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
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
name|AliasSet
operator|&
name|AS
operator|)
block|{
name|AS
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
end_expr_stmt

begin_decl_stmt
name|class
name|AliasSetTracker
block|{
comment|/// CallbackVH - A CallbackVH to arrange for AliasSetTracker to be
comment|/// notified whenever a Value is deleted.
name|class
name|ASTCallbackVH
range|:
name|public
name|CallbackVH
block|{
name|AliasSetTracker
operator|*
name|AST
block|;
name|void
name|deleted
argument_list|()
name|override
block|;
name|void
name|allUsesReplacedWith
argument_list|(
argument|Value *
argument_list|)
name|override
block|;
name|public
operator|:
name|ASTCallbackVH
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|AliasSetTracker
operator|*
name|AST
operator|=
name|nullptr
argument_list|)
block|;
name|ASTCallbackVH
operator|&
name|operator
operator|=
operator|(
name|Value
operator|*
name|V
operator|)
block|;   }
decl_stmt|;
comment|/// ASTCallbackVHDenseMapInfo - Traits to tell DenseMap that tell us how to
comment|/// compare and hash the value handle.
name|struct
name|ASTCallbackVHDenseMapInfo
range|:
name|public
name|DenseMapInfo
operator|<
name|Value
operator|*
operator|>
block|{}
decl_stmt|;
name|AliasAnalysis
modifier|&
name|AA
decl_stmt|;
name|ilist
operator|<
name|AliasSet
operator|>
name|AliasSets
expr_stmt|;
typedef|typedef
name|DenseMap
operator|<
name|ASTCallbackVH
operator|,
name|AliasSet
operator|::
name|PointerRec
operator|*
operator|,
name|ASTCallbackVHDenseMapInfo
operator|>
name|PointerMapType
expr_stmt|;
comment|// Map from pointers to their node
name|PointerMapType
name|PointerMap
decl_stmt|;
name|public
label|:
comment|/// AliasSetTracker ctor - Create an empty collection of AliasSets, and use
comment|/// the specified alias analysis object to disambiguate load and store
comment|/// addresses.
name|explicit
name|AliasSetTracker
argument_list|(
name|AliasAnalysis
operator|&
name|aa
argument_list|)
operator|:
name|AA
argument_list|(
argument|aa
argument_list|)
block|{}
operator|~
name|AliasSetTracker
argument_list|()
block|{
name|clear
argument_list|()
block|; }
comment|/// add methods - These methods are used to add different types of
comment|/// instructions to the alias sets.  Adding a new instruction can result in
comment|/// one of three actions happening:
comment|///
comment|///   1. If the instruction doesn't alias any other sets, create a new set.
comment|///   2. If the instruction aliases exactly one set, add it to the set
comment|///   3. If the instruction aliases multiple sets, merge the sets, and add
comment|///      the instruction to the result.
comment|///
comment|/// These methods return true if inserting the instruction resulted in the
comment|/// addition of a new alias set (i.e., the pointer did not alias anything).
comment|///
name|bool
name|add
argument_list|(
argument|Value *Ptr
argument_list|,
argument|uint64_t Size
argument_list|,
argument|const AAMDNodes&AAInfo
argument_list|)
expr_stmt|;
comment|// Add a loc.
name|bool
name|add
parameter_list|(
name|LoadInst
modifier|*
name|LI
parameter_list|)
function_decl|;
name|bool
name|add
parameter_list|(
name|StoreInst
modifier|*
name|SI
parameter_list|)
function_decl|;
name|bool
name|add
parameter_list|(
name|VAArgInst
modifier|*
name|VAAI
parameter_list|)
function_decl|;
name|bool
name|add
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
comment|// Dispatch to one of the other add methods...
name|void
name|add
parameter_list|(
name|BasicBlock
modifier|&
name|BB
parameter_list|)
function_decl|;
comment|// Add all instructions in basic block
name|void
name|add
parameter_list|(
specifier|const
name|AliasSetTracker
modifier|&
name|AST
parameter_list|)
function_decl|;
comment|// Add alias relations from another AST
name|bool
name|addUnknown
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// remove methods - These methods are used to remove all entries that might
comment|/// be aliased by the specified instruction.  These methods return true if any
comment|/// alias sets were eliminated.
comment|// Remove a location
name|bool
name|remove
parameter_list|(
name|Value
modifier|*
name|Ptr
parameter_list|,
name|uint64_t
name|Size
parameter_list|,
specifier|const
name|AAMDNodes
modifier|&
name|AAInfo
parameter_list|)
function_decl|;
name|bool
name|remove
parameter_list|(
name|LoadInst
modifier|*
name|LI
parameter_list|)
function_decl|;
name|bool
name|remove
parameter_list|(
name|StoreInst
modifier|*
name|SI
parameter_list|)
function_decl|;
name|bool
name|remove
parameter_list|(
name|VAArgInst
modifier|*
name|VAAI
parameter_list|)
function_decl|;
name|bool
name|remove
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
name|void
name|remove
parameter_list|(
name|AliasSet
modifier|&
name|AS
parameter_list|)
function_decl|;
name|bool
name|removeUnknown
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
comment|/// getAliasSets - Return the alias sets that are active.
comment|///
specifier|const
name|ilist
operator|<
name|AliasSet
operator|>
operator|&
name|getAliasSets
argument_list|()
specifier|const
block|{
return|return
name|AliasSets
return|;
block|}
comment|/// getAliasSetForPointer - Return the alias set that the specified pointer
comment|/// lives in.  If the New argument is non-null, this method sets the value to
comment|/// true if a new alias set is created to contain the pointer (because the
comment|/// pointer didn't alias anything).
name|AliasSet
modifier|&
name|getAliasSetForPointer
parameter_list|(
name|Value
modifier|*
name|P
parameter_list|,
name|uint64_t
name|Size
parameter_list|,
specifier|const
name|AAMDNodes
modifier|&
name|AAInfo
parameter_list|,
name|bool
modifier|*
name|New
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// getAliasSetForPointerIfExists - Return the alias set containing the
comment|/// location specified if one exists, otherwise return null.
name|AliasSet
modifier|*
name|getAliasSetForPointerIfExists
parameter_list|(
name|Value
modifier|*
name|P
parameter_list|,
name|uint64_t
name|Size
parameter_list|,
specifier|const
name|AAMDNodes
modifier|&
name|AAInfo
parameter_list|)
block|{
return|return
name|findAliasSetForPointer
argument_list|(
name|P
argument_list|,
name|Size
argument_list|,
name|AAInfo
argument_list|)
return|;
block|}
comment|/// containsPointer - Return true if the specified location is represented by
comment|/// this alias set, false otherwise.  This does not modify the AST object or
comment|/// alias sets.
name|bool
name|containsPointer
argument_list|(
name|Value
operator|*
name|P
argument_list|,
name|uint64_t
name|Size
argument_list|,
specifier|const
name|AAMDNodes
operator|&
name|AAInfo
argument_list|)
decl|const
decl_stmt|;
comment|/// Return true if the specified instruction "may" (or must) alias one of the
comment|/// members in any of the sets.
name|bool
name|containsUnknown
argument_list|(
name|Instruction
operator|*
name|I
argument_list|)
decl|const
decl_stmt|;
comment|/// getAliasAnalysis - Return the underlying alias analysis object used by
comment|/// this tracker.
name|AliasAnalysis
operator|&
name|getAliasAnalysis
argument_list|()
specifier|const
block|{
return|return
name|AA
return|;
block|}
comment|/// deleteValue method - This method is used to remove a pointer value from
comment|/// the AliasSetTracker entirely.  It should be used when an instruction is
comment|/// deleted from the program to update the AST.  If you don't use this, you
comment|/// would have dangling pointers to deleted instructions.
comment|///
name|void
name|deleteValue
parameter_list|(
name|Value
modifier|*
name|PtrVal
parameter_list|)
function_decl|;
comment|/// copyValue - This method should be used whenever a preexisting value in the
comment|/// program is copied or cloned, introducing a new value.  Note that it is ok
comment|/// for clients that use this method to introduce the same value multiple
comment|/// times: if the tracker already knows about a value, it will ignore the
comment|/// request.
comment|///
name|void
name|copyValue
parameter_list|(
name|Value
modifier|*
name|From
parameter_list|,
name|Value
modifier|*
name|To
parameter_list|)
function_decl|;
typedef|typedef
name|ilist
operator|<
name|AliasSet
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|ilist
operator|<
name|AliasSet
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|AliasSets
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|AliasSets
operator|.
name|end
argument_list|()
return|;
block|}
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|AliasSets
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|AliasSets
operator|.
name|end
argument_list|()
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
name|private
label|:
name|friend
name|class
name|AliasSet
decl_stmt|;
name|void
name|removeAliasSet
parameter_list|(
name|AliasSet
modifier|*
name|AS
parameter_list|)
function_decl|;
comment|// getEntryFor - Just like operator[] on the map, except that it creates an
comment|// entry for the pointer if it doesn't already exist.
name|AliasSet
operator|::
name|PointerRec
operator|&
name|getEntryFor
argument_list|(
argument|Value *V
argument_list|)
block|{
name|AliasSet
operator|::
name|PointerRec
operator|*
operator|&
name|Entry
operator|=
name|PointerMap
index|[
name|ASTCallbackVH
argument_list|(
name|V
argument_list|,
name|this
argument_list|)
index|]
block|;
if|if
condition|(
operator|!
name|Entry
condition|)
name|Entry
operator|=
name|new
name|AliasSet
operator|::
name|PointerRec
argument_list|(
name|V
argument_list|)
expr_stmt|;
return|return
operator|*
name|Entry
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|AliasSet
modifier|&
name|addPointer
argument_list|(
name|Value
operator|*
name|P
argument_list|,
name|uint64_t
name|Size
argument_list|,
specifier|const
name|AAMDNodes
operator|&
name|AAInfo
argument_list|,
name|AliasSet
operator|::
name|AccessType
name|E
argument_list|,
name|bool
operator|&
name|NewSet
argument_list|)
block|{
name|NewSet
operator|=
name|false
expr_stmt|;
name|AliasSet
modifier|&
name|AS
init|=
name|getAliasSetForPointer
argument_list|(
name|P
argument_list|,
name|Size
argument_list|,
name|AAInfo
argument_list|,
operator|&
name|NewSet
argument_list|)
decl_stmt|;
name|AS
operator|.
name|AccessTy
operator||=
name|E
expr_stmt|;
return|return
name|AS
return|;
block|}
end_decl_stmt

begin_function_decl
name|AliasSet
modifier|*
name|findAliasSetForPointer
parameter_list|(
specifier|const
name|Value
modifier|*
name|Ptr
parameter_list|,
name|uint64_t
name|Size
parameter_list|,
specifier|const
name|AAMDNodes
modifier|&
name|AAInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AliasSet
modifier|*
name|findAliasSetForUnknownInst
parameter_list|(
name|Instruction
modifier|*
name|Inst
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
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
name|AliasSetTracker
operator|&
name|AST
operator|)
block|{
name|AST
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
end_expr_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

