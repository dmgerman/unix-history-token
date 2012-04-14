begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CXTranslationUnit.h - Routines for manipulating CXTranslationUnits -===//
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
comment|// This file defines routines for manipulating CXTranslationUnits.
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
name|LLVM_CLANG_CXTRANSLATIONUNIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CXTRANSLATIONUNIT_H
end_define

begin_extern
extern|extern
literal|"C"
block|{
struct|struct
name|CXTranslationUnitImpl
block|{
name|void
modifier|*
name|CIdx
decl_stmt|;
name|void
modifier|*
name|TUData
decl_stmt|;
name|void
modifier|*
name|StringPool
decl_stmt|;
name|void
modifier|*
name|Diagnostics
decl_stmt|;
block|}
struct|;
block|}
end_extern

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTUnit
decl_stmt|;
name|class
name|CIndexer
decl_stmt|;
name|namespace
name|cxtu
block|{
name|CXTranslationUnitImpl
modifier|*
name|MakeCXTranslationUnit
parameter_list|(
name|CIndexer
modifier|*
name|CIdx
parameter_list|,
name|ASTUnit
modifier|*
name|TU
parameter_list|)
function_decl|;
name|class
name|CXTUOwner
block|{
name|CXTranslationUnitImpl
modifier|*
name|TU
decl_stmt|;
name|public
label|:
name|CXTUOwner
argument_list|(
name|CXTranslationUnitImpl
operator|*
name|tu
argument_list|)
operator|:
name|TU
argument_list|(
argument|tu
argument_list|)
block|{ }
operator|~
name|CXTUOwner
argument_list|()
expr_stmt|;
name|CXTranslationUnitImpl
operator|*
name|getTU
argument_list|()
specifier|const
block|{
return|return
name|TU
return|;
block|}
name|CXTranslationUnitImpl
modifier|*
name|takeTU
parameter_list|()
block|{
name|CXTranslationUnitImpl
modifier|*
name|retTU
init|=
name|TU
decl_stmt|;
name|TU
operator|=
literal|0
expr_stmt|;
return|return
name|retTU
return|;
block|}
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang::cxtu
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

