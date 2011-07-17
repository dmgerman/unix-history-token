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
file|<vector>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Diagnostic
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
comment|/// FileIDInfos when a #pragma system_header is seen or various other cases.
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
argument|Diagnostic&Diag
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
comment|///  this ContentCache.  This can be 0 if the MemBuffer was not actually
comment|///  instantiated.
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
comment|/// from.  This information encodes the #include chain that a token was
comment|/// instantiated from.  The main include file has an invalid IncludeLoc.
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
comment|/// Data - This contains the ContentCache* and the bits indicating the
comment|/// characteristic of the file and whether it has #line info, all bitmangled
comment|/// together.
name|uintptr_t
name|Data
decl_stmt|;
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
comment|/// InstantiationInfo - Each InstantiationInfo encodes the Instantiation
comment|/// location - where the token was ultimately instantiated, and the
comment|/// SpellingLoc - where the actual character data for the token came from.
name|class
name|InstantiationInfo
block|{
comment|// Really these are all SourceLocations.
comment|/// SpellingLoc - Where the spelling for the token can be found.
name|unsigned
name|SpellingLoc
decl_stmt|;
comment|/// InstantiationLocStart/InstantiationLocEnd - In a macro expansion, these
comment|/// indicate the start and end of the instantiation.  In object-like macros,
comment|/// these will be the same.  In a function-like macro instantiation, the
comment|/// start will be the identifier and the end will be the ')'.  Finally, in
comment|/// macro-argument instantitions, the end will be 'SourceLocation()', an
comment|/// invalid location.
name|unsigned
name|InstantiationLocStart
decl_stmt|,
name|InstantiationLocEnd
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
name|getInstantiationLocStart
argument_list|()
specifier|const
block|{
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|InstantiationLocStart
argument_list|)
return|;
block|}
name|SourceLocation
name|getInstantiationLocEnd
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
name|InstantiationLocEnd
argument_list|)
block|;
return|return
name|EndLoc
operator|.
name|isInvalid
argument_list|()
condition|?
name|getInstantiationLocStart
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
name|getInstantiationLocRange
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|getInstantiationLocStart
argument_list|()
argument_list|,
name|getInstantiationLocEnd
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|isMacroArgInstantiation
argument_list|()
specifier|const
block|{
comment|// Note that this needs to return false for default constructed objects.
return|return
name|getInstantiationLocStart
argument_list|()
operator|.
name|isValid
argument_list|()
operator|&&
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|InstantiationLocEnd
argument_list|)
operator|.
name|isInvalid
argument_list|()
return|;
block|}
comment|/// create - Return a InstantiationInfo for an expansion. ILStart and
comment|/// ILEnd specify the instantiation range (where the macro is expanded),
comment|/// and SL specifies the spelling location (where the characters from the
comment|/// token come from). All three can refer to normal File SLocs or
comment|/// instantiation locations.
specifier|static
name|InstantiationInfo
name|create
parameter_list|(
name|SourceLocation
name|SL
parameter_list|,
name|SourceLocation
name|ILStart
parameter_list|,
name|SourceLocation
name|ILEnd
parameter_list|)
block|{
name|InstantiationInfo
name|X
decl_stmt|;
name|X
operator|.
name|SpellingLoc
operator|=
name|SL
operator|.
name|getRawEncoding
argument_list|()
expr_stmt|;
name|X
operator|.
name|InstantiationLocStart
operator|=
name|ILStart
operator|.
name|getRawEncoding
argument_list|()
expr_stmt|;
name|X
operator|.
name|InstantiationLocEnd
operator|=
name|ILEnd
operator|.
name|getRawEncoding
argument_list|()
expr_stmt|;
return|return
name|X
return|;
block|}
comment|/// createForMacroArg - Return a special InstantiationInfo for the
comment|/// expansion of a macro argument into a function-like macro's body. IL
comment|/// specifies the instantiation location (where the macro is expanded).
comment|/// This doesn't need to be a range because a macro is always instantiated
comment|/// at a macro parameter reference, and macro parameters are always exactly
comment|/// one token. SL specifies the spelling location (where the characters
comment|/// from the token come from). IL and SL can both refer to normal File
comment|/// SLocs or instantiation locations.
comment|///
comment|/// Given the code:
comment|/// \code
comment|///   #define F(x) f(x)
comment|///   F(42);
comment|/// \endcode
comment|///
comment|/// When expanding '\c F(42)', the '\c x' would call this with an SL
comment|/// pointing at '\c 42' anad an IL pointing at its location in the
comment|/// definition of '\c F'.
specifier|static
name|InstantiationInfo
name|createForMacroArg
parameter_list|(
name|SourceLocation
name|SL
parameter_list|,
name|SourceLocation
name|IL
parameter_list|)
block|{
comment|// We store an intentionally invalid source location for the end of the
comment|// instantiation range to mark that this is a macro argument instantation
comment|// rather than a normal one.
return|return
name|create
argument_list|(
name|SL
argument_list|,
name|IL
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// SLocEntry - This is a discriminated union of FileInfo and
comment|/// InstantiationInfo.  SourceManager keeps an array of these objects, and
comment|/// they are uniquely identified by the FileID datatype.
name|class
name|SLocEntry
block|{
name|unsigned
name|Offset
decl_stmt|;
comment|// low bit is set for instantiation info.
union|union
block|{
name|FileInfo
name|File
decl_stmt|;
name|InstantiationInfo
name|Instantiation
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
name|isInstantiation
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
name|isInstantiation
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
name|InstantiationInfo
operator|&
name|getInstantiation
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isInstantiation
argument_list|()
operator|&&
literal|"Not an instantiation SLocEntry!"
argument_list|)
block|;
return|return
name|Instantiation
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
name|InstantiationInfo
modifier|&
name|II
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
name|Instantiation
operator|=
name|II
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
comment|/// \brief Read the source location entry with index ID.
comment|///
comment|/// \returns true if an error occurred that prevented the source-location
comment|/// entry from being loaded.
name|virtual
name|bool
name|ReadSLocEntry
parameter_list|(
name|unsigned
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
parameter_list|)
block|{
name|LQueryFID
operator|=
name|LHS
expr_stmt|;
name|RQueryFID
operator|=
name|RHS
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
comment|/// SourceManager - This file handles loading and caching of source files into
comment|/// memory.  This object owns the MemoryBuffer objects for all of the loaded
comment|/// files and assigns unique FileID's for each unique #include chain.
comment|///
comment|/// The SourceManager can be queried for information about SourceLocation
comment|/// objects, turning them into either spelling or instantiation locations.
comment|/// Spelling locations represent where the bytes corresponding to a token came
comment|/// from and instantiation locations represent where the location is in the
comment|/// user's view.  In the case of a macro expansion, for example, the spelling
comment|/// location indicates  where the expanded token came from and the instantiation
comment|/// location specifies where it was expanded.
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
comment|/// \brief Diagnostic object.
name|Diagnostic
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
comment|/// SLocEntryTable - This is an array of SLocEntry's that we have created.
comment|/// FileID is an index into this vector.  This array is sorted by the offset.
name|std
operator|::
name|vector
operator|<
name|SrcMgr
operator|::
name|SLocEntry
operator|>
name|SLocEntryTable
block|;
comment|/// NextOffset - This is the next available offset that a new SLocEntry can
comment|/// start at.  It is SLocEntryTable.back().getOffset()+size of back() entry.
name|unsigned
name|NextOffset
block|;
comment|/// \brief If source location entries are being lazily loaded from
comment|/// an external source, this vector indicates whether the Ith source
comment|/// location entry has already been loaded from the external storage.
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
comment|// SourceManager doesn't support copy construction.
name|explicit
name|SourceManager
argument_list|(
specifier|const
name|SourceManager
operator|&
argument_list|)
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|SourceManager
operator|&
operator|)
block|;
name|public
operator|:
name|SourceManager
argument_list|(
name|Diagnostic
operator|&
name|Diag
argument_list|,
name|FileManager
operator|&
name|FileMgr
argument_list|)
block|;
operator|~
name|SourceManager
argument_list|()
block|;
name|void
name|clearIDTables
argument_list|()
block|;
name|Diagnostic
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
argument_list|(
argument|bool value
argument_list|)
block|{
name|OverridenFilesKeepOriginalName
operator|=
name|value
block|;   }
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
argument_list|(
argument|const FileEntry *SourceFile
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
block|;
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
block|;
return|return
name|MainFileID
return|;
block|}
comment|/// \brief Set the file ID for the precompiled preamble, which is also the
comment|/// main file.
name|void
name|SetPreambleFileID
argument_list|(
argument|FileID Preamble
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
block|;
name|MainFileID
operator|=
name|Preamble
block|;   }
comment|//===--------------------------------------------------------------------===//
comment|// Methods to create new FileID's and instantiations.
comment|//===--------------------------------------------------------------------===//
comment|/// createFileID - Create a new FileID that represents the specified file
comment|/// being #included from the specified IncludePosition.  This translates NULL
comment|/// into standard input.
comment|/// PreallocateID should be non-zero to specify which pre-allocated,
comment|/// lazily computed source location is being filled in by this operation.
name|FileID
name|createFileID
argument_list|(
argument|const FileEntry *SourceFile
argument_list|,
argument|SourceLocation IncludePos
argument_list|,
argument|SrcMgr::CharacteristicKind FileCharacter
argument_list|,
argument|unsigned PreallocatedID =
literal|0
argument_list|,
argument|unsigned Offset =
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
block|;
name|assert
argument_list|(
name|IR
operator|&&
literal|"getOrCreateContentCache() cannot return NULL"
argument_list|)
block|;
return|return
name|createFileID
argument_list|(
name|IR
argument_list|,
name|IncludePos
argument_list|,
name|FileCharacter
argument_list|,
name|PreallocatedID
argument_list|,
name|Offset
argument_list|)
return|;
block|}
comment|/// createFileIDForMemBuffer - Create a new FileID that represents the
comment|/// specified memory buffer.  This does no caching of the buffer and takes
comment|/// ownership of the MemoryBuffer, so only pass a MemoryBuffer to this once.
name|FileID
name|createFileIDForMemBuffer
argument_list|(
argument|const llvm::MemoryBuffer *Buffer
argument_list|,
argument|unsigned PreallocatedID =
literal|0
argument_list|,
argument|unsigned Offset =
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
name|PreallocatedID
argument_list|,
name|Offset
argument_list|)
return|;
block|}
comment|/// createMainFileIDForMembuffer - Create the FileID for a memory buffer
comment|///  that will represent the FileID for the main source.  One example
comment|///  of when this would be used is when the main source is read from STDIN.
name|FileID
name|createMainFileIDForMemBuffer
argument_list|(
argument|const llvm::MemoryBuffer *Buffer
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
block|;
name|MainFileID
operator|=
name|createFileIDForMemBuffer
argument_list|(
name|Buffer
argument_list|)
block|;
return|return
name|MainFileID
return|;
block|}
comment|/// createMacroArgInstantiationLoc - Return a new SourceLocation that encodes
comment|/// the fact that a token from SpellingLoc should actually be referenced from
comment|/// InstantiationLoc, and that it represents the instantiation of a macro
comment|/// argument into the function-like macro body.
name|SourceLocation
name|createMacroArgInstantiationLoc
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|SourceLocation InstantiationLoc
argument_list|,
argument|unsigned TokLength
argument_list|)
block|;
comment|/// createInstantiationLoc - Return a new SourceLocation that encodes the fact
comment|/// that a token from SpellingLoc should actually be referenced from
comment|/// InstantiationLoc.
name|SourceLocation
name|createInstantiationLoc
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|SourceLocation InstantiationLocStart
argument_list|,
argument|SourceLocation InstantiationLocEnd
argument_list|,
argument|unsigned TokLength
argument_list|,
argument|unsigned PreallocatedID =
literal|0
argument_list|,
argument|unsigned Offset =
literal|0
argument_list|)
block|;
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
block|;
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
argument|const FileEntry *SourceFile
argument_list|,
argument|const llvm::MemoryBuffer *Buffer
argument_list|,
argument|bool DoNotFree = false
argument_list|)
block|;
comment|/// \brief Override the the given source file with another one.
comment|///
comment|/// \param SourceFile the source file which will be overriden.
comment|///
comment|/// \param NewFile the file whose contents will be used as the
comment|/// data instead of the contents of the given source file.
name|void
name|overrideFileContents
argument_list|(
specifier|const
name|FileEntry
operator|*
name|SourceFile
argument_list|,
specifier|const
name|FileEntry
operator|*
name|NewFile
argument_list|)
block|;
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
operator|*
name|getFileEntryForID
argument_list|(
argument|FileID FID
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
name|llvm
operator|::
name|StringRef
name|getBufferData
argument_list|(
argument|FileID FID
argument_list|,
argument|bool *Invalid =
literal|0
argument_list|)
specifier|const
expr_stmt|;
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
name|assert
argument_list|(
name|FID
operator|.
name|ID
operator|<
name|SLocEntryTable
operator|.
name|size
argument_list|()
operator|&&
literal|"FileID out of range"
argument_list|)
expr_stmt|;
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
comment|/// getInstantiationLoc - Given a SourceLocation object, return the
comment|/// instantiation location referenced by the ID.
name|SourceLocation
name|getInstantiationLoc
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
block|{
comment|// Handle the non-mapped case inline, defer to out of line code to handle
comment|// instantiations.
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
name|getInstantiationLocSlowCase
argument_list|(
name|Loc
argument_list|)
return|;
block|}
comment|/// getImmediateInstantiationRange - Loc is required to be an instantiation
comment|/// location.  Return the start/end of the instantiation information.
name|std
operator|::
name|pair
operator|<
name|SourceLocation
operator|,
name|SourceLocation
operator|>
name|getImmediateInstantiationRange
argument_list|(
argument|SourceLocation Loc
argument_list|)
specifier|const
expr_stmt|;
comment|/// getInstantiationRange - Given a SourceLocation object, return the
comment|/// range of tokens covered by the instantiation in the ultimate file.
name|std
operator|::
name|pair
operator|<
name|SourceLocation
operator|,
name|SourceLocation
operator|>
name|getInstantiationRange
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
comment|// instantiations.
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
comment|/// getDecomposedInstantiationLoc - Decompose the specified location into a
comment|/// raw FileID + Offset pair.  If the location is an instantiation record,
comment|/// walk through it until we find the final location instantiated.
name|std
operator|::
name|pair
operator|<
name|FileID
operator|,
name|unsigned
operator|>
name|getDecomposedInstantiationLoc
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
name|getDecomposedInstantiationLocSlowCase
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
comment|/// FileID + Offset pair.  If the location is an instantiation record, walk
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
comment|/// isMacroArgInstantiation - This method tests whether the given source
end_comment

begin_comment
comment|/// location represents a macro argument's instantiation into the
end_comment

begin_comment
comment|/// function-like macro definition. Such source locations only appear inside
end_comment

begin_comment
comment|/// of the instantiation locations representing where a particular
end_comment

begin_comment
comment|/// function-like macro was expanded.
end_comment

begin_decl_stmt
name|bool
name|isMacroArgInstantiation
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
decl_stmt|;
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
comment|/// returns zero if the column number isn't known.  This may only be called on
end_comment

begin_comment
comment|/// a file sloc, so you must choose a spelling or instantiation location
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
name|getInstantiationColumnNumber
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
name|getInstantiationLineNumber
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
comment|/// Note that a presumed location is always given as the instantiation point
end_comment

begin_comment
comment|/// of an instantiation location, not at the spelling location.
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
comment|/// \brief Given a specific chunk of a FileID (FileID with offset+length),
end_comment

begin_comment
comment|/// returns true if \arg Loc is inside that chunk and sets relative offset
end_comment

begin_comment
comment|/// (offset of \arg Loc from beginning of chunk) to \arg relativeOffset.
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
name|offset
argument_list|,
name|unsigned
name|length
argument_list|,
name|unsigned
operator|*
name|relativeOffset
operator|=
literal|0
argument_list|)
decl|const
block|{
name|assert
argument_list|(
operator|!
name|FID
operator|.
name|isInvalid
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|Loc
operator|.
name|isInvalid
argument_list|()
condition|)
return|return
name|false
return|;
name|unsigned
name|start
init|=
name|getSLocEntry
argument_list|(
name|FID
argument_list|)
operator|.
name|getOffset
argument_list|()
operator|+
name|offset
decl_stmt|;
name|unsigned
name|end
init|=
name|start
operator|+
name|length
decl_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
comment|// Make sure offset/length describe a chunk inside the given FileID.
name|unsigned
name|NextOffset
decl_stmt|;
if|if
condition|(
name|FID
operator|.
name|ID
operator|+
literal|1
operator|==
name|SLocEntryTable
operator|.
name|size
argument_list|()
condition|)
name|NextOffset
operator|=
name|getNextOffset
argument_list|()
expr_stmt|;
else|else
name|NextOffset
operator|=
name|getSLocEntry
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
expr_stmt|;
name|assert
argument_list|(
name|start
operator|<
name|NextOffset
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|end
operator|<
name|NextOffset
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|Loc
operator|.
name|getOffset
argument_list|()
operator|>=
name|start
operator|&&
name|Loc
operator|.
name|getOffset
argument_list|()
operator|<
name|end
condition|)
block|{
if|if
condition|(
name|relativeOffset
condition|)
operator|*
name|relativeOffset
operator|=
name|Loc
operator|.
name|getOffset
argument_list|()
operator|-
name|start
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

begin_decl_stmt
name|unsigned
name|getLineTableFilenameID
argument_list|(
name|llvm
operator|::
name|StringRef
name|Str
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_function_decl
name|SourceLocation
name|getLocation
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|SourceFile
parameter_list|,
name|unsigned
name|Line
parameter_list|,
name|unsigned
name|Col
parameter_list|)
function_decl|;
end_function_decl

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

begin_function
specifier|static
name|bool
name|isBeforeInSourceLocationOffset
parameter_list|(
name|SourceLocation
name|LHS
parameter_list|,
name|SourceLocation
name|RHS
parameter_list|)
block|{
return|return
name|isBeforeInSourceLocationOffset
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
end_function

begin_comment
comment|/// \brief Determines the order of a source location and a source location
end_comment

begin_comment
comment|/// offset in the "source location address space".
end_comment

begin_function
specifier|static
name|bool
name|isBeforeInSourceLocationOffset
parameter_list|(
name|SourceLocation
name|LHS
parameter_list|,
name|unsigned
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|.
name|getOffset
argument_list|()
operator|<
name|RHS
return|;
block|}
end_function

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

begin_expr_stmt
name|unsigned
name|sloc_entry_size
argument_list|()
specifier|const
block|{
return|return
name|SLocEntryTable
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// FIXME: Exposing this is a little gross; what we want is a good way
end_comment

begin_comment
comment|//  to iterate the entries that were not defined in an AST file (or
end_comment

begin_comment
comment|//  any other external source).
end_comment

begin_expr_stmt
name|unsigned
name|sloc_loaded_entry_size
argument_list|()
specifier|const
block|{
return|return
name|SLocEntryLoaded
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|SrcMgr
operator|::
name|SLocEntry
operator|&
name|getSLocEntry
argument_list|(
argument|unsigned ID
argument_list|,
argument|bool *Invalid =
literal|0
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|ID
operator|<
name|SLocEntryTable
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid id"
argument_list|)
block|;
comment|// If we haven't loaded this source-location entry from the external source
comment|// yet, do so now.
if|if
condition|(
name|ExternalSLocEntries
operator|&&
name|ID
operator|<
name|SLocEntryLoaded
operator|.
name|size
argument_list|()
operator|&&
operator|!
name|SLocEntryLoaded
index|[
name|ID
index|]
operator|&&
name|ExternalSLocEntries
operator|->
name|ReadSLocEntry
argument_list|(
name|ID
argument_list|)
operator|&&
name|Invalid
condition|)
operator|*
name|Invalid
operator|=
name|true
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|SLocEntryTable
index|[
name|ID
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
name|getSLocEntry
argument_list|(
name|FID
operator|.
name|ID
argument_list|,
name|Invalid
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getNextOffset
argument_list|()
specifier|const
block|{
return|return
name|NextOffset
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Preallocate some number of source location entries, which
end_comment

begin_comment
comment|/// will be loaded as needed from the given external source.
end_comment

begin_function_decl
name|void
name|PreallocateSLocEntries
parameter_list|(
name|ExternalSLocEntrySource
modifier|*
name|Source
parameter_list|,
name|unsigned
name|NumSLocEntries
parameter_list|,
name|unsigned
name|NextOffset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Clear out any preallocated source location entries that
end_comment

begin_comment
comment|/// haven't already been loaded.
end_comment

begin_function_decl
name|void
name|ClearPreallocatedSLocEntries
parameter_list|()
function_decl|;
end_function_decl

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
comment|/// createInstantiationLoc - Implements the common elements of storing an
end_comment

begin_comment
comment|/// instantiation info struct into the SLocEntry table and producing a source
end_comment

begin_comment
comment|/// location that refers to it.
end_comment

begin_decl_stmt
name|SourceLocation
name|createInstantiationLocImpl
argument_list|(
specifier|const
name|SrcMgr
operator|::
name|InstantiationInfo
operator|&
name|II
argument_list|,
name|unsigned
name|TokLength
argument_list|,
name|unsigned
name|PreallocatedID
operator|=
literal|0
argument_list|,
name|unsigned
name|Offset
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
comment|// If this is the last entry than it does.  Otherwise, the entry after it
comment|// has to not include it.
if|if
condition|(
name|FID
operator|.
name|ID
operator|+
literal|1
operator|==
name|SLocEntryTable
operator|.
name|size
argument_list|()
condition|)
return|return
name|true
return|;
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
name|unsigned
name|PreallocatedID
operator|=
literal|0
argument_list|,
name|unsigned
name|Offset
operator|=
literal|0
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
name|SourceLocation
name|getInstantiationLocSlowCase
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

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|FileID
operator|,
name|unsigned
operator|>
name|getDecomposedInstantiationLocSlowCase
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

begin_comment
unit|};   }
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

