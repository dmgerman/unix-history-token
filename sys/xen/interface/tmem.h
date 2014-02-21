begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * tmem.h  *   * Guest OS interface to Xen Transcendent Memory.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2004, K A Fraser  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_TMEM_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_TMEM_H__
end_define

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_comment
comment|/* version of ABI */
end_comment

begin_define
define|#
directive|define
name|TMEM_SPEC_VERSION
value|1
end_define

begin_comment
comment|/* Commands to HYPERVISOR_tmem_op() */
end_comment

begin_define
define|#
directive|define
name|TMEM_CONTROL
value|0
end_define

begin_define
define|#
directive|define
name|TMEM_NEW_POOL
value|1
end_define

begin_define
define|#
directive|define
name|TMEM_DESTROY_POOL
value|2
end_define

begin_define
define|#
directive|define
name|TMEM_NEW_PAGE
value|3
end_define

begin_define
define|#
directive|define
name|TMEM_PUT_PAGE
value|4
end_define

begin_define
define|#
directive|define
name|TMEM_GET_PAGE
value|5
end_define

begin_define
define|#
directive|define
name|TMEM_FLUSH_PAGE
value|6
end_define

begin_define
define|#
directive|define
name|TMEM_FLUSH_OBJECT
value|7
end_define

begin_define
define|#
directive|define
name|TMEM_READ
value|8
end_define

begin_define
define|#
directive|define
name|TMEM_WRITE
value|9
end_define

begin_define
define|#
directive|define
name|TMEM_XCHG
value|10
end_define

begin_comment
comment|/* Privileged commands to HYPERVISOR_tmem_op() */
end_comment

begin_define
define|#
directive|define
name|TMEM_AUTH
value|101
end_define

begin_define
define|#
directive|define
name|TMEM_RESTORE_NEW
value|102
end_define

begin_comment
comment|/* Subops for HYPERVISOR_tmem_op(TMEM_CONTROL) */
end_comment

begin_define
define|#
directive|define
name|TMEMC_THAW
value|0
end_define

begin_define
define|#
directive|define
name|TMEMC_FREEZE
value|1
end_define

begin_define
define|#
directive|define
name|TMEMC_FLUSH
value|2
end_define

begin_define
define|#
directive|define
name|TMEMC_DESTROY
value|3
end_define

begin_define
define|#
directive|define
name|TMEMC_LIST
value|4
end_define

begin_define
define|#
directive|define
name|TMEMC_SET_WEIGHT
value|5
end_define

begin_define
define|#
directive|define
name|TMEMC_SET_CAP
value|6
end_define

begin_define
define|#
directive|define
name|TMEMC_SET_COMPRESS
value|7
end_define

begin_define
define|#
directive|define
name|TMEMC_QUERY_FREEABLE_MB
value|8
end_define

begin_define
define|#
directive|define
name|TMEMC_SAVE_BEGIN
value|10
end_define

begin_define
define|#
directive|define
name|TMEMC_SAVE_GET_VERSION
value|11
end_define

begin_define
define|#
directive|define
name|TMEMC_SAVE_GET_MAXPOOLS
value|12
end_define

begin_define
define|#
directive|define
name|TMEMC_SAVE_GET_CLIENT_WEIGHT
value|13
end_define

begin_define
define|#
directive|define
name|TMEMC_SAVE_GET_CLIENT_CAP
value|14
end_define

begin_define
define|#
directive|define
name|TMEMC_SAVE_GET_CLIENT_FLAGS
value|15
end_define

begin_define
define|#
directive|define
name|TMEMC_SAVE_GET_POOL_FLAGS
value|16
end_define

begin_define
define|#
directive|define
name|TMEMC_SAVE_GET_POOL_NPAGES
value|17
end_define

begin_define
define|#
directive|define
name|TMEMC_SAVE_GET_POOL_UUID
value|18
end_define

begin_define
define|#
directive|define
name|TMEMC_SAVE_GET_NEXT_PAGE
value|19
end_define

begin_define
define|#
directive|define
name|TMEMC_SAVE_GET_NEXT_INV
value|20
end_define

begin_define
define|#
directive|define
name|TMEMC_SAVE_END
value|21
end_define

begin_define
define|#
directive|define
name|TMEMC_RESTORE_BEGIN
value|30
end_define

begin_define
define|#
directive|define
name|TMEMC_RESTORE_PUT_PAGE
value|32
end_define

begin_define
define|#
directive|define
name|TMEMC_RESTORE_FLUSH_PAGE
value|33
end_define

begin_comment
comment|/* Bits for HYPERVISOR_tmem_op(TMEM_NEW_POOL) */
end_comment

begin_define
define|#
directive|define
name|TMEM_POOL_PERSIST
value|1
end_define

begin_define
define|#
directive|define
name|TMEM_POOL_SHARED
value|2
end_define

begin_define
define|#
directive|define
name|TMEM_POOL_PRECOMPRESSED
value|4
end_define

begin_define
define|#
directive|define
name|TMEM_POOL_PAGESIZE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|TMEM_POOL_PAGESIZE_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|TMEM_POOL_VERSION_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|TMEM_POOL_VERSION_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|TMEM_POOL_RESERVED_BITS
value|0x00ffff00
end_define

begin_comment
comment|/* Bits for client flags (save/restore) */
end_comment

begin_define
define|#
directive|define
name|TMEM_CLIENT_COMPRESS
value|1
end_define

begin_define
define|#
directive|define
name|TMEM_CLIENT_FROZEN
value|2
end_define

begin_comment
comment|/* Special errno values */
end_comment

begin_define
define|#
directive|define
name|EFROZEN
value|1000
end_define

begin_define
define|#
directive|define
name|EEMPTY
value|1001
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_typedef
typedef|typedef
name|xen_pfn_t
name|tmem_cli_mfn_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XEN_GUEST_HANDLE
argument_list|(
argument|char
argument_list|)
name|tmem_cli_va_t
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|tmem_op
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|int32_t
name|pool_id
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint64_t
name|uuid
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|arg1
decl_stmt|;
block|}
name|creat
struct|;
comment|/* for cmd == TMEM_NEW_POOL, TMEM_AUTH, TMEM_RESTORE_NEW */
struct|struct
block|{
name|uint32_t
name|subop
decl_stmt|;
name|uint32_t
name|cli_id
decl_stmt|;
name|uint32_t
name|arg1
decl_stmt|;
name|uint32_t
name|arg2
decl_stmt|;
name|uint64_t
name|oid
index|[
literal|3
index|]
decl_stmt|;
name|tmem_cli_va_t
name|buf
decl_stmt|;
block|}
name|ctrl
struct|;
comment|/* for cmd == TMEM_CONTROL */
struct|struct
block|{
name|uint64_t
name|oid
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|index
decl_stmt|;
name|uint32_t
name|tmem_offset
decl_stmt|;
name|uint32_t
name|pfn_offset
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|tmem_cli_mfn_t
name|cmfn
decl_stmt|;
comment|/* client machine page frame */
block|}
name|gen
struct|;
comment|/* for all other cmd ("generic") */
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|tmem_op
name|tmem_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|tmem_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|tmem_handle
block|{
name|uint32_t
name|pool_id
decl_stmt|;
name|uint32_t
name|index
decl_stmt|;
name|uint64_t
name|oid
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_TMEM_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

