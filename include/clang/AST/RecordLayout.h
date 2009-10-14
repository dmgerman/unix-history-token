begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- RecordLayout.h - Layout information for a struct/union -*- C++ -*-===//
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
comment|//  This file defines the RecordLayout interface.
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
name|LLVM_CLANG_AST_LAYOUTINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_LAYOUTINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|FieldDecl
decl_stmt|;
name|class
name|RecordDecl
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
comment|/// ASTRecordLayout -
comment|/// This class contains layout information for one RecordDecl,
comment|/// which is a struct/union/class.  The decl represented must be a definition,
comment|/// not a forward declaration.
comment|/// This class is also used to contain layout information for one
comment|/// ObjCInterfaceDecl. FIXME - Find appropriate name.
comment|/// These objects are managed by ASTContext.
name|class
name|ASTRecordLayout
block|{
comment|/// Size - Size of record in bits.
name|uint64_t
name|Size
decl_stmt|;
comment|/// DataSize - Size of record in bits without tail padding.
name|uint64_t
name|DataSize
decl_stmt|;
comment|/// FieldOffsets - Array of field offsets in bits.
name|uint64_t
modifier|*
name|FieldOffsets
decl_stmt|;
comment|// Alignment - Alignment of record in bits.
name|unsigned
name|Alignment
decl_stmt|;
comment|// FieldCount - Number of fields.
name|unsigned
name|FieldCount
decl_stmt|;
struct|struct
name|CXXRecordLayoutInfo
block|{
comment|/// NonVirtualSize - The non-virtual size (in bits) of an object, which is
comment|/// the size of the object without virtual bases.
name|uint64_t
name|NonVirtualSize
decl_stmt|;
comment|/// NonVirtualAlign - The non-virtual alignment (in bits) of an object,
comment|/// which is the alignment of the object without virtual bases.
name|uint64_t
name|NonVirtualAlign
decl_stmt|;
comment|/// PrimaryBase - The primary base for our vtable.
specifier|const
name|CXXRecordDecl
modifier|*
name|PrimaryBase
decl_stmt|;
comment|/// PrimaryBase - Wether or not the primary base was a virtual base.
name|bool
name|PrimaryBaseWasVirtual
decl_stmt|;
comment|/// BaseOffsets - Contains a map from base classes to their offset.
comment|/// FIXME: This should really use a SmallPtrMap, once we have one in LLVM :)
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
name|uint64_t
operator|>
name|BaseOffsets
expr_stmt|;
comment|/// VBaseOffsets - Contains a map from vbase classes to their offset.
comment|/// FIXME: This should really use a SmallPtrMap, once we have one in LLVM :)
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
name|uint64_t
operator|>
name|VBaseOffsets
expr_stmt|;
block|}
struct|;
comment|/// CXXInfo - If the record layout is for a C++ record, this will have
comment|/// C++ specific information about the record.
name|CXXRecordLayoutInfo
modifier|*
name|CXXInfo
decl_stmt|;
name|friend
name|class
name|ASTContext
decl_stmt|;
name|friend
name|class
name|ASTRecordLayoutBuilder
decl_stmt|;
name|ASTRecordLayout
argument_list|(
argument|uint64_t size
argument_list|,
argument|unsigned alignment
argument_list|,
argument|unsigned datasize
argument_list|,
argument|const uint64_t *fieldoffsets
argument_list|,
argument|unsigned fieldcount
argument_list|)
block|:
name|Size
argument_list|(
name|size
argument_list|)
operator|,
name|DataSize
argument_list|(
name|datasize
argument_list|)
operator|,
name|FieldOffsets
argument_list|(
literal|0
argument_list|)
operator|,
name|Alignment
argument_list|(
name|alignment
argument_list|)
operator|,
name|FieldCount
argument_list|(
name|fieldcount
argument_list|)
operator|,
name|CXXInfo
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|FieldCount
operator|>
literal|0
condition|)
block|{
name|FieldOffsets
operator|=
name|new
name|uint64_t
index|[
name|FieldCount
index|]
expr_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|FieldCount
condition|;
operator|++
name|i
control|)
name|FieldOffsets
index|[
name|i
index|]
operator|=
name|fieldoffsets
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
comment|// Constructor for C++ records.
name|ASTRecordLayout
argument_list|(
argument|uint64_t size
argument_list|,
argument|unsigned alignment
argument_list|,
argument|uint64_t datasize
argument_list|,
argument|const uint64_t *fieldoffsets
argument_list|,
argument|unsigned fieldcount
argument_list|,
argument|uint64_t nonvirtualsize
argument_list|,
argument|unsigned nonvirtualalign
argument_list|,
argument|const CXXRecordDecl *PB
argument_list|,
argument|bool PBVirtual
argument_list|,
argument|const std::pair<const CXXRecordDecl *
argument_list|,
argument|uint64_t> *bases
argument_list|,
argument|unsigned numbases
argument_list|,
argument|const std::pair<const CXXRecordDecl *
argument_list|,
argument|uint64_t> *vbases
argument_list|,
argument|unsigned numvbases
argument_list|)
operator|:
name|Size
argument_list|(
name|size
argument_list|)
operator|,
name|DataSize
argument_list|(
name|datasize
argument_list|)
operator|,
name|FieldOffsets
argument_list|(
literal|0
argument_list|)
operator|,
name|Alignment
argument_list|(
name|alignment
argument_list|)
operator|,
name|FieldCount
argument_list|(
name|fieldcount
argument_list|)
operator|,
name|CXXInfo
argument_list|(
argument|new CXXRecordLayoutInfo
argument_list|)
block|{
if|if
condition|(
name|FieldCount
operator|>
literal|0
condition|)
block|{
name|FieldOffsets
operator|=
name|new
name|uint64_t
index|[
name|FieldCount
index|]
expr_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|FieldCount
condition|;
operator|++
name|i
control|)
name|FieldOffsets
index|[
name|i
index|]
operator|=
name|fieldoffsets
index|[
name|i
index|]
expr_stmt|;
block|}
name|CXXInfo
operator|->
name|PrimaryBase
operator|=
name|PB
expr_stmt|;
name|CXXInfo
operator|->
name|PrimaryBaseWasVirtual
operator|=
name|PBVirtual
expr_stmt|;
name|CXXInfo
operator|->
name|NonVirtualSize
operator|=
name|nonvirtualsize
expr_stmt|;
name|CXXInfo
operator|->
name|NonVirtualAlign
operator|=
name|nonvirtualalign
expr_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|numbases
condition|;
operator|++
name|i
control|)
name|CXXInfo
operator|->
name|BaseOffsets
index|[
name|bases
index|[
name|i
index|]
operator|.
name|first
index|]
operator|=
name|bases
index|[
name|i
index|]
operator|.
name|second
expr_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|numvbases
condition|;
operator|++
name|i
control|)
name|CXXInfo
operator|->
name|VBaseOffsets
index|[
name|vbases
index|[
name|i
index|]
operator|.
name|first
index|]
operator|=
name|vbases
index|[
name|i
index|]
operator|.
name|second
expr_stmt|;
block|}
operator|~
name|ASTRecordLayout
argument_list|()
block|{
name|delete
index|[]
name|FieldOffsets
block|;
name|delete
name|CXXInfo
block|;   }
name|ASTRecordLayout
argument_list|(
specifier|const
name|ASTRecordLayout
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|ASTRecordLayout
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
comment|/// getAlignment - Get the record alignment in bits.
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|Alignment
return|;
block|}
comment|/// getSize - Get the record size in bits.
name|uint64_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
comment|/// getFieldCount - Get the number of fields in the layout.
name|unsigned
name|getFieldCount
argument_list|()
specifier|const
block|{
return|return
name|FieldCount
return|;
block|}
comment|/// getFieldOffset - Get the offset of the given field index, in
comment|/// bits.
name|uint64_t
name|getFieldOffset
argument_list|(
name|unsigned
name|FieldNo
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|FieldNo
operator|<
name|FieldCount
operator|&&
literal|"Invalid Field No"
argument_list|)
expr_stmt|;
return|return
name|FieldOffsets
index|[
name|FieldNo
index|]
return|;
block|}
comment|/// getDataSize() - Get the record data size, which is the record size
comment|/// without tail padding, in bits.
name|uint64_t
name|getDataSize
argument_list|()
specifier|const
block|{
return|return
name|DataSize
return|;
block|}
comment|/// getNonVirtualSize - Get the non-virtual size (in bits) of an object,
comment|/// which is the size of the object without virtual bases.
name|uint64_t
name|getNonVirtualSize
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
name|CXXInfo
operator|->
name|NonVirtualSize
return|;
block|}
comment|/// getNonVirtualSize - Get the non-virtual alignment (in bits) of an object,
comment|/// which is the alignment of the object without virtual bases.
name|unsigned
name|getNonVirtualAlign
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
name|CXXInfo
operator|->
name|NonVirtualAlign
return|;
block|}
comment|/// getPrimaryBase - Get the primary base.
specifier|const
name|CXXRecordDecl
operator|*
name|getPrimaryBase
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
name|CXXInfo
operator|->
name|PrimaryBase
return|;
block|}
comment|/// getPrimaryBaseWasVirtual - Indicates if the primary base was virtual.
name|bool
name|getPrimaryBaseWasVirtual
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
block|;
return|return
name|CXXInfo
operator|->
name|PrimaryBaseWasVirtual
return|;
block|}
comment|/// getBaseClassOffset - Get the offset, in bits, for the given base class.
name|uint64_t
name|getBaseClassOffset
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|Base
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|CXXInfo
operator|->
name|BaseOffsets
operator|.
name|count
argument_list|(
name|Base
argument_list|)
operator|&&
literal|"Did not find base!"
argument_list|)
expr_stmt|;
return|return
name|CXXInfo
operator|->
name|BaseOffsets
index|[
name|Base
index|]
return|;
block|}
comment|/// getVBaseClassOffset - Get the offset, in bits, for the given base class.
name|uint64_t
name|getVBaseClassOffset
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|VBase
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|CXXInfo
operator|&&
literal|"Record layout does not have C++ specific info!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|CXXInfo
operator|->
name|VBaseOffsets
operator|.
name|count
argument_list|(
name|VBase
argument_list|)
operator|&&
literal|"Did not find base!"
argument_list|)
expr_stmt|;
return|return
name|CXXInfo
operator|->
name|VBaseOffsets
index|[
name|VBase
index|]
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

