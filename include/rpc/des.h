begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
name|u_char
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
name|u_char
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
name|u_char
name|UDES_data
index|[
name|DES_QUICKLEN
index|]
decl_stmt|;
name|u_char
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

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_comment
comment|/*  * These ioctls are only implemented in SunOS. Maybe someday  * if somebody writes a driver for DES hardware that works  * with FreeBSD, we can being that back.  */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Software DES.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_des_crypt
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
expr|struct
name|desparams
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

