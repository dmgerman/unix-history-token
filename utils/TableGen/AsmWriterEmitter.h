begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AsmWriterEmitter.h - Generate an assembly writer ---------*- C++ -*-===//
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
comment|// This tablegen backend is responsible for emitting an assembly printer for the
end_comment

begin_comment
comment|// code generator.
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
name|ASMWRITER_EMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|ASMWRITER_EMITTER_H
end_define

begin_include
include|#
directive|include
file|"TableGenBackend.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmWriterInst
decl_stmt|;
name|class
name|CodeGenInstruction
decl_stmt|;
name|class
name|AsmWriterEmitter
range|:
name|public
name|TableGenBackend
block|{
name|RecordKeeper
operator|&
name|Records
block|;
name|std
operator|::
name|map
operator|<
specifier|const
name|CodeGenInstruction
operator|*
block|,
name|AsmWriterInst
operator|*
operator|>
name|CGIAWIMap
block|;
name|std
operator|::
name|vector
operator|<
specifier|const
name|CodeGenInstruction
operator|*
operator|>
name|NumberedInstructions
block|;
name|public
operator|:
name|AsmWriterEmitter
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
block|{}
comment|// run - Output the asmwriter, returning true on failure.
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
name|void
name|EmitPrintInstruction
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|)
block|;
name|void
name|EmitGetRegisterName
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|)
block|;
name|AsmWriterInst
operator|*
name|getAsmWriterInstByID
argument_list|(
argument|unsigned ID
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|ID
operator|<
name|NumberedInstructions
operator|.
name|size
argument_list|()
argument_list|)
block|;
name|std
operator|::
name|map
operator|<
specifier|const
name|CodeGenInstruction
operator|*
block|,
name|AsmWriterInst
operator|*
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|CGIAWIMap
operator|.
name|find
argument_list|(
name|NumberedInstructions
index|[
name|ID
index|]
argument_list|)
block|;
name|assert
argument_list|(
name|I
operator|!=
name|CGIAWIMap
operator|.
name|end
argument_list|()
operator|&&
literal|"Didn't find inst!"
argument_list|)
block|;
return|return
name|I
operator|->
name|second
return|;
block|}
name|void
name|FindUniqueOperandCommands
argument_list|(
argument|std::vector<std::string>&UOC
argument_list|,
argument|std::vector<unsigned>&InstIdxs
argument_list|,
argument|std::vector<unsigned>&InstOpsUsed
argument_list|)
specifier|const
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

