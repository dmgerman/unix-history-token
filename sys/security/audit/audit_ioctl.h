begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by Robert Watson for the TrustedBSD Project.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SECURITY_AUDIT_AUDIT_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SECURITY_AUDIT_AUDIT_IOCTL_H_
end_define

begin_define
define|#
directive|define
name|AUDITPIPE_IOBASE
value|'A'
end_define

begin_comment
comment|/*  * Ioctls to read and control the behavior of individual audit pipe devices.  */
end_comment

begin_define
define|#
directive|define
name|AUDITPIPE_GET_QLEN
value|_IOR(AUDITPIPE_IOBASE, 1, u_int)
end_define

begin_define
define|#
directive|define
name|AUDITPIPE_GET_QLIMIT
value|_IOR(AUDITPIPE_IOBASE, 2, u_int)
end_define

begin_define
define|#
directive|define
name|AUDITPIPE_SET_QLIMIT
value|_IOW(AUDITPIPE_IOBASE, 3, u_int)
end_define

begin_define
define|#
directive|define
name|AUDITPIPE_GET_QLIMIT_MIN
value|_IOR(AUDITPIPE_IOBASE, 4, u_int)
end_define

begin_define
define|#
directive|define
name|AUDITPIPE_GET_QLIMIT_MAX
value|_IOR(AUDITPIPE_IOBASE, 5, u_int)
end_define

begin_comment
comment|/*  * Ioctls to retrieve audit pipe statistics.  */
end_comment

begin_define
define|#
directive|define
name|AUDITPIPE_GET_INSERTS
value|_IOR(AUDITPIPE_IOBASE, 100, u_int64_t)
end_define

begin_define
define|#
directive|define
name|AUDITPIPE_GET_READS
value|_IOR(AUDITPIPE_IOBASE, 101, u_int64_t)
end_define

begin_define
define|#
directive|define
name|AUDITPIPE_GET_DROPS
value|_IOR(AUDITPIPE_IOBASE, 102, u_int64_t)
end_define

begin_define
define|#
directive|define
name|AUDITPIPE_GET_TRUNCATES
value|_IOR(AUDITPIPE_IOBASE, 103, u_int64_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SECURITY_AUDIT_AUDIT_IOCTL_H_ */
end_comment

end_unit

