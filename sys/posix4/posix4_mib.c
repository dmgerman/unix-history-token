begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998  *	HD Associates, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by HD Associates, Inc  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY HD ASSOCIATES AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL HD ASSOCIATES OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<posix4/posix4.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|facility
index|[
name|CTL_P1003_1B_MAXID
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* OID_AUTO isn't working with sysconf(3).  I guess I'd have to  * modify it to do a lookup by name from the index.  * For now I've left it a top-level sysctl.  */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_p1003_1b
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|P1B_SYSCTL
parameter_list|(
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|SYSCTL_INT(_p1003_1b, num, \ 	name, CTLFLAG_RD, facility + num - 1, 0, "");
end_define

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern_p1003_1b
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|P1B_SYSCTL
parameter_list|(
name|num
parameter_list|,
name|name
parameter_list|)
define|\
value|SYSCTL_INT(_kern_p1003_1b, OID_AUTO, \ 	name, CTLFLAG_RD, facility + num - 1, 0, "");
end_define

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|p1003_1b
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"P1003.1B"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_ASYNCHRONOUS_IO
argument_list|,
name|asynchronous_io
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_MAPPED_FILES
argument_list|,
name|mapped_files
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_MEMLOCK
argument_list|,
name|memlock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_MEMLOCK_RANGE
argument_list|,
name|memlock_range
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_MEMORY_PROTECTION
argument_list|,
name|memory_protection
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_MESSAGE_PASSING
argument_list|,
name|message_passing
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_PRIORITIZED_IO
argument_list|,
name|prioritized_io
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_PRIORITY_SCHEDULING
argument_list|,
name|priority_scheduling
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_REALTIME_SIGNALS
argument_list|,
name|realtime_signals
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_SEMAPHORES
argument_list|,
name|semaphores
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_FSYNC
argument_list|,
name|fsync
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_SHARED_MEMORY_OBJECTS
argument_list|,
name|shared_memory_objects
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_SYNCHRONIZED_IO
argument_list|,
name|synchronized_io
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_TIMERS
argument_list|,
name|timers
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_AIO_LISTIO_MAX
argument_list|,
name|aio_listio_max
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_AIO_MAX
argument_list|,
name|aio_max
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_AIO_PRIO_DELTA_MAX
argument_list|,
name|aio_prio_delta_max
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_DELAYTIMER_MAX
argument_list|,
name|delaytimer_max
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_MQ_OPEN_MAX
argument_list|,
name|mq_open_max
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_PAGESIZE
argument_list|,
name|pagesize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_RTSIG_MAX
argument_list|,
name|rtsig_max
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_SEM_NSEMS_MAX
argument_list|,
name|sem_nsems_max
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_SEM_VALUE_MAX
argument_list|,
name|sem_value_max
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_SIGQUEUE_MAX
argument_list|,
name|sigqueue_max
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|P1B_SYSCTL
argument_list|(
name|CTL_P1003_1B_TIMER_MAX
argument_list|,
name|timer_max
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* p31b_setcfg: Set the configuration  */
end_comment

begin_function
name|void
name|p31b_setcfg
parameter_list|(
name|int
name|num
parameter_list|,
name|int
name|value
parameter_list|)
block|{
if|if
condition|(
name|num
operator|>=
literal|1
operator|&&
name|num
operator|<
name|CTL_P1003_1B_MAXID
condition|)
name|facility
index|[
name|num
operator|-
literal|1
index|]
operator|=
name|value
expr_stmt|;
block|}
end_function

end_unit

