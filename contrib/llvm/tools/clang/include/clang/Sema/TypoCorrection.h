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

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
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
argument|NestedNameSpecifier *NNS=
literal|0
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
name|EditDistance
argument_list|(
argument|distance
argument_list|)
block|{
if|if
condition|(
name|NameDecl
condition|)
name|CorrectionDecls
operator|.
name|push_back
argument_list|(
name|NameDecl
argument_list|)
expr_stmt|;
block|}
name|TypoCorrection
argument_list|(
argument|NamedDecl *Name
argument_list|,
argument|NestedNameSpecifier *NNS=
literal|0
argument_list|,
argument|unsigned distance=
literal|0
argument_list|)
block|:
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
name|EditDistance
argument_list|(
argument|distance
argument_list|)
block|{
if|if
condition|(
name|Name
condition|)
name|CorrectionDecls
operator|.
name|push_back
argument_list|(
name|Name
argument_list|)
expr_stmt|;
block|}
name|TypoCorrection
argument_list|(
argument|DeclarationName Name
argument_list|,
argument|NestedNameSpecifier *NNS=
literal|0
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
name|EditDistance
argument_list|(
argument|distance
argument_list|)
block|{}
name|TypoCorrection
argument_list|()
operator|:
name|CorrectionNameSpec
argument_list|(
literal|0
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
name|hasCorrectionDecl
argument_list|()
operator|?
operator|*
operator|(
name|CorrectionDecls
operator|.
name|begin
argument_list|()
operator|)
operator|:
literal|0
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
comment|/// \brief Clears the list of NamedDecls before adding the new one.
name|void
name|setCorrectionDecl
parameter_list|(
name|NamedDecl
modifier|*
name|CDecl
parameter_list|)
block|{
name|CorrectionDecls
operator|.
name|clear
argument_list|()
expr_stmt|;
name|addCorrectionDecl
argument_list|(
name|CDecl
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Add the given NamedDecl to the list of NamedDecls that are the
comment|/// declarations associated with the DeclarationName of this TypoCorrection
name|void
name|addCorrectionDecl
parameter_list|(
name|NamedDecl
modifier|*
name|CDecl
parameter_list|)
function_decl|;
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
comment|/// \brief Returns whether this TypoCorrection has a non-empty DeclarationName
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
comment|/// \brief Mark this TypoCorrection as being a keyword.
comment|/// Since addCorrectionDeclsand setCorrectionDecl don't allow NULL to be
comment|/// added to the list of the correction's NamedDecl pointers, NULL is added
comment|/// as the only element in the list to mark this TypoCorrection as a keyword.
name|void
name|makeKeyword
parameter_list|()
block|{
name|CorrectionDecls
operator|.
name|clear
argument_list|()
expr_stmt|;
name|CorrectionDecls
operator|.
name|push_back
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
comment|// Check if this TypoCorrection is a keyword by checking if the first
comment|// item in CorrectionDecls is NULL.
name|bool
name|isKeyword
argument_list|()
specifier|const
block|{
return|return
operator|!
name|CorrectionDecls
operator|.
name|empty
argument_list|()
operator|&&
name|CorrectionDecls
operator|.
name|front
argument_list|()
operator|==
literal|0
return|;
block|}
comment|// Returns true if the correction either is a keyword or has a known decl.
name|bool
name|isResolved
argument_list|()
specifier|const
block|{
return|return
operator|!
name|CorrectionDecls
operator|.
name|empty
argument_list|()
return|;
block|}
name|bool
name|isOverloaded
argument_list|()
specifier|const
block|{
return|return
name|CorrectionDecls
operator|.
name|size
argument_list|()
operator|>
literal|1
return|;
block|}
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|NamedDecl
operator|*
operator|,
literal|1
operator|>
operator|::
name|iterator
name|decl_iterator
expr_stmt|;
name|decl_iterator
name|begin
parameter_list|()
block|{
return|return
name|isKeyword
argument_list|()
condition|?
name|CorrectionDecls
operator|.
name|end
argument_list|()
else|:
name|CorrectionDecls
operator|.
name|begin
argument_list|()
return|;
block|}
name|decl_iterator
name|end
parameter_list|()
block|{
return|return
name|CorrectionDecls
operator|.
name|end
argument_list|()
return|;
block|}
name|private
label|:
name|bool
name|hasCorrectionDecl
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|!
name|isKeyword
argument_list|()
operator|&&
operator|!
name|CorrectionDecls
operator|.
name|empty
argument_list|()
operator|)
return|;
block|}
comment|// Results.
name|DeclarationName
name|CorrectionName
decl_stmt|;
name|NestedNameSpecifier
modifier|*
name|CorrectionNameSpec
decl_stmt|;
name|llvm
operator|::
name|SmallVector
operator|<
name|NamedDecl
operator|*
operator|,
literal|1
operator|>
name|CorrectionDecls
expr_stmt|;
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

