begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * sched.h  *   * Scheduler state interactions  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2005, Keir Fraser<keir@xensource.com>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_SCHED_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_SCHED_H__
end_define

begin_include
include|#
directive|include
file|"event_channel.h"
end_include

begin_comment
comment|/*  * The prototype for this hypercall is:  *  long sched_op(int cmd, void *arg)  * @cmd == SCHEDOP_??? (scheduler operation).  * @arg == Operation-specific extra argument(s), as described below.  *   * Versions of Xen prior to 3.0.2 provided only the following legacy version  * of this hypercall, supporting only the commands yield, block and shutdown:  *  long sched_op(int cmd, unsigned long arg)  * @cmd == SCHEDOP_??? (scheduler operation).  * @arg == 0               (SCHEDOP_yield and SCHEDOP_block)  *      == SHUTDOWN_* code (SCHEDOP_shutdown)  * This legacy version is available to new guests as sched_op_compat().  */
end_comment

begin_comment
comment|/*  * Voluntarily yield the CPU.  * @arg == NULL.  */
end_comment

begin_define
define|#
directive|define
name|SCHEDOP_yield
value|0
end_define

begin_comment
comment|/*  * Block execution of this VCPU until an event is received for processing.  * If called with event upcalls masked, this operation will atomically  * reenable event delivery and check for pending events before blocking the  * VCPU. This avoids a "wakeup waiting" race.  * @arg == NULL.  */
end_comment

begin_define
define|#
directive|define
name|SCHEDOP_block
value|1
end_define

begin_comment
comment|/*  * Halt execution of this domain (all VCPUs) and notify the system controller.  * @arg == pointer to sched_shutdown structure.  */
end_comment

begin_define
define|#
directive|define
name|SCHEDOP_shutdown
value|2
end_define

begin_struct
struct|struct
name|sched_shutdown
block|{
name|unsigned
name|int
name|reason
decl_stmt|;
comment|/* SHUTDOWN_* */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sched_shutdown
name|sched_shutdown_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|sched_shutdown_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Poll a set of event-channel ports. Return when one or more are pending. An  * optional timeout may be specified.  * @arg == pointer to sched_poll structure.  */
end_comment

begin_define
define|#
directive|define
name|SCHEDOP_poll
value|3
end_define

begin_struct
struct|struct
name|sched_poll
block|{
name|XEN_GUEST_HANDLE
argument_list|(
argument|evtchn_port_t
argument_list|)
name|ports
expr_stmt|;
name|unsigned
name|int
name|nr_ports
decl_stmt|;
name|uint64_t
name|timeout
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sched_poll
name|sched_poll_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|sched_poll_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Declare a shutdown for another domain. The main use of this function is  * in interpreting shutdown requests and reasons for fully-virtualized  * domains.  A para-virtualized domain may use SCHEDOP_shutdown directly.  * @arg == pointer to sched_remote_shutdown structure.  */
end_comment

begin_define
define|#
directive|define
name|SCHEDOP_remote_shutdown
value|4
end_define

begin_struct
struct|struct
name|sched_remote_shutdown
block|{
name|domid_t
name|domain_id
decl_stmt|;
comment|/* Remote domain ID */
name|unsigned
name|int
name|reason
decl_stmt|;
comment|/* SHUTDOWN_xxx reason */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sched_remote_shutdown
name|sched_remote_shutdown_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|sched_remote_shutdown_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Reason codes for SCHEDOP_shutdown. These may be interpreted by control  * software to determine the appropriate action. For the most part, Xen does  * not care about the shutdown code.  */
end_comment

begin_define
define|#
directive|define
name|SHUTDOWN_poweroff
value|0
end_define

begin_comment
comment|/* Domain exited normally. Clean up and kill. */
end_comment

begin_define
define|#
directive|define
name|SHUTDOWN_reboot
value|1
end_define

begin_comment
comment|/* Clean up, kill, and then restart.          */
end_comment

begin_define
define|#
directive|define
name|SHUTDOWN_suspend
value|2
end_define

begin_comment
comment|/* Clean up, save suspend info, kill.         */
end_comment

begin_define
define|#
directive|define
name|SHUTDOWN_crash
value|3
end_define

begin_comment
comment|/* Tell controller we've crashed.             */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_SCHED_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

