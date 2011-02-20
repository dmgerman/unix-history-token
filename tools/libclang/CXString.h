begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CXString.h - Routines for manipulating CXStrings -------------------===//
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
comment|// This file defines routines for manipulating CXStrings.
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
name|LLVM_CLANG_CXSTRING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CXSTRING_H
end_define

begin_include
include|#
directive|include
file|"clang-c/Index.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|cxstring
block|{
struct|struct
name|CXStringBuf
block|{
name|llvm
operator|::
name|SmallString
operator|<
literal|128
operator|>
name|Data
expr_stmt|;
name|CXTranslationUnit
name|TU
decl_stmt|;
name|CXStringBuf
argument_list|(
argument|CXTranslationUnit tu
argument_list|)
block|:
name|TU
argument_list|(
argument|tu
argument_list|)
block|{}
block|}
struct|;
comment|/// \brief Create a CXString object from a C string.
name|CXString
name|createCXString
parameter_list|(
specifier|const
name|char
modifier|*
name|String
parameter_list|,
name|bool
name|DupString
init|=
name|false
parameter_list|)
function_decl|;
comment|/// \brief Create a CXString object from a StringRef.
name|CXString
name|createCXString
argument_list|(
name|llvm
operator|::
name|StringRef
name|String
argument_list|,
name|bool
name|DupString
operator|=
name|true
argument_list|)
decl_stmt|;
comment|/// \brief Create a CXString object that is backed by a string buffer.
name|CXString
name|createCXString
parameter_list|(
name|CXStringBuf
modifier|*
name|buf
parameter_list|)
function_decl|;
comment|/// \brief Create an opaque string pool used for fast geneneration of strings.
name|void
modifier|*
name|createCXStringPool
parameter_list|()
function_decl|;
comment|/// \brief Dispose of a string pool.
name|void
name|disposeCXStringPool
parameter_list|(
name|void
modifier|*
name|pool
parameter_list|)
function_decl|;
name|CXStringBuf
modifier|*
name|getCXStringBuf
parameter_list|(
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
name|void
name|disposeCXStringBuf
parameter_list|(
name|CXStringBuf
modifier|*
name|buf
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

