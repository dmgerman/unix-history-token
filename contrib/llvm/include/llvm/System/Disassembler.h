begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/Disassembler.h ------------------------------*- C++ -*-===//
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
comment|// This file implements the necessary glue to call external disassembler
end_comment

begin_comment
comment|// libraries.
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
name|LLVM_SYSTEM_DISASSEMBLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEM_DISASSEMBLER_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|/// This function returns true, if there is possible to use some external
comment|/// disassembler library. False otherwise.
name|bool
name|hasDisassembler
parameter_list|()
function_decl|;
comment|/// This function provides some "glue" code to call external disassembler
comment|/// libraries.
name|std
operator|::
name|string
name|disassembleBuffer
argument_list|(
argument|uint8_t* start
argument_list|,
argument|size_t length
argument_list|,
argument|uint64_t pc =
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SYSTEM_DISASSEMBLER_H
end_comment

end_unit

