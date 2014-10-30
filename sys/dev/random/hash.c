begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000-2013 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<threads.h>
end_include

begin_include
include|#
directive|include
file|"unit_test.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_include
include|#
directive|include
file|<crypto/rijndael/rijndael-api-fst.h>
end_include

begin_include
include|#
directive|include
file|<crypto/sha2/sha2.h>
end_include

begin_include
include|#
directive|include
file|<dev/random/hash.h>
end_include

begin_comment
comment|/* This code presumes that KEYSIZE is twice as large as BLOCKSIZE */
end_comment

begin_expr_stmt
name|CTASSERT
argument_list|(
name|KEYSIZE
operator|==
literal|2
operator|*
name|BLOCKSIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Initialise the hash */
end_comment

begin_function
name|void
name|randomdev_hash_init
parameter_list|(
name|struct
name|randomdev_hash
modifier|*
name|context
parameter_list|)
block|{
name|SHA256_Init
argument_list|(
operator|&
name|context
operator|->
name|sha
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Iterate the hash */
end_comment

begin_function
name|void
name|randomdev_hash_iterate
parameter_list|(
name|struct
name|randomdev_hash
modifier|*
name|context
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|SHA256_Update
argument_list|(
operator|&
name|context
operator|->
name|sha
argument_list|,
name|data
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Conclude by returning the hash in the supplied<*buf> which must be  * KEYSIZE bytes long.  */
end_comment

begin_function
name|void
name|randomdev_hash_finish
parameter_list|(
name|struct
name|randomdev_hash
modifier|*
name|context
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
block|{
name|SHA256_Final
argument_list|(
name|buf
argument_list|,
operator|&
name|context
operator|->
name|sha
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Initialise the encryption routine by setting up the key schedule  * from the supplied<*data> which must be KEYSIZE bytes of binary  * data. Use CBC mode for better avalanche.  */
end_comment

begin_function
name|void
name|randomdev_encrypt_init
parameter_list|(
name|struct
name|randomdev_key
modifier|*
name|context
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|rijndael_cipherInit
argument_list|(
operator|&
name|context
operator|->
name|cipher
argument_list|,
name|MODE_CBC
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|rijndael_makeKey
argument_list|(
operator|&
name|context
operator|->
name|key
argument_list|,
name|DIR_ENCRYPT
argument_list|,
name|KEYSIZE
operator|*
literal|8
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Encrypt the supplied data using the key schedule preset in the context.  *<length> bytes are encrypted from<*d_in> to<*d_out>.<length> must be  * a multiple of BLOCKSIZE.  */
end_comment

begin_function
name|void
name|randomdev_encrypt
parameter_list|(
name|struct
name|randomdev_key
modifier|*
name|context
parameter_list|,
name|void
modifier|*
name|d_in
parameter_list|,
name|void
modifier|*
name|d_out
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|rijndael_blockEncrypt
argument_list|(
operator|&
name|context
operator|->
name|cipher
argument_list|,
operator|&
name|context
operator|->
name|key
argument_list|,
name|d_in
argument_list|,
name|length
operator|*
literal|8
argument_list|,
name|d_out
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

