begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)encrypt.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Copyright (C) 1990 by the Massachusetts Institute of Technology  *  * Export of this software from the United States of America is assumed  * to require a specific license from the United States Government.  * It is the responsibility of any person or organization contemplating  * export to obtain such a license before exporting.  *  * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and  * distribute this software and its documentation for any purpose and  * without fee is hereby granted, provided that the above copyright  * notice appear in all copies and that both that copyright notice and  * this permission notice appear in supporting documentation, and that  * the name of M.I.T. not be used in advertising or publicity pertaining  * to distribution of the software without specific, written prior  * permission.  M.I.T. makes no representations about the suitability of  * this software for any purpose.  It is provided "as is" without express  * or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ENCRYPT__
end_ifndef

begin_define
define|#
directive|define
name|__ENCRYPT__
end_define

begin_define
define|#
directive|define
name|DIR_DECRYPT
value|1
end_define

begin_define
define|#
directive|define
name|DIR_ENCRYPT
value|2
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Block
index|[
literal|8
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
modifier|*
name|BlockT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Block
name|_
decl_stmt|;
block|}
name|Schedule
index|[
literal|16
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VALIDKEY
parameter_list|(
name|key
parameter_list|)
value|( key[0] | key[1] | key[2] | key[3] | \ 			  key[4] | key[5] | key[6] | key[7])
end_define

begin_define
define|#
directive|define
name|SAMEKEY
parameter_list|(
name|k1
parameter_list|,
name|k2
parameter_list|)
value|(!bcmp((void *)k1, (void *)k2, sizeof(Block)))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|type
decl_stmt|;
name|int
name|length
decl_stmt|;
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|Session_Key
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|P
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|type
decl_stmt|;
name|void
argument_list|(
argument|*output
argument_list|)
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*input
argument_list|)
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*init
argument_list|)
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*start
argument_list|)
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*is
argument_list|)
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*reply
argument_list|)
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*session
argument_list|)
name|P
argument_list|(
operator|(
name|Session_Key
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*keyid
argument_list|)
name|P
argument_list|(
operator|(
name|int
operator|,
name|unsigned
name|char
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*printsub
argument_list|)
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|,
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
block|}
name|Encryptions
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SK_DES
value|1
end_define

begin_comment
comment|/* Matched Kerberos v5 KEYTYPE_DES */
end_comment

begin_include
include|#
directive|include
file|"enc-proto.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|encrypt_debug_mode
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern int (*decrypt_input
end_extern

begin_expr_stmt
unit|)
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern void (*encrypt_output
end_extern

begin_expr_stmt
unit|)
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

