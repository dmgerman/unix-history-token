begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CodeGen/ModuleBuilder.h - Build LLVM from ASTs ---------*- C++ -*-===//
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
comment|//  This file defines the ModuleBuilder interface.
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
name|LLVM_CLANG_CODEGEN_MODULEBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CODEGEN_MODULEBUILDER_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTConsumer.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|CoverageSourceInfo
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|CodeGenOptions
decl_stmt|;
name|class
name|TargetOptions
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|CodeGenerator
range|:
name|public
name|ASTConsumer
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|virtual
name|llvm
operator|::
name|Module
operator|*
name|GetModule
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|llvm
operator|::
name|Module
operator|*
name|ReleaseModule
argument_list|()
operator|=
literal|0
block|;
name|virtual
specifier|const
name|Decl
operator|*
name|GetDeclForMangledName
argument_list|(
argument|llvm::StringRef MangledName
argument_list|)
operator|=
literal|0
block|;   }
decl_stmt|;
comment|/// CreateLLVMCodeGen - Create a CodeGenerator instance.
comment|/// It is the responsibility of the caller to call delete on
comment|/// the allocated CodeGenerator instance.
name|CodeGenerator
modifier|*
name|CreateLLVMCodeGen
argument_list|(
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|ModuleName
argument_list|,
specifier|const
name|CodeGenOptions
operator|&
name|CGO
argument_list|,
specifier|const
name|TargetOptions
operator|&
name|TO
argument_list|,
name|llvm
operator|::
name|LLVMContext
operator|&
name|C
argument_list|,
name|CoverageSourceInfo
operator|*
name|CoverageInfo
operator|=
name|nullptr
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

