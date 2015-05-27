begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- LayoutOverrideSource.h --Override Record Layouts -----------------===//
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
name|LLVM_CLANG_FRONTEND_LAYOUTOVERRIDESOURCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_LAYOUTOVERRIDESOURCE_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ExternalASTSource.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief An external AST source that overrides the layout of
comment|/// a specified set of record types.
comment|///
comment|/// This class is used only for testing the ability of external AST sources
comment|/// to override the layout of record types. Its input is the output format
comment|/// of the command-line argument -fdump-record-layouts.
name|class
name|LayoutOverrideSource
range|:
name|public
name|ExternalASTSource
block|{
comment|/// \brief The layout of a given record.
block|struct
name|Layout
block|{
comment|/// \brief The size of the record.
name|uint64_t
name|Size
block|;
comment|/// \brief The alignment of the record.
name|uint64_t
name|Align
block|;
comment|/// \brief The offsets of the fields, in source order.
name|SmallVector
operator|<
name|uint64_t
block|,
literal|8
operator|>
name|FieldOffsets
block|;     }
block|;
comment|/// \brief The set of layouts that will be overridden.
name|llvm
operator|::
name|StringMap
operator|<
name|Layout
operator|>
name|Layouts
block|;
name|public
operator|:
comment|/// \brief Create a new AST source that overrides the layout of some
comment|/// set of record types.
comment|///
comment|/// The file is the result of passing -fdump-record-layouts to a file.
name|explicit
name|LayoutOverrideSource
argument_list|(
argument|StringRef Filename
argument_list|)
block|;
comment|/// \brief If this particular record type has an overridden layout,
comment|/// return that layout.
name|bool
name|layoutRecordType
argument_list|(
argument|const RecordDecl *Record
argument_list|,
argument|uint64_t&Size
argument_list|,
argument|uint64_t&Alignment
argument_list|,
argument|llvm::DenseMap<const FieldDecl *
argument_list|,
argument|uint64_t>&FieldOffsets
argument_list|,
argument|llvm::DenseMap<const CXXRecordDecl *
argument_list|,
argument|CharUnits>&BaseOffsets
argument_list|,
argument|llvm::DenseMap<const CXXRecordDecl *
argument_list|,
argument|CharUnits>&VirtualBaseOffsets
argument_list|)
name|override
block|;
comment|/// \brief Dump the overridden layouts.
name|void
name|dump
argument_list|()
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

