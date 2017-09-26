begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------------------- Range.h ------------------------------*- C++ -*-===//
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
name|utility_Range_h_
end_ifndef

begin_define
define|#
directive|define
name|utility_Range_h_
end_define

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_decl_stmt
name|namespace
name|lldb_utility
block|{
name|class
name|Range
block|{
name|public
label|:
typedef|typedef
name|uint64_t
name|ValueType
typedef|;
specifier|static
specifier|const
name|ValueType
name|OPEN_END
init|=
name|UINT64_MAX
decl_stmt|;
name|Range
argument_list|(
specifier|const
name|Range
operator|&
name|rng
argument_list|)
expr_stmt|;
name|Range
argument_list|(
argument|ValueType low =
literal|0
argument_list|,
argument|ValueType high = OPEN_END
argument_list|)
empty_stmt|;
name|Range
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Range
operator|&
name|rhs
operator|)
decl_stmt|;
name|ValueType
name|GetLow
parameter_list|()
block|{
return|return
name|m_low
return|;
block|}
name|ValueType
name|GetHigh
parameter_list|()
block|{
return|return
name|m_high
return|;
block|}
name|void
name|SetLow
parameter_list|(
name|ValueType
name|low
parameter_list|)
block|{
name|m_low
operator|=
name|low
expr_stmt|;
block|}
name|void
name|SetHigh
parameter_list|(
name|ValueType
name|high
parameter_list|)
block|{
name|m_high
operator|=
name|high
expr_stmt|;
block|}
name|void
name|Flip
parameter_list|()
function_decl|;
name|void
name|Intersection
parameter_list|(
specifier|const
name|Range
modifier|&
name|other
parameter_list|)
function_decl|;
name|void
name|Union
parameter_list|(
specifier|const
name|Range
modifier|&
name|other
parameter_list|)
function_decl|;
typedef|typedef
name|bool
function_decl|(
modifier|*
name|RangeCallback
function_decl|)
parameter_list|(
name|ValueType
name|index
parameter_list|)
function_decl|;
name|void
name|Iterate
parameter_list|(
name|RangeCallback
name|callback
parameter_list|)
function_decl|;
name|ValueType
name|GetSize
parameter_list|()
function_decl|;
name|bool
name|IsEmpty
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|InitRange
parameter_list|()
function_decl|;
name|ValueType
name|m_low
decl_stmt|;
name|ValueType
name|m_high
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef utility_Range_h_
end_comment

end_unit

