begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- CGOpenCLRuntime.h - Interface to OpenCL Runtimes -----*- C++ -*-===//
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
comment|// This provides an abstract class for OpenCL code generation.  Concrete
end_comment

begin_comment
comment|// subclasses of this implement code generation for specific OpenCL
end_comment

begin_comment
comment|// runtime libraries.
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
name|LLVM_CLANG_LIB_CODEGEN_CGOPENCLRUNTIME_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_CGOPENCLRUNTIME_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|VarDecl
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenFunction
decl_stmt|;
name|class
name|CodeGenModule
decl_stmt|;
name|class
name|CGOpenCLRuntime
block|{
name|protected
label|:
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
name|public
label|:
name|CGOpenCLRuntime
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|)
operator|:
name|CGM
argument_list|(
argument|CGM
argument_list|)
block|{}
name|virtual
operator|~
name|CGOpenCLRuntime
argument_list|()
expr_stmt|;
comment|/// Emit the IR required for a work-group-local variable declaration, and add
comment|/// an entry to CGF's LocalDeclMap for D.  The base class does this using
comment|/// CodeGenFunction::EmitStaticVarDecl to emit an internal global for D.
name|virtual
name|void
name|EmitWorkGroupLocalVarDecl
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|VarDecl
modifier|&
name|D
parameter_list|)
function_decl|;
name|virtual
name|llvm
operator|::
name|Type
operator|*
name|convertOpenCLSpecificType
argument_list|(
specifier|const
name|Type
operator|*
name|T
argument_list|)
expr_stmt|;
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

