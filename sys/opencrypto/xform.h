begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: xform.h,v 1.8 2001/08/28 12:20:43 ben Exp $	*/
end_comment

begin_comment
comment|/*-  * The author of this code is Angelos D. Keromytis (angelos@cis.upenn.edu)  *  * This code was written by Angelos D. Keromytis in Athens, Greece, in  * February 2000. Network Security Technologies Inc. (NSTI) kindly  * supported the development of this code.  *  * Copyright (c) 2000 Angelos D. Keromytis  * Copyright (c) 2014 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by John-Mark Gurney  * under sponsorship of the FreeBSD Foundation and  * Rubicon Communications, LLC (Netgate).  *  * Permission to use, copy, and modify this software without fee  * is hereby granted, provided that this entire notice is included in  * all source code copies of any software which is or includes a copy or  * modification of this software.   *  * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTY. IN PARTICULAR, NONE OF THE AUTHORS MAKES ANY  * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE  * MERCHANTABILITY OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR  * PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CRYPTO_XFORM_H_
end_ifndef

begin_define
define|#
directive|define
name|_CRYPTO_XFORM_H_
end_define

begin_include
include|#
directive|include
file|<sys/md5.h>
end_include

begin_include
include|#
directive|include
file|<crypto/sha1.h>
end_include

begin_include
include|#
directive|include
file|<crypto/sha2/sha256.h>
end_include

begin_include
include|#
directive|include
file|<crypto/sha2/sha384.h>
end_include

begin_include
include|#
directive|include
file|<crypto/sha2/sha512.h>
end_include

begin_include
include|#
directive|include
file|<opencrypto/rmd160.h>
end_include

begin_include
include|#
directive|include
file|<opencrypto/gmac.h>
end_include

begin_include
include|#
directive|include
file|<opencrypto/xform_auth.h>
end_include

begin_include
include|#
directive|include
file|<opencrypto/xform_comp.h>
end_include

begin_include
include|#
directive|include
file|<opencrypto/xform_enc.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_XDATA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CRYPTO_XFORM_H_ */
end_comment

end_unit

