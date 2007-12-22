begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2004, 2006 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *  *	$Id: mfapi.h,v 8.77 2006/11/02 02:44:07 ca Exp $  */
end_comment

begin_comment
comment|/* **  MFAPI.H -- Global definitions for mail filter library and mail filters. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBMILTER_MFAPI_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBMILTER_MFAPI_H
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SMFI_VERSION
end_ifndef

begin_define
define|#
directive|define
name|SMFI_VERSION
value|0x01000000
end_define

begin_comment
comment|/* libmilter version number */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SMFI_VERSION */
end_comment

begin_define
define|#
directive|define
name|SM_LM_VRS_MAJOR
parameter_list|(
name|v
parameter_list|)
value|(((v)& 0x7f000000)>> 24)
end_define

begin_define
define|#
directive|define
name|SM_LM_VRS_MINOR
parameter_list|(
name|v
parameter_list|)
value|(((v)& 0x007fff00)>> 8)
end_define

begin_define
define|#
directive|define
name|SM_LM_VRS_PLVL
parameter_list|(
name|v
parameter_list|)
value|((v)& 0x0000007f)
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
file|"libmilter/mfdef.h"
end_include

begin_define
define|#
directive|define
name|LIBMILTER_API
value|extern
end_define

begin_comment
comment|/* Only need to export C interface if used by C++ source code */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
ifndef|#
directive|ifndef
name|_SOCK_ADDR
define|#
directive|define
name|_SOCK_ADDR
value|struct sockaddr
endif|#
directive|endif
comment|/* ! _SOCK_ADDR */
comment|/* **  libmilter functions return one of the following to indicate **  success/failure(/continue): */
define|#
directive|define
name|MI_SUCCESS
value|0
define|#
directive|define
name|MI_FAILURE
value|(-1)
if|#
directive|if
name|_FFR_WORKERS_POOL
define|#
directive|define
name|MI_CONTINUE
value|1
endif|#
directive|endif
comment|/* _FFR_WORKERS_POOL */
comment|/* "forward" declarations */
typedef|typedef
name|struct
name|smfi_str
name|SMFICTX
typedef|;
typedef|typedef
name|struct
name|smfi_str
modifier|*
name|SMFICTX_PTR
typedef|;
typedef|typedef
name|struct
name|smfiDesc
name|smfiDesc_str
typedef|;
typedef|typedef
name|struct
name|smfiDesc
modifier|*
name|smfiDesc_ptr
typedef|;
comment|/* **  Type which callbacks should return to indicate message status. **  This may take on one of the SMFIS_* values listed below. */
typedef|typedef
name|int
name|sfsistat
typedef|;
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|8
define|#
directive|define
name|SM__P
parameter_list|(
name|X
parameter_list|)
value|__PMT(X)
else|#
directive|else
comment|/* __linux__&& __GNUC__&& __cplusplus&& _GNUC_MINOR__>= 8 */
define|#
directive|define
name|SM__P
parameter_list|(
name|X
parameter_list|)
value|__P(X)
endif|#
directive|endif
comment|/* __linux__&& __GNUC__&& __cplusplus&& _GNUC_MINOR__>= 8 */
comment|/* Some platforms don't define __P -- do it for them here: */
ifndef|#
directive|ifndef
name|__P
ifdef|#
directive|ifdef
name|__STDC__
define|#
directive|define
name|__P
parameter_list|(
name|X
parameter_list|)
value|X
else|#
directive|else
comment|/* __STDC__ */
define|#
directive|define
name|__P
parameter_list|(
name|X
parameter_list|)
value|()
endif|#
directive|endif
comment|/* __STDC__ */
endif|#
directive|endif
comment|/* __P */
if|#
directive|if
name|SM_CONF_STDBOOL_H
include|#
directive|include
file|<stdbool.h>
else|#
directive|else
comment|/* SM_CONF_STDBOOL_H */
ifndef|#
directive|ifndef
name|__cplusplus
ifndef|#
directive|ifndef
name|bool
ifndef|#
directive|ifndef
name|__bool_true_false_are_defined
typedef|typedef
name|int
name|bool
typedef|;
define|#
directive|define
name|__bool_true_false_are_defined
value|1
endif|#
directive|endif
comment|/* ! __bool_true_false_are_defined */
endif|#
directive|endif
comment|/* bool */
endif|#
directive|endif
comment|/* ! __cplusplus */
endif|#
directive|endif
comment|/* SM_CONF_STDBOOL_H */
comment|/* **  structure describing one milter */
struct|struct
name|smfiDesc
block|{
name|char
modifier|*
name|xxfi_name
decl_stmt|;
comment|/* filter name */
name|int
name|xxfi_version
decl_stmt|;
comment|/* version code -- do not change */
name|unsigned
name|long
name|xxfi_flags
decl_stmt|;
comment|/* flags */
comment|/* connection info filter */
name|sfsistat
argument_list|(
argument|*xxfi_connect
argument_list|)
name|SM__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|char
operator|*
operator|,
name|_SOCK_ADDR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* SMTP HELO command filter */
name|sfsistat
argument_list|(
argument|*xxfi_helo
argument_list|)
name|SM__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* envelope sender filter */
name|sfsistat
argument_list|(
argument|*xxfi_envfrom
argument_list|)
name|SM__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* envelope recipient filter */
name|sfsistat
argument_list|(
argument|*xxfi_envrcpt
argument_list|)
name|SM__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* header filter */
name|sfsistat
argument_list|(
argument|*xxfi_header
argument_list|)
name|SM__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* end of header */
name|sfsistat
argument_list|(
argument|*xxfi_eoh
argument_list|)
name|SM__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* body block */
name|sfsistat
argument_list|(
argument|*xxfi_body
argument_list|)
name|SM__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
expr_stmt|;
comment|/* end of message */
name|sfsistat
argument_list|(
argument|*xxfi_eom
argument_list|)
name|SM__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* message aborted */
name|sfsistat
argument_list|(
argument|*xxfi_abort
argument_list|)
name|SM__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* connection cleanup */
name|sfsistat
argument_list|(
argument|*xxfi_close
argument_list|)
name|SM__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* any unrecognized or unimplemented command filter */
name|sfsistat
argument_list|(
argument|*xxfi_unknown
argument_list|)
name|SM__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* SMTP DATA command filter */
name|sfsistat
argument_list|(
argument|*xxfi_data
argument_list|)
name|SM__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* negotiation callback */
name|sfsistat
argument_list|(
argument|*xxfi_negotiate
argument_list|)
name|SM__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|unsigned
name|long
operator|,
name|unsigned
name|long
operator|,
name|unsigned
name|long
operator|,
name|unsigned
name|long
operator|,
name|unsigned
name|long
operator|*
operator|,
name|unsigned
name|long
operator|*
operator|,
name|unsigned
name|long
operator|*
operator|,
name|unsigned
name|long
operator|*
operator|)
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
comment|/* signal handler callback, not yet implemented. */
block|int		(*xxfi_signal) SM__P((int));
endif|#
directive|endif
block|}
struct|;
name|LIBMILTER_API
name|int
name|smfi_opensocket
name|__P
argument_list|(
operator|(
name|bool
operator|)
argument_list|)
decl_stmt|;
name|LIBMILTER_API
name|int
name|smfi_register
name|__P
argument_list|(
operator|(
expr|struct
name|smfiDesc
operator|)
argument_list|)
decl_stmt|;
name|LIBMILTER_API
name|int
name|smfi_main
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
name|LIBMILTER_API
name|int
name|smfi_setbacklog
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
name|LIBMILTER_API
name|int
name|smfi_setdbg
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
name|LIBMILTER_API
name|int
name|smfi_settimeout
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
name|LIBMILTER_API
name|int
name|smfi_setconn
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
name|LIBMILTER_API
name|int
name|smfi_stop
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
if|#
directive|if
name|_FFR_MAXDATASIZE
name|LIBMILTER_API
name|size_t
name|smfi_setmaxdatasize
name|__P
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
endif|#
directive|endif
comment|/* _FFR_MAXDATASIZE */
name|LIBMILTER_API
name|int
name|smfi_version
name|__P
argument_list|(
operator|(
name|unsigned
name|int
operator|*
operator|,
name|unsigned
name|int
operator|*
operator|,
name|unsigned
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* **  What the filter might do -- values to be ORed together for **  smfiDesc.xxfi_flags. */
define|#
directive|define
name|SMFIF_NONE
value|0x00000000L
comment|/* no flags */
define|#
directive|define
name|SMFIF_ADDHDRS
value|0x00000001L
comment|/* filter may add headers */
define|#
directive|define
name|SMFIF_CHGBODY
value|0x00000002L
comment|/* filter may replace body */
define|#
directive|define
name|SMFIF_MODBODY
value|SMFIF_CHGBODY
comment|/* backwards compatible */
define|#
directive|define
name|SMFIF_ADDRCPT
value|0x00000004L
comment|/* filter may add recipients */
define|#
directive|define
name|SMFIF_DELRCPT
value|0x00000008L
comment|/* filter may delete recipients */
define|#
directive|define
name|SMFIF_CHGHDRS
value|0x00000010L
comment|/* filter may change/delete headers */
define|#
directive|define
name|SMFIF_QUARANTINE
value|0x00000020L
comment|/* filter may quarantine envelope */
comment|/* filter may change "from" (envelope sender) */
define|#
directive|define
name|SMFIF_CHGFROM
value|0x00000040L
define|#
directive|define
name|SMFIF_ADDRCPT_PAR
value|0x00000080L
comment|/* add recipients incl. args */
comment|/* filter can send set of symbols (macros) that it wants */
define|#
directive|define
name|SMFIF_SETSYMLIST
value|0x00000100L
comment|/* **  Macro "places"; **  Notes: **  - must be coordinated with libmilter/engine.c and sendmail/milter.c **  - the order MUST NOT be changed as it would break compatibility between **	different versions. It's ok to append new entries however **	(hence the list is not sorted by the SMT protocol steps). */
define|#
directive|define
name|SMFIM_FIRST
value|0
comment|/* Do NOT use, internal marker only */
define|#
directive|define
name|SMFIM_CONNECT
value|0
comment|/* connect */
define|#
directive|define
name|SMFIM_HELO
value|1
comment|/* HELO/EHLO */
define|#
directive|define
name|SMFIM_ENVFROM
value|2
comment|/* MAIL From */
define|#
directive|define
name|SMFIM_ENVRCPT
value|3
comment|/* RCPT To */
define|#
directive|define
name|SMFIM_DATA
value|4
comment|/* DATA */
define|#
directive|define
name|SMFIM_EOM
value|5
comment|/* end of message (final dot) */
define|#
directive|define
name|SMFIM_EOH
value|6
comment|/* end of header */
define|#
directive|define
name|SMFIM_LAST
value|6
comment|/* Do NOT use, internal marker only */
comment|/* **  Continue processing message/connection. */
define|#
directive|define
name|SMFIS_CONTINUE
value|0
comment|/* **  Reject the message/connection. **  No further routines will be called for this message **  (or connection, if returned from a connection-oriented routine). */
define|#
directive|define
name|SMFIS_REJECT
value|1
comment|/* **  Accept the message, **  but silently discard the message. **  No further routines will be called for this message. **  This is only meaningful from message-oriented routines. */
define|#
directive|define
name|SMFIS_DISCARD
value|2
comment|/* **  Accept the message/connection. **  No further routines will be called for this message **  (or connection, if returned from a connection-oriented routine; **  in this case, it causes all messages on this connection **  to be accepted without filtering). */
define|#
directive|define
name|SMFIS_ACCEPT
value|3
comment|/* **  Return a temporary failure, i.e., **  the corresponding SMTP command will return a 4xx status code. **  In some cases this may prevent further routines from **  being called on this message or connection, **  although in other cases (e.g., when processing an envelope **  recipient) processing of the message will continue. */
define|#
directive|define
name|SMFIS_TEMPFAIL
value|4
comment|/* **  Do not send a reply to the MTA */
define|#
directive|define
name|SMFIS_NOREPLY
value|7
comment|/* **  Skip over rest of same callbacks, e.g., body. */
define|#
directive|define
name|SMFIS_SKIP
value|8
comment|/* xxfi_negotiate: use all existing protocol options/actions */
define|#
directive|define
name|SMFIS_ALL_OPTS
value|10
if|#
directive|if
literal|0
comment|/* **  Filter Routine Details */
comment|/* connection info filter */
block|extern sfsistat	xxfi_connect __P((SMFICTX *, char *, _SOCK_ADDR *));
comment|/* **  xxfi_connect(ctx, hostname, hostaddr) Invoked on each connection ** **	char *hostname; Host domain name, as determined by a reverse lookup **		on the host address. **	_SOCK_ADDR *hostaddr; Host address, as determined by a getpeername **		call on the SMTP socket. */
comment|/* SMTP HELO command filter */
block|extern sfsistat	xxfi_helo __P((SMFICTX *, char *));
comment|/* **  xxfi_helo(ctx, helohost) Invoked on SMTP HELO/EHLO command ** **	char *helohost; Value passed to HELO/EHLO command, which should be **		the domain name of the sending host (but is, in practice, **		anything the sending host wants to send). */
comment|/* envelope sender filter */
block|extern sfsistat	xxfi_envfrom __P((SMFICTX *, char **));
comment|/* **  xxfi_envfrom(ctx, argv) Invoked on envelope from ** **	char **argv; Null-terminated SMTP command arguments; **		argv[0] is guaranteed to be the sender address. **		Later arguments are the ESMTP arguments. */
comment|/* envelope recipient filter */
block|extern sfsistat	xxfi_envrcpt __P((SMFICTX *, char **));
comment|/* **  xxfi_envrcpt(ctx, argv) Invoked on each envelope recipient ** **	char **argv; Null-terminated SMTP command arguments; **		argv[0] is guaranteed to be the recipient address. **		Later arguments are the ESMTP arguments. */
comment|/* unknown command filter */
block|extern sfsistat	*xxfi_unknown __P((SMFICTX *, const char *));
comment|/* **  xxfi_unknown(ctx, arg) Invoked when SMTP command is not recognized or not **  implemented. **	const char *arg; Null-terminated SMTP command */
comment|/* header filter */
block|extern sfsistat	xxfi_header __P((SMFICTX *, char *, char *));
comment|/* **  xxfi_header(ctx, headerf, headerv) Invoked on each message header. The **  content of the header may have folded white space (that is, multiple **  lines with following white space) included. ** **	char *headerf; Header field name **	char *headerv; Header field value */
comment|/* end of header */
block|extern sfsistat	xxfi_eoh __P((SMFICTX *));
comment|/* **  xxfi_eoh(ctx) Invoked at end of header */
comment|/* body block */
block|extern sfsistat	xxfi_body __P((SMFICTX *, unsigned char *, size_t));
comment|/* **  xxfi_body(ctx, bodyp, bodylen) Invoked for each body chunk. There may **  be multiple body chunks passed to the filter. End-of-lines are **  represented as received from SMTP (normally Carriage-Return/Line-Feed). ** **	unsigned char *bodyp; Pointer to body data **	size_t bodylen; Length of body data */
comment|/* end of message */
block|extern sfsistat	xxfi_eom __P((SMFICTX *));
comment|/* **  xxfi_eom(ctx) Invoked at end of message. This routine can perform **  special operations such as modifying the message header, body, or **  envelope. */
comment|/* message aborted */
block|extern sfsistat	xxfi_abort __P((SMFICTX *));
comment|/* **  xxfi_abort(ctx) Invoked if message is aborted outside of the control of **  the filter, for example, if the SMTP sender issues an RSET command. If **  xxfi_abort is called, xxfi_eom will not be called and vice versa. */
comment|/* connection cleanup */
block|extern sfsistat	xxfi_close __P((SMFICTX *));
comment|/* **  xxfi_close(ctx) Invoked at end of the connection. This is called on **  close even if the previous mail transaction was aborted. */
endif|#
directive|endif
comment|/* 0 */
comment|/* **  Additional information is passed in to the vendor filter routines using **  symbols. Symbols correspond closely to sendmail macros. The symbols **  defined depend on the context. The value of a symbol is accessed using: */
comment|/* Return the value of a symbol. */
name|LIBMILTER_API
name|char
modifier|*
name|smfi_getsymval
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* **  Return the value of a symbol. ** **	SMFICTX *ctx; Opaque context structure **	char *symname; The name of the symbol to access. */
comment|/* **  Vendor filter routines that want to pass additional information back to **  the MTA for use in SMTP replies may call smfi_setreply before returning. */
name|LIBMILTER_API
name|int
name|smfi_setreply
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* **  Alternatively, smfi_setmlreply can be called if a multi-line SMTP reply **  is needed. */
name|LIBMILTER_API
name|int
name|smfi_setmlreply
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
comment|/* **  Set the specific reply code to be used in response to the active **  command. If not specified, a generic reply code is used. ** **	SMFICTX *ctx; Opaque context structure **	char *rcode; The three-digit (RFC 821) SMTP reply code to be **		returned, e.g., ``551''. **	char *xcode; The extended (RFC 2034) reply code, e.g., ``5.7.6''. **	char *message; The text part of the SMTP reply. */
comment|/* **  The xxfi_eom routine is called at the end of a message (essentially, **  after the final DATA dot). This routine can call some special routines **  to modify the envelope, header, or body of the message before the **  message is enqueued. These routines must not be called from any vendor **  routine other than xxfi_eom. */
name|LIBMILTER_API
name|int
name|smfi_addheader
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* **  Add a header to the message. It is not checked for standards **  compliance; the mail filter must ensure that no protocols are violated **  as a result of adding this header. ** **	SMFICTX *ctx; Opaque context structure **	char *headerf; Header field name **	char *headerv; Header field value */
name|LIBMILTER_API
name|int
name|smfi_chgheader
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* **  Change/delete a header in the message.  It is not checked for standards **  compliance; the mail filter must ensure that no protocols are violated **  as a result of adding this header. ** **	SMFICTX *ctx; Opaque context structure **	char *headerf; Header field name **	int index; The Nth occurence of header field name **	char *headerv; New header field value (empty for delete header) */
name|LIBMILTER_API
name|int
name|smfi_insheader
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* **  Insert a header into the message.  It is not checked for standards **  compliance; the mail filter must ensure that no protocols are violated **  as a result of adding this header. ** **	SMFICTX *ctx; Opaque context structure **  	int idx; index into the header list where the insertion should happen **	char *headerh; Header field name **	char *headerv; Header field value */
name|LIBMILTER_API
name|int
name|smfi_chgfrom
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* **  Modify envelope sender address ** **	SMFICTX *ctx; Opaque context structure **	char *mail; New envelope sender address **	char *args; ESMTP arguments */
name|LIBMILTER_API
name|int
name|smfi_addrcpt
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* **  Add a recipient to the envelope ** **	SMFICTX *ctx; Opaque context structure **	char *rcpt; Recipient to be added */
name|LIBMILTER_API
name|int
name|smfi_addrcpt_par
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* **  Add a recipient to the envelope ** **	SMFICTX *ctx; Opaque context structure **	char *rcpt; Recipient to be added **	char *args; ESMTP arguments */
name|LIBMILTER_API
name|int
name|smfi_delrcpt
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* **  Send a "no-op" up to the MTA to tell it we're still alive, so long **  milter-side operations don't time out. ** **	SMFICTX *ctx; Opaque context structure */
name|LIBMILTER_API
name|int
name|smfi_progress
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* **  Delete a recipient from the envelope ** **	SMFICTX *ctx; Opaque context structure **	char *rcpt; Envelope recipient to be deleted. This should be in **		exactly the form passed to xxfi_envrcpt or the address may **		not be deleted. */
name|LIBMILTER_API
name|int
name|smfi_replacebody
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* **  Replace the body of the message. This routine may be called multiple **  times if the body is longer than convenient to send in one call. End of **  line should be represented as Carriage-Return/Line Feed. ** **	char *bodyp; Pointer to block of body information to insert **	int bodylen; Length of data pointed at by bodyp */
comment|/* **  If the message is aborted (for example, if the SMTP sender sends the **  envelope but then does a QUIT or RSET before the data is sent), **  xxfi_abort is called. This can be used to reset state. */
comment|/* **  Quarantine an envelope ** **	SMFICTX *ctx; Opaque context structure **	char *reason: explanation */
name|LIBMILTER_API
name|int
name|smfi_quarantine
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
name|ctx
operator|,
name|char
operator|*
name|reason
operator|)
argument_list|)
decl_stmt|;
comment|/* **  Connection-private data (specific to an SMTP connection) can be **  allocated using the smfi_setpriv routine; routines can access private **  data using smfi_getpriv. */
name|LIBMILTER_API
name|int
name|smfi_setpriv
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* **  Set the private data pointer ** **	SMFICTX *ctx; Opaque context structure **	void *privatedata; Pointer to private data area */
name|LIBMILTER_API
name|void
modifier|*
name|smfi_getpriv
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* **  Get the private data pointer ** **	SMFICTX *ctx; Opaque context structure **	void *privatedata; Pointer to private data area */
name|LIBMILTER_API
name|int
name|smfi_setsymlist
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
comment|/* **  Set list of symbols (macros) to receive ** **	SMFICTX *ctx; Opaque context structure **	int where; where in the SMTP dialogue should the macros be sent **	char *macros; list of macros (space separated) */
if|#
directive|if
name|_FFR_THREAD_MONITOR
name|LIBMILTER_API
name|int
name|smfi_set_max_exec_time
name|__P
argument_list|(
operator|(
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
endif|#
directive|endif
comment|/* _FFR_THREAD_MONITOR */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _LIBMILTER_MFAPI_H */
end_comment

end_unit

