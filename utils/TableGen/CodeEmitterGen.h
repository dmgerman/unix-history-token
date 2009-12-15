begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CodeEmitterGen.h - Code Emitter Generator ----------------*- C++ -*-===//
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
comment|// FIXME: document
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
name|CODEMITTERGEN_H
end_ifndef

begin_define
define|#
directive|define
name|CODEMITTERGEN_H
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
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|RecordVal
decl_stmt|;
name|class
name|BitsInit
decl_stmt|;
struct_decl|struct
name|Init
struct_decl|;
name|class
name|CodeEmitterGen
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
name|CodeEmitterGen
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
name|void
name|emitMachineOpEmitter
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Namespace
argument_list|)
block|;
name|void
name|emitGetValueBit
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Namespace
argument_list|)
block|;
name|void
name|reverseBits
argument_list|(
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
operator|&
name|Insts
argument_list|)
block|;
name|int
name|getVariableBit
argument_list|(
argument|const Init *VarVal
argument_list|,
argument|BitsInit *BI
argument_list|,
argument|int bit
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

