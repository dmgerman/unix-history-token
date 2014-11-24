begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- X86AsmInstrumentation.h - Instrument X86 inline assembly *- C++ -*-===//
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
name|X86_ASM_INSTRUMENTATION_H
end_ifndef

begin_define
define|#
directive|define
name|X86_ASM_INSTRUMENTATION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|MCInstrInfo
decl_stmt|;
name|class
name|MCParsedAsmOperand
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|MCTargetOptions
decl_stmt|;
name|class
name|X86AsmInstrumentation
decl_stmt|;
name|X86AsmInstrumentation
modifier|*
name|CreateX86AsmInstrumentation
parameter_list|(
specifier|const
name|MCTargetOptions
modifier|&
name|MCOptions
parameter_list|,
specifier|const
name|MCContext
modifier|&
name|Ctx
parameter_list|,
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|)
function_decl|;
name|class
name|X86AsmInstrumentation
block|{
name|public
label|:
name|virtual
operator|~
name|X86AsmInstrumentation
argument_list|()
expr_stmt|;
comment|// Instruments Inst. Should be called just before the original
comment|// instruction is sent to Out.
name|virtual
name|void
name|InstrumentInstruction
argument_list|(
specifier|const
name|MCInst
operator|&
name|Inst
argument_list|,
name|SmallVectorImpl
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MCParsedAsmOperand
operator|>>
operator|&
name|Operands
argument_list|,
name|MCContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|MCInstrInfo
operator|&
name|MII
argument_list|,
name|MCStreamer
operator|&
name|Out
argument_list|)
decl_stmt|;
name|protected
label|:
name|friend
name|X86AsmInstrumentation
modifier|*
name|CreateX86AsmInstrumentation
parameter_list|(
specifier|const
name|MCTargetOptions
modifier|&
name|MCOptions
parameter_list|,
specifier|const
name|MCContext
modifier|&
name|Ctx
parameter_list|,
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|)
function_decl|;
name|X86AsmInstrumentation
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// X86_ASM_INSTRUMENTATION_H
end_comment

end_unit

