begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2012,2016 Microsoft Corp.  * Copyright (c) 2012 NetApp Inc.  * Copyright (c) 2012 Citrix Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMBUS_BRVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMBUS_BRVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/_iovec.h>
end_include

begin_struct
struct|struct
name|vmbus_br
block|{
name|struct
name|vmbus_bufring
modifier|*
name|vbr
decl_stmt|;
name|uint32_t
name|vbr_dsize
decl_stmt|;
comment|/* total data size */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|vbr_windex
value|vbr->br_windex
end_define

begin_define
define|#
directive|define
name|vbr_rindex
value|vbr->br_rindex
end_define

begin_define
define|#
directive|define
name|vbr_imask
value|vbr->br_imask
end_define

begin_define
define|#
directive|define
name|vbr_data
value|vbr->br_data
end_define

begin_struct
struct|struct
name|vmbus_rxbr
block|{
name|struct
name|mtx
name|rxbr_lock
decl_stmt|;
name|struct
name|vmbus_br
name|rxbr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rxbr_windex
value|rxbr.vbr_windex
end_define

begin_define
define|#
directive|define
name|rxbr_rindex
value|rxbr.vbr_rindex
end_define

begin_define
define|#
directive|define
name|rxbr_imask
value|rxbr.vbr_imask
end_define

begin_define
define|#
directive|define
name|rxbr_data
value|rxbr.vbr_data
end_define

begin_define
define|#
directive|define
name|rxbr_dsize
value|rxbr.vbr_dsize
end_define

begin_struct
struct|struct
name|vmbus_txbr
block|{
name|struct
name|mtx
name|txbr_lock
decl_stmt|;
name|struct
name|vmbus_br
name|txbr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|txbr_windex
value|txbr.vbr_windex
end_define

begin_define
define|#
directive|define
name|txbr_rindex
value|txbr.vbr_rindex
end_define

begin_define
define|#
directive|define
name|txbr_imask
value|txbr.vbr_imask
end_define

begin_define
define|#
directive|define
name|txbr_data
value|txbr.vbr_data
end_define

begin_define
define|#
directive|define
name|txbr_dsize
value|txbr.vbr_dsize
end_define

begin_struct_decl
struct_decl|struct
name|sysctl_ctx_list
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sysctl_oid
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|vmbus_br_sysctl_create
parameter_list|(
name|struct
name|sysctl_ctx_list
modifier|*
name|ctx
parameter_list|,
name|struct
name|sysctl_oid
modifier|*
name|br_tree
parameter_list|,
name|struct
name|vmbus_br
modifier|*
name|br
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_rxbr_init
parameter_list|(
name|struct
name|vmbus_rxbr
modifier|*
name|rbr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_rxbr_deinit
parameter_list|(
name|struct
name|vmbus_rxbr
modifier|*
name|rbr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_rxbr_setup
parameter_list|(
name|struct
name|vmbus_rxbr
modifier|*
name|rbr
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|blen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_rxbr_peek
parameter_list|(
name|struct
name|vmbus_rxbr
modifier|*
name|rbr
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|dlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_rxbr_read
parameter_list|(
name|struct
name|vmbus_rxbr
modifier|*
name|rbr
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|dlen
parameter_list|,
name|uint32_t
name|skip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_rxbr_intr_mask
parameter_list|(
name|struct
name|vmbus_rxbr
modifier|*
name|rbr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|vmbus_rxbr_intr_unmask
parameter_list|(
name|struct
name|vmbus_rxbr
modifier|*
name|rbr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_txbr_init
parameter_list|(
name|struct
name|vmbus_txbr
modifier|*
name|tbr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_txbr_deinit
parameter_list|(
name|struct
name|vmbus_txbr
modifier|*
name|tbr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_txbr_setup
parameter_list|(
name|struct
name|vmbus_txbr
modifier|*
name|tbr
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|blen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmbus_txbr_write
parameter_list|(
name|struct
name|vmbus_txbr
modifier|*
name|tbr
parameter_list|,
specifier|const
name|struct
name|iovec
name|iov
index|[]
parameter_list|,
name|int
name|iovlen
parameter_list|,
name|boolean_t
modifier|*
name|need_sig
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VMBUS_BRVAR_H_ */
end_comment

end_unit

