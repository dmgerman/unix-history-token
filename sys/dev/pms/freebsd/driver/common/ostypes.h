begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * *******************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  Note: ******************************************************************************* Module Name:     ostypes.h Abstract:     Request by fclayer for data type define. Authors:     EW - Yiding(Eddie) Wang Environment:     Kernel or loadable module    Version Control Information:     $ver. 1.0.0      Revision History:   $Revision: 114125 $0.1.0   $Date: 2012-04-23 23:37:56 -0700 (Mon, 23 Apr 2012) $09-27-2001   $Modtime: 11/12/01 11:15a $15:56:00  Notes: **************************** MODIFICATION HISTORY *****************************  NAME     DATE         Rev.          DESCRIPTION ----     ----         ----          ----------- EW     09-16-2002     0.1.0     Header file for most constant definitions ******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OSTYPES_H__
end_ifndef

begin_define
define|#
directive|define
name|__OSTYPES_H__
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_comment
comment|/* ** Included for Linux 2.4, built in kernel and other possible cases. */
end_comment

begin_comment
comment|/* #ifdef  TARGET_DRIVER #if !defined(AGBUILD_TFE_DRIVER)&& !defined(COMBO_IBE_TFE_MODULE) #include "lxtgtdef.h" #endif #endif */
end_comment

begin_comment
comment|/* ** Included for possible lower layer ignorance. */
end_comment

begin_include
include|#
directive|include
file|"osdebug.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|STATIC
end_ifdef

begin_undef
undef|#
directive|undef
name|STATIC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STATIC
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|INLINE
end_ifndef

begin_define
define|#
directive|define
name|INLINE
value|inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FORCEINLINE
end_ifndef

begin_define
define|#
directive|define
name|FORCEINLINE
end_define

begin_comment
comment|//#define FORCEINLINE inline
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|BITS_PER_LONG
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BITS_PER_LONG
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|char
name|bit8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|bit16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|bit32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|sbit8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|sbit16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|sbit32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|BOOLEAN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|bit64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|sbit64
typedef|;
end_typedef

begin_comment
comment|//typedef unsigned long long  bitptr;
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_if
if|#
directive|if
operator|(
name|BITS_PER_LONG
operator|==
literal|64
operator|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|bitptr
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|bitptr
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|char
name|S08
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|S16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|S32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|S32_64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|S64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|U08
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|U16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|U32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|U32_64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|U64
typedef|;
end_typedef

begin_comment
comment|/* ** some really basic defines */
end_comment

begin_define
define|#
directive|define
name|GLOBAL
value|extern
end_define

begin_define
define|#
directive|define
name|LOCAL
value|static
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|FAILURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|((void*)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|agBOOLEAN
value|BOOLEAN
end_define

begin_define
define|#
directive|define
name|osGLOBAL
value|GLOBAL
end_define

begin_define
define|#
directive|define
name|osLOCAL
value|LOCAL
end_define

begin_define
define|#
directive|define
name|agTRUE
value|TRUE
end_define

begin_define
define|#
directive|define
name|agFALSE
value|FALSE
end_define

begin_define
define|#
directive|define
name|agNULL
value|NULL
end_define

begin_define
define|#
directive|define
name|AGTIAPI_UNKNOWN
value|2
end_define

begin_define
define|#
directive|define
name|AGTIAPI_SUCCESS
value|1
end_define

begin_define
define|#
directive|define
name|AGTIAPI_FAIL
value|0
end_define

begin_define
define|#
directive|define
name|AGTIAPI_DRIVER_VERSION
value|"1.4.0.10800"
end_define

begin_comment
comment|/*************************************************************************** **************************************************************************** * MACROS - some basic macros     **************************************************************************** ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIT
end_ifndef

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|x
parameter_list|)
value|(1<<x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|osti_sprintf
value|sprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OSTYPES_H__ */
end_comment

end_unit

