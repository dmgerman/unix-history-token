begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Google, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|"bootstrap.h"
end_include

begin_include
include|#
directive|include
file|"libuserboot.h"
end_include

begin_decl_stmt
name|int
name|console
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|console
modifier|*
name|userboot_comconsp
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|userboot_cons_probe
parameter_list|(
name|struct
name|console
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|userboot_cons_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|userboot_comcons_probe
parameter_list|(
name|struct
name|console
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|userboot_comcons_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|userboot_cons_putchar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|userboot_cons_getchar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|userboot_cons_poll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|console
name|userboot_console
init|=
block|{
literal|"userboot"
block|,
literal|"userboot"
block|,
literal|0
block|,
name|userboot_cons_probe
block|,
name|userboot_cons_init
block|,
name|userboot_cons_putchar
block|,
name|userboot_cons_getchar
block|,
name|userboot_cons_poll
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Provide a simple alias to allow loader scripts to set the  * console to comconsole without resulting in an error  */
end_comment

begin_decl_stmt
name|struct
name|console
name|userboot_comconsole
init|=
block|{
literal|"comconsole"
block|,
literal|"comconsole"
block|,
literal|0
block|,
name|userboot_comcons_probe
block|,
name|userboot_comcons_init
block|,
name|userboot_cons_putchar
block|,
name|userboot_cons_getchar
block|,
name|userboot_cons_poll
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|userboot_cons_probe
parameter_list|(
name|struct
name|console
modifier|*
name|cp
parameter_list|)
block|{
name|cp
operator|->
name|c_flags
operator||=
operator|(
name|C_PRESENTIN
operator||
name|C_PRESENTOUT
operator|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|userboot_cons_init
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|userboot_comcons_probe
parameter_list|(
name|struct
name|console
modifier|*
name|cp
parameter_list|)
block|{
comment|/* 	 * Save the console pointer so the comcons_init routine 	 * can set the C_PRESENT* flags. They are not set 	 * here to allow the existing userboot console to 	 * be elected the default. 	 */
name|userboot_comconsp
operator|=
name|cp
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|userboot_comcons_init
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
comment|/* 	 * Set the C_PRESENT* flags to allow the comconsole 	 * to be selected as the active console 	 */
name|userboot_comconsp
operator|->
name|c_flags
operator||=
operator|(
name|C_PRESENTIN
operator||
name|C_PRESENTOUT
operator|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|userboot_cons_putchar
parameter_list|(
name|int
name|c
parameter_list|)
block|{
name|CALLBACK
argument_list|(
name|putc
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|userboot_cons_getchar
parameter_list|()
block|{
return|return
operator|(
name|CALLBACK
argument_list|(
name|getc
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|userboot_cons_poll
parameter_list|()
block|{
return|return
operator|(
name|CALLBACK
argument_list|(
name|poll
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

