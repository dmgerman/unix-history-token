begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_crypt.c,v 1.3 2011/12/28 22:07:40 christos Exp $ */
end_comment

begin_comment
comment|/*  * This version is derived from the original implementation of FreeSec  * (release 1.1) by David Burren.  I've reviewed the changes made in  * OpenBSD (as of 2.7) and modified the original code in a similar way  * where applicable.  I've also made it reentrant and made a number of  * other changes.  * - Solar Designer<solar at openwall.com>  */
end_comment

begin_comment
comment|/*  * FreeSec: libcrypt for NetBSD  *  * Copyright (c) 1994 David Burren  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of other contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Owl: Owl/packages/glibc/crypt_freesec.c,v 1.6 2010/02/20 14:45:06 solar Exp $  *	Id: crypt.c,v 1.15 1994/09/13 04:58:49 davidb Exp  *  * This is an original implementation of the DES and the crypt(3) interfaces  * by David Burren<davidb at werj.com.au>.  *  * An excellent reference on the underlying algorithm (and related  * algorithms) is:  *  *	B. Schneier, Applied Cryptography: protocols, algorithms,  *	and source code in C, John Wiley& Sons, 1994.  *  * Note that in that book's description of DES the lookups for the initial,  * pbox, and final permutations are inverted (this has been brought to the  * attention of the author).  A list of errata for this book has been  * posted to the sci.crypt newsgroup by the author and is available for FTP.  *  * ARCHITECTURE ASSUMPTIONS:  *	This code used to have some nasty ones, but these have been removed  *	by now.	 The code requires a 32-bit integer type, though.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: t_crypt.c,v 1.3 2011/12/28 22:07:40 christos Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_struct
specifier|static
specifier|const
struct|struct
block|{
specifier|const
name|char
modifier|*
name|hash
decl_stmt|;
specifier|const
name|char
modifier|*
name|pw
decl_stmt|;
block|}
name|tests
index|[]
init|=
block|{
comment|/* "new"-style */
comment|/*  0 */
block|{
literal|"_J9..CCCCXBrJUJV154M"
block|,
literal|"U*U*U*U*"
block|}
block|,
comment|/*  1 */
block|{
literal|"_J9..CCCCXUhOBTXzaiE"
block|,
literal|"U*U***U"
block|}
block|,
comment|/*  2 */
block|{
literal|"_J9..CCCC4gQ.mB/PffM"
block|,
literal|"U*U***U*"
block|}
block|,
comment|/*  3 */
block|{
literal|"_J9..XXXXvlzQGqpPPdk"
block|,
literal|"*U*U*U*U"
block|}
block|,
comment|/*  4 */
block|{
literal|"_J9..XXXXsqM/YSSP..Y"
block|,
literal|"*U*U*U*U*"
block|}
block|,
comment|/*  5 */
block|{
literal|"_J9..XXXXVL7qJCnku0I"
block|,
literal|"*U*U*U*U*U*U*U*U"
block|}
block|,
comment|/*  6 */
block|{
literal|"_J9..XXXXAj8cFbP5scI"
block|,
literal|"*U*U*U*U*U*U*U*U*"
block|}
block|,
comment|/*  7 */
block|{
literal|"_J9..SDizh.vll5VED9g"
block|,
literal|"ab1234567"
block|}
block|,
comment|/*  8 */
block|{
literal|"_J9..SDizRjWQ/zePPHc"
block|,
literal|"cr1234567"
block|}
block|,
comment|/*  9 */
block|{
literal|"_J9..SDizxmRI1GjnQuE"
block|,
literal|"zxyDPWgydbQjgq"
block|}
block|,
comment|/* 10 */
block|{
literal|"_K9..SaltNrQgIYUAeoY"
block|,
literal|"726 even"
block|}
block|,
comment|/* 11 */
block|{
literal|"_J9..SDSD5YGyRCr4W4c"
block|,
literal|""
block|}
block|,
comment|/* "old"-style, valid salts */
comment|/* 12 */
block|{
literal|"CCNf8Sbh3HDfQ"
block|,
literal|"U*U*U*U*"
block|}
block|,
comment|/* 13 */
block|{
literal|"CCX.K.MFy4Ois"
block|,
literal|"U*U***U"
block|}
block|,
comment|/* 14 */
block|{
literal|"CC4rMpbg9AMZ."
block|,
literal|"U*U***U*"
block|}
block|,
comment|/* 15 */
block|{
literal|"XXxzOu6maQKqQ"
block|,
literal|"*U*U*U*U"
block|}
block|,
comment|/* 16 */
block|{
literal|"SDbsugeBiC58A"
block|,
literal|""
block|}
block|,
comment|/* 17 */
block|{
literal|"./xZjzHv5vzVE"
block|,
literal|"password"
block|}
block|,
comment|/* 18 */
block|{
literal|"0A2hXM1rXbYgo"
block|,
literal|"password"
block|}
block|,
comment|/* 19 */
block|{
literal|"A9RXdR23Y.cY6"
block|,
literal|"password"
block|}
block|,
comment|/* 20 */
block|{
literal|"ZziFATVXHo2.6"
block|,
literal|"password"
block|}
block|,
comment|/* 21 */
block|{
literal|"zZDDIZ0NOlPzw"
block|,
literal|"password"
block|}
block|,
comment|/* "old"-style, "reasonable" invalid salts, UFC-crypt behavior expected */
comment|/* 22 */
block|{
literal|"\001\002wyd0KZo65Jo"
block|,
literal|"password"
block|}
block|,
comment|/* 23 */
block|{
literal|"a_C10Dk/ExaG."
block|,
literal|"password"
block|}
block|,
comment|/* 24 */
block|{
literal|"~\377.5OTsRVjwLo"
block|,
literal|"password"
block|}
block|,
comment|/* The below are erroneous inputs, so NULL return is expected/required */
comment|/* 25 */
block|{
literal|""
block|,
literal|""
block|}
block|,
comment|/* no salt */
comment|/* 26 */
block|{
literal|" "
block|,
literal|""
block|}
block|,
comment|/* setting string is too short */
comment|/* 27 */
block|{
literal|"a:"
block|,
literal|""
block|}
block|,
comment|/* unsafe character */
comment|/* 28 */
block|{
literal|"\na"
block|,
literal|""
block|}
block|,
comment|/* unsafe character */
comment|/* 29 */
block|{
literal|"_/......"
block|,
literal|""
block|}
block|,
comment|/* setting string is too short for its type */
comment|/* 30 */
block|{
literal|"_........"
block|,
literal|""
block|}
block|,
comment|/* zero iteration count */
comment|/* 31 */
block|{
literal|"_/!......"
block|,
literal|""
block|}
block|,
comment|/* invalid character in count */
comment|/* 32 */
block|{
literal|"_/......!"
block|,
literal|""
block|}
block|,
comment|/* invalid character in salt */
comment|/* 33 */
block|{
name|NULL
block|,
name|NULL
block|}
block|}
struct|;
end_struct

begin_expr_stmt
name|ATF_TC
argument_list|(
name|crypt_salts
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|crypt_salts
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"crypt(3) salt consistency checks"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|crypt_salts
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|tests
index|[
name|i
index|]
operator|.
name|hash
condition|;
name|i
operator|++
control|)
block|{
name|char
modifier|*
name|hash
init|=
name|crypt
argument_list|(
name|tests
index|[
name|i
index|]
operator|.
name|pw
argument_list|,
name|tests
index|[
name|i
index|]
operator|.
name|hash
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|hash
condition|)
block|{
name|ATF_CHECK_MSG
argument_list|(
literal|0
argument_list|,
literal|"Test %zu NULL\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|strcmp
argument_list|(
name|hash
argument_list|,
literal|"*0"
argument_list|)
operator|==
literal|0
operator|&&
name|strlen
argument_list|(
name|tests
index|[
name|i
index|]
operator|.
name|hash
argument_list|)
operator|<
literal|13
condition|)
continue|continue;
comment|/* expected failure */
if|if
condition|(
name|strcmp
argument_list|(
name|hash
argument_list|,
name|tests
index|[
name|i
index|]
operator|.
name|hash
argument_list|)
condition|)
name|ATF_CHECK_MSG
argument_list|(
literal|0
argument_list|,
literal|"Test %zu %s != %s\n"
argument_list|,
name|i
argument_list|,
name|hash
argument_list|,
name|tests
index|[
name|i
index|]
operator|.
name|hash
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|ATF_TP_ADD_TCS
argument_list|(
argument|tp
argument_list|)
end_macro

begin_block
block|{
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|crypt_salts
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

