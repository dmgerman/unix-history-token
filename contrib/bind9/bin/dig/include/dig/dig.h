begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: dig.h,v 1.71.2.6.2.14 2006/12/07 01:26:33 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DIG_H
end_ifndef

begin_define
define|#
directive|define
name|DIG_H
end_define

begin_include
include|#
directive|include
file|<dns/rdatalist.h>
end_include

begin_include
include|#
directive|include
file|<dst/dst.h>
end_include

begin_include
include|#
directive|include
file|<isc/boolean.h>
end_include

begin_include
include|#
directive|include
file|<isc/buffer.h>
end_include

begin_include
include|#
directive|include
file|<isc/bufferlist.h>
end_include

begin_include
include|#
directive|include
file|<isc/formatcheck.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/list.h>
end_include

begin_include
include|#
directive|include
file|<isc/mem.h>
end_include

begin_include
include|#
directive|include
file|<isc/print.h>
end_include

begin_include
include|#
directive|include
file|<isc/sockaddr.h>
end_include

begin_include
include|#
directive|include
file|<isc/socket.h>
end_include

begin_define
define|#
directive|define
name|MXSERV
value|20
end_define

begin_define
define|#
directive|define
name|MXNAME
value|(DNS_NAME_MAXTEXT+1)
end_define

begin_define
define|#
directive|define
name|MXRD
value|32
end_define

begin_define
define|#
directive|define
name|BUFSIZE
value|512
end_define

begin_define
define|#
directive|define
name|COMMSIZE
value|0xffff
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|RESOLV_CONF
end_ifndef

begin_define
define|#
directive|define
name|RESOLV_CONF
value|"/etc/resolv.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OUTPUTBUF
value|32767
end_define

begin_define
define|#
directive|define
name|MAXRRLIMIT
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|MAXTIMEOUT
value|0xffff
end_define

begin_define
define|#
directive|define
name|MAXTRIES
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|MAXNDOTS
value|0xffff
end_define

begin_define
define|#
directive|define
name|MAXPORT
value|0xffff
end_define

begin_define
define|#
directive|define
name|MAXSERIAL
value|0xffffffff
end_define

begin_comment
comment|/*  * Default timeout values  */
end_comment

begin_define
define|#
directive|define
name|TCP_TIMEOUT
value|10
end_define

begin_define
define|#
directive|define
name|UDP_TIMEOUT
value|5
end_define

begin_define
define|#
directive|define
name|SERVER_TIMEOUT
value|1
end_define

begin_define
define|#
directive|define
name|LOOKUP_LIMIT
value|64
end_define

begin_comment
comment|/*  * Lookup_limit is just a limiter, keeping too many lookups from being  * created.  It's job is mainly to prevent the program from running away  * in a tight loop of constant lookups.  It's value is arbitrary.  */
end_comment

begin_comment
comment|/*  * Defaults for the sigchase suboptions.  Consolidated here because  * these control the layout of dig_lookup_t (among other things).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DIG_SIGCHASE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|DIG_SIGCHASE_BU
end_ifndef

begin_define
define|#
directive|define
name|DIG_SIGCHASE_BU
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DIG_SIGCHASE_TD
end_ifndef

begin_define
define|#
directive|define
name|DIG_SIGCHASE_TD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_typedef
typedef|typedef
name|struct
name|dig_lookup
name|dig_lookup_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dig_query
name|dig_query_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dig_server
name|dig_server_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|DIG_SIGCHASE
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|dig_message
name|dig_message_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|dig_server_t
argument_list|)
name|dig_serverlist_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|dig_searchlist
name|dig_searchlist_t
typedef|;
end_typedef

begin_struct
struct|struct
name|dig_lookup
block|{
name|isc_boolean_t
name|pending
decl_stmt|,
comment|/* Pending a successful answer */
name|waiting_connect
decl_stmt|,
name|doing_xfr
decl_stmt|,
name|ns_search_only
decl_stmt|,
comment|/* dig +nssearch, host -C */
name|identify
decl_stmt|,
comment|/* Append an "on server<foo>" message */
name|identify_previous_line
decl_stmt|,
comment|/* Prepend a "Nameserver<foo>:" 					   message, with newline and tab */
name|ignore
decl_stmt|,
name|recurse
decl_stmt|,
name|aaonly
decl_stmt|,
name|adflag
decl_stmt|,
name|cdflag
decl_stmt|,
name|trace
decl_stmt|,
comment|/* dig +trace */
name|trace_root
decl_stmt|,
comment|/* initial query for either +trace or +nssearch */
name|tcp_mode
decl_stmt|,
name|ip6_int
decl_stmt|,
name|comments
decl_stmt|,
name|stats
decl_stmt|,
name|section_question
decl_stmt|,
name|section_answer
decl_stmt|,
name|section_authority
decl_stmt|,
name|section_additional
decl_stmt|,
name|servfail_stops
decl_stmt|,
name|new_search
decl_stmt|,
name|besteffort
decl_stmt|,
name|dnssec
decl_stmt|;
ifdef|#
directive|ifdef
name|DIG_SIGCHASE
name|isc_boolean_t
name|sigchase
decl_stmt|;
if|#
directive|if
name|DIG_SIGCHASE_TD
name|isc_boolean_t
name|do_topdown
decl_stmt|,
name|trace_root_sigchase
decl_stmt|,
name|rdtype_sigchaseset
decl_stmt|,
name|rdclass_sigchaseset
decl_stmt|;
comment|/* Name we are going to validate RRset */
name|char
name|textnamesigchase
index|[
name|MXNAME
index|]
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|char
name|textname
index|[
name|MXNAME
index|]
decl_stmt|;
comment|/* Name we're going to be looking up */
name|char
name|cmdline
index|[
name|MXNAME
index|]
decl_stmt|;
name|dns_rdatatype_t
name|rdtype
decl_stmt|;
name|dns_rdatatype_t
name|qrdtype
decl_stmt|;
if|#
directive|if
name|DIG_SIGCHASE_TD
name|dns_rdatatype_t
name|rdtype_sigchase
decl_stmt|;
name|dns_rdatatype_t
name|qrdtype_sigchase
decl_stmt|;
name|dns_rdataclass_t
name|rdclass_sigchase
decl_stmt|;
endif|#
directive|endif
name|dns_rdataclass_t
name|rdclass
decl_stmt|;
name|isc_boolean_t
name|rdtypeset
decl_stmt|;
name|isc_boolean_t
name|rdclassset
decl_stmt|;
name|char
name|namespace
index|[
name|BUFSIZE
index|]
decl_stmt|;
name|char
name|onamespace
index|[
name|BUFSIZE
index|]
decl_stmt|;
name|isc_buffer_t
name|namebuf
decl_stmt|;
name|isc_buffer_t
name|onamebuf
decl_stmt|;
name|isc_buffer_t
name|renderbuf
decl_stmt|;
name|char
modifier|*
name|sendspace
decl_stmt|;
name|dns_name_t
modifier|*
name|name
decl_stmt|;
name|isc_timer_t
modifier|*
name|timer
decl_stmt|;
name|isc_interval_t
name|interval
decl_stmt|;
name|dns_message_t
modifier|*
name|sendmsg
decl_stmt|;
name|dns_name_t
modifier|*
name|oname
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|dig_lookup_t
argument_list|)
name|link
expr_stmt|;
name|ISC_LIST
argument_list|(
argument|dig_query_t
argument_list|)
name|q
expr_stmt|;
name|dig_query_t
modifier|*
name|current_query
decl_stmt|;
name|dig_serverlist_t
name|my_server_list
decl_stmt|;
name|dig_searchlist_t
modifier|*
name|origin
decl_stmt|;
name|dig_query_t
modifier|*
name|xfr_q
decl_stmt|;
name|isc_uint32_t
name|retries
decl_stmt|;
name|int
name|nsfound
decl_stmt|;
name|isc_uint16_t
name|udpsize
decl_stmt|;
name|isc_uint32_t
name|ixfr_serial
decl_stmt|;
name|isc_buffer_t
name|rdatabuf
decl_stmt|;
name|char
name|rdatastore
index|[
name|MXNAME
index|]
decl_stmt|;
name|dst_context_t
modifier|*
name|tsigctx
decl_stmt|;
name|isc_buffer_t
modifier|*
name|querysig
decl_stmt|;
name|isc_uint32_t
name|msgcounter
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dig_query
block|{
name|dig_lookup_t
modifier|*
name|lookup
decl_stmt|;
name|isc_boolean_t
name|waiting_connect
decl_stmt|,
name|pending_free
decl_stmt|,
name|waiting_senddone
decl_stmt|,
name|first_pass
decl_stmt|,
name|first_soa_rcvd
decl_stmt|,
name|second_rr_rcvd
decl_stmt|,
name|first_repeat_rcvd
decl_stmt|,
name|recv_made
decl_stmt|,
name|warn_id
decl_stmt|;
name|isc_uint32_t
name|first_rr_serial
decl_stmt|;
name|isc_uint32_t
name|second_rr_serial
decl_stmt|;
name|isc_uint32_t
name|msg_count
decl_stmt|;
name|isc_uint32_t
name|rr_count
decl_stmt|;
name|char
modifier|*
name|servname
decl_stmt|;
name|char
modifier|*
name|userarg
decl_stmt|;
name|isc_bufferlist_t
name|sendlist
decl_stmt|,
name|recvlist
decl_stmt|,
name|lengthlist
decl_stmt|;
name|isc_buffer_t
name|recvbuf
decl_stmt|,
name|lengthbuf
decl_stmt|,
name|slbuf
decl_stmt|;
name|char
modifier|*
name|recvspace
decl_stmt|,
name|lengthspace
index|[
literal|4
index|]
decl_stmt|,
name|slspace
index|[
literal|4
index|]
decl_stmt|;
name|isc_socket_t
modifier|*
name|sock
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|dig_query_t
argument_list|)
name|link
expr_stmt|;
name|isc_sockaddr_t
name|sockaddr
decl_stmt|;
name|isc_time_t
name|time_sent
decl_stmt|;
name|isc_buffer_t
name|sendbuf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dig_server
block|{
name|char
name|servername
index|[
name|MXNAME
index|]
decl_stmt|;
name|char
name|userarg
index|[
name|MXNAME
index|]
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|dig_server_t
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dig_searchlist
block|{
name|char
name|origin
index|[
name|MXNAME
index|]
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|dig_searchlist_t
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|DIG_SIGCHASE
end_ifdef

begin_struct
struct|struct
name|dig_message
block|{
name|dns_message_t
modifier|*
name|msg
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|dig_message_t
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|dig_searchlist_t
argument_list|)
name|dig_searchlistlist_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|dig_lookup_t
argument_list|)
name|dig_lookuplist_t
expr_stmt|;
end_typedef

begin_comment
comment|/*  * Externals from dighost.c  */
end_comment

begin_decl_stmt
specifier|extern
name|dig_lookuplist_t
name|lookup_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dig_serverlist_t
name|server_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dig_searchlistlist_t
name|search_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|isc_boolean_t
name|have_ipv4
decl_stmt|,
name|have_ipv6
decl_stmt|,
name|specified_source
decl_stmt|,
name|usesearch
decl_stmt|,
name|qr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|in_port_t
name|port
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|timeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dns_messageid_t
name|id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sendcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ndots
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lookup_counter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|exitcode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|isc_sockaddr_t
name|bind_address
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|keynametext
index|[
name|MXNAME
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|keyfile
index|[
name|MXNAME
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|keysecret
index|[
name|MXNAME
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DIG_SIGCHASE
end_ifdef

begin_decl_stmt
specifier|extern
name|char
name|trustedkey
index|[
name|MXNAME
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|dns_tsigkey_t
modifier|*
name|key
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|isc_boolean_t
name|validated
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|isc_taskmgr_t
modifier|*
name|taskmgr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|isc_task_t
modifier|*
name|global_task
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|isc_boolean_t
name|free_now
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|isc_boolean_t
name|debugging
decl_stmt|,
name|memdebugging
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tries
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fatalexit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Routines in dighost.c.  */
end_comment

begin_function_decl
name|void
name|get_address
parameter_list|(
name|char
modifier|*
name|host
parameter_list|,
name|in_port_t
name|port
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|sockaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|get_reverse
parameter_list|(
name|char
modifier|*
name|reverse
parameter_list|,
name|size_t
name|len
parameter_list|,
name|char
modifier|*
name|value
parameter_list|,
name|isc_boolean_t
name|ip6_int
parameter_list|,
name|isc_boolean_t
name|strict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|debug
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|check_result
parameter_list|(
name|isc_result_t
name|result
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setup_lookup
parameter_list|(
name|dig_lookup_t
modifier|*
name|lookup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_lookup
parameter_list|(
name|dig_lookup_t
modifier|*
name|lookup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|start_lookup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|onrun_callback
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dhmain
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setup_libs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setup_system
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dig_lookup_t
modifier|*
name|requeue_lookup
parameter_list|(
name|dig_lookup_t
modifier|*
name|lookold
parameter_list|,
name|isc_boolean_t
name|servers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dig_lookup_t
modifier|*
name|make_empty_lookup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dig_lookup_t
modifier|*
name|clone_lookup
parameter_list|(
name|dig_lookup_t
modifier|*
name|lookold
parameter_list|,
name|isc_boolean_t
name|servers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dig_server_t
modifier|*
name|make_server
parameter_list|(
specifier|const
name|char
modifier|*
name|servname
parameter_list|,
specifier|const
name|char
modifier|*
name|userarg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flush_server_list
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_nameserver
parameter_list|(
name|char
modifier|*
name|opt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clone_server_list
parameter_list|(
name|dig_serverlist_t
name|src
parameter_list|,
name|dig_serverlist_t
modifier|*
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cancel_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|destroy_libs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_search_domain
parameter_list|(
name|char
modifier|*
name|domain
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DIG_SIGCHASE
end_ifdef

begin_function_decl
name|void
name|clean_trustedkey
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Routines to be defined in dig.c, host.c, and nslookup.c.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DIG_SIGCHASE
end_ifdef

begin_function_decl
name|isc_result_t
name|printrdataset
parameter_list|(
name|dns_name_t
modifier|*
name|owner_name
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|isc_result_t
name|printmessage
parameter_list|(
name|dig_query_t
modifier|*
name|query
parameter_list|,
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|isc_boolean_t
name|headers
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Print the final result of the lookup.  */
end_comment

begin_function_decl
name|void
name|received
parameter_list|(
name|int
name|bytes
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|from
parameter_list|,
name|dig_query_t
modifier|*
name|query
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Print a message about where and when the response  * was received from, like the final comment in the  * output of "dig".  */
end_comment

begin_function_decl
name|void
name|trying
parameter_list|(
name|char
modifier|*
name|frm
parameter_list|,
name|dig_lookup_t
modifier|*
name|lookup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dighost_shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|next_token
parameter_list|(
name|char
modifier|*
modifier|*
name|stringp
parameter_list|,
specifier|const
name|char
modifier|*
name|delim
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DIG_SIGCHASE
end_ifdef

begin_comment
comment|/* Chasing functions */
end_comment

begin_function_decl
name|dns_rdataset_t
modifier|*
name|chase_scanname
parameter_list|(
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_rdatatype_t
name|covers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chase_sig
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

