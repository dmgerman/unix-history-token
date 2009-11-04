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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TYPE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TYPE_H
end_define

begin_include
include|#
directive|include
file|"llvm/AbstractTypeUser.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Atomic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/GraphTraits.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DerivedType
decl_stmt|;
name|class
name|PointerType
decl_stmt|;
name|class
name|IntegerType
decl_stmt|;
name|class
name|TypeMapBase
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
comment|/// This file contains the declaration of the Type class.  For more "Type" type
comment|/// stuff, look in DerivedTypes.h.
comment|///
comment|/// The instances of the Type class are immutable: once they are created,
comment|/// they are never changed.  Also note that only one instance of a particular
comment|/// type is ever created.  Thus seeing if two types are equal is a matter of
comment|/// doing a trivial pointer comparison. To enforce that no two equal instances
comment|/// are created, Type instances can only be created via static factory methods
comment|/// in class Type and in derived classes.
comment|///
comment|/// Once allocated, Types are never free'd, unless they are an abstract type
comment|/// that is resolved to a more concrete type.
comment|///
comment|/// Types themself don't have a name, and can be named either by:
comment|/// - using SymbolTable instance, typically from some Module,
comment|/// - using convenience methods in the Module class (which uses module's
comment|///    SymbolTable too).
comment|///
comment|/// Opaque types are simple derived types with no state.  There may be many
comment|/// different Opaque type objects floating around, but two are only considered
comment|/// identical if they are pointer equals of each other.  This allows us to have
comment|/// two opaque types that end up resolving to different concrete types later.
comment|///
comment|/// Opaque types are also kinda weird and scary and different because they have
comment|/// to keep a list of uses of the type.  When, through linking, parsing, or
comment|/// bitcode reading, they become resolved, they need to find and update all
comment|/// users of the unknown type, causing them to reference a new, more concrete
comment|/// type.  Opaque types are deleted when their use list dwindles to zero users.
comment|///
comment|/// @brief Root of type hierarchy
name|class
name|Type
range|:
name|public
name|AbstractTypeUser
block|{
name|public
operator|:
comment|//===-------------------------------------------------------------------===//
comment|/// Definitions of all of the base types for the Type system.  Based on this
comment|/// value, you can cast to a "DerivedType" subclass (see DerivedTypes.h)
comment|/// Note: If you add an element to this, you need to add an element to the
comment|/// Type::getPrimitiveType function, or else things will break!
comment|/// Also update LLVMTypeKind and LLVMGetTypeKind () in the C binding.
comment|///
expr|enum
name|TypeID
block|{
comment|// PrimitiveTypes .. make sure LastPrimitiveTyID stays up to date
name|VoidTyID
operator|=
literal|0
block|,
comment|///<  0: type with no size
name|FloatTyID
block|,
comment|///<  1: 32 bit floating point type
name|DoubleTyID
block|,
comment|///<  2: 64 bit floating point type
name|X86_FP80TyID
block|,
comment|///<  3: 80 bit floating point type (X87)
name|FP128TyID
block|,
comment|///<  4: 128 bit floating point type (112-bit mantissa)
name|PPC_FP128TyID
block|,
comment|///<  5: 128 bit floating point type (two 64-bits)
name|LabelTyID
block|,
comment|///<  6: Labels
name|MetadataTyID
block|,
comment|///<  7: Metadata
comment|// Derived types... see DerivedTypes.h file...
comment|// Make sure FirstDerivedTyID stays up to date!!!
name|IntegerTyID
block|,
comment|///<  8: Arbitrary bit width integers
name|FunctionTyID
block|,
comment|///<  9: Functions
name|StructTyID
block|,
comment|///< 10: Structures
name|ArrayTyID
block|,
comment|///< 11: Arrays
name|PointerTyID
block|,
comment|///< 12: Pointers
name|OpaqueTyID
block|,
comment|///< 13: Opaque: type with unknown structure
name|VectorTyID
block|,
comment|///< 14: SIMD 'packed' format, or other vector type
name|NumTypeIDs
block|,
comment|// Must remain as last defined ID
name|LastPrimitiveTyID
operator|=
name|LabelTyID
block|,
name|FirstDerivedTyID
operator|=
name|IntegerTyID
block|}
block|;
name|private
operator|:
name|TypeID
name|ID
operator|:
literal|8
block|;
comment|// The current base type of this type.
name|bool
name|Abstract
operator|:
literal|1
block|;
comment|// True if type contains an OpaqueType
name|unsigned
name|SubclassData
operator|:
literal|23
block|;
comment|//Space for subclasses to store data
comment|/// RefCount - This counts the number of PATypeHolders that are pointing to
comment|/// this type.  When this number falls to zero, if the type is abstract and
comment|/// has no AbstractTypeUsers, the type is deleted.  This is only sensical for
comment|/// derived types.
comment|///
name|mutable
name|sys
operator|::
name|cas_flag
name|RefCount
block|;
comment|/// Context - This refers to the LLVMContext in which this type was uniqued.
name|LLVMContext
operator|&
name|Context
block|;
name|friend
name|class
name|LLVMContextImpl
block|;
specifier|const
name|Type
operator|*
name|getForwardedTypeInternal
argument_list|()
specifier|const
block|;
comment|// Some Type instances are allocated as arrays, some aren't. So we provide
comment|// this method to get the right kind of destruction for the type of Type.
name|void
name|destroy
argument_list|()
specifier|const
block|;
comment|// const is a lie, this does "delete this"!
name|protected
operator|:
name|explicit
name|Type
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|TypeID id
argument_list|)
operator|:
name|ID
argument_list|(
name|id
argument_list|)
block|,
name|Abstract
argument_list|(
name|false
argument_list|)
block|,
name|SubclassData
argument_list|(
literal|0
argument_list|)
block|,
name|RefCount
argument_list|(
literal|0
argument_list|)
block|,
name|Context
argument_list|(
name|C
argument_list|)
block|,
name|ForwardType
argument_list|(
literal|0
argument_list|)
block|,
name|NumContainedTys
argument_list|(
literal|0
argument_list|)
block|,
name|ContainedTys
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
operator|~
name|Type
argument_list|()
block|{
name|assert
argument_list|(
name|AbstractTypeUsers
operator|.
name|empty
argument_list|()
operator|&&
literal|"Abstract types remain"
argument_list|)
block|;   }
comment|/// Types can become nonabstract later, if they are refined.
comment|///
specifier|inline
name|void
name|setAbstract
argument_list|(
argument|bool Val
argument_list|)
block|{
name|Abstract
operator|=
name|Val
block|; }
name|unsigned
name|getRefCount
argument_list|()
specifier|const
block|{
return|return
name|RefCount
return|;
block|}
name|unsigned
name|getSubclassData
argument_list|()
specifier|const
block|{
return|return
name|SubclassData
return|;
block|}
name|void
name|setSubclassData
argument_list|(
argument|unsigned val
argument_list|)
block|{
name|SubclassData
operator|=
name|val
block|; }
comment|/// ForwardType - This field is used to implement the union find scheme for
comment|/// abstract types.  When types are refined to other types, this field is set
comment|/// to the more refined type.  Only abstract types can be forwarded.
name|mutable
specifier|const
name|Type
operator|*
name|ForwardType
block|;
comment|/// AbstractTypeUsers - Implement a list of the users that need to be notified
comment|/// if I am a type, and I get resolved into a more concrete type.
comment|///
name|mutable
name|std
operator|::
name|vector
operator|<
name|AbstractTypeUser
operator|*
operator|>
name|AbstractTypeUsers
block|;
comment|/// NumContainedTys - Keeps track of how many PATypeHandle instances there
comment|/// are at the end of this type instance for the list of contained types. It
comment|/// is the subclasses responsibility to set this up. Set to 0 if there are no
comment|/// contained types in this type.
name|unsigned
name|NumContainedTys
block|;
comment|/// ContainedTys - A pointer to the array of Types (PATypeHandle) contained
comment|/// by this Type.  For example, this includes the arguments of a function
comment|/// type, the elements of a structure, the pointee of a pointer, the element
comment|/// type of an array, etc.  This pointer may be 0 for types that don't
comment|/// contain other types (Integer, Double, Float).  In general, the subclass
comment|/// should arrange for space for the PATypeHandles to be included in the
comment|/// allocation of the type object and set this pointer to the address of the
comment|/// first element. This allows the Type class to manipulate the ContainedTys
comment|/// without understanding the subclass's placement for this array.  keeping
comment|/// it here also allows the subtype_* members to be implemented MUCH more
comment|/// efficiently, and dynamically very few types do not contain any elements.
name|PATypeHandle
operator|*
name|ContainedTys
block|;
name|public
operator|:
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
comment|/// @brief Debugging support: print to stderr
name|void
name|dump
argument_list|()
specifier|const
block|;
comment|/// @brief Debugging support: print to stderr (use type names from context
comment|/// module).
name|void
name|dump
argument_list|(
argument|const Module *Context
argument_list|)
specifier|const
block|;
comment|/// getContext - Fetch the LLVMContext in which this type was uniqued.
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
comment|// Property accessors for dealing with types... Some of these virtual methods
comment|// are defined in private classes defined in Type.cpp for primitive types.
comment|//
comment|/// getTypeID - Return the type id for the type.  This will return one
comment|/// of the TypeID enum elements defined above.
comment|///
specifier|inline
name|TypeID
name|getTypeID
argument_list|()
specifier|const
block|{
return|return
name|ID
return|;
block|}
comment|/// isVoidTy - Return true if this is 'void'.
name|bool
name|isVoidTy
argument_list|()
specifier|const
block|{
return|return
name|ID
operator|==
name|VoidTyID
return|;
block|}
comment|/// isFloatTy - Return true if this is 'float', a 32-bit IEEE fp type.
name|bool
name|isFloatTy
argument_list|()
specifier|const
block|{
return|return
name|ID
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
name|ID
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
name|ID
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
name|ID
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
name|ID
operator|==
name|PPC_FP128TyID
return|;
block|}
comment|/// isLabelTy - Return true if this is 'label'.
name|bool
name|isLabelTy
argument_list|()
specifier|const
block|{
return|return
name|ID
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
name|ID
operator|==
name|MetadataTyID
return|;
block|}
comment|/// getDescription - Return the string representation of the type.
name|std
operator|::
name|string
name|getDescription
argument_list|()
specifier|const
block|;
comment|/// isInteger - True if this is an instance of IntegerType.
comment|///
name|bool
name|isInteger
argument_list|()
specifier|const
block|{
return|return
name|ID
operator|==
name|IntegerTyID
return|;
block|}
comment|/// isIntOrIntVector - Return true if this is an integer type or a vector of
comment|/// integer types.
comment|///
name|bool
name|isIntOrIntVector
argument_list|()
specifier|const
block|;
comment|/// isFloatingPoint - Return true if this is one of the five floating point
comment|/// types
name|bool
name|isFloatingPoint
argument_list|()
specifier|const
block|{
return|return
name|ID
operator|==
name|FloatTyID
operator|||
name|ID
operator|==
name|DoubleTyID
operator|||
name|ID
operator|==
name|X86_FP80TyID
operator|||
name|ID
operator|==
name|FP128TyID
operator|||
name|ID
operator|==
name|PPC_FP128TyID
return|;
block|}
comment|/// isFPOrFPVector - Return true if this is a FP type or a vector of FP types.
comment|///
name|bool
name|isFPOrFPVector
argument_list|()
specifier|const
block|;
comment|/// isAbstract - True if the type is either an Opaque type, or is a derived
comment|/// type that includes an opaque type somewhere in it.
comment|///
specifier|inline
name|bool
name|isAbstract
argument_list|()
specifier|const
block|{
return|return
name|Abstract
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
argument|const Type *Ty
argument_list|)
specifier|const
block|;
comment|/// Here are some useful little methods to query what type derived types are
comment|/// Note that all other types can just compare to see if this == Type::xxxTy;
comment|///
specifier|inline
name|bool
name|isPrimitiveType
argument_list|()
specifier|const
block|{
return|return
name|ID
operator|<=
name|LastPrimitiveTyID
return|;
block|}
specifier|inline
name|bool
name|isDerivedType
argument_list|()
specifier|const
block|{
return|return
name|ID
operator|>=
name|FirstDerivedTyID
return|;
block|}
comment|/// isFirstClassType - Return true if the type is "first class", meaning it
comment|/// is a valid type for a Value.
comment|///
specifier|inline
name|bool
name|isFirstClassType
argument_list|()
specifier|const
block|{
comment|// There are more first-class kinds than non-first-class kinds, so a
comment|// negative test is simpler than a positive one.
return|return
name|ID
operator|!=
name|FunctionTyID
operator|&&
name|ID
operator|!=
name|VoidTyID
operator|&&
name|ID
operator|!=
name|OpaqueTyID
return|;
block|}
comment|/// isSingleValueType - Return true if the type is a valid type for a
comment|/// virtual register in codegen.  This includes all first-class types
comment|/// except struct and array types.
comment|///
specifier|inline
name|bool
name|isSingleValueType
argument_list|()
specifier|const
block|{
return|return
operator|(
name|ID
operator|!=
name|VoidTyID
operator|&&
name|ID
operator|<=
name|LastPrimitiveTyID
operator|)
operator|||
name|ID
operator|==
name|IntegerTyID
operator|||
name|ID
operator|==
name|PointerTyID
operator|||
name|ID
operator|==
name|VectorTyID
return|;
block|}
comment|/// isAggregateType - Return true if the type is an aggregate type. This
comment|/// means it is valid as the first operand of an insertvalue or
comment|/// extractvalue instruction. This includes struct and array types, but
comment|/// does not include vector types.
comment|///
specifier|inline
name|bool
name|isAggregateType
argument_list|()
specifier|const
block|{
return|return
name|ID
operator|==
name|StructTyID
operator|||
name|ID
operator|==
name|ArrayTyID
return|;
block|}
comment|/// isSized - Return true if it makes sense to take the size of this type.  To
comment|/// get the actual size for a particular target, it is reasonable to use the
comment|/// TargetData subsystem to do this.
comment|///
name|bool
name|isSized
argument_list|()
specifier|const
block|{
comment|// If it's a primitive, it is always sized.
if|if
condition|(
name|ID
operator|==
name|IntegerTyID
operator|||
name|isFloatingPoint
argument_list|()
operator|||
name|ID
operator|==
name|PointerTyID
condition|)
return|return
name|true
return|;
comment|// If it is not something that can have a size (e.g. a function or label),
comment|// it doesn't have a size.
if|if
condition|(
name|ID
operator|!=
name|StructTyID
operator|&&
name|ID
operator|!=
name|ArrayTyID
operator|&&
name|ID
operator|!=
name|VectorTyID
condition|)
return|return
name|false
return|;
comment|// If it is something that can have a size and it's concrete, it definitely
comment|// has a size, otherwise we have to try harder to decide.
return|return
operator|!
name|isAbstract
argument_list|()
operator|||
name|isSizedDerivedType
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getPrimitiveSizeInBits - Return the basic size of this type if it is a
end_comment

begin_comment
comment|/// primitive type.  These are fixed by LLVM and are not target dependent.
end_comment

begin_comment
comment|/// This will return zero if the type does not have a size or is not a
end_comment

begin_comment
comment|/// primitive type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this may not reflect the size of memory allocated for an
end_comment

begin_comment
comment|/// instance of the type or the number of bytes that are written when an
end_comment

begin_comment
comment|/// instance of the type is stored to memory. The TargetData class provides
end_comment

begin_comment
comment|/// additional query functions to provide this information.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|unsigned
name|getPrimitiveSizeInBits
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getScalarSizeInBits - If this is a vector type, return the
end_comment

begin_comment
comment|/// getPrimitiveSizeInBits value for the element type. Otherwise return the
end_comment

begin_comment
comment|/// getPrimitiveSizeInBits value for this type.
end_comment

begin_expr_stmt
name|unsigned
name|getScalarSizeInBits
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getFPMantissaWidth - Return the width of the mantissa of this type.  This
end_comment

begin_comment
comment|/// is only valid on floating point types.  If the FP type does not
end_comment

begin_comment
comment|/// have a stable mantissa (e.g. ppc long double), this method returns -1.
end_comment

begin_expr_stmt
name|int
name|getFPMantissaWidth
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getForwardedType - Return the type that this type has been resolved to if
end_comment

begin_comment
comment|/// it has been resolved to anything.  This is used to implement the
end_comment

begin_comment
comment|/// union-find algorithm for type resolution, and shouldn't be used by general
end_comment

begin_comment
comment|/// purpose clients.
end_comment

begin_expr_stmt
specifier|const
name|Type
operator|*
name|getForwardedType
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|ForwardType
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|getForwardedTypeInternal
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// getVAArgsPromotedType - Return the type an argument of this type
end_comment

begin_comment
comment|/// will be promoted to if passed through a variable argument
end_comment

begin_comment
comment|/// function.
end_comment

begin_decl_stmt
unit|const
name|Type
modifier|*
name|getVAArgsPromotedType
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getScalarType - If this is a vector type, return the element type,
end_comment

begin_comment
comment|/// otherwise return this.
end_comment

begin_expr_stmt
specifier|const
name|Type
operator|*
name|getScalarType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Type Iteration support
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|PATypeHandle
modifier|*
name|subtype_iterator
typedef|;
end_typedef

begin_expr_stmt
name|subtype_iterator
name|subtype_begin
argument_list|()
specifier|const
block|{
return|return
name|ContainedTys
return|;
block|}
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// getContainedType - This method is used to implement the type iterator
end_comment

begin_comment
comment|/// (defined a the end of the file).  For derived types, this returns the
end_comment

begin_comment
comment|/// types 'contained' in the derived type.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|const
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
operator|.
name|get
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getNumContainedTypes - Return the number of types in the derived type.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|unsigned
name|getNumContainedTypes
argument_list|()
specifier|const
block|{
return|return
name|NumContainedTys
return|;
block|}
end_expr_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Static members exported by the Type class itself.  Useful for getting
end_comment

begin_comment
comment|// instances of Type.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// getPrimitiveType - Return a type based on an identifier.
end_comment

begin_function_decl
specifier|static
specifier|const
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
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// These are the builtin types that are always available...
end_comment

begin_comment
comment|//
end_comment

begin_function_decl
specifier|static
specifier|const
name|Type
modifier|*
name|getVoidTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|const
name|Type
modifier|*
name|getLabelTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|const
name|Type
modifier|*
name|getFloatTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|const
name|Type
modifier|*
name|getDoubleTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|const
name|Type
modifier|*
name|getMetadataTy
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|const
name|Type
modifier|*
name|getX86_FP80Ty
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|const
name|Type
modifier|*
name|getFP128Ty
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|const
name|Type
modifier|*
name|getPPC_FP128Ty
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|const
name|IntegerType
modifier|*
name|getInt1Ty
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|const
name|IntegerType
modifier|*
name|getInt8Ty
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|const
name|IntegerType
modifier|*
name|getInt16Ty
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|const
name|IntegerType
modifier|*
name|getInt32Ty
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|const
name|IntegerType
modifier|*
name|getInt64Ty
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Convenience methods for getting pointer types with one of the above builtin
end_comment

begin_comment
comment|// types as pointee.
end_comment

begin_comment
comment|//
end_comment

begin_function_decl
specifier|static
specifier|const
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
end_function_decl

begin_function_decl
specifier|static
specifier|const
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
end_function_decl

begin_function_decl
specifier|static
specifier|const
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
end_function_decl

begin_function_decl
specifier|static
specifier|const
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
end_function_decl

begin_function_decl
specifier|static
specifier|const
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
end_function_decl

begin_function_decl
specifier|static
specifier|const
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
end_function_decl

begin_function_decl
specifier|static
specifier|const
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
end_function_decl

begin_function_decl
specifier|static
specifier|const
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
end_function_decl

begin_function_decl
specifier|static
specifier|const
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
end_function_decl

begin_function_decl
specifier|static
specifier|const
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
end_function_decl

begin_comment
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|Type
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_expr_stmt
name|void
name|addRef
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isAbstract
argument_list|()
operator|&&
literal|"Cannot add a reference to a non-abstract type!"
argument_list|)
block|;
name|sys
operator|::
name|AtomicIncrement
argument_list|(
operator|&
name|RefCount
argument_list|)
block|;   }
name|void
name|dropRef
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isAbstract
argument_list|()
operator|&&
literal|"Cannot drop a reference to a non-abstract type!"
argument_list|)
block|;
name|assert
argument_list|(
name|RefCount
operator|&&
literal|"No objects are currently referencing this object!"
argument_list|)
block|;
comment|// If this is the last PATypeHolder using this object, and there are no
comment|// PATypeHandles using it, the type is dead, delete it now.
name|sys
operator|::
name|cas_flag
name|OldCount
operator|=
name|sys
operator|::
name|AtomicDecrement
argument_list|(
operator|&
name|RefCount
argument_list|)
block|;
if|if
condition|(
name|OldCount
operator|==
literal|0
operator|&&
name|AbstractTypeUsers
operator|.
name|empty
argument_list|()
condition|)
name|this
operator|->
name|destroy
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|/// addAbstractTypeUser - Notify an abstract type that there is a new user of
end_comment

begin_comment
comment|/// it.  This function is called primarily by the PATypeHandle class.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|addAbstractTypeUser
argument_list|(
name|AbstractTypeUser
operator|*
name|U
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// removeAbstractTypeUser - Notify an abstract type that a user of the class
end_comment

begin_comment
comment|/// no longer has a handle to the type.  This function is called primarily by
end_comment

begin_comment
comment|/// the PATypeHandle class.  When there are no users of the abstract type, it
end_comment

begin_comment
comment|/// is annihilated, because there is no way to get a reference to it ever
end_comment

begin_comment
comment|/// again.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|removeAbstractTypeUser
argument_list|(
name|AbstractTypeUser
operator|*
name|U
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getPointerTo - Return a pointer to the current type.  This is equivalent
end_comment

begin_comment
comment|/// to PointerType::get(Foo, AddrSpace).
end_comment

begin_decl_stmt
specifier|const
name|PointerType
modifier|*
name|getPointerTo
argument_list|(
name|unsigned
name|AddrSpace
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// isSizedDerivedType - Derived types like structures and arrays are sized
end_comment

begin_comment
comment|/// iff all of the members of the type are sized as well.  Since asking for
end_comment

begin_comment
comment|/// their size is relatively uncommon, move this operation out of line.
end_comment

begin_expr_stmt
name|bool
name|isSizedDerivedType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|virtual
name|void
name|refineAbstractType
parameter_list|(
specifier|const
name|DerivedType
modifier|*
name|OldTy
parameter_list|,
specifier|const
name|Type
modifier|*
name|NewTy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|typeBecameConcrete
parameter_list|(
specifier|const
name|DerivedType
modifier|*
name|AbsTy
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_comment
comment|// PromoteAbstractToConcrete - This is an internal method used to calculate
end_comment

begin_comment
comment|// change "Abstract" from true to false when types are refined.
end_comment

begin_function_decl
name|void
name|PromoteAbstractToConcrete
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|friend
name|class
name|TypeMapBase
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Define some inline methods for the AbstractTypeUser.h:PATypeHandle class.
end_comment

begin_comment
comment|// These are defined here because they MUST be inlined, yet are dependent on
end_comment

begin_comment
comment|// the definition of the Type class.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
specifier|inline
name|void
name|PATypeHandle
operator|::
name|addUser
argument_list|()
block|{
name|assert
argument_list|(
name|Ty
operator|&&
literal|"Type Handle has a null type!"
argument_list|)
block|;
if|if
condition|(
name|Ty
operator|->
name|isAbstract
argument_list|()
condition|)
name|Ty
operator|->
name|addAbstractTypeUser
argument_list|(
name|User
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|void
name|PATypeHandle
operator|::
name|removeUser
argument_list|()
block|{
if|if
condition|(
name|Ty
operator|->
name|isAbstract
argument_list|()
condition|)
name|Ty
operator|->
name|removeAbstractTypeUser
argument_list|(
name|User
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|// Define inline methods for PATypeHolder.
end_comment

begin_comment
comment|/// get - This implements the forwarding part of the union-find algorithm for
end_comment

begin_comment
comment|/// abstract types.  Before every access to the Type*, we check to see if the
end_comment

begin_comment
comment|/// type we are pointing to is forwarding to a new type.  If so, we drop our
end_comment

begin_comment
comment|/// reference to the type.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
specifier|inline
name|Type
operator|*
name|PATypeHolder
operator|::
name|get
argument_list|()
specifier|const
block|{
specifier|const
name|Type
operator|*
name|NewTy
operator|=
name|Ty
operator|->
name|getForwardedType
argument_list|()
block|;
if|if
condition|(
operator|!
name|NewTy
condition|)
return|return
name|const_cast
operator|<
name|Type
operator|*
operator|>
operator|(
name|Ty
operator|)
return|;
end_expr_stmt

begin_return
return|return
operator|*
name|const_cast
operator|<
name|PATypeHolder
operator|*
operator|>
operator|(
name|this
operator|)
operator|=
name|NewTy
return|;
end_return

begin_expr_stmt
unit|}  inline
name|void
name|PATypeHolder
operator|::
name|addRef
argument_list|()
block|{
name|assert
argument_list|(
name|Ty
operator|&&
literal|"Type Holder has a null type!"
argument_list|)
block|;
if|if
condition|(
name|Ty
operator|->
name|isAbstract
argument_list|()
condition|)
name|Ty
operator|->
name|addRef
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|void
name|PATypeHolder
operator|::
name|dropRef
argument_list|()
block|{
if|if
condition|(
name|Ty
operator|->
name|isAbstract
argument_list|()
condition|)
name|Ty
operator|->
name|dropRef
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Provide specializations of GraphTraits to be able to treat a type as a
end_comment

begin_comment
comment|// graph of sub types...
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
specifier|const
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
specifier|inline
name|bool
name|isa_impl
operator|<
name|PointerType
operator|,
name|Type
operator|>
operator|(
specifier|const
name|Type
operator|&
name|Ty
operator|)
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

begin_expr_stmt
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
name|Type
operator|&
name|T
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

