begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTFwd.h ----------------------------------------*- C++ -*-===//
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
comment|//===--------------------------------------------------------------===//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Forward declaration of all AST node types.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===-------------------------------------------------------------===//
end_comment

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Decl
decl_stmt|;
define|#
directive|define
name|DECL
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
value|class DERIVED##Decl;
include|#
directive|include
file|"clang/AST/DeclNodes.inc"
name|class
name|Stmt
decl_stmt|;
define|#
directive|define
name|STMT
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
value|class DERIVED;
include|#
directive|include
file|"clang/AST/StmtNodes.inc"
name|class
name|Type
decl_stmt|;
define|#
directive|define
name|TYPE
parameter_list|(
name|DERIVED
parameter_list|,
name|BASE
parameter_list|)
value|class DERIVED##Type;
include|#
directive|include
file|"clang/AST/TypeNodes.def"
name|class
name|CXXCtorInitializer
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

end_unit

