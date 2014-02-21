begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Type.h - Classes for handling data types -----------*- C++ -*-===//
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
comment|// This file contains the declaration of the Type class.  For more "Type"
end_comment

begin_comment
comment|// stuff, look in DerivedTypes.h.
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
name|LLVM_IR_TYPE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_TYPE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APFloat.h"
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
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
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
name|PointerType
decl_stmt|;
name|class
name|IntegerType
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|LLVMContextImpl
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|template
operator|<
name|class
name|GraphType
operator|>
expr|struct
name|GraphTraits
expr_stmt|;
comment|/// The instances of the Type class are immutable: once they are created,
comment|/// they are never changed.  Also note that only one instance of a particular
comment|/// type is ever created.  Thus seeing if two types are equal is a matter of
comment|/// doing a trivial pointer comparison. To enforce that no two equal instances
comment|/// are created, Type instances can only be created via static factory methods
comment|/// in class Type and in derived classes.  Once allocated, Types are never
comment|/// free'd.
comment|///
name|class
name|Type
block|{
name|public
label|:
comment|//===--------------------------------------------------------------------===//
comment|/// Definitions of all of the base types for the Type system.  Based on this
comment|/// value, you can cast to a class defined in DerivedTypes.h.
comment|/// Note: If you add an element to this, you need to add an element to the
comment|/// Type::getPrimitiveType function, or else things will break!
comment|/// Also update LLVMTypeKind and LLVMGetTypeKind () in the C binding.
comment|///
enum|enum
name|TypeID
block|{
comment|// PrimitiveTypes - make sure LastPrimitiveTyID stays up to date.
name|VoidTyID
init|=
literal|0
block|,
comment|///<  0: type with no size
name|HalfTyID
block|,
comment|///<  1: 16-bit floating point type
name|FloatTyID
block|,
comment|///<  2: 32-bit floating point type
name|DoubleTyID
block|,
comment|///<  3: 64-bit floating point type
name|X86_FP80TyID
block|,
comment|///<  4: 80-bit floating point type (X87)
name|FP128TyID
block|,
comment|///<  5: 128-bit floating point type (112-bit mantissa)
name|PPC_FP128TyID
block|,
comment|///<  6: 128-bit floating point type (two 64-bits, PowerPC)
name|LabelTyID
block|,
comment|///<  7: Labels
name|MetadataTyID
block|,
comment|///<  8: Metadata
name|X86_MMXTyID
block|,
comment|///<  9: MMX vectors (64 bits, X86 specific)
comment|// Derived types... see DerivedTypes.h file.
comment|// Make sure FirstDerivedTyID stays up to date!
name|IntegerTyID
block|,
comment|///< 10: Arbitrary bit width integers
name|FunctionTyID
block|,
comment|///< 11: Functions
name|StructTyID
block|,
comment|///< 12: Structures
name|ArrayTyID
block|,
comment|///< 13: Arrays
name|PointerTyID
block|,
comment|///< 14: Pointers
name|VectorTyID
block|,
comment|///< 15: SIMD 'packed' format, or other vector type
name|NumTypeIDs
block|,
comment|// Must remain as last defined ID
name|LastPrimitiveTyID
init|=
name|X86_MMXTyID
block|,
name|FirstDerivedTyID
init|=
name|IntegerTyID
block|}
enum|;
name|private
label|:
comment|/// Context - This refers to the LLVMContext in which this type was uniqued.
name|LLVMContext
modifier|&
name|Context
decl_stmt|;
comment|// Due to Ubuntu GCC bug 910363:
comment|// https://bugs.launchpad.net/ubuntu/+source/gcc-4.5/+bug/910363
comment|// Bitpack ID and SubclassData manually.
comment|// Note: TypeID : low 8 bit; SubclassData : high 24 bit.
name|uint32_t
name|IDAndSubclassData
decl_stmt|;
name|protected
label|:
name|friend
name|class
name|LLVMContextImpl
decl_stmt|;
name|explicit
name|Type
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|TypeID tid
argument_list|)
block|:
name|Context
argument_list|(
name|C
argument_list|)
operator|,
name|IDAndSubclassData
argument_list|(
literal|0
argument_list|)
operator|,
name|NumContainedTys
argument_list|(
literal|0
argument_list|)
operator|,
name|ContainedTys
argument_list|(
literal|0
argument_list|)
block|{
name|setTypeID
argument_list|(
name|tid
argument_list|)
block|;   }
operator|~
name|Type
argument_list|()
block|{}
name|void
name|setTypeID
argument_list|(
argument|TypeID ID
argument_list|)
block|{
name|IDAndSubclassData
operator|=
operator|(
name|ID
operator|&
literal|0xFF
operator|)
operator||
operator|(
name|IDAndSubclassData
operator|&
literal|0xFFFFFF00
operator|)
block|;
name|assert
argument_list|(
name|getTypeID
argument_list|()
operator|==
name|ID
operator|&&
literal|"TypeID data too large for field"
argument_list|)
block|;   }
name|unsigned
name|getSubclassData
argument_list|()
specifier|const
block|{
return|return
name|IDAndSubclassData
operator|>>
literal|8
return|;
block|}
name|void
name|setSubclassData
parameter_list|(
name|unsigned
name|val
parameter_list|)
block|{
name|IDAndSubclassData
operator|=
operator|(
name|IDAndSubclassData
operator|&
literal|0xFF
operator|)
operator||
operator|(
name|val
operator|<<
literal|8
operator|)
expr_stmt|;
comment|// Ensure we don't have any accidental truncation.
name|assert
argument_list|(
name|getSubclassData
argument_list|()
operator|==
name|val
operator|&&
literal|"Subclass data too large for field"
argument_list|)
expr_stmt|;
block|}
comment|/// NumContainedTys - Keeps track of how many Type*'s there are in the
comment|/// ContainedTys list.
name|unsigned
name|NumContainedTys
decl_stmt|;
comment|/// ContainedTys - A pointer to the array of Types contained by this Type.
comment|/// For example, this includes the arguments of a function type, the elements
comment|/// of a structure, the pointee of a pointer, the element type of an array,
comment|/// etc.  This pointer may be 0 for types that don't contain other types
comment|/// (Integer, Double, Float).
name|Type
modifier|*
specifier|const
modifier|*
name|ContainedTys
decl_stmt|;
name|public
label|:
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// getContext - Return the LLVMContext in which this type was uniqued.
name|LLVMContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|Context
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Accessors for working with types.
comment|//
comment|/// getTypeID - Return the type id for the type.  This will return one
comment|/// of the TypeID enum elements defined above.
comment|///
name|TypeID
name|getTypeID
argument_list|()
specifier|const
block|{
return|return
call|(
name|TypeID
call|)
argument_list|(
name|IDAndSubclassData
operator|&
literal|0xFF
argument_list|)
return|;
block|}
comment|/// isVoidTy - Return true if this is 'void'.
name|bool
name|isVoidTy
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|VoidTyID
return|;
block|}
comment|/// isHalfTy - Return true if this is 'half', a 16-bit IEEE fp type.
name|bool
name|isHalfTy
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|HalfTyID
return|;
block|}
comment|/// isFloatTy - Return true if this is 'float', a 32-bit IEEE fp type.
name|bool
name|isFloatTy
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|FloatTyID
return|;
block|}
comment|/// isDoubleTy - Return true if this is 'double', a 64-bit IEEE fp type.
name|bool
name|isDoubleTy
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|DoubleTyID
return|;
block|}
comment|/// isX86_FP80Ty - Return true if this is x86 long double.
name|bool
name|isX86_FP80Ty
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|X86_FP80TyID
return|;
block|}
comment|/// isFP128Ty - Return true if this is 'fp128'.
name|bool
name|isFP128Ty
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|FP128TyID
return|;
block|}
comment|/// isPPC_FP128Ty - Return true if this is powerpc long double.
name|bool
name|isPPC_FP128Ty
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|PPC_FP128TyID
return|;
block|}
comment|/// isFloatingPointTy - Return true if this is one of the six floating point
comment|/// types
name|bool
name|isFloatingPointTy
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|HalfTyID
operator|||
name|getTypeID
argument_list|()
operator|==
name|FloatTyID
operator|||
name|getTypeID
argument_list|()
operator|==
name|DoubleTyID
operator|||
name|getTypeID
argument_list|()
operator|==
name|X86_FP80TyID
operator|||
name|getTypeID
argument_list|()
operator|==
name|FP128TyID
operator|||
name|getTypeID
argument_list|()
operator|==
name|PPC_FP128TyID
return|;
block|}
specifier|const
name|fltSemantics
operator|&
name|getFltSemantics
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|getTypeID
argument_list|()
condition|)
block|{
case|case
name|HalfTyID
case|:
return|return
name|APFloat
operator|::
name|IEEEhalf
return|;
case|case
name|FloatTyID
case|:
return|return
name|APFloat
operator|::
name|IEEEsingle
return|;
case|case
name|DoubleTyID
case|:
return|return
name|APFloat
operator|::
name|IEEEdouble
return|;
case|case
name|X86_FP80TyID
case|:
return|return
name|APFloat
operator|::
name|x87DoubleExtended
return|;
case|case
name|FP128TyID
case|:
return|return
name|APFloat
operator|::
name|IEEEquad
return|;
case|case
name|PPC_FP128TyID
case|:
return|return
name|APFloat
operator|::
name|PPCDoubleDouble
return|;
default|default:
name|llvm_unreachable
argument_list|(
literal|"Invalid floating type"
argument_list|)
expr_stmt|;
block|}
block|}
comment|/// isX86_MMXTy - Return true if this is X86 MMX.
name|bool
name|isX86_MMXTy
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|X86_MMXTyID
return|;
block|}
comment|/// isFPOrFPVectorTy - Return true if this is a FP type or a vector of FP.
comment|///
name|bool
name|isFPOrFPVectorTy
argument_list|()
specifier|const
block|{
return|return
name|getScalarType
argument_list|()
operator|->
name|isFloatingPointTy
argument_list|()
return|;
block|}
comment|/// isLabelTy - Return true if this is 'label'.
name|bool
name|isLabelTy
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|LabelTyID
return|;
block|}
comment|/// isMetadataTy - Return true if this is 'metadata'.
name|bool
name|isMetadataTy
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|MetadataTyID
return|;
block|}
comment|/// isIntegerTy - True if this is an instance of IntegerType.
comment|///
name|bool
name|isIntegerTy
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|IntegerTyID
return|;
block|}
comment|/// isIntegerTy - Return true if this is an IntegerType of the given width.
name|bool
name|isIntegerTy
argument_list|(
name|unsigned
name|Bitwidth
argument_list|)
decl|const
decl_stmt|;
comment|/// isIntOrIntVectorTy - Return true if this is an integer type or a vector of
comment|/// integer types.
comment|///
name|bool
name|isIntOrIntVectorTy
argument_list|()
specifier|const
block|{
return|return
name|getScalarType
argument_list|()
operator|->
name|isIntegerTy
argument_list|()
return|;
block|}
comment|/// isFunctionTy - True if this is an instance of FunctionType.
comment|///
name|bool
name|isFunctionTy
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|FunctionTyID
return|;
block|}
comment|/// isStructTy - True if this is an instance of StructType.
comment|///
name|bool
name|isStructTy
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|StructTyID
return|;
block|}
comment|/// isArrayTy - True if this is an instance of ArrayType.
comment|///
name|bool
name|isArrayTy
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|ArrayTyID
return|;
block|}
comment|/// isPointerTy - True if this is an instance of PointerType.
comment|///
name|bool
name|isPointerTy
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|PointerTyID
return|;
block|}
comment|/// isPtrOrPtrVectorTy - Return true if this is a pointer type or a vector of
comment|/// pointer types.
comment|///
name|bool
name|isPtrOrPtrVectorTy
argument_list|()
specifier|const
block|{
return|return
name|getScalarType
argument_list|()
operator|->
name|isPointerTy
argument_list|()
return|;
block|}
comment|/// isVectorTy - True if this is an instance of VectorType.
comment|///
name|bool
name|isVectorTy
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|VectorTyID
return|;
block|}
comment|/// canLosslesslyBitCastTo - Return true if this type could be converted
comment|/// with a lossless BitCast to type 'Ty'. For example, i8* to i32*. BitCasts
comment|/// are valid for types of the same size only where no re-interpretation of
comment|/// the bits is done.
comment|/// @brief Determine if this type could be losslessly bitcast to Ty
name|bool
name|canLosslesslyBitCastTo
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// isEmptyTy - Return true if this type is empty, that is, it has no
comment|/// elements or all its elements are empty.
name|bool
name|isEmptyTy
argument_list|()
specifier|const
expr_stmt|;
comment|/// Here are some useful little methods to query what type derived types are
comment|/// Note that all other types can just compare to see if this == Type::xxxTy;
comment|///
name|bool
name|isPrimitiveType
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|<=
name|LastPrimitiveTyID
return|;
block|}
name|bool
name|isDerivedType
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|>=
name|FirstDerivedTyID
return|;
block|}
comment|/// isFirstClassType - Return true if the type is "first class", meaning it
comment|/// is a valid type for a Value.
comment|///
name|bool
name|isFirstClassType
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|!=
name|FunctionTyID
operator|&&
name|getTypeID
argument_list|()
operator|!=
name|VoidTyID
return|;
block|}
comment|/// isSingleValueType - Return true if the type is a valid type for a
comment|/// register in codegen.  This includes all first-class types except struct
comment|/// and array types.
comment|///
name|bool
name|isSingleValueType
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getTypeID
argument_list|()
operator|!=
name|VoidTyID
operator|&&
name|isPrimitiveType
argument_list|()
operator|)
operator|||
name|getTypeID
argument_list|()
operator|==
name|IntegerTyID
operator|||
name|getTypeID
argument_list|()
operator|==
name|PointerTyID
operator|||
name|getTypeID
argument_list|()
operator|==
name|VectorTyID
return|;
block|}
comment|/// isAggregateType - Return true if the type is an aggregate type. This
comment|/// means it is valid as the first operand of an insertvalue or
comment|/// extractvalue instruction. This includes struct and array types, but
comment|/// does not include vector types.
comment|///
name|bool
name|isAggregateType
argument_list|()
specifier|const
block|{
return|return
name|getTypeID
argument_list|()
operator|==
name|StructTyID
operator|||
name|getTypeID
argument_list|()
operator|==
name|ArrayTyID
return|;
block|}
comment|/// isSized - Return true if it makes sense to take the size of this type.  To
comment|/// get the actual size for a particular target, it is reasonable to use the
comment|/// DataLayout subsystem to do this.
comment|///
name|bool
name|isSized
argument_list|()
specifier|const
block|{
comment|// If it's a primitive, it is always sized.
if|if
condition|(
name|getTypeID
argument_list|()
operator|==
name|IntegerTyID
operator|||
name|isFloatingPointTy
argument_list|()
operator|||
name|getTypeID
argument_list|()
operator|==
name|PointerTyID
operator|||
name|getTypeID
argument_list|()
operator|==
name|X86_MMXTyID
condition|)
return|return
name|true
return|;
comment|// If it is not something that can have a size (e.g. a function or label),
comment|// it doesn't have a size.
if|if
condition|(
name|getTypeID
argument_list|()
operator|!=
name|StructTyID
operator|&&
name|getTypeID
argument_list|()
operator|!=
name|ArrayTyID
operator|&&
name|getTypeID
argument_list|()
operator|!=
name|VectorTyID
condition|)
return|return
name|false
return|;
comment|// Otherwise we have to try harder to decide.
return|return
name|isSizedDerivedType
argument_list|()
return|;
block|}
comment|/// getPrimitiveSizeInBits - Return the basic size of this type if it is a
comment|/// primitive type.  These are fixed by LLVM and are not target dependent.
comment|/// This will return zero if the type does not have a size or is not a
comment|/// primitive type.
comment|///
comment|/// Note that this may not reflect the size of memory allocated for an
comment|/// instance of the type or the number of bytes that are written when an
comment|/// instance of the type is stored to memory. The DataLayout class provides
comment|/// additional query functions to provide this information.
comment|///
name|unsigned
name|getPrimitiveSizeInBits
argument_list|()
specifier|const
expr_stmt|;
comment|/// getScalarSizeInBits - If this is a vector type, return the
comment|/// getPrimitiveSizeInBits value for the element type. Otherwise return the
comment|/// getPrimitiveSizeInBits value for this type.
name|unsigned
name|getScalarSizeInBits
parameter_list|()
function_decl|;
comment|/// getFPMantissaWidth - Return the width of the mantissa of this type.  This
comment|/// is only valid on floating point types.  If the FP type does not
comment|/// have a stable mantissa (e.g. ppc long double), this method returns -1.
name|int
name|getFPMantissaWidth
argument_list|()
specifier|const
expr_stmt|;
comment|/// getScalarType - If this is a vector type, return the element type,
comment|/// otherwise return 'this'.
specifier|const
name|Type
operator|*
name|getScalarType
argument_list|()
specifier|const
expr_stmt|;
name|Type
modifier|*
name|getScalarType
parameter_list|()
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|// Type Iteration support.
comment|//
typedef|typedef
name|Type
modifier|*
specifier|const
modifier|*
name|subtype_iterator
typedef|;
name|subtype_iterator
name|subtype_begin
argument_list|()
specifier|const
block|{
return|return
name|ContainedTys
return|;
block|}
name|subtype_iterator
name|subtype_end
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
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|subtype_iterator
operator|>
name|subtype_reverse_iterator
expr_stmt|;
name|subtype_reverse_iterator
name|subtype_rbegin
argument_list|()
specifier|const
block|{
return|return
name|subtype_reverse_iterator
argument_list|(
name|subtype_end
argument_list|()
argument_list|)
return|;
block|}
name|subtype_reverse_iterator
name|subtype_rend
argument_list|()
specifier|const
block|{
return|return
name|subtype_reverse_iterator
argument_list|(
name|subtype_begin
argument_list|()
argument_list|)
return|;
block|}
comment|/// getContainedType - This method is used to implement the type iterator
comment|/// (defined a the end of the file).  For derived types, this returns the
comment|/// types 'contained' in the derived type.
comment|///
name|Type
modifier|*
name|getContainedType
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|NumContainedTys
operator|&&
literal|"Index out of range!"
argument_list|)
expr_stmt|;
return|return
name|ContainedTys
index|[
name|i
index|]
return|;
block|}
comment|/// getNumContainedTypes - Return the number of types in the derived type.
comment|///
name|unsigned
name|getNumContainedTypes
argument_list|()
specifier|const
block|{
return|return
name|NumContainedTys
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Helper methods corresponding to subclass methods.  This forces a cast to
comment|// the specified subclass and calls its accessor.  "getVectorNumElements" (for
comment|// example) is shorthand for cast<VectorType>(Ty)->getNumElements().  This is
comment|// only intended to cover the core methods that are frequently used, helper
comment|// methods should not be added here.
name|unsigned
name|getIntegerBitWidth
argument_list|()
specifier|const
expr_stmt|;
name|Type
modifier|*
name|getFunctionParamType
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|getFunctionNumParams
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isFunctionVarArg
argument_list|()
specifier|const
expr_stmt|;
name|StringRef
name|getStructName
argument_list|()
specifier|const
expr_stmt|;
name|unsigned
name|getStructNumElements
argument_list|()
specifier|const
expr_stmt|;
name|Type
modifier|*
name|getStructElementType
argument_list|(
name|unsigned
name|N
argument_list|)
decl|const
decl_stmt|;
name|Type
operator|*
name|getSequentialElementType
argument_list|()
specifier|const
expr_stmt|;
name|uint64_t
name|getArrayNumElements
argument_list|()
specifier|const
expr_stmt|;
name|Type
operator|*
name|getArrayElementType
argument_list|()
specifier|const
block|{
return|return
name|getSequentialElementType
argument_list|()
return|;
block|}
name|unsigned
name|getVectorNumElements
argument_list|()
specifier|const
expr_stmt|;
name|Type
operator|*
name|getVectorElementType
argument_list|()
specifier|const
block|{
return|return
name|getSequentialElementType
argument_list|()
return|;
block|}
name|Type
operator|*
name|getPointerElementType
argument_list|()
specifier|const
block|{
return|return
name|getSequentialElementType
argument_list|()
return|;
block|}
comment|/// \brief Get the address space of this pointer or pointer vector type.
name|unsigned
name|getPointerAddressSpace
argument_list|()
specifier|const
expr_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Static members exported by the Type class itself.  Useful for getting
comment|// instances of Type.
comment|//
comment|/// getPrimitiveType - Return a type based on an identifier.
specifier|static
name|Type
modifier|*
name|getPrimitiveType
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|TypeID
name|IDNumber
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|// These are the builtin types that are always available.
comment|//
specifier|static
name|Type
modifier|*
name|getVoidTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
specifier|static
name|Type
modifier|*
name|getLabelTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
specifier|static
name|Type
modifier|*
name|getHalfTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
specifier|static
name|Type
modifier|*
name|getFloatTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
specifier|static
name|Type
modifier|*
name|getDoubleTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
specifier|static
name|Type
modifier|*
name|getMetadataTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
specifier|static
name|Type
modifier|*
name|getX86_FP80Ty
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
specifier|static
name|Type
modifier|*
name|getFP128Ty
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
specifier|static
name|Type
modifier|*
name|getPPC_FP128Ty
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
specifier|static
name|Type
modifier|*
name|getX86_MMXTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
specifier|static
name|IntegerType
modifier|*
name|getIntNTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|N
parameter_list|)
function_decl|;
specifier|static
name|IntegerType
modifier|*
name|getInt1Ty
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
specifier|static
name|IntegerType
modifier|*
name|getInt8Ty
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
specifier|static
name|IntegerType
modifier|*
name|getInt16Ty
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
specifier|static
name|IntegerType
modifier|*
name|getInt32Ty
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
specifier|static
name|IntegerType
modifier|*
name|getInt64Ty
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|// Convenience methods for getting pointer types with one of the above builtin
comment|// types as pointee.
comment|//
specifier|static
name|PointerType
modifier|*
name|getHalfPtrTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|AS
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|PointerType
modifier|*
name|getFloatPtrTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|AS
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|PointerType
modifier|*
name|getDoublePtrTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|AS
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|PointerType
modifier|*
name|getX86_FP80PtrTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|AS
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|PointerType
modifier|*
name|getFP128PtrTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|AS
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|PointerType
modifier|*
name|getPPC_FP128PtrTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|AS
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|PointerType
modifier|*
name|getX86_MMXPtrTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|AS
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|PointerType
modifier|*
name|getIntNPtrTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|N
parameter_list|,
name|unsigned
name|AS
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|PointerType
modifier|*
name|getInt1PtrTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|AS
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|PointerType
modifier|*
name|getInt8PtrTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|AS
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|PointerType
modifier|*
name|getInt16PtrTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|AS
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|PointerType
modifier|*
name|getInt32PtrTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|AS
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|PointerType
modifier|*
name|getInt64PtrTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|AS
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// getPointerTo - Return a pointer to the current type.  This is equivalent
comment|/// to PointerType::get(Foo, AddrSpace).
name|PointerType
modifier|*
name|getPointerTo
parameter_list|(
name|unsigned
name|AddrSpace
init|=
literal|0
parameter_list|)
function_decl|;
name|private
label|:
comment|/// isSizedDerivedType - Derived types like structures and arrays are sized
comment|/// iff all of the members of the type are sized as well.  Since asking for
comment|/// their size is relatively uncommon, move this operation out of line.
name|bool
name|isSizedDerivedType
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Printing of types.
end_comment

begin_expr_stmt
specifier|static
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
name|Type
operator|&
name|T
operator|)
block|{
name|T
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

begin_comment
comment|// allow isa<PointerType>(x) to work without DerivedTypes.h included.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|isa_impl
operator|<
name|PointerType
operator|,
name|Type
operator|>
block|{
specifier|static
specifier|inline
name|bool
name|doit
argument_list|(
argument|const Type&Ty
argument_list|)
block|{
return|return
name|Ty
operator|.
name|getTypeID
argument_list|()
operator|==
name|Type
operator|::
name|PointerTyID
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Provide specializations of GraphTraits to be able to treat a type as a
end_comment

begin_comment
comment|// graph of sub types.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|Type
operator|*
operator|>
block|{
typedef|typedef
name|Type
name|NodeType
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|Type
operator|::
name|subtype_iterator
name|ChildIteratorType
expr_stmt|;
end_typedef

begin_function
specifier|static
specifier|inline
name|NodeType
modifier|*
name|getEntryNode
parameter_list|(
name|Type
modifier|*
name|T
parameter_list|)
block|{
return|return
name|T
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|subtype_begin
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|subtype_end
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
specifier|const
name|Type
operator|*
operator|>
block|{
typedef|typedef
specifier|const
name|Type
name|NodeType
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|Type
operator|::
name|subtype_iterator
name|ChildIteratorType
expr_stmt|;
end_typedef

begin_function
specifier|static
specifier|inline
name|NodeType
modifier|*
name|getEntryNode
parameter_list|(
name|NodeType
modifier|*
name|T
parameter_list|)
block|{
return|return
name|T
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|subtype_begin
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
block|{
return|return
name|N
operator|->
name|subtype_end
argument_list|()
return|;
block|}
end_function

begin_comment
unit|};
comment|// Create wrappers for C Binding types (see CBindingWrapping.h).
end_comment

begin_macro
name|DEFINE_ISA_CONVERSION_FUNCTIONS
argument_list|(
argument|Type
argument_list|,
argument|LLVMTypeRef
argument_list|)
end_macro

begin_comment
comment|/* Specialized opaque type conversions.  */
end_comment

begin_function
specifier|inline
name|Type
modifier|*
modifier|*
name|unwrap
parameter_list|(
name|LLVMTypeRef
modifier|*
name|Tys
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|Type
operator|*
operator|*
operator|>
operator|(
name|Tys
operator|)
return|;
block|}
end_function

begin_function
specifier|inline
name|LLVMTypeRef
modifier|*
name|wrap
parameter_list|(
name|Type
modifier|*
modifier|*
name|Tys
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|LLVMTypeRef
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|Type
operator|*
operator|*
operator|>
operator|(
name|Tys
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

