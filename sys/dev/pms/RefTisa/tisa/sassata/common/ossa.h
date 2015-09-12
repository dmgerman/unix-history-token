begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/** \file  *  * The file defines the declaration of OS types  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OS_SA_H__
end_ifndef

begin_define
define|#
directive|define
name|__OS_SA_H__
end_define

begin_define
define|#
directive|define
name|DEBUG_LEVEL
value|OSSA_DEBUG_LEVEL_1
end_define

begin_define
define|#
directive|define
name|ossaLogDebugString
value|TIDEBUG_MSG
end_define

begin_define
define|#
directive|define
name|ossaAssert
value|OS_ASSERT
end_define

begin_define
define|#
directive|define
name|tddmLogDebugString
value|TIDEBUG_MSG
end_define

begin_define
define|#
directive|define
name|DM_ASSERT
value|OS_ASSERT
end_define

begin_define
define|#
directive|define
name|tdsmLogDebugString
value|TIDEBUG_MSG
end_define

begin_define
define|#
directive|define
name|SM_ASSERT
value|OS_ASSERT
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NOT_YET
end_ifdef

begin_comment
comment|/* no longer valid */
end_comment

begin_define
define|#
directive|define
name|ossaLogDebugString
parameter_list|(
name|agRoot
parameter_list|,
name|level
parameter_list|,
name|string
parameter_list|,
name|ptr1
parameter_list|,
name|ptr2
parameter_list|,
name|value1
parameter_list|,
name|value2
parameter_list|)
define|\
value|do { \     if ( level<= DEBUG_LEVEL ) \     {                          \       printk("%s:", __FUNCTION__); \       if ( agNULL != string )  \       {                        \         printk("%s:", string); \       }                        \       if ( agNULL != ptr1 )    \       {                        \         printk("ptr1=%p,", ptr1); \       }                           \       if ( agNULL != ptr2 )       \       {                           \         printk("ptr2=%p,", ptr2); \       }                           \       if ( OSSA_DEBUG_PRINT_INVALID_NUMBER != value1 ) \       {                                   \         printk("value1=0x%08x ", value1); \       }                                   \       if ( OSSA_DEBUG_PRINT_INVALID_NUMBER != value2 ) \       {                                                \         printk("value2=0x%08x ", value2);              \       } \       printk("\n"); \     }        \   } while (0);
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ossaAssert
end_ifndef

begin_define
define|#
directive|define
name|ossaAssert
parameter_list|(
name|agRoot
parameter_list|,
name|expr
parameter_list|,
name|message
parameter_list|)
define|\
value|do {                                                              \     if (agFALSE == (expr))                                            \     {                                                       \       printk("ossaAssert: %s", (message));                        \       printk(" - file %s, line %d\n", __FILE__, __LINE__);  \     }                                                       \   } while (0);
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
comment|/* 0 */
end_comment

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/osenv.h>
end_include

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/ostypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OS_SA_H__ */
end_comment

end_unit

