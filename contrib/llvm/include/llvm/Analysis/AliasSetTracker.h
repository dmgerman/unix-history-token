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
comment|// This file defines two classes: AliasSetTracker and AliasSet. These interfaces
end_comment

begin_comment
comment|// are used to classify a collection of pointer references into a maximal number
end_comment

begin_comment
comment|// of disjoint sets. Each AliasSet object constructed by the AliasSetTracker
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
file|"llvm/Analysis/AliasAnalysis.h"
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
name|LoadInst
decl_stmt|;
name|class
name|StoreInst
decl_stmt|;
name|class
name|VAArgInst
decl_stmt|;
name|class
name|MemSetInst
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
name|bool
name|updateSizeAndAAInfo
argument_list|(
argument|uint64_t NewSize
argument_list|,
argument|const AAMDNodes&NewAAInfo
argument_list|)
block|{
name|bool
name|SizeChanged
operator|=
name|false
block|;
if|if
condition|(
name|NewSize
operator|>
name|Size
condition|)
block|{
name|Size
operator|=
name|NewSize
expr_stmt|;
name|SizeChanged
operator|=
name|true
expr_stmt|;
block|}
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
return|return
name|SizeChanged
return|;
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
comment|/// Return the AAInfo, or null if there is no information or conflicting
comment|/// information.
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

begin_comment
comment|// Doubly linked list of nodes.
end_comment

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
comment|// Forwarding pointer.
end_comment

begin_decl_stmt
name|AliasSet
modifier|*
name|Forward
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// All instructions without a specific address in this alias set.
end_comment

begin_comment
comment|/// In rare cases this vector can have a null'ed out WeakVH
end_comment

begin_comment
comment|/// instances (can happen if some other loop pass deletes an
end_comment

begin_comment
comment|/// instruction in this list).
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|WeakVH
operator|>
name|UnknownInsts
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Number of nodes pointing to this AliasSet plus the number of AliasSets
end_comment

begin_comment
comment|/// forwarding to it.
end_comment

begin_decl_stmt
name|unsigned
name|RefCount
range|:
literal|27
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Signifies that this set should be considered to alias any pointer.
end_comment

begin_comment
comment|// Use when the tracker holding this set is saturated.
end_comment

begin_decl_stmt
name|unsigned
name|AliasAny
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The kinds of access this alias set models.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// We keep track of whether this alias set merely refers to the locations of
end_comment

begin_comment
comment|/// memory (and not any particular access), whether it modifies or references
end_comment

begin_comment
comment|/// the memory, or whether it does both. The lattice goes from "NoAccess" to
end_comment

begin_comment
comment|/// either RefAccess or ModAccess, then to ModRefAccess as necessary.
end_comment

begin_enum
enum|enum
name|AccessLattice
block|{
name|NoAccess
init|=
literal|0
block|,
name|RefAccess
init|=
literal|1
block|,
name|ModAccess
init|=
literal|2
block|,
name|ModRefAccess
init|=
name|RefAccess
operator||
name|ModAccess
block|}
enum|;
end_enum

begin_decl_stmt
name|unsigned
name|Access
range|:
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The kind of alias relationship between pointers of the set.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These represent conservatively correct alias results between any members
end_comment

begin_comment
comment|/// of the set. We represent these independently of the values of alias
end_comment

begin_comment
comment|/// results in order to pack it into a single bit. Lattice goes from
end_comment

begin_comment
comment|/// MustAlias to MayAlias.
end_comment

begin_enum
enum|enum
name|AliasLattice
block|{
name|SetMustAlias
init|=
literal|0
block|,
name|SetMayAlias
init|=
literal|1
block|}
enum|;
end_enum

begin_decl_stmt
name|unsigned
name|Alias
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// True if this alias set contains volatile loads or stores.
end_comment

begin_decl_stmt
name|unsigned
name|Volatile
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|SetSize
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
name|cast_or_null
operator|<
name|Instruction
operator|>
operator|(
name|UnknownInsts
index|[
name|i
index|]
operator|)
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
name|Access
operator|&
name|RefAccess
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
name|Access
operator|&
name|ModAccess
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
name|Alias
operator|==
name|SetMustAlias
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
name|Alias
operator|==
name|SetMayAlias
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Return true if this alias set contains volatile loads or stores.
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
comment|/// Return true if this alias set should be ignored as part of the
end_comment

begin_comment
comment|/// AliasSetTracker object.
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
comment|/// Merge the specified alias set into this alias set.
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
comment|// Alias Set iteration - Allow access to all of the pointers which are part of
end_comment

begin_comment
comment|// this alias set.
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

begin_comment
comment|// Unfortunately, ilist::size() is linear, so we have to add code to keep
end_comment

begin_comment
comment|// track of the list's exact size.
end_comment

begin_function
name|unsigned
name|size
parameter_list|()
block|{
return|return
name|SetSize
return|;
block|}
end_function

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
comment|// Can only be created by AliasSetTracker.
end_comment

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
name|AliasAny
argument_list|(
name|false
argument_list|)
operator|,
name|Access
argument_list|(
name|NoAccess
argument_list|)
operator|,
name|Alias
argument_list|(
name|SetMustAlias
argument_list|)
operator|,
name|Volatile
argument_list|(
name|false
argument_list|)
operator|,
name|SetSize
argument_list|(
literal|0
argument_list|)
block|{}
name|AliasSet
argument_list|(
specifier|const
name|AliasSet
operator|&
name|AS
argument_list|)
operator|=
name|delete
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
operator|=
name|delete
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
comment|/// Return the real alias set this represents. If this has been merged with
end_comment

begin_comment
comment|/// another set and is forwarding, return the ultimate destination set. This
end_comment

begin_comment
comment|/// also implements the union-find collapsing as well.
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
comment|/// Return true if the specified pointer "may" (or must) alias one of the
end_comment

begin_comment
comment|/// members in the set.
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
specifier|const
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
comment|/// A CallbackVH to arrange for AliasSetTracker to be notified whenever a
comment|/// Value is deleted.
name|class
name|ASTCallbackVH
name|final
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
comment|/// Traits to tell DenseMap that tell us how to compare and hash the value
comment|/// handle.
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
comment|/// Create an empty collection of AliasSets, and use the specified alias
comment|/// analysis object to disambiguate load and store addresses.
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
name|aa
argument_list|)
operator|,
name|TotalMayAliasSetSize
argument_list|(
literal|0
argument_list|)
operator|,
name|AliasAnyAS
argument_list|(
argument|nullptr
argument_list|)
block|{}
operator|~
name|AliasSetTracker
argument_list|()
block|{
name|clear
argument_list|()
block|; }
comment|/// These methods are used to add different types of instructions to the alias
comment|/// sets. Adding a new instruction can result in one of three actions
comment|/// happening:
comment|///
comment|///   1. If the instruction doesn't alias any other sets, create a new set.
comment|///   2. If the instruction aliases exactly one set, add it to the set
comment|///   3. If the instruction aliases multiple sets, merge the sets, and add
comment|///      the instruction to the result.
comment|///
comment|/// These methods return true if inserting the instruction resulted in the
comment|/// addition of a new alias set (i.e., the pointer did not alias anything).
comment|///
name|void
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
name|void
name|add
parameter_list|(
name|LoadInst
modifier|*
name|LI
parameter_list|)
function_decl|;
name|void
name|add
parameter_list|(
name|StoreInst
modifier|*
name|SI
parameter_list|)
function_decl|;
name|void
name|add
parameter_list|(
name|VAArgInst
modifier|*
name|VAAI
parameter_list|)
function_decl|;
name|void
name|add
parameter_list|(
name|MemSetInst
modifier|*
name|MSI
parameter_list|)
function_decl|;
name|void
name|add
parameter_list|(
name|MemTransferInst
modifier|*
name|MTI
parameter_list|)
function_decl|;
name|void
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
name|void
name|addUnknown
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
comment|/// Return the alias sets that are active.
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
comment|/// Return the alias set that the specified pointer lives in. If the New
comment|/// argument is non-null, this method sets the value to true if a new alias
comment|/// set is created to contain the pointer (because the pointer didn't alias
comment|/// anything).
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
parameter_list|)
function_decl|;
comment|/// Return the alias set containing the location specified if one exists,
comment|/// otherwise return null.
name|AliasSet
modifier|*
name|getAliasSetForPointerIfExists
parameter_list|(
specifier|const
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
name|mergeAliasSetsForPointer
argument_list|(
name|P
argument_list|,
name|Size
argument_list|,
name|AAInfo
argument_list|)
return|;
block|}
comment|/// Return true if the specified instruction "may" (or must) alias one of the
comment|/// members in any of the sets.
name|bool
name|containsUnknown
argument_list|(
specifier|const
name|Instruction
operator|*
name|I
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the underlying alias analysis object used by this tracker.
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
comment|/// This method is used to remove a pointer value from the AliasSetTracker
comment|/// entirely. It should be used when an instruction is deleted from the
comment|/// program to update the AST. If you don't use this, you would have dangling
comment|/// pointers to deleted instructions.
name|void
name|deleteValue
parameter_list|(
name|Value
modifier|*
name|PtrVal
parameter_list|)
function_decl|;
comment|/// This method should be used whenever a preexisting value in the program is
comment|/// copied or cloned, introducing a new value.  Note that it is ok for clients
comment|/// that use this method to introduce the same value multiple times: if the
comment|/// tracker already knows about a value, it will ignore the request.
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
comment|// The total number of pointers contained in all "may" alias sets.
name|unsigned
name|TotalMayAliasSetSize
decl_stmt|;
comment|// A non-null value signifies this AST is saturated. A saturated AST lumps
comment|// all pointers into a single "May" set.
name|AliasSet
modifier|*
name|AliasAnyAS
decl_stmt|;
name|void
name|removeAliasSet
parameter_list|(
name|AliasSet
modifier|*
name|AS
parameter_list|)
function_decl|;
comment|/// Just like operator[] on the map, except that it creates an entry for the
comment|/// pointer if it doesn't already exist.
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
name|AccessLattice
name|E
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|AliasSet
modifier|*
name|mergeAliasSetsForPointer
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

begin_comment
comment|/// Merge all alias sets into a single set that is considered to alias any
end_comment

begin_comment
comment|/// pointer.
end_comment

begin_function_decl
name|AliasSet
modifier|&
name|mergeAllAliasSets
parameter_list|()
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

