begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/EquivalenceClasses.h - Generic Equiv. Classes ---*- C++ -*-===//
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
comment|// Generic implementation of equivalence classes through the use Tarjan's
end_comment

begin_comment
comment|// efficient union-find algorithm.
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
name|LLVM_ADT_EQUIVALENCECLASSES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_EQUIVALENCECLASSES_H
end_define

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
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<iterator>
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
comment|/// EquivalenceClasses - This represents a collection of equivalence classes and
comment|/// supports three efficient operations: insert an element into a class of its
comment|/// own, union two classes, and find the class for a given element.  In
comment|/// addition to these modification methods, it is possible to iterate over all
comment|/// of the equivalence classes and all of the elements in a class.
comment|///
comment|/// This implementation is an efficient implementation that only stores one copy
comment|/// of the element being indexed per entry in the set, and allows any arbitrary
comment|/// type to be indexed (as long as it can be ordered with operator<).
comment|///
comment|/// Here is a simple example using integers:
comment|///
comment|/// \code
comment|///  EquivalenceClasses<int> EC;
comment|///  EC.unionSets(1, 2);                // insert 1, 2 into the same set
comment|///  EC.insert(4); EC.insert(5);        // insert 4, 5 into own sets
comment|///  EC.unionSets(5, 1);                // merge the set for 1 with 5's set.
comment|///
comment|///  for (EquivalenceClasses<int>::iterator I = EC.begin(), E = EC.end();
comment|///       I != E; ++I) {           // Iterate over all of the equivalence sets.
comment|///    if (!I->isLeader()) continue;   // Ignore non-leader sets.
comment|///    for (EquivalenceClasses<int>::member_iterator MI = EC.member_begin(I);
comment|///         MI != EC.member_end(); ++MI)   // Loop over members in this set.
comment|///      cerr<< *MI<< " ";  // Print member.
comment|///    cerr<< "\n";   // Finish set.
comment|///  }
comment|/// \endcode
comment|///
comment|/// This example prints:
comment|///   4
comment|///   5 1 2
comment|///
name|template
operator|<
name|class
name|ElemTy
operator|>
name|class
name|EquivalenceClasses
block|{
comment|/// ECValue - The EquivalenceClasses data structure is just a set of these.
comment|/// Each of these represents a relation for a value.  First it stores the
comment|/// value itself, which provides the ordering that the set queries.  Next, it
comment|/// provides a "next pointer", which is used to enumerate all of the elements
comment|/// in the unioned set.  Finally, it defines either a "end of list pointer" or
comment|/// "leader pointer" depending on whether the value itself is a leader.  A
comment|/// "leader pointer" points to the node that is the leader for this element,
comment|/// if the node is not a leader.  A "end of list pointer" points to the last
comment|/// node in the list of members of this list.  Whether or not a node is a
comment|/// leader is determined by a bit stolen from one of the pointers.
name|class
name|ECValue
block|{
name|friend
name|class
name|EquivalenceClasses
block|;
name|mutable
specifier|const
name|ECValue
operator|*
name|Leader
block|,
operator|*
name|Next
block|;
name|ElemTy
name|Data
block|;
comment|// ECValue ctor - Start out with EndOfList pointing to this node, Next is
comment|// Null, isLeader = true.
name|ECValue
argument_list|(
specifier|const
name|ElemTy
operator|&
name|Elt
argument_list|)
operator|:
name|Leader
argument_list|(
name|this
argument_list|)
block|,
name|Next
argument_list|(
operator|(
name|ECValue
operator|*
operator|)
operator|(
name|intptr_t
operator|)
literal|1
argument_list|)
block|,
name|Data
argument_list|(
argument|Elt
argument_list|)
block|{}
specifier|const
name|ECValue
operator|*
name|getLeader
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isLeader
argument_list|()
condition|)
return|return
name|this
return|;
if|if
condition|(
name|Leader
operator|->
name|isLeader
argument_list|()
condition|)
return|return
name|Leader
return|;
comment|// Path compression.
return|return
name|Leader
operator|=
name|Leader
operator|->
name|getLeader
argument_list|()
return|;
block|}
specifier|const
name|ECValue
operator|*
name|getEndOfList
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isLeader
argument_list|()
operator|&&
literal|"Cannot get the end of a list for a non-leader!"
argument_list|)
block|;
return|return
name|Leader
return|;
block|}
name|void
name|setNext
argument_list|(
specifier|const
name|ECValue
operator|*
name|NewNext
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|getNext
argument_list|()
operator|==
name|nullptr
operator|&&
literal|"Already has a next pointer!"
argument_list|)
expr_stmt|;
name|Next
operator|=
operator|(
specifier|const
name|ECValue
operator|*
operator|)
operator|(
operator|(
name|intptr_t
operator|)
name|NewNext
operator||
operator|(
name|intptr_t
operator|)
name|isLeader
argument_list|()
operator|)
expr_stmt|;
block|}
name|public
label|:
name|ECValue
argument_list|(
specifier|const
name|ECValue
operator|&
name|RHS
argument_list|)
operator|:
name|Leader
argument_list|(
name|this
argument_list|)
operator|,
name|Next
argument_list|(
operator|(
name|ECValue
operator|*
operator|)
operator|(
name|intptr_t
operator|)
literal|1
argument_list|)
operator|,
name|Data
argument_list|(
argument|RHS.Data
argument_list|)
block|{
comment|// Only support copying of singleton nodes.
name|assert
argument_list|(
name|RHS
operator|.
name|isLeader
argument_list|()
operator|&&
name|RHS
operator|.
name|getNext
argument_list|()
operator|==
name|nullptr
operator|&&
literal|"Not a singleton!"
argument_list|)
block|;     }
name|bool
name|operator
operator|<
operator|(
specifier|const
name|ECValue
operator|&
name|UFN
operator|)
specifier|const
block|{
return|return
name|Data
operator|<
name|UFN
operator|.
name|Data
return|;
block|}
name|bool
name|isLeader
argument_list|()
specifier|const
block|{
return|return
operator|(
name|intptr_t
operator|)
name|Next
operator|&
literal|1
return|;
block|}
specifier|const
name|ElemTy
operator|&
name|getData
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
specifier|const
name|ECValue
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
operator|(
name|ECValue
operator|*
operator|)
operator|(
operator|(
name|intptr_t
operator|)
name|Next
operator|&
operator|~
operator|(
name|intptr_t
operator|)
literal|1
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|operator
operator|<
operator|(
specifier|const
name|T
operator|&
name|Val
operator|)
specifier|const
block|{
return|return
name|Data
operator|<
name|Val
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// TheMapping - This implicitly provides a mapping from ElemTy values to the
end_comment

begin_comment
comment|/// ECValues, it just keeps the key as part of the value.
end_comment

begin_expr_stmt
name|std
operator|::
name|set
operator|<
name|ECValue
operator|>
name|TheMapping
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|EquivalenceClasses
argument_list|()
operator|=
expr|default
expr_stmt|;
end_expr_stmt

begin_macro
name|EquivalenceClasses
argument_list|(
argument|const EquivalenceClasses&RHS
argument_list|)
end_macro

begin_block
block|{
name|operator
operator|=
operator|(
name|RHS
operator|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|const
name|EquivalenceClasses
modifier|&
name|operator
init|=
operator|(
specifier|const
name|EquivalenceClasses
operator|&
name|RHS
operator|)
block|{
name|TheMapping
operator|.
name|clear
argument_list|()
block|;
for|for
control|(
name|iterator
name|I
init|=
name|RHS
operator|.
name|begin
argument_list|()
init|,
name|E
init|=
name|RHS
operator|.
name|end
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
name|I
operator|->
name|isLeader
argument_list|()
condition|)
block|{
name|member_iterator
name|MI
init|=
name|RHS
operator|.
name|member_begin
argument_list|(
name|I
argument_list|)
decl_stmt|;
name|member_iterator
name|LeaderIt
init|=
name|member_begin
argument_list|(
name|insert
argument_list|(
operator|*
name|MI
argument_list|)
argument_list|)
decl_stmt|;
for|for
control|(
operator|++
name|MI
init|;
name|MI
operator|!=
name|member_end
argument_list|()
condition|;
operator|++
name|MI
control|)
name|unionSets
argument_list|(
name|LeaderIt
argument_list|,
name|member_begin
argument_list|(
name|insert
argument_list|(
operator|*
name|MI
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Inspection methods
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// iterator* - Provides a way to iterate over all values in the set.
end_comment

begin_decl_stmt
name|using
name|iterator
init|=
name|typename
name|std
operator|::
name|set
operator|<
name|ECValue
operator|>
operator|::
name|const_iterator
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|TheMapping
operator|.
name|begin
argument_list|()
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
name|TheMapping
operator|.
name|end
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
name|TheMapping
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// member_* Iterate over the members of an equivalence class.
end_comment

begin_decl_stmt
name|class
name|member_iterator
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|member_iterator
name|member_begin
argument_list|(
name|iterator
name|I
argument_list|)
decl|const
block|{
comment|// Only leaders provide anything to iterate over.
return|return
name|member_iterator
argument_list|(
name|I
operator|->
name|isLeader
argument_list|()
condition|?
operator|&
operator|*
name|I
else|:
name|nullptr
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|member_iterator
name|member_end
argument_list|()
specifier|const
block|{
return|return
name|member_iterator
argument_list|(
name|nullptr
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// findValue - Return an iterator to the specified value.  If it does not
end_comment

begin_comment
comment|/// exist, end() is returned.
end_comment

begin_decl_stmt
name|iterator
name|findValue
argument_list|(
specifier|const
name|ElemTy
operator|&
name|V
argument_list|)
decl|const
block|{
return|return
name|TheMapping
operator|.
name|find
argument_list|(
name|V
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getLeaderValue - Return the leader for the specified value that is in the
end_comment

begin_comment
comment|/// set.  It is an error to call this method for a value that is not yet in
end_comment

begin_comment
comment|/// the set.  For that, call getOrInsertLeaderValue(V).
end_comment

begin_decl_stmt
specifier|const
name|ElemTy
modifier|&
name|getLeaderValue
argument_list|(
specifier|const
name|ElemTy
operator|&
name|V
argument_list|)
decl|const
block|{
name|member_iterator
name|MI
init|=
name|findLeader
argument_list|(
name|V
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|MI
operator|!=
name|member_end
argument_list|()
operator|&&
literal|"Value is not in the set!"
argument_list|)
expr_stmt|;
return|return
operator|*
name|MI
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getOrInsertLeaderValue - Return the leader for the specified value that is
end_comment

begin_comment
comment|/// in the set.  If the member is not in the set, it is inserted, then
end_comment

begin_comment
comment|/// returned.
end_comment

begin_function
specifier|const
name|ElemTy
modifier|&
name|getOrInsertLeaderValue
parameter_list|(
specifier|const
name|ElemTy
modifier|&
name|V
parameter_list|)
block|{
name|member_iterator
name|MI
init|=
name|findLeader
argument_list|(
name|insert
argument_list|(
name|V
argument_list|)
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|MI
operator|!=
name|member_end
argument_list|()
operator|&&
literal|"Value is not in the set!"
argument_list|)
expr_stmt|;
return|return
operator|*
name|MI
return|;
block|}
end_function

begin_comment
comment|/// getNumClasses - Return the number of equivalence classes in this set.
end_comment

begin_comment
comment|/// Note that this is a linear time operation.
end_comment

begin_expr_stmt
name|unsigned
name|getNumClasses
argument_list|()
specifier|const
block|{
name|unsigned
name|NC
operator|=
literal|0
block|;
for|for
control|(
name|iterator
name|I
init|=
name|begin
argument_list|()
init|,
name|E
init|=
name|end
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
name|I
operator|->
name|isLeader
argument_list|()
condition|)
operator|++
name|NC
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|NC
return|;
end_return

begin_comment
unit|}
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Mutation methods
end_comment

begin_comment
comment|/// insert - Insert a new value into the union/find set, ignoring the request
end_comment

begin_comment
comment|/// if the value already exists.
end_comment

begin_macro
unit|iterator
name|insert
argument_list|(
argument|const ElemTy&Data
argument_list|)
end_macro

begin_block
block|{
return|return
name|TheMapping
operator|.
name|insert
argument_list|(
name|ECValue
argument_list|(
name|Data
argument_list|)
argument_list|)
operator|.
name|first
return|;
block|}
end_block

begin_comment
comment|/// findLeader - Given a value in the set, return a member iterator for the
end_comment

begin_comment
comment|/// equivalence class it is in.  This does the path-compression part that
end_comment

begin_comment
comment|/// makes union-find "union findy".  This returns an end iterator if the value
end_comment

begin_comment
comment|/// is not in the equivalence class.
end_comment

begin_decl_stmt
name|member_iterator
name|findLeader
argument_list|(
name|iterator
name|I
argument_list|)
decl|const
block|{
if|if
condition|(
name|I
operator|==
name|TheMapping
operator|.
name|end
argument_list|()
condition|)
return|return
name|member_end
argument_list|()
return|;
return|return
name|member_iterator
argument_list|(
name|I
operator|->
name|getLeader
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|member_iterator
name|findLeader
argument_list|(
specifier|const
name|ElemTy
operator|&
name|V
argument_list|)
decl|const
block|{
return|return
name|findLeader
argument_list|(
name|TheMapping
operator|.
name|find
argument_list|(
name|V
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// union - Merge the two equivalence sets for the specified values, inserting
end_comment

begin_comment
comment|/// them if they do not already exist in the equivalence set.
end_comment

begin_function
name|member_iterator
name|unionSets
parameter_list|(
specifier|const
name|ElemTy
modifier|&
name|V1
parameter_list|,
specifier|const
name|ElemTy
modifier|&
name|V2
parameter_list|)
block|{
name|iterator
name|V1I
init|=
name|insert
argument_list|(
name|V1
argument_list|)
decl_stmt|,
name|V2I
init|=
name|insert
argument_list|(
name|V2
argument_list|)
decl_stmt|;
return|return
name|unionSets
argument_list|(
name|findLeader
argument_list|(
name|V1I
argument_list|)
argument_list|,
name|findLeader
argument_list|(
name|V2I
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|member_iterator
name|unionSets
parameter_list|(
name|member_iterator
name|L1
parameter_list|,
name|member_iterator
name|L2
parameter_list|)
block|{
name|assert
argument_list|(
name|L1
operator|!=
name|member_end
argument_list|()
operator|&&
name|L2
operator|!=
name|member_end
argument_list|()
operator|&&
literal|"Illegal inputs!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|L1
operator|==
name|L2
condition|)
return|return
name|L1
return|;
comment|// Unifying the same two sets, noop.
comment|// Otherwise, this is a real union operation.  Set the end of the L1 list to
comment|// point to the L2 leader node.
specifier|const
name|ECValue
modifier|&
name|L1LV
init|=
operator|*
name|L1
operator|.
name|Node
decl_stmt|,
modifier|&
name|L2LV
init|=
operator|*
name|L2
operator|.
name|Node
decl_stmt|;
name|L1LV
operator|.
name|getEndOfList
argument_list|()
operator|->
name|setNext
argument_list|(
operator|&
name|L2LV
argument_list|)
expr_stmt|;
comment|// Update L1LV's end of list pointer.
name|L1LV
operator|.
name|Leader
operator|=
name|L2LV
operator|.
name|getEndOfList
argument_list|()
expr_stmt|;
comment|// Clear L2's leader flag:
name|L2LV
operator|.
name|Next
operator|=
name|L2LV
operator|.
name|getNext
argument_list|()
expr_stmt|;
comment|// L2's leader is now L1.
name|L2LV
operator|.
name|Leader
operator|=
operator|&
name|L1LV
expr_stmt|;
return|return
name|L1
return|;
block|}
end_function

begin_decl_stmt
name|class
name|member_iterator
range|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
decl_stmt|,                                                const
name|ElemTy
decl_stmt|,
name|ptrdiff_t
decl|>
block|{
name|friend
name|class
name|EquivalenceClasses
decl_stmt|;
name|using
name|super
init|=
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
decl_stmt|,                                 const
name|ElemTy
decl_stmt|,
name|ptrdiff_t
decl|>
decl_stmt|;
specifier|const
name|ECValue
modifier|*
name|Node
decl_stmt|;
name|public
label|:
name|using
name|size_type
init|=
name|size_t
decl_stmt|;
name|using
name|pointer
init|=
name|typename
name|super
operator|::
name|pointer
decl_stmt|;
name|using
name|reference
init|=
name|typename
name|super
operator|::
name|reference
decl_stmt|;
name|explicit
name|member_iterator
parameter_list|()
init|=
init|default
function_decl|;
name|explicit
name|member_iterator
argument_list|(
specifier|const
name|ECValue
operator|*
name|N
argument_list|)
operator|:
name|Node
argument_list|(
argument|N
argument_list|)
block|{}
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Node
operator|!=
name|nullptr
operator|&&
literal|"Dereferencing end()!"
argument_list|)
block|;
return|return
name|Node
operator|->
name|getData
argument_list|()
return|;
block|}
name|pointer
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
name|member_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|assert
argument_list|(
name|Node
operator|!=
name|nullptr
operator|&&
literal|"++'d off the end of the list!"
argument_list|)
block|;
name|Node
operator|=
name|Node
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
name|member_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// postincrement operators.
name|member_iterator
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

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|member_iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Node
operator|==
name|RHS
operator|.
name|Node
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|member_iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Node
operator|!=
name|RHS
operator|.
name|Node
return|;
block|}
end_expr_stmt

begin_comment
unit|}; };  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_EQUIVALENCECLASSES_H
end_comment

end_unit

