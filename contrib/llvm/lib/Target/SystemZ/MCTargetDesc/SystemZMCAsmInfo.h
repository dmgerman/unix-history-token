begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//====-- SystemZMCAsmInfo.h - SystemZ asm properties -----------*- C++ -*--===//
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
name|SystemZTARGETASMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|SystemZTARGETASMINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmInfoELF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|class
name|SystemZMCAsmInfo
range|:
name|public
name|MCAsmInfoELF
block|{
name|public
operator|:
name|explicit
name|SystemZMCAsmInfo
argument_list|(
argument|StringRef TT
argument_list|)
block|;
comment|// Override MCAsmInfo;
name|virtual
specifier|const
name|MCSection
operator|*
name|getNonexecutableStackSection
argument_list|(
argument|MCContext&Ctx
argument_list|)
specifier|const
name|LLVM_OVERRIDE
block|; }
decl_stmt|;
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

