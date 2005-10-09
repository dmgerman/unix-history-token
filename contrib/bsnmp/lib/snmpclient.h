begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *	   Kendy Kutzner  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: bsnmp/lib/snmpclient.h,v 1.19 2005/05/23 11:10:14 brandt_h Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSNMP_SNMPCLIENT_H
end_ifndef

begin_define
define|#
directive|define
name|_BSNMP_SNMPCLIENT_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_define
define|#
directive|define
name|SNMP_STRERROR_LEN
value|200
end_define

begin_define
define|#
directive|define
name|SNMP_LOCAL_PATH
value|"/tmp/snmpXXXXXXXXXXXXXX"
end_define

begin_comment
comment|/*  * transport methods  */
end_comment

begin_define
define|#
directive|define
name|SNMP_TRANS_UDP
value|0
end_define

begin_define
define|#
directive|define
name|SNMP_TRANS_LOC_DGRAM
value|1
end_define

begin_define
define|#
directive|define
name|SNMP_TRANS_LOC_STREAM
value|2
end_define

begin_comment
comment|/* type of callback function for responses  * this callback function is responsible for free() any memory associated with  * any of the PDUs. Therefor it may call snmp_pdu_free() */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|snmp_send_cb_f
function_decl|)
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* type of callback function for timeouts */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|snmp_timeout_cb_f
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* timeout start function */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|snmp_timeout_start_f
function_decl|)
parameter_list|(
name|struct
name|timeval
modifier|*
name|timeout
parameter_list|,
name|snmp_timeout_cb_f
name|callback
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* timeout stop function */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|snmp_timeout_stop_f
function_decl|)
parameter_list|(
name|void
modifier|*
name|timeout_id
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Client context.  */
end_comment

begin_struct
struct|struct
name|snmp_client
block|{
name|enum
name|snmp_version
name|version
decl_stmt|;
name|int
name|trans
decl_stmt|;
comment|/* which transport to use */
comment|/* these two are read-only for the application */
name|char
modifier|*
name|cport
decl_stmt|;
comment|/* port number as string */
name|char
modifier|*
name|chost
decl_stmt|;
comment|/* host name or IP address as string */
name|char
name|read_community
index|[
name|SNMP_COMMUNITY_MAXLEN
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|write_community
index|[
name|SNMP_COMMUNITY_MAXLEN
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|timeval
name|timeout
decl_stmt|;
name|u_int
name|retries
decl_stmt|;
name|int
name|dump_pdus
decl_stmt|;
name|size_t
name|txbuflen
decl_stmt|;
name|size_t
name|rxbuflen
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|int32_t
name|next_reqid
decl_stmt|;
name|int32_t
name|max_reqid
decl_stmt|;
name|int32_t
name|min_reqid
decl_stmt|;
name|char
name|error
index|[
name|SNMP_STRERROR_LEN
index|]
decl_stmt|;
name|snmp_timeout_start_f
name|timeout_start
decl_stmt|;
name|snmp_timeout_stop_f
name|timeout_stop
decl_stmt|;
name|char
name|local_path
index|[
sizeof|sizeof
argument_list|(
name|SNMP_LOCAL_PATH
argument_list|)
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* the global context */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|snmp_client
name|snmp_client
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initizialies a snmp_client structure */
end_comment

begin_function_decl
name|void
name|snmp_client_init
parameter_list|(
name|struct
name|snmp_client
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* initialize fields */
end_comment

begin_function_decl
name|int
name|snmp_client_set_host
parameter_list|(
name|struct
name|snmp_client
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
name|snmp_client_set_port
parameter_list|(
name|struct
name|snmp_client
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* open connection to snmp server (hostname or portname can be NULL) */
end_comment

begin_function_decl
name|int
name|snmp_open
parameter_list|(
specifier|const
name|char
modifier|*
name|_hostname
parameter_list|,
specifier|const
name|char
modifier|*
name|_portname
parameter_list|,
specifier|const
name|char
modifier|*
name|_read_community
parameter_list|,
specifier|const
name|char
modifier|*
name|_write_community
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* close connection */
end_comment

begin_function_decl
name|void
name|snmp_close
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* initialize a snmp_pdu structure */
end_comment

begin_function_decl
name|void
name|snmp_pdu_create
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
name|u_int
name|_op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* add pairs of (struct asn_oid *, enum snmp_syntax) to an existing pdu */
end_comment

begin_function_decl
name|int
name|snmp_add_binding
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* check wheater the answer is valid or not */
end_comment

begin_function_decl
name|int
name|snmp_pdu_check
parameter_list|(
specifier|const
name|struct
name|snmp_pdu
modifier|*
name|_req
parameter_list|,
specifier|const
name|struct
name|snmp_pdu
modifier|*
name|_resp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_pdu_send
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
name|_pdu
parameter_list|,
name|snmp_send_cb_f
name|_func
parameter_list|,
name|void
modifier|*
name|_arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  append an index to an oid */
end_comment

begin_function_decl
name|int
name|snmp_oid_append
parameter_list|(
name|struct
name|asn_oid
modifier|*
name|_oid
parameter_list|,
specifier|const
name|char
modifier|*
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* receive a packet */
end_comment

begin_function_decl
name|int
name|snmp_receive
parameter_list|(
name|int
name|_blocking
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This structure is used to describe an SNMP table that is to be fetched.  * The C-structure that is produced by the fetch function must start with  * a TAILQ_ENTRY and an u_int64_t.  */
end_comment

begin_struct
struct|struct
name|snmp_table
block|{
comment|/* base OID of the table */
name|struct
name|asn_oid
name|table
decl_stmt|;
comment|/* type OID of the LastChange variable for the table if any */
name|struct
name|asn_oid
name|last_change
decl_stmt|;
comment|/* maximum number of iterations if table has changed */
name|u_int
name|max_iter
decl_stmt|;
comment|/* size of the C-structure */
name|size_t
name|entry_size
decl_stmt|;
comment|/* number of index fields */
name|u_int
name|index_size
decl_stmt|;
comment|/* bit mask of required fields */
name|uint64_t
name|req_mask
decl_stmt|;
comment|/* indexes and columns to fetch. Ended by a NULL syntax entry */
struct|struct
name|snmp_table_entry
block|{
comment|/* the column sub-oid, ignored for index fields */
name|asn_subid_t
name|subid
decl_stmt|;
comment|/* the syntax of the column or index */
name|enum
name|snmp_syntax
name|syntax
decl_stmt|;
comment|/* offset of the field into the C-structure. For octet strings 	     * this points to an u_char * followed by a size_t */
name|off_t
name|offset
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|__GNUC__
operator|<
literal|3
block|}
name|entries
index|[
literal|0
index|]
struct|;
else|#
directive|else
block|}
name|entries
index|[]
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|};
comment|/* callback type for table fetch */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|snmp_table_cb_f
function_decl|)
parameter_list|(
name|void
modifier|*
name|_list
parameter_list|,
name|void
modifier|*
name|_arg
parameter_list|,
name|int
name|_res
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* fetch a table. The argument points to a TAILQ_HEAD */
end_comment

begin_function_decl
name|int
name|snmp_table_fetch
parameter_list|(
specifier|const
name|struct
name|snmp_table
modifier|*
name|descr
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snmp_table_fetch_async
parameter_list|(
specifier|const
name|struct
name|snmp_table
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|snmp_table_cb_f
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* send a request and wait for the response */
end_comment

begin_function_decl
name|int
name|snmp_dialog
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
name|_req
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
name|_resp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* parse a server specification */
end_comment

begin_function_decl
name|int
name|snmp_parse_server
parameter_list|(
name|struct
name|snmp_client
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSNMP_SNMPCLIENT_H */
end_comment

end_unit

