begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ++Copyright++ 1985, 1989  * -  * Copyright (c) 1985, 1989  *    The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  * -  * Portions Copyright (c) 1993 by Digital Equipment Corporation.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Digital Equipment Corporation not be used in advertising or  * publicity pertaining to distribution of the document or software without  * specific, written prior permission.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT  * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  * -  * --Copyright--  */
end_comment

begin_comment
comment|/*  *	@(#)res.h	5.10 (Berkeley) 6/1/90  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *******************************************************************************  *  *  res.h --  *  *	Definitions used by modules of the name server lookup program.  *  *	Copyright (c) 1985  *	Andrew Cherenson  *	U.C. Berkeley  *	CS298-26  Fall 1985  *  *******************************************************************************  */
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_typedef
typedef|typedef
name|int
name|Boolean
typedef|;
end_typedef

begin_comment
comment|/*  *  Define return statuses in addtion to the ones defined in namserv.h  *   let SUCCESS be a synonym for NOERROR  *  *	TIME_OUT	- a socket connection timed out.  *	NO_INFO		- the server didn't find any info about the host.  *	ERROR		- one of the following types of errors:  *			   dn_expand, res_mkquery failed  *			   bad command line, socket operation failed, etc.  *	NONAUTH		- the server didn't have the desired info but  *			  returned the name(s) of some servers who should.  *	NO_RESPONSE	- the server didn't respond.  *  */
end_comment

begin_define
define|#
directive|define
name|SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|TIME_OUT
value|-1
end_define

begin_define
define|#
directive|define
name|NO_INFO
value|-2
end_define

begin_define
define|#
directive|define
name|ERROR
value|-3
end_define

begin_define
define|#
directive|define
name|NONAUTH
value|-4
end_define

begin_define
define|#
directive|define
name|NO_RESPONSE
value|-5
end_define

begin_comment
comment|/*  *  Define additional options for the resolver state structure.  *  *   RES_DEBUG2		more verbose debug level  */
end_comment

begin_define
define|#
directive|define
name|RES_DEBUG2
value|0x80000000
end_define

begin_comment
comment|/*  *  Maximum length of server, host and file names.  */
end_comment

begin_define
define|#
directive|define
name|NAME_LEN
value|256
end_define

begin_comment
comment|/*  * Modified struct hostent from<netdb.h>  *  * "Structures returned by network data base library.  All addresses  * are supplied in host order, and returned in network order (suitable  * for use in system calls)."  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* official name of host */
name|char
modifier|*
modifier|*
name|domains
decl_stmt|;
comment|/* domains it serves */
name|char
modifier|*
modifier|*
name|addrList
decl_stmt|;
comment|/* list of addresses from name server */
block|}
name|ServerInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* official name of host */
name|char
modifier|*
modifier|*
name|aliases
decl_stmt|;
comment|/* alias list */
name|char
modifier|*
modifier|*
name|addrList
decl_stmt|;
comment|/* list of addresses from name server */
name|int
name|addrType
decl_stmt|;
comment|/* host address type */
name|int
name|addrLen
decl_stmt|;
comment|/* length of address */
name|ServerInfo
modifier|*
modifier|*
name|servers
decl_stmt|;
block|}
name|HostInfo
typedef|;
end_typedef

begin_comment
comment|/*  *  FilePtr is used for directing listings to a file.  *  It is global so the Control-C handler can close it.  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|filePtr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * TCP/UDP port of server.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|nsport
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *  External routines:  */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|IsAddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|Print_query
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|Print_cdname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|Print_cdname2
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* fixed width */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|Print_rr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|DecodeType
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* descriptive version of p_type */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|DecodeError
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|Calloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|Malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|NsError
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|PrintServer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|PrintHostInfo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ShowOptions
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|FreeHostInfoPtr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|OpenFile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|res_skip
parameter_list|()
function_decl|;
end_function_decl

end_unit

