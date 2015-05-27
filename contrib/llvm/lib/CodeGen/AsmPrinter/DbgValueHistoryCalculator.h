begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/AsmPrinter/DbgValueHistoryCalculator.h ----*- C++ -*--===//
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
name|LLVM_LIB_CODEGEN_ASMPRINTER_DBGVALUEHISTORYCALCULATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_DBGVALUEHISTORYCALCULATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
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
name|MDNode
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
comment|// For each user variable, keep a list of instruction ranges where this variable
comment|// is accessible. The variables are listed in order of appearance.
name|class
name|DbgValueHistoryMap
block|{
comment|// Each instruction range starts with a DBG_VALUE instruction, specifying the
comment|// location of a variable, which is assumed to be valid until the end of the
comment|// range. If end is not specified, location is valid until the start
comment|// instruction of the next instruction range, or until the end of the
comment|// function.
name|public
label|:
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|MachineInstr
operator|*
operator|,
specifier|const
name|MachineInstr
operator|*
operator|>
name|InstrRange
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|InstrRange
operator|,
literal|4
operator|>
name|InstrRanges
expr_stmt|;
typedef|typedef
name|MapVector
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|InstrRanges
operator|>
name|InstrRangesMap
expr_stmt|;
name|private
label|:
name|InstrRangesMap
name|VarInstrRanges
decl_stmt|;
name|public
label|:
name|void
name|startInstrRange
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|Var
parameter_list|,
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
name|void
name|endInstrRange
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|Var
parameter_list|,
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
comment|// Returns register currently describing @Var. If @Var is currently
comment|// unaccessible or is not described by a register, returns 0.
name|unsigned
name|getRegisterForVar
argument_list|(
specifier|const
name|MDNode
operator|*
name|Var
argument_list|)
decl|const
decl_stmt|;
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|VarInstrRanges
operator|.
name|empty
argument_list|()
return|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|VarInstrRanges
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|InstrRangesMap
operator|::
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|VarInstrRanges
operator|.
name|begin
argument_list|()
return|;
block|}
name|InstrRangesMap
operator|::
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|VarInstrRanges
operator|.
name|end
argument_list|()
return|;
block|}
block|}
empty_stmt|;
name|void
name|calculateDbgValueHistory
parameter_list|(
specifier|const
name|MachineFunction
modifier|*
name|MF
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
parameter_list|,
name|DbgValueHistoryMap
modifier|&
name|Result
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

