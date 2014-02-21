begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsAnalyzeImmediate.h - Analyze Immediates ------------*- C++ -*--===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_ANALYZE_IMMEDIATE_H
end_ifndef

begin_define
define|#
directive|define
name|MIPS_ANALYZE_IMMEDIATE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
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
name|MipsAnalyzeImmediate
block|{
name|public
label|:
struct|struct
name|Inst
block|{
name|unsigned
name|Opc
decl_stmt|,
name|ImmOpnd
decl_stmt|;
name|Inst
argument_list|(
argument|unsigned Opc
argument_list|,
argument|unsigned ImmOpnd
argument_list|)
empty_stmt|;
block|}
struct|;
typedef|typedef
name|SmallVector
operator|<
name|Inst
operator|,
literal|7
operator|>
name|InstSeq
expr_stmt|;
comment|/// Analyze - Get an instruction sequence to load immediate Imm. The last
comment|/// instruction in the sequence must be an ADDiu if LastInstrIsADDiu is
comment|/// true;
specifier|const
name|InstSeq
modifier|&
name|Analyze
parameter_list|(
name|uint64_t
name|Imm
parameter_list|,
name|unsigned
name|Size
parameter_list|,
name|bool
name|LastInstrIsADDiu
parameter_list|)
function_decl|;
name|private
label|:
typedef|typedef
name|SmallVector
operator|<
name|InstSeq
operator|,
literal|5
operator|>
name|InstSeqLs
expr_stmt|;
comment|/// AddInstr - Add I to all instruction sequences in SeqLs.
name|void
name|AddInstr
parameter_list|(
name|InstSeqLs
modifier|&
name|SeqLs
parameter_list|,
specifier|const
name|Inst
modifier|&
name|I
parameter_list|)
function_decl|;
comment|/// GetInstSeqLsADDiu - Get instruction sequences which end with an ADDiu to
comment|/// load immediate Imm
name|void
name|GetInstSeqLsADDiu
parameter_list|(
name|uint64_t
name|Imm
parameter_list|,
name|unsigned
name|RemSize
parameter_list|,
name|InstSeqLs
modifier|&
name|SeqLs
parameter_list|)
function_decl|;
comment|/// GetInstSeqLsORi - Get instrutcion sequences which end with an ORi to
comment|/// load immediate Imm
name|void
name|GetInstSeqLsORi
parameter_list|(
name|uint64_t
name|Imm
parameter_list|,
name|unsigned
name|RemSize
parameter_list|,
name|InstSeqLs
modifier|&
name|SeqLs
parameter_list|)
function_decl|;
comment|/// GetInstSeqLsSLL - Get instruction sequences which end with a SLL to
comment|/// load immediate Imm
name|void
name|GetInstSeqLsSLL
parameter_list|(
name|uint64_t
name|Imm
parameter_list|,
name|unsigned
name|RemSize
parameter_list|,
name|InstSeqLs
modifier|&
name|SeqLs
parameter_list|)
function_decl|;
comment|/// GetInstSeqLs - Get instruction sequences to load immediate Imm.
name|void
name|GetInstSeqLs
parameter_list|(
name|uint64_t
name|Imm
parameter_list|,
name|unsigned
name|RemSize
parameter_list|,
name|InstSeqLs
modifier|&
name|SeqLs
parameter_list|)
function_decl|;
comment|/// ReplaceADDiuSLLWithLUi - Replace an ADDiu& SLL pair with a LUi.
name|void
name|ReplaceADDiuSLLWithLUi
parameter_list|(
name|InstSeq
modifier|&
name|Seq
parameter_list|)
function_decl|;
comment|/// GetShortestSeq - Find the shortest instruction sequence in SeqLs and
comment|/// return it in Insts.
name|void
name|GetShortestSeq
parameter_list|(
name|InstSeqLs
modifier|&
name|SeqLs
parameter_list|,
name|InstSeq
modifier|&
name|Insts
parameter_list|)
function_decl|;
name|unsigned
name|Size
decl_stmt|;
name|unsigned
name|ADDiu
decl_stmt|,
name|ORi
decl_stmt|,
name|SLL
decl_stmt|,
name|LUi
decl_stmt|;
name|InstSeq
name|Insts
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

