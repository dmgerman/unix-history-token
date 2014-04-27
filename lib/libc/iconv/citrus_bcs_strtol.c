begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: citrus_bcs_strtol.c,v 1.4 2013/04/26 21:20:47 joerg Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2005 The DragonFly Project.  All rights reserved.  * Copyright (c) 2003, 2008 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"citrus_namespace.h"
end_include

begin_include
include|#
directive|include
file|"citrus_bcs.h"
end_include

begin_define
define|#
directive|define
name|_FUNCNAME
value|_bcs_strtol
end_define

begin_define
define|#
directive|define
name|__INT
value|long int
end_define

begin_undef
undef|#
directive|undef
name|isspace
end_undef

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|_bcs_isspace(c)
end_define

begin_undef
undef|#
directive|undef
name|isdigit
end_undef

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|_bcs_isdigit(c)
end_define

begin_undef
undef|#
directive|undef
name|isalpha
end_undef

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|c
parameter_list|)
value|_bcs_isalpha(c)
end_define

begin_undef
undef|#
directive|undef
name|isupper
end_undef

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|_bcs_isupper(c)
end_define

begin_include
include|#
directive|include
file|"_strtol.h"
end_include

end_unit

