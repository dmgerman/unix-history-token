begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUAsmUtils.h - AsmParser/InstPrinter common ---------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_AMDGPU_UTILS_AMDGPUASMUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_UTILS_AMDGPUASMUTILS_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|AMDGPU
block|{
name|namespace
name|SendMsg
block|{
comment|// Symbolic names for the sendmsg(...) syntax.
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|IdSymbolic
index|[]
decl_stmt|;
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|OpSysSymbolic
index|[]
decl_stmt|;
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|OpGsSymbolic
index|[]
decl_stmt|;
block|}
comment|// namespace SendMsg
name|namespace
name|Hwreg
block|{
comment|// Symbolic names for the hwreg(...) syntax.
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|IdSymbolic
index|[]
decl_stmt|;
block|}
comment|// namespace Hwreg
name|namespace
name|Swizzle
block|{
comment|// Symbolic names for the swizzle(...) syntax.
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|IdSymbolic
index|[]
decl_stmt|;
block|}
comment|// namespace Swizzle
block|}
comment|// namespace AMDGPU
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

