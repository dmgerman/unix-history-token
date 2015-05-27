begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMAsmBackendWinCOFF.h - ARM Asm Backend WinCOFF --------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_ARM_ARMASMBACKENDWINCOFF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_ARMASMBACKENDWINCOFF_H
end_define

begin_decl_stmt
name|using
name|namespace
name|llvm
decl_stmt|;
end_decl_stmt

begin_macro
name|namespace
end_macro

begin_block
block|{
name|class
name|ARMAsmBackendWinCOFF
range|:
name|public
name|ARMAsmBackend
block|{
name|public
operator|:
name|ARMAsmBackendWinCOFF
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef Triple
argument_list|)
operator|:
name|ARMAsmBackend
argument_list|(
argument|T
argument_list|,
argument|Triple
argument_list|,
argument|true
argument_list|)
block|{}
name|MCObjectWriter
operator|*
name|createObjectWriter
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
name|override
block|{
return|return
name|createARMWinCOFFObjectWriter
argument_list|(
name|OS
argument_list|,
comment|/*Is64Bit=*/
name|false
argument_list|)
return|;
block|}
expr|}
block|; }
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

