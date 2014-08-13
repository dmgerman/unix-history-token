begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/config_file.h - reads and stores the config file for unbound.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions for the config file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_CONFIG_FILE_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_CONFIG_FILE_H
end_define

begin_struct_decl
struct_decl|struct
name|config_stub
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|config_strlist
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|config_str2list
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_qstate
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sock_list
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_packed_rrset_key
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * The configuration options.  * Strings are malloced.  */
end_comment

begin_struct
struct|struct
name|config_file
block|{
comment|/** verbosity level as specified in the config file */
name|int
name|verbosity
decl_stmt|;
comment|/** statistics interval (in seconds) */
name|int
name|stat_interval
decl_stmt|;
comment|/** if false, statistics values are reset after printing them */
name|int
name|stat_cumulative
decl_stmt|;
comment|/** if true, the statistics are kept in greater detail */
name|int
name|stat_extended
decl_stmt|;
comment|/** number of threads to create */
name|int
name|num_threads
decl_stmt|;
comment|/** port on which queries are answered. */
name|int
name|port
decl_stmt|;
comment|/** do ip4 query support. */
name|int
name|do_ip4
decl_stmt|;
comment|/** do ip6 query support. */
name|int
name|do_ip6
decl_stmt|;
comment|/** do udp query support. */
name|int
name|do_udp
decl_stmt|;
comment|/** do tcp query support. */
name|int
name|do_tcp
decl_stmt|;
comment|/** tcp upstream queries (no UDP upstream queries) */
name|int
name|tcp_upstream
decl_stmt|;
comment|/** private key file for dnstcp-ssl service (enabled if not NULL) */
name|char
modifier|*
name|ssl_service_key
decl_stmt|;
comment|/** public key file for dnstcp-ssl service */
name|char
modifier|*
name|ssl_service_pem
decl_stmt|;
comment|/** port on which to provide ssl service */
name|int
name|ssl_port
decl_stmt|;
comment|/** if outgoing tcp connections use SSL */
name|int
name|ssl_upstream
decl_stmt|;
comment|/** outgoing port range number of ports (per thread) */
name|int
name|outgoing_num_ports
decl_stmt|;
comment|/** number of outgoing tcp buffers per (per thread) */
name|size_t
name|outgoing_num_tcp
decl_stmt|;
comment|/** number of incoming tcp buffers per (per thread) */
name|size_t
name|incoming_num_tcp
decl_stmt|;
comment|/** allowed udp port numbers, array with 0 if not allowed */
name|int
modifier|*
name|outgoing_avail_ports
decl_stmt|;
comment|/** EDNS buffer size to use */
name|size_t
name|edns_buffer_size
decl_stmt|;
comment|/** number of bytes buffer size for DNS messages */
name|size_t
name|msg_buffer_size
decl_stmt|;
comment|/** size of the message cache */
name|size_t
name|msg_cache_size
decl_stmt|;
comment|/** slabs in the message cache. */
name|size_t
name|msg_cache_slabs
decl_stmt|;
comment|/** number of queries every thread can service */
name|size_t
name|num_queries_per_thread
decl_stmt|;
comment|/** number of msec to wait before items can be jostled out */
name|size_t
name|jostle_time
decl_stmt|;
comment|/** size of the rrset cache */
name|size_t
name|rrset_cache_size
decl_stmt|;
comment|/** slabs in the rrset cache */
name|size_t
name|rrset_cache_slabs
decl_stmt|;
comment|/** host cache ttl in seconds */
name|int
name|host_ttl
decl_stmt|;
comment|/** number of slabs in the infra host cache */
name|size_t
name|infra_cache_slabs
decl_stmt|;
comment|/** max number of hosts in the infra cache */
name|size_t
name|infra_cache_numhosts
decl_stmt|;
comment|/** delay close of udp-timeouted ports, if 0 no delayclose. in msec */
name|int
name|delay_close
decl_stmt|;
comment|/** the target fetch policy for the iterator */
name|char
modifier|*
name|target_fetch_policy
decl_stmt|;
comment|/** automatic interface for incoming messages. Uses ipv6 remapping, 	 * and recvmsg/sendmsg ancillary data to detect interfaces, boolean */
name|int
name|if_automatic
decl_stmt|;
comment|/** SO_RCVBUF size to set on port 53 UDP socket */
name|size_t
name|so_rcvbuf
decl_stmt|;
comment|/** SO_SNDBUF size to set on port 53 UDP socket */
name|size_t
name|so_sndbuf
decl_stmt|;
comment|/** SO_REUSEPORT requested on port 53 sockets */
name|int
name|so_reuseport
decl_stmt|;
comment|/** number of interfaces to open. If 0 default all interfaces. */
name|int
name|num_ifs
decl_stmt|;
comment|/** interface description strings (IP addresses) */
name|char
modifier|*
modifier|*
name|ifs
decl_stmt|;
comment|/** number of outgoing interfaces to open.  	 * If 0 default all interfaces. */
name|int
name|num_out_ifs
decl_stmt|;
comment|/** outgoing interface description strings (IP addresses) */
name|char
modifier|*
modifier|*
name|out_ifs
decl_stmt|;
comment|/** the root hints */
name|struct
name|config_strlist
modifier|*
name|root_hints
decl_stmt|;
comment|/** the stub definitions, linked list */
name|struct
name|config_stub
modifier|*
name|stubs
decl_stmt|;
comment|/** the forward zone definitions, linked list */
name|struct
name|config_stub
modifier|*
name|forwards
decl_stmt|;
comment|/** list of donotquery addresses, linked list */
name|struct
name|config_strlist
modifier|*
name|donotqueryaddrs
decl_stmt|;
comment|/** list of access control entries, linked list */
name|struct
name|config_str2list
modifier|*
name|acls
decl_stmt|;
comment|/** use default localhost donotqueryaddr entries */
name|int
name|donotquery_localhost
decl_stmt|;
comment|/** harden against very small edns buffer sizes */
name|int
name|harden_short_bufsize
decl_stmt|;
comment|/** harden against very large query sizes */
name|int
name|harden_large_queries
decl_stmt|;
comment|/** harden against spoofed glue (out of zone data) */
name|int
name|harden_glue
decl_stmt|;
comment|/** harden against receiving no DNSSEC data for trust anchor */
name|int
name|harden_dnssec_stripped
decl_stmt|;
comment|/** harden against queries that fall under known nxdomain names */
name|int
name|harden_below_nxdomain
decl_stmt|;
comment|/** harden the referral path, query for NS,A,AAAA and validate */
name|int
name|harden_referral_path
decl_stmt|;
comment|/** use 0x20 bits in query as random ID bits */
name|int
name|use_caps_bits_for_id
decl_stmt|;
comment|/** strip away these private addrs from answers, no DNS Rebinding */
name|struct
name|config_strlist
modifier|*
name|private_address
decl_stmt|;
comment|/** allow domain (and subdomains) to use private address space */
name|struct
name|config_strlist
modifier|*
name|private_domain
decl_stmt|;
comment|/** what threshold for unwanted action. */
name|size_t
name|unwanted_threshold
decl_stmt|;
comment|/** the number of seconds maximal TTL used for RRsets and messages */
name|int
name|max_ttl
decl_stmt|;
comment|/** the number of seconds minimum TTL used for RRsets and messages */
name|int
name|min_ttl
decl_stmt|;
comment|/** if prefetching of messages should be performed. */
name|int
name|prefetch
decl_stmt|;
comment|/** if prefetching of DNSKEYs should be performed. */
name|int
name|prefetch_key
decl_stmt|;
comment|/** chrootdir, if not "" or chroot will be done */
name|char
modifier|*
name|chrootdir
decl_stmt|;
comment|/** username to change to, if not "". */
name|char
modifier|*
name|username
decl_stmt|;
comment|/** working directory */
name|char
modifier|*
name|directory
decl_stmt|;
comment|/** filename to log to. */
name|char
modifier|*
name|logfile
decl_stmt|;
comment|/** pidfile to write pid to. */
name|char
modifier|*
name|pidfile
decl_stmt|;
comment|/** should log messages be sent to syslogd */
name|int
name|use_syslog
decl_stmt|;
comment|/** log timestamp in ascii UTC */
name|int
name|log_time_ascii
decl_stmt|;
comment|/** log queries with one line per query */
name|int
name|log_queries
decl_stmt|;
comment|/** do not report identity (id.server, hostname.bind) */
name|int
name|hide_identity
decl_stmt|;
comment|/** do not report version (version.server, version.bind) */
name|int
name|hide_version
decl_stmt|;
comment|/** identity, hostname is returned if "". */
name|char
modifier|*
name|identity
decl_stmt|;
comment|/** version, package version returned if "". */
name|char
modifier|*
name|version
decl_stmt|;
comment|/** the module configuration string */
name|char
modifier|*
name|module_conf
decl_stmt|;
comment|/** files with trusted DS and DNSKEYs in zonefile format, list */
name|struct
name|config_strlist
modifier|*
name|trust_anchor_file_list
decl_stmt|;
comment|/** list of trustanchor keys, linked list */
name|struct
name|config_strlist
modifier|*
name|trust_anchor_list
decl_stmt|;
comment|/** files with 5011 autotrust tracked keys */
name|struct
name|config_strlist
modifier|*
name|auto_trust_anchor_file_list
decl_stmt|;
comment|/** files with trusted DNSKEYs in named.conf format, list */
name|struct
name|config_strlist
modifier|*
name|trusted_keys_file_list
decl_stmt|;
comment|/** DLV anchor file */
name|char
modifier|*
name|dlv_anchor_file
decl_stmt|;
comment|/** DLV anchor inline */
name|struct
name|config_strlist
modifier|*
name|dlv_anchor_list
decl_stmt|;
comment|/** insecure domain list */
name|struct
name|config_strlist
modifier|*
name|domain_insecure
decl_stmt|;
comment|/** if not 0, this value is the validation date for RRSIGs */
name|int32_t
name|val_date_override
decl_stmt|;
comment|/** the minimum for signature clock skew */
name|int32_t
name|val_sig_skew_min
decl_stmt|;
comment|/** the maximum for signature clock skew */
name|int32_t
name|val_sig_skew_max
decl_stmt|;
comment|/** this value sets the number of seconds before revalidating bogus */
name|int
name|bogus_ttl
decl_stmt|;
comment|/** should validator clean additional section for secure msgs */
name|int
name|val_clean_additional
decl_stmt|;
comment|/** log bogus messages by the validator */
name|int
name|val_log_level
decl_stmt|;
comment|/** squelch val_log_level to log - this is library goes to callback */
name|int
name|val_log_squelch
decl_stmt|;
comment|/** should validator allow bogus messages to go through */
name|int
name|val_permissive_mode
decl_stmt|;
comment|/** ignore the CD flag in incoming queries and refuse them bogus data */
name|int
name|ignore_cd
decl_stmt|;
comment|/** nsec3 maximum iterations per key size, string */
name|char
modifier|*
name|val_nsec3_key_iterations
decl_stmt|;
comment|/** autotrust add holddown time, in seconds */
name|unsigned
name|int
name|add_holddown
decl_stmt|;
comment|/** autotrust del holddown time, in seconds */
name|unsigned
name|int
name|del_holddown
decl_stmt|;
comment|/** autotrust keep_missing time, in seconds. 0 is forever. */
name|unsigned
name|int
name|keep_missing
decl_stmt|;
comment|/** size of the key cache */
name|size_t
name|key_cache_size
decl_stmt|;
comment|/** slabs in the key cache. */
name|size_t
name|key_cache_slabs
decl_stmt|;
comment|/** size of the neg cache */
name|size_t
name|neg_cache_size
decl_stmt|;
comment|/** local zones config */
name|struct
name|config_str2list
modifier|*
name|local_zones
decl_stmt|;
comment|/** local zones nodefault list */
name|struct
name|config_strlist
modifier|*
name|local_zones_nodefault
decl_stmt|;
comment|/** local data RRs configged */
name|struct
name|config_strlist
modifier|*
name|local_data
decl_stmt|;
comment|/** unblock lan zones (reverse lookups for 10/8 and so on) */
name|int
name|unblock_lan_zones
decl_stmt|;
comment|/** remote control section. enable toggle. */
name|int
name|remote_control_enable
decl_stmt|;
comment|/** the interfaces the remote control should listen on */
name|struct
name|config_strlist
modifier|*
name|control_ifs
decl_stmt|;
comment|/** port number for the control port */
name|int
name|control_port
decl_stmt|;
comment|/** private key file for server */
name|char
modifier|*
name|server_key_file
decl_stmt|;
comment|/** certificate file for server */
name|char
modifier|*
name|server_cert_file
decl_stmt|;
comment|/** private key file for unbound-control */
name|char
modifier|*
name|control_key_file
decl_stmt|;
comment|/** certificate file for unbound-control */
name|char
modifier|*
name|control_cert_file
decl_stmt|;
comment|/** Python script file */
name|char
modifier|*
name|python_script
decl_stmt|;
comment|/** daemonize, i.e. fork into the background. */
name|int
name|do_daemonize
decl_stmt|;
comment|/* minimal response when positive answer */
name|int
name|minimal_responses
decl_stmt|;
comment|/* RRSet roundrobin */
name|int
name|rrset_roundrobin
decl_stmt|;
comment|/* maximum UDP response size */
name|size_t
name|max_udp_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Stub config options  */
end_comment

begin_struct
struct|struct
name|config_stub
block|{
comment|/** next in list */
name|struct
name|config_stub
modifier|*
name|next
decl_stmt|;
comment|/** domain name (in text) of the stub apex domain */
name|char
modifier|*
name|name
decl_stmt|;
comment|/** list of stub nameserver hosts (domain name) */
name|struct
name|config_strlist
modifier|*
name|hosts
decl_stmt|;
comment|/** list of stub nameserver addresses (IP address) */
name|struct
name|config_strlist
modifier|*
name|addrs
decl_stmt|;
comment|/** if stub-prime is set */
name|int
name|isprime
decl_stmt|;
comment|/** if forward-first is set (failover to without if fails) */
name|int
name|isfirst
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * List of strings for config options  */
end_comment

begin_struct
struct|struct
name|config_strlist
block|{
comment|/** next item in list */
name|struct
name|config_strlist
modifier|*
name|next
decl_stmt|;
comment|/** config option string */
name|char
modifier|*
name|str
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * List of two strings for config options  */
end_comment

begin_struct
struct|struct
name|config_str2list
block|{
comment|/** next item in list */
name|struct
name|config_str2list
modifier|*
name|next
decl_stmt|;
comment|/** first string */
name|char
modifier|*
name|str
decl_stmt|;
comment|/** second string */
name|char
modifier|*
name|str2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** List head for strlist processing, used for append operation. */
end_comment

begin_struct
struct|struct
name|config_strlist_head
block|{
comment|/** first in list of text items */
name|struct
name|config_strlist
modifier|*
name|first
decl_stmt|;
comment|/** last in list of text items */
name|struct
name|config_strlist
modifier|*
name|last
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create config file structure. Filled with default values.  * @return: the new structure or NULL on memory error.  */
end_comment

begin_function_decl
name|struct
name|config_file
modifier|*
name|config_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create config file structure for library use. Filled with default values.  * @return: the new structure or NULL on memory error.  */
end_comment

begin_function_decl
name|struct
name|config_file
modifier|*
name|config_create_forlib
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Read the config file from the specified filename.  * @param config: where options are stored into, must be freshly created.  * @param filename: name of configfile. If NULL nothing is done.  * @param chroot: if not NULL, the chroot dir currently in use (for include).  * @return: false on error. In that case errno is set, ENOENT means   * 	file not found.  */
end_comment

begin_function_decl
name|int
name|config_read
parameter_list|(
name|struct
name|config_file
modifier|*
name|config
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|char
modifier|*
name|chroot
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Destroy the config file structure.  * @param config: to delete.  */
end_comment

begin_function_decl
name|void
name|config_delete
parameter_list|(
name|struct
name|config_file
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Apply config to global constants; this routine is called in single thread.  * @param config: to apply. Side effect: global constants change.  */
end_comment

begin_function_decl
name|void
name|config_apply
parameter_list|(
name|struct
name|config_file
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set the given keyword to the given value.  * @param config: where to store config  * @param option: option name, including the ':' character.  * @param value: value, this string is copied if needed, or parsed.  * 	The caller owns the value string.  * @return 0 on error (malloc or syntax error).  */
end_comment

begin_function_decl
name|int
name|config_set_option
parameter_list|(
name|struct
name|config_file
modifier|*
name|config
parameter_list|,
specifier|const
name|char
modifier|*
name|option
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Call print routine for the given option.  * @param cfg: config.  * @param opt: option name without trailing :.   *	This is different from config_set_option.  * @param func: print func, called as (str, arg) for every data element.  * @param arg: user argument for print func.  * @return false if the option name is not supported (syntax error).  */
end_comment

begin_function_decl
name|int
name|config_get_option
parameter_list|(
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|,
specifier|const
name|char
modifier|*
name|opt
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get an option and return strlist  * @param cfg: config file  * @param opt: option name.  * @param list: list is returned here. malloced, caller must free it.  * @return 0=OK, 1=syntax error, 2=malloc failed.  */
end_comment

begin_function_decl
name|int
name|config_get_option_list
parameter_list|(
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|,
specifier|const
name|char
modifier|*
name|opt
parameter_list|,
name|struct
name|config_strlist
modifier|*
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get an option and collate results into string  * @param cfg: config file  * @param opt: option name.  * @param str: string. malloced, caller must free it.  * @return 0=OK, 1=syntax error, 2=malloc failed.  */
end_comment

begin_function_decl
name|int
name|config_get_option_collate
parameter_list|(
name|struct
name|config_file
modifier|*
name|cfg
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
end_function_decl

begin_comment
comment|/**  * function to print to a file, use as func with config_get_option.  * @param line: text to print. \n appended.  * @param arg: pass a FILE*, like stdout.  */
end_comment

begin_function_decl
name|void
name|config_print_func
parameter_list|(
name|char
modifier|*
name|line
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * function to collate the text strings into a strlist_head.  * @param line: text to append.  * @param arg: pass a strlist_head structure. zeroed on start.  */
end_comment

begin_function_decl
name|void
name|config_collate_func
parameter_list|(
name|char
modifier|*
name|line
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * take a strlist_head list and return a malloc string. separated with newline.  * @param list: strlist first to collate. zeroes return "".  * @return NULL on malloc failure. Or if malloc failure happened in strlist.  */
end_comment

begin_function_decl
name|char
modifier|*
name|config_collate_cat
parameter_list|(
name|struct
name|config_strlist
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Append text at end of list.  * @param list: list head. zeroed at start.  * @param item: new item. malloced by caller. if NULL the insertion fails.  * @return true on success.  */
end_comment

begin_function_decl
name|int
name|cfg_strlist_append
parameter_list|(
name|struct
name|config_strlist_head
modifier|*
name|list
parameter_list|,
name|char
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Insert string into strlist.  * @param head: pointer to strlist head variable.  * @param item: new item. malloced by caller. If NULL the insertion fails.  * @return: true on success.  */
end_comment

begin_function_decl
name|int
name|cfg_strlist_insert
parameter_list|(
name|struct
name|config_strlist
modifier|*
modifier|*
name|head
parameter_list|,
name|char
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Insert string into str2list.  * @param head: pointer to str2list head variable.  * @param item: new item. malloced by caller. If NULL the insertion fails.  * @param i2: 2nd string, malloced by caller. If NULL the insertion fails.  * @return: true on success.  */
end_comment

begin_function_decl
name|int
name|cfg_str2list_insert
parameter_list|(
name|struct
name|config_str2list
modifier|*
modifier|*
name|head
parameter_list|,
name|char
modifier|*
name|item
parameter_list|,
name|char
modifier|*
name|i2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete items in config string list.  * @param list: list.  */
end_comment

begin_function_decl
name|void
name|config_delstrlist
parameter_list|(
name|struct
name|config_strlist
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete items in config double string list.  * @param list: list.  */
end_comment

begin_function_decl
name|void
name|config_deldblstrlist
parameter_list|(
name|struct
name|config_str2list
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete items in config stub list.  * @param list: list.  */
end_comment

begin_function_decl
name|void
name|config_delstubs
parameter_list|(
name|struct
name|config_stub
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert 14digit to time value  * @param str: string of 14 digits  * @return time value or 0 for error.  */
end_comment

begin_function_decl
name|time_t
name|cfg_convert_timeval
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Count number of values in the string.  * format ::= (sp num)+ sp  * num ::= [-](0-9)+  * sp ::= (space|tab)*  *  * @param str: string  * @return: 0 on parse error, or empty string, else  *	number of integer values in the string.  */
end_comment

begin_function_decl
name|int
name|cfg_count_numbers
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert a 'nice' memory or file size into a bytecount  * From '100k' to 102400. and so on. Understands kKmMgG.  * k=1024, m=1024*1024, g=1024*1024*1024.  * @param str: string  * @param res: result is stored here, size in bytes.  * @return: true if parsed correctly, or 0 on a parse error (and an error   * is logged).  */
end_comment

begin_function_decl
name|int
name|cfg_parse_memsize
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Parse local-zone directive into two strings and register it in the config.  * @param cfg: to put it in.  * @param val: argument strings to local-zone, "example.com nodefault".  * @return: false on failure  */
end_comment

begin_function_decl
name|int
name|cfg_parse_local_zone
parameter_list|(
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|,
specifier|const
name|char
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Mark "number" or "low-high" as available or not in ports array.  * @param str: string in input  * @param allow: give true if this range is permitted.  * @param avail: the array from cfg.  * @param num: size of the array (65536).  * @return: true if parsed correctly, or 0 on a parse error (and an error   * is logged).  */
end_comment

begin_function_decl
name|int
name|cfg_mark_ports
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|allow
parameter_list|,
name|int
modifier|*
name|avail
parameter_list|,
name|int
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get a condensed list of ports returned. allocated.  * @param cfg: config file.  * @param avail: the available ports array is returned here.  * @return: number of ports in array or 0 on error.  */
end_comment

begin_function_decl
name|int
name|cfg_condense_ports
parameter_list|(
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|,
name|int
modifier|*
modifier|*
name|avail
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan ports available  * @param avail: the array from cfg.  * @param num: size of the array (65536).  * @return the number of ports available for use.  */
end_comment

begin_function_decl
name|int
name|cfg_scan_ports
parameter_list|(
name|int
modifier|*
name|avail
parameter_list|,
name|int
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Convert a filename to full pathname in original filesys  * @param fname: the path name to convert.  *      Must not be null or empty.  * @param cfg: config struct for chroot and chdir (if set).  * @param use_chdir: if false, only chroot is applied.  * @return pointer to malloced buffer which is: [chroot][chdir]fname  *      or NULL on malloc failure.  */
end_comment

begin_function_decl
name|char
modifier|*
name|fname_after_chroot
parameter_list|(
specifier|const
name|char
modifier|*
name|fname
parameter_list|,
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|,
name|int
name|use_chdir
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert a ptr shorthand into a full reverse-notation PTR record.  * @param str: input string, "IP name"  * @return: malloced string "reversed-ip-name PTR name"  */
end_comment

begin_function_decl
name|char
modifier|*
name|cfg_ptr_reverse
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Append text to the error info for validation.  * @param qstate: query state.  * @param str: copied into query region and appended.  * Failures to allocate are logged.  */
end_comment

begin_function_decl
name|void
name|errinf
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Append text to error info:  from 1.2.3.4  * @param qstate: query state.  * @param origin: sock list with origin of trouble.   *	Every element added.  *	If NULL: nothing is added.  *	if 0len element: 'from cache' is added.  */
end_comment

begin_function_decl
name|void
name|errinf_origin
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|struct
name|sock_list
modifier|*
name|origin
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Append text to error info:  for RRset name type class  * @param qstate: query state.  * @param rr: rrset_key.  */
end_comment

begin_function_decl
name|void
name|errinf_rrset
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|rr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Append text to error info:  str dname  * @param qstate: query state.  * @param str: explanation string  * @param dname: the dname.  */
end_comment

begin_function_decl
name|void
name|errinf_dname
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|uint8_t
modifier|*
name|dname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create error info in string  * @param qstate: query state.  * @return string or NULL on malloc failure (already logged).  *    This string is malloced and has to be freed by caller.  */
end_comment

begin_function_decl
name|char
modifier|*
name|errinf_to_str
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Used during options parsing  */
end_comment

begin_struct
struct|struct
name|config_parser_state
block|{
comment|/** name of file being parser */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/** line number in the file, starts at 1 */
name|int
name|line
decl_stmt|;
comment|/** number of errors encountered */
name|int
name|errors
decl_stmt|;
comment|/** the result of parsing is stored here. */
name|struct
name|config_file
modifier|*
name|cfg
decl_stmt|;
comment|/** the current chroot dir (or NULL if none) */
specifier|const
name|char
modifier|*
name|chroot
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** global config parser object used during config parsing */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|config_parser_state
modifier|*
name|cfg_parser
decl_stmt|;
end_decl_stmt

begin_comment
comment|/** init lex state */
end_comment

begin_function_decl
name|void
name|init_cfg_parse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** lex in file */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|ub_c_in
decl_stmt|;
end_decl_stmt

begin_comment
comment|/** lex out file */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|ub_c_out
decl_stmt|;
end_decl_stmt

begin_comment
comment|/** the yacc lex generated parse function */
end_comment

begin_function_decl
name|int
name|ub_c_parse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** the lexer function */
end_comment

begin_function_decl
name|int
name|ub_c_lex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** wrap function */
end_comment

begin_function_decl
name|int
name|ub_c_wrap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** parsing helpers: print error with file and line numbers */
end_comment

begin_function_decl
name|void
name|ub_c_error
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** parsing helpers: print error with file and line numbers */
end_comment

begin_function_decl
name|void
name|ub_c_error_msg
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTR_FORMAT
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|UB_ON_WINDOWS
end_ifdef

begin_comment
comment|/**  * Obtain registry string (if it exists).  * @param key: key string  * @param name: name of value to fetch.  * @return malloced string with the result or NULL if it did not  * 	exist on an error (logged with log_err) was encountered.  */
end_comment

begin_function_decl
name|char
modifier|*
name|w_lookup_reg_str
parameter_list|(
specifier|const
name|char
modifier|*
name|key
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UB_ON_WINDOWS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_CONFIG_FILE_H */
end_comment

end_unit

