begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Kazutaka YOKOTA<yokota@zodiac.mech.utsunomiya-u.ac.jp>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $Id: videoio.h,v 1.1 1998/09/15 18:16:38 sos Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_VIDEOIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_ISA_VIDEOIO_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|V_MAX_ADAPTERS
value|2
end_define

begin_define
define|#
directive|define
name|V_MODE_MAP_SIZE
value|(M_VGA_CG320 + 1)
end_define

begin_define
define|#
directive|define
name|V_MODE_PARAM_SIZE
value|64
end_define

begin_comment
comment|/* physical addresses */
end_comment

begin_define
define|#
directive|define
name|MONO_BUF
value|BIOS_PADDRTOVADDR(0xb0000)
end_define

begin_define
define|#
directive|define
name|CGA_BUF
value|BIOS_PADDRTOVADDR(0xb8000)
end_define

begin_define
define|#
directive|define
name|GRAPHICS_BUF
value|BIOS_PADDRTOVADDR(0xa0000)
end_define

begin_define
define|#
directive|define
name|VIDEOMEM
value|0x000A0000
end_define

begin_comment
comment|/* I/O port addresses */
end_comment

begin_define
define|#
directive|define
name|MONO_BASE
value|0x3B4
end_define

begin_comment
comment|/* crt controller base mono */
end_comment

begin_define
define|#
directive|define
name|COLOR_BASE
value|0x3D4
end_define

begin_comment
comment|/* crt controller base color */
end_comment

begin_define
define|#
directive|define
name|MISC
value|0x3C2
end_define

begin_comment
comment|/* misc output register */
end_comment

begin_define
define|#
directive|define
name|ATC
value|IO_VGA+0x00
end_define

begin_comment
comment|/* attribute controller */
end_comment

begin_define
define|#
directive|define
name|TSIDX
value|IO_VGA+0x04
end_define

begin_comment
comment|/* timing sequencer idx */
end_comment

begin_define
define|#
directive|define
name|TSREG
value|IO_VGA+0x05
end_define

begin_comment
comment|/* timing sequencer data */
end_comment

begin_define
define|#
directive|define
name|PIXMASK
value|IO_VGA+0x06
end_define

begin_comment
comment|/* pixel write mask */
end_comment

begin_define
define|#
directive|define
name|PALRADR
value|IO_VGA+0x07
end_define

begin_comment
comment|/* palette read address */
end_comment

begin_define
define|#
directive|define
name|PALWADR
value|IO_VGA+0x08
end_define

begin_comment
comment|/* palette write address */
end_comment

begin_define
define|#
directive|define
name|PALDATA
value|IO_VGA+0x09
end_define

begin_comment
comment|/* palette data register */
end_comment

begin_define
define|#
directive|define
name|GDCIDX
value|IO_VGA+0x0E
end_define

begin_comment
comment|/* graph data controller idx */
end_comment

begin_define
define|#
directive|define
name|GDCREG
value|IO_VGA+0x0F
end_define

begin_comment
comment|/* graph data controller data */
end_comment

begin_comment
comment|/* video function table */
end_comment

begin_typedef
typedef|typedef
name|int
name|vi_init_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|video_adapter_t
modifier|*
name|vi_adapter_t
parameter_list|(
name|int
name|ad
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_get_info_t
parameter_list|(
name|int
name|ad
parameter_list|,
name|int
name|mode
parameter_list|,
name|video_info_t
modifier|*
name|info
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_query_mode_t
parameter_list|(
name|int
name|ad
parameter_list|,
name|video_info_t
modifier|*
name|info
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_set_mode_t
parameter_list|(
name|int
name|ad
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_save_font_t
parameter_list|(
name|int
name|ad
parameter_list|,
name|int
name|page
parameter_list|,
name|int
name|size
parameter_list|,
name|u_char
modifier|*
name|data
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_load_font_t
parameter_list|(
name|int
name|ad
parameter_list|,
name|int
name|page
parameter_list|,
name|int
name|size
parameter_list|,
name|u_char
modifier|*
name|data
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_show_font_t
parameter_list|(
name|int
name|ad
parameter_list|,
name|int
name|page
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_save_palette_t
parameter_list|(
name|int
name|ad
parameter_list|,
name|u_char
modifier|*
name|palette
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_load_palette_t
parameter_list|(
name|int
name|ad
parameter_list|,
name|u_char
modifier|*
name|palette
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_set_border_t
parameter_list|(
name|int
name|ad
parameter_list|,
name|int
name|border
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_save_state_t
parameter_list|(
name|int
name|ad
parameter_list|,
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_load_state_t
parameter_list|(
name|int
name|ad
parameter_list|,
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_set_win_org_t
parameter_list|(
name|int
name|ad
parameter_list|,
name|off_t
name|offset
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_read_hw_cursor_t
parameter_list|(
name|int
name|ad
parameter_list|,
name|int
modifier|*
name|col
parameter_list|,
name|int
modifier|*
name|row
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_set_hw_cursor_t
parameter_list|(
name|int
name|ad
parameter_list|,
name|int
name|col
parameter_list|,
name|int
name|row
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_diag_t
parameter_list|(
name|int
name|level
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|vidsw
block|{
name|vi_init_t
modifier|*
name|init
decl_stmt|;
comment|/* all */
name|vi_adapter_t
modifier|*
name|adapter
decl_stmt|;
comment|/* all */
name|vi_get_info_t
modifier|*
name|get_info
decl_stmt|;
comment|/* all */
name|vi_query_mode_t
modifier|*
name|query_mode
decl_stmt|;
comment|/* all */
name|vi_set_mode_t
modifier|*
name|set_mode
decl_stmt|;
comment|/* EGA/VGA */
name|vi_save_font_t
modifier|*
name|save_font
decl_stmt|;
comment|/* EGA/VGA */
name|vi_load_font_t
modifier|*
name|load_font
decl_stmt|;
comment|/* EGA/VGA */
name|vi_show_font_t
modifier|*
name|show_font
decl_stmt|;
comment|/* EGA/VGA */
name|vi_save_palette_t
modifier|*
name|save_palette
decl_stmt|;
comment|/* VGA */
name|vi_load_palette_t
modifier|*
name|load_palette
decl_stmt|;
comment|/* VGA */
name|vi_set_border_t
modifier|*
name|set_border
decl_stmt|;
comment|/* CGA/EGA/VGA */
name|vi_save_state_t
modifier|*
name|save_state
decl_stmt|;
comment|/* VGA */
name|vi_load_state_t
modifier|*
name|load_state
decl_stmt|;
comment|/* EGA/VGA */
name|vi_set_win_org_t
modifier|*
name|set_win_org
decl_stmt|;
comment|/* all */
name|vi_read_hw_cursor_t
modifier|*
name|read_hw_cursor
decl_stmt|;
comment|/* all */
name|vi_set_hw_cursor_t
modifier|*
name|set_hw_cursor
decl_stmt|;
comment|/* all */
name|vi_diag_t
modifier|*
name|diag
decl_stmt|;
comment|/* all */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vidsw
name|biosvidsw
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_I386_ISA_VIDEOIO_H_ */
end_comment

end_unit

