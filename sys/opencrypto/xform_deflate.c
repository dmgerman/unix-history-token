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
file|<opencrypto/deflate.h>
end_include

begin_include
include|#
directive|include
file|<opencrypto/xform_comp.h>
end_include

begin_function_decl
specifier|static
name|u_int32_t
name|deflate_compress
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int8_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|u_int32_t
name|deflate_decompress
parameter_list|(
name|u_int8_t
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int8_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compression instance */
end_comment

begin_decl_stmt
name|struct
name|comp_algo
name|comp_algo_deflate
init|=
block|{
name|CRYPTO_DEFLATE_COMP
block|,
literal|"Deflate"
block|,
literal|90
block|,
name|deflate_compress
block|,
name|deflate_decompress
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * And compression  */
end_comment

begin_function
specifier|static
name|u_int32_t
name|deflate_compress
parameter_list|(
name|data
parameter_list|,
name|size
parameter_list|,
name|out
parameter_list|)
name|u_int8_t
modifier|*
name|data
decl_stmt|;
name|u_int32_t
name|size
decl_stmt|;
name|u_int8_t
modifier|*
modifier|*
name|out
decl_stmt|;
block|{
return|return
name|deflate_global
argument_list|(
name|data
argument_list|,
name|size
argument_list|,
literal|0
argument_list|,
name|out
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|u_int32_t
name|deflate_decompress
parameter_list|(
name|data
parameter_list|,
name|size
parameter_list|,
name|out
parameter_list|)
name|u_int8_t
modifier|*
name|data
decl_stmt|;
name|u_int32_t
name|size
decl_stmt|;
name|u_int8_t
modifier|*
modifier|*
name|out
decl_stmt|;
block|{
return|return
name|deflate_global
argument_list|(
name|data
argument_list|,
name|size
argument_list|,
literal|1
argument_list|,
name|out
argument_list|)
return|;
block|}
end_function

end_unit

