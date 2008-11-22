begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/des/rpc_des.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_comment
comment|/*  @(#)des.h	2.2 88/08/10 4.0 RPCSRC; from 2.7 88/02/08 SMI  */
end_comment

begin_comment
comment|/*  * Sun RPC is a product of Sun Microsystems, Inc. and is provided for  * unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify Sun RPC without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *   * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE  * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR  * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.  *   * Sun RPC is provided with no support and without any obligation on the  * part of Sun Microsystems, Inc. to assist in its use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC  * OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_comment
comment|/*  * Generic DES driver interface  * Keep this file hardware independent!  * Copyright (c) 1986 by Sun Microsystems, Inc.  */
end_comment

begin_define
define|#
directive|define
name|DES_MAXLEN
value|65536
end_define

begin_comment
comment|/* maximum # of bytes to encrypt  */
end_comment

begin_define
define|#
directive|define
name|DES_QUICKLEN
value|16
end_define

begin_comment
comment|/* maximum # of bytes to encrypt quickly */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HEADER_DES_H
end_ifdef

begin_undef
undef|#
directive|undef
name|ENCRYPT
end_undef

begin_undef
undef|#
directive|undef
name|DECRYPT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|desdir
block|{
name|ENCRYPT
block|,
name|DECRYPT
block|}
enum|;
end_enum

begin_enum
enum|enum
name|desmode
block|{
name|CBC
block|,
name|ECB
block|}
enum|;
end_enum

begin_comment
comment|/*  * parameters to ioctl call  */
end_comment

begin_struct
struct|struct
name|desparams
block|{
name|unsigned
name|char
name|des_key
index|[
literal|8
index|]
decl_stmt|;
comment|/* key (with low bit parity) */
name|enum
name|desdir
name|des_dir
decl_stmt|;
comment|/* direction */
name|enum
name|desmode
name|des_mode
decl_stmt|;
comment|/* mode */
name|unsigned
name|char
name|des_ivec
index|[
literal|8
index|]
decl_stmt|;
comment|/* input vector */
name|unsigned
name|des_len
decl_stmt|;
comment|/* number of bytes to crypt */
union|union
block|{
name|unsigned
name|char
name|UDES_data
index|[
name|DES_QUICKLEN
index|]
decl_stmt|;
name|unsigned
name|char
modifier|*
name|UDES_buf
decl_stmt|;
block|}
name|UDES
union|;
define|#
directive|define
name|des_data
value|UDES.UDES_data
comment|/* direct data here if quick */
define|#
directive|define
name|des_buf
value|UDES.UDES_buf
comment|/* otherwise, pointer to data */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Encrypt an arbitrary sized buffer  */
end_comment

begin_define
define|#
directive|define
name|DESIOCBLOCK
value|_IOWR(d, 6, struct desparams)
end_define

begin_comment
comment|/*   * Encrypt of small amount of data, quickly  */
end_comment

begin_define
define|#
directive|define
name|DESIOCQUICK
value|_IOWR(d, 7, struct desparams)
end_define

end_unit

