begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- VarBypassDetector.cpp - Bypass jumps detector ------------*- C++ -*-=//
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
comment|// This file contains VarBypassDetector class, which is used to detect
end_comment

begin_comment
comment|// local variable declarations which can be bypassed by jumps.
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
name|LLVM_CLANG_LIB_CODEGEN_VARBYPASSDETECTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_VARBYPASSDETECTOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Decl
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
name|namespace
name|CodeGen
block|{
comment|/// The class detects jumps which bypass local variables declaration:
comment|///    goto L;
comment|///    int a;
comment|///  L:
comment|///
comment|/// This is simplified version of JumpScopeChecker. Primary differences:
comment|///  * Detects only jumps into the scope local variables.
comment|///  * Does not detect jumps out of the scope of local variables.
comment|///  * Not limited to variables with initializers, JumpScopeChecker is limited.
name|class
name|VarBypassDetector
block|{
comment|// Scope information. Contains a parent scope and related variable
comment|// declaration.
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
specifier|const
name|VarDecl
operator|*
operator|>
operator|,
literal|48
operator|>
name|Scopes
expr_stmt|;
comment|// List of jumps with scopes.
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|Stmt
operator|*
operator|,
name|unsigned
operator|>
operator|,
literal|16
operator|>
name|FromScopes
expr_stmt|;
comment|// Lookup map to find scope for destinations.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Stmt
operator|*
operator|,
name|unsigned
operator|>
name|ToScopes
expr_stmt|;
comment|// Set of variables which were bypassed by some jump.
name|llvm
operator|::
name|DenseSet
operator|<
specifier|const
name|VarDecl
operator|*
operator|>
name|Bypasses
expr_stmt|;
comment|// If true assume that all variables are being bypassed.
name|bool
name|AlwaysBypassed
init|=
name|false
decl_stmt|;
name|public
label|:
name|void
name|Init
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|Body
parameter_list|)
function_decl|;
comment|/// Returns true if the variable declaration was by bypassed by any goto or
comment|/// switch statement.
name|bool
name|IsBypassed
argument_list|(
specifier|const
name|VarDecl
operator|*
name|D
argument_list|)
decl|const
block|{
return|return
name|AlwaysBypassed
operator|||
name|Bypasses
operator|.
name|find
argument_list|(
name|D
argument_list|)
operator|!=
name|Bypasses
operator|.
name|end
argument_list|()
return|;
block|}
name|private
label|:
name|bool
name|BuildScopeInformation
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|,
name|unsigned
modifier|&
name|ParentScope
parameter_list|)
function_decl|;
name|bool
name|BuildScopeInformation
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|,
name|unsigned
modifier|&
name|origParentScope
parameter_list|)
function_decl|;
name|void
name|Detect
parameter_list|()
function_decl|;
name|void
name|Detect
parameter_list|(
name|unsigned
name|From
parameter_list|,
name|unsigned
name|To
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

