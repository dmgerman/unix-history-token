begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 John D. Polstra  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: dlfcn.c,v 1.1 1998/02/09 06:05:24 jdp Exp $  */
end_comment

begin_comment
comment|/*  * Linkage to services provided by the dynamic linker.  These are  * implemented differently in ELF and a.out, because the dynamic  * linkers have different interfaces.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

begin_include
include|#
directive|include
file|<dlfcn.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
name|sorry
index|[]
init|=
literal|"Service unavailable"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * For ELF, the dynamic linker directly resolves references to its  * services to functions inside the dynamic linker itself.  These  * weak-symbol stubs are necessary so that "ld" won't complain about  * undefined symbols.  The stubs are executed only when the program is  * linked statically, or when a given service isn't implemented in the  * dynamic linker.  They must return an error if called, and they must  * be weak symbols so that the dynamic linker can override them.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|_rtld_error
end_pragma

begin_function
name|void
name|_rtld_error
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{ }
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|dladdr
end_pragma

begin_function
name|int
name|dladdr
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|,
name|Dl_info
modifier|*
name|dlip
parameter_list|)
block|{
name|_rtld_error
argument_list|(
name|sorry
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|dlclose
end_pragma

begin_function
name|int
name|dlclose
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
block|{
name|_rtld_error
argument_list|(
name|sorry
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|dlerror
end_pragma

begin_function
specifier|const
name|char
modifier|*
name|dlerror
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|sorry
return|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|dlopen
end_pragma

begin_function
name|void
modifier|*
name|dlopen
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|mode
parameter_list|)
block|{
name|_rtld_error
argument_list|(
name|sorry
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|dlsym
end_pragma

begin_function
name|void
modifier|*
name|dlsym
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|_rtld_error
argument_list|(
name|sorry
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* a.out format */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<nlist.h>
end_include

begin_comment
comment|/* XXX - Required by link.h */
end_comment

begin_include
include|#
directive|include
file|<dlfcn.h>
end_include

begin_include
include|#
directive|include
file|<link.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/*  * For a.out, entry to the dynamic linker is via these trampolines.  * They enter the dynamic linker through the ld_entry struct that was  * passed back from the dynamic linker at startup time.  */
end_comment

begin_comment
comment|/* GCC is needed because we use its __builtin_return_address construct. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_error
error|#
directive|error
literal|"GCC is needed to compile this file"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * These variables are set by code in crt0.o.  For compatibility with  * old executables, they must be common, not extern.  */
end_comment

begin_decl_stmt
name|struct
name|ld_entry
modifier|*
name|__ldso_entry
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Entry points to dynamic linker */
end_comment

begin_decl_stmt
name|int
name|__ldso_version
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dynamic linker version number */
end_comment

begin_function
name|int
name|dladdr
parameter_list|(
specifier|const
name|void
modifier|*
name|addr
parameter_list|,
name|Dl_info
modifier|*
name|dlip
parameter_list|)
block|{
if|if
condition|(
name|__ldso_entry
operator|==
name|NULL
operator|||
name|__ldso_version
operator|<
name|LDSO_VERSION_HAS_DLADDR
condition|)
return|return
literal|0
return|;
return|return
call|(
name|__ldso_entry
operator|->
name|dladdr
call|)
argument_list|(
name|addr
argument_list|,
name|dlip
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|dlclose
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
block|{
if|if
condition|(
name|__ldso_entry
operator|==
name|NULL
condition|)
return|return
operator|-
literal|1
return|;
return|return
call|(
name|__ldso_entry
operator|->
name|dlclose
call|)
argument_list|(
name|handle
argument_list|)
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|dlerror
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|__ldso_entry
operator|==
name|NULL
condition|)
return|return
literal|"Service unavailable"
return|;
return|return
call|(
name|__ldso_entry
operator|->
name|dlerror
call|)
argument_list|()
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|dlopen
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|mode
parameter_list|)
block|{
if|if
condition|(
name|__ldso_entry
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
return|return
call|(
name|__ldso_entry
operator|->
name|dlopen
call|)
argument_list|(
name|name
argument_list|,
name|mode
argument_list|)
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|dlsym
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
if|if
condition|(
name|__ldso_entry
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
if|if
condition|(
name|__ldso_version
operator|>=
name|LDSO_VERSION_HAS_DLSYM3
condition|)
block|{
name|void
modifier|*
name|retaddr
init|=
name|__builtin_return_address
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|/* __GNUC__ only */
return|return
call|(
name|__ldso_entry
operator|->
name|dlsym3
call|)
argument_list|(
name|handle
argument_list|,
name|name
argument_list|,
name|retaddr
argument_list|)
return|;
block|}
else|else
return|return
call|(
name|__ldso_entry
operator|->
name|dlsym
call|)
argument_list|(
name|handle
argument_list|,
name|name
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ELF__ */
end_comment

end_unit

