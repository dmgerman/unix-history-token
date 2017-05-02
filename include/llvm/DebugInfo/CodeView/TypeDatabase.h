begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TypeDatabase.h - A collection of CodeView type records ---*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_TYPEDATABASE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_TYPEDATABASE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/StringSaver.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|TypeDatabase
block|{
name|public
label|:
name|TypeDatabase
argument_list|()
operator|:
name|TypeNameStorage
argument_list|(
argument|Allocator
argument_list|)
block|{}
comment|/// Gets the type index for the next type record.
name|TypeIndex
name|getNextTypeIndex
argument_list|()
specifier|const
expr_stmt|;
comment|/// Records the name of a type, and reserves its type index.
name|void
name|recordType
parameter_list|(
name|StringRef
name|Name
parameter_list|,
specifier|const
name|CVType
modifier|&
name|Data
parameter_list|)
function_decl|;
comment|/// Saves the name in a StringSet and creates a stable StringRef.
name|StringRef
name|saveTypeName
parameter_list|(
name|StringRef
name|TypeName
parameter_list|)
function_decl|;
name|StringRef
name|getTypeName
argument_list|(
name|TypeIndex
name|Index
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|CVType
modifier|&
name|getTypeRecord
argument_list|(
name|TypeIndex
name|Index
argument_list|)
decl|const
decl_stmt|;
name|CVType
modifier|&
name|getTypeRecord
parameter_list|(
name|TypeIndex
name|Index
parameter_list|)
function_decl|;
name|bool
name|containsTypeIndex
argument_list|(
name|TypeIndex
name|Index
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|size
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|BumpPtrAllocator
name|Allocator
decl_stmt|;
comment|/// All user defined type records in .debug$T live in here. Type indices
comment|/// greater than 0x1000 are user defined. Subtract 0x1000 from the index to
comment|/// index into this vector.
name|SmallVector
operator|<
name|StringRef
operator|,
literal|10
operator|>
name|CVUDTNames
expr_stmt|;
name|SmallVector
operator|<
name|CVType
operator|,
literal|10
operator|>
name|TypeRecords
expr_stmt|;
name|StringSaver
name|TypeNameStorage
decl_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

