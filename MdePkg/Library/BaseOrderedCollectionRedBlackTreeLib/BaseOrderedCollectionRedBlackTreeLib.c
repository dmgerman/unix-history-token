begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   An OrderedCollectionLib instance that provides a red-black tree   implementation, and allocates and releases tree nodes with   MemoryAllocationLib.    This library instance is useful when a fast associative container is needed.   Worst case time complexity is O(log n) for Find(), Next(), Prev(), Min(),   Max(), Insert(), and Delete(), where "n" is the number of elements in the   tree. Complete ordered traversal takes O(n) time.    The implementation is also useful as a fast priority queue.    Copyright (C) 2014, Red Hat, Inc.   Copyright (c) 2014, Intel Corporation. All rights reserved.<BR>    This program and the accompanying materials are licensed and made available   under the terms and conditions of the BSD License that accompanies this   distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT   WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. **/
end_comment

begin_include
include|#
directive|include
file|<Library/OrderedCollectionLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/MemoryAllocationLib.h>
end_include

begin_typedef
typedef|typedef
enum|enum
block|{
name|RedBlackTreeRed
block|,
name|RedBlackTreeBlack
block|}
name|RED_BLACK_TREE_COLOR
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Incomplete types and convenience typedefs are present in the library class
end_comment

begin_comment
comment|// header. Beside completing the types, we introduce typedefs here that reflect
end_comment

begin_comment
comment|// the implementation closely.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|ORDERED_COLLECTION
name|RED_BLACK_TREE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ORDERED_COLLECTION_ENTRY
name|RED_BLACK_TREE_NODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ORDERED_COLLECTION_USER_COMPARE
name|RED_BLACK_TREE_USER_COMPARE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ORDERED_COLLECTION_KEY_COMPARE
name|RED_BLACK_TREE_KEY_COMPARE
typedef|;
end_typedef

begin_struct
struct|struct
name|ORDERED_COLLECTION
block|{
name|RED_BLACK_TREE_NODE
modifier|*
name|Root
decl_stmt|;
name|RED_BLACK_TREE_USER_COMPARE
name|UserStructCompare
decl_stmt|;
name|RED_BLACK_TREE_KEY_COMPARE
name|KeyCompare
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ORDERED_COLLECTION_ENTRY
block|{
name|VOID
modifier|*
name|UserStruct
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|Parent
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|Left
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|Right
decl_stmt|;
name|RED_BLACK_TREE_COLOR
name|Color
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**   Retrieve the user structure linked by the specified tree node.    Read-only operation.    @param[in] Node  Pointer to the tree node whose associated user structure we                    want to retrieve. The caller is responsible for passing a                    non-NULL argument.    @return  Pointer to user structure linked by Node. **/
end_comment

begin_function
name|VOID
modifier|*
name|EFIAPI
name|OrderedCollectionUserStruct
parameter_list|(
name|IN
name|CONST
name|RED_BLACK_TREE_NODE
modifier|*
name|Node
parameter_list|)
block|{
return|return
name|Node
operator|->
name|UserStruct
return|;
block|}
end_function

begin_comment
comment|/**   A slow function that asserts that the tree is a valid red-black tree, and   that it orders user structures correctly.    Read-only operation.    This function uses the stack for recursion and is not recommended for   "production use".    @param[in] Tree  The tree to validate. **/
end_comment

begin_function_decl
name|VOID
name|RedBlackTreeValidate
parameter_list|(
name|IN
name|CONST
name|RED_BLACK_TREE
modifier|*
name|Tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Allocate and initialize the RED_BLACK_TREE structure.    Allocation occurs via MemoryAllocationLib's AllocatePool() function.    @param[in]  UserStructCompare  This caller-provided function will be used to                                  order two user structures linked into the                                  tree, during the insertion procedure.    @param[in]  KeyCompare         This caller-provided function will be used to                                  order the standalone search key against user                                  structures linked into the tree, during the                                  lookup procedure.    @retval NULL  If allocation failed.    @return       Pointer to the allocated, initialized RED_BLACK_TREE structure,                 otherwise. **/
end_comment

begin_function
name|RED_BLACK_TREE
modifier|*
name|EFIAPI
name|OrderedCollectionInit
parameter_list|(
name|IN
name|RED_BLACK_TREE_USER_COMPARE
name|UserStructCompare
parameter_list|,
name|IN
name|RED_BLACK_TREE_KEY_COMPARE
name|KeyCompare
parameter_list|)
block|{
name|RED_BLACK_TREE
modifier|*
name|Tree
decl_stmt|;
name|Tree
operator|=
name|AllocatePool
argument_list|(
sizeof|sizeof
expr|*
name|Tree
argument_list|)
expr_stmt|;
if|if
condition|(
name|Tree
operator|==
name|NULL
condition|)
block|{
return|return
name|NULL
return|;
block|}
name|Tree
operator|->
name|Root
operator|=
name|NULL
expr_stmt|;
name|Tree
operator|->
name|UserStructCompare
operator|=
name|UserStructCompare
expr_stmt|;
name|Tree
operator|->
name|KeyCompare
operator|=
name|KeyCompare
expr_stmt|;
if|if
condition|(
name|FeaturePcdGet
argument_list|(
name|PcdValidateOrderedCollection
argument_list|)
condition|)
block|{
name|RedBlackTreeValidate
argument_list|(
name|Tree
argument_list|)
expr_stmt|;
block|}
return|return
name|Tree
return|;
block|}
end_function

begin_comment
comment|/**   Check whether the tree is empty (has no nodes).    Read-only operation.    @param[in] Tree  The tree to check for emptiness.    @retval TRUE   The tree is empty.    @retval FALSE  The tree is not empty. **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|OrderedCollectionIsEmpty
parameter_list|(
name|IN
name|CONST
name|RED_BLACK_TREE
modifier|*
name|Tree
parameter_list|)
block|{
return|return
call|(
name|BOOLEAN
call|)
argument_list|(
name|Tree
operator|->
name|Root
operator|==
name|NULL
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**   Uninitialize and release an empty RED_BLACK_TREE structure.    Read-write operation.    Release occurs via MemoryAllocationLib's FreePool() function.    It is the caller's responsibility to delete all nodes from the tree before   calling this function.    @param[in] Tree  The empty tree to uninitialize and release. **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|OrderedCollectionUninit
parameter_list|(
name|IN
name|RED_BLACK_TREE
modifier|*
name|Tree
parameter_list|)
block|{
name|ASSERT
argument_list|(
name|OrderedCollectionIsEmpty
argument_list|(
name|Tree
argument_list|)
argument_list|)
expr_stmt|;
name|FreePool
argument_list|(
name|Tree
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Look up the tree node that links the user structure that matches the   specified standalone key.    Read-only operation.    @param[in] Tree           The tree to search for StandaloneKey.    @param[in] StandaloneKey  The key to locate among the user structures linked                             into Tree. StandaloneKey will be passed to                             Tree->KeyCompare().    @retval NULL  StandaloneKey could not be found.    @return       The tree node that links to the user structure matching                 StandaloneKey, otherwise. **/
end_comment

begin_function
name|RED_BLACK_TREE_NODE
modifier|*
name|EFIAPI
name|OrderedCollectionFind
parameter_list|(
name|IN
name|CONST
name|RED_BLACK_TREE
modifier|*
name|Tree
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|StandaloneKey
parameter_list|)
block|{
name|RED_BLACK_TREE_NODE
modifier|*
name|Node
decl_stmt|;
name|Node
operator|=
name|Tree
operator|->
name|Root
expr_stmt|;
while|while
condition|(
name|Node
operator|!=
name|NULL
condition|)
block|{
name|INTN
name|Result
decl_stmt|;
name|Result
operator|=
name|Tree
operator|->
name|KeyCompare
argument_list|(
name|StandaloneKey
argument_list|,
name|Node
operator|->
name|UserStruct
argument_list|)
expr_stmt|;
if|if
condition|(
name|Result
operator|==
literal|0
condition|)
block|{
break|break;
block|}
name|Node
operator|=
operator|(
name|Result
operator|<
literal|0
operator|)
condition|?
name|Node
operator|->
name|Left
else|:
name|Node
operator|->
name|Right
expr_stmt|;
block|}
return|return
name|Node
return|;
block|}
end_function

begin_comment
comment|/**   Find the tree node of the minimum user structure stored in the tree.    Read-only operation.    @param[in] Tree  The tree to return the minimum node of. The user structure                    linked by the minimum node compares less than all other user                    structures in the tree.    @retval NULL  If Tree is empty.    @return       The tree node that links the minimum user structure, otherwise. **/
end_comment

begin_function
name|RED_BLACK_TREE_NODE
modifier|*
name|EFIAPI
name|OrderedCollectionMin
parameter_list|(
name|IN
name|CONST
name|RED_BLACK_TREE
modifier|*
name|Tree
parameter_list|)
block|{
name|RED_BLACK_TREE_NODE
modifier|*
name|Node
decl_stmt|;
name|Node
operator|=
name|Tree
operator|->
name|Root
expr_stmt|;
if|if
condition|(
name|Node
operator|==
name|NULL
condition|)
block|{
return|return
name|NULL
return|;
block|}
while|while
condition|(
name|Node
operator|->
name|Left
operator|!=
name|NULL
condition|)
block|{
name|Node
operator|=
name|Node
operator|->
name|Left
expr_stmt|;
block|}
return|return
name|Node
return|;
block|}
end_function

begin_comment
comment|/**   Find the tree node of the maximum user structure stored in the tree.    Read-only operation.    @param[in] Tree  The tree to return the maximum node of. The user structure                    linked by the maximum node compares greater than all other                    user structures in the tree.    @retval NULL  If Tree is empty.    @return       The tree node that links the maximum user structure, otherwise. **/
end_comment

begin_function
name|RED_BLACK_TREE_NODE
modifier|*
name|EFIAPI
name|OrderedCollectionMax
parameter_list|(
name|IN
name|CONST
name|RED_BLACK_TREE
modifier|*
name|Tree
parameter_list|)
block|{
name|RED_BLACK_TREE_NODE
modifier|*
name|Node
decl_stmt|;
name|Node
operator|=
name|Tree
operator|->
name|Root
expr_stmt|;
if|if
condition|(
name|Node
operator|==
name|NULL
condition|)
block|{
return|return
name|NULL
return|;
block|}
while|while
condition|(
name|Node
operator|->
name|Right
operator|!=
name|NULL
condition|)
block|{
name|Node
operator|=
name|Node
operator|->
name|Right
expr_stmt|;
block|}
return|return
name|Node
return|;
block|}
end_function

begin_comment
comment|/**   Get the tree node of the least user structure that is greater than the one   linked by Node.    Read-only operation.    @param[in] Node  The node to get the successor node of.    @retval NULL  If Node is NULL, or Node is the maximum node of its containing                 tree (ie. Node has no successor node).    @return       The tree node linking the least user structure that is greater                 than the one linked by Node, otherwise. **/
end_comment

begin_function
name|RED_BLACK_TREE_NODE
modifier|*
name|EFIAPI
name|OrderedCollectionNext
parameter_list|(
name|IN
name|CONST
name|RED_BLACK_TREE_NODE
modifier|*
name|Node
parameter_list|)
block|{
name|RED_BLACK_TREE_NODE
modifier|*
name|Walk
decl_stmt|;
name|CONST
name|RED_BLACK_TREE_NODE
modifier|*
name|Child
decl_stmt|;
if|if
condition|(
name|Node
operator|==
name|NULL
condition|)
block|{
return|return
name|NULL
return|;
block|}
comment|//
comment|// If Node has a right subtree, then the successor is the minimum node of
comment|// that subtree.
comment|//
name|Walk
operator|=
name|Node
operator|->
name|Right
expr_stmt|;
if|if
condition|(
name|Walk
operator|!=
name|NULL
condition|)
block|{
while|while
condition|(
name|Walk
operator|->
name|Left
operator|!=
name|NULL
condition|)
block|{
name|Walk
operator|=
name|Walk
operator|->
name|Left
expr_stmt|;
block|}
return|return
name|Walk
return|;
block|}
comment|//
comment|// Otherwise we have to ascend as long as we're our parent's right child (ie.
comment|// ascending to the left).
comment|//
name|Child
operator|=
name|Node
expr_stmt|;
name|Walk
operator|=
name|Child
operator|->
name|Parent
expr_stmt|;
while|while
condition|(
name|Walk
operator|!=
name|NULL
operator|&&
name|Child
operator|==
name|Walk
operator|->
name|Right
condition|)
block|{
name|Child
operator|=
name|Walk
expr_stmt|;
name|Walk
operator|=
name|Child
operator|->
name|Parent
expr_stmt|;
block|}
return|return
name|Walk
return|;
block|}
end_function

begin_comment
comment|/**   Get the tree node of the greatest user structure that is less than the one   linked by Node.    Read-only operation.    @param[in] Node  The node to get the predecessor node of.    @retval NULL  If Node is NULL, or Node is the minimum node of its containing                 tree (ie. Node has no predecessor node).    @return       The tree node linking the greatest user structure that is less                 than the one linked by Node, otherwise. **/
end_comment

begin_function
name|RED_BLACK_TREE_NODE
modifier|*
name|EFIAPI
name|OrderedCollectionPrev
parameter_list|(
name|IN
name|CONST
name|RED_BLACK_TREE_NODE
modifier|*
name|Node
parameter_list|)
block|{
name|RED_BLACK_TREE_NODE
modifier|*
name|Walk
decl_stmt|;
name|CONST
name|RED_BLACK_TREE_NODE
modifier|*
name|Child
decl_stmt|;
if|if
condition|(
name|Node
operator|==
name|NULL
condition|)
block|{
return|return
name|NULL
return|;
block|}
comment|//
comment|// If Node has a left subtree, then the predecessor is the maximum node of
comment|// that subtree.
comment|//
name|Walk
operator|=
name|Node
operator|->
name|Left
expr_stmt|;
if|if
condition|(
name|Walk
operator|!=
name|NULL
condition|)
block|{
while|while
condition|(
name|Walk
operator|->
name|Right
operator|!=
name|NULL
condition|)
block|{
name|Walk
operator|=
name|Walk
operator|->
name|Right
expr_stmt|;
block|}
return|return
name|Walk
return|;
block|}
comment|//
comment|// Otherwise we have to ascend as long as we're our parent's left child (ie.
comment|// ascending to the right).
comment|//
name|Child
operator|=
name|Node
expr_stmt|;
name|Walk
operator|=
name|Child
operator|->
name|Parent
expr_stmt|;
while|while
condition|(
name|Walk
operator|!=
name|NULL
operator|&&
name|Child
operator|==
name|Walk
operator|->
name|Left
condition|)
block|{
name|Child
operator|=
name|Walk
expr_stmt|;
name|Walk
operator|=
name|Child
operator|->
name|Parent
expr_stmt|;
block|}
return|return
name|Walk
return|;
block|}
end_function

begin_comment
comment|/**   Rotate tree nodes around Pivot to the right.                  Parent                       Parent                   |                            |                 Pivot                      LeftChild                /     .                    .         \_       LeftChild       Node1   --->   Node2           Pivot          . \                                          / .     Node2   LeftRightChild              LeftRightChild   Node1    The ordering Node2< LeftChild< LeftRightChild< Pivot< Node1 is kept   intact. Parent (if any) is either at the left extreme or the right extreme of   this ordering, and that relation is also kept intact.    Edges marked with a dot (".") don't change during rotation.    Internal read-write operation.    @param[in,out] Pivot    The tree node to rotate other nodes right around. It                           is the caller's responsibility to ensure that                           Pivot->Left is not NULL.    @param[out]    NewRoot  If Pivot has a parent node on input, then the                           function updates Pivot's original parent on output                           according to the rotation, and NewRoot is not                           accessed.                            If Pivot has no parent node on input (ie. Pivot is                           the root of the tree), then the function stores the                           new root node of the tree in NewRoot. **/
end_comment

begin_function
name|VOID
name|RedBlackTreeRotateRight
parameter_list|(
name|IN
name|OUT
name|RED_BLACK_TREE_NODE
modifier|*
name|Pivot
parameter_list|,
name|OUT
name|RED_BLACK_TREE_NODE
modifier|*
modifier|*
name|NewRoot
parameter_list|)
block|{
name|RED_BLACK_TREE_NODE
modifier|*
name|Parent
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|LeftChild
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|LeftRightChild
decl_stmt|;
name|Parent
operator|=
name|Pivot
operator|->
name|Parent
expr_stmt|;
name|LeftChild
operator|=
name|Pivot
operator|->
name|Left
expr_stmt|;
name|LeftRightChild
operator|=
name|LeftChild
operator|->
name|Right
expr_stmt|;
name|Pivot
operator|->
name|Left
operator|=
name|LeftRightChild
expr_stmt|;
if|if
condition|(
name|LeftRightChild
operator|!=
name|NULL
condition|)
block|{
name|LeftRightChild
operator|->
name|Parent
operator|=
name|Pivot
expr_stmt|;
block|}
name|LeftChild
operator|->
name|Parent
operator|=
name|Parent
expr_stmt|;
if|if
condition|(
name|Parent
operator|==
name|NULL
condition|)
block|{
operator|*
name|NewRoot
operator|=
name|LeftChild
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|Pivot
operator|==
name|Parent
operator|->
name|Left
condition|)
block|{
name|Parent
operator|->
name|Left
operator|=
name|LeftChild
expr_stmt|;
block|}
else|else
block|{
name|Parent
operator|->
name|Right
operator|=
name|LeftChild
expr_stmt|;
block|}
block|}
name|LeftChild
operator|->
name|Right
operator|=
name|Pivot
expr_stmt|;
name|Pivot
operator|->
name|Parent
operator|=
name|LeftChild
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Rotate tree nodes around Pivot to the left.            Parent                                 Parent             |                                      |           Pivot                                RightChild          .     \                              /          .     Node1       RightChild    --->       Pivot            Node2                     /.                    . \_       RightLeftChild  Node2          Node1   RightLeftChild    The ordering Node1< Pivot< RightLeftChild< RightChild< Node2 is kept   intact. Parent (if any) is either at the left extreme or the right extreme of   this ordering, and that relation is also kept intact.    Edges marked with a dot (".") don't change during rotation.    Internal read-write operation.    @param[in,out] Pivot    The tree node to rotate other nodes left around. It                           is the caller's responsibility to ensure that                           Pivot->Right is not NULL.    @param[out]    NewRoot  If Pivot has a parent node on input, then the                           function updates Pivot's original parent on output                           according to the rotation, and NewRoot is not                           accessed.                            If Pivot has no parent node on input (ie. Pivot is                           the root of the tree), then the function stores the                           new root node of the tree in NewRoot. **/
end_comment

begin_function
name|VOID
name|RedBlackTreeRotateLeft
parameter_list|(
name|IN
name|OUT
name|RED_BLACK_TREE_NODE
modifier|*
name|Pivot
parameter_list|,
name|OUT
name|RED_BLACK_TREE_NODE
modifier|*
modifier|*
name|NewRoot
parameter_list|)
block|{
name|RED_BLACK_TREE_NODE
modifier|*
name|Parent
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|RightChild
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|RightLeftChild
decl_stmt|;
name|Parent
operator|=
name|Pivot
operator|->
name|Parent
expr_stmt|;
name|RightChild
operator|=
name|Pivot
operator|->
name|Right
expr_stmt|;
name|RightLeftChild
operator|=
name|RightChild
operator|->
name|Left
expr_stmt|;
name|Pivot
operator|->
name|Right
operator|=
name|RightLeftChild
expr_stmt|;
if|if
condition|(
name|RightLeftChild
operator|!=
name|NULL
condition|)
block|{
name|RightLeftChild
operator|->
name|Parent
operator|=
name|Pivot
expr_stmt|;
block|}
name|RightChild
operator|->
name|Parent
operator|=
name|Parent
expr_stmt|;
if|if
condition|(
name|Parent
operator|==
name|NULL
condition|)
block|{
operator|*
name|NewRoot
operator|=
name|RightChild
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|Pivot
operator|==
name|Parent
operator|->
name|Left
condition|)
block|{
name|Parent
operator|->
name|Left
operator|=
name|RightChild
expr_stmt|;
block|}
else|else
block|{
name|Parent
operator|->
name|Right
operator|=
name|RightChild
expr_stmt|;
block|}
block|}
name|RightChild
operator|->
name|Left
operator|=
name|Pivot
expr_stmt|;
name|Pivot
operator|->
name|Parent
operator|=
name|RightChild
expr_stmt|;
block|}
end_function

begin_comment
comment|/**   Insert (link) a user structure into the tree.    Read-write operation.    This function allocates the new tree node with MemoryAllocationLib's   AllocatePool() function.    @param[in,out] Tree        The tree to insert UserStruct into.    @param[out]    Node        The meaning of this optional, output-only                              parameter depends on the return value of the                              function.                               When insertion is successful (RETURN_SUCCESS),                              Node is set on output to the new tree node that                              now links UserStruct.                               When insertion fails due to lack of memory                              (RETURN_OUT_OF_RESOURCES), Node is not changed.                               When insertion fails due to key collision (ie.                              another user structure is already in the tree that                              compares equal to UserStruct), with return value                              RETURN_ALREADY_STARTED, then Node is set on output                              to the node that links the colliding user                              structure. This enables "find-or-insert" in one                              function call, or helps with later removal of the                              colliding element.    @param[in]     UserStruct  The user structure to link into the tree.                              UserStruct is ordered against in-tree user                              structures with the Tree->UserStructCompare()                              function.    @retval RETURN_SUCCESS           Insertion successful. A new tree node has                                    been allocated, linking UserStruct. The new                                    tree node is reported back in Node (if the                                    caller requested it).                                     Existing RED_BLACK_TREE_NODE pointers into                                    Tree remain valid. For example, on-going                                    iterations in the caller can continue with                                    OrderedCollectionNext() /                                    OrderedCollectionPrev(), and they will                                    return the new node at some point if user                                    structure order dictates it.    @retval RETURN_OUT_OF_RESOURCES  AllocatePool() failed to allocate memory for                                    the new tree node. The tree has not been                                    changed. Existing RED_BLACK_TREE_NODE                                    pointers into Tree remain valid.    @retval RETURN_ALREADY_STARTED   A user structure has been found in the tree                                    that compares equal to UserStruct. The node                                    linking the colliding user structure is                                    reported back in Node (if the caller                                    requested it). The tree has not been                                    changed. Existing RED_BLACK_TREE_NODE                                    pointers into Tree remain valid. **/
end_comment

begin_function
name|RETURN_STATUS
name|EFIAPI
name|OrderedCollectionInsert
parameter_list|(
name|IN
name|OUT
name|RED_BLACK_TREE
modifier|*
name|Tree
parameter_list|,
name|OUT
name|RED_BLACK_TREE_NODE
modifier|*
modifier|*
name|Node
name|OPTIONAL
parameter_list|,
name|IN
name|VOID
modifier|*
name|UserStruct
parameter_list|)
block|{
name|RED_BLACK_TREE_NODE
modifier|*
name|Tmp
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|Parent
decl_stmt|;
name|INTN
name|Result
decl_stmt|;
name|RETURN_STATUS
name|Status
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|NewRoot
decl_stmt|;
name|Tmp
operator|=
name|Tree
operator|->
name|Root
expr_stmt|;
name|Parent
operator|=
name|NULL
expr_stmt|;
name|Result
operator|=
literal|0
expr_stmt|;
comment|//
comment|// First look for a collision, saving the last examined node for the case
comment|// when there's no collision.
comment|//
while|while
condition|(
name|Tmp
operator|!=
name|NULL
condition|)
block|{
name|Result
operator|=
name|Tree
operator|->
name|UserStructCompare
argument_list|(
name|UserStruct
argument_list|,
name|Tmp
operator|->
name|UserStruct
argument_list|)
expr_stmt|;
if|if
condition|(
name|Result
operator|==
literal|0
condition|)
block|{
break|break;
block|}
name|Parent
operator|=
name|Tmp
expr_stmt|;
name|Tmp
operator|=
operator|(
name|Result
operator|<
literal|0
operator|)
condition|?
name|Tmp
operator|->
name|Left
else|:
name|Tmp
operator|->
name|Right
expr_stmt|;
block|}
if|if
condition|(
name|Tmp
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|Node
operator|!=
name|NULL
condition|)
block|{
operator|*
name|Node
operator|=
name|Tmp
expr_stmt|;
block|}
name|Status
operator|=
name|RETURN_ALREADY_STARTED
expr_stmt|;
goto|goto
name|Done
goto|;
block|}
comment|//
comment|// no collision, allocate a new node
comment|//
name|Tmp
operator|=
name|AllocatePool
argument_list|(
sizeof|sizeof
expr|*
name|Tmp
argument_list|)
expr_stmt|;
if|if
condition|(
name|Tmp
operator|==
name|NULL
condition|)
block|{
name|Status
operator|=
name|RETURN_OUT_OF_RESOURCES
expr_stmt|;
goto|goto
name|Done
goto|;
block|}
if|if
condition|(
name|Node
operator|!=
name|NULL
condition|)
block|{
operator|*
name|Node
operator|=
name|Tmp
expr_stmt|;
block|}
comment|//
comment|// reference the user structure from the node
comment|//
name|Tmp
operator|->
name|UserStruct
operator|=
name|UserStruct
expr_stmt|;
comment|//
comment|// Link the node as a child to the correct side of the parent.
comment|// If there's no parent, the new node is the root node in the tree.
comment|//
name|Tmp
operator|->
name|Parent
operator|=
name|Parent
expr_stmt|;
name|Tmp
operator|->
name|Left
operator|=
name|NULL
expr_stmt|;
name|Tmp
operator|->
name|Right
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|Parent
operator|==
name|NULL
condition|)
block|{
name|Tree
operator|->
name|Root
operator|=
name|Tmp
expr_stmt|;
name|Tmp
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
name|Status
operator|=
name|RETURN_SUCCESS
expr_stmt|;
goto|goto
name|Done
goto|;
block|}
if|if
condition|(
name|Result
operator|<
literal|0
condition|)
block|{
name|Parent
operator|->
name|Left
operator|=
name|Tmp
expr_stmt|;
block|}
else|else
block|{
name|Parent
operator|->
name|Right
operator|=
name|Tmp
expr_stmt|;
block|}
name|Tmp
operator|->
name|Color
operator|=
name|RedBlackTreeRed
expr_stmt|;
comment|//
comment|// Red-black tree properties:
comment|//
comment|// #1 Each node is either red or black (RED_BLACK_TREE_NODE.Color).
comment|//
comment|// #2 Each leaf (ie. a pseudo-node pointed-to by a NULL valued
comment|//    RED_BLACK_TREE_NODE.Left or RED_BLACK_TREE_NODE.Right field) is black.
comment|//
comment|// #3 Each red node has two black children.
comment|//
comment|// #4 For any node N, and for any leaves L1 and L2 reachable from N, the
comment|//    paths N..L1 and N..L2 contain the same number of black nodes.
comment|//
comment|// #5 The root node is black.
comment|//
comment|// By replacing a leaf with a red node above, only property #3 may have been
comment|// broken. (Note that this is the only edge across which property #3 might
comment|// not hold in the entire tree.) Restore property #3.
comment|//
name|NewRoot
operator|=
name|Tree
operator|->
name|Root
expr_stmt|;
while|while
condition|(
name|Tmp
operator|!=
name|NewRoot
operator|&&
name|Parent
operator|->
name|Color
operator|==
name|RedBlackTreeRed
condition|)
block|{
name|RED_BLACK_TREE_NODE
modifier|*
name|GrandParent
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|Uncle
decl_stmt|;
comment|//
comment|// Tmp is not the root node. Tmp is red. Tmp's parent is red. (Breaking
comment|// property #3.)
comment|//
comment|// Due to property #5, Tmp's parent cannot be the root node, hence Tmp's
comment|// grandparent exists.
comment|//
comment|// Tmp's grandparent is black, because property #3 is only broken between
comment|// Tmp and Tmp's parent.
comment|//
name|GrandParent
operator|=
name|Parent
operator|->
name|Parent
expr_stmt|;
if|if
condition|(
name|Parent
operator|==
name|GrandParent
operator|->
name|Left
condition|)
block|{
name|Uncle
operator|=
name|GrandParent
operator|->
name|Right
expr_stmt|;
if|if
condition|(
name|Uncle
operator|!=
name|NULL
operator|&&
name|Uncle
operator|->
name|Color
operator|==
name|RedBlackTreeRed
condition|)
block|{
comment|//
comment|//             GrandParent (black)
comment|//            /                   \_
comment|// Parent (red)                    Uncle (red)
comment|//      |
comment|//  Tmp (red)
comment|//
name|Parent
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
name|Uncle
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
name|GrandParent
operator|->
name|Color
operator|=
name|RedBlackTreeRed
expr_stmt|;
comment|//
comment|//                GrandParent (red)
comment|//               /                 \_
comment|// Parent (black)                   Uncle (black)
comment|//       |
comment|//   Tmp (red)
comment|//
comment|// We restored property #3 between Tmp and Tmp's parent, without
comment|// breaking property #4. However, we may have broken property #3
comment|// between Tmp's grandparent and Tmp's great-grandparent (if any), so
comment|// repeat the loop for Tmp's grandparent.
comment|//
comment|// If Tmp's grandparent has no parent, then the loop will terminate,
comment|// and we will have broken property #5, by coloring the root red. We'll
comment|// restore property #5 after the loop, without breaking any others.
comment|//
name|Tmp
operator|=
name|GrandParent
expr_stmt|;
name|Parent
operator|=
name|Tmp
operator|->
name|Parent
expr_stmt|;
block|}
else|else
block|{
comment|//
comment|// Tmp's uncle is black (satisfied by the case too when Tmp's uncle is
comment|// NULL, see property #2).
comment|//
if|if
condition|(
name|Tmp
operator|==
name|Parent
operator|->
name|Right
condition|)
block|{
comment|//
comment|//                 GrandParent (black): D
comment|//                /                      \_
comment|// Parent (red): A                        Uncle (black): E
comment|//      \_
comment|//       Tmp (red): B
comment|//            \_
comment|//             black: C
comment|//
comment|// Rotate left, pivoting on node A. This keeps the breakage of
comment|// property #3 in the same spot, and keeps other properties intact
comment|// (because both Tmp and its parent are red).
comment|//
name|Tmp
operator|=
name|Parent
expr_stmt|;
name|RedBlackTreeRotateLeft
argument_list|(
name|Tmp
argument_list|,
operator|&
name|NewRoot
argument_list|)
expr_stmt|;
name|Parent
operator|=
name|Tmp
operator|->
name|Parent
expr_stmt|;
comment|//
comment|// With the rotation we reached the same configuration as if Tmp had
comment|// been a left child to begin with.
comment|//
comment|//                       GrandParent (black): D
comment|//                      /                      \_
comment|//       Parent (red): B                        Uncle (black): E
comment|//             / \_
comment|// Tmp (red): A   black: C
comment|//
name|ASSERT
argument_list|(
name|GrandParent
operator|==
name|Parent
operator|->
name|Parent
argument_list|)
expr_stmt|;
block|}
name|Parent
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
name|GrandParent
operator|->
name|Color
operator|=
name|RedBlackTreeRed
expr_stmt|;
comment|//
comment|// Property #3 is now restored, but we've broken property #4. Namely,
comment|// paths going through node E now see a decrease in black count, while
comment|// paths going through node B don't.
comment|//
comment|//                        GrandParent (red): D
comment|//                       /                    \_
comment|//      Parent (black): B                      Uncle (black): E
comment|//             / \_
comment|// Tmp (red): A   black: C
comment|//
name|RedBlackTreeRotateRight
argument_list|(
name|GrandParent
argument_list|,
operator|&
name|NewRoot
argument_list|)
expr_stmt|;
comment|//
comment|// Property #4 has been restored for node E, and preserved for others.
comment|//
comment|//              Parent (black): B
comment|//             /                 \_
comment|// Tmp (red): A                   [GrandParent] (red): D
comment|//                                         / \_
comment|//                                 black: C   [Uncle] (black): E
comment|//
comment|// This configuration terminates the loop because Tmp's parent is now
comment|// black.
comment|//
block|}
block|}
else|else
block|{
comment|//
comment|// Symmetrical to the other branch.
comment|//
name|Uncle
operator|=
name|GrandParent
operator|->
name|Left
expr_stmt|;
if|if
condition|(
name|Uncle
operator|!=
name|NULL
operator|&&
name|Uncle
operator|->
name|Color
operator|==
name|RedBlackTreeRed
condition|)
block|{
name|Parent
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
name|Uncle
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
name|GrandParent
operator|->
name|Color
operator|=
name|RedBlackTreeRed
expr_stmt|;
name|Tmp
operator|=
name|GrandParent
expr_stmt|;
name|Parent
operator|=
name|Tmp
operator|->
name|Parent
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|Tmp
operator|==
name|Parent
operator|->
name|Left
condition|)
block|{
name|Tmp
operator|=
name|Parent
expr_stmt|;
name|RedBlackTreeRotateRight
argument_list|(
name|Tmp
argument_list|,
operator|&
name|NewRoot
argument_list|)
expr_stmt|;
name|Parent
operator|=
name|Tmp
operator|->
name|Parent
expr_stmt|;
name|ASSERT
argument_list|(
name|GrandParent
operator|==
name|Parent
operator|->
name|Parent
argument_list|)
expr_stmt|;
block|}
name|Parent
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
name|GrandParent
operator|->
name|Color
operator|=
name|RedBlackTreeRed
expr_stmt|;
name|RedBlackTreeRotateLeft
argument_list|(
name|GrandParent
argument_list|,
operator|&
name|NewRoot
argument_list|)
expr_stmt|;
block|}
block|}
block|}
name|NewRoot
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
name|Tree
operator|->
name|Root
operator|=
name|NewRoot
expr_stmt|;
name|Status
operator|=
name|RETURN_SUCCESS
expr_stmt|;
name|Done
label|:
if|if
condition|(
name|FeaturePcdGet
argument_list|(
name|PcdValidateOrderedCollection
argument_list|)
condition|)
block|{
name|RedBlackTreeValidate
argument_list|(
name|Tree
argument_list|)
expr_stmt|;
block|}
return|return
name|Status
return|;
block|}
end_function

begin_comment
comment|/**   Check if a node is black, allowing for leaf nodes (see property #2).    This is a convenience shorthand.    param[in] Node  The node to check. Node may be NULL, corresponding to a leaf.    @return  If Node is NULL or colored black. **/
end_comment

begin_function
name|BOOLEAN
name|NodeIsNullOrBlack
parameter_list|(
name|IN
name|CONST
name|RED_BLACK_TREE_NODE
modifier|*
name|Node
parameter_list|)
block|{
return|return
call|(
name|BOOLEAN
call|)
argument_list|(
name|Node
operator|==
name|NULL
operator|||
name|Node
operator|->
name|Color
operator|==
name|RedBlackTreeBlack
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**   Delete a node from the tree, unlinking the associated user structure.    Read-write operation.    @param[in,out] Tree        The tree to delete Node from.    @param[in]     Node        The tree node to delete from Tree. The caller is                              responsible for ensuring that Node belongs to                              Tree, and that Node is non-NULL and valid. Node is                              typically an earlier return value, or output                              parameter, of:                               - OrderedCollectionFind(), for deleting a node by                                user structure key,                               - OrderedCollectionMin() / OrderedCollectionMax(),                                for deleting the minimum / maximum node,                               - OrderedCollectionNext() /                                OrderedCollectionPrev(), for deleting a node                                found during an iteration,                               - OrderedCollectionInsert() with return value                                RETURN_ALREADY_STARTED, for deleting a node                                whose linked user structure caused collision                                during insertion.                               Given a non-empty Tree, Tree->Root is also a valid                              Node argument (typically used for simplicity in                              loops that empty the tree completely).                               Node is released with MemoryAllocationLib's                              FreePool() function.                               Existing RED_BLACK_TREE_NODE pointers (ie.                              iterators) *different* from Node remain valid. For                              example:                               - OrderedCollectionNext() /                                OrderedCollectionPrev() iterations in the caller                                can be continued from Node, if                                OrderedCollectionNext() or                                OrderedCollectionPrev() is called on Node                                *before* OrderedCollectionDelete() is. That is,                                fetch the successor / predecessor node first,                                then delete Node.                               - On-going iterations in the caller that would                                have otherwise returned Node at some point, as                                dictated by user structure order, will correctly                                reflect the absence of Node after                                OrderedCollectionDelete() is called                                mid-iteration.    @param[out]    UserStruct  If the caller provides this optional output-only                              parameter, then on output it is set to the user                              structure originally linked by Node (which is now                              freed).                               This is a convenience that may save the caller a                              OrderedCollectionUserStruct() invocation before                              calling OrderedCollectionDelete(), in order to                              retrieve the user structure being unlinked. **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|OrderedCollectionDelete
parameter_list|(
name|IN
name|OUT
name|RED_BLACK_TREE
modifier|*
name|Tree
parameter_list|,
name|IN
name|RED_BLACK_TREE_NODE
modifier|*
name|Node
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|UserStruct
name|OPTIONAL
parameter_list|)
block|{
name|RED_BLACK_TREE_NODE
modifier|*
name|NewRoot
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|OrigLeftChild
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|OrigRightChild
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|OrigParent
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|Child
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|Parent
decl_stmt|;
name|RED_BLACK_TREE_COLOR
name|ColorOfUnlinked
decl_stmt|;
name|NewRoot
operator|=
name|Tree
operator|->
name|Root
expr_stmt|;
name|OrigLeftChild
operator|=
name|Node
operator|->
name|Left
operator|,
name|OrigRightChild
operator|=
name|Node
operator|->
name|Right
operator|,
name|OrigParent
operator|=
name|Node
operator|->
name|Parent
expr_stmt|;
if|if
condition|(
name|UserStruct
operator|!=
name|NULL
condition|)
block|{
operator|*
name|UserStruct
operator|=
name|Node
operator|->
name|UserStruct
expr_stmt|;
block|}
comment|//
comment|// After this block, no matter which branch we take:
comment|// - Child will point to the unique (or NULL) original child of the node that
comment|//   we will have unlinked,
comment|// - Parent will point to the *position* of the original parent of the node
comment|//   that we will have unlinked.
comment|//
if|if
condition|(
name|OrigLeftChild
operator|==
name|NULL
operator|||
name|OrigRightChild
operator|==
name|NULL
condition|)
block|{
comment|//
comment|// Node has at most one child. We can connect that child (if any) with
comment|// Node's parent (if any), unlinking Node. This will preserve ordering
comment|// because the subtree rooted in Node's child (if any) remains on the same
comment|// side of Node's parent (if any) that Node was before.
comment|//
name|Parent
operator|=
name|OrigParent
expr_stmt|;
name|Child
operator|=
operator|(
name|OrigLeftChild
operator|!=
name|NULL
operator|)
condition|?
name|OrigLeftChild
else|:
name|OrigRightChild
expr_stmt|;
name|ColorOfUnlinked
operator|=
name|Node
operator|->
name|Color
expr_stmt|;
if|if
condition|(
name|Child
operator|!=
name|NULL
condition|)
block|{
name|Child
operator|->
name|Parent
operator|=
name|Parent
expr_stmt|;
block|}
if|if
condition|(
name|OrigParent
operator|==
name|NULL
condition|)
block|{
name|NewRoot
operator|=
name|Child
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|Node
operator|==
name|OrigParent
operator|->
name|Left
condition|)
block|{
name|OrigParent
operator|->
name|Left
operator|=
name|Child
expr_stmt|;
block|}
else|else
block|{
name|OrigParent
operator|->
name|Right
operator|=
name|Child
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
comment|//
comment|// Node has two children. We unlink Node's successor, and then link it into
comment|// Node's place, keeping Node's original color. This preserves ordering
comment|// because:
comment|// - Node's left subtree is less than Node, hence less than Node's
comment|//   successor.
comment|// - Node's right subtree is greater than Node. Node's successor is the
comment|//   minimum of that subtree, hence Node's successor is less than Node's
comment|//   right subtree with its minimum removed.
comment|// - Node's successor is in Node's subtree, hence it falls on the same side
comment|//   of Node's parent as Node itself. The relinking doesn't change this
comment|//   relation.
comment|//
name|RED_BLACK_TREE_NODE
modifier|*
name|ToRelink
decl_stmt|;
name|ToRelink
operator|=
name|OrigRightChild
expr_stmt|;
if|if
condition|(
name|ToRelink
operator|->
name|Left
operator|==
name|NULL
condition|)
block|{
comment|//
comment|// OrigRightChild itself is Node's successor, it has no left child:
comment|//
comment|//                OrigParent
comment|//                    |
comment|//                  Node: B
comment|//                 /       \_
comment|// OrigLeftChild: A         OrigRightChild: E<--- Parent, ToRelink
comment|//                                           \_
comment|//                                            F<--- Child
comment|//
name|Parent
operator|=
name|OrigRightChild
expr_stmt|;
name|Child
operator|=
name|OrigRightChild
operator|->
name|Right
expr_stmt|;
block|}
else|else
block|{
do|do
block|{
name|ToRelink
operator|=
name|ToRelink
operator|->
name|Left
expr_stmt|;
block|}
do|while
condition|(
name|ToRelink
operator|->
name|Left
operator|!=
name|NULL
condition|)
do|;
comment|//
comment|// Node's successor is the minimum of OrigRightChild's proper subtree:
comment|//
comment|//                OrigParent
comment|//                    |
comment|//                  Node: B
comment|//                 /       \_
comment|// OrigLeftChild: A         OrigRightChild: E<--- Parent
comment|//                                  /
comment|//                                 C<--- ToRelink
comment|//                                  \_
comment|//                                   D<--- Child
name|Parent
operator|=
name|ToRelink
operator|->
name|Parent
expr_stmt|;
name|Child
operator|=
name|ToRelink
operator|->
name|Right
expr_stmt|;
comment|//
comment|// Unlink Node's successor (ie. ToRelink):
comment|//
comment|//                OrigParent
comment|//                    |
comment|//                  Node: B
comment|//                 /       \_
comment|// OrigLeftChild: A         OrigRightChild: E<--- Parent
comment|//                                  /
comment|//                                 D<--- Child
comment|//
comment|//                                 C<--- ToRelink
comment|//
name|Parent
operator|->
name|Left
operator|=
name|Child
expr_stmt|;
if|if
condition|(
name|Child
operator|!=
name|NULL
condition|)
block|{
name|Child
operator|->
name|Parent
operator|=
name|Parent
expr_stmt|;
block|}
comment|//
comment|// We start to link Node's unlinked successor into Node's place:
comment|//
comment|//                OrigParent
comment|//                    |
comment|//                  Node: B     C<--- ToRelink
comment|//                 /             \_
comment|// OrigLeftChild: A               OrigRightChild: E<--- Parent
comment|//                                        /
comment|//                                       D<--- Child
comment|//
comment|//
comment|//
name|ToRelink
operator|->
name|Right
operator|=
name|OrigRightChild
expr_stmt|;
name|OrigRightChild
operator|->
name|Parent
operator|=
name|ToRelink
expr_stmt|;
block|}
comment|//
comment|// The rest handles both cases, attaching ToRelink (Node's original
comment|// successor) to OrigLeftChild and OrigParent.
comment|//
comment|//                           Parent,
comment|//              OrigParent   ToRelink             OrigParent
comment|//                  |        |                        |
comment|//                Node: B    |                      Node: B          Parent
comment|//                           v                                          |
comment|//           OrigRightChild: E                        C<--- ToRelink   |
comment|//                 / \                               / \                v
comment|// OrigLeftChild: A   F              OrigLeftChild: A   OrigRightChild: E
comment|//                    ^                                         /
comment|//                    |                                        D<--- Child
comment|//                  Child
comment|//
name|ToRelink
operator|->
name|Left
operator|=
name|OrigLeftChild
expr_stmt|;
name|OrigLeftChild
operator|->
name|Parent
operator|=
name|ToRelink
expr_stmt|;
comment|//
comment|// Node's color must be preserved in Node's original place.
comment|//
name|ColorOfUnlinked
operator|=
name|ToRelink
operator|->
name|Color
expr_stmt|;
name|ToRelink
operator|->
name|Color
operator|=
name|Node
operator|->
name|Color
expr_stmt|;
comment|//
comment|// Finish linking Node's unlinked successor into Node's place.
comment|//
comment|//                           Parent,
comment|//                Node: B    ToRelink               Node: B
comment|//                           |
comment|//              OrigParent   |                    OrigParent         Parent
comment|//                  |        v                        |                 |
comment|//           OrigRightChild: E                        C<--- ToRelink   |
comment|//                 / \                               / \                v
comment|// OrigLeftChild: A   F              OrigLeftChild: A   OrigRightChild: E
comment|//                    ^                                         /
comment|//                    |                                        D<--- Child
comment|//                  Child
comment|//
name|ToRelink
operator|->
name|Parent
operator|=
name|OrigParent
expr_stmt|;
if|if
condition|(
name|OrigParent
operator|==
name|NULL
condition|)
block|{
name|NewRoot
operator|=
name|ToRelink
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|Node
operator|==
name|OrigParent
operator|->
name|Left
condition|)
block|{
name|OrigParent
operator|->
name|Left
operator|=
name|ToRelink
expr_stmt|;
block|}
else|else
block|{
name|OrigParent
operator|->
name|Right
operator|=
name|ToRelink
expr_stmt|;
block|}
block|}
block|}
name|FreePool
argument_list|(
name|Node
argument_list|)
expr_stmt|;
comment|//
comment|// If the node that we unlinked from its original spot (ie. Node itself, or
comment|// Node's successor), was red, then we broke neither property #3 nor property
comment|// #4: we didn't create any red-red edge between Child and Parent, and we
comment|// didn't change the black count on any path.
comment|//
if|if
condition|(
name|ColorOfUnlinked
operator|==
name|RedBlackTreeBlack
condition|)
block|{
comment|//
comment|// However, if the unlinked node was black, then we have to transfer its
comment|// "black-increment" to its unique child (pointed-to by Child), lest we
comment|// break property #4 for its ancestors.
comment|//
comment|// If Child is red, we can simply color it black. If Child is black
comment|// already, we can't technically transfer a black-increment to it, due to
comment|// property #1.
comment|//
comment|// In the following loop we ascend searching for a red node to color black,
comment|// or until we reach the root (in which case we can drop the
comment|// black-increment). Inside the loop body, Child has a black value of 2,
comment|// transitorily breaking property #1 locally, but maintaining property #4
comment|// globally.
comment|//
comment|// Rotations in the loop preserve property #4.
comment|//
while|while
condition|(
name|Child
operator|!=
name|NewRoot
operator|&&
name|NodeIsNullOrBlack
argument_list|(
name|Child
argument_list|)
condition|)
block|{
name|RED_BLACK_TREE_NODE
modifier|*
name|Sibling
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|LeftNephew
decl_stmt|;
name|RED_BLACK_TREE_NODE
modifier|*
name|RightNephew
decl_stmt|;
if|if
condition|(
name|Child
operator|==
name|Parent
operator|->
name|Left
condition|)
block|{
name|Sibling
operator|=
name|Parent
operator|->
name|Right
expr_stmt|;
comment|//
comment|// Sibling can never be NULL (ie. a leaf).
comment|//
comment|// If Sibling was NULL, then the black count on the path from Parent to
comment|// Sibling would equal Parent's black value, plus 1 (due to property
comment|// #2). Whereas the black count on the path from Parent to any leaf via
comment|// Child would be at least Parent's black value, plus 2 (due to Child's
comment|// black value of 2). This would clash with property #4.
comment|//
comment|// (Sibling can be black of course, but it has to be an internal node.
comment|// Internality allows Sibling to have children, bumping the black
comment|// counts of paths that go through it.)
comment|//
name|ASSERT
argument_list|(
name|Sibling
operator|!=
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|Sibling
operator|->
name|Color
operator|==
name|RedBlackTreeRed
condition|)
block|{
comment|//
comment|// Sibling's red color implies its children (if any), node C and node
comment|// E, are black (property #3). It also implies that Parent is black.
comment|//
comment|//           grandparent                                 grandparent
comment|//                |                                           |
comment|//            Parent,b:B                                     b:D
comment|//           /          \                                   /   \_
comment|// Child,2b:A            Sibling,r:D  --->        Parent,r:B     b:E
comment|//                           /\                       /\_
comment|//                        b:C  b:E          Child,2b:A  Sibling,b:C
comment|//
name|Sibling
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
name|Parent
operator|->
name|Color
operator|=
name|RedBlackTreeRed
expr_stmt|;
name|RedBlackTreeRotateLeft
argument_list|(
name|Parent
argument_list|,
operator|&
name|NewRoot
argument_list|)
expr_stmt|;
name|Sibling
operator|=
name|Parent
operator|->
name|Right
expr_stmt|;
comment|//
comment|// Same reasoning as above.
comment|//
name|ASSERT
argument_list|(
name|Sibling
operator|!=
name|NULL
argument_list|)
expr_stmt|;
block|}
comment|//
comment|// Sibling is black, and not NULL. (Ie. Sibling is a black internal
comment|// node.)
comment|//
name|ASSERT
argument_list|(
name|Sibling
operator|->
name|Color
operator|==
name|RedBlackTreeBlack
argument_list|)
expr_stmt|;
name|LeftNephew
operator|=
name|Sibling
operator|->
name|Left
expr_stmt|;
name|RightNephew
operator|=
name|Sibling
operator|->
name|Right
expr_stmt|;
if|if
condition|(
name|NodeIsNullOrBlack
argument_list|(
name|LeftNephew
argument_list|)
operator|&&
name|NodeIsNullOrBlack
argument_list|(
name|RightNephew
argument_list|)
condition|)
block|{
comment|//
comment|// In this case we can "steal" one black value from Child and Sibling
comment|// each, and pass it to Parent. "Stealing" means that Sibling (black
comment|// value 1) becomes red, Child (black value 2) becomes singly-black,
comment|// and Parent will have to be examined if it can eat the
comment|// black-increment.
comment|//
comment|// Sibling is allowed to become red because both of its children are
comment|// black (property #3).
comment|//
comment|//           grandparent                             Parent
comment|//                |                                     |
comment|//            Parent,x:B                            Child,x:B
comment|//           /          \                          /         \_
comment|// Child,2b:A            Sibling,b:D    --->    b:A           r:D
comment|//                           /\                                /\_
comment|//             LeftNephew,b:C  RightNephew,b:E              b:C  b:E
comment|//
name|Sibling
operator|->
name|Color
operator|=
name|RedBlackTreeRed
expr_stmt|;
name|Child
operator|=
name|Parent
expr_stmt|;
name|Parent
operator|=
name|Parent
operator|->
name|Parent
expr_stmt|;
comment|//
comment|// Continue ascending.
comment|//
block|}
else|else
block|{
comment|//
comment|// At least one nephew is red.
comment|//
if|if
condition|(
name|NodeIsNullOrBlack
argument_list|(
name|RightNephew
argument_list|)
condition|)
block|{
comment|//
comment|// Since the right nephew is black, the left nephew is red. Due to
comment|// property #3, LeftNephew has two black children, hence node E is
comment|// black.
comment|//
comment|// Together with the rotation, this enables us to color node F red
comment|// (because property #3 will be satisfied). We flip node D to black
comment|// to maintain property #4.
comment|//
comment|//      grandparent                         grandparent
comment|//           |                                   |
comment|//       Parent,x:B                          Parent,x:B
comment|//           /\                                  /\_
comment|// Child,2b:A  Sibling,b:F     --->    Child,2b:A  Sibling,b:D
comment|//                  /\                            /   \_
comment|//    LeftNephew,r:D  RightNephew,b:G          b:C  RightNephew,r:F
comment|//               /\                                       /\_
comment|//            b:C  b:E                                 b:E  b:G
comment|//
name|LeftNephew
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
name|Sibling
operator|->
name|Color
operator|=
name|RedBlackTreeRed
expr_stmt|;
name|RedBlackTreeRotateRight
argument_list|(
name|Sibling
argument_list|,
operator|&
name|NewRoot
argument_list|)
expr_stmt|;
name|Sibling
operator|=
name|Parent
operator|->
name|Right
expr_stmt|;
name|RightNephew
operator|=
name|Sibling
operator|->
name|Right
expr_stmt|;
comment|//
comment|// These operations ensure that...
comment|//
block|}
comment|//
comment|// ... RightNephew is definitely red here, plus Sibling is (still)
comment|// black and non-NULL.
comment|//
name|ASSERT
argument_list|(
name|RightNephew
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|RightNephew
operator|->
name|Color
operator|==
name|RedBlackTreeRed
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|Sibling
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|Sibling
operator|->
name|Color
operator|==
name|RedBlackTreeBlack
argument_list|)
expr_stmt|;
comment|//
comment|// In this case we can flush the extra black-increment immediately,
comment|// restoring property #1 for Child (node A): we color RightNephew
comment|// (node E) from red to black.
comment|//
comment|// In order to maintain property #4, we exchange colors between
comment|// Parent and Sibling (nodes B and D), and rotate left around Parent
comment|// (node B). The transformation doesn't change the black count
comment|// increase incurred by each partial path, eg.
comment|// - ascending from node A: 2 + x     == 1 + 1 + x
comment|// - ascending from node C: y + 1 + x == y + 1 + x
comment|// - ascending from node E: 0 + 1 + x == 1 + x
comment|//
comment|// The color exchange is valid, because even if x stands for red,
comment|// both children of node D are black after the transformation
comment|// (preserving property #3).
comment|//
comment|//           grandparent                                  grandparent
comment|//                |                                            |
comment|//            Parent,x:B                                      x:D
comment|//           /          \                                    /   \_
comment|// Child,2b:A            Sibling,b:D              --->    b:B     b:E
comment|//                         /     \                       /   \_
comment|//                      y:C       RightNephew,r:E     b:A     y:C
comment|//
comment|//
name|Sibling
operator|->
name|Color
operator|=
name|Parent
operator|->
name|Color
expr_stmt|;
name|Parent
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
name|RightNephew
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
name|RedBlackTreeRotateLeft
argument_list|(
name|Parent
argument_list|,
operator|&
name|NewRoot
argument_list|)
expr_stmt|;
name|Child
operator|=
name|NewRoot
expr_stmt|;
comment|//
comment|// This terminates the loop.
comment|//
block|}
block|}
else|else
block|{
comment|//
comment|// Mirrors the other branch.
comment|//
name|Sibling
operator|=
name|Parent
operator|->
name|Left
expr_stmt|;
name|ASSERT
argument_list|(
name|Sibling
operator|!=
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|Sibling
operator|->
name|Color
operator|==
name|RedBlackTreeRed
condition|)
block|{
name|Sibling
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
name|Parent
operator|->
name|Color
operator|=
name|RedBlackTreeRed
expr_stmt|;
name|RedBlackTreeRotateRight
argument_list|(
name|Parent
argument_list|,
operator|&
name|NewRoot
argument_list|)
expr_stmt|;
name|Sibling
operator|=
name|Parent
operator|->
name|Left
expr_stmt|;
name|ASSERT
argument_list|(
name|Sibling
operator|!=
name|NULL
argument_list|)
expr_stmt|;
block|}
name|ASSERT
argument_list|(
name|Sibling
operator|->
name|Color
operator|==
name|RedBlackTreeBlack
argument_list|)
expr_stmt|;
name|RightNephew
operator|=
name|Sibling
operator|->
name|Right
expr_stmt|;
name|LeftNephew
operator|=
name|Sibling
operator|->
name|Left
expr_stmt|;
if|if
condition|(
name|NodeIsNullOrBlack
argument_list|(
name|RightNephew
argument_list|)
operator|&&
name|NodeIsNullOrBlack
argument_list|(
name|LeftNephew
argument_list|)
condition|)
block|{
name|Sibling
operator|->
name|Color
operator|=
name|RedBlackTreeRed
expr_stmt|;
name|Child
operator|=
name|Parent
expr_stmt|;
name|Parent
operator|=
name|Parent
operator|->
name|Parent
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|NodeIsNullOrBlack
argument_list|(
name|LeftNephew
argument_list|)
condition|)
block|{
name|RightNephew
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
name|Sibling
operator|->
name|Color
operator|=
name|RedBlackTreeRed
expr_stmt|;
name|RedBlackTreeRotateLeft
argument_list|(
name|Sibling
argument_list|,
operator|&
name|NewRoot
argument_list|)
expr_stmt|;
name|Sibling
operator|=
name|Parent
operator|->
name|Left
expr_stmt|;
name|LeftNephew
operator|=
name|Sibling
operator|->
name|Left
expr_stmt|;
block|}
name|ASSERT
argument_list|(
name|LeftNephew
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|LeftNephew
operator|->
name|Color
operator|==
name|RedBlackTreeRed
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|Sibling
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|Sibling
operator|->
name|Color
operator|==
name|RedBlackTreeBlack
argument_list|)
expr_stmt|;
name|Sibling
operator|->
name|Color
operator|=
name|Parent
operator|->
name|Color
expr_stmt|;
name|Parent
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
name|LeftNephew
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
name|RedBlackTreeRotateRight
argument_list|(
name|Parent
argument_list|,
operator|&
name|NewRoot
argument_list|)
expr_stmt|;
name|Child
operator|=
name|NewRoot
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
name|Child
operator|!=
name|NULL
condition|)
block|{
name|Child
operator|->
name|Color
operator|=
name|RedBlackTreeBlack
expr_stmt|;
block|}
block|}
name|Tree
operator|->
name|Root
operator|=
name|NewRoot
expr_stmt|;
if|if
condition|(
name|FeaturePcdGet
argument_list|(
name|PcdValidateOrderedCollection
argument_list|)
condition|)
block|{
name|RedBlackTreeValidate
argument_list|(
name|Tree
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/**   Recursively check the red-black tree properties #1 to #4 on a node.    @param[in] Node  The root of the subtree to validate.    @retval  The black-height of Node's parent. **/
end_comment

begin_function
name|UINT32
name|RedBlackTreeRecursiveCheck
parameter_list|(
name|IN
name|CONST
name|RED_BLACK_TREE_NODE
modifier|*
name|Node
parameter_list|)
block|{
name|UINT32
name|LeftHeight
decl_stmt|;
name|UINT32
name|RightHeight
decl_stmt|;
comment|//
comment|// property #2
comment|//
if|if
condition|(
name|Node
operator|==
name|NULL
condition|)
block|{
return|return
literal|1
return|;
block|}
comment|//
comment|// property #1
comment|//
name|ASSERT
argument_list|(
name|Node
operator|->
name|Color
operator|==
name|RedBlackTreeRed
operator|||
name|Node
operator|->
name|Color
operator|==
name|RedBlackTreeBlack
argument_list|)
expr_stmt|;
comment|//
comment|// property #3
comment|//
if|if
condition|(
name|Node
operator|->
name|Color
operator|==
name|RedBlackTreeRed
condition|)
block|{
name|ASSERT
argument_list|(
name|NodeIsNullOrBlack
argument_list|(
name|Node
operator|->
name|Left
argument_list|)
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|NodeIsNullOrBlack
argument_list|(
name|Node
operator|->
name|Right
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//
comment|// property #4
comment|//
name|LeftHeight
operator|=
name|RedBlackTreeRecursiveCheck
argument_list|(
name|Node
operator|->
name|Left
argument_list|)
expr_stmt|;
name|RightHeight
operator|=
name|RedBlackTreeRecursiveCheck
argument_list|(
name|Node
operator|->
name|Right
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|LeftHeight
operator|==
name|RightHeight
argument_list|)
expr_stmt|;
return|return
operator|(
name|Node
operator|->
name|Color
operator|==
name|RedBlackTreeBlack
operator|)
operator|+
name|LeftHeight
return|;
block|}
end_function

begin_comment
comment|/**   A slow function that asserts that the tree is a valid red-black tree, and   that it orders user structures correctly.    Read-only operation.    This function uses the stack for recursion and is not recommended for   "production use".    @param[in] Tree  The tree to validate. **/
end_comment

begin_function
name|VOID
name|RedBlackTreeValidate
parameter_list|(
name|IN
name|CONST
name|RED_BLACK_TREE
modifier|*
name|Tree
parameter_list|)
block|{
name|UINT32
name|BlackHeight
decl_stmt|;
name|UINT32
name|ForwardCount
decl_stmt|;
name|UINT32
name|BackwardCount
decl_stmt|;
name|CONST
name|RED_BLACK_TREE_NODE
modifier|*
name|Last
decl_stmt|;
name|CONST
name|RED_BLACK_TREE_NODE
modifier|*
name|Node
decl_stmt|;
name|DEBUG
argument_list|(
operator|(
name|DEBUG_VERBOSE
operator|,
literal|"%a: Tree=%p\n"
operator|,
name|__FUNCTION__
operator|,
name|Tree
operator|)
argument_list|)
expr_stmt|;
comment|//
comment|// property #5
comment|//
name|ASSERT
argument_list|(
name|NodeIsNullOrBlack
argument_list|(
name|Tree
operator|->
name|Root
argument_list|)
argument_list|)
expr_stmt|;
comment|//
comment|// check the other properties
comment|//
name|BlackHeight
operator|=
name|RedBlackTreeRecursiveCheck
argument_list|(
name|Tree
operator|->
name|Root
argument_list|)
operator|-
literal|1
expr_stmt|;
comment|//
comment|// forward ordering
comment|//
name|Last
operator|=
name|OrderedCollectionMin
argument_list|(
name|Tree
argument_list|)
expr_stmt|;
name|ForwardCount
operator|=
operator|(
name|Last
operator|!=
name|NULL
operator|)
expr_stmt|;
for|for
control|(
name|Node
operator|=
name|OrderedCollectionNext
argument_list|(
name|Last
argument_list|)
init|;
name|Node
operator|!=
name|NULL
condition|;
name|Node
operator|=
name|OrderedCollectionNext
argument_list|(
name|Last
argument_list|)
control|)
block|{
name|ASSERT
argument_list|(
name|Tree
operator|->
name|UserStructCompare
argument_list|(
name|Last
operator|->
name|UserStruct
argument_list|,
name|Node
operator|->
name|UserStruct
argument_list|)
operator|<
literal|0
argument_list|)
expr_stmt|;
name|Last
operator|=
name|Node
expr_stmt|;
operator|++
name|ForwardCount
expr_stmt|;
block|}
comment|//
comment|// backward ordering
comment|//
name|Last
operator|=
name|OrderedCollectionMax
argument_list|(
name|Tree
argument_list|)
expr_stmt|;
name|BackwardCount
operator|=
operator|(
name|Last
operator|!=
name|NULL
operator|)
expr_stmt|;
for|for
control|(
name|Node
operator|=
name|OrderedCollectionPrev
argument_list|(
name|Last
argument_list|)
init|;
name|Node
operator|!=
name|NULL
condition|;
name|Node
operator|=
name|OrderedCollectionPrev
argument_list|(
name|Last
argument_list|)
control|)
block|{
name|ASSERT
argument_list|(
name|Tree
operator|->
name|UserStructCompare
argument_list|(
name|Last
operator|->
name|UserStruct
argument_list|,
name|Node
operator|->
name|UserStruct
argument_list|)
operator|>
literal|0
argument_list|)
expr_stmt|;
name|Last
operator|=
name|Node
expr_stmt|;
operator|++
name|BackwardCount
expr_stmt|;
block|}
name|ASSERT
argument_list|(
name|ForwardCount
operator|==
name|BackwardCount
argument_list|)
expr_stmt|;
name|DEBUG
argument_list|(
operator|(
name|DEBUG_VERBOSE
operator|,
literal|"%a: Tree=%p BlackHeight=%Ld Count=%Ld\n"
operator|,
name|__FUNCTION__
operator|,
name|Tree
operator|,
operator|(
name|INT64
operator|)
name|BlackHeight
operator|,
operator|(
name|INT64
operator|)
name|ForwardCount
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

