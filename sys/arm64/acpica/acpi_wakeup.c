begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Andrew Turner under  * sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acpi.h>
end_include

begin_include
include|#
directive|include
file|<dev/acpica/acpivar.h>
end_include

begin_comment
comment|/*  * ARM64TODO: Implement this.  */
end_comment

begin_function
name|int
name|acpi_sleep_machdep
parameter_list|(
name|struct
name|acpi_softc
modifier|*
name|sc
parameter_list|,
name|int
name|state
parameter_list|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
name|int
name|acpi_wakeup_machdep
parameter_list|(
name|struct
name|acpi_softc
modifier|*
name|sc
parameter_list|,
name|int
name|state
parameter_list|,
name|int
name|sleep_result
parameter_list|,
name|int
name|intr_enabled
parameter_list|)
block|{
comment|/* ARM64TODO: We will need this with acpi_sleep_machdep */
name|KASSERT
argument_list|(
name|sleep_result
operator|==
operator|-
literal|1
argument_list|,
operator|(
literal|"acpi_wakeup_machdep: Invalid sleep result"
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|sleep_result
operator|)
return|;
block|}
end_function

end_unit

