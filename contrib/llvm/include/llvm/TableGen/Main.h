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
name|TableGenAction
decl_stmt|;
comment|/// Run the table generator, performing the specified Action on parsed records.
name|int
name|TableGenMain
parameter_list|(
name|char
modifier|*
name|argv0
parameter_list|,
name|TableGenAction
modifier|&
name|Action
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

