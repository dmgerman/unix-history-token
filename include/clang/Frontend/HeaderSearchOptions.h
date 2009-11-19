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
comment|/// represents its relative positive in the search list.
enum|enum
name|IncludeDirGroup
block|{
name|Quoted
init|=
literal|0
block|,
comment|///< `#include ""` paths. Thing `gcc -iquote`.
name|Angled
block|,
comment|///< Paths for both `#include ""` and `#include<>`. (`-I`)
name|System
block|,
comment|///< Like Angled, but marks system directories.
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
name|Entry
argument_list|(
argument|llvm::StringRef _Path
argument_list|,
argument|frontend::IncludeDirGroup _Group
argument_list|,
argument|bool _IsUserSupplied
argument_list|,
argument|bool _IsFramework
argument_list|)
block|:
name|Path
argument_list|(
name|_Path
argument_list|)
operator|,
name|Group
argument_list|(
name|_Group
argument_list|)
operator|,
name|IsUserSupplied
argument_list|(
name|_IsUserSupplied
argument_list|)
operator|,
name|IsFramework
argument_list|(
argument|_IsFramework
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
comment|/// A (system-path) delimited list of include paths to be added from the
comment|/// environment following the user specified includes (but prior to builtin
comment|/// and standard includes). This is parsed in the same manner as the CPATH
comment|/// environment variable for gcc.
name|std
operator|::
name|string
name|EnvIncPath
expr_stmt|;
comment|/// Per-language environmental include paths, see \see EnvIncPath.
name|std
operator|::
name|string
name|CEnvIncPath
expr_stmt|;
name|std
operator|::
name|string
name|ObjCEnvIncPath
expr_stmt|;
name|std
operator|::
name|string
name|CXXEnvIncPath
expr_stmt|;
name|std
operator|::
name|string
name|ObjCXXEnvIncPath
expr_stmt|;
comment|/// If non-empty, the path to the compiler builtin include directory, which
comment|/// will be searched following the user and environment includes.
name|std
operator|::
name|string
name|BuiltinIncludePath
expr_stmt|;
comment|/// Include the system standard include search directories.
name|unsigned
name|UseStandardIncludes
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
argument|llvm::StringRef _Sysroot =
literal|"/"
argument_list|)
block|:
name|Sysroot
argument_list|(
name|_Sysroot
argument_list|)
operator|,
name|UseStandardIncludes
argument_list|(
name|true
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
argument|llvm::StringRef Path
argument_list|,
argument|frontend::IncludeDirGroup Group
argument_list|,
argument|bool IsUserSupplied
argument_list|,
argument|bool IsFramework
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

