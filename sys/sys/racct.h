begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Edward Tomasz Napierala under sponsorship  * from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Resource accounting.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RACCT_H_
end_ifndef

begin_define
define|#
directive|define
name|_RACCT_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rctl_rule_link
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Resources.  */
end_comment

begin_define
define|#
directive|define
name|RACCT_UNDEFINED
value|-1
end_define

begin_define
define|#
directive|define
name|RACCT_CPU
value|0
end_define

begin_define
define|#
directive|define
name|RACCT_DATA
value|1
end_define

begin_define
define|#
directive|define
name|RACCT_STACK
value|2
end_define

begin_define
define|#
directive|define
name|RACCT_CORE
value|3
end_define

begin_define
define|#
directive|define
name|RACCT_RSS
value|4
end_define

begin_define
define|#
directive|define
name|RACCT_MEMLOCK
value|5
end_define

begin_define
define|#
directive|define
name|RACCT_NPROC
value|6
end_define

begin_define
define|#
directive|define
name|RACCT_NOFILE
value|7
end_define

begin_define
define|#
directive|define
name|RACCT_VMEM
value|8
end_define

begin_define
define|#
directive|define
name|RACCT_NPTS
value|9
end_define

begin_define
define|#
directive|define
name|RACCT_SWAP
value|10
end_define

begin_define
define|#
directive|define
name|RACCT_NTHR
value|11
end_define

begin_define
define|#
directive|define
name|RACCT_MSGQQUEUED
value|12
end_define

begin_define
define|#
directive|define
name|RACCT_MSGQSIZE
value|13
end_define

begin_define
define|#
directive|define
name|RACCT_NMSGQ
value|14
end_define

begin_define
define|#
directive|define
name|RACCT_NSEM
value|15
end_define

begin_define
define|#
directive|define
name|RACCT_NSEMOP
value|16
end_define

begin_define
define|#
directive|define
name|RACCT_NSHM
value|17
end_define

begin_define
define|#
directive|define
name|RACCT_SHMSIZE
value|18
end_define

begin_define
define|#
directive|define
name|RACCT_WALLCLOCK
value|19
end_define

begin_define
define|#
directive|define
name|RACCT_PCTCPU
value|20
end_define

begin_define
define|#
directive|define
name|RACCT_MAX
value|RACCT_PCTCPU
end_define

begin_comment
comment|/*  * Resource properties.  */
end_comment

begin_define
define|#
directive|define
name|RACCT_IN_MILLIONS
value|0x01
end_define

begin_define
define|#
directive|define
name|RACCT_RECLAIMABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|RACCT_INHERITABLE
value|0x04
end_define

begin_define
define|#
directive|define
name|RACCT_DENIABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|RACCT_SLOPPY
value|0x10
end_define

begin_define
define|#
directive|define
name|RACCT_DECAYING
value|0x20
end_define

begin_decl_stmt
specifier|extern
name|int
name|racct_types
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Amount stored in c_resources[] is 10**6 times bigger than what's  * visible to the userland.  It gets fixed up when retrieving resource  * usage or adding rules.  */
end_comment

begin_define
define|#
directive|define
name|RACCT_IS_IN_MILLIONS
parameter_list|(
name|X
parameter_list|)
value|(racct_types[X]& RACCT_IN_MILLIONS)
end_define

begin_comment
comment|/*  * Resource usage can drop, as opposed to only grow.  When the process  * terminates, its resource usage is freed from the respective  * per-credential racct containers.  */
end_comment

begin_define
define|#
directive|define
name|RACCT_IS_RECLAIMABLE
parameter_list|(
name|X
parameter_list|)
value|(racct_types[X]& RACCT_RECLAIMABLE)
end_define

begin_comment
comment|/*  * Children inherit resource usage.  */
end_comment

begin_define
define|#
directive|define
name|RACCT_IS_INHERITABLE
parameter_list|(
name|X
parameter_list|)
value|(racct_types[X]& RACCT_INHERITABLE)
end_define

begin_comment
comment|/*  * racct_{add,set}(9) can actually return an error and not update resource  * usage counters.  Note that even when resource is not deniable, allocating  * resource might cause signals to be sent by RCTL code.  */
end_comment

begin_define
define|#
directive|define
name|RACCT_IS_DENIABLE
parameter_list|(
name|X
parameter_list|)
value|(racct_types[X]& RACCT_DENIABLE)
end_define

begin_comment
comment|/*  * Per-process resource usage information makes no sense, but per-credential  * one does.  This kind of resources are usually allocated for process, but  * freed using credentials.  */
end_comment

begin_define
define|#
directive|define
name|RACCT_IS_SLOPPY
parameter_list|(
name|X
parameter_list|)
value|(racct_types[X]& RACCT_SLOPPY)
end_define

begin_comment
comment|/*  * When a process terminates, its resource usage is not automatically  * subtracted from per-credential racct containers.  Instead, the resource  * usage of per-credential racct containers decays in time.  * Resource usage can olso drop for such resource.  * So far, the only such resource is RACCT_PCTCPU.  */
end_comment

begin_define
define|#
directive|define
name|RACCT_IS_DECAYING
parameter_list|(
name|X
parameter_list|)
value|(racct_types[X]& RACCT_DECAYING)
end_define

begin_comment
comment|/*  * Resource usage can drop, as opposed to only grow.  */
end_comment

begin_define
define|#
directive|define
name|RACCT_CAN_DROP
parameter_list|(
name|X
parameter_list|)
value|(RACCT_IS_RECLAIMABLE(X) | RACCT_IS_DECAYING(X))
end_define

begin_comment
comment|/*  * The 'racct' structure defines resource consumption for a particular  * subject, such as process or jail.  *  * This structure must be filled with zeroes initially.  */
end_comment

begin_struct
struct|struct
name|racct
block|{
name|int64_t
name|r_resources
index|[
name|RACCT_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|rctl_rule_link
argument_list|)
name|r_rule_links
expr_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|RACCT
end_ifdef

begin_function_decl
name|int
name|racct_add
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|resource
parameter_list|,
name|uint64_t
name|amount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|racct_add_cred
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|resource
parameter_list|,
name|uint64_t
name|amount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|racct_add_force
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|resource
parameter_list|,
name|uint64_t
name|amount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|racct_set
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|resource
parameter_list|,
name|uint64_t
name|amount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|racct_set_force
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|resource
parameter_list|,
name|uint64_t
name|amount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|racct_sub
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|resource
parameter_list|,
name|uint64_t
name|amount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|racct_sub_cred
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|resource
parameter_list|,
name|uint64_t
name|amount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|racct_get_limit
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|resource
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|racct_get_available
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|resource
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|racct_create
parameter_list|(
name|struct
name|racct
modifier|*
modifier|*
name|racctp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|racct_destroy
parameter_list|(
name|struct
name|racct
modifier|*
modifier|*
name|racctp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|racct_proc_fork
parameter_list|(
name|struct
name|proc
modifier|*
name|parent
parameter_list|,
name|struct
name|proc
modifier|*
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|racct_proc_fork_done
parameter_list|(
name|struct
name|proc
modifier|*
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|racct_proc_exit
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|racct_proc_ucred_changed
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|ucred
modifier|*
name|oldcred
parameter_list|,
name|struct
name|ucred
modifier|*
name|newcred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|racct_move
parameter_list|(
name|struct
name|racct
modifier|*
name|dest
parameter_list|,
name|struct
name|racct
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
specifier|inline
name|int
name|racct_add
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|resource
parameter_list|,
name|uint64_t
name|amount
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|racct_add_cred
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|resource
parameter_list|,
name|uint64_t
name|amount
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|racct_add_force
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|resource
parameter_list|,
name|uint64_t
name|amount
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|int
name|racct_set
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|resource
parameter_list|,
name|uint64_t
name|amount
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|racct_set_force
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|resource
parameter_list|,
name|uint64_t
name|amount
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|racct_sub
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|resource
parameter_list|,
name|uint64_t
name|amount
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|racct_sub_cred
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
name|resource
parameter_list|,
name|uint64_t
name|amount
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|racct_get_limit
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|resource
parameter_list|)
block|{
return|return
operator|(
name|UINT64_MAX
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|racct_get_available
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|resource
parameter_list|)
block|{
return|return
operator|(
name|UINT64_MAX
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|racct_create
parameter_list|(
name|struct
name|racct
modifier|*
modifier|*
name|racctp
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|racct_destroy
parameter_list|(
name|struct
name|racct
modifier|*
modifier|*
name|racctp
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|int
name|racct_proc_fork
parameter_list|(
name|struct
name|proc
modifier|*
name|parent
parameter_list|,
name|struct
name|proc
modifier|*
name|child
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|racct_proc_fork_done
parameter_list|(
name|struct
name|proc
modifier|*
name|child
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|void
name|racct_proc_exit
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RACCT_H_ */
end_comment

end_unit

