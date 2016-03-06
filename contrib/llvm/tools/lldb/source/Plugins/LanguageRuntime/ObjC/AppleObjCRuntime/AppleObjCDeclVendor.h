begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AppleObjCDeclVendor.h -----------------------------------*- C++ -*-===//
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
name|liblldb_AppleObjCDeclVendor_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_AppleObjCDeclVendor_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/ClangASTContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/DeclVendor.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ObjCLanguageRuntime.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|AppleObjCExternalASTSource
decl_stmt|;
name|class
name|AppleObjCDeclVendor
range|:
name|public
name|DeclVendor
block|{
name|public
operator|:
name|AppleObjCDeclVendor
argument_list|(
name|ObjCLanguageRuntime
operator|&
name|runtime
argument_list|)
block|;
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
name|override
block|;
name|friend
name|class
name|AppleObjCExternalASTSource
block|;
name|private
operator|:
name|clang
operator|::
name|ObjCInterfaceDecl
operator|*
name|GetDeclForISA
argument_list|(
argument|ObjCLanguageRuntime::ObjCISA isa
argument_list|)
block|;
name|bool
name|FinishDecl
argument_list|(
name|clang
operator|::
name|ObjCInterfaceDecl
operator|*
name|decl
argument_list|)
block|;
name|ObjCLanguageRuntime
operator|&
name|m_runtime
block|;
name|ClangASTContext
name|m_ast_ctx
block|;
name|ObjCLanguageRuntime
operator|::
name|EncodingToTypeSP
name|m_type_realizer_sp
block|;
name|AppleObjCExternalASTSource
operator|*
name|m_external_source
block|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|ObjCLanguageRuntime
operator|::
name|ObjCISA
operator|,
name|clang
operator|::
name|ObjCInterfaceDecl
operator|*
operator|>
name|ISAToInterfaceMap
expr_stmt|;
name|ISAToInterfaceMap
name|m_isa_to_interface
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
comment|// liblldb_AppleObjCDeclVendor_h_
end_comment

end_unit

