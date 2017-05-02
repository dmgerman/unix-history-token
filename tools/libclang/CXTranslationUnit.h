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
name|LLVM_CLANG_TOOLS_LIBCLANG_CXTRANSLATIONUNIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLS_LIBCLANG_CXTRANSLATIONUNIT_H
end_define

begin_include
include|#
directive|include
file|"CLog.h"
end_include

begin_include
include|#
directive|include
file|"CXString.h"
end_include

begin_include
include|#
directive|include
file|"clang-c/Index.h"
end_include

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
name|index
block|{
name|class
name|CommentToXMLConverter
decl_stmt|;
block|}
comment|// namespace index
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_struct
struct|struct
name|CXTranslationUnitImpl
block|{
name|clang
operator|::
name|CIndexer
operator|*
name|CIdx
expr_stmt|;
name|clang
operator|::
name|ASTUnit
operator|*
name|TheASTUnit
expr_stmt|;
name|clang
operator|::
name|cxstring
operator|::
name|CXStringPool
operator|*
name|StringPool
expr_stmt|;
name|void
modifier|*
name|Diagnostics
decl_stmt|;
name|void
modifier|*
name|OverridenCursorsPool
decl_stmt|;
name|clang
operator|::
name|index
operator|::
name|CommentToXMLConverter
operator|*
name|CommentToXML
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|CXTargetInfoImpl
block|{
name|CXTranslationUnit
name|TranslationUnit
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|cxtu
block|{
name|CXTranslationUnitImpl
modifier|*
name|MakeCXTranslationUnit
argument_list|(
name|CIndexer
operator|*
name|CIdx
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|ASTUnit
operator|>
name|AU
argument_list|)
decl_stmt|;
specifier|static
specifier|inline
name|ASTUnit
modifier|*
name|getASTUnit
parameter_list|(
name|CXTranslationUnit
name|TU
parameter_list|)
block|{
if|if
condition|(
operator|!
name|TU
condition|)
return|return
name|nullptr
return|;
return|return
name|TU
operator|->
name|TheASTUnit
return|;
block|}
comment|/// \returns true if the ASTUnit has a diagnostic about the AST file being
comment|/// corrupted.
name|bool
name|isASTReadError
parameter_list|(
name|ASTUnit
modifier|*
name|AU
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|bool
name|isNotUsableTU
parameter_list|(
name|CXTranslationUnit
name|TU
parameter_list|)
block|{
return|return
operator|!
name|TU
return|;
block|}
define|#
directive|define
name|LOG_BAD_TU
parameter_list|(
name|TU
parameter_list|)
define|\
value|do {                                                \       LOG_FUNC_SECTION {                                \         *Log<< "called with a bad TU: "<< TU;         \       }                                                 \     } while(false)
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
name|nullptr
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

