begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* adler32.c -- compute the Adler-32 checksum of a data stream  * Copyright (C) 1995-1998 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h   */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|"zlib.h"
end_include

begin_define
define|#
directive|define
name|BASE
value|65521L
end_define

begin_comment
comment|/* largest prime smaller than 65536 */
end_comment

begin_define
define|#
directive|define
name|NMAX
value|5552
end_define

begin_comment
comment|/* NMAX is the largest n such that 255n(n+1)/2 + (n+1)(BASE-1)<= 2^32-1 */
end_comment

begin_define
define|#
directive|define
name|DO1
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|{s1 += buf[i]; s2 += s1;}
end_define

begin_define
define|#
directive|define
name|DO2
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|DO1(buf,i); DO1(buf,i+1);
end_define

begin_define
define|#
directive|define
name|DO4
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|DO2(buf,i); DO2(buf,i+2);
end_define

begin_define
define|#
directive|define
name|DO8
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|DO4(buf,i); DO4(buf,i+4);
end_define

begin_define
define|#
directive|define
name|DO16
parameter_list|(
name|buf
parameter_list|)
value|DO8(buf,0); DO8(buf,8);
end_define

begin_comment
comment|/* ========================================================================= */
end_comment

begin_function
name|uLong
name|ZEXPORT
name|adler32
parameter_list|(
name|adler
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
name|uLong
name|adler
decl_stmt|;
specifier|const
name|Bytef
modifier|*
name|buf
decl_stmt|;
name|uInt
name|len
decl_stmt|;
block|{
name|unsigned
name|long
name|s1
init|=
name|adler
operator|&
literal|0xffff
decl_stmt|;
name|unsigned
name|long
name|s2
init|=
operator|(
name|adler
operator|>>
literal|16
operator|)
operator|&
literal|0xffff
decl_stmt|;
name|int
name|k
decl_stmt|;
if|if
condition|(
name|buf
operator|==
name|Z_NULL
condition|)
return|return
literal|1L
return|;
while|while
condition|(
name|len
operator|>
literal|0
condition|)
block|{
name|k
operator|=
name|len
operator|<
name|NMAX
condition|?
name|len
else|:
name|NMAX
expr_stmt|;
name|len
operator|-=
name|k
expr_stmt|;
while|while
condition|(
name|k
operator|>=
literal|16
condition|)
block|{
name|DO16
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|buf
operator|+=
literal|16
expr_stmt|;
name|k
operator|-=
literal|16
expr_stmt|;
block|}
if|if
condition|(
name|k
operator|!=
literal|0
condition|)
do|do
block|{
name|s1
operator|+=
operator|*
name|buf
operator|++
expr_stmt|;
name|s2
operator|+=
name|s1
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|k
condition|)
do|;
name|s1
operator|%=
name|BASE
expr_stmt|;
name|s2
operator|%=
name|BASE
expr_stmt|;
block|}
return|return
operator|(
name|s2
operator|<<
literal|16
operator|)
operator||
name|s1
return|;
block|}
end_function

end_unit

