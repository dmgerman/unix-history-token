begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Mitsuru IWASAKI  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acpi.h>
end_include

begin_include
include|#
directive|include
file|<dev/acpica/acpivar.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|intr_model
init|=
name|ACPI_INTR_PIC
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|acpi_machdep_init
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|acpi_softc
modifier|*
name|sc
decl_stmt|;
name|sc
operator|=
name|devclass_get_softc
argument_list|(
name|devclass_find
argument_list|(
literal|"acpi"
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|acpi_install_wakeup_handler
argument_list|(
name|sc
argument_list|)
expr_stmt|;
if|if
condition|(
name|intr_model
operator|!=
name|ACPI_INTR_PIC
condition|)
name|acpi_SetIntrModel
argument_list|(
name|intr_model
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|acpi_SetDefaultIntrModel
parameter_list|(
name|int
name|model
parameter_list|)
block|{
name|intr_model
operator|=
name|model
expr_stmt|;
block|}
end_function

begin_function
name|int
name|acpi_machdep_quirks
parameter_list|(
name|int
modifier|*
name|quirks
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
name|void
name|acpi_cpu_c1
parameter_list|()
block|{
asm|__asm __volatile("sti; hlt");
block|}
end_function

end_unit

