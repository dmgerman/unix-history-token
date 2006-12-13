begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: compress.h,v 1.29.2.2.8.3 2006/03/02 00:37:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_COMPRESS_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_COMPRESS_H
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
file|<isc/region.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_define
define|#
directive|define
name|DNS_COMPRESS_NONE
value|0x00
end_define

begin_comment
comment|/* no compression */
end_comment

begin_define
define|#
directive|define
name|DNS_COMPRESS_GLOBAL14
value|0x01
end_define

begin_comment
comment|/* "normal" compression. */
end_comment

begin_define
define|#
directive|define
name|DNS_COMPRESS_ALL
value|0x01
end_define

begin_comment
comment|/* all compression. */
end_comment

begin_comment
comment|/*  *	Direct manipulation of the structures is strongly discouraged.  */
end_comment

begin_define
define|#
directive|define
name|DNS_COMPRESS_TABLESIZE
value|64
end_define

begin_define
define|#
directive|define
name|DNS_COMPRESS_INITIALNODES
value|16
end_define

begin_typedef
typedef|typedef
name|struct
name|dns_compressnode
name|dns_compressnode_t
typedef|;
end_typedef

begin_struct
struct|struct
name|dns_compressnode
block|{
name|isc_region_t
name|r
decl_stmt|;
name|isc_uint16_t
name|offset
decl_stmt|;
name|isc_uint16_t
name|count
decl_stmt|;
name|isc_uint8_t
name|labels
decl_stmt|;
name|dns_compressnode_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dns_compress
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
comment|/* Magic number. */
name|unsigned
name|int
name|allowed
decl_stmt|;
comment|/* Allowed methods. */
name|int
name|edns
decl_stmt|;
comment|/* Edns version or -1. */
comment|/* Global compression table. */
name|dns_compressnode_t
modifier|*
name|table
index|[
name|DNS_COMPRESS_TABLESIZE
index|]
decl_stmt|;
comment|/* Preallocated nodes for the table. */
name|dns_compressnode_t
name|initialnodes
index|[
name|DNS_COMPRESS_INITIALNODES
index|]
decl_stmt|;
name|isc_uint16_t
name|count
decl_stmt|;
comment|/* Number of nodes. */
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
comment|/* Memory context. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|DNS_DECOMPRESS_ANY
block|,
comment|/* Any compression */
name|DNS_DECOMPRESS_STRICT
block|,
comment|/* Allowed compression */
name|DNS_DECOMPRESS_NONE
comment|/* No compression */
block|}
name|dns_decompresstype_t
typedef|;
end_typedef

begin_struct
struct|struct
name|dns_decompress
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
comment|/* Magic number. */
name|unsigned
name|int
name|allowed
decl_stmt|;
comment|/* Allowed methods. */
name|int
name|edns
decl_stmt|;
comment|/* Edns version or -1. */
name|dns_decompresstype_t
name|type
decl_stmt|;
comment|/* Strict checking */
block|}
struct|;
end_struct

begin_function_decl
name|isc_result_t
name|dns_compress_init
parameter_list|(
name|dns_compress_t
modifier|*
name|cctx
parameter_list|,
name|int
name|edns
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Inialise the compression context structure pointed to by 'cctx'.  *  *	Requires:  *		'cctx' is a valid dns_compress_t structure.  *		'mctx' is an initialized memory context.  *	Ensures:  *		cctx->global is initialized.  *  *	Returns:  *		ISC_R_SUCCESS  *		failures from dns_rbt_create()  */
end_comment

begin_function_decl
name|void
name|dns_compress_invalidate
parameter_list|(
name|dns_compress_t
modifier|*
name|cctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Invalidate the compression structure pointed to by cctx.  *  *	Requires:  *		'cctx' to be initialized.  */
end_comment

begin_function_decl
name|void
name|dns_compress_setmethods
parameter_list|(
name|dns_compress_t
modifier|*
name|cctx
parameter_list|,
name|unsigned
name|int
name|allowed
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Sets allowed compression methods.  *  *	Requires:  *		'cctx' to be initialized.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|dns_compress_getmethods
parameter_list|(
name|dns_compress_t
modifier|*
name|cctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Gets allowed compression methods.  *  *	Requires:  *		'cctx' to be initialized.  *  *	Returns:  *		allowed compression bitmap.  */
end_comment

begin_function_decl
name|int
name|dns_compress_getedns
parameter_list|(
name|dns_compress_t
modifier|*
name|cctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Gets edns value.  *  *	Requires:  *		'cctx' to be initialized.  *  *	Returns:  *		-1 .. 255  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_compress_findglobal
parameter_list|(
name|dns_compress_t
modifier|*
name|cctx
parameter_list|,
specifier|const
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_name_t
modifier|*
name|prefix
parameter_list|,
name|isc_uint16_t
modifier|*
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Finds longest possible match of 'name' in the global compression table.  *  *	Requires:  *		'cctx' to be initialized.  *		'name' to be a absolute name.  *		'prefix' to be initialized.  *		'offset' to point to an isc_uint16_t.  *  *	Ensures:  *		'prefix' and 'offset' are valid if ISC_TRUE is 	returned.  *  *	Returns:  *		ISC_TRUE / ISC_FALSE  */
end_comment

begin_function_decl
name|void
name|dns_compress_add
parameter_list|(
name|dns_compress_t
modifier|*
name|cctx
parameter_list|,
specifier|const
name|dns_name_t
modifier|*
name|name
parameter_list|,
specifier|const
name|dns_name_t
modifier|*
name|prefix
parameter_list|,
name|isc_uint16_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Add compression pointers for 'name' to the compression table,  *	not replacing existing pointers.  *  *	Requires:  *		'cctx' initialized  *  *		'name' must be initialized and absolute, and must remain  *		valid until the message compression is complete.  *  *		'prefix' must be a prefix returned by  *		dns_compress_findglobal(), or the same as 'name'.  */
end_comment

begin_function_decl
name|void
name|dns_compress_rollback
parameter_list|(
name|dns_compress_t
modifier|*
name|cctx
parameter_list|,
name|isc_uint16_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Remove any compression pointers from global table>= offset.  *  *	Requires:  *		'cctx' is initialized.  */
end_comment

begin_function_decl
name|void
name|dns_decompress_init
parameter_list|(
name|dns_decompress_t
modifier|*
name|dctx
parameter_list|,
name|int
name|edns
parameter_list|,
name|dns_decompresstype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Initializes 'dctx'.  *	Records 'edns' and 'type' into the structure.  *  *	Requires:  *		'dctx' to be a valid pointer.  */
end_comment

begin_function_decl
name|void
name|dns_decompress_invalidate
parameter_list|(
name|dns_decompress_t
modifier|*
name|dctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Invalidates 'dctx'.  *  *	Requires:  *		'dctx' to be initialized  */
end_comment

begin_function_decl
name|void
name|dns_decompress_setmethods
parameter_list|(
name|dns_decompress_t
modifier|*
name|dctx
parameter_list|,
name|unsigned
name|int
name|allowed
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Sets 'dctx->allowed' to 'allowed'.  *  *	Requires:  *		'dctx' to be initialized  */
end_comment

begin_function_decl
name|unsigned
name|int
name|dns_decompress_getmethods
parameter_list|(
name|dns_decompress_t
modifier|*
name|dctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Returns 'dctx->allowed'  *  *	Requires:  *		'dctx' to be initialized  */
end_comment

begin_function_decl
name|int
name|dns_decompress_edns
parameter_list|(
name|dns_decompress_t
modifier|*
name|dctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Returns 'dctx->edns'  *  *	Requires:  *		'dctx' to be initialized  */
end_comment

begin_function_decl
name|dns_decompresstype_t
name|dns_decompress_type
parameter_list|(
name|dns_decompress_t
modifier|*
name|dctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Returns 'dctx->type'  *  *	Requires:  *		'dctx' to be initialized  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_COMPRESS_H */
end_comment

end_unit

