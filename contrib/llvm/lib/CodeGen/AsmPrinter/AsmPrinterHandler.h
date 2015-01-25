begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/CodeGen/AsmPrinter/AsmPrinterHandler.h -------------*- C++ -*--===//
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
comment|// This file contains a generic interface for AsmPrinter handlers,
end_comment

begin_comment
comment|// like debug and EH info emitters.
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
name|LLVM_LIB_CODEGEN_ASMPRINTER_ASMPRINTERHANDLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_ASMPRINTERHANDLER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
comment|/// \brief Collects and handles AsmPrinter objects required to build debug
comment|/// or EH information.
name|class
name|AsmPrinterHandler
block|{
name|public
label|:
name|virtual
operator|~
name|AsmPrinterHandler
argument_list|()
expr_stmt|;
comment|/// \brief For symbols that have a size designated (e.g. common symbols),
comment|/// this tracks that size.
name|virtual
name|void
name|setSymbolSize
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Sym
parameter_list|,
name|uint64_t
name|Size
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Emit all sections that should come after the content.
name|virtual
name|void
name|endModule
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// \brief Gather pre-function debug information.
comment|/// Every beginFunction(MF) call should be followed by an endFunction(MF)
comment|/// call.
name|virtual
name|void
name|beginFunction
parameter_list|(
specifier|const
name|MachineFunction
modifier|*
name|MF
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Gather post-function debug information.
comment|/// Please note that some AsmPrinter implementations may not call
comment|/// beginFunction at all.
name|virtual
name|void
name|endFunction
parameter_list|(
specifier|const
name|MachineFunction
modifier|*
name|MF
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Process beginning of an instruction.
name|virtual
name|void
name|beginInstruction
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Process end of an instruction.
name|virtual
name|void
name|endInstruction
parameter_list|()
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

