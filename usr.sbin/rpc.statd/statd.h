begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995  *	A.R. Gordon (andrew.gordon@net-tel.co.uk).  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the FreeBSD project  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY ANDREW GORDON AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|"sm_inter.h"
end_include

begin_comment
comment|/* These pieces are missing from the distributed sm_inter.x, which	*/
end_comment

begin_comment
comment|/* omits the SM_NOTIFY procedure used between cooperating rpc.statd's	*/
end_comment

begin_define
define|#
directive|define
name|SM_NOTIFY
value|((u_long)6)
end_define

begin_function_decl
specifier|extern
name|void
modifier|*
name|sm_notify_1
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|stat_chge
block|{
name|char
modifier|*
name|mon_name
decl_stmt|;
name|int
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|stat_chge
name|stat_chge
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_stat_chge
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* ------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/*   Data structures for recording monitored hosts    The information held by the status monitor comprises a list of hosts   that we have been asked to monitor, and, associated with each monitored   host, one or more clients to be called back if the monitored host crashes.    The list of monitored hosts must be retained over a crash, so that upon   re-boot we can call the SM_NOTIFY procedure in all those hosts so as to   cause them to start recovery processing.  On the other hand, the client   call-backs are not required to be preserved: they are assumed (in the   protocol design) to be local processes which will have crashed when   we did, and so are discarded on restart.    We handle this by keeping the list of monitored hosts in a file   (/var/statd.state) which is mmap()ed and whose format is described   by the typedef FileLayout.  The lists of client callbacks are chained   off this structure, but are held in normal memory and so will be   lost after a re-boot.  Hence the actual values of MonList * pointers   in the copy on disc have no significance, but their NULL/non-NULL   status indicates whether this host is actually being monitored or if it   is an empty slot in the file. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|MonList_s
block|{
name|struct
name|MonList_s
modifier|*
name|next
decl_stmt|;
comment|/* Next in list or NULL			*/
name|char
name|notifyHost
index|[
name|SM_MAXSTRLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Host to notify		*/
name|int
name|notifyProg
decl_stmt|;
comment|/* RPC program number to call		*/
name|int
name|notifyVers
decl_stmt|;
comment|/* version number			*/
name|int
name|notifyProc
decl_stmt|;
comment|/* procedure number			*/
name|unsigned
name|char
name|notifyData
index|[
literal|16
index|]
decl_stmt|;
comment|/* Opaque data from caller		*/
block|}
name|MonList
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|hostname
index|[
name|SM_MAXSTRLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Name of monitored host	*/
name|int
name|notifyReqd
decl_stmt|;
comment|/* TRUE if we've crashed and not yet	*/
comment|/* informed the monitored host		*/
name|MonList
modifier|*
name|monList
decl_stmt|;
comment|/* List of clients to inform if we	*/
comment|/* hear that the monitored host has	*/
comment|/* crashed, NULL if no longer monitored	*/
block|}
name|HostInfo
typedef|;
end_typedef

begin_comment
comment|/* Overall file layout.  						*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|ourState
decl_stmt|;
comment|/* State number as defined in statd protocol	*/
name|int
name|noOfHosts
decl_stmt|;
comment|/* Number of elements in hosts[]		*/
name|char
name|reserved
index|[
literal|248
index|]
decl_stmt|;
comment|/* Reserved for future use			*/
name|HostInfo
name|hosts
index|[
literal|1
index|]
decl_stmt|;
comment|/* vector of monitored hosts			*/
block|}
name|FileLayout
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HEADER_LEN
value|(sizeof(FileLayout) - sizeof(HostInfo))
end_define

begin_comment
comment|/* ------------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* Global variables		*/
end_comment

begin_decl_stmt
specifier|extern
name|FileLayout
modifier|*
name|status_info
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The mmap()ed status file		*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* =1 to enable diagnostics to syslog	*/
end_comment

begin_comment
comment|/* Function prototypes		*/
end_comment

begin_function_decl
specifier|extern
name|HostInfo
modifier|*
name|find_host
parameter_list|(
name|char
modifier|*
comment|/*hostname*/
parameter_list|,
name|int
comment|/*create*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_file
parameter_list|(
name|char
modifier|*
comment|/*filename*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|notify_hosts
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sync_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

