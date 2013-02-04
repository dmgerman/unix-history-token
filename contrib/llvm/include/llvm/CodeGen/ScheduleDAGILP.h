begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ScheduleDAGILP.h - ILP metric for ScheduleDAGInstrs ------*- C++ -*-===//
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
comment|// Definition of an ILP metric for machine level instruction scheduling.
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
name|LLVM_CODEGEN_SCHEDULEDAGILP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SCHEDULEDAGILP_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|ScheduleDAGInstrs
decl_stmt|;
name|class
name|SUnit
decl_stmt|;
comment|/// \brief Represent the ILP of the subDAG rooted at a DAG node.
struct|struct
name|ILPValue
block|{
name|unsigned
name|InstrCount
decl_stmt|;
name|unsigned
name|Cycles
decl_stmt|;
name|ILPValue
argument_list|()
operator|:
name|InstrCount
argument_list|(
literal|0
argument_list|)
operator|,
name|Cycles
argument_list|(
literal|0
argument_list|)
block|{}
name|ILPValue
argument_list|(
argument|unsigned count
argument_list|,
argument|unsigned cycles
argument_list|)
operator|:
name|InstrCount
argument_list|(
name|count
argument_list|)
operator|,
name|Cycles
argument_list|(
argument|cycles
argument_list|)
block|{}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Cycles
operator|>
literal|0
return|;
block|}
comment|// Order by the ILP metric's value.
name|bool
name|operator
operator|<
operator|(
name|ILPValue
name|RHS
operator|)
specifier|const
block|{
return|return
operator|(
name|uint64_t
operator|)
name|InstrCount
operator|*
name|RHS
operator|.
name|Cycles
operator|<
operator|(
name|uint64_t
operator|)
name|Cycles
operator|*
name|RHS
operator|.
name|InstrCount
return|;
block|}
name|bool
name|operator
operator|>
operator|(
name|ILPValue
name|RHS
operator|)
specifier|const
block|{
return|return
name|RHS
operator|<
operator|*
name|this
return|;
block|}
name|bool
name|operator
operator|<=
operator|(
name|ILPValue
name|RHS
operator|)
specifier|const
block|{
return|return
operator|(
name|uint64_t
operator|)
name|InstrCount
operator|*
name|RHS
operator|.
name|Cycles
operator|<=
operator|(
name|uint64_t
operator|)
name|Cycles
operator|*
name|RHS
operator|.
name|InstrCount
return|;
block|}
name|bool
name|operator
operator|>=
operator|(
name|ILPValue
name|RHS
operator|)
specifier|const
block|{
return|return
name|RHS
operator|<=
operator|*
name|this
return|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NDEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|LLVM_ENABLE_DUMP
argument_list|)
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
block|}
struct|;
comment|/// \brief Compute the values of each DAG node for an ILP metric.
comment|///
comment|/// This metric assumes that the DAG is a forest of trees with roots at the
comment|/// bottom of the schedule.
name|class
name|ScheduleDAGILP
block|{
name|bool
name|IsBottomUp
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|ILPValue
operator|>
name|ILPValues
expr_stmt|;
name|public
label|:
name|ScheduleDAGILP
argument_list|(
argument|bool IsBU
argument_list|)
block|:
name|IsBottomUp
argument_list|(
argument|IsBU
argument_list|)
block|{}
comment|/// \brief Initialize the result data with the size of the DAG.
name|void
name|resize
parameter_list|(
name|unsigned
name|NumSUnits
parameter_list|)
function_decl|;
comment|/// \brief Compute the ILP metric for the subDAG at this root.
name|void
name|computeILP
parameter_list|(
specifier|const
name|SUnit
modifier|*
name|Root
parameter_list|)
function_decl|;
comment|/// \brief Get the ILP value for a DAG node.
name|ILPValue
name|getILP
parameter_list|(
specifier|const
name|SUnit
modifier|*
name|SU
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|ILPValue
operator|&
name|Val
operator|)
expr_stmt|;
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

