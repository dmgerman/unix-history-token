begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* authmd5decrypt.c,v 3.1 1993/07/06 01:07:53 jbj Exp  *  md5crypt - MD5 based authentication routines  */
end_comment

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
file|"md5.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_decl_stmt
specifier|extern
name|U_LONG
name|cache_keyid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cache_key
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cache_keylen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Stat counters, imported from data base module  */
end_comment

begin_decl_stmt
specifier|extern
name|U_LONG
name|authencryptions
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|U_LONG
name|authdecryptions
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|U_LONG
name|authkeyuncached
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|U_LONG
name|authdecryptok
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|U_LONG
name|authnokey
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * For our purposes an NTP packet looks like:  *  *	a variable amount of encrypted data, multiple of 8 bytes, followed by:  *	NOCRYPT_OCTETS worth of unencrypted data, followed by:  *	BLOCK_OCTETS worth of ciphered checksum.  */
end_comment

begin_define
define|#
directive|define
name|NOCRYPT_OCTETS
value|4
end_define

begin_define
define|#
directive|define
name|BLOCK_OCTETS
value|16
end_define

begin_define
define|#
directive|define
name|NOCRYPT_LONGS
value|((NOCRYPT_OCTETS)/sizeof(U_LONG))
end_define

begin_define
define|#
directive|define
name|BLOCK_LONGS
value|((BLOCK_OCTETS)/sizeof(U_LONG))
end_define

begin_function
name|int
name|MD5authdecrypt
parameter_list|(
name|keyno
parameter_list|,
name|pkt
parameter_list|,
name|length
parameter_list|)
name|U_LONG
name|keyno
decl_stmt|;
specifier|const
name|U_LONG
modifier|*
name|pkt
decl_stmt|;
name|int
name|length
decl_stmt|;
comment|/* length of variable data in octets */
block|{
name|MD5_CTX
name|ctx
decl_stmt|;
name|authdecryptions
operator|++
expr_stmt|;
if|if
condition|(
name|keyno
operator|!=
name|cache_keyid
condition|)
block|{
name|authkeyuncached
operator|++
expr_stmt|;
if|if
condition|(
operator|!
name|authhavekey
argument_list|(
name|keyno
argument_list|)
condition|)
return|return
literal|0
return|;
block|}
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
name|cache_key
argument_list|,
name|cache_keylen
argument_list|)
expr_stmt|;
name|MD5Update
argument_list|(
operator|&
name|ctx
argument_list|,
operator|(
name|char
operator|*
operator|)
name|pkt
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|MD5Final
argument_list|(
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
name|ctx
operator|.
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

