begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: citrus_namespace.h,v 1.8 2009/01/11 02:46:24 christos Exp $ */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause  *  * Copyright (c)2003 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"citrus_bcs.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_NAMESPACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_CITRUS_NAMESPACE_H_
end_define

begin_comment
comment|/* citrus_alias */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_ALIAS_NO_NAMESPACE
end_ifndef

begin_define
define|#
directive|define
name|_alias_lookup
value|_citrus_alias_lookup
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CITRUS_ALIAS_NO_NAMESPACE */
end_comment

begin_comment
comment|/* citrus_bcs */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_BCS_NO_NAMESPACE
end_ifndef

begin_define
define|#
directive|define
name|_bcs_isalnum
value|_citrus_bcs_isalnum
end_define

begin_define
define|#
directive|define
name|_bcs_isalpha
value|_citrus_bcs_isalpha
end_define

begin_define
define|#
directive|define
name|_bcs_isblank
value|_citrus_bcs_isblank
end_define

begin_define
define|#
directive|define
name|_bcs_isdigit
value|_citrus_bcs_isdigit
end_define

begin_define
define|#
directive|define
name|_bcs_islower
value|_citrus_bcs_islower
end_define

begin_define
define|#
directive|define
name|_bcs_iseol
value|_citrus_bcs_iseol
end_define

begin_define
define|#
directive|define
name|_bcs_isspace
value|_citrus_bcs_isspace
end_define

begin_define
define|#
directive|define
name|_bcs_isupper
value|_citrus_bcs_isupper
end_define

begin_define
define|#
directive|define
name|_bcs_isxdigit
value|_citrus_bcs_isxdigit
end_define

begin_define
define|#
directive|define
name|_bcs_skip_nonws
value|_citrus_bcs_skip_nonws
end_define

begin_define
define|#
directive|define
name|_bcs_skip_nonws_len
value|_citrus_bcs_skip_nonws_len
end_define

begin_define
define|#
directive|define
name|_bcs_skip_ws
value|_citrus_bcs_skip_ws
end_define

begin_define
define|#
directive|define
name|_bcs_skip_ws_len
value|_citrus_bcs_skip_ws_len
end_define

begin_define
define|#
directive|define
name|_bcs_strcasecmp
value|_citrus_bcs_strcasecmp
end_define

begin_define
define|#
directive|define
name|_bcs_strncasecmp
value|_citrus_bcs_strncasecmp
end_define

begin_define
define|#
directive|define
name|_bcs_tolower
value|_citrus_bcs_tolower
end_define

begin_define
define|#
directive|define
name|_bcs_toupper
value|_citrus_bcs_toupper
end_define

begin_define
define|#
directive|define
name|_bcs_trunc_rws_len
value|_citrus_bcs_trunc_rws_len
end_define

begin_define
define|#
directive|define
name|_bcs_convert_to_lower
value|_citrus_bcs_convert_to_lower
end_define

begin_define
define|#
directive|define
name|_bcs_convert_to_upper
value|_citrus_bcs_convert_to_upper
end_define

begin_define
define|#
directive|define
name|_bcs_strtol
value|_citrus_bcs_strtol
end_define

begin_define
define|#
directive|define
name|_bcs_strtoul
value|_citrus_bcs_strtoul
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CITRUS_BCS_NO_NAMESPACE */
end_comment

begin_comment
comment|/* citrus_csmapper */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_CSMAPPER_NO_NAMESPACE
end_ifndef

begin_define
define|#
directive|define
name|_csmapper
value|_citrus_csmapper
end_define

begin_define
define|#
directive|define
name|_csmapper_open
value|_citrus_csmapper_open
end_define

begin_define
define|#
directive|define
name|_csmapper_close
value|_citrus_csmapper_close
end_define

begin_define
define|#
directive|define
name|_csmapper_convert
value|_citrus_csmapper_convert
end_define

begin_define
define|#
directive|define
name|_csmapper_init_state
value|_citrus_csmapper_init_state
end_define

begin_define
define|#
directive|define
name|_csmapper_get_state_size
value|_citrus_csmapper_get_state_size
end_define

begin_define
define|#
directive|define
name|_csmapper_get_src_max
value|_citrus_csmapper_get_src_max
end_define

begin_define
define|#
directive|define
name|_csmapper_get_dst_max
value|_citrus_csmapper_get_dst_max
end_define

begin_define
define|#
directive|define
name|_CSMAPPER_F_PREVENT_PIVOT
value|_CITRUS_CSMAPPER_F_PREVENT_PIVOT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CITRUS_CSMAPPER_NO_NAMESPACE */
end_comment

begin_comment
comment|/* citrus_db */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_DB_NO_NAMESPACE
end_ifndef

begin_define
define|#
directive|define
name|_db_open
value|_citrus_db_open
end_define

begin_define
define|#
directive|define
name|_db_close
value|_citrus_db_close
end_define

begin_define
define|#
directive|define
name|_db_lookup
value|_citrus_db_lookup
end_define

begin_define
define|#
directive|define
name|_db_lookup_by_s
value|_citrus_db_lookup_by_string
end_define

begin_define
define|#
directive|define
name|_db_lookup8_by_s
value|_citrus_db_lookup8_by_string
end_define

begin_define
define|#
directive|define
name|_db_lookup16_by_s
value|_citrus_db_lookup16_by_string
end_define

begin_define
define|#
directive|define
name|_db_lookup32_by_s
value|_citrus_db_lookup32_by_string
end_define

begin_define
define|#
directive|define
name|_db_lookupstr_by_s
value|_citrus_db_lookup_string_by_string
end_define

begin_define
define|#
directive|define
name|_db_hash_std
value|_citrus_db_hash_std
end_define

begin_define
define|#
directive|define
name|_db_get_num_entries
value|_citrus_db_get_number_of_entries
end_define

begin_define
define|#
directive|define
name|_db_get_entry
value|_citrus_db_get_entry
end_define

begin_define
define|#
directive|define
name|_db_locator
value|_citrus_db_locator
end_define

begin_define
define|#
directive|define
name|_db_locator_init
value|_citrus_db_locator_init
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CITRUS_DB_NO_NAMESPACE */
end_comment

begin_comment
comment|/* citrus_db_factory */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_DB_FACTORY_NO_NAMESPACE
end_ifndef

begin_define
define|#
directive|define
name|_db_factory
value|_citrus_db_factory
end_define

begin_define
define|#
directive|define
name|_db_factory_create
value|_citrus_db_factory_create
end_define

begin_define
define|#
directive|define
name|_db_factory_free
value|_citrus_db_factory_free
end_define

begin_define
define|#
directive|define
name|_db_factory_add
value|_citrus_db_factory_add
end_define

begin_define
define|#
directive|define
name|_db_factory_add_by_s
value|_citrus_db_factory_add_by_string
end_define

begin_define
define|#
directive|define
name|_db_factory_add8_by_s
value|_citrus_db_factory_add8_by_string
end_define

begin_define
define|#
directive|define
name|_db_factory_add16_by_s
value|_citrus_db_factory_add16_by_string
end_define

begin_define
define|#
directive|define
name|_db_factory_add32_by_s
value|_citrus_db_factory_add32_by_string
end_define

begin_define
define|#
directive|define
name|_db_factory_addstr_by_s
value|_citrus_db_factory_add_string_by_string
end_define

begin_define
define|#
directive|define
name|_db_factory_calc_size
value|_citrus_db_factory_calc_size
end_define

begin_define
define|#
directive|define
name|_db_factory_serialize
value|_citrus_db_factory_serialize
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CITRUS_DB_FACTORY_NO_NAMESPACE */
end_comment

begin_comment
comment|/* citrus_lookup */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_DB_NO_NAMESPACE
end_ifndef

begin_define
define|#
directive|define
name|_LOOKUP_CASE_SENSITIVE
value|_CITRUS_LOOKUP_CASE_SENSITIVE
end_define

begin_define
define|#
directive|define
name|_LOOKUP_CASE_IGNORE
value|_CITRUS_LOOKUP_CASE_IGNORE
end_define

begin_define
define|#
directive|define
name|_lookup
value|_citrus_lookup
end_define

begin_define
define|#
directive|define
name|_lookup_simple
value|_citrus_lookup_simple
end_define

begin_define
define|#
directive|define
name|_lookup_alias
value|_citrus_lookup_alias
end_define

begin_define
define|#
directive|define
name|_lookup_seq_open
value|_citrus_lookup_seq_open
end_define

begin_define
define|#
directive|define
name|_lookup_seq_rewind
value|_citrus_lookup_seq_rewind
end_define

begin_define
define|#
directive|define
name|_lookup_seq_next
value|_citrus_lookup_seq_next
end_define

begin_define
define|#
directive|define
name|_lookup_seq_lookup
value|_citrus_lookup_seq_lookup
end_define

begin_define
define|#
directive|define
name|_lookup_get_num_entries
value|_citrus_lookup_get_number_of_entries
end_define

begin_define
define|#
directive|define
name|_lookup_seq_close
value|_citrus_lookup_seq_close
end_define

begin_define
define|#
directive|define
name|_lookup_factory_convert
value|_citrus_lookup_factory_convert
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CITRUS_DB_NO_NAMESPACE */
end_comment

begin_comment
comment|/* citrus_esdb */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_ESDB_NO_NAMESPACE
end_ifndef

begin_define
define|#
directive|define
name|_esdb
value|_citrus_esdb
end_define

begin_define
define|#
directive|define
name|_esdb_charset
value|_citrus_esdb_charset
end_define

begin_define
define|#
directive|define
name|_esdb_open
value|_citrus_esdb_open
end_define

begin_define
define|#
directive|define
name|_esdb_close
value|_citrus_esdb_close
end_define

begin_define
define|#
directive|define
name|_esdb_get_list
value|_citrus_esdb_get_list
end_define

begin_define
define|#
directive|define
name|_esdb_free_list
value|_citrus_esdb_free_list
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CITRUS_ESDB_NO_NAMESPACE */
end_comment

begin_comment
comment|/* citrus_hash */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_HASH_NO_NAMESPACE
end_ifndef

begin_define
define|#
directive|define
name|_citrus_string_hash_func
value|_string_hash_func
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CITRUS_HASH_NO_NAMESPACE */
end_comment

begin_comment
comment|/* citrus_mapper */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_MAPPER_NO_NAMESPACE
end_ifndef

begin_define
define|#
directive|define
name|_mapper
value|_citrus_mapper
end_define

begin_define
define|#
directive|define
name|_mapper_ops
value|_citrus_mapper_ops
end_define

begin_define
define|#
directive|define
name|_mapper_traits
value|_citrus_mapper_traits
end_define

begin_define
define|#
directive|define
name|_mapper_open
value|_citrus_mapper_open
end_define

begin_define
define|#
directive|define
name|_mapper_open_direct
value|_citrus_mapper_open_direct
end_define

begin_define
define|#
directive|define
name|_mapper_close
value|_citrus_mapper_close
end_define

begin_define
define|#
directive|define
name|_MAPPER_CONVERT_SUCCESS
value|_CITRUS_MAPPER_CONVERT_SUCCESS
end_define

begin_define
define|#
directive|define
name|_MAPPER_CONVERT_NONIDENTICAL
value|_CITRUS_MAPPER_CONVERT_NONIDENTICAL
end_define

begin_define
define|#
directive|define
name|_MAPPER_CONVERT_SRC_MORE
value|_CITRUS_MAPPER_CONVERT_SRC_MORE
end_define

begin_define
define|#
directive|define
name|_MAPPER_CONVERT_DST_MORE
value|_CITRUS_MAPPER_CONVERT_DST_MORE
end_define

begin_define
define|#
directive|define
name|_MAPPER_CONVERT_ILSEQ
value|_CITRUS_MAPPER_CONVERT_ILSEQ
end_define

begin_define
define|#
directive|define
name|_MAPPER_CONVERT_FATAL
value|_CITRUS_MAPPER_CONVERT_FATAL
end_define

begin_define
define|#
directive|define
name|_mapper_convert
value|_citrus_mapper_convert
end_define

begin_define
define|#
directive|define
name|_mapper_init_state
value|_citrus_mapper_init_state
end_define

begin_define
define|#
directive|define
name|_mapper_get_state_size
value|_citrus_mapper_get_state_size
end_define

begin_define
define|#
directive|define
name|_mapper_get_src_max
value|_citrus_mapper_get_src_max
end_define

begin_define
define|#
directive|define
name|_mapper_get_dst_max
value|_citrus_mapper_get_dst_max
end_define

begin_define
define|#
directive|define
name|_mapper_set_persistent
value|_citrus_mapper_set_persistent
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CITRUS_MAPPER_NO_NAMESPACE */
end_comment

begin_comment
comment|/* citrus_memstream */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_MEMSTREAM_NO_NAMESPACE
end_ifndef

begin_define
define|#
directive|define
name|_memstream
value|_citrus_memory_stream
end_define

begin_define
define|#
directive|define
name|_memstream_getln
value|_citrus_memory_stream_getln
end_define

begin_define
define|#
directive|define
name|_memstream_matchline
value|_citrus_memory_stream_matchline
end_define

begin_define
define|#
directive|define
name|_memstream_chr
value|_citrus_memory_stream_chr
end_define

begin_define
define|#
directive|define
name|_memstream_skip_ws
value|_citrus_memory_stream_skip_ws
end_define

begin_define
define|#
directive|define
name|_memstream_iseof
value|_citrus_memory_stream_iseof
end_define

begin_define
define|#
directive|define
name|_memstream_bind
value|_citrus_memory_stream_bind
end_define

begin_define
define|#
directive|define
name|_memstream_bind_ptr
value|_citrus_memory_stream_bind_ptr
end_define

begin_define
define|#
directive|define
name|_memstream_seek
value|_citrus_memory_stream_seek
end_define

begin_define
define|#
directive|define
name|_memstream_rewind
value|_citrus_memory_stream_rewind
end_define

begin_define
define|#
directive|define
name|_memstream_tell
value|_citrus_memory_stream_tell
end_define

begin_define
define|#
directive|define
name|_memstream_remainder
value|_citrus_memory_stream_remainder
end_define

begin_define
define|#
directive|define
name|_memstream_getc
value|_citrus_memory_stream_getc
end_define

begin_define
define|#
directive|define
name|_memstream_ungetc
value|_citrus_memory_stream_ungetc
end_define

begin_define
define|#
directive|define
name|_memstream_peek
value|_citrus_memory_stream_peek
end_define

begin_define
define|#
directive|define
name|_memstream_getregion
value|_citrus_memory_stream_getregion
end_define

begin_define
define|#
directive|define
name|_memstream_getln_region
value|_citrus_memory_stream_getln_region
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CITRUS_MEMSTREAM_NO_NAMESPACE */
end_comment

begin_comment
comment|/* citrus_mmap */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_MMAP_NO_NAMESPACE
end_ifndef

begin_define
define|#
directive|define
name|_map_file
value|_citrus_map_file
end_define

begin_define
define|#
directive|define
name|_unmap_file
value|_citrus_unmap_file
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CITRUS_MMAP_NO_NAMESPACE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_PIVOT_NO_NAMESPACE
end_ifndef

begin_define
define|#
directive|define
name|_pivot_factory_convert
value|_citrus_pivot_factory_convert
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CITRUS_PIVOT_NO_NAMESPACE */
end_comment

begin_comment
comment|/* citrus_region.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_REGION_NO_NAMESPACE
end_ifndef

begin_define
define|#
directive|define
name|_region
value|_citrus_region
end_define

begin_define
define|#
directive|define
name|_region_init
value|_citrus_region_init
end_define

begin_define
define|#
directive|define
name|_region_head
value|_citrus_region_head
end_define

begin_define
define|#
directive|define
name|_region_size
value|_citrus_region_size
end_define

begin_define
define|#
directive|define
name|_region_check
value|_citrus_region_check
end_define

begin_define
define|#
directive|define
name|_region_offset
value|_citrus_region_offset
end_define

begin_define
define|#
directive|define
name|_region_peek8
value|_citrus_region_peek8
end_define

begin_define
define|#
directive|define
name|_region_peek16
value|_citrus_region_peek16
end_define

begin_define
define|#
directive|define
name|_region_peek32
value|_citrus_region_peek32
end_define

begin_define
define|#
directive|define
name|_region_get_subregion
value|_citrus_region_get_subregion
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CITRUS_REGION_NO_NAMESPACE */
end_comment

begin_comment
comment|/* citrus_stdenc.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_STDENC_NO_NAMESPACE
end_ifndef

begin_define
define|#
directive|define
name|_stdenc
value|_citrus_stdenc
end_define

begin_define
define|#
directive|define
name|_stdenc_ops
value|_citrus_stdenc_ops
end_define

begin_define
define|#
directive|define
name|_stdenc_traits
value|_citrus_stdenc_traits
end_define

begin_define
define|#
directive|define
name|_stdenc_state_desc
value|_citrus_stdenc_state_desc
end_define

begin_define
define|#
directive|define
name|_stdenc_open
value|_citrus_stdenc_open
end_define

begin_define
define|#
directive|define
name|_stdenc_close
value|_citrus_stdenc_close
end_define

begin_define
define|#
directive|define
name|_stdenc_init_state
value|_citrus_stdenc_init_state
end_define

begin_define
define|#
directive|define
name|_stdenc_mbtocs
value|_citrus_stdenc_mbtocs
end_define

begin_define
define|#
directive|define
name|_stdenc_cstomb
value|_citrus_stdenc_cstomb
end_define

begin_define
define|#
directive|define
name|_stdenc_mbtowc
value|_citrus_stdenc_mbtowc
end_define

begin_define
define|#
directive|define
name|_stdenc_wctomb
value|_citrus_stdenc_wctomb
end_define

begin_define
define|#
directive|define
name|_stdenc_put_state_reset
value|_citrus_stdenc_put_state_reset
end_define

begin_define
define|#
directive|define
name|_stdenc_get_state_size
value|_citrus_stdenc_get_state_size
end_define

begin_define
define|#
directive|define
name|_stdenc_get_mb_cur_max
value|_citrus_stdenc_get_mb_cur_max
end_define

begin_define
define|#
directive|define
name|_stdenc_get_state_desc
value|_citrus_stdenc_get_state_desc
end_define

begin_define
define|#
directive|define
name|_STDENC_SDID_GENERIC
value|_CITRUS_STDENC_SDID_GENERIC
end_define

begin_define
define|#
directive|define
name|_STDENC_SDGEN_UNKNOWN
value|_CITRUS_STDENC_SDGEN_UNKNOWN
end_define

begin_define
define|#
directive|define
name|_STDENC_SDGEN_INITIAL
value|_CITRUS_STDENC_SDGEN_INITIAL
end_define

begin_define
define|#
directive|define
name|_STDENC_SDGEN_STABLE
value|_CITRUS_STDENC_SDGEN_STABLE
end_define

begin_define
define|#
directive|define
name|_STDENC_SDGEN_INCOMPLETE_CHAR
value|_CITRUS_STDENC_SDGEN_INCOMPLETE_CHAR
end_define

begin_define
define|#
directive|define
name|_STDENC_SDGEN_INCOMPLETE_SHIFT
value|_CITRUS_STDENC_SDGEN_INCOMPLETE_SHIFT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CITRUS_STDENC_NO_NAMESPACE */
end_comment

begin_comment
comment|/* citrus_types.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_TYPES_NO_NAMESPACE
end_ifndef

begin_define
define|#
directive|define
name|_index_t
value|_citrus_index_t
end_define

begin_define
define|#
directive|define
name|_csid_t
value|_citrus_csid_t
end_define

begin_define
define|#
directive|define
name|_wc_t
value|_citrus_wc_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CITRUS_TYPES_NO_NAMESPACE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

