begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FileWriters.h - File Writers Creation Functions ---------*- C++ -*-===//
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
comment|// Functions to add the various file writer passes.
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
name|LLVM_CODEGEN_FILEWRITERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_FILEWRITERS_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PassManagerBase
decl_stmt|;
name|class
name|ObjectCodeEmitter
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|ObjectCodeEmitter
modifier|*
name|AddELFWriter
parameter_list|(
name|PassManagerBase
modifier|&
name|FPM
parameter_list|,
name|raw_ostream
modifier|&
name|O
parameter_list|,
name|TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|ObjectCodeEmitter
modifier|*
name|AddMachOWriter
parameter_list|(
name|PassManagerBase
modifier|&
name|FPM
parameter_list|,
name|raw_ostream
modifier|&
name|O
parameter_list|,
name|TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_FILEWRITERS_H
end_comment

end_unit

