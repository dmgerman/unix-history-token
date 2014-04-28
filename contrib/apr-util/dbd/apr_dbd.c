begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"apu_config.h"
end_include

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_dso.h"
end_include

begin_include
include|#
directive|include
file|"apr_strings.h"
end_include

begin_include
include|#
directive|include
file|"apr_hash.h"
end_include

begin_include
include|#
directive|include
file|"apr_thread_mutex.h"
end_include

begin_include
include|#
directive|include
file|"apr_lib.h"
end_include

begin_include
include|#
directive|include
file|"apr_atomic.h"
end_include

begin_include
include|#
directive|include
file|"apu_internal.h"
end_include

begin_include
include|#
directive|include
file|"apr_dbd_internal.h"
end_include

begin_include
include|#
directive|include
file|"apr_dbd.h"
end_include

begin_include
include|#
directive|include
file|"apu_version.h"
end_include

begin_decl_stmt
specifier|static
name|apr_hash_t
modifier|*
name|drivers
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|apr_uint32_t
name|initialised
init|=
literal|0
decl_stmt|,
name|in_init
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CLEANUP_CAST
value|(apr_status_t (*)(void*))
end_define

begin_if
if|#
directive|if
name|APR_HAS_THREADS
end_if

begin_comment
comment|/* deprecated, but required for existing providers.  Existing and new  * providers should be refactored to use a provider-specific mutex so  * that different providers do not block one another.  * In APR 1.3 this is no longer used for dso module loading, and  * apu_dso_mutex_[un]lock is used instead.  * In APR 2.0 this should become entirely local to libaprutil-2.so and  * no longer be exported.  */
end_comment

begin_decl_stmt
specifier|static
name|apr_thread_mutex_t
modifier|*
name|mutex
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_dbd_mutex_lock
argument_list|()
end_macro

begin_block
block|{
return|return
name|apr_thread_mutex_lock
argument_list|(
name|mutex
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_dbd_mutex_unlock
argument_list|()
end_macro

begin_block
block|{
return|return
name|apr_thread_mutex_unlock
argument_list|(
name|mutex
argument_list|)
return|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_dbd_mutex_lock
argument_list|()
end_macro

begin_block
block|{
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_dbd_mutex_unlock
argument_list|()
end_macro

begin_block
block|{
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|APU_DSO_BUILD
end_if

begin_define
define|#
directive|define
name|DRIVER_LOAD
parameter_list|(
name|name
parameter_list|,
name|driver
parameter_list|,
name|pool
parameter_list|)
define|\
value|{   \         extern const apr_dbd_driver_t driver; \         apr_hash_set(drivers,name,APR_HASH_KEY_STRING,&driver); \         if (driver.init) {     \             driver.init(pool); \         }  \     }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|apr_status_t
name|apr_dbd_term
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
comment|/* set drivers to NULL so init can work again */
name|drivers
operator|=
name|NULL
expr_stmt|;
comment|/* Everything else we need is handled by cleanups registered      * when we created mutexes and loaded DSOs      */
return|return
name|APR_SUCCESS
return|;
block|}
end_function

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_dbd_init
argument_list|(
argument|apr_pool_t *pool
argument_list|)
end_macro

begin_block
block|{
name|apr_status_t
name|ret
init|=
name|APR_SUCCESS
decl_stmt|;
name|apr_pool_t
modifier|*
name|parent
decl_stmt|;
if|if
condition|(
name|apr_atomic_inc32
argument_list|(
operator|&
name|initialised
argument_list|)
condition|)
block|{
name|apr_atomic_set32
argument_list|(
operator|&
name|initialised
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* prevent wrap-around */
while|while
condition|(
name|apr_atomic_read32
argument_list|(
operator|&
name|in_init
argument_list|)
condition|)
comment|/* wait until we get fully inited */
empty_stmt|;
return|return
name|APR_SUCCESS
return|;
block|}
comment|/* Top level pool scope, need process-scope lifetime */
for|for
control|(
name|parent
operator|=
name|apr_pool_parent_get
argument_list|(
name|pool
argument_list|)
init|;
name|parent
operator|&&
name|parent
operator|!=
name|pool
condition|;
name|parent
operator|=
name|apr_pool_parent_get
argument_list|(
name|pool
argument_list|)
control|)
name|pool
operator|=
name|parent
expr_stmt|;
if|#
directive|if
name|APU_DSO_BUILD
comment|/* deprecate in 2.0 - permit implicit initialization */
name|apu_dso_init
argument_list|(
name|pool
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|drivers
operator|=
name|apr_hash_make
argument_list|(
name|pool
argument_list|)
expr_stmt|;
if|#
directive|if
name|APR_HAS_THREADS
name|ret
operator|=
name|apr_thread_mutex_create
argument_list|(
operator|&
name|mutex
argument_list|,
name|APR_THREAD_MUTEX_DEFAULT
argument_list|,
name|pool
argument_list|)
expr_stmt|;
comment|/* This already registers a pool cleanup */
endif|#
directive|endif
if|#
directive|if
operator|!
name|APU_DSO_BUILD
comment|/* Load statically-linked drivers: */
if|#
directive|if
name|APU_HAVE_MYSQL
name|DRIVER_LOAD
argument_list|(
literal|"mysql"
argument_list|,
name|apr_dbd_mysql_driver
argument_list|,
name|pool
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|APU_HAVE_PGSQL
name|DRIVER_LOAD
argument_list|(
literal|"pgsql"
argument_list|,
name|apr_dbd_pgsql_driver
argument_list|,
name|pool
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|APU_HAVE_SQLITE3
name|DRIVER_LOAD
argument_list|(
literal|"sqlite3"
argument_list|,
name|apr_dbd_sqlite3_driver
argument_list|,
name|pool
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|APU_HAVE_SQLITE2
name|DRIVER_LOAD
argument_list|(
literal|"sqlite2"
argument_list|,
name|apr_dbd_sqlite2_driver
argument_list|,
name|pool
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|APU_HAVE_ORACLE
name|DRIVER_LOAD
argument_list|(
literal|"oracle"
argument_list|,
name|apr_dbd_oracle_driver
argument_list|,
name|pool
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|APU_HAVE_FREETDS
name|DRIVER_LOAD
argument_list|(
literal|"freetds"
argument_list|,
name|apr_dbd_freetds_driver
argument_list|,
name|pool
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|APU_HAVE_ODBC
name|DRIVER_LOAD
argument_list|(
literal|"odbc"
argument_list|,
name|apr_dbd_odbc_driver
argument_list|,
name|pool
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|APU_HAVE_SOME_OTHER_BACKEND
name|DRIVER_LOAD
argument_list|(
literal|"firebird"
argument_list|,
name|apr_dbd_other_driver
argument_list|,
name|pool
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* APU_DSO_BUILD */
name|apr_pool_cleanup_register
argument_list|(
name|pool
argument_list|,
name|NULL
argument_list|,
name|apr_dbd_term
argument_list|,
name|apr_pool_cleanup_null
argument_list|)
expr_stmt|;
name|apr_atomic_dec32
argument_list|(
operator|&
name|in_init
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_dbd_get_driver
argument_list|(
argument|apr_pool_t *pool
argument_list|,
argument|const char *name
argument_list|,
argument|const apr_dbd_driver_t **driver
argument_list|)
end_macro

begin_block
block|{
if|#
directive|if
name|APU_DSO_BUILD
name|char
name|modname
index|[
literal|32
index|]
decl_stmt|;
name|char
name|symname
index|[
literal|34
index|]
decl_stmt|;
name|apr_dso_handle_sym_t
name|symbol
decl_stmt|;
endif|#
directive|endif
name|apr_status_t
name|rv
decl_stmt|;
if|#
directive|if
name|APU_DSO_BUILD
name|rv
operator|=
name|apu_dso_mutex_lock
argument_list|()
expr_stmt|;
if|if
condition|(
name|rv
condition|)
block|{
return|return
name|rv
return|;
block|}
endif|#
directive|endif
operator|*
name|driver
operator|=
name|apr_hash_get
argument_list|(
name|drivers
argument_list|,
name|name
argument_list|,
name|APR_HASH_KEY_STRING
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|driver
condition|)
block|{
if|#
directive|if
name|APU_DSO_BUILD
name|apu_dso_mutex_unlock
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
name|APR_SUCCESS
return|;
block|}
if|#
directive|if
name|APU_DSO_BUILD
comment|/* The driver DSO must have exactly the same lifetime as the      * drivers hash table; ignore the passed-in pool */
name|pool
operator|=
name|apr_hash_pool_get
argument_list|(
name|drivers
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|NETWARE
argument_list|)
name|apr_snprintf
argument_list|(
name|modname
argument_list|,
sizeof|sizeof
argument_list|(
name|modname
argument_list|)
argument_list|,
literal|"dbd%s.nlm"
argument_list|,
name|name
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
name|apr_snprintf
argument_list|(
name|modname
argument_list|,
sizeof|sizeof
argument_list|(
name|modname
argument_list|)
argument_list|,
literal|"apr_dbd_%s-"
name|APU_STRINGIFY
argument_list|(
name|APU_MAJOR_VERSION
argument_list|)
literal|".dll"
argument_list|,
name|name
argument_list|)
expr_stmt|;
else|#
directive|else
name|apr_snprintf
argument_list|(
name|modname
argument_list|,
sizeof|sizeof
argument_list|(
name|modname
argument_list|)
argument_list|,
literal|"apr_dbd_%s-"
name|APU_STRINGIFY
argument_list|(
name|APU_MAJOR_VERSION
argument_list|)
literal|".so"
argument_list|,
name|name
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|apr_snprintf
argument_list|(
name|symname
argument_list|,
sizeof|sizeof
argument_list|(
name|symname
argument_list|)
argument_list|,
literal|"apr_dbd_%s_driver"
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|rv
operator|=
name|apu_dso_load
argument_list|(
name|NULL
argument_list|,
operator|&
name|symbol
argument_list|,
name|modname
argument_list|,
name|symname
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|rv
operator|==
name|APR_SUCCESS
operator|||
name|rv
operator|==
name|APR_EINIT
condition|)
block|{
comment|/* previously loaded?!? */
operator|*
name|driver
operator|=
name|symbol
expr_stmt|;
name|name
operator|=
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|apr_hash_set
argument_list|(
name|drivers
argument_list|,
name|name
argument_list|,
name|APR_HASH_KEY_STRING
argument_list|,
operator|*
name|driver
argument_list|)
expr_stmt|;
name|rv
operator|=
name|APR_SUCCESS
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|driver
operator|)
operator|->
name|init
condition|)
block|{
operator|(
operator|*
name|driver
operator|)
operator|->
name|init
argument_list|(
name|pool
argument_list|)
expr_stmt|;
block|}
block|}
name|apu_dso_mutex_unlock
argument_list|()
expr_stmt|;
else|#
directive|else
comment|/* not builtin and !APU_DSO_BUILD => not implemented */
name|rv
operator|=
name|APR_ENOTIMPL
expr_stmt|;
endif|#
directive|endif
return|return
name|rv
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_dbd_open_ex
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|const char *params
argument_list|,
argument|apr_dbd_t **handle
argument_list|,
argument|const char **error
argument_list|)
end_macro

begin_block
block|{
name|apr_status_t
name|rv
decl_stmt|;
operator|*
name|handle
operator|=
call|(
name|driver
operator|->
name|open
call|)
argument_list|(
name|pool
argument_list|,
name|params
argument_list|,
name|error
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|handle
operator|==
name|NULL
condition|)
block|{
return|return
name|APR_EGENERAL
return|;
block|}
name|rv
operator|=
name|apr_dbd_check_conn
argument_list|(
name|driver
argument_list|,
name|pool
argument_list|,
operator|*
name|handle
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|rv
operator|!=
name|APR_SUCCESS
operator|)
operator|&&
operator|(
name|rv
operator|!=
name|APR_ENOTIMPL
operator|)
condition|)
block|{
comment|/* XXX: rv is APR error code, but apr_dbd_error() takes int! */
if|if
condition|(
name|error
condition|)
block|{
operator|*
name|error
operator|=
name|apr_dbd_error
argument_list|(
name|driver
argument_list|,
operator|*
name|handle
argument_list|,
name|rv
argument_list|)
expr_stmt|;
block|}
name|apr_dbd_close
argument_list|(
name|driver
argument_list|,
operator|*
name|handle
argument_list|)
expr_stmt|;
return|return
name|APR_EGENERAL
return|;
block|}
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_dbd_open
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|const char *params
argument_list|,
argument|apr_dbd_t **handle
argument_list|)
end_macro

begin_block
block|{
return|return
name|apr_dbd_open_ex
argument_list|(
name|driver
argument_list|,
name|pool
argument_list|,
name|params
argument_list|,
name|handle
argument_list|,
name|NULL
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_transaction_start
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|apr_dbd_transaction_t **trans
argument_list|)
end_macro

begin_block
block|{
name|int
name|ret
init|=
name|driver
operator|->
name|start_transaction
argument_list|(
name|pool
argument_list|,
name|handle
argument_list|,
name|trans
argument_list|)
decl_stmt|;
if|if
condition|(
operator|*
name|trans
condition|)
block|{
name|apr_pool_cleanup_register
argument_list|(
argument|pool
argument_list|,
argument|*trans
argument_list|,
argument|CLEANUP_CAST driver->end_transaction
argument_list|,
argument|apr_pool_cleanup_null
argument_list|)
empty_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_transaction_end
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_transaction_t *trans
argument_list|)
end_macro

begin_block
block|{
name|apr_pool_cleanup_kill
argument_list|(
argument|pool
argument_list|,
argument|trans
argument_list|,
argument|CLEANUP_CAST driver->end_transaction
argument_list|)
empty_stmt|;
return|return
name|driver
operator|->
name|end_transaction
argument_list|(
name|trans
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_transaction_mode_get
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_dbd_transaction_t *trans
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|transaction_mode_get
argument_list|(
name|trans
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_transaction_mode_set
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_dbd_transaction_t *trans
argument_list|,
argument|int mode
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|transaction_mode_set
argument_list|(
name|trans
argument_list|,
name|mode
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_dbd_close
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_dbd_t *handle
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|close
argument_list|(
name|handle
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|const char*
argument_list|)
end_macro

begin_macro
name|apr_dbd_name
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|name
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|void*
argument_list|)
end_macro

begin_macro
name|apr_dbd_native_handle
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_dbd_t *handle
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|native_handle
argument_list|(
name|handle
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_check_conn
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|check_conn
argument_list|(
name|pool
argument_list|,
name|handle
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_set_dbname
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|const char *name
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|set_dbname
argument_list|(
name|pool
argument_list|,
name|handle
argument_list|,
name|name
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_query
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|int *nrows
argument_list|,
argument|const char *statement
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|query
argument_list|(
name|handle
argument_list|,
name|nrows
argument_list|,
name|statement
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_select
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|apr_dbd_results_t **res
argument_list|,
argument|const char *statement
argument_list|,
argument|int random
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|select
argument_list|(
name|pool
argument_list|,
name|handle
argument_list|,
name|res
argument_list|,
name|statement
argument_list|,
name|random
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_num_cols
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_dbd_results_t *res
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|num_cols
argument_list|(
name|res
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_num_tuples
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_dbd_results_t *res
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|num_tuples
argument_list|(
name|res
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_get_row
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_results_t *res
argument_list|,
argument|apr_dbd_row_t **row
argument_list|,
argument|int rownum
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|get_row
argument_list|(
name|pool
argument_list|,
name|res
argument_list|,
name|row
argument_list|,
name|rownum
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|const char*
argument_list|)
end_macro

begin_macro
name|apr_dbd_get_entry
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_dbd_row_t *row
argument_list|,
argument|int col
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|get_entry
argument_list|(
name|row
argument_list|,
name|col
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|const char*
argument_list|)
end_macro

begin_macro
name|apr_dbd_get_name
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_dbd_results_t *res
argument_list|,
argument|int col
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|get_name
argument_list|(
name|res
argument_list|,
name|col
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|const char*
argument_list|)
end_macro

begin_macro
name|apr_dbd_error
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|int errnum
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|error
argument_list|(
name|handle
argument_list|,
name|errnum
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|const char*
argument_list|)
end_macro

begin_macro
name|apr_dbd_escape
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|const char *string
argument_list|,
argument|apr_dbd_t *handle
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|escape
argument_list|(
name|pool
argument_list|,
name|string
argument_list|,
name|handle
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_prepare
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|const char *query
argument_list|,
argument|const char *label
argument_list|,
argument|apr_dbd_prepared_t **statement
argument_list|)
end_macro

begin_block
block|{
name|size_t
name|qlen
decl_stmt|;
name|int
name|i
decl_stmt|,
name|nargs
init|=
literal|0
decl_stmt|,
name|nvals
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|pq
decl_stmt|;
specifier|const
name|char
modifier|*
name|q
decl_stmt|;
name|apr_dbd_type_e
modifier|*
name|t
decl_stmt|;
if|if
condition|(
operator|!
name|driver
operator|->
name|pformat
condition|)
block|{
return|return
name|APR_ENOTIMPL
return|;
block|}
comment|/* find the number of parameters in the query */
for|for
control|(
name|q
operator|=
name|query
init|;
operator|*
name|q
condition|;
name|q
operator|++
control|)
block|{
if|if
condition|(
name|q
index|[
literal|0
index|]
operator|==
literal|'%'
condition|)
block|{
if|if
condition|(
name|apr_isalpha
argument_list|(
name|q
index|[
literal|1
index|]
argument_list|)
condition|)
block|{
name|nargs
operator|++
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|q
index|[
literal|1
index|]
operator|==
literal|'%'
condition|)
block|{
name|q
operator|++
expr_stmt|;
block|}
block|}
block|}
name|nvals
operator|=
name|nargs
expr_stmt|;
name|qlen
operator|=
name|strlen
argument_list|(
name|query
argument_list|)
operator|+
name|nargs
operator|*
operator|(
name|strlen
argument_list|(
name|driver
operator|->
name|pformat
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|nargs
argument_list|)
operator|*
literal|3
operator|+
literal|2
operator|)
operator|+
literal|1
expr_stmt|;
name|pq
operator|=
name|apr_palloc
argument_list|(
name|pool
argument_list|,
name|qlen
argument_list|)
expr_stmt|;
name|t
operator|=
name|apr_pcalloc
argument_list|(
name|pool
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|t
argument_list|)
operator|*
name|nargs
argument_list|)
expr_stmt|;
for|for
control|(
name|p
operator|=
name|pq
operator|,
name|q
operator|=
name|query
operator|,
name|i
operator|=
literal|0
init|;
operator|*
name|q
condition|;
name|q
operator|++
control|)
block|{
if|if
condition|(
name|q
index|[
literal|0
index|]
operator|==
literal|'%'
condition|)
block|{
if|if
condition|(
name|apr_isalpha
argument_list|(
name|q
index|[
literal|1
index|]
argument_list|)
condition|)
block|{
switch|switch
condition|(
name|q
index|[
literal|1
index|]
condition|)
block|{
case|case
literal|'d'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_INT
expr_stmt|;
break|break;
case|case
literal|'u'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_UINT
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_FLOAT
expr_stmt|;
break|break;
case|case
literal|'h'
case|:
switch|switch
condition|(
name|q
index|[
literal|2
index|]
condition|)
block|{
case|case
literal|'h'
case|:
switch|switch
condition|(
name|q
index|[
literal|3
index|]
condition|)
block|{
case|case
literal|'d'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_TINY
expr_stmt|;
name|q
operator|+=
literal|2
expr_stmt|;
break|break;
case|case
literal|'u'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_UTINY
expr_stmt|;
name|q
operator|+=
literal|2
expr_stmt|;
break|break;
block|}
break|break;
case|case
literal|'d'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_SHORT
expr_stmt|;
name|q
operator|++
expr_stmt|;
break|break;
case|case
literal|'u'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_USHORT
expr_stmt|;
name|q
operator|++
expr_stmt|;
break|break;
block|}
break|break;
case|case
literal|'l'
case|:
switch|switch
condition|(
name|q
index|[
literal|2
index|]
condition|)
block|{
case|case
literal|'l'
case|:
switch|switch
condition|(
name|q
index|[
literal|3
index|]
condition|)
block|{
case|case
literal|'d'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_LONGLONG
expr_stmt|;
name|q
operator|+=
literal|2
expr_stmt|;
break|break;
case|case
literal|'u'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_ULONGLONG
expr_stmt|;
name|q
operator|+=
literal|2
expr_stmt|;
break|break;
block|}
break|break;
case|case
literal|'d'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_LONG
expr_stmt|;
name|q
operator|++
expr_stmt|;
break|break;
case|case
literal|'u'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_ULONG
expr_stmt|;
name|q
operator|++
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_DOUBLE
expr_stmt|;
name|q
operator|++
expr_stmt|;
break|break;
block|}
break|break;
case|case
literal|'p'
case|:
if|if
condition|(
name|q
index|[
literal|2
index|]
operator|==
literal|'D'
condition|)
block|{
switch|switch
condition|(
name|q
index|[
literal|3
index|]
condition|)
block|{
case|case
literal|'t'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_TEXT
expr_stmt|;
name|q
operator|+=
literal|2
expr_stmt|;
break|break;
case|case
literal|'i'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_TIME
expr_stmt|;
name|q
operator|+=
literal|2
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_DATE
expr_stmt|;
name|q
operator|+=
literal|2
expr_stmt|;
break|break;
case|case
literal|'a'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_DATETIME
expr_stmt|;
name|q
operator|+=
literal|2
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_TIMESTAMP
expr_stmt|;
name|q
operator|+=
literal|2
expr_stmt|;
break|break;
case|case
literal|'z'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_ZTIMESTAMP
expr_stmt|;
name|q
operator|+=
literal|2
expr_stmt|;
break|break;
case|case
literal|'b'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_BLOB
expr_stmt|;
name|q
operator|+=
literal|2
expr_stmt|;
break|break;
case|case
literal|'c'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_CLOB
expr_stmt|;
name|q
operator|+=
literal|2
expr_stmt|;
break|break;
case|case
literal|'n'
case|:
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_NULL
expr_stmt|;
name|q
operator|+=
literal|2
expr_stmt|;
break|break;
block|}
block|}
break|break;
block|}
name|q
operator|++
expr_stmt|;
switch|switch
condition|(
name|t
index|[
name|i
index|]
condition|)
block|{
case|case
name|APR_DBD_TYPE_NONE
case|:
comment|/* by default, we expect strings */
name|t
index|[
name|i
index|]
operator|=
name|APR_DBD_TYPE_STRING
expr_stmt|;
break|break;
case|case
name|APR_DBD_TYPE_BLOB
case|:
case|case
name|APR_DBD_TYPE_CLOB
case|:
comment|/* three (3) more values passed in */
name|nvals
operator|+=
literal|3
expr_stmt|;
break|break;
default|default:
break|break;
block|}
comment|/* insert database specific parameter reference */
name|p
operator|+=
name|apr_snprintf
argument_list|(
name|p
argument_list|,
name|qlen
operator|-
operator|(
name|p
operator|-
name|pq
operator|)
argument_list|,
name|driver
operator|->
name|pformat
argument_list|,
operator|++
name|i
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|q
index|[
literal|1
index|]
operator|==
literal|'%'
condition|)
block|{
comment|/* reduce %% to % */
operator|*
name|p
operator|++
operator|=
operator|*
name|q
operator|++
expr_stmt|;
block|}
else|else
block|{
operator|*
name|p
operator|++
operator|=
operator|*
name|q
expr_stmt|;
block|}
block|}
else|else
block|{
operator|*
name|p
operator|++
operator|=
operator|*
name|q
expr_stmt|;
block|}
block|}
operator|*
name|p
operator|=
literal|'\0'
expr_stmt|;
return|return
name|driver
operator|->
name|prepare
argument_list|(
name|pool
argument_list|,
name|handle
argument_list|,
name|pq
argument_list|,
name|label
argument_list|,
name|nargs
argument_list|,
name|nvals
argument_list|,
name|t
argument_list|,
name|statement
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_pquery
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|int *nrows
argument_list|,
argument|apr_dbd_prepared_t *statement
argument_list|,
argument|int nargs
argument_list|,
argument|const char **args
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|pquery
argument_list|(
name|pool
argument_list|,
name|handle
argument_list|,
name|nrows
argument_list|,
name|statement
argument_list|,
name|args
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_pselect
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|apr_dbd_results_t **res
argument_list|,
argument|apr_dbd_prepared_t *statement
argument_list|,
argument|int random
argument_list|,
argument|int nargs
argument_list|,
argument|const char **args
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|pselect
argument_list|(
name|pool
argument_list|,
name|handle
argument_list|,
name|res
argument_list|,
name|statement
argument_list|,
name|random
argument_list|,
name|args
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE_NONSTD
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_pvquery
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|int *nrows
argument_list|,
argument|apr_dbd_prepared_t *statement
argument_list|,
argument|...
argument_list|)
end_macro

begin_block
block|{
name|int
name|ret
decl_stmt|;
name|va_list
name|args
decl_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|statement
argument_list|)
expr_stmt|;
name|ret
operator|=
name|driver
operator|->
name|pvquery
argument_list|(
name|pool
argument_list|,
name|handle
argument_list|,
name|nrows
argument_list|,
name|statement
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_block

begin_macro
name|APU_DECLARE_NONSTD
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_pvselect
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|apr_dbd_results_t **res
argument_list|,
argument|apr_dbd_prepared_t *statement
argument_list|,
argument|int random
argument_list|,
argument|...
argument_list|)
end_macro

begin_block
block|{
name|int
name|ret
decl_stmt|;
name|va_list
name|args
decl_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|random
argument_list|)
expr_stmt|;
name|ret
operator|=
name|driver
operator|->
name|pvselect
argument_list|(
name|pool
argument_list|,
name|handle
argument_list|,
name|res
argument_list|,
name|statement
argument_list|,
name|random
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_pbquery
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|int *nrows
argument_list|,
argument|apr_dbd_prepared_t *statement
argument_list|,
argument|const void **args
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|pbquery
argument_list|(
name|pool
argument_list|,
name|handle
argument_list|,
name|nrows
argument_list|,
name|statement
argument_list|,
name|args
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_pbselect
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|apr_dbd_results_t **res
argument_list|,
argument|apr_dbd_prepared_t *statement
argument_list|,
argument|int random
argument_list|,
argument|const void **args
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|pbselect
argument_list|(
name|pool
argument_list|,
name|handle
argument_list|,
name|res
argument_list|,
name|statement
argument_list|,
name|random
argument_list|,
name|args
argument_list|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE_NONSTD
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_pvbquery
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|int *nrows
argument_list|,
argument|apr_dbd_prepared_t *statement
argument_list|,
argument|...
argument_list|)
end_macro

begin_block
block|{
name|int
name|ret
decl_stmt|;
name|va_list
name|args
decl_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|statement
argument_list|)
expr_stmt|;
name|ret
operator|=
name|driver
operator|->
name|pvbquery
argument_list|(
name|pool
argument_list|,
name|handle
argument_list|,
name|nrows
argument_list|,
name|statement
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_block

begin_macro
name|APU_DECLARE_NONSTD
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_dbd_pvbselect
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_pool_t *pool
argument_list|,
argument|apr_dbd_t *handle
argument_list|,
argument|apr_dbd_results_t **res
argument_list|,
argument|apr_dbd_prepared_t *statement
argument_list|,
argument|int random
argument_list|,
argument|...
argument_list|)
end_macro

begin_block
block|{
name|int
name|ret
decl_stmt|;
name|va_list
name|args
decl_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|random
argument_list|)
expr_stmt|;
name|ret
operator|=
name|driver
operator|->
name|pvbselect
argument_list|(
name|pool
argument_list|,
name|handle
argument_list|,
name|res
argument_list|,
name|statement
argument_list|,
name|random
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_dbd_datum_get
argument_list|(
argument|const apr_dbd_driver_t *driver
argument_list|,
argument|apr_dbd_row_t *row
argument_list|,
argument|int col
argument_list|,
argument|apr_dbd_type_e type
argument_list|,
argument|void *data
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|datum_get
argument_list|(
name|row
argument_list|,
name|col
argument_list|,
name|type
argument_list|,
name|data
argument_list|)
return|;
block|}
end_block

end_unit

