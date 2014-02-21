begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * evtchn.h  *   * Interface to /dev/xen/evtchn.  *   * Copyright (c) 2003-2005, K A Fraser  *   * This file may be distributed separately from the Linux kernel, or  * incorporated into other software packages, subject to the following license:  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this source file (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use, copy, modify,  * merge, publish, distribute, sublicense, and/or sell copies of the Software,  * and to permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS  * IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_EVTCHN_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_EVTCHN_H__
end_define

begin_comment
comment|/*  * Bind a fresh port to VIRQ @virq.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_EVTCHN_BIND_VIRQ
define|\
value|_IOWR('E', 4, struct ioctl_evtchn_bind_virq)
end_define

begin_struct
struct|struct
name|ioctl_evtchn_bind_virq
block|{
name|unsigned
name|int
name|virq
decl_stmt|;
name|unsigned
name|int
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bind a fresh port to remote<@remote_domain, @remote_port>.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_EVTCHN_BIND_INTERDOMAIN
define|\
value|_IOWR('E', 5, struct ioctl_evtchn_bind_interdomain)
end_define

begin_struct
struct|struct
name|ioctl_evtchn_bind_interdomain
block|{
name|unsigned
name|int
name|remote_domain
decl_stmt|,
name|remote_port
decl_stmt|;
name|unsigned
name|int
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Allocate a fresh port for binding to @remote_domain.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_EVTCHN_BIND_UNBOUND_PORT
define|\
value|_IOWR('E', 6, struct ioctl_evtchn_bind_unbound_port)
end_define

begin_struct
struct|struct
name|ioctl_evtchn_bind_unbound_port
block|{
name|unsigned
name|int
name|remote_domain
decl_stmt|;
name|unsigned
name|int
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Unbind previously allocated @port.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_EVTCHN_UNBIND
define|\
value|_IOW('E', 7, struct ioctl_evtchn_unbind)
end_define

begin_struct
struct|struct
name|ioctl_evtchn_unbind
block|{
name|unsigned
name|int
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Send event to previously allocated @port.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_EVTCHN_NOTIFY
define|\
value|_IOW('E', 8, struct ioctl_evtchn_notify)
end_define

begin_struct
struct|struct
name|ioctl_evtchn_notify
block|{
name|unsigned
name|int
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Clear and reinitialise the event buffer. Clear error condition. */
end_comment

begin_define
define|#
directive|define
name|IOCTL_EVTCHN_RESET
define|\
value|_IO('E', 9)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_EVTCHN_H__ */
end_comment

end_unit

