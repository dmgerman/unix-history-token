begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2002 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Frank van der Linden and Jason R. Thorpe for  * Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_KTTCPIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_KTTCPIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_struct
struct|struct
name|kttcp_io_args
block|{
name|unsigned
name|long
name|long
name|kio_totalsize
decl_stmt|;
comment|/* i/o total size (IN) */
name|unsigned
name|long
name|long
name|kio_bytesdone
decl_stmt|;
comment|/* i/o actually completed (OUT) */
name|struct
name|timeval
name|kio_elapsed
decl_stmt|;
comment|/* elapsed time (OUT) */
name|int
name|kio_socket
decl_stmt|;
comment|/* socket to use for i/o (IN) */
name|int
name|kio_protovers
decl_stmt|;
comment|/* KTTCP protocol version */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KTTCP_IO_SEND
value|_IOWR('K', 0, struct kttcp_io_args)
end_define

begin_define
define|#
directive|define
name|KTTCP_IO_RECV
value|_IOWR('K', 1, struct kttcp_io_args)
end_define

begin_define
define|#
directive|define
name|KTTCP_MAX_XMIT
value|0x7fffffffLL
end_define

begin_comment
comment|/* XXX can't handle> 31 bits */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_KTTCPIO_H_ */
end_comment

end_unit

