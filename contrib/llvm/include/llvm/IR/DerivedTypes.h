begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/DerivedTypes.h - Classes for handling data types ----*- C++ -*-===//
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
comment|// "function returning x taking (y,z) as parameters", etc...
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
name|LLVM_IR_DERIVEDTYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_DERIVEDTYPES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|APInt
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
comment|/// Class to represent integer types. Note that this class is also used to
comment|/// represent the built-in integer types: Int1Ty, Int8Ty, Int16Ty, Int32Ty and
comment|/// Int64Ty.
comment|/// @brief Integer representation type
name|class
name|IntegerType
range|:
name|public
name|Type
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
name|Type
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
literal|24
operator|)
operator|-
literal|1
comment|///< Maximum number of bits that can be specified
comment|///< Note that bit width is stored in the Type classes SubclassData field
comment|///< which has 24 bits. This yields a maximum bit width of 16,777,215
comment|///< bits.
block|}
block|;
comment|/// This static method is the primary way of constructing an IntegerType.
comment|/// If an IntegerType with the same NumBits value was previously instantiated,
comment|/// that instance will be returned. Otherwise a new one will be created. Only
comment|/// one instance with a given NumBits value is ever created.
comment|/// @brief Get or create an IntegerType instance.
specifier|static
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
comment|/// Return a bitmask with ones set for all of the bits that can be set by an
comment|/// unsigned version of this type. This is 0xFF for i8, 0xFFFF for i16, etc.
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
comment|/// Return a uint64_t with just the most significant bit set (the sign bit, if
comment|/// the value is treated as a signed number).
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
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast.
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
name|unsigned
name|Type
operator|::
name|getIntegerBitWidth
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|IntegerType
operator|>
operator|(
name|this
operator|)
operator|->
name|getBitWidth
argument_list|()
return|;
block|}
comment|/// Class to represent function types
comment|///
name|class
name|FunctionType
operator|:
name|public
name|Type
block|{
name|FunctionType
argument_list|(
argument|Type *Result
argument_list|,
argument|ArrayRef<Type*> Params
argument_list|,
argument|bool IsVarArgs
argument_list|)
block|;
name|public
operator|:
name|FunctionType
argument_list|(
specifier|const
name|FunctionType
operator|&
argument_list|)
operator|=
name|delete
block|;
name|FunctionType
operator|&
name|operator
operator|=
operator|(
specifier|const
name|FunctionType
operator|&
operator|)
operator|=
name|delete
block|;
comment|/// This static method is the primary way of constructing a FunctionType.
specifier|static
name|FunctionType
operator|*
name|get
argument_list|(
argument|Type *Result
argument_list|,
argument|ArrayRef<Type*> Params
argument_list|,
argument|bool isVarArg
argument_list|)
block|;
comment|/// Create a FunctionType taking no parameters.
specifier|static
name|FunctionType
operator|*
name|get
argument_list|(
argument|Type *Result
argument_list|,
argument|bool isVarArg
argument_list|)
block|;
comment|/// Return true if the specified type is valid as a return type.
specifier|static
name|bool
name|isValidReturnType
argument_list|(
name|Type
operator|*
name|RetTy
argument_list|)
block|;
comment|/// Return true if the specified type is valid as an argument type.
specifier|static
name|bool
name|isValidArgumentType
argument_list|(
name|Type
operator|*
name|ArgTy
argument_list|)
block|;
name|bool
name|isVarArg
argument_list|()
specifier|const
block|{
return|return
name|getSubclassData
argument_list|()
operator|!=
literal|0
return|;
block|}
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
name|using
name|param_iterator
operator|=
name|Type
operator|::
name|subtype_iterator
block|;
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
name|ArrayRef
operator|<
name|Type
operator|*
operator|>
name|params
argument_list|()
specifier|const
block|{
return|return
name|makeArrayRef
argument_list|(
name|param_begin
argument_list|()
argument_list|,
name|param_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// Parameter type accessors.
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
comment|/// Return the number of fixed parameters this function type requires.
comment|/// This does not consider varargs.
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
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast.
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
name|static_assert
argument_list|(
name|alignof
argument_list|(
name|FunctionType
argument_list|)
operator|>=
name|alignof
argument_list|(
name|Type
operator|*
argument_list|)
argument_list|,
literal|"Alignment sufficient for objects appended to FunctionType"
argument_list|)
block|;
name|bool
name|Type
operator|::
name|isFunctionVarArg
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|FunctionType
operator|>
operator|(
name|this
operator|)
operator|->
name|isVarArg
argument_list|()
return|;
block|}
name|Type
operator|*
name|Type
operator|::
name|getFunctionParamType
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|cast
operator|<
name|FunctionType
operator|>
operator|(
name|this
operator|)
operator|->
name|getParamType
argument_list|(
name|i
argument_list|)
return|;
block|}
name|unsigned
name|Type
operator|::
name|getFunctionNumParams
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|FunctionType
operator|>
operator|(
name|this
operator|)
operator|->
name|getNumParams
argument_list|()
return|;
block|}
comment|/// Common super class of ArrayType, StructType and VectorType.
name|class
name|CompositeType
operator|:
name|public
name|Type
block|{
name|protected
operator|:
name|explicit
name|CompositeType
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|TypeID tid
argument_list|)
operator|:
name|Type
argument_list|(
argument|C
argument_list|,
argument|tid
argument_list|)
block|{}
name|public
operator|:
comment|/// Given an index value into the type, return the type of the element.
name|Type
operator|*
name|getTypeAtIndex
argument_list|(
argument|const Value *V
argument_list|)
specifier|const
block|;
name|Type
operator|*
name|getTypeAtIndex
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|;
name|bool
name|indexValid
argument_list|(
argument|const Value *V
argument_list|)
specifier|const
block|;
name|bool
name|indexValid
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast.
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
name|VectorTyID
return|;
block|}
expr|}
block|;
comment|/// Class to represent struct types. There are two different kinds of struct
comment|/// types: Literal structs and Identified structs.
comment|///
comment|/// Literal struct types (e.g. { i32, i32 }) are uniqued structurally, and must
comment|/// always have a body when created.  You can get one of these by using one of
comment|/// the StructType::get() forms.
comment|///
comment|/// Identified structs (e.g. %foo or %42) may optionally have a name and are not
comment|/// uniqued.  The names for identified structs are managed at the LLVMContext
comment|/// level, so there can only be a single identified struct with a given name in
comment|/// a particular LLVMContext.  Identified structs may also optionally be opaque
comment|/// (have no body specified).  You get one of these by using one of the
comment|/// StructType::create() forms.
comment|///
comment|/// Independent of what kind of struct you have, the body of a struct type are
comment|/// laid out in memory consequtively with the elements directly one after the
comment|/// other (if the struct is packed) or (if not packed) with padding between the
comment|/// elements as defined by DataLayout (which is required to match what the code
comment|/// generator for a target expects).
comment|///
name|class
name|StructType
operator|:
name|public
name|CompositeType
block|{
name|StructType
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|)
operator|:
name|CompositeType
argument_list|(
argument|C
argument_list|,
argument|StructTyID
argument_list|)
block|{}
expr|enum
block|{
comment|/// This is the contents of the SubClassData field.
name|SCDB_HasBody
operator|=
literal|1
block|,
name|SCDB_Packed
operator|=
literal|2
block|,
name|SCDB_IsLiteral
operator|=
literal|4
block|,
name|SCDB_IsSized
operator|=
literal|8
block|}
block|;
comment|/// For a named struct that actually has a name, this is a pointer to the
comment|/// symbol table entry (maintained by LLVMContext) for the struct.
comment|/// This is null if the type is an literal struct or if it is a identified
comment|/// type that has an empty name.
name|void
operator|*
name|SymbolTableEntry
operator|=
name|nullptr
block|;
name|public
operator|:
name|StructType
argument_list|(
specifier|const
name|StructType
operator|&
argument_list|)
operator|=
name|delete
block|;
name|StructType
operator|&
name|operator
operator|=
operator|(
specifier|const
name|StructType
operator|&
operator|)
operator|=
name|delete
block|;
comment|/// This creates an identified struct.
specifier|static
name|StructType
operator|*
name|create
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|StringRef Name
argument_list|)
block|;
specifier|static
name|StructType
operator|*
name|create
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|)
block|;
specifier|static
name|StructType
operator|*
name|create
argument_list|(
argument|ArrayRef<Type *> Elements
argument_list|,
argument|StringRef Name
argument_list|,
argument|bool isPacked = false
argument_list|)
block|;
specifier|static
name|StructType
operator|*
name|create
argument_list|(
name|ArrayRef
operator|<
name|Type
operator|*
operator|>
name|Elements
argument_list|)
block|;
specifier|static
name|StructType
operator|*
name|create
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|ArrayRef<Type *> Elements
argument_list|,
argument|StringRef Name
argument_list|,
argument|bool isPacked = false
argument_list|)
block|;
specifier|static
name|StructType
operator|*
name|create
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|Type
operator|*
operator|>
name|Elements
argument_list|)
block|;
name|template
operator|<
name|class
operator|...
name|Tys
operator|>
specifier|static
name|typename
name|std
operator|::
name|enable_if
operator|<
name|are_base_of
operator|<
name|Type
block|,
name|Tys
operator|...
operator|>
operator|::
name|value
block|,
name|StructType
operator|*
operator|>
operator|::
name|type
name|create
argument_list|(
argument|StringRef Name
argument_list|,
argument|Type *elt1
argument_list|,
argument|Tys *... elts
argument_list|)
block|{
name|assert
argument_list|(
name|elt1
operator|&&
literal|"Cannot create a struct type with no elements with this"
argument_list|)
block|;
name|SmallVector
operator|<
name|llvm
operator|::
name|Type
operator|*
block|,
literal|8
operator|>
name|StructFields
argument_list|(
block|{
name|elt1
block|,
name|elts
operator|...
block|}
argument_list|)
block|;
return|return
name|create
argument_list|(
name|StructFields
argument_list|,
name|Name
argument_list|)
return|;
block|}
comment|/// This static method is the primary way to create a literal StructType.
specifier|static
name|StructType
operator|*
name|get
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|ArrayRef<Type*> Elements
argument_list|,
argument|bool isPacked = false
argument_list|)
block|;
comment|/// Create an empty structure type.
specifier|static
name|StructType
operator|*
name|get
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|bool isPacked = false
argument_list|)
block|;
comment|/// This static method is a convenience method for creating structure types by
comment|/// specifying the elements as arguments. Note that this method always returns
comment|/// a non-packed struct, and requires at least one element type.
name|template
operator|<
name|class
operator|...
name|Tys
operator|>
specifier|static
name|typename
name|std
operator|::
name|enable_if
operator|<
name|are_base_of
operator|<
name|Type
block|,
name|Tys
operator|...
operator|>
operator|::
name|value
block|,
name|StructType
operator|*
operator|>
operator|::
name|type
name|get
argument_list|(
argument|Type *elt1
argument_list|,
argument|Tys *... elts
argument_list|)
block|{
name|assert
argument_list|(
name|elt1
operator|&&
literal|"Cannot create a struct type with no elements with this"
argument_list|)
block|;
name|LLVMContext
operator|&
name|Ctx
operator|=
name|elt1
operator|->
name|getContext
argument_list|()
block|;
name|SmallVector
operator|<
name|llvm
operator|::
name|Type
operator|*
block|,
literal|8
operator|>
name|StructFields
argument_list|(
block|{
name|elt1
block|,
name|elts
operator|...
block|}
argument_list|)
block|;
return|return
name|llvm
operator|::
name|StructType
operator|::
name|get
argument_list|(
name|Ctx
argument_list|,
name|StructFields
argument_list|)
return|;
block|}
name|bool
name|isPacked
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getSubclassData
argument_list|()
operator|&
name|SCDB_Packed
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// Return true if this type is uniqued by structural equivalence, false if it
comment|/// is a struct definition.
name|bool
name|isLiteral
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getSubclassData
argument_list|()
operator|&
name|SCDB_IsLiteral
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// Return true if this is a type with an identity that has no body specified
comment|/// yet. These prints as 'opaque' in .ll files.
name|bool
name|isOpaque
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getSubclassData
argument_list|()
operator|&
name|SCDB_HasBody
operator|)
operator|==
literal|0
return|;
block|}
comment|/// isSized - Return true if this is a sized type.
name|bool
name|isSized
argument_list|(
argument|SmallPtrSetImpl<Type *> *Visited = nullptr
argument_list|)
specifier|const
block|;
comment|/// Return true if this is a named struct that has a non-empty name.
name|bool
name|hasName
argument_list|()
specifier|const
block|{
return|return
name|SymbolTableEntry
operator|!=
name|nullptr
return|;
block|}
comment|/// Return the name for this struct type if it has an identity.
comment|/// This may return an empty string for an unnamed struct type.  Do not call
comment|/// this on an literal type.
name|StringRef
name|getName
argument_list|()
specifier|const
block|;
comment|/// Change the name of this type to the specified name, or to a name with a
comment|/// suffix if there is a collision. Do not call this on an literal type.
name|void
name|setName
argument_list|(
argument|StringRef Name
argument_list|)
block|;
comment|/// Specify a body for an opaque identified type.
name|void
name|setBody
argument_list|(
argument|ArrayRef<Type*> Elements
argument_list|,
argument|bool isPacked = false
argument_list|)
block|;
name|template
operator|<
name|typename
operator|...
name|Tys
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|are_base_of
operator|<
name|Type
block|,
name|Tys
operator|...
operator|>
operator|::
name|value
block|,
name|void
operator|>
operator|::
name|type
name|setBody
argument_list|(
argument|Type *elt1
argument_list|,
argument|Tys *... elts
argument_list|)
block|{
name|assert
argument_list|(
name|elt1
operator|&&
literal|"Cannot create a struct type with no elements with this"
argument_list|)
block|;
name|SmallVector
operator|<
name|llvm
operator|::
name|Type
operator|*
block|,
literal|8
operator|>
name|StructFields
argument_list|(
block|{
name|elt1
block|,
name|elts
operator|...
block|}
argument_list|)
block|;
name|setBody
argument_list|(
name|StructFields
argument_list|)
block|;   }
comment|/// Return true if the specified type is valid as a element type.
specifier|static
name|bool
name|isValidElementType
argument_list|(
name|Type
operator|*
name|ElemTy
argument_list|)
block|;
comment|// Iterator access to the elements.
name|using
name|element_iterator
operator|=
name|Type
operator|::
name|subtype_iterator
block|;
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
name|ArrayRef
operator|<
name|Type
operator|*
operator|>
specifier|const
name|elements
argument_list|()
specifier|const
block|{
return|return
name|makeArrayRef
argument_list|(
name|element_begin
argument_list|()
argument_list|,
name|element_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// Return true if this is layout identical to the specified struct.
name|bool
name|isLayoutIdentical
argument_list|(
argument|StructType *Other
argument_list|)
specifier|const
block|;
comment|/// Random access to the elements
name|unsigned
name|getNumElements
argument_list|()
specifier|const
block|{
return|return
name|NumContainedTys
return|;
block|}
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
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast.
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
expr|}
block|;
name|StringRef
name|Type
operator|::
name|getStructName
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|StructType
operator|>
operator|(
name|this
operator|)
operator|->
name|getName
argument_list|()
return|;
block|}
name|unsigned
name|Type
operator|::
name|getStructNumElements
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|StructType
operator|>
operator|(
name|this
operator|)
operator|->
name|getNumElements
argument_list|()
return|;
block|}
name|Type
operator|*
name|Type
operator|::
name|getStructElementType
argument_list|(
argument|unsigned N
argument_list|)
specifier|const
block|{
return|return
name|cast
operator|<
name|StructType
operator|>
operator|(
name|this
operator|)
operator|->
name|getElementType
argument_list|(
name|N
argument_list|)
return|;
block|}
comment|/// This is the superclass of the array and vector type classes. Both of these
comment|/// represent "arrays" in memory. The array type represents a specifically sized
comment|/// array, and the vector type represents a specifically sized array that allows
comment|/// for use of SIMD instructions. SequentialType holds the common features of
comment|/// both, which stem from the fact that both lay their components out in memory
comment|/// identically.
name|class
name|SequentialType
operator|:
name|public
name|CompositeType
block|{
name|Type
operator|*
name|ContainedType
block|;
comment|///< Storage for the single contained type.
name|uint64_t
name|NumElements
block|;
name|protected
operator|:
name|SequentialType
argument_list|(
argument|TypeID TID
argument_list|,
argument|Type *ElType
argument_list|,
argument|uint64_t NumElements
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
name|ElType
argument_list|)
block|,
name|NumElements
argument_list|(
argument|NumElements
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
name|SequentialType
argument_list|(
specifier|const
name|SequentialType
operator|&
argument_list|)
operator|=
name|delete
block|;
name|SequentialType
operator|&
name|operator
operator|=
operator|(
specifier|const
name|SequentialType
operator|&
operator|)
operator|=
name|delete
block|;
name|uint64_t
name|getNumElements
argument_list|()
specifier|const
block|{
return|return
name|NumElements
return|;
block|}
name|Type
operator|*
name|getElementType
argument_list|()
specifier|const
block|{
return|return
name|ContainedType
return|;
block|}
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast.
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
name|VectorTyID
return|;
block|}
expr|}
block|;
comment|/// Class to represent array types.
name|class
name|ArrayType
operator|:
name|public
name|SequentialType
block|{
name|ArrayType
argument_list|(
argument|Type *ElType
argument_list|,
argument|uint64_t NumEl
argument_list|)
block|;
name|public
operator|:
name|ArrayType
argument_list|(
specifier|const
name|ArrayType
operator|&
argument_list|)
operator|=
name|delete
block|;
name|ArrayType
operator|&
name|operator
operator|=
operator|(
specifier|const
name|ArrayType
operator|&
operator|)
operator|=
name|delete
block|;
comment|/// This static method is the primary way to construct an ArrayType
specifier|static
name|ArrayType
operator|*
name|get
argument_list|(
argument|Type *ElementType
argument_list|,
argument|uint64_t NumElements
argument_list|)
block|;
comment|/// Return true if the specified type is valid as a element type.
specifier|static
name|bool
name|isValidElementType
argument_list|(
name|Type
operator|*
name|ElemTy
argument_list|)
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast.
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
name|uint64_t
name|Type
operator|::
name|getArrayNumElements
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|ArrayType
operator|>
operator|(
name|this
operator|)
operator|->
name|getNumElements
argument_list|()
return|;
block|}
comment|/// Class to represent vector types.
name|class
name|VectorType
operator|:
name|public
name|SequentialType
block|{
name|VectorType
argument_list|(
argument|Type *ElType
argument_list|,
argument|unsigned NumEl
argument_list|)
block|;
name|public
operator|:
name|VectorType
argument_list|(
specifier|const
name|VectorType
operator|&
argument_list|)
operator|=
name|delete
block|;
name|VectorType
operator|&
name|operator
operator|=
operator|(
specifier|const
name|VectorType
operator|&
operator|)
operator|=
name|delete
block|;
comment|/// This static method is the primary way to construct an VectorType.
specifier|static
name|VectorType
operator|*
name|get
argument_list|(
argument|Type *ElementType
argument_list|,
argument|unsigned NumElements
argument_list|)
block|;
comment|/// This static method gets a VectorType with the same number of elements as
comment|/// the input type, and the element type is an integer type of the same width
comment|/// as the input element type.
specifier|static
name|VectorType
operator|*
name|getInteger
argument_list|(
argument|VectorType *VTy
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
name|EltBits
operator|&&
literal|"Element size must be of a non-zero size"
argument_list|)
block|;
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
comment|/// This static method is like getInteger except that the element types are
comment|/// twice as wide as the elements in the input type.
specifier|static
name|VectorType
operator|*
name|getExtendedElementVectorType
argument_list|(
argument|VectorType *VTy
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
comment|/// This static method is like getInteger except that the element types are
comment|/// half as wide as the elements in the input type.
specifier|static
name|VectorType
operator|*
name|getTruncatedElementVectorType
argument_list|(
argument|VectorType *VTy
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
comment|/// This static method returns a VectorType with half as many elements as the
comment|/// input type and the same element type.
specifier|static
name|VectorType
operator|*
name|getHalfElementsVectorType
argument_list|(
argument|VectorType *VTy
argument_list|)
block|{
name|unsigned
name|NumElts
operator|=
name|VTy
operator|->
name|getNumElements
argument_list|()
block|;
name|assert
argument_list|(
operator|(
name|NumElts
operator|&
literal|1
operator|)
operator|==
literal|0
operator|&&
literal|"Cannot halve vector with odd number of elements."
argument_list|)
block|;
return|return
name|VectorType
operator|::
name|get
argument_list|(
name|VTy
operator|->
name|getElementType
argument_list|()
argument_list|,
name|NumElts
operator|/
literal|2
argument_list|)
return|;
block|}
comment|/// This static method returns a VectorType with twice as many elements as the
comment|/// input type and the same element type.
specifier|static
name|VectorType
operator|*
name|getDoubleElementsVectorType
argument_list|(
argument|VectorType *VTy
argument_list|)
block|{
name|unsigned
name|NumElts
operator|=
name|VTy
operator|->
name|getNumElements
argument_list|()
block|;
return|return
name|VectorType
operator|::
name|get
argument_list|(
name|VTy
operator|->
name|getElementType
argument_list|()
argument_list|,
name|NumElts
operator|*
literal|2
argument_list|)
return|;
block|}
comment|/// Return true if the specified type is valid as a element type.
specifier|static
name|bool
name|isValidElementType
argument_list|(
name|Type
operator|*
name|ElemTy
argument_list|)
block|;
comment|/// Return the number of bits in the Vector type.
comment|/// Returns zero when the vector is a vector of pointers.
name|unsigned
name|getBitWidth
argument_list|()
specifier|const
block|{
return|return
name|getNumElements
argument_list|()
operator|*
name|getElementType
argument_list|()
operator|->
name|getPrimitiveSizeInBits
argument_list|()
return|;
block|}
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast.
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
name|unsigned
name|Type
operator|::
name|getVectorNumElements
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|VectorType
operator|>
operator|(
name|this
operator|)
operator|->
name|getNumElements
argument_list|()
return|;
block|}
comment|/// Class to represent pointers.
name|class
name|PointerType
operator|:
name|public
name|Type
block|{
name|explicit
name|PointerType
argument_list|(
argument|Type *ElType
argument_list|,
argument|unsigned AddrSpace
argument_list|)
block|;
name|Type
operator|*
name|PointeeTy
block|;
name|public
operator|:
name|PointerType
argument_list|(
specifier|const
name|PointerType
operator|&
argument_list|)
operator|=
name|delete
block|;
name|PointerType
operator|&
name|operator
operator|=
operator|(
specifier|const
name|PointerType
operator|&
operator|)
operator|=
name|delete
block|;
comment|/// This constructs a pointer to an object of the specified type in a numbered
comment|/// address space.
specifier|static
name|PointerType
operator|*
name|get
argument_list|(
argument|Type *ElementType
argument_list|,
argument|unsigned AddressSpace
argument_list|)
block|;
comment|/// This constructs a pointer to an object of the specified type in the
comment|/// generic address space (address space zero).
specifier|static
name|PointerType
operator|*
name|getUnqual
argument_list|(
argument|Type *ElementType
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
name|Type
operator|*
name|getElementType
argument_list|()
specifier|const
block|{
return|return
name|PointeeTy
return|;
block|}
comment|/// Return true if the specified type is valid as a element type.
specifier|static
name|bool
name|isValidElementType
argument_list|(
name|Type
operator|*
name|ElemTy
argument_list|)
block|;
comment|/// Return true if we can load or store from a pointer to this type.
specifier|static
name|bool
name|isLoadableOrStorableType
argument_list|(
name|Type
operator|*
name|ElemTy
argument_list|)
block|;
comment|/// Return the address space of the Pointer type.
specifier|inline
name|unsigned
name|getAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|getSubclassData
argument_list|()
return|;
block|}
comment|/// Implement support type inquiry through isa, cast, and dyn_cast.
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
name|unsigned
name|Type
operator|::
name|getPointerAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|getScalarType
argument_list|()
operator|)
operator|->
name|getAddressSpace
argument_list|()
return|;
block|}
expr|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_DERIVEDTYPES_H
end_comment

end_unit

