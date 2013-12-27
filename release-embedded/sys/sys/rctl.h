begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Edward Tomasz Napierala under sponsorship  * from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Resource Limits.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_RCTL_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
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

begin_include
include|#
directive|include
file|<sys/_task.h>
end_include

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uidinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|loginclass
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|prison_racct
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rctl_rule_link
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Rules describe an action to be taken when conditions defined  * in the rule are met.  There is no global list of rules; instead,  * rules are linked to by the racct structures for all the subjects  * they apply to - for example, a rule of type "user" is linked to the  * appropriate struct uidinfo, and to all the processes of that user.  *  * 'rr_refcount' is equal to the number of rctl_rule_link structures  * pointing to the rule.  *  * This structure must never change after being added, via rctl_rule_link  * structures, to subjects.  In order to change a rule, add a new rule  * and remove the previous one.  */
end_comment

begin_struct
struct|struct
name|rctl_rule
block|{
name|int
name|rr_subject_type
decl_stmt|;
union|union
block|{
name|struct
name|proc
modifier|*
name|rs_proc
decl_stmt|;
name|struct
name|uidinfo
modifier|*
name|rs_uip
decl_stmt|;
name|struct
name|loginclass
modifier|*
name|rs_loginclass
decl_stmt|;
name|struct
name|prison_racct
modifier|*
name|rs_prison_racct
decl_stmt|;
block|}
name|rr_subject
union|;
name|int
name|rr_per
decl_stmt|;
name|int
name|rr_resource
decl_stmt|;
name|int
name|rr_action
decl_stmt|;
name|int64_t
name|rr_amount
decl_stmt|;
name|u_int
name|rr_refcount
decl_stmt|;
name|struct
name|task
name|rr_task
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Allowed values for rr_subject_type and rr_per fields.  */
end_comment

begin_define
define|#
directive|define
name|RCTL_SUBJECT_TYPE_UNDEFINED
value|-1
end_define

begin_define
define|#
directive|define
name|RCTL_SUBJECT_TYPE_PROCESS
value|0x0000
end_define

begin_define
define|#
directive|define
name|RCTL_SUBJECT_TYPE_USER
value|0x0001
end_define

begin_define
define|#
directive|define
name|RCTL_SUBJECT_TYPE_LOGINCLASS
value|0x0003
end_define

begin_define
define|#
directive|define
name|RCTL_SUBJECT_TYPE_JAIL
value|0x0004
end_define

begin_define
define|#
directive|define
name|RCTL_SUBJECT_TYPE_MAX
value|RCTL_SUBJECT_TYPE_JAIL
end_define

begin_comment
comment|/*  * Allowed values for rr_action field.  */
end_comment

begin_define
define|#
directive|define
name|RCTL_ACTION_UNDEFINED
value|-1
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGHUP
value|SIGHUP
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGINT
value|SIGINT
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGQUIT
value|SIGQUIT
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGILL
value|SIGILL
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGTRAP
value|SIGTRAP
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGABRT
value|SIGABRT
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGEMT
value|SIGEMT
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGFPE
value|SIGFPE
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGKILL
value|SIGKILL
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGBUS
value|SIGBUS
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGSEGV
value|SIGSEGV
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGSYS
value|SIGSYS
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGPIPE
value|SIGPIPE
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGALRM
value|SIGALRM
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGTERM
value|SIGTERM
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGURG
value|SIGURG
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGSTOP
value|SIGSTOP
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGTSTP
value|SIGTSTP
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGCHLD
value|SIGCHLD
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGTTIN
value|SIGTTIN
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGTTOU
value|SIGTTOU
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGIO
value|SIGIO
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGXCPU
value|SIGXCPU
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGXFSZ
value|SIGXFSZ
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGVTALRM
value|SIGVTALRM
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGPROF
value|SIGPROF
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGWINCH
value|SIGWINCH
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGINFO
value|SIGINFO
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGUSR1
value|SIGUSR1
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGUSR2
value|SIGUSR2
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGTHR
value|SIGTHR
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_SIGNAL_MAX
value|RCTL_ACTION_SIGTHR
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_DENY
value|(RCTL_ACTION_SIGNAL_MAX + 1)
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_LOG
value|(RCTL_ACTION_SIGNAL_MAX + 2)
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_DEVCTL
value|(RCTL_ACTION_SIGNAL_MAX + 3)
end_define

begin_define
define|#
directive|define
name|RCTL_ACTION_MAX
value|RCTL_ACTION_DEVCTL
end_define

begin_define
define|#
directive|define
name|RCTL_AMOUNT_UNDEFINED
value|-1
end_define

begin_function_decl
name|struct
name|rctl_rule
modifier|*
name|rctl_rule_alloc
parameter_list|(
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|rctl_rule
modifier|*
name|rctl_rule_duplicate
parameter_list|(
specifier|const
name|struct
name|rctl_rule
modifier|*
name|rule
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rctl_rule_acquire
parameter_list|(
name|struct
name|rctl_rule
modifier|*
name|rule
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rctl_rule_release
parameter_list|(
name|struct
name|rctl_rule
modifier|*
name|rule
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rctl_rule_add
parameter_list|(
name|struct
name|rctl_rule
modifier|*
name|rule
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rctl_rule_remove
parameter_list|(
name|struct
name|rctl_rule
modifier|*
name|filter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rctl_enforce
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
name|int64_t
name|rctl_pcpu_available
parameter_list|(
specifier|const
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|rctl_get_limit
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
name|rctl_get_available
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
specifier|const
name|char
modifier|*
name|rctl_resource_name
parameter_list|(
name|int
name|resource
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rctl_proc_ucred_changed
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|ucred
modifier|*
name|newcred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rctl_proc_fork
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
name|rctl_racct_release
parameter_list|(
name|struct
name|racct
modifier|*
name|racct
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_comment
comment|/*  * Syscall interface.  */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|int
name|rctl_get_racct
parameter_list|(
specifier|const
name|char
modifier|*
name|inbufp
parameter_list|,
name|size_t
name|inbuflen
parameter_list|,
name|char
modifier|*
name|outbufp
parameter_list|,
name|size_t
name|outbuflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rctl_get_rules
parameter_list|(
specifier|const
name|char
modifier|*
name|inbufp
parameter_list|,
name|size_t
name|inbuflen
parameter_list|,
name|char
modifier|*
name|outbufp
parameter_list|,
name|size_t
name|outbuflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rctl_get_limits
parameter_list|(
specifier|const
name|char
modifier|*
name|inbufp
parameter_list|,
name|size_t
name|inbuflen
parameter_list|,
name|char
modifier|*
name|outbufp
parameter_list|,
name|size_t
name|outbuflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rctl_add_rule
parameter_list|(
specifier|const
name|char
modifier|*
name|inbufp
parameter_list|,
name|size_t
name|inbuflen
parameter_list|,
name|char
modifier|*
name|outbufp
parameter_list|,
name|size_t
name|outbuflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rctl_remove_rule
parameter_list|(
specifier|const
name|char
modifier|*
name|inbufp
parameter_list|,
name|size_t
name|inbuflen
parameter_list|,
name|char
modifier|*
name|outbufp
parameter_list|,
name|size_t
name|outbuflen
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RCTL_H_ */
end_comment

end_unit

