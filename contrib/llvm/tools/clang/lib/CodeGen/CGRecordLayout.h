begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CGRecordLayout.h - LLVM Record Layout Information ------*- C++ -*-===//
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
name|LLVM_CLANG_LIB_CODEGEN_CGRECORDLAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_CGRECORDLAYOUT_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/CharUnits.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DerivedTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StructType
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
block|{
comment|/// \brief Structure with information about how a bitfield should be accessed.
comment|///
comment|/// Often we layout a sequence of bitfields as a contiguous sequence of bits.
comment|/// When the AST record layout does this, we represent it in the LLVM IR's type
comment|/// as either a sequence of i8 members or a byte array to reserve the number of
comment|/// bytes touched without forcing any particular alignment beyond the basic
comment|/// character alignment.
comment|///
comment|/// Then accessing a particular bitfield involves converting this byte array
comment|/// into a single integer of that size (i24 or i40 -- may not be power-of-two
comment|/// size), loading it, and shifting and masking to extract the particular
comment|/// subsequence of bits which make up that particular bitfield. This structure
comment|/// encodes the information used to construct the extraction code sequences.
comment|/// The CGRecordLayout also has a field index which encodes which byte-sequence
comment|/// this bitfield falls within. Let's assume the following C struct:
comment|///
comment|///   struct S {
comment|///     char a, b, c;
comment|///     unsigned bits : 3;
comment|///     unsigned more_bits : 4;
comment|///     unsigned still_more_bits : 7;
comment|///   };
comment|///
comment|/// This will end up as the following LLVM type. The first array is the
comment|/// bitfield, and the second is the padding out to a 4-byte alignmnet.
comment|///
comment|///   %t = type { i8, i8, i8, i8, i8, [3 x i8] }
comment|///
comment|/// When generating code to access more_bits, we'll generate something
comment|/// essentially like this:
comment|///
comment|///   define i32 @foo(%t* %base) {
comment|///     %0 = gep %t* %base, i32 0, i32 3
comment|///     %2 = load i8* %1
comment|///     %3 = lshr i8 %2, 3
comment|///     %4 = and i8 %3, 15
comment|///     %5 = zext i8 %4 to i32
comment|///     ret i32 %i
comment|///   }
comment|///
struct|struct
name|CGBitFieldInfo
block|{
comment|/// The offset within a contiguous run of bitfields that are represented as
comment|/// a single "field" within the LLVM struct type. This offset is in bits.
name|unsigned
name|Offset
range|:
literal|16
decl_stmt|;
comment|/// The total size of the bit-field, in bits.
name|unsigned
name|Size
range|:
literal|15
decl_stmt|;
comment|/// Whether the bit-field is signed.
name|unsigned
name|IsSigned
range|:
literal|1
decl_stmt|;
comment|/// The storage size in bits which should be used when accessing this
comment|/// bitfield.
name|unsigned
name|StorageSize
decl_stmt|;
comment|/// The alignment which should be used when accessing the bitfield.
name|unsigned
name|StorageAlignment
decl_stmt|;
name|CGBitFieldInfo
argument_list|()
operator|:
name|Offset
argument_list|()
operator|,
name|Size
argument_list|()
operator|,
name|IsSigned
argument_list|()
operator|,
name|StorageSize
argument_list|()
operator|,
name|StorageAlignment
argument_list|()
block|{}
name|CGBitFieldInfo
argument_list|(
argument|unsigned Offset
argument_list|,
argument|unsigned Size
argument_list|,
argument|bool IsSigned
argument_list|,
argument|unsigned StorageSize
argument_list|,
argument|unsigned StorageAlignment
argument_list|)
operator|:
name|Offset
argument_list|(
name|Offset
argument_list|)
operator|,
name|Size
argument_list|(
name|Size
argument_list|)
operator|,
name|IsSigned
argument_list|(
name|IsSigned
argument_list|)
operator|,
name|StorageSize
argument_list|(
name|StorageSize
argument_list|)
operator|,
name|StorageAlignment
argument_list|(
argument|StorageAlignment
argument_list|)
block|{}
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
expr_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Given a bit-field decl, build an appropriate helper object for
comment|/// accessing that field (which is expected to have the given offset and
comment|/// size).
specifier|static
name|CGBitFieldInfo
name|MakeInfo
parameter_list|(
name|class
name|CodeGenTypes
modifier|&
name|Types
parameter_list|,
specifier|const
name|FieldDecl
modifier|*
name|FD
parameter_list|,
name|uint64_t
name|Offset
parameter_list|,
name|uint64_t
name|Size
parameter_list|,
name|uint64_t
name|StorageSize
parameter_list|,
name|uint64_t
name|StorageAlignment
parameter_list|)
function_decl|;
block|}
struct|;
comment|/// CGRecordLayout - This class handles struct and union layout info while
comment|/// lowering AST types to LLVM types.
comment|///
comment|/// These layout objects are only created on demand as IR generation requires.
name|class
name|CGRecordLayout
block|{
name|friend
name|class
name|CodeGenTypes
decl_stmt|;
name|CGRecordLayout
argument_list|(
argument|const CGRecordLayout&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CGRecordLayout
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|private
label|:
comment|/// The LLVM type corresponding to this record layout; used when
comment|/// laying it out as a complete object.
name|llvm
operator|::
name|StructType
operator|*
name|CompleteObjectType
expr_stmt|;
comment|/// The LLVM type for the non-virtual part of this record layout;
comment|/// used when laying it out as a base subobject.
name|llvm
operator|::
name|StructType
operator|*
name|BaseSubobjectType
expr_stmt|;
comment|/// Map from (non-bit-field) struct field to the corresponding llvm struct
comment|/// type field no. This info is populated by record builder.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FieldDecl
operator|*
operator|,
name|unsigned
operator|>
name|FieldInfo
expr_stmt|;
comment|/// Map from (bit-field) struct field to the corresponding llvm struct type
comment|/// field no. This info is populated by record builder.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FieldDecl
operator|*
operator|,
name|CGBitFieldInfo
operator|>
name|BitFields
expr_stmt|;
comment|// FIXME: Maybe we could use a CXXBaseSpecifier as the key and use a single
comment|// map for both virtual and non-virtual bases.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
name|unsigned
operator|>
name|NonVirtualBases
expr_stmt|;
comment|/// Map from virtual bases to their field index in the complete object.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
name|unsigned
operator|>
name|CompleteObjectVirtualBases
expr_stmt|;
comment|/// False if any direct or indirect subobject of this class, when
comment|/// considered as a complete object, requires a non-zero bitpattern
comment|/// when zero-initialized.
name|bool
name|IsZeroInitializable
range|:
literal|1
decl_stmt|;
comment|/// False if any direct or indirect subobject of this class, when
comment|/// considered as a base subobject, requires a non-zero bitpattern
comment|/// when zero-initialized.
name|bool
name|IsZeroInitializableAsBase
range|:
literal|1
decl_stmt|;
name|public
label|:
name|CGRecordLayout
argument_list|(
argument|llvm::StructType *CompleteObjectType
argument_list|,
argument|llvm::StructType *BaseSubobjectType
argument_list|,
argument|bool IsZeroInitializable
argument_list|,
argument|bool IsZeroInitializableAsBase
argument_list|)
block|:
name|CompleteObjectType
argument_list|(
name|CompleteObjectType
argument_list|)
operator|,
name|BaseSubobjectType
argument_list|(
name|BaseSubobjectType
argument_list|)
operator|,
name|IsZeroInitializable
argument_list|(
name|IsZeroInitializable
argument_list|)
operator|,
name|IsZeroInitializableAsBase
argument_list|(
argument|IsZeroInitializableAsBase
argument_list|)
block|{}
comment|/// \brief Return the "complete object" LLVM type associated with
comment|/// this record.
name|llvm
operator|::
name|StructType
operator|*
name|getLLVMType
argument_list|()
specifier|const
block|{
return|return
name|CompleteObjectType
return|;
block|}
comment|/// \brief Return the "base subobject" LLVM type associated with
comment|/// this record.
name|llvm
operator|::
name|StructType
operator|*
name|getBaseSubobjectLLVMType
argument_list|()
specifier|const
block|{
return|return
name|BaseSubobjectType
return|;
block|}
comment|/// \brief Check whether this struct can be C++ zero-initialized
comment|/// with a zeroinitializer.
name|bool
name|isZeroInitializable
argument_list|()
specifier|const
block|{
return|return
name|IsZeroInitializable
return|;
block|}
comment|/// \brief Check whether this struct can be C++ zero-initialized
comment|/// with a zeroinitializer when considered as a base subobject.
name|bool
name|isZeroInitializableAsBase
argument_list|()
specifier|const
block|{
return|return
name|IsZeroInitializableAsBase
return|;
block|}
comment|/// \brief Return llvm::StructType element number that corresponds to the
comment|/// field FD.
name|unsigned
name|getLLVMFieldNo
argument_list|(
specifier|const
name|FieldDecl
operator|*
name|FD
argument_list|)
decl|const
block|{
name|FD
operator|=
name|FD
operator|->
name|getCanonicalDecl
argument_list|()
expr_stmt|;
name|assert
argument_list|(
name|FieldInfo
operator|.
name|count
argument_list|(
name|FD
argument_list|)
operator|&&
literal|"Invalid field for record!"
argument_list|)
expr_stmt|;
return|return
name|FieldInfo
operator|.
name|lookup
argument_list|(
name|FD
argument_list|)
return|;
block|}
name|unsigned
name|getNonVirtualBaseLLVMFieldNo
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|NonVirtualBases
operator|.
name|count
argument_list|(
name|RD
argument_list|)
operator|&&
literal|"Invalid non-virtual base!"
argument_list|)
expr_stmt|;
return|return
name|NonVirtualBases
operator|.
name|lookup
argument_list|(
name|RD
argument_list|)
return|;
block|}
comment|/// \brief Return the LLVM field index corresponding to the given
comment|/// virtual base.  Only valid when operating on the complete object.
name|unsigned
name|getVirtualBaseIndex
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|base
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|CompleteObjectVirtualBases
operator|.
name|count
argument_list|(
name|base
argument_list|)
operator|&&
literal|"Invalid virtual base!"
argument_list|)
expr_stmt|;
return|return
name|CompleteObjectVirtualBases
operator|.
name|lookup
argument_list|(
name|base
argument_list|)
return|;
block|}
comment|/// \brief Return the BitFieldInfo that corresponds to the field FD.
specifier|const
name|CGBitFieldInfo
modifier|&
name|getBitFieldInfo
argument_list|(
specifier|const
name|FieldDecl
operator|*
name|FD
argument_list|)
decl|const
block|{
name|FD
operator|=
name|FD
operator|->
name|getCanonicalDecl
argument_list|()
expr_stmt|;
name|assert
argument_list|(
name|FD
operator|->
name|isBitField
argument_list|()
operator|&&
literal|"Invalid call for non-bit-field decl!"
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FieldDecl
operator|*
operator|,
name|CGBitFieldInfo
operator|>
operator|::
name|const_iterator
name|it
operator|=
name|BitFields
operator|.
name|find
argument_list|(
name|FD
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|it
operator|!=
name|BitFields
operator|.
name|end
argument_list|()
operator|&&
literal|"Unable to find bitfield info"
argument_list|)
expr_stmt|;
return|return
name|it
operator|->
name|second
return|;
block|}
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace CodeGen
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

