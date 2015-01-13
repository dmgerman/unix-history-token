begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- BackendUtil.h - LLVM Backend Utilities -----------------*- C++ -*-===//
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
name|LLVM_CLANG_CODEGEN_BACKEND_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CODEGEN_BACKEND_UTIL_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
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
name|CodeGenOptions
decl_stmt|;
name|class
name|TargetOptions
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
enum|enum
name|BackendAction
block|{
name|Backend_EmitAssembly
block|,
comment|///< Emit native assembly files
name|Backend_EmitBC
block|,
comment|///< Emit LLVM bitcode files
name|Backend_EmitLL
block|,
comment|///< Emit human-readable LLVM assembly
name|Backend_EmitNothing
block|,
comment|///< Don't emit anything (benchmarking mode)
name|Backend_EmitMCNull
block|,
comment|///< Run CodeGen, but don't emit anything
name|Backend_EmitObj
comment|///< Emit native object files
block|}
enum|;
name|void
name|EmitBackendOutput
argument_list|(
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|,
specifier|const
name|CodeGenOptions
operator|&
name|CGOpts
argument_list|,
specifier|const
name|TargetOptions
operator|&
name|TOpts
argument_list|,
specifier|const
name|LangOptions
operator|&
name|LOpts
argument_list|,
name|StringRef
name|TDesc
argument_list|,
name|llvm
operator|::
name|Module
operator|*
name|M
argument_list|,
name|BackendAction
name|Action
argument_list|,
name|raw_ostream
operator|*
name|OS
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

