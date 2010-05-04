begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ARMDisassembler.h - Disassembler for ARM/Thumb ISA -------*- C++ -*-===//
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
comment|// This file is part of the ARM Disassembler.
end_comment

begin_comment
comment|// It contains the header for ARMDisassembler and ThumbDisassembler, both are
end_comment

begin_comment
comment|// subclasses of MCDisassembler.
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
name|ARMDISASSEMBLER_H
end_ifndef

begin_define
define|#
directive|define
name|ARMDISASSEMBLER_H
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
struct_decl|struct
name|EDInstInfo
struct_decl|;
comment|/// ARMDisassembler - ARM disassembler for all ARM platforms.
name|class
name|ARMDisassembler
range|:
name|public
name|MCDisassembler
block|{
name|public
operator|:
comment|/// Constructor     - Initializes the disassembler.
comment|///
name|ARMDisassembler
argument_list|()
operator|:
name|MCDisassembler
argument_list|()
block|{   }
operator|~
name|ARMDisassembler
argument_list|()
block|{   }
comment|/// getInstruction - See MCDisassembler.
name|bool
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
argument_list|)
specifier|const
block|;
comment|/// getEDInfo - See MCDisassembler.
name|EDInstInfo
operator|*
name|getEDInfo
argument_list|()
specifier|const
block|;
name|private
operator|:
block|}
decl_stmt|;
comment|// Forward declaration.
name|class
name|ARMBasicMCBuilder
decl_stmt|;
comment|/// Session - Keep track of the IT Block progression.
name|class
name|Session
block|{
name|friend
name|class
name|ARMBasicMCBuilder
decl_stmt|;
name|public
label|:
name|Session
argument_list|()
operator|:
name|ITCounter
argument_list|(
literal|0
argument_list|)
operator|,
name|ITState
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|Session
argument_list|()
block|{}
comment|/// InitIT - Initializes ITCounter/ITState.
name|bool
name|InitIT
argument_list|(
argument|unsigned short bits7_0
argument_list|)
expr_stmt|;
comment|/// UpdateIT - Updates ITCounter/ITState as IT Block progresses.
name|void
name|UpdateIT
parameter_list|()
function_decl|;
name|private
label|:
name|unsigned
name|ITCounter
decl_stmt|;
comment|// Possible values: 0, 1, 2, 3, 4.
name|unsigned
name|ITState
decl_stmt|;
comment|// A2.5.2 Consists of IT[7:5] and IT[4:0] initially.
block|}
empty_stmt|;
comment|/// ThumbDisassembler - Thumb disassembler for all ARM platforms.
name|class
name|ThumbDisassembler
range|:
name|public
name|MCDisassembler
block|{
name|public
operator|:
comment|/// Constructor     - Initializes the disassembler.
comment|///
name|ThumbDisassembler
argument_list|()
operator|:
name|MCDisassembler
argument_list|()
block|,
name|SO
argument_list|()
block|{   }
operator|~
name|ThumbDisassembler
argument_list|()
block|{   }
comment|/// getInstruction - See MCDisassembler.
name|bool
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
argument_list|)
specifier|const
block|;
comment|/// getEDInfo - See MCDisassembler.
name|EDInstInfo
operator|*
name|getEDInfo
argument_list|()
specifier|const
block|;
name|private
operator|:
name|Session
name|SO
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

