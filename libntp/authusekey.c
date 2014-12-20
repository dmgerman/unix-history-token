begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * authusekey - decode a key from ascii and use it  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
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
file|"ntp_stdlib.h"
end_include

begin_comment
comment|/*  * Types of ascii representations for keys.  "Standard" means a 64 bit  * hex number in NBS format, i.e. with the low order bit of each byte  * a parity bit.  "NTP" means a 64 bit key in NTP format, with the  * high order bit of each byte a parity bit.  "Ascii" means a 1-to-8  * character string whose ascii representation is used as the key.  */
end_comment

begin_function
name|int
name|authusekey
parameter_list|(
name|keyid_t
name|keyno
parameter_list|,
name|int
name|keytype
parameter_list|,
specifier|const
name|u_char
modifier|*
name|str
parameter_list|)
block|{
name|int
name|len
decl_stmt|;
name|len
operator|=
name|strlen
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
name|str
argument_list|)
expr_stmt|;
if|if
condition|(
literal|0
operator|==
name|len
condition|)
return|return
literal|0
return|;
name|MD5auth_setkey
argument_list|(
name|keyno
argument_list|,
name|keytype
argument_list|,
name|str
argument_list|,
name|len
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

end_unit

