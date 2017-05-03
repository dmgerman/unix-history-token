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
file|"clang/Lex/ModuleMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
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
file|<memory>
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
name|DiagnosticsEngine
decl_stmt|;
name|class
name|ExternalPreprocessorSource
decl_stmt|;
name|class
name|FileEntry
decl_stmt|;
name|class
name|FileManager
decl_stmt|;
name|class
name|HeaderSearchOptions
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
comment|/// \brief The preprocessor keeps track of this information for each
comment|/// file that is \#included.
struct|struct
name|HeaderFileInfo
block|{
comment|/// \brief True if this is a \#import'd or \#pragma once file.
name|unsigned
name|isImport
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this is a \#pragma once file.
name|unsigned
name|isPragmaOnce
range|:
literal|1
decl_stmt|;
comment|/// DirInfo - Keep track of whether this is a system header, and if so,
comment|/// whether it is C++ clean or not.  This can be set by the include paths or
comment|/// by \#pragma gcc system_header.  This is an instance of
comment|/// SrcMgr::CharacteristicKind.
name|unsigned
name|DirInfo
range|:
literal|2
decl_stmt|;
comment|/// \brief Whether this header file info was supplied by an external source,
comment|/// and has not changed since.
name|unsigned
name|External
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this header is part of a module.
name|unsigned
name|isModuleHeader
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this header is part of the module that we are building.
name|unsigned
name|isCompilingModuleHeader
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
comment|/// \brief Whether this file has been looked up as a header.
name|unsigned
name|IsValid
range|:
literal|1
decl_stmt|;
comment|/// \brief The number of times the file has been included already.
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
comment|/// If this file has a \#ifndef XXX (or equivalent) guard that
comment|/// protects the entire contents of the file, this is the identifier
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
name|isModuleHeader
argument_list|(
name|false
argument_list|)
operator|,
name|isCompilingModuleHeader
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
name|IsValid
argument_list|(
literal|0
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
argument|nullptr
argument_list|)
block|{}
comment|/// \brief Retrieve the controlling macro for this header file, if
comment|/// any.
specifier|const
name|IdentifierInfo
operator|*
name|getControllingMacro
argument_list|(
name|ExternalPreprocessorSource
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
comment|/// \brief Encapsulates the information needed to find the file referenced
comment|/// by a \#include or \#include_next, (sub-)framework lookup, etc.
name|class
name|HeaderSearch
block|{
comment|/// This structure is used to record entries in our framework cache.
struct|struct
name|FrameworkCacheEntry
block|{
comment|/// The directory entry which should be used for the cached framework.
specifier|const
name|DirectoryEntry
modifier|*
name|Directory
decl_stmt|;
comment|/// Whether this framework has been "user-specified" to be treated as if it
comment|/// were a system framework (even if it was found outside a system framework
comment|/// directory).
name|bool
name|IsUserSpecifiedSystemFramework
decl_stmt|;
block|}
struct|;
comment|/// \brief Header-search options used to initialize this header search.
name|std
operator|::
name|shared_ptr
operator|<
name|HeaderSearchOptions
operator|>
name|HSOpts
expr_stmt|;
name|DiagnosticsEngine
modifier|&
name|Diags
decl_stmt|;
name|FileManager
modifier|&
name|FileMgr
decl_stmt|;
comment|/// \#include search path information.  Requests for \#include "x" search the
comment|/// directory of the \#including file first, then each directory in SearchDirs
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
comment|/// \brief \#include prefixes for which the 'system header' property is
comment|/// overridden.
comment|///
comment|/// For a \#include "x" or \#include \<x> directive, the last string in this
comment|/// list which is a prefix of 'x' determines whether the file is treated as
comment|/// a system header.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|bool
operator|>
expr|>
name|SystemHeaderPrefixes
expr_stmt|;
comment|/// \brief The path to the module cache.
name|std
operator|::
name|string
name|ModuleCachePath
expr_stmt|;
comment|/// \brief All of the preprocessor-specific data about files that are
comment|/// included, indexed by the FileEntry's UID.
name|mutable
name|std
operator|::
name|vector
operator|<
name|HeaderFileInfo
operator|>
name|FileInfo
expr_stmt|;
comment|/// Keeps track of each lookup performed by LookupFile.
struct|struct
name|LookupFileCacheInfo
block|{
comment|/// Starting index in SearchDirs that the cached search was performed from.
comment|/// If there is a hit and this value doesn't match the current query, the
comment|/// cache has to be ignored.
name|unsigned
name|StartIdx
decl_stmt|;
comment|/// The entry in SearchDirs that satisfied the query.
name|unsigned
name|HitIdx
decl_stmt|;
comment|/// This is non-null if the original filename was mapped to a framework
comment|/// include via a headermap.
specifier|const
name|char
modifier|*
name|MappedName
decl_stmt|;
comment|/// Default constructor -- Initialize all members with zero.
name|LookupFileCacheInfo
argument_list|()
operator|:
name|StartIdx
argument_list|(
literal|0
argument_list|)
operator|,
name|HitIdx
argument_list|(
literal|0
argument_list|)
operator|,
name|MappedName
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|void
name|reset
argument_list|(
argument|unsigned StartIdx
argument_list|)
block|{
name|this
operator|->
name|StartIdx
operator|=
name|StartIdx
block|;
name|this
operator|->
name|MappedName
operator|=
name|nullptr
block|;     }
block|}
struct|;
name|llvm
operator|::
name|StringMap
operator|<
name|LookupFileCacheInfo
operator|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|LookupFileCache
expr_stmt|;
comment|/// \brief Collection mapping a framework or subframework
comment|/// name like "Carbon" to the Carbon.framework directory.
name|llvm
operator|::
name|StringMap
operator|<
name|FrameworkCacheEntry
operator|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|FrameworkMap
expr_stmt|;
comment|/// IncludeAliases - maps include file names (including the quotes or
comment|/// angle brackets) to other include file names.  This is used to support the
comment|/// include_alias pragma for Microsoft compatibility.
typedef|typedef
name|llvm
operator|::
name|StringMap
operator|<
name|std
operator|::
name|string
operator|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|IncludeAliasMap
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|IncludeAliasMap
operator|>
name|IncludeAliases
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
comment|/// \brief The mapping between modules and headers.
name|mutable
name|ModuleMap
name|ModMap
decl_stmt|;
comment|/// \brief Describes whether a given directory has a module map in it.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|DirectoryEntry
operator|*
operator|,
name|bool
operator|>
name|DirectoryHasModuleMap
expr_stmt|;
comment|/// \brief Set of module map files we've already loaded, and a flag indicating
comment|/// whether they were valid or not.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FileEntry
operator|*
operator|,
name|bool
operator|>
name|LoadedModuleMaps
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
comment|/// macros into IdentifierInfo pointers, and keep the identifire up to date,
comment|/// as needed.
name|ExternalPreprocessorSource
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
name|HeaderSearch
argument_list|(
specifier|const
name|HeaderSearch
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|HeaderSearch
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|friend
name|class
name|DirectoryLookup
decl_stmt|;
name|public
label|:
name|HeaderSearch
argument_list|(
name|std
operator|::
name|shared_ptr
operator|<
name|HeaderSearchOptions
operator|>
name|HSOpts
argument_list|,
name|SourceManager
operator|&
name|SourceMgr
argument_list|,
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|,
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|,
specifier|const
name|TargetInfo
operator|*
name|Target
argument_list|)
expr_stmt|;
operator|~
name|HeaderSearch
argument_list|()
expr_stmt|;
comment|/// \brief Retrieve the header-search options with which this header search
comment|/// was initialized.
name|HeaderSearchOptions
operator|&
name|getHeaderSearchOpts
argument_list|()
specifier|const
block|{
return|return
operator|*
name|HSOpts
return|;
block|}
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
comment|/// \brief Interface for setting the file search paths.
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
comment|/// \brief Add an additional search path.
name|void
name|AddSearchPath
parameter_list|(
specifier|const
name|DirectoryLookup
modifier|&
name|dir
parameter_list|,
name|bool
name|isAngled
parameter_list|)
block|{
name|unsigned
name|idx
init|=
name|isAngled
condition|?
name|SystemDirIdx
else|:
name|AngledDirIdx
decl_stmt|;
name|SearchDirs
operator|.
name|insert
argument_list|(
name|SearchDirs
operator|.
name|begin
argument_list|()
operator|+
name|idx
argument_list|,
name|dir
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isAngled
condition|)
name|AngledDirIdx
operator|++
expr_stmt|;
name|SystemDirIdx
operator|++
expr_stmt|;
block|}
comment|/// \brief Set the list of system header prefixes.
name|void
name|SetSystemHeaderPrefixes
argument_list|(
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
argument_list|,
name|bool
operator|>
expr|>
name|P
argument_list|)
block|{
name|SystemHeaderPrefixes
operator|.
name|assign
argument_list|(
name|P
operator|.
name|begin
argument_list|()
argument_list|,
name|P
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Checks whether the map exists or not.
name|bool
name|HasIncludeAliasMap
argument_list|()
specifier|const
block|{
return|return
operator|(
name|bool
operator|)
name|IncludeAliases
return|;
block|}
comment|/// \brief Map the source include name to the dest include name.
comment|///
comment|/// The Source should include the angle brackets or quotes, the dest
comment|/// should not.  This allows for distinction between<> and "" headers.
name|void
name|AddIncludeAlias
parameter_list|(
name|StringRef
name|Source
parameter_list|,
name|StringRef
name|Dest
parameter_list|)
block|{
if|if
condition|(
operator|!
name|IncludeAliases
condition|)
name|IncludeAliases
operator|.
name|reset
argument_list|(
argument|new IncludeAliasMap
argument_list|)
expr_stmt|;
operator|(
operator|*
name|IncludeAliases
operator|)
index|[
name|Source
index|]
operator|=
name|Dest
expr_stmt|;
block|}
comment|/// MapHeaderToIncludeAlias - Maps one header file name to a different header
comment|/// file name, for use with the include_alias pragma.  Note that the source
comment|/// file name should include the angle brackets or quotes.  Returns StringRef
comment|/// as null if the header cannot be mapped.
name|StringRef
name|MapHeaderToIncludeAlias
parameter_list|(
name|StringRef
name|Source
parameter_list|)
block|{
name|assert
argument_list|(
name|IncludeAliases
operator|&&
literal|"Trying to map headers when there's no map"
argument_list|)
expr_stmt|;
comment|// Do any filename replacements before anything else
name|IncludeAliasMap
operator|::
name|const_iterator
name|Iter
operator|=
name|IncludeAliases
operator|->
name|find
argument_list|(
name|Source
argument_list|)
expr_stmt|;
if|if
condition|(
name|Iter
operator|!=
name|IncludeAliases
operator|->
name|end
argument_list|()
condition|)
return|return
name|Iter
operator|->
name|second
return|;
return|return
name|StringRef
argument_list|()
return|;
block|}
comment|/// \brief Set the path to the module cache.
name|void
name|setModuleCachePath
parameter_list|(
name|StringRef
name|CachePath
parameter_list|)
block|{
name|ModuleCachePath
operator|=
name|CachePath
expr_stmt|;
block|}
comment|/// \brief Retrieve the path to the module cache.
name|StringRef
name|getModuleCachePath
argument_list|()
specifier|const
block|{
return|return
name|ModuleCachePath
return|;
block|}
comment|/// \brief Consider modules when including files from this directory.
name|void
name|setDirectoryHasModuleMap
parameter_list|(
specifier|const
name|DirectoryEntry
modifier|*
name|Dir
parameter_list|)
block|{
name|DirectoryHasModuleMap
index|[
name|Dir
index|]
operator|=
name|true
expr_stmt|;
block|}
comment|/// \brief Forget everything we know about headers so far.
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
name|ExternalPreprocessorSource
modifier|*
name|EPS
parameter_list|)
block|{
name|ExternalLookup
operator|=
name|EPS
expr_stmt|;
block|}
name|ExternalPreprocessorSource
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
comment|/// \brief Set the target information for the header search, if not
comment|/// already known.
name|void
name|setTarget
parameter_list|(
specifier|const
name|TargetInfo
modifier|&
name|Target
parameter_list|)
function_decl|;
comment|/// \brief Given a "foo" or \<foo> reference, look up the indicated file,
comment|/// return null on failure.
comment|///
comment|/// \returns If successful, this returns 'UsedDir', the DirectoryLookup member
comment|/// the file was found in, or null if not applicable.
comment|///
comment|/// \param IncludeLoc Used for diagnostics if valid.
comment|///
comment|/// \param isAngled indicates whether the file reference is a<> reference.
comment|///
comment|/// \param CurDir If non-null, the file was found in the specified directory
comment|/// search location.  This is used to implement \#include_next.
comment|///
comment|/// \param Includers Indicates where the \#including file(s) are, in case
comment|/// relative searches are needed. In reverse order of inclusion.
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
comment|/// part of a known module, this will be set to the module that should
comment|/// be imported instead of preprocessing/parsing the file found.
comment|///
comment|/// \param IsMapped If non-null, and the search involved header maps, set to
comment|/// true.
specifier|const
name|FileEntry
modifier|*
name|LookupFile
argument_list|(
name|StringRef
name|Filename
argument_list|,
name|SourceLocation
name|IncludeLoc
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
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|FileEntry
operator|*
argument_list|,
specifier|const
name|DirectoryEntry
operator|*
operator|>>
name|Includers
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
name|Module
operator|*
name|RequestingModule
argument_list|,
name|ModuleMap
operator|::
name|KnownHeader
operator|*
name|SuggestedModule
argument_list|,
name|bool
operator|*
name|IsMapped
argument_list|,
name|bool
name|SkipCache
operator|=
name|false
argument_list|,
name|bool
name|BuildSystemModule
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// \brief Look up a subframework for the specified \#include file.
comment|///
comment|/// For example, if \#include'ing<HIToolbox/HIToolbox.h> from
comment|/// within ".../Carbon.framework/Headers/Carbon.h", check to see if
comment|/// HIToolbox is a subframework within Carbon.framework.  If so, return
comment|/// the FileEntry for the designated file, otherwise return null.
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
argument_list|,
name|Module
operator|*
name|RequestingModule
argument_list|,
name|ModuleMap
operator|::
name|KnownHeader
operator|*
name|SuggestedModule
argument_list|)
decl_stmt|;
comment|/// \brief Look up the specified framework name in our framework cache.
comment|/// \returns The DirectoryEntry it is in if we know, null otherwise.
name|FrameworkCacheEntry
modifier|&
name|LookupFrameworkCache
parameter_list|(
name|StringRef
name|FWName
parameter_list|)
block|{
return|return
name|FrameworkMap
index|[
name|FWName
index|]
return|;
block|}
comment|/// \brief Mark the specified file as a target of of a \#include,
comment|/// \#include_next, or \#import directive.
comment|///
comment|/// \return false if \#including the file will have no effect or true
comment|/// if we should include it.
name|bool
name|ShouldEnterIncludeFile
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|,
name|bool
name|isImport
parameter_list|,
name|bool
name|ModulesEnabled
parameter_list|,
name|Module
modifier|*
name|CorrespondingModule
parameter_list|)
function_decl|;
comment|/// \brief Return whether the specified file is a normal header,
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
comment|/// \brief Mark the specified file as a "once only" file, e.g. due to
comment|/// \#pragma once.
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
comment|/// \brief Mark the specified file as a system header, e.g. due to
comment|/// \#pragma GCC system_header.
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
comment|/// \brief Mark the specified file as part of a module.
name|void
name|MarkFileModuleHeader
argument_list|(
specifier|const
name|FileEntry
operator|*
name|File
argument_list|,
name|ModuleMap
operator|::
name|ModuleHeaderRole
name|Role
argument_list|,
name|bool
name|IsCompiledModuleHeader
argument_list|)
decl_stmt|;
comment|/// \brief Increment the count for the number of times the specified
comment|/// FileEntry has been entered.
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
comment|/// \brief Mark the specified file as having a controlling macro.
comment|///
comment|/// This is used by the multiple-include optimization to eliminate
comment|/// no-op \#includes.
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
comment|/// \brief Return true if this is the first time encountering this header.
name|bool
name|FirstTimeLexingFile
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|)
block|{
return|return
name|getFileInfo
argument_list|(
name|File
argument_list|)
operator|.
name|NumIncludes
operator|==
literal|1
return|;
block|}
comment|/// \brief Determine whether this file is intended to be safe from
comment|/// multiple inclusions, e.g., it has \#pragma once or a controlling
comment|/// macro.
comment|///
comment|/// This routine does not consider the effect of \#import
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
comment|/// FileEntry, uniquing them through the 'HeaderMaps' datastructure.
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
comment|/// \brief Get filenames for all registered header maps.
name|void
name|getHeaderMapFileNames
argument_list|(
name|SmallVectorImpl
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|Names
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Retrieve the name of the module file that should be used to
comment|/// load the given module.
comment|///
comment|/// \param Module The module whose module file name will be returned.
comment|///
comment|/// \returns The name of the module file that corresponds to this module,
comment|/// or an empty string if this module does not correspond to any module file.
name|std
operator|::
name|string
name|getModuleFileName
argument_list|(
name|Module
operator|*
name|Module
argument_list|)
expr_stmt|;
comment|/// \brief Retrieve the name of the module file that should be used to
comment|/// load a module with the given name.
comment|///
comment|/// \param ModuleName The module whose module file name will be returned.
comment|///
comment|/// \param ModuleMapPath A path that when combined with \c ModuleName
comment|/// uniquely identifies this module. See Module::ModuleMap.
comment|///
comment|/// \param UsePrebuiltPath Whether we should use the prebuilt module path.
comment|///
comment|/// \returns The name of the module file that corresponds to this module,
comment|/// or an empty string if this module does not correspond to any module file.
name|std
operator|::
name|string
name|getModuleFileName
argument_list|(
argument|StringRef ModuleName
argument_list|,
argument|StringRef ModuleMapPath
argument_list|,
argument|bool UsePrebuiltPath
argument_list|)
expr_stmt|;
comment|/// \brief Lookup a module Search for a module with the given name.
comment|///
comment|/// \param ModuleName The name of the module we're looking for.
comment|///
comment|/// \param AllowSearch Whether we are allowed to search in the various
comment|/// search directories to produce a module definition. If not, this lookup
comment|/// will only return an already-known module.
comment|///
comment|/// \returns The module with the given name.
name|Module
modifier|*
name|lookupModule
parameter_list|(
name|StringRef
name|ModuleName
parameter_list|,
name|bool
name|AllowSearch
init|=
name|true
parameter_list|)
function_decl|;
comment|/// \brief Try to find a module map file in the given directory, returning
comment|/// \c nullptr if none is found.
specifier|const
name|FileEntry
modifier|*
name|lookupModuleMapFile
parameter_list|(
specifier|const
name|DirectoryEntry
modifier|*
name|Dir
parameter_list|,
name|bool
name|IsFramework
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
comment|/// \brief Determine whether there is a module map that may map the header
comment|/// with the given file name to a (sub)module.
comment|/// Always returns false if modules are disabled.
comment|///
comment|/// \param Filename The name of the file.
comment|///
comment|/// \param Root The "root" directory, at which we should stop looking for
comment|/// module maps.
comment|///
comment|/// \param IsSystem Whether the directories we're looking at are system
comment|/// header directories.
name|bool
name|hasModuleMap
parameter_list|(
name|StringRef
name|Filename
parameter_list|,
specifier|const
name|DirectoryEntry
modifier|*
name|Root
parameter_list|,
name|bool
name|IsSystem
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the module that corresponds to the given file, if any.
comment|///
comment|/// \param File The header that we wish to map to a module.
comment|/// \param AllowTextual Whether we want to find textual headers too.
name|ModuleMap
operator|::
name|KnownHeader
name|findModuleForHeader
argument_list|(
argument|const FileEntry *File
argument_list|,
argument|bool AllowTextual = false
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Read the contents of the given module map file.
comment|///
comment|/// \param File The module map file.
comment|/// \param IsSystem Whether this file is in a system header directory.
comment|///
comment|/// \returns true if an error occurred, false otherwise.
name|bool
name|loadModuleMapFile
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|,
name|bool
name|IsSystem
parameter_list|)
function_decl|;
comment|/// \brief Collect the set of all known, top-level modules.
comment|///
comment|/// \param Modules Will be filled with the set of known, top-level modules.
name|void
name|collectAllModules
argument_list|(
name|SmallVectorImpl
operator|<
name|Module
operator|*
operator|>
operator|&
name|Modules
argument_list|)
decl_stmt|;
comment|/// \brief Load all known, top-level system modules.
name|void
name|loadTopLevelSystemModules
parameter_list|()
function_decl|;
name|private
label|:
comment|/// \brief Lookup a module with the given module name and search-name.
comment|///
comment|/// \param ModuleName The name of the module we're looking for.
comment|///
comment|/// \param SearchName The "search-name" to derive filesystem paths from
comment|/// when looking for the module map; this is usually equal to ModuleName,
comment|/// but for compatibility with some buggy frameworks, additional attempts
comment|/// may be made to find the module under a related-but-different search-name.
comment|///
comment|/// \returns The module named ModuleName.
name|Module
modifier|*
name|lookupModule
parameter_list|(
name|StringRef
name|ModuleName
parameter_list|,
name|StringRef
name|SearchName
parameter_list|)
function_decl|;
comment|/// \brief Retrieve a module with the given name, which may be part of the
comment|/// given framework.
comment|///
comment|/// \param Name The name of the module to retrieve.
comment|///
comment|/// \param Dir The framework directory (e.g., ModuleName.framework).
comment|///
comment|/// \param IsSystem Whether the framework directory is part of the system
comment|/// frameworks.
comment|///
comment|/// \returns The module, if found; otherwise, null.
name|Module
modifier|*
name|loadFrameworkModule
parameter_list|(
name|StringRef
name|Name
parameter_list|,
specifier|const
name|DirectoryEntry
modifier|*
name|Dir
parameter_list|,
name|bool
name|IsSystem
parameter_list|)
function_decl|;
comment|/// \brief Load all of the module maps within the immediate subdirectories
comment|/// of the given search directory.
name|void
name|loadSubdirectoryModuleMaps
parameter_list|(
name|DirectoryLookup
modifier|&
name|SearchDir
parameter_list|)
function_decl|;
comment|/// \brief Find and suggest a usable module for the given file.
comment|///
comment|/// \return \c true if the file can be used, \c false if we are not permitted to
comment|///         find this file due to requirements from \p RequestingModule.
name|bool
name|findUsableModuleForHeader
argument_list|(
specifier|const
name|FileEntry
operator|*
name|File
argument_list|,
specifier|const
name|DirectoryEntry
operator|*
name|Root
argument_list|,
name|Module
operator|*
name|RequestingModule
argument_list|,
name|ModuleMap
operator|::
name|KnownHeader
operator|*
name|SuggestedModule
argument_list|,
name|bool
name|IsSystemHeaderDir
argument_list|)
decl_stmt|;
comment|/// \brief Find and suggest a usable module for the given file, which is part of
comment|/// the specified framework.
comment|///
comment|/// \return \c true if the file can be used, \c false if we are not permitted to
comment|///         find this file due to requirements from \p RequestingModule.
name|bool
name|findUsableModuleForFrameworkHeader
argument_list|(
specifier|const
name|FileEntry
operator|*
name|File
argument_list|,
name|StringRef
name|FrameworkDir
argument_list|,
name|Module
operator|*
name|RequestingModule
argument_list|,
name|ModuleMap
operator|::
name|KnownHeader
operator|*
name|SuggestedModule
argument_list|,
name|bool
name|IsSystemFramework
argument_list|)
decl_stmt|;
comment|/// \brief Look up the file with the specified name and determine its owning
comment|/// module.
specifier|const
name|FileEntry
modifier|*
name|getFileAndSuggestModule
argument_list|(
name|StringRef
name|FileName
argument_list|,
name|SourceLocation
name|IncludeLoc
argument_list|,
specifier|const
name|DirectoryEntry
operator|*
name|Dir
argument_list|,
name|bool
name|IsSystemHeaderDir
argument_list|,
name|Module
operator|*
name|RequestingModule
argument_list|,
name|ModuleMap
operator|::
name|KnownHeader
operator|*
name|SuggestedModule
argument_list|)
decl_stmt|;
name|public
label|:
comment|/// \brief Retrieve the module map.
name|ModuleMap
modifier|&
name|getModuleMap
parameter_list|()
block|{
return|return
name|ModMap
return|;
block|}
comment|/// \brief Retrieve the module map.
specifier|const
name|ModuleMap
operator|&
name|getModuleMap
argument_list|()
specifier|const
block|{
return|return
name|ModMap
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
comment|/// \brief Return the HeaderFileInfo structure for the specified FileEntry,
comment|/// in preparation for updating it in some way.
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
comment|/// \brief Return the HeaderFileInfo structure for the specified FileEntry,
comment|/// if it has ever been filled in.
comment|/// \param WantExternal Whether the caller wants purely-external header file
comment|///        info (where \p External is true).
specifier|const
name|HeaderFileInfo
modifier|*
name|getExistingFileInfo
argument_list|(
specifier|const
name|FileEntry
operator|*
name|FE
argument_list|,
name|bool
name|WantExternal
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
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
comment|/// \brief Suggest a path by which the specified file could be found, for
comment|/// use in diagnostics to suggest a #include.
comment|///
comment|/// \param IsSystem If non-null, filled in to indicate whether the suggested
comment|///        path is relative to a system header directory.
name|std
operator|::
name|string
name|suggestPathToFileForDiagnostics
argument_list|(
specifier|const
name|FileEntry
operator|*
name|File
argument_list|,
name|bool
operator|*
name|IsSystem
operator|=
name|nullptr
argument_list|)
expr_stmt|;
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
comment|/// \brief Describes what happened when we tried to load a module map file.
enum|enum
name|LoadModuleMapResult
block|{
comment|/// \brief The module map file had already been loaded.
name|LMM_AlreadyLoaded
block|,
comment|/// \brief The module map file was loaded by this invocation.
name|LMM_NewlyLoaded
block|,
comment|/// \brief There is was directory with the given name.
name|LMM_NoDirectory
block|,
comment|/// \brief There was either no module map file or the module map file was
comment|/// invalid.
name|LMM_InvalidModuleMap
block|}
enum|;
name|LoadModuleMapResult
name|loadModuleMapFileImpl
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|,
name|bool
name|IsSystem
parameter_list|,
specifier|const
name|DirectoryEntry
modifier|*
name|Dir
parameter_list|)
function_decl|;
comment|/// \brief Try to load the module map file in the given directory.
comment|///
comment|/// \param DirName The name of the directory where we will look for a module
comment|/// map file.
comment|/// \param IsSystem Whether this is a system header directory.
comment|/// \param IsFramework Whether this is a framework directory.
comment|///
comment|/// \returns The result of attempting to load the module map file from the
comment|/// named directory.
name|LoadModuleMapResult
name|loadModuleMapFile
parameter_list|(
name|StringRef
name|DirName
parameter_list|,
name|bool
name|IsSystem
parameter_list|,
name|bool
name|IsFramework
parameter_list|)
function_decl|;
comment|/// \brief Try to load the module map file in the given directory.
comment|///
comment|/// \param Dir The directory where we will look for a module map file.
comment|/// \param IsSystem Whether this is a system header directory.
comment|/// \param IsFramework Whether this is a framework directory.
comment|///
comment|/// \returns The result of attempting to load the module map file from the
comment|/// named directory.
name|LoadModuleMapResult
name|loadModuleMapFile
parameter_list|(
specifier|const
name|DirectoryEntry
modifier|*
name|Dir
parameter_list|,
name|bool
name|IsSystem
parameter_list|,
name|bool
name|IsFramework
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

