begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Value.h - Definition of the Value class ------------*- C++ -*-===//
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
comment|// This file declares the Value class.
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
name|LLVM_VALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_VALUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/AbstractTypeUser.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Use.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Constant
decl_stmt|;
name|class
name|Argument
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|GlobalAlias
decl_stmt|;
name|class
name|InlineAsm
decl_stmt|;
name|class
name|ValueSymbolTable
decl_stmt|;
name|class
name|TypeSymbolTable
decl_stmt|;
name|template
operator|<
name|typename
name|ValueTy
operator|>
name|class
name|StringMapEntry
expr_stmt|;
name|template
operator|<
name|typename
name|ValueTy
operator|=
name|Value
operator|>
name|class
name|AssertingVH
expr_stmt|;
typedef|typedef
name|StringMapEntry
operator|<
name|Value
operator|*
operator|>
name|ValueName
expr_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|AssemblyAnnotationWriter
decl_stmt|;
name|class
name|ValueHandleBase
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|MetadataContextImpl
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//                                 Value Class
comment|//===----------------------------------------------------------------------===//
comment|/// This is a very important LLVM class. It is the base class of all values
comment|/// computed by a program that may be used as operands to other values. Value is
comment|/// the super class of other important classes such as Instruction and Function.
comment|/// All Values have a Type. Type is not a subclass of Value. All types can have
comment|/// a name and they should belong to some Module. Setting the name on the Value
comment|/// automatically updates the module's symbol table.
comment|///
comment|/// Every value has a "use list" that keeps track of which other Values are
comment|/// using this Value.  A Value can also have an arbitrary number of ValueHandle
comment|/// objects that watch it and listen to RAUW and Destroy events see
comment|/// llvm/Support/ValueHandle.h for details.
comment|///
comment|/// @brief LLVM Value Representation
name|class
name|Value
block|{
specifier|const
name|unsigned
name|char
name|SubclassID
decl_stmt|;
comment|// Subclass identifier (for isa/dyn_cast)
name|unsigned
name|char
name|HasValueHandle
range|:
literal|1
decl_stmt|;
comment|// Has a ValueHandle pointing to this?
name|unsigned
name|char
name|HasMetadata
range|:
literal|1
decl_stmt|;
comment|// Has a metadata attached to this ?
name|protected
label|:
comment|/// SubclassOptionalData - This member is similar to SubclassData, however it
comment|/// is for holding information which may be used to aid optimization, but
comment|/// which may be cleared to zero without affecting conservative
comment|/// interpretation.
name|unsigned
name|char
name|SubclassOptionalData
range|:
literal|7
decl_stmt|;
comment|/// SubclassData - This member is defined by this class, but is not used for
comment|/// anything.  Subclasses can use it to hold whatever state they find useful.
comment|/// This field is initialized to zero by the ctor.
name|unsigned
name|short
name|SubclassData
decl_stmt|;
name|private
label|:
name|PATypeHolder
name|VTy
decl_stmt|;
name|Use
modifier|*
name|UseList
decl_stmt|;
name|friend
name|class
name|ValueSymbolTable
decl_stmt|;
comment|// Allow ValueSymbolTable to directly mod Name.
name|friend
name|class
name|SymbolTable
decl_stmt|;
comment|// Allow SymbolTable to directly poke Name.
name|friend
name|class
name|ValueHandleBase
decl_stmt|;
name|friend
name|class
name|MetadataContextImpl
decl_stmt|;
name|friend
name|class
name|AbstractTypeUser
decl_stmt|;
name|ValueName
modifier|*
name|Name
decl_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|Value
operator|&
operator|)
decl_stmt|;
comment|// Do not implement
name|Value
argument_list|(
specifier|const
name|Value
operator|&
argument_list|)
expr_stmt|;
comment|// Do not implement
name|protected
label|:
comment|/// printCustom - Value subclasses can override this to implement custom
comment|/// printing behavior.
name|virtual
name|void
name|printCustom
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
name|Value
argument_list|(
argument|const Type *Ty
argument_list|,
argument|unsigned scid
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|Value
argument_list|()
expr_stmt|;
comment|/// dump - Support for debugging, callable in GDB: V->dump()
comment|//
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// print - Implement operator<< on Value.
comment|///
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|,
name|AssemblyAnnotationWriter
operator|*
name|AAW
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// All values are typed, get the type of this value.
comment|///
specifier|inline
specifier|const
name|Type
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|VTy
return|;
block|}
comment|/// All values hold a context through their type.
name|LLVMContext
operator|&
name|getContext
argument_list|()
specifier|const
expr_stmt|;
comment|// All values can potentially be named...
specifier|inline
name|bool
name|hasName
argument_list|()
specifier|const
block|{
return|return
name|Name
operator|!=
literal|0
return|;
block|}
name|ValueName
operator|*
name|getValueName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// getName() - Return a constant reference to the value's name. This is cheap
comment|/// and guaranteed to return the same reference as long as the value is not
comment|/// modified.
comment|///
comment|/// This is currently guaranteed to return a StringRef for which data() points
comment|/// to a valid null terminated string. The use of StringRef.data() is
comment|/// deprecated here, however, and clients should not rely on it. If such
comment|/// behavior is needed, clients should use expensive getNameStr(), or switch
comment|/// to an interface that does not depend on null termination.
name|StringRef
name|getName
argument_list|()
specifier|const
expr_stmt|;
comment|/// getNameStr() - Return the name of the specified value, *constructing a
comment|/// string* to hold it.  This is guaranteed to construct a string and is very
comment|/// expensive, clients should use getName() unless necessary.
name|std
operator|::
name|string
name|getNameStr
argument_list|()
specifier|const
expr_stmt|;
comment|/// setName() - Change the name of the value, choosing a new unique name if
comment|/// the provided name is taken.
comment|///
comment|/// \arg Name - The new name; or "" if the value's name should be removed.
name|void
name|setName
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Name
parameter_list|)
function_decl|;
comment|/// takeName - transfer the name from V to this value, setting V's name to
comment|/// empty.  It is an error to call V->takeName(V).
name|void
name|takeName
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|/// replaceAllUsesWith - Go through the uses list for this definition and make
comment|/// each use point to "V" instead of "this".  After this completes, 'this's
comment|/// use list is guaranteed to be empty.
comment|///
name|void
name|replaceAllUsesWith
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|// uncheckedReplaceAllUsesWith - Just like replaceAllUsesWith but dangerous.
comment|// Only use when in type resolution situations!
name|void
name|uncheckedReplaceAllUsesWith
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
function_decl|;
comment|//----------------------------------------------------------------------
comment|// Methods for handling the chain of uses of this Value.
comment|//
typedef|typedef
name|value_use_iterator
operator|<
name|User
operator|>
name|use_iterator
expr_stmt|;
typedef|typedef
name|value_use_iterator
operator|<
specifier|const
name|User
operator|>
name|use_const_iterator
expr_stmt|;
name|bool
name|use_empty
argument_list|()
specifier|const
block|{
return|return
name|UseList
operator|==
literal|0
return|;
block|}
name|use_iterator
name|use_begin
parameter_list|()
block|{
return|return
name|use_iterator
argument_list|(
name|UseList
argument_list|)
return|;
block|}
name|use_const_iterator
name|use_begin
argument_list|()
specifier|const
block|{
return|return
name|use_const_iterator
argument_list|(
name|UseList
argument_list|)
return|;
block|}
name|use_iterator
name|use_end
parameter_list|()
block|{
return|return
name|use_iterator
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|use_const_iterator
name|use_end
argument_list|()
specifier|const
block|{
return|return
name|use_const_iterator
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|User
modifier|*
name|use_back
parameter_list|()
block|{
return|return
operator|*
name|use_begin
argument_list|()
return|;
block|}
specifier|const
name|User
operator|*
name|use_back
argument_list|()
specifier|const
block|{
return|return
operator|*
name|use_begin
argument_list|()
return|;
block|}
comment|/// hasOneUse - Return true if there is exactly one user of this value.  This
comment|/// is specialized because it is a common request and does not require
comment|/// traversing the whole use list.
comment|///
name|bool
name|hasOneUse
argument_list|()
specifier|const
block|{
name|use_const_iterator
name|I
operator|=
name|use_begin
argument_list|()
block|,
name|E
operator|=
name|use_end
argument_list|()
block|;
if|if
condition|(
name|I
operator|==
name|E
condition|)
return|return
name|false
return|;
return|return
operator|++
name|I
operator|==
name|E
return|;
block|}
comment|/// hasNUses - Return true if this Value has exactly N users.
comment|///
name|bool
name|hasNUses
argument_list|(
name|unsigned
name|N
argument_list|)
decl|const
decl_stmt|;
comment|/// hasNUsesOrMore - Return true if this value has N users or more.  This is
comment|/// logically equivalent to getNumUses()>= N.
comment|///
name|bool
name|hasNUsesOrMore
argument_list|(
name|unsigned
name|N
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isUsedInBasicBlock
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
comment|/// getNumUses - This method computes the number of uses of this Value.  This
comment|/// is a linear time operation.  Use hasOneUse, hasNUses, or hasMoreThanNUses
comment|/// to check for specific values.
name|unsigned
name|getNumUses
argument_list|()
specifier|const
expr_stmt|;
comment|/// addUse - This method should only be used by the Use class.
comment|///
name|void
name|addUse
parameter_list|(
name|Use
modifier|&
name|U
parameter_list|)
block|{
name|U
operator|.
name|addToList
argument_list|(
operator|&
name|UseList
argument_list|)
expr_stmt|;
block|}
comment|/// An enumeration for keeping track of the concrete subclass of Value that
comment|/// is actually instantiated. Values of this enumeration are kept in the
comment|/// Value classes SubclassID field. They are used for concrete type
comment|/// identification.
enum|enum
name|ValueTy
block|{
name|ArgumentVal
block|,
comment|// This is an instance of Argument
name|BasicBlockVal
block|,
comment|// This is an instance of BasicBlock
name|FunctionVal
block|,
comment|// This is an instance of Function
name|GlobalAliasVal
block|,
comment|// This is an instance of GlobalAlias
name|GlobalVariableVal
block|,
comment|// This is an instance of GlobalVariable
name|UndefValueVal
block|,
comment|// This is an instance of UndefValue
name|BlockAddressVal
block|,
comment|// This is an instance of BlockAddress
name|ConstantExprVal
block|,
comment|// This is an instance of ConstantExpr
name|ConstantAggregateZeroVal
block|,
comment|// This is an instance of ConstantAggregateNull
name|ConstantIntVal
block|,
comment|// This is an instance of ConstantInt
name|ConstantFPVal
block|,
comment|// This is an instance of ConstantFP
name|ConstantArrayVal
block|,
comment|// This is an instance of ConstantArray
name|ConstantStructVal
block|,
comment|// This is an instance of ConstantStruct
name|ConstantVectorVal
block|,
comment|// This is an instance of ConstantVector
name|ConstantPointerNullVal
block|,
comment|// This is an instance of ConstantPointerNull
name|MDNodeVal
block|,
comment|// This is an instance of MDNode
name|MDStringVal
block|,
comment|// This is an instance of MDString
name|NamedMDNodeVal
block|,
comment|// This is an instance of NamedMDNode
name|InlineAsmVal
block|,
comment|// This is an instance of InlineAsm
name|PseudoSourceValueVal
block|,
comment|// This is an instance of PseudoSourceValue
name|InstructionVal
block|,
comment|// This is an instance of Instruction
comment|// Markers:
name|ConstantFirstVal
init|=
name|FunctionVal
block|,
name|ConstantLastVal
init|=
name|ConstantPointerNullVal
block|}
enum|;
comment|/// getValueID - Return an ID for the concrete type of this object.  This is
comment|/// used to implement the classof checks.  This should not be used for any
comment|/// other purpose, as the values may change as LLVM evolves.  Also, note that
comment|/// for instructions, the Instruction's opcode is added to InstructionVal. So
comment|/// this means three things:
comment|/// # there is no value with code InstructionVal (no opcode==0).
comment|/// # there are more possible values for the value type than in ValueTy enum.
comment|/// # the InstructionVal enumerator must be the highest valued enumerator in
comment|///   the ValueTy enum.
name|unsigned
name|getValueID
argument_list|()
specifier|const
block|{
return|return
name|SubclassID
return|;
block|}
comment|/// getRawSubclassOptionalData - Return the raw optional flags value
comment|/// contained in this value. This should only be used when testing two
comment|/// Values for equivalence.
name|unsigned
name|getRawSubclassOptionalData
argument_list|()
specifier|const
block|{
return|return
name|SubclassOptionalData
return|;
block|}
comment|/// hasSameSubclassOptionalData - Test whether the optional flags contained
comment|/// in this value are equal to the optional flags in the given value.
name|bool
name|hasSameSubclassOptionalData
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
decl|const
block|{
return|return
name|SubclassOptionalData
operator|==
name|V
operator|->
name|SubclassOptionalData
return|;
block|}
comment|/// intersectOptionalDataWith - Clear any optional flags in this value
comment|/// that are not also set in the given value.
name|void
name|intersectOptionalDataWith
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
block|{
name|SubclassOptionalData
operator|&=
name|V
operator|->
name|SubclassOptionalData
expr_stmt|;
block|}
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|Value
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
comment|// Values are always values.
block|}
comment|/// getRawType - This should only be used to implement the vmcore library.
comment|///
specifier|const
name|Type
operator|*
name|getRawType
argument_list|()
specifier|const
block|{
return|return
name|VTy
operator|.
name|getRawType
argument_list|()
return|;
block|}
comment|/// stripPointerCasts - This method strips off any unneeded pointer
comment|/// casts from the specified value, returning the original uncasted value.
comment|/// Note that the returned value has pointer type if the specified value does.
name|Value
modifier|*
name|stripPointerCasts
parameter_list|()
function_decl|;
specifier|const
name|Value
operator|*
name|stripPointerCasts
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|stripPointerCasts
argument_list|()
return|;
block|}
comment|/// getUnderlyingObject - This method strips off any GEP address adjustments
comment|/// and pointer casts from the specified value, returning the original object
comment|/// being addressed.  Note that the returned value has pointer type if the
comment|/// specified value does.
name|Value
modifier|*
name|getUnderlyingObject
parameter_list|()
function_decl|;
specifier|const
name|Value
operator|*
name|getUnderlyingObject
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getUnderlyingObject
argument_list|()
return|;
block|}
comment|/// DoPHITranslation - If this value is a PHI node with CurBB as its parent,
comment|/// return the value in the PHI node corresponding to PredBB.  If not, return
comment|/// ourself.  This is useful if you want to know the value something has in a
comment|/// predecessor block.
name|Value
modifier|*
name|DoPHITranslation
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|CurBB
parameter_list|,
specifier|const
name|BasicBlock
modifier|*
name|PredBB
parameter_list|)
function_decl|;
specifier|const
name|Value
modifier|*
name|DoPHITranslation
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|CurBB
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|PredBB
argument_list|)
decl|const
block|{
return|return
name|const_cast
operator|<
name|Value
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|DoPHITranslation
argument_list|(
name|CurBB
argument_list|,
name|PredBB
argument_list|)
return|;
block|}
comment|/// hasMetadata - Return true if metadata is attached with this value.
name|bool
name|hasMetadata
argument_list|()
specifier|const
block|{
return|return
name|HasMetadata
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
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
name|Value
operator|&
name|V
operator|)
block|{
name|V
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

begin_expr_stmt
name|void
name|Use
operator|::
name|set
argument_list|(
argument|Value *V
argument_list|)
block|{
if|if
condition|(
name|Val
condition|)
name|removeFromList
argument_list|()
expr_stmt|;
name|Val
operator|=
name|V
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|V
condition|)
name|V
operator|->
name|addUse
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
end_if

begin_comment
unit|}
comment|// isa - Provide some specializations of isa so that we don't have to include
end_comment

begin_comment
comment|// the subtype header files to test to see if the value is a subclass...
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
unit|template
operator|<
operator|>
specifier|inline
name|bool
name|isa_impl
operator|<
name|Constant
operator|,
name|Value
operator|>
operator|(
specifier|const
name|Value
operator|&
name|Val
operator|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|>=
name|Value
operator|::
name|ConstantFirstVal
operator|&&
name|Val
operator|.
name|getValueID
argument_list|()
operator|<=
name|Value
operator|::
name|ConstantLastVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|isa_impl
operator|<
name|Argument
operator|,
name|Value
operator|>
operator|(
specifier|const
name|Value
operator|&
name|Val
operator|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|ArgumentVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|isa_impl
operator|<
name|InlineAsm
operator|,
name|Value
operator|>
operator|(
specifier|const
name|Value
operator|&
name|Val
operator|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|InlineAsmVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|isa_impl
operator|<
name|Instruction
operator|,
name|Value
operator|>
operator|(
specifier|const
name|Value
operator|&
name|Val
operator|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|>=
name|Value
operator|::
name|InstructionVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|isa_impl
operator|<
name|BasicBlock
operator|,
name|Value
operator|>
operator|(
specifier|const
name|Value
operator|&
name|Val
operator|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|BasicBlockVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|isa_impl
operator|<
name|Function
operator|,
name|Value
operator|>
operator|(
specifier|const
name|Value
operator|&
name|Val
operator|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|FunctionVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|isa_impl
operator|<
name|GlobalVariable
operator|,
name|Value
operator|>
operator|(
specifier|const
name|Value
operator|&
name|Val
operator|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|GlobalVariableVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|isa_impl
operator|<
name|GlobalAlias
operator|,
name|Value
operator|>
operator|(
specifier|const
name|Value
operator|&
name|Val
operator|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|GlobalAliasVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|isa_impl
operator|<
name|GlobalValue
operator|,
name|Value
operator|>
operator|(
specifier|const
name|Value
operator|&
name|Val
operator|)
block|{
return|return
name|isa
operator|<
name|GlobalVariable
operator|>
operator|(
name|Val
operator|)
operator|||
name|isa
operator|<
name|Function
operator|>
operator|(
name|Val
operator|)
operator|||
name|isa
operator|<
name|GlobalAlias
operator|>
operator|(
name|Val
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Value* is only 4-byte aligned.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|Value
operator|*
operator|>
block|{
typedef|typedef
name|Value
modifier|*
name|PT
typedef|;
name|public
operator|:
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|PT P
argument_list|)
block|{
return|return
name|P
return|;
block|}
specifier|static
specifier|inline
name|PT
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|PT
operator|>
operator|(
name|P
operator|)
return|;
block|}
block|enum
block|{
name|NumLowBitsAvailable
operator|=
literal|2
block|}
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

