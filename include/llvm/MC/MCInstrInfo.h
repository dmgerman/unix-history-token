begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCInstrInfo.h - Target Instruction Info ---------*- C++ -*-===//
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
comment|// This file describes the target machine instruction set.
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
name|LLVM_MC_MCINSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCINSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrDesc.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//---------------------------------------------------------------------------
comment|///
comment|/// MCInstrInfo - Interface to description of machine instruction set
comment|///
name|class
name|MCInstrInfo
block|{
specifier|const
name|MCInstrDesc
modifier|*
name|Desc
decl_stmt|;
comment|// Raw array to allow static init'n
name|unsigned
name|NumOpcodes
decl_stmt|;
comment|// Number of entries in the desc array
name|public
label|:
comment|/// InitMCInstrInfo - Initialize MCInstrInfo, called by TableGen
comment|/// auto-generated routines. *DO NOT USE*.
name|void
name|InitMCInstrInfo
parameter_list|(
specifier|const
name|MCInstrDesc
modifier|*
name|D
parameter_list|,
name|unsigned
name|NO
parameter_list|)
block|{
name|Desc
operator|=
name|D
expr_stmt|;
name|NumOpcodes
operator|=
name|NO
expr_stmt|;
block|}
name|unsigned
name|getNumOpcodes
argument_list|()
specifier|const
block|{
return|return
name|NumOpcodes
return|;
block|}
comment|/// get - Return the machine instruction descriptor that corresponds to the
comment|/// specified instruction opcode.
comment|///
specifier|const
name|MCInstrDesc
modifier|&
name|get
argument_list|(
name|unsigned
name|Opcode
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Opcode
operator|<
name|NumOpcodes
operator|&&
literal|"Invalid opcode!"
argument_list|)
expr_stmt|;
return|return
name|Desc
index|[
name|Opcode
index|]
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

