begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LanaiDisassembler.cpp - Disassembler for Lanai -----------*- C++ -*-===//
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
comment|// This file is part of the Lanai Disassembler.
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
name|LLVM_LIB_TARGET_LANAI_DISASSEMBLER_LANAIDISASSEMBLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_LANAI_DISASSEMBLER_LANAIDISASSEMBLER_H
end_define

begin_define
define|#
directive|define
name|DEBUG_TYPE
value|"lanai-disassembler"
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCDisassembler/MCDisassembler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LanaiDisassembler
range|:
name|public
name|MCDisassembler
block|{
name|public
operator|:
name|LanaiDisassembler
argument_list|(
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
argument_list|,
name|MCContext
operator|&
name|Ctx
argument_list|)
block|;
operator|~
name|LanaiDisassembler
argument_list|()
name|override
operator|=
expr|default
block|;
comment|// getInstruction - See MCDisassembler.
name|MCDisassembler
operator|::
name|DecodeStatus
name|getInstruction
argument_list|(
argument|MCInst&Instr
argument_list|,
argument|uint64_t&Size
argument_list|,
argument|ArrayRef<uint8_t> Bytes
argument_list|,
argument|uint64_t Address
argument_list|,
argument|raw_ostream&VStream
argument_list|,
argument|raw_ostream&CStream
argument_list|)
specifier|const
name|override
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

begin_comment
comment|// LLVM_LIB_TARGET_LANAI_DISASSEMBLER_LANAIDISASSEMBLER_H
end_comment

end_unit

