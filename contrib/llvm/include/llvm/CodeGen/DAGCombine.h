begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/DAGCombine.h  ------- SelectionDAG Nodes ---*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_DAGCOMBINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_DAGCOMBINE_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
enum|enum
name|CombineLevel
block|{
name|BeforeLegalizeTypes
block|,
name|AfterLegalizeTypes
block|,
name|AfterLegalizeVectorOps
block|,
name|AfterLegalizeDAG
block|}
enum|;
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

