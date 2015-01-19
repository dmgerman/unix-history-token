begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------- llvm/DataLayout.h - Data size& alignment info ---*- C++ -*-===//
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
comment|// This file defines layout properties related to datatype size/offset/alignment
end_comment

begin_comment
comment|// information.  It uses lazy annotations to cache information about how
end_comment

begin_comment
comment|// structure types are laid out and used.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This structure should be created once, filled in if the defaults are not
end_comment

begin_comment
comment|// correct and then passed around by const&.  None of the members functions
end_comment

begin_comment
comment|// require modification to the object.
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
name|LLVM_IR_DATALAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_DATALAYOUT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DerivedTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_comment
comment|// this needs to be outside of the namespace, to avoid conflict with llvm-c decl
end_comment

begin_typedef
typedef|typedef
name|struct
name|LLVMOpaqueTargetData
modifier|*
name|LLVMTargetDataRef
typedef|;
end_typedef

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|IntegerType
decl_stmt|;
name|class
name|StructType
decl_stmt|;
name|class
name|StructLayout
decl_stmt|;
name|class
name|Triple
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ArrayRef
expr_stmt|;
comment|/// Enum used to categorize the alignment types stored by LayoutAlignElem
enum|enum
name|AlignTypeEnum
block|{
name|INVALID_ALIGN
init|=
literal|0
block|,
comment|///< An invalid alignment
name|INTEGER_ALIGN
init|=
literal|'i'
block|,
comment|///< Integer type alignment
name|VECTOR_ALIGN
init|=
literal|'v'
block|,
comment|///< Vector type alignment
name|FLOAT_ALIGN
init|=
literal|'f'
block|,
comment|///< Floating point type alignment
name|AGGREGATE_ALIGN
init|=
literal|'a'
comment|///< Aggregate alignment
block|}
enum|;
comment|/// Layout alignment element.
comment|///
comment|/// Stores the alignment data associated with a given alignment type (integer,
comment|/// vector, float) and type bit width.
comment|///
comment|/// @note The unusual order of elements in the structure attempts to reduce
comment|/// padding and make the structure slightly more cache friendly.
struct|struct
name|LayoutAlignElem
block|{
name|unsigned
name|AlignType
range|:
literal|8
decl_stmt|;
comment|///< Alignment type (AlignTypeEnum)
name|unsigned
name|TypeBitWidth
range|:
literal|24
decl_stmt|;
comment|///< Type bit width
name|unsigned
name|ABIAlign
range|:
literal|16
decl_stmt|;
comment|///< ABI alignment for this type/bitw
name|unsigned
name|PrefAlign
range|:
literal|16
decl_stmt|;
comment|///< Pref. alignment for this type/bitw
comment|/// Initializer
specifier|static
name|LayoutAlignElem
name|get
parameter_list|(
name|AlignTypeEnum
name|align_type
parameter_list|,
name|unsigned
name|abi_align
parameter_list|,
name|unsigned
name|pref_align
parameter_list|,
name|uint32_t
name|bit_width
parameter_list|)
function_decl|;
comment|/// Equality predicate
name|bool
name|operator
operator|==
operator|(
specifier|const
name|LayoutAlignElem
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
block|}
struct|;
comment|/// Layout pointer alignment element.
comment|///
comment|/// Stores the alignment data associated with a given pointer and address space.
comment|///
comment|/// @note The unusual order of elements in the structure attempts to reduce
comment|/// padding and make the structure slightly more cache friendly.
struct|struct
name|PointerAlignElem
block|{
name|unsigned
name|ABIAlign
decl_stmt|;
comment|///< ABI alignment for this type/bitw
name|unsigned
name|PrefAlign
decl_stmt|;
comment|///< Pref. alignment for this type/bitw
name|uint32_t
name|TypeByteWidth
decl_stmt|;
comment|///< Type byte width
name|uint32_t
name|AddressSpace
decl_stmt|;
comment|///< Address space for the pointer type
comment|/// Initializer
specifier|static
name|PointerAlignElem
name|get
parameter_list|(
name|uint32_t
name|AddressSpace
parameter_list|,
name|unsigned
name|ABIAlign
parameter_list|,
name|unsigned
name|PrefAlign
parameter_list|,
name|uint32_t
name|TypeByteWidth
parameter_list|)
function_decl|;
comment|/// Equality predicate
name|bool
name|operator
operator|==
operator|(
specifier|const
name|PointerAlignElem
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
block|}
struct|;
comment|/// This class holds a parsed version of the target data layout string in a
comment|/// module and provides methods for querying it. The target data layout string
comment|/// is specified *by the target* - a frontend generating LLVM IR is required to
comment|/// generate the right target data for the target being codegen'd to.
name|class
name|DataLayout
block|{
name|private
label|:
name|bool
name|LittleEndian
decl_stmt|;
comment|///< Defaults to false
name|unsigned
name|StackNaturalAlign
decl_stmt|;
comment|///< Stack natural alignment
enum|enum
name|ManglingModeT
block|{
name|MM_None
block|,
name|MM_ELF
block|,
name|MM_MachO
block|,
name|MM_WINCOFF
block|,
name|MM_Mips
block|}
enum|;
name|ManglingModeT
name|ManglingMode
decl_stmt|;
name|SmallVector
operator|<
name|unsigned
name|char
operator|,
literal|8
operator|>
name|LegalIntWidths
expr_stmt|;
comment|///< Legal Integers.
comment|/// Alignments - Where the primitive type alignment data is stored.
comment|///
comment|/// @sa reset().
comment|/// @note Could support multiple size pointer alignments, e.g., 32-bit
comment|/// pointers vs. 64-bit pointers by extending LayoutAlignment, but for now,
comment|/// we don't.
name|SmallVector
operator|<
name|LayoutAlignElem
operator|,
literal|16
operator|>
name|Alignments
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|PointerAlignElem
operator|,
literal|8
operator|>
name|PointersTy
expr_stmt|;
name|PointersTy
name|Pointers
decl_stmt|;
name|PointersTy
operator|::
name|const_iterator
name|findPointerLowerBound
argument_list|(
argument|uint32_t AddressSpace
argument_list|)
specifier|const
block|{
return|return
name|const_cast
operator|<
name|DataLayout
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|findPointerLowerBound
argument_list|(
name|AddressSpace
argument_list|)
return|;
block|}
name|PointersTy
operator|::
name|iterator
name|findPointerLowerBound
argument_list|(
argument|uint32_t AddressSpace
argument_list|)
expr_stmt|;
comment|/// InvalidAlignmentElem - This member is a signal that a requested alignment
comment|/// type and bit width were not found in the SmallVector.
specifier|static
specifier|const
name|LayoutAlignElem
name|InvalidAlignmentElem
decl_stmt|;
comment|/// InvalidPointerElem - This member is a signal that a requested pointer
comment|/// type and bit width were not found in the DenseSet.
specifier|static
specifier|const
name|PointerAlignElem
name|InvalidPointerElem
decl_stmt|;
comment|// The StructType -> StructLayout map.
name|mutable
name|void
modifier|*
name|LayoutMap
decl_stmt|;
comment|//! Set/initialize target alignments
name|void
name|setAlignment
parameter_list|(
name|AlignTypeEnum
name|align_type
parameter_list|,
name|unsigned
name|abi_align
parameter_list|,
name|unsigned
name|pref_align
parameter_list|,
name|uint32_t
name|bit_width
parameter_list|)
function_decl|;
name|unsigned
name|getAlignmentInfo
argument_list|(
name|AlignTypeEnum
name|align_type
argument_list|,
name|uint32_t
name|bit_width
argument_list|,
name|bool
name|ABIAlign
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|//! Set/initialize pointer alignments
name|void
name|setPointerAlignment
parameter_list|(
name|uint32_t
name|AddrSpace
parameter_list|,
name|unsigned
name|ABIAlign
parameter_list|,
name|unsigned
name|PrefAlign
parameter_list|,
name|uint32_t
name|TypeByteWidth
parameter_list|)
function_decl|;
comment|//! Internal helper method that returns requested alignment for type.
name|unsigned
name|getAlignment
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
name|bool
name|abi_or_pref
argument_list|)
decl|const
decl_stmt|;
comment|/// Valid alignment predicate.
comment|///
comment|/// Predicate that tests a LayoutAlignElem reference returned by get() against
comment|/// InvalidAlignmentElem.
name|bool
name|validAlignment
argument_list|(
specifier|const
name|LayoutAlignElem
operator|&
name|align
argument_list|)
decl|const
block|{
return|return
operator|&
name|align
operator|!=
operator|&
name|InvalidAlignmentElem
return|;
block|}
comment|/// Valid pointer predicate.
comment|///
comment|/// Predicate that tests a PointerAlignElem reference returned by get() against
comment|/// InvalidPointerElem.
name|bool
name|validPointer
argument_list|(
specifier|const
name|PointerAlignElem
operator|&
name|align
argument_list|)
decl|const
block|{
return|return
operator|&
name|align
operator|!=
operator|&
name|InvalidPointerElem
return|;
block|}
comment|/// Parses a target data specification string. Assert if the string is
comment|/// malformed.
name|void
name|parseSpecifier
parameter_list|(
name|StringRef
name|LayoutDescription
parameter_list|)
function_decl|;
comment|// Free all internal data structures.
name|void
name|clear
parameter_list|()
function_decl|;
name|public
label|:
comment|/// Constructs a DataLayout from a specification string. See reset().
name|explicit
name|DataLayout
argument_list|(
argument|StringRef LayoutDescription
argument_list|)
block|:
name|LayoutMap
argument_list|(
argument|nullptr
argument_list|)
block|{
name|reset
argument_list|(
name|LayoutDescription
argument_list|)
expr_stmt|;
block|}
comment|/// Initialize target data from properties stored in the module.
name|explicit
name|DataLayout
parameter_list|(
specifier|const
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
name|DataLayout
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
operator|:
name|LayoutMap
argument_list|(
argument|nullptr
argument_list|)
block|{
operator|*
name|this
operator|=
name|DL
block|; }
name|DataLayout
operator|&
name|operator
operator|=
operator|(
specifier|const
name|DataLayout
operator|&
name|DL
operator|)
block|{
name|clear
argument_list|()
block|;
name|LittleEndian
operator|=
name|DL
operator|.
name|isLittleEndian
argument_list|()
block|;
name|StackNaturalAlign
operator|=
name|DL
operator|.
name|StackNaturalAlign
block|;
name|ManglingMode
operator|=
name|DL
operator|.
name|ManglingMode
block|;
name|LegalIntWidths
operator|=
name|DL
operator|.
name|LegalIntWidths
block|;
name|Alignments
operator|=
name|DL
operator|.
name|Alignments
block|;
name|Pointers
operator|=
name|DL
operator|.
name|Pointers
block|;
return|return
operator|*
name|this
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|DataLayout
operator|&
name|Other
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|DataLayout
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|Other
operator|)
return|;
block|}
operator|~
name|DataLayout
argument_list|()
expr_stmt|;
comment|// Not virtual, do not subclass this class
comment|/// Parse a data layout string (with fallback to default values).
name|void
name|reset
parameter_list|(
name|StringRef
name|LayoutDescription
parameter_list|)
function_decl|;
comment|/// Layout endianness...
name|bool
name|isLittleEndian
argument_list|()
specifier|const
block|{
return|return
name|LittleEndian
return|;
block|}
name|bool
name|isBigEndian
argument_list|()
specifier|const
block|{
return|return
operator|!
name|LittleEndian
return|;
block|}
comment|/// getStringRepresentation - Return the string representation of the
comment|/// DataLayout.  This representation is in the same format accepted by the
comment|/// string constructor above.
name|std
operator|::
name|string
name|getStringRepresentation
argument_list|()
specifier|const
expr_stmt|;
comment|/// isLegalInteger - This function returns true if the specified type is
comment|/// known to be a native integer type supported by the CPU.  For example,
comment|/// i64 is not native on most 32-bit CPUs and i37 is not native on any known
comment|/// one.  This returns false if the integer width is not legal.
comment|///
comment|/// The width is specified in bits.
comment|///
name|bool
name|isLegalInteger
argument_list|(
name|unsigned
name|Width
argument_list|)
decl|const
block|{
for|for
control|(
name|unsigned
name|LegalIntWidth
range|:
name|LegalIntWidths
control|)
if|if
condition|(
name|LegalIntWidth
operator|==
name|Width
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
name|bool
name|isIllegalInteger
argument_list|(
name|unsigned
name|Width
argument_list|)
decl|const
block|{
return|return
operator|!
name|isLegalInteger
argument_list|(
name|Width
argument_list|)
return|;
block|}
comment|/// Returns true if the given alignment exceeds the natural stack alignment.
name|bool
name|exceedsNaturalStackAlignment
argument_list|(
name|unsigned
name|Align
argument_list|)
decl|const
block|{
return|return
operator|(
name|StackNaturalAlign
operator|!=
literal|0
operator|)
operator|&&
operator|(
name|Align
operator|>
name|StackNaturalAlign
operator|)
return|;
block|}
name|bool
name|hasMicrosoftFastStdCallMangling
argument_list|()
specifier|const
block|{
return|return
name|ManglingMode
operator|==
name|MM_WINCOFF
return|;
block|}
name|bool
name|hasLinkerPrivateGlobalPrefix
argument_list|()
specifier|const
block|{
return|return
name|ManglingMode
operator|==
name|MM_MachO
return|;
block|}
specifier|const
name|char
operator|*
name|getLinkerPrivateGlobalPrefix
argument_list|()
specifier|const
block|{
if|if
condition|(
name|ManglingMode
operator|==
name|MM_MachO
condition|)
return|return
literal|"l"
return|;
return|return
name|getPrivateGlobalPrefix
argument_list|()
return|;
block|}
name|char
name|getGlobalPrefix
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|ManglingMode
condition|)
block|{
case|case
name|MM_None
case|:
case|case
name|MM_ELF
case|:
case|case
name|MM_Mips
case|:
return|return
literal|'\0'
return|;
case|case
name|MM_MachO
case|:
case|case
name|MM_WINCOFF
case|:
return|return
literal|'_'
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"invalid mangling mode"
argument_list|)
expr_stmt|;
block|}
specifier|const
name|char
operator|*
name|getPrivateGlobalPrefix
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|ManglingMode
condition|)
block|{
case|case
name|MM_None
case|:
return|return
literal|""
return|;
case|case
name|MM_ELF
case|:
return|return
literal|".L"
return|;
case|case
name|MM_Mips
case|:
return|return
literal|"$"
return|;
case|case
name|MM_MachO
case|:
case|case
name|MM_WINCOFF
case|:
return|return
literal|"L"
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"invalid mangling mode"
argument_list|)
expr_stmt|;
block|}
specifier|static
specifier|const
name|char
operator|*
name|getManglingComponent
argument_list|(
specifier|const
name|Triple
operator|&
name|T
argument_list|)
expr_stmt|;
comment|/// fitsInLegalInteger - This function returns true if the specified type fits
comment|/// in a native integer type supported by the CPU.  For example, if the CPU
comment|/// only supports i32 as a native integer type, then i27 fits in a legal
comment|/// integer type but i45 does not.
name|bool
name|fitsInLegalInteger
argument_list|(
name|unsigned
name|Width
argument_list|)
decl|const
block|{
for|for
control|(
name|unsigned
name|LegalIntWidth
range|:
name|LegalIntWidths
control|)
if|if
condition|(
name|Width
operator|<=
name|LegalIntWidth
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
comment|/// Layout pointer alignment
comment|/// FIXME: The defaults need to be removed once all of
comment|/// the backends/clients are updated.
name|unsigned
name|getPointerABIAlignment
argument_list|(
name|unsigned
name|AS
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// Return target's alignment for stack-based pointers
comment|/// FIXME: The defaults need to be removed once all of
comment|/// the backends/clients are updated.
name|unsigned
name|getPointerPrefAlignment
argument_list|(
name|unsigned
name|AS
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// Layout pointer size
comment|/// FIXME: The defaults need to be removed once all of
comment|/// the backends/clients are updated.
name|unsigned
name|getPointerSize
argument_list|(
name|unsigned
name|AS
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// Layout pointer size, in bits
comment|/// FIXME: The defaults need to be removed once all of
comment|/// the backends/clients are updated.
name|unsigned
name|getPointerSizeInBits
argument_list|(
name|unsigned
name|AS
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
name|getPointerSize
argument_list|(
name|AS
argument_list|)
operator|*
literal|8
return|;
block|}
comment|/// Layout pointer size, in bits, based on the type.  If this function is
comment|/// called with a pointer type, then the type size of the pointer is returned.
comment|/// If this function is called with a vector of pointers, then the type size
comment|/// of the pointer is returned.  This should only be called with a pointer or
comment|/// vector of pointers.
name|unsigned
name|getPointerTypeSizeInBits
argument_list|(
name|Type
operator|*
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|getPointerTypeSize
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
block|{
return|return
name|getPointerTypeSizeInBits
argument_list|(
name|Ty
argument_list|)
operator|/
literal|8
return|;
block|}
comment|/// Size examples:
comment|///
comment|/// Type        SizeInBits  StoreSizeInBits  AllocSizeInBits[*]
comment|/// ----        ----------  ---------------  ---------------
comment|///  i1            1           8                8
comment|///  i8            8           8                8
comment|///  i19          19          24               32
comment|///  i32          32          32               32
comment|///  i100        100         104              128
comment|///  i128        128         128              128
comment|///  Float        32          32               32
comment|///  Double       64          64               64
comment|///  X86_FP80     80          80               96
comment|///
comment|/// [*] The alloc size depends on the alignment, and thus on the target.
comment|///     These values are for x86-32 linux.
comment|/// getTypeSizeInBits - Return the number of bits necessary to hold the
comment|/// specified type.  For example, returns 36 for i36 and 80 for x86_fp80.
comment|/// The type passed must have a size (Type::isSized() must return true).
name|uint64_t
name|getTypeSizeInBits
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getTypeStoreSize - Return the maximum number of bytes that may be
comment|/// overwritten by storing the specified type.  For example, returns 5
comment|/// for i36 and 10 for x86_fp80.
name|uint64_t
name|getTypeStoreSize
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
block|{
return|return
operator|(
name|getTypeSizeInBits
argument_list|(
name|Ty
argument_list|)
operator|+
literal|7
operator|)
operator|/
literal|8
return|;
block|}
comment|/// getTypeStoreSizeInBits - Return the maximum number of bits that may be
comment|/// overwritten by storing the specified type; always a multiple of 8.  For
comment|/// example, returns 40 for i36 and 80 for x86_fp80.
name|uint64_t
name|getTypeStoreSizeInBits
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
block|{
return|return
literal|8
operator|*
name|getTypeStoreSize
argument_list|(
name|Ty
argument_list|)
return|;
block|}
comment|/// getTypeAllocSize - Return the offset in bytes between successive objects
comment|/// of the specified type, including alignment padding.  This is the amount
comment|/// that alloca reserves for this type.  For example, returns 12 or 16 for
comment|/// x86_fp80, depending on alignment.
name|uint64_t
name|getTypeAllocSize
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
block|{
comment|// Round up to the next alignment boundary.
return|return
name|RoundUpAlignment
argument_list|(
name|getTypeStoreSize
argument_list|(
name|Ty
argument_list|)
argument_list|,
name|getABITypeAlignment
argument_list|(
name|Ty
argument_list|)
argument_list|)
return|;
block|}
comment|/// getTypeAllocSizeInBits - Return the offset in bits between successive
comment|/// objects of the specified type, including alignment padding; always a
comment|/// multiple of 8.  This is the amount that alloca reserves for this type.
comment|/// For example, returns 96 or 128 for x86_fp80, depending on alignment.
name|uint64_t
name|getTypeAllocSizeInBits
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
block|{
return|return
literal|8
operator|*
name|getTypeAllocSize
argument_list|(
name|Ty
argument_list|)
return|;
block|}
comment|/// getABITypeAlignment - Return the minimum ABI-required alignment for the
comment|/// specified type.
name|unsigned
name|getABITypeAlignment
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getABIIntegerTypeAlignment - Return the minimum ABI-required alignment for
comment|/// an integer type of the specified bitwidth.
name|unsigned
name|getABIIntegerTypeAlignment
argument_list|(
name|unsigned
name|BitWidth
argument_list|)
decl|const
decl_stmt|;
comment|/// getPrefTypeAlignment - Return the preferred stack/global alignment for
comment|/// the specified type.  This is always at least as good as the ABI alignment.
name|unsigned
name|getPrefTypeAlignment
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getPreferredTypeAlignmentShift - Return the preferred alignment for the
comment|/// specified type, returned as log2 of the value (a shift amount).
name|unsigned
name|getPreferredTypeAlignmentShift
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getIntPtrType - Return an integer type with size at least as big as that
comment|/// of a pointer in the given address space.
name|IntegerType
modifier|*
name|getIntPtrType
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|unsigned
name|AddressSpace
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// getIntPtrType - Return an integer (vector of integer) type with size at
comment|/// least as big as that of a pointer of the given pointer (vector of pointer)
comment|/// type.
name|Type
modifier|*
name|getIntPtrType
argument_list|(
name|Type
operator|*
argument_list|)
decl|const
decl_stmt|;
comment|/// getSmallestLegalIntType - Return the smallest integer type with size at
comment|/// least as big as Width bits.
name|Type
modifier|*
name|getSmallestLegalIntType
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|unsigned
name|Width
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// getLargestLegalIntType - Return the largest legal integer type, or null if
comment|/// none are set.
name|Type
modifier|*
name|getLargestLegalIntType
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|)
decl|const
block|{
name|unsigned
name|LargestSize
init|=
name|getLargestLegalIntTypeSize
argument_list|()
decl_stmt|;
return|return
operator|(
name|LargestSize
operator|==
literal|0
operator|)
condition|?
name|nullptr
else|:
name|Type
operator|::
name|getIntNTy
argument_list|(
name|C
argument_list|,
name|LargestSize
argument_list|)
return|;
block|}
comment|/// getLargestLegalIntTypeSize - Return the size of largest legal integer
comment|/// type size, or 0 if none are set.
name|unsigned
name|getLargestLegalIntTypeSize
argument_list|()
specifier|const
expr_stmt|;
comment|/// getIndexedOffset - return the offset from the beginning of the type for
comment|/// the specified indices.  This is used to implement getelementptr.
name|uint64_t
name|getIndexedOffset
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
name|ArrayRef
operator|<
name|Value
operator|*
operator|>
name|Indices
argument_list|)
decl|const
decl_stmt|;
comment|/// getStructLayout - Return a StructLayout object, indicating the alignment
comment|/// of the struct, its size, and the offsets of its fields.  Note that this
comment|/// information is lazily cached.
specifier|const
name|StructLayout
modifier|*
name|getStructLayout
argument_list|(
name|StructType
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getPreferredAlignment - Return the preferred alignment of the specified
comment|/// global.  This includes an explicitly requested alignment (if the global
comment|/// has one).
name|unsigned
name|getPreferredAlignment
argument_list|(
specifier|const
name|GlobalVariable
operator|*
name|GV
argument_list|)
decl|const
decl_stmt|;
comment|/// getPreferredAlignmentLog - Return the preferred alignment of the
comment|/// specified global, returned in log form.  This includes an explicitly
comment|/// requested alignment (if the global has one).
name|unsigned
name|getPreferredAlignmentLog
argument_list|(
specifier|const
name|GlobalVariable
operator|*
name|GV
argument_list|)
decl|const
decl_stmt|;
comment|/// RoundUpAlignment - Round the specified value up to the next alignment
comment|/// boundary specified by Alignment.  For example, 7 rounded up to an
comment|/// alignment boundary of 4 is 8.  8 rounded up to the alignment boundary of 4
comment|/// is 8 because it is already aligned.
name|template
operator|<
name|typename
name|UIntTy
operator|>
specifier|static
name|UIntTy
name|RoundUpAlignment
argument_list|(
argument|UIntTy Val
argument_list|,
argument|unsigned Alignment
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|Alignment
operator|&
operator|(
name|Alignment
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
operator|&&
literal|"Alignment must be power of 2!"
argument_list|)
block|;
return|return
operator|(
name|Val
operator|+
operator|(
name|Alignment
operator|-
literal|1
operator|)
operator|)
operator|&
operator|~
name|UIntTy
argument_list|(
name|Alignment
operator|-
literal|1
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
specifier|inline
name|DataLayout
modifier|*
name|unwrap
parameter_list|(
name|LLVMTargetDataRef
name|P
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|DataLayout
operator|*
operator|>
operator|(
name|P
operator|)
return|;
block|}
end_function

begin_function
specifier|inline
name|LLVMTargetDataRef
name|wrap
parameter_list|(
specifier|const
name|DataLayout
modifier|*
name|P
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|LLVMTargetDataRef
operator|>
operator|(
name|const_cast
operator|<
name|DataLayout
operator|*
operator|>
operator|(
name|P
operator|)
operator|)
return|;
block|}
end_function

begin_decl_stmt
name|class
name|DataLayoutPass
range|:
name|public
name|ImmutablePass
block|{
name|DataLayout
name|DL
block|;
name|public
operator|:
comment|/// This has to exist, because this is a pass, but it should never be used.
name|DataLayoutPass
argument_list|()
block|;
operator|~
name|DataLayoutPass
argument_list|()
block|;
specifier|const
name|DataLayout
operator|&
name|getDataLayout
argument_list|()
specifier|const
block|{
return|return
name|DL
return|;
block|}
comment|// For use with the C API. C++ code should always use the constructor that
comment|// takes a module.
name|explicit
name|DataLayoutPass
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
block|;
name|explicit
name|DataLayoutPass
argument_list|(
specifier|const
name|Module
operator|*
name|M
argument_list|)
block|;
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// StructLayout - used to lazily calculate structure layout information for a
end_comment

begin_comment
comment|/// target machine, based on the DataLayout structure.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|StructLayout
block|{
name|uint64_t
name|StructSize
decl_stmt|;
name|unsigned
name|StructAlignment
decl_stmt|;
name|unsigned
name|NumElements
decl_stmt|;
name|uint64_t
name|MemberOffsets
index|[
literal|1
index|]
decl_stmt|;
comment|// variable sized array!
name|public
label|:
name|uint64_t
name|getSizeInBytes
argument_list|()
specifier|const
block|{
return|return
name|StructSize
return|;
block|}
name|uint64_t
name|getSizeInBits
argument_list|()
specifier|const
block|{
return|return
literal|8
operator|*
name|StructSize
return|;
block|}
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|StructAlignment
return|;
block|}
comment|/// getElementContainingOffset - Given a valid byte offset into the structure,
comment|/// return the structure index that contains it.
comment|///
name|unsigned
name|getElementContainingOffset
argument_list|(
name|uint64_t
name|Offset
argument_list|)
decl|const
decl_stmt|;
name|uint64_t
name|getElementOffset
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|NumElements
operator|&&
literal|"Invalid element idx!"
argument_list|)
expr_stmt|;
return|return
name|MemberOffsets
index|[
name|Idx
index|]
return|;
block|}
name|uint64_t
name|getElementOffsetInBits
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
return|return
name|getElementOffset
argument_list|(
name|Idx
argument_list|)
operator|*
literal|8
return|;
block|}
name|private
label|:
name|friend
name|class
name|DataLayout
decl_stmt|;
comment|// Only DataLayout can create this class
name|StructLayout
argument_list|(
name|StructType
operator|*
name|ST
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// The implementation of this method is provided inline as it is particularly
end_comment

begin_comment
comment|// well suited to constant folding when called on a specific Type subclass.
end_comment

begin_expr_stmt
specifier|inline
name|uint64_t
name|DataLayout
operator|::
name|getTypeSizeInBits
argument_list|(
argument|Type *Ty
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Ty
operator|->
name|isSized
argument_list|()
operator|&&
literal|"Cannot getTypeInfo() on a type that is unsized!"
argument_list|)
block|;
switch|switch
condition|(
name|Ty
operator|->
name|getTypeID
argument_list|()
condition|)
block|{
case|case
name|Type
operator|::
name|LabelTyID
case|:
return|return
name|getPointerSizeInBits
argument_list|(
literal|0
argument_list|)
return|;
case|case
name|Type
operator|::
name|PointerTyID
case|:
return|return
name|getPointerSizeInBits
argument_list|(
name|Ty
operator|->
name|getPointerAddressSpace
argument_list|()
argument_list|)
return|;
case|case
name|Type
operator|::
name|ArrayTyID
case|:
block|{
name|ArrayType
modifier|*
name|ATy
init|=
name|cast
operator|<
name|ArrayType
operator|>
operator|(
name|Ty
operator|)
decl_stmt|;
return|return
name|ATy
operator|->
name|getNumElements
argument_list|()
operator|*
name|getTypeAllocSizeInBits
argument_list|(
name|ATy
operator|->
name|getElementType
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_case
case|case
name|Type
operator|::
name|StructTyID
case|:
end_case

begin_comment
comment|// Get the layout annotation... which is lazily created on demand.
end_comment

begin_return
return|return
name|getStructLayout
argument_list|(
name|cast
operator|<
name|StructType
operator|>
operator|(
name|Ty
operator|)
argument_list|)
operator|->
name|getSizeInBits
argument_list|()
return|;
end_return

begin_case
case|case
name|Type
operator|::
name|IntegerTyID
case|:
end_case

begin_return
return|return
name|Ty
operator|->
name|getIntegerBitWidth
argument_list|()
return|;
end_return

begin_case
case|case
name|Type
operator|::
name|HalfTyID
case|:
end_case

begin_return
return|return
literal|16
return|;
end_return

begin_case
case|case
name|Type
operator|::
name|FloatTyID
case|:
end_case

begin_return
return|return
literal|32
return|;
end_return

begin_case
case|case
name|Type
operator|::
name|DoubleTyID
case|:
end_case

begin_case
case|case
name|Type
operator|::
name|X86_MMXTyID
case|:
end_case

begin_return
return|return
literal|64
return|;
end_return

begin_case
case|case
name|Type
operator|::
name|PPC_FP128TyID
case|:
end_case

begin_case
case|case
name|Type
operator|::
name|FP128TyID
case|:
end_case

begin_return
return|return
literal|128
return|;
end_return

begin_comment
comment|// In memory objects this is always aligned to a higher boundary, but
end_comment

begin_comment
comment|// only 80 bits contain information.
end_comment

begin_case
case|case
name|Type
operator|::
name|X86_FP80TyID
case|:
end_case

begin_return
return|return
literal|80
return|;
end_return

begin_case
case|case
name|Type
operator|::
name|VectorTyID
case|:
end_case

begin_block
block|{
name|VectorType
modifier|*
name|VTy
init|=
name|cast
operator|<
name|VectorType
operator|>
operator|(
name|Ty
operator|)
decl_stmt|;
return|return
name|VTy
operator|->
name|getNumElements
argument_list|()
operator|*
name|getTypeSizeInBits
argument_list|(
name|VTy
operator|->
name|getElementType
argument_list|()
argument_list|)
return|;
block|}
end_block

begin_default
default|default:
end_default

begin_expr_stmt
name|llvm_unreachable
argument_list|(
literal|"DataLayout::getTypeSizeInBits(): Unsupported type"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|} }  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

