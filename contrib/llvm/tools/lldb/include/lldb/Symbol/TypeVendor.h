begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TypeVendor.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_TypeVendor_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_TypeVendor_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/ClangForward.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// The type vendor class is intended as a generic interface to search
comment|// for Clang types that are not necessarily backed by a specific symbol
comment|// file.
comment|//----------------------------------------------------------------------
name|class
name|TypeVendor
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|TypeVendor
argument_list|()
block|{     }
name|virtual
operator|~
name|TypeVendor
argument_list|()
block|{     }
name|virtual
name|uint32_t
name|FindTypes
argument_list|(
argument|const ConstString&name
argument_list|,
argument|bool append
argument_list|,
argument|uint32_t max_matches
argument_list|,
argument|std::vector<ClangASTType>&types
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|clang
operator|::
name|ASTContext
operator|*
name|GetClangASTContext
argument_list|()
operator|=
literal|0
expr_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from TypeVendor can see and modify these
comment|//------------------------------------------------------------------
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For TypeVendor only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TypeVendor
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

