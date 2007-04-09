begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2007 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *  *	$Id: mfdef.h,v 8.38 2007/03/27 18:53:48 ca Exp $  */
end_comment

begin_comment
comment|/* **  mfdef.h -- Global definitions for mail filter and MTA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBMILTER_MFDEF_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBMILTER_MFDEF_H
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SMFI_PROT_VERSION
end_ifndef

begin_define
define|#
directive|define
name|SMFI_PROT_VERSION
value|6
end_define

begin_comment
comment|/* MTA - libmilter protocol version */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMFI_PROT_VERSION */
end_comment

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

begin_define
define|#
directive|define
name|MILTER_MAX_DATA_SIZE
value|65535
end_define

begin_comment
comment|/* default milter command data limit */
end_comment

begin_comment
comment|/* These apply to SMFIF_* flags */
end_comment

begin_define
define|#
directive|define
name|SMFI_V1_ACTS
value|0x0000000FL
end_define

begin_comment
comment|/* The actions of V1 filter */
end_comment

begin_define
define|#
directive|define
name|SMFI_V2_ACTS
value|0x0000003FL
end_define

begin_comment
comment|/* The actions of V2 filter */
end_comment

begin_define
define|#
directive|define
name|SMFI_CURR_ACTS
value|0x000001FFL
end_define

begin_comment
comment|/* actions of current version */
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
name|SMFIC_QUIT_NC
value|'K'
end_define

begin_comment
comment|/* QUIT but new connection follows */
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

begin_define
define|#
directive|define
name|SMFIC_DATA
value|'T'
end_define

begin_comment
comment|/* DATA */
end_comment

begin_define
define|#
directive|define
name|SMFIC_UNKNOWN
value|'U'
end_define

begin_comment
comment|/* Any unknown command */
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
name|SMFIR_ADDRCPT_PAR
value|'2'
end_define

begin_comment
comment|/* add recipient (incl. ESMTP args) */
end_comment

begin_define
define|#
directive|define
name|SMFIR_SHUTDOWN
value|'4'
end_define

begin_comment
comment|/* 421: shutdown (internal to MTA) */
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
name|SMFIR_CHGFROM
value|'e'
end_define

begin_comment
comment|/* change envelope sender (from) */
end_comment

begin_define
define|#
directive|define
name|SMFIR_CONN_FAIL
value|'f'
end_define

begin_comment
comment|/* cause a connection failure */
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
name|SMFIR_INSHEADER
value|'i'
end_define

begin_comment
comment|/* insert header */
end_comment

begin_define
define|#
directive|define
name|SMFIR_SETSYMLIST
value|'l'
end_define

begin_comment
comment|/* set list of symbols (macros) */
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
name|SMFIR_QUARANTINE
value|'q'
end_define

begin_comment
comment|/* quarantine */
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
name|SMFIR_SKIP
value|'s'
end_define

begin_comment
comment|/* skip */
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
name|SMFIP_NR_HDR
value|0x00000080L
end_define

begin_comment
comment|/* No reply for headers */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NOHREPL
value|SMFIP_NR_HDR
end_define

begin_comment
comment|/* No reply for headers */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NOUNKNOWN
value|0x00000100L
end_define

begin_comment
comment|/* MTA should not send unknown commands */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NODATA
value|0x00000200L
end_define

begin_comment
comment|/* MTA should not send DATA */
end_comment

begin_define
define|#
directive|define
name|SMFIP_SKIP
value|0x00000400L
end_define

begin_comment
comment|/* MTA understands SMFIS_SKIP */
end_comment

begin_define
define|#
directive|define
name|SMFIP_RCPT_REJ
value|0x00000800L
end_define

begin_comment
comment|/* MTA should also send rejected RCPTs */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NR_CONN
value|0x00001000L
end_define

begin_comment
comment|/* No reply for connect */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NR_HELO
value|0x00002000L
end_define

begin_comment
comment|/* No reply for HELO */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NR_MAIL
value|0x00004000L
end_define

begin_comment
comment|/* No reply for MAIL */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NR_RCPT
value|0x00008000L
end_define

begin_comment
comment|/* No reply for RCPT */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NR_DATA
value|0x00010000L
end_define

begin_comment
comment|/* No reply for DATA */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NR_UNKN
value|0x00020000L
end_define

begin_comment
comment|/* No reply for UNKN */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NR_EOH
value|0x00040000L
end_define

begin_comment
comment|/* No reply for eoh */
end_comment

begin_define
define|#
directive|define
name|SMFIP_NR_BODY
value|0x00080000L
end_define

begin_comment
comment|/* No reply for body chunk */
end_comment

begin_define
define|#
directive|define
name|SMFIP_HDR_LEADSPC
value|0x00100000L
end_define

begin_comment
comment|/* header value leading space */
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

begin_comment
comment|/* all defined protocol bits */
end_comment

begin_define
define|#
directive|define
name|SMFI_CURR_PROT
value|0x001FFFFFL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBMILTER_MFDEF_H */
end_comment

end_unit

