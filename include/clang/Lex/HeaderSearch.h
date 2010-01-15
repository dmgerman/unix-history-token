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
name|bool
name|isImport
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
comment|/// NumIncludes - This is the number of times the file has been included
comment|/// already.
name|unsigned
name|short
name|NumIncludes
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
comment|/// \brief The ID number of the controlling macro.
comment|///
comment|/// This ID number will be non-zero when there is a controlling
comment|/// macro whose IdentifierInfo may not yet have been loaded from
comment|/// external storage.
name|unsigned
name|ControllingMacroID
decl_stmt|;
name|HeaderFileInfo
argument_list|()
operator|:
name|isImport
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
name|NumIncludes
argument_list|(
literal|0
argument_list|)
operator|,
name|ControllingMacro
argument_list|(
literal|0
argument_list|)
operator|,
name|ControllingMacroID
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
block|}
struct|;
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
comment|/// consequtively. Requests for<x> search the current dir first, then each
comment|/// directory in SearchDirs, starting at SystemDirIdx, consequtively.  If
comment|/// NoCurDirSearch is true, then the check for the file in the current
comment|/// directory is supressed.
name|std
operator|::
name|vector
operator|<
name|DirectoryLookup
operator|>
name|SearchDirs
expr_stmt|;
name|unsigned
name|SystemDirIdx
decl_stmt|;
name|bool
name|NoCurDirSearch
decl_stmt|;
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
expr|>
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
comment|/// \brief Entity used to resolve the identifier IDs of controlling
comment|/// macros into IdentifierInfo pointers, as needed.
name|ExternalIdentifierLookup
modifier|*
name|ExternalLookup
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
name|systemDirIdx
argument_list|,
name|bool
name|noCurDirSearch
argument_list|)
block|{
name|SearchDirs
operator|=
name|dirs
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
comment|/// LookupFile - Given a "foo" or<foo> reference, look up the indicated file,
comment|/// return null on failure.  isAngled indicates whether the file reference is
comment|/// a<> reference.  If successful, this returns 'UsedDir', the
comment|/// DirectoryLookup member the file was found in, or null if not applicable.
comment|/// If CurDir is non-null, the file was found in the specified directory
comment|/// search location.  This is used to implement #include_next.  CurFileEnt, if
comment|/// non-null, indicates where the #including file is, in case a relative
comment|/// search is needed.
specifier|const
name|FileEntry
modifier|*
name|LookupFile
argument_list|(
name|llvm
operator|::
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
name|llvm
operator|::
name|StringRef
name|Filename
argument_list|,
specifier|const
name|FileEntry
operator|*
name|RelativeFileEnt
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
argument_list|(
name|llvm
operator|::
name|StringRef
name|FWName
argument_list|)
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
name|getFileInfo
argument_list|(
name|File
argument_list|)
operator|.
name|isImport
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
name|iterator
name|header_file_iterator
expr_stmt|;
name|header_file_iterator
name|header_file_begin
parameter_list|()
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
parameter_list|()
block|{
return|return
name|FileInfo
operator|.
name|end
argument_list|()
return|;
block|}
comment|// Used by PCHReader.
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
name|void
name|PrintStats
parameter_list|()
function_decl|;
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

