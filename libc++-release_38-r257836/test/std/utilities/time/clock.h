begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----------------------------------------------------------------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
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
name|CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|CLOCK_H
end_define

begin_include
include|#
directive|include
file|<chrono>
end_include

begin_decl_stmt
name|class
name|Clock
block|{
typedef|typedef
name|std
operator|::
name|chrono
operator|::
name|nanoseconds
name|duration
expr_stmt|;
typedef|typedef
name|duration
operator|::
name|rep
name|rep
expr_stmt|;
typedef|typedef
name|duration
operator|::
name|period
name|period
expr_stmt|;
typedef|typedef
name|std
operator|::
name|chrono
operator|::
name|time_point
operator|<
name|Clock
operator|,
name|duration
operator|>
name|time_point
expr_stmt|;
specifier|static
specifier|const
name|bool
name|is_steady
init|=
name|false
decl_stmt|;
specifier|static
name|time_point
name|now
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CLOCK_H
end_comment

end_unit

