begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2008-2012 - Symmetricom, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  $FreeBSD$   */
end_comment

begin_comment
comment|/*  * FTDI USB serial converter chip ioctl commands.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_UFTDIIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_UFTDIIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_enum
enum|enum
name|uftdi_bitmodes
block|{
name|UFTDI_BITMODE_ASYNC
init|=
literal|0
block|,
name|UFTDI_BITMODE_MPSSE
init|=
literal|1
block|,
name|UFTDI_BITMODE_SYNC
init|=
literal|2
block|,
name|UFTDI_BITMODE_CPU_EMUL
init|=
literal|3
block|,
name|UFTDI_BITMODE_FAST_SERIAL
init|=
literal|4
block|,
name|UFTDI_BITMODE_CBUS
init|=
literal|5
block|,
name|UFTDI_BITMODE_NONE
init|=
literal|0xff
block|, }
enum|;
end_enum

begin_comment
comment|/*  * For UFTDIIOC_SET_BITMODE:  *   mode   = One of the uftdi_bitmodes enum values.  *   iomask = Mask of bits enabled for bitbang output.  *  * For UFTDIIOC_GET_BITMODE:  *   mode   = Unused.  *   iomask = Returned snapshot of bitbang pin states at time of call.  */
end_comment

begin_struct
struct|struct
name|uftdi_bitmode
block|{
name|uint8_t
name|mode
decl_stmt|;
name|uint8_t
name|iomask
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UFTDIIOC_RESET_IO
value|_IO('c', 0)
end_define

begin_comment
comment|/* Reset config, flush fifos.*/
end_comment

begin_define
define|#
directive|define
name|UFTDIIOC_RESET_RX
value|_IO('c', 1)
end_define

begin_comment
comment|/* Flush input fifo. */
end_comment

begin_define
define|#
directive|define
name|UFTDIIOC_RESET_TX
value|_IO('c', 2)
end_define

begin_comment
comment|/* Flush output fifo. */
end_comment

begin_define
define|#
directive|define
name|UFTDIIOC_SET_BITMODE
value|_IOW('c', 3, struct uftdi_bitmode)
end_define

begin_define
define|#
directive|define
name|UFTDIIOC_GET_BITMODE
value|_IOR('c', 4, struct uftdi_bitmode)
end_define

begin_define
define|#
directive|define
name|UFTDIIOC_SET_ERROR_CHAR
value|_IOW('c', 5, int)
end_define

begin_comment
comment|/* -1 to disable */
end_comment

begin_define
define|#
directive|define
name|UFTDIIOC_SET_EVENT_CHAR
value|_IOW('c', 6, int)
end_define

begin_comment
comment|/* -1 to disable */
end_comment

begin_define
define|#
directive|define
name|UFTDIIOC_SET_LATENCY
value|_IOW('c', 7, int)
end_define

begin_comment
comment|/* 1-255 ms */
end_comment

begin_define
define|#
directive|define
name|UFTDIIOC_GET_LATENCY
value|_IOR('c', 8, int)
end_define

begin_define
define|#
directive|define
name|UFTDIIOC_GET_HWREV
value|_IOR('c', 9, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

