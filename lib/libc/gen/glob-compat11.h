begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Guido van Rossum.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)glob.h	8.1 (Berkeley) 6/2/93  * from: $FreeBSD$  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLOB_COMPAT11_H_
end_ifndef

begin_define
define|#
directive|define
name|_GLOB_COMPAT11_H_
end_define

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
file|<glob.h>
end_include

begin_struct_decl
struct_decl|struct
name|freebsd11_stat
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|size_t
name|gl_pathc
decl_stmt|;
comment|/* Count of total paths so far. */
name|size_t
name|gl_matchc
decl_stmt|;
comment|/* Count of paths matching pattern. */
name|size_t
name|gl_offs
decl_stmt|;
comment|/* Reserved at beginning of gl_pathv. */
name|int
name|gl_flags
decl_stmt|;
comment|/* Copy of flags parameter to glob. */
name|char
modifier|*
modifier|*
name|gl_pathv
decl_stmt|;
comment|/* List of paths matching pattern. */
comment|/* Copy of errfunc parameter to glob. */
name|int
function_decl|(
modifier|*
name|gl_errfunc
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* 	 * Alternate filesystem access methods for glob; replacement 	 * versions of closedir(3), readdir(3), opendir(3), stat(2) 	 * and lstat(2). 	 */
name|void
function_decl|(
modifier|*
name|gl_closedir
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|struct
name|freebsd11_dirent
modifier|*
function_decl|(
modifier|*
name|gl_readdir
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
function_decl|(
modifier|*
name|gl_opendir
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|gl_lstat
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|freebsd11_stat
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|gl_stat
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|freebsd11_stat
modifier|*
parameter_list|)
function_decl|;
block|}
name|glob11_t
typedef|;
end_typedef

begin_function_decl
name|__BEGIN_DECLS
name|int
name|freebsd11_glob
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|glob11_t
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freebsd11_globfree
parameter_list|(
name|glob11_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_GLOB_COMPAT11_H_ */
end_comment

end_unit

