begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FastISelEmitter.h - Generate an instruction selector -----*- C++ -*-===//
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
comment|// This tablegen backend emits a "fast" instruction selector.
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
name|FASTISEL_EMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|FASTISEL_EMITTER_H
end_define

begin_include
include|#
directive|include
file|"CodeGenDAGPatterns.h"
end_include

begin_include
include|#
directive|include
file|"llvm/TableGen/TableGenBackend.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CodeGenTarget
decl_stmt|;
comment|/// FastISelEmitter - The top-level class which coordinates construction
comment|/// and emission of the instruction selector.
comment|///
name|class
name|FastISelEmitter
range|:
name|public
name|TableGenBackend
block|{
name|RecordKeeper
operator|&
name|Records
block|;
name|CodeGenDAGPatterns
name|CGP
block|;
name|public
operator|:
name|explicit
name|FastISelEmitter
argument_list|(
name|RecordKeeper
operator|&
name|R
argument_list|)
block|;
comment|// run - Output the isel, returning true on failure.
name|void
name|run
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|; }
decl_stmt|;
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

