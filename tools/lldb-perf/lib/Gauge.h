begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Gauge.h -------------------------------------------------*- C++ -*-===//
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
name|PerfTestDriver_Gauge_h
end_ifndef

begin_define
define|#
directive|define
name|PerfTestDriver_Gauge_h
end_define

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"Results.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_perf
block|{
name|template
operator|<
name|class
name|T
operator|>
name|class
name|Gauge
block|{
name|public
operator|:
typedef|typedef
name|T
name|ValueType
typedef|;
name|Gauge
argument_list|()
block|{}
name|virtual
operator|~
name|Gauge
argument_list|()
block|{}
name|virtual
name|void
name|Start
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|ValueType
name|Stop
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|ValueType
name|GetStartValue
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|ValueType
name|GetStopValue
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|ValueType
name|GetDeltaValue
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|Results
operator|::
name|ResultSP
name|GetResult
argument_list|(
argument|const char *description
argument_list|,
argument|T value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|Results
operator|::
name|ResultSP
name|GetResult
argument_list|(
argument|const char *description
argument_list|,
argument|double value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|Results
operator|::
name|ResultSP
name|GetResult
argument_list|(
argument|const char *description
argument_list|,
argument|uint64_t value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|Results
operator|::
name|ResultSP
name|GetResult
argument_list|(
argument|const char *description
argument_list|,
argument|std::string value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

