begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-2003 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IPROP_H__
end_ifndef

begin_define
define|#
directive|define
name|__IPROP_H__
end_define

begin_include
include|#
directive|include
file|"kadm5_locl.h"
end_include

begin_include
include|#
directive|include
file|<getarg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SELECT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UTIL_H
end_ifdef

begin_include
include|#
directive|include
file|<util.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<parse_time.h>
end_include

begin_define
define|#
directive|define
name|IPROP_VERSION
value|"iprop-0.0"
end_define

begin_define
define|#
directive|define
name|IPROP_NAME
value|"iprop"
end_define

begin_define
define|#
directive|define
name|IPROP_SERVICE
value|"iprop"
end_define

begin_define
define|#
directive|define
name|IPROP_PORT
value|2121
end_define

begin_enum
enum|enum
name|iprop_cmd
block|{
name|I_HAVE
init|=
literal|1
block|,
name|FOR_YOU
init|=
literal|2
block|,
name|TELL_YOU_EVERYTHING
init|=
literal|3
block|,
name|ONE_PRINC
init|=
literal|4
block|,
name|NOW_YOU_HAVE
init|=
literal|5
block|,
name|ARE_YOU_THERE
init|=
literal|6
block|,
name|I_AM_HERE
init|=
literal|7
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|sig_atomic_t
name|exit_flag
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|setup_signal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IPROP_H__ */
end_comment

end_unit

