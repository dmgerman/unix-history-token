begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/DerivedTypes.h - Classes for handling data types ---*- C++ -*-===//
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
comment|// This file contains the declarations of classes that represent "derived
end_comment

begin_comment
comment|// types".  These are things like "arrays of x" or "structure of x, y, z" or
end_comment

begin_comment
comment|// "method returning x taking (y,z) as parameters", etc...
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The implementations of these classes live in the Type.cpp file.
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
name|LLVM_DERIVED_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DERIVED_TYPES_H
end_define

begin_include
include|#
directive|include
file|"llvm/Type.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|template
operator|<
name|class
name|ValType
operator|,
name|class
name|TypeClass
operator|>
name|class
name|TypeMap
expr_stmt|;
name|class
name|FunctionValType
decl_stmt|;
name|class
name|ArrayValType
decl_stmt|;
name|class
name|StructValType
decl_stmt|;
name|class
name|PointerValType
decl_stmt|;
name|class
name|VectorValType
decl_stmt|;
name|class
name|IntegerValType
decl_stmt|;
name|class
name|APInt
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|DerivedType
range|:
name|public
name|Type
block|{
name|friend
name|class
name|Type
block|;
name|protected
operator|:
name|explicit
name|DerivedType
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|TypeID id
argument_list|)
operator|:
name|Type
argument_list|(
argument|C
argument_list|,
argument|id
argument_list|)
block|{}
comment|/// notifyUsesThatTypeBecameConcrete - Notify AbstractTypeUsers of this type
comment|/// that the current type has transitioned from being abstract to being
comment|/// concrete.
comment|///
name|void
name|notifyUsesThatTypeBecameConcrete
argument_list|()
block|;
comment|/// dropAllTypeUses - When this (abstract) type is resolved to be equal to
comment|/// another (more concrete) type, we must eliminate all references to other
comment|/// types, to avoid some circular reference problems.
comment|///
name|void
name|dropAllTypeUses
argument_list|()
block|;
comment|/// unlockedRefineAbstractTypeTo - Internal version of refineAbstractTypeTo
comment|/// that performs no locking.  Only used for internal recursion.
name|void
name|unlockedRefineAbstractTypeTo
argument_list|(
specifier|const
name|Type
operator|*
name|NewType
argument_list|)
block|;
name|public
operator|:
comment|//===--------------------------------------------------------------------===//
comment|// Abstract Type handling methods - These types have special lifetimes, which
comment|// are managed by (add|remove)AbstractTypeUser. See comments in
comment|// AbstractTypeUser.h for more information.
comment|/// refineAbstractTypeTo - This function is used to when it is discovered that
comment|/// the 'this' abstract type is actually equivalent to the NewType specified.
comment|/// This causes all users of 'this' to switch to reference the more concrete
comment|/// type NewType and for 'this' to be deleted.
comment|///
name|void
name|refineAbstractTypeTo
argument_list|(
specifier|const
name|Type
operator|*
name|NewType
argument_list|)
block|;
name|void
name|dump
argument_list|()
specifier|const
block|{
name|Type
operator|::
name|dump
argument_list|()
block|; }
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const DerivedType *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|isDerivedType
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// Class to represent integer types. Note that this class is also used to
comment|/// represent the built-in integer types: Int1Ty, Int8Ty, Int16Ty, Int32Ty and
comment|/// Int64Ty.
comment|/// @brief Integer representation type
name|class
name|IntegerType
operator|:
name|public
name|DerivedType
block|{
name|friend
name|class
name|LLVMContextImpl
block|;
name|protected
operator|:
name|explicit
name|IntegerType
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned NumBits
argument_list|)
operator|:
name|DerivedType
argument_list|(
argument|C
argument_list|,
argument|IntegerTyID
argument_list|)
block|{
name|setSubclassData
argument_list|(
name|NumBits
argument_list|)
block|;   }
name|friend
name|class
name|TypeMap
operator|<
name|IntegerValType
block|,
name|IntegerType
operator|>
block|;
name|public
operator|:
comment|/// This enum is just used to hold constants we need for IntegerType.
expr|enum
block|{
name|MIN_INT_BITS
operator|=
literal|1
block|,
comment|///< Minimum number of bits that can be specified
name|MAX_INT_BITS
operator|=
operator|(
literal|1
operator|<<
literal|23
operator|)
operator|-
literal|1
comment|///< Maximum number of bits that can be specified
comment|///< Note that bit width is stored in the Type classes SubclassData field
comment|///< which has 23 bits. This yields a maximum bit width of 8,388,607 bits.
block|}
block|;
comment|/// This static method is the primary way of constructing an IntegerType.
comment|/// If an IntegerType with the same NumBits value was previously instantiated,
comment|/// that instance will be returned. Otherwise a new one will be created. Only
comment|/// one instance with a given NumBits value is ever created.
comment|/// @brief Get or create an IntegerType instance.
specifier|static
specifier|const
name|IntegerType
operator|*
name|get
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned NumBits
argument_list|)
block|;
comment|/// @brief Get the number of bits in this IntegerType
name|unsigned
name|getBitWidth
argument_list|()
specifier|const
block|{
return|return
name|getSubclassData
argument_list|()
return|;
block|}
comment|/// getBitMask - Return a bitmask with ones set for all of the bits
comment|/// that can be set by an unsigned version of this type.  This is 0xFF for
comment|/// i8, 0xFFFF for i16, etc.
name|uint64_t
name|getBitMask
argument_list|()
specifier|const
block|{
return|return
operator|~
name|uint64_t
argument_list|(
literal|0UL
argument_list|)
operator|>>
operator|(
literal|64
operator|-
name|getBitWidth
argument_list|()
operator|)
return|;
block|}
comment|/// getSignBit - Return a uint64_t with just the most significant bit set (the
comment|/// sign bit, if the value is treated as a signed number).
name|uint64_t
name|getSignBit
argument_list|()
specifier|const
block|{
return|return
literal|1ULL
operator|<<
operator|(
name|getBitWidth
argument_list|()
operator|-
literal|1
operator|)
return|;
block|}
comment|/// For example, this is 0xFF for an 8 bit integer, 0xFFFF for i16, etc.
comment|/// @returns a bit mask with ones set for all the bits of this type.
comment|/// @brief Get a bit mask for this type.
name|APInt
name|getMask
argument_list|()
specifier|const
block|;
comment|/// This method determines if the width of this IntegerType is a power-of-2
comment|/// in terms of 8 bit bytes.
comment|/// @returns true if this is a power-of-2 byte width.
comment|/// @brief Is this a power-of-2 byte-width IntegerType ?
name|bool
name|isPowerOf2ByteWidth
argument_list|()
specifier|const
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const IntegerType *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeID
argument_list|()
operator|==
name|IntegerTyID
return|;
block|}
expr|}
block|;
comment|/// FunctionType - Class to represent function types
comment|///
name|class
name|FunctionType
operator|:
name|public
name|DerivedType
block|{
name|friend
name|class
name|TypeMap
operator|<
name|FunctionValType
block|,
name|FunctionType
operator|>
block|;
name|bool
name|isVarArgs
block|;
name|FunctionType
argument_list|(
specifier|const
name|FunctionType
operator|&
argument_list|)
block|;
comment|// Do not implement
specifier|const
name|FunctionType
operator|&
name|operator
operator|=
operator|(
specifier|const
name|FunctionType
operator|&
operator|)
block|;
comment|// Do not implement
name|FunctionType
argument_list|(
argument|const Type *Result
argument_list|,
argument|const std::vector<const Type*>&Params
argument_list|,
argument|bool IsVarArgs
argument_list|)
block|;
name|public
operator|:
comment|/// FunctionType::get - This static method is the primary way of constructing
comment|/// a FunctionType.
comment|///
specifier|static
name|FunctionType
operator|*
name|get
argument_list|(
argument|const Type *Result
argument_list|,
comment|///< The result type
argument|const std::vector<const Type*>&Params
argument_list|,
comment|///< The types of the parameters
argument|bool isVarArg
comment|///< Whether this is a variable argument length function
argument_list|)
block|;
comment|/// FunctionType::get - Create a FunctionType taking no parameters.
comment|///
specifier|static
name|FunctionType
operator|*
name|get
argument_list|(
argument|const Type *Result
argument_list|,
comment|///< The result type
argument|bool isVarArg
comment|///< Whether this is a variable argument length function
argument_list|)
block|{
return|return
name|get
argument_list|(
name|Result
argument_list|,
name|std
operator|::
name|vector
operator|<
specifier|const
name|Type
operator|*
operator|>
operator|(
operator|)
argument_list|,
name|isVarArg
argument_list|)
return|;
block|}
comment|/// isValidReturnType - Return true if the specified type is valid as a return
comment|/// type.
specifier|static
name|bool
name|isValidReturnType
argument_list|(
specifier|const
name|Type
operator|*
name|RetTy
argument_list|)
block|;
comment|/// isValidArgumentType - Return true if the specified type is valid as an
comment|/// argument type.
specifier|static
name|bool
name|isValidArgumentType
argument_list|(
specifier|const
name|Type
operator|*
name|ArgTy
argument_list|)
block|;
specifier|inline
name|bool
name|isVarArg
argument_list|()
specifier|const
block|{
return|return
name|isVarArgs
return|;
block|}
specifier|inline
specifier|const
name|Type
operator|*
name|getReturnType
argument_list|()
specifier|const
block|{
return|return
name|ContainedTys
index|[
literal|0
index|]
return|;
block|}
typedef|typedef
name|Type
operator|::
name|subtype_iterator
name|param_iterator
expr_stmt|;
name|param_iterator
name|param_begin
argument_list|()
specifier|const
block|{
return|return
name|ContainedTys
operator|+
literal|1
return|;
block|}
name|param_iterator
name|param_end
argument_list|()
specifier|const
block|{
return|return
operator|&
name|ContainedTys
index|[
name|NumContainedTys
index|]
return|;
block|}
comment|// Parameter type accessors...
specifier|const
name|Type
operator|*
name|getParamType
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|ContainedTys
index|[
name|i
operator|+
literal|1
index|]
return|;
block|}
comment|/// getNumParams - Return the number of fixed parameters this function type
comment|/// requires.  This does not consider varargs.
comment|///
name|unsigned
name|getNumParams
argument_list|()
specifier|const
block|{
return|return
name|NumContainedTys
operator|-
literal|1
return|;
block|}
comment|// Implement the AbstractTypeUser interface.
name|virtual
name|void
name|refineAbstractType
argument_list|(
specifier|const
name|DerivedType
operator|*
name|OldTy
argument_list|,
specifier|const
name|Type
operator|*
name|NewTy
argument_list|)
block|;
name|virtual
name|void
name|typeBecameConcrete
argument_list|(
specifier|const
name|DerivedType
operator|*
name|AbsTy
argument_list|)
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const FunctionType *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeID
argument_list|()
operator|==
name|FunctionTyID
return|;
block|}
expr|}
block|;
comment|/// CompositeType - Common super class of ArrayType, StructType, PointerType
comment|/// and VectorType
name|class
name|CompositeType
operator|:
name|public
name|DerivedType
block|{
name|protected
operator|:
specifier|inline
name|explicit
name|CompositeType
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|TypeID id
argument_list|)
operator|:
name|DerivedType
argument_list|(
argument|C
argument_list|,
argument|id
argument_list|)
block|{ }
name|public
operator|:
comment|/// getTypeAtIndex - Given an index value into the type, return the type of
comment|/// the element.
comment|///
name|virtual
specifier|const
name|Type
operator|*
name|getTypeAtIndex
argument_list|(
argument|const Value *V
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
specifier|const
name|Type
operator|*
name|getTypeAtIndex
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|indexValid
argument_list|(
argument|const Value *V
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|indexValid
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const CompositeType *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeID
argument_list|()
operator|==
name|ArrayTyID
operator|||
name|T
operator|->
name|getTypeID
argument_list|()
operator|==
name|StructTyID
operator|||
name|T
operator|->
name|getTypeID
argument_list|()
operator|==
name|PointerTyID
operator|||
name|T
operator|->
name|getTypeID
argument_list|()
operator|==
name|VectorTyID
return|;
block|}
expr|}
block|;
comment|/// StructType - Class to represent struct types
comment|///
name|class
name|StructType
operator|:
name|public
name|CompositeType
block|{
name|friend
name|class
name|TypeMap
operator|<
name|StructValType
block|,
name|StructType
operator|>
block|;
name|StructType
argument_list|(
specifier|const
name|StructType
operator|&
argument_list|)
block|;
comment|// Do not implement
specifier|const
name|StructType
operator|&
name|operator
operator|=
operator|(
specifier|const
name|StructType
operator|&
operator|)
block|;
comment|// Do not implement
name|StructType
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|const std::vector<const Type*>&Types
argument_list|,
argument|bool isPacked
argument_list|)
block|;
name|public
operator|:
comment|/// StructType::get - This static method is the primary way to create a
comment|/// StructType.
comment|///
specifier|static
name|StructType
operator|*
name|get
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|const std::vector<const Type*>&Params
argument_list|,
argument|bool isPacked=false
argument_list|)
block|;
comment|/// StructType::get - Create an empty structure type.
comment|///
specifier|static
name|StructType
operator|*
name|get
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|bool isPacked=false
argument_list|)
block|{
return|return
name|get
argument_list|(
name|Context
argument_list|,
name|std
operator|::
name|vector
operator|<
specifier|const
name|Type
operator|*
operator|>
operator|(
operator|)
argument_list|,
name|isPacked
argument_list|)
return|;
block|}
comment|/// StructType::get - This static method is a convenience method for
comment|/// creating structure types by specifying the elements as arguments.
comment|/// Note that this method always returns a non-packed struct.  To get
comment|/// an empty struct, pass NULL, NULL.
specifier|static
name|StructType
operator|*
name|get
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|const Type *type
argument_list|,
argument|...
argument_list|)
name|END_WITH_NULL
block|;
comment|/// isValidElementType - Return true if the specified type is valid as a
comment|/// element type.
specifier|static
name|bool
name|isValidElementType
argument_list|(
specifier|const
name|Type
operator|*
name|ElemTy
argument_list|)
block|;
comment|// Iterator access to the elements
typedef|typedef
name|Type
operator|::
name|subtype_iterator
name|element_iterator
expr_stmt|;
name|element_iterator
name|element_begin
argument_list|()
specifier|const
block|{
return|return
name|ContainedTys
return|;
block|}
name|element_iterator
name|element_end
argument_list|()
specifier|const
block|{
return|return
operator|&
name|ContainedTys
index|[
name|NumContainedTys
index|]
return|;
block|}
comment|// Random access to the elements
name|unsigned
name|getNumElements
argument_list|()
specifier|const
block|{
return|return
name|NumContainedTys
return|;
block|}
specifier|const
name|Type
operator|*
name|getElementType
argument_list|(
argument|unsigned N
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|N
operator|<
name|NumContainedTys
operator|&&
literal|"Element number out of range!"
argument_list|)
block|;
return|return
name|ContainedTys
index|[
name|N
index|]
return|;
block|}
comment|/// getTypeAtIndex - Given an index value into the type, return the type of
comment|/// the element.  For a structure type, this must be a constant value...
comment|///
name|virtual
specifier|const
name|Type
operator|*
name|getTypeAtIndex
argument_list|(
argument|const Value *V
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|Type
operator|*
name|getTypeAtIndex
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|indexValid
argument_list|(
argument|const Value *V
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|indexValid
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|;
comment|// Implement the AbstractTypeUser interface.
name|virtual
name|void
name|refineAbstractType
argument_list|(
specifier|const
name|DerivedType
operator|*
name|OldTy
argument_list|,
specifier|const
name|Type
operator|*
name|NewTy
argument_list|)
block|;
name|virtual
name|void
name|typeBecameConcrete
argument_list|(
specifier|const
name|DerivedType
operator|*
name|AbsTy
argument_list|)
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const StructType *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeID
argument_list|()
operator|==
name|StructTyID
return|;
block|}
name|bool
name|isPacked
argument_list|()
specifier|const
block|{
return|return
operator|(
literal|0
operator|!=
name|getSubclassData
argument_list|()
operator|)
operator|?
name|true
operator|:
name|false
return|;
block|}
expr|}
block|;
comment|/// SequentialType - This is the superclass of the array, pointer and vector
comment|/// type classes.  All of these represent "arrays" in memory.  The array type
comment|/// represents a specifically sized array, pointer types are unsized/unknown
comment|/// size arrays, vector types represent specifically sized arrays that
comment|/// allow for use of SIMD instructions.  SequentialType holds the common
comment|/// features of all, which stem from the fact that all three lay their
comment|/// components out in memory identically.
comment|///
name|class
name|SequentialType
operator|:
name|public
name|CompositeType
block|{
name|PATypeHandle
name|ContainedType
block|;
comment|///< Storage for the single contained type
name|SequentialType
argument_list|(
specifier|const
name|SequentialType
operator|&
argument_list|)
block|;
comment|// Do not implement!
specifier|const
name|SequentialType
operator|&
name|operator
operator|=
operator|(
specifier|const
name|SequentialType
operator|&
operator|)
block|;
comment|// Do not implement!
comment|// avoiding warning: 'this' : used in base member initializer list
name|SequentialType
operator|*
name|this_
argument_list|()
block|{
return|return
name|this
return|;
block|}
name|protected
operator|:
name|SequentialType
argument_list|(
argument|TypeID TID
argument_list|,
argument|const Type *ElType
argument_list|)
operator|:
name|CompositeType
argument_list|(
name|ElType
operator|->
name|getContext
argument_list|()
argument_list|,
name|TID
argument_list|)
block|,
name|ContainedType
argument_list|(
argument|ElType
argument_list|,
argument|this_()
argument_list|)
block|{
name|ContainedTys
operator|=
operator|&
name|ContainedType
block|;
name|NumContainedTys
operator|=
literal|1
block|;   }
name|public
operator|:
specifier|inline
specifier|const
name|Type
operator|*
name|getElementType
argument_list|()
specifier|const
block|{
return|return
name|ContainedTys
index|[
literal|0
index|]
return|;
block|}
name|virtual
name|bool
name|indexValid
argument_list|(
argument|const Value *V
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|indexValid
argument_list|(
argument|unsigned
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// getTypeAtIndex - Given an index value into the type, return the type of
comment|/// the element.  For sequential types, there is only one subtype...
comment|///
name|virtual
specifier|const
name|Type
operator|*
name|getTypeAtIndex
argument_list|(
argument|const Value *
argument_list|)
specifier|const
block|{
return|return
name|ContainedTys
index|[
literal|0
index|]
return|;
block|}
name|virtual
specifier|const
name|Type
operator|*
name|getTypeAtIndex
argument_list|(
argument|unsigned
argument_list|)
specifier|const
block|{
return|return
name|ContainedTys
index|[
literal|0
index|]
return|;
block|}
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SequentialType *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeID
argument_list|()
operator|==
name|ArrayTyID
operator|||
name|T
operator|->
name|getTypeID
argument_list|()
operator|==
name|PointerTyID
operator|||
name|T
operator|->
name|getTypeID
argument_list|()
operator|==
name|VectorTyID
return|;
block|}
expr|}
block|;
comment|/// ArrayType - Class to represent array types
comment|///
name|class
name|ArrayType
operator|:
name|public
name|SequentialType
block|{
name|friend
name|class
name|TypeMap
operator|<
name|ArrayValType
block|,
name|ArrayType
operator|>
block|;
name|uint64_t
name|NumElements
block|;
name|ArrayType
argument_list|(
specifier|const
name|ArrayType
operator|&
argument_list|)
block|;
comment|// Do not implement
specifier|const
name|ArrayType
operator|&
name|operator
operator|=
operator|(
specifier|const
name|ArrayType
operator|&
operator|)
block|;
comment|// Do not implement
name|ArrayType
argument_list|(
argument|const Type *ElType
argument_list|,
argument|uint64_t NumEl
argument_list|)
block|;
name|public
operator|:
comment|/// ArrayType::get - This static method is the primary way to construct an
comment|/// ArrayType
comment|///
specifier|static
name|ArrayType
operator|*
name|get
argument_list|(
argument|const Type *ElementType
argument_list|,
argument|uint64_t NumElements
argument_list|)
block|;
comment|/// isValidElementType - Return true if the specified type is valid as a
comment|/// element type.
specifier|static
name|bool
name|isValidElementType
argument_list|(
specifier|const
name|Type
operator|*
name|ElemTy
argument_list|)
block|;
specifier|inline
name|uint64_t
name|getNumElements
argument_list|()
specifier|const
block|{
return|return
name|NumElements
return|;
block|}
comment|// Implement the AbstractTypeUser interface.
name|virtual
name|void
name|refineAbstractType
argument_list|(
specifier|const
name|DerivedType
operator|*
name|OldTy
argument_list|,
specifier|const
name|Type
operator|*
name|NewTy
argument_list|)
block|;
name|virtual
name|void
name|typeBecameConcrete
argument_list|(
specifier|const
name|DerivedType
operator|*
name|AbsTy
argument_list|)
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const ArrayType *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeID
argument_list|()
operator|==
name|ArrayTyID
return|;
block|}
expr|}
block|;
comment|/// VectorType - Class to represent vector types
comment|///
name|class
name|VectorType
operator|:
name|public
name|SequentialType
block|{
name|friend
name|class
name|TypeMap
operator|<
name|VectorValType
block|,
name|VectorType
operator|>
block|;
name|unsigned
name|NumElements
block|;
name|VectorType
argument_list|(
specifier|const
name|VectorType
operator|&
argument_list|)
block|;
comment|// Do not implement
specifier|const
name|VectorType
operator|&
name|operator
operator|=
operator|(
specifier|const
name|VectorType
operator|&
operator|)
block|;
comment|// Do not implement
name|VectorType
argument_list|(
argument|const Type *ElType
argument_list|,
argument|unsigned NumEl
argument_list|)
block|;
name|public
operator|:
comment|/// VectorType::get - This static method is the primary way to construct an
comment|/// VectorType
comment|///
specifier|static
name|VectorType
operator|*
name|get
argument_list|(
argument|const Type *ElementType
argument_list|,
argument|unsigned NumElements
argument_list|)
block|;
comment|/// VectorType::getInteger - This static method gets a VectorType with the
comment|/// same number of elements as the input type, and the element type is an
comment|/// integer type of the same width as the input element type.
comment|///
specifier|static
name|VectorType
operator|*
name|getInteger
argument_list|(
argument|const VectorType *VTy
argument_list|)
block|{
name|unsigned
name|EltBits
operator|=
name|VTy
operator|->
name|getElementType
argument_list|()
operator|->
name|getPrimitiveSizeInBits
argument_list|()
block|;
specifier|const
name|Type
operator|*
name|EltTy
operator|=
name|IntegerType
operator|::
name|get
argument_list|(
name|VTy
operator|->
name|getContext
argument_list|()
argument_list|,
name|EltBits
argument_list|)
block|;
return|return
name|VectorType
operator|::
name|get
argument_list|(
name|EltTy
argument_list|,
name|VTy
operator|->
name|getNumElements
argument_list|()
argument_list|)
return|;
block|}
comment|/// VectorType::getExtendedElementVectorType - This static method is like
comment|/// getInteger except that the element types are twice as wide as the
comment|/// elements in the input type.
comment|///
specifier|static
name|VectorType
operator|*
name|getExtendedElementVectorType
argument_list|(
argument|const VectorType *VTy
argument_list|)
block|{
name|unsigned
name|EltBits
operator|=
name|VTy
operator|->
name|getElementType
argument_list|()
operator|->
name|getPrimitiveSizeInBits
argument_list|()
block|;
specifier|const
name|Type
operator|*
name|EltTy
operator|=
name|IntegerType
operator|::
name|get
argument_list|(
name|VTy
operator|->
name|getContext
argument_list|()
argument_list|,
name|EltBits
operator|*
literal|2
argument_list|)
block|;
return|return
name|VectorType
operator|::
name|get
argument_list|(
name|EltTy
argument_list|,
name|VTy
operator|->
name|getNumElements
argument_list|()
argument_list|)
return|;
block|}
comment|/// VectorType::getTruncatedElementVectorType - This static method is like
comment|/// getInteger except that the element types are half as wide as the
comment|/// elements in the input type.
comment|///
specifier|static
name|VectorType
operator|*
name|getTruncatedElementVectorType
argument_list|(
argument|const VectorType *VTy
argument_list|)
block|{
name|unsigned
name|EltBits
operator|=
name|VTy
operator|->
name|getElementType
argument_list|()
operator|->
name|getPrimitiveSizeInBits
argument_list|()
block|;
name|assert
argument_list|(
operator|(
name|EltBits
operator|&
literal|1
operator|)
operator|==
literal|0
operator|&&
literal|"Cannot truncate vector element with odd bit-width"
argument_list|)
block|;
specifier|const
name|Type
operator|*
name|EltTy
operator|=
name|IntegerType
operator|::
name|get
argument_list|(
name|VTy
operator|->
name|getContext
argument_list|()
argument_list|,
name|EltBits
operator|/
literal|2
argument_list|)
block|;
return|return
name|VectorType
operator|::
name|get
argument_list|(
name|EltTy
argument_list|,
name|VTy
operator|->
name|getNumElements
argument_list|()
argument_list|)
return|;
block|}
comment|/// isValidElementType - Return true if the specified type is valid as a
comment|/// element type.
specifier|static
name|bool
name|isValidElementType
argument_list|(
specifier|const
name|Type
operator|*
name|ElemTy
argument_list|)
block|;
comment|/// @brief Return the number of elements in the Vector type.
specifier|inline
name|unsigned
name|getNumElements
argument_list|()
specifier|const
block|{
return|return
name|NumElements
return|;
block|}
comment|/// @brief Return the number of bits in the Vector type.
specifier|inline
name|unsigned
name|getBitWidth
argument_list|()
specifier|const
block|{
return|return
name|NumElements
operator|*
name|getElementType
argument_list|()
operator|->
name|getPrimitiveSizeInBits
argument_list|()
return|;
block|}
comment|// Implement the AbstractTypeUser interface.
name|virtual
name|void
name|refineAbstractType
argument_list|(
specifier|const
name|DerivedType
operator|*
name|OldTy
argument_list|,
specifier|const
name|Type
operator|*
name|NewTy
argument_list|)
block|;
name|virtual
name|void
name|typeBecameConcrete
argument_list|(
specifier|const
name|DerivedType
operator|*
name|AbsTy
argument_list|)
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const VectorType *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeID
argument_list|()
operator|==
name|VectorTyID
return|;
block|}
expr|}
block|;
comment|/// PointerType - Class to represent pointers
comment|///
name|class
name|PointerType
operator|:
name|public
name|SequentialType
block|{
name|friend
name|class
name|TypeMap
operator|<
name|PointerValType
block|,
name|PointerType
operator|>
block|;
name|unsigned
name|AddressSpace
block|;
name|PointerType
argument_list|(
specifier|const
name|PointerType
operator|&
argument_list|)
block|;
comment|// Do not implement
specifier|const
name|PointerType
operator|&
name|operator
operator|=
operator|(
specifier|const
name|PointerType
operator|&
operator|)
block|;
comment|// Do not implement
name|explicit
name|PointerType
argument_list|(
argument|const Type *ElType
argument_list|,
argument|unsigned AddrSpace
argument_list|)
block|;
name|public
operator|:
comment|/// PointerType::get - This constructs a pointer to an object of the specified
comment|/// type in a numbered address space.
specifier|static
name|PointerType
operator|*
name|get
argument_list|(
argument|const Type *ElementType
argument_list|,
argument|unsigned AddressSpace
argument_list|)
block|;
comment|/// PointerType::getUnqual - This constructs a pointer to an object of the
comment|/// specified type in the generic address space (address space zero).
specifier|static
name|PointerType
operator|*
name|getUnqual
argument_list|(
argument|const Type *ElementType
argument_list|)
block|{
return|return
name|PointerType
operator|::
name|get
argument_list|(
name|ElementType
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// isValidElementType - Return true if the specified type is valid as a
comment|/// element type.
specifier|static
name|bool
name|isValidElementType
argument_list|(
specifier|const
name|Type
operator|*
name|ElemTy
argument_list|)
block|;
comment|/// @brief Return the address space of the Pointer type.
specifier|inline
name|unsigned
name|getAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|AddressSpace
return|;
block|}
comment|// Implement the AbstractTypeUser interface.
name|virtual
name|void
name|refineAbstractType
argument_list|(
specifier|const
name|DerivedType
operator|*
name|OldTy
argument_list|,
specifier|const
name|Type
operator|*
name|NewTy
argument_list|)
block|;
name|virtual
name|void
name|typeBecameConcrete
argument_list|(
specifier|const
name|DerivedType
operator|*
name|AbsTy
argument_list|)
block|;
comment|// Implement support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const PointerType *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeID
argument_list|()
operator|==
name|PointerTyID
return|;
block|}
expr|}
block|;
comment|/// OpaqueType - Class to represent abstract types
comment|///
name|class
name|OpaqueType
operator|:
name|public
name|DerivedType
block|{
name|OpaqueType
argument_list|(
specifier|const
name|OpaqueType
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
specifier|const
name|OpaqueType
operator|&
name|operator
operator|=
operator|(
specifier|const
name|OpaqueType
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT
name|OpaqueType
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|)
block|;
name|public
operator|:
comment|/// OpaqueType::get - Static factory method for the OpaqueType class...
comment|///
specifier|static
name|OpaqueType
operator|*
name|get
argument_list|(
argument|LLVMContext&C
argument_list|)
block|{
return|return
name|new
name|OpaqueType
argument_list|(
name|C
argument_list|)
return|;
comment|// All opaque types are distinct
block|}
comment|// Implement support for type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const OpaqueType *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeID
argument_list|()
operator|==
name|OpaqueTyID
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

