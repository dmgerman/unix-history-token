begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Metric.h ------------------------------------------------*- C++ -*-===//
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
name|__PerfTestDriver__Metric__
end_ifndef

begin_define
define|#
directive|define
name|__PerfTestDriver__Metric__
end_define

begin_include
include|#
directive|include
file|<mach/task_info.h>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lldb_perf
block|{
name|class
name|MemoryStats
decl_stmt|;
name|template
operator|<
name|class
name|ValueType
operator|>
name|class
name|Metric
block|{
name|public
operator|:
expr|enum
name|class
name|StandardDeviationMode
block|{
name|eSample
block|,
name|ePopulation
block|}
block|;
name|Metric
argument_list|()
block|;
name|Metric
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
operator|=
name|NULL
argument_list|)
block|;
name|void
name|Append
argument_list|(
argument|ValueType v
argument_list|)
block|;
name|ValueType
name|GetAverage
argument_list|()
specifier|const
block|;
name|size_t
name|GetCount
argument_list|()
specifier|const
block|;
name|ValueType
name|GetSum
argument_list|()
specifier|const
block|;
name|ValueType
name|GetStandardDeviation
argument_list|(
argument|StandardDeviationMode mode = StandardDeviationMode::ePopulation
argument_list|)
specifier|const
block|;
specifier|const
name|char
operator|*
name|GetName
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_name
operator|.
name|empty
argument_list|()
condition|)
return|return
name|NULL
return|;
return|return
name|m_name
operator|.
name|c_str
argument_list|()
return|;
block|}
specifier|const
name|char
operator|*
name|GetDescription
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_description
operator|.
name|empty
argument_list|()
condition|)
return|return
name|NULL
return|;
return|return
name|m_description
operator|.
name|c_str
argument_list|()
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|string
name|m_name
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|m_description
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|ValueType
operator|>
name|m_dataset
expr_stmt|;
end_expr_stmt

begin_endif
unit|}; }
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__PerfTestDriver__Metric__) */
end_comment

end_unit

