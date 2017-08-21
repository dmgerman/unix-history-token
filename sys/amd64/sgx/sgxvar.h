begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * This software was developed by BAE Systems, the University of Cambridge  * Computer Laboratory, and Memorial University under DARPA/AFRL contract  * FA8650-15-C-7558 ("CADETS"), as part of the DARPA Transparent Computing  * (TC) research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AMD64_SGX_SGXVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_AMD64_SGX_SGXVAR_H_
end_define

begin_define
define|#
directive|define
name|SGX_CPUID
value|0x12
end_define

begin_define
define|#
directive|define
name|SGX_PAGE_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|SGX_VA_PAGE_SLOTS
value|512
end_define

begin_define
define|#
directive|define
name|SGX_VA_PAGES_OFFS
value|512
end_define

begin_define
define|#
directive|define
name|SGX_SECS_VM_OBJECT_INDEX
value|-1
end_define

begin_define
define|#
directive|define
name|SGX_SIGSTRUCT_SIZE
value|1808
end_define

begin_define
define|#
directive|define
name|SGX_EINITTOKEN_SIZE
value|304
end_define

begin_define
define|#
directive|define
name|SGX_IOCTL_MAX_DATA_LEN
value|26
end_define

begin_define
define|#
directive|define
name|SGX_ENCL_SIZE_MAX_DEF
value|0x1000000000ULL
end_define

begin_define
define|#
directive|define
name|SGX_EFAULT
value|99
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_expr_stmt
specifier|static
name|MALLOC_DEFINE
argument_list|(
name|M_SGX
argument_list|,
literal|"sgx"
argument_list|,
literal|"SGX driver"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|sgx_vm_handle
block|{
name|struct
name|sgx_softc
modifier|*
name|sc
decl_stmt|;
name|vm_object_t
name|mem
decl_stmt|;
name|uint64_t
name|base
decl_stmt|;
name|vm_size_t
name|size
decl_stmt|;
name|struct
name|sgx_enclave
modifier|*
name|enclave
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* EPC (Enclave Page Cache) page. */
end_comment

begin_struct
struct|struct
name|epc_page
block|{
name|uint64_t
name|base
decl_stmt|;
name|uint64_t
name|phys
decl_stmt|;
name|int
name|index
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sgx_enclave
block|{
name|uint64_t
name|base
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
name|struct
name|sgx_vm_handle
modifier|*
name|vmh
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|sgx_enclave
argument_list|)
name|next
expr_stmt|;
name|vm_object_t
name|object
decl_stmt|;
name|struct
name|epc_page
modifier|*
name|secs_epc_page
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sgx_softc
block|{
name|struct
name|cdev
modifier|*
name|sgx_cdev
decl_stmt|;
name|struct
name|mtx
name|mtx_encls
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
name|uint64_t
name|epc_base
decl_stmt|;
name|uint64_t
name|epc_size
decl_stmt|;
name|struct
name|epc_page
modifier|*
name|epc_pages
decl_stmt|;
name|struct
name|vmem
modifier|*
name|vmem_epc
decl_stmt|;
name|uint32_t
name|npages
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|sgx_enclave
argument_list|)
name|enclaves
expr_stmt|;
name|uint64_t
name|enclave_size_max
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
define|#
directive|define
name|SGX_STATE_RUNNING
value|(1<< 0)
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_AMD64_SGX_SGXVAR_H_ */
end_comment

end_unit

