begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- WebAssemblyMCInstLower.h - Lower MachineInstr to MCInst -*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file declares the class to lower WebAssembly MachineInstrs to
end_comment

begin_comment
comment|/// their corresponding MCInst records.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYMCINSTLOWER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYMCINSTLOWER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCInst.h"
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
name|WebAssemblyAsmPrinter
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineOperand
decl_stmt|;
comment|/// This class is used to lower an MachineInstr into an MCInst.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|WebAssemblyMCInstLower
block|{
name|MCContext
modifier|&
name|Ctx
decl_stmt|;
name|WebAssemblyAsmPrinter
modifier|&
name|Printer
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
name|MCOperand
name|LowerSymbolOperand
argument_list|(
name|MCSymbol
operator|*
name|Sym
argument_list|,
name|int64_t
name|Offset
argument_list|,
name|bool
name|IsFunc
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
name|WebAssemblyMCInstLower
argument_list|(
name|MCContext
operator|&
name|ctx
argument_list|,
name|WebAssemblyAsmPrinter
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

end_unit

