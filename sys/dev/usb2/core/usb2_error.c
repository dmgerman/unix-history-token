begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<dev/usb2/include/usb2_mfunc.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb2/include/usb2_error.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb2/core/usb2_core.h>
end_include

begin_expr_stmt
name|USB_MAKE_DEBUG_TABLE
argument_list|(
name|USB_ERR
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*------------------------------------------------------------------------*  *	usb2_errstr  *  * This function converts an USB error code into a string.  *------------------------------------------------------------------------*/
end_comment

begin_function
specifier|const
name|char
modifier|*
name|usb2_errstr
parameter_list|(
name|usb2_error_t
name|err
parameter_list|)
block|{
return|return
operator|(
operator|(
name|err
operator|<
name|USB_ERR_MAX
operator|)
condition|?
name|USB_ERR
index|[
name|err
index|]
else|:
literal|"USB_ERR_UNKNOWN"
operator|)
return|;
block|}
end_function

end_unit

