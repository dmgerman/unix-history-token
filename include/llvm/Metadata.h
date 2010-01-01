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
comment|// MetadataBase  - A base class for MDNode, MDString and NamedMDNode.
name|class
name|MetadataBase
range|:
name|public
name|Value
block|{
name|protected
operator|:
name|MetadataBase
argument_list|(
argument|const Type *Ty
argument_list|,
argument|unsigned scid
argument_list|)
operator|:
name|Value
argument_list|(
argument|Ty
argument_list|,
argument|scid
argument_list|)
block|{}
name|public
operator|:
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const MetadataBase *
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
operator|||
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|MDNodeVal
operator|||
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|NamedMDNodeVal
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// MDString - a single uniqued string.
comment|/// These are used to efficiently contain a byte sequence for metadata.
comment|/// MDString is always unnamd.
name|class
name|MDString
operator|:
name|public
name|MetadataBase
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
expr|}
block|;
name|class
name|MDNodeOperand
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// MDNode - a tuple of other values.
name|class
name|MDNode
operator|:
name|public
name|MetadataBase
block|,
name|public
name|FoldingSetNode
block|{
name|MDNode
argument_list|(
specifier|const
name|MDNode
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
operator|=
operator|(
specifier|const
name|MDNode
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT
name|friend
name|class
name|MDNodeOperand
block|;
comment|/// NumOperands - This many 'MDNodeOperand' items are co-allocated onto the
comment|/// end of this MDNode.
name|unsigned
name|NumOperands
block|;
comment|// Subclass data enums.
block|enum
block|{
comment|/// FunctionLocalBit - This bit is set if this MDNode is function local.
comment|/// This is true when it (potentially transitively) contains a reference to
comment|/// something in a function, like an argument, basicblock, or instruction.
name|FunctionLocalBit
operator|=
literal|1
operator|<<
literal|0
block|,
comment|/// NotUniquedBit - This is set on MDNodes that are not uniqued because they
comment|/// have a null perand.
name|NotUniquedBit
operator|=
literal|1
operator|<<
literal|1
block|,
comment|/// DestroyFlag - This bit is set by destroy() so the destructor can assert
comment|/// that the node isn't being destroyed with a plain 'delete'.
name|DestroyFlag
operator|=
literal|1
operator|<<
literal|2
block|}
block|;
comment|// Replace each instance of F from the operand list of this node with T.
name|void
name|replaceOperand
argument_list|(
name|MDNodeOperand
operator|*
name|Op
argument_list|,
name|Value
operator|*
name|NewVal
argument_list|)
block|;
operator|~
name|MDNode
argument_list|()
block|;
name|protected
operator|:
name|explicit
name|MDNode
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|Value *const *Vals
argument_list|,
argument|unsigned NumVals
argument_list|,
argument|bool isFunctionLocal
argument_list|)
block|;
name|public
operator|:
comment|// Constructors and destructors.
specifier|static
name|MDNode
operator|*
name|get
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|Value *const *Vals
argument_list|,
argument|unsigned NumVals
argument_list|,
argument|bool isFunctionLocal = false
argument_list|)
block|;
comment|/// getOperand - Return specified operand.
name|Value
operator|*
name|getOperand
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|;
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
comment|// destroy - Delete this node.  Only when there are no uses.
name|void
name|destroy
argument_list|()
block|;
comment|/// Profile - calculate a unique identifier for this MDNode to collapse
comment|/// duplicates
name|void
name|Profile
argument_list|(
argument|FoldingSetNodeID&ID
argument_list|)
specifier|const
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const MDNode *
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
name|MDNodeVal
return|;
block|}
name|private
operator|:
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
argument_list|()
block|{
name|setValueSubclassData
argument_list|(
name|getSubclassDataFromValue
argument_list|()
operator||
name|NotUniquedBit
argument_list|)
block|;   }
comment|// Shadow Value::setValueSubclassData with a private forwarding method so that
comment|// any future subclasses cannot accidentally use it.
name|void
name|setValueSubclassData
argument_list|(
argument|unsigned short D
argument_list|)
block|{
name|Value
operator|::
name|setValueSubclassData
argument_list|(
name|D
argument_list|)
block|;   }
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// NamedMDNode - a tuple of other metadata.
comment|/// NamedMDNode is always named. All NamedMDNode operand has a type of metadata.
name|class
name|NamedMDNode
operator|:
name|public
name|MetadataBase
block|,
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
name|class
name|LLVMContextImpl
block|;
name|NamedMDNode
argument_list|(
specifier|const
name|NamedMDNode
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|Module
operator|*
name|Parent
block|;
name|void
operator|*
name|Operands
block|;
comment|// SmallVector<TrackingVH<MetadataBase>, 4>
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
name|protected
operator|:
name|explicit
name|NamedMDNode
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|const Twine&N
argument_list|,
argument|MetadataBase*const *Vals
argument_list|,
argument|unsigned NumVals
argument_list|,
argument|Module *M =
literal|0
argument_list|)
block|;
name|public
operator|:
specifier|static
name|NamedMDNode
operator|*
name|Create
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|const Twine&N
argument_list|,
argument|MetadataBase *const *MDs
argument_list|,
argument|unsigned NumMDs
argument_list|,
argument|Module *M =
literal|0
argument_list|)
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
operator|*
name|Create
argument_list|(
specifier|const
name|NamedMDNode
operator|*
name|NMD
argument_list|,
name|Module
operator|*
name|M
operator|=
literal|0
argument_list|)
block|;
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
name|MetadataBase
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
name|MetadataBase
operator|*
name|M
argument_list|)
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const NamedMDNode *
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
name|NamedMDNodeVal
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

