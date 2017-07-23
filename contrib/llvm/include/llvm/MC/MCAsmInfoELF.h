begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/MC/MCAsmInfoELF.h - ELF Asm info --------------------*- C++ -*-===//
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
name|LLVM_MC_MCASMINFOELF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCASMINFOELF_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmInfoELF
range|:
name|public
name|MCAsmInfo
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|MCSection
operator|*
name|getNonexecutableStackSection
argument_list|(
argument|MCContext&Ctx
argument_list|)
specifier|const
name|final
block|;
name|protected
operator|:
comment|/// Targets which have non-executable stacks by default can set this to false
comment|/// to disable the special section which requests a non-executable stack.
name|bool
name|UsesNonexecutableStackSection
operator|=
name|true
block|;
name|MCAsmInfoELF
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_MCASMINFOELF_H
end_comment

end_unit

