begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- HeaderSearch.h - Resolve Header File Locations ---------*- C++ -*-===//
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
comment|// This file defines the HeaderSearch interface.
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
name|LLVM_CLANG_LEX_HEADERSEARCH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_HEADERSEARCH_H
end_define

begin_include
include|#
directive|include
file|"clang/Lex/DirectoryLookup.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
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
name|ExternalIdentifierLookup
decl_stmt|;
name|class
name|FileEntry
decl_stmt|;
name|class
name|FileManager
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
comment|/// HeaderFileInfo - The preprocessor keeps track of this information for each
comment|/// file that is #included.
struct|struct
name|HeaderFileInfo
block|{
comment|/// isImport - True if this is a #import'd or #pragma once file.
name|unsigned
name|isImport
range|:
literal|1
decl_stmt|;
comment|/// isPragmaOnce - True if this is  #pragma once file.
name|unsigned
name|isPragmaOnce
range|:
literal|1
decl_stmt|;
comment|/// DirInfo - Keep track of whether this is a system header, and if so,
comment|/// whether it is C++ clean or not.  This can be set by the include paths or
comment|/// by #pragma gcc system_header.  This is an instance of
comment|/// SrcMgr::CharacteristicKind.
name|unsigned
name|DirInfo
range|:
literal|2
decl_stmt|;
comment|/// \brief Whether this header file info was supplied by an external source.
name|unsigned
name|External
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this structure is considered to already have been
comment|/// "resolved", meaning that it was loaded from the external source.
name|unsigned
name|Resolved
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this is a header inside a framework that is currently
comment|/// being built.
comment|///
comment|/// When a framework is being built, the headers have not yet been placed
comment|/// into the appropriate framework subdirectories, and therefore are
comment|/// provided via a header map. This bit indicates when this is one of
comment|/// those framework headers.
name|unsigned
name|IndexHeaderMapHeader
range|:
literal|1
decl_stmt|;
comment|/// NumIncludes - This is the number of times the file has been included
comment|/// already.
name|unsigned
name|short
name|NumIncludes
decl_stmt|;
comment|/// \brief The ID number of the controlling macro.
comment|///
comment|/// This ID number will be non-zero when there is a controlling
comment|/// macro whose IdentifierInfo may not yet have been loaded from
comment|/// external storage.
name|unsigned
name|ControllingMacroID
decl_stmt|;
comment|/// ControllingMacro - If this file has a #ifndef XXX (or equivalent) guard
comment|/// that protects the entire contents of the file, this is the identifier
comment|/// for the macro that controls whether or not it has any effect.
comment|///
comment|/// Note: Most clients should use getControllingMacro() to access
comment|/// the controlling macro of this header, since
comment|/// getControllingMacro() is able to load a controlling macro from
comment|/// external storage.
specifier|const
name|IdentifierInfo
modifier|*
name|ControllingMacro
decl_stmt|;
comment|/// \brief If this header came from a framework include, this is the name
comment|/// of the framework.
name|StringRef
name|Framework
decl_stmt|;
name|HeaderFileInfo
argument_list|()
operator|:
name|isImport
argument_list|(
name|false
argument_list|)
operator|,
name|isPragmaOnce
argument_list|(
name|false
argument_list|)
operator|,
name|DirInfo
argument_list|(
name|SrcMgr
operator|::
name|C_User
argument_list|)
operator|,
name|External
argument_list|(
name|false
argument_list|)
operator|,
name|Resolved
argument_list|(
name|false
argument_list|)
operator|,
name|IndexHeaderMapHeader
argument_list|(
name|false
argument_list|)
operator|,
name|NumIncludes
argument_list|(
literal|0
argument_list|)
operator|,
name|ControllingMacroID
argument_list|(
literal|0
argument_list|)
operator|,
name|ControllingMacro
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// \brief Retrieve the controlling macro for this header file, if
comment|/// any.
specifier|const
name|IdentifierInfo
operator|*
name|getControllingMacro
argument_list|(
name|ExternalIdentifierLookup
operator|*
name|External
argument_list|)
expr_stmt|;
comment|/// \brief Determine whether this is a non-default header file info, e.g.,
comment|/// it corresponds to an actual header we've included or tried to include.
name|bool
name|isNonDefault
argument_list|()
specifier|const
block|{
return|return
name|isImport
operator|||
name|isPragmaOnce
operator|||
name|NumIncludes
operator|||
name|ControllingMacro
operator|||
name|ControllingMacroID
return|;
block|}
block|}
struct|;
comment|/// \brief An external source of header file information, which may supply
comment|/// information about header files already included.
name|class
name|ExternalHeaderFileInfoSource
block|{
name|public
label|:
name|virtual
operator|~
name|ExternalHeaderFileInfoSource
argument_list|()
expr_stmt|;
comment|/// \brief Retrieve the header file information for the given file entry.
comment|///
comment|/// \returns Header file information for the given file entry, with the
comment|/// \c External bit set. If the file entry is not known, return a
comment|/// default-constructed \c HeaderFileInfo.
name|virtual
name|HeaderFileInfo
name|GetHeaderFileInfo
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|FE
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|/// HeaderSearch - This class encapsulates the information needed to find the
comment|/// file referenced by a #include or #include_next, (sub-)framework lookup, etc.
name|class
name|HeaderSearch
block|{
name|FileManager
modifier|&
name|FileMgr
decl_stmt|;
comment|/// #include search path information.  Requests for #include "x" search the
comment|/// directory of the #including file first, then each directory in SearchDirs
comment|/// consecutively. Requests for<x> search the current dir first, then each
comment|/// directory in SearchDirs, starting at AngledDirIdx, consecutively.  If
comment|/// NoCurDirSearch is true, then the check for the file in the current
comment|/// directory is suppressed.
name|std
operator|::
name|vector
operator|<
name|DirectoryLookup
operator|>
name|SearchDirs
expr_stmt|;
name|unsigned
name|AngledDirIdx
decl_stmt|;
name|unsigned
name|SystemDirIdx
decl_stmt|;
name|bool
name|NoCurDirSearch
decl_stmt|;
comment|/// \brief The path to the module cache.
name|std
operator|::
name|string
name|ModuleCachePath
expr_stmt|;
comment|/// \brief The name of the module we're building.
name|std
operator|::
name|string
name|BuildingModule
expr_stmt|;
comment|/// FileInfo - This contains all of the preprocessor-specific data about files
comment|/// that are included.  The vector is indexed by the FileEntry's UID.
comment|///
name|std
operator|::
name|vector
operator|<
name|HeaderFileInfo
operator|>
name|FileInfo
expr_stmt|;
comment|/// LookupFileCache - This is keeps track of each lookup performed by
comment|/// LookupFile.  The first part of the value is the starting index in
comment|/// SearchDirs that the cached search was performed from.  If there is a hit
comment|/// and this value doesn't match the current query, the cache has to be
comment|/// ignored.  The second value is the entry in SearchDirs that satisfied the
comment|/// query.
name|llvm
operator|::
name|StringMap
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
operator|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|LookupFileCache
expr_stmt|;
comment|/// FrameworkMap - This is a collection mapping a framework or subframework
comment|/// name like "Carbon" to the Carbon.framework directory.
name|llvm
operator|::
name|StringMap
operator|<
specifier|const
name|DirectoryEntry
operator|*
operator|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|FrameworkMap
expr_stmt|;
comment|/// HeaderMaps - This is a mapping from FileEntry -> HeaderMap, uniquing
comment|/// headermaps.  This vector owns the headermap.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|FileEntry
operator|*
operator|,
specifier|const
name|HeaderMap
operator|*
operator|>
expr|>
name|HeaderMaps
expr_stmt|;
comment|/// \brief Uniqued set of framework names, which is used to track which
comment|/// headers were included as framework headers.
name|llvm
operator|::
name|StringSet
operator|<
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|FrameworkNames
expr_stmt|;
comment|/// \brief Entity used to resolve the identifier IDs of controlling
comment|/// macros into IdentifierInfo pointers, as needed.
name|ExternalIdentifierLookup
modifier|*
name|ExternalLookup
decl_stmt|;
comment|/// \brief Entity used to look up stored header file information.
name|ExternalHeaderFileInfoSource
modifier|*
name|ExternalSource
decl_stmt|;
comment|// Various statistics we track for performance analysis.
name|unsigned
name|NumIncluded
decl_stmt|;
name|unsigned
name|NumMultiIncludeFileOptzn
decl_stmt|;
name|unsigned
name|NumFrameworkLookups
decl_stmt|,
name|NumSubFrameworkLookups
decl_stmt|;
comment|// HeaderSearch doesn't support default or copy construction.
name|explicit
name|HeaderSearch
parameter_list|()
function_decl|;
name|explicit
name|HeaderSearch
parameter_list|(
specifier|const
name|HeaderSearch
modifier|&
parameter_list|)
function_decl|;
name|void
name|operator
init|=
operator|(
specifier|const
name|HeaderSearch
operator|&
operator|)
decl_stmt|;
name|public
label|:
name|HeaderSearch
argument_list|(
name|FileManager
operator|&
name|FM
argument_list|)
expr_stmt|;
operator|~
name|HeaderSearch
argument_list|()
expr_stmt|;
name|FileManager
operator|&
name|getFileMgr
argument_list|()
specifier|const
block|{
return|return
name|FileMgr
return|;
block|}
comment|/// SetSearchPaths - Interface for setting the file search paths.
comment|///
name|void
name|SetSearchPaths
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|DirectoryLookup
operator|>
operator|&
name|dirs
argument_list|,
name|unsigned
name|angledDirIdx
argument_list|,
name|unsigned
name|systemDirIdx
argument_list|,
name|bool
name|noCurDirSearch
argument_list|)
block|{
name|assert
argument_list|(
name|angledDirIdx
operator|<=
name|systemDirIdx
operator|&&
name|systemDirIdx
operator|<=
name|dirs
operator|.
name|size
argument_list|()
operator|&&
literal|"Directory indicies are unordered"
argument_list|)
expr_stmt|;
name|SearchDirs
operator|=
name|dirs
expr_stmt|;
name|AngledDirIdx
operator|=
name|angledDirIdx
expr_stmt|;
name|SystemDirIdx
operator|=
name|systemDirIdx
expr_stmt|;
name|NoCurDirSearch
operator|=
name|noCurDirSearch
expr_stmt|;
comment|//LookupFileCache.clear();
block|}
comment|/// \brief Set the path to the module cache and the name of the module
comment|/// we're building
name|void
name|configureModules
parameter_list|(
name|StringRef
name|CachePath
parameter_list|,
name|StringRef
name|BuildingModule
parameter_list|)
block|{
name|ModuleCachePath
operator|=
name|CachePath
expr_stmt|;
name|this
operator|->
name|BuildingModule
operator|=
name|BuildingModule
expr_stmt|;
block|}
comment|/// ClearFileInfo - Forget everything we know about headers so far.
name|void
name|ClearFileInfo
parameter_list|()
block|{
name|FileInfo
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|void
name|SetExternalLookup
parameter_list|(
name|ExternalIdentifierLookup
modifier|*
name|EIL
parameter_list|)
block|{
name|ExternalLookup
operator|=
name|EIL
expr_stmt|;
block|}
name|ExternalIdentifierLookup
operator|*
name|getExternalLookup
argument_list|()
specifier|const
block|{
return|return
name|ExternalLookup
return|;
block|}
comment|/// \brief Set the external source of header information.
name|void
name|SetExternalSource
parameter_list|(
name|ExternalHeaderFileInfoSource
modifier|*
name|ES
parameter_list|)
block|{
name|ExternalSource
operator|=
name|ES
expr_stmt|;
block|}
comment|/// LookupFile - Given a "foo" or<foo> reference, look up the indicated file,
comment|/// return null on failure.
comment|///
comment|/// \returns If successful, this returns 'UsedDir', the DirectoryLookup member
comment|/// the file was found in, or null if not applicable.
comment|///
comment|/// \param isAngled indicates whether the file reference is a<> reference.
comment|///
comment|/// \param CurDir If non-null, the file was found in the specified directory
comment|/// search location.  This is used to implement #include_next.
comment|///
comment|/// \param CurFileEnt If non-null, indicates where the #including file is, in
comment|/// case a relative search is needed.
comment|///
comment|/// \param SearchPath If non-null, will be set to the search path relative
comment|/// to which the file was found. If the include path is absolute, SearchPath
comment|/// will be set to an empty string.
comment|///
comment|/// \param RelativePath If non-null, will be set to the path relative to
comment|/// SearchPath at which the file was found. This only differs from the
comment|/// Filename for framework includes.
comment|///
comment|/// \param SuggestedModule If non-null, and the file found is semantically
comment|/// part of a known module, this will be set to the name of the module that
comment|/// could be imported instead of preprocessing/parsing the file found.
specifier|const
name|FileEntry
modifier|*
name|LookupFile
argument_list|(
name|StringRef
name|Filename
argument_list|,
name|bool
name|isAngled
argument_list|,
specifier|const
name|DirectoryLookup
operator|*
name|FromDir
argument_list|,
specifier|const
name|DirectoryLookup
operator|*
operator|&
name|CurDir
argument_list|,
specifier|const
name|FileEntry
operator|*
name|CurFileEnt
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|*
name|SearchPath
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|*
name|RelativePath
argument_list|,
name|StringRef
operator|*
name|SuggestedModule
argument_list|)
decl_stmt|;
comment|/// LookupSubframeworkHeader - Look up a subframework for the specified
comment|/// #include file.  For example, if #include'ing<HIToolbox/HIToolbox.h> from
comment|/// within ".../Carbon.framework/Headers/Carbon.h", check to see if HIToolbox
comment|/// is a subframework within Carbon.framework.  If so, return the FileEntry
comment|/// for the designated file, otherwise return null.
specifier|const
name|FileEntry
modifier|*
name|LookupSubframeworkHeader
argument_list|(
name|StringRef
name|Filename
argument_list|,
specifier|const
name|FileEntry
operator|*
name|RelativeFileEnt
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|*
name|SearchPath
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|*
name|RelativePath
argument_list|)
decl_stmt|;
comment|/// LookupFrameworkCache - Look up the specified framework name in our
comment|/// framework cache, returning the DirectoryEntry it is in if we know,
comment|/// otherwise, return null.
specifier|const
name|DirectoryEntry
modifier|*
modifier|&
name|LookupFrameworkCache
parameter_list|(
name|StringRef
name|FWName
parameter_list|)
block|{
return|return
name|FrameworkMap
operator|.
name|GetOrCreateValue
argument_list|(
name|FWName
argument_list|)
operator|.
name|getValue
argument_list|()
return|;
block|}
comment|/// ShouldEnterIncludeFile - Mark the specified file as a target of of a
comment|/// #include, #include_next, or #import directive.  Return false if #including
comment|/// the file will have no effect or true if we should include it.
name|bool
name|ShouldEnterIncludeFile
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|,
name|bool
name|isImport
parameter_list|)
function_decl|;
comment|/// getFileDirFlavor - Return whether the specified file is a normal header,
comment|/// a system header, or a C++ friendly system header.
name|SrcMgr
operator|::
name|CharacteristicKind
name|getFileDirFlavor
argument_list|(
argument|const FileEntry *File
argument_list|)
block|{
return|return
operator|(
name|SrcMgr
operator|::
name|CharacteristicKind
operator|)
name|getFileInfo
argument_list|(
name|File
argument_list|)
operator|.
name|DirInfo
return|;
block|}
comment|/// MarkFileIncludeOnce - Mark the specified file as a "once only" file, e.g.
comment|/// due to #pragma once.
name|void
name|MarkFileIncludeOnce
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|)
block|{
name|HeaderFileInfo
modifier|&
name|FI
init|=
name|getFileInfo
argument_list|(
name|File
argument_list|)
decl_stmt|;
name|FI
operator|.
name|isImport
operator|=
name|true
expr_stmt|;
name|FI
operator|.
name|isPragmaOnce
operator|=
name|true
expr_stmt|;
block|}
comment|/// MarkFileSystemHeader - Mark the specified file as a system header, e.g.
comment|/// due to #pragma GCC system_header.
name|void
name|MarkFileSystemHeader
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|)
block|{
name|getFileInfo
argument_list|(
name|File
argument_list|)
operator|.
name|DirInfo
operator|=
name|SrcMgr
operator|::
name|C_System
expr_stmt|;
block|}
comment|/// IncrementIncludeCount - Increment the count for the number of times the
comment|/// specified FileEntry has been entered.
name|void
name|IncrementIncludeCount
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|)
block|{
operator|++
name|getFileInfo
argument_list|(
name|File
argument_list|)
operator|.
name|NumIncludes
expr_stmt|;
block|}
comment|/// SetFileControllingMacro - Mark the specified file as having a controlling
comment|/// macro.  This is used by the multiple-include optimization to eliminate
comment|/// no-op #includes.
name|void
name|SetFileControllingMacro
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|*
name|ControllingMacro
parameter_list|)
block|{
name|getFileInfo
argument_list|(
name|File
argument_list|)
operator|.
name|ControllingMacro
operator|=
name|ControllingMacro
expr_stmt|;
block|}
comment|/// \brief Determine whether this file is intended to be safe from
comment|/// multiple inclusions, e.g., it has #pragma once or a controlling
comment|/// macro.
comment|///
comment|/// This routine does not consider the effect of #import
name|bool
name|isFileMultipleIncludeGuarded
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|)
function_decl|;
comment|/// CreateHeaderMap - This method returns a HeaderMap for the specified
comment|/// FileEntry, uniquing them through the the 'HeaderMaps' datastructure.
specifier|const
name|HeaderMap
modifier|*
name|CreateHeaderMap
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|FE
parameter_list|)
function_decl|;
comment|/// \brief Search in the module cache path for a module with the given
comment|/// name.
comment|///
comment|/// \param If non-NULL, will be set to the module file name we expected to
comment|/// find (regardless of whether it was actually found or not).
comment|///
comment|/// \param UmbrellaHeader If non-NULL, and no module was found in the module
comment|/// cache, this routine will search in the framework paths to determine
comment|/// whether a module can be built from an umbrella header. If so, the pointee
comment|/// will be set to the path of the umbrella header.
comment|///
comment|/// \returns A file describing the named module, if available, or NULL to
comment|/// indicate that the module could not be found.
specifier|const
name|FileEntry
modifier|*
name|lookupModule
argument_list|(
name|StringRef
name|ModuleName
argument_list|,
name|std
operator|::
name|string
operator|*
name|ModuleFileName
operator|=
literal|0
argument_list|,
name|std
operator|::
name|string
operator|*
name|UmbrellaHeader
operator|=
literal|0
argument_list|)
decl_stmt|;
name|void
name|IncrementFrameworkLookupCount
parameter_list|()
block|{
operator|++
name|NumFrameworkLookups
expr_stmt|;
block|}
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|HeaderFileInfo
operator|>
operator|::
name|const_iterator
name|header_file_iterator
expr_stmt|;
name|header_file_iterator
name|header_file_begin
argument_list|()
specifier|const
block|{
return|return
name|FileInfo
operator|.
name|begin
argument_list|()
return|;
block|}
name|header_file_iterator
name|header_file_end
argument_list|()
specifier|const
block|{
return|return
name|FileInfo
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|header_file_size
argument_list|()
specifier|const
block|{
return|return
name|FileInfo
operator|.
name|size
argument_list|()
return|;
block|}
comment|// Used by ASTReader.
name|void
name|setHeaderFileInfoForUID
parameter_list|(
name|HeaderFileInfo
name|HFI
parameter_list|,
name|unsigned
name|UID
parameter_list|)
function_decl|;
comment|// Used by external tools
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|DirectoryLookup
operator|>
operator|::
name|const_iterator
name|search_dir_iterator
expr_stmt|;
name|search_dir_iterator
name|search_dir_begin
argument_list|()
specifier|const
block|{
return|return
name|SearchDirs
operator|.
name|begin
argument_list|()
return|;
block|}
name|search_dir_iterator
name|search_dir_end
argument_list|()
specifier|const
block|{
return|return
name|SearchDirs
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|search_dir_size
argument_list|()
specifier|const
block|{
return|return
name|SearchDirs
operator|.
name|size
argument_list|()
return|;
block|}
name|search_dir_iterator
name|quoted_dir_begin
argument_list|()
specifier|const
block|{
return|return
name|SearchDirs
operator|.
name|begin
argument_list|()
return|;
block|}
name|search_dir_iterator
name|quoted_dir_end
argument_list|()
specifier|const
block|{
return|return
name|SearchDirs
operator|.
name|begin
argument_list|()
operator|+
name|AngledDirIdx
return|;
block|}
name|search_dir_iterator
name|angled_dir_begin
argument_list|()
specifier|const
block|{
return|return
name|SearchDirs
operator|.
name|begin
argument_list|()
operator|+
name|AngledDirIdx
return|;
block|}
name|search_dir_iterator
name|angled_dir_end
argument_list|()
specifier|const
block|{
return|return
name|SearchDirs
operator|.
name|begin
argument_list|()
operator|+
name|SystemDirIdx
return|;
block|}
name|search_dir_iterator
name|system_dir_begin
argument_list|()
specifier|const
block|{
return|return
name|SearchDirs
operator|.
name|begin
argument_list|()
operator|+
name|SystemDirIdx
return|;
block|}
name|search_dir_iterator
name|system_dir_end
argument_list|()
specifier|const
block|{
return|return
name|SearchDirs
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// \brief Retrieve a uniqued framework name.
name|StringRef
name|getUniqueFrameworkName
parameter_list|(
name|StringRef
name|Framework
parameter_list|)
function_decl|;
name|void
name|PrintStats
parameter_list|()
function_decl|;
name|size_t
name|getTotalMemory
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|/// getFileInfo - Return the HeaderFileInfo structure for the specified
comment|/// FileEntry.
name|HeaderFileInfo
modifier|&
name|getFileInfo
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|FE
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

