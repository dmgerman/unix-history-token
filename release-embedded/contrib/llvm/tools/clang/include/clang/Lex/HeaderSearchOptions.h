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
comment|/// IncludeDirGroup - Identifiers the group a include entry belongs to, which
comment|/// represents its relative positive in the search list.  A \#include of a ""
comment|/// path starts at the -iquote group, then searches the Angled group, then
comment|/// searches the system group, etc.
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
range|:
name|public
name|RefCountedBase
operator|<
name|HeaderSearchOptions
operator|>
block|{
name|public
operator|:
expr|struct
name|Entry
block|{
name|std
operator|::
name|string
name|Path
block|;
name|frontend
operator|::
name|IncludeDirGroup
name|Group
block|;
name|unsigned
name|IsFramework
operator|:
literal|1
block|;
comment|/// IgnoreSysRoot - This is false if an absolute path should be treated
comment|/// relative to the sysroot, or true if it should always be the absolute
comment|/// path.
name|unsigned
name|IgnoreSysRoot
operator|:
literal|1
block|;
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
operator|:
name|Path
argument_list|(
name|path
argument_list|)
block|,
name|Group
argument_list|(
name|group
argument_list|)
block|,
name|IsFramework
argument_list|(
name|isFramework
argument_list|)
block|,
name|IgnoreSysRoot
argument_list|(
argument|ignoreSysRoot
argument_list|)
block|{}
block|}
block|;    struct
name|SystemHeaderPrefix
block|{
comment|/// A prefix to be matched against paths in \#include directives.
name|std
operator|::
name|string
name|Prefix
block|;
comment|/// True if paths beginning with this prefix should be treated as system
comment|/// headers.
name|bool
name|IsSystemHeader
block|;
name|SystemHeaderPrefix
argument_list|(
argument|StringRef Prefix
argument_list|,
argument|bool IsSystemHeader
argument_list|)
operator|:
name|Prefix
argument_list|(
name|Prefix
argument_list|)
block|,
name|IsSystemHeader
argument_list|(
argument|IsSystemHeader
argument_list|)
block|{}
block|}
block|;
comment|/// If non-empty, the directory to use as a "virtual system root" for include
comment|/// paths.
name|std
operator|::
name|string
name|Sysroot
block|;
comment|/// User specified include entries.
name|std
operator|::
name|vector
operator|<
name|Entry
operator|>
name|UserEntries
block|;
comment|/// User-specified system header prefixes.
name|std
operator|::
name|vector
operator|<
name|SystemHeaderPrefix
operator|>
name|SystemHeaderPrefixes
block|;
comment|/// The directory which holds the compiler resource files (builtin includes,
comment|/// etc.).
name|std
operator|::
name|string
name|ResourceDir
block|;
comment|/// \brief The directory used for the module cache.
name|std
operator|::
name|string
name|ModuleCachePath
block|;
comment|/// \brief Whether we should disable the use of the hash string within the
comment|/// module cache.
comment|///
comment|/// Note: Only used for testing!
name|unsigned
name|DisableModuleHash
operator|:
literal|1
block|;
comment|/// \brief Interpret module maps.  This option is implied by full modules.
name|unsigned
name|ModuleMaps
operator|:
literal|1
block|;
comment|/// \brief The interval (in seconds) between pruning operations.
comment|///
comment|/// This operation is expensive, because it requires Clang to walk through
comment|/// the directory structure of the module cache, stat()'ing and removing
comment|/// files.
comment|///
comment|/// The default value is large, e.g., the operation runs once a week.
name|unsigned
name|ModuleCachePruneInterval
block|;
comment|/// \brief The time (in seconds) after which an unused module file will be
comment|/// considered unused and will, therefore, be pruned.
comment|///
comment|/// When the module cache is pruned, any module file that has not been
comment|/// accessed in this many seconds will be removed. The default value is
comment|/// large, e.g., a month, to avoid forcing infrequently-used modules to be
comment|/// regenerated often.
name|unsigned
name|ModuleCachePruneAfter
block|;
comment|/// \brief The set of macro names that should be ignored for the purposes
comment|/// of computing the module hash.
name|llvm
operator|::
name|SetVector
operator|<
name|std
operator|::
name|string
operator|>
name|ModulesIgnoreMacros
block|;
comment|/// \brief The set of user-provided module-map-files.
name|llvm
operator|::
name|SetVector
operator|<
name|std
operator|::
name|string
operator|>
name|ModuleMapFiles
block|;
comment|/// Include the compiler builtin includes.
name|unsigned
name|UseBuiltinIncludes
operator|:
literal|1
block|;
comment|/// Include the system standard include search directories.
name|unsigned
name|UseStandardSystemIncludes
operator|:
literal|1
block|;
comment|/// Include the system standard C++ library include search directories.
name|unsigned
name|UseStandardCXXIncludes
operator|:
literal|1
block|;
comment|/// Use libc++ instead of the default libstdc++.
name|unsigned
name|UseLibcxx
operator|:
literal|1
block|;
comment|/// Whether header search information should be output as for -v.
name|unsigned
name|Verbose
operator|:
literal|1
block|;
name|public
operator|:
name|HeaderSearchOptions
argument_list|(
argument|StringRef _Sysroot =
literal|"/"
argument_list|)
operator|:
name|Sysroot
argument_list|(
name|_Sysroot
argument_list|)
block|,
name|DisableModuleHash
argument_list|(
literal|0
argument_list|)
block|,
name|ModuleMaps
argument_list|(
literal|0
argument_list|)
block|,
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
block|,
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
block|,
name|UseBuiltinIncludes
argument_list|(
name|true
argument_list|)
block|,
name|UseStandardSystemIncludes
argument_list|(
name|true
argument_list|)
block|,
name|UseStandardCXXIncludes
argument_list|(
name|true
argument_list|)
block|,
name|UseLibcxx
argument_list|(
name|false
argument_list|)
block|,
name|Verbose
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
name|push_back
argument_list|(
name|Entry
argument_list|(
name|Path
argument_list|,
name|Group
argument_list|,
name|IsFramework
argument_list|,
name|IgnoreSysRoot
argument_list|)
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
name|push_back
argument_list|(
name|SystemHeaderPrefix
argument_list|(
name|Prefix
argument_list|,
name|IsSystemHeader
argument_list|)
argument_list|)
block|;   }
block|}
decl_stmt|;
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

