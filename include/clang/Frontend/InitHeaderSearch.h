begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- InitHeaderSearch.h - Initialize header search paths ----*- C++ -*-===//
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
comment|// This file defines the InitHeaderSearch class.
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
name|LLVM_CLANG_FRONTEND_INIT_HEADER_SEARCH_H_
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_INIT_HEADER_SEARCH_H_
end_define

begin_include
include|#
directive|include
file|"clang/Lex/DirectoryLookup.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
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
name|class
name|HeaderSearch
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
comment|/// InitHeaderSearch - This class makes it easier to set the search paths of
comment|///  a HeaderSearch object. InitHeaderSearch stores several search path lists
comment|///  internally, which can be sent to a HeaderSearch object in one swoop.
name|class
name|InitHeaderSearch
block|{
name|std
operator|::
name|vector
operator|<
name|DirectoryLookup
operator|>
name|IncludeGroup
index|[
literal|4
index|]
expr_stmt|;
name|HeaderSearch
modifier|&
name|Headers
decl_stmt|;
name|bool
name|Verbose
decl_stmt|;
name|std
operator|::
name|string
name|isysroot
expr_stmt|;
name|public
label|:
comment|/// InitHeaderSearch::IncludeDirGroup - Identifies the several search path
comment|///  lists stored internally.
enum|enum
name|IncludeDirGroup
block|{
name|Quoted
init|=
literal|0
block|,
comment|//< `#include ""` paths. Thing `gcc -iquote`.
name|Angled
block|,
comment|//< Paths for both `#include ""` and `#include<>`. (`-I`)
name|System
block|,
comment|//< Like Angled, but marks system directories.
name|After
comment|//< Like System, but searched after the system directories.
block|}
enum|;
name|InitHeaderSearch
argument_list|(
argument|HeaderSearch&HS
argument_list|,
argument|bool verbose = false
argument_list|,
argument|const std::string&iSysroot =
literal|""
argument_list|)
block|:
name|Headers
argument_list|(
name|HS
argument_list|)
operator|,
name|Verbose
argument_list|(
name|verbose
argument_list|)
operator|,
name|isysroot
argument_list|(
argument|iSysroot
argument_list|)
block|{}
comment|/// AddPath - Add the specified path to the specified group list.
name|void
name|AddPath
argument_list|(
argument|const llvm::StringRef&Path
argument_list|,
argument|IncludeDirGroup Group
argument_list|,
argument|bool isCXXAware
argument_list|,
argument|bool isUserSupplied
argument_list|,
argument|bool isFramework
argument_list|,
argument|bool IgnoreSysRoot = false
argument_list|)
expr_stmt|;
comment|/// AddEnvVarPaths - Add a list of paths from an environment variable to a
comment|///  header search list.
name|void
name|AddEnvVarPaths
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
comment|/// AddGnuCPlusPlusIncludePaths - Add the necessary paths to suport a gnu
comment|///  libstdc++.
name|void
name|AddGnuCPlusPlusIncludePaths
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Base
argument_list|,
specifier|const
name|char
operator|*
name|Dir32
argument_list|,
specifier|const
name|char
operator|*
name|Dir64
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|triple
argument_list|)
decl_stmt|;
comment|/// AddMinGWCPlusPlusIncludePaths - Add the necessary paths to suport a MinGW
comment|///  libstdc++.
name|void
name|AddMinGWCPlusPlusIncludePaths
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Base
argument_list|,
specifier|const
name|char
operator|*
name|Arch
argument_list|,
specifier|const
name|char
operator|*
name|Version
argument_list|)
decl_stmt|;
comment|/// AddDefaultEnvVarPaths - Adds list of paths from default environment
comment|///  variables such as CPATH.
name|void
name|AddDefaultEnvVarPaths
parameter_list|(
specifier|const
name|LangOptions
modifier|&
name|Lang
parameter_list|)
function_decl|;
comment|// AddDefaultCIncludePaths - Add paths that should always be searched.
name|void
name|AddDefaultCIncludePaths
argument_list|(
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|triple
argument_list|)
decl_stmt|;
comment|// AddDefaultCPlusPlusIncludePaths -  Add paths that should be searched when
comment|//  compiling c++.
name|void
name|AddDefaultCPlusPlusIncludePaths
argument_list|(
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|triple
argument_list|)
decl_stmt|;
comment|// AddDefaultFrameworkIncludePaths - Add the framework paths. Used on darwin.
name|void
name|AddDefaultFrameworkIncludePaths
argument_list|(
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|triple
argument_list|)
decl_stmt|;
comment|/// AddDefaultSystemIncludePaths - Adds the default system include paths so
comment|///  that e.g. stdio.h is found.
name|void
name|AddDefaultSystemIncludePaths
argument_list|(
specifier|const
name|LangOptions
operator|&
name|Lang
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|triple
argument_list|)
decl_stmt|;
comment|/// Realize - Merges all search path lists into one list and send it to
comment|/// HeaderSearch.
name|void
name|Realize
parameter_list|()
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

