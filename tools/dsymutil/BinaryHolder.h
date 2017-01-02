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
file|"llvm/ADT/Triple.h"
end_include

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
file|"llvm/Object/MachOUniversal.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Chrono.h"
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
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|object
operator|::
name|Archive
operator|>>
name|CurrentArchives
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
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|object
operator|::
name|ObjectFile
operator|>>
name|CurrentObjectFiles
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|object
operator|::
name|MachOUniversalBinary
operator|>
name|CurrentFatBinary
expr_stmt|;
name|std
operator|::
name|string
name|CurrentFatBinaryName
expr_stmt|;
name|bool
name|Verbose
decl_stmt|;
comment|/// Get the MemoryBufferRefs for the file specification in \p
comment|/// Filename from the current archive. Multiple buffers are returned
comment|/// when there are multiple architectures available for the
comment|/// requested file.
comment|///
comment|/// This function performs no system calls, it just looks up a
comment|/// potential match for the given \p Filename in the currently
comment|/// mapped archive if there is one.
name|ErrorOr
operator|<
name|std
operator|::
name|vector
operator|<
name|MemoryBufferRef
operator|>>
name|GetArchiveMemberBuffers
argument_list|(
argument|StringRef Filename
argument_list|,
argument|sys::TimePoint<std::chrono::seconds> Timestamp
argument_list|)
expr_stmt|;
comment|/// Interpret Filename as an archive member specification map the
comment|/// corresponding archive to memory and return the MemoryBufferRefs
comment|/// corresponding to the described member. Multiple buffers are
comment|/// returned when there are multiple architectures available for the
comment|/// requested file.
name|ErrorOr
operator|<
name|std
operator|::
name|vector
operator|<
name|MemoryBufferRef
operator|>>
name|MapArchiveAndGetMemberBuffers
argument_list|(
argument|StringRef Filename
argument_list|,
argument|sys::TimePoint<std::chrono::seconds> Timestamp
argument_list|)
expr_stmt|;
comment|/// Return the MemoryBufferRef that holds the memory mapping for the
comment|/// given \p Filename. This function will try to parse archive
comment|/// member specifications of the form /path/to/archive.a(member.o).
comment|///
comment|/// The returned MemoryBufferRefs points to a buffer owned by this
comment|/// object. The buffer is valid until the next call to
comment|/// GetMemoryBufferForFile() on this object.
comment|/// Multiple buffers are returned when there are multiple
comment|/// architectures available for the requested file.
name|ErrorOr
operator|<
name|std
operator|::
name|vector
operator|<
name|MemoryBufferRef
operator|>>
name|GetMemoryBuffersForFile
argument_list|(
argument|StringRef Filename
argument_list|,
argument|sys::TimePoint<std::chrono::seconds> Timestamp
argument_list|)
expr_stmt|;
name|void
name|changeBackingMemoryBuffer
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
operator|&&
name|MemBuf
argument_list|)
decl_stmt|;
name|ErrorOr
operator|<
specifier|const
name|object
operator|::
name|ObjectFile
operator|&
operator|>
name|getObjfileForArch
argument_list|(
specifier|const
name|Triple
operator|&
name|T
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
comment|/// Get the ObjectFiles designated by the \p Filename. This
comment|/// might be an archive member specification of the form
comment|/// /path/to/archive.a(member.o).
comment|///
comment|/// Calling this function invalidates the previous mapping owned by
comment|/// the BinaryHolder. Multiple buffers are returned when there are
comment|/// multiple architectures available for the requested file.
name|ErrorOr
operator|<
name|std
operator|::
name|vector
operator|<
specifier|const
name|object
operator|::
name|ObjectFile
operator|*
operator|>>
name|GetObjectFiles
argument_list|(
argument|StringRef Filename
argument_list|,
argument|sys::TimePoint<std::chrono::seconds> Timestamp =                      sys::TimePoint<std::chrono::seconds>()
argument_list|)
expr_stmt|;
comment|/// Wraps GetObjectFiles() to return a derived ObjectFile type.
name|template
operator|<
name|typename
name|ObjectFileType
operator|>
name|ErrorOr
operator|<
name|std
operator|::
name|vector
operator|<
specifier|const
name|ObjectFileType
operator|*
operator|>>
name|GetFilesAs
argument_list|(
argument|StringRef Filename
argument_list|,
argument|sys::TimePoint<std::chrono::seconds> Timestamp =                  sys::TimePoint<std::chrono::seconds>()
argument_list|)
block|{
name|auto
name|ErrOrObjFile
operator|=
name|GetObjectFiles
argument_list|(
name|Filename
argument_list|,
name|Timestamp
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
name|std
operator|::
name|vector
operator|<
specifier|const
name|ObjectFileType
operator|*
operator|>
name|Objects
expr_stmt|;
name|Objects
operator|.
name|reserve
argument_list|(
operator|(
operator|*
name|ErrOrObjFile
operator|)
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|Obj
range|:
operator|*
name|ErrOrObjFile
control|)
block|{
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
name|Obj
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|Derived
condition|)
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
name|Objects
operator|.
name|push_back
argument_list|(
name|Derived
argument_list|)
expr_stmt|;
block|}
return|return
name|std
operator|::
name|move
argument_list|(
name|Objects
argument_list|)
return|;
block|}
comment|/// Access the currently owned ObjectFile with architecture \p T. As
comment|/// successfull call to GetObjectFiles() or GetFilesAs() must have
comment|/// been performed before calling this.
name|ErrorOr
operator|<
specifier|const
name|object
operator|::
name|ObjectFile
operator|&
operator|>
name|Get
argument_list|(
argument|const Triple&T
argument_list|)
block|{
return|return
name|getObjfileForArch
argument_list|(
name|T
argument_list|)
return|;
block|}
comment|/// Access to a derived version of the currently owned
comment|/// ObjectFile. The conversion must be known to be valid.
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
name|GetAs
argument_list|(
argument|const Triple&T
argument_list|)
block|{
name|auto
name|ErrOrObj
operator|=
name|Get
argument_list|(
name|T
argument_list|)
block|;
if|if
condition|(
name|auto
name|Err
init|=
name|ErrOrObj
operator|.
name|getError
argument_list|()
condition|)
return|return
name|Err
return|;
return|return
name|cast
operator|<
name|ObjectFileType
operator|>
operator|(
operator|*
name|ErrOrObj
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|} }
endif|#
directive|endif
end_endif

end_unit

