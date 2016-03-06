begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ArchiveWriter.h - ar archive file format writer ----------*- C++ -*-===//
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
comment|// Declares the writeArchive function for writing an archive file.
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
name|LLVM_OBJECT_ARCHIVEWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECT_ARCHIVEWRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/Archive.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FileSystem.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|NewArchiveIterator
block|{
name|bool
name|IsNewMember
decl_stmt|;
name|StringRef
name|Name
decl_stmt|;
name|object
operator|::
name|Archive
operator|::
name|Child
name|OldMember
expr_stmt|;
name|public
label|:
name|NewArchiveIterator
argument_list|(
argument|const object::Archive::Child&OldMember
argument_list|,
argument|StringRef Name
argument_list|)
empty_stmt|;
name|NewArchiveIterator
argument_list|(
argument|StringRef FileName
argument_list|)
empty_stmt|;
name|bool
name|isNewMember
argument_list|()
specifier|const
expr_stmt|;
name|StringRef
name|getName
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|object
operator|::
name|Archive
operator|::
name|Child
operator|&
name|getOld
argument_list|()
specifier|const
expr_stmt|;
name|StringRef
name|getNew
argument_list|()
specifier|const
expr_stmt|;
name|llvm
operator|::
name|ErrorOr
operator|<
name|int
operator|>
name|getFD
argument_list|(
argument|sys::fs::file_status&NewStatus
argument_list|)
specifier|const
expr_stmt|;
specifier|const
name|sys
operator|::
name|fs
operator|::
name|file_status
operator|&
name|getStatus
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
name|std
operator|::
name|pair
operator|<
name|StringRef
operator|,
name|std
operator|::
name|error_code
operator|>
name|writeArchive
argument_list|(
argument|StringRef ArcName
argument_list|,
argument|std::vector<NewArchiveIterator>&NewMembers
argument_list|,
argument|bool WriteSymtab
argument_list|,
argument|object::Archive::Kind Kind
argument_list|,
argument|bool Deterministic
argument_list|,
argument|bool Thin
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

