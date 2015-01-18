begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TokenRewriter.h - Token-based Rewriter -----------------*- C++ -*-===//
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
comment|//  This file defines the TokenRewriter class, which is used for code
end_comment

begin_comment
comment|//  transformations.
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
name|LLVM_CLANG_REWRITE_CORE_TOKENREWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_REWRITE_CORE_TOKENREWRITER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/Token.h"
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|LangOptions
decl_stmt|;
name|class
name|ScratchBuffer
decl_stmt|;
name|class
name|TokenRewriter
block|{
comment|/// TokenList - This is the list of raw tokens that make up this file.  Each
comment|/// of these tokens has a unique SourceLocation, which is a FileID.
name|std
operator|::
name|list
operator|<
name|Token
operator|>
name|TokenList
expr_stmt|;
comment|/// TokenRefTy - This is the type used to refer to a token in the TokenList.
typedef|typedef
name|std
operator|::
name|list
operator|<
name|Token
operator|>
operator|::
name|iterator
name|TokenRefTy
expr_stmt|;
comment|/// TokenAtLoc - This map indicates which token exists at a specific
comment|/// SourceLocation.  Since each token has a unique SourceLocation, this is a
comment|/// one to one map.  The token can return its own location directly, to map
comment|/// backwards.
name|std
operator|::
name|map
operator|<
name|SourceLocation
operator|,
name|TokenRefTy
operator|>
name|TokenAtLoc
expr_stmt|;
comment|/// ScratchBuf - This is the buffer that we create scratch tokens from.
comment|///
name|std
operator|::
name|unique_ptr
operator|<
name|ScratchBuffer
operator|>
name|ScratchBuf
expr_stmt|;
name|TokenRewriter
argument_list|(
argument|const TokenRewriter&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|TokenRewriter
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
comment|/// TokenRewriter - This creates a TokenRewriter for the file with the
comment|/// specified FileID.
name|TokenRewriter
argument_list|(
argument|FileID FID
argument_list|,
argument|SourceManager&SM
argument_list|,
argument|const LangOptions&LO
argument_list|)
empty_stmt|;
operator|~
name|TokenRewriter
argument_list|()
expr_stmt|;
typedef|typedef
name|std
operator|::
name|list
operator|<
name|Token
operator|>
operator|::
name|const_iterator
name|token_iterator
expr_stmt|;
name|token_iterator
name|token_begin
argument_list|()
specifier|const
block|{
return|return
name|TokenList
operator|.
name|begin
argument_list|()
return|;
block|}
name|token_iterator
name|token_end
argument_list|()
specifier|const
block|{
return|return
name|TokenList
operator|.
name|end
argument_list|()
return|;
block|}
name|token_iterator
name|AddTokenBefore
parameter_list|(
name|token_iterator
name|I
parameter_list|,
specifier|const
name|char
modifier|*
name|Val
parameter_list|)
function_decl|;
name|token_iterator
name|AddTokenAfter
parameter_list|(
name|token_iterator
name|I
parameter_list|,
specifier|const
name|char
modifier|*
name|Val
parameter_list|)
block|{
name|assert
argument_list|(
name|I
operator|!=
name|token_end
argument_list|()
operator|&&
literal|"Cannot insert after token_end()!"
argument_list|)
expr_stmt|;
return|return
name|AddTokenBefore
argument_list|(
operator|++
name|I
argument_list|,
name|Val
argument_list|)
return|;
block|}
name|private
label|:
comment|/// RemapIterator - Convert from token_iterator (a const iterator) to
comment|/// TokenRefTy (a non-const iterator).
name|TokenRefTy
name|RemapIterator
parameter_list|(
name|token_iterator
name|I
parameter_list|)
function_decl|;
comment|/// AddToken - Add the specified token into the Rewriter before the other
comment|/// position.
name|TokenRefTy
name|AddToken
parameter_list|(
specifier|const
name|Token
modifier|&
name|T
parameter_list|,
name|TokenRefTy
name|Where
parameter_list|)
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

