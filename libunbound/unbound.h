begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * unbound.h - unbound validating resolver public API  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions to resolve DNS queries and   * validate the answers. Synchonously and asynchronously.  *  * Several ways to use this interface from an application wishing  * to perform (validated) DNS lookups.  *  * All start with  *	ctx = ub_ctx_create();  *	err = ub_ctx_add_ta(ctx, "...");  *	err = ub_ctx_add_ta(ctx, "...");  *	... some lookups  *	... call ub_ctx_delete(ctx); when you want to stop.  *  * Application not threaded. Blocking.  *	int err = ub_resolve(ctx, "www.example.com", ...  *	if(err) fprintf(stderr, "lookup error: %s\n", ub_strerror(err));  *	... use the answer  *  * Application not threaded. Non-blocking ('asynchronous').  *      err = ub_resolve_async(ctx, "www.example.com", ... my_callback);  *	... application resumes processing ...  *	... and when either ub_poll(ctx) is true  *	... or when the file descriptor ub_fd(ctx) is readable,  *	... or whenever, the app calls ...  *	ub_process(ctx);  *	... if no result is ready, the app resumes processing above,  *	... or process() calls my_callback() with results.  *  *      ... if the application has nothing more to do, wait for answer  *      ub_wait(ctx);   *  * Application threaded. Blocking.  *	Blocking, same as above. The current thread does the work.  *	Multiple threads can use the *same context*, each does work and uses  *	shared cache data from the context.  *  * Application threaded. Non-blocking ('asynchronous').  *	... setup threaded-asynchronous config option  *	err = ub_ctx_async(ctx, 1);  *	... same as async for non-threaded  *	... the callbacks are called in the thread that calls process(ctx)  *  * Openssl needs to have locking in place, and the application must set  * it up, because a mere library cannot do this, use the calls  * CRYPTO_set_id_callback and CRYPTO_set_locking_callback.  *  * If no threading is compiled in, the above async example uses fork(2) to  * create a process to perform the work. The forked process exits when the   * calling process exits, or ctx_delete() is called.  * Otherwise, for asynchronous with threading, a worker thread is created.  *  * The blocking calls use shared ctx-cache when threaded. Thus  * ub_resolve() and ub_resolve_async()&& ub_wait() are  * not the same. The first makes the current thread do the work, setting  * up buffers, etc, to perform the work (but using shared cache data).  * The second calls another worker thread (or process) to perform the work.  * And no buffers need to be set up, but a context-switch happens.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UB_UNBOUND_H
end_ifndef

begin_define
define|#
directive|define
name|_UB_UNBOUND_H
end_define

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
comment|/** the version of this header file */
define|#
directive|define
name|UNBOUND_VERSION_MAJOR
value|@UNBOUND_VERSION_MAJOR@
define|#
directive|define
name|UNBOUND_VERSION_MINOR
value|@UNBOUND_VERSION_MINOR@
define|#
directive|define
name|UNBOUND_VERSION_MICRO
value|@UNBOUND_VERSION_MICRO@
comment|/**  * The validation context is created to hold the resolver status,  * validation keys and a small cache (containing messages, rrsets,  * roundtrip times, trusted keys, lameness information).  *  * Its contents are internally defined.  */
struct_decl|struct
name|ub_ctx
struct_decl|;
comment|/**  * The validation and resolution results.  * Allocated by the resolver, and need to be freed by the application  * with ub_resolve_free().  */
struct|struct
name|ub_result
block|{
comment|/** The original question, name text string. */
name|char
modifier|*
name|qname
decl_stmt|;
comment|/** the type asked for */
name|int
name|qtype
decl_stmt|;
comment|/** the class asked for */
name|int
name|qclass
decl_stmt|;
comment|/**  	 * a list of network order DNS rdata items, terminated with a  	 * NULL pointer, so that data[0] is the first result entry, 	 * data[1] the second, and the last entry is NULL.  	 * If there was no data, data[0] is NULL. 	 */
name|char
modifier|*
modifier|*
name|data
decl_stmt|;
comment|/** the length in bytes of the data items, len[i] for data[i] */
name|int
modifier|*
name|len
decl_stmt|;
comment|/**  	 * canonical name for the result (the final cname).  	 * zero terminated string. 	 * May be NULL if no canonical name exists. 	 */
name|char
modifier|*
name|canonname
decl_stmt|;
comment|/** 	 * DNS RCODE for the result. May contain additional error code if 	 * there was no data due to an error. 0 (NOERROR) if okay. 	 */
name|int
name|rcode
decl_stmt|;
comment|/** 	 * The DNS answer packet. Network formatted. Can contain DNSSEC types. 	 */
name|void
modifier|*
name|answer_packet
decl_stmt|;
comment|/** length of the answer packet in octets. */
name|int
name|answer_len
decl_stmt|;
comment|/** 	 * If there is any data, this is true. 	 * If false, there was no data (nxdomain may be true, rcode can be set). 	 */
name|int
name|havedata
decl_stmt|;
comment|/**  	 * If there was no data, and the domain did not exist, this is true. 	 * If it is false, and there was no data, then the domain name  	 * is purported to exist, but the requested data type is not available. 	 */
name|int
name|nxdomain
decl_stmt|;
comment|/** 	 * True, if the result is validated securely. 	 * False, if validation failed or domain queried has no security info. 	 * 	 * It is possible to get a result with no data (havedata is false), 	 * and secure is true. This means that the non-existance of the data 	 * was cryptographically proven (with signatures). 	 */
name|int
name|secure
decl_stmt|;
comment|/**  	 * If the result was not secure (secure==0), and this result is due  	 * to a security failure, bogus is true. 	 * This means the data has been actively tampered with, signatures 	 * failed, expected signatures were not present, timestamps on  	 * signatures were out of date and so on. 	 * 	 * If !secure and !bogus, this can happen if the data is not secure  	 * because security is disabled for that domain name.  	 * This means the data is from a domain where data is not signed. 	 */
name|int
name|bogus
decl_stmt|;
comment|/** 	 * If the result is bogus this contains a string (zero terminated) 	 * that describes the failure.  There may be other errors as well 	 * as the one described, the description may not be perfectly accurate. 	 * Is NULL if the result is not bogus. 	 */
name|char
modifier|*
name|why_bogus
decl_stmt|;
comment|/** 	 * TTL for the result, in seconds.  If the security is bogus, then 	 * you also cannot trust this value. 	 */
name|int
name|ttl
decl_stmt|;
block|}
struct|;
comment|/**  * Callback for results of async queries.  * The readable function definition looks like:  * void my_callback(void* my_arg, int err, struct ub_result* result);  * It is called with  *	void* my_arg: your pointer to a (struct of) data of your choice,   *		or NULL.  *	int err: if 0 all is OK, otherwise an error occured and no results  *	     are forthcoming.  *	struct result: pointer to more detailed result structure.  *		This structure is allocated on the heap and needs to be  *		freed with ub_resolve_free(result);  */
typedef|typedef
name|void
function_decl|(
modifier|*
name|ub_callback_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ub_result
modifier|*
parameter_list|)
function_decl|;
comment|/**  * Create a resolving and validation context.  * The information from /etc/resolv.conf and /etc/hosts is not utilised by  * default. Use ub_ctx_resolvconf and ub_ctx_hosts to read them.  * @return a new context. default initialisation.  * 	returns NULL on error.  */
name|struct
name|ub_ctx
modifier|*
name|ub_ctx_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Destroy a validation context and free all its resources.  * Outstanding async queries are killed and callbacks are not called for them.  * @param ctx: context to delete.  */
name|void
name|ub_ctx_delete
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/**  * Set an option for the context.  * @param ctx: context.  * @param opt: option name from the unbound.conf config file format.  *	(not all settings applicable). The name includes the trailing ':'  *	for example ub_ctx_set_option(ctx, "logfile:", "mylog.txt");  * 	This is a power-users interface that lets you specify all sorts  * 	of options.  * 	For some specific options, such as adding trust anchors, special  * 	routines exist.  * @param val: value of the option.  * @return: 0 if OK, else error.  */
name|int
name|ub_ctx_set_option
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|opt
parameter_list|,
specifier|const
name|char
modifier|*
name|val
parameter_list|)
function_decl|;
comment|/**  * Get an option from the context.  * @param ctx: context.  * @param opt: option name from the unbound.conf config file format.  *	(not all settings applicable). The name excludes the trailing ':'  *	for example ub_ctx_get_option(ctx, "logfile",&result);  * 	This is a power-users interface that lets you specify all sorts  * 	of options.  * @param str: the string is malloced and returned here. NULL on error.  * 	The caller must free() the string.  In cases with multiple   * 	entries (auto-trust-anchor-file), a newline delimited list is   * 	returned in the string.  * @return 0 if OK else an error code (malloc failure, syntax error).  */
name|int
name|ub_ctx_get_option
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|opt
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|)
function_decl|;
comment|/**  * setup configuration for the given context.  * @param ctx: context.  * @param fname: unbound config file (not all settings applicable).  * 	This is a power-users interface that lets you specify all sorts  * 	of options.  * 	For some specific options, such as adding trust anchors, special  * 	routines exist.  * @return: 0 if OK, else error.  */
name|int
name|ub_ctx_config
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
comment|/**  * Set machine to forward DNS queries to, the caching resolver to use.   * IP4 or IP6 address. Forwards all DNS requests to that machine, which   * is expected to run a recursive resolver. If the proxy is not   * DNSSEC-capable, validation may fail. Can be called several times, in   * that case the addresses are used as backup servers.  *  * To read the list of nameservers from /etc/resolv.conf (from DHCP or so),  * use the call ub_ctx_resolvconf.  *  * @param ctx: context.  *	At this time it is only possible to set configuration before the  *	first resolve is done.  * @param addr: address, IP4 or IP6 in string format.  * 	If the addr is NULL, forwarding is disabled.  * @return 0 if OK, else error.  */
name|int
name|ub_ctx_set_fwd
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|addr
parameter_list|)
function_decl|;
comment|/**  * Read list of nameservers to use from the filename given.  * Usually "/etc/resolv.conf". Uses those nameservers as caching proxies.  * If they do not support DNSSEC, validation may fail.  *  * Only nameservers are picked up, the searchdomain, ndots and other  * settings from resolv.conf(5) are ignored.  *  * @param ctx: context.  *	At this time it is only possible to set configuration before the  *	first resolve is done.  * @param fname: file name string. If NULL "/etc/resolv.conf" is used.  * @return 0 if OK, else error.  */
name|int
name|ub_ctx_resolvconf
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
comment|/**  * Read list of hosts from the filename given.  * Usually "/etc/hosts".   * These addresses are not flagged as DNSSEC secure when queried for.  *  * @param ctx: context.  *	At this time it is only possible to set configuration before the  *	first resolve is done.  * @param fname: file name string. If NULL "/etc/hosts" is used.  * @return 0 if OK, else error.  */
name|int
name|ub_ctx_hosts
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
comment|/**  * Add a trust anchor to the given context.  * The trust anchor is a string, on one line, that holds a valid DNSKEY or  * DS RR.   * @param ctx: context.  *	At this time it is only possible to add trusted keys before the  *	first resolve is done.  * @param ta: string, with zone-format RR on one line.  * 	[domainname] [TTL optional] [type] [class optional] [rdata contents]  * @return 0 if OK, else error.  */
name|int
name|ub_ctx_add_ta
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|ta
parameter_list|)
function_decl|;
comment|/**  * Add trust anchors to the given context.  * Pass name of a file with DS and DNSKEY records (like from dig or drill).  * @param ctx: context.  *	At this time it is only possible to add trusted keys before the  *	first resolve is done.  * @param fname: filename of file with keyfile with trust anchors.  * @return 0 if OK, else error.  */
name|int
name|ub_ctx_add_ta_file
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
comment|/**  * Add trust anchors to the given context.  * Pass the name of a bind-style config file with trusted-keys{}.  * @param ctx: context.  *	At this time it is only possible to add trusted keys before the  *	first resolve is done.  * @param fname: filename of file with bind-style config entries with trust  * 	anchors.  * @return 0 if OK, else error.  */
name|int
name|ub_ctx_trustedkeys
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
comment|/**  * Set debug output (and error output) to the specified stream.  * Pass NULL to disable. Default is stderr.  * @param ctx: context.  * @param out: FILE* out file stream to log to.  * 	Type void* to avoid stdio dependency of this header file.  * @return 0 if OK, else error.  */
name|int
name|ub_ctx_debugout
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
name|void
modifier|*
name|out
parameter_list|)
function_decl|;
comment|/**  * Set debug verbosity for the context  * Output is directed to stderr.  * @param ctx: context.  * @param d: debug level, 0 is off, 1 is very minimal, 2 is detailed,   *	and 3 is lots.  * @return 0 if OK, else error.  */
name|int
name|ub_ctx_debuglevel
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
name|int
name|d
parameter_list|)
function_decl|;
comment|/**  * Set a context behaviour for asynchronous action.  * @param ctx: context.  * @param dothread: if true, enables threading and a call to resolve_async()   *	creates a thread to handle work in the background.  *	If false, a process is forked to handle work in the background.  *	Changes to this setting after async() calls have been made have   *	no effect (delete and re-create the context to change).  * @return 0 if OK, else error.  */
name|int
name|ub_ctx_async
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
name|int
name|dothread
parameter_list|)
function_decl|;
comment|/**  * Poll a context to see if it has any new results  * Do not poll in a loop, instead extract the fd below to poll for readiness,  * and then check, or wait using the wait routine.  * @param ctx: context.  * @return: 0 if nothing to read, or nonzero if a result is available.  * 	If nonzero, call ctx_process() to do callbacks.  */
name|int
name|ub_poll
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/**  * Wait for a context to finish with results. Calls ub_process() after  * the wait for you. After the wait, there are no more outstanding   * asynchronous queries.  * @param ctx: context.  * @return: 0 if OK, else error.  */
name|int
name|ub_wait
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/**  * Get file descriptor. Wait for it to become readable, at this point  * answers are returned from the asynchronous validating resolver.  * Then call the ub_process to continue processing.  * This routine works immediately after context creation, the fd  * does not change.  * @param ctx: context.  * @return: -1 on error, or file descriptor to use select(2) with.  */
name|int
name|ub_fd
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/**  * Call this routine to continue processing results from the validating  * resolver (when the fd becomes readable).  * Will perform necessary callbacks.  * @param ctx: context  * @return: 0 if OK, else error.  */
name|int
name|ub_process
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/**  * Perform resolution and validation of the target name.  * @param ctx: context.  *	The context is finalized, and can no longer accept config changes.  * @param name: domain name in text format (a zero terminated text string).  * @param rrtype: type of RR in host order, 1 is A (address).  * @param rrclass: class of RR in host order, 1 is IN (for internet).  * @param result: the result data is returned in a newly allocated result  * 	structure. May be NULL on return, return value is set to an error   * 	in that case (out of memory).  * @return 0 if OK, else error.  */
name|int
name|ub_resolve
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|rrtype
parameter_list|,
name|int
name|rrclass
parameter_list|,
name|struct
name|ub_result
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
comment|/**  * Perform resolution and validation of the target name.  * Asynchronous, after a while, the callback will be called with your  * data and the result.  * @param ctx: context.  *	If no thread or process has been created yet to perform the  *	work in the background, it is created now.  *	The context is finalized, and can no longer accept config changes.  * @param name: domain name in text format (a string).  * @param rrtype: type of RR in host order, 1 is A.  * @param rrclass: class of RR in host order, 1 is IN (for internet).  * @param mydata: this data is your own data (you can pass NULL),  * 	and is passed on to the callback function.  * @param callback: this is called on completion of the resolution.  * 	It is called as:  * 	void callback(void* mydata, int err, struct ub_result* result)  * 	with mydata: the same as passed here, you may pass NULL,  * 	with err: is 0 when a result has been found.  * 	with result: a newly allocated result structure.  *		The result may be NULL, in that case err is set.  *  * 	If an error happens during processing, your callback will be called  * 	with error set to a nonzero value (and result==NULL).  * @param async_id: if you pass a non-NULL value, an identifier number is  *	returned for the query as it is in progress. It can be used to   *	cancel the query.  * @return 0 if OK, else error.  */
name|int
name|ub_resolve_async
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|rrtype
parameter_list|,
name|int
name|rrclass
parameter_list|,
name|void
modifier|*
name|mydata
parameter_list|,
name|ub_callback_t
name|callback
parameter_list|,
name|int
modifier|*
name|async_id
parameter_list|)
function_decl|;
comment|/**  * Cancel an async query in progress.  * Its callback will not be called.  *  * @param ctx: context.  * @param async_id: which query to cancel.  * @return 0 if OK, else error.  * This routine can return an error if the async_id passed does not exist  * or has already been delivered. If another thread is processing results  * at the same time, the result may be delivered at the same time and the  * cancel fails with an error.  Also the cancel can fail due to a system  * error, no memory or socket failures.  */
name|int
name|ub_cancel
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
name|int
name|async_id
parameter_list|)
function_decl|;
comment|/**  * Free storage associated with a result structure.  * @param result: to free  */
name|void
name|ub_resolve_free
parameter_list|(
name|struct
name|ub_result
modifier|*
name|result
parameter_list|)
function_decl|;
comment|/**   * Convert error value to a human readable string.  * @param err: error code from one of the ub_val* functions.  * @return pointer to constant text string, zero terminated.  */
specifier|const
name|char
modifier|*
name|ub_strerror
parameter_list|(
name|int
name|err
parameter_list|)
function_decl|;
comment|/**  * Debug routine.  Print the local zone information to debug output.  * @param ctx: context.  Is finalized by the routine.  * @return 0 if OK, else error.  */
name|int
name|ub_ctx_print_local_zones
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/**  * Add a new zone with the zonetype to the local authority info of the   * library.  * @param ctx: context.  Is finalized by the routine.  * @param zone_name: name of the zone in text, "example.com"  *	If it already exists, the type is updated.  * @param zone_type: type of the zone (like for unbound.conf) in text.  * @return 0 if OK, else error.  */
name|int
name|ub_ctx_zone_add
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|zone_name
parameter_list|,
specifier|const
name|char
modifier|*
name|zone_type
parameter_list|)
function_decl|;
comment|/**  * Remove zone from local authority info of the library.  * @param ctx: context.  Is finalized by the routine.  * @param zone_name: name of the zone in text, "example.com"  *	If it does not exist, nothing happens.  * @return 0 if OK, else error.  */
name|int
name|ub_ctx_zone_remove
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|zone_name
parameter_list|)
function_decl|;
comment|/**  * Add localdata to the library local authority info.  * Similar to local-data config statement.  * @param ctx: context.  Is finalized by the routine.  * @param data: the resource record in text format, for example  *	"www.example.com IN A 127.0.0.1"  * @return 0 if OK, else error.  */
name|int
name|ub_ctx_data_add
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**  * Remove localdata from the library local authority info.  * @param ctx: context.  Is finalized by the routine.  * @param data: the name to delete all data from, like "www.example.com".  * @return 0 if OK, else error.  */
name|int
name|ub_ctx_data_remove
parameter_list|(
name|struct
name|ub_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**  * Get a version string from the libunbound implementation.  * @return a static constant string with the version number.  */
specifier|const
name|char
modifier|*
name|ub_version
parameter_list|(
name|void
parameter_list|)
function_decl|;
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
comment|/* _UB_UNBOUND_H */
end_comment

end_unit

