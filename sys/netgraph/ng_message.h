begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_message.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Julian Elischer<julian@whistle.com>  *  * $FreeBSD$  * $Whistle: ng_message.h,v 1.12 1999/01/25 01:17:44 archie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_MESSAGE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_MESSAGE_H_
value|1
end_define

begin_comment
comment|/* ASCII string size limits */
end_comment

begin_define
define|#
directive|define
name|NG_TYPELEN
value|15
end_define

begin_comment
comment|/* max type name len (16 with null) */
end_comment

begin_define
define|#
directive|define
name|NG_HOOKLEN
value|15
end_define

begin_comment
comment|/* max hook name len (16 with null) */
end_comment

begin_define
define|#
directive|define
name|NG_NODELEN
value|15
end_define

begin_comment
comment|/* max node name len (16 with null) */
end_comment

begin_define
define|#
directive|define
name|NG_PATHLEN
value|511
end_define

begin_comment
comment|/* max path len     (512 with null) */
end_comment

begin_define
define|#
directive|define
name|NG_CMDSTRLEN
value|15
end_define

begin_comment
comment|/* max command string (16 with null) */
end_comment

begin_define
define|#
directive|define
name|NG_TEXTRESPONSE
value|1024
end_define

begin_comment
comment|/* allow this length for a text response */
end_comment

begin_comment
comment|/* A netgraph message */
end_comment

begin_struct
struct|struct
name|ng_mesg
block|{
struct|struct
name|ng_msghdr
block|{
name|u_char
name|version
decl_stmt|;
comment|/* must == NG_VERSION */
name|u_char
name|spare
decl_stmt|;
comment|/* pad to 2 bytes */
name|u_int16_t
name|arglen
decl_stmt|;
comment|/* length of data */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* message status */
name|u_int32_t
name|token
decl_stmt|;
comment|/* match with reply */
name|u_int32_t
name|typecookie
decl_stmt|;
comment|/* node's type cookie */
name|u_int32_t
name|cmd
decl_stmt|;
comment|/* command identifier */
name|u_char
name|cmdstr
index|[
name|NG_CMDSTRLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* cmd string + \0 */
block|}
name|header
struct|;
name|char
name|data
index|[
literal|0
index|]
decl_stmt|;
comment|/* placeholder for actual data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NG_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|NGF_ORIG
value|0x0000
end_define

begin_comment
comment|/* the msg is the original request */
end_comment

begin_define
define|#
directive|define
name|NGF_RESP
value|0x0001
end_define

begin_comment
comment|/* the message is a response */
end_comment

begin_comment
comment|/*  * Here we describe the "generic" messages that all nodes inherently  * understand. With the exception of NGM_TEXT_STATUS, these are handled  * automatically by the base netgraph code.  */
end_comment

begin_comment
comment|/* Generic message type cookie */
end_comment

begin_define
define|#
directive|define
name|NGM_GENERIC_COOKIE
value|851672668
end_define

begin_comment
comment|/* Generic messages defined for this type cookie */
end_comment

begin_define
define|#
directive|define
name|NGM_SHUTDOWN
value|0x0001
end_define

begin_comment
comment|/* no args */
end_comment

begin_define
define|#
directive|define
name|NGM_MKPEER
value|0x0002
end_define

begin_define
define|#
directive|define
name|NGM_CONNECT
value|0x0003
end_define

begin_define
define|#
directive|define
name|NGM_NAME
value|0x0004
end_define

begin_define
define|#
directive|define
name|NGM_RMHOOK
value|0x0005
end_define

begin_define
define|#
directive|define
name|NGM_NODEINFO
value|0x0006
end_define

begin_comment
comment|/* get nodeinfo for the target */
end_comment

begin_define
define|#
directive|define
name|NGM_LISTHOOKS
value|0x0007
end_define

begin_comment
comment|/* get nodeinfo for the target + hook info */
end_comment

begin_define
define|#
directive|define
name|NGM_LISTNAMES
value|0x0008
end_define

begin_comment
comment|/* list all globally named nodes */
end_comment

begin_define
define|#
directive|define
name|NGM_LISTNODES
value|0x0009
end_define

begin_comment
comment|/* list all nodes, named and unnamed */
end_comment

begin_define
define|#
directive|define
name|NGM_LISTTYPES
value|0x000a
end_define

begin_comment
comment|/* list all installed node types */
end_comment

begin_define
define|#
directive|define
name|NGM_TEXT_STATUS
value|0x000b
end_define

begin_comment
comment|/* (optional) returns human readable status */
end_comment

begin_comment
comment|/*  * Args sections for generic NG commands. All strings are NUL-terminated.  */
end_comment

begin_struct
struct|struct
name|ngm_mkpeer
block|{
name|char
name|type
index|[
name|NG_TYPELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* peer type */
name|char
name|ourhook
index|[
name|NG_HOOKLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* hook name */
name|char
name|peerhook
index|[
name|NG_HOOKLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* peer hook name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ngm_connect
block|{
name|char
name|path
index|[
name|NG_PATHLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* peer path */
name|char
name|ourhook
index|[
name|NG_HOOKLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* hook name */
name|char
name|peerhook
index|[
name|NG_HOOKLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* peer hook name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ngm_name
block|{
name|char
name|name
index|[
name|NG_NODELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* node name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ngm_rmhook
block|{
name|char
name|ourhook
index|[
name|NG_HOOKLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* hook name */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ng_ID_t
value|unsigned int
end_define

begin_comment
comment|/* Structures used in response to NGM_NODEINFO and NGM_LISTHOOKS */
end_comment

begin_struct
struct|struct
name|nodeinfo
block|{
name|char
name|name
index|[
name|NG_NODELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* node name (if any) */
name|char
name|type
index|[
name|NG_TYPELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* peer type */
name|ng_ID_t
name|id
decl_stmt|;
comment|/* unique identifier */
name|u_int32_t
name|hooks
decl_stmt|;
comment|/* number of active hooks */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|linkinfo
block|{
name|char
name|ourhook
index|[
name|NG_HOOKLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* hook name */
name|char
name|peerhook
index|[
name|NG_HOOKLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* peer hook */
name|struct
name|nodeinfo
name|nodeinfo
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hooklist
block|{
name|struct
name|nodeinfo
name|nodeinfo
decl_stmt|;
comment|/* node information */
name|struct
name|linkinfo
name|link
index|[
literal|0
index|]
decl_stmt|;
comment|/* info about each hook */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure used for NGM_LISTNAMES/NGM_LISTNODES (not node specific) */
end_comment

begin_struct
struct|struct
name|namelist
block|{
name|u_int32_t
name|numnames
decl_stmt|;
name|struct
name|nodeinfo
name|nodeinfo
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structures used for NGM_LISTTYPES (not node specific) */
end_comment

begin_struct
struct|struct
name|typeinfo
block|{
name|char
name|typename
index|[
name|NG_TYPELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name of type */
name|u_int32_t
name|numnodes
decl_stmt|;
comment|/* number alive */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|typelist
block|{
name|u_int32_t
name|numtypes
decl_stmt|;
name|struct
name|typeinfo
name|typeinfo
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * For netgraph nodes that are somehow associated with file descriptors  * (e.g., a device that has a /dev entry and is also a netgraph node),  * we define a generic ioctl for requesting the corresponding nodeinfo  * structure and for assigning a name (if there isn't one already).  *  * For these to you need to also #include<sys/ioccom.h>.  */
end_comment

begin_define
define|#
directive|define
name|NGIOCGINFO
value|_IOR('N', 40, struct nodeinfo)
end_define

begin_comment
comment|/* get node info */
end_comment

begin_define
define|#
directive|define
name|NGIOCSETNAME
value|_IOW('N', 41, struct ngm_name)
end_define

begin_comment
comment|/* set node name */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Allocate and initialize a netgraph message "msg" with "len"  * extra bytes of argument. Sets "msg" to NULL if fails.  * Does not initialize token.  */
end_comment

begin_define
define|#
directive|define
name|NG_MKMESSAGE
parameter_list|(
name|msg
parameter_list|,
name|cookie
parameter_list|,
name|cmdid
parameter_list|,
name|len
parameter_list|,
name|how
parameter_list|)
define|\
value|do {								\ 	  MALLOC((msg), struct ng_mesg *, sizeof(struct ng_mesg)	\ 	    + (len), M_NETGRAPH, (how));				\ 	  if ((msg) == NULL)						\ 	    break;							\ 	  bzero((msg), sizeof(struct ng_mesg) + (len));			\ 	  (msg)->header.version = NG_VERSION;				\ 	  (msg)->header.typecookie = (cookie);				\ 	  (msg)->header.cmd = (cmdid);					\ 	  (msg)->header.arglen = (len);					\ 	  strncpy((msg)->header.cmdstr, #cmdid,				\ 	    sizeof((msg)->header.cmdstr) - 1);				\ 	} while (0)
end_define

begin_comment
comment|/*  * Allocate and initialize a response "rsp" to a message "msg"  * with "len" extra bytes of argument. Sets "rsp" to NULL if fails.  */
end_comment

begin_define
define|#
directive|define
name|NG_MKRESPONSE
parameter_list|(
name|rsp
parameter_list|,
name|msg
parameter_list|,
name|len
parameter_list|,
name|how
parameter_list|)
define|\
value|do {								\ 	  MALLOC((rsp), struct ng_mesg *, sizeof(struct ng_mesg)	\ 	    + (len), M_NETGRAPH, (how));				\ 	  if ((rsp) == NULL)						\ 	    break;							\ 	  bzero((rsp), sizeof(struct ng_mesg) + (len));			\ 	  (rsp)->header.version = NG_VERSION;				\ 	  (rsp)->header.arglen = (len);					\ 	  (rsp)->header.token = (msg)->header.token;			\ 	  (rsp)->header.typecookie = (msg)->header.typecookie;		\ 	  (rsp)->header.cmd = (msg)->header.cmd;			\ 	  bcopy((msg)->header.cmdstr, (rsp)->header.cmdstr,		\ 	    sizeof((rsp)->header.cmdstr));				\ 	  (rsp)->header.flags |= NGF_RESP;				\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_MESSAGE_H_ */
end_comment

end_unit

