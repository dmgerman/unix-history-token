begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/DataLayout.h - Data size& alignment info -----------*- C++ -*-===//
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
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
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
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
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

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// This needs to be outside of the namespace, to avoid conflict with llvm-c
end_comment

begin_comment
comment|// decl.
end_comment

begin_decl_stmt
name|using
name|LLVMTargetDataRef
init|= struct
name|LLVMOpaqueTargetData
operator|*
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|StructLayout
decl_stmt|;
name|class
name|Triple
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// Enum used to categorize the alignment types stored by LayoutAlignElem
enum|enum
name|AlignTypeEnum
block|{
name|INVALID_ALIGN
init|=
literal|0
block|,
name|INTEGER_ALIGN
init|=
literal|'i'
block|,
name|VECTOR_ALIGN
init|=
literal|'v'
block|,
name|FLOAT_ALIGN
init|=
literal|'f'
block|,
name|AGGREGATE_ALIGN
init|=
literal|'a'
block|}
enum|;
comment|// FIXME: Currently the DataLayout string carries a "preferred alignment"
comment|// for types. As the DataLayout is module/global, this should likely be
comment|// sunk down to an FTTI element that is queried rather than a global
comment|// preference.
comment|/// \brief Layout alignment element.
comment|///
comment|/// Stores the alignment data associated with a given alignment type (integer,
comment|/// vector, float) and type bit width.
comment|///
comment|/// \note The unusual order of elements in the structure attempts to reduce
comment|/// padding and make the structure slightly more cache friendly.
struct|struct
name|LayoutAlignElem
block|{
comment|/// \brief Alignment type from \c AlignTypeEnum
name|unsigned
name|AlignType
range|:
literal|8
decl_stmt|;
name|unsigned
name|TypeBitWidth
range|:
literal|24
decl_stmt|;
name|unsigned
name|ABIAlign
range|:
literal|16
decl_stmt|;
name|unsigned
name|PrefAlign
range|:
literal|16
decl_stmt|;
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
comment|/// \brief Layout pointer alignment element.
comment|///
comment|/// Stores the alignment data associated with a given pointer and address space.
comment|///
comment|/// \note The unusual order of elements in the structure attempts to reduce
comment|/// padding and make the structure slightly more cache friendly.
struct|struct
name|PointerAlignElem
block|{
name|unsigned
name|ABIAlign
decl_stmt|;
name|unsigned
name|PrefAlign
decl_stmt|;
name|uint32_t
name|TypeByteWidth
decl_stmt|;
name|uint32_t
name|AddressSpace
decl_stmt|;
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
comment|/// \brief A parsed version of the target data layout string in and methods for
comment|/// querying it.
comment|///
comment|/// The target data layout string is specified *by the target* - a frontend
comment|/// generating LLVM IR is required to generate the right target data for the
comment|/// target being codegen'd to.
name|class
name|DataLayout
block|{
name|private
label|:
comment|/// Defaults to false.
name|bool
name|BigEndian
decl_stmt|;
name|unsigned
name|AllocaAddrSpace
decl_stmt|;
name|unsigned
name|StackNaturalAlign
decl_stmt|;
enum|enum
name|ManglingModeT
block|{
name|MM_None
block|,
name|MM_ELF
block|,
name|MM_MachO
block|,
name|MM_WinCOFF
block|,
name|MM_WinCOFFX86
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
comment|/// \brief Primitive type alignment data. This is sorted by type and bit
comment|/// width during construction.
name|using
name|AlignmentsTy
init|=
name|SmallVector
operator|<
name|LayoutAlignElem
decl_stmt|, 16>;
name|AlignmentsTy
name|Alignments
decl_stmt|;
name|AlignmentsTy
operator|::
name|const_iterator
name|findAlignmentLowerBound
argument_list|(
argument|AlignTypeEnum AlignType
argument_list|,
argument|uint32_t BitWidth
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
name|findAlignmentLowerBound
argument_list|(
name|AlignType
argument_list|,
name|BitWidth
argument_list|)
return|;
block|}
name|AlignmentsTy
operator|::
name|iterator
name|findAlignmentLowerBound
argument_list|(
argument|AlignTypeEnum AlignType
argument_list|,
argument|uint32_t BitWidth
argument_list|)
expr_stmt|;
comment|/// \brief The string representation used to create this DataLayout
name|std
operator|::
name|string
name|StringRepresentation
expr_stmt|;
name|using
name|PointersTy
init|=
name|SmallVector
operator|<
name|PointerAlignElem
decl_stmt|, 8>;
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
comment|// The StructType -> StructLayout map.
name|mutable
name|void
modifier|*
name|LayoutMap
init|=
name|nullptr
decl_stmt|;
comment|/// Pointers in these address spaces are non-integral, and don't have a
comment|/// well-defined bitwise representation.
name|SmallVector
operator|<
name|unsigned
operator|,
literal|8
operator|>
name|NonIntegralAddressSpaces
expr_stmt|;
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
comment|/// Internal helper method that returns requested alignment for type.
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
parameter_list|(
name|StringRef
name|LayoutDescription
parameter_list|)
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
argument|const DataLayout&DL
argument_list|)
block|{
operator|*
name|this
operator|=
name|DL
expr_stmt|;
block|}
operator|~
name|DataLayout
argument_list|()
expr_stmt|;
comment|// Not virtual, do not subclass this class
name|DataLayout
modifier|&
name|operator
init|=
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
name|StringRepresentation
operator|=
name|DL
operator|.
name|StringRepresentation
block|;
name|BigEndian
operator|=
name|DL
operator|.
name|isBigEndian
argument_list|()
block|;
name|AllocaAddrSpace
operator|=
name|DL
operator|.
name|AllocaAddrSpace
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
name|NonIntegralAddressSpaces
operator|=
name|DL
operator|.
name|NonIntegralAddressSpaces
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
name|void
name|init
parameter_list|(
specifier|const
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
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
operator|!
name|BigEndian
return|;
block|}
name|bool
name|isBigEndian
argument_list|()
specifier|const
block|{
return|return
name|BigEndian
return|;
block|}
comment|/// \brief Returns the string representation of the DataLayout.
comment|///
comment|/// This representation is in the same format accepted by the string
comment|/// constructor above. This should not be used to compare two DataLayout as
comment|/// different string can represent the same layout.
specifier|const
name|std
operator|::
name|string
operator|&
name|getStringRepresentation
argument_list|()
specifier|const
block|{
return|return
name|StringRepresentation
return|;
block|}
comment|/// \brief Test if the DataLayout was constructed from an empty string.
name|bool
name|isDefault
argument_list|()
specifier|const
block|{
return|return
name|StringRepresentation
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// \brief Returns true if the specified type is known to be a native integer
comment|/// type supported by the CPU.
comment|///
comment|/// For example, i64 is not native on most 32-bit CPUs and i37 is not native
comment|/// on any known one. This returns false if the integer width is not legal.
comment|///
comment|/// The width is specified in bits.
name|bool
name|isLegalInteger
argument_list|(
name|uint64_t
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
name|uint64_t
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
name|unsigned
name|getStackAlignment
argument_list|()
specifier|const
block|{
return|return
name|StackNaturalAlign
return|;
block|}
name|unsigned
name|getAllocaAddrSpace
argument_list|()
specifier|const
block|{
return|return
name|AllocaAddrSpace
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
name|MM_WinCOFFX86
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
name|StringRef
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
literal|""
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
case|case
name|MM_WinCOFF
case|:
return|return
literal|'\0'
return|;
case|case
name|MM_MachO
case|:
case|case
name|MM_WinCOFFX86
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
name|StringRef
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
case|case
name|MM_WinCOFF
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
name|MM_WinCOFFX86
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
comment|/// \brief Returns true if the specified type fits in a native integer type
comment|/// supported by the CPU.
comment|///
comment|/// For example, if the CPU only supports i32 as a native integer type, then
comment|/// i27 fits in a legal integer type but i45 does not.
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
comment|/// Return the address spaces containing non-integral pointers.  Pointers in
comment|/// this address space don't have a well-defined bitwise representation.
name|ArrayRef
operator|<
name|unsigned
operator|>
name|getNonIntegralAddressSpaces
argument_list|()
specifier|const
block|{
return|return
name|NonIntegralAddressSpaces
return|;
block|}
name|bool
name|isNonIntegralPointerType
argument_list|(
name|PointerType
operator|*
name|PT
argument_list|)
decl|const
block|{
name|ArrayRef
operator|<
name|unsigned
operator|>
name|NonIntegralSpaces
operator|=
name|getNonIntegralAddressSpaces
argument_list|()
expr_stmt|;
return|return
name|find
argument_list|(
name|NonIntegralSpaces
argument_list|,
name|PT
operator|->
name|getAddressSpace
argument_list|()
argument_list|)
operator|!=
name|NonIntegralSpaces
operator|.
name|end
argument_list|()
return|;
block|}
name|bool
name|isNonIntegralPointerType
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
block|{
name|auto
operator|*
name|PTy
operator|=
name|dyn_cast
operator|<
name|PointerType
operator|>
operator|(
name|Ty
operator|)
expr_stmt|;
return|return
name|PTy
operator|&&
name|isNonIntegralPointerType
argument_list|(
name|PTy
argument_list|)
return|;
block|}
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
comment|/// \brief Returns the number of bits necessary to hold the specified type.
comment|///
comment|/// For example, returns 36 for i36 and 80 for x86_fp80. The type passed must
comment|/// have a size (Type::isSized() must return true).
name|uint64_t
name|getTypeSizeInBits
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns the maximum number of bytes that may be overwritten by
comment|/// storing the specified type.
comment|///
comment|/// For example, returns 5 for i36 and 10 for x86_fp80.
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
comment|/// \brief Returns the maximum number of bits that may be overwritten by
comment|/// storing the specified type; always a multiple of 8.
comment|///
comment|/// For example, returns 40 for i36 and 80 for x86_fp80.
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
comment|/// \brief Returns the offset in bytes between successive objects of the
comment|/// specified type, including alignment padding.
comment|///
comment|/// This is the amount that alloca reserves for this type. For example,
comment|/// returns 12 or 16 for x86_fp80, depending on alignment.
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
name|alignTo
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
comment|/// \brief Returns the offset in bits between successive objects of the
comment|/// specified type, including alignment padding; always a multiple of 8.
comment|///
comment|/// This is the amount that alloca reserves for this type. For example,
comment|/// returns 96 or 128 for x86_fp80, depending on alignment.
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
comment|/// \brief Returns the minimum ABI-required alignment for the specified type.
name|unsigned
name|getABITypeAlignment
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns the minimum ABI-required alignment for an integer type of
comment|/// the specified bitwidth.
name|unsigned
name|getABIIntegerTypeAlignment
argument_list|(
name|unsigned
name|BitWidth
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns the preferred stack/global alignment for the specified
comment|/// type.
comment|///
comment|/// This is always at least as good as the ABI alignment.
name|unsigned
name|getPrefTypeAlignment
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns the preferred alignment for the specified type, returned as
comment|/// log2 of the value (a shift amount).
name|unsigned
name|getPreferredTypeAlignmentShift
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns an integer type with size at least as big as that of a
comment|/// pointer in the given address space.
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
comment|/// \brief Returns an integer (vector of integer) type with size at least as
comment|/// big as that of a pointer of the given pointer (vector of pointer) type.
name|Type
modifier|*
name|getIntPtrType
argument_list|(
name|Type
operator|*
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns the smallest integer type with size at least as big as
comment|/// Width bits.
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
comment|/// \brief Returns the largest legal integer type, or null if none are set.
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
name|getLargestLegalIntTypeSizeInBits
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
comment|/// \brief Returns the size of largest legal integer type size, or 0 if none
comment|/// are set.
name|unsigned
name|getLargestLegalIntTypeSizeInBits
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns the offset from the beginning of the type for the specified
comment|/// indices.
comment|///
comment|/// Note that this takes the element type, not the pointer type.
comment|/// This is used to implement getelementptr.
name|int64_t
name|getIndexedOffsetInType
argument_list|(
name|Type
operator|*
name|ElemTy
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
comment|/// \brief Returns a StructLayout object, indicating the alignment of the
comment|/// struct, its size, and the offsets of its fields.
comment|///
comment|/// Note that this information is lazily cached.
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
comment|/// \brief Returns the preferred alignment of the specified global.
comment|///
comment|/// This includes an explicitly requested alignment (if the global has one).
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
comment|/// \brief Returns the preferred alignment of the specified global, returned
comment|/// in log form.
comment|///
comment|/// This includes an explicitly requested alignment (if the global has one).
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

begin_comment
comment|/// Used to lazily calculate structure layout information for a target machine,
end_comment

begin_comment
comment|/// based on the DataLayout structure.
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
name|IsPadded
range|:
literal|1
decl_stmt|;
name|unsigned
name|NumElements
range|:
literal|31
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
comment|/// Returns whether the struct has padding or not between its fields.
comment|/// NB: Padding in nested element is not taken into account.
name|bool
name|hasPadding
argument_list|()
specifier|const
block|{
return|return
name|IsPadded
return|;
block|}
comment|/// \brief Given a valid byte offset into the structure, returns the structure
comment|/// index that contains it.
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
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_DATALAYOUT_H
end_comment

end_unit

