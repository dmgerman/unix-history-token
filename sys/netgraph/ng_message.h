begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_message.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Julian Elischer<julian@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_message.h,v 1.12 1999/01/25 01:17:44 archie Exp $  */
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

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_GENERIC_NG_MESG_INFO
parameter_list|(
name|dtype
parameter_list|)
value|{			\ 	{							\ 	  { "version",&ng_parse_uint8_type	},	\ 	  { "spare",&ng_parse_uint8_type	},	\ 	  { "arglen",&ng_parse_uint16_type	},	\ 	  { "flags",&ng_parse_hint32_type	},	\ 	  { "token",&ng_parse_uint32_type	},	\ 	  { "typecookie",&ng_parse_uint32_type	},	\ 	  { "cmd",&ng_parse_uint32_type	},	\ 	  { "cmdstr",&ng_parse_cmdbuf_type	},	\ 	  { "data",		(dtype)			},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Negraph type binary compatibility field */
end_comment

begin_define
define|#
directive|define
name|NG_VERSION
value|2
end_define

begin_comment
comment|/* Flags field flags */
end_comment

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
comment|/* Type of a unique node ID */
end_comment

begin_define
define|#
directive|define
name|ng_ID_t
value|unsigned int
end_define

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
value|1
end_define

begin_comment
comment|/* shut down node */
end_comment

begin_define
define|#
directive|define
name|NGM_MKPEER
value|2
end_define

begin_comment
comment|/* create and attach a peer node */
end_comment

begin_define
define|#
directive|define
name|NGM_CONNECT
value|3
end_define

begin_comment
comment|/* connect two nodes */
end_comment

begin_define
define|#
directive|define
name|NGM_NAME
value|4
end_define

begin_comment
comment|/* give a node a name */
end_comment

begin_define
define|#
directive|define
name|NGM_RMHOOK
value|5
end_define

begin_comment
comment|/* break a connection btw. two nodes */
end_comment

begin_define
define|#
directive|define
name|NGM_NODEINFO
value|6
end_define

begin_comment
comment|/* get nodeinfo for the target */
end_comment

begin_define
define|#
directive|define
name|NGM_LISTHOOKS
value|7
end_define

begin_comment
comment|/* get list of hooks on node */
end_comment

begin_define
define|#
directive|define
name|NGM_LISTNAMES
value|8
end_define

begin_comment
comment|/* list all globally named nodes */
end_comment

begin_define
define|#
directive|define
name|NGM_LISTNODES
value|9
end_define

begin_comment
comment|/* list all nodes, named and unnamed */
end_comment

begin_define
define|#
directive|define
name|NGM_LISTTYPES
value|10
end_define

begin_comment
comment|/* list all installed node types */
end_comment

begin_define
define|#
directive|define
name|NGM_TEXT_STATUS
value|11
end_define

begin_comment
comment|/* (optional) get text status report */
end_comment

begin_define
define|#
directive|define
name|NGM_BINARY2ASCII
value|12
end_define

begin_comment
comment|/* convert struct ng_mesg to ascii */
end_comment

begin_define
define|#
directive|define
name|NGM_ASCII2BINARY
value|13
end_define

begin_comment
comment|/* convert ascii to struct ng_mesg */
end_comment

begin_define
define|#
directive|define
name|NGM_TEXT_CONFIG
value|14
end_define

begin_comment
comment|/* (optional) get/set text config */
end_comment

begin_comment
comment|/* Structure used for NGM_MKPEER */
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

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_GENERIC_MKPEER_INFO
parameter_list|()
value|{			\ 	{							\ 	  { "type",&ng_parse_typebuf_type	},	\ 	  { "ourhook",&ng_parse_hookbuf_type	},	\ 	  { "peerhook",&ng_parse_hookbuf_type	},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Structure used for NGM_CONNECT */
end_comment

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

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_GENERIC_CONNECT_INFO
parameter_list|()
value|{			\ 	{							\ 	  { "path",&ng_parse_pathbuf_type	},	\ 	  { "ourhook",&ng_parse_hookbuf_type	},	\ 	  { "peerhook",&ng_parse_hookbuf_type	},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Structure used for NGM_NAME */
end_comment

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

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_GENERIC_NAME_INFO
parameter_list|()
value|{				\ 	{							\ 	  { "name",&ng_parse_nodebuf_type	},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Structure used for NGM_RMHOOK */
end_comment

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

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_GENERIC_RMHOOK_INFO
parameter_list|()
value|{			\ 	{							\ 	  { "hook",&ng_parse_hookbuf_type	},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Structure used for NGM_NODEINFO */
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

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_GENERIC_NODEINFO_INFO
parameter_list|()
value|{			\ 	{							\ 	  { "name",&ng_parse_nodebuf_type	},	\ 	  { "type",&ng_parse_typebuf_type	},	\ 	  { "id",&ng_parse_hint32_type	},	\ 	  { "hooks",&ng_parse_uint32_type	},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Structure used for NGM_LISTHOOKS */
end_comment

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

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_GENERIC_LINKINFO_INFO
parameter_list|(
name|nitype
parameter_list|)
value|{		\ 	{							\ 	  { "ourhook",&ng_parse_hookbuf_type	},	\ 	  { "peerhook",&ng_parse_hookbuf_type	},	\ 	  { "nodeinfo",		(nitype)		},	\ 	  { NULL },						\ 	}							\ }
end_define

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
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_GENERIC_HOOKLIST_INFO
parameter_list|(
name|nitype
parameter_list|,
name|litype
parameter_list|)
value|{		\ 	{							\ 	  { "nodeinfo",		(nitype)		},	\ 	  { "linkinfo",		(litype)		},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Structure used for NGM_LISTNAMES/NGM_LISTNODES */
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
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_GENERIC_LISTNODES_INFO
parameter_list|(
name|niarraytype
parameter_list|)
value|{		\ 	{							\ 	  { "numnames",&ng_parse_uint32_type	},	\ 	  { "nodeinfo",		(niarraytype)		},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Structure used for NGM_LISTTYPES */
end_comment

begin_struct
struct|struct
name|typeinfo
block|{
name|char
name|type_name
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

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_GENERIC_TYPEINFO_INFO
parameter_list|()
value|{		\ 	{							\ 	  { "typename",&ng_parse_typebuf_type	},	\ 	  { "numnodes",&ng_parse_uint32_type	},	\ 	  { NULL },						\ 	}							\ }
end_define

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
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_GENERIC_TYPELIST_INFO
parameter_list|(
name|tiarraytype
parameter_list|)
value|{		\ 	{							\ 	  { "numtypes",&ng_parse_uint32_type	},	\ 	  { "typeinfo",		(tiarraytype)		},	\ 	  { NULL },						\ 	}							\ }
end_define

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
name|_KERNEL
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
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_MESSAGE_H_ */
end_comment

end_unit

