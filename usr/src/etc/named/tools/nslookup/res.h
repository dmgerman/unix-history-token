begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)res.h	5.3 (Berkeley) 2/17/88  */
end_comment

begin_comment
comment|/*  *******************************************************************************  *  *  res.h --  *  *	Definitions used by modules of the name server   *	lookup program.  *  *	Copyright (c) 1985   *  	Andrew Cherenson  *  	CS298-26  Fall 1985  *    *******************************************************************************  */
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

begin_comment
comment|/*  *  Define return statuses in addtion to the ones defined in namserv.h  *   let SUCCESS be a synonym for NOERROR  *  *	TIME_OUT	- a socket connection timed out.  *	NO_INFO		- the server didn't find any info about the host.  *	ERROR		- one of the following types of errors:  *			   dn_expand, res_mkquery failed  *			   bad command line, socket operation failed, etc.  *	NONAUTH		- the server didn't have the desired info but  *			  returned the name(s) of some servers who should.  *  */
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

begin_comment
comment|/*  *  Define additional options for the resolver state structure.  *  *   RES_DEBUG2		more verbose debug level   */
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
value|80
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
comment|/*  *  SockFD is the file descriptor for sockets used to connect with  *  the name servers. It is global so the Control-C handler can close  *  it. Likewise for filePtr, which is used for directing listings  *  to a file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sockFD
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|filePtr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *  External routines:  */
end_comment

begin_function_decl
specifier|extern
name|int
name|Print_query
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|Print_cdname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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
name|inet_ntoa
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

