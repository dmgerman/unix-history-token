begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * *******************************************************************************/
end_comment

begin_comment
comment|/***************************************************************************  Version Control Information:  $RCSfile: osdebug.h,v $ $Revision: 114125 $  Note: ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OSDEBUG_H__
end_ifndef

begin_define
define|#
directive|define
name|__OSDEBUG_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AGTIAPI_KDB_ENABLE
end_ifdef

begin_include
include|#
directive|include
file|<linux/kdb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*************************************************************************** OS_ASSERT : This macro is used when an internal error is detected.       ***************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AGTIAPI_KDB_ENABLE
end_ifdef

begin_define
define|#
directive|define
name|OS_ASSERT
parameter_list|(
name|expr
parameter_list|,
name|message
parameter_list|)
define|\
value|do {                                                              \           if (!(expr))                                            \           {                                                       \             printf("ASSERT: %s", message);                        \             printf(" - file %s, line %d\n", __FILE__, __LINE__);  \             BUG_ON(1);                                            \             KDB_ENTER();                                          \           }                                                       \ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OS_ASSERT
parameter_list|(
name|expr
parameter_list|,
name|message
parameter_list|)
define|\
value|do {                                                              \           if (!(expr))                                            \           {                                                       \             printf("ASSERT: %s", message);                        \             printf(" - file %s, line %d\n", __FILE__, __LINE__);  \           }                                                       \ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AG_ERROR_MSG
parameter_list|(
name|mask
parameter_list|,
name|val
parameter_list|,
name|format
parameter_list|)
define|\
value|do {                                    \           if (mask)                     \           {                             \             if (mask>= val)            \               printf format;            \           }                             \           else                          \             printf format;              \ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TD_DEBUG_ENABLE
end_ifdef

begin_define
define|#
directive|define
name|TIDEBUG_MSG
parameter_list|(
name|mask
parameter_list|,
name|val
parameter_list|,
name|format
parameter_list|)
define|\
value|do {                                    \           if (mask)                     \           {                             \             if (!val)                   \               printf format ;           \             else                        \               if (!(mask& 0x80000000)) \               {                         \                 if (mask>= val)        \                   printf format ;       \               }                         \               else                      \               {                         \                 if (mask& val)         \                   printf format ;       \               }                         \           }                             \ } while (0)
end_define

begin_define
define|#
directive|define
name|TIDEBUG_MSG0
parameter_list|(
name|format
parameter_list|)
define|\
value|do {                                    \               printf format ;           \ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TIDEBUG_MSG
parameter_list|(
name|mask
parameter_list|,
name|val
parameter_list|,
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TIDEBUG_MSG0
parameter_list|(
name|format
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*************************************************************************** FC debug - The following is used for FC specific debug. **************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AG_PROTOCOL_FC
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|fcEnableTraceFunctions
end_ifndef

begin_define
define|#
directive|define
name|fcEnableTraceFunctions
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|fcEnableTraceFunctions
end_ifndef

begin_define
define|#
directive|define
name|fcEnableTraceFunctions
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AG_PROTOCOL_FC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef __OSDEBUG_H__ */
end_comment

end_unit

