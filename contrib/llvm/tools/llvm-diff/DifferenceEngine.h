begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DifferenceEngine.h - Module comparator ------------------*- C++ -*-===//
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
comment|// This header defines the interface to the LLVM difference engine,
end_comment

begin_comment
comment|// which structurally compares functions within a module.
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
name|LLVM_TOOLS_LLVM_DIFF_DIFFERENCEENGINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVM_DIFF_DIFFERENCEENGINE_H
end_define

begin_include
include|#
directive|include
file|"DiffConsumer.h"
end_include

begin_include
include|#
directive|include
file|"DiffLog.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// A class for performing structural comparisons of LLVM assembly.
name|class
name|DifferenceEngine
block|{
name|public
label|:
comment|/// A RAII object for recording the current context.
struct|struct
name|Context
block|{
name|Context
argument_list|(
name|DifferenceEngine
operator|&
name|Engine
argument_list|,
name|Value
operator|*
name|L
argument_list|,
name|Value
operator|*
name|R
argument_list|)
operator|:
name|Engine
argument_list|(
argument|Engine
argument_list|)
block|{
name|Engine
operator|.
name|consumer
operator|.
name|enterContext
argument_list|(
name|L
argument_list|,
name|R
argument_list|)
block|;       }
operator|~
name|Context
argument_list|()
block|{
name|Engine
operator|.
name|consumer
operator|.
name|exitContext
argument_list|()
block|;       }
name|private
operator|:
name|DifferenceEngine
operator|&
name|Engine
expr_stmt|;
block|}
struct|;
comment|/// An oracle for answering whether two values are equivalent as
comment|/// operands.
name|class
name|Oracle
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|virtual
name|bool
name|operator
argument_list|()
argument_list|(
name|Value
operator|*
name|L
argument_list|,
name|Value
operator|*
name|R
argument_list|)
operator|=
literal|0
expr_stmt|;
name|protected
label|:
name|virtual
operator|~
name|Oracle
argument_list|()
block|{}
block|}
empty_stmt|;
name|DifferenceEngine
argument_list|(
name|Consumer
operator|&
name|consumer
argument_list|)
operator|:
name|consumer
argument_list|(
name|consumer
argument_list|)
operator|,
name|globalValueOracle
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|void
name|diff
argument_list|(
name|Module
operator|*
name|L
argument_list|,
name|Module
operator|*
name|R
argument_list|)
expr_stmt|;
name|void
name|diff
parameter_list|(
name|Function
modifier|*
name|L
parameter_list|,
name|Function
modifier|*
name|R
parameter_list|)
function_decl|;
name|void
name|log
parameter_list|(
name|StringRef
name|text
parameter_list|)
block|{
name|consumer
operator|.
name|log
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
name|LogBuilder
name|logf
parameter_list|(
name|StringRef
name|text
parameter_list|)
block|{
return|return
name|LogBuilder
argument_list|(
name|consumer
argument_list|,
name|text
argument_list|)
return|;
block|}
name|Consumer
operator|&
name|getConsumer
argument_list|()
specifier|const
block|{
return|return
name|consumer
return|;
block|}
comment|/// Installs an oracle to decide whether two global values are
comment|/// equivalent as operands.  Without an oracle, global values are
comment|/// considered equivalent as operands precisely when they have the
comment|/// same name.
name|void
name|setGlobalValueOracle
parameter_list|(
name|Oracle
modifier|*
name|oracle
parameter_list|)
block|{
name|globalValueOracle
operator|=
name|oracle
expr_stmt|;
block|}
comment|/// Determines whether two global values are equivalent.
name|bool
name|equivalentAsOperands
parameter_list|(
name|GlobalValue
modifier|*
name|L
parameter_list|,
name|GlobalValue
modifier|*
name|R
parameter_list|)
function_decl|;
name|private
label|:
name|Consumer
modifier|&
name|consumer
decl_stmt|;
name|Oracle
modifier|*
name|globalValueOracle
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

