begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CCOMPILE_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CCOMPILE_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_comment
comment|/*  * This file contains definitions designed to enable different compilers  * to be used harmoniously on Solaris systems.  */
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
comment|/*  * Allow for version tests for compiler bugs and features.  */
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
define|#
directive|define
name|__GNUC_VERSION
define|\
value|(__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
else|#
directive|else
define|#
directive|define
name|__GNUC_VERSION
value|0
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__ATTRIBUTE_IMPLEMENTED
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
comment|/*  * analogous to lint's PRINTFLIKEn  */
define|#
directive|define
name|__sun_attr___PRINTFLIKE__
parameter_list|(
name|__n
parameter_list|)
define|\
value|__attribute__((__format__(printf, __n, (__n)+1)))
define|#
directive|define
name|__sun_attr___VPRINTFLIKE__
parameter_list|(
name|__n
parameter_list|)
define|\
value|__attribute__((__format__(printf, __n, 0)))
comment|/*  * Handle the kernel printf routines that can take '%b' too  */
if|#
directive|if
name|__GNUC_VERSION
operator|<
literal|30402
comment|/*  * XX64 at least this doesn't work correctly yet with 3.4.1 anyway!  */
define|#
directive|define
name|__sun_attr___KPRINTFLIKE__
value|__sun_attr___PRINTFLIKE__
define|#
directive|define
name|__sun_attr___KVPRINTFLIKE__
value|__sun_attr___VPRINTFLIKE__
else|#
directive|else
define|#
directive|define
name|__sun_attr___KPRINTFLIKE__
parameter_list|(
name|__n
parameter_list|)
define|\
value|__attribute__((__format__(cmn_err, __n, (__n)+1)))
define|#
directive|define
name|__sun_attr___KVPRINTFLIKE__
parameter_list|(
name|__n
parameter_list|)
define|\
value|__attribute__((__format__(cmn_err, __n, 0)))
endif|#
directive|endif
comment|/*  * This one's pretty obvious -- the function never returns  */
define|#
directive|define
name|__sun_attr___noreturn__
value|__attribute__((__noreturn__))
comment|/*  * This is an appropriate label for functions that do not  * modify their arguments, e.g. strlen()  */
define|#
directive|define
name|__sun_attr___pure__
value|__attribute__((__pure__))
comment|/*  * This is a stronger form of __pure__. Can be used for functions  * that do not modify their arguments and don't depend on global  * memory.  */
define|#
directive|define
name|__sun_attr___const__
value|__attribute__((__const__))
comment|/*  * structure packing like #pragma pack(1)  */
define|#
directive|define
name|__sun_attr___packed__
value|__attribute__((__packed__))
define|#
directive|define
name|___sun_attr_inner
parameter_list|(
name|__a
parameter_list|)
value|__sun_attr_##__a
define|#
directive|define
name|__sun_attr__
parameter_list|(
name|__a
parameter_list|)
value|___sun_attr_inner __a
else|#
directive|else
comment|/* __ATTRIBUTE_IMPLEMENTED || __GNUC__ */
define|#
directive|define
name|__sun_attr__
parameter_list|(
name|__a
parameter_list|)
endif|#
directive|endif
comment|/* __ATTRIBUTE_IMPLEMENTED || __GNUC__ */
comment|/*  * Shorthand versions for readability  */
define|#
directive|define
name|__PRINTFLIKE
parameter_list|(
name|__n
parameter_list|)
value|__sun_attr__((__PRINTFLIKE__(__n)))
define|#
directive|define
name|__VPRINTFLIKE
parameter_list|(
name|__n
parameter_list|)
value|__sun_attr__((__VPRINTFLIKE__(__n)))
define|#
directive|define
name|__KPRINTFLIKE
parameter_list|(
name|__n
parameter_list|)
value|__sun_attr__((__KPRINTFLIKE__(__n)))
define|#
directive|define
name|__KVPRINTFLIKE
parameter_list|(
name|__n
parameter_list|)
value|__sun_attr__((__KVPRINTFLIKE__(__n)))
define|#
directive|define
name|__NORETURN
value|__sun_attr__((__noreturn__))
define|#
directive|define
name|__CONST
value|__sun_attr__((__const__))
define|#
directive|define
name|__PURE
value|__sun_attr__((__pure__))
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
comment|/* _SYS_CCOMPILE_H */
end_comment

end_unit

