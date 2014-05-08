begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 John Birrell (jb@freebsd.org)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/event.h>
end_include

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_include
include|#
directive|include
file|<rtld_db.h>
end_include

begin_include
include|#
directive|include
file|"libproc.h"
end_include

begin_struct
struct|struct
name|proc_handle
block|{
name|pid_t
name|pid
decl_stmt|;
comment|/* Process ID. */
name|int
name|kq
decl_stmt|;
comment|/* Kernel event queue ID. */
name|int
name|flags
decl_stmt|;
comment|/* Process flags. */
name|int
name|status
decl_stmt|;
comment|/* Process status (PS_*). */
name|int
name|wstat
decl_stmt|;
comment|/* Process wait status. */
name|rd_agent_t
modifier|*
name|rdap
decl_stmt|;
comment|/* librtld_db agent */
name|rd_loadobj_t
modifier|*
name|rdobjs
decl_stmt|;
name|size_t
name|rdobjsz
decl_stmt|;
name|size_t
name|nobjs
decl_stmt|;
name|struct
name|lwpstatus
name|lwps
decl_stmt|;
name|rd_loadobj_t
modifier|*
name|rdexec
decl_stmt|;
comment|/* rdobj index of program executable. */
name|char
name|execname
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
comment|/* Path to program executable. */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
modifier|...
parameter_list|)
value|warn(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|DPRINTFX
parameter_list|(
modifier|...
parameter_list|)
value|warnx(__VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|DPRINTFX
parameter_list|(
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

