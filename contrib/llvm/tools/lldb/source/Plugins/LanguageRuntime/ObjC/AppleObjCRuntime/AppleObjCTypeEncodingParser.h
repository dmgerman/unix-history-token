begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AppleObjCTypeEncodingParser.h ---------------------------*- C++ -*-===//
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
name|liblldb_AppleObjCTypeEncodingParser_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_AppleObjCTypeEncodingParser_h_
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

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

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
file|"lldb/Target/ObjCLanguageRuntime.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_utility
block|{
name|class
name|StringLexer
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|AppleObjCTypeEncodingParser
range|:
name|public
name|ObjCLanguageRuntime
operator|::
name|EncodingToType
block|{
name|public
operator|:
name|AppleObjCTypeEncodingParser
argument_list|(
name|ObjCLanguageRuntime
operator|&
name|runtime
argument_list|)
block|;
operator|~
name|AppleObjCTypeEncodingParser
argument_list|()
name|override
operator|=
expr|default
block|;
name|CompilerType
name|RealizeType
argument_list|(
argument|clang::ASTContext&ast_ctx
argument_list|,
argument|const char* name
argument_list|,
argument|bool for_expression
argument_list|)
name|override
block|;
name|private
operator|:
expr|struct
name|StructElement
block|{
name|std
operator|::
name|string
name|name
block|;
name|clang
operator|::
name|QualType
name|type
block|;
name|uint32_t
name|bitfield
block|;
name|StructElement
argument_list|()
block|;
operator|~
name|StructElement
argument_list|()
operator|=
expr|default
block|;         }
block|;
name|clang
operator|::
name|QualType
name|BuildType
argument_list|(
argument|clang::ASTContext&ast_ctx
argument_list|,
argument|lldb_utility::StringLexer& type
argument_list|,
argument|bool for_expression
argument_list|,
argument|uint32_t *bitfield_bit_size = nullptr
argument_list|)
block|;
name|clang
operator|::
name|QualType
name|BuildStruct
argument_list|(
argument|clang::ASTContext&ast_ctx
argument_list|,
argument|lldb_utility::StringLexer& type
argument_list|,
argument|bool for_expression
argument_list|)
block|;
name|clang
operator|::
name|QualType
name|BuildAggregate
argument_list|(
argument|clang::ASTContext&ast_ctx
argument_list|,
argument|lldb_utility::StringLexer& type
argument_list|,
argument|bool for_expression
argument_list|,
argument|char opener
argument_list|,
argument|char closer
argument_list|,
argument|uint32_t kind
argument_list|)
block|;
name|clang
operator|::
name|QualType
name|BuildUnion
argument_list|(
argument|clang::ASTContext&ast_ctx
argument_list|,
argument|lldb_utility::StringLexer& type
argument_list|,
argument|bool for_expression
argument_list|)
block|;
name|clang
operator|::
name|QualType
name|BuildArray
argument_list|(
argument|clang::ASTContext&ast_ctx
argument_list|,
argument|lldb_utility::StringLexer& type
argument_list|,
argument|bool for_expression
argument_list|)
block|;
name|std
operator|::
name|string
name|ReadStructName
argument_list|(
name|lldb_utility
operator|::
name|StringLexer
operator|&
name|type
argument_list|)
block|;
name|StructElement
name|ReadStructElement
argument_list|(
argument|clang::ASTContext&ast_ctx
argument_list|,
argument|lldb_utility::StringLexer& type
argument_list|,
argument|bool for_expression
argument_list|)
block|;
name|clang
operator|::
name|QualType
name|BuildObjCObjectPointerType
argument_list|(
argument|clang::ASTContext&ast_ctx
argument_list|,
argument|lldb_utility::StringLexer& type
argument_list|,
argument|bool for_expression
argument_list|)
block|;
name|uint32_t
name|ReadNumber
argument_list|(
name|lldb_utility
operator|::
name|StringLexer
operator|&
name|type
argument_list|)
block|;
name|std
operator|::
name|string
name|ReadQuotedString
argument_list|(
name|lldb_utility
operator|::
name|StringLexer
operator|&
name|type
argument_list|)
block|;
name|ObjCLanguageRuntime
operator|&
name|m_runtime
block|;     }
decl_stmt|;
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
comment|// liblldb_AppleObjCTypeEncodingParser_h_
end_comment

end_unit

