begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013-2016 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_ERRNO_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_ERRNO_H_
end_define

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_define
define|#
directive|define
name|ECHRNG
value|EDOM
end_define

begin_define
define|#
directive|define
name|ETIME
value|ETIMEDOUT
end_define

begin_define
define|#
directive|define
name|ECOMM
value|ESTALE
end_define

begin_define
define|#
directive|define
name|ENODATA
value|ECONNREFUSED
end_define

begin_define
define|#
directive|define
name|ENOIOCTLCMD
value|ENOIOCTL
end_define

begin_comment
comment|/* Use same value as Linux, because BSD's ERESTART is negative */
end_comment

begin_define
define|#
directive|define
name|ERESTARTSYS
value|512
end_define

begin_define
define|#
directive|define
name|ENOTSUPP
value|EOPNOTSUPP
end_define

begin_define
define|#
directive|define
name|ENONET
value|EHOSTDOWN
end_define

begin_define
define|#
directive|define
name|ERESTARTNOINTR
value|513
end_define

begin_define
define|#
directive|define
name|ERESTARTNOHAND
value|514
end_define

begin_define
define|#
directive|define
name|ERESTART_RESTARTBLOCK
value|516
end_define

begin_define
define|#
directive|define
name|EPROBE_DEFER
value|517
end_define

begin_define
define|#
directive|define
name|EOPENSTALE
value|518
end_define

begin_define
define|#
directive|define
name|EBADHANDLE
value|521
end_define

begin_define
define|#
directive|define
name|ENOTSYNC
value|522
end_define

begin_define
define|#
directive|define
name|EBADCOOKIE
value|523
end_define

begin_define
define|#
directive|define
name|ETOOSMALL
value|525
end_define

begin_define
define|#
directive|define
name|ESERVERFAULT
value|526
end_define

begin_define
define|#
directive|define
name|EBADTYPE
value|527
end_define

begin_define
define|#
directive|define
name|EJUKEBOX
value|528
end_define

begin_define
define|#
directive|define
name|EIOCBQUEUED
value|529
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_ERRNO_H_ */
end_comment

end_unit

