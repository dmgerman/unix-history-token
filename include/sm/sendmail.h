begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  */
end_comment

begin_comment
comment|/* **  SENDMAIL.H -- MTA-specific definitions for sendmail. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SM_SENDMAIL_H
end_ifndef

begin_define
define|#
directive|define
name|_SM_SENDMAIL_H
value|1
end_define

begin_comment
comment|/* "out of band" indicator */
end_comment

begin_define
define|#
directive|define
name|METAQUOTE
value|((unsigned char)0377)
end_define

begin_comment
comment|/* quotes the next octet */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dequote_internal_chars
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|quote_internal_chars
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|str2prt
name|__P
argument_list|(
operator|(
name|char
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
comment|/* ! _SM_SENDMAIL_H */
end_comment

end_unit

