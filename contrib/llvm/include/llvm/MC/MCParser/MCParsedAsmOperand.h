begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCParsedAsmOperand.h - Asm Parser Operand -------*- C++ -*-===//
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
name|LLVM_MC_MCASMOPERAND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCASMOPERAND_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SMLoc
decl_stmt|;
comment|/// MCParsedAsmOperand - This abstract class represents a source-level assembly
comment|/// instruction operand.  It should be subclassed by target-specific code.  This
comment|/// base class is used by target-independent clients and is the interface
comment|/// between parsing an asm instruction and recognizing it.
name|class
name|MCParsedAsmOperand
block|{
name|public
label|:
name|MCParsedAsmOperand
argument_list|()
block|{}
name|virtual
operator|~
name|MCParsedAsmOperand
argument_list|()
block|{}
comment|/// getStartLoc - Get the location of the first token of this operand.
name|virtual
name|SMLoc
name|getStartLoc
argument_list|()
specifier|const
expr_stmt|;
comment|/// getEndLoc - Get the location of the last token of this operand.
name|virtual
name|SMLoc
name|getEndLoc
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

