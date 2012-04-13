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
name|LLVM_CLANG_FRONTEND_HEADERSEARCHOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_HEADERSEARCHOPTIONS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
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
comment|/// represents its relative positive in the search list.  A #include of a ""
comment|/// path starts at the -iquote group, then searches the Angled group, then
comment|/// searches the system group, etc.
enum|enum
name|IncludeDirGroup
block|{
name|Quoted
init|=
literal|0
block|,
comment|///< '#include ""' paths, added by'gcc -iquote'.
name|Angled
block|,
comment|///< Paths for '#include<>' added by '-I'.
name|IndexHeaderMap
block|,
comment|///< Like Angled, but marks header maps used when
comment|///  building frameworks.
name|System
block|,
comment|///< Like Angled, but marks system directories.
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
name|IsUserSupplied
range|:
literal|1
decl_stmt|;
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
comment|/// \brief True if this entry is an internal search path.
comment|///
comment|/// This typically indicates that users didn't directly provide it, but
comment|/// instead it was provided by a compatibility layer for a particular
comment|/// system. This isn't redundant with IsUserSupplied (even though perhaps
comment|/// it should be) because that is false for user provided '-iwithprefix'
comment|/// header search entries.
name|unsigned
name|IsInternal
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this entry's headers should be wrapped in extern "C".
name|unsigned
name|ImplicitExternC
range|:
literal|1
decl_stmt|;
name|Entry
argument_list|(
argument|StringRef path
argument_list|,
argument|frontend::IncludeDirGroup group
argument_list|,
argument|bool isUserSupplied
argument_list|,
argument|bool isFramework
argument_list|,
argument|bool ignoreSysRoot
argument_list|,
argument|bool isInternal
argument_list|,
argument|bool implicitExternC
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
name|IsUserSupplied
argument_list|(
name|isUserSupplied
argument_list|)
operator|,
name|IsFramework
argument_list|(
name|isFramework
argument_list|)
operator|,
name|IgnoreSysRoot
argument_list|(
name|ignoreSysRoot
argument_list|)
operator|,
name|IsInternal
argument_list|(
name|isInternal
argument_list|)
operator|,
name|ImplicitExternC
argument_list|(
argument|implicitExternC
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
comment|/// \brief Whether we should disable the use of the hash string within the
comment|/// module cache.
comment|///
comment|/// Note: Only used for testing!
name|unsigned
name|DisableModuleHash
range|:
literal|1
decl_stmt|;
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
name|public
label|:
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
name|DisableModuleHash
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
argument|false
argument_list|)
block|{}
comment|/// AddPath - Add the \arg Path path to the specified \arg Group list.
name|void
name|AddPath
argument_list|(
argument|StringRef Path
argument_list|,
argument|frontend::IncludeDirGroup Group
argument_list|,
argument|bool IsUserSupplied
argument_list|,
argument|bool IsFramework
argument_list|,
argument|bool IgnoreSysRoot
argument_list|,
argument|bool IsInternal = false
argument_list|,
argument|bool ImplicitExternC = false
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
name|IsUserSupplied
argument_list|,
name|IsFramework
argument_list|,
name|IgnoreSysRoot
argument_list|,
name|IsInternal
argument_list|,
name|ImplicitExternC
argument_list|)
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

