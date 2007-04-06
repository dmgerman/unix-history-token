begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBUUTIL_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBUUTIL_COMMON_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<solaris.h>
end_include

begin_comment
comment|/*  * We don't bind to the internal libc interfaces if this is a  * native build.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NATIVE_BUILD
end_ifndef

begin_include
include|#
directive|include
file|"c_synonyms.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<libuutil.h>
end_include

begin_include
include|#
directive|include
file|<libuutil_impl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBUUTIL_COMMON_H */
end_comment

end_unit

