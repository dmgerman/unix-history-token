begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Michael Bushkov<bushman@rsu.ru>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NS_CACHE_H__
end_ifndef

begin_define
define|#
directive|define
name|__NS_CACHE_H__
end_define

begin_include
include|#
directive|include
file|"nscachedcli.h"
end_include

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|nss_cache_id_func_t
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|va_list
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|nss_cache_marshal_func_t
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|va_list
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|nss_cache_unmarshal_func_t
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|va_list
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|nss_set_mp_ws_func_t
function_decl|)
parameter_list|(
name|cached_mp_write_session
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|cached_mp_write_session
function_decl|(
modifier|*
name|nss_get_mp_ws_func_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|nss_set_mp_rs_func_t
function_decl|)
parameter_list|(
name|cached_mp_read_session
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|cached_mp_read_session
function_decl|(
modifier|*
name|nss_get_mp_rs_func_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_nss_cache_info
block|{
name|char
modifier|*
name|entry_name
decl_stmt|;
name|void
modifier|*
name|mdata
decl_stmt|;
comment|/* 	 * These 3 functions should be implemented specifically for each 	 * nsswitch database. 	 */
name|nss_cache_id_func_t
name|id_func
decl_stmt|;
comment|/* marshals the request parameters */
name|nss_cache_marshal_func_t
name|marshal_func
decl_stmt|;
comment|/* marshals response */
name|nss_cache_unmarshal_func_t
name|unmarshal_func
decl_stmt|;
comment|/* unmarshals response */
comment|/* 	 * These 4 functions should be generated with NSS_MP_CACHE_HANDLING 	 * macro. 	 */
name|nss_set_mp_ws_func_t
name|set_mp_ws_func
decl_stmt|;
comment|/* sets current write session */
name|nss_get_mp_ws_func_t
name|get_mp_ws_func
decl_stmt|;
comment|/* gets current write session */
name|nss_set_mp_rs_func_t
name|set_mp_rs_func
decl_stmt|;
comment|/* sets current read session */
name|nss_get_mp_rs_func_t
name|get_mp_rs_func
decl_stmt|;
comment|/* gets current read session */
block|}
name|nss_cache_info
typedef|;
end_typedef

begin_comment
comment|/*  * NSS_MP_CACHE_HANDLING implements the set_mp_ws, get_mp_ws, set_mp_rs,  * get_mp_rs functions, that are used in _nss_cache_info. It uses  * NSS_TLS_HANDLING macro to organize thread local storage.  */
end_comment

begin_define
define|#
directive|define
name|NSS_MP_CACHE_HANDLING
parameter_list|(
name|name
parameter_list|)
define|\
value|struct name##_mp_state {						\ 	cached_mp_write_session	mp_write_session;			\ 	cached_mp_read_session	mp_read_session;			\ };									\ 									\ static void								\ name##_mp_endstate(void *s) {						\ 	struct name##_mp_state	*mp_state;				\ 									\ 	mp_state = (struct name##_mp_state *)s;				\ 	if (mp_state->mp_write_session != INVALID_CACHED_MP_WRITE_SESSION)\ 		__abandon_cached_mp_write_session(mp_state->mp_write_session);\ 									\ 	if (mp_state->mp_read_session != INVALID_CACHED_MP_READ_SESSION)\ 		__close_cached_mp_read_session(mp_state->mp_read_session);\ }									\ NSS_TLS_HANDLING(name##_mp);						\ 									\ static void								\ name##_set_mp_ws(cached_mp_write_session ws)				\ {									\ 	struct name##_mp_state	*mp_state;				\ 	int	res;							\ 									\ 	res = name##_mp_getstate(&mp_state);				\ 	if (res != 0)							\ 		return;							\ 									\ 	mp_state->mp_write_session = ws;				\ }									\ 									\ static cached_mp_write_session						\ name##_get_mp_ws(void)							\ {									\ 	struct name##_mp_state	*mp_state;				\ 	int	res;							\ 									\ 	res = name##_mp_getstate(&mp_state);				\ 	if (res != 0)							\ 		return (INVALID_CACHED_MP_WRITE_SESSION);		\ 									\ 	return (mp_state->mp_write_session);				\ }									\ 									\ static void								\ name##_set_mp_rs(cached_mp_read_session rs)				\ {									\ 	struct name##_mp_state	*mp_state;				\ 	int	res;							\ 									\ 	res = name##_mp_getstate(&mp_state);				\ 	if (res != 0)							\ 		return;							\ 									\ 	mp_state->mp_read_session = rs;					\ }									\ 									\ static cached_mp_read_session						\ name##_get_mp_rs(void)							\ {									\ 	struct name##_mp_state	*mp_state;				\ 	int	res;							\ 									\ 	res = name##_mp_getstate(&mp_state);				\ 	if (res != 0)							\ 		return (INVALID_CACHED_MP_READ_SESSION);		\ 									\ 	return (mp_state->mp_read_session);				\ }
end_define

begin_comment
comment|/*  * These macros should be used to initialize _nss_cache_info structure. For  * multipart queries in setXXXent and getXXXent functions mf and uf  * (marshal function and unmarshal function) should be both NULL.  */
end_comment

begin_define
define|#
directive|define
name|NS_COMMON_CACHE_INFO_INITIALIZER
parameter_list|(
name|name
parameter_list|,
name|mdata
parameter_list|,
define|if, mf, uf)	\ 	{#name, mdata, if, mf, uf, NULL, NULL, NULL, NULL}
end_define

begin_define
define|#
directive|define
name|NS_MP_CACHE_INFO_INITIALIZER
parameter_list|(
name|name
parameter_list|,
name|mdata
parameter_list|,
name|mf
parameter_list|,
name|uf
parameter_list|)
define|\
value|{#name, mdata, NULL, mf, uf, name##_set_mp_ws, name##_get_mp_ws,\ 		name##_set_mp_rs, name##_get_mp_rs }
end_define

begin_comment
comment|/*  * Analog of other XXX_CB macros. Has the pointer to _nss_cache_info  * structure as the only argument.  */
end_comment

begin_define
define|#
directive|define
name|NS_CACHE_CB
parameter_list|(
name|cinfo
parameter_list|)
value|{NSSRC_CACHE, __nss_cache_handler, (void *)(cinfo) },
end_define

begin_comment
comment|/* args are: current pointer, current buffer, initial buffer, pointer type */
end_comment

begin_define
define|#
directive|define
name|NS_APPLY_OFFSET
parameter_list|(
name|cp
parameter_list|,
name|cb
parameter_list|,
name|ib
parameter_list|,
name|p_type
parameter_list|)
define|\
value|if ((cp) != NULL)						\ 		(cp) = (p_type)((char *)(cb) + (size_t)(cp) - (size_t)(ib))
end_define

begin_comment
comment|/*  * Gets new pointer from the marshalled buffer by uisng initial address  * and initial buffer address  */
end_comment

begin_define
define|#
directive|define
name|NS_GET_NEWP
parameter_list|(
name|cp
parameter_list|,
name|cb
parameter_list|,
name|ib
parameter_list|)
define|\
value|((char *)(cb) + (size_t)(cp) - (size_t)(ib))
end_define

begin_typedef
typedef|typedef
struct|struct
name|_nss_cache_data
block|{
name|char
modifier|*
name|key
decl_stmt|;
name|size_t
name|key_size
decl_stmt|;
name|nss_cache_info
specifier|const
modifier|*
name|info
decl_stmt|;
block|}
name|nss_cache_data
typedef|;
end_typedef

begin_function_decl
name|__BEGIN_DECLS
comment|/* dummy function, which is needed to make nss_method_lookup happy */
specifier|extern
name|int
name|__nss_cache_handler
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_NS_PRIVATE
end_ifdef

begin_function_decl
specifier|extern
name|int
name|__nss_common_cache_read
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__nss_common_cache_write
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__nss_common_cache_write_negative
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__nss_mp_cache_read
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__nss_mp_cache_write
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__nss_mp_cache_write_submit
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__nss_mp_cache_end
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NS_PRIVATE */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

