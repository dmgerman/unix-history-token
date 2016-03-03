begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Semihalf.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DFLAGS_H_
end_ifndef

begin_define
define|#
directive|define
name|DFLAGS_H_
end_define

begin_include
include|#
directive|include
file|"opt_platform.h"
end_include

begin_include
include|#
directive|include
file|"events_mapping.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|P3041DS
argument_list|)
end_if

begin_define
define|#
directive|define
name|P3041
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|P2041RDB
argument_list|)
end_elif

begin_define
define|#
directive|define
name|P2041
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|P5020DS
argument_list|)
end_elif

begin_define
define|#
directive|define
name|P5020
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P5020
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NCSW_PPC_CORE
end_define

begin_define
define|#
directive|define
name|NCSW_FREEBSD
end_define

begin_comment
comment|/* Debugging */
end_comment

begin_define
define|#
directive|define
name|DEBUG_ERRORS
value|1
end_define

begin_define
define|#
directive|define
name|DPAA_DEBUG
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DPAA_DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEBUG_GLOBAL_LEVEL
value|REPORT_LEVEL_INFO
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUG_GLOBAL_LEVEL
value|REPORT_LEVEL_WARNING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Events */
end_comment

begin_define
define|#
directive|define
name|REPORT_EVENTS
value|1
end_define

begin_define
define|#
directive|define
name|EVENT_GLOBAL_LEVEL
value|REPORT_LEVEL_MINOR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DFLAGS_H_ */
end_comment

end_unit

