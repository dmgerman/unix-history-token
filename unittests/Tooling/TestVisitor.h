begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TestVisitor.h ------------------------------------------*- C++ -*-===//
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
comment|//  This file defines a utility class for RecursiveASTVisitor related tests.
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
name|LLVM_CLANG_TEST_VISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TEST_VISITOR_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ASTConsumer.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/RecursiveASTVisitor.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/FrontendAction.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/CompilerInstance.h"
end_include

begin_include
include|#
directive|include
file|"clang/Tooling/Tooling.h"
end_include

begin_include
include|#
directive|include
file|"gtest/gtest.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Base class for simple RecursiveASTVisitor based tests.
comment|///
comment|/// This is a drop-in replacement for RecursiveASTVisitor itself, with the
comment|/// additional capability of running it over a snippet of code.
comment|///
comment|/// Visits template instantiations by default.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|TestVisitor
operator|:
name|public
name|RecursiveASTVisitor
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|TestVisitor
argument_list|()
block|{ }
name|virtual
operator|~
name|TestVisitor
argument_list|()
block|{ }
comment|/// \brief Runs the current AST visitor over the given code.
name|bool
name|runOver
argument_list|(
argument|StringRef Code
argument_list|)
block|{
return|return
name|tooling
operator|::
name|runToolOnCode
argument_list|(
name|CreateTestAction
argument_list|()
argument_list|,
name|Code
argument_list|)
return|;
block|}
name|bool
name|shouldVisitTemplateInstantiations
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|protected
operator|:
name|virtual
name|ASTFrontendAction
operator|*
name|CreateTestAction
argument_list|()
block|{
return|return
name|new
name|TestAction
argument_list|(
name|this
argument_list|)
return|;
block|}
name|class
name|FindConsumer
operator|:
name|public
name|ASTConsumer
block|{
name|public
operator|:
name|FindConsumer
argument_list|(
name|TestVisitor
operator|*
name|Visitor
argument_list|)
operator|:
name|Visitor
argument_list|(
argument|Visitor
argument_list|)
block|{}
name|virtual
name|void
name|HandleTranslationUnit
argument_list|(
argument|clang::ASTContext&Context
argument_list|)
block|{
name|Visitor
operator|->
name|Context
operator|=
operator|&
name|Context
block|;
name|Visitor
operator|->
name|TraverseDecl
argument_list|(
name|Context
operator|.
name|getTranslationUnitDecl
argument_list|()
argument_list|)
block|;     }
name|private
operator|:
name|TestVisitor
operator|*
name|Visitor
block|;   }
block|;
name|class
name|TestAction
operator|:
name|public
name|ASTFrontendAction
block|{
name|public
operator|:
name|TestAction
argument_list|(
name|TestVisitor
operator|*
name|Visitor
argument_list|)
operator|:
name|Visitor
argument_list|(
argument|Visitor
argument_list|)
block|{}
name|virtual
name|clang
operator|::
name|ASTConsumer
operator|*
name|CreateASTConsumer
argument_list|(
argument|CompilerInstance&
argument_list|,
argument|llvm::StringRef dummy
argument_list|)
block|{
comment|/// TestConsumer will be deleted by the framework calling us.
return|return
name|new
name|FindConsumer
argument_list|(
name|Visitor
argument_list|)
return|;
block|}
name|protected
operator|:
name|TestVisitor
operator|*
name|Visitor
block|;   }
block|;
name|ASTContext
operator|*
name|Context
block|; }
expr_stmt|;
comment|/// \brief A RecursiveASTVisitor for testing the RecursiveASTVisitor itself.
comment|///
comment|/// Allows simple creation of test visitors running matches on only a small
comment|/// subset of the Visit* methods.
name|template
operator|<
name|typename
name|T
operator|,
name|template
operator|<
name|typename
operator|>
name|class
name|Visitor
operator|=
name|TestVisitor
operator|>
name|class
name|ExpectedLocationVisitor
operator|:
name|public
name|Visitor
operator|<
name|T
operator|>
block|{
name|public
operator|:
name|ExpectedLocationVisitor
argument_list|()
operator|:
name|ExpectedLine
argument_list|(
literal|0
argument_list|)
block|,
name|ExpectedColumn
argument_list|(
literal|0
argument_list|)
block|,
name|Found
argument_list|(
argument|false
argument_list|)
block|{}
name|virtual
operator|~
name|ExpectedLocationVisitor
argument_list|()
block|{
name|EXPECT_TRUE
argument_list|(
name|Found
argument_list|)
operator|<<
literal|"Expected \""
operator|<<
name|ExpectedMatch
operator|<<
literal|"\" at "
operator|<<
name|ExpectedLine
operator|<<
literal|":"
operator|<<
name|ExpectedColumn
operator|<<
name|PartialMatches
block|;   }
comment|/// \brief Expect 'Match' to occur at the given 'Line' and 'Column'.
name|void
name|ExpectMatch
argument_list|(
argument|Twine Match
argument_list|,
argument|unsigned Line
argument_list|,
argument|unsigned Column
argument_list|)
block|{
name|ExpectedMatch
operator|=
name|Match
operator|.
name|str
argument_list|()
block|;
name|ExpectedLine
operator|=
name|Line
block|;
name|ExpectedColumn
operator|=
name|Column
block|;   }
name|protected
operator|:
comment|/// \brief Convenience method to simplify writing test visitors.
comment|///
comment|/// Sets 'Found' to true if 'Name' and 'Location' match the expected
comment|/// values. If only a partial match is found, record the information
comment|/// to produce nice error output when a test fails.
comment|///
comment|/// Implementations are required to call this with appropriate values
comment|/// for 'Name' during visitation.
name|void
name|Match
argument_list|(
argument|StringRef Name
argument_list|,
argument|SourceLocation Location
argument_list|)
block|{
name|FullSourceLoc
name|FullLocation
operator|=
name|this
operator|->
name|Context
operator|->
name|getFullLoc
argument_list|(
name|Location
argument_list|)
block|;
if|if
condition|(
name|Name
operator|==
name|ExpectedMatch
operator|&&
name|FullLocation
operator|.
name|isValid
argument_list|()
operator|&&
name|FullLocation
operator|.
name|getSpellingLineNumber
argument_list|()
operator|==
name|ExpectedLine
operator|&&
name|FullLocation
operator|.
name|getSpellingColumnNumber
argument_list|()
operator|==
name|ExpectedColumn
condition|)
block|{
name|EXPECT_TRUE
argument_list|(
operator|!
name|Found
argument_list|)
expr_stmt|;
name|Found
operator|=
name|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|Name
operator|==
name|ExpectedMatch
operator|||
operator|(
name|FullLocation
operator|.
name|isValid
argument_list|()
operator|&&
name|FullLocation
operator|.
name|getSpellingLineNumber
argument_list|()
operator|==
name|ExpectedLine
operator|&&
name|FullLocation
operator|.
name|getSpellingColumnNumber
argument_list|()
operator|==
name|ExpectedColumn
operator|)
condition|)
block|{
comment|// If we did not match, record information about partial matches.
name|llvm
operator|::
name|raw_string_ostream
name|Stream
argument_list|(
name|PartialMatches
argument_list|)
expr_stmt|;
name|Stream
operator|<<
literal|", partial match: \""
operator|<<
name|Name
operator|<<
literal|"\" at "
expr_stmt|;
name|Location
operator|.
name|print
argument_list|(
name|Stream
argument_list|,
name|this
operator|->
name|Context
operator|->
name|getSourceManager
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|std
operator|::
name|string
name|ExpectedMatch
block|;
name|unsigned
name|ExpectedLine
block|;
name|unsigned
name|ExpectedColumn
block|;
name|std
operator|::
name|string
name|PartialMatches
block|;
name|bool
name|Found
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_CLANG_TEST_VISITOR_H */
end_comment

end_unit

