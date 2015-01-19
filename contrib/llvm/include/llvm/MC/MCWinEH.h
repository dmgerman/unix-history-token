begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCWinEH.h - Windows Unwinding Support --------------------*- C++ -*-===//
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
name|LLVM_MC_MCWINEH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCWINEH_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSymbol
decl_stmt|;
name|namespace
name|WinEH
block|{
struct|struct
name|Instruction
block|{
specifier|const
name|MCSymbol
modifier|*
name|Label
decl_stmt|;
specifier|const
name|unsigned
name|Offset
decl_stmt|;
specifier|const
name|unsigned
name|Register
decl_stmt|;
specifier|const
name|unsigned
name|Operation
decl_stmt|;
name|Instruction
argument_list|(
argument|unsigned Op
argument_list|,
argument|MCSymbol *L
argument_list|,
argument|unsigned Reg
argument_list|,
argument|unsigned Off
argument_list|)
block|:
name|Label
argument_list|(
name|L
argument_list|)
operator|,
name|Offset
argument_list|(
name|Off
argument_list|)
operator|,
name|Register
argument_list|(
name|Reg
argument_list|)
operator|,
name|Operation
argument_list|(
argument|Op
argument_list|)
block|{}
block|}
struct|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

