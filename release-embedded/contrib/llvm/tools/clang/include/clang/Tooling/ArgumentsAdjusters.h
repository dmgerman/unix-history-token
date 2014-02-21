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
comment|// This file declares base abstract class ArgumentsAdjuster and its descendants.
end_comment

begin_comment
comment|// These classes are intended to modify command line arguments obtained from
end_comment

begin_comment
comment|// a compilation database before they are used to run a frontend action.
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
comment|/// \brief Abstract interface for a command line adjusters.
comment|///
comment|/// This abstract interface describes a command line argument adjuster,
comment|/// which is responsible for command line arguments modification before
comment|/// the arguments are used to run a frontend action.
name|class
name|ArgumentsAdjuster
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
comment|/// \brief Returns adjusted command line arguments.
comment|///
comment|/// \param Args Input sequence of command line arguments.
comment|///
comment|/// \returns Modified sequence of command line arguments.
name|virtual
name|CommandLineArguments
name|Adjust
parameter_list|(
specifier|const
name|CommandLineArguments
modifier|&
name|Args
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
operator|~
name|ArgumentsAdjuster
argument_list|()
block|{   }
block|}
empty_stmt|;
comment|/// \brief Syntax check only command line adjuster.
comment|///
comment|/// This class implements ArgumentsAdjuster interface and converts input
comment|/// command line arguments to the "syntax check only" variant.
name|class
name|ClangSyntaxOnlyAdjuster
range|:
name|public
name|ArgumentsAdjuster
block|{
name|virtual
name|CommandLineArguments
name|Adjust
argument_list|(
specifier|const
name|CommandLineArguments
operator|&
name|Args
argument_list|)
block|; }
decl_stmt|;
comment|/// \brief An argument adjuster which removes output-related command line
comment|/// arguments.
name|class
name|ClangStripOutputAdjuster
range|:
name|public
name|ArgumentsAdjuster
block|{
name|virtual
name|CommandLineArguments
name|Adjust
argument_list|(
specifier|const
name|CommandLineArguments
operator|&
name|Args
argument_list|)
block|; }
decl_stmt|;
block|}
comment|// end namespace tooling
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_TOOLING_ARGUMENTSADJUSTERS_H
end_comment

end_unit

