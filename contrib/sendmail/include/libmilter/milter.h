begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *  *	$Id: milter.h,v 8.24.16.10 2001/07/20 04:19:35 gshapiro Exp $  */
end_comment

begin_comment
comment|/* **  MILTER.H -- Global definitions for mail filter and MTA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBMILTER_MILTER_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBMILTER_MILTER_H
value|1
end_define

begin_include
include|#
directive|include
file|"libmilter/mfapi.h"
end_include

begin_include
include|#
directive|include
file|"sendmail.h"
end_include

begin_comment
comment|/* Shared protocol constants */
end_comment

begin_define
define|#
directive|define
name|MILTER_LEN_BYTES
value|4
end_define

begin_comment
comment|/* length of 32 bit integer in bytes */
end_comment

begin_define
define|#
directive|define
name|MILTER_OPTLEN
value|(MILTER_LEN_BYTES * 3)
end_define

begin_comment
comment|/* length of options */
end_comment

begin_define
define|#
directive|define
name|MILTER_CHUNK_SIZE
value|65535
end_define

begin_comment
comment|/* body chunk size */
end_comment

begin_comment
comment|/* address families */
end_comment

begin_define
define|#
directive|define
name|SMFIA_UNKNOWN
value|'U'
end_define

begin_comment
comment|/* unknown */
end_comment

begin_define
define|#
directive|define
name|SMFIA_UNIX
value|'L'
end_define

begin_comment
comment|/* unix/local */
end_comment

begin_define
define|#
directive|define
name|SMFIA_INET
value|'4'
end_define

begin_comment
comment|/* inet */
end_comment

begin_define
define|#
directive|define
name|SMFIA_INET6
value|'6'
end_define

begin_comment
comment|/* inet6 */
end_comment

begin_comment
comment|/* commands: don't use anything smaller than ' ' */
end_comment

begin_define
define|#
directive|define
name|SMFIC_ABORT
value|'A'
end_define

begin_comment
comment|/* Abort */
end_comment

begin_define
define|#
directive|define
name|SMFIC_BODY
value|'B'
end_define

begin_comment
comment|/* Body chunk */
end_comment

begin_define
define|#
directive|define
name|SMFIC_CONNECT
value|'C'
end_define

begin_comment
comment|/* Connection information */
end_comment

begin_define
define|#
directive|define
name|SMFIC_MACRO
value|'D'
end_define

begin_comment
comment|/* Define macro */
end_comment

begin_define
define|#
directive|define
name|SMFIC_BODYEOB
value|'E'
end_define

begin_comment
comment|/* final body chunk (End) */
end_comment

begin_define
define|#
directive|define
name|SMFIC_HELO
value|'H'
end_define

begin_comment
comment|/* HELO/EHLO */
end_comment

begin_define
define|#
directive|define
name|SMFIC_HEADER
value|'L'
end_define

begin_comment
comment|/* Header */
end_comment

begin_define
define|#
directive|define
name|SMFIC_MAIL
value|'M'
end_define

begin_comment
comment|/* MAIL from */
end_comment

begin_define
define|#
directive|define
name|SMFIC_EOH
value|'N'
end_define

begin_comment
comment|/* EOH */
end_comment

begin_define
define|#
directive|define
name|SMFIC_OPTNEG
value|'O'
end_define

begin_comment
comment|/* Option negotiation */
end_comment

begin_define
define|#
directive|define
name|SMFIC_QUIT
value|'Q'
end_define

begin_comment
comment|/* QUIT */
end_comment

begin_define
define|#
directive|define
name|SMFIC_RCPT
value|'R'
end_define

begin_comment
comment|/* RCPT to */
end_comment

begin_comment
comment|/* actions (replies) */
end_comment

begin_define
define|#
directive|define
name|SMFIR_ADDRCPT
value|'+'
end_define

begin_comment
comment|/* add recipient */
end_comment

begin_define
define|#
directive|define
name|SMFIR_DELRCPT
value|'-'
end_define

begin_comment
comment|/* remove recipient */
end_comment

begin_define
define|#
directive|define
name|SMFIR_ACCEPT
value|'a'
end_define

begin_comment
comment|/* accept */
end_comment

begin_define
define|#
directive|define
name|SMFIR_REPLBODY
value|'b'
end_define

begin_comment
comment|/* replace body (chunk) */
end_comment

begin_define
define|#
directive|define
name|SMFIR_CONTINUE
value|'c'
end_define

begin_comment
comment|/* continue */
end_comment

begin_define
define|#
directive|define
name|SMFIR_DISCARD
value|'d'
end_define

begin_comment
comment|/* discard */
end_comment

begin_define
define|#
directive|define
name|SMFIR_CHGHEADER
value|'m'
end_define

begin_comment
comment|/* change header */
end_comment

begin_define
define|#
directive|define
name|SMFIR_PROGRESS
value|'p'
end_define

begin_comment
comment|/* progress */
end_comment

begin_define
define|#
directive|define
name|SMFIR_REJECT
value|'r'
end_define

begin_comment
comment|/* reject */
end_comment

begin_define
define|#
directive|define
name|SMFIR_TEMPFAIL
value|'t'
end_define

begin_comment
comment|/* tempfail */
end_comment

begin_define
define|#
directive|define
name|SMFIR_ADDHEADER
value|'h'
end_define

begin_comment
comment|/* add header */
end_comment

begin_define
define|#
directive|define
name|SMFIR_REPLYCODE
value|'y'
end_define

begin_comment
comment|/* reply code etc */
end_comment

begin_comment
comment|/* What the MTA can send/filter wants in protocol */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NOCONNECT
value|0x00000001L
end_define

begin_comment
comment|/* MTA should not send connect info */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NOHELO
value|0x00000002L
end_define

begin_comment
comment|/* MTA should not send HELO info */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NOMAIL
value|0x00000004L
end_define

begin_comment
comment|/* MTA should not send MAIL info */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NORCPT
value|0x00000008L
end_define

begin_comment
comment|/* MTA should not send RCPT info */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NOBODY
value|0x00000010L
end_define

begin_comment
comment|/* MTA should not send body */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NOHDRS
value|0x00000020L
end_define

begin_comment
comment|/* MTA should not send headers */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NOEOH
value|0x00000040L
end_define

begin_comment
comment|/* MTA should not send EOH */
end_comment

begin_define
define|#
directive|define
name|SMFI_V1_PROT
value|0x0000003FL
end_define

begin_comment
comment|/* The protocol of V1 filter */
end_comment

begin_define
define|#
directive|define
name|SMFI_V2_PROT
value|0x0000007FL
end_define

begin_comment
comment|/* The protocol of V2 filter */
end_comment

begin_define
define|#
directive|define
name|SMFI_CURR_PROT
value|SMFI_V2_PROT
end_define

begin_comment
comment|/* The current version */
end_comment

begin_comment
comment|/* socket and thread portability */
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_typedef
typedef|typedef
name|pthread_t
name|sthread_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|socket_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_MACROS_ENTRIES
value|4
end_define

begin_comment
comment|/* max size of macro pointer array */
end_comment

begin_comment
comment|/* **  context for milter **  implementation hint: **  macros are stored in mac_buf[] as sequence of: **  macro_name \0 macro_value **  (just as read from the MTA) **  mac_ptr is a list of pointers into mac_buf to the beginning of each **  entry, i.e., macro_name, macro_value, ... */
end_comment

begin_struct
struct|struct
name|smfi_str
block|{
name|sthread_t
name|ctx_id
decl_stmt|;
comment|/* thread id */
name|socket_t
name|ctx_sd
decl_stmt|;
comment|/* socket descriptor */
name|int
name|ctx_dbg
decl_stmt|;
comment|/* debug level */
name|time_t
name|ctx_timeout
decl_stmt|;
comment|/* timeout */
name|int
name|ctx_state
decl_stmt|;
comment|/* state */
name|smfiDesc_ptr
name|ctx_smfi
decl_stmt|;
comment|/* filter description */
name|u_long
name|ctx_pflags
decl_stmt|;
comment|/* protocol flags */
name|char
modifier|*
modifier|*
name|ctx_mac_ptr
index|[
name|MAX_MACROS_ENTRIES
index|]
decl_stmt|;
name|char
modifier|*
name|ctx_mac_buf
index|[
name|MAX_MACROS_ENTRIES
index|]
decl_stmt|;
name|char
modifier|*
name|ctx_reply
decl_stmt|;
comment|/* reply code */
name|void
modifier|*
name|ctx_privdata
decl_stmt|;
comment|/* private data */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBMILTER_MILTER_H */
end_comment

end_unit

