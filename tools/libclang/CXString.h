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
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|cxstring
block|{
struct_decl|struct
name|CXStringBuf
struct_decl|;
comment|/// \brief Create a CXString object for an empty "" string.
name|CXString
name|createEmpty
parameter_list|()
function_decl|;
comment|/// \brief Create a CXString object for an NULL string.
comment|///
comment|/// A NULL string should be used as an "invalid" value in case of errors.
name|CXString
name|createNull
parameter_list|()
function_decl|;
comment|/// \brief Create a CXString object from a nul-terminated C string.  New
comment|/// CXString may contain a pointer to \p String.
comment|///
comment|/// \p String should not be changed by the caller afterwards.
name|CXString
name|createRef
parameter_list|(
specifier|const
name|char
modifier|*
name|String
parameter_list|)
function_decl|;
comment|/// \brief Create a CXString object from a nul-terminated C string.  New
comment|/// CXString will contain a copy of \p String.
comment|///
comment|/// \p String can be changed or freed by the caller.
name|CXString
name|createDup
parameter_list|(
specifier|const
name|char
modifier|*
name|String
parameter_list|)
function_decl|;
comment|/// \brief Create a CXString object from a StringRef.  New CXString may
comment|/// contain a pointer to the undrelying data of \p String.
comment|///
comment|/// \p String should not be changed by the caller afterwards.
name|CXString
name|createRef
parameter_list|(
name|StringRef
name|String
parameter_list|)
function_decl|;
comment|/// \brief Create a CXString object from a StringRef.  New CXString will
comment|/// contain a copy of \p String.
comment|///
comment|/// \p String can be changed or freed by the caller.
name|CXString
name|createDup
parameter_list|(
name|StringRef
name|String
parameter_list|)
function_decl|;
comment|// Usually std::string is intended to be used as backing storage for CXString.
comment|// In this case, call \c createRef(String.c_str()).
comment|//
comment|// If you need to make a copy, call \c createDup(StringRef(String)).
name|CXString
name|createRef
argument_list|(
name|std
operator|::
name|string
name|String
argument_list|)
name|LLVM_DELETED_FUNCTION
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
comment|/// \brief A string pool used for fast allocation/deallocation of strings.
name|class
name|CXStringPool
block|{
name|public
label|:
operator|~
name|CXStringPool
argument_list|()
expr_stmt|;
name|CXStringBuf
modifier|*
name|getCXStringBuf
parameter_list|(
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
name|private
label|:
name|std
operator|::
name|vector
operator|<
name|CXStringBuf
operator|*
operator|>
name|Pool
expr_stmt|;
name|friend
struct_decl|struct
name|CXStringBuf
struct_decl|;
block|}
empty_stmt|;
struct|struct
name|CXStringBuf
block|{
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
argument|CXTranslationUnit TU
argument_list|)
block|:
name|TU
argument_list|(
argument|TU
argument_list|)
block|{}
comment|/// \brief Return this buffer to the pool.
name|void
name|dispose
parameter_list|()
function_decl|;
block|}
struct|;
name|CXStringBuf
modifier|*
name|getCXStringBuf
parameter_list|(
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Returns true if the CXString data is managed by a pool.
name|bool
name|isManagedByPool
parameter_list|(
name|CXString
name|str
parameter_list|)
function_decl|;
block|}
specifier|static
specifier|inline
name|StringRef
name|getContents
parameter_list|(
specifier|const
name|CXUnsavedFile
modifier|&
name|UF
parameter_list|)
block|{
return|return
name|StringRef
argument_list|(
name|UF
operator|.
name|Contents
argument_list|,
name|UF
operator|.
name|Length
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

