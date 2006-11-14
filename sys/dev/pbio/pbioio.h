begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *  Copyright (c) 2000-2004  *          Diomidis D. Spinellis, Athens, Greece  *      All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer as  *     the first lines of this file unmodified.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY Diomidis D. Spinellis ``AS IS'' AND ANY  *  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  *  PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL Diomidis D. Spinellis BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  *  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Definitions needed to access the pbio device (ioctls etc)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_PBIO_H
end_ifndef

begin_define
define|#
directive|define
name|SYS_PBIO_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/*  * ioctls  */
end_comment

begin_define
define|#
directive|define
name|PBIO_SETDIFF
value|_IOW('p', 0x01, int)
end_define

begin_define
define|#
directive|define
name|PBIO_SETIPACE
value|_IOW('p', 0x02, int)
end_define

begin_define
define|#
directive|define
name|PBIO_SETOPACE
value|_IOW('p', 0x03, int)
end_define

begin_define
define|#
directive|define
name|PBIO_GETDIFF
value|_IOR('p', 0x81, int)
end_define

begin_define
define|#
directive|define
name|PBIO_GETIPACE
value|_IOR('p', 0x82, int)
end_define

begin_define
define|#
directive|define
name|PBIO_GETOPACE
value|_IOR('p', 0x83, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

