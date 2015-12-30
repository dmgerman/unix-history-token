begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AArch64TargetStreamer.h - AArch64 Target Streamer ------*- C++ -*--===//
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
name|LLVM_LIB_TARGET_AARCH64_MCTARGETDESC_AARCH64TARGETSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AARCH64_MCTARGETDESC_AARCH64TARGETSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AArch64TargetStreamer
range|:
name|public
name|MCTargetStreamer
block|{
name|public
operator|:
name|AArch64TargetStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|)
block|;
operator|~
name|AArch64TargetStreamer
argument_list|()
name|override
block|;
name|void
name|finish
argument_list|()
name|override
block|;
comment|/// Callback used to implement the ldr= pseudo.
comment|/// Add a new entry to the constant pool for the current section and return an
comment|/// MCExpr that can be used to refer to the constant pool location.
specifier|const
name|MCExpr
operator|*
name|addConstantPoolEntry
argument_list|(
argument|const MCExpr *
argument_list|,
argument|unsigned Size
argument_list|,
argument|SMLoc Loc
argument_list|)
block|;
comment|/// Callback used to implemnt the .ltorg directive.
comment|/// Emit contents of constant pool for the current section.
name|void
name|emitCurrentConstantPool
argument_list|()
block|;
comment|/// Callback used to implement the .inst directive.
name|virtual
name|void
name|emitInst
argument_list|(
argument|uint32_t Inst
argument_list|)
block|;
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|AssemblerConstantPools
operator|>
name|ConstantPools
block|; }
decl_stmt|;
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

