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
name|RecordDecl
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
name|uint64_t
name|Size
decl_stmt|;
comment|// Size of record in bits.
name|uint64_t
name|NextOffset
decl_stmt|;
comment|// Next available offset
name|uint64_t
modifier|*
name|FieldOffsets
decl_stmt|;
name|unsigned
name|Alignment
decl_stmt|;
comment|// Alignment of record in bits.
name|unsigned
name|FieldCount
decl_stmt|;
comment|// Number of fields
name|friend
name|class
name|ASTContext
decl_stmt|;
name|ASTRecordLayout
argument_list|(
argument|uint64_t S =
literal|0
argument_list|,
argument|unsigned A =
literal|8
argument_list|)
block|:
name|Size
argument_list|(
name|S
argument_list|)
operator|,
name|NextOffset
argument_list|(
name|S
argument_list|)
operator|,
name|Alignment
argument_list|(
name|A
argument_list|)
operator|,
name|FieldCount
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|ASTRecordLayout
argument_list|()
block|{
name|delete
index|[]
name|FieldOffsets
block|;   }
comment|/// Initialize record layout. N is the number of fields in this record.
name|void
name|InitializeLayout
argument_list|(
argument|unsigned N
argument_list|)
block|{
name|FieldCount
operator|=
name|N
block|;
name|FieldOffsets
operator|=
name|new
name|uint64_t
index|[
name|N
index|]
block|;   }
comment|/// Finalize record layout. Adjust record size based on the alignment.
name|void
name|FinalizeLayout
argument_list|(
argument|bool ForceNonEmpty = false
argument_list|)
block|{
comment|// In C++, records cannot be of size 0.
if|if
condition|(
name|ForceNonEmpty
operator|&&
name|Size
operator|==
literal|0
condition|)
name|Size
operator|=
literal|8
expr_stmt|;
comment|// Finally, round the size of the record up to the alignment of the
comment|// record itself.
name|Size
operator|=
operator|(
name|Size
operator|+
operator|(
name|Alignment
operator|-
literal|1
operator|)
operator|)
operator|&
operator|~
operator|(
name|Alignment
operator|-
literal|1
operator|)
expr_stmt|;
block|}
name|void
name|SetFieldOffset
parameter_list|(
name|unsigned
name|FieldNo
parameter_list|,
name|uint64_t
name|Offset
parameter_list|)
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
name|FieldOffsets
index|[
name|FieldNo
index|]
operator|=
name|Offset
expr_stmt|;
block|}
name|void
name|SetAlignment
parameter_list|(
name|unsigned
name|A
parameter_list|)
block|{
name|Alignment
operator|=
name|A
expr_stmt|;
block|}
comment|/// LayoutField - Field layout. StructPacking is the specified
comment|/// packing alignment (maximum alignment) in bits to use for the
comment|/// structure, or 0 if no packing alignment is specified.
name|void
name|LayoutField
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|FD
parameter_list|,
name|unsigned
name|FieldNo
parameter_list|,
name|bool
name|IsUnion
parameter_list|,
name|unsigned
name|StructPacking
parameter_list|,
name|ASTContext
modifier|&
name|Context
parameter_list|)
function_decl|;
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
comment|/// getNextOffset - Get the next available (unused) offset in the
comment|/// structure, in bits.
name|uint64_t
name|getNextOffset
argument_list|()
specifier|const
block|{
return|return
name|NextOffset
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

