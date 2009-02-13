begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)filio.h	8.1 (Berkeley) 3/28/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_FILIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FILIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/* Generic file-descriptor ioctl's. */
end_comment

begin_define
define|#
directive|define
name|FIOCLEX
value|_IO('f', 1)
end_define

begin_comment
comment|/* set close on exec on fd */
end_comment

begin_define
define|#
directive|define
name|FIONCLEX
value|_IO('f', 2)
end_define

begin_comment
comment|/* remove close on exec */
end_comment

begin_define
define|#
directive|define
name|FIONREAD
value|_IOR('f', 127, int)
end_define

begin_comment
comment|/* get # bytes to read */
end_comment

begin_define
define|#
directive|define
name|FIONBIO
value|_IOW('f', 126, int)
end_define

begin_comment
comment|/* set/clear non-blocking i/o */
end_comment

begin_define
define|#
directive|define
name|FIOASYNC
value|_IOW('f', 125, int)
end_define

begin_comment
comment|/* set/clear async i/o */
end_comment

begin_define
define|#
directive|define
name|FIOSETOWN
value|_IOW('f', 124, int)
end_define

begin_comment
comment|/* set owner */
end_comment

begin_define
define|#
directive|define
name|FIOGETOWN
value|_IOR('f', 123, int)
end_define

begin_comment
comment|/* get owner */
end_comment

begin_define
define|#
directive|define
name|FIODTYPE
value|_IOR('f', 122, int)
end_define

begin_comment
comment|/* get d_flags type part */
end_comment

begin_define
define|#
directive|define
name|FIOGETLBA
value|_IOR('f', 121, int)
end_define

begin_comment
comment|/* get start blk # */
end_comment

begin_struct
struct|struct
name|fiodgname_arg
block|{
name|int
name|len
decl_stmt|;
name|void
modifier|*
name|buf
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FIODGNAME
value|_IOW('f', 120, struct fiodgname_arg)
end_define

begin_comment
comment|/* get dev. name */
end_comment

begin_comment
comment|/* Handle lseek SEEK_DATA and SEEK_HOLE for holey file knowledge. */
end_comment

begin_define
define|#
directive|define
name|FIOSEEKDATA
value|_IOWR('f', 97, off_t)
end_define

begin_comment
comment|/* SEEK_DATA */
end_comment

begin_define
define|#
directive|define
name|FIOSEEKHOLE
value|_IOWR('f', 98, off_t)
end_define

begin_comment
comment|/* SEEK_HOLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_FILIO_H_ */
end_comment

end_unit

