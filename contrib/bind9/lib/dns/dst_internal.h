begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Portions Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (C) 2000-2002  Internet Software Consortium.  * Portions Copyright (C) 1995-2000 by Network Associates, Inc.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC AND NETWORK ASSOCIATES DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE  * FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR  * IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: dst_internal.h,v 1.1.4.1 2004/12/09 04:07:16 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DST_DST_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|DST_DST_INTERNAL_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/buffer.h>
end_include

begin_include
include|#
directive|include
file|<isc/int.h>
end_include

begin_include
include|#
directive|include
file|<isc/magic.h>
end_include

begin_include
include|#
directive|include
file|<isc/region.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<dst/dst.h>
end_include

begin_decl_stmt
name|ISC_LANG_BEGINDECLS
define|#
directive|define
name|KEY_MAGIC
value|ISC_MAGIC('D','S','T','K')
define|#
directive|define
name|CTX_MAGIC
value|ISC_MAGIC('D','S','T','C')
define|#
directive|define
name|VALID_KEY
parameter_list|(
name|x
parameter_list|)
value|ISC_MAGIC_VALID(x, KEY_MAGIC)
define|#
directive|define
name|VALID_CTX
parameter_list|(
name|x
parameter_list|)
value|ISC_MAGIC_VALID(x, CTX_MAGIC)
specifier|extern
name|isc_mem_t
modifier|*
name|dst__memory_pool
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_typedef
typedef|typedef
name|struct
name|dst_func
name|dst_func_t
typedef|;
end_typedef

begin_struct
struct|struct
name|dst_key
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|dns_name_t
modifier|*
name|key_name
decl_stmt|;
comment|/* name of the key */
name|unsigned
name|int
name|key_size
decl_stmt|;
comment|/* size of the key in bits */
name|unsigned
name|int
name|key_proto
decl_stmt|;
comment|/* protocols this key is used for */
name|unsigned
name|int
name|key_alg
decl_stmt|;
comment|/* algorithm of the key */
name|isc_uint32_t
name|key_flags
decl_stmt|;
comment|/* flags of the public key */
name|isc_uint16_t
name|key_id
decl_stmt|;
comment|/* identifier of the key */
name|dns_rdataclass_t
name|key_class
decl_stmt|;
comment|/* class of the key record */
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
comment|/* memory context */
name|void
modifier|*
name|opaque
decl_stmt|;
comment|/* pointer to key in crypto pkg fmt */
name|dst_func_t
modifier|*
name|func
decl_stmt|;
comment|/* crypto package specific functions */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dst_context
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|dst_key_t
modifier|*
name|key
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|void
modifier|*
name|opaque
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dst_func
block|{
comment|/* 	 * Context functions 	 */
name|isc_result_t
function_decl|(
modifier|*
name|createctx
function_decl|)
parameter_list|(
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|dst_context_t
modifier|*
name|dctx
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|destroyctx
function_decl|)
parameter_list|(
name|dst_context_t
modifier|*
name|dctx
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|adddata
function_decl|)
parameter_list|(
name|dst_context_t
modifier|*
name|dctx
parameter_list|,
specifier|const
name|isc_region_t
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/* 	 * Key operations 	 */
name|isc_result_t
function_decl|(
modifier|*
name|sign
function_decl|)
parameter_list|(
name|dst_context_t
modifier|*
name|dctx
parameter_list|,
name|isc_buffer_t
modifier|*
name|sig
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|verify
function_decl|)
parameter_list|(
name|dst_context_t
modifier|*
name|dctx
parameter_list|,
specifier|const
name|isc_region_t
modifier|*
name|sig
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|computesecret
function_decl|)
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|pub
parameter_list|,
specifier|const
name|dst_key_t
modifier|*
name|priv
parameter_list|,
name|isc_buffer_t
modifier|*
name|secret
parameter_list|)
function_decl|;
name|isc_boolean_t
function_decl|(
modifier|*
name|compare
function_decl|)
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key1
parameter_list|,
specifier|const
name|dst_key_t
modifier|*
name|key2
parameter_list|)
function_decl|;
name|isc_boolean_t
function_decl|(
modifier|*
name|paramcompare
function_decl|)
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key1
parameter_list|,
specifier|const
name|dst_key_t
modifier|*
name|key2
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|generate
function_decl|)
parameter_list|(
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|int
name|parms
parameter_list|)
function_decl|;
name|isc_boolean_t
function_decl|(
modifier|*
name|isprivate
function_decl|)
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|dst_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
comment|/* conversion functions */
name|isc_result_t
function_decl|(
modifier|*
name|todns
function_decl|)
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|isc_buffer_t
modifier|*
name|data
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|fromdns
function_decl|)
parameter_list|(
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|isc_buffer_t
modifier|*
name|data
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|tofile
function_decl|)
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|,
specifier|const
name|char
modifier|*
name|directory
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|parse
function_decl|)
parameter_list|(
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|isc_lex_t
modifier|*
name|lexer
parameter_list|)
function_decl|;
comment|/* cleanup */
name|void
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Initializers  */
end_comment

begin_function_decl
name|isc_result_t
name|dst__openssl_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dst__hmacmd5_init
parameter_list|(
name|struct
name|dst_func
modifier|*
modifier|*
name|funcp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dst__opensslrsa_init
parameter_list|(
name|struct
name|dst_func
modifier|*
modifier|*
name|funcp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dst__openssldsa_init
parameter_list|(
name|struct
name|dst_func
modifier|*
modifier|*
name|funcp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dst__openssldh_init
parameter_list|(
name|struct
name|dst_func
modifier|*
modifier|*
name|funcp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dst__gssapi_init
parameter_list|(
name|struct
name|dst_func
modifier|*
modifier|*
name|funcp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destructors  */
end_comment

begin_function_decl
name|void
name|dst__openssl_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Memory allocators using the DST memory pool.  */
end_comment

begin_function_decl
name|void
modifier|*
name|dst__mem_alloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dst__mem_free
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|dst__mem_realloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Entropy retriever using the DST entropy pool.  */
end_comment

begin_function_decl
name|isc_result_t
name|dst__entropy_getdata
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|,
name|isc_boolean_t
name|pseudo
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DST_DST_INTERNAL_H */
end_comment

end_unit

