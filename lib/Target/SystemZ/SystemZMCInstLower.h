begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemZMCInstLower.h - Lower MachineInstr to MCInst ----*- C++ -*--===//
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
name|LLVM_SYSTEMZMCINSTLOWER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEMZMCINSTLOWER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCExpr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
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
name|MCInst
decl_stmt|;
name|class
name|MCOperand
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineOperand
decl_stmt|;
name|class
name|Mangler
decl_stmt|;
name|class
name|SystemZAsmPrinter
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|SystemZMCInstLower
block|{
name|MCContext
modifier|&
name|Ctx
decl_stmt|;
name|SystemZAsmPrinter
modifier|&
name|AsmPrinter
decl_stmt|;
name|public
label|:
name|SystemZMCInstLower
argument_list|(
name|MCContext
operator|&
name|ctx
argument_list|,
name|SystemZAsmPrinter
operator|&
name|asmPrinter
argument_list|)
expr_stmt|;
comment|// Lower MachineInstr MI to MCInst OutMI.
name|void
name|lower
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|MCInst
operator|&
name|OutMI
argument_list|)
decl|const
decl_stmt|;
comment|// Return an MCOperand for MO.
name|MCOperand
name|lowerOperand
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|)
decl|const
decl_stmt|;
comment|// Return an MCExpr for symbolic operand MO with variant kind Kind.
specifier|const
name|MCExpr
modifier|*
name|getExpr
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|,
name|MCSymbolRefExpr
operator|::
name|VariantKind
name|Kind
argument_list|)
decl|const
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

end_unit

