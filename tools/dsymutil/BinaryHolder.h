begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BinaryHolder.h - Utility class for accessing binaries -------------===//
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
comment|// This program is a utility that aims to be a dropin replacement for
end_comment

begin_comment
comment|// Darwin's dsymutil.
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
name|LLVM_TOOLS_DSYMUTIL_BINARYHOLDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_DSYMUTIL_BINARYHOLDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Object/Archive.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Errc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|dsymutil
block|{
comment|/// \brief The BinaryHolder class is responsible for creating and
comment|/// owning ObjectFile objects and their underlying MemoryBuffer. This
comment|/// is different from a simple OwningBinary in that it handles
comment|/// accessing to archive members.
comment|///
comment|/// As an optimization, this class will reuse an already mapped and
comment|/// parsed Archive object if 2 successive requests target the same
comment|/// archive file (Which is always the case in debug maps).
comment|/// Currently it only owns one memory buffer at any given time,
comment|/// meaning that a mapping request will invalidate the previous memory
comment|/// mapping.
name|class
name|BinaryHolder
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|object
operator|::
name|Archive
operator|>
name|CurrentArchive
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|CurrentMemoryBuffer
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|object
operator|::
name|ObjectFile
operator|>
name|CurrentObjectFile
expr_stmt|;
name|bool
name|Verbose
decl_stmt|;
comment|/// \brief Get the MemoryBufferRef for the file specification in \p
comment|/// Filename from the current archive.
comment|///
comment|/// This function performs no system calls, it just looks up a
comment|/// potential match for the given \p Filename in the currently
comment|/// mapped archive if there is one.
name|ErrorOr
operator|<
name|MemoryBufferRef
operator|>
name|GetArchiveMemberBuffer
argument_list|(
argument|StringRef Filename
argument_list|)
expr_stmt|;
comment|/// \brief Interpret Filename as an archive member specification,
comment|/// map the corresponding archive to memory and return the
comment|/// MemoryBufferRef corresponding to the described member.
name|ErrorOr
operator|<
name|MemoryBufferRef
operator|>
name|MapArchiveAndGetMemberBuffer
argument_list|(
argument|StringRef Filename
argument_list|)
expr_stmt|;
comment|/// \brief Return the MemoryBufferRef that holds the memory
comment|/// mapping for the given \p Filename. This function will try to
comment|/// parse archive member specifications of the form
comment|/// /path/to/archive.a(member.o).
comment|///
comment|/// The returned MemoryBufferRef points to a buffer owned by this
comment|/// object. The buffer is valid until the next call to
comment|/// GetMemoryBufferForFile() on this object.
name|ErrorOr
operator|<
name|MemoryBufferRef
operator|>
name|GetMemoryBufferForFile
argument_list|(
argument|StringRef Filename
argument_list|)
expr_stmt|;
name|public
label|:
name|BinaryHolder
argument_list|(
argument|bool Verbose
argument_list|)
block|:
name|Verbose
argument_list|(
argument|Verbose
argument_list|)
block|{}
comment|/// \brief Get the ObjectFile designated by the \p Filename. This
comment|/// might be an archive member specification of the form
comment|/// /path/to/archive.a(member.o).
comment|///
comment|/// Calling this function invalidates the previous mapping owned by
comment|/// the BinaryHolder.
name|ErrorOr
operator|<
specifier|const
name|object
operator|::
name|ObjectFile
operator|&
operator|>
name|GetObjectFile
argument_list|(
argument|StringRef Filename
argument_list|)
expr_stmt|;
comment|/// \brief Wraps GetObjectFile() to return a derived ObjectFile type.
name|template
operator|<
name|typename
name|ObjectFileType
operator|>
name|ErrorOr
operator|<
specifier|const
name|ObjectFileType
operator|&
operator|>
name|GetFileAs
argument_list|(
argument|StringRef Filename
argument_list|)
block|{
name|auto
name|ErrOrObjFile
operator|=
name|GetObjectFile
argument_list|(
name|Filename
argument_list|)
block|;
if|if
condition|(
name|auto
name|Err
init|=
name|ErrOrObjFile
operator|.
name|getError
argument_list|()
condition|)
return|return
name|Err
return|;
if|if
condition|(
specifier|const
specifier|auto
modifier|*
name|Derived
init|=
name|dyn_cast
operator|<
name|ObjectFileType
operator|>
operator|(
name|CurrentObjectFile
operator|.
name|get
argument_list|()
operator|)
condition|)
return|return
operator|*
name|Derived
return|;
return|return
name|make_error_code
argument_list|(
name|object
operator|::
name|object_error
operator|::
name|invalid_file_type
argument_list|)
return|;
block|}
comment|/// \brief Access the currently owned ObjectFile. As successfull
comment|/// call to GetObjectFile() or GetFileAs() must have been performed
comment|/// before calling this.
specifier|const
name|object
operator|::
name|ObjectFile
operator|&
name|Get
argument_list|()
block|{
name|assert
argument_list|(
name|CurrentObjectFile
argument_list|)
block|;
return|return
operator|*
name|CurrentObjectFile
return|;
block|}
comment|/// \brief Access to a derived version of the currently owned
comment|/// ObjectFile. The conversion must be known to be valid.
name|template
operator|<
name|typename
name|ObjectFileType
operator|>
specifier|const
name|ObjectFileType
operator|&
name|GetAs
argument_list|()
block|{
return|return
name|cast
operator|<
name|ObjectFileType
operator|>
operator|(
operator|*
name|CurrentObjectFile
operator|)
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

