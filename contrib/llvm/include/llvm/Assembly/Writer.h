begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Assembly/Writer.h - Printer for LLVM assembly files --*- C++ -*-=//
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
comment|// This functionality is implemented by lib/VMCore/AsmWriter.cpp.
end_comment

begin_comment
comment|// This library is used to print LLVM assembly language files to an iostream. It
end_comment

begin_comment
comment|// can print LLVM code at a variety of granularities, including Modules,
end_comment

begin_comment
comment|// BasicBlocks, and Instructions.  This makes it useful for debugging.
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
name|LLVM_ASSEMBLY_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ASSEMBLY_WRITER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|// WriteAsOperand - Write the name of the specified value out to the specified
comment|// ostream.  This can be useful when you just want to print int %reg126, not the
comment|// whole instruction that generated it.  If you specify a Module for context,
comment|// then even constants get pretty-printed; for example, the type of a null
comment|// pointer is printed symbolically.
comment|//
name|void
name|WriteAsOperand
parameter_list|(
name|raw_ostream
modifier|&
parameter_list|,
specifier|const
name|Value
modifier|*
parameter_list|,
name|bool
name|PrintTy
init|=
name|true
parameter_list|,
specifier|const
name|Module
modifier|*
name|Context
init|=
literal|0
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

