begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  *  * $FreeBSD$   */
end_comment

begin_comment
comment|/*  * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*	Copyright (c) 1990, 1991 UNIX System Laboratories, Inc. */
end_comment

begin_comment
comment|/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T		*/
end_comment

begin_comment
comment|/*	All Rights Reserved	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_REGSET_H
end_ifndef

begin_define
define|#
directive|define
name|_REGSET_H
end_define

begin_comment
comment|/*  * #pragma ident	"@(#)regset.h	1.11	05/06/08 SMI"  */
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
literal|0
define|#
directive|define
name|REG_LINK
value|R14
define|#
directive|define
name|REG_SP
value|R12
define|#
directive|define
name|REG_PS
value|R0
define|#
directive|define
name|REG_R0
value|R0
define|#
directive|define
name|REG_R1
value|R1
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
comment|/* _REGSET_H */
end_comment

end_unit

