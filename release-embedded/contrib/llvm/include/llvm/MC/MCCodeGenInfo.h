begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCCodeGenInfo.h - Target CodeGen Info -----------*- C++ -*-===//
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
comment|// This file tracks information about the target which can affect codegen,
end_comment

begin_comment
comment|// asm parsing, and asm printing. For example, relocation model.
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
name|LLVM_MC_MCCODEGENINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCCODEGENINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCCodeGenInfo
block|{
comment|/// RelocationModel - Relocation model: static, pic, etc.
comment|///
name|Reloc
operator|::
name|Model
name|RelocationModel
expr_stmt|;
comment|/// CMModel - Code model.
comment|///
name|CodeModel
operator|::
name|Model
name|CMModel
expr_stmt|;
comment|/// OptLevel - Optimization level.
comment|///
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
expr_stmt|;
name|public
label|:
name|void
name|InitMCCodeGenInfo
argument_list|(
name|Reloc
operator|::
name|Model
name|RM
operator|=
name|Reloc
operator|::
name|Default
argument_list|,
name|CodeModel
operator|::
name|Model
name|CM
operator|=
name|CodeModel
operator|::
name|Default
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OL
operator|=
name|CodeGenOpt
operator|::
name|Default
argument_list|)
decl_stmt|;
name|Reloc
operator|::
name|Model
name|getRelocationModel
argument_list|()
specifier|const
block|{
return|return
name|RelocationModel
return|;
block|}
name|CodeModel
operator|::
name|Model
name|getCodeModel
argument_list|()
specifier|const
block|{
return|return
name|CMModel
return|;
block|}
name|CodeGenOpt
operator|::
name|Level
name|getOptLevel
argument_list|()
specifier|const
block|{
return|return
name|OptLevel
return|;
block|}
comment|// Allow overriding OptLevel on a per-function basis.
name|void
name|setOptLevel
argument_list|(
name|CodeGenOpt
operator|::
name|Level
name|Level
argument_list|)
block|{
name|OptLevel
operator|=
name|Level
expr_stmt|;
block|}
block|}
empty_stmt|;
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

