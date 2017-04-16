begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DeclVendor.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_DeclVendor_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DeclVendor_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/ClangForward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// The Decl vendor class is intended as a generic interface to search
comment|// for named declarations that are not necessarily backed by a specific
comment|// symbol file.
comment|//----------------------------------------------------------------------
name|class
name|DeclVendor
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|DeclVendor
argument_list|()
block|{}
name|virtual
operator|~
name|DeclVendor
argument_list|()
block|{}
comment|//------------------------------------------------------------------
comment|/// Look up the set of Decls that the DeclVendor currently knows about
comment|/// matching a given name.
comment|///
comment|/// @param[in] name
comment|///     The name to look for.
comment|///
comment|/// @param[in] append
comment|///     If true, FindDecls will clear "decls" when it starts.
comment|///
comment|/// @param[in] max_matches
comment|///     The maximum number of Decls to return.  UINT32_MAX means "as
comment|///     many as possible."
comment|///
comment|/// @return
comment|///     The number of Decls added to decls; will not exceed
comment|///     max_matches.
comment|//------------------------------------------------------------------
name|virtual
name|uint32_t
name|FindDecls
argument_list|(
argument|const ConstString&name
argument_list|,
argument|bool append
argument_list|,
argument|uint32_t max_matches
argument_list|,
argument|std::vector<clang::NamedDecl *>&decls
argument_list|)
operator|=
literal|0
expr_stmt|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For DeclVendor only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|DeclVendor
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

