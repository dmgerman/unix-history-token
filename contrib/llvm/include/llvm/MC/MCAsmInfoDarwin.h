begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCAsmInfoDarwin.h - Darwin asm properties ----------------*- C++ -*-===//
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
comment|// This file defines target asm properties related what form asm statements
end_comment

begin_comment
comment|// should take in general on Darwin-based targets
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
name|LLVM_MC_MCASMINFODARWIN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCASMINFODARWIN_H
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
name|MCAsmInfoDarwin
range|:
name|public
name|MCAsmInfo
block|{
name|public
operator|:
name|explicit
name|MCAsmInfoDarwin
argument_list|()
block|;
name|bool
name|isSectionAtomizableBySymbols
argument_list|(
argument|const MCSection&Section
argument_list|)
specifier|const
name|override
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
comment|// LLVM_MC_MCASMINFODARWIN_H
end_comment

end_unit

