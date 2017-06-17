begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/TableGen/Main.h - tblgen entry point ----------------*- C++ -*-===//
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
comment|// This file declares the common entry point for tblgen tools.
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
name|LLVM_TABLEGEN_MAIN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TABLEGEN_MAIN_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|RecordKeeper
decl_stmt|;
comment|/// \brief Perform the action using Records, and write output to OS.
comment|/// \returns true on error, false otherwise
name|using
name|TableGenMainFn
init|=
name|bool
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|RecordKeeper
operator|&
name|Records
argument_list|)
decl_stmt|;
name|int
name|TableGenMain
parameter_list|(
name|char
modifier|*
name|argv0
parameter_list|,
name|TableGenMainFn
modifier|*
name|MainFn
parameter_list|)
function_decl|;
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
comment|// LLVM_TABLEGEN_MAIN_H
end_comment

end_unit

