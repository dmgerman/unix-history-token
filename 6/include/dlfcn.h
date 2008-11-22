begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<sys/_types.h>
end_include

begin_comment
comment|/*  * Modes and flags for dlopen().  */
end_comment

begin_define
define|#
directive|define
name|RTLD_LAZY
value|1
end_define

begin_comment
comment|/* Bind function calls lazily. */
end_comment

begin_define
define|#
directive|define
name|RTLD_NOW
value|2
end_define

begin_comment
comment|/* Bind function calls immediately. */
end_comment

begin_define
define|#
directive|define
name|RTLD_MODEMASK
value|0x3
end_define

begin_define
define|#
directive|define
name|RTLD_GLOBAL
value|0x100
end_define

begin_comment
comment|/* Make symbols globally available. */
end_comment

begin_define
define|#
directive|define
name|RTLD_LOCAL
value|0
end_define

begin_comment
comment|/* Opposite of RTLD_GLOBAL, and the default. */
end_comment

begin_define
define|#
directive|define
name|RTLD_TRACE
value|0x200
end_define

begin_comment
comment|/* Trace loaded objects and exit. */
end_comment

begin_comment
comment|/*  * Request arguments for dlinfo().  */
end_comment

begin_define
define|#
directive|define
name|RTLD_DI_LINKMAP
value|2
end_define

begin_comment
comment|/* Obtain link map. */
end_comment

begin_define
define|#
directive|define
name|RTLD_DI_SERINFO
value|4
end_define

begin_comment
comment|/* Obtain search path info. */
end_comment

begin_define
define|#
directive|define
name|RTLD_DI_SERINFOSIZE
value|5
end_define

begin_comment
comment|/*  ... query for required space. */
end_comment

begin_define
define|#
directive|define
name|RTLD_DI_ORIGIN
value|6
end_define

begin_comment
comment|/* Obtain object origin */
end_comment

begin_define
define|#
directive|define
name|RTLD_DI_MAX
value|RTLD_DI_ORIGIN
end_define

begin_comment
comment|/*  * Special handle arguments for dlsym()/dlinfo().  */
end_comment

begin_define
define|#
directive|define
name|RTLD_NEXT
value|((void *) -1)
end_define

begin_comment
comment|/* Search subsequent objects. */
end_comment

begin_define
define|#
directive|define
name|RTLD_DEFAULT
value|((void *) -2)
end_define

begin_comment
comment|/* Use default search algorithm. */
end_comment

begin_define
define|#
directive|define
name|RTLD_SELF
value|((void *) -3)
end_define

begin_comment
comment|/* Search the caller itself. */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Pathname of shared object. */
name|void
modifier|*
name|dli_fbase
decl_stmt|;
comment|/* Base address of shared object. */
specifier|const
name|char
modifier|*
name|dli_sname
decl_stmt|;
comment|/* Name of nearest symbol. */
name|void
modifier|*
name|dli_saddr
decl_stmt|;
comment|/* Address of nearest symbol. */
block|}
name|Dl_info
typedef|;
end_typedef

begin_comment
comment|/*-  * The actual type declared by this typedef is immaterial, provided that  * it is a function pointer.  Its purpose is to provide a return type for  * dlfunc() which can be cast to a function pointer type without depending  * on behavior undefined by the C standard, which might trigger a compiler  * diagnostic.  We intentionally declare a unique type signature to force  * a diagnostic should the application not cast the return value of dlfunc()  * appropriately.  */
end_comment

begin_struct
struct|struct
name|__dlfunc_arg
block|{
name|int
name|__dlfunc_dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dlfunc_t
function_decl|)
parameter_list|(
name|struct
name|__dlfunc_arg
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Structures, returned by the RTLD_DI_SERINFO dlinfo() request.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dl_serpath
block|{
name|char
modifier|*
name|dls_name
decl_stmt|;
comment|/* single search path entry */
name|unsigned
name|int
name|dls_flags
decl_stmt|;
comment|/* path information */
block|}
name|Dl_serpath
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dl_serinfo
block|{
name|size_t
name|dls_size
decl_stmt|;
comment|/* total buffer size */
name|unsigned
name|int
name|dls_cnt
decl_stmt|;
comment|/* number of path entries */
name|Dl_serpath
name|dls_serpath
index|[
literal|1
index|]
decl_stmt|;
comment|/* there may be more than one */
block|}
name|Dl_serinfo
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_function_decl
name|__BEGIN_DECLS
comment|/* XSI functions first. */
name|int
name|dlclose
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|dlerror
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|dlopen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|dlsym
parameter_list|(
name|void
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|int
name|dladdr
parameter_list|(
specifier|const
name|void
modifier|*
name|__restrict
parameter_list|,
name|Dl_info
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dlfunc_t
name|dlfunc
parameter_list|(
name|void
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dlinfo
parameter_list|(
name|void
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dllockinit
parameter_list|(
name|void
modifier|*
name|_context
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
name|_lock_create
function_decl|)
parameter_list|(
name|void
modifier|*
name|_context
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|_rlock_acquire
function_decl|)
parameter_list|(
name|void
modifier|*
name|_lock
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|_wlock_acquire
function_decl|)
parameter_list|(
name|void
modifier|*
name|_lock
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|_lock_release
function_decl|)
parameter_list|(
name|void
modifier|*
name|_lock
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|_lock_destroy
function_decl|)
parameter_list|(
name|void
modifier|*
name|_lock
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|_context_destroy
function_decl|)
parameter_list|(
name|void
modifier|*
name|_context
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

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

