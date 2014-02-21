begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUAsmPrinter.h - Print AMDGPU assembly code ---------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief AMDGPU Assembly printer class.
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
name|AMDGPU_ASMPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|AMDGPU_ASMPRINTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AMDGPUAsmPrinter
range|:
name|public
name|AsmPrinter
block|{
name|public
operator|:
name|explicit
name|AMDGPUAsmPrinter
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|,
name|MCStreamer
operator|&
name|Streamer
argument_list|)
block|;
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|virtual
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
literal|"AMDGPU Assembly Printer"
return|;
block|}
comment|/// \brief Emit register usage information so that the GPU driver
comment|/// can correctly setup the GPU state.
name|void
name|EmitProgramInfoR600
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|void
name|EmitProgramInfoSI
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
comment|/// Implemented in AMDGPUMCInstLower.cpp
name|virtual
name|void
name|EmitInstruction
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
name|protected
operator|:
name|bool
name|DisasmEnabled
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|DisasmLines
block|,
name|HexLines
block|;
name|size_t
name|DisasmLineMaxLen
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End anonymous llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//AMDGPU_ASMPRINTER_H
end_comment

end_unit

