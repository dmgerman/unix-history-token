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
name|CLANG_CODEGEN_CGRECORDLAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CGRECORDLAYOUT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|Type
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
comment|/// \brief Helper object for describing how to generate the code for access to a
comment|/// bit-field.
comment|///
comment|/// This structure is intended to describe the "policy" of how the bit-field
comment|/// should be accessed, which may be target, language, or ABI dependent.
name|class
name|CGBitFieldInfo
block|{
name|public
label|:
comment|/// Descriptor for a single component of a bit-field access. The entire
comment|/// bit-field is constituted of a bitwise OR of all of the individual
comment|/// components.
comment|///
comment|/// Each component describes an accessed value, which is how the component
comment|/// should be transferred to/from memory, and a target placement, which is how
comment|/// that component fits into the constituted bit-field. The pseudo-IR for a
comment|/// load is:
comment|///
comment|///   %0 = gep %base, 0, FieldIndex
comment|///   %1 = gep (i8*) %0, FieldByteOffset
comment|///   %2 = (i(AccessWidth) *) %1
comment|///   %3 = load %2, align AccessAlignment
comment|///   %4 = shr %3, FieldBitStart
comment|///
comment|/// and the composed bit-field is formed as the boolean OR of all accesses,
comment|/// masked to TargetBitWidth bits and shifted to TargetBitOffset.
struct|struct
name|AccessInfo
block|{
comment|/// Offset of the field to load in the LLVM structure, if any.
name|unsigned
name|FieldIndex
decl_stmt|;
comment|/// Byte offset from the field address, if any. This should generally be
comment|/// unused as the cleanest IR comes from having a well-constructed LLVM type
comment|/// with proper GEP instructions, but sometimes its use is required, for
comment|/// example if an access is intended to straddle an LLVM field boundary.
name|unsigned
name|FieldByteOffset
decl_stmt|;
comment|/// Bit offset in the accessed value to use. The width is implied by \see
comment|/// TargetBitWidth.
name|unsigned
name|FieldBitStart
decl_stmt|;
comment|/// Bit width of the memory access to perform.
name|unsigned
name|AccessWidth
decl_stmt|;
comment|/// The alignment of the memory access, or 0 if the default alignment should
comment|/// be used.
comment|//
comment|// FIXME: Remove use of 0 to encode default, instead have IRgen do the right
comment|// thing when it generates the code, if avoiding align directives is
comment|// desired.
name|unsigned
name|AccessAlignment
decl_stmt|;
comment|/// Offset for the target value.
name|unsigned
name|TargetBitOffset
decl_stmt|;
comment|/// Number of bits in the access that are destined for the bit-field.
name|unsigned
name|TargetBitWidth
decl_stmt|;
block|}
struct|;
name|private
label|:
comment|/// The components to use to access the bit-field. We may need up to three
comment|/// separate components to support up to i64 bit-field access (4 + 2 + 1 byte
comment|/// accesses).
comment|//
comment|// FIXME: De-hardcode this, just allocate following the struct.
name|AccessInfo
name|Components
index|[
literal|3
index|]
decl_stmt|;
comment|/// The total size of the bit-field, in bits.
name|unsigned
name|Size
decl_stmt|;
comment|/// The number of access components to use.
name|unsigned
name|NumComponents
decl_stmt|;
comment|/// Whether the bit-field is signed.
name|bool
name|IsSigned
range|:
literal|1
decl_stmt|;
name|public
label|:
name|CGBitFieldInfo
argument_list|(
argument|unsigned Size
argument_list|,
argument|unsigned NumComponents
argument_list|,
argument|AccessInfo *_Components
argument_list|,
argument|bool IsSigned
argument_list|)
block|:
name|Size
argument_list|(
name|Size
argument_list|)
operator|,
name|NumComponents
argument_list|(
name|NumComponents
argument_list|)
operator|,
name|IsSigned
argument_list|(
argument|IsSigned
argument_list|)
block|{
name|assert
argument_list|(
name|NumComponents
operator|<=
literal|3
operator|&&
literal|"invalid number of components!"
argument_list|)
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|NumComponents
condition|;
operator|++
name|i
control|)
name|Components
index|[
name|i
index|]
operator|=
name|_Components
index|[
name|i
index|]
expr_stmt|;
comment|// Check some invariants.
name|unsigned
name|AccessedSize
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|getNumComponents
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|AccessInfo
modifier|&
name|AI
init|=
name|getComponent
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|AccessedSize
operator|+=
name|AI
operator|.
name|TargetBitWidth
expr_stmt|;
comment|// We shouldn't try to load 0 bits.
name|assert
argument_list|(
name|AI
operator|.
name|TargetBitWidth
operator|>
literal|0
argument_list|)
expr_stmt|;
comment|// We can't load more bits than we accessed.
name|assert
argument_list|(
name|AI
operator|.
name|FieldBitStart
operator|+
name|AI
operator|.
name|TargetBitWidth
operator|<=
name|AI
operator|.
name|AccessWidth
argument_list|)
expr_stmt|;
comment|// We shouldn't put any bits outside the result size.
name|assert
argument_list|(
name|AI
operator|.
name|TargetBitWidth
operator|+
name|AI
operator|.
name|TargetBitOffset
operator|<=
name|Size
argument_list|)
expr_stmt|;
block|}
comment|// Check that the total number of target bits matches the total bit-field
comment|// size.
name|assert
argument_list|(
name|AccessedSize
operator|==
name|Size
operator|&&
literal|"Total size does not match accessed size!"
argument_list|)
expr_stmt|;
block|}
name|public
label|:
comment|/// \brief Check whether this bit-field access is (i.e., should be sign
comment|/// extended on loads).
name|bool
name|isSigned
argument_list|()
specifier|const
block|{
return|return
name|IsSigned
return|;
block|}
comment|/// \brief Get the size of the bit-field, in bits.
name|unsigned
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
comment|/// @name Component Access
comment|/// @{
name|unsigned
name|getNumComponents
argument_list|()
specifier|const
block|{
return|return
name|NumComponents
return|;
block|}
specifier|const
name|AccessInfo
modifier|&
name|getComponent
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Index
operator|<
name|getNumComponents
argument_list|()
operator|&&
literal|"Invalid access!"
argument_list|)
expr_stmt|;
return|return
name|Components
index|[
name|Index
index|]
return|;
block|}
comment|/// @}
name|void
name|print
argument_list|(
name|llvm
operator|::
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
specifier|const
name|CGRecordLayout
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|CGRecordLayout
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|private
label|:
comment|/// The LLVMType corresponding to this record layout.
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|LLVMType
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
comment|/// Whether one of the fields in this record layout is a pointer to data
comment|/// member, or a struct that contains pointer to data member.
name|bool
name|ContainsPointerToDataMember
range|:
literal|1
decl_stmt|;
name|public
label|:
name|CGRecordLayout
argument_list|(
argument|const llvm::Type *T
argument_list|,
argument|bool ContainsPointerToDataMember
argument_list|)
block|:
name|LLVMType
argument_list|(
name|T
argument_list|)
operator|,
name|ContainsPointerToDataMember
argument_list|(
argument|ContainsPointerToDataMember
argument_list|)
block|{}
comment|/// \brief Return the LLVM type associated with this record.
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|getLLVMType
argument_list|()
specifier|const
block|{
return|return
name|LLVMType
return|;
block|}
comment|/// \brief Check whether this struct contains pointers to data members.
name|bool
name|containsPointerToDataMember
argument_list|()
specifier|const
block|{
return|return
name|ContainsPointerToDataMember
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
name|assert
argument_list|(
operator|!
name|FD
operator|->
name|isBitField
argument_list|()
operator|&&
literal|"Invalid call for bit-field decl!"
argument_list|)
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
name|assert
argument_list|(
name|FD
operator|->
name|isBitField
argument_list|()
operator|&&
literal|"Invalid call for non bit-field decl!"
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
name|llvm
operator|::
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
end_decl_stmt

begin_comment
comment|// end namespace CodeGen
end_comment

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

