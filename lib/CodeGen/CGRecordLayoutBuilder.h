begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CGRecordLayoutBuilder.h - Record builder helper --------*- C++ -*-===//
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
comment|// This is a helper class used to build CGRecordLayout objects and LLVM types.
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
name|CLANG_CODEGEN_CGRECORDLAYOUTBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CGRECORDLAYOUTBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
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
name|Type
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTRecordLayout
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
name|class
name|FieldDecl
decl_stmt|;
name|class
name|RecordDecl
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CGRecordLayout
decl_stmt|;
name|class
name|CodeGenTypes
decl_stmt|;
name|class
name|CGRecordLayoutBuilder
block|{
name|CodeGenTypes
modifier|&
name|Types
decl_stmt|;
comment|/// Packed - Whether the resulting LLVM struct will be packed or not.
name|bool
name|Packed
decl_stmt|;
comment|/// ContainsMemberPointer - Whether one of the fields is a member pointer
comment|/// or is a struct that contains a member pointer.
name|bool
name|ContainsMemberPointer
decl_stmt|;
comment|/// Alignment - Contains the alignment of the RecordDecl.
name|unsigned
name|Alignment
decl_stmt|;
comment|/// AlignmentAsLLVMStruct - Will contain the maximum alignment of all the
comment|/// LLVM types.
name|unsigned
name|AlignmentAsLLVMStruct
decl_stmt|;
comment|/// BitsAvailableInLastField - If a bit field spans only part of a LLVM field,
comment|/// this will have the number of bits still available in the field.
name|char
name|BitsAvailableInLastField
decl_stmt|;
comment|/// NextFieldOffsetInBytes - Holds the next field offset in bytes.
name|uint64_t
name|NextFieldOffsetInBytes
decl_stmt|;
comment|/// FieldTypes - Holds the LLVM types that the struct is created from.
name|std
operator|::
name|vector
operator|<
specifier|const
name|llvm
operator|::
name|Type
operator|*
operator|>
name|FieldTypes
expr_stmt|;
comment|/// LLVMFieldInfo - Holds a field and its corresponding LLVM field number.
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|FieldDecl
operator|*
operator|,
name|unsigned
operator|>
name|LLVMFieldInfo
expr_stmt|;
name|llvm
operator|::
name|SmallVector
operator|<
name|LLVMFieldInfo
operator|,
literal|16
operator|>
name|LLVMFields
expr_stmt|;
comment|/// LLVMBitFieldInfo - Holds location and size information about a bit field.
struct|struct
name|LLVMBitFieldInfo
block|{
name|LLVMBitFieldInfo
argument_list|(
argument|const FieldDecl *FD
argument_list|,
argument|unsigned FieldNo
argument_list|,
argument|unsigned Start
argument_list|,
argument|unsigned Size
argument_list|)
block|:
name|FD
argument_list|(
name|FD
argument_list|)
operator|,
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
block|{ }
specifier|const
name|FieldDecl
operator|*
name|FD
expr_stmt|;
name|unsigned
name|FieldNo
decl_stmt|;
name|unsigned
name|Start
decl_stmt|;
name|unsigned
name|Size
decl_stmt|;
block|}
struct|;
name|llvm
operator|::
name|SmallVector
operator|<
name|LLVMBitFieldInfo
operator|,
literal|16
operator|>
name|LLVMBitFields
expr_stmt|;
name|CGRecordLayoutBuilder
argument_list|(
name|CodeGenTypes
operator|&
name|Types
argument_list|)
operator|:
name|Types
argument_list|(
name|Types
argument_list|)
operator|,
name|Packed
argument_list|(
name|false
argument_list|)
operator|,
name|ContainsMemberPointer
argument_list|(
name|false
argument_list|)
operator|,
name|Alignment
argument_list|(
literal|0
argument_list|)
operator|,
name|AlignmentAsLLVMStruct
argument_list|(
literal|1
argument_list|)
operator|,
name|BitsAvailableInLastField
argument_list|(
literal|0
argument_list|)
operator|,
name|NextFieldOffsetInBytes
argument_list|(
literal|0
argument_list|)
block|{ }
comment|/// Layout - Will layout a RecordDecl.
name|void
name|Layout
argument_list|(
specifier|const
name|RecordDecl
operator|*
name|D
argument_list|)
expr_stmt|;
comment|/// LayoutUnion - Will layout a union RecordDecl.
name|void
name|LayoutUnion
parameter_list|(
specifier|const
name|RecordDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// LayoutField - try to layout all fields in the record decl.
comment|/// Returns false if the operation failed because the struct is not packed.
name|bool
name|LayoutFields
parameter_list|(
specifier|const
name|RecordDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// LayoutBases - layout the bases and vtable pointer of a record decl.
name|void
name|LayoutBases
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
specifier|const
name|ASTRecordLayout
modifier|&
name|Layout
parameter_list|)
function_decl|;
comment|/// LayoutField - layout a single field. Returns false if the operation failed
comment|/// because the current struct is not packed.
name|bool
name|LayoutField
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|D
parameter_list|,
name|uint64_t
name|FieldOffset
parameter_list|)
function_decl|;
comment|/// LayoutBitField - layout a single bit field.
name|void
name|LayoutBitField
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|D
parameter_list|,
name|uint64_t
name|FieldOffset
parameter_list|)
function_decl|;
comment|/// AppendField - Appends a field with the given offset and type.
name|void
name|AppendField
argument_list|(
name|uint64_t
name|FieldOffsetInBytes
argument_list|,
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|FieldTy
argument_list|)
decl_stmt|;
comment|/// AppendPadding - Appends enough padding bytes so that the total struct
comment|/// size matches the alignment of the passed in type.
name|void
name|AppendPadding
argument_list|(
name|uint64_t
name|FieldOffsetInBytes
argument_list|,
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|FieldTy
argument_list|)
decl_stmt|;
comment|/// AppendPadding - Appends enough padding bytes so that the total
comment|/// struct size is a multiple of the field alignment.
name|void
name|AppendPadding
parameter_list|(
name|uint64_t
name|FieldOffsetInBytes
parameter_list|,
name|unsigned
name|FieldAlignment
parameter_list|)
function_decl|;
comment|/// AppendBytes - Append a given number of bytes to the record.
name|void
name|AppendBytes
parameter_list|(
name|uint64_t
name|NumBytes
parameter_list|)
function_decl|;
comment|/// AppendTailPadding - Append enough tail padding so that the type will have
comment|/// the passed size.
name|void
name|AppendTailPadding
parameter_list|(
name|uint64_t
name|RecordSize
parameter_list|)
function_decl|;
name|unsigned
name|getTypeAlignment
argument_list|(
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
name|uint64_t
name|getTypeSizeInBytes
argument_list|(
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
comment|/// CheckForMemberPointer - Check if the field contains a member pointer.
name|void
name|CheckForMemberPointer
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
name|public
label|:
comment|/// ComputeLayout - Return the right record layout for a given record decl.
specifier|static
name|CGRecordLayout
modifier|*
name|ComputeLayout
parameter_list|(
name|CodeGenTypes
modifier|&
name|Types
parameter_list|,
specifier|const
name|RecordDecl
modifier|*
name|D
parameter_list|)
function_decl|;
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

