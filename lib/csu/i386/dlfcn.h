begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)err.h	8.1 (Berkeley) 6/2/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DLFCN_H_
end_ifndef

begin_define
define|#
directive|define
name|_DLFCN_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * Modes for dlopen().  */
end_comment

begin_define
define|#
directive|define
name|RTLD_LAZY
value|1
end_define

begin_comment
comment|/* Bind function calls lazily */
end_comment

begin_define
define|#
directive|define
name|RTLD_NOW
value|2
end_define

begin_comment
comment|/* Bind function calls immediately */
end_comment

begin_comment
comment|/*  * Special handle argument for dlsym().  It causes the search for the  * symbol to begin in the next shared object after the one containing  * the caller.  */
end_comment

begin_define
define|#
directive|define
name|RTLD_NEXT
value|((void *) -1)
end_define

begin_comment
comment|/*  * Structure filled in by dladdr().  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dl_info
block|{
specifier|const
name|char
modifier|*
name|dli_fname
decl_stmt|;
comment|/* Pathname of shared object */
name|void
modifier|*
name|dli_fbase
decl_stmt|;
comment|/* Base address of shared object */
specifier|const
name|char
modifier|*
name|dli_sname
decl_stmt|;
comment|/* Name of nearest symbol */
name|void
modifier|*
name|dli_saddr
decl_stmt|;
comment|/* Address of nearest symbol */
block|}
name|Dl_info
typedef|;
end_typedef

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|dladdr
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
name|Dl_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dlclose
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|dlerror
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|dlopen
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|dlsym
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DLFCN_H_ */
end_comment

end_unit

