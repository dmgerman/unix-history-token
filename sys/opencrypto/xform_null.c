begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: xform.c,v 1.16 2001/08/28 12:20:43 ben Exp $	*/
end_comment

begin_comment
comment|/*-  * The authors of this code are John Ioannidis (ji@tla.org),  * Angelos D. Keromytis (kermit@csd.uch.gr),  * Niels Provos (provos@physnet.uni-hamburg.de) and  * Damien Miller (djm@mindrot.org).  *  * This code was written by John Ioannidis for BSD/OS in Athens, Greece,  * in November 1995.  *  * Ported to OpenBSD and NetBSD, with additional transforms, in December 1996,  * by Angelos D. Keromytis.  *  * Additional transforms and features in 1997 and 1998 by Angelos D. Keromytis  * and Niels Provos.  *  * Additional features in 1999 by Angelos D. Keromytis.  *  * AES XTS implementation in 2008 by Damien Miller  *  * Copyright (C) 1995, 1996, 1997, 1998, 1999 by John Ioannidis,  * Angelos D. Keromytis and Niels Provos.  *  * Copyright (C) 2001, Angelos D. Keromytis.  *  * Copyright (C) 2008, Damien Miller  * Copyright (c) 2014 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by John-Mark Gurney  * under sponsorship of the FreeBSD Foundation and  * Rubicon Communications, LLC (Netgate).  *  * Permission to use, copy, and modify this software with or without fee  * is hereby granted, provided that this entire notice is included in  * all copies of any software which is or includes a copy or  * modification of this software.  * You may use this code under the GNU public license if you so wish. Please  * contribute changes back to the authors under this freer than GPL license  * so that we may further the use of strong encryption without limitations to  * all.  *  * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTY. IN PARTICULAR, NONE OF THE AUTHORS MAKES ANY  * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE  * MERCHANTABILITY OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR  * PURPOSE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<opencrypto/xform_auth.h>
end_include

begin_include
include|#
directive|include
file|<opencrypto/xform_enc.h>
end_include

begin_function_decl
specifier|static
name|int
name|null_setkey
parameter_list|(
name|u_int8_t
modifier|*
modifier|*
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|null_encrypt
parameter_list|(
name|caddr_t
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|null_decrypt
parameter_list|(
name|caddr_t
parameter_list|,
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|null_zerokey
parameter_list|(
name|u_int8_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|null_init
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|null_reinit
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|buf
parameter_list|,
name|u_int16_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|null_update
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|null_final
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Encryption instances */
end_comment

begin_decl_stmt
name|struct
name|enc_xform
name|enc_xform_null
init|=
block|{
name|CRYPTO_NULL_CBC
block|,
literal|"NULL"
block|,
comment|/* NB: blocksize of 4 is to generate a properly aligned ESP header */
name|NULL_BLOCK_LEN
block|,
literal|0
block|,
name|NULL_MIN_KEY
block|,
name|NULL_MAX_KEY
block|,
name|null_encrypt
block|,
name|null_decrypt
block|,
name|null_setkey
block|,
name|null_zerokey
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Authentication instances */
end_comment

begin_decl_stmt
name|struct
name|auth_hash
name|auth_hash_null
init|=
block|{
operator|.
name|type
operator|=
name|CRYPTO_NULL_HMAC
block|,
operator|.
name|name
operator|=
literal|"NULL-HMAC"
block|,
operator|.
name|keysize
operator|=
literal|0
block|,
operator|.
name|hashsize
operator|=
name|NULL_HASH_LEN
block|,
operator|.
name|ctxsize
operator|=
sizeof|sizeof
argument_list|(
name|int
argument_list|)
block|,
comment|/* NB: context isn't used */
operator|.
name|blocksize
operator|=
name|NULL_HMAC_BLOCK_LEN
block|,
operator|.
name|Init
operator|=
name|null_init
block|,
operator|.
name|Setkey
operator|=
name|null_reinit
block|,
operator|.
name|Reinit
operator|=
name|null_reinit
block|,
operator|.
name|Update
operator|=
name|null_update
block|,
operator|.
name|Final
operator|=
name|null_final
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Encryption wrapper routines.  */
end_comment

begin_function
specifier|static
name|void
name|null_encrypt
parameter_list|(
name|caddr_t
name|key
parameter_list|,
name|u_int8_t
modifier|*
name|blk
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|void
name|null_decrypt
parameter_list|(
name|caddr_t
name|key
parameter_list|,
name|u_int8_t
modifier|*
name|blk
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|int
name|null_setkey
parameter_list|(
name|u_int8_t
modifier|*
modifier|*
name|sched
parameter_list|,
name|u_int8_t
modifier|*
name|key
parameter_list|,
name|int
name|len
parameter_list|)
block|{
operator|*
name|sched
operator|=
name|NULL
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|null_zerokey
parameter_list|(
name|u_int8_t
modifier|*
modifier|*
name|sched
parameter_list|)
block|{
operator|*
name|sched
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * And now for auth.  */
end_comment

begin_function
specifier|static
name|void
name|null_init
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|void
name|null_reinit
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|buf
parameter_list|,
name|u_int16_t
name|len
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|int
name|null_update
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
name|buf
parameter_list|,
name|u_int16_t
name|len
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|null_final
parameter_list|(
name|u_int8_t
modifier|*
name|buf
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
block|{
if|if
condition|(
name|buf
operator|!=
operator|(
name|u_int8_t
operator|*
operator|)
literal|0
condition|)
name|bzero
argument_list|(
name|buf
argument_list|,
literal|12
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

