begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SPIGENIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SPIGENIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/_iovec.h>
end_include

begin_struct
struct|struct
name|spigen_transfer
block|{
name|struct
name|iovec
name|st_command
decl_stmt|;
comment|/* master to slave */
name|struct
name|iovec
name|st_data
decl_stmt|;
comment|/* slave to master and/or master to slave */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|spigen_transfer_mmapped
block|{
name|size_t
name|stm_command_length
decl_stmt|;
comment|/* at offset 0 in mmap(2) area */
name|size_t
name|stm_data_length
decl_stmt|;
comment|/* at offset stm_command_length */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SPIGENIOC_BASE
value|'S'
end_define

begin_define
define|#
directive|define
name|SPIGENIOC_TRANSFER
value|_IOW(SPIGENIOC_BASE, 0, \ 	    struct spigen_transfer)
end_define

begin_define
define|#
directive|define
name|SPIGENIOC_TRANSFER_MMAPPED
value|_IOW(SPIGENIOC_BASE, 1, \ 	    struct spigen_transfer_mmapped)
end_define

begin_define
define|#
directive|define
name|SPIGENIOC_GET_CLOCK_SPEED
value|_IOR(SPIGENIOC_BASE, 2, uint32_t)
end_define

begin_define
define|#
directive|define
name|SPIGENIOC_SET_CLOCK_SPEED
value|_IOW(SPIGENIOC_BASE, 3, uint32_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SPIGENIO_H_ */
end_comment

end_unit

