begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Core/ArchiveLibraryFile.h - Models static library ------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
name|LLD_CORE_ARCHIVE_LIBRARY_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_ARCHIVE_LIBRARY_FILE_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/File.h"
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
comment|///
comment|/// The ArchiveLibraryFile subclass of File is used to represent unix
comment|/// static library archives.  These libraries provide no atoms to the
comment|/// initial set of atoms linked.  Instead, when the Resolver will query
comment|/// ArchiveLibraryFile instances for specific symbols names using the
comment|/// find() method.  If the archive contains an object file which has a
comment|/// DefinedAtom whose scope is not translationUnit, then that entire
comment|/// object file File is returned.
comment|///
name|class
name|ArchiveLibraryFile
range|:
name|public
name|File
block|{
name|public
operator|:
specifier|static
name|bool
name|classof
argument_list|(
argument|const File *f
argument_list|)
block|{
return|return
name|f
operator|->
name|kind
argument_list|()
operator|==
name|kindArchiveLibrary
return|;
block|}
comment|/// Check if any member of the archive contains an Atom with the
comment|/// specified name and return the File object for that member, or nullptr.
name|virtual
name|File
operator|*
name|find
argument_list|(
argument|StringRef name
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|std
operator|::
name|error_code
name|parseAllMembers
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>>
operator|&
name|result
argument_list|)
operator|=
literal|0
block|;
name|protected
operator|:
comment|/// only subclasses of ArchiveLibraryFile can be instantiated
name|ArchiveLibraryFile
argument_list|(
argument|StringRef path
argument_list|)
operator|:
name|File
argument_list|(
argument|path
argument_list|,
argument|kindArchiveLibrary
argument_list|)
block|{}
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_CORE_ARCHIVE_LIBRARY_FILE_H
end_comment

end_unit

