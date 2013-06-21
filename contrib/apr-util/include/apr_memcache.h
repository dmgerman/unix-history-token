begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_MEMCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|APR_MEMCACHE_H
end_define

begin_comment
comment|/**  * @file apr_memcache.h  * @brief Client interface for memcached  * @remark To use this interface you must have a separate memcached  * server running. See the memcached website at http://www.danga.com/memcached/  * for more information.  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_time.h"
end_include

begin_include
include|#
directive|include
file|"apr_strings.h"
end_include

begin_include
include|#
directive|include
file|"apr_network_io.h"
end_include

begin_include
include|#
directive|include
file|"apr_ring.h"
end_include

begin_include
include|#
directive|include
file|"apr_buckets.h"
end_include

begin_include
include|#
directive|include
file|"apr_reslist.h"
end_include

begin_include
include|#
directive|include
file|"apr_hash.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
comment|/**  * @defgroup APR_Util_MC Memcached Client Routines  * @ingroup APR_Util  * @{  */
comment|/** Specifies the status of a memcached server */
typedef|typedef
enum|enum
block|{
name|APR_MC_SERVER_LIVE
block|,
comment|/**< Server is alive and responding to requests */
name|APR_MC_SERVER_DEAD
comment|/**< Server is not responding to requests */
block|}
name|apr_memcache_server_status_t
typedef|;
comment|/** Opaque memcache client connection object */
typedef|typedef
name|struct
name|apr_memcache_conn_t
name|apr_memcache_conn_t
typedef|;
comment|/** Memcache Server Info Object */
typedef|typedef
name|struct
name|apr_memcache_server_t
name|apr_memcache_server_t
typedef|;
struct|struct
name|apr_memcache_server_t
block|{
specifier|const
name|char
modifier|*
name|host
decl_stmt|;
comment|/**< Hostname of this Server */
name|apr_port_t
name|port
decl_stmt|;
comment|/**< Port of this Server */
name|apr_memcache_server_status_t
name|status
decl_stmt|;
comment|/**< @see apr_memcache_server_status_t */
if|#
directive|if
name|APR_HAS_THREADS
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
name|apr_reslist_t
modifier|*
name|conns
decl_stmt|;
comment|/**< Resource list of actual client connections */
else|#
directive|else
name|apr_memcache_conn_t
modifier|*
name|conn
decl_stmt|;
endif|#
directive|endif
name|apr_pool_t
modifier|*
name|p
decl_stmt|;
comment|/** Pool to use for private allocations */
if|#
directive|if
name|APR_HAS_THREADS
name|apr_thread_mutex_t
modifier|*
name|lock
decl_stmt|;
endif|#
directive|endif
name|apr_time_t
name|btime
decl_stmt|;
block|}
struct|;
comment|/* Custom hash callback function prototype, user for server selection. * @param baton user selected baton * @param data data to hash * @param data_len length of data */
typedef|typedef
name|apr_uint32_t
function_decl|(
modifier|*
name|apr_memcache_hash_func
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|,
specifier|const
name|apr_size_t
name|data_len
parameter_list|)
function_decl|;
typedef|typedef
name|struct
name|apr_memcache_t
name|apr_memcache_t
typedef|;
comment|/* Custom Server Select callback function prototype. * @param baton user selected baton * @param mc memcache instance, use mc->live_servers to select a node * @param hash hash of the selected key. */
typedef|typedef
name|apr_memcache_server_t
modifier|*
function_decl|(
modifier|*
name|apr_memcache_server_func
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|apr_memcache_t
modifier|*
name|mc
parameter_list|,
specifier|const
name|apr_uint32_t
name|hash
parameter_list|)
function_decl|;
comment|/** Container for a set of memcached servers */
struct|struct
name|apr_memcache_t
block|{
name|apr_uint32_t
name|flags
decl_stmt|;
comment|/**< Flags, Not currently used */
name|apr_uint16_t
name|nalloc
decl_stmt|;
comment|/**< Number of Servers Allocated */
name|apr_uint16_t
name|ntotal
decl_stmt|;
comment|/**< Number of Servers Added */
name|apr_memcache_server_t
modifier|*
modifier|*
name|live_servers
decl_stmt|;
comment|/**< Array of Servers */
name|apr_pool_t
modifier|*
name|p
decl_stmt|;
comment|/** Pool to use for allocations */
name|void
modifier|*
name|hash_baton
decl_stmt|;
name|apr_memcache_hash_func
name|hash_func
decl_stmt|;
name|void
modifier|*
name|server_baton
decl_stmt|;
name|apr_memcache_server_func
name|server_func
decl_stmt|;
block|}
struct|;
comment|/** Returned Data from a multiple get */
typedef|typedef
struct|struct
block|{
name|apr_status_t
name|status
decl_stmt|;
specifier|const
name|char
modifier|*
name|key
decl_stmt|;
name|apr_size_t
name|len
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
name|apr_uint16_t
name|flags
decl_stmt|;
block|}
name|apr_memcache_value_t
typedef|;
comment|/**  * Creates a crc32 hash used to split keys between servers  * @param mc The memcache client object to use  * @param data Data to be hashed  * @param data_len Length of the data to use  * @return crc32 hash of data  * @remark The crc32 hash is not compatible with old memcached clients.  */
name|APU_DECLARE
argument_list|(
argument|apr_uint32_t
argument_list|)
name|apr_memcache_hash
argument_list|(
argument|apr_memcache_t *mc
argument_list|,
argument|const char *data
argument_list|,
argument|const apr_size_t data_len
argument_list|)
empty_stmt|;
comment|/**  * Pure CRC32 Hash. Used by some clients.  */
name|APU_DECLARE
argument_list|(
argument|apr_uint32_t
argument_list|)
name|apr_memcache_hash_crc32
argument_list|(
argument|void *baton
argument_list|,
argument|const char *data
argument_list|,
argument|const apr_size_t data_len
argument_list|)
empty_stmt|;
comment|/**  * hash compatible with the standard Perl Client.  */
name|APU_DECLARE
argument_list|(
argument|apr_uint32_t
argument_list|)
name|apr_memcache_hash_default
argument_list|(
argument|void *baton
argument_list|,
argument|const char *data
argument_list|,
argument|const apr_size_t data_len
argument_list|)
empty_stmt|;
comment|/**  * Picks a server based on a hash  * @param mc The memcache client object to use  * @param hash Hashed value of a Key  * @return server that controls specified hash  * @see apr_memcache_hash  */
name|APU_DECLARE
argument_list|(
argument|apr_memcache_server_t *
argument_list|)
name|apr_memcache_find_server_hash
argument_list|(
argument|apr_memcache_t *mc
argument_list|,
argument|const apr_uint32_t hash
argument_list|)
empty_stmt|;
comment|/**  * server selection compatible with the standard Perl Client.  */
name|APU_DECLARE
argument_list|(
argument|apr_memcache_server_t *
argument_list|)
name|apr_memcache_find_server_hash_default
argument_list|(
argument|void *baton
argument_list|,
argument|apr_memcache_t *mc
argument_list|,
argument|const apr_uint32_t hash
argument_list|)
empty_stmt|;
comment|/**  * Adds a server to a client object  * @param mc The memcache client object to use  * @param server Server to add  * @remark Adding servers is not thread safe, and should be done once at startup.  * @warning Changing servers after startup may cause keys to go to  * different servers.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_memcache_add_server
argument_list|(
name|apr_memcache_t
operator|*
name|mc
argument_list|,
name|apr_memcache_server_t
operator|*
name|server
argument_list|)
expr_stmt|;
comment|/**  * Finds a Server object based on a hostname/port pair  * @param mc The memcache client object to use  * @param host Hostname of the server  * @param port Port of the server  * @return Server with matching Hostname and Port, or NULL if none was found.  */
name|APU_DECLARE
argument_list|(
argument|apr_memcache_server_t *
argument_list|)
name|apr_memcache_find_server
argument_list|(
argument|apr_memcache_t *mc
argument_list|,
argument|const char *host
argument_list|,
argument|apr_port_t port
argument_list|)
empty_stmt|;
comment|/**  * Enables a Server for use again  * @param mc The memcache client object to use  * @param ms Server to Activate  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_memcache_enable_server
argument_list|(
name|apr_memcache_t
operator|*
name|mc
argument_list|,
name|apr_memcache_server_t
operator|*
name|ms
argument_list|)
expr_stmt|;
comment|/**  * Disable a Server  * @param mc The memcache client object to use  * @param ms Server to Disable  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_memcache_disable_server
argument_list|(
name|apr_memcache_t
operator|*
name|mc
argument_list|,
name|apr_memcache_server_t
operator|*
name|ms
argument_list|)
expr_stmt|;
comment|/**  * Creates a new Server Object  * @param p Pool to use  * @param host hostname of the server  * @param port port of the server  * @param min  minimum number of client sockets to open  * @param smax soft maximum number of client connections to open  * @param max  hard maximum number of client connections  * @param ttl  time to live in microseconds of a client connection  * @param ns   location of the new server object  * @see apr_reslist_create  * @remark min, smax, and max are only used when APR_HAS_THREADS  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_memcache_server_create
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const char *host
argument_list|,
argument|apr_port_t port
argument_list|,
argument|apr_uint32_t min
argument_list|,
argument|apr_uint32_t smax
argument_list|,
argument|apr_uint32_t max
argument_list|,
argument|apr_uint32_t ttl
argument_list|,
argument|apr_memcache_server_t **ns
argument_list|)
empty_stmt|;
comment|/**  * Creates a new memcached client object  * @param p Pool to use  * @param max_servers maximum number of servers  * @param flags Not currently used  * @param mc   location of the new memcache client object  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_memcache_create
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|apr_uint16_t max_servers
argument_list|,
argument|apr_uint32_t flags
argument_list|,
argument|apr_memcache_t **mc
argument_list|)
empty_stmt|;
comment|/**  * Gets a value from the server, allocating the value out of p  * @param mc client to use  * @param p Pool to use  * @param key null terminated string containing the key  * @param baton location of the allocated value  * @param len   length of data at baton  * @param flags any flags set by the client for this key  * @return   */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_memcache_getp
argument_list|(
name|apr_memcache_t
operator|*
name|mc
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|,
specifier|const
name|char
operator|*
name|key
argument_list|,
name|char
operator|*
operator|*
name|baton
argument_list|,
name|apr_size_t
operator|*
name|len
argument_list|,
name|apr_uint16_t
operator|*
name|flags
argument_list|)
expr_stmt|;
comment|/**  * Add a key to a hash for a multiget query  *  if the hash (*value) is NULL it will be created  * @param data_pool pool from where the hash and their items are created from  * @param key null terminated string containing the key  * @param values hash of keys and values that this key will be added to  * @return  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_memcache_add_multget_key
argument_list|(
name|apr_pool_t
operator|*
name|data_pool
argument_list|,
specifier|const
name|char
operator|*
name|key
argument_list|,
name|apr_hash_t
operator|*
operator|*
name|values
argument_list|)
expr_stmt|;
comment|/**  * Gets multiple values from the server, allocating the values out of p  * @param mc client to use  * @param temp_pool Pool used for temporary allocations. May be cleared inside this  *        call.  * @param data_pool Pool used to allocate data for the returned values.  * @param values hash of apr_memcache_value_t keyed by strings, contains the  *        result of the multiget call.  * @return  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_memcache_multgetp
argument_list|(
name|apr_memcache_t
operator|*
name|mc
argument_list|,
name|apr_pool_t
operator|*
name|temp_pool
argument_list|,
name|apr_pool_t
operator|*
name|data_pool
argument_list|,
name|apr_hash_t
operator|*
name|values
argument_list|)
expr_stmt|;
comment|/**  * Sets a value by key on the server  * @param mc client to use  * @param key   null terminated string containing the key  * @param baton data to store on the server  * @param data_size   length of data at baton  * @param timeout time in seconds for the data to live on the server  * @param flags any flags set by the client for this key  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_memcache_set
argument_list|(
argument|apr_memcache_t *mc
argument_list|,
argument|const char *key
argument_list|,
argument|char *baton
argument_list|,
argument|const apr_size_t data_size
argument_list|,
argument|apr_uint32_t timeout
argument_list|,
argument|apr_uint16_t flags
argument_list|)
empty_stmt|;
comment|/**  * Adds value by key on the server  * @param mc client to use  * @param key   null terminated string containing the key  * @param baton data to store on the server  * @param data_size   length of data at baton  * @param timeout time for the data to live on the server  * @param flags any flags set by the client for this key  * @return APR_SUCCESS if the key was added, APR_EEXIST if the key   * already exists on the server.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_memcache_add
argument_list|(
argument|apr_memcache_t *mc
argument_list|,
argument|const char *key
argument_list|,
argument|char *baton
argument_list|,
argument|const apr_size_t data_size
argument_list|,
argument|apr_uint32_t timeout
argument_list|,
argument|apr_uint16_t flags
argument_list|)
empty_stmt|;
comment|/**  * Replaces value by key on the server  * @param mc client to use  * @param key   null terminated string containing the key  * @param baton data to store on the server  * @param data_size   length of data at baton  * @param timeout time for the data to live on the server  * @param flags any flags set by the client for this key  * @return APR_SUCCESS if the key was added, APR_EEXIST if the key   * did not exist on the server.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_memcache_replace
argument_list|(
argument|apr_memcache_t *mc
argument_list|,
argument|const char *key
argument_list|,
argument|char *baton
argument_list|,
argument|const apr_size_t data_size
argument_list|,
argument|apr_uint32_t timeout
argument_list|,
argument|apr_uint16_t flags
argument_list|)
empty_stmt|;
comment|/**  * Deletes a key from a server  * @param mc client to use  * @param key   null terminated string containing the key  * @param timeout time for the delete to stop other clients from adding  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_memcache_delete
argument_list|(
argument|apr_memcache_t *mc
argument_list|,
argument|const char *key
argument_list|,
argument|apr_uint32_t timeout
argument_list|)
empty_stmt|;
comment|/**  * Increments a value  * @param mc client to use  * @param key   null terminated string containing the key  * @param n     number to increment by  * @param nv    new value after incrementing  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_memcache_incr
argument_list|(
argument|apr_memcache_t *mc
argument_list|,
argument|const char *key
argument_list|,
argument|apr_int32_t n
argument_list|,
argument|apr_uint32_t *nv
argument_list|)
empty_stmt|;
comment|/**  * Decrements a value  * @param mc client to use  * @param key   null terminated string containing the key  * @param n     number to decrement by  * @param new_value    new value after decrementing  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_memcache_decr
argument_list|(
argument|apr_memcache_t *mc
argument_list|,
argument|const char *key
argument_list|,
argument|apr_int32_t n
argument_list|,
argument|apr_uint32_t *new_value
argument_list|)
empty_stmt|;
comment|/**  * Query a server's version  * @param ms    server to query  * @param p     Pool to allocate answer from  * @param baton location to store server version string  * @param len   length of the server version string  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_memcache_version
argument_list|(
name|apr_memcache_server_t
operator|*
name|ms
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|,
name|char
operator|*
operator|*
name|baton
argument_list|)
expr_stmt|;
typedef|typedef
struct|struct
block|{
comment|/** Version string of this server */
specifier|const
name|char
modifier|*
name|version
decl_stmt|;
comment|/** Process id of this server process */
name|apr_uint32_t
name|pid
decl_stmt|;
comment|/** Number of seconds this server has been running */
name|apr_uint32_t
name|uptime
decl_stmt|;
comment|/** current UNIX time according to the server */
name|apr_time_t
name|time
decl_stmt|;
comment|/** The size of a pointer on the current machine */
name|apr_uint32_t
name|pointer_size
decl_stmt|;
comment|/** Accumulated user time for this process */
name|apr_time_t
name|rusage_user
decl_stmt|;
comment|/** Accumulated system time for this process */
name|apr_time_t
name|rusage_system
decl_stmt|;
comment|/** Current number of items stored by the server */
name|apr_uint32_t
name|curr_items
decl_stmt|;
comment|/** Total number of items stored by this server */
name|apr_uint32_t
name|total_items
decl_stmt|;
comment|/** Current number of bytes used by this server to store items */
name|apr_uint64_t
name|bytes
decl_stmt|;
comment|/** Number of open connections */
name|apr_uint32_t
name|curr_connections
decl_stmt|;
comment|/** Total number of connections opened since the server started running */
name|apr_uint32_t
name|total_connections
decl_stmt|;
comment|/** Number of connection structures allocated by the server */
name|apr_uint32_t
name|connection_structures
decl_stmt|;
comment|/** Cumulative number of retrieval requests */
name|apr_uint32_t
name|cmd_get
decl_stmt|;
comment|/** Cumulative number of storage requests */
name|apr_uint32_t
name|cmd_set
decl_stmt|;
comment|/** Number of keys that have been requested and found present */
name|apr_uint32_t
name|get_hits
decl_stmt|;
comment|/** Number of items that have been requested and not found */
name|apr_uint32_t
name|get_misses
decl_stmt|;
comment|/** Number of items removed from cache because they passed their         expiration time */
name|apr_uint64_t
name|evictions
decl_stmt|;
comment|/** Total number of bytes read by this server */
name|apr_uint64_t
name|bytes_read
decl_stmt|;
comment|/** Total number of bytes sent by this server */
name|apr_uint64_t
name|bytes_written
decl_stmt|;
comment|/** Number of bytes this server is allowed to use for storage. */
name|apr_uint32_t
name|limit_maxbytes
decl_stmt|;
comment|/** Number of threads the server is running (if built with threading) */
name|apr_uint32_t
name|threads
decl_stmt|;
block|}
name|apr_memcache_stats_t
typedef|;
comment|/**  * Query a server for statistics  * @param ms    server to query  * @param p     Pool to allocate answer from  * @param stats location of the new statistics structure  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_memcache_stats
argument_list|(
name|apr_memcache_server_t
operator|*
name|ms
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|,
name|apr_memcache_stats_t
operator|*
operator|*
name|stats
argument_list|)
expr_stmt|;
comment|/** @} */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_MEMCACHE_H */
end_comment

end_unit

