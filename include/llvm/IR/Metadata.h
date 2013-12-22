begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Metadata.h - Metadata definitions ------------------*- C++ -*-===//
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
comment|/// @file
end_comment

begin_comment
comment|/// This file contains the declarations for metadata subclasses.
end_comment

begin_comment
comment|/// They represent the different flavors of metadata that live in LLVM.
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
name|LLVM_IR_METADATA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_METADATA_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|template
operator|<
name|typename
name|ValueSubClass
operator|,
name|typename
name|ItemParentClass
operator|>
name|class
name|SymbolTableListTraits
expr_stmt|;
name|enum
name|LLVMConstants
name|LLVM_ENUM_INT_TYPE
parameter_list|(
name|uint32_t
parameter_list|)
block|{
name|DEBUG_METADATA_VERSION
operator|=
literal|1
comment|// Current debug info version number.
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// MDString - a single uniqued string.
comment|/// These are used to efficiently contain a byte sequence for metadata.
comment|/// MDString is always unnamed.
name|class
name|MDString
range|:
name|public
name|Value
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|MDString
argument_list|(
argument|const MDString&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|explicit
name|MDString
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|)
block|;
name|public
operator|:
specifier|static
name|MDString
operator|*
name|get
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|StringRef Str
argument_list|)
block|;
specifier|static
name|MDString
operator|*
name|get
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|const char *Str
argument_list|)
block|{
return|return
name|get
argument_list|(
name|Context
argument_list|,
name|Str
operator|?
name|StringRef
argument_list|(
name|Str
argument_list|)
operator|:
name|StringRef
argument_list|()
argument_list|)
return|;
block|}
name|StringRef
name|getString
argument_list|()
specifier|const
block|{
return|return
name|getName
argument_list|()
return|;
block|}
name|unsigned
name|getLength
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|getName
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
typedef|typedef
name|StringRef
operator|::
name|iterator
name|iterator
expr_stmt|;
comment|/// begin() - Pointer to the first byte of the string.
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|getName
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// end() - Pointer to one byte past the end of the string.
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|getName
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|MDStringVal
return|;
block|}
block|}
empty_stmt|;
name|class
name|MDNodeOperand
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// MDNode - a tuple of other values.
name|class
name|MDNode
range|:
name|public
name|Value
decl_stmt|,
name|public
name|FoldingSetNode
block|{
name|MDNode
argument_list|(
argument|const MDNode&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|MDNode
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|friend
name|class
name|MDNodeOperand
decl_stmt|;
name|friend
name|class
name|LLVMContextImpl
decl_stmt|;
name|friend
block|struct
name|FoldingSetTrait
operator|<
name|MDNode
operator|>
expr_stmt|;
comment|/// Hash - If the MDNode is uniqued cache the hash to speed up lookup.
name|unsigned
name|Hash
decl_stmt|;
comment|/// NumOperands - This many 'MDNodeOperand' items are co-allocated onto the
comment|/// end of this MDNode.
name|unsigned
name|NumOperands
decl_stmt|;
comment|// Subclass data enums.
enum|enum
block|{
comment|/// FunctionLocalBit - This bit is set if this MDNode is function local.
comment|/// This is true when it (potentially transitively) contains a reference to
comment|/// something in a function, like an argument, basicblock, or instruction.
name|FunctionLocalBit
init|=
literal|1
operator|<<
literal|0
block|,
comment|/// NotUniquedBit - This is set on MDNodes that are not uniqued because they
comment|/// have a null operand.
name|NotUniquedBit
init|=
literal|1
operator|<<
literal|1
block|,
comment|/// DestroyFlag - This bit is set by destroy() so the destructor can assert
comment|/// that the node isn't being destroyed with a plain 'delete'.
name|DestroyFlag
init|=
literal|1
operator|<<
literal|2
block|}
enum|;
comment|// FunctionLocal enums.
enum|enum
name|FunctionLocalness
block|{
name|FL_Unknown
init|=
operator|-
literal|1
block|,
name|FL_No
init|=
literal|0
block|,
name|FL_Yes
init|=
literal|1
block|}
enum|;
comment|/// replaceOperand - Replace each instance of F from the operand list of this
comment|/// node with T.
name|void
name|replaceOperand
parameter_list|(
name|MDNodeOperand
modifier|*
name|Op
parameter_list|,
name|Value
modifier|*
name|NewVal
parameter_list|)
function_decl|;
operator|~
name|MDNode
argument_list|()
expr_stmt|;
name|MDNode
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|ArrayRef<Value*> Vals
argument_list|,
argument|bool isFunctionLocal
argument_list|)
empty_stmt|;
specifier|static
name|MDNode
modifier|*
name|getMDNode
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Vals
argument_list|,
name|FunctionLocalness
name|FL
argument_list|,
name|bool
name|Insert
operator|=
name|true
argument_list|)
decl_stmt|;
name|public
label|:
comment|// Constructors and destructors.
specifier|static
name|MDNode
modifier|*
name|get
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Vals
argument_list|)
decl_stmt|;
comment|// getWhenValsUnresolved - Construct MDNode determining function-localness
comment|// from isFunctionLocal argument, not by analyzing Vals.
specifier|static
name|MDNode
modifier|*
name|getWhenValsUnresolved
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Vals
argument_list|,
name|bool
name|isFunctionLocal
argument_list|)
decl_stmt|;
specifier|static
name|MDNode
modifier|*
name|getIfExists
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Vals
argument_list|)
decl_stmt|;
comment|/// getTemporary - Return a temporary MDNode, for use in constructing
comment|/// cyclic MDNode structures. A temporary MDNode is not uniqued,
comment|/// may be RAUW'd, and must be manually deleted with deleteTemporary.
specifier|static
name|MDNode
modifier|*
name|getTemporary
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Vals
argument_list|)
decl_stmt|;
comment|/// deleteTemporary - Deallocate a node created by getTemporary. The
comment|/// node must not have any users.
specifier|static
name|void
name|deleteTemporary
parameter_list|(
name|MDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// replaceOperandWith - Replace a specific operand.
name|void
name|replaceOperandWith
parameter_list|(
name|unsigned
name|i
parameter_list|,
name|Value
modifier|*
name|NewVal
parameter_list|)
function_decl|;
comment|/// getOperand - Return specified operand.
name|Value
modifier|*
name|getOperand
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
name|LLVM_READONLY
decl_stmt|;
comment|/// getNumOperands - Return number of MDNode operands.
name|unsigned
name|getNumOperands
argument_list|()
specifier|const
block|{
return|return
name|NumOperands
return|;
block|}
comment|/// isFunctionLocal - Return whether MDNode is local to a function.
name|bool
name|isFunctionLocal
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getSubclassDataFromValue
argument_list|()
operator|&
name|FunctionLocalBit
operator|)
operator|!=
literal|0
return|;
block|}
comment|// getFunction - If this metadata is function-local and recursively has a
comment|// function-local operand, return the first such operand's parent function.
comment|// Otherwise, return null. getFunction() should not be used for performance-
comment|// critical code because it recursively visits all the MDNode's operands.
specifier|const
name|Function
operator|*
name|getFunction
argument_list|()
specifier|const
expr_stmt|;
comment|/// Profile - calculate a unique identifier for this MDNode to collapse
comment|/// duplicates
name|void
name|Profile
argument_list|(
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
decl|const
decl_stmt|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
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
name|MDNodeVal
return|;
block|}
comment|/// Check whether MDNode is a vtable access.
name|bool
name|isTBAAVtableAccess
argument_list|()
specifier|const
expr_stmt|;
comment|/// Methods for metadata merging.
specifier|static
name|MDNode
modifier|*
name|getMostGenericTBAA
parameter_list|(
name|MDNode
modifier|*
name|A
parameter_list|,
name|MDNode
modifier|*
name|B
parameter_list|)
function_decl|;
specifier|static
name|MDNode
modifier|*
name|getMostGenericFPMath
parameter_list|(
name|MDNode
modifier|*
name|A
parameter_list|,
name|MDNode
modifier|*
name|B
parameter_list|)
function_decl|;
specifier|static
name|MDNode
modifier|*
name|getMostGenericRange
parameter_list|(
name|MDNode
modifier|*
name|A
parameter_list|,
name|MDNode
modifier|*
name|B
parameter_list|)
function_decl|;
name|private
label|:
comment|// destroy - Delete this node.  Only when there are no uses.
name|void
name|destroy
parameter_list|()
function_decl|;
name|bool
name|isNotUniqued
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getSubclassDataFromValue
argument_list|()
operator|&
name|NotUniquedBit
operator|)
operator|!=
literal|0
return|;
block|}
name|void
name|setIsNotUniqued
parameter_list|()
function_decl|;
comment|// Shadow Value::setValueSubclassData with a private forwarding method so that
comment|// any future subclasses cannot accidentally use it.
name|void
name|setValueSubclassData
parameter_list|(
name|unsigned
name|short
name|D
parameter_list|)
block|{
name|Value
operator|::
name|setValueSubclassData
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// NamedMDNode - a tuple of MDNodes. Despite its name, a NamedMDNode isn't
comment|/// itself an MDNode. NamedMDNodes belong to modules, have names, and contain
comment|/// lists of MDNodes.
name|class
name|NamedMDNode
range|:
name|public
name|ilist_node
operator|<
name|NamedMDNode
operator|>
block|{
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|NamedMDNode
block|,
name|Module
operator|>
block|;
name|friend
expr|struct
name|ilist_traits
operator|<
name|NamedMDNode
operator|>
block|;
name|friend
name|class
name|LLVMContextImpl
block|;
name|friend
name|class
name|Module
block|;
name|NamedMDNode
argument_list|(
argument|const NamedMDNode&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|std
operator|::
name|string
name|Name
block|;
name|Module
operator|*
name|Parent
block|;
name|void
operator|*
name|Operands
block|;
comment|// SmallVector<TrackingVH<MDNode>, 4>
name|void
name|setParent
argument_list|(
argument|Module *M
argument_list|)
block|{
name|Parent
operator|=
name|M
block|; }
name|explicit
name|NamedMDNode
argument_list|(
specifier|const
name|Twine
operator|&
name|N
argument_list|)
block|;
name|public
operator|:
comment|/// eraseFromParent - Drop all references and remove the node from parent
comment|/// module.
name|void
name|eraseFromParent
argument_list|()
block|;
comment|/// dropAllReferences - Remove all uses and clear node vector.
name|void
name|dropAllReferences
argument_list|()
block|;
comment|/// ~NamedMDNode - Destroy NamedMDNode.
operator|~
name|NamedMDNode
argument_list|()
block|;
comment|/// getParent - Get the module that holds this named metadata collection.
specifier|inline
name|Module
operator|*
name|getParent
argument_list|()
block|{
return|return
name|Parent
return|;
block|}
specifier|inline
specifier|const
name|Module
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|Parent
return|;
block|}
comment|/// getOperand - Return specified operand.
name|MDNode
operator|*
name|getOperand
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|;
comment|/// getNumOperands - Return the number of NamedMDNode operands.
name|unsigned
name|getNumOperands
argument_list|()
specifier|const
block|;
comment|/// addOperand - Add metadata operand.
name|void
name|addOperand
argument_list|(
name|MDNode
operator|*
name|M
argument_list|)
block|;
comment|/// getName - Return a constant reference to this named metadata's name.
name|StringRef
name|getName
argument_list|()
specifier|const
block|;
comment|/// print - Implement operator<< on NamedMDNode.
name|void
name|print
argument_list|(
argument|raw_ostream&ROS
argument_list|,
argument|AssemblyAnnotationWriter *AAW =
literal|0
argument_list|)
specifier|const
block|;
comment|/// dump() - Allow printing of NamedMDNodes from the debugger.
name|void
name|dump
argument_list|()
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

