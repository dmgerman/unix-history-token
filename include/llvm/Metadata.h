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
name|LLVM_METADATA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_METADATA_H
end_define

begin_include
include|#
directive|include
file|"llvm/Value.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Constant
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
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
comment|//===----------------------------------------------------------------------===//
comment|/// MDString - a single uniqued string.
comment|/// These are used to efficiently contain a byte sequence for metadata.
comment|/// MDString is always unnamd.
name|class
name|MDString
range|:
name|public
name|Value
block|{
name|MDString
argument_list|(
specifier|const
name|MDString
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|StringRef
name|Str
block|;
name|protected
operator|:
name|explicit
name|MDString
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|StringRef S
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
name|LLVMContext
operator|&
name|Context
argument_list|,
specifier|const
name|char
operator|*
name|Str
argument_list|)
block|;
name|StringRef
name|getString
argument_list|()
specifier|const
block|{
return|return
name|Str
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
name|Str
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
comment|///
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Str
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// end() - Pointer to one byte past the end of the string.
comment|///
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Str
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const MDString *
argument_list|)
block|{
return|return
name|true
return|;
block|}
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
specifier|const
name|MDNode
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|MDNode
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|friend
name|class
name|MDNodeOperand
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
comment|/// have a null perand.
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
comment|// Replace each instance of F from the operand list of this node with T.
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
name|protected
label|:
name|explicit
name|MDNode
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|Value
modifier|*
specifier|const
modifier|*
name|Vals
parameter_list|,
name|unsigned
name|NumVals
parameter_list|,
name|bool
name|isFunctionLocal
parameter_list|)
function_decl|;
specifier|static
name|MDNode
modifier|*
name|getMDNode
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|Value
modifier|*
specifier|const
modifier|*
name|Vals
parameter_list|,
name|unsigned
name|NumVals
parameter_list|,
name|FunctionLocalness
name|FL
parameter_list|)
function_decl|;
name|public
label|:
comment|// Constructors and destructors.
specifier|static
name|MDNode
modifier|*
name|get
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|Value
modifier|*
specifier|const
modifier|*
name|Vals
parameter_list|,
name|unsigned
name|NumVals
parameter_list|)
function_decl|;
comment|// getWhenValsUnresolved - Construct MDNode determining function-localness
comment|// from isFunctionLocal argument, not by analyzing Vals.
specifier|static
name|MDNode
modifier|*
name|getWhenValsUnresolved
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|Value
modifier|*
specifier|const
modifier|*
name|Vals
parameter_list|,
name|unsigned
name|NumVals
parameter_list|,
name|bool
name|isFunctionLocal
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
comment|/// Note: MDNodes are designated as function-local when created, and keep
comment|///       that designation even if their operands are modified to no longer
comment|///       refer to function-local IR.
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
comment|// destroy - Delete this node.  Only when there are no uses.
name|void
name|destroy
parameter_list|()
function_decl|;
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
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|MDNode
modifier|*
parameter_list|)
block|{
return|return
name|true
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
name|MDNodeVal
return|;
block|}
name|private
label|:
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
block|{
name|setValueSubclassData
argument_list|(
name|getSubclassDataFromValue
argument_list|()
operator||
name|NotUniquedBit
argument_list|)
expr_stmt|;
block|}
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
comment|/// NamedMDNode - a tuple of MDNodes.
comment|/// NamedMDNode is always named. All NamedMDNode operand has a type of metadata.
name|class
name|NamedMDNode
range|:
name|public
name|Value
decl_stmt|,
name|public
name|ilist_node
decl|<
name|NamedMDNode
decl|>
block|{
name|friend
name|class
name|SymbolTableListTraits
operator|<
name|NamedMDNode
operator|,
name|Module
operator|>
expr_stmt|;
name|friend
block|struct
name|ilist_traits
operator|<
name|NamedMDNode
operator|>
expr_stmt|;
name|friend
name|class
name|LLVMContextImpl
decl_stmt|;
name|NamedMDNode
argument_list|(
specifier|const
name|NamedMDNode
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|Module
modifier|*
name|Parent
decl_stmt|;
name|void
modifier|*
name|Operands
decl_stmt|;
comment|// SmallVector<WeakVH<MDNode>, 4>
name|void
name|setParent
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
block|{
name|Parent
operator|=
name|M
expr_stmt|;
block|}
name|protected
label|:
name|explicit
name|NamedMDNode
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
specifier|const
name|Twine
modifier|&
name|N
parameter_list|,
name|MDNode
modifier|*
specifier|const
modifier|*
name|Vals
parameter_list|,
name|unsigned
name|NumVals
parameter_list|,
name|Module
modifier|*
name|M
init|=
literal|0
parameter_list|)
function_decl|;
name|public
label|:
specifier|static
name|NamedMDNode
modifier|*
name|Create
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
specifier|const
name|Twine
modifier|&
name|N
parameter_list|,
name|MDNode
modifier|*
specifier|const
modifier|*
name|MDs
parameter_list|,
name|unsigned
name|NumMDs
parameter_list|,
name|Module
modifier|*
name|M
init|=
literal|0
parameter_list|)
block|{
return|return
name|new
name|NamedMDNode
argument_list|(
name|C
argument_list|,
name|N
argument_list|,
name|MDs
argument_list|,
name|NumMDs
argument_list|,
name|M
argument_list|)
return|;
block|}
specifier|static
name|NamedMDNode
modifier|*
name|Create
parameter_list|(
specifier|const
name|NamedMDNode
modifier|*
name|NMD
parameter_list|,
name|Module
modifier|*
name|M
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// eraseFromParent - Drop all references and remove the node from parent
comment|/// module.
name|void
name|eraseFromParent
parameter_list|()
function_decl|;
comment|/// dropAllReferences - Remove all uses and clear node vector.
name|void
name|dropAllReferences
parameter_list|()
function_decl|;
comment|/// ~NamedMDNode - Destroy NamedMDNode.
operator|~
name|NamedMDNode
argument_list|()
expr_stmt|;
comment|/// getParent - Get the module that holds this named metadata collection.
specifier|inline
name|Module
modifier|*
name|getParent
parameter_list|()
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
modifier|*
name|getOperand
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
decl_stmt|;
comment|/// getNumOperands - Return the number of NamedMDNode operands.
name|unsigned
name|getNumOperands
argument_list|()
specifier|const
expr_stmt|;
comment|/// addOperand - Add metadata operand.
name|void
name|addOperand
parameter_list|(
name|MDNode
modifier|*
name|M
parameter_list|)
function_decl|;
comment|/// setName - Set the name of this named metadata.
name|void
name|setName
parameter_list|(
specifier|const
name|Twine
modifier|&
name|NewName
parameter_list|)
function_decl|;
comment|/// getName - Return a constant reference to this named metadata's name.
name|StringRef
name|getName
argument_list|()
specifier|const
expr_stmt|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|NamedMDNode
modifier|*
parameter_list|)
block|{
return|return
name|true
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
name|NamedMDNodeVal
return|;
block|}
block|}
empty_stmt|;
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

