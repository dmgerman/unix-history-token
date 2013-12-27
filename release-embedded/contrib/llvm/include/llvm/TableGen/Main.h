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
name|RecordKeeper
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// \brief Perform the action using Records, and write output to OS.
comment|/// \returns true on error, false otherwise
typedef|typedef
name|bool
name|TableGenMainFn
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|RecordKeeper
modifier|&
name|Records
parameter_list|)
function_decl|;
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

