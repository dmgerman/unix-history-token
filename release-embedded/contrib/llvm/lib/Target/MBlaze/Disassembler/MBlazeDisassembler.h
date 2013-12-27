begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MBlazeDisassembler.h - Disassembler for MicroBlaze  -----*- C++ -*-===//
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
comment|// This file is part of the MBlaze Disassembler. It it the header for
end_comment

begin_comment
comment|// MBlazeDisassembler, a subclass of MCDisassembler.
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
name|MBLAZEDISASSEMBLER_H
end_ifndef

begin_define
define|#
directive|define
name|MBLAZEDISASSEMBLER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCDisassembler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCInst
decl_stmt|;
name|class
name|MemoryObject
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// MBlazeDisassembler - Disassembler for all MBlaze platforms.
name|class
name|MBlazeDisassembler
range|:
name|public
name|MCDisassembler
block|{
name|public
operator|:
comment|/// Constructor     - Initializes the disassembler.
comment|///
name|MBlazeDisassembler
argument_list|(
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
argument_list|)
operator|:
name|MCDisassembler
argument_list|(
argument|STI
argument_list|)
block|{   }
operator|~
name|MBlazeDisassembler
argument_list|()
block|{   }
comment|/// getInstruction - See MCDisassembler.
name|MCDisassembler
operator|::
name|DecodeStatus
name|getInstruction
argument_list|(
argument|MCInst&instr
argument_list|,
argument|uint64_t&size
argument_list|,
argument|const MemoryObject&region
argument_list|,
argument|uint64_t address
argument_list|,
argument|raw_ostream&vStream
argument_list|,
argument|raw_ostream&cStream
argument_list|)
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

