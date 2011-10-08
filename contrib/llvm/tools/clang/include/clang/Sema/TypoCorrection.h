begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TypoCorrection.h - Class for typo correction results ---*- C++ -*-===//
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
comment|// This file defines the TypoCorrection class, which stores the results of
end_comment

begin_comment
comment|// Sema's typo correction (Sema::CorrectTypo).
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
name|LLVM_CLANG_SEMA_TYPOCORRECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_TYPOCORRECTION_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclCXX.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// @brief Simple class containing the result of Sema::CorrectTypo
name|class
name|TypoCorrection
block|{
name|public
label|:
name|TypoCorrection
argument_list|(
argument|const DeclarationName&Name
argument_list|,
argument|NamedDecl *NameDecl
argument_list|,
argument|NestedNameSpecifier *NNS=NULL
argument_list|,
argument|unsigned distance=
literal|0
argument_list|)
block|:
name|CorrectionName
argument_list|(
name|Name
argument_list|)
operator|,
name|CorrectionNameSpec
argument_list|(
name|NNS
argument_list|)
operator|,
name|CorrectionDecl
argument_list|(
name|NameDecl
argument_list|)
operator|,
name|EditDistance
argument_list|(
argument|distance
argument_list|)
block|{}
name|TypoCorrection
argument_list|(
argument|NamedDecl *Name
argument_list|,
argument|NestedNameSpecifier *NNS=NULL
argument_list|,
argument|unsigned distance=
literal|0
argument_list|)
operator|:
name|CorrectionName
argument_list|(
name|Name
operator|->
name|getDeclName
argument_list|()
argument_list|)
operator|,
name|CorrectionNameSpec
argument_list|(
name|NNS
argument_list|)
operator|,
name|CorrectionDecl
argument_list|(
name|Name
argument_list|)
operator|,
name|EditDistance
argument_list|(
argument|distance
argument_list|)
block|{}
name|TypoCorrection
argument_list|(
argument|DeclarationName Name
argument_list|,
argument|NestedNameSpecifier *NNS=NULL
argument_list|,
argument|unsigned distance=
literal|0
argument_list|)
operator|:
name|CorrectionName
argument_list|(
name|Name
argument_list|)
operator|,
name|CorrectionNameSpec
argument_list|(
name|NNS
argument_list|)
operator|,
name|CorrectionDecl
argument_list|(
name|NULL
argument_list|)
operator|,
name|EditDistance
argument_list|(
argument|distance
argument_list|)
block|{}
name|TypoCorrection
argument_list|()
operator|:
name|CorrectionName
argument_list|()
operator|,
name|CorrectionNameSpec
argument_list|(
name|NULL
argument_list|)
operator|,
name|CorrectionDecl
argument_list|(
name|NULL
argument_list|)
operator|,
name|EditDistance
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// \brief Gets the DeclarationName of the typo correction
name|DeclarationName
name|getCorrection
argument_list|()
specifier|const
block|{
return|return
name|CorrectionName
return|;
block|}
name|IdentifierInfo
operator|*
name|getCorrectionAsIdentifierInfo
argument_list|()
specifier|const
block|{
return|return
name|CorrectionName
operator|.
name|getAsIdentifierInfo
argument_list|()
return|;
block|}
comment|/// \brief Gets the NestedNameSpecifier needed to use the typo correction
name|NestedNameSpecifier
operator|*
name|getCorrectionSpecifier
argument_list|()
specifier|const
block|{
return|return
name|CorrectionNameSpec
return|;
block|}
name|void
name|setCorrectionSpecifier
parameter_list|(
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|)
block|{
name|CorrectionNameSpec
operator|=
name|NNS
expr_stmt|;
block|}
comment|/// \brief Gets the "edit distance" of the typo correction from the typo
name|unsigned
name|getEditDistance
argument_list|()
specifier|const
block|{
return|return
name|EditDistance
return|;
block|}
comment|/// \brief Gets the pointer to the declaration of the typo correction
name|NamedDecl
operator|*
name|getCorrectionDecl
argument_list|()
specifier|const
block|{
return|return
name|isKeyword
argument_list|()
operator|?
name|NULL
operator|:
name|CorrectionDecl
return|;
block|}
name|template
operator|<
name|class
name|DeclClass
operator|>
name|DeclClass
operator|*
name|getCorrectionDeclAs
argument_list|()
specifier|const
block|{
return|return
name|dyn_cast_or_null
operator|<
name|DeclClass
operator|>
operator|(
name|getCorrectionDecl
argument_list|()
operator|)
return|;
block|}
name|void
name|setCorrectionDecl
parameter_list|(
name|NamedDecl
modifier|*
name|CDecl
parameter_list|)
block|{
name|CorrectionDecl
operator|=
name|CDecl
expr_stmt|;
if|if
condition|(
operator|!
name|CorrectionName
condition|)
name|CorrectionName
operator|=
name|CDecl
operator|->
name|getDeclName
argument_list|()
expr_stmt|;
block|}
name|std
operator|::
name|string
name|getAsString
argument_list|(
argument|const LangOptions&LO
argument_list|)
specifier|const
expr_stmt|;
name|std
operator|::
name|string
name|getQuoted
argument_list|(
argument|const LangOptions&LO
argument_list|)
specifier|const
block|{
return|return
literal|"'"
operator|+
name|getAsString
argument_list|(
name|LO
argument_list|)
operator|+
literal|"'"
return|;
block|}
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|bool
argument_list|(
name|CorrectionName
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|NamedDecl
modifier|*
name|KeywordDecl
parameter_list|()
block|{
return|return
operator|(
name|NamedDecl
operator|*
operator|)
operator|-
literal|1
return|;
block|}
name|bool
name|isKeyword
argument_list|()
specifier|const
block|{
return|return
name|CorrectionDecl
operator|==
name|KeywordDecl
argument_list|()
return|;
block|}
comment|// Returns true if the correction either is a keyword or has a known decl.
name|bool
name|isResolved
argument_list|()
specifier|const
block|{
return|return
name|CorrectionDecl
operator|!=
name|NULL
return|;
block|}
name|private
label|:
comment|// Results.
name|DeclarationName
name|CorrectionName
decl_stmt|;
name|NestedNameSpecifier
modifier|*
name|CorrectionNameSpec
decl_stmt|;
name|NamedDecl
modifier|*
name|CorrectionDecl
decl_stmt|;
name|unsigned
name|EditDistance
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

