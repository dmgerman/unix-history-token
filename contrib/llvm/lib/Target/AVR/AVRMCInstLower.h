begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AVRMCInstLower.h - Lower MachineInstr to MCInst ---------*- C++ -*-===//
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
name|LLVM_AVR_MCINST_LOWER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AVR_MCINST_LOWER_H
end_define

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
name|AsmPrinter
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineOperand
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|MCOperand
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
comment|/// Lowers `MachineInstr` objects into `MCInst` objects.
name|class
name|AVRMCInstLower
block|{
name|public
label|:
name|AVRMCInstLower
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|,
name|AsmPrinter
operator|&
name|Printer
argument_list|)
operator|:
name|Ctx
argument_list|(
name|Ctx
argument_list|)
operator|,
name|Printer
argument_list|(
argument|Printer
argument_list|)
block|{}
comment|/// Lowers a `MachineInstr` into a `MCInst`.
name|void
name|lowerInstruction
argument_list|(
argument|const MachineInstr&MI
argument_list|,
argument|MCInst&OutMI
argument_list|)
specifier|const
expr_stmt|;
name|MCOperand
name|lowerSymbolOperand
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|,
name|MCSymbol
operator|*
name|Sym
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|MCContext
modifier|&
name|Ctx
decl_stmt|;
name|AsmPrinter
modifier|&
name|Printer
decl_stmt|;
block|}
empty_stmt|;
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
comment|// LLVM_AVR_MCINST_LOWER_H
end_comment

end_unit

