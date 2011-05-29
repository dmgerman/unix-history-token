begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IODEV_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IODEV_H_
end_define

begin_include
include|#
directive|include
file|<sys/uuid.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IODEV_EFIVAR_GETVAR
value|0
end_define

begin_define
define|#
directive|define
name|IODEV_EFIVAR_NEXTNAME
value|1
end_define

begin_define
define|#
directive|define
name|IODEV_EFIVAR_SETVAR
value|2
end_define

begin_struct
struct|struct
name|iodev_efivar_req
block|{
name|u_int
name|access
decl_stmt|;
name|u_int
name|result
decl_stmt|;
comment|/* errno value */
name|size_t
name|namesize
decl_stmt|;
name|u_short
modifier|*
name|name
decl_stmt|;
comment|/* UCS-2 */
name|struct
name|uuid
name|vendor
decl_stmt|;
name|uint32_t
name|attrib
decl_stmt|;
name|size_t
name|datasize
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IODEV_EFIVAR
value|_IOWR('I', 1, struct iodev_efivar_req)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|iodev_read_1
value|bus_space_read_io_1
end_define

begin_define
define|#
directive|define
name|iodev_read_2
value|bus_space_read_io_2
end_define

begin_define
define|#
directive|define
name|iodev_read_4
value|bus_space_read_io_4
end_define

begin_define
define|#
directive|define
name|iodev_write_1
value|bus_space_write_io_1
end_define

begin_define
define|#
directive|define
name|iodev_write_2
value|bus_space_write_io_2
end_define

begin_define
define|#
directive|define
name|iodev_write_4
value|bus_space_write_io_4
end_define

begin_function_decl
name|int
name|iodev_open
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iodev_close
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iodev_ioctl
parameter_list|(
name|u_long
parameter_list|,
name|caddr_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_IODEV_H_ */
end_comment

end_unit

