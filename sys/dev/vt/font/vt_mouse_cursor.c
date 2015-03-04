begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Aleksandr Rybalko under sponsorship from the  * FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<dev/vt/vt.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SC_NO_CUTPASTE
end_ifndef

begin_decl_stmt
name|struct
name|vt_mouse_cursor
name|vt_default_mouse_pointer
init|=
block|{
operator|.
name|map
operator|=
block|{
literal|0x00
block|,
literal|0x00
block|,
comment|/* "__        " */
literal|0x40
block|,
literal|0x00
block|,
comment|/* "_*_       " */
literal|0x60
block|,
literal|0x00
block|,
comment|/* "_**_      " */
literal|0x70
block|,
literal|0x00
block|,
comment|/* "_***_     " */
literal|0x78
block|,
literal|0x00
block|,
comment|/* "_****_    " */
literal|0x7c
block|,
literal|0x00
block|,
comment|/* "_*****_   " */
literal|0x7e
block|,
literal|0x00
block|,
comment|/* "_******_  " */
literal|0x7f
block|,
literal|0x00
block|,
comment|/* "_*******_ " */
literal|0x7f
block|,
literal|0x80
block|,
comment|/* "_********_" */
literal|0x7c
block|,
literal|0x00
block|,
comment|/* "_*****____" */
literal|0x6c
block|,
literal|0x00
block|,
comment|/* "_**_**_   " */
literal|0x46
block|,
literal|0x00
block|,
comment|/* "_*_ _**_  " */
literal|0x06
block|,
literal|0x00
block|,
comment|/* "__  _**_  " */
literal|0x03
block|,
literal|0x00
block|,
comment|/* "     _**_ " */
literal|0x03
block|,
literal|0x00
block|,
comment|/* "     _**_ " */
literal|0x00
block|,
literal|0x00
block|,
comment|/* "      __  " */
block|}
block|,
operator|.
name|mask
operator|=
block|{
literal|0xc0
block|,
literal|0x00
block|,
comment|/* "__        " */
literal|0xe0
block|,
literal|0x00
block|,
comment|/* "___       " */
literal|0xf0
block|,
literal|0x00
block|,
comment|/* "____      " */
literal|0xf8
block|,
literal|0x00
block|,
comment|/* "_____     " */
literal|0xfc
block|,
literal|0x00
block|,
comment|/* "______    " */
literal|0xfe
block|,
literal|0x00
block|,
comment|/* "_______   " */
literal|0xff
block|,
literal|0x00
block|,
comment|/* "________  " */
literal|0xff
block|,
literal|0x80
block|,
comment|/* "_________ " */
literal|0xff
block|,
literal|0xc0
block|,
comment|/* "__________" */
literal|0xff
block|,
literal|0xc0
block|,
comment|/* "__________" */
literal|0xfe
block|,
literal|0x00
block|,
comment|/* "_______   " */
literal|0xef
block|,
literal|0x00
block|,
comment|/* "___ ____  " */
literal|0xcf
block|,
literal|0x00
block|,
comment|/* "__  ____  " */
literal|0x07
block|,
literal|0x80
block|,
comment|/* "     ____ " */
literal|0x07
block|,
literal|0x80
block|,
comment|/* "     ____ " */
literal|0x03
block|,
literal|0x00
block|,
comment|/* "      __  " */
block|}
block|,
operator|.
name|width
operator|=
literal|10
block|,
operator|.
name|height
operator|=
literal|16
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

