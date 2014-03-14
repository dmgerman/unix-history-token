begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009 Advanced Micro Devices, Inc.  * Copyright 2009 Red Hat Inc.  * Copyright 2012 Alcatel-Lucent, Inc.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RADEON_BLIT_COMMON_H__
end_ifndef

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
name|DI_PT_RECTLIST
value|0x11
end_define

begin_define
define|#
directive|define
name|DI_INDEX_SIZE_16_BIT
value|0x0
end_define

begin_define
define|#
directive|define
name|DI_SRC_SEL_AUTO_INDEX
value|0x2
end_define

begin_define
define|#
directive|define
name|FMT_8
value|0x1
end_define

begin_define
define|#
directive|define
name|FMT_5_6_5
value|0x8
end_define

begin_define
define|#
directive|define
name|FMT_8_8_8_8
value|0x1a
end_define

begin_define
define|#
directive|define
name|COLOR_8
value|0x1
end_define

begin_define
define|#
directive|define
name|COLOR_5_6_5
value|0x8
end_define

begin_define
define|#
directive|define
name|COLOR_8_8_8_8
value|0x1a
end_define

begin_define
define|#
directive|define
name|RECT_UNIT_H
value|32
end_define

begin_define
define|#
directive|define
name|RECT_UNIT_W
value|(RADEON_GPU_PAGE_SIZE / 4 / RECT_UNIT_H)
end_define

begin_define
define|#
directive|define
name|__RADEON_BLIT_COMMON_H__
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

