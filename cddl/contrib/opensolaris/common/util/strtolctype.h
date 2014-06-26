begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*	Copyright (c) 1988 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMMON_UTIL_CTYPE_H
end_ifndef

begin_define
define|#
directive|define
name|_COMMON_UTIL_CTYPE_H
end_define

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
comment|/*  * This header file contains a collection of macros that the strtou?ll?  * functions in common/util use to test characters.  What we need is a kernel  * version of ctype.h.  *  * NOTE: These macros are used within several DTrace probe context functions.  * They must not be altered to make function calls or perform actions not  * safe in probe context.  */
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_BOOT
argument_list|)
operator|)
define|#
directive|define
name|isalnum
parameter_list|(
name|ch
parameter_list|)
value|(isalpha(ch) || isdigit(ch))
define|#
directive|define
name|isalpha
parameter_list|(
name|ch
parameter_list|)
value|(isupper(ch) || islower(ch))
define|#
directive|define
name|isdigit
parameter_list|(
name|ch
parameter_list|)
value|((ch)>= '0'&& (ch)<= '9')
define|#
directive|define
name|islower
parameter_list|(
name|ch
parameter_list|)
value|((ch)>= 'a'&& (ch)<= 'z')
define|#
directive|define
name|isspace
parameter_list|(
name|ch
parameter_list|)
value|(((ch) == ' ') || ((ch) == '\r') || ((ch) == '\n') || \ 			((ch) == '\t') || ((ch) == '\f'))
define|#
directive|define
name|isupper
parameter_list|(
name|ch
parameter_list|)
value|((ch)>= 'A'&& (ch)<= 'Z')
define|#
directive|define
name|isxdigit
parameter_list|(
name|ch
parameter_list|)
value|(isdigit(ch) || ((ch)>= 'a'&& (ch)<= 'f') || \ 			((ch)>= 'A'&& (ch)<= 'F'))
endif|#
directive|endif
comment|/* _KERNEL || _BOOT */
define|#
directive|define
name|DIGIT
parameter_list|(
name|x
parameter_list|)
define|\
value|(isdigit(x) ? (x) - '0' : islower(x) ? (x) + 10 - 'a' : (x) + 10 - 'A')
define|#
directive|define
name|MBASE
value|('z' - 'a' + 1 + 10)
comment|/*  * The following macro is a version of isalnum() that limits alphabetic  * characters to the ranges a-z and A-Z; locale dependent characters will not  * return 1.  The members of a-z and A-Z are assumed to be in ascending order  * and contiguous.  */
define|#
directive|define
name|lisalnum
parameter_list|(
name|x
parameter_list|)
define|\
value|(isdigit(x) || ((x)>= 'a'&& (x)<= 'z') || ((x)>= 'A'&& (x)<= 'Z'))
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
comment|/* _COMMON_UTIL_CTYPE_H */
end_comment

end_unit

