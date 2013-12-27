begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Michael Bushkov<bushman@rsu.ru>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NSCD_CONFIG_H__
end_ifndef

begin_define
define|#
directive|define
name|__NSCD_CONFIG_H__
end_define

begin_include
include|#
directive|include
file|"cachelib.h"
end_include

begin_define
define|#
directive|define
name|DEFAULT_QUERY_TIMEOUT
value|8
end_define

begin_define
define|#
directive|define
name|DEFAULT_THREADS_NUM
value|8
end_define

begin_define
define|#
directive|define
name|DEFAULT_COMMON_ENTRY_TIMEOUT
value|10
end_define

begin_define
define|#
directive|define
name|DEFAULT_MP_ENTRY_TIMEOUT
value|60
end_define

begin_define
define|#
directive|define
name|DEFAULT_CACHE_HT_SIZE
value|257
end_define

begin_define
define|#
directive|define
name|INITIAL_ENTRIES_CAPACITY
value|8
end_define

begin_define
define|#
directive|define
name|DEFAULT_SOCKET_PATH
value|"/var/run/nscd"
end_define

begin_define
define|#
directive|define
name|DEFAULT_PIDFILE_PATH
value|"/var/run/nscd.pid"
end_define

begin_define
define|#
directive|define
name|DEFAULT_POSITIVE_ELEMENTS_SIZE
value|(2048)
end_define

begin_define
define|#
directive|define
name|DEFAULT_POSITIVE_LIFETIME
value|(3600)
end_define

begin_define
define|#
directive|define
name|DEFAULT_POSITIVE_CONF_THRESH
value|(1)
end_define

begin_define
define|#
directive|define
name|DEFAULT_NEGATIVE_ELEMENTS_SIZE
value|(2048)
end_define

begin_define
define|#
directive|define
name|DEFAULT_NEGATIVE_LIFETIME
value|(60)
end_define

begin_define
define|#
directive|define
name|DEFAULT_NEGATIVE_CONF_THRESH
value|(1)
end_define

begin_comment
comment|/* (2) ??? */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_MULTIPART_ELEMENTS_SIZE
value|(1024 * 8)
end_define

begin_define
define|#
directive|define
name|DEFAULT_MULITPART_SESSIONS_SIZE
value|(1024)
end_define

begin_define
define|#
directive|define
name|DEFAULT_MULITPART_LIFETIME
value|(3600)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|c_default_entries
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Configuration entry represents the details of each cache entry in the  * config file (i.e. passwd or group). Its purpose also is to acquire locks  * of three different types (for usual read/write caching, for multipart  * caching and for caching of the negative results) for that cache entry.  */
end_comment

begin_struct
struct|struct
name|configuration_entry
block|{
name|struct
name|common_cache_entry_params
name|positive_cache_params
decl_stmt|;
name|struct
name|common_cache_entry_params
name|negative_cache_params
decl_stmt|;
name|struct
name|mp_cache_entry_params
name|mp_cache_params
decl_stmt|;
comment|/* 	 * configuration_entry holds pointers for all actual cache_entries, 	 * which are used for it. There is one for positive caching, one for 	 * for negative caching, and several (one per each euid/egid) for 	 * multipart caching. 	 */
name|cache_entry
name|positive_cache_entry
decl_stmt|;
name|cache_entry
name|negative_cache_entry
decl_stmt|;
name|cache_entry
modifier|*
name|mp_cache_entries
decl_stmt|;
name|size_t
name|mp_cache_entries_size
decl_stmt|;
name|struct
name|timeval
name|common_query_timeout
decl_stmt|;
name|struct
name|timeval
name|mp_query_timeout
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|pthread_mutex_t
name|positive_cache_lock
decl_stmt|;
name|pthread_mutex_t
name|negative_cache_lock
decl_stmt|;
name|pthread_mutex_t
name|mp_cache_lock
decl_stmt|;
name|int
name|perform_actual_lookups
decl_stmt|;
name|int
name|enabled
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Contains global configuration options and array of all configuration entries  */
end_comment

begin_struct
struct|struct
name|configuration
block|{
name|char
modifier|*
name|pidfile_path
decl_stmt|;
name|char
modifier|*
name|socket_path
decl_stmt|;
name|struct
name|configuration_entry
modifier|*
modifier|*
name|entries
decl_stmt|;
name|size_t
name|entries_capacity
decl_stmt|;
name|size_t
name|entries_size
decl_stmt|;
name|pthread_rwlock_t
name|rwlock
decl_stmt|;
name|mode_t
name|socket_mode
decl_stmt|;
name|int
name|force_unlink
decl_stmt|;
name|int
name|query_timeout
decl_stmt|;
name|int
name|threads_num
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|config_entry_lock_type
block|{
name|CELT_POSITIVE
block|,
name|CELT_NEGATIVE
block|,
name|CELT_MULTIPART
block|}
enum|;
end_enum

begin_function_decl
name|struct
name|configuration
modifier|*
name|init_configuration
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|destroy_configuration
parameter_list|(
name|struct
name|configuration
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fill_configuration_defaults
parameter_list|(
name|struct
name|configuration
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|add_configuration_entry
parameter_list|(
name|struct
name|configuration
modifier|*
parameter_list|,
name|struct
name|configuration_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|configuration_entry
modifier|*
name|create_def_configuration_entry
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|destroy_configuration_entry
parameter_list|(
name|struct
name|configuration_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|configuration_get_entries_size
parameter_list|(
name|struct
name|configuration
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|configuration_entry
modifier|*
name|configuration_get_entry
parameter_list|(
name|struct
name|configuration
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|configuration_entry
modifier|*
name|configuration_find_entry
parameter_list|(
name|struct
name|configuration
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|configuration_entry_add_mp_cache_entry
parameter_list|(
name|struct
name|configuration_entry
modifier|*
parameter_list|,
name|cache_entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cache_entry
name|configuration_entry_find_mp_cache_entry
parameter_list|(
name|struct
name|configuration_entry
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|configuration_entry_find_mp_cache_entries
parameter_list|(
name|struct
name|configuration_entry
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|cache_entry
modifier|*
modifier|*
parameter_list|,
name|cache_entry
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|configuration_lock_rdlock
parameter_list|(
name|struct
name|configuration
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|configuration_lock_wrlock
parameter_list|(
name|struct
name|configuration
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|configuration_unlock
parameter_list|(
name|struct
name|configuration
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|configuration_lock_entry
parameter_list|(
name|struct
name|configuration_entry
modifier|*
parameter_list|,
name|enum
name|config_entry_lock_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|configuration_unlock_entry
parameter_list|(
name|struct
name|configuration_entry
modifier|*
parameter_list|,
name|enum
name|config_entry_lock_type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

