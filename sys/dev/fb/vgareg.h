begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Kazutaka YOKOTA<yokota@zodiac.mech.utsunomiya-u.ac.jp>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_FB_VGAREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_FB_VGAREG_H_
end_define

begin_comment
comment|/* physical addresses */
end_comment

begin_define
define|#
directive|define
name|MDA_BUF_BASE
value|0xb0000
end_define

begin_define
define|#
directive|define
name|MDA_BUF_SIZE
value|0x08000
end_define

begin_define
define|#
directive|define
name|MDA_BUF
value|BIOS_PADDRTOVADDR(MDA_BUF_BASE)
end_define

begin_define
define|#
directive|define
name|CGA_BUF_BASE
value|0xb8000
end_define

begin_define
define|#
directive|define
name|CGA_BUF_SIZE
value|0x08000
end_define

begin_define
define|#
directive|define
name|CGA_BUF
value|BIOS_PADDRTOVADDR(CGA_BUF_BASE)
end_define

begin_define
define|#
directive|define
name|EGA_BUF_BASE
value|0xa0000
end_define

begin_define
define|#
directive|define
name|EGA_BUF_SIZE
value|0x20000
end_define

begin_define
define|#
directive|define
name|EGA_BUF
value|BIOS_PADDRTOVADDR(EGA_BUF_BASE)
end_define

begin_define
define|#
directive|define
name|GRAPHICS_BUF_BASE
value|0xa0000
end_define

begin_define
define|#
directive|define
name|GRAPHICS_BUF_SIZE
value|0x10000
end_define

begin_define
define|#
directive|define
name|GRAPHICS_BUF
value|BIOS_PADDRTOVADDR(GRAPHICS_BUF_BASE)
end_define

begin_define
define|#
directive|define
name|FONT_BUF
value|BIOS_PADDRTOVADDR(GRAPHICS_BUF_BASE)
end_define

begin_define
define|#
directive|define
name|VIDEO_BUF_BASE
value|0xa0000
end_define

begin_define
define|#
directive|define
name|VIDEO_BUF_SIZE
value|0x20000
end_define

begin_comment
comment|/* I/O port addresses */
end_comment

begin_define
define|#
directive|define
name|MONO_CRTC
value|(IO_MDA + 0x04)
end_define

begin_comment
comment|/* crt controller base mono */
end_comment

begin_define
define|#
directive|define
name|COLOR_CRTC
value|(IO_CGA + 0x04)
end_define

begin_comment
comment|/* crt controller base color */
end_comment

begin_define
define|#
directive|define
name|MISC
value|(IO_VGA + 0x02)
end_define

begin_comment
comment|/* misc output register */
end_comment

begin_define
define|#
directive|define
name|ATC
value|(IO_VGA + 0x00)
end_define

begin_comment
comment|/* attribute controller */
end_comment

begin_define
define|#
directive|define
name|TSIDX
value|(IO_VGA + 0x04)
end_define

begin_comment
comment|/* timing sequencer idx */
end_comment

begin_define
define|#
directive|define
name|TSREG
value|(IO_VGA + 0x05)
end_define

begin_comment
comment|/* timing sequencer data */
end_comment

begin_define
define|#
directive|define
name|PIXMASK
value|(IO_VGA + 0x06)
end_define

begin_comment
comment|/* pixel write mask */
end_comment

begin_define
define|#
directive|define
name|PALRADR
value|(IO_VGA + 0x07)
end_define

begin_comment
comment|/* palette read address */
end_comment

begin_define
define|#
directive|define
name|PALWADR
value|(IO_VGA + 0x08)
end_define

begin_comment
comment|/* palette write address */
end_comment

begin_define
define|#
directive|define
name|PALDATA
value|(IO_VGA + 0x09)
end_define

begin_comment
comment|/* palette data register */
end_comment

begin_define
define|#
directive|define
name|GDCIDX
value|(IO_VGA + 0x0E)
end_define

begin_comment
comment|/* graph data controller idx */
end_comment

begin_define
define|#
directive|define
name|GDCREG
value|(IO_VGA + 0x0F)
end_define

begin_comment
comment|/* graph data controller data */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|vga_sub_configure
function_decl|)
parameter_list|(
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_FB_VGAREG_H_ */
end_comment

end_unit

