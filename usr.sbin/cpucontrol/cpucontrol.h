begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Stanislav Sedov<stas@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CPUCONTROL_H
end_ifndef

begin_define
define|#
directive|define
name|CPUCONTROL_H
end_define

begin_typedef
typedef|typedef
name|int
name|ucode_probe_t
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|ucode_update_t
parameter_list|(
specifier|const
name|char
modifier|*
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|image
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|verbosity_level
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|WARNX
parameter_list|(
name|level
parameter_list|,
modifier|...
parameter_list|)
define|\
value|if ((level)<= verbosity_level) {			\ 		fprintf(stderr, "%s:%d ", __FILE__, __LINE__);	\ 		warnx(__VA_ARGS__);				\ 	}
end_define

begin_define
define|#
directive|define
name|WARN
parameter_list|(
name|level
parameter_list|,
modifier|...
parameter_list|)
define|\
value|if ((level)<= verbosity_level) {			\ 		fprintf(stderr, "%s:%d ", __FILE__, __LINE__);	\ 		warn(__VA_ARGS__);				\ 	}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WARNX
parameter_list|(
name|level
parameter_list|,
modifier|...
parameter_list|)
define|\
value|if ((level)<= verbosity_level)				\ 		warnx(__VA_ARGS__);
end_define

begin_define
define|#
directive|define
name|WARN
parameter_list|(
name|level
parameter_list|,
modifier|...
parameter_list|)
define|\
value|if ((level)<= verbosity_level)				\ 		warn(__VA_ARGS__);
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
comment|/* !CPUCONTROL_H */
end_comment

end_unit

