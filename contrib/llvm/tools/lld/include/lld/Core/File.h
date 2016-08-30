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
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
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
name|kindErrorObject
block|,
comment|///< a error object file (.o)
name|kindNormalizedObject
block|,
comment|///< a normalized file (.o)
name|kindMachObject
block|,
comment|///< a MachO object file (.o)
name|kindCEntryObject
block|,
comment|///< a file for CEntries
name|kindHeaderObject
block|,
comment|///< a file for file headers
name|kindEntryObject
block|,
comment|///< a file for the entry
name|kindUndefinedSymsObject
block|,
comment|///< a file for undefined symbols
name|kindStubHelperObject
block|,
comment|///< a file for stub helpers
name|kindResolverMergedObject
block|,
comment|///< the resolver merged file.
name|kindSectCreateObject
block|,
comment|///< a sect create object file (.o)
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
name|OwningAtomPtr
operator|<
name|T
operator|>>
expr_stmt|;
comment|/// The range type for the atoms.
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
operator|&
name|v
argument_list|)
operator|:
name|_v
argument_list|(
argument|v
argument_list|)
block|{}
name|AtomRange
argument_list|(
specifier|const
name|AtomVector
operator|<
name|T
operator|>
operator|&
name|v
argument_list|)
operator|:
name|_v
argument_list|(
argument|const_cast<AtomVector<T>&>(v)
argument_list|)
block|{}
typedef|typedef
name|std
operator|::
name|pointer_to_unary_function
operator|<
specifier|const
name|OwningAtomPtr
operator|<
name|T
operator|>
operator|&
operator|,
specifier|const
name|T
operator|*
operator|>
name|ConstDerefFn
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pointer_to_unary_function
operator|<
name|OwningAtomPtr
operator|<
name|T
operator|>
operator|&
operator|,
name|T
operator|*
operator|>
name|DerefFn
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|mapped_iterator
operator|<
name|typename
name|AtomVector
operator|<
name|T
operator|>
operator|::
name|const_iterator
operator|,
name|ConstDerefFn
operator|>
name|ConstItTy
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|mapped_iterator
operator|<
name|typename
name|AtomVector
operator|<
name|T
operator|>
operator|::
name|iterator
operator|,
name|DerefFn
operator|>
name|ItTy
expr_stmt|;
specifier|static
specifier|const
name|T
modifier|*
name|DerefConst
argument_list|(
specifier|const
name|OwningAtomPtr
operator|<
name|T
operator|>
operator|&
name|p
argument_list|)
block|{
return|return
name|p
operator|.
name|get
argument_list|()
return|;
block|}
specifier|static
name|T
modifier|*
name|Deref
argument_list|(
name|OwningAtomPtr
operator|<
name|T
operator|>
operator|&
name|p
argument_list|)
block|{
return|return
name|p
operator|.
name|get
argument_list|()
return|;
block|}
name|ConstItTy
name|begin
argument_list|()
specifier|const
block|{
return|return
name|ConstItTy
argument_list|(
name|_v
operator|.
name|begin
argument_list|()
argument_list|,
name|ConstDerefFn
argument_list|(
name|DerefConst
argument_list|)
argument_list|)
return|;
block|}
name|ConstItTy
name|end
argument_list|()
specifier|const
block|{
return|return
name|ConstItTy
argument_list|(
name|_v
operator|.
name|end
argument_list|()
argument_list|,
name|ConstDerefFn
argument_list|(
name|DerefConst
argument_list|)
argument_list|)
return|;
block|}
name|ItTy
name|begin
parameter_list|()
block|{
return|return
name|ItTy
argument_list|(
name|_v
operator|.
name|begin
argument_list|()
argument_list|,
name|DerefFn
argument_list|(
name|Deref
argument_list|)
argument_list|)
return|;
block|}
name|ItTy
name|end
parameter_list|()
block|{
return|return
name|ItTy
argument_list|(
name|_v
operator|.
name|end
argument_list|()
argument_list|,
name|DerefFn
argument_list|(
name|Deref
argument_list|)
argument_list|)
return|;
block|}
name|llvm
operator|::
name|iterator_range
operator|<
name|typename
name|AtomVector
operator|<
name|T
operator|>
operator|::
name|iterator
operator|>
name|owning_ptrs
argument_list|()
block|{
return|return
name|llvm
operator|::
name|make_range
argument_list|(
name|_v
operator|.
name|begin
argument_list|()
argument_list|,
name|_v
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|llvm
operator|::
name|iterator_range
operator|<
name|typename
name|AtomVector
operator|<
name|T
operator|>
operator|::
name|iterator
operator|>
name|owning_ptrs
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|make_range
argument_list|(
name|_v
operator|.
name|begin
argument_list|()
argument_list|,
name|_v
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|_v
operator|.
name|empty
argument_list|()
return|;
block|}
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|_v
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|OwningAtomPtr
operator|<
name|T
operator|>
operator|&
name|operator
index|[]
operator|(
name|size_t
name|idx
operator|)
specifier|const
block|{
return|return
name|_v
index|[
name|idx
index|]
return|;
block|}
name|OwningAtomPtr
operator|<
name|T
operator|>
operator|&
name|operator
index|[]
operator|(
name|size_t
name|idx
operator|)
block|{
return|return
name|_v
index|[
name|idx
index|]
return|;
block|}
name|private
label|:
name|AtomVector
operator|<
name|T
operator|>
operator|&
name|_v
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Must be implemented to return the AtomVector object for
end_comment

begin_comment
comment|/// all DefinedAtoms in this File.
end_comment

begin_expr_stmt
name|virtual
specifier|const
name|AtomRange
operator|<
name|DefinedAtom
operator|>
name|defined
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Must be implemented to return the AtomVector object for
end_comment

begin_comment
comment|/// all UndefinedAtomw in this File.
end_comment

begin_expr_stmt
name|virtual
specifier|const
name|AtomRange
operator|<
name|UndefinedAtom
operator|>
name|undefined
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Must be implemented to return the AtomVector object for
end_comment

begin_comment
comment|/// all SharedLibraryAtoms in this File.
end_comment

begin_expr_stmt
name|virtual
specifier|const
name|AtomRange
operator|<
name|SharedLibraryAtom
operator|>
name|sharedLibrary
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Must be implemented to return the AtomVector object for
end_comment

begin_comment
comment|/// all AbsoluteAtoms in this File.
end_comment

begin_expr_stmt
name|virtual
specifier|const
name|AtomRange
operator|<
name|AbsoluteAtom
operator|>
name|absolute
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Drop all of the atoms owned by this file.  This will result in all of
end_comment

begin_comment
comment|/// the atoms running their destructors.
end_comment

begin_comment
comment|/// This is required because atoms may be allocated on a BumpPtrAllocator
end_comment

begin_comment
comment|/// of a different file.  We need to destruct all atoms before any files.
end_comment

begin_function_decl
name|virtual
name|void
name|clearAtoms
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// \brief If a file is parsed using a different method than doParse(),
end_comment

begin_comment
comment|/// one must use this method to set the last error status, so that
end_comment

begin_comment
comment|/// doParse will not be called twice. Only YAML reader uses this
end_comment

begin_comment
comment|/// (because YAML reader does not read blobs but structured data).
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|error_code
name|parse
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Usually each file owns a std::unique_ptr<MemoryBuffer>.
end_comment

begin_comment
comment|// However, there's one special case. If a file is an archive file,
end_comment

begin_comment
comment|// the archive file and its children all shares the same memory buffer.
end_comment

begin_comment
comment|// This method is used by the ArchiveFile to give its children
end_comment

begin_comment
comment|// co-ownership of the buffer.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// \brief only subclasses of File can be instantiated
end_comment

begin_macro
name|File
argument_list|(
argument|StringRef p
argument_list|,
argument|Kind kind
argument_list|)
end_macro

begin_expr_stmt
unit|:
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
end_expr_stmt

begin_expr_stmt
specifier|static
name|AtomVector
operator|<
name|DefinedAtom
operator|>
name|_noDefinedAtoms
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|AtomVector
operator|<
name|UndefinedAtom
operator|>
name|_noUndefinedAtoms
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|AtomVector
operator|<
name|SharedLibraryAtom
operator|>
name|_noSharedLibraryAtoms
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|AtomVector
operator|<
name|AbsoluteAtom
operator|>
name|_noAbsoluteAtoms
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|mutable
name|llvm
operator|::
name|BumpPtrAllocator
name|_allocator
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|StringRef
name|_path
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|_archivePath
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|mutable
name|std
operator|::
name|string
name|_archiveMemberPath
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Kind
name|_kind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mutable
name|uint64_t
name|_ordinal
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mutable
name|uint64_t
name|_nextAtomOrdinal
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|shared_ptr
operator|<
name|MemoryBuffer
operator|>
name|_sharedMemoryBuffer
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|mutex
name|_parseMutex
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
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
name|kindErrorObject
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
name|AtomRange
operator|<
name|DefinedAtom
operator|>
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
name|AtomRange
operator|<
name|UndefinedAtom
operator|>
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
name|AtomRange
operator|<
name|SharedLibraryAtom
operator|>
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
name|AtomRange
operator|<
name|AbsoluteAtom
operator|>
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
name|void
name|clearAtoms
argument_list|()
name|override
block|{   }
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

