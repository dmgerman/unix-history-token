begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- XCoreMCInstLower.h - Lower MachineInstr to MCInst ------*- C++ -*--===//
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
name|LLVM_LIB_TARGET_XCORE_XCOREMCINSTLOWER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_XCORE_XCOREMCINSTLOWER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineOperand.h"
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
name|MCContext
decl_stmt|;
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
name|MachineFunction
decl_stmt|;
name|class
name|Mangler
decl_stmt|;
name|class
name|AsmPrinter
decl_stmt|;
comment|/// \brief This class is used to lower an MachineInstr into an MCInst.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|XCoreMCInstLower
block|{
typedef|typedef
name|MachineOperand
operator|::
name|MachineOperandType
name|MachineOperandType
expr_stmt|;
name|MCContext
modifier|*
name|Ctx
decl_stmt|;
name|Mangler
modifier|*
name|Mang
decl_stmt|;
name|AsmPrinter
modifier|&
name|Printer
decl_stmt|;
name|public
label|:
name|XCoreMCInstLower
argument_list|(
argument|class AsmPrinter&asmprinter
argument_list|)
empty_stmt|;
name|void
name|Initialize
parameter_list|(
name|Mangler
modifier|*
name|mang
parameter_list|,
name|MCContext
modifier|*
name|C
parameter_list|)
function_decl|;
name|void
name|Lower
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
name|MCOperand
name|LowerOperand
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|,
name|unsigned
name|offset
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|MCOperand
name|LowerSymbolOperand
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|,
name|MachineOperandType
name|MOTy
argument_list|,
name|unsigned
name|Offset
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

