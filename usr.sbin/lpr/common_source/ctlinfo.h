begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ------+---------+---------+---------+---------+---------+---------+---------*  * Copyright (c) 2001  - Garance Alistair Drosehn<gad@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * The views and conclusions contained in the software and documentation  * are those of the authors and should not be interpreted as representing  * official policies, either expressed or implied, of the FreeBSD Project.  *  * ------+---------+---------+---------+---------+---------+---------+---------*  * $FreeBSD$  * ------+---------+---------+---------+---------+---------+---------+---------*  */
end_comment

begin_comment
comment|/*  * ctlinfo - This collection of routines will know everything there is to  * know about the information inside a control file ('cf*') which is used  * to describe a print job in lpr& friends.  The eventual goal is that it  * will be the ONLY source file to know what's inside these control-files.  */
end_comment

begin_struct_decl
struct_decl|struct
name|cjprivate
struct_decl|;
end_struct_decl

begin_comment
comment|/* used internal to ctl* routines */
end_comment

begin_struct
struct|struct
name|cjobinfo
block|{
name|int
name|cji_dfcount
decl_stmt|;
comment|/* number of data files to print */
name|int
name|cji_uncount
decl_stmt|;
comment|/* number of unlink-file requests */
name|char
modifier|*
name|cji_accthost
decl_stmt|;
comment|/* the host that this job came from, 					 * for accounting purposes (usually 					 * the host where the original 'lpr' 					 * was done) */
name|char
modifier|*
name|cji_acctuser
decl_stmt|;
comment|/* userid who should be charged for 					 * this job (usually, the userid which 					 * did the original 'lpr') */
name|char
modifier|*
name|cji_class
decl_stmt|;
comment|/* class-name */
name|char
modifier|*
name|cji_curqueue
decl_stmt|;
comment|/* printer-queue that this cf-file is 					 * curently sitting in (mainly used 					 * in syslog error messages) */
name|char
modifier|*
name|cji_fname
decl_stmt|;
comment|/* filename of the control file */
name|char
modifier|*
name|cji_jobname
decl_stmt|;
comment|/* job-name (for banner) */
name|char
modifier|*
name|cji_mailto
decl_stmt|;
comment|/* userid to send email to (or null) */
name|char
modifier|*
name|cji_username
decl_stmt|;
comment|/* "literal" user-name (for banner) or 					 * NULL if no banner-page is wanted */
name|struct
name|cjprivate
modifier|*
name|cji_priv
decl_stmt|;
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|char
modifier|*
name|ctl_renametf
parameter_list|(
specifier|const
name|char
modifier|*
name|_ptrname
parameter_list|,
specifier|const
name|char
modifier|*
name|_tfname
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

end_unit

