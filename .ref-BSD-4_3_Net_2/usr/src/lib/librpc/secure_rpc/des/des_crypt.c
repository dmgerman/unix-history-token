begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)des_crypt.c	2.2 88/08/10 4.0 RPCSRC; from 1.13 88/02/08 SMI"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_comment
comment|/*  * des_crypt.c, DES encryption library routines  * Copyright (C) 1986, Sun Microsystems, Inc.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<des_crypt.h>
end_include

begin_include
include|#
directive|include
file|<sys/des.h>
end_include

begin_comment
comment|/*  * To see if chip is installed   */
end_comment

begin_define
define|#
directive|define
name|UNOPENED
value|(-2)
end_define

begin_decl_stmt
specifier|static
name|int
name|g_desfd
init|=
name|UNOPENED
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Copy 8 bytes  */
end_comment

begin_define
define|#
directive|define
name|COPY8
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|{ \ 	register char *a = (char *) dst; \ 	register char *b = (char *) src; \ 	*a++ = *b++; *a++ = *b++; *a++ = *b++; *a++ = *b++; \ 	*a++ = *b++; *a++ = *b++; *a++ = *b++; *a++ = *b++; \ }
end_define

begin_comment
comment|/*  * Copy multiple of 8 bytes  */
end_comment

begin_define
define|#
directive|define
name|DESCOPY
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|len
parameter_list|)
value|{ \ 	register char *a = (char *) dst; \ 	register char *b = (char *) src; \ 	register int i; \ 	for (i = (int) len; i> 0; i -= 8) { \ 		*a++ = *b++; *a++ = *b++; *a++ = *b++; *a++ = *b++; \ 		*a++ = *b++; *a++ = *b++; *a++ = *b++; *a++ = *b++; \ 	} \ }
end_define

begin_comment
comment|/*  * CBC mode encryption  */
end_comment

begin_macro
name|cbc_crypt
argument_list|(
argument|key
argument_list|,
argument|buf
argument_list|,
argument|len
argument_list|,
argument|mode
argument_list|,
argument|ivec
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|key
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ivec
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|err
decl_stmt|;
name|struct
name|desparams
name|dp
decl_stmt|;
name|dp
operator|.
name|des_mode
operator|=
name|CBC
expr_stmt|;
name|COPY8
argument_list|(
name|ivec
argument_list|,
name|dp
operator|.
name|des_ivec
argument_list|)
expr_stmt|;
name|err
operator|=
name|common_crypt
argument_list|(
name|key
argument_list|,
name|buf
argument_list|,
name|len
argument_list|,
name|mode
argument_list|,
operator|&
name|dp
argument_list|)
expr_stmt|;
name|COPY8
argument_list|(
name|dp
operator|.
name|des_ivec
argument_list|,
name|ivec
argument_list|)
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * ECB mode encryption  */
end_comment

begin_macro
name|ecb_crypt
argument_list|(
argument|key
argument_list|,
argument|buf
argument_list|,
argument|len
argument_list|,
argument|mode
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|key
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|mode
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|desparams
name|dp
decl_stmt|;
name|dp
operator|.
name|des_mode
operator|=
name|ECB
expr_stmt|;
return|return
operator|(
name|common_crypt
argument_list|(
name|key
argument_list|,
name|buf
argument_list|,
name|len
argument_list|,
name|mode
argument_list|,
operator|&
name|dp
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Common code to cbc_crypt()& ecb_crypt()  */
end_comment

begin_expr_stmt
specifier|static
name|common_crypt
argument_list|(
argument|key
argument_list|,
argument|buf
argument_list|,
argument|len
argument_list|,
argument|mode
argument_list|,
argument|desp
argument_list|)
name|char
operator|*
name|key
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|unsigned
name|len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|struct
name|desparams
modifier|*
name|desp
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|desdev
decl_stmt|;
specifier|register
name|int
name|res
decl_stmt|;
if|if
condition|(
operator|(
name|len
operator|%
literal|8
operator|)
operator|!=
literal|0
operator|||
name|len
operator|>
name|DES_MAXDATA
condition|)
block|{
return|return
operator|(
name|DESERR_BADPARAM
operator|)
return|;
block|}
name|desp
operator|->
name|des_dir
operator|=
operator|(
operator|(
name|mode
operator|&
name|DES_DIRMASK
operator|)
operator|==
name|DES_ENCRYPT
operator|)
condition|?
name|ENCRYPT
else|:
name|DECRYPT
expr_stmt|;
name|desdev
operator|=
name|mode
operator|&
name|DES_DEVMASK
expr_stmt|;
name|COPY8
argument_list|(
name|key
argument_list|,
name|desp
operator|->
name|des_key
argument_list|)
expr_stmt|;
comment|/*  	 * software 	 */
if|if
condition|(
operator|!
name|_des_crypt
argument_list|(
name|buf
argument_list|,
name|len
argument_list|,
name|desp
argument_list|)
condition|)
block|{
return|return
operator|(
name|DESERR_HWERROR
operator|)
return|;
block|}
return|return
operator|(
name|desdev
operator|==
name|DES_SW
condition|?
name|DESERR_NONE
else|:
name|DESERR_NOHWDEVICE
operator|)
return|;
block|}
end_block

end_unit

