begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tdfx.h -- 3dfx DRM template customization -*- linux-c -*-  * Created: Wed Feb 14 12:32:32 2001 by gareth@valinux.com  *  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Gareth Hughes<gareth@valinux.com>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TDFX_H__
end_ifndef

begin_define
define|#
directive|define
name|__TDFX_H__
end_define

begin_comment
comment|/* This remains constant for all DRM template files.  */
end_comment

begin_define
define|#
directive|define
name|DRM
parameter_list|(
name|x
parameter_list|)
value|tdfx_##x
end_define

begin_comment
comment|/* General customization:  */
end_comment

begin_define
define|#
directive|define
name|__HAVE_MTRR
value|1
end_define

begin_define
define|#
directive|define
name|__HAVE_CTX_BITMAP
value|1
end_define

begin_define
define|#
directive|define
name|DRIVER_AUTHOR
value|"VA Linux Systems Inc."
end_define

begin_define
define|#
directive|define
name|DRIVER_NAME
value|"tdfx"
end_define

begin_define
define|#
directive|define
name|DRIVER_DESC
value|"3dfx Banshee/Voodoo3+"
end_define

begin_define
define|#
directive|define
name|DRIVER_DATE
value|"20010216"
end_define

begin_define
define|#
directive|define
name|DRIVER_MAJOR
value|1
end_define

begin_define
define|#
directive|define
name|DRIVER_MINOR
value|0
end_define

begin_define
define|#
directive|define
name|DRIVER_PATCHLEVEL
value|0
end_define

begin_define
define|#
directive|define
name|DRIVER_PCI_IDS
define|\
value|{0x121a, 0x0003, 0, "3dfx Voodoo Banshee"},			\ 	{0x121a, 0x0004, 0, "3dfx Voodoo3 2000"},			\ 	{0x121a, 0x0005, 0, "3dfx Voodoo3 3000"},			\ 	{0x121a, 0x0007, 0, "3dfx Voodoo4"},				\ 	{0x121a, 0x0009, 0, "3dfx Voodoo5"},				\ 	{0, 0, 0, NULL}
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

