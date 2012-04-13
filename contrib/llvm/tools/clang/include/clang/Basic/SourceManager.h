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
comment|//
end_comment

begin_comment
comment|//  This file defines the SourceManager interface.
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
name|LLVM_CLANG_SOURCEMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SOURCEMANAGER_H
end_define

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
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|FileManager
decl_stmt|;
name|class
name|FileEntry
decl_stmt|;
name|class
name|LineTableInfo
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|ASTWriter
decl_stmt|;
name|class
name|ASTReader
decl_stmt|;
comment|/// There are three different types of locations in a file: a spelling
comment|/// location, an expansion location, and a presumed location.
comment|///
comment|/// Given an example of:
comment|/// #define min(x, y) x< y ? x : y
comment|///
comment|/// and then later on a use of min:
comment|/// #line 17
comment|/// return min(a, b);
comment|///
comment|/// The expansion location is the line in the source code where the macro
comment|/// was expanded (the return statement), the spelling location is the
comment|/// location in the source where the macro was originally defined,
comment|/// and the presumed location is where the line directive states that
comment|/// the line is 17, or any other line.
comment|/// SrcMgr - Public enums and private classes that are part of the
comment|/// SourceManager implementation.
comment|///
name|namespace
name|SrcMgr
block|{
comment|/// CharacteristicKind - This is used to represent whether a file or directory
comment|/// holds normal user code, system code, or system code which is implicitly
comment|/// 'extern "C"' in C++ mode.  Entire directories can be tagged with this
comment|/// (this is maintained by DirectoryLookup and friends) as can specific
comment|/// FileInfos when a #pragma system_header is seen or various other cases.
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
comment|/// ContentCache - One instance of this struct is kept for every file
comment|/// loaded or used.  This object owns the MemoryBuffer object.
name|class
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
comment|/// Buffer - The actual buffer containing the characters from the input
comment|/// file.  This is owned by the ContentCache object.
comment|/// The bits indicate indicates whether the buffer is invalid.
name|mutable
name|llvm
operator|::
name|PointerIntPair
operator|<
specifier|const
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
comment|/// Reference to the file entry representing this ContentCache.
comment|/// This reference does not own the FileEntry object.
comment|/// It is possible for this to be NULL if
comment|/// the ContentCache encapsulates an imaginary text buffer.
specifier|const
name|FileEntry
modifier|*
name|OrigEntry
decl_stmt|;
comment|/// \brief References the file which the contents were actually loaded from.
comment|/// Can be different from 'Entry' if we overridden the contents of one file
comment|/// with the contents of another file.
specifier|const
name|FileEntry
modifier|*
name|ContentsEntry
decl_stmt|;
comment|/// SourceLineCache - A bump pointer allocated array of offsets for each
comment|/// source line.  This is lazily computed.  This is owned by the
comment|/// SourceManager BumpPointerAllocator object.
name|unsigned
modifier|*
name|SourceLineCache
decl_stmt|;
comment|/// NumLines - The number of lines in this ContentCache.  This is only valid
comment|/// if SourceLineCache is non-null.
name|unsigned
name|NumLines
decl_stmt|;
comment|/// getBuffer - Returns the memory buffer for the associated content.
comment|///
comment|/// \param Diag Object through which diagnostics will be emitted if the
comment|/// buffer cannot be retrieved.
comment|///
comment|/// \param Loc If specified, is the location that invalid file diagnostics
comment|///     will be emitted at.
comment|///
comment|/// \param Invalid If non-NULL, will be set \c true if an error occurred.
specifier|const
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
argument|bool *Invalid =
literal|0
argument_list|)
specifier|const
expr_stmt|;
comment|/// getSize - Returns the size of the content encapsulated by this
comment|///  ContentCache. This can be the size of the source file or the size of an
comment|///  arbitrary scratch buffer.  If the ContentCache encapsulates a source
comment|///  file this size is retrieved from the file's FileEntry.
name|unsigned
name|getSize
argument_list|()
specifier|const
expr_stmt|;
comment|/// getSizeBytesMapped - Returns the number of bytes actually mapped for
comment|/// this ContentCache. This can be 0 if the MemBuffer was not actually
comment|/// expanded.
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
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
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
argument_list|)
expr_stmt|;
name|Buffer
operator|.
name|setInt
argument_list|(
name|false
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Get the underlying buffer, returning NULL if the buffer is not
comment|/// yet available.
specifier|const
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
specifier|const
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
name|ContentCache
argument_list|(
specifier|const
name|FileEntry
operator|*
name|Ent
operator|=
literal|0
argument_list|)
operator|:
name|Buffer
argument_list|(
literal|0
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
name|Ent
argument_list|)
operator|,
name|SourceLineCache
argument_list|(
literal|0
argument_list|)
operator|,
name|NumLines
argument_list|(
literal|0
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
literal|0
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
literal|0
argument_list|)
operator|,
name|NumLines
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|ContentCache
argument_list|()
expr_stmt|;
comment|/// The copy ctor does not allow copies where source object has either
comment|///  a non-NULL Buffer or SourceLineCache.  Ownership of allocated memory
comment|///  is not transferred, so this is a logical error.
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
literal|0
argument_list|,
name|false
argument_list|)
operator|,
name|SourceLineCache
argument_list|(
literal|0
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
literal|0
operator|&&
name|RHS
operator|.
name|SourceLineCache
operator|==
literal|0
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
name|private
operator|:
comment|// Disable assignments.
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
expr_stmt|;
block|}
empty_stmt|;
comment|/// FileInfo - Information about a FileID, basically just the logical file
comment|/// that it represents and include stack information.
comment|///
comment|/// Each FileInfo has include stack information, indicating where it came
comment|/// from. This information encodes the #include chain that a token was
comment|/// expanded from. The main include file has an invalid IncludeLoc.
comment|///
comment|/// FileInfos contain a "ContentCache *", with the contents of the file.
comment|///
name|class
name|FileInfo
block|{
comment|/// IncludeLoc - The location of the #include that brought in this file.
comment|/// This is an invalid SLOC for the main file (top of the #include chain).
name|unsigned
name|IncludeLoc
decl_stmt|;
comment|// Really a SourceLocation
comment|/// \brief Number of FileIDs (files and macros) that were created during
comment|/// preprocessing of this #include, including this SLocEntry.
comment|/// Zero means the preprocessor didn't provide such info for this SLocEntry.
name|unsigned
name|NumCreatedFIDs
decl_stmt|;
comment|/// Data - This contains the ContentCache* and the bits indicating the
comment|/// characteristic of the file and whether it has #line info, all bitmangled
comment|/// together.
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
comment|/// get - Return a FileInfo object.
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
literal|7UL
operator|)
return|;
block|}
comment|/// getCharacteristic - Return whether this is a system header or not.
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
comment|/// hasLineDirectives - Return true if this FileID has #line directives in
comment|/// it.
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
comment|/// setHasLineDirectives - Set the flag that indicates that this FileID has
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
comment|/// ExpansionInfo - Each ExpansionInfo encodes the expansion location - where
comment|/// the token was ultimately expanded, and the SpellingLoc - where the actual
comment|/// character data for the token came from.
name|class
name|ExpansionInfo
block|{
comment|// Really these are all SourceLocations.
comment|/// SpellingLoc - Where the spelling for the token can be found.
name|unsigned
name|SpellingLoc
decl_stmt|;
comment|/// ExpansionLocStart/ExpansionLocEnd - In a macro expansion, these
comment|/// indicate the start and end of the expansion. In object-like macros,
comment|/// these will be the same. In a function-like macro expansion, the start
comment|/// will be the identifier and the end will be the ')'. Finally, in
comment|/// macro-argument instantitions, the end will be 'SourceLocation()', an
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
comment|/// create - Return a ExpansionInfo for an expansion. Start and End specify
comment|/// the expansion range (where the macro is expanded), and SpellingLoc
comment|/// specifies the spelling location (where the characters from the token
comment|/// come from). All three can refer to normal File SLocs or expansion
comment|/// locations.
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
comment|/// createForMacroArg - Return a special ExpansionInfo for the expansion of
comment|/// a macro argument into a function-like macro's body. ExpansionLoc
comment|/// specifies the expansion location (where the macro is expanded). This
comment|/// doesn't need to be a range because a macro is always expanded at
comment|/// a macro parameter reference, and macro parameters are always exactly
comment|/// one token. SpellingLoc specifies the spelling location (where the
comment|/// characters from the token come from). ExpansionLoc and SpellingLoc can
comment|/// both refer to normal File SLocs or expansion locations.
comment|///
comment|/// Given the code:
comment|/// \code
comment|///   #define F(x) f(x)
comment|///   F(42);
comment|/// \endcode
comment|///
comment|/// When expanding '\c F(42)', the '\c x' would call this with an
comment|/// SpellingLoc pointing at '\c 42' anad an ExpansionLoc pointing at its
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
comment|/// SLocEntry - This is a discriminated union of FileInfo and
comment|/// ExpansionInfo.  SourceManager keeps an array of these objects, and
comment|/// they are uniquely identified by the FileID datatype.
name|class
name|SLocEntry
block|{
name|unsigned
name|Offset
decl_stmt|;
comment|// low bit is set for expansion info.
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
operator|>>
literal|1
return|;
block|}
name|bool
name|isExpansion
argument_list|()
specifier|const
block|{
return|return
name|Offset
operator|&
literal|1
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
name|SLocEntry
name|E
decl_stmt|;
name|E
operator|.
name|Offset
operator|=
name|Offset
operator|<<
literal|1
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
name|SLocEntry
name|E
decl_stmt|;
name|E
operator|.
name|Offset
operator|=
operator|(
name|Offset
operator|<<
literal|1
operator|)
operator||
literal|1
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
block|}
empty_stmt|;
comment|/// IsBeforeInTranslationUnitCache - This class holds the cache used by
comment|/// isBeforeInTranslationUnit.  The cache structure is complex enough to be
comment|/// worth breaking out of SourceManager.
name|class
name|IsBeforeInTranslationUnitCache
block|{
comment|/// L/R QueryFID - These are the FID's of the cached query.  If these match up
comment|/// with a subsequent query, the result can be reused.
name|FileID
name|LQueryFID
decl_stmt|,
name|RQueryFID
decl_stmt|;
comment|/// \brief True if LQueryFID was created before RQueryFID. This is used
comment|/// to compare macro expansion locations.
name|bool
name|IsLQFIDBeforeRQFID
decl_stmt|;
comment|/// CommonFID - This is the file found in common between the two #include
comment|/// traces.  It is the nearest common ancestor of the #include tree.
name|FileID
name|CommonFID
decl_stmt|;
comment|/// L/R CommonOffset - This is the offset of the previous query in CommonFID.
comment|/// Usually, this represents the location of the #include for QueryFID, but if
comment|/// LQueryFID is a parent of RQueryFID (or vise versa) then these can be a
comment|/// random token in the parent.
name|unsigned
name|LCommonOffset
decl_stmt|,
name|RCommonOffset
decl_stmt|;
name|public
label|:
comment|/// isCacheValid - Return true if the currently cached values match up with
comment|/// the specified LHS/RHS query.  If not, we can't use the cache.
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
comment|/// getCachedResult - If the cache is valid, compute the result given the
comment|/// specified offsets in the LHS/RHS FID's.
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
operator|&&
operator|(
name|LQueryFID
operator|!=
name|CommonFID
operator|||
name|RQueryFID
operator|!=
name|CommonFID
operator|)
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
comment|// Set up a new query.
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
comment|/// \brief This class handles loading and caching of source files into memory.
comment|///
comment|/// This object owns the MemoryBuffer objects for all of the loaded
comment|/// files and assigns unique FileID's for each unique #include chain.
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
name|llvm
operator|::
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
comment|/// FileInfos - Memoized information about all of the files tracked by this
comment|/// SourceManager.  This set allows us to merge ContentCache entries based
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
comment|/// \brief True if the ContentCache for files that are overriden by other
comment|/// files, should report the original file name. Defaults to true.
name|bool
name|OverridenFilesKeepOriginalName
block|;
comment|/// \brief Files that have been overriden with the contents from another file.
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
comment|/// MemBufferInfos - Information about various memory buffers that we have
comment|/// read in.  All FileEntry* within the stored ContentCache objects are NULL,
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
block|;
comment|/// \brief The table of SLocEntries that are local to this module.
comment|///
comment|/// Positive FileIDs are indexes into this table. Entry 0 indicates an invalid
comment|/// expansion.
name|std
operator|::
name|vector
operator|<
name|SrcMgr
operator|::
name|SLocEntry
operator|>
name|LocalSLocEntryTable
block|;
comment|/// \brief The table of SLocEntries that are loaded from other modules.
comment|///
comment|/// Negative FileIDs are indexes into this table. To get from ID to an index,
comment|/// use (-ID - 2).
name|std
operator|::
name|vector
operator|<
name|SrcMgr
operator|::
name|SLocEntry
operator|>
name|LoadedSLocEntryTable
block|;
comment|/// \brief The starting offset of the next local SLocEntry.
comment|///
comment|/// This is LocalSLocEntryTable.back().Offset + the size of that entry.
name|unsigned
name|NextLocalOffset
block|;
comment|/// \brief The starting offset of the latest batch of loaded SLocEntries.
comment|///
comment|/// This is LoadedSLocEntryTable.back().Offset, except that that entry might
comment|/// not have been loaded, so that value would be unknown.
name|unsigned
name|CurrentLoadedOffset
block|;
comment|/// \brief The highest possible offset is 2^31-1, so CurrentLoadedOffset
comment|/// starts at 2^31.
specifier|static
specifier|const
name|unsigned
name|MaxLoadedOffset
operator|=
literal|1U
operator|<<
literal|31U
block|;
comment|/// \brief A bitmap that indicates whether the entries of LoadedSLocEntryTable
comment|/// have already been loaded from the external source.
comment|///
comment|/// Same indexing as LoadedSLocEntryTable.
name|std
operator|::
name|vector
operator|<
name|bool
operator|>
name|SLocEntryLoaded
block|;
comment|/// \brief An external source for source location entries.
name|ExternalSLocEntrySource
operator|*
name|ExternalSLocEntries
block|;
comment|/// LastFileIDLookup - This is a one-entry cache to speed up getFileID.
comment|/// LastFileIDLookup records the last FileID looked up or created, because it
comment|/// is very common to look up many tokens from the same file.
name|mutable
name|FileID
name|LastFileIDLookup
block|;
comment|/// LineTable - This holds information for #line directives.  It is referenced
comment|/// by indices from SLocEntryTable.
name|LineTableInfo
operator|*
name|LineTable
block|;
comment|/// LastLineNo - These ivars serve as a cache used in the getLineNumber
comment|/// method which is used to speedup getLineNumber calls to nearby locations.
name|mutable
name|FileID
name|LastLineNoFileIDQuery
block|;
name|mutable
name|SrcMgr
operator|::
name|ContentCache
operator|*
name|LastLineNoContentCache
block|;
name|mutable
name|unsigned
name|LastLineNoFilePos
block|;
name|mutable
name|unsigned
name|LastLineNoResult
block|;
comment|/// MainFileID - The file ID for the main source file of the translation unit.
name|FileID
name|MainFileID
block|;
comment|/// \brief The file ID for the precompiled preamble there is one.
name|FileID
name|PreambleFileID
block|;
comment|// Statistics for -print-stats.
name|mutable
name|unsigned
name|NumLinearScans
block|,
name|NumBinaryProbes
block|;
comment|// Cache results for the isBeforeInTranslationUnit method.
name|mutable
name|IsBeforeInTranslationUnitCache
name|IsBeforeInTUCache
block|;
comment|// Cache for the "fake" buffer used for error-recovery purposes.
name|mutable
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|FakeBufferForRecovery
block|;
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
block|,
name|MacroArgsMap
operator|*
operator|>
name|MacroArgsCacheMap
decl_stmt|;
comment|// SourceManager doesn't support copy construction.
name|explicit
name|SourceManager
parameter_list|(
specifier|const
name|SourceManager
modifier|&
parameter_list|)
function_decl|;
name|void
name|operator
init|=
operator|(
specifier|const
name|SourceManager
operator|&
operator|)
decl_stmt|;
name|public
label|:
name|SourceManager
argument_list|(
name|DiagnosticsEngine
operator|&
name|Diag
argument_list|,
name|FileManager
operator|&
name|FileMgr
argument_list|)
expr_stmt|;
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
comment|/// for contents of files that were overriden by other files.Defaults to true.
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
comment|/// createMainFileIDForMembuffer - Create the FileID for a memory buffer
comment|///  that will represent the FileID for the main source.  One example
comment|///  of when this would be used is when the main source is read from STDIN.
name|FileID
name|createMainFileIDForMemBuffer
argument_list|(
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|Buffer
argument_list|)
block|{
name|assert
argument_list|(
name|MainFileID
operator|.
name|isInvalid
argument_list|()
operator|&&
literal|"MainFileID already set!"
argument_list|)
expr_stmt|;
name|MainFileID
operator|=
name|createFileIDForMemBuffer
argument_list|(
name|Buffer
argument_list|)
expr_stmt|;
return|return
name|MainFileID
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// MainFileID creation and querying methods.
comment|//===--------------------------------------------------------------------===//
comment|/// getMainFileID - Returns the FileID of the main source file.
name|FileID
name|getMainFileID
argument_list|()
specifier|const
block|{
return|return
name|MainFileID
return|;
block|}
comment|/// createMainFileID - Create the FileID for the main source file.
name|FileID
name|createMainFileID
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|SourceFile
parameter_list|)
block|{
name|assert
argument_list|(
name|MainFileID
operator|.
name|isInvalid
argument_list|()
operator|&&
literal|"MainFileID already set!"
argument_list|)
expr_stmt|;
name|MainFileID
operator|=
name|createFileID
argument_list|(
name|SourceFile
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SrcMgr
operator|::
name|C_User
argument_list|)
expr_stmt|;
return|return
name|MainFileID
return|;
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
comment|/// createFileID - Create a new FileID that represents the specified file
comment|/// being #included from the specified IncludePosition.  This translates NULL
comment|/// into standard input.
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
comment|/// createFileIDForMemBuffer - Create a new FileID that represents the
comment|/// specified memory buffer.  This does no caching of the buffer and takes
comment|/// ownership of the MemoryBuffer, so only pass a MemoryBuffer to this once.
name|FileID
name|createFileIDForMemBuffer
argument_list|(
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|Buffer
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
return|return
name|createFileID
argument_list|(
name|createMemBufferContentCache
argument_list|(
name|Buffer
argument_list|)
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SrcMgr
operator|::
name|C_User
argument_list|,
name|LoadedID
argument_list|,
name|LoadedOffset
argument_list|)
return|;
block|}
comment|/// createMacroArgExpansionLoc - Return a new SourceLocation that encodes the
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
comment|/// createExpansionLoc - Return a new SourceLocation that encodes the fact
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
specifier|const
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
literal|0
argument_list|)
expr_stmt|;
comment|/// \brief Override the contents of the given source file by providing an
comment|/// already-allocated buffer.
comment|///
comment|/// \param SourceFile the source file whose contents will be overriden.
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
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|Buffer
argument_list|,
name|bool
name|DoNotFree
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// \brief Override the the given source file with another one.
comment|///
comment|/// \param SourceFile the source file which will be overriden.
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
comment|//===--------------------------------------------------------------------===//
comment|// FileID manipulation methods.
comment|//===--------------------------------------------------------------------===//
comment|/// getBuffer - Return the buffer for the specified FileID. If there is an
comment|/// error opening this buffer the first time, this manufactures a temporary
comment|/// buffer and returns a non-empty error string.
specifier|const
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
argument|bool *Invalid =
literal|0
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
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|getBuffer
argument_list|(
argument|FileID FID
argument_list|,
argument|bool *Invalid =
literal|0
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
comment|/// getFileEntryForID - Returns the FileEntry record for the provided FileID.
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
literal|0
return|;
return|return
name|Entry
operator|.
name|getFile
argument_list|()
operator|.
name|getContentCache
argument_list|()
operator|->
name|OrigEntry
return|;
block|}
comment|/// Returns the FileEntry record for the provided SLocEntry.
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
return|return
name|sloc
operator|.
name|getFile
argument_list|()
operator|.
name|getContentCache
argument_list|()
operator|->
name|OrigEntry
return|;
block|}
comment|/// getBufferData - Return a StringRef to the source buffer data for the
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
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Get the number of FileIDs (files and macros) that were created
comment|/// during preprocessing of \arg FID, including it.
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
comment|/// during preprocessing of \arg FID, including it.
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
comment|/// getFileID - Return the FileID for a SourceLocation.  This is a very
comment|/// hot method that is used for all SourceManager queries that start with a
comment|/// SourceLocation object.  It is responsible for finding the entry in
comment|/// SLocEntryTable which contains the specified location.
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
comment|/// getLocForStartOfFile - Return the source location corresponding to the
comment|/// first byte of the specified file.
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
comment|/// \brief Returns the include location if \arg FID is a #include'd file
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
comment|/// getExpansionLoc - Given a SourceLocation object, return the expansion
comment|/// location referenced by the ID.
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
comment|/// \brief Given \arg Loc, if it is a macro location return the expansion
comment|/// location or the spelling location, depending on if it comes from a
comment|/// macro argument or not.
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
comment|/// getImmediateExpansionRange - Loc is required to be an expansion location.
comment|/// Return the start/end of the expansion information.
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
comment|/// getExpansionRange - Given a SourceLocation object, return the range of
comment|/// tokens covered by the expansion the ultimate file.
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
comment|/// getSpellingLoc - Given a SourceLocation object, return the spelling
comment|/// location referenced by the ID.  This is the place where the characters
comment|/// that make up the lexed token can be found.
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
comment|/// getImmediateSpellingLoc - Given a SourceLocation object, return the
comment|/// spelling location referenced by the ID.  This is the first level down
comment|/// towards the place where the characters that make up the lexed token can be
comment|/// found.  This should not generally be used by clients.
name|SourceLocation
name|getImmediateSpellingLoc
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
decl_stmt|;
comment|/// getDecomposedLoc - Decompose the specified location into a raw FileID +
comment|/// Offset pair.  The first element is the FileID, the second is the
comment|/// offset from the start of the buffer of the location.
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
name|getSLocEntry
argument_list|(
name|FID
argument_list|)
operator|.
name|getOffset
argument_list|()
argument_list|)
return|;
block|}
comment|/// getDecomposedExpansionLoc - Decompose the specified location into a raw
comment|/// FileID + Offset pair. If the location is an expansion record, walk
comment|/// through it until we find the final location expanded.
name|std
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
argument_list|)
block|;
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
block|;
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
return|return
name|getDecomposedExpansionLocSlowCase
argument_list|(
name|E
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getDecomposedSpellingLoc - Decompose the specified location into a raw
end_comment

begin_comment
comment|/// FileID + Offset pair.  If the location is an expansion record, walk
end_comment

begin_comment
comment|/// through it until we find its spelling record.
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
argument_list|)
block|;
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
block|;
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
end_expr_stmt

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
comment|/// getFileOffset - This method returns the offset from the start
end_comment

begin_comment
comment|/// of the file that the specified SourceLocation represents. This is not very
end_comment

begin_comment
comment|/// meaningful for a macro ID.
end_comment

begin_macro
unit|unsigned
name|getFileOffset
argument_list|(
argument|SourceLocation SpellingLoc
argument_list|)
end_macro

begin_expr_stmt
specifier|const
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
end_expr_stmt

begin_comment
comment|/// isMacroArgExpansion - This method tests whether the given source location
end_comment

begin_comment
comment|/// represents a macro argument's expansion into the function-like macro
end_comment

begin_comment
comment|/// definition. Such source locations only appear inside of the expansion
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
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Returns true if \arg Loc is inside the [\arg Start, +\arg Length)
end_comment

begin_comment
comment|/// chunk of the source location address space.
end_comment

begin_comment
comment|/// If it's true and \arg RelativeOffset is non-null, it will be set to the
end_comment

begin_comment
comment|/// relative offset of \arg Loc inside the chunk.
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
literal|0
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
comment|/// \brief Return true if both \arg LHS and \arg RHS are in the local source
end_comment

begin_comment
comment|/// location address space or the loaded one. If it's true and
end_comment

begin_comment
comment|/// \arg RelativeOffset is non-null, it will be set to the offset of \arg RHS
end_comment

begin_comment
comment|/// relative to \arg LHS.
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
comment|/// getCharacterData - Return a pointer to the start of the specified location
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
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getColumnNumber - Return the column # for the specified file position.
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
literal|0
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
literal|0
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
literal|0
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
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getLineNumber - Given a SourceLocation, return the spelling line number
end_comment

begin_comment
comment|/// for the position indicated.  This requires building and caching a table of
end_comment

begin_comment
comment|/// line offsets for the MemoryBuffer, so this is not cheap: use only when
end_comment

begin_comment
comment|/// about to emit a diagnostic.
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
literal|0
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
literal|0
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
literal|0
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
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return the filename or buffer identifier of the buffer the location is in.
end_comment

begin_comment
comment|/// Note that this name does not respect #line directives.  Use getPresumedLoc
end_comment

begin_comment
comment|/// for normal clients.
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|getBufferName
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getFileCharacteristic - return the file characteristic of the specified
end_comment

begin_comment
comment|/// source location, indicating whether this is a normal file, a system
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
comment|///   # 4 "foo.h" 3
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
comment|/// getPresumedLoc - This method returns the "presumed" location of a
end_comment

begin_comment
comment|/// SourceLocation specifies.  A "presumed location" can be modified by #line
end_comment

begin_comment
comment|/// or GNU line marker directives.  This provides a view on the data that a
end_comment

begin_comment
comment|/// user should see in diagnostics, for example.
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
comment|/// presumed location cannot be calculate (e.g., because \p Loc is invalid
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
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// isFromSameFile - Returns true if both SourceLocations correspond to
end_comment

begin_comment
comment|///  the same file.
end_comment

begin_decl_stmt
name|bool
name|isFromSameFile
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
comment|/// isFromMainFile - Returns true if the file of provided SourceLocation is
end_comment

begin_comment
comment|///   the main file.
end_comment

begin_decl_stmt
name|bool
name|isFromMainFile
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
comment|/// isInSystemHeader - Returns if a SourceLocation is in a system header.
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
comment|/// isInExternCSystemHeader - Returns if a SourceLocation is in an "extern C"
end_comment

begin_comment
comment|/// system header.
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
comment|/// \brief The size of the SLocEnty that \arg FID represents.
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
comment|/// \brief Given a specific FileID, returns true if \arg Loc is inside that
end_comment

begin_comment
comment|/// FileID chunk and sets relative offset (offset of \arg Loc from beginning
end_comment

begin_comment
comment|/// of FileID) to \arg relativeOffset.
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
literal|0
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
comment|/// getLineTableFilenameID - Return the uniqued ID for the specified filename.
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
comment|/// AddLineNote - Add a line note to the line table for the FileID and offset
end_comment

begin_comment
comment|/// specified by Loc.  If FilenameID is -1, it is considered to be
end_comment

begin_comment
comment|/// unspecified.
end_comment

begin_function_decl
name|void
name|AddLineNote
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
name|LineNo
parameter_list|,
name|int
name|FilenameID
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddLineNote
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
name|LineNo
parameter_list|,
name|int
name|FilenameID
parameter_list|,
name|bool
name|IsFileEntry
parameter_list|,
name|bool
name|IsFileExit
parameter_list|,
name|bool
name|IsSystemHeader
parameter_list|,
name|bool
name|IsExternCHeader
parameter_list|)
function_decl|;
end_function_decl

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
literal|0
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
comment|/// Return the total amount of physical memory allocated by the
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
comment|/// Return the amount of memory used by memory buffers, breaking down
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
comment|// Return the amount of memory used for various side tables and
end_comment

begin_comment
comment|// data structures in the SourceManager.
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
comment|/// \brief Get the source location in \arg FID for the given line:col.
end_comment

begin_comment
comment|/// Returns null location if \arg FID is not a file SLocEntry.
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
comment|/// \brief If \arg Loc points inside a function macro argument, the returned
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
comment|/// \brief Comparison function class.
end_comment

begin_decl_stmt
name|class
name|LocBeforeThanCompare
range|:
name|public
name|std
operator|::
name|binary_function
operator|<
name|SourceLocation
decl_stmt|,
name|SourceLocation
decl_stmt|,
name|bool
decl|>
block|{
name|SourceManager
modifier|&
name|SM
decl_stmt|;
name|public
label|:
name|explicit
name|LocBeforeThanCompare
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
comment|/// PrintStats - Print statistics to stderr.
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
argument|bool *Invalid =
literal|0
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
argument|bool *Invalid=
literal|0
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
operator|!
name|SLocEntryLoaded
index|[
name|Index
index|]
condition|)
name|ExternalSLocEntries
operator|->
name|ReadSLocEntry
argument_list|(
operator|-
operator|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|Index
operator|)
operator|+
literal|2
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|LoadedSLocEntryTable
index|[
name|Index
index|]
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
argument|bool *Invalid =
literal|0
argument_list|)
specifier|const
block|{
return|return
name|getSLocEntryByID
argument_list|(
name|FID
operator|.
name|ID
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getNextLocalOffset
argument_list|()
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
comment|/// \brief Returns true if \arg Loc came from a PCH/Module.
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
comment|/// \brief Returns true if \arg Loc did not come from a PCH/Module.
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

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|getFakeBufferForRecovery
argument_list|()
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
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// createExpansionLoc - Implements the common elements of storing an
end_comment

begin_comment
comment|/// expansion info struct into the SLocEntry table and producing a source
end_comment

begin_comment
comment|/// location that refers to it.
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
comment|/// isOffsetInFileID - Return true if the specified FileID contains the
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
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|FID
operator|.
name|ID
operator|+
literal|1
operator|)
operator|==
name|LocalSLocEntryTable
operator|.
name|size
argument_list|()
condition|)
block|{
return|return
name|SLocOffset
operator|<
name|NextLocalOffset
return|;
block|}
comment|// Otherwise, the entry after it has to not include it. This works for both
comment|// local and loaded entries.
return|return
name|SLocOffset
operator|<
name|getSLocEntry
argument_list|(
name|FileID
operator|::
name|get
argument_list|(
name|FID
operator|.
name|ID
operator|+
literal|1
argument_list|)
argument_list|)
operator|.
name|getOffset
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// createFileID - Create a new fileID for the specified ContentCache and
end_comment

begin_comment
comment|///  include position.  This works regardless of whether the ContentCache
end_comment

begin_comment
comment|///  corresponds to a file or some other input source.
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
specifier|const
name|FileEntry
operator|*
name|SourceFile
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// createMemBufferContentCache - Create a new ContentCache for the specified
end_comment

begin_comment
comment|///  memory buffer.
end_comment

begin_expr_stmt
specifier|const
name|SrcMgr
operator|::
name|ContentCache
operator|*
name|createMemBufferContentCache
argument_list|(
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
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
operator|*
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
unit|};   }
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

