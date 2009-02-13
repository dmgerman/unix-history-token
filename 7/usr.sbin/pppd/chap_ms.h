begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * chap.h - Challenge Handshake Authentication Protocol definitions.  *  * Copyright (c) 1995 Eric Rosenquist, Strata Software Limited.  * http://www.strataware.com/  *  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Eric Rosenquist.  The name of the author may not be used to  * endorse or promote products derived from this software without  * specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CHAPMS_INCLUDE__
end_ifndef

begin_define
define|#
directive|define
name|MD4_SIGNATURE_SIZE
value|16
end_define

begin_comment
comment|/* 16 bytes in a MD4 message digest */
end_comment

begin_define
define|#
directive|define
name|MAX_NT_PASSWORD
value|256
end_define

begin_comment
comment|/* Maximum number of (Unicode) chars in an NT password */
end_comment

begin_decl_stmt
name|void
name|ChapMS
name|__P
argument_list|(
operator|(
name|chap_state
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|__CHAPMS_INCLUDE__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CHAPMS_INCLUDE__ */
end_comment

end_unit

