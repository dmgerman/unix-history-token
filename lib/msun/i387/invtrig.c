begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2008 David Schultz<das@FreeBSD.ORG>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<stdint.h>
end_include

begin_define
define|#
directive|define
name|STRUCT_DECLS
end_define

begin_include
include|#
directive|include
file|"invtrig.h"
end_include

begin_comment
comment|/*  * asinl() and acosl()  */
end_comment

begin_decl_stmt
specifier|const
name|LONGDOUBLE
name|pS0
init|=
block|{
literal|0xaaaaaaaaaaaaaaa8ULL
block|,
literal|0x3ffcU
block|}
decl_stmt|,
comment|/*  1.66666666666666666631e-01L */
name|pS1
init|=
block|{
literal|0xd5271b6699b48bfaULL
block|,
literal|0xbffdU
block|}
decl_stmt|,
comment|/* -4.16313987993683104320e-01L */
name|pS2
init|=
block|{
literal|0xbcf67ca9e9f669cfULL
block|,
literal|0x3ffdU
block|}
decl_stmt|,
comment|/*  3.69068046323246813704e-01L */
name|pS3
init|=
block|{
literal|0x8b7baa3d15f9830dULL
block|,
literal|0xbffcU
block|}
decl_stmt|,
comment|/* -1.36213932016738603108e-01L */
name|pS4
init|=
block|{
literal|0x92154b093a3bff1cULL
block|,
literal|0x3ff9U
block|}
decl_stmt|,
comment|/*  1.78324189708471965733e-02L */
name|pS5
init|=
block|{
literal|0xe5dd76401964508cULL
block|,
literal|0xbff2U
block|}
decl_stmt|,
comment|/* -2.19216428382605211588e-04L */
name|pS6
init|=
block|{
literal|0xee69c5b0fdb76951ULL
block|,
literal|0xbfedU
block|}
decl_stmt|,
comment|/* -7.10526623669075243183e-06L */
name|qS1
init|=
block|{
literal|0xbcaa2159c01436a0ULL
block|,
literal|0xc000U
block|}
decl_stmt|,
comment|/* -2.94788392796209867269e+00L */
name|qS2
init|=
block|{
literal|0xd17a73d1e1564c29ULL
block|,
literal|0x4000U
block|}
decl_stmt|,
comment|/*  3.27309890266528636716e+00L */
name|qS3
init|=
block|{
literal|0xd767e411c9cf4c2cULL
block|,
literal|0xbfffU
block|}
decl_stmt|,
comment|/* -1.68285799854822427013e+00L */
name|qS4
init|=
block|{
literal|0xc809c0dfb9b0d0b7ULL
block|,
literal|0x3ffdU
block|}
decl_stmt|,
comment|/*  3.90699412641738801874e-01L */
name|qS5
init|=
block|{
literal|0x80c3a2197c8ced57ULL
block|,
literal|0xbffaU
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -3.14365703596053263322e-02L */
end_comment

begin_comment
comment|/*  * atanl()  */
end_comment

begin_decl_stmt
specifier|const
name|LONGDOUBLE
name|atanhi
index|[]
init|=
block|{
block|{
literal|0xed63382b0dda7b45ULL
block|,
literal|0x3ffdU
block|}
block|,
comment|/*  4.63647609000806116202e-01L */
block|{
literal|0xc90fdaa22168c235ULL
block|,
literal|0x3ffeU
block|}
block|,
comment|/*  7.85398163397448309628e-01L */
block|{
literal|0xfb985e940fb4d900ULL
block|,
literal|0x3ffeU
block|}
block|,
comment|/*  9.82793723247329067960e-01L */
block|{
literal|0xc90fdaa22168c235ULL
block|,
literal|0x3fffU
block|}
block|,
comment|/*  1.57079632679489661926e+00L */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|LONGDOUBLE
name|atanlo
index|[]
init|=
block|{
block|{
literal|0xdfc88bd978751a07ULL
block|,
literal|0x3fbcU
block|}
block|,
comment|/*  1.18469937025062860669e-20L */
block|{
literal|0xece675d1fc8f8cbbULL
block|,
literal|0xbfbcU
block|}
block|,
comment|/* -1.25413940316708300586e-20L */
block|{
literal|0xf10f5e197793c283ULL
block|,
literal|0x3fbdU
block|}
block|,
comment|/*  2.55232234165405176172e-20L */
block|{
literal|0xece675d1fc8f8cbbULL
block|,
literal|0xbfbdU
block|}
block|,
comment|/* -2.50827880633416601173e-20L */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|LONGDOUBLE
name|aT
index|[]
init|=
block|{
block|{
literal|0xaaaaaaaaaaaaaa9fULL
block|,
literal|0x3ffdU
block|}
block|,
comment|/*  3.33333333333333333017e-01L */
block|{
literal|0xcccccccccccc62bcULL
block|,
literal|0xbffcU
block|}
block|,
comment|/* -1.99999999999999632011e-01L */
block|{
literal|0x9249249248b81e3fULL
block|,
literal|0x3ffcU
block|}
block|,
comment|/*  1.42857142857046531280e-01L */
block|{
literal|0xe38e38e3316f3de5ULL
block|,
literal|0xbffbU
block|}
block|,
comment|/* -1.11111111100562372733e-01L */
block|{
literal|0xba2e8b8dc280726aULL
block|,
literal|0x3ffbU
block|}
block|,
comment|/*  9.09090902935647302252e-02L */
block|{
literal|0x9d89d5b4c6847ec4ULL
block|,
literal|0xbffbU
block|}
block|,
comment|/* -7.69230552476207730353e-02L */
block|{
literal|0x8888461d3099c677ULL
block|,
literal|0x3ffbU
block|}
block|,
comment|/*  6.66661718042406260546e-02L */
block|{
literal|0xf0e8ee0f5328dc29ULL
block|,
literal|0xbffaU
block|}
block|,
comment|/* -5.88158892835030888692e-02L */
block|{
literal|0xd73ea84d24bae54aULL
block|,
literal|0x3ffaU
block|}
block|,
comment|/*  5.25499891539726639379e-02L */
block|{
literal|0xc08fa381dcd9213aULL
block|,
literal|0xbffaU
block|}
block|,
comment|/* -4.70119845393155721494e-02L */
block|{
literal|0xa54a26f4095f2a3aULL
block|,
literal|0x3ffaU
block|}
block|,
comment|/*  4.03539201366454414072e-02L */
block|{
literal|0xeea2d8d059ef3ad6ULL
block|,
literal|0xbff9U
block|}
block|,
comment|/* -2.91303858419364158725e-02L */
block|{
literal|0xcc82292ab894b051ULL
block|,
literal|0x3ff8U
block|}
block|,
comment|/*  1.24822046299269234080e-02L */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|LONGDOUBLE
name|pi_lo
init|=
block|{
literal|0xece675d1fc8f8cbbULL
block|,
literal|0xbfbeU
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -5.01655761266833202345e-20L */
end_comment

end_unit

