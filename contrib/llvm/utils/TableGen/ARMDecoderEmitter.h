begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------------ ARMDecoderEmitter.h - Decoder Generator -------*- C++ -*-===//
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
comment|// It contains the tablegen backend declaration ARMDecoderEmitter.
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
name|ARMDECODEREMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|ARMDECODEREMITTER_H
end_define

begin_include
include|#
directive|include
file|"TableGenBackend.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMDecoderEmitter
range|:
name|public
name|TableGenBackend
block|{
name|RecordKeeper
operator|&
name|Records
block|;
name|public
operator|:
name|ARMDecoderEmitter
argument_list|(
name|RecordKeeper
operator|&
name|R
argument_list|)
operator|:
name|Records
argument_list|(
argument|R
argument_list|)
block|{
name|initBackend
argument_list|()
block|;   }
operator|~
name|ARMDecoderEmitter
argument_list|()
block|{
name|shutdownBackend
argument_list|()
block|;   }
comment|// run - Output the code emitter
name|void
name|run
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|)
block|;
name|private
operator|:
comment|// Helper class for ARMDecoderEmitter.
name|class
name|ARMDEBackend
block|;
name|ARMDEBackend
operator|*
name|Backend
block|;
name|void
name|initBackend
argument_list|()
block|;
name|void
name|shutdownBackend
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

