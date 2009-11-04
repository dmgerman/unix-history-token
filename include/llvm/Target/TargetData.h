begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetData.h - Data size& alignment info ---*- C++ -*-===//
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
comment|// This file defines target properties related to datatype size/offset/alignment
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
name|LLVM_TARGET_TARGETDATA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETDATA_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
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
name|GlobalVariable
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
comment|/// Enum used to categorize the alignment types stored by TargetAlignElem
enum|enum
name|AlignTypeEnum
block|{
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
block|,
comment|///< Aggregate alignment
name|STACK_ALIGN
init|=
literal|'s'
comment|///< Stack objects alignment
block|}
enum|;
comment|/// Target alignment element.
comment|///
comment|/// Stores the alignment data associated with a given alignment type (pointer,
comment|/// integer, vector, float) and type bit width.
comment|///
comment|/// @note The unusual order of elements in the structure attempts to reduce
comment|/// padding and make the structure slightly more cache friendly.
struct|struct
name|TargetAlignElem
block|{
name|AlignTypeEnum
name|AlignType
range|:
literal|8
decl_stmt|;
comment|//< Alignment type (AlignTypeEnum)
name|unsigned
name|char
name|ABIAlign
decl_stmt|;
comment|//< ABI alignment for this type/bitw
name|unsigned
name|char
name|PrefAlign
decl_stmt|;
comment|//< Pref. alignment for this type/bitw
name|uint32_t
name|TypeBitWidth
decl_stmt|;
comment|//< Type bit width
comment|/// Initializer
specifier|static
name|TargetAlignElem
name|get
parameter_list|(
name|AlignTypeEnum
name|align_type
parameter_list|,
name|unsigned
name|char
name|abi_align
parameter_list|,
name|unsigned
name|char
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
name|TargetAlignElem
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
comment|/// output stream operator
name|std
operator|::
name|ostream
operator|&
name|dump
argument_list|(
argument|std::ostream&os
argument_list|)
specifier|const
expr_stmt|;
block|}
struct|;
name|class
name|TargetData
range|:
name|public
name|ImmutablePass
block|{
name|private
operator|:
name|bool
name|LittleEndian
block|;
comment|///< Defaults to false
name|unsigned
name|char
name|PointerMemSize
block|;
comment|///< Pointer size in bytes
name|unsigned
name|char
name|PointerABIAlign
block|;
comment|///< Pointer ABI alignment
name|unsigned
name|char
name|PointerPrefAlign
block|;
comment|///< Pointer preferred alignment
comment|//! Where the primitive type alignment data is stored.
comment|/*!    @sa init().    @note Could support multiple size pointer alignments, e.g., 32-bit pointers    vs. 64-bit pointers by extending TargetAlignment, but for now, we don't.    */
name|SmallVector
operator|<
name|TargetAlignElem
block|,
literal|16
operator|>
name|Alignments
block|;
comment|//! Alignment iterator shorthand
typedef|typedef
name|SmallVector
operator|<
name|TargetAlignElem
operator|,
literal|16
operator|>
operator|::
name|iterator
name|align_iterator
expr_stmt|;
comment|//! Constant alignment iterator shorthand
typedef|typedef
name|SmallVector
operator|<
name|TargetAlignElem
operator|,
literal|16
operator|>
operator|::
name|const_iterator
name|align_const_iterator
expr_stmt|;
comment|//! Invalid alignment.
comment|/*!     This member is a signal that a requested alignment type and bit width were     not found in the SmallVector.    */
specifier|static
specifier|const
name|TargetAlignElem
name|InvalidAlignmentElem
decl_stmt|;
comment|// Opaque pointer for the StructType -> StructLayout map.
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
name|char
name|abi_align
parameter_list|,
name|unsigned
name|char
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
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|//! Internal helper method that returns requested alignment for type.
name|unsigned
name|char
name|getAlignment
argument_list|(
specifier|const
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
comment|/// Predicate that tests a TargetAlignElem reference returned by get() against
comment|/// InvalidAlignmentElem.
specifier|inline
name|bool
name|validAlignment
argument_list|(
specifier|const
name|TargetAlignElem
operator|&
name|align
argument_list|)
decl|const
block|{
return|return
operator|(
operator|&
name|align
operator|!=
operator|&
name|InvalidAlignmentElem
operator|)
return|;
block|}
name|public
label|:
comment|/// Default ctor.
comment|///
comment|/// @note This has to exist, because this is a pass, but it should never be
comment|/// used.
name|TargetData
argument_list|()
operator|:
name|ImmutablePass
argument_list|(
argument|&ID
argument_list|)
block|{
name|llvm_report_error
argument_list|(
literal|"Bad TargetData ctor used.  "
literal|"Tool did not specify a TargetData to use?"
argument_list|)
block|;   }
comment|/// Constructs a TargetData from a specification string. See init().
name|explicit
name|TargetData
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|TargetDescription
argument_list|)
operator|:
name|ImmutablePass
argument_list|(
argument|&ID
argument_list|)
block|{
name|init
argument_list|(
name|TargetDescription
argument_list|)
block|;   }
comment|/// Initialize target data from properties stored in the module.
name|explicit
name|TargetData
argument_list|(
specifier|const
name|Module
operator|*
name|M
argument_list|)
expr_stmt|;
name|TargetData
argument_list|(
specifier|const
name|TargetData
operator|&
name|TD
argument_list|)
operator|:
name|ImmutablePass
argument_list|(
operator|&
name|ID
argument_list|)
operator|,
name|LittleEndian
argument_list|(
name|TD
operator|.
name|isLittleEndian
argument_list|()
argument_list|)
operator|,
name|PointerMemSize
argument_list|(
name|TD
operator|.
name|PointerMemSize
argument_list|)
operator|,
name|PointerABIAlign
argument_list|(
name|TD
operator|.
name|PointerABIAlign
argument_list|)
operator|,
name|PointerPrefAlign
argument_list|(
name|TD
operator|.
name|PointerPrefAlign
argument_list|)
operator|,
name|Alignments
argument_list|(
name|TD
operator|.
name|Alignments
argument_list|)
operator|,
name|LayoutMap
argument_list|(
literal|0
argument_list|)
block|{ }
operator|~
name|TargetData
argument_list|()
expr_stmt|;
comment|// Not virtual, do not subclass this class
comment|//! Parse a target data layout string and initialize TargetData alignments.
name|void
name|init
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|TargetDescription
argument_list|)
decl_stmt|;
comment|/// Target endianness...
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
comment|/// TargetData.  This representation is in the same format accepted by the
comment|/// string constructor above.
name|std
operator|::
name|string
name|getStringRepresentation
argument_list|()
specifier|const
expr_stmt|;
comment|/// Target pointer alignment
name|unsigned
name|char
name|getPointerABIAlignment
argument_list|()
specifier|const
block|{
return|return
name|PointerABIAlign
return|;
block|}
comment|/// Return target's alignment for stack-based pointers
name|unsigned
name|char
name|getPointerPrefAlignment
argument_list|()
specifier|const
block|{
return|return
name|PointerPrefAlign
return|;
block|}
comment|/// Target pointer size
name|unsigned
name|char
name|getPointerSize
argument_list|()
specifier|const
block|{
return|return
name|PointerMemSize
return|;
block|}
comment|/// Target pointer size, in bits
name|unsigned
name|char
name|getPointerSizeInBits
argument_list|()
specifier|const
block|{
return|return
literal|8
operator|*
name|PointerMemSize
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
name|uint64_t
name|getTypeSizeInBits
argument_list|(
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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
name|char
name|getABITypeAlignment
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getCallFrameTypeAlignment - Return the minimum ABI-required alignment
comment|/// for the specified type when it is part of a call frame.
name|unsigned
name|char
name|getCallFrameTypeAlignment
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getPrefTypeAlignment - Return the preferred stack/global alignment for
comment|/// the specified type.  This is always at least as good as the ABI alignment.
name|unsigned
name|char
name|getPrefTypeAlignment
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getPreferredTypeAlignmentShift - Return the preferred alignment for the
comment|/// specified type, returned as log2 of the value (a shift amount).
comment|///
name|unsigned
name|char
name|getPreferredTypeAlignmentShift
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// getIntPtrType - Return an unsigned integer type that is the same size or
comment|/// greater to the host pointer size.
comment|///
specifier|const
name|IntegerType
modifier|*
name|getIntPtrType
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|)
decl|const
decl_stmt|;
comment|/// getIndexedOffset - return the offset from the beginning of the type for
comment|/// the specified indices.  This is used to implement getelementptr.
comment|///
name|uint64_t
name|getIndexedOffset
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
name|Value
operator|*
specifier|const
operator|*
name|Indices
argument_list|,
name|unsigned
name|NumIndices
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
specifier|const
name|StructType
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// InvalidateStructLayoutInfo - TargetData speculatively caches StructLayout
comment|/// objects.  If a TargetData object is alive when types are being refined and
comment|/// removed, this method must be called whenever a StructType is removed to
comment|/// avoid a dangling pointer in this cache.
name|void
name|InvalidateStructLayoutInfo
argument_list|(
specifier|const
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
specifier|static
name|char
name|ID
decl_stmt|;
comment|// Pass identification, replacement for typeid
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// StructLayout - used to lazily calculate structure layout information for a
end_comment

begin_comment
comment|/// target machine, based on the TargetData structure.
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
name|TargetData
decl_stmt|;
comment|// Only TargetData can create this class
name|StructLayout
argument_list|(
specifier|const
name|StructType
operator|*
name|ST
argument_list|,
specifier|const
name|TargetData
operator|&
name|TD
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

