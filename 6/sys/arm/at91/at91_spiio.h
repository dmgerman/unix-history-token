begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_AT91_AT91_SPIIO_H
end_ifndef

begin_define
define|#
directive|define
name|_ARM_AT91_AT91_SPIIO_H
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_struct
struct|struct
name|at91_spi_io
block|{
name|int
name|dadr
decl_stmt|;
comment|/* Device address */
name|int
name|type
decl_stmt|;
comment|/* read/write */
define|#
directive|define
name|SPI_IO_READ_MASTER
value|1
define|#
directive|define
name|SPI_IO_WRITE_MASTER
value|2
name|int
name|iadrsz
decl_stmt|;
comment|/* Internal addr size */
name|uint32_t
name|iadr
decl_stmt|;
comment|/* Interbak addr */
name|size_t
name|xfer_len
decl_stmt|;
comment|/* Size to transfer */
name|caddr_t
name|xfer_buf
decl_stmt|;
comment|/* buffer for xfer */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|at91_spi_clock
block|{
name|int
name|ckdiv
decl_stmt|;
comment|/* Clock divider */
name|int
name|high_rate
decl_stmt|;
comment|/* rate of clock high period */
name|int
name|low_rate
decl_stmt|;
comment|/* rate of clock low period */
block|}
struct|;
end_struct

begin_comment
comment|/** SPIIOCXFER: Do a two-wire transfer  */
end_comment

begin_define
define|#
directive|define
name|SPIIOCXFER
value|_IOW('x', 1, struct at91_spi_io)
end_define

begin_comment
comment|/** SPIIOCSETCLOCK: Sets the clocking parameters for this operation.  */
end_comment

begin_define
define|#
directive|define
name|SPIIOCSETCLOCK
value|_IOW('x', 2, struct at91_spi_clock)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ARM_AT91_AT91_SPIIO_H */
end_comment

end_unit

