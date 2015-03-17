begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Disassembler.h - Text File Disassembler ----------------------------===//
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
comment|// This class implements the disassembler of strings of bytes written in
end_comment

begin_comment
comment|// hexadecimal, from standard input or from a file.
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
name|LLVM_TOOLS_LLVM_MC_DISASSEMBLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVM_MC_DISASSEMBLER_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBuffer
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|SourceMgr
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|Disassembler
block|{
name|public
label|:
specifier|static
name|int
name|disassemble
argument_list|(
specifier|const
name|Target
operator|&
name|T
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Triple
argument_list|,
name|MCSubtargetInfo
operator|&
name|STI
argument_list|,
name|MCStreamer
operator|&
name|Streamer
argument_list|,
name|MemoryBuffer
operator|&
name|Buffer
argument_list|,
name|SourceMgr
operator|&
name|SM
argument_list|,
name|raw_ostream
operator|&
name|Out
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
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

