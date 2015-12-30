begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Core/File.h - A Container of Atoms ---------------------------------===//
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
name|LLD_CORE_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_FILE_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/AbsoluteAtom.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/DefinedAtom.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/SharedLibraryAtom.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/UndefinedAtom.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|LinkingContext
decl_stmt|;
comment|/// Every Atom is owned by some File. A common scenario is for a single
comment|/// object file (.o) to be parsed by some reader and produce a single
comment|/// File object that represents the content of that object file.
comment|///
comment|/// To iterate through the Atoms in a File there are four methods that
comment|/// return collections.  For instance to iterate through all the DefinedAtoms
comment|/// in a File object use:
comment|///      for (const DefinedAtoms *atom : file->defined()) {
comment|///      }
comment|///
comment|/// The Atom objects in a File are owned by the File object.  The Atom objects
comment|/// are destroyed when the File object is destroyed.
name|class
name|File
block|{
name|public
label|:
name|virtual
operator|~
name|File
argument_list|()
expr_stmt|;
comment|/// \brief Kinds of files that are supported.
enum|enum
name|Kind
block|{
name|kindObject
block|,
comment|///< object file (.o)
name|kindSharedLibrary
block|,
comment|///< shared library (.so)
name|kindArchiveLibrary
comment|///< archive (.a)
block|}
enum|;
comment|/// \brief Returns file kind.  Need for dyn_cast<> on File objects.
name|Kind
name|kind
argument_list|()
specifier|const
block|{
return|return
name|_kind
return|;
block|}
comment|/// This returns the path to the file which was used to create this object
comment|/// (e.g. "/tmp/foo.o"). If the file is a member of an archive file, the
comment|/// returned string includes the archive file name.
name|StringRef
name|path
argument_list|()
specifier|const
block|{
if|if
condition|(
name|_archivePath
operator|.
name|empty
argument_list|()
condition|)
return|return
name|_path
return|;
if|if
condition|(
name|_archiveMemberPath
operator|.
name|empty
argument_list|()
condition|)
name|_archiveMemberPath
operator|=
operator|(
name|_archivePath
operator|+
literal|"("
operator|+
name|_path
operator|+
literal|")"
operator|)
operator|.
name|str
argument_list|()
expr_stmt|;
return|return
name|_archiveMemberPath
return|;
block|}
comment|/// Returns the path of the archive file name if this file is instantiated
comment|/// from an archive file. Otherwise returns the empty string.
name|StringRef
name|archivePath
argument_list|()
specifier|const
block|{
return|return
name|_archivePath
return|;
block|}
name|void
name|setArchivePath
parameter_list|(
name|StringRef
name|path
parameter_list|)
block|{
name|_archivePath
operator|=
name|path
expr_stmt|;
block|}
comment|/// Returns the path name of this file. It doesn't include archive file name.
name|StringRef
name|memberPath
argument_list|()
specifier|const
block|{
return|return
name|_path
return|;
block|}
comment|/// Returns the command line order of the file.
name|uint64_t
name|ordinal
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|_ordinal
operator|!=
name|UINT64_MAX
argument_list|)
block|;
return|return
name|_ordinal
return|;
block|}
comment|/// Returns true/false depending on whether an ordinal has been set.
name|bool
name|hasOrdinal
argument_list|()
specifier|const
block|{
return|return
operator|(
name|_ordinal
operator|!=
name|UINT64_MAX
operator|)
return|;
block|}
comment|/// Sets the command line order of the file.
name|void
name|setOrdinal
argument_list|(
name|uint64_t
name|ordinal
argument_list|)
decl|const
block|{
name|_ordinal
operator|=
name|ordinal
expr_stmt|;
block|}
comment|/// Returns the ordinal for the next atom to be defined in this file.
name|uint64_t
name|getNextAtomOrdinalAndIncrement
argument_list|()
specifier|const
block|{
return|return
name|_nextAtomOrdinal
operator|++
return|;
block|}
comment|/// For allocating any objects owned by this File.
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|allocator
argument_list|()
specifier|const
block|{
return|return
name|_allocator
return|;
block|}
comment|/// The type of atom mutable container.
name|template
operator|<
name|typename
name|T
operator|>
name|using
name|AtomVector
operator|=
name|std
operator|::
name|vector
operator|<
specifier|const
name|T
operator|*
operator|>
expr_stmt|;
comment|/// The range type for the atoms. It's backed by a std::vector, but hides
comment|/// its member functions so that you can only call begin or end.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|AtomRange
block|{
name|public
operator|:
name|AtomRange
argument_list|(
name|AtomVector
operator|<
name|T
operator|>
name|v
argument_list|)
operator|:
name|_v
argument_list|(
argument|v
argument_list|)
block|{}
name|typename
name|AtomVector
operator|<
name|T
operator|>
operator|::
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|_v
operator|.
name|begin
argument_list|()
return|;
block|}
name|typename
name|AtomVector
operator|<
name|T
operator|>
operator|::
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|_v
operator|.
name|end
argument_list|()
return|;
block|}
name|typename
name|AtomVector
operator|<
name|T
operator|>
operator|::
name|iterator
name|begin
argument_list|()
block|{
return|return
name|_v
operator|.
name|begin
argument_list|()
return|;
block|}
name|typename
name|AtomVector
operator|<
name|T
operator|>
operator|::
name|iterator
name|end
argument_list|()
block|{
return|return
name|_v
operator|.
name|end
argument_list|()
return|;
block|}
name|private
operator|:
name|AtomVector
operator|<
name|T
operator|>
operator|&
name|_v
block|;   }
expr_stmt|;
comment|/// \brief Must be implemented to return the AtomVector object for
comment|/// all DefinedAtoms in this File.
name|virtual
specifier|const
name|AtomVector
operator|<
name|DefinedAtom
operator|>
operator|&
name|defined
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// \brief Must be implemented to return the AtomVector object for
comment|/// all UndefinedAtomw in this File.
name|virtual
specifier|const
name|AtomVector
operator|<
name|UndefinedAtom
operator|>
operator|&
name|undefined
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// \brief Must be implemented to return the AtomVector object for
comment|/// all SharedLibraryAtoms in this File.
name|virtual
specifier|const
name|AtomVector
operator|<
name|SharedLibraryAtom
operator|>
operator|&
name|sharedLibrary
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// \brief Must be implemented to return the AtomVector object for
comment|/// all AbsoluteAtoms in this File.
name|virtual
specifier|const
name|AtomVector
operator|<
name|AbsoluteAtom
operator|>
operator|&
name|absolute
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// \brief If a file is parsed using a different method than doParse(),
comment|/// one must use this method to set the last error status, so that
comment|/// doParse will not be called twice. Only YAML reader uses this
comment|/// (because YAML reader does not read blobs but structured data).
name|void
name|setLastError
argument_list|(
name|std
operator|::
name|error_code
name|err
argument_list|)
block|{
name|_lastError
operator|=
name|err
expr_stmt|;
block|}
name|std
operator|::
name|error_code
name|parse
argument_list|()
expr_stmt|;
comment|// This function is called just before the core linker tries to use
comment|// a file. Currently the PECOFF reader uses this to trigger the
comment|// driver to parse .drectve section (which contains command line options).
comment|// If you want to do something having side effects, don't do that in
comment|// doParse() because a file could be pre-loaded speculatively.
comment|// Use this hook instead.
name|virtual
name|void
name|beforeLink
parameter_list|()
block|{}
comment|// Usually each file owns a std::unique_ptr<MemoryBuffer>.
comment|// However, there's one special case. If a file is an archive file,
comment|// the archive file and its children all shares the same memory buffer.
comment|// This method is used by the ArchiveFile to give its children
comment|// co-ownership of the buffer.
name|void
name|setSharedMemoryBuffer
argument_list|(
name|std
operator|::
name|shared_ptr
operator|<
name|MemoryBuffer
operator|>
name|mb
argument_list|)
block|{
name|_sharedMemoryBuffer
operator|=
name|mb
expr_stmt|;
block|}
name|protected
label|:
comment|/// \brief only subclasses of File can be instantiated
name|File
argument_list|(
argument|StringRef p
argument_list|,
argument|Kind kind
argument_list|)
block|:
name|_path
argument_list|(
name|p
argument_list|)
operator|,
name|_kind
argument_list|(
name|kind
argument_list|)
operator|,
name|_ordinal
argument_list|(
name|UINT64_MAX
argument_list|)
operator|,
name|_nextAtomOrdinal
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// \brief Subclasses should override this method to parse the
comment|/// memory buffer passed to this file's constructor.
name|virtual
name|std
operator|::
name|error_code
name|doParse
argument_list|()
block|{
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
specifier|static
name|AtomVector
operator|<
name|DefinedAtom
operator|>
name|_noDefinedAtoms
expr_stmt|;
specifier|static
name|AtomVector
operator|<
name|UndefinedAtom
operator|>
name|_noUndefinedAtoms
expr_stmt|;
specifier|static
name|AtomVector
operator|<
name|SharedLibraryAtom
operator|>
name|_noSharedLibraryAtoms
expr_stmt|;
specifier|static
name|AtomVector
operator|<
name|AbsoluteAtom
operator|>
name|_noAbsoluteAtoms
expr_stmt|;
name|mutable
name|llvm
operator|::
name|BumpPtrAllocator
name|_allocator
expr_stmt|;
name|private
label|:
name|StringRef
name|_path
decl_stmt|;
name|std
operator|::
name|string
name|_archivePath
expr_stmt|;
name|mutable
name|std
operator|::
name|string
name|_archiveMemberPath
expr_stmt|;
name|Kind
name|_kind
decl_stmt|;
name|mutable
name|uint64_t
name|_ordinal
decl_stmt|;
name|mutable
name|uint64_t
name|_nextAtomOrdinal
decl_stmt|;
name|std
operator|::
name|shared_ptr
operator|<
name|MemoryBuffer
operator|>
name|_sharedMemoryBuffer
expr_stmt|;
name|llvm
operator|::
name|Optional
operator|<
name|std
operator|::
name|error_code
operator|>
name|_lastError
expr_stmt|;
name|std
operator|::
name|mutex
name|_parseMutex
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// An ErrorFile represents a file that doesn't exist.
end_comment

begin_comment
comment|/// If you try to parse a file which doesn't exist, an instance of this
end_comment

begin_comment
comment|/// class will be returned. That's parse method always returns an error.
end_comment

begin_comment
comment|/// This is useful to delay erroring on non-existent files, so that we
end_comment

begin_comment
comment|/// can do unit testing a driver using non-existing file paths.
end_comment

begin_decl_stmt
name|class
name|ErrorFile
range|:
name|public
name|File
block|{
name|public
operator|:
name|ErrorFile
argument_list|(
argument|StringRef path
argument_list|,
argument|std::error_code ec
argument_list|)
operator|:
name|File
argument_list|(
name|path
argument_list|,
name|kindObject
argument_list|)
block|,
name|_ec
argument_list|(
argument|ec
argument_list|)
block|{}
name|std
operator|::
name|error_code
name|doParse
argument_list|()
name|override
block|{
return|return
name|_ec
return|;
block|}
specifier|const
name|AtomVector
operator|<
name|DefinedAtom
operator|>
operator|&
name|defined
argument_list|()
specifier|const
name|override
block|{
name|llvm_unreachable
argument_list|(
literal|"internal error"
argument_list|)
block|;   }
specifier|const
name|AtomVector
operator|<
name|UndefinedAtom
operator|>
operator|&
name|undefined
argument_list|()
specifier|const
name|override
block|{
name|llvm_unreachable
argument_list|(
literal|"internal error"
argument_list|)
block|;   }
specifier|const
name|AtomVector
operator|<
name|SharedLibraryAtom
operator|>
operator|&
name|sharedLibrary
argument_list|()
specifier|const
name|override
block|{
name|llvm_unreachable
argument_list|(
literal|"internal error"
argument_list|)
block|;   }
specifier|const
name|AtomVector
operator|<
name|AbsoluteAtom
operator|>
operator|&
name|absolute
argument_list|()
specifier|const
name|override
block|{
name|llvm_unreachable
argument_list|(
literal|"internal error"
argument_list|)
block|;   }
name|private
operator|:
name|std
operator|::
name|error_code
name|_ec
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

