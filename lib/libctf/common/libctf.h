begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2001-2003 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * This header file defines the interfaces available from the CTF debugger  * library, libctf.  This library provides functions that a debugger can  * use to operate on data in the Compact ANSI-C Type Format (CTF).  This  * is NOT a public interface, although it may eventually become one in  * the fullness of time after we gain more experience with the interfaces.  *  * In the meantime, be aware that any program linked with libctf in this  * release of Solaris is almost guaranteed to break in the next release.  *  * In short, do not user this header file or libctf for any purpose.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBCTF_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCTF_H
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
file|<sys/ctf_api.h>
end_include

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
comment|/*  * This flag can be used to enable debug messages.  */
specifier|extern
name|int
name|_libctf_debug
decl_stmt|;
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
comment|/* _LIBCTF_H */
end_comment

end_unit

