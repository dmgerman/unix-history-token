begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-07 Applied Micro Circuits Corporation.  * Copyright (c) 2004-05 Vinod Kashyap.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * AMCC'S 3ware driver for 9000 series storage controllers.  *  * Author: Vinod Kashyap  * Modifications by: Adam Radford  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TW_OSL_SHARE_H
end_ifndef

begin_define
define|#
directive|define
name|TW_OSL_SHARE_H
end_define

begin_comment
comment|/*  * Macros, structures and functions shared between OSL and CL,  * and defined by OSL.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/clock.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/twa/tw_osl_types.h>
end_include

begin_include
include|#
directive|include
file|"opt_twa.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TWA_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|TW_OSL_DEBUG
value|TWA_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TWA_ENCLOSURE_SUPPORT
end_ifdef

begin_define
define|#
directive|define
name|TW_OSL_ENCLOSURE_SUPPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TW_OSL_DRIVER_VERSION_STRING
value|"3.60.03.006"
end_define

begin_define
define|#
directive|define
name|TW_OSL_CAN_SLEEP
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_CAN_SLEEP
end_ifdef

begin_typedef
typedef|typedef
name|TW_VOID
modifier|*
name|TW_SLEEP_HANDLE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_CAN_SLEEP */
end_comment

begin_define
define|#
directive|define
name|TW_OSL_PCI_CONFIG_ACCESSIBLE
end_define

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|TW_OSL_BIG_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TW_OSL_LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TW_OSL_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|TW_INT32
name|TW_OSL_DEBUG_LEVEL_FOR_CL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_DEBUG */
end_comment

begin_comment
comment|/* Possible return codes from/to Common Layer functions. */
end_comment

begin_define
define|#
directive|define
name|TW_OSL_ESUCCESS
value|0
end_define

begin_comment
comment|/* success */
end_comment

begin_define
define|#
directive|define
name|TW_OSL_EGENFAILURE
value|1
end_define

begin_comment
comment|/* general failure */
end_comment

begin_define
define|#
directive|define
name|TW_OSL_ENOMEM
value|ENOMEM
end_define

begin_comment
comment|/* insufficient memory */
end_comment

begin_define
define|#
directive|define
name|TW_OSL_EIO
value|EIO
end_define

begin_comment
comment|/* I/O error */
end_comment

begin_define
define|#
directive|define
name|TW_OSL_ETIMEDOUT
value|ETIMEDOUT
end_define

begin_comment
comment|/* time out */
end_comment

begin_define
define|#
directive|define
name|TW_OSL_ENOTTY
value|ENOTTY
end_define

begin_comment
comment|/* invalid command */
end_comment

begin_define
define|#
directive|define
name|TW_OSL_EBUSY
value|EBUSY
end_define

begin_comment
comment|/* busy -- try later */
end_comment

begin_define
define|#
directive|define
name|TW_OSL_EBIG
value|EFBIG
end_define

begin_comment
comment|/* request too big */
end_comment

begin_define
define|#
directive|define
name|TW_OSL_EWOULDBLOCK
value|EWOULDBLOCK
end_define

begin_comment
comment|/* sleep timed out */
end_comment

begin_define
define|#
directive|define
name|TW_OSL_ERESTART
value|ERESTART
end_define

begin_comment
comment|/* sleep terminated by a signal */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TW_OSL_SHARE_H */
end_comment

end_unit

