begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       mytime.c
end_comment

begin_comment
comment|/// \brief      Time handling functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_include
include|#
directive|include
file|"private.h"
end_include

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|HAVE_CLOCK_GETTIME
argument_list|)
operator|&&
name|HAVE_DECL_CLOCK_MONOTONIC
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|uint64_t
name|opt_flush_timeout
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|flush_needed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|uint64_t
name|start_time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|uint64_t
name|next_flush
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief      Get the current time as milliseconds
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It's relative to some point but not necessarily to the UNIX Epoch.
end_comment

begin_function
specifier|static
name|uint64_t
name|mytime_now
parameter_list|(
name|void
parameter_list|)
block|{
comment|// NOTE: HAVE_DECL_CLOCK_MONOTONIC is always defined to 0 or 1.
if|#
directive|if
name|defined
argument_list|(
name|HAVE_CLOCK_GETTIME
argument_list|)
operator|&&
name|HAVE_DECL_CLOCK_MONOTONIC
comment|// If CLOCK_MONOTONIC was available at compile time but for some
comment|// reason isn't at runtime, fallback to CLOCK_REALTIME which
comment|// according to POSIX is mandatory for all implementations.
specifier|static
name|clockid_t
name|clk_id
init|=
name|CLOCK_MONOTONIC
decl_stmt|;
name|struct
name|timespec
name|tv
decl_stmt|;
while|while
condition|(
name|clock_gettime
argument_list|(
name|clk_id
argument_list|,
operator|&
name|tv
argument_list|)
condition|)
name|clk_id
operator|=
name|CLOCK_REALTIME
expr_stmt|;
return|return
call|(
name|uint64_t
call|)
argument_list|(
name|tv
operator|.
name|tv_sec
argument_list|)
operator|*
name|UINT64_C
argument_list|(
literal|1000
argument_list|)
operator|+
name|tv
operator|.
name|tv_nsec
operator|/
literal|1000000
return|;
else|#
directive|else
name|struct
name|timeval
name|tv
decl_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|tv
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
call|(
name|uint64_t
call|)
argument_list|(
name|tv
operator|.
name|tv_sec
argument_list|)
operator|*
name|UINT64_C
argument_list|(
literal|1000
argument_list|)
operator|+
name|tv
operator|.
name|tv_usec
operator|/
literal|1000
return|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|extern
name|void
name|mytime_set_start_time
parameter_list|(
name|void
parameter_list|)
block|{
name|start_time
operator|=
name|mytime_now
argument_list|()
expr_stmt|;
name|next_flush
operator|=
name|start_time
operator|+
name|opt_flush_timeout
expr_stmt|;
name|flush_needed
operator|=
name|false
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|uint64_t
name|mytime_get_elapsed
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|mytime_now
argument_list|()
operator|-
name|start_time
return|;
block|}
end_function

begin_function
specifier|extern
name|void
name|mytime_set_flush_time
parameter_list|(
name|void
parameter_list|)
block|{
name|next_flush
operator|=
name|mytime_now
argument_list|()
operator|+
name|opt_flush_timeout
expr_stmt|;
name|flush_needed
operator|=
name|false
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|int
name|mytime_get_flush_timeout
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|opt_flush_timeout
operator|==
literal|0
operator|||
name|opt_mode
operator|!=
name|MODE_COMPRESS
condition|)
return|return
operator|-
literal|1
return|;
specifier|const
name|uint64_t
name|now
init|=
name|mytime_now
argument_list|()
decl_stmt|;
if|if
condition|(
name|now
operator|>=
name|next_flush
condition|)
return|return
literal|0
return|;
specifier|const
name|uint64_t
name|remaining
init|=
name|next_flush
operator|-
name|now
decl_stmt|;
return|return
name|remaining
operator|>
name|INT_MAX
condition|?
name|INT_MAX
else|:
operator|(
name|int
operator|)
name|remaining
return|;
block|}
end_function

end_unit

