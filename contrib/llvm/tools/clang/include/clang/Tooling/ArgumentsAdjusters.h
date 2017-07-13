begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ArgumentsAdjusters.h - Command line arguments adjuster -*- C++ -*-===//
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
comment|// This file declares typedef ArgumentsAdjuster and functions to create several
end_comment

begin_comment
comment|// useful argument adjusters.
end_comment

begin_comment
comment|// ArgumentsAdjusters modify command line arguments obtained from a compilation
end_comment

begin_comment
comment|// database before they are used to run a frontend action.
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
name|LLVM_CLANG_TOOLING_ARGUMENTSADJUSTERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_ARGUMENTSADJUSTERS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<functional>
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
name|tooling
block|{
comment|/// \brief A sequence of command line arguments.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|CommandLineArguments
expr_stmt|;
comment|/// \brief A prototype of a command line adjuster.
comment|///
comment|/// Command line argument adjuster is responsible for command line arguments
comment|/// modification before the arguments are used to run a frontend action.
typedef|typedef
name|std
operator|::
name|function
operator|<
name|CommandLineArguments
argument_list|(
argument|const CommandLineArguments&
argument_list|,
argument|StringRef Filename
argument_list|)
operator|>
name|ArgumentsAdjuster
expr_stmt|;
comment|/// \brief Gets an argument adjuster that converts input command line arguments
comment|/// to the "syntax check only" variant.
name|ArgumentsAdjuster
name|getClangSyntaxOnlyAdjuster
parameter_list|()
function_decl|;
comment|/// \brief Gets an argument adjuster which removes output-related command line
comment|/// arguments.
name|ArgumentsAdjuster
name|getClangStripOutputAdjuster
parameter_list|()
function_decl|;
comment|/// \brief Gets an argument adjuster which removes dependency-file
comment|/// related command line arguments.
name|ArgumentsAdjuster
name|getClangStripDependencyFileAdjuster
parameter_list|()
function_decl|;
name|enum
name|class
name|ArgumentInsertPosition
block|{
name|BEGIN
operator|,
name|END
block|}
empty_stmt|;
comment|/// \brief Gets an argument adjuster which inserts \p Extra arguments in the
comment|/// specified position.
name|ArgumentsAdjuster
name|getInsertArgumentAdjuster
parameter_list|(
specifier|const
name|CommandLineArguments
modifier|&
name|Extra
parameter_list|,
name|ArgumentInsertPosition
name|Pos
parameter_list|)
function_decl|;
comment|/// \brief Gets an argument adjuster which inserts an \p Extra argument in the
comment|/// specified position.
name|ArgumentsAdjuster
name|getInsertArgumentAdjuster
parameter_list|(
specifier|const
name|char
modifier|*
name|Extra
parameter_list|,
name|ArgumentInsertPosition
name|Pos
init|=
name|ArgumentInsertPosition
operator|::
name|END
parameter_list|)
function_decl|;
comment|/// \brief Gets an argument adjuster which adjusts the arguments in sequence
comment|/// with the \p First adjuster and then with the \p Second one.
name|ArgumentsAdjuster
name|combineAdjusters
parameter_list|(
name|ArgumentsAdjuster
name|First
parameter_list|,
name|ArgumentsAdjuster
name|Second
parameter_list|)
function_decl|;
block|}
comment|// namespace tooling
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_TOOLING_ARGUMENTSADJUSTERS_H
end_comment

end_unit

