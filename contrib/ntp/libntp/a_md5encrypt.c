begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	MD5 interface for rsaref2.0  *  * These routines implement an interface for the RSA Laboratories  * implementation of the Message Digest 5 (MD5) algorithm. This  * algorithm is included in the rsaref2.0 package available from RSA in  * the US and foreign countries. Further information is available at  * www.rsa.com.  */
end_comment

begin_include
include|#
directive|include
file|"ntp_machine.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_include
include|#
directive|include
file|"ntp_string.h"
end_include

begin_include
include|#
directive|include
file|"global.h"
end_include

begin_include
include|#
directive|include
file|"md5.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_define
define|#
directive|define
name|BLOCK_OCTETS
value|16
end_define

begin_comment
comment|/* message digest size */
end_comment

begin_comment
comment|/*  * MD5authencrypt - generate MD5 message authenticator  *  * Returns length of authenticator field.  */
end_comment

begin_function
name|int
name|MD5authencrypt
parameter_list|(
name|u_char
modifier|*
name|key
parameter_list|,
comment|/* key pointer */
name|u_int32
modifier|*
name|pkt
parameter_list|,
comment|/* packet pointer */
name|int
name|length
comment|/* packet length */
parameter_list|)
block|{
name|MD5_CTX
name|ctx
decl_stmt|;
name|u_char
name|digest
index|[
name|BLOCK_OCTETS
index|]
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|/* 	 * MD5 with key identifier concatenated with packet. 	 */
name|MD5Init
argument_list|(
operator|&
name|ctx
argument_list|)
expr_stmt|;
name|MD5Update
argument_list|(
operator|&
name|ctx
argument_list|,
name|key
argument_list|,
operator|(
name|u_int
operator|)
name|cache_keylen
argument_list|)
expr_stmt|;
name|MD5Update
argument_list|(
operator|&
name|ctx
argument_list|,
operator|(
name|u_char
operator|*
operator|)
name|pkt
argument_list|,
operator|(
name|u_int
operator|)
name|length
argument_list|)
expr_stmt|;
name|MD5Final
argument_list|(
name|digest
argument_list|,
operator|&
name|ctx
argument_list|)
expr_stmt|;
name|i
operator|=
name|length
operator|/
literal|4
expr_stmt|;
name|memmove
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|pkt
index|[
name|i
operator|+
literal|1
index|]
argument_list|,
operator|(
name|char
operator|*
operator|)
name|digest
argument_list|,
name|BLOCK_OCTETS
argument_list|)
expr_stmt|;
return|return
operator|(
name|BLOCK_OCTETS
operator|+
literal|4
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * MD5authdecrypt - verify MD5 message authenticator  *  * Returns one if authenticator valid, zero if invalid.  */
end_comment

begin_function
name|int
name|MD5authdecrypt
parameter_list|(
name|u_char
modifier|*
name|key
parameter_list|,
comment|/* key pointer */
name|u_int32
modifier|*
name|pkt
parameter_list|,
comment|/* packet pointer */
name|int
name|length
parameter_list|,
comment|/* packet length */
name|int
name|size
comment|/* MAC size */
parameter_list|)
block|{
name|MD5_CTX
name|ctx
decl_stmt|;
name|u_char
name|digest
index|[
name|BLOCK_OCTETS
index|]
decl_stmt|;
comment|/* 	 * MD5 with key identifier concatenated with packet. 	 */
if|if
condition|(
name|size
operator|!=
name|BLOCK_OCTETS
operator|+
literal|4
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|MD5Init
argument_list|(
operator|&
name|ctx
argument_list|)
expr_stmt|;
name|MD5Update
argument_list|(
operator|&
name|ctx
argument_list|,
name|key
argument_list|,
operator|(
name|u_int
operator|)
name|cache_keylen
argument_list|)
expr_stmt|;
name|MD5Update
argument_list|(
operator|&
name|ctx
argument_list|,
operator|(
name|u_char
operator|*
operator|)
name|pkt
argument_list|,
operator|(
name|u_int
operator|)
name|length
argument_list|)
expr_stmt|;
name|MD5Final
argument_list|(
name|digest
argument_list|,
operator|&
name|ctx
argument_list|)
expr_stmt|;
return|return
operator|(
operator|!
name|memcmp
argument_list|(
operator|(
name|char
operator|*
operator|)
name|digest
argument_list|,
operator|(
name|char
operator|*
operator|)
name|pkt
operator|+
name|length
operator|+
literal|4
argument_list|,
name|BLOCK_OCTETS
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

