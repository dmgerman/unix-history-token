begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangDiagnostic.h ---------------------------------------*- C++ -*-===//
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
name|lldb_ClangDiagnostic_h
end_ifndef

begin_define
define|#
directive|define
name|lldb_ClangDiagnostic_h
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/DiagnosticManager.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ClangDiagnostic
range|:
name|public
name|Diagnostic
block|{
name|public
operator|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|clang
operator|::
name|FixItHint
operator|>
name|FixItList
expr_stmt|;
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const ClangDiagnostic *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Diagnostic *diag
argument_list|)
block|{
return|return
name|diag
operator|->
name|getKind
argument_list|()
operator|==
name|eDiagnosticOriginClang
return|;
block|}
name|ClangDiagnostic
argument_list|(
argument|const char *message
argument_list|,
argument|DiagnosticSeverity severity
argument_list|,
argument|uint32_t compiler_id
argument_list|)
operator|:
name|Diagnostic
argument_list|(
argument|message
argument_list|,
argument|severity
argument_list|,
argument|eDiagnosticOriginClang
argument_list|,
argument|compiler_id
argument_list|)
block|{}
name|virtual
operator|~
name|ClangDiagnostic
argument_list|()
operator|=
expr|default
decl_stmt|;
name|bool
name|HasFixIts
argument_list|()
specifier|const
name|override
block|{
return|return
operator|!
name|m_fixit_vec
operator|.
name|empty
argument_list|()
return|;
block|}
name|void
name|AddFixitHint
argument_list|(
specifier|const
name|clang
operator|::
name|FixItHint
operator|&
name|fixit
argument_list|)
block|{
name|m_fixit_vec
operator|.
name|push_back
argument_list|(
name|fixit
argument_list|)
expr_stmt|;
block|}
specifier|const
name|FixItList
operator|&
name|FixIts
argument_list|()
specifier|const
block|{
return|return
name|m_fixit_vec
return|;
block|}
name|FixItList
name|m_fixit_vec
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lldb_ClangDiagnostic_h */
end_comment

end_unit

