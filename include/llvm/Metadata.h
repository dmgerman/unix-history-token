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
name|LLVM_MDNODE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MDNODE_H
end_define

begin_include
include|#
directive|include
file|"llvm/User.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/OperandTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ValueHandle.h"
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
comment|//===----------------------------------------------------------------------===//
comment|// MetadataBase  - A base class for MDNode, MDString and NamedMDNode.
name|class
name|MetadataBase
range|:
name|public
name|User
block|{
name|private
operator|:
comment|/// ReservedSpace - The number of operands actually allocated.  NumOperands is
comment|/// the number actually in use.
name|unsigned
name|ReservedSpace
block|;
name|protected
operator|:
name|MetadataBase
argument_list|(
argument|const Type *Ty
argument_list|,
argument|unsigned scid
argument_list|)
operator|:
name|User
argument_list|(
name|Ty
argument_list|,
name|scid
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
block|,
name|ReservedSpace
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|resizeOperands
argument_list|(
argument|unsigned NumOps
argument_list|)
block|;
name|public
operator|:
comment|/// isNullValue - Return true if this is the value that would be returned by
comment|/// getNullValue.  This always returns false because getNullValue will never
comment|/// produce metadata.
name|virtual
name|bool
name|isNullValue
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
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
name|void
operator|*
name|operator
name|new
argument_list|(
name|size_t
argument_list|,
name|unsigned
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|unsigned
name|getNumOperands
argument_list|()
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
argument|const char *begin
argument_list|,
argument|unsigned l
argument_list|)
operator|:
name|MetadataBase
argument_list|(
name|Type
operator|::
name|getMetadataTy
argument_list|(
name|C
argument_list|)
argument_list|,
name|Value
operator|::
name|MDStringVal
argument_list|)
block|,
name|Str
argument_list|(
argument|begin
argument_list|,
argument|l
argument_list|)
block|{}
name|public
operator|:
comment|// Do not allocate any space for operands.
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
literal|0
argument_list|)
return|;
block|}
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
name|StringRef
operator|&
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
name|length
argument_list|()
specifier|const
block|{
return|return
name|Str
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// begin() - Pointer to the first byte of the string.
comment|///
specifier|const
name|char
operator|*
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
specifier|const
name|char
operator|*
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
comment|//===----------------------------------------------------------------------===//
comment|/// MDNode - a tuple of other values.
comment|/// These contain a list of the values that represent the metadata.
comment|/// MDNode is always unnamed.
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
operator|*
name|operator
name|new
argument_list|(
name|size_t
argument_list|,
name|unsigned
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
comment|// getNumOperands - Make this only available for private uses.
name|unsigned
name|getNumOperands
argument_list|()
block|{
return|return
name|User
operator|::
name|getNumOperands
argument_list|()
return|;
block|}
name|friend
name|class
name|ElementVH
block|;
comment|// Use CallbackVH to hold MDNOde elements.
block|struct
name|ElementVH
operator|:
name|public
name|CallbackVH
block|{
name|MDNode
operator|*
name|Parent
block|;
name|ElementVH
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|MDNode
operator|*
name|P
argument_list|)
operator|:
name|CallbackVH
argument_list|(
name|V
argument_list|)
block|,
name|Parent
argument_list|(
argument|P
argument_list|)
block|{}
operator|~
name|ElementVH
argument_list|()
block|{}
name|virtual
name|void
name|deleted
argument_list|()
block|{
name|Parent
operator|->
name|replaceElement
argument_list|(
argument|this->operator Value*()
argument_list|,
literal|0
argument_list|)
block|;     }
name|virtual
name|void
name|allUsesReplacedWith
argument_list|(
argument|Value *NV
argument_list|)
block|{
name|Parent
operator|->
name|replaceElement
argument_list|(
argument|this->operator Value*()
argument_list|,
argument|NV
argument_list|)
block|;     }
block|}
block|;
comment|// Replace each instance of F from the element list of this node with T.
name|void
name|replaceElement
argument_list|(
name|Value
operator|*
name|F
argument_list|,
name|Value
operator|*
name|T
argument_list|)
block|;
name|SmallVector
operator|<
name|ElementVH
block|,
literal|4
operator|>
name|Node
block|;
name|protected
operator|:
name|explicit
name|MDNode
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|Value*const* Vals
argument_list|,
argument|unsigned NumVals
argument_list|)
block|;
name|public
operator|:
comment|// Do not allocate any space for operands.
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
literal|0
argument_list|)
return|;
block|}
comment|// Constructors and destructors.
specifier|static
name|MDNode
operator|*
name|get
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|Value* const* Vals
argument_list|,
argument|unsigned NumVals
argument_list|)
block|;
comment|/// dropAllReferences - Remove all uses and clear node vector.
name|void
name|dropAllReferences
argument_list|()
block|;
comment|/// ~MDNode - Destroy MDNode.
operator|~
name|MDNode
argument_list|()
block|;
comment|/// getElement - Return specified element.
name|Value
operator|*
name|getElement
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|getNumElements
argument_list|()
operator|>
name|i
operator|&&
literal|"Invalid element number!"
argument_list|)
block|;
return|return
name|Node
index|[
name|i
index|]
return|;
block|}
comment|/// getNumElements - Return number of MDNode elements.
name|unsigned
name|getNumElements
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|.
name|size
argument_list|()
return|;
block|}
comment|// Element access
typedef|typedef
name|SmallVectorImpl
operator|<
name|ElementVH
operator|>
operator|::
name|const_iterator
name|const_elem_iterator
expr_stmt|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|ElementVH
operator|>
operator|::
name|iterator
name|elem_iterator
expr_stmt|;
comment|/// elem_empty - Return true if MDNode is empty.
name|bool
name|elem_empty
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|.
name|empty
argument_list|()
return|;
block|}
name|const_elem_iterator
name|elem_begin
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_elem_iterator
name|elem_end
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|.
name|end
argument_list|()
return|;
block|}
name|elem_iterator
name|elem_begin
argument_list|()
block|{
return|return
name|Node
operator|.
name|begin
argument_list|()
return|;
block|}
name|elem_iterator
name|elem_end
argument_list|()
block|{
return|return
name|Node
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// isNullValue - Return true if this is the value that would be returned by
comment|/// getNullValue.  This always returns false because getNullValue will never
comment|/// produce metadata.
name|virtual
name|bool
name|isNullValue
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Profile - calculate a unique identifier for this MDNode to collapse
comment|/// duplicates
name|void
name|Profile
argument_list|(
argument|FoldingSetNodeID&ID
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|replaceUsesOfWithOnConstant
argument_list|(
argument|Value *
argument_list|,
argument|Value *
argument_list|,
argument|Use *
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"This should never be called because MDNodes have no ops"
argument_list|)
block|;   }
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
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// WeakMetadataVH - a weak value handle for metadata.
name|class
name|WeakMetadataVH
operator|:
name|public
name|WeakVH
block|{
name|public
operator|:
name|WeakMetadataVH
argument_list|()
operator|:
name|WeakVH
argument_list|()
block|{}
name|WeakMetadataVH
argument_list|(
name|MetadataBase
operator|*
name|M
argument_list|)
operator|:
name|WeakVH
argument_list|(
argument|M
argument_list|)
block|{}
name|WeakMetadataVH
argument_list|(
specifier|const
name|WeakMetadataVH
operator|&
name|RHS
argument_list|)
operator|:
name|WeakVH
argument_list|(
argument|RHS
argument_list|)
block|{}
name|operator
name|Value
operator|*
operator|(
operator|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"WeakMetadataVH only handles Metadata"
argument_list|)
block|;   }
name|operator
name|MetadataBase
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|dyn_cast_or_null
operator|<
name|MetadataBase
operator|>
operator|(
name|getValPtr
argument_list|()
operator|)
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// NamedMDNode - a tuple of other metadata.
comment|/// NamedMDNode is always named. All NamedMDNode element has a type of metadata.
name|template
operator|<
name|typename
name|ValueSubClass
block|,
name|typename
name|ItemParentClass
operator|>
name|class
name|SymbolTableListTraits
block|;
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
name|void
operator|*
name|operator
name|new
argument_list|(
name|size_t
argument_list|,
name|unsigned
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
comment|// getNumOperands - Make this only available for private uses.
name|unsigned
name|getNumOperands
argument_list|()
block|{
return|return
name|User
operator|::
name|getNumOperands
argument_list|()
return|;
block|}
name|Module
operator|*
name|Parent
block|;
name|SmallVector
operator|<
name|WeakMetadataVH
block|,
literal|4
operator|>
name|Node
block|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|WeakMetadataVH
operator|>
operator|::
name|iterator
name|elem_iterator
expr_stmt|;
name|protected
operator|:
name|explicit
name|NamedMDNode
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|const Twine&N
argument_list|,
argument|MetadataBase*const* Vals
argument_list|,
argument|unsigned NumVals
argument_list|,
argument|Module *M =
literal|0
argument_list|)
block|;
name|public
operator|:
comment|// Do not allocate any space for operands.
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
literal|0
argument_list|)
return|;
block|}
specifier|static
name|NamedMDNode
operator|*
name|Create
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|const Twine&N
argument_list|,
argument|MetadataBase*const*MDs
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
comment|/// getElement - Return specified element.
name|MetadataBase
operator|*
name|getElement
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|getNumElements
argument_list|()
operator|>
name|i
operator|&&
literal|"Invalid element number!"
argument_list|)
block|;
return|return
name|Node
index|[
name|i
index|]
return|;
block|}
comment|/// getNumElements - Return number of NamedMDNode elements.
name|unsigned
name|getNumElements
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// addElement - Add metadata element.
name|void
name|addElement
argument_list|(
argument|MetadataBase *M
argument_list|)
block|{
name|resizeOperands
argument_list|(
literal|0
argument_list|)
block|;
name|OperandList
index|[
name|NumOperands
operator|++
index|]
operator|=
name|M
block|;
name|Node
operator|.
name|push_back
argument_list|(
name|WeakMetadataVH
argument_list|(
name|M
argument_list|)
argument_list|)
block|;   }
typedef|typedef
name|SmallVectorImpl
operator|<
name|WeakMetadataVH
operator|>
operator|::
name|const_iterator
name|const_elem_iterator
expr_stmt|;
name|bool
name|elem_empty
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|.
name|empty
argument_list|()
return|;
block|}
name|const_elem_iterator
name|elem_begin
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_elem_iterator
name|elem_end
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|.
name|end
argument_list|()
return|;
block|}
name|elem_iterator
name|elem_begin
argument_list|()
block|{
return|return
name|Node
operator|.
name|begin
argument_list|()
return|;
block|}
name|elem_iterator
name|elem_end
argument_list|()
block|{
return|return
name|Node
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// isNullValue - Return true if this is the value that would be returned by
comment|/// getNullValue.  This always returns false because getNullValue will never
comment|/// produce metadata.
name|virtual
name|bool
name|isNullValue
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|void
name|replaceUsesOfWithOnConstant
argument_list|(
argument|Value *
argument_list|,
argument|Value *
argument_list|,
argument|Use *
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"This should never be called because NamedMDNodes have no ops"
argument_list|)
block|;   }
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
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// MetadataContext -
comment|/// MetadataContext handles uniquing and assignment of IDs for custom metadata
comment|/// types. Custom metadata handler names do not contain spaces. And the name
comment|/// must start with an alphabet. The regular expression used to check name
comment|/// is [a-zA-Z$._][a-zA-Z$._0-9]*
name|class
name|MetadataContext
block|{
name|public
operator|:
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|WeakVH
operator|>
name|MDPairTy
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|MDPairTy
operator|,
literal|2
operator|>
name|MDMapTy
expr_stmt|;
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|Instruction
operator|*
operator|,
name|MDMapTy
operator|>
name|MDStoreTy
expr_stmt|;
name|friend
name|class
name|BitcodeReader
decl_stmt|;
name|private
label|:
comment|/// MetadataStore - Collection of metadata used in this context.
name|MDStoreTy
name|MetadataStore
decl_stmt|;
comment|/// MDHandlerNames - Map to hold metadata handler names.
name|StringMap
operator|<
name|unsigned
operator|>
name|MDHandlerNames
expr_stmt|;
name|public
label|:
comment|/// RegisterMDKind - Register a new metadata kind and return its ID.
comment|/// A metadata kind can be registered only once.
name|unsigned
name|RegisterMDKind
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
comment|/// getMDKind - Return metadata kind. If the requested metadata kind
comment|/// is not registered then return 0.
name|unsigned
name|getMDKind
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
comment|/// validName - Return true if Name is a valid custom metadata handler name.
name|bool
name|validName
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
comment|/// getMD - Get the metadata of given kind attached with an Instruction.
comment|/// If the metadata is not found then return 0.
name|MDNode
modifier|*
name|getMD
parameter_list|(
name|unsigned
name|Kind
parameter_list|,
specifier|const
name|Instruction
modifier|*
name|Inst
parameter_list|)
function_decl|;
comment|/// getMDs - Get the metadata attached with an Instruction.
specifier|const
name|MDMapTy
modifier|*
name|getMDs
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|Inst
parameter_list|)
function_decl|;
comment|/// addMD - Attach the metadata of given kind with an Instruction.
name|void
name|addMD
parameter_list|(
name|unsigned
name|Kind
parameter_list|,
name|MDNode
modifier|*
name|Node
parameter_list|,
name|Instruction
modifier|*
name|Inst
parameter_list|)
function_decl|;
comment|/// removeMD - Remove metadata of given kind attached with an instuction.
name|void
name|removeMD
parameter_list|(
name|unsigned
name|Kind
parameter_list|,
name|Instruction
modifier|*
name|Inst
parameter_list|)
function_decl|;
comment|/// removeMDs - Remove all metadata attached with an instruction.
name|void
name|removeMDs
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|Inst
parameter_list|)
function_decl|;
comment|/// copyMD - If metadata is attached with Instruction In1 then attach
comment|/// the same metadata to In2.
name|void
name|copyMD
parameter_list|(
name|Instruction
modifier|*
name|In1
parameter_list|,
name|Instruction
modifier|*
name|In2
parameter_list|)
function_decl|;
comment|/// getHandlerNames - Get handler names. This is used by bitcode
comment|/// writer.
specifier|const
name|StringMap
operator|<
name|unsigned
operator|>
operator|*
name|getHandlerNames
argument_list|()
expr_stmt|;
comment|/// ValueIsDeleted - This handler is used to update metadata store
comment|/// when a value is deleted.
name|void
name|ValueIsDeleted
parameter_list|(
specifier|const
name|Value
modifier|*
parameter_list|)
block|{}
name|void
name|ValueIsDeleted
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|Inst
parameter_list|)
block|{
name|removeMDs
argument_list|(
name|Inst
argument_list|)
expr_stmt|;
block|}
name|void
name|ValueIsRAUWd
parameter_list|(
name|Value
modifier|*
name|V1
parameter_list|,
name|Value
modifier|*
name|V2
parameter_list|)
function_decl|;
comment|/// ValueIsCloned - This handler is used to update metadata store
comment|/// when In1 is cloned to create In2.
name|void
name|ValueIsCloned
parameter_list|(
specifier|const
name|Instruction
modifier|*
name|In1
parameter_list|,
name|Instruction
modifier|*
name|In2
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

