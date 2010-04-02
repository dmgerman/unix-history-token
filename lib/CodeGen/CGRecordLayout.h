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
name|public
label|:
struct|struct
name|BitFieldInfo
block|{
name|BitFieldInfo
argument_list|(
argument|unsigned FieldNo
argument_list|,
argument|unsigned Start
argument_list|,
argument|unsigned Size
argument_list|)
block|:
name|FieldNo
argument_list|(
name|FieldNo
argument_list|)
operator|,
name|Start
argument_list|(
name|Start
argument_list|)
operator|,
name|Size
argument_list|(
argument|Size
argument_list|)
block|{}
name|unsigned
name|FieldNo
expr_stmt|;
name|unsigned
name|Start
decl_stmt|;
name|unsigned
name|Size
decl_stmt|;
block|}
struct|;
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
name|BitFieldInfo
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
comment|/// \brief Return the BitFieldInfo that corresponds to the field FD.
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
comment|/// \brief Return llvm::StructType element number that corresponds to the
comment|/// field FD.
specifier|const
name|BitFieldInfo
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
name|BitFieldInfo
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

