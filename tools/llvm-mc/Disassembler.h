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
name|DISASSEMBLER_H
end_ifndef

begin_define
define|#
directive|define
name|DISASSEMBLER_H
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
name|Target
decl_stmt|;
name|class
name|MemoryBuffer
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
name|target
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|tripleString
argument_list|,
name|MemoryBuffer
operator|&
name|buffer
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

