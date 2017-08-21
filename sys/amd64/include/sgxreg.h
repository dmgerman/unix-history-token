begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * This software was developed by BAE Systems, the University of Cambridge  * Computer Laboratory, and Memorial University under DARPA/AFRL contract  * FA8650-15-C-7558 ("CADETS"), as part of the DARPA Transparent Computing  * (TC) research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Machine-defined variables. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SGXREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SGXREG_H_
end_define

begin_comment
comment|/* Error codes. */
end_comment

begin_define
define|#
directive|define
name|SGX_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|SGX_INVALID_SIG_STRUCT
value|1
end_define

begin_comment
comment|/* EINIT */
end_comment

begin_define
define|#
directive|define
name|SGX_INVALID_ATTRIBUTE
value|2
end_define

begin_comment
comment|/* EINIT, EGETKEY */
end_comment

begin_define
define|#
directive|define
name|SGX_BLSTATE
value|3
end_define

begin_comment
comment|/* EBLOCK */
end_comment

begin_define
define|#
directive|define
name|SGX_INVALID_MEASUREMENT
value|4
end_define

begin_comment
comment|/* EINIT */
end_comment

begin_define
define|#
directive|define
name|SGX_NOTBLOCKABLE
value|5
end_define

begin_comment
comment|/* EBLOCK */
end_comment

begin_define
define|#
directive|define
name|SGX_PG_INVLD
value|6
end_define

begin_comment
comment|/* EBLOCK */
end_comment

begin_define
define|#
directive|define
name|SGX_LOCKFAIL
value|7
end_define

begin_comment
comment|/* EBLOCK, EMODPR, EMODT */
end_comment

begin_define
define|#
directive|define
name|SGX_INVALID_SIGNATURE
value|8
end_define

begin_comment
comment|/* EINIT */
end_comment

begin_define
define|#
directive|define
name|SGX_MAC_COMPARE_FAIL
value|9
end_define

begin_comment
comment|/* ELDB, ELDU */
end_comment

begin_define
define|#
directive|define
name|SGX_PAGE_NOT_BLOCKED
value|10
end_define

begin_comment
comment|/* EWB */
end_comment

begin_define
define|#
directive|define
name|SGX_NOT_TRACKED
value|11
end_define

begin_comment
comment|/* EWB, EACCEPT */
end_comment

begin_define
define|#
directive|define
name|SGX_VA_SLOT_OCCUPIED
value|12
end_define

begin_comment
comment|/* EWB */
end_comment

begin_define
define|#
directive|define
name|SGX_CHILD_PRESENT
value|13
end_define

begin_comment
comment|/* EWB, EREMOVE */
end_comment

begin_define
define|#
directive|define
name|SGX_ENCLAVE_ACT
value|14
end_define

begin_comment
comment|/* EREMOVE */
end_comment

begin_define
define|#
directive|define
name|SGX_ENTRYEPOCH_LOCKED
value|15
end_define

begin_comment
comment|/* EBLOCK */
end_comment

begin_define
define|#
directive|define
name|SGX_INVALID_EINIT_TOKEN
value|16
end_define

begin_comment
comment|/* EINIT */
end_comment

begin_define
define|#
directive|define
name|SGX_PREV_TRK_INCMPL
value|17
end_define

begin_comment
comment|/* ETRACK */
end_comment

begin_define
define|#
directive|define
name|SGX_PG_IS_SECS
value|18
end_define

begin_comment
comment|/* EBLOCK */
end_comment

begin_define
define|#
directive|define
name|SGX_PAGE_ATTRIBUTES_MISMATCH
value|19
end_define

begin_comment
comment|/* EACCEPT, EACCEPTCOPY */
end_comment

begin_define
define|#
directive|define
name|SGX_PAGE_NOT_MODIFIABLE
value|20
end_define

begin_comment
comment|/* EMODPR, EMODT */
end_comment

begin_define
define|#
directive|define
name|SGX_INVALID_CPUSVN
value|32
end_define

begin_comment
comment|/* EINIT, EGETKEY */
end_comment

begin_define
define|#
directive|define
name|SGX_INVALID_ISVSVN
value|64
end_define

begin_comment
comment|/* EGETKEY */
end_comment

begin_define
define|#
directive|define
name|SGX_UNMASKED_EVENT
value|128
end_define

begin_comment
comment|/* EINIT */
end_comment

begin_define
define|#
directive|define
name|SGX_INVALID_KEYNAME
value|256
end_define

begin_comment
comment|/* EGETKEY */
end_comment

begin_comment
comment|/*  * 2.10 Page Information (PAGEINFO)  * PAGEINFO is an architectural data structure that is used as a parameter  * to the EPC-management instructions. It requires 32-Byte alignment.  */
end_comment

begin_struct
struct|struct
name|page_info
block|{
name|uint64_t
name|linaddr
decl_stmt|;
name|uint64_t
name|srcpge
decl_stmt|;
union|union
block|{
name|struct
name|secinfo
modifier|*
name|secinfo
decl_stmt|;
name|uint64_t
name|pcmd
decl_stmt|;
block|}
union|;
name|uint64_t
name|secs
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|32
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * 2.11 Security Information (SECINFO)  * The SECINFO data structure holds meta-data about an enclave page.  */
end_comment

begin_struct
struct|struct
name|secinfo
block|{
name|uint64_t
name|flags
decl_stmt|;
define|#
directive|define
name|SECINFO_FLAGS_PT_S
value|8
comment|/* Page type shift */
define|#
directive|define
name|SECINFO_FLAGS_PT_M
value|(0xff<< SECINFO_FLAGS_PT_S)
name|uint64_t
name|reserved
index|[
literal|7
index|]
decl_stmt|;
block|}
name|__aligned
argument_list|(
literal|64
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * 2.7.1 ATTRIBUTES  * The ATTRIBUTES data structure is comprised of bit-granular fields that  * are used in the SECS, CPUID enumeration, the REPORT and the KEYREQUEST  * structures.  */
end_comment

begin_struct
struct|struct
name|secs_attr
block|{
name|uint8_t
name|reserved1
range|:
literal|1
decl_stmt|;
name|uint8_t
name|debug
range|:
literal|1
decl_stmt|;
name|uint8_t
name|mode64bit
range|:
literal|1
decl_stmt|;
name|uint8_t
name|reserved2
range|:
literal|1
decl_stmt|;
name|uint8_t
name|provisionkey
range|:
literal|1
decl_stmt|;
name|uint8_t
name|einittokenkey
range|:
literal|1
decl_stmt|;
name|uint8_t
name|reserved3
range|:
literal|2
decl_stmt|;
define|#
directive|define
name|SECS_ATTR_RSV4_SIZE
value|7
name|uint8_t
name|reserved4
index|[
name|SECS_ATTR_RSV4_SIZE
index|]
decl_stmt|;
name|uint64_t
name|xfrm
decl_stmt|;
comment|/* X-Feature Request Mask */
block|}
struct|;
end_struct

begin_comment
comment|/*  * 2.7 SGX Enclave Control Structure (SECS)  * The SECS data structure requires 4K-Bytes alignment.  */
end_comment

begin_struct
struct|struct
name|secs
block|{
name|uint64_t
name|size
decl_stmt|;
name|uint64_t
name|base
decl_stmt|;
name|uint32_t
name|ssa_frame_size
decl_stmt|;
name|uint32_t
name|misc_select
decl_stmt|;
define|#
directive|define
name|SECS_RSV1_SIZE
value|24
name|uint8_t
name|reserved1
index|[
name|SECS_RSV1_SIZE
index|]
decl_stmt|;
name|struct
name|secs_attr
name|attributes
decl_stmt|;
name|uint8_t
name|mr_enclave
index|[
literal|32
index|]
decl_stmt|;
define|#
directive|define
name|SECS_RSV2_SIZE
value|32
name|uint8_t
name|reserved2
index|[
name|SECS_RSV2_SIZE
index|]
decl_stmt|;
name|uint8_t
name|mr_signer
index|[
literal|32
index|]
decl_stmt|;
define|#
directive|define
name|SECS_RSV3_SIZE
value|96
name|uint8_t
name|reserved3
index|[
name|SECS_RSV3_SIZE
index|]
decl_stmt|;
name|uint16_t
name|isv_prod_id
decl_stmt|;
name|uint16_t
name|isv_svn
decl_stmt|;
define|#
directive|define
name|SECS_RSV4_SIZE
value|3836
name|uint8_t
name|reserved4
index|[
name|SECS_RSV4_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * 2.8 Thread Control Structure (TCS)  * Each executing thread in the enclave is associated with a  * Thread Control Structure. It requires 4K-Bytes alignment.  */
end_comment

begin_struct
struct|struct
name|tcs
block|{
name|uint64_t
name|reserved1
decl_stmt|;
name|uint64_t
name|flags
decl_stmt|;
name|uint64_t
name|ossa
decl_stmt|;
name|uint32_t
name|cssa
decl_stmt|;
name|uint32_t
name|nssa
decl_stmt|;
name|uint64_t
name|oentry
decl_stmt|;
name|uint64_t
name|reserved2
decl_stmt|;
name|uint64_t
name|ofsbasgx
decl_stmt|;
name|uint64_t
name|ogsbasgx
decl_stmt|;
name|uint32_t
name|fslimit
decl_stmt|;
name|uint32_t
name|gslimit
decl_stmt|;
name|uint64_t
name|reserved3
index|[
literal|503
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SGXREG_H_ */
end_comment

end_unit

