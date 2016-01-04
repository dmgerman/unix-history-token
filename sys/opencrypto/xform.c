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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<crypto/blowfish/blowfish.h>
end_include

begin_include
include|#
directive|include
file|<crypto/des/des.h>
end_include

begin_include
include|#
directive|include
file|<crypto/rijndael/rijndael.h>
end_include

begin_include
include|#
directive|include
file|<crypto/camellia/camellia.h>
end_include

begin_include
include|#
directive|include
file|<crypto/sha1.h>
end_include

begin_include
include|#
directive|include
file|<opencrypto/cast.h>
end_include

begin_include
include|#
directive|include
file|<opencrypto/deflate.h>
end_include

begin_include
include|#
directive|include
file|<opencrypto/rmd160.h>
end_include

begin_include
include|#
directive|include
file|<opencrypto/skipjack.h>
end_include

begin_include
include|#
directive|include
file|<sys/md5.h>
end_include

begin_include
include|#
directive|include
file|<opencrypto/cryptodev.h>
end_include

begin_include
include|#
directive|include
file|<opencrypto/xform.h>
end_include

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|M_XDATA
argument_list|,
literal|"xform"
argument_list|,
literal|"xform data buffers"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Encryption instances */
end_comment

begin_decl_stmt
name|struct
name|enc_xform
name|enc_xform_arc4
init|=
block|{
name|CRYPTO_ARC4
block|,
literal|"ARC4"
block|,
name|ARC4_BLOCK_LEN
block|,
name|ARC4_IV_LEN
block|,
name|ARC4_MIN_KEY
block|,
name|ARC4_MAX_KEY
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Include the encryption algorithms */
end_comment

begin_include
include|#
directive|include
file|"xform_null.c"
end_include

begin_include
include|#
directive|include
file|"xform_des1.c"
end_include

begin_include
include|#
directive|include
file|"xform_des3.c"
end_include

begin_include
include|#
directive|include
file|"xform_blf.c"
end_include

begin_include
include|#
directive|include
file|"xform_cast5.c"
end_include

begin_include
include|#
directive|include
file|"xform_skipjack.c"
end_include

begin_include
include|#
directive|include
file|"xform_rijndael.c"
end_include

begin_include
include|#
directive|include
file|"xform_aes_icm.c"
end_include

begin_include
include|#
directive|include
file|"xform_aes_xts.c"
end_include

begin_include
include|#
directive|include
file|"xform_cml.c"
end_include

begin_comment
comment|/* Include the authentication and hashing algorithms */
end_comment

begin_include
include|#
directive|include
file|"xform_gmac.c"
end_include

begin_include
include|#
directive|include
file|"xform_md5.c"
end_include

begin_include
include|#
directive|include
file|"xform_rmd160.c"
end_include

begin_include
include|#
directive|include
file|"xform_sha1.c"
end_include

begin_include
include|#
directive|include
file|"xform_sha2.c"
end_include

begin_comment
comment|/* Include the compression algorithms */
end_comment

begin_include
include|#
directive|include
file|"xform_deflate.c"
end_include

end_unit

