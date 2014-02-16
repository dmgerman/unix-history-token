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
name|LLVM_IR_VALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_VALUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Use.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CBindingWrapping.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Core.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|APInt
decl_stmt|;
name|class
name|Argument
decl_stmt|;
name|class
name|AssemblyAnnotationWriter
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|GlobalAlias
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|InlineAsm
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|ValueHandleBase
decl_stmt|;
name|class
name|ValueSymbolTable
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|template
operator|<
name|typename
name|ValueTy
operator|>
name|class
name|StringMapEntry
expr_stmt|;
typedef|typedef
name|StringMapEntry
operator|<
name|Value
operator|*
operator|>
name|ValueName
expr_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//                                 Value Class
comment|//===----------------------------------------------------------------------===//
comment|/// This is a very important LLVM class. It is the base class of all values
comment|/// computed by a program that may be used as operands to other values. Value is
comment|/// the super class of other important classes such as Instruction and Function.
comment|/// All Values have a Type. Type is not a subclass of Value. Some values can
comment|/// have a name and they belong to some Module.  Setting the name on the Value
comment|/// automatically updates the module's symbol table.
comment|///
comment|/// Every value has a "use list" that keeps track of which other Values are
comment|/// using this Value.  A Value can also have an arbitrary number of ValueHandle
comment|/// objects that watch it and listen to RAUW and Destroy events.  See
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
name|private
label|:
comment|/// SubclassData - This member is defined by this class, but is not used for
comment|/// anything.  Subclasses can use it to hold whatever state they find useful.
comment|/// This field is initialized to zero by the ctor.
name|unsigned
name|short
name|SubclassData
decl_stmt|;
name|Type
modifier|*
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
name|ValueHandleBase
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
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|Value
argument_list|(
argument|const Value&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|protected
label|:
comment|/// printCustom - Value subclasses can override this to implement custom
comment|/// printing behavior.
name|virtual
name|void
name|printCustom
parameter_list|(
name|raw_ostream
modifier|&
name|O
parameter_list|)
function_decl|const;
name|Value
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned scid
argument_list|)
empty_stmt|;
name|public
label|:
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
comment|// All values can potentially be named.
name|bool
name|hasName
argument_list|()
specifier|const
block|{
return|return
name|Name
operator|!=
literal|0
operator|&&
name|SubclassID
operator|!=
name|MDStringVal
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
name|void
name|setValueName
parameter_list|(
name|ValueName
modifier|*
name|VN
parameter_list|)
block|{
name|Name
operator|=
name|VN
expr_stmt|;
block|}
comment|/// getName() - Return a constant reference to the value's name. This is cheap
comment|/// and guaranteed to return the same reference as long as the value is not
comment|/// modified.
name|StringRef
name|getName
argument_list|()
specifier|const
expr_stmt|;
comment|/// setName() - Change the name of the value, choosing a new unique name if
comment|/// the provided name is taken.
comment|///
comment|/// \param Name The new name; or "" if the value's name should be removed.
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
name|const_use_iterator
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
name|const_use_iterator
name|use_begin
argument_list|()
specifier|const
block|{
return|return
name|const_use_iterator
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
name|const_use_iterator
name|use_end
argument_list|()
specifier|const
block|{
return|return
name|const_use_iterator
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
name|const_use_iterator
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
comment|/// is a linear time operation.  Use hasOneUse, hasNUses, or hasNUsesOrMore
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
comment|// This is an instance of ConstantAggregateZero
name|ConstantDataArrayVal
block|,
comment|// This is an instance of ConstantDataArray
name|ConstantDataVectorVal
block|,
comment|// This is an instance of ConstantDataVector
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
name|InlineAsmVal
block|,
comment|// This is an instance of InlineAsm
name|PseudoSourceValueVal
block|,
comment|// This is an instance of PseudoSourceValue
name|FixedStackPseudoSourceValueVal
block|,
comment|// This is an instance of
comment|// FixedStackPseudoSourceValue
name|InstructionVal
block|,
comment|// This is an instance of Instruction
comment|// Enum values starting at InstructionVal are used for Instructions;
comment|// don't add new values here!
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
comment|/// clearSubclassOptionalData - Clear the optional flags contained in
comment|/// this value.
name|void
name|clearSubclassOptionalData
parameter_list|()
block|{
name|SubclassOptionalData
operator|=
literal|0
expr_stmt|;
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
comment|/// hasValueHandle - Return true if there is a value handle associated with
comment|/// this value.
name|bool
name|hasValueHandle
argument_list|()
specifier|const
block|{
return|return
name|HasValueHandle
return|;
block|}
comment|/// \brief Strips off any unneeded pointer casts, all-zero GEPs and aliases
comment|/// from the specified value, returning the original uncasted value.
comment|///
comment|/// If this is called on a non-pointer value, it returns 'this'.
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
comment|/// \brief Strips off any unneeded pointer casts and all-zero GEPs from the
comment|/// specified value, returning the original uncasted value.
comment|///
comment|/// If this is called on a non-pointer value, it returns 'this'.
name|Value
modifier|*
name|stripPointerCastsNoFollowAliases
parameter_list|()
function_decl|;
specifier|const
name|Value
operator|*
name|stripPointerCastsNoFollowAliases
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
name|stripPointerCastsNoFollowAliases
argument_list|()
return|;
block|}
comment|/// \brief Strips off unneeded pointer casts and all-constant GEPs from the
comment|/// specified value, returning the original pointer value.
comment|///
comment|/// If this is called on a non-pointer value, it returns 'this'.
name|Value
modifier|*
name|stripInBoundsConstantOffsets
parameter_list|()
function_decl|;
specifier|const
name|Value
operator|*
name|stripInBoundsConstantOffsets
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
name|stripInBoundsConstantOffsets
argument_list|()
return|;
block|}
comment|/// \brief Strips like \c stripInBoundsConstantOffsets but also accumulates
comment|/// the constant offset stripped.
comment|///
comment|/// Stores the resulting constant offset stripped into the APInt provided.
comment|/// The provided APInt will be extended or truncated as needed to be the
comment|/// correct bitwidth for an offset of this pointer type.
comment|///
comment|/// If this is called on a non-pointer value, it returns 'this'.
name|Value
modifier|*
name|stripAndAccumulateInBoundsConstantOffsets
parameter_list|(
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
name|APInt
modifier|&
name|Offset
parameter_list|)
function_decl|;
specifier|const
name|Value
modifier|*
name|stripAndAccumulateInBoundsConstantOffsets
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
name|APInt
operator|&
name|Offset
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
name|stripAndAccumulateInBoundsConstantOffsets
argument_list|(
name|DL
argument_list|,
name|Offset
argument_list|)
return|;
block|}
comment|/// \brief Strips off unneeded pointer casts and any in-bounds offsets from
comment|/// the specified value, returning the original pointer value.
comment|///
comment|/// If this is called on a non-pointer value, it returns 'this'.
name|Value
modifier|*
name|stripInBoundsOffsets
parameter_list|()
function_decl|;
specifier|const
name|Value
operator|*
name|stripInBoundsOffsets
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
name|stripInBoundsOffsets
argument_list|()
return|;
block|}
comment|/// isDereferenceablePointer - Test if this value is always a pointer to
comment|/// allocated and suitably aligned memory for a simple load or store.
name|bool
name|isDereferenceablePointer
argument_list|()
specifier|const
expr_stmt|;
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
comment|/// MaximumAlignment - This is the greatest alignment value supported by
comment|/// load, store, and alloca instructions, and global values.
specifier|static
specifier|const
name|unsigned
name|MaximumAlignment
init|=
literal|1u
operator|<<
literal|29
decl_stmt|;
comment|/// mutateType - Mutate the type of this Value to be of the specified type.
comment|/// Note that this is an extremely dangerous operation which can create
comment|/// completely invalid IR very easily.  It is strongly recommended that you
comment|/// recreate IR objects with the right types instead of mutating them in
comment|/// place.
name|void
name|mutateType
parameter_list|(
name|Type
modifier|*
name|Ty
parameter_list|)
block|{
name|VTy
operator|=
name|Ty
expr_stmt|;
block|}
name|protected
label|:
name|unsigned
name|short
name|getSubclassDataFromValue
argument_list|()
specifier|const
block|{
return|return
name|SubclassData
return|;
block|}
name|void
name|setValueSubclassData
parameter_list|(
name|unsigned
name|short
name|D
parameter_list|)
block|{
name|SubclassData
operator|=
name|D
expr_stmt|;
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
expr|struct
name|isa_impl
operator|<
name|Constant
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
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
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|Argument
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
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
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|InlineAsm
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
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
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|Instruction
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
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
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|BasicBlock
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
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
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|Function
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
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
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|GlobalVariable
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
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
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|GlobalAlias
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
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
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|GlobalValue
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
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

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|MDNode
operator|,
name|Value
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Value&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|MDNodeVal
return|;
block|}
end_expr_stmt

begin_comment
unit|};
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
unit|};
comment|// Create wrappers for C Binding types (see CBindingWrapping.h).
end_comment

begin_macro
name|DEFINE_ISA_CONVERSION_FUNCTIONS
argument_list|(
argument|Value
argument_list|,
argument|LLVMValueRef
argument_list|)
end_macro

begin_comment
comment|/* Specialized opaque value conversions.  */
end_comment

begin_function
specifier|inline
name|Value
modifier|*
modifier|*
name|unwrap
parameter_list|(
name|LLVMValueRef
modifier|*
name|Vals
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|Value
operator|*
operator|*
operator|>
operator|(
name|Vals
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
operator|*
operator|*
name|unwrap
argument_list|(
argument|LLVMValueRef *Vals
argument_list|,
argument|unsigned Length
argument_list|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
for|for
control|(
name|LLVMValueRef
modifier|*
name|I
init|=
name|Vals
init|,
modifier|*
name|E
init|=
name|Vals
operator|+
name|Length
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
name|cast
operator|<
name|T
operator|>
operator|(
operator|*
name|I
operator|)
expr_stmt|;
endif|#
directive|endif
operator|(
name|void
operator|)
name|Length
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|reinterpret_cast
operator|<
name|T
operator|*
operator|*
operator|>
operator|(
name|Vals
operator|)
return|;
end_return

begin_function
unit|}  inline
name|LLVMValueRef
modifier|*
name|wrap
parameter_list|(
specifier|const
name|Value
modifier|*
modifier|*
name|Vals
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|LLVMValueRef
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|Value
operator|*
operator|*
operator|>
operator|(
name|Vals
operator|)
operator|)
return|;
block|}
end_function

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

