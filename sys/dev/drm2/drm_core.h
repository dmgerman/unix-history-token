begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2004 Jon Smirl<jonsmirl@gmail.com>  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sub license,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL  * VIA, S3 GRAPHICS, AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
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

begin_define
define|#
directive|define
name|CORE_AUTHOR
value|"Gareth Hughes, Leif Delgass, JosÃ© Fonseca, Jon Smirl"
end_define

begin_define
define|#
directive|define
name|CORE_NAME
value|"drm"
end_define

begin_define
define|#
directive|define
name|CORE_DESC
value|"DRM shared core routines"
end_define

begin_define
define|#
directive|define
name|CORE_DATE
value|"20060810"
end_define

begin_define
define|#
directive|define
name|DRM_IF_MAJOR
value|1
end_define

begin_define
define|#
directive|define
name|DRM_IF_MINOR
value|4
end_define

begin_define
define|#
directive|define
name|CORE_MAJOR
value|1
end_define

begin_define
define|#
directive|define
name|CORE_MINOR
value|1
end_define

begin_define
define|#
directive|define
name|CORE_PATCHLEVEL
value|0
end_define

end_unit

