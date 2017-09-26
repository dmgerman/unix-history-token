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
struct|struct
name|NewArchiveMember
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|Buf
expr_stmt|;
name|StringRef
name|MemberName
decl_stmt|;
name|sys
operator|::
name|TimePoint
operator|<
name|std
operator|::
name|chrono
operator|::
name|seconds
operator|>
name|ModTime
expr_stmt|;
name|unsigned
name|UID
init|=
literal|0
decl_stmt|,
name|GID
init|=
literal|0
decl_stmt|,
name|Perms
init|=
literal|0644
decl_stmt|;
name|bool
name|IsNew
init|=
name|false
decl_stmt|;
name|NewArchiveMember
argument_list|()
operator|=
expr|default
expr_stmt|;
name|NewArchiveMember
argument_list|(
argument|MemoryBufferRef BufRef
argument_list|)
empty_stmt|;
specifier|static
name|Expected
operator|<
name|NewArchiveMember
operator|>
name|getOldMember
argument_list|(
argument|const object::Archive::Child&OldMember
argument_list|,
argument|bool Deterministic
argument_list|)
expr_stmt|;
specifier|static
name|Expected
operator|<
name|NewArchiveMember
operator|>
name|getFile
argument_list|(
argument|StringRef FileName
argument_list|,
argument|bool Deterministic
argument_list|)
expr_stmt|;
block|}
struct|;
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
argument|std::vector<NewArchiveMember>&NewMembers
argument_list|,
argument|bool WriteSymtab
argument_list|,
argument|object::Archive::Kind Kind
argument_list|,
argument|bool Deterministic
argument_list|,
argument|bool Thin
argument_list|,
argument|std::unique_ptr<MemoryBuffer> OldArchiveBuf = nullptr
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

