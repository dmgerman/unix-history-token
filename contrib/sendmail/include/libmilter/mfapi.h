begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2000 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *  *	$Id: mfapi.h,v 8.13.4.12 2000/09/09 02:11:48 ca Exp $  */
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

begin_define
define|#
directive|define
name|LIBMILTER_API
value|extern
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_SOCK_ADDR
end_ifndef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_define
define|#
directive|define
name|_SOCK_ADDR
value|struct sockaddr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _SOCK_ADDR */
end_comment

begin_comment
comment|/* **  libmilter functions return one of the following to indicate **  success/failure: */
end_comment

begin_define
define|#
directive|define
name|MI_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|MI_FAILURE
value|(-1)
end_define

begin_comment
comment|/* "forward" declarations */
end_comment

begin_typedef
typedef|typedef
name|struct
name|smfi_str
name|SMFICTX
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|smfi_str
modifier|*
name|SMFICTX_PTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|smfiDesc
name|smfiDesc_str
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|smfiDesc
modifier|*
name|smfiDesc_ptr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SMFI_VERSION
value|2
end_define

begin_comment
comment|/* version number */
end_comment

begin_comment
comment|/* **  What the filter might do -- values to be ORed together for **  smfiDesc.xxfi_flags. */
end_comment

begin_define
define|#
directive|define
name|SMFIF_ADDHDRS
value|0x00000001L
end_define

begin_comment
comment|/* filter may add headers */
end_comment

begin_define
define|#
directive|define
name|SMFIF_CHGBODY
value|0x00000002L
end_define

begin_comment
comment|/* filter may replace body */
end_comment

begin_define
define|#
directive|define
name|SMFIF_MODBODY
value|SMFIF_CHGBODY
end_define

begin_comment
comment|/* backwards compatible */
end_comment

begin_define
define|#
directive|define
name|SMFIF_ADDRCPT
value|0x00000004L
end_define

begin_comment
comment|/* filter may add recipients */
end_comment

begin_define
define|#
directive|define
name|SMFIF_DELRCPT
value|0x00000008L
end_define

begin_comment
comment|/* filter may delete recipients */
end_comment

begin_define
define|#
directive|define
name|SMFIF_CHGHDRS
value|0x00000010L
end_define

begin_comment
comment|/* filter may change/delete headers */
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
value|0x0000001FL
end_define

begin_comment
comment|/* The actions of V2 filter */
end_comment

begin_define
define|#
directive|define
name|SMFI_CURR_ACTS
value|SMFI_V2_ACTS
end_define

begin_comment
comment|/* The current version */
end_comment

begin_comment
comment|/* **  Type which callbacks should return to indicate message status. **  This may take on one of the SMFIS_* values listed below. */
end_comment

begin_typedef
typedef|typedef
name|int
name|sfsistat
typedef|;
end_typedef

begin_comment
comment|/* **  structure describing one milter */
end_comment

begin_if
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
end_if

begin_define
define|#
directive|define
name|SM__P
parameter_list|(
name|X
parameter_list|)
value|__PMT(X)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __linux__&& __GNUC__&& __cplusplus&& _GNUC_MINOR__>= 8 */
end_comment

begin_define
define|#
directive|define
name|SM__P
parameter_list|(
name|X
parameter_list|)
value|__P(X)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__&& __GNUC__&& __cplusplus&& _GNUC_MINOR__>= 8 */
end_comment

begin_comment
comment|/* Some platforms don't define __P -- do it for them here: */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|X
parameter_list|)
value|X
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|X
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __P */
end_comment

begin_struct
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
name|u_long
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
name|u_char
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
block|}
struct|;
end_struct

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/* **  Continue processing message/connection. */
end_comment

begin_define
define|#
directive|define
name|SMFIS_CONTINUE
value|0
end_define

begin_comment
comment|/* **  Reject the message/connection. **  No further routines will be called for this message **  (or connection, if returned from a connection-oriented routine). */
end_comment

begin_define
define|#
directive|define
name|SMFIS_REJECT
value|1
end_define

begin_comment
comment|/* **  Accept the message, **  but silently discard the message. **  No further routines will be called for this message. **  This is only meaningful from message-oriented routines. */
end_comment

begin_define
define|#
directive|define
name|SMFIS_DISCARD
value|2
end_define

begin_comment
comment|/* **  Accept the message/connection. **  No further routines will be called for this message **  (or connection, if returned from a connection-oriented routine; **  in this case, it causes all messages on this connection **  to be accepted without filtering). */
end_comment

begin_define
define|#
directive|define
name|SMFIS_ACCEPT
value|3
end_define

begin_comment
comment|/* **  Return a temporary failure, i.e., **  the corresponding SMTP command will return a 4xx status code. **  In some cases this may prevent further routines from **  being called on this message or connection, **  although in other cases (e.g., when processing an envelope **  recipient) processing of the message will continue. */
end_comment

begin_define
define|#
directive|define
name|SMFIS_TEMPFAIL
value|4
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* **  Filter Routine Details */
end_comment

begin_comment
comment|/* connection info filter */
end_comment

begin_comment
unit|extern sfsistat	xxfi_connect __P((SMFICTX *, char *, _SOCK_ADDR *));
comment|/* **  xxfi_connect(ctx, hostname, hostaddr) Invoked on each connection ** **	char *hostname; Host domain name, as determined by a reverse lookup **		on the host address. **	_SOCK_ADDR *hostaddr; Host address, as determined by a getpeername **		call on the SMTP socket. */
end_comment

begin_comment
comment|/* SMTP HELO command filter */
end_comment

begin_comment
unit|extern sfsistat	xxfi_helo __P((SMFICTX *, char *));
comment|/* **  xxfi_helo(ctx, helohost) Invoked on SMTP HELO/EHLO command ** **	char *helohost; Value passed to HELO/EHLO command, which should be **		the domain name of the sending host (but is, in practice, **		anything the sending host wants to send). */
end_comment

begin_comment
comment|/* envelope sender filter */
end_comment

begin_comment
unit|extern sfsistat	xxfi_envfrom __P((SMFICTX *, char **));
comment|/* **  xxfi_envfrom(ctx, argv) Invoked on envelope from ** **	char **argv; Null-terminated SMTP command arguments; **		argv[0] is guaranteed to be the sender address. **		Later arguments are the ESMTP arguments. */
end_comment

begin_comment
comment|/* envelope recipient filter */
end_comment

begin_comment
unit|extern sfsistat	xxfi_envrcpt __P((SMFICTX *, char **));
comment|/* **  xxfi_envrcpt(ctx, argv) Invoked on each envelope recipient ** **	char **argv; Null-terminated SMTP command arguments; **		argv[0] is guaranteed to be the recipient address. **		Later arguments are the ESMTP arguments. */
end_comment

begin_comment
comment|/* header filter */
end_comment

begin_comment
unit|extern sfsistat	xxfi_header __P((SMFICTX *, char *, char *));
comment|/* **  xxfi_header(ctx, headerf, headerv) Invoked on each message header. The **  content of the header may have folded white space (that is, multiple **  lines with following white space) included. ** **	char *headerf; Header field name **	char *headerv; Header field value */
end_comment

begin_comment
comment|/* end of header */
end_comment

begin_comment
unit|extern sfsistat	xxfi_eoh __P((SMFICTX *));
comment|/* **  xxfi_eoh(ctx) Invoked at end of header */
end_comment

begin_comment
comment|/* body block */
end_comment

begin_comment
unit|extern sfsistat	xxfi_body __P((SMFICTX *, u_char *, size_t));
comment|/* **  xxfi_body(ctx, bodyp, bodylen) Invoked for each body chunk. There may **  be multiple body chunks passed to the filter. End-of-lines are **  represented as received from SMTP (normally Carriage-Return/Line-Feed). ** **	u_char *bodyp; Pointer to body data **	size_t bodylen; Length of body data */
end_comment

begin_comment
comment|/* end of message */
end_comment

begin_comment
unit|extern sfsistat	xxfi_eom __P((SMFICTX *));
comment|/* **  xxfi_eom(ctx) Invoked at end of message. This routine can perform **  special operations such as modifying the message header, body, or **  envelope. */
end_comment

begin_comment
comment|/* message aborted */
end_comment

begin_comment
unit|extern sfsistat	xxfi_abort __P((SMFICTX *));
comment|/* **  xxfi_abort(ctx) Invoked if message is aborted outside of the control of **  the filter, for example, if the SMTP sender issues an RSET command. If **  xxfi_abort is called, xxfi_eom will not be called and vice versa. */
end_comment

begin_comment
comment|/* connection cleanup */
end_comment

begin_comment
unit|extern sfsistat	xxfi_close __P((SMFICTX *));
comment|/* **  xxfi_close(ctx) Invoked at end of the connection. This is called on **  close even if the previous mail transaction was aborted. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/* **  Additional information is passed in to the vendor filter routines using **  symbols. Symbols correspond closely to sendmail macros. The symbols **  defined depend on the context. The value of a symbol is accessed using: */
end_comment

begin_comment
comment|/* Return the value of a symbol. */
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/* **  Return the value of a symbol. ** **	SMFICTX *ctx; Opaque context structure **	char *symname; The name of the symbol to access. */
end_comment

begin_comment
comment|/* **  Vendor filter routines that want to pass additional information back to **  the MTA for use in SMTP replies may call smfi_setreply before returning. */
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/* **  Set the specific reply code to be used in response to the active **  command. If not specified, a generic reply code is used. ** **	SMFICTX *ctx; Opaque context structure **	char *rcode; The three-digit (RFC 821) SMTP reply code to be **		returned, e.g., ``551''. **	char *xcode; The extended (RFC 2034) reply code, e.g., ``5.7.6''. **	char *message; The text part of the SMTP reply. */
end_comment

begin_comment
comment|/* **  The xxfi_eom routine is called at the end of a message (essentially, **  after the final DATA dot). This routine can call some special routines **  to modify the envelope, header, or body of the message before the **  message is enqueued. These routines must not be called from any vendor **  routine other than xxfi_eom. */
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/* **  Add a header to the message. This header is not passed to other **  filters. It is not checked for standards compliance; the mail filter **  must ensure that no protocols are violated as a result of adding this **  header. ** **	SMFICTX *ctx; Opaque context structure **	char *headerf; Header field name **	char *headerv; Header field value */
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/* **  Change/delete a header in the message.  It is not checked for standards **  compliance; the mail filter must ensure that no protocols are violated **  as a result of adding this header. ** **	SMFICTX *ctx; Opaque context structure **	char *headerf; Header field name **	int index; The Nth occurence of header field name **	char *headerv; New header field value (empty for delete header) */
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/* **  Add a recipient to the envelope ** **	SMFICTX *ctx; Opaque context structure **	char *rcpt; Recipient to be added */
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/* **  Delete a recipient from the envelope ** **	SMFICTX *ctx; Opaque context structure **	char *rcpt; Envelope recipient to be deleted. This should be in **		exactly the form passed to xxfi_envrcpt or the address may **		not be deleted. */
end_comment

begin_decl_stmt
name|LIBMILTER_API
name|int
name|smfi_replacebody
name|__P
argument_list|(
operator|(
name|SMFICTX
operator|*
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  Replace the body of the message. This routine may be called multiple **  times if the body is longer than convenient to send in one call. End of **  line should be represented as Carriage-Return/Line Feed. ** **	char *bodyp; Pointer to block of body information to insert **	int bodylen; Length of data pointed at by bodyp */
end_comment

begin_comment
comment|/* **  If the message is aborted (for example, if the SMTP sender sends the **  envelope but then does a QUIT or RSET before the data is sent), **  xxfi_abort is called. This can be used to reset state. */
end_comment

begin_comment
comment|/* **  Connection-private data (specific to an SMTP connection) can be **  allocated using the smfi_setpriv routine; routines can access private **  data using smfi_getpriv. */
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|/* **  Set the private data pointer ** **	SMFICTX *ctx; Opaque context structure **	void *privatedata; Pointer to private data area */
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBMILTER_MFAPI_H */
end_comment

end_unit

