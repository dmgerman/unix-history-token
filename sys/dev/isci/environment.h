begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ENVIRONMENT_H_
end_ifndef

begin_define
define|#
directive|define
name|ENVIRONMENT_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief Types and macros specific to the FreeBSD environment.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|"opt_isci.h"
end_include

begin_typedef
typedef|typedef
name|int8_t
name|S8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|U8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int16_t
name|S16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|U16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|S32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|U32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|S64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|U64
typedef|;
end_typedef

begin_comment
comment|/* Technically, this should be defined as bus_addr_t, but SCIL makes some  *  incorrect assumptions in some of its physical address calculations which  *  necessitate using uint64_t here to avoid compiler warnings.  This is  *  easier for now than modifying SCIL, and works just as well.  */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|SCI_PHYSICAL_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|U64
name|SATI_LBA
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|FUNCPTR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sci_cb_physical_address_upper
parameter_list|(
name|address
parameter_list|)
value|((uint32_t)((address)>>32))
end_define

begin_define
define|#
directive|define
name|sci_cb_physical_address_lower
parameter_list|(
name|address
parameter_list|)
value|((uint32_t)((address)&0xFFFFFFFF))
end_define

begin_define
define|#
directive|define
name|sci_cb_make_physical_address
parameter_list|(
name|physical_address
parameter_list|,
name|address_upper
parameter_list|,
name|address_lower
parameter_list|)
define|\
value|((physical_address) = ((U64)(address_upper))<<32 | (address_lower))
end_define

begin_define
define|#
directive|define
name|INLINE
value|__inline
end_define

begin_define
define|#
directive|define
name|PLACEMENT_HINTS
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SCIC_SDS_4_ENABLED
value|1
end_define

begin_define
define|#
directive|define
name|PBG_BUILD
value|1
end_define

begin_define
define|#
directive|define
name|PHY_MAX_LINK_SPEED_GENERATION
value|3
end_define

begin_comment
comment|/* SCIL defines logging as SCI_LOGGING, but the FreeBSD driver name is ISCI. 	So we define ISCI_LOGGING as the option exported to the kernel, and 	translate it here. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISCI_LOGGING
end_ifdef

begin_define
define|#
directive|define
name|SCI_LOGGING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__SCI_LIBRARY_MAJOR_VERSION__
value|3
end_define

begin_define
define|#
directive|define
name|__SCI_LIBRARY_MINOR_VERSION__
value|1
end_define

begin_define
define|#
directive|define
name|__SCI_LIBRARY_BUILD_VERSION__
value|7142
end_define

begin_define
define|#
directive|define
name|SATI_TRANSPORT_SUPPORTS_SATA
end_define

begin_define
define|#
directive|define
name|SATI_TRANSPORT_SUPPORTS_SAS
end_define

begin_define
define|#
directive|define
name|USE_ABSTRACT_LIST_FUNCTIONS
end_define

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|cond
parameter_list|)
end_define

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|cond
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENVIRONMENT_H_ */
end_comment

end_unit

