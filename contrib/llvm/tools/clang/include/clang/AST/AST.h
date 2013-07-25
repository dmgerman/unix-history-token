begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- AST.h - "Umbrella" header for AST library --------------*- C++ -*-===//
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
comment|//  This file defines the interface to the AST classes.
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
name|LLVM_CLANG_AST_AST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_AST_H
end_define

begin_comment
comment|// This header exports all AST interfaces.
end_comment

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclTemplate.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExprObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/StmtVisitor.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

