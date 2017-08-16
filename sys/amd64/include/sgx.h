begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * This software was developed by BAE Systems, the University of Cambridge  * Computer Laboratory, and Memorial University under DARPA/AFRL contract  * FA8650-15-C-7558 ("CADETS"), as part of the DARPA Transparent Computing  * (TC) research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* User-visible header. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SGX_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SGX_H_
end_define

begin_define
define|#
directive|define
name|SGX_MAGIC
value|0xA4
end_define

begin_define
define|#
directive|define
name|SGX_IOC_ENCLAVE_CREATE
define|\
value|_IOW(SGX_MAGIC, 0x00, struct sgx_enclave_create)
end_define

begin_define
define|#
directive|define
name|SGX_IOC_ENCLAVE_ADD_PAGE
define|\
value|_IOW(SGX_MAGIC, 0x01, struct sgx_enclave_add_page)
end_define

begin_define
define|#
directive|define
name|SGX_IOC_ENCLAVE_INIT
define|\
value|_IOW(SGX_MAGIC, 0x02, struct sgx_enclave_init)
end_define

begin_struct
struct|struct
name|sgx_enclave_create
block|{
name|uint64_t
name|src
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|sgx_enclave_add_page
block|{
name|uint64_t
name|addr
decl_stmt|;
name|uint64_t
name|src
decl_stmt|;
name|uint64_t
name|secinfo
decl_stmt|;
name|uint16_t
name|mrmask
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|sgx_enclave_init
block|{
name|uint64_t
name|addr
decl_stmt|;
name|uint64_t
name|sigstruct
decl_stmt|;
name|uint64_t
name|einittoken
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SGX_H_ */
end_comment

end_unit

