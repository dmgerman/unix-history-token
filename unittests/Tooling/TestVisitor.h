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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines utility templates for RecursiveASTVisitor related tests.
end_comment

begin_comment
comment|///
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
file|<vector>
end_include

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
comment|/// Visits template instantiations (but not implicit code) by default.
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
expr|enum
name|Language
block|{
name|Lang_C
block|,
name|Lang_CXX
block|}
block|;
comment|/// \brief Runs the current AST visitor over the given code.
name|bool
name|runOver
argument_list|(
argument|StringRef Code
argument_list|,
argument|Language L = Lang_CXX
argument_list|)
block|{
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Args
block|;
switch|switch
condition|(
name|L
condition|)
block|{
case|case
name|Lang_C
case|:
name|Args
operator|.
name|push_back
argument_list|(
literal|"-std=c99"
argument_list|)
expr_stmt|;
break|break;
case|case
name|Lang_CXX
case|:
name|Args
operator|.
name|push_back
argument_list|(
literal|"-std=c++98"
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
name|tooling
operator|::
name|runToolOnCodeWithArgs
argument_list|(
name|CreateTestAction
argument_list|()
argument_list|,
name|Code
argument_list|,
name|Args
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
comment|/// \brief A RecursiveASTVisitor to check that certain matches are (or are
comment|/// not) observed during visitation.
comment|///
comment|/// This is a RecursiveASTVisitor for testing the RecursiveASTVisitor itself,
comment|/// and allows simple creation of test visitors running matches on only a small
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
comment|/// \brief Expect 'Match' *not* to occur at the given 'Line' and 'Column'.
comment|///
comment|/// Any number of matches can be disallowed.
name|void
name|DisallowMatch
argument_list|(
argument|Twine Match
argument_list|,
argument|unsigned Line
argument_list|,
argument|unsigned Column
argument_list|)
block|{
name|DisallowedMatches
operator|.
name|push_back
argument_list|(
name|MatchCandidate
argument_list|(
name|Match
argument_list|,
name|Line
argument_list|,
name|Column
argument_list|)
argument_list|)
block|;   }
comment|/// \brief Expect 'Match' to occur at the given 'Line' and 'Column'.
comment|///
comment|/// Any number of expected matches can be set by calling this repeatedly.
comment|/// Each is expected to be matched exactly once.
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
name|ExpectedMatches
operator|.
name|push_back
argument_list|(
name|ExpectedMatch
argument_list|(
name|Match
argument_list|,
name|Line
argument_list|,
name|Column
argument_list|)
argument_list|)
block|;   }
comment|/// \brief Checks that all expected matches have been found.
name|virtual
operator|~
name|ExpectedLocationVisitor
argument_list|()
block|{
for|for
control|(
name|typename
name|std
operator|::
name|vector
operator|<
name|ExpectedMatch
operator|>
operator|::
name|const_iterator
name|It
operator|=
name|ExpectedMatches
operator|.
name|begin
argument_list|()
operator|,
name|End
operator|=
name|ExpectedMatches
operator|.
name|end
argument_list|()
init|;
name|It
operator|!=
name|End
condition|;
operator|++
name|It
control|)
block|{
name|It
operator|->
name|ExpectFound
argument_list|()
expr_stmt|;
block|}
block|}
name|protected
operator|:
comment|/// \brief Checks an actual match against expected and disallowed matches.
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
specifier|const
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
for|for
control|(
name|typename
name|std
operator|::
name|vector
operator|<
name|MatchCandidate
operator|>
operator|::
name|const_iterator
name|It
operator|=
name|DisallowedMatches
operator|.
name|begin
argument_list|()
operator|,
name|End
operator|=
name|DisallowedMatches
operator|.
name|end
argument_list|()
init|;
name|It
operator|!=
name|End
condition|;
operator|++
name|It
control|)
block|{
name|EXPECT_FALSE
argument_list|(
name|It
operator|->
name|Matches
argument_list|(
name|Name
argument_list|,
name|FullLocation
argument_list|)
argument_list|)
operator|<<
literal|"Matched disallowed "
operator|<<
operator|*
name|It
expr_stmt|;
block|}
for|for
control|(
name|typename
name|std
operator|::
name|vector
operator|<
name|ExpectedMatch
operator|>
operator|::
name|iterator
name|It
operator|=
name|ExpectedMatches
operator|.
name|begin
argument_list|()
operator|,
name|End
operator|=
name|ExpectedMatches
operator|.
name|end
argument_list|()
init|;
name|It
operator|!=
name|End
condition|;
operator|++
name|It
control|)
block|{
name|It
operator|->
name|UpdateFor
argument_list|(
name|Name
argument_list|,
name|FullLocation
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
name|private
operator|:
expr|struct
name|MatchCandidate
block|{
name|std
operator|::
name|string
name|ExpectedName
block|;
name|unsigned
name|LineNumber
block|;
name|unsigned
name|ColumnNumber
block|;
name|MatchCandidate
argument_list|(
argument|Twine Name
argument_list|,
argument|unsigned LineNumber
argument_list|,
argument|unsigned ColumnNumber
argument_list|)
operator|:
name|ExpectedName
argument_list|(
name|Name
operator|.
name|str
argument_list|()
argument_list|)
block|,
name|LineNumber
argument_list|(
name|LineNumber
argument_list|)
block|,
name|ColumnNumber
argument_list|(
argument|ColumnNumber
argument_list|)
block|{     }
name|bool
name|Matches
argument_list|(
argument|StringRef Name
argument_list|,
argument|FullSourceLoc const&Location
argument_list|)
specifier|const
block|{
return|return
name|MatchesName
argument_list|(
name|Name
argument_list|)
operator|&&
name|MatchesLocation
argument_list|(
name|Location
argument_list|)
return|;
block|}
name|bool
name|PartiallyMatches
argument_list|(
argument|StringRef Name
argument_list|,
argument|FullSourceLoc const&Location
argument_list|)
specifier|const
block|{
return|return
name|MatchesName
argument_list|(
name|Name
argument_list|)
operator|||
name|MatchesLocation
argument_list|(
name|Location
argument_list|)
return|;
block|}
name|bool
name|MatchesName
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|{
return|return
name|Name
operator|==
name|ExpectedName
return|;
block|}
name|bool
name|MatchesLocation
argument_list|(
argument|FullSourceLoc const&Location
argument_list|)
specifier|const
block|{
return|return
name|Location
operator|.
name|isValid
argument_list|()
operator|&&
name|Location
operator|.
name|getSpellingLineNumber
argument_list|()
operator|==
name|LineNumber
operator|&&
name|Location
operator|.
name|getSpellingColumnNumber
argument_list|()
operator|==
name|ColumnNumber
return|;
block|}
name|friend
name|std
operator|::
name|ostream
operator|&
name|operator
operator|<<
operator|(
name|std
operator|::
name|ostream
operator|&
name|Stream
operator|,
name|MatchCandidate
specifier|const
operator|&
name|Match
operator|)
block|{
return|return
name|Stream
operator|<<
name|Match
operator|.
name|ExpectedName
operator|<<
literal|" at "
operator|<<
name|Match
operator|.
name|LineNumber
operator|<<
literal|":"
operator|<<
name|Match
operator|.
name|ColumnNumber
return|;
block|}
expr|}
block|;    struct
name|ExpectedMatch
block|{
name|ExpectedMatch
argument_list|(
argument|Twine Name
argument_list|,
argument|unsigned LineNumber
argument_list|,
argument|unsigned ColumnNumber
argument_list|)
operator|:
name|Candidate
argument_list|(
name|Name
argument_list|,
name|LineNumber
argument_list|,
name|ColumnNumber
argument_list|)
block|,
name|Found
argument_list|(
argument|false
argument_list|)
block|{}
name|void
name|UpdateFor
argument_list|(
argument|StringRef Name
argument_list|,
argument|FullSourceLoc Location
argument_list|,
argument|SourceManager&SM
argument_list|)
block|{
if|if
condition|(
name|Candidate
operator|.
name|Matches
argument_list|(
name|Name
argument_list|,
name|Location
argument_list|)
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
operator|!
name|Found
operator|&&
name|Candidate
operator|.
name|PartiallyMatches
argument_list|(
name|Name
argument_list|,
name|Location
argument_list|)
condition|)
block|{
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
name|SM
argument_list|)
expr_stmt|;
block|}
block|}
name|void
name|ExpectFound
argument_list|()
specifier|const
block|{
name|EXPECT_TRUE
argument_list|(
name|Found
argument_list|)
operator|<<
literal|"Expected \""
operator|<<
name|Candidate
operator|.
name|ExpectedName
operator|<<
literal|"\" at "
operator|<<
name|Candidate
operator|.
name|LineNumber
operator|<<
literal|":"
operator|<<
name|Candidate
operator|.
name|ColumnNumber
operator|<<
name|PartialMatches
block|;     }
name|MatchCandidate
name|Candidate
block|;
name|std
operator|::
name|string
name|PartialMatches
block|;
name|bool
name|Found
block|;   }
block|;
name|std
operator|::
name|vector
operator|<
name|MatchCandidate
operator|>
name|DisallowedMatches
block|;
name|std
operator|::
name|vector
operator|<
name|ExpectedMatch
operator|>
name|ExpectedMatches
block|; }
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_CLANG_TEST_VISITOR_H */
end_comment

end_unit

