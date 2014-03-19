begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangNamespaceDecl.h ------------------------------------*- C++ -*-===//
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
name|liblldb_ClangNamespaceDecl_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ClangNamespaceDecl_h_
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ClangForward.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ClangNamespaceDecl
block|{
name|public
label|:
name|ClangNamespaceDecl
argument_list|()
operator|:
name|m_ast
argument_list|(
name|NULL
argument_list|)
operator|,
name|m_namespace_decl
argument_list|(
argument|NULL
argument_list|)
block|{     }
name|ClangNamespaceDecl
argument_list|(
name|clang
operator|::
name|ASTContext
operator|*
name|ast
argument_list|,
name|clang
operator|::
name|NamespaceDecl
operator|*
name|namespace_decl
argument_list|)
operator|:
name|m_ast
argument_list|(
name|ast
argument_list|)
operator|,
name|m_namespace_decl
argument_list|(
argument|namespace_decl
argument_list|)
block|{     }
name|ClangNamespaceDecl
argument_list|(
specifier|const
name|ClangNamespaceDecl
operator|&
name|rhs
argument_list|)
operator|:
name|m_ast
argument_list|(
name|rhs
operator|.
name|m_ast
argument_list|)
operator|,
name|m_namespace_decl
argument_list|(
argument|rhs.m_namespace_decl
argument_list|)
block|{     }
specifier|const
name|ClangNamespaceDecl
operator|&
name|operator
operator|=
operator|(
specifier|const
name|ClangNamespaceDecl
operator|&
name|rhs
operator|)
block|{
name|m_ast
operator|=
name|rhs
operator|.
name|m_ast
block|;
name|m_namespace_decl
operator|=
name|rhs
operator|.
name|m_namespace_decl
block|;
return|return
operator|*
name|this
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Convert to bool operator.
comment|///
comment|/// This allows code to check a ClangNamespaceDecl object to see if
comment|/// it contains a valid namespace decl using code such as:
comment|///
comment|/// @code
comment|/// ClangNamespaceDecl ns_decl(...);
comment|/// if (ns_decl)
comment|/// { ...
comment|/// @endcode
comment|///
comment|/// @return
comment|///     /b True this object contains a valid namespace decl, \b
comment|///     false otherwise.
comment|//------------------------------------------------------------------
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|m_ast
operator|!=
name|NULL
operator|&&
name|m_namespace_decl
operator|!=
name|NULL
return|;
block|}
name|clang
operator|::
name|ASTContext
operator|*
name|GetASTContext
argument_list|()
specifier|const
block|{
return|return
name|m_ast
return|;
block|}
name|void
name|SetASTContext
argument_list|(
name|clang
operator|::
name|ASTContext
operator|*
name|ast
argument_list|)
block|{
name|m_ast
operator|=
name|ast
expr_stmt|;
block|}
name|clang
operator|::
name|NamespaceDecl
operator|*
name|GetNamespaceDecl
argument_list|()
specifier|const
block|{
return|return
name|m_namespace_decl
return|;
block|}
name|void
name|SetNamespaceDecl
argument_list|(
name|clang
operator|::
name|NamespaceDecl
operator|*
name|namespace_decl
argument_list|)
block|{
name|m_namespace_decl
operator|=
name|namespace_decl
expr_stmt|;
block|}
name|std
operator|::
name|string
name|GetQualifiedName
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|clang
operator|::
name|ASTContext
operator|*
name|m_ast
expr_stmt|;
name|clang
operator|::
name|NamespaceDecl
operator|*
name|m_namespace_decl
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

begin_comment
comment|// #ifndef liblldb_ClangNamespaceDecl_h_
end_comment

end_unit

