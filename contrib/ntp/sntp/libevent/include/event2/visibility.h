begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* -*- Mode: C; tab-width: 4; c-basic-offset: 4; indent-tabs-mode: nil -*- */
end_comment

begin_comment
comment|/*  * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENT2_VISIBILITY_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVENT2_VISIBILITY_H_INCLUDED_
end_define

begin_include
include|#
directive|include
file|<event2/event-config.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|event_EXPORTS
argument_list|)
operator|||
name|defined
argument_list|(
name|event_extra_EXPORTS
argument_list|)
operator|||
name|defined
argument_list|(
name|event_core_EXPORTS
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SUNPRO_C
argument_list|)
operator|&&
operator|(
name|__SUNPRO_C
operator|>=
literal|0x550
operator|)
end_if

begin_define
define|#
directive|define
name|EVENT2_EXPORT_SYMBOL
value|__global
end_define

begin_elif
elif|#
directive|elif
name|defined
name|__GNUC__
end_elif

begin_define
define|#
directive|define
name|EVENT2_EXPORT_SYMBOL
value|__attribute__ ((visibility("default")))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_define
define|#
directive|define
name|EVENT2_EXPORT_SYMBOL
value|extern __declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* unknown compiler */
end_comment

begin_define
define|#
directive|define
name|EVENT2_EXPORT_SYMBOL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EVENT__NEED_DLLIMPORT
argument_list|)
operator|&&
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|EVENT_BUILDING_REGRESS_TEST
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVENT2_EXPORT_SYMBOL
value|extern __declspec(dllimport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVENT2_EXPORT_SYMBOL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EVENT2_VISIBILITY_H_INCLUDED_ */
end_comment

end_unit

