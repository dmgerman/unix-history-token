begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BPFMCInstLower.h - Lower MachineInstr to MCInst ---------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_BPF_BPFMCINSTLOWER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_BPF_BPFMCINSTLOWER_H
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
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineModuleInfoMachO
decl_stmt|;
name|class
name|MachineOperand
decl_stmt|;
name|class
name|Mangler
decl_stmt|;
comment|// BPFMCInstLower - This class is used to lower an MachineInstr into an MCInst.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|BPFMCInstLower
block|{
name|MCContext
modifier|&
name|Ctx
decl_stmt|;
name|AsmPrinter
modifier|&
name|Printer
decl_stmt|;
name|public
label|:
name|BPFMCInstLower
argument_list|(
name|MCContext
operator|&
name|ctx
argument_list|,
name|AsmPrinter
operator|&
name|printer
argument_list|)
operator|:
name|Ctx
argument_list|(
name|ctx
argument_list|)
operator|,
name|Printer
argument_list|(
argument|printer
argument_list|)
block|{}
name|void
name|Lower
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|MCInst&OutMI
argument_list|)
specifier|const
expr_stmt|;
name|MCOperand
name|LowerSymbolOperand
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
name|MCSymbol
modifier|*
name|GetGlobalAddressSymbol
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|)
decl|const
decl_stmt|;
name|MCSymbol
modifier|*
name|GetExternalSymbolSymbol
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

