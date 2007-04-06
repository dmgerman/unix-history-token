begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*	Copyright (c) 1988 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_comment
comment|/*  * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ASSERT_H
end_ifndef

begin_define
define|#
directive|define
name|_ASSERT_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_comment
comment|/* SVr4.0 1.6.1.4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
if|#
directive|if
name|__STDC_VERSION__
operator|-
literal|0
operator|>=
literal|199901L
specifier|extern
name|void
name|__assert_c99
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
else|#
directive|else
specifier|extern
name|void
name|__assert
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* __STDC_VERSION__ - 0>= 199901L */
else|#
directive|else
specifier|extern
name|void
name|_assert
parameter_list|()
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ASSERT_H */
end_comment

begin_comment
comment|/*  * Note that the ANSI C Standard requires all headers to be idempotent except  *<assert.h> which is explicitly required not to be idempotent (section 4.1.2).  * Therefore, it is by intent that the header guards (#ifndef _ASSERT_H) do  * not span this entire file.  */
end_comment

begin_undef
undef|#
directive|undef
name|assert
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|NDEBUG
end_ifdef

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|EX
parameter_list|)
value|((void)0)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|-
literal|0
operator|>=
literal|199901L
end_if

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|EX
parameter_list|)
value|(void)((EX) || \ 	(__assert_c99(#EX, __FILE__, __LINE__, __func__), 0))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|EX
parameter_list|)
value|(void)((EX) || (__assert(#EX, __FILE__, __LINE__), 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC_VERSION__ - 0>= 199901L */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|EX
parameter_list|)
value|(void)((EX) || (_assert("EX", __FILE__, __LINE__), 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NDEBUG */
end_comment

end_unit

