begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- RawCommentList.h - Classes for processing raw comments -*- C++ -*-===//
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
name|LLVM_CLANG_AST_RAW_COMMENT_LIST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_RAW_COMMENT_LIST_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/CommentOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|ASTReader
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|namespace
name|comments
block|{
name|class
name|FullComment
decl_stmt|;
block|}
comment|// end namespace comments
name|class
name|RawComment
block|{
name|public
label|:
enum|enum
name|CommentKind
block|{
name|RCK_Invalid
block|,
comment|///< Invalid comment
name|RCK_OrdinaryBCPL
block|,
comment|///< Any normal BCPL comments
name|RCK_OrdinaryC
block|,
comment|///< Any normal C comment
name|RCK_BCPLSlash
block|,
comment|///< \code /// stuff \endcode
name|RCK_BCPLExcl
block|,
comment|///< \code //! stuff \endcode
name|RCK_JavaDoc
block|,
comment|///< \code /** stuff */ \endcode
name|RCK_Qt
block|,
comment|///< \code /*! stuff */ \endcode, also used by HeaderDoc
name|RCK_Merged
comment|///< Two or more documentation comments merged together
block|}
enum|;
name|RawComment
argument_list|()
operator|:
name|Kind
argument_list|(
name|RCK_Invalid
argument_list|)
operator|,
name|IsAlmostTrailingComment
argument_list|(
argument|false
argument_list|)
block|{ }
name|RawComment
argument_list|(
argument|const SourceManager&SourceMgr
argument_list|,
argument|SourceRange SR
argument_list|,
argument|bool Merged
argument_list|,
argument|bool ParseAllComments
argument_list|)
expr_stmt|;
name|CommentKind
name|getKind
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
operator|(
name|CommentKind
operator|)
name|Kind
return|;
block|}
name|bool
name|isInvalid
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Kind
operator|==
name|RCK_Invalid
return|;
block|}
name|bool
name|isMerged
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Kind
operator|==
name|RCK_Merged
return|;
block|}
comment|/// Is this comment attached to any declaration?
name|bool
name|isAttached
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|IsAttached
return|;
block|}
name|void
name|setAttached
parameter_list|()
block|{
name|IsAttached
operator|=
name|true
expr_stmt|;
block|}
comment|/// Returns true if it is a comment that should be put after a member:
comment|/// \code ///< stuff \endcode
comment|/// \code //!< stuff \endcode
comment|/// \code /**< stuff */ \endcode
comment|/// \code /*!< stuff */ \endcode
name|bool
name|isTrailingComment
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
name|assert
argument_list|(
name|isDocumentation
argument_list|()
argument_list|)
block|;
return|return
name|IsTrailingComment
return|;
block|}
comment|/// Returns true if it is a probable typo:
comment|/// \code //< stuff \endcode
comment|/// \code /*< stuff */ \endcode
name|bool
name|isAlmostTrailingComment
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|IsAlmostTrailingComment
return|;
block|}
comment|/// Returns true if this comment is not a documentation comment.
name|bool
name|isOrdinary
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
operator|(
operator|(
name|Kind
operator|==
name|RCK_OrdinaryBCPL
operator|)
operator|||
operator|(
name|Kind
operator|==
name|RCK_OrdinaryC
operator|)
operator|)
operator|&&
operator|!
name|ParseAllComments
return|;
block|}
comment|/// Returns true if this comment any kind of a documentation comment.
name|bool
name|isDocumentation
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
operator|!
name|isInvalid
argument_list|()
operator|&&
operator|!
name|isOrdinary
argument_list|()
return|;
block|}
comment|/// Returns whether we are parsing all comments.
name|bool
name|isParseAllComments
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|ParseAllComments
return|;
block|}
comment|/// Returns raw comment text with comment markers.
name|StringRef
name|getRawText
argument_list|(
specifier|const
name|SourceManager
operator|&
name|SourceMgr
argument_list|)
decl|const
block|{
if|if
condition|(
name|RawTextValid
condition|)
return|return
name|RawText
return|;
name|RawText
operator|=
name|getRawTextSlow
argument_list|(
name|SourceMgr
argument_list|)
expr_stmt|;
name|RawTextValid
operator|=
name|true
expr_stmt|;
return|return
name|RawText
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
operator|.
name|getBegin
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
operator|.
name|getEnd
argument_list|()
return|;
block|}
specifier|const
name|char
modifier|*
name|getBriefText
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
block|{
if|if
condition|(
name|BriefTextValid
condition|)
return|return
name|BriefText
return|;
return|return
name|extractBriefText
argument_list|(
name|Context
argument_list|)
return|;
block|}
comment|/// Parse the comment, assuming it is attached to decl \c D.
name|comments
operator|::
name|FullComment
operator|*
name|parse
argument_list|(
argument|const ASTContext&Context
argument_list|,
argument|const Preprocessor *PP
argument_list|,
argument|const Decl *D
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
name|SourceRange
name|Range
decl_stmt|;
name|mutable
name|StringRef
name|RawText
decl_stmt|;
name|mutable
specifier|const
name|char
modifier|*
name|BriefText
decl_stmt|;
name|mutable
name|bool
name|RawTextValid
range|:
literal|1
decl_stmt|;
comment|///< True if RawText is valid
name|mutable
name|bool
name|BriefTextValid
range|:
literal|1
decl_stmt|;
comment|///< True if BriefText is valid
name|unsigned
name|Kind
range|:
literal|3
decl_stmt|;
comment|/// True if comment is attached to a declaration in ASTContext.
name|bool
name|IsAttached
range|:
literal|1
decl_stmt|;
name|bool
name|IsTrailingComment
range|:
literal|1
decl_stmt|;
name|bool
name|IsAlmostTrailingComment
range|:
literal|1
decl_stmt|;
comment|/// When true, ordinary comments starting with "//" and "/*" will be
comment|/// considered as documentation comments.
name|bool
name|ParseAllComments
range|:
literal|1
decl_stmt|;
comment|/// \brief Constructor for AST deserialization.
name|RawComment
argument_list|(
argument|SourceRange SR
argument_list|,
argument|CommentKind K
argument_list|,
argument|bool IsTrailingComment
argument_list|,
argument|bool IsAlmostTrailingComment
argument_list|,
argument|bool ParseAllComments
argument_list|)
block|:
name|Range
argument_list|(
name|SR
argument_list|)
operator|,
name|RawTextValid
argument_list|(
name|false
argument_list|)
operator|,
name|BriefTextValid
argument_list|(
name|false
argument_list|)
operator|,
name|Kind
argument_list|(
name|K
argument_list|)
operator|,
name|IsAttached
argument_list|(
name|false
argument_list|)
operator|,
name|IsTrailingComment
argument_list|(
name|IsTrailingComment
argument_list|)
operator|,
name|IsAlmostTrailingComment
argument_list|(
name|IsAlmostTrailingComment
argument_list|)
operator|,
name|ParseAllComments
argument_list|(
argument|ParseAllComments
argument_list|)
block|{ }
name|StringRef
name|getRawTextSlow
argument_list|(
argument|const SourceManager&SourceMgr
argument_list|)
specifier|const
expr_stmt|;
specifier|const
name|char
modifier|*
name|extractBriefText
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
name|friend
name|class
name|ASTReader
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Compare comments' source locations.
name|template
operator|<
operator|>
name|class
name|BeforeThanCompare
operator|<
name|RawComment
operator|>
block|{
specifier|const
name|SourceManager
operator|&
name|SM
block|;
name|public
operator|:
name|explicit
name|BeforeThanCompare
argument_list|(
specifier|const
name|SourceManager
operator|&
name|SM
argument_list|)
operator|:
name|SM
argument_list|(
argument|SM
argument_list|)
block|{ }
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|RawComment
operator|&
name|LHS
operator|,
specifier|const
name|RawComment
operator|&
name|RHS
operator|)
block|{
return|return
name|SM
operator|.
name|isBeforeInTranslationUnit
argument_list|(
name|LHS
operator|.
name|getLocStart
argument_list|()
argument_list|,
name|RHS
operator|.
name|getLocStart
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|RawComment
operator|*
name|LHS
operator|,
specifier|const
name|RawComment
operator|*
name|RHS
operator|)
block|{
return|return
name|operator
argument_list|()
argument_list|(
operator|*
name|LHS
argument_list|,
operator|*
name|RHS
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief This class represents all comments included in the translation unit,
comment|/// sorted in order of appearance in the translation unit.
name|class
name|RawCommentList
block|{
name|public
operator|:
name|RawCommentList
argument_list|(
name|SourceManager
operator|&
name|SourceMgr
argument_list|)
operator|:
name|SourceMgr
argument_list|(
argument|SourceMgr
argument_list|)
block|{}
name|void
name|addComment
argument_list|(
specifier|const
name|RawComment
operator|&
name|RC
argument_list|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|Allocator
argument_list|)
block|;
name|ArrayRef
operator|<
name|RawComment
operator|*
operator|>
name|getComments
argument_list|()
specifier|const
block|{
return|return
name|Comments
return|;
block|}
name|private
operator|:
name|SourceManager
operator|&
name|SourceMgr
block|;
name|std
operator|::
name|vector
operator|<
name|RawComment
operator|*
operator|>
name|Comments
block|;
name|void
name|addCommentsToFront
argument_list|(
argument|const std::vector<RawComment *>&C
argument_list|)
block|{
name|Comments
operator|.
name|insert
argument_list|(
name|Comments
operator|.
name|begin
argument_list|()
argument_list|,
name|C
operator|.
name|begin
argument_list|()
argument_list|,
name|C
operator|.
name|end
argument_list|()
argument_list|)
block|;   }
name|friend
name|class
name|ASTReader
block|; }
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

