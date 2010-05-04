begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SPUMachineFunctionInfo.h - Private data used for CellSPU --*- C++ -*-=//
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
comment|// This file declares the IBM Cell SPU specific subclass of MachineFunctionInfo.
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
name|SPU_MACHINE_FUNCTION_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|SPU_MACHINE_FUNCTION_INFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// SPUFunctionInfo - Cell SPU target-specific information for each
comment|/// MachineFunction
name|class
name|SPUFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
name|private
operator|:
comment|/// UsesLR - Indicates whether LR is used in the current function.
comment|///
name|bool
name|UsesLR
block|;
comment|// VarArgsFrameIndex - FrameIndex for start of varargs area.
name|int
name|VarArgsFrameIndex
block|;
name|public
operator|:
name|SPUFunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|:
name|UsesLR
argument_list|(
name|false
argument_list|)
block|,
name|VarArgsFrameIndex
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|setUsesLR
argument_list|(
argument|bool U
argument_list|)
block|{
name|UsesLR
operator|=
name|U
block|; }
name|bool
name|usesLR
argument_list|()
block|{
return|return
name|UsesLR
return|;
block|}
name|int
name|getVarArgsFrameIndex
argument_list|()
specifier|const
block|{
return|return
name|VarArgsFrameIndex
return|;
block|}
name|void
name|setVarArgsFrameIndex
argument_list|(
argument|int Index
argument_list|)
block|{
name|VarArgsFrameIndex
operator|=
name|Index
block|; }
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

