begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * 6.6 : Stream I/O  */
end_comment

begin_include
include|#
directive|include
file|"acpi.h"
end_include

begin_function
name|void
name|AcpiOsPrintf
parameter_list|(
specifier|const
name|NATIVE_CHAR
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|Format
argument_list|)
expr_stmt|;
name|vprintf
argument_list|(
name|Format
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|AcpiOsVprintf
parameter_list|(
specifier|const
name|NATIVE_CHAR
modifier|*
name|Format
parameter_list|,
name|va_list
name|Args
parameter_list|)
block|{
name|vprintf
argument_list|(
name|Format
argument_list|,
name|Args
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

