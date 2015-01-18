begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CXSourceLocation.h - CXSourceLocations Utilities ---------*- C++ -*-===//
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
comment|// This file defines routines for manipulating CXSourceLocations.
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
name|LLVM_CLANG_TOOLS_LIBCLANG_CXSOURCELOCATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLS_LIBCLANG_CXSOURCELOCATION_H
end_define

begin_include
include|#
directive|include
file|"clang-c/Index.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|SourceManager
decl_stmt|;
name|namespace
name|cxloc
block|{
comment|/// \brief Translate a Clang source location into a CIndex source location.
specifier|static
specifier|inline
name|CXSourceLocation
name|translateSourceLocation
parameter_list|(
specifier|const
name|SourceManager
modifier|&
name|SM
parameter_list|,
specifier|const
name|LangOptions
modifier|&
name|LangOpts
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
block|{
if|if
condition|(
name|Loc
operator|.
name|isInvalid
argument_list|()
condition|)
name|clang_getNullLocation
argument_list|()
expr_stmt|;
name|CXSourceLocation
name|Result
init|=
block|{
block|{
operator|&
name|SM
block|,
operator|&
name|LangOpts
block|, }
block|,
name|Loc
operator|.
name|getRawEncoding
argument_list|()
block|}
decl_stmt|;
return|return
name|Result
return|;
block|}
comment|/// \brief Translate a Clang source location into a CIndex source location.
specifier|static
specifier|inline
name|CXSourceLocation
name|translateSourceLocation
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
block|{
return|return
name|translateSourceLocation
argument_list|(
name|Context
operator|.
name|getSourceManager
argument_list|()
argument_list|,
name|Context
operator|.
name|getLangOpts
argument_list|()
argument_list|,
name|Loc
argument_list|)
return|;
block|}
comment|/// \brief Translate a Clang source range into a CIndex source range.
comment|///
comment|/// Clang internally represents ranges where the end location points to the
comment|/// start of the token at the end. However, for external clients it is more
comment|/// useful to have a CXSourceRange be a proper half-open interval. This routine
comment|/// does the appropriate translation.
name|CXSourceRange
name|translateSourceRange
parameter_list|(
specifier|const
name|SourceManager
modifier|&
name|SM
parameter_list|,
specifier|const
name|LangOptions
modifier|&
name|LangOpts
parameter_list|,
specifier|const
name|CharSourceRange
modifier|&
name|R
parameter_list|)
function_decl|;
comment|/// \brief Translate a Clang source range into a CIndex source range.
specifier|static
specifier|inline
name|CXSourceRange
name|translateSourceRange
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|SourceRange
name|R
parameter_list|)
block|{
return|return
name|translateSourceRange
argument_list|(
name|Context
operator|.
name|getSourceManager
argument_list|()
argument_list|,
name|Context
operator|.
name|getLangOpts
argument_list|()
argument_list|,
name|CharSourceRange
operator|::
name|getTokenRange
argument_list|(
name|R
argument_list|)
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|SourceLocation
name|translateSourceLocation
parameter_list|(
name|CXSourceLocation
name|L
parameter_list|)
block|{
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|L
operator|.
name|int_data
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|SourceRange
name|translateCXSourceRange
parameter_list|(
name|CXSourceRange
name|R
parameter_list|)
block|{
return|return
name|SourceRange
argument_list|(
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|R
operator|.
name|begin_int_data
argument_list|)
argument_list|,
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|R
operator|.
name|end_int_data
argument_list|)
argument_list|)
return|;
block|}
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace: clang::cxloc
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

