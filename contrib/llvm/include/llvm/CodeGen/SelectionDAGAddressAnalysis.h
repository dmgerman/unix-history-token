begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/SelectionDAGAddressAnalysis.h  ------- DAG Address Analysis
end_comment

begin_comment
comment|//---*- C++ -*-===//
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
name|LLVM_CODEGEN_SELECTIONDAGADDRESSANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SELECTIONDAGADDRESSANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/ISDOpcodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGNodes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Helper struct to parse and store a memory address as base + index + offset.
comment|/// We ignore sign extensions when it is safe to do so.
comment|/// The following two expressions are not equivalent. To differentiate we need
comment|/// to store whether there was a sign extension involved in the index
comment|/// computation.
comment|///  (load (i64 add (i64 copyfromreg %c)
comment|///                 (i64 signextend (add (i8 load %index)
comment|///                                      (i8 1))))
comment|/// vs
comment|///
comment|/// (load (i64 add (i64 copyfromreg %c)
comment|///                (i64 signextend (i32 add (i32 signextend (i8 load %index))
comment|///                                         (i32 1)))))
name|class
name|BaseIndexOffset
block|{
name|private
label|:
name|SDValue
name|Base
decl_stmt|;
name|SDValue
name|Index
decl_stmt|;
name|int64_t
name|Offset
decl_stmt|;
name|bool
name|IsIndexSignExt
decl_stmt|;
name|public
label|:
name|BaseIndexOffset
argument_list|()
operator|:
name|Offset
argument_list|(
literal|0
argument_list|)
operator|,
name|IsIndexSignExt
argument_list|(
argument|false
argument_list|)
block|{}
name|BaseIndexOffset
argument_list|(
argument|SDValue Base
argument_list|,
argument|SDValue Index
argument_list|,
argument|int64_t Offset
argument_list|,
argument|bool IsIndexSignExt
argument_list|)
operator|:
name|Base
argument_list|(
name|Base
argument_list|)
operator|,
name|Index
argument_list|(
name|Index
argument_list|)
operator|,
name|Offset
argument_list|(
name|Offset
argument_list|)
operator|,
name|IsIndexSignExt
argument_list|(
argument|IsIndexSignExt
argument_list|)
block|{}
name|SDValue
name|getBase
argument_list|()
block|{
return|return
name|Base
return|;
block|}
name|SDValue
name|getIndex
parameter_list|()
block|{
return|return
name|Index
return|;
block|}
name|bool
name|equalBaseIndex
parameter_list|(
name|BaseIndexOffset
modifier|&
name|Other
parameter_list|,
specifier|const
name|SelectionDAG
modifier|&
name|DAG
parameter_list|)
block|{
name|int64_t
name|Off
decl_stmt|;
return|return
name|equalBaseIndex
argument_list|(
name|Other
argument_list|,
name|DAG
argument_list|,
name|Off
argument_list|)
return|;
block|}
name|bool
name|equalBaseIndex
parameter_list|(
name|BaseIndexOffset
modifier|&
name|Other
parameter_list|,
specifier|const
name|SelectionDAG
modifier|&
name|DAG
parameter_list|,
name|int64_t
modifier|&
name|Off
parameter_list|)
function_decl|;
comment|/// Parses tree in Ptr for base, index, offset addresses.
specifier|static
name|BaseIndexOffset
name|match
parameter_list|(
name|SDValue
name|Ptr
parameter_list|,
specifier|const
name|SelectionDAG
modifier|&
name|DAG
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

