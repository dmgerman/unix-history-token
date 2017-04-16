begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- HeaderSearchOptions.h ----------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_LEX_HEADERSEARCHOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_HEADERSEARCHOPTIONS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/CachedHashString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<string>
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
name|namespace
name|frontend
block|{
comment|/// IncludeDirGroup - Identifies the group an include Entry belongs to,
comment|/// representing its relative positive in the search list.
comment|/// \#include directives whose paths are enclosed by string quotes ("")
comment|/// start searching at the Quoted group (specified by '-iquote'),
comment|/// then search the Angled group, then the System group, etc.
enum|enum
name|IncludeDirGroup
block|{
name|Quoted
init|=
literal|0
block|,
comment|///< '\#include ""' paths, added by 'gcc -iquote'.
name|Angled
block|,
comment|///< Paths for '\#include<>' added by '-I'.
name|IndexHeaderMap
block|,
comment|///< Like Angled, but marks header maps used when
comment|///  building frameworks.
name|System
block|,
comment|///< Like Angled, but marks system directories.
name|ExternCSystem
block|,
comment|///< Like System, but headers are implicitly wrapped in
comment|///  extern "C".
name|CSystem
block|,
comment|///< Like System, but only used for C.
name|CXXSystem
block|,
comment|///< Like System, but only used for C++.
name|ObjCSystem
block|,
comment|///< Like System, but only used for ObjC.
name|ObjCXXSystem
block|,
comment|///< Like System, but only used for ObjC++.
name|After
comment|///< Like System, but searched after the system directories.
block|}
enum|;
block|}
comment|/// HeaderSearchOptions - Helper class for storing options related to the
comment|/// initialization of the HeaderSearch object.
name|class
name|HeaderSearchOptions
block|{
name|public
label|:
struct|struct
name|Entry
block|{
name|std
operator|::
name|string
name|Path
expr_stmt|;
name|frontend
operator|::
name|IncludeDirGroup
name|Group
expr_stmt|;
name|unsigned
name|IsFramework
range|:
literal|1
decl_stmt|;
comment|/// IgnoreSysRoot - This is false if an absolute path should be treated
comment|/// relative to the sysroot, or true if it should always be the absolute
comment|/// path.
name|unsigned
name|IgnoreSysRoot
range|:
literal|1
decl_stmt|;
name|Entry
argument_list|(
argument|StringRef path
argument_list|,
argument|frontend::IncludeDirGroup group
argument_list|,
argument|bool isFramework
argument_list|,
argument|bool ignoreSysRoot
argument_list|)
block|:
name|Path
argument_list|(
name|path
argument_list|)
operator|,
name|Group
argument_list|(
name|group
argument_list|)
operator|,
name|IsFramework
argument_list|(
name|isFramework
argument_list|)
operator|,
name|IgnoreSysRoot
argument_list|(
argument|ignoreSysRoot
argument_list|)
block|{}
block|}
struct|;
struct|struct
name|SystemHeaderPrefix
block|{
comment|/// A prefix to be matched against paths in \#include directives.
name|std
operator|::
name|string
name|Prefix
expr_stmt|;
comment|/// True if paths beginning with this prefix should be treated as system
comment|/// headers.
name|bool
name|IsSystemHeader
decl_stmt|;
name|SystemHeaderPrefix
argument_list|(
argument|StringRef Prefix
argument_list|,
argument|bool IsSystemHeader
argument_list|)
block|:
name|Prefix
argument_list|(
name|Prefix
argument_list|)
operator|,
name|IsSystemHeader
argument_list|(
argument|IsSystemHeader
argument_list|)
block|{}
block|}
struct|;
comment|/// If non-empty, the directory to use as a "virtual system root" for include
comment|/// paths.
name|std
operator|::
name|string
name|Sysroot
expr_stmt|;
comment|/// User specified include entries.
name|std
operator|::
name|vector
operator|<
name|Entry
operator|>
name|UserEntries
expr_stmt|;
comment|/// User-specified system header prefixes.
name|std
operator|::
name|vector
operator|<
name|SystemHeaderPrefix
operator|>
name|SystemHeaderPrefixes
expr_stmt|;
comment|/// The directory which holds the compiler resource files (builtin includes,
comment|/// etc.).
name|std
operator|::
name|string
name|ResourceDir
expr_stmt|;
comment|/// \brief The directory used for the module cache.
name|std
operator|::
name|string
name|ModuleCachePath
expr_stmt|;
comment|/// \brief The directory used for a user build.
name|std
operator|::
name|string
name|ModuleUserBuildPath
expr_stmt|;
comment|/// \brief The directories used to load prebuilt module files.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|PrebuiltModulePaths
expr_stmt|;
comment|/// The module/pch container format.
name|std
operator|::
name|string
name|ModuleFormat
expr_stmt|;
comment|/// \brief Whether we should disable the use of the hash string within the
comment|/// module cache.
comment|///
comment|/// Note: Only used for testing!
name|unsigned
name|DisableModuleHash
range|:
literal|1
decl_stmt|;
comment|/// \brief Implicit module maps.  This option is enabld by default when
comment|/// modules is enabled.
name|unsigned
name|ImplicitModuleMaps
range|:
literal|1
decl_stmt|;
comment|/// \brief Set the 'home directory' of a module map file to the current
comment|/// working directory (or the home directory of the module map file that
comment|/// contained the 'extern module' directive importing this module map file
comment|/// if any) rather than the directory containing the module map file.
comment|//
comment|/// The home directory is where we look for files named in the module map
comment|/// file.
name|unsigned
name|ModuleMapFileHomeIsCwd
range|:
literal|1
decl_stmt|;
comment|/// \brief The interval (in seconds) between pruning operations.
comment|///
comment|/// This operation is expensive, because it requires Clang to walk through
comment|/// the directory structure of the module cache, stat()'ing and removing
comment|/// files.
comment|///
comment|/// The default value is large, e.g., the operation runs once a week.
name|unsigned
name|ModuleCachePruneInterval
decl_stmt|;
comment|/// \brief The time (in seconds) after which an unused module file will be
comment|/// considered unused and will, therefore, be pruned.
comment|///
comment|/// When the module cache is pruned, any module file that has not been
comment|/// accessed in this many seconds will be removed. The default value is
comment|/// large, e.g., a month, to avoid forcing infrequently-used modules to be
comment|/// regenerated often.
name|unsigned
name|ModuleCachePruneAfter
decl_stmt|;
comment|/// \brief The time in seconds when the build session started.
comment|///
comment|/// This time is used by other optimizations in header search and module
comment|/// loading.
name|uint64_t
name|BuildSessionTimestamp
decl_stmt|;
comment|/// \brief The set of macro names that should be ignored for the purposes
comment|/// of computing the module hash.
name|llvm
operator|::
name|SmallSetVector
operator|<
name|llvm
operator|::
name|CachedHashString
operator|,
literal|16
operator|>
name|ModulesIgnoreMacros
expr_stmt|;
comment|/// \brief The set of user-provided virtual filesystem overlay files.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|VFSOverlayFiles
expr_stmt|;
comment|/// Include the compiler builtin includes.
name|unsigned
name|UseBuiltinIncludes
range|:
literal|1
decl_stmt|;
comment|/// Include the system standard include search directories.
name|unsigned
name|UseStandardSystemIncludes
range|:
literal|1
decl_stmt|;
comment|/// Include the system standard C++ library include search directories.
name|unsigned
name|UseStandardCXXIncludes
range|:
literal|1
decl_stmt|;
comment|/// Use libc++ instead of the default libstdc++.
name|unsigned
name|UseLibcxx
range|:
literal|1
decl_stmt|;
comment|/// Whether header search information should be output as for -v.
name|unsigned
name|Verbose
range|:
literal|1
decl_stmt|;
comment|/// \brief If true, skip verifying input files used by modules if the
comment|/// module was already verified during this build session (see
comment|/// \c BuildSessionTimestamp).
name|unsigned
name|ModulesValidateOncePerBuildSession
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether to validate system input files when a module is loaded.
name|unsigned
name|ModulesValidateSystemHeaders
range|:
literal|1
decl_stmt|;
comment|/// Whether the module includes debug information (-gmodules).
name|unsigned
name|UseDebugInfo
range|:
literal|1
decl_stmt|;
name|unsigned
name|ModulesValidateDiagnosticOptions
range|:
literal|1
decl_stmt|;
name|unsigned
name|ModulesHashContent
range|:
literal|1
decl_stmt|;
name|HeaderSearchOptions
argument_list|(
argument|StringRef _Sysroot =
literal|"/"
argument_list|)
block|:
name|Sysroot
argument_list|(
name|_Sysroot
argument_list|)
operator|,
name|ModuleFormat
argument_list|(
literal|"raw"
argument_list|)
operator|,
name|DisableModuleHash
argument_list|(
literal|0
argument_list|)
operator|,
name|ImplicitModuleMaps
argument_list|(
literal|0
argument_list|)
operator|,
name|ModuleMapFileHomeIsCwd
argument_list|(
literal|0
argument_list|)
operator|,
name|ModuleCachePruneInterval
argument_list|(
literal|7
operator|*
literal|24
operator|*
literal|60
operator|*
literal|60
argument_list|)
operator|,
name|ModuleCachePruneAfter
argument_list|(
literal|31
operator|*
literal|24
operator|*
literal|60
operator|*
literal|60
argument_list|)
operator|,
name|BuildSessionTimestamp
argument_list|(
literal|0
argument_list|)
operator|,
name|UseBuiltinIncludes
argument_list|(
name|true
argument_list|)
operator|,
name|UseStandardSystemIncludes
argument_list|(
name|true
argument_list|)
operator|,
name|UseStandardCXXIncludes
argument_list|(
name|true
argument_list|)
operator|,
name|UseLibcxx
argument_list|(
name|false
argument_list|)
operator|,
name|Verbose
argument_list|(
name|false
argument_list|)
operator|,
name|ModulesValidateOncePerBuildSession
argument_list|(
name|false
argument_list|)
operator|,
name|ModulesValidateSystemHeaders
argument_list|(
name|false
argument_list|)
operator|,
name|UseDebugInfo
argument_list|(
name|false
argument_list|)
operator|,
name|ModulesValidateDiagnosticOptions
argument_list|(
name|true
argument_list|)
operator|,
name|ModulesHashContent
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// AddPath - Add the \p Path path to the specified \p Group list.
name|void
name|AddPath
argument_list|(
argument|StringRef Path
argument_list|,
argument|frontend::IncludeDirGroup Group
argument_list|,
argument|bool IsFramework
argument_list|,
argument|bool IgnoreSysRoot
argument_list|)
block|{
name|UserEntries
operator|.
name|emplace_back
argument_list|(
name|Path
argument_list|,
name|Group
argument_list|,
name|IsFramework
argument_list|,
name|IgnoreSysRoot
argument_list|)
block|;   }
comment|/// AddSystemHeaderPrefix - Override whether \#include directives naming a
comment|/// path starting with \p Prefix should be considered as naming a system
comment|/// header.
name|void
name|AddSystemHeaderPrefix
argument_list|(
argument|StringRef Prefix
argument_list|,
argument|bool IsSystemHeader
argument_list|)
block|{
name|SystemHeaderPrefixes
operator|.
name|emplace_back
argument_list|(
name|Prefix
argument_list|,
name|IsSystemHeader
argument_list|)
block|;   }
name|void
name|AddVFSOverlayFile
argument_list|(
argument|StringRef Name
argument_list|)
block|{
name|VFSOverlayFiles
operator|.
name|push_back
argument_list|(
name|Name
argument_list|)
block|;   }
name|void
name|AddPrebuiltModulePath
argument_list|(
argument|StringRef Name
argument_list|)
block|{
name|PrebuiltModulePaths
operator|.
name|push_back
argument_list|(
name|Name
argument_list|)
block|;   }
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

