begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ASTDumper.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_ASTDumper_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ASTDumper_h_
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclVisitor.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TypeVisitor.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Stream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ASTDumper
block|{
name|public
label|:
name|ASTDumper
argument_list|(
name|clang
operator|::
name|Decl
operator|*
name|decl
argument_list|)
expr_stmt|;
name|ASTDumper
argument_list|(
name|clang
operator|::
name|DeclContext
operator|*
name|decl_ctx
argument_list|)
expr_stmt|;
name|ASTDumper
argument_list|(
specifier|const
name|clang
operator|::
name|Type
operator|*
name|type
argument_list|)
expr_stmt|;
name|ASTDumper
argument_list|(
argument|clang::QualType type
argument_list|)
empty_stmt|;
name|ASTDumper
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
empty_stmt|;
name|ASTDumper
argument_list|(
specifier|const
name|CompilerType
operator|&
name|compiler_type
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|GetCString
parameter_list|()
function_decl|;
name|void
name|ToSTDERR
parameter_list|()
function_decl|;
name|void
name|ToLog
parameter_list|(
name|Log
modifier|*
name|log
parameter_list|,
specifier|const
name|char
modifier|*
name|prefix
parameter_list|)
function_decl|;
name|void
name|ToStream
argument_list|(
name|lldb
operator|::
name|StreamSP
operator|&
name|stream
argument_list|)
decl_stmt|;
name|private
label|:
name|std
operator|::
name|string
name|m_dump
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

