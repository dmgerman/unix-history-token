begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * $Id: bsd-cray.h,v 1.3 2002/05/15 16:39:52 mouring Exp $  *  * bsd-cray.h  *  * Copyright (c) 2002, Cray Inc.  (Wendy Palm<wendyp@cray.com>)  * Significant portions provided by   *          Wayne Schroeder, SDSC<schroeder@sdsc.edu>  *          William Jones, UTexas<jones@tacc.utexas.edu>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Created: Apr 22 16.34:00 2002 wp  *  * This file contains functions required for proper execution  * on UNICOS systems.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_CRAY_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_CRAY_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_CRAY
end_ifdef

begin_function_decl
name|void
name|cray_init_job
parameter_list|(
name|struct
name|passwd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* init cray job */
end_comment

begin_function_decl
name|void
name|cray_job_termination_handler
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* process end of job signal */
end_comment

begin_function_decl
name|void
name|cray_setup
parameter_list|(
name|uid_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set cray limits */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|cray_tmpdir
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cray tmpdir */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_CRAY_H */
end_comment

end_unit

