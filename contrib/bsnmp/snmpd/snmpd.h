begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *  * Redistribution of this software and documentation and use in source and  * binary forms, with or without modification, are permitted provided that  * the following conditions are met:  *  * 1. Redistributions of source code or documentation must retain the above  *    copyright notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE AND DOCUMENTATION IS PROVIDED BY FRAUNHOFER FOKUS  * AND ITS CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * FRAUNHOFER FOKUS OR ITS CONTRIBUTORS  BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $Begemot: bsnmp/snmpd/snmpd.h,v 1.17 2003/01/28 13:44:35 hbb Exp $  *  * Private SNMPd data and functions.  */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<isc/eventlib.h>
end_include

begin_define
define|#
directive|define
name|PATH_SYSCONFIG
value|"/etc:/usr/etc:/usr/local/etc"
end_define

begin_comment
comment|/*************************************************************  *  * Communities  */
end_comment

begin_struct
struct|struct
name|community
block|{
name|struct
name|lmodule
modifier|*
name|owner
decl_stmt|;
comment|/* who created the community */
name|u_int
name|private
decl_stmt|;
comment|/* private name for the module */
name|u_int
name|value
decl_stmt|;
comment|/* value of this community */
name|u_char
modifier|*
name|string
decl_stmt|;
comment|/* the community string */
specifier|const
name|u_char
modifier|*
name|descr
decl_stmt|;
comment|/* description */
name|TAILQ_ENTRY
argument_list|(
argument|community
argument_list|)
name|link
expr_stmt|;
name|struct
name|asn_oid
name|index
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* list of all known communities */
end_comment

begin_extern
extern|extern TAILQ_HEAD(community_list
operator|,
extern|community
end_extern

begin_expr_stmt
unit|)
name|community_list
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*************************************************************  *  * Request IDs.  */
end_comment

begin_struct
struct|struct
name|idrange
block|{
name|u_int
name|type
decl_stmt|;
comment|/* type id */
name|int32_t
name|base
decl_stmt|;
comment|/* base of this range */
name|int32_t
name|size
decl_stmt|;
comment|/* size of this range */
name|int32_t
name|next
decl_stmt|;
comment|/* generator */
name|struct
name|lmodule
modifier|*
name|owner
decl_stmt|;
comment|/* owner module */
name|TAILQ_ENTRY
argument_list|(
argument|idrange
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* list of all known ranges */
end_comment

begin_extern
extern|extern TAILQ_HEAD(idrange_list
operator|,
extern|idrange
end_extern

begin_expr_stmt
unit|)
name|idrange_list
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* identifier generator */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|next_idrange
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* request id generator for traps */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|trap_reqid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*************************************************************  *  * Timers  */
end_comment

begin_struct
struct|struct
name|timer
block|{
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* user function */
name|void
modifier|*
name|udata
decl_stmt|;
comment|/* user data */
name|evTimerID
name|id
decl_stmt|;
comment|/* timer id */
name|struct
name|lmodule
modifier|*
name|owner
decl_stmt|;
comment|/* owner of the timer */
name|LIST_ENTRY
argument_list|(
argument|timer
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* list of all current timers */
end_comment

begin_extern
extern|extern LIST_HEAD(timer_list
operator|,
extern|timer
end_extern

begin_expr_stmt
unit|)
name|timer_list
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*************************************************************  *  * File descriptors  */
end_comment

begin_struct
struct|struct
name|fdesc
block|{
name|int
name|fd
decl_stmt|;
comment|/* the file descriptor */
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* user function */
name|void
modifier|*
name|udata
decl_stmt|;
comment|/* user data */
name|evFileID
name|id
decl_stmt|;
comment|/* file id */
name|struct
name|lmodule
modifier|*
name|owner
decl_stmt|;
comment|/* owner module of the file */
name|LIST_ENTRY
argument_list|(
argument|fdesc
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* list of all current selected files */
end_comment

begin_extern
extern|extern LIST_HEAD(fdesc_list
operator|,
extern|fdesc
end_extern

begin_expr_stmt
unit|)
name|fdesc_list
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*************************************************************  *  * Loadable modules  */
end_comment

begin_define
define|#
directive|define
name|LM_SECTION_MAX
value|14
end_define

begin_struct
struct|struct
name|lmodule
block|{
name|char
name|section
index|[
name|LM_SECTION_MAX
operator|+
literal|1
index|]
decl_stmt|;
comment|/* and index */
name|char
modifier|*
name|path
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
name|void
modifier|*
name|handle
decl_stmt|;
specifier|const
name|struct
name|snmp_module
modifier|*
name|config
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|lmodule
argument_list|)
name|link
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|lmodule
argument_list|)
name|start
expr_stmt|;
name|struct
name|asn_oid
name|index
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LM_STARTED
value|0x0001
end_define

begin_define
define|#
directive|define
name|LM_ONSTARTLIST
value|0x0002
end_define

begin_extern
extern|extern TAILQ_HEAD(lmodules
operator|,
extern|lmodule
end_extern

begin_expr_stmt
unit|)
name|lmodules
expr_stmt|;
end_expr_stmt

begin_function_decl
name|struct
name|lmodule
modifier|*
name|lm_load
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lm_unload
parameter_list|(
name|struct
name|lmodule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lm_start
parameter_list|(
name|struct
name|lmodule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*************************************************************  *  * SNMP ports  */
end_comment

begin_struct
struct|struct
name|snmp_port
block|{
name|u_int8_t
name|addr
index|[
literal|4
index|]
decl_stmt|;
comment|/* host byteorder */
name|u_int16_t
name|port
decl_stmt|;
comment|/* host byteorder */
name|int
name|sock
decl_stmt|;
comment|/* the socket */
name|void
modifier|*
name|id
decl_stmt|;
comment|/* evSelect handle */
name|struct
name|sockaddr_in
name|ret
decl_stmt|;
comment|/* the return address */
name|socklen_t
name|retlen
decl_stmt|;
comment|/* length of that address */
name|TAILQ_ENTRY
argument_list|(
argument|snmp_port
argument_list|)
name|link
expr_stmt|;
name|struct
name|asn_oid
name|index
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|snmp_port_list
argument_list|,
name|snmp_port
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|snmp_port_list
name|snmp_port_list
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|close_snmp_port
parameter_list|(
name|struct
name|snmp_port
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|open_snmp_port
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|struct
name|snmp_port
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|local_port
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* unix path name */
name|int
name|sock
decl_stmt|;
comment|/* the socket */
name|void
modifier|*
name|id
decl_stmt|;
comment|/* evSelect handle */
name|struct
name|sockaddr_un
name|ret
decl_stmt|;
comment|/* the return address */
name|socklen_t
name|retlen
decl_stmt|;
comment|/* length of that address */
name|TAILQ_ENTRY
argument_list|(
argument|local_port
argument_list|)
name|link
expr_stmt|;
name|struct
name|asn_oid
name|index
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|local_port_list
argument_list|,
name|local_port
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|local_port_list
name|local_port_list
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|close_local_port
parameter_list|(
name|struct
name|local_port
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|open_local_port
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|local_port
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*************************************************************  *  * SNMPd scalar configuration.  */
end_comment

begin_struct
struct|struct
name|snmpd
block|{
comment|/* transmit buffer size */
name|u_int32_t
name|txbuf
decl_stmt|;
comment|/* receive buffer size */
name|u_int32_t
name|rxbuf
decl_stmt|;
comment|/* disable community table */
name|int
name|comm_dis
decl_stmt|;
comment|/* authentication traps */
name|int
name|auth_traps
decl_stmt|;
comment|/* source address for V1 traps */
name|u_char
name|trap1addr
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|snmpd
name|snmpd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The debug group  */
end_comment

begin_struct
struct|struct
name|debug
block|{
name|u_int
name|dump_pdus
decl_stmt|;
name|u_int
name|logpri
decl_stmt|;
name|u_int
name|evdebug
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|debug
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * SNMPd statistics table  */
end_comment

begin_struct
struct|struct
name|snmpd_stats
block|{
name|u_int32_t
name|inPkts
decl_stmt|;
comment|/* total packets received */
name|u_int32_t
name|inBadVersions
decl_stmt|;
comment|/* unknown version number */
name|u_int32_t
name|inASNParseErrs
decl_stmt|;
comment|/* fatal parse errors */
name|u_int32_t
name|inBadCommunityNames
decl_stmt|;
name|u_int32_t
name|inBadCommunityUses
decl_stmt|;
name|u_int32_t
name|proxyDrops
decl_stmt|;
comment|/* dropped by proxy function */
name|u_int32_t
name|silentDrops
decl_stmt|;
name|u_int32_t
name|inBadPduTypes
decl_stmt|;
name|u_int32_t
name|inTooLong
decl_stmt|;
name|u_int32_t
name|noTxbuf
decl_stmt|;
name|u_int32_t
name|noRxbuf
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|snmpd_stats
name|snmpd_stats
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * OR Table  */
end_comment

begin_struct
struct|struct
name|objres
block|{
name|TAILQ_ENTRY
argument_list|(
argument|objres
argument_list|)
name|link
expr_stmt|;
name|u_int
name|index
decl_stmt|;
name|struct
name|asn_oid
name|oid
decl_stmt|;
comment|/* the resource OID */
name|char
name|descr
index|[
literal|256
index|]
decl_stmt|;
name|u_int32_t
name|uptime
decl_stmt|;
name|struct
name|lmodule
modifier|*
name|module
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|objres_list
argument_list|,
name|objres
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|objres_list
name|objres_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Trap Sink Table  */
end_comment

begin_struct
struct|struct
name|trapsink
block|{
name|TAILQ_ENTRY
argument_list|(
argument|trapsink
argument_list|)
name|link
expr_stmt|;
name|struct
name|asn_oid
name|index
decl_stmt|;
name|u_int
name|status
decl_stmt|;
name|int
name|socket
decl_stmt|;
name|u_char
name|comm
index|[
name|SNMP_COMMUNITY_MAXLEN
index|]
decl_stmt|;
name|int
name|version
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|TRAPSINK_ACTIVE
init|=
literal|1
block|,
name|TRAPSINK_NOT_IN_SERVICE
init|=
literal|2
block|,
name|TRAPSINK_NOT_READY
init|=
literal|3
block|,
name|TRAPSINK_DESTROY
init|=
literal|6
block|,
name|TRAPSINK_V1
init|=
literal|1
block|,
name|TRAPSINK_V2
init|=
literal|2
block|, }
enum|;
end_enum

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|trapsink_list
argument_list|,
name|trapsink
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|trapsink_list
name|trapsink_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|syspath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* snmpSerialNo */
end_comment

begin_decl_stmt
specifier|extern
name|int32_t
name|snmp_serial_no
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|init_actvals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_config
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|lmodule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|define_macro
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

end_unit

