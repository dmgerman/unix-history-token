begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: ssh1.h,v 1.3 2001/05/30 12:55:13 markus Exp $	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/*  * Definition of message types.  New values can be added, but old values  * should not be removed or without careful consideration of the consequences  * for compatibility.  The maximum value is 254; value 255 is reserved for  * future extension.  */
end_comment

begin_comment
comment|/* Message name */
end_comment

begin_comment
comment|/* msg code */
end_comment

begin_comment
comment|/* arguments */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_NONE
value|0
end_define

begin_comment
comment|/* no message */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_DISCONNECT
value|1
end_define

begin_comment
comment|/* cause (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_PUBLIC_KEY
value|2
end_define

begin_comment
comment|/* ck,msk,srvk,hostk */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_SESSION_KEY
value|3
end_define

begin_comment
comment|/* key (BIGNUM) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_USER
value|4
end_define

begin_comment
comment|/* user (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AUTH_RHOSTS
value|5
end_define

begin_comment
comment|/* user (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AUTH_RSA
value|6
end_define

begin_comment
comment|/* modulus (BIGNUM) */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_AUTH_RSA_CHALLENGE
value|7
end_define

begin_comment
comment|/* int (BIGNUM) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AUTH_RSA_RESPONSE
value|8
end_define

begin_comment
comment|/* int (BIGNUM) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AUTH_PASSWORD
value|9
end_define

begin_comment
comment|/* pass (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_REQUEST_PTY
value|10
end_define

begin_comment
comment|/* TERM, tty modes */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_WINDOW_SIZE
value|11
end_define

begin_comment
comment|/* row,col,xpix,ypix */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_EXEC_SHELL
value|12
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_EXEC_CMD
value|13
end_define

begin_comment
comment|/* cmd (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_SUCCESS
value|14
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_FAILURE
value|15
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_STDIN_DATA
value|16
end_define

begin_comment
comment|/* data (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_STDOUT_DATA
value|17
end_define

begin_comment
comment|/* data (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_STDERR_DATA
value|18
end_define

begin_comment
comment|/* data (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_EOF
value|19
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_EXITSTATUS
value|20
end_define

begin_comment
comment|/* status (int) */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_CHANNEL_OPEN_CONFIRMATION
value|21
end_define

begin_comment
comment|/* channel (int) */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_CHANNEL_OPEN_FAILURE
value|22
end_define

begin_comment
comment|/* channel (int) */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_CHANNEL_DATA
value|23
end_define

begin_comment
comment|/* ch,data (int,str) */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_CHANNEL_CLOSE
value|24
end_define

begin_comment
comment|/* channel (int) */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_CHANNEL_CLOSE_CONFIRMATION
value|25
end_define

begin_comment
comment|/* channel (int) */
end_comment

begin_comment
comment|/*      SSH_CMSG_X11_REQUEST_FORWARDING         26         OBSOLETE */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_X11_OPEN
value|27
end_define

begin_comment
comment|/* channel (int) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_PORT_FORWARD_REQUEST
value|28
end_define

begin_comment
comment|/* p,host,hp (i,s,i) */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_PORT_OPEN
value|29
end_define

begin_comment
comment|/* ch,h,p (i,s,i) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AGENT_REQUEST_FORWARDING
value|30
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_AGENT_OPEN
value|31
end_define

begin_comment
comment|/* port (int) */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_IGNORE
value|32
end_define

begin_comment
comment|/* string */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_EXIT_CONFIRMATION
value|33
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_X11_REQUEST_FORWARDING
value|34
end_define

begin_comment
comment|/* proto,data (s,s) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AUTH_RHOSTS_RSA
value|35
end_define

begin_comment
comment|/* user,mod (s,mpi) */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_DEBUG
value|36
end_define

begin_comment
comment|/* string */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_REQUEST_COMPRESSION
value|37
end_define

begin_comment
comment|/* level 1-9 (int) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_MAX_PACKET_SIZE
value|38
end_define

begin_comment
comment|/* size 4k-1024k (int) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AUTH_TIS
value|39
end_define

begin_comment
comment|/* we use this for s/key */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_AUTH_TIS_CHALLENGE
value|40
end_define

begin_comment
comment|/* challenge (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AUTH_TIS_RESPONSE
value|41
end_define

begin_comment
comment|/* response (string) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_AUTH_KERBEROS
value|42
end_define

begin_comment
comment|/* (KTEXT) */
end_comment

begin_define
define|#
directive|define
name|SSH_SMSG_AUTH_KERBEROS_RESPONSE
value|43
end_define

begin_comment
comment|/* (KTEXT) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_HAVE_KERBEROS_TGT
value|44
end_define

begin_comment
comment|/* credentials (s) */
end_comment

begin_define
define|#
directive|define
name|SSH_CMSG_HAVE_AFS_TOKEN
value|65
end_define

begin_comment
comment|/* token (s) */
end_comment

begin_comment
comment|/* protocol version 1.5 overloads some version 1.3 message types */
end_comment

begin_define
define|#
directive|define
name|SSH_MSG_CHANNEL_INPUT_EOF
value|SSH_MSG_CHANNEL_CLOSE
end_define

begin_define
define|#
directive|define
name|SSH_MSG_CHANNEL_OUTPUT_CLOSE
value|SSH_MSG_CHANNEL_CLOSE_CONFIRMATION
end_define

begin_comment
comment|/*  * Authentication methods.  New types can be added, but old types should not  * be removed for compatibility.  The maximum allowed value is 31.  */
end_comment

begin_define
define|#
directive|define
name|SSH_AUTH_RHOSTS
value|1
end_define

begin_define
define|#
directive|define
name|SSH_AUTH_RSA
value|2
end_define

begin_define
define|#
directive|define
name|SSH_AUTH_PASSWORD
value|3
end_define

begin_define
define|#
directive|define
name|SSH_AUTH_RHOSTS_RSA
value|4
end_define

begin_define
define|#
directive|define
name|SSH_AUTH_TIS
value|5
end_define

begin_define
define|#
directive|define
name|SSH_AUTH_KERBEROS
value|6
end_define

begin_define
define|#
directive|define
name|SSH_PASS_KERBEROS_TGT
value|7
end_define

begin_comment
comment|/* 8 to 15 are reserved */
end_comment

begin_define
define|#
directive|define
name|SSH_PASS_AFS_TOKEN
value|21
end_define

begin_comment
comment|/* Protocol flags.  These are bit masks. */
end_comment

begin_define
define|#
directive|define
name|SSH_PROTOFLAG_SCREEN_NUMBER
value|1
end_define

begin_comment
comment|/* X11 forwarding includes screen */
end_comment

begin_define
define|#
directive|define
name|SSH_PROTOFLAG_HOST_IN_FWD_OPEN
value|2
end_define

begin_comment
comment|/* forwarding opens contain host */
end_comment

end_unit

