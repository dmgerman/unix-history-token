begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SourceManager.h - Track and cache source files ---------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the SourceManager interface.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// There are three different types of locations in a %file: a spelling
end_comment

begin_comment
comment|/// location, an expansion location, and a presumed location.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Given an example of:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// #define min(x, y) x< y ? x : y
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// and then later on a use of min:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// #line 17
end_comment

begin_comment
comment|/// return min(a, b);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The expansion location is the line in the source code where the macro
end_comment

begin_comment
comment|/// was expanded (the return statement), the spelling location is the
end_comment

begin_comment
comment|/// location in the source where the macro was originally defined,
end_comment

begin_comment
comment|/// and the presumed location is where the line directive states that
end_comment

begin_comment
comment|/// the line is 17, or any other line.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_BASIC_SOURCEMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_SOURCEMANAGER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/FileManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

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
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTReader
decl_stmt|;
name|class
name|ASTWriter
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|LineTableInfo
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
comment|/// \brief Public enums and private classes that are part of the
comment|/// SourceManager implementation.
comment|///
name|namespace
name|SrcMgr
block|{
comment|/// \brief Indicates whether a file or directory holds normal user code,
comment|/// system code, or system code which is implicitly 'extern "C"' in C++ mode.
comment|///
comment|/// Entire directories can be tagged with this (this is maintained by
comment|/// DirectoryLookup and friends) as can specific FileInfos when a \#pragma
comment|/// system_header is seen or in various other cases.
comment|///
enum|enum
name|CharacteristicKind
block|{
name|C_User
block|,
name|C_System
block|,
name|C_ExternCSystem
block|}
enum|;
comment|/// \brief One instance of this struct is kept for every file loaded or used.
comment|///
comment|/// This object owns the MemoryBuffer object.
name|class
name|LLVM_ALIGNAS
argument_list|(
literal|8
argument_list|)
name|ContentCache
block|{
enum|enum
name|CCFlags
block|{
comment|/// \brief Whether the buffer is invalid.
name|InvalidFlag
init|=
literal|0x01
block|,
comment|/// \brief Whether the buffer should not be freed on destruction.
name|DoNotFreeFlag
init|=
literal|0x02
block|}
enum|;
comment|/// \brief The actual buffer containing the characters from the input
comment|/// file.
comment|///
comment|/// This is owned by the ContentCache object.  The bits indicate
comment|/// whether the buffer is invalid.
name|mutable
name|llvm
operator|::
name|PointerIntPair
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|*
operator|,
literal|2
operator|>
name|Buffer
expr_stmt|;
name|public
label|:
comment|/// \brief Reference to the file entry representing this ContentCache.
comment|///
comment|/// This reference does not own the FileEntry object.
comment|///
comment|/// It is possible for this to be NULL if the ContentCache encapsulates
comment|/// an imaginary text buffer.
specifier|const
name|FileEntry
modifier|*
name|OrigEntry
decl_stmt|;
comment|/// \brief References the file which the contents were actually loaded from.
comment|///
comment|/// Can be different from 'Entry' if we overridden the contents of one file
comment|/// with the contents of another file.
specifier|const
name|FileEntry
modifier|*
name|ContentsEntry
decl_stmt|;
comment|/// \brief A bump pointer allocated array of offsets for each source line.
comment|///
comment|/// This is lazily computed.  This is owned by the SourceManager
comment|/// BumpPointerAllocator object.
name|unsigned
modifier|*
name|SourceLineCache
decl_stmt|;
comment|/// \brief The number of lines in this ContentCache.
comment|///
comment|/// This is only valid if SourceLineCache is non-null.
name|unsigned
name|NumLines
decl_stmt|;
comment|/// \brief Indicates whether the buffer itself was provided to override
comment|/// the actual file contents.
comment|///
comment|/// When true, the original entry may be a virtual file that does not
comment|/// exist.
name|unsigned
name|BufferOverridden
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this content cache was initially created for a source
comment|/// file considered as a system one.
name|unsigned
name|IsSystemFile
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this file may be transient, that is, if it might not
comment|/// exist at some later point in time when this content entry is used,
comment|/// after serialization and deserialization.
name|unsigned
name|IsTransient
range|:
literal|1
decl_stmt|;
name|ContentCache
argument_list|(
specifier|const
name|FileEntry
operator|*
name|Ent
operator|=
name|nullptr
argument_list|)
operator|:
name|ContentCache
argument_list|(
argument|Ent
argument_list|,
argument|Ent
argument_list|)
block|{}
name|ContentCache
argument_list|(
specifier|const
name|FileEntry
operator|*
name|Ent
argument_list|,
specifier|const
name|FileEntry
operator|*
name|contentEnt
argument_list|)
operator|:
name|Buffer
argument_list|(
name|nullptr
argument_list|,
name|false
argument_list|)
operator|,
name|OrigEntry
argument_list|(
name|Ent
argument_list|)
operator|,
name|ContentsEntry
argument_list|(
name|contentEnt
argument_list|)
operator|,
name|SourceLineCache
argument_list|(
name|nullptr
argument_list|)
operator|,
name|NumLines
argument_list|(
literal|0
argument_list|)
operator|,
name|BufferOverridden
argument_list|(
name|false
argument_list|)
operator|,
name|IsSystemFile
argument_list|(
name|false
argument_list|)
operator|,
name|IsTransient
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// The copy ctor does not allow copies where source object has either
comment|/// a non-NULL Buffer or SourceLineCache.  Ownership of allocated memory
comment|/// is not transferred, so this is a logical error.
name|ContentCache
argument_list|(
specifier|const
name|ContentCache
operator|&
name|RHS
argument_list|)
operator|:
name|Buffer
argument_list|(
name|nullptr
argument_list|,
name|false
argument_list|)
operator|,
name|SourceLineCache
argument_list|(
name|nullptr
argument_list|)
operator|,
name|BufferOverridden
argument_list|(
name|false
argument_list|)
operator|,
name|IsSystemFile
argument_list|(
name|false
argument_list|)
operator|,
name|IsTransient
argument_list|(
argument|false
argument_list|)
block|{
name|OrigEntry
operator|=
name|RHS
operator|.
name|OrigEntry
block|;
name|ContentsEntry
operator|=
name|RHS
operator|.
name|ContentsEntry
block|;
name|assert
argument_list|(
name|RHS
operator|.
name|Buffer
operator|.
name|getPointer
argument_list|()
operator|==
name|nullptr
operator|&&
name|RHS
operator|.
name|SourceLineCache
operator|==
name|nullptr
operator|&&
literal|"Passed ContentCache object cannot own a buffer."
argument_list|)
block|;
name|NumLines
operator|=
name|RHS
operator|.
name|NumLines
block|;     }
name|ContentCache
operator|&
name|operator
operator|=
operator|(
specifier|const
name|ContentCache
operator|&
name|RHS
operator|)
operator|=
name|delete
expr_stmt|;
operator|~
name|ContentCache
argument_list|()
expr_stmt|;
comment|/// \brief Returns the memory buffer for the associated content.
comment|///
comment|/// \param Diag Object through which diagnostics will be emitted if the
comment|///   buffer cannot be retrieved.
comment|///
comment|/// \param Loc If specified, is the location that invalid file diagnostics
comment|///   will be emitted at.
comment|///
comment|/// \param Invalid If non-NULL, will be set \c true if an error occurred.
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|getBuffer
argument_list|(
argument|DiagnosticsEngine&Diag
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|SourceLocation Loc = SourceLocation()
argument_list|,
argument|bool *Invalid = nullptr
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Returns the size of the content encapsulated by this
comment|/// ContentCache.
comment|///
comment|/// This can be the size of the source file or the size of an
comment|/// arbitrary scratch buffer.  If the ContentCache encapsulates a source
comment|/// file this size is retrieved from the file's FileEntry.
name|unsigned
name|getSize
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns the number of bytes actually mapped for this
comment|/// ContentCache.
comment|///
comment|/// This can be 0 if the MemBuffer was not actually expanded.
name|unsigned
name|getSizeBytesMapped
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns the kind of memory used to back the memory buffer for
comment|/// this content cache.  This is used for performance analysis.
name|llvm
operator|::
name|MemoryBuffer
operator|::
name|BufferKind
name|getMemoryBufferKind
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setBuffer
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|B
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|Buffer
operator|.
name|getPointer
argument_list|()
operator|&&
literal|"MemoryBuffer already set."
argument_list|)
expr_stmt|;
name|Buffer
operator|.
name|setPointer
argument_list|(
name|B
operator|.
name|release
argument_list|()
argument_list|)
expr_stmt|;
name|Buffer
operator|.
name|setInt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Get the underlying buffer, returning NULL if the buffer is not
comment|/// yet available.
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|getRawBuffer
argument_list|()
specifier|const
block|{
return|return
name|Buffer
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// \brief Replace the existing buffer (which will be deleted)
comment|/// with the given buffer.
name|void
name|replaceBuffer
argument_list|(
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|B
argument_list|,
name|bool
name|DoNotFree
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// \brief Determine whether the buffer itself is invalid.
name|bool
name|isBufferInvalid
argument_list|()
specifier|const
block|{
return|return
name|Buffer
operator|.
name|getInt
argument_list|()
operator|&
name|InvalidFlag
return|;
block|}
comment|/// \brief Determine whether the buffer should be freed.
name|bool
name|shouldFreeBuffer
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Buffer
operator|.
name|getInt
argument_list|()
operator|&
name|DoNotFreeFlag
operator|)
operator|==
literal|0
return|;
block|}
block|}
empty_stmt|;
comment|// Assert that the \c ContentCache objects will always be 8-byte aligned so
comment|// that we can pack 3 bits of integer into pointers to such objects.
name|static_assert
argument_list|(
name|alignof
argument_list|(
name|ContentCache
argument_list|)
operator|>=
literal|8
argument_list|,
literal|"ContentCache must be 8-byte aligned."
argument_list|)
expr_stmt|;
comment|/// \brief Information about a FileID, basically just the logical file
comment|/// that it represents and include stack information.
comment|///
comment|/// Each FileInfo has include stack information, indicating where it came
comment|/// from. This information encodes the \#include chain that a token was
comment|/// expanded from. The main include file has an invalid IncludeLoc.
comment|///
comment|/// FileInfos contain a "ContentCache *", with the contents of the file.
comment|///
name|class
name|FileInfo
block|{
comment|/// \brief The location of the \#include that brought in this file.
comment|///
comment|/// This is an invalid SLOC for the main file (top of the \#include chain).
name|unsigned
name|IncludeLoc
decl_stmt|;
comment|// Really a SourceLocation
comment|/// \brief Number of FileIDs (files and macros) that were created during
comment|/// preprocessing of this \#include, including this SLocEntry.
comment|///
comment|/// Zero means the preprocessor didn't provide such info for this SLocEntry.
name|unsigned
name|NumCreatedFIDs
decl_stmt|;
comment|/// \brief Contains the ContentCache* and the bits indicating the
comment|/// characteristic of the file and whether it has \#line info, all
comment|/// bitmangled together.
name|uintptr_t
name|Data
decl_stmt|;
name|friend
name|class
name|clang
operator|::
name|SourceManager
expr_stmt|;
name|friend
name|class
name|clang
operator|::
name|ASTWriter
expr_stmt|;
name|friend
name|class
name|clang
operator|::
name|ASTReader
expr_stmt|;
name|public
label|:
comment|/// \brief Return a FileInfo object.
specifier|static
name|FileInfo
name|get
parameter_list|(
name|SourceLocation
name|IL
parameter_list|,
specifier|const
name|ContentCache
modifier|*
name|Con
parameter_list|,
name|CharacteristicKind
name|FileCharacter
parameter_list|)
block|{
name|FileInfo
name|X
decl_stmt|;
name|X
operator|.
name|IncludeLoc
operator|=
name|IL
operator|.
name|getRawEncoding
argument_list|()
expr_stmt|;
name|X
operator|.
name|NumCreatedFIDs
operator|=
literal|0
expr_stmt|;
name|X
operator|.
name|Data
operator|=
operator|(
name|uintptr_t
operator|)
name|Con
expr_stmt|;
name|assert
argument_list|(
operator|(
name|X
operator|.
name|Data
operator|&
literal|7
operator|)
operator|==
literal|0
operator|&&
literal|"ContentCache pointer insufficiently aligned"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|unsigned
operator|)
name|FileCharacter
operator|<
literal|4
operator|&&
literal|"invalid file character"
argument_list|)
expr_stmt|;
name|X
operator|.
name|Data
operator||=
operator|(
name|unsigned
operator|)
name|FileCharacter
expr_stmt|;
return|return
name|X
return|;
block|}
name|SourceLocation
name|getIncludeLoc
argument_list|()
specifier|const
block|{
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|IncludeLoc
argument_list|)
return|;
block|}
specifier|const
name|ContentCache
operator|*
name|getContentCache
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|ContentCache
operator|*
operator|>
operator|(
name|Data
operator|&
operator|~
name|uintptr_t
argument_list|(
literal|7
argument_list|)
operator|)
return|;
block|}
comment|/// \brief Return whether this is a system header or not.
name|CharacteristicKind
name|getFileCharacteristic
argument_list|()
specifier|const
block|{
return|return
call|(
name|CharacteristicKind
call|)
argument_list|(
name|Data
operator|&
literal|3
argument_list|)
return|;
block|}
comment|/// \brief Return true if this FileID has \#line directives in it.
name|bool
name|hasLineDirectives
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Data
operator|&
literal|4
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// \brief Set the flag that indicates that this FileID has
comment|/// line table entries associated with it.
name|void
name|setHasLineDirectives
parameter_list|()
block|{
name|Data
operator||=
literal|4
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// \brief Each ExpansionInfo encodes the expansion location - where
comment|/// the token was ultimately expanded, and the SpellingLoc - where the actual
comment|/// character data for the token came from.
name|class
name|ExpansionInfo
block|{
comment|// Really these are all SourceLocations.
comment|/// \brief Where the spelling for the token can be found.
name|unsigned
name|SpellingLoc
decl_stmt|;
comment|/// In a macro expansion, ExpansionLocStart and ExpansionLocEnd
comment|/// indicate the start and end of the expansion. In object-like macros,
comment|/// they will be the same. In a function-like macro expansion, the start
comment|/// will be the identifier and the end will be the ')'. Finally, in
comment|/// macro-argument instantiations, the end will be 'SourceLocation()', an
comment|/// invalid location.
name|unsigned
name|ExpansionLocStart
decl_stmt|,
name|ExpansionLocEnd
decl_stmt|;
name|public
label|:
name|SourceLocation
name|getSpellingLoc
argument_list|()
specifier|const
block|{
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|SpellingLoc
argument_list|)
return|;
block|}
name|SourceLocation
name|getExpansionLocStart
argument_list|()
specifier|const
block|{
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|ExpansionLocStart
argument_list|)
return|;
block|}
name|SourceLocation
name|getExpansionLocEnd
argument_list|()
specifier|const
block|{
name|SourceLocation
name|EndLoc
operator|=
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|ExpansionLocEnd
argument_list|)
block|;
return|return
name|EndLoc
operator|.
name|isInvalid
argument_list|()
condition|?
name|getExpansionLocStart
argument_list|()
else|:
name|EndLoc
return|;
block|}
name|std
operator|::
name|pair
operator|<
name|SourceLocation
operator|,
name|SourceLocation
operator|>
name|getExpansionLocRange
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|getExpansionLocStart
argument_list|()
argument_list|,
name|getExpansionLocEnd
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|isMacroArgExpansion
argument_list|()
specifier|const
block|{
comment|// Note that this needs to return false for default constructed objects.
return|return
name|getExpansionLocStart
argument_list|()
operator|.
name|isValid
argument_list|()
operator|&&
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|ExpansionLocEnd
argument_list|)
operator|.
name|isInvalid
argument_list|()
return|;
block|}
name|bool
name|isMacroBodyExpansion
argument_list|()
specifier|const
block|{
return|return
name|getExpansionLocStart
argument_list|()
operator|.
name|isValid
argument_list|()
operator|&&
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|ExpansionLocEnd
argument_list|)
operator|.
name|isValid
argument_list|()
return|;
block|}
name|bool
name|isFunctionMacroExpansion
argument_list|()
specifier|const
block|{
return|return
name|getExpansionLocStart
argument_list|()
operator|.
name|isValid
argument_list|()
operator|&&
name|getExpansionLocStart
argument_list|()
operator|!=
name|getExpansionLocEnd
argument_list|()
return|;
block|}
comment|/// \brief Return a ExpansionInfo for an expansion.
comment|///
comment|/// Start and End specify the expansion range (where the macro is
comment|/// expanded), and SpellingLoc specifies the spelling location (where
comment|/// the characters from the token come from). All three can refer to
comment|/// normal File SLocs or expansion locations.
specifier|static
name|ExpansionInfo
name|create
parameter_list|(
name|SourceLocation
name|SpellingLoc
parameter_list|,
name|SourceLocation
name|Start
parameter_list|,
name|SourceLocation
name|End
parameter_list|)
block|{
name|ExpansionInfo
name|X
decl_stmt|;
name|X
operator|.
name|SpellingLoc
operator|=
name|SpellingLoc
operator|.
name|getRawEncoding
argument_list|()
expr_stmt|;
name|X
operator|.
name|ExpansionLocStart
operator|=
name|Start
operator|.
name|getRawEncoding
argument_list|()
expr_stmt|;
name|X
operator|.
name|ExpansionLocEnd
operator|=
name|End
operator|.
name|getRawEncoding
argument_list|()
expr_stmt|;
return|return
name|X
return|;
block|}
comment|/// \brief Return a special ExpansionInfo for the expansion of
comment|/// a macro argument into a function-like macro's body.
comment|///
comment|/// ExpansionLoc specifies the expansion location (where the macro is
comment|/// expanded). This doesn't need to be a range because a macro is always
comment|/// expanded at a macro parameter reference, and macro parameters are
comment|/// always exactly one token. SpellingLoc specifies the spelling location
comment|/// (where the characters from the token come from). ExpansionLoc and
comment|/// SpellingLoc can both refer to normal File SLocs or expansion locations.
comment|///
comment|/// Given the code:
comment|/// \code
comment|///   #define F(x) f(x)
comment|///   F(42);
comment|/// \endcode
comment|///
comment|/// When expanding '\c F(42)', the '\c x' would call this with an
comment|/// SpellingLoc pointing at '\c 42' and an ExpansionLoc pointing at its
comment|/// location in the definition of '\c F'.
specifier|static
name|ExpansionInfo
name|createForMacroArg
parameter_list|(
name|SourceLocation
name|SpellingLoc
parameter_list|,
name|SourceLocation
name|ExpansionLoc
parameter_list|)
block|{
comment|// We store an intentionally invalid source location for the end of the
comment|// expansion range to mark that this is a macro argument ion rather than
comment|// a normal one.
return|return
name|create
argument_list|(
name|SpellingLoc
argument_list|,
name|ExpansionLoc
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief This is a discriminated union of FileInfo and ExpansionInfo.
comment|///
comment|/// SourceManager keeps an array of these objects, and they are uniquely
comment|/// identified by the FileID datatype.
name|class
name|SLocEntry
block|{
name|unsigned
name|Offset
range|:
literal|31
decl_stmt|;
name|unsigned
name|IsExpansion
range|:
literal|1
decl_stmt|;
union|union
block|{
name|FileInfo
name|File
decl_stmt|;
name|ExpansionInfo
name|Expansion
decl_stmt|;
block|}
union|;
name|public
label|:
name|unsigned
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
name|bool
name|isExpansion
argument_list|()
specifier|const
block|{
return|return
name|IsExpansion
return|;
block|}
name|bool
name|isFile
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isExpansion
argument_list|()
return|;
block|}
specifier|const
name|FileInfo
operator|&
name|getFile
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isFile
argument_list|()
operator|&&
literal|"Not a file SLocEntry!"
argument_list|)
block|;
return|return
name|File
return|;
block|}
specifier|const
name|ExpansionInfo
operator|&
name|getExpansion
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isExpansion
argument_list|()
operator|&&
literal|"Not a macro expansion SLocEntry!"
argument_list|)
block|;
return|return
name|Expansion
return|;
block|}
specifier|static
name|SLocEntry
name|get
parameter_list|(
name|unsigned
name|Offset
parameter_list|,
specifier|const
name|FileInfo
modifier|&
name|FI
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
operator|(
name|Offset
operator|&
operator|(
literal|1
operator|<<
literal|31
operator|)
operator|)
operator|&&
literal|"Offset is too large"
argument_list|)
expr_stmt|;
name|SLocEntry
name|E
decl_stmt|;
name|E
operator|.
name|Offset
operator|=
name|Offset
expr_stmt|;
name|E
operator|.
name|IsExpansion
operator|=
name|false
expr_stmt|;
name|E
operator|.
name|File
operator|=
name|FI
expr_stmt|;
return|return
name|E
return|;
block|}
specifier|static
name|SLocEntry
name|get
parameter_list|(
name|unsigned
name|Offset
parameter_list|,
specifier|const
name|ExpansionInfo
modifier|&
name|Expansion
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
operator|(
name|Offset
operator|&
operator|(
literal|1
operator|<<
literal|31
operator|)
operator|)
operator|&&
literal|"Offset is too large"
argument_list|)
expr_stmt|;
name|SLocEntry
name|E
decl_stmt|;
name|E
operator|.
name|Offset
operator|=
name|Offset
expr_stmt|;
name|E
operator|.
name|IsExpansion
operator|=
name|true
expr_stmt|;
name|E
operator|.
name|Expansion
operator|=
name|Expansion
expr_stmt|;
return|return
name|E
return|;
block|}
block|}
empty_stmt|;
block|}
comment|// end SrcMgr namespace.
comment|/// \brief External source of source location entries.
name|class
name|ExternalSLocEntrySource
block|{
name|public
label|:
name|virtual
operator|~
name|ExternalSLocEntrySource
argument_list|()
expr_stmt|;
comment|/// \brief Read the source location entry with index ID, which will always be
comment|/// less than -1.
comment|///
comment|/// \returns true if an error occurred that prevented the source-location
comment|/// entry from being loaded.
name|virtual
name|bool
name|ReadSLocEntry
parameter_list|(
name|int
name|ID
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Retrieve the module import location and name for the given ID, if
comment|/// in fact it was loaded from a module (rather than, say, a precompiled
comment|/// header).
name|virtual
name|std
operator|::
name|pair
operator|<
name|SourceLocation
operator|,
name|StringRef
operator|>
name|getModuleImportLoc
argument_list|(
argument|int ID
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief Holds the cache used by isBeforeInTranslationUnit.
comment|///
comment|/// The cache structure is complex enough to be worth breaking out of
comment|/// SourceManager.
name|class
name|InBeforeInTUCacheEntry
block|{
comment|/// \brief The FileID's of the cached query.
comment|///
comment|/// If these match up with a subsequent query, the result can be reused.
name|FileID
name|LQueryFID
decl_stmt|,
name|RQueryFID
decl_stmt|;
comment|/// \brief True if LQueryFID was created before RQueryFID.
comment|///
comment|/// This is used to compare macro expansion locations.
name|bool
name|IsLQFIDBeforeRQFID
decl_stmt|;
comment|/// \brief The file found in common between the two \#include traces, i.e.,
comment|/// the nearest common ancestor of the \#include tree.
name|FileID
name|CommonFID
decl_stmt|;
comment|/// \brief The offset of the previous query in CommonFID.
comment|///
comment|/// Usually, this represents the location of the \#include for QueryFID, but
comment|/// if LQueryFID is a parent of RQueryFID (or vice versa) then these can be a
comment|/// random token in the parent.
name|unsigned
name|LCommonOffset
decl_stmt|,
name|RCommonOffset
decl_stmt|;
name|public
label|:
comment|/// \brief Return true if the currently cached values match up with
comment|/// the specified LHS/RHS query.
comment|///
comment|/// If not, we can't use the cache.
name|bool
name|isCacheValid
argument_list|(
name|FileID
name|LHS
argument_list|,
name|FileID
name|RHS
argument_list|)
decl|const
block|{
return|return
name|LQueryFID
operator|==
name|LHS
operator|&&
name|RQueryFID
operator|==
name|RHS
return|;
block|}
comment|/// \brief If the cache is valid, compute the result given the
comment|/// specified offsets in the LHS/RHS FileID's.
name|bool
name|getCachedResult
argument_list|(
name|unsigned
name|LOffset
argument_list|,
name|unsigned
name|ROffset
argument_list|)
decl|const
block|{
comment|// If one of the query files is the common file, use the offset.  Otherwise,
comment|// use the #include loc in the common file.
if|if
condition|(
name|LQueryFID
operator|!=
name|CommonFID
condition|)
name|LOffset
operator|=
name|LCommonOffset
expr_stmt|;
if|if
condition|(
name|RQueryFID
operator|!=
name|CommonFID
condition|)
name|ROffset
operator|=
name|RCommonOffset
expr_stmt|;
comment|// It is common for multiple macro expansions to be "included" from the same
comment|// location (expansion location), in which case use the order of the FileIDs
comment|// to determine which came first. This will also take care the case where
comment|// one of the locations points at the inclusion/expansion point of the other
comment|// in which case its FileID will come before the other.
if|if
condition|(
name|LOffset
operator|==
name|ROffset
condition|)
return|return
name|IsLQFIDBeforeRQFID
return|;
return|return
name|LOffset
operator|<
name|ROffset
return|;
block|}
comment|/// \brief Set up a new query.
name|void
name|setQueryFIDs
parameter_list|(
name|FileID
name|LHS
parameter_list|,
name|FileID
name|RHS
parameter_list|,
name|bool
name|isLFIDBeforeRFID
parameter_list|)
block|{
name|assert
argument_list|(
name|LHS
operator|!=
name|RHS
argument_list|)
expr_stmt|;
name|LQueryFID
operator|=
name|LHS
expr_stmt|;
name|RQueryFID
operator|=
name|RHS
expr_stmt|;
name|IsLQFIDBeforeRQFID
operator|=
name|isLFIDBeforeRFID
expr_stmt|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|LQueryFID
operator|=
name|RQueryFID
operator|=
name|FileID
argument_list|()
expr_stmt|;
name|IsLQFIDBeforeRQFID
operator|=
name|false
expr_stmt|;
block|}
name|void
name|setCommonLoc
parameter_list|(
name|FileID
name|commonFID
parameter_list|,
name|unsigned
name|lCommonOffset
parameter_list|,
name|unsigned
name|rCommonOffset
parameter_list|)
block|{
name|CommonFID
operator|=
name|commonFID
expr_stmt|;
name|LCommonOffset
operator|=
name|lCommonOffset
expr_stmt|;
name|RCommonOffset
operator|=
name|rCommonOffset
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// \brief The stack used when building modules on demand, which is used
comment|/// to provide a link between the source managers of the different compiler
comment|/// instances.
typedef|typedef
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|FullSourceLoc
operator|>>
name|ModuleBuildStack
expr_stmt|;
comment|/// \brief This class handles loading and caching of source files into memory.
comment|///
comment|/// This object owns the MemoryBuffer objects for all of the loaded
comment|/// files and assigns unique FileID's for each unique \#include chain.
comment|///
comment|/// The SourceManager can be queried for information about SourceLocation
comment|/// objects, turning them into either spelling or expansion locations. Spelling
comment|/// locations represent where the bytes corresponding to a token came from and
comment|/// expansion locations represent where the location is in the user's view. In
comment|/// the case of a macro expansion, for example, the spelling location indicates
comment|/// where the expanded token came from and the expansion location specifies
comment|/// where it was expanded.
name|class
name|SourceManager
range|:
name|public
name|RefCountedBase
operator|<
name|SourceManager
operator|>
block|{
comment|/// \brief DiagnosticsEngine object.
name|DiagnosticsEngine
operator|&
name|Diag
block|;
name|FileManager
operator|&
name|FileMgr
block|;
name|mutable
name|llvm
operator|::
name|BumpPtrAllocator
name|ContentCacheAlloc
block|;
comment|/// \brief Memoized information about all of the files tracked by this
comment|/// SourceManager.
comment|///
comment|/// This map allows us to merge ContentCache entries based
comment|/// on their FileEntry*.  All ContentCache objects will thus have unique,
comment|/// non-null, FileEntry pointers.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FileEntry
operator|*
block|,
name|SrcMgr
operator|::
name|ContentCache
operator|*
operator|>
name|FileInfos
block|;
comment|/// \brief True if the ContentCache for files that are overridden by other
comment|/// files, should report the original file name. Defaults to true.
name|bool
name|OverridenFilesKeepOriginalName
block|;
comment|/// \brief True if non-system source files should be treated as volatile
comment|/// (likely to change while trying to use them). Defaults to false.
name|bool
name|UserFilesAreVolatile
block|;
comment|/// \brief True if all files read during this compilation should be treated
comment|/// as transient (may not be present in later compilations using a module
comment|/// file created from this compilation). Defaults to false.
name|bool
name|FilesAreTransient
block|;    struct
name|OverriddenFilesInfoTy
block|{
comment|/// \brief Files that have been overridden with the contents from another
comment|/// file.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FileEntry
operator|*
block|,
specifier|const
name|FileEntry
operator|*
operator|>
name|OverriddenFiles
block|;
comment|/// \brief Files that were overridden with a memory buffer.
name|llvm
operator|::
name|DenseSet
operator|<
specifier|const
name|FileEntry
operator|*
operator|>
name|OverriddenFilesWithBuffer
block|;   }
block|;
comment|/// \brief Lazily create the object keeping overridden files info, since
comment|/// it is uncommonly used.
name|std
operator|::
name|unique_ptr
operator|<
name|OverriddenFilesInfoTy
operator|>
name|OverriddenFilesInfo
block|;
name|OverriddenFilesInfoTy
operator|&
name|getOverriddenFilesInfo
argument_list|()
block|{
if|if
condition|(
operator|!
name|OverriddenFilesInfo
condition|)
name|OverriddenFilesInfo
operator|.
name|reset
argument_list|(
argument|new OverriddenFilesInfoTy
argument_list|)
expr_stmt|;
return|return
operator|*
name|OverriddenFilesInfo
return|;
block|}
comment|/// \brief Information about various memory buffers that we have read in.
comment|///
comment|/// All FileEntry* within the stored ContentCache objects are NULL,
comment|/// as they do not refer to a file.
name|std
operator|::
name|vector
operator|<
name|SrcMgr
operator|::
name|ContentCache
operator|*
operator|>
name|MemBufferInfos
expr_stmt|;
comment|/// \brief The table of SLocEntries that are local to this module.
comment|///
comment|/// Positive FileIDs are indexes into this table. Entry 0 indicates an invalid
comment|/// expansion.
name|SmallVector
operator|<
name|SrcMgr
operator|::
name|SLocEntry
operator|,
literal|0
operator|>
name|LocalSLocEntryTable
expr_stmt|;
comment|/// \brief The table of SLocEntries that are loaded from other modules.
comment|///
comment|/// Negative FileIDs are indexes into this table. To get from ID to an index,
comment|/// use (-ID - 2).
name|mutable
name|SmallVector
operator|<
name|SrcMgr
operator|::
name|SLocEntry
operator|,
literal|0
operator|>
name|LoadedSLocEntryTable
expr_stmt|;
comment|/// \brief The starting offset of the next local SLocEntry.
comment|///
comment|/// This is LocalSLocEntryTable.back().Offset + the size of that entry.
name|unsigned
name|NextLocalOffset
decl_stmt|;
comment|/// \brief The starting offset of the latest batch of loaded SLocEntries.
comment|///
comment|/// This is LoadedSLocEntryTable.back().Offset, except that that entry might
comment|/// not have been loaded, so that value would be unknown.
name|unsigned
name|CurrentLoadedOffset
decl_stmt|;
comment|/// \brief The highest possible offset is 2^31-1, so CurrentLoadedOffset
comment|/// starts at 2^31.
specifier|static
specifier|const
name|unsigned
name|MaxLoadedOffset
init|=
literal|1U
operator|<<
literal|31U
decl_stmt|;
comment|/// \brief A bitmap that indicates whether the entries of LoadedSLocEntryTable
comment|/// have already been loaded from the external source.
comment|///
comment|/// Same indexing as LoadedSLocEntryTable.
name|llvm
operator|::
name|BitVector
name|SLocEntryLoaded
expr_stmt|;
comment|/// \brief An external source for source location entries.
name|ExternalSLocEntrySource
modifier|*
name|ExternalSLocEntries
decl_stmt|;
comment|/// \brief A one-entry cache to speed up getFileID.
comment|///
comment|/// LastFileIDLookup records the last FileID looked up or created, because it
comment|/// is very common to look up many tokens from the same file.
name|mutable
name|FileID
name|LastFileIDLookup
decl_stmt|;
comment|/// \brief Holds information for \#line directives.
comment|///
comment|/// This is referenced by indices from SLocEntryTable.
name|LineTableInfo
modifier|*
name|LineTable
decl_stmt|;
comment|/// \brief These ivars serve as a cache used in the getLineNumber
comment|/// method which is used to speedup getLineNumber calls to nearby locations.
name|mutable
name|FileID
name|LastLineNoFileIDQuery
decl_stmt|;
name|mutable
name|SrcMgr
operator|::
name|ContentCache
operator|*
name|LastLineNoContentCache
expr_stmt|;
name|mutable
name|unsigned
name|LastLineNoFilePos
decl_stmt|;
name|mutable
name|unsigned
name|LastLineNoResult
decl_stmt|;
comment|/// \brief The file ID for the main source file of the translation unit.
name|FileID
name|MainFileID
decl_stmt|;
comment|/// \brief The file ID for the precompiled preamble there is one.
name|FileID
name|PreambleFileID
decl_stmt|;
comment|// Statistics for -print-stats.
name|mutable
name|unsigned
name|NumLinearScans
decl_stmt|,
name|NumBinaryProbes
decl_stmt|;
comment|/// \brief Associates a FileID with its "included/expanded in" decomposed
comment|/// location.
comment|///
comment|/// Used to cache results from and speed-up \c getDecomposedIncludedLoc
comment|/// function.
name|mutable
name|llvm
operator|::
name|DenseMap
operator|<
name|FileID
operator|,
name|std
operator|::
name|pair
operator|<
name|FileID
operator|,
name|unsigned
operator|>>
name|IncludedLocMap
expr_stmt|;
comment|/// The key value into the IsBeforeInTUCache table.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|FileID
operator|,
name|FileID
operator|>
name|IsBeforeInTUCacheKey
expr_stmt|;
comment|/// The IsBeforeInTranslationUnitCache is a mapping from FileID pairs
comment|/// to cache results.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|IsBeforeInTUCacheKey
operator|,
name|InBeforeInTUCacheEntry
operator|>
name|InBeforeInTUCache
expr_stmt|;
comment|/// Cache results for the isBeforeInTranslationUnit method.
name|mutable
name|InBeforeInTUCache
name|IBTUCache
decl_stmt|;
name|mutable
name|InBeforeInTUCacheEntry
name|IBTUCacheOverflow
decl_stmt|;
comment|/// Return the cache entry for comparing the given file IDs
comment|/// for isBeforeInTranslationUnit.
name|InBeforeInTUCacheEntry
modifier|&
name|getInBeforeInTUCache
argument_list|(
name|FileID
name|LFID
argument_list|,
name|FileID
name|RFID
argument_list|)
decl|const
decl_stmt|;
comment|// Cache for the "fake" buffer used for error-recovery purposes.
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|FakeBufferForRecovery
expr_stmt|;
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|SrcMgr
operator|::
name|ContentCache
operator|>
name|FakeContentCacheForRecovery
expr_stmt|;
comment|/// \brief Lazily computed map of macro argument chunks to their expanded
comment|/// source location.
typedef|typedef
name|std
operator|::
name|map
operator|<
name|unsigned
operator|,
name|SourceLocation
operator|>
name|MacroArgsMap
expr_stmt|;
name|mutable
name|llvm
operator|::
name|DenseMap
operator|<
name|FileID
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|MacroArgsMap
operator|>>
name|MacroArgsCacheMap
expr_stmt|;
comment|/// \brief The stack of modules being built, which is used to detect
comment|/// cycles in the module dependency graph as modules are being built, as
comment|/// well as to describe why we're rebuilding a particular module.
comment|///
comment|/// There is no way to set this value from the command line. If we ever need
comment|/// to do so (e.g., if on-demand module construction moves out-of-process),
comment|/// we can add a cc1-level option to do so.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|FullSourceLoc
operator|>
operator|,
literal|2
operator|>
name|StoredModuleBuildStack
expr_stmt|;
name|public
label|:
name|SourceManager
argument_list|(
argument|DiagnosticsEngine&Diag
argument_list|,
argument|FileManager&FileMgr
argument_list|,
argument|bool UserFilesAreVolatile = false
argument_list|)
empty_stmt|;
name|explicit
name|SourceManager
parameter_list|(
specifier|const
name|SourceManager
modifier|&
parameter_list|)
init|=
name|delete
function_decl|;
name|SourceManager
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SourceManager
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
operator|~
name|SourceManager
argument_list|()
expr_stmt|;
name|void
name|clearIDTables
parameter_list|()
function_decl|;
name|DiagnosticsEngine
operator|&
name|getDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|Diag
return|;
block|}
name|FileManager
operator|&
name|getFileManager
argument_list|()
specifier|const
block|{
return|return
name|FileMgr
return|;
block|}
comment|/// \brief Set true if the SourceManager should report the original file name
comment|/// for contents of files that were overridden by other files. Defaults to
comment|/// true.
name|void
name|setOverridenFilesKeepOriginalName
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|OverridenFilesKeepOriginalName
operator|=
name|value
expr_stmt|;
block|}
comment|/// \brief True if non-system source files should be treated as volatile
comment|/// (likely to change while trying to use them).
name|bool
name|userFilesAreVolatile
argument_list|()
specifier|const
block|{
return|return
name|UserFilesAreVolatile
return|;
block|}
comment|/// \brief Retrieve the module build stack.
name|ModuleBuildStack
name|getModuleBuildStack
argument_list|()
specifier|const
block|{
return|return
name|StoredModuleBuildStack
return|;
block|}
comment|/// \brief Set the module build stack.
name|void
name|setModuleBuildStack
parameter_list|(
name|ModuleBuildStack
name|stack
parameter_list|)
block|{
name|StoredModuleBuildStack
operator|.
name|clear
argument_list|()
expr_stmt|;
name|StoredModuleBuildStack
operator|.
name|append
argument_list|(
name|stack
operator|.
name|begin
argument_list|()
argument_list|,
name|stack
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Push an entry to the module build stack.
name|void
name|pushModuleBuildStack
parameter_list|(
name|StringRef
name|moduleName
parameter_list|,
name|FullSourceLoc
name|importLoc
parameter_list|)
block|{
name|StoredModuleBuildStack
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|moduleName
operator|.
name|str
argument_list|()
argument_list|,
name|importLoc
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// MainFileID creation and querying methods.
comment|//===--------------------------------------------------------------------===//
comment|/// \brief Returns the FileID of the main source file.
name|FileID
name|getMainFileID
argument_list|()
specifier|const
block|{
return|return
name|MainFileID
return|;
block|}
comment|/// \brief Set the file ID for the main source file.
name|void
name|setMainFileID
parameter_list|(
name|FileID
name|FID
parameter_list|)
block|{
name|MainFileID
operator|=
name|FID
expr_stmt|;
block|}
comment|/// \brief Set the file ID for the precompiled preamble.
name|void
name|setPreambleFileID
parameter_list|(
name|FileID
name|Preamble
parameter_list|)
block|{
name|assert
argument_list|(
name|PreambleFileID
operator|.
name|isInvalid
argument_list|()
operator|&&
literal|"PreambleFileID already set!"
argument_list|)
expr_stmt|;
name|PreambleFileID
operator|=
name|Preamble
expr_stmt|;
block|}
comment|/// \brief Get the file ID for the precompiled preamble if there is one.
name|FileID
name|getPreambleFileID
argument_list|()
specifier|const
block|{
return|return
name|PreambleFileID
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Methods to create new FileID's and macro expansions.
comment|//===--------------------------------------------------------------------===//
comment|/// \brief Create a new FileID that represents the specified file
comment|/// being \#included from the specified IncludePosition.
comment|///
comment|/// This translates NULL into standard input.
name|FileID
name|createFileID
argument_list|(
specifier|const
name|FileEntry
operator|*
name|SourceFile
argument_list|,
name|SourceLocation
name|IncludePos
argument_list|,
name|SrcMgr
operator|::
name|CharacteristicKind
name|FileCharacter
argument_list|,
name|int
name|LoadedID
operator|=
literal|0
argument_list|,
name|unsigned
name|LoadedOffset
operator|=
literal|0
argument_list|)
block|{
specifier|const
name|SrcMgr
operator|::
name|ContentCache
operator|*
name|IR
operator|=
name|getOrCreateContentCache
argument_list|(
name|SourceFile
argument_list|,
comment|/*isSystemFile=*/
name|FileCharacter
operator|!=
name|SrcMgr
operator|::
name|C_User
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|IR
operator|&&
literal|"getOrCreateContentCache() cannot return NULL"
argument_list|)
expr_stmt|;
return|return
name|createFileID
argument_list|(
name|IR
argument_list|,
name|IncludePos
argument_list|,
name|FileCharacter
argument_list|,
name|LoadedID
argument_list|,
name|LoadedOffset
argument_list|)
return|;
block|}
comment|/// \brief Create a new FileID that represents the specified memory buffer.
comment|///
comment|/// This does no caching of the buffer and takes ownership of the
comment|/// MemoryBuffer, so only pass a MemoryBuffer to this once.
name|FileID
name|createFileID
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|Buffer
argument_list|,
name|SrcMgr
operator|::
name|CharacteristicKind
name|FileCharacter
operator|=
name|SrcMgr
operator|::
name|C_User
argument_list|,
name|int
name|LoadedID
operator|=
literal|0
argument_list|,
name|unsigned
name|LoadedOffset
operator|=
literal|0
argument_list|,
name|SourceLocation
name|IncludeLoc
operator|=
name|SourceLocation
argument_list|()
argument_list|)
block|{
return|return
name|createFileID
argument_list|(
name|createMemBufferContentCache
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Buffer
argument_list|)
argument_list|)
argument_list|,
name|IncludeLoc
argument_list|,
name|FileCharacter
argument_list|,
name|LoadedID
argument_list|,
name|LoadedOffset
argument_list|)
return|;
block|}
comment|/// \brief Get the FileID for \p SourceFile if it exists. Otherwise, create a
comment|/// new FileID for the \p SourceFile.
name|FileID
name|getOrCreateFileID
argument_list|(
specifier|const
name|FileEntry
operator|*
name|SourceFile
argument_list|,
name|SrcMgr
operator|::
name|CharacteristicKind
name|FileCharacter
argument_list|)
block|{
name|FileID
name|ID
init|=
name|translateFile
argument_list|(
name|SourceFile
argument_list|)
decl_stmt|;
return|return
name|ID
operator|.
name|isValid
argument_list|()
condition|?
name|ID
else|:
name|createFileID
argument_list|(
name|SourceFile
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|FileCharacter
argument_list|)
return|;
block|}
comment|/// \brief Return a new SourceLocation that encodes the
comment|/// fact that a token from SpellingLoc should actually be referenced from
comment|/// ExpansionLoc, and that it represents the expansion of a macro argument
comment|/// into the function-like macro body.
name|SourceLocation
name|createMacroArgExpansionLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|SourceLocation
name|ExpansionLoc
parameter_list|,
name|unsigned
name|TokLength
parameter_list|)
function_decl|;
comment|/// \brief Return a new SourceLocation that encodes the fact
comment|/// that a token from SpellingLoc should actually be referenced from
comment|/// ExpansionLoc.
name|SourceLocation
name|createExpansionLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|SourceLocation
name|ExpansionLocStart
parameter_list|,
name|SourceLocation
name|ExpansionLocEnd
parameter_list|,
name|unsigned
name|TokLength
parameter_list|,
name|int
name|LoadedID
init|=
literal|0
parameter_list|,
name|unsigned
name|LoadedOffset
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the memory buffer associated with the given file.
comment|///
comment|/// \param Invalid If non-NULL, will be set \c true if an error
comment|/// occurs while retrieving the memory buffer.
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|getMemoryBufferForFile
argument_list|(
specifier|const
name|FileEntry
operator|*
name|File
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
expr_stmt|;
comment|/// \brief Override the contents of the given source file by providing an
comment|/// already-allocated buffer.
comment|///
comment|/// \param SourceFile the source file whose contents will be overridden.
comment|///
comment|/// \param Buffer the memory buffer whose contents will be used as the
comment|/// data in the given source file.
comment|///
comment|/// \param DoNotFree If true, then the buffer will not be freed when the
comment|/// source manager is destroyed.
name|void
name|overrideFileContents
argument_list|(
specifier|const
name|FileEntry
operator|*
name|SourceFile
argument_list|,
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|Buffer
argument_list|,
name|bool
name|DoNotFree
argument_list|)
decl_stmt|;
name|void
name|overrideFileContents
argument_list|(
specifier|const
name|FileEntry
operator|*
name|SourceFile
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|Buffer
argument_list|)
block|{
name|overrideFileContents
argument_list|(
name|SourceFile
argument_list|,
name|Buffer
operator|.
name|release
argument_list|()
argument_list|,
comment|/*DoNotFree*/
name|false
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Override the given source file with another one.
comment|///
comment|/// \param SourceFile the source file which will be overridden.
comment|///
comment|/// \param NewFile the file whose contents will be used as the
comment|/// data instead of the contents of the given source file.
name|void
name|overrideFileContents
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|SourceFile
parameter_list|,
specifier|const
name|FileEntry
modifier|*
name|NewFile
parameter_list|)
function_decl|;
comment|/// \brief Returns true if the file contents have been overridden.
name|bool
name|isFileOverridden
argument_list|(
specifier|const
name|FileEntry
operator|*
name|File
argument_list|)
decl|const
block|{
if|if
condition|(
name|OverriddenFilesInfo
condition|)
block|{
if|if
condition|(
name|OverriddenFilesInfo
operator|->
name|OverriddenFilesWithBuffer
operator|.
name|count
argument_list|(
name|File
argument_list|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|OverriddenFilesInfo
operator|->
name|OverriddenFiles
operator|.
name|find
argument_list|(
name|File
argument_list|)
operator|!=
name|OverriddenFilesInfo
operator|->
name|OverriddenFiles
operator|.
name|end
argument_list|()
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
comment|/// \brief Disable overridding the contents of a file, previously enabled
comment|/// with #overrideFileContents.
comment|///
comment|/// This should be called before parsing has begun.
name|void
name|disableFileContentsOverride
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|)
function_decl|;
comment|/// \brief Specify that a file is transient.
name|void
name|setFileIsTransient
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|SourceFile
parameter_list|)
function_decl|;
comment|/// \brief Specify that all files that are read during this compilation are
comment|/// transient.
name|void
name|setAllFilesAreTransient
parameter_list|(
name|bool
name|Transient
parameter_list|)
block|{
name|FilesAreTransient
operator|=
name|Transient
expr_stmt|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// FileID manipulation methods.
comment|//===--------------------------------------------------------------------===//
comment|/// \brief Return the buffer for the specified FileID.
comment|///
comment|/// If there is an error opening this buffer the first time, this
comment|/// manufactures a temporary buffer and returns a non-empty error string.
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|getBuffer
argument_list|(
argument|FileID FID
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|bool *Invalid = nullptr
argument_list|)
specifier|const
block|{
name|bool
name|MyInvalid
operator|=
name|false
block|;
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|Entry
operator|=
name|getSLocEntry
argument_list|(
name|FID
argument_list|,
operator|&
name|MyInvalid
argument_list|)
block|;
if|if
condition|(
name|MyInvalid
operator|||
operator|!
name|Entry
operator|.
name|isFile
argument_list|()
condition|)
block|{
if|if
condition|(
name|Invalid
condition|)
operator|*
name|Invalid
operator|=
name|true
expr_stmt|;
return|return
name|getFakeBufferForRecovery
argument_list|()
return|;
block|}
return|return
name|Entry
operator|.
name|getFile
argument_list|()
operator|.
name|getContentCache
argument_list|()
operator|->
name|getBuffer
argument_list|(
name|Diag
argument_list|,
operator|*
name|this
argument_list|,
name|Loc
argument_list|,
name|Invalid
argument_list|)
return|;
block|}
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|getBuffer
argument_list|(
argument|FileID FID
argument_list|,
argument|bool *Invalid = nullptr
argument_list|)
specifier|const
block|{
name|bool
name|MyInvalid
operator|=
name|false
block|;
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|Entry
operator|=
name|getSLocEntry
argument_list|(
name|FID
argument_list|,
operator|&
name|MyInvalid
argument_list|)
block|;
if|if
condition|(
name|MyInvalid
operator|||
operator|!
name|Entry
operator|.
name|isFile
argument_list|()
condition|)
block|{
if|if
condition|(
name|Invalid
condition|)
operator|*
name|Invalid
operator|=
name|true
expr_stmt|;
return|return
name|getFakeBufferForRecovery
argument_list|()
return|;
block|}
return|return
name|Entry
operator|.
name|getFile
argument_list|()
operator|.
name|getContentCache
argument_list|()
operator|->
name|getBuffer
argument_list|(
name|Diag
argument_list|,
operator|*
name|this
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|Invalid
argument_list|)
return|;
block|}
comment|/// \brief Returns the FileEntry record for the provided FileID.
specifier|const
name|FileEntry
modifier|*
name|getFileEntryForID
argument_list|(
name|FileID
name|FID
argument_list|)
decl|const
block|{
name|bool
name|MyInvalid
init|=
name|false
decl_stmt|;
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|Entry
operator|=
name|getSLocEntry
argument_list|(
name|FID
argument_list|,
operator|&
name|MyInvalid
argument_list|)
expr_stmt|;
if|if
condition|(
name|MyInvalid
operator|||
operator|!
name|Entry
operator|.
name|isFile
argument_list|()
condition|)
return|return
name|nullptr
return|;
specifier|const
name|SrcMgr
operator|::
name|ContentCache
operator|*
name|Content
operator|=
name|Entry
operator|.
name|getFile
argument_list|()
operator|.
name|getContentCache
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|Content
condition|)
return|return
name|nullptr
return|;
return|return
name|Content
operator|->
name|OrigEntry
return|;
block|}
comment|/// \brief Returns the FileEntry record for the provided SLocEntry.
specifier|const
name|FileEntry
modifier|*
name|getFileEntryForSLocEntry
argument_list|(
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|sloc
argument_list|)
decl|const
block|{
specifier|const
name|SrcMgr
operator|::
name|ContentCache
operator|*
name|Content
operator|=
name|sloc
operator|.
name|getFile
argument_list|()
operator|.
name|getContentCache
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|Content
condition|)
return|return
name|nullptr
return|;
return|return
name|Content
operator|->
name|OrigEntry
return|;
block|}
comment|/// \brief Return a StringRef to the source buffer data for the
comment|/// specified FileID.
comment|///
comment|/// \param FID The file ID whose contents will be returned.
comment|/// \param Invalid If non-NULL, will be set true if an error occurred.
name|StringRef
name|getBufferData
argument_list|(
name|FileID
name|FID
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Get the number of FileIDs (files and macros) that were created
comment|/// during preprocessing of \p FID, including it.
name|unsigned
name|getNumCreatedFIDsForFileID
argument_list|(
name|FileID
name|FID
argument_list|)
decl|const
block|{
name|bool
name|Invalid
init|=
name|false
decl_stmt|;
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|Entry
operator|=
name|getSLocEntry
argument_list|(
name|FID
argument_list|,
operator|&
name|Invalid
argument_list|)
expr_stmt|;
if|if
condition|(
name|Invalid
operator|||
operator|!
name|Entry
operator|.
name|isFile
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|Entry
operator|.
name|getFile
argument_list|()
operator|.
name|NumCreatedFIDs
return|;
block|}
comment|/// \brief Set the number of FileIDs (files and macros) that were created
comment|/// during preprocessing of \p FID, including it.
name|void
name|setNumCreatedFIDsForFileID
argument_list|(
name|FileID
name|FID
argument_list|,
name|unsigned
name|NumFIDs
argument_list|)
decl|const
block|{
name|bool
name|Invalid
init|=
name|false
decl_stmt|;
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|Entry
operator|=
name|getSLocEntry
argument_list|(
name|FID
argument_list|,
operator|&
name|Invalid
argument_list|)
expr_stmt|;
if|if
condition|(
name|Invalid
operator|||
operator|!
name|Entry
operator|.
name|isFile
argument_list|()
condition|)
return|return;
name|assert
argument_list|(
name|Entry
operator|.
name|getFile
argument_list|()
operator|.
name|NumCreatedFIDs
operator|==
literal|0
operator|&&
literal|"Already set!"
argument_list|)
expr_stmt|;
name|const_cast
operator|<
name|SrcMgr
operator|::
name|FileInfo
operator|&
operator|>
operator|(
name|Entry
operator|.
name|getFile
argument_list|()
operator|)
operator|.
name|NumCreatedFIDs
operator|=
name|NumFIDs
expr_stmt|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// SourceLocation manipulation methods.
comment|//===--------------------------------------------------------------------===//
comment|/// \brief Return the FileID for a SourceLocation.
comment|///
comment|/// This is a very hot method that is used for all SourceManager queries
comment|/// that start with a SourceLocation object.  It is responsible for finding
comment|/// the entry in SLocEntryTable which contains the specified location.
comment|///
name|FileID
name|getFileID
argument_list|(
name|SourceLocation
name|SpellingLoc
argument_list|)
decl|const
block|{
name|unsigned
name|SLocOffset
init|=
name|SpellingLoc
operator|.
name|getOffset
argument_list|()
decl_stmt|;
comment|// If our one-entry cache covers this offset, just return it.
if|if
condition|(
name|isOffsetInFileID
argument_list|(
name|LastFileIDLookup
argument_list|,
name|SLocOffset
argument_list|)
condition|)
return|return
name|LastFileIDLookup
return|;
return|return
name|getFileIDSlow
argument_list|(
name|SLocOffset
argument_list|)
return|;
block|}
comment|/// \brief Return the filename of the file containing a SourceLocation.
name|StringRef
name|getFilename
argument_list|(
name|SourceLocation
name|SpellingLoc
argument_list|)
decl|const
block|{
if|if
condition|(
specifier|const
name|FileEntry
modifier|*
name|F
init|=
name|getFileEntryForID
argument_list|(
name|getFileID
argument_list|(
name|SpellingLoc
argument_list|)
argument_list|)
condition|)
return|return
name|F
operator|->
name|getName
argument_list|()
return|;
return|return
name|StringRef
argument_list|()
return|;
block|}
comment|/// \brief Return the source location corresponding to the first byte of
comment|/// the specified file.
name|SourceLocation
name|getLocForStartOfFile
argument_list|(
name|FileID
name|FID
argument_list|)
decl|const
block|{
name|bool
name|Invalid
init|=
name|false
decl_stmt|;
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|Entry
operator|=
name|getSLocEntry
argument_list|(
name|FID
argument_list|,
operator|&
name|Invalid
argument_list|)
expr_stmt|;
if|if
condition|(
name|Invalid
operator|||
operator|!
name|Entry
operator|.
name|isFile
argument_list|()
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
name|unsigned
name|FileOffset
init|=
name|Entry
operator|.
name|getOffset
argument_list|()
decl_stmt|;
return|return
name|SourceLocation
operator|::
name|getFileLoc
argument_list|(
name|FileOffset
argument_list|)
return|;
block|}
comment|/// \brief Return the source location corresponding to the last byte of the
comment|/// specified file.
name|SourceLocation
name|getLocForEndOfFile
argument_list|(
name|FileID
name|FID
argument_list|)
decl|const
block|{
name|bool
name|Invalid
init|=
name|false
decl_stmt|;
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|Entry
operator|=
name|getSLocEntry
argument_list|(
name|FID
argument_list|,
operator|&
name|Invalid
argument_list|)
expr_stmt|;
if|if
condition|(
name|Invalid
operator|||
operator|!
name|Entry
operator|.
name|isFile
argument_list|()
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
name|unsigned
name|FileOffset
init|=
name|Entry
operator|.
name|getOffset
argument_list|()
decl_stmt|;
return|return
name|SourceLocation
operator|::
name|getFileLoc
argument_list|(
name|FileOffset
operator|+
name|getFileIDSize
argument_list|(
name|FID
argument_list|)
argument_list|)
return|;
block|}
comment|/// \brief Returns the include location if \p FID is a \#include'd file
comment|/// otherwise it returns an invalid location.
name|SourceLocation
name|getIncludeLoc
argument_list|(
name|FileID
name|FID
argument_list|)
decl|const
block|{
name|bool
name|Invalid
init|=
name|false
decl_stmt|;
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|Entry
operator|=
name|getSLocEntry
argument_list|(
name|FID
argument_list|,
operator|&
name|Invalid
argument_list|)
expr_stmt|;
if|if
condition|(
name|Invalid
operator|||
operator|!
name|Entry
operator|.
name|isFile
argument_list|()
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
return|return
name|Entry
operator|.
name|getFile
argument_list|()
operator|.
name|getIncludeLoc
argument_list|()
return|;
block|}
comment|// \brief Returns the import location if the given source location is
comment|// located within a module, or an invalid location if the source location
comment|// is within the current translation unit.
name|std
operator|::
name|pair
operator|<
name|SourceLocation
operator|,
name|StringRef
operator|>
name|getModuleImportLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
specifier|const
block|{
name|FileID
name|FID
operator|=
name|getFileID
argument_list|(
name|Loc
argument_list|)
block|;
comment|// Positive file IDs are in the current translation unit, and -1 is a
comment|// placeholder.
if|if
condition|(
name|FID
operator|.
name|ID
operator|>=
operator|-
literal|1
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|SourceLocation
argument_list|()
argument_list|,
literal|""
argument_list|)
return|;
return|return
name|ExternalSLocEntries
operator|->
name|getModuleImportLoc
argument_list|(
name|FID
operator|.
name|ID
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Given a SourceLocation object \p Loc, return the expansion
end_comment

begin_comment
comment|/// location referenced by the ID.
end_comment

begin_decl_stmt
name|SourceLocation
name|getExpansionLoc
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
block|{
comment|// Handle the non-mapped case inline, defer to out of line code to handle
comment|// expansions.
if|if
condition|(
name|Loc
operator|.
name|isFileID
argument_list|()
condition|)
return|return
name|Loc
return|;
return|return
name|getExpansionLocSlowCase
argument_list|(
name|Loc
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Given \p Loc, if it is a macro location return the expansion
end_comment

begin_comment
comment|/// location or the spelling location, depending on if it comes from a
end_comment

begin_comment
comment|/// macro argument or not.
end_comment

begin_decl_stmt
name|SourceLocation
name|getFileLoc
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
block|{
if|if
condition|(
name|Loc
operator|.
name|isFileID
argument_list|()
condition|)
return|return
name|Loc
return|;
return|return
name|getFileLocSlowCase
argument_list|(
name|Loc
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Return the start/end of the expansion information for an
end_comment

begin_comment
comment|/// expansion location.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre \p Loc is required to be an expansion location.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|SourceLocation
operator|,
name|SourceLocation
operator|>
name|getImmediateExpansionRange
argument_list|(
argument|SourceLocation Loc
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Given a SourceLocation object, return the range of
end_comment

begin_comment
comment|/// tokens covered by the expansion in the ultimate file.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|SourceLocation
operator|,
name|SourceLocation
operator|>
name|getExpansionRange
argument_list|(
argument|SourceLocation Loc
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Given a SourceRange object, return the range of
end_comment

begin_comment
comment|/// tokens covered by the expansion in the ultimate file.
end_comment

begin_decl_stmt
name|SourceRange
name|getExpansionRange
argument_list|(
name|SourceRange
name|Range
argument_list|)
decl|const
block|{
return|return
name|SourceRange
argument_list|(
name|getExpansionRange
argument_list|(
name|Range
operator|.
name|getBegin
argument_list|()
argument_list|)
operator|.
name|first
argument_list|,
name|getExpansionRange
argument_list|(
name|Range
operator|.
name|getEnd
argument_list|()
argument_list|)
operator|.
name|second
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Given a SourceLocation object, return the spelling
end_comment

begin_comment
comment|/// location referenced by the ID.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is the place where the characters that make up the lexed token
end_comment

begin_comment
comment|/// can be found.
end_comment

begin_decl_stmt
name|SourceLocation
name|getSpellingLoc
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
block|{
comment|// Handle the non-mapped case inline, defer to out of line code to handle
comment|// expansions.
if|if
condition|(
name|Loc
operator|.
name|isFileID
argument_list|()
condition|)
return|return
name|Loc
return|;
return|return
name|getSpellingLocSlowCase
argument_list|(
name|Loc
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Given a SourceLocation object, return the spelling location
end_comment

begin_comment
comment|/// referenced by the ID.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is the first level down towards the place where the characters
end_comment

begin_comment
comment|/// that make up the lexed token can be found.  This should not generally
end_comment

begin_comment
comment|/// be used by clients.
end_comment

begin_decl_stmt
name|SourceLocation
name|getImmediateSpellingLoc
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Decompose the specified location into a raw FileID + Offset pair.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The first element is the FileID, the second is the offset from the
end_comment

begin_comment
comment|/// start of the buffer of the location.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|FileID
operator|,
name|unsigned
operator|>
name|getDecomposedLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
specifier|const
block|{
name|FileID
name|FID
operator|=
name|getFileID
argument_list|(
name|Loc
argument_list|)
block|;
name|bool
name|Invalid
operator|=
name|false
block|;
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|E
operator|=
name|getSLocEntry
argument_list|(
name|FID
argument_list|,
operator|&
name|Invalid
argument_list|)
block|;
if|if
condition|(
name|Invalid
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|FileID
argument_list|()
argument_list|,
literal|0
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|FID
argument_list|,
name|Loc
operator|.
name|getOffset
argument_list|()
operator|-
name|E
operator|.
name|getOffset
argument_list|()
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Decompose the specified location into a raw FileID + Offset pair.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If the location is an expansion record, walk through it until we find
end_comment

begin_comment
comment|/// the final location expanded.
end_comment

begin_expr_stmt
unit|std
operator|::
name|pair
operator|<
name|FileID
operator|,
name|unsigned
operator|>
name|getDecomposedExpansionLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
specifier|const
block|{
name|FileID
name|FID
operator|=
name|getFileID
argument_list|(
name|Loc
argument_list|)
block|;
name|bool
name|Invalid
operator|=
name|false
block|;
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|*
name|E
operator|=
operator|&
name|getSLocEntry
argument_list|(
name|FID
argument_list|,
operator|&
name|Invalid
argument_list|)
block|;
if|if
condition|(
name|Invalid
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|FileID
argument_list|()
argument_list|,
literal|0
argument_list|)
return|;
name|unsigned
name|Offset
operator|=
name|Loc
operator|.
name|getOffset
argument_list|()
operator|-
name|E
operator|->
name|getOffset
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Loc
operator|.
name|isFileID
argument_list|()
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|FID
argument_list|,
name|Offset
argument_list|)
return|;
end_if

begin_return
return|return
name|getDecomposedExpansionLocSlowCase
argument_list|(
name|E
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Decompose the specified location into a raw FileID + Offset pair.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If the location is an expansion record, walk through it until we find
end_comment

begin_comment
comment|/// its spelling record.
end_comment

begin_expr_stmt
unit|std
operator|::
name|pair
operator|<
name|FileID
operator|,
name|unsigned
operator|>
name|getDecomposedSpellingLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
specifier|const
block|{
name|FileID
name|FID
operator|=
name|getFileID
argument_list|(
name|Loc
argument_list|)
block|;
name|bool
name|Invalid
operator|=
name|false
block|;
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|*
name|E
operator|=
operator|&
name|getSLocEntry
argument_list|(
name|FID
argument_list|,
operator|&
name|Invalid
argument_list|)
block|;
if|if
condition|(
name|Invalid
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|FileID
argument_list|()
argument_list|,
literal|0
argument_list|)
return|;
name|unsigned
name|Offset
operator|=
name|Loc
operator|.
name|getOffset
argument_list|()
operator|-
name|E
operator|->
name|getOffset
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Loc
operator|.
name|isFileID
argument_list|()
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|FID
argument_list|,
name|Offset
argument_list|)
return|;
end_if

begin_return
return|return
name|getDecomposedSpellingLocSlowCase
argument_list|(
name|E
argument_list|,
name|Offset
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Returns the "included/expanded in" decomposed location of the given
end_comment

begin_comment
comment|/// FileID.
end_comment

begin_expr_stmt
unit|std
operator|::
name|pair
operator|<
name|FileID
operator|,
name|unsigned
operator|>
name|getDecomposedIncludedLoc
argument_list|(
argument|FileID FID
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Returns the offset from the start of the file that the
end_comment

begin_comment
comment|/// specified SourceLocation represents.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is not very meaningful for a macro ID.
end_comment

begin_decl_stmt
name|unsigned
name|getFileOffset
argument_list|(
name|SourceLocation
name|SpellingLoc
argument_list|)
decl|const
block|{
return|return
name|getDecomposedLoc
argument_list|(
name|SpellingLoc
argument_list|)
operator|.
name|second
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Tests whether the given source location represents a macro
end_comment

begin_comment
comment|/// argument's expansion into the function-like macro definition.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param StartLoc If non-null and function returns true, it is set to the
end_comment

begin_comment
comment|/// start location of the macro argument expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Such source locations only appear inside of the expansion
end_comment

begin_comment
comment|/// locations representing where a particular function-like macro was
end_comment

begin_comment
comment|/// expanded.
end_comment

begin_decl_stmt
name|bool
name|isMacroArgExpansion
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|SourceLocation
operator|*
name|StartLoc
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Tests whether the given source location represents the expansion of
end_comment

begin_comment
comment|/// a macro body.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is equivalent to testing whether the location is part of a macro
end_comment

begin_comment
comment|/// expansion but not the expansion of an argument to a function-like macro.
end_comment

begin_decl_stmt
name|bool
name|isMacroBodyExpansion
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Returns true if the given MacroID location points at the beginning
end_comment

begin_comment
comment|/// of the immediate macro expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param MacroBegin If non-null and function returns true, it is set to the
end_comment

begin_comment
comment|/// begin location of the immediate macro expansion.
end_comment

begin_decl_stmt
name|bool
name|isAtStartOfImmediateMacroExpansion
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|SourceLocation
operator|*
name|MacroBegin
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Returns true if the given MacroID location points at the character
end_comment

begin_comment
comment|/// end of the immediate macro expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param MacroEnd If non-null and function returns true, it is set to the
end_comment

begin_comment
comment|/// character end location of the immediate macro expansion.
end_comment

begin_decl_stmt
name|bool
name|isAtEndOfImmediateMacroExpansion
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|SourceLocation
operator|*
name|MacroEnd
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Returns true if \p Loc is inside the [\p Start, +\p Length)
end_comment

begin_comment
comment|/// chunk of the source location address space.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If it's true and \p RelativeOffset is non-null, it will be set to the
end_comment

begin_comment
comment|/// relative offset of \p Loc inside the chunk.
end_comment

begin_decl_stmt
name|bool
name|isInSLocAddrSpace
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|SourceLocation
name|Start
argument_list|,
name|unsigned
name|Length
argument_list|,
name|unsigned
operator|*
name|RelativeOffset
operator|=
name|nullptr
argument_list|)
decl|const
block|{
name|assert
argument_list|(
operator|(
operator|(
name|Start
operator|.
name|getOffset
argument_list|()
operator|<
name|NextLocalOffset
operator|&&
name|Start
operator|.
name|getOffset
argument_list|()
operator|+
name|Length
operator|<=
name|NextLocalOffset
operator|)
operator|||
operator|(
name|Start
operator|.
name|getOffset
argument_list|()
operator|>=
name|CurrentLoadedOffset
operator|&&
name|Start
operator|.
name|getOffset
argument_list|()
operator|+
name|Length
operator|<
name|MaxLoadedOffset
operator|)
operator|)
operator|&&
literal|"Chunk is not valid SLoc address space"
argument_list|)
expr_stmt|;
name|unsigned
name|LocOffs
init|=
name|Loc
operator|.
name|getOffset
argument_list|()
decl_stmt|;
name|unsigned
name|BeginOffs
init|=
name|Start
operator|.
name|getOffset
argument_list|()
decl_stmt|;
name|unsigned
name|EndOffs
init|=
name|BeginOffs
operator|+
name|Length
decl_stmt|;
if|if
condition|(
name|LocOffs
operator|>=
name|BeginOffs
operator|&&
name|LocOffs
operator|<
name|EndOffs
condition|)
block|{
if|if
condition|(
name|RelativeOffset
condition|)
operator|*
name|RelativeOffset
operator|=
name|LocOffs
operator|-
name|BeginOffs
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Return true if both \p LHS and \p RHS are in the local source
end_comment

begin_comment
comment|/// location address space or the loaded one.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If it's true and \p RelativeOffset is non-null, it will be set to the
end_comment

begin_comment
comment|/// offset of \p RHS relative to \p LHS.
end_comment

begin_decl_stmt
name|bool
name|isInSameSLocAddrSpace
argument_list|(
name|SourceLocation
name|LHS
argument_list|,
name|SourceLocation
name|RHS
argument_list|,
name|int
operator|*
name|RelativeOffset
argument_list|)
decl|const
block|{
name|unsigned
name|LHSOffs
init|=
name|LHS
operator|.
name|getOffset
argument_list|()
decl_stmt|,
name|RHSOffs
init|=
name|RHS
operator|.
name|getOffset
argument_list|()
decl_stmt|;
name|bool
name|LHSLoaded
init|=
name|LHSOffs
operator|>=
name|CurrentLoadedOffset
decl_stmt|;
name|bool
name|RHSLoaded
init|=
name|RHSOffs
operator|>=
name|CurrentLoadedOffset
decl_stmt|;
if|if
condition|(
name|LHSLoaded
operator|==
name|RHSLoaded
condition|)
block|{
if|if
condition|(
name|RelativeOffset
condition|)
operator|*
name|RelativeOffset
operator|=
name|RHSOffs
operator|-
name|LHSOffs
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Queries about the code at a SourceLocation.
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \brief Return a pointer to the start of the specified location
end_comment

begin_comment
comment|/// in the appropriate spelling MemoryBuffer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Invalid If non-NULL, will be set \c true if an error occurs.
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|getCharacterData
argument_list|(
name|SourceLocation
name|SL
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return the column # for the specified file position.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is significantly cheaper to compute than the line number.  This
end_comment

begin_comment
comment|/// returns zero if the column number isn't known.  This may only be called
end_comment

begin_comment
comment|/// on a file sloc, so you must choose a spelling or expansion location
end_comment

begin_comment
comment|/// before calling this method.
end_comment

begin_decl_stmt
name|unsigned
name|getColumnNumber
argument_list|(
name|FileID
name|FID
argument_list|,
name|unsigned
name|FilePos
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|getSpellingColumnNumber
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|getExpansionColumnNumber
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|getPresumedColumnNumber
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Given a SourceLocation, return the spelling line number
end_comment

begin_comment
comment|/// for the position indicated.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This requires building and caching a table of line offsets for the
end_comment

begin_comment
comment|/// MemoryBuffer, so this is not cheap: use only when about to emit a
end_comment

begin_comment
comment|/// diagnostic.
end_comment

begin_decl_stmt
name|unsigned
name|getLineNumber
argument_list|(
name|FileID
name|FID
argument_list|,
name|unsigned
name|FilePos
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|getSpellingLineNumber
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|getExpansionLineNumber
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|getPresumedLineNumber
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return the filename or buffer identifier of the buffer the
end_comment

begin_comment
comment|/// location is in.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this name does not respect \#line directives.  Use
end_comment

begin_comment
comment|/// getPresumedLoc for normal clients.
end_comment

begin_decl_stmt
name|StringRef
name|getBufferName
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return the file characteristic of the specified source
end_comment

begin_comment
comment|/// location, indicating whether this is a normal file, a system
end_comment

begin_comment
comment|/// header, or an "implicit extern C" system header.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This state can be modified with flags on GNU linemarker directives like:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///   # 4 "foo.h" 3
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|/// which changes all source locations in the current file after that to be
end_comment

begin_comment
comment|/// considered to be from a system header.
end_comment

begin_expr_stmt
name|SrcMgr
operator|::
name|CharacteristicKind
name|getFileCharacteristic
argument_list|(
argument|SourceLocation Loc
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Returns the "presumed" location of a SourceLocation specifies.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A "presumed location" can be modified by \#line or GNU line marker
end_comment

begin_comment
comment|/// directives.  This provides a view on the data that a user should see
end_comment

begin_comment
comment|/// in diagnostics, for example.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that a presumed location is always given as the expansion point of
end_comment

begin_comment
comment|/// an expansion location, not at the spelling location.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The presumed location of the specified SourceLocation. If the
end_comment

begin_comment
comment|/// presumed location cannot be calculated (e.g., because \p Loc is invalid
end_comment

begin_comment
comment|/// or the file containing \p Loc has changed on disk), returns an invalid
end_comment

begin_comment
comment|/// presumed location.
end_comment

begin_decl_stmt
name|PresumedLoc
name|getPresumedLoc
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|bool
name|UseLineDirectives
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Returns whether the PresumedLoc for a given SourceLocation is
end_comment

begin_comment
comment|/// in the main file.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This computes the "presumed" location for a SourceLocation, then checks
end_comment

begin_comment
comment|/// whether it came from a file other than the main file. This is different
end_comment

begin_comment
comment|/// from isWrittenInMainFile() because it takes line marker directives into
end_comment

begin_comment
comment|/// account.
end_comment

begin_decl_stmt
name|bool
name|isInMainFile
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Returns true if the spelling locations for both SourceLocations
end_comment

begin_comment
comment|/// are part of the same file buffer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This check ignores line marker directives.
end_comment

begin_decl_stmt
name|bool
name|isWrittenInSameFile
argument_list|(
name|SourceLocation
name|Loc1
argument_list|,
name|SourceLocation
name|Loc2
argument_list|)
decl|const
block|{
return|return
name|getFileID
argument_list|(
name|Loc1
argument_list|)
operator|==
name|getFileID
argument_list|(
name|Loc2
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns true if the spelling location for the given location
end_comment

begin_comment
comment|/// is in the main file buffer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This check ignores line marker directives.
end_comment

begin_decl_stmt
name|bool
name|isWrittenInMainFile
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
block|{
return|return
name|getFileID
argument_list|(
name|Loc
argument_list|)
operator|==
name|getMainFileID
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns if a SourceLocation is in a system header.
end_comment

begin_decl_stmt
name|bool
name|isInSystemHeader
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
block|{
return|return
name|getFileCharacteristic
argument_list|(
name|Loc
argument_list|)
operator|!=
name|SrcMgr
operator|::
name|C_User
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns if a SourceLocation is in an "extern C" system header.
end_comment

begin_decl_stmt
name|bool
name|isInExternCSystemHeader
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
block|{
return|return
name|getFileCharacteristic
argument_list|(
name|Loc
argument_list|)
operator|==
name|SrcMgr
operator|::
name|C_ExternCSystem
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns whether \p Loc is expanded from a macro in a system header.
end_comment

begin_decl_stmt
name|bool
name|isInSystemMacro
argument_list|(
name|SourceLocation
name|loc
argument_list|)
decl|const
block|{
return|return
name|loc
operator|.
name|isMacroID
argument_list|()
operator|&&
name|isInSystemHeader
argument_list|(
name|getSpellingLoc
argument_list|(
name|loc
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief The size of the SLocEntry that \p FID represents.
end_comment

begin_decl_stmt
name|unsigned
name|getFileIDSize
argument_list|(
name|FileID
name|FID
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Given a specific FileID, returns true if \p Loc is inside that
end_comment

begin_comment
comment|/// FileID chunk and sets relative offset (offset of \p Loc from beginning
end_comment

begin_comment
comment|/// of FileID) to \p relativeOffset.
end_comment

begin_decl_stmt
name|bool
name|isInFileID
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|FileID
name|FID
argument_list|,
name|unsigned
operator|*
name|RelativeOffset
operator|=
name|nullptr
argument_list|)
decl|const
block|{
name|unsigned
name|Offs
init|=
name|Loc
operator|.
name|getOffset
argument_list|()
decl_stmt|;
if|if
condition|(
name|isOffsetInFileID
argument_list|(
name|FID
argument_list|,
name|Offs
argument_list|)
condition|)
block|{
if|if
condition|(
name|RelativeOffset
condition|)
operator|*
name|RelativeOffset
operator|=
name|Offs
operator|-
name|getSLocEntry
argument_list|(
name|FID
argument_list|)
operator|.
name|getOffset
argument_list|()
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Line Table Manipulation Routines
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \brief Return the uniqued ID for the specified filename.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|unsigned
name|getLineTableFilenameID
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Add a line note to the line table for the FileID and offset
end_comment

begin_comment
comment|/// specified by Loc.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If FilenameID is -1, it is considered to be unspecified.
end_comment

begin_decl_stmt
name|void
name|AddLineNote
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|unsigned
name|LineNo
argument_list|,
name|int
name|FilenameID
argument_list|,
name|bool
name|IsFileEntry
argument_list|,
name|bool
name|IsFileExit
argument_list|,
name|SrcMgr
operator|::
name|CharacteristicKind
name|FileKind
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine if the source manager has a line table.
end_comment

begin_expr_stmt
name|bool
name|hasLineTable
argument_list|()
specifier|const
block|{
return|return
name|LineTable
operator|!=
name|nullptr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the stored line table.
end_comment

begin_function_decl
name|LineTableInfo
modifier|&
name|getLineTable
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Queries for performance analysis.
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \brief Return the total amount of physical memory allocated by the
end_comment

begin_comment
comment|/// ContentCache allocator.
end_comment

begin_expr_stmt
name|size_t
name|getContentCacheSize
argument_list|()
specifier|const
block|{
return|return
name|ContentCacheAlloc
operator|.
name|getTotalMemory
argument_list|()
return|;
block|}
end_expr_stmt

begin_struct
struct|struct
name|MemoryBufferSizes
block|{
specifier|const
name|size_t
name|malloc_bytes
decl_stmt|;
specifier|const
name|size_t
name|mmap_bytes
decl_stmt|;
name|MemoryBufferSizes
argument_list|(
argument|size_t malloc_bytes
argument_list|,
argument|size_t mmap_bytes
argument_list|)
block|:
name|malloc_bytes
argument_list|(
name|malloc_bytes
argument_list|)
operator|,
name|mmap_bytes
argument_list|(
argument|mmap_bytes
argument_list|)
block|{}
block|}
struct|;
end_struct

begin_comment
comment|/// \brief Return the amount of memory used by memory buffers, breaking down
end_comment

begin_comment
comment|/// by heap-backed versus mmap'ed memory.
end_comment

begin_expr_stmt
name|MemoryBufferSizes
name|getMemoryBufferSizes
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return the amount of memory used for various side tables and
end_comment

begin_comment
comment|/// data structures in the SourceManager.
end_comment

begin_expr_stmt
name|size_t
name|getDataStructureSizes
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Other miscellaneous methods.
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \brief Get the source location for the given file:line:col triplet.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If the source file is included multiple times, the source location will
end_comment

begin_comment
comment|/// be based upon the first inclusion.
end_comment

begin_decl_stmt
name|SourceLocation
name|translateFileLineCol
argument_list|(
specifier|const
name|FileEntry
operator|*
name|SourceFile
argument_list|,
name|unsigned
name|Line
argument_list|,
name|unsigned
name|Col
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Get the FileID for the given file.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If the source file is included multiple times, the FileID will be the
end_comment

begin_comment
comment|/// first inclusion.
end_comment

begin_decl_stmt
name|FileID
name|translateFile
argument_list|(
specifier|const
name|FileEntry
operator|*
name|SourceFile
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Get the source location in \p FID for the given line:col.
end_comment

begin_comment
comment|/// Returns null location if \p FID is not a file SLocEntry.
end_comment

begin_decl_stmt
name|SourceLocation
name|translateLineCol
argument_list|(
name|FileID
name|FID
argument_list|,
name|unsigned
name|Line
argument_list|,
name|unsigned
name|Col
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief If \p Loc points inside a function macro argument, the returned
end_comment

begin_comment
comment|/// location will be the macro location in which the argument was expanded.
end_comment

begin_comment
comment|/// If a macro argument is used multiple times, the expanded location will
end_comment

begin_comment
comment|/// be at the first expansion of the argument.
end_comment

begin_comment
comment|/// e.g.
end_comment

begin_comment
comment|///   MY_MACRO(foo);
end_comment

begin_comment
comment|///             ^
end_comment

begin_comment
comment|/// Passing a file location pointing at 'foo', will yield a macro location
end_comment

begin_comment
comment|/// where 'foo' was expanded into.
end_comment

begin_decl_stmt
name|SourceLocation
name|getMacroArgExpandedLocation
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determines the order of 2 source locations in the translation unit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if LHS source location comes before RHS, false otherwise.
end_comment

begin_decl_stmt
name|bool
name|isBeforeInTranslationUnit
argument_list|(
name|SourceLocation
name|LHS
argument_list|,
name|SourceLocation
name|RHS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determines the order of 2 source locations in the "source location
end_comment

begin_comment
comment|/// address space".
end_comment

begin_decl_stmt
name|bool
name|isBeforeInSLocAddrSpace
argument_list|(
name|SourceLocation
name|LHS
argument_list|,
name|SourceLocation
name|RHS
argument_list|)
decl|const
block|{
return|return
name|isBeforeInSLocAddrSpace
argument_list|(
name|LHS
argument_list|,
name|RHS
operator|.
name|getOffset
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Determines the order of a source location and a source location
end_comment

begin_comment
comment|/// offset in the "source location address space".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that we always consider source locations loaded from
end_comment

begin_decl_stmt
name|bool
name|isBeforeInSLocAddrSpace
argument_list|(
name|SourceLocation
name|LHS
argument_list|,
name|unsigned
name|RHS
argument_list|)
decl|const
block|{
name|unsigned
name|LHSOffset
init|=
name|LHS
operator|.
name|getOffset
argument_list|()
decl_stmt|;
name|bool
name|LHSLoaded
init|=
name|LHSOffset
operator|>=
name|CurrentLoadedOffset
decl_stmt|;
name|bool
name|RHSLoaded
init|=
name|RHS
operator|>=
name|CurrentLoadedOffset
decl_stmt|;
if|if
condition|(
name|LHSLoaded
operator|==
name|RHSLoaded
condition|)
return|return
name|LHSOffset
operator|<
name|RHS
return|;
return|return
name|LHSLoaded
return|;
block|}
end_decl_stmt

begin_comment
comment|// Iterators over FileInfos.
end_comment

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FileEntry
operator|*
operator|,
name|SrcMgr
operator|::
name|ContentCache
operator|*
operator|>
operator|::
name|const_iterator
name|fileinfo_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|fileinfo_iterator
name|fileinfo_begin
argument_list|()
specifier|const
block|{
return|return
name|FileInfos
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|fileinfo_iterator
name|fileinfo_end
argument_list|()
specifier|const
block|{
return|return
name|FileInfos
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|bool
name|hasFileInfo
argument_list|(
specifier|const
name|FileEntry
operator|*
name|File
argument_list|)
decl|const
block|{
return|return
name|FileInfos
operator|.
name|find
argument_list|(
name|File
argument_list|)
operator|!=
name|FileInfos
operator|.
name|end
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Print statistics to stderr.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|void
name|PrintStats
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Get the number of local SLocEntries we have.
end_comment

begin_expr_stmt
name|unsigned
name|local_sloc_entry_size
argument_list|()
specifier|const
block|{
return|return
name|LocalSLocEntryTable
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Get a local SLocEntry. This is exposed for indexing.
end_comment

begin_expr_stmt
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|getLocalSLocEntry
argument_list|(
argument|unsigned Index
argument_list|,
argument|bool *Invalid = nullptr
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Index
operator|<
name|LocalSLocEntryTable
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid index"
argument_list|)
block|;
return|return
name|LocalSLocEntryTable
index|[
name|Index
index|]
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Get the number of loaded SLocEntries we have.
end_comment

begin_expr_stmt
name|unsigned
name|loaded_sloc_entry_size
argument_list|()
specifier|const
block|{
return|return
name|LoadedSLocEntryTable
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Get a loaded SLocEntry. This is exposed for indexing.
end_comment

begin_expr_stmt
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|getLoadedSLocEntry
argument_list|(
argument|unsigned Index
argument_list|,
argument|bool *Invalid = nullptr
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Index
operator|<
name|LoadedSLocEntryTable
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid index"
argument_list|)
block|;
if|if
condition|(
name|SLocEntryLoaded
index|[
name|Index
index|]
condition|)
return|return
name|LoadedSLocEntryTable
index|[
name|Index
index|]
return|;
end_expr_stmt

begin_return
return|return
name|loadSLocEntry
argument_list|(
name|Index
argument_list|,
name|Invalid
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}    const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|getSLocEntry
argument_list|(
argument|FileID FID
argument_list|,
argument|bool *Invalid = nullptr
argument_list|)
specifier|const
block|{
if|if
condition|(
name|FID
operator|.
name|ID
operator|==
literal|0
operator|||
name|FID
operator|.
name|ID
operator|==
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|Invalid
condition|)
operator|*
name|Invalid
operator|=
name|true
expr_stmt|;
return|return
name|LocalSLocEntryTable
index|[
literal|0
index|]
return|;
block|}
end_expr_stmt

begin_return
return|return
name|getSLocEntryByID
argument_list|(
name|FID
operator|.
name|ID
argument_list|,
name|Invalid
argument_list|)
return|;
end_return

begin_macro
unit|}    unsigned
name|getNextLocalOffset
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|NextLocalOffset
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setExternalSLocEntrySource
parameter_list|(
name|ExternalSLocEntrySource
modifier|*
name|Source
parameter_list|)
block|{
name|assert
argument_list|(
name|LoadedSLocEntryTable
operator|.
name|empty
argument_list|()
operator|&&
literal|"Invalidating existing loaded entries"
argument_list|)
expr_stmt|;
name|ExternalSLocEntries
operator|=
name|Source
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Allocate a number of loaded SLocEntries, which will be actually
end_comment

begin_comment
comment|/// loaded on demand from the external source.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// NumSLocEntries will be allocated, which occupy a total of TotalSize space
end_comment

begin_comment
comment|/// in the global source view. The lowest ID and the base offset of the
end_comment

begin_comment
comment|/// entries will be returned.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|int
operator|,
name|unsigned
operator|>
name|AllocateLoadedSLocEntries
argument_list|(
argument|unsigned NumSLocEntries
argument_list|,
argument|unsigned TotalSize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Returns true if \p Loc came from a PCH/Module.
end_comment

begin_decl_stmt
name|bool
name|isLoadedSourceLocation
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
block|{
return|return
name|Loc
operator|.
name|getOffset
argument_list|()
operator|>=
name|CurrentLoadedOffset
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns true if \p Loc did not come from a PCH/Module.
end_comment

begin_decl_stmt
name|bool
name|isLocalSourceLocation
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
block|{
return|return
name|Loc
operator|.
name|getOffset
argument_list|()
operator|<
name|NextLocalOffset
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns true if \p FID came from a PCH/Module.
end_comment

begin_decl_stmt
name|bool
name|isLoadedFileID
argument_list|(
name|FileID
name|FID
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|FID
operator|.
name|ID
operator|!=
operator|-
literal|1
operator|&&
literal|"Using FileID sentinel value"
argument_list|)
expr_stmt|;
return|return
name|FID
operator|.
name|ID
operator|<
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns true if \p FID did not come from a PCH/Module.
end_comment

begin_decl_stmt
name|bool
name|isLocalFileID
argument_list|(
name|FileID
name|FID
argument_list|)
decl|const
block|{
return|return
operator|!
name|isLoadedFileID
argument_list|(
name|FID
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Gets the location of the immediate macro caller, one level up the stack
end_comment

begin_comment
comment|/// toward the initial macro typed into the source.
end_comment

begin_decl_stmt
name|SourceLocation
name|getImmediateMacroCallerLoc
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|Loc
operator|.
name|isMacroID
argument_list|()
condition|)
return|return
name|Loc
return|;
comment|// When we have the location of (part of) an expanded parameter, its
comment|// spelling location points to the argument as expanded in the macro call,
comment|// and therefore is used to locate the macro caller.
if|if
condition|(
name|isMacroArgExpansion
argument_list|(
name|Loc
argument_list|)
condition|)
return|return
name|getImmediateSpellingLoc
argument_list|(
name|Loc
argument_list|)
return|;
comment|// Otherwise, the caller of the macro is located where this macro is
comment|// expanded (while the spelling is part of the macro definition).
return|return
name|getImmediateExpansionRange
argument_list|(
name|Loc
argument_list|)
operator|.
name|first
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|getFakeBufferForRecovery
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|SrcMgr
operator|::
name|ContentCache
operator|*
name|getFakeContentCacheForRecovery
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|loadSLocEntry
argument_list|(
argument|unsigned Index
argument_list|,
argument|bool *Invalid
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Get the entry with the given unwrapped FileID.
end_comment

begin_expr_stmt
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|getSLocEntryByID
argument_list|(
argument|int ID
argument_list|,
argument|bool *Invalid = nullptr
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|ID
operator|!=
operator|-
literal|1
operator|&&
literal|"Using FileID sentinel value"
argument_list|)
block|;
if|if
condition|(
name|ID
operator|<
literal|0
condition|)
return|return
name|getLoadedSLocEntryByID
argument_list|(
name|ID
argument_list|,
name|Invalid
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|getLocalSLocEntry
argument_list|(
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|ID
operator|)
argument_list|,
name|Invalid
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}    const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|getLoadedSLocEntryByID
argument_list|(
argument|int ID
argument_list|,
argument|bool *Invalid = nullptr
argument_list|)
specifier|const
block|{
return|return
name|getLoadedSLocEntry
argument_list|(
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
operator|-
name|ID
operator|-
literal|2
operator|)
argument_list|,
name|Invalid
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Implements the common elements of storing an expansion info struct into
end_comment

begin_comment
comment|/// the SLocEntry table and producing a source location that refers to it.
end_comment

begin_decl_stmt
name|SourceLocation
name|createExpansionLocImpl
argument_list|(
specifier|const
name|SrcMgr
operator|::
name|ExpansionInfo
operator|&
name|Expansion
argument_list|,
name|unsigned
name|TokLength
argument_list|,
name|int
name|LoadedID
operator|=
literal|0
argument_list|,
name|unsigned
name|LoadedOffset
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return true if the specified FileID contains the
end_comment

begin_comment
comment|/// specified SourceLocation offset.  This is a very hot method.
end_comment

begin_decl_stmt
specifier|inline
name|bool
name|isOffsetInFileID
argument_list|(
name|FileID
name|FID
argument_list|,
name|unsigned
name|SLocOffset
argument_list|)
decl|const
block|{
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|Entry
operator|=
name|getSLocEntry
argument_list|(
name|FID
argument_list|)
expr_stmt|;
comment|// If the entry is after the offset, it can't contain it.
if|if
condition|(
name|SLocOffset
operator|<
name|Entry
operator|.
name|getOffset
argument_list|()
condition|)
return|return
name|false
return|;
comment|// If this is the very last entry then it does.
if|if
condition|(
name|FID
operator|.
name|ID
operator|==
operator|-
literal|2
condition|)
return|return
name|true
return|;
comment|// If it is the last local entry, then it does if the location is local.
if|if
condition|(
name|FID
operator|.
name|ID
operator|+
literal|1
operator|==
name|static_cast
operator|<
name|int
operator|>
operator|(
name|LocalSLocEntryTable
operator|.
name|size
argument_list|()
operator|)
condition|)
return|return
name|SLocOffset
operator|<
name|NextLocalOffset
return|;
comment|// Otherwise, the entry after it has to not include it. This works for both
comment|// local and loaded entries.
return|return
name|SLocOffset
operator|<
name|getSLocEntryByID
argument_list|(
name|FID
operator|.
name|ID
operator|+
literal|1
argument_list|)
operator|.
name|getOffset
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns the previous in-order FileID or an invalid FileID if there
end_comment

begin_comment
comment|/// is no previous one.
end_comment

begin_decl_stmt
name|FileID
name|getPreviousFileID
argument_list|(
name|FileID
name|FID
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Returns the next in-order FileID or an invalid FileID if there is
end_comment

begin_comment
comment|/// no next one.
end_comment

begin_decl_stmt
name|FileID
name|getNextFileID
argument_list|(
name|FileID
name|FID
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Create a new fileID for the specified ContentCache and
end_comment

begin_comment
comment|/// include position.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This works regardless of whether the ContentCache corresponds to a
end_comment

begin_comment
comment|/// file or some other input source.
end_comment

begin_decl_stmt
name|FileID
name|createFileID
argument_list|(
specifier|const
name|SrcMgr
operator|::
name|ContentCache
operator|*
name|File
argument_list|,
name|SourceLocation
name|IncludePos
argument_list|,
name|SrcMgr
operator|::
name|CharacteristicKind
name|DirCharacter
argument_list|,
name|int
name|LoadedID
argument_list|,
name|unsigned
name|LoadedOffset
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|SrcMgr
operator|::
name|ContentCache
operator|*
name|getOrCreateContentCache
argument_list|(
argument|const FileEntry *SourceFile
argument_list|,
argument|bool isSystemFile = false
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Create a new ContentCache for the specified  memory buffer.
end_comment

begin_expr_stmt
specifier|const
name|SrcMgr
operator|::
name|ContentCache
operator|*
name|createMemBufferContentCache
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|Buf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|FileID
name|getFileIDSlow
argument_list|(
name|unsigned
name|SLocOffset
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FileID
name|getFileIDLocal
argument_list|(
name|unsigned
name|SLocOffset
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FileID
name|getFileIDLoaded
argument_list|(
name|unsigned
name|SLocOffset
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SourceLocation
name|getExpansionLocSlowCase
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SourceLocation
name|getSpellingLocSlowCase
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SourceLocation
name|getFileLocSlowCase
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|FileID
operator|,
name|unsigned
operator|>
name|getDecomposedExpansionLocSlowCase
argument_list|(
argument|const SrcMgr::SLocEntry *E
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|FileID
operator|,
name|unsigned
operator|>
name|getDecomposedSpellingLocSlowCase
argument_list|(
argument|const SrcMgr::SLocEntry *E
argument_list|,
argument|unsigned Offset
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|computeMacroArgsCache
argument_list|(
name|MacroArgsMap
operator|&
name|MacroArgsCache
argument_list|,
name|FileID
name|FID
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|associateFileChunkWithMacroArgExp
argument_list|(
name|MacroArgsMap
operator|&
name|MacroArgsCache
argument_list|,
name|FileID
name|FID
argument_list|,
name|SourceLocation
name|SpellLoc
argument_list|,
name|SourceLocation
name|ExpansionLoc
argument_list|,
name|unsigned
name|ExpansionLength
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTWriter
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Comparison function object.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|BeforeThanCompare
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Compare two source locations.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|BeforeThanCompare
operator|<
name|SourceLocation
operator|>
block|{
name|SourceManager
operator|&
name|SM
block|;
name|public
operator|:
name|explicit
name|BeforeThanCompare
argument_list|(
name|SourceManager
operator|&
name|SM
argument_list|)
operator|:
name|SM
argument_list|(
argument|SM
argument_list|)
block|{ }
name|bool
name|operator
argument_list|()
operator|(
name|SourceLocation
name|LHS
operator|,
name|SourceLocation
name|RHS
operator|)
specifier|const
block|{
return|return
name|SM
operator|.
name|isBeforeInTranslationUnit
argument_list|(
name|LHS
argument_list|,
name|RHS
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Compare two non-overlapping source ranges.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|BeforeThanCompare
operator|<
name|SourceRange
operator|>
block|{
name|SourceManager
operator|&
name|SM
block|;
name|public
operator|:
name|explicit
name|BeforeThanCompare
argument_list|(
name|SourceManager
operator|&
name|SM
argument_list|)
operator|:
name|SM
argument_list|(
argument|SM
argument_list|)
block|{ }
name|bool
name|operator
argument_list|()
operator|(
name|SourceRange
name|LHS
operator|,
name|SourceRange
name|RHS
operator|)
specifier|const
block|{
return|return
name|SM
operator|.
name|isBeforeInTranslationUnit
argument_list|(
name|LHS
operator|.
name|getBegin
argument_list|()
argument_list|,
name|RHS
operator|.
name|getBegin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};  }
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_BASIC_SOURCEMANAGER_H
end_comment

end_unit

