begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * *******************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  Note: This program is separated from main driver source due to the common usage of both initiator and target. ******************************************************************************* Module Name:     osstring.h Abstract:     FreeBSD SPCv Initiator driver module OS API definitions Authors:     EW - Eddie Wang Environment:     Kernel or loadable module    Version Control Information:     $ver. 1.0.0      Revision History:   $Revision: 114125 $0.1.0   $Date: 2012-01-06 17:12:27 -0800 (Fri, 06 Jan 2012) $08-27-2001   $Modtime: 11/12/01 11:15a $11:46:00  Notes:  **************************** MODIFICATION HISTORY *****************************  NAME     DATE         Rev.        DESCRIPTION ----     ----         ----        ----------- EW     05-27-2002     1.0.0     Code construction started. ******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OSSTRING_H__
end_ifndef

begin_define
define|#
directive|define
name|__OSSTRING_H__
end_define

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslimits.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/ctype.h>
end_include

begin_define
define|#
directive|define
name|osti_memcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|memcmp((void *)s1, (void *)s2, (size_t)n)
end_define

begin_define
define|#
directive|define
name|osti_memcpy
parameter_list|(
name|des
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
value|memcpy((void *)des, (void *)src, (size_t)n)
end_define

begin_define
define|#
directive|define
name|osti_memset
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
value|memset((void *)s, (int)c, (size_t)n)
end_define

begin_define
define|#
directive|define
name|osti_strcat
parameter_list|(
name|des
parameter_list|,
name|src
parameter_list|)
value|strcat((char *)des, (char *)src)
end_define

begin_define
define|#
directive|define
name|osti_strchr
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|strchr((char *)s, (int)n)
end_define

begin_define
define|#
directive|define
name|osti_strcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|strcmp((char *)s1, (char *)s2)
end_define

begin_define
define|#
directive|define
name|osti_strcpy
parameter_list|(
name|des
parameter_list|,
name|src
parameter_list|)
value|strcpy((char *)des, (char *)src)
end_define

begin_define
define|#
directive|define
name|osti_strlen
parameter_list|(
name|s
parameter_list|)
value|strlen((char *)s)
end_define

begin_define
define|#
directive|define
name|osti_strncmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|strncmp((char *)s1, (char *)s2, (size_t)n)
end_define

begin_define
define|#
directive|define
name|osti_strncpy
parameter_list|(
name|des
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
value|strncpy((char *)des, (char *)src, (size_t)n)
end_define

begin_define
define|#
directive|define
name|osti_strstr
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|strstr((char *)s1, (char *)s2)
end_define

begin_define
define|#
directive|define
name|osti_strtoul
parameter_list|(
name|nptr
parameter_list|,
name|endptr
parameter_list|,
name|base
parameter_list|)
define|\
value|strtoul((char *)nptr, (char **)endptr, 0)
end_define

begin_define
define|#
directive|define
name|osti_isxdigit
parameter_list|(
name|c
parameter_list|)
value|isxdigit(c)
end_define

begin_define
define|#
directive|define
name|osti_isdigit
parameter_list|(
name|c
parameter_list|)
value|isdigit(c)
end_define

begin_define
define|#
directive|define
name|osti_islower
parameter_list|(
name|c
parameter_list|)
value|islower(c)
end_define

begin_define
define|#
directive|define
name|osMemCpy
parameter_list|(
name|des
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
value|memcpy((void *)des, (void *)src, (size_t)n)
end_define

begin_define
define|#
directive|define
name|osMemSet
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
value|memset((void *)s, (int)c, (size_t)n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OSSTRING_H__ */
end_comment

end_unit

