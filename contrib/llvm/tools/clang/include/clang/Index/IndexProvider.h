begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- IndexProvider.h - Maps information to translation units -*- C++ -*-==//
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
comment|//  Maps information to TranslationUnits.
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
name|LLVM_CLANG_INDEX_INDEXPROVIDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_INDEXPROVIDER_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|idx
block|{
name|class
name|Entity
decl_stmt|;
name|class
name|TranslationUnitHandler
decl_stmt|;
name|class
name|GlobalSelector
decl_stmt|;
comment|/// \brief Maps information to TranslationUnits.
name|class
name|IndexProvider
block|{
name|public
label|:
name|virtual
operator|~
name|IndexProvider
argument_list|()
expr_stmt|;
name|virtual
name|void
name|GetTranslationUnitsFor
parameter_list|(
name|Entity
name|Ent
parameter_list|,
name|TranslationUnitHandler
modifier|&
name|Handler
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|GetTranslationUnitsFor
parameter_list|(
name|GlobalSelector
name|Sel
parameter_list|,
name|TranslationUnitHandler
modifier|&
name|Handler
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
comment|// namespace idx
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

