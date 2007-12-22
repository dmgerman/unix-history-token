begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Kazutaka YOKOTA<yokota@zodiac.mech.utsunomiya-u.ac.jp>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_FB_FBREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_FB_FBREG_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|V_MAX_ADAPTERS
value|8
end_define

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/* some macros */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_define
define|#
directive|define
name|bcopy_io
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|generic_bcopy((void *)(s), (void *)(d), (c))
end_define

begin_define
define|#
directive|define
name|bcopy_toio
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|generic_bcopy((void *)(s), (void *)(d), (c))
end_define

begin_define
define|#
directive|define
name|bcopy_fromio
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|generic_bcopy((void *)(s), (void *)(d), (c))
end_define

begin_define
define|#
directive|define
name|bzero_io
parameter_list|(
name|d
parameter_list|,
name|c
parameter_list|)
value|generic_bzero((void *)(d), (c))
end_define

begin_define
define|#
directive|define
name|fill_io
parameter_list|(
name|p
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|fill((p), (void *)(d), (c))
end_define

begin_define
define|#
directive|define
name|fillw_io
parameter_list|(
name|p
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|fillw((p), (void *)(d), (c))
end_define

begin_function_decl
name|void
name|generic_bcopy
parameter_list|(
specifier|const
name|void
modifier|*
name|s
parameter_list|,
name|void
modifier|*
name|d
parameter_list|,
name|size_t
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|generic_bzero
parameter_list|(
name|void
modifier|*
name|d
parameter_list|,
name|size_t
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|bcopy_io
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|bcopy((void *)(s), (void *)(d), (c))
end_define

begin_define
define|#
directive|define
name|bcopy_toio
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|bcopy((void *)(s), (void *)(d), (c))
end_define

begin_define
define|#
directive|define
name|bcopy_fromio
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|bcopy((void *)(s), (void *)(d), (c))
end_define

begin_define
define|#
directive|define
name|bzero_io
parameter_list|(
name|d
parameter_list|,
name|c
parameter_list|)
value|bzero((void *)(d), (c))
end_define

begin_define
define|#
directive|define
name|fill_io
parameter_list|(
name|p
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|fill((p), (void *)(d), (c))
end_define

begin_define
define|#
directive|define
name|fillw_io
parameter_list|(
name|p
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|fillw((p), (void *)(d), (c))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ia64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc64__
argument_list|)
end_elif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_define
define|#
directive|define
name|bcopy_fromio
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_read_region_1(IA64_BUS_SPACE_MEM, s, 0, (void*)(d), c)
end_define

begin_define
define|#
directive|define
name|bcopy_io
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_copy_region_1(IA64_BUS_SPACE_MEM, s, 0, d, 0, c)
end_define

begin_define
define|#
directive|define
name|bcopy_toio
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_write_region_1(IA64_BUS_SPACE_MEM, d, 0, (void*)(s), c)
end_define

begin_define
define|#
directive|define
name|bzero_io
parameter_list|(
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_region_1(IA64_BUS_SPACE_MEM, (intptr_t)(d), 0, 0, c)
end_define

begin_define
define|#
directive|define
name|fill_io
parameter_list|(
name|p
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_region_1(IA64_BUS_SPACE_MEM, (intptr_t)(d), 0, p, c)
end_define

begin_define
define|#
directive|define
name|fillw_io
parameter_list|(
name|p
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_space_set_region_2(IA64_BUS_SPACE_MEM, (intptr_t)(d), 0, p, c)
end_define

begin_define
define|#
directive|define
name|readb
parameter_list|(
name|a
parameter_list|)
value|bus_space_read_1(IA64_BUS_SPACE_MEM, a, 0)
end_define

begin_define
define|#
directive|define
name|readw
parameter_list|(
name|a
parameter_list|)
value|bus_space_read_2(IA64_BUS_SPACE_MEM, a, 0)
end_define

begin_define
define|#
directive|define
name|writeb
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|bus_space_write_1(IA64_BUS_SPACE_MEM, a, 0, v)
end_define

begin_define
define|#
directive|define
name|writew
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|bus_space_write_2(IA64_BUS_SPACE_MEM, a, 0, v)
end_define

begin_define
define|#
directive|define
name|writel
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|bus_space_write_4(IA64_BUS_SPACE_MEM, a, 0, v)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ia64__ */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|fillw
parameter_list|(
name|int
name|val
parameter_list|,
name|uint16_t
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
while|while
condition|(
name|size
operator|--
condition|)
operator|*
name|buf
operator|++
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__powerpc__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|bcopy_io
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|ofwfb_bcopy((void *)(s), (void *)(d), (c))
end_define

begin_define
define|#
directive|define
name|bcopy_toio
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|ofwfb_bcopy((void *)(s), (void *)(d), (c))
end_define

begin_define
define|#
directive|define
name|bcopy_fromio
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|ofwfb_bcopy((void *)(s), (void *)(d), (c))
end_define

begin_define
define|#
directive|define
name|bzero_io
parameter_list|(
name|d
parameter_list|,
name|c
parameter_list|)
value|ofwfb_bzero((void *)(d), (c))
end_define

begin_define
define|#
directive|define
name|fillw
parameter_list|(
name|p
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|ofwfb_fillw((p), (void *)(d), (c))
end_define

begin_define
define|#
directive|define
name|fillw_io
parameter_list|(
name|p
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|ofwfb_fillw((p), (void *)(d), (c))
end_define

begin_define
define|#
directive|define
name|readw
parameter_list|(
name|a
parameter_list|)
value|ofwfb_readw((u_int16_t *)(a))
end_define

begin_define
define|#
directive|define
name|writew
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|ofwfb_writew((u_int16_t *)(a), (v))
end_define

begin_function_decl
name|void
name|ofwfb_bcopy
parameter_list|(
specifier|const
name|void
modifier|*
name|s
parameter_list|,
name|void
modifier|*
name|d
parameter_list|,
name|size_t
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ofwfb_bzero
parameter_list|(
name|void
modifier|*
name|d
parameter_list|,
name|size_t
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ofwfb_fillw
parameter_list|(
name|int
name|pat
parameter_list|,
name|void
modifier|*
name|base
parameter_list|,
name|size_t
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int16_t
name|ofwfb_readw
parameter_list|(
name|u_int16_t
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ofwfb_writew
parameter_list|(
name|u_int16_t
modifier|*
name|addr
parameter_list|,
name|u_int16_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__i386__&& !__amd64__&& !__ia64__&& !__sparc64__&& !__powerpc__ */
end_comment

begin_define
define|#
directive|define
name|bcopy_io
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|memcpy_io((d), (s), (c))
end_define

begin_define
define|#
directive|define
name|bcopy_toio
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|memcpy_toio((d), (void *)(s), (c))
end_define

begin_define
define|#
directive|define
name|bcopy_fromio
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|memcpy_fromio((void *)(d), (s), (c))
end_define

begin_define
define|#
directive|define
name|bzero_io
parameter_list|(
name|d
parameter_list|,
name|c
parameter_list|)
value|memset_io((d), 0, (c))
end_define

begin_define
define|#
directive|define
name|fill_io
parameter_list|(
name|p
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|memset_io((d), (p), (c))
end_define

begin_define
define|#
directive|define
name|fillw
parameter_list|(
name|p
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|memsetw((d), (p), (c))
end_define

begin_define
define|#
directive|define
name|fillw_io
parameter_list|(
name|p
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
value|memsetw_io((d), (p), (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__i386__ */
end_comment

begin_comment
comment|/* video function table */
end_comment

begin_typedef
typedef|typedef
name|int
name|vi_probe_t
parameter_list|(
name|int
name|unit
parameter_list|,
name|video_adapter_t
modifier|*
modifier|*
name|adpp
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_init_t
parameter_list|(
name|int
name|unit
parameter_list|,
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_get_info_t
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
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
name|video_adapter_t
modifier|*
name|adp
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
name|video_adapter_t
modifier|*
name|adp
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
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|int
name|page
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|width
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
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|int
name|page
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|width
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
name|video_adapter_t
modifier|*
name|adp
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
name|video_adapter_t
modifier|*
name|adp
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
name|video_adapter_t
modifier|*
name|adp
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
name|video_adapter_t
modifier|*
name|adp
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
name|video_adapter_t
modifier|*
name|adp
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
name|video_adapter_t
modifier|*
name|adp
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
name|video_adapter_t
modifier|*
name|adp
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
name|video_adapter_t
modifier|*
name|adp
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
name|video_adapter_t
modifier|*
name|adp
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
name|vi_set_hw_cursor_shape_t
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|int
name|base
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|celsize
parameter_list|,
name|int
name|blink
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_blank_display_t
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* defined in sys/fbio.h #define V_DISPLAY_ON		0 #define V_DISPLAY_BLANK		1 #define V_DISPLAY_STAND_BY	2 #define V_DISPLAY_SUSPEND	3 */
end_comment

begin_typedef
typedef|typedef
name|int
name|vi_mmap_t
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|vm_offset_t
name|offset
parameter_list|,
name|vm_paddr_t
modifier|*
name|paddr
parameter_list|,
name|int
name|prot
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_ioctl_t
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_clear_t
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_fill_rect_t
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|int
name|val
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|cx
parameter_list|,
name|int
name|cy
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_bitblt_t
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_diag_t
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|int
name|level
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_save_cursor_palette_t
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
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
name|vi_load_cursor_palette_t
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
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
name|vi_copy_t
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|vm_offset_t
name|src
parameter_list|,
name|vm_offset_t
name|dst
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_putp_t
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|vm_offset_t
name|off
parameter_list|,
name|u_int32_t
name|p
parameter_list|,
name|u_int32_t
name|a
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|bpp
parameter_list|,
name|int
name|bit_ltor
parameter_list|,
name|int
name|byte_ltor
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_putc_t
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|vm_offset_t
name|off
parameter_list|,
name|u_int8_t
name|c
parameter_list|,
name|u_int8_t
name|a
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_puts_t
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|vm_offset_t
name|off
parameter_list|,
name|u_int16_t
modifier|*
name|s
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vi_putm_t
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|u_int8_t
modifier|*
name|pixel_image
parameter_list|,
name|u_int32_t
name|pixel_mask
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|video_switch
block|{
name|vi_probe_t
modifier|*
name|probe
decl_stmt|;
name|vi_init_t
modifier|*
name|init
decl_stmt|;
name|vi_get_info_t
modifier|*
name|get_info
decl_stmt|;
name|vi_query_mode_t
modifier|*
name|query_mode
decl_stmt|;
name|vi_set_mode_t
modifier|*
name|set_mode
decl_stmt|;
name|vi_save_font_t
modifier|*
name|save_font
decl_stmt|;
name|vi_load_font_t
modifier|*
name|load_font
decl_stmt|;
name|vi_show_font_t
modifier|*
name|show_font
decl_stmt|;
name|vi_save_palette_t
modifier|*
name|save_palette
decl_stmt|;
name|vi_load_palette_t
modifier|*
name|load_palette
decl_stmt|;
name|vi_set_border_t
modifier|*
name|set_border
decl_stmt|;
name|vi_save_state_t
modifier|*
name|save_state
decl_stmt|;
name|vi_load_state_t
modifier|*
name|load_state
decl_stmt|;
name|vi_set_win_org_t
modifier|*
name|set_win_org
decl_stmt|;
name|vi_read_hw_cursor_t
modifier|*
name|read_hw_cursor
decl_stmt|;
name|vi_set_hw_cursor_t
modifier|*
name|set_hw_cursor
decl_stmt|;
name|vi_set_hw_cursor_shape_t
modifier|*
name|set_hw_cursor_shape
decl_stmt|;
name|vi_blank_display_t
modifier|*
name|blank_display
decl_stmt|;
name|vi_mmap_t
modifier|*
name|mmap
decl_stmt|;
name|vi_ioctl_t
modifier|*
name|ioctl
decl_stmt|;
name|vi_clear_t
modifier|*
name|clear
decl_stmt|;
name|vi_fill_rect_t
modifier|*
name|fill_rect
decl_stmt|;
name|vi_bitblt_t
modifier|*
name|bitblt
decl_stmt|;
name|int
function_decl|(
modifier|*
name|reserved1
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|reserved2
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|vi_diag_t
modifier|*
name|diag
decl_stmt|;
name|vi_save_cursor_palette_t
modifier|*
name|save_cursor_palette
decl_stmt|;
name|vi_load_cursor_palette_t
modifier|*
name|load_cursor_palette
decl_stmt|;
name|vi_copy_t
modifier|*
name|copy
decl_stmt|;
name|vi_putp_t
modifier|*
name|putp
decl_stmt|;
name|vi_putc_t
modifier|*
name|putc
decl_stmt|;
name|vi_puts_t
modifier|*
name|puts
decl_stmt|;
name|vi_putm_t
modifier|*
name|putm
decl_stmt|;
block|}
name|video_switch_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|save_palette
parameter_list|(
name|adp
parameter_list|,
name|pal
parameter_list|)
define|\
value|(*vidsw[(adp)->va_index]->save_palette)((adp), (pal))
end_define

begin_define
define|#
directive|define
name|load_palette
parameter_list|(
name|adp
parameter_list|,
name|pal
parameter_list|)
define|\
value|(*vidsw[(adp)->va_index]->load_palette)((adp), (pal))
end_define

begin_define
define|#
directive|define
name|get_mode_info
parameter_list|(
name|adp
parameter_list|,
name|mode
parameter_list|,
name|buf
parameter_list|)
define|\
value|(*vidsw[(adp)->va_index]->get_info)((adp), (mode), (buf))
end_define

begin_define
define|#
directive|define
name|set_video_mode
parameter_list|(
name|adp
parameter_list|,
name|mode
parameter_list|)
define|\
value|(*vidsw[(adp)->va_index]->set_mode)((adp), (mode))
end_define

begin_define
define|#
directive|define
name|set_border
parameter_list|(
name|adp
parameter_list|,
name|border
parameter_list|)
define|\
value|(*vidsw[(adp)->va_index]->set_border)((adp), (border))
end_define

begin_define
define|#
directive|define
name|set_origin
parameter_list|(
name|adp
parameter_list|,
name|o
parameter_list|)
define|\
value|(*vidsw[(adp)->va_index]->set_win_org)(adp, o)
end_define

begin_comment
comment|/* XXX - add more macros */
end_comment

begin_comment
comment|/* video driver */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|video_driver
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|video_switch_t
modifier|*
name|vidsw
decl_stmt|;
name|int
function_decl|(
modifier|*
name|configure
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/* backdoor for the console driver */
block|}
name|video_driver_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VIDEO_DRIVER
parameter_list|(
name|name
parameter_list|,
name|sw
parameter_list|,
name|config
parameter_list|)
define|\
value|static struct video_driver name##_driver = {	\ 		#name,&sw, config			\ 	};						\ 	DATA_SET(videodriver_set, name##_driver);
end_define

begin_comment
comment|/* global variables */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|video_switch
modifier|*
modifier|*
name|vidsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* functions for the video card driver */
end_comment

begin_function_decl
name|int
name|vid_register
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vid_unregister
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|video_switch_t
modifier|*
name|vid_get_switch
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vid_init_struct
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* functions for the video card client */
end_comment

begin_function_decl
name|int
name|vid_allocate
parameter_list|(
name|char
modifier|*
name|driver
parameter_list|,
name|int
name|unit
parameter_list|,
name|void
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vid_release
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|void
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vid_find_adapter
parameter_list|(
name|char
modifier|*
name|driver
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|video_adapter_t
modifier|*
name|vid_get_adapter
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* a backdoor for the console driver to tickle the video driver XXX */
end_comment

begin_function_decl
name|int
name|vid_configure
parameter_list|(
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|VIO_PROBE_ONLY
value|(1<< 0)
end_define

begin_comment
comment|/* probe only, don't initialize */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FB_INSTALL_CDEV
end_ifdef

begin_comment
comment|/* virtual frame buffer driver functions */
end_comment

begin_function_decl
name|int
name|fb_attach
parameter_list|(
name|int
name|unit
parameter_list|,
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|struct
name|cdevsw
modifier|*
name|cdevsw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fb_detach
parameter_list|(
name|int
name|unit
parameter_list|,
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|struct
name|cdevsw
modifier|*
name|cdevsw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* generic frame buffer cdev driver functions */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|genfb_softc
block|{
name|int
name|gfb_flags
decl_stmt|;
comment|/* flag/status bits */
define|#
directive|define
name|FB_OPEN
value|(1<< 0)
block|}
name|genfb_softc_t
typedef|;
end_typedef

begin_function_decl
name|int
name|genfbopen
parameter_list|(
name|genfb_softc_t
modifier|*
name|sc
parameter_list|,
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|int
name|flag
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|genfbclose
parameter_list|(
name|genfb_softc_t
modifier|*
name|sc
parameter_list|,
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|int
name|flag
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|genfbread
parameter_list|(
name|genfb_softc_t
modifier|*
name|sc
parameter_list|,
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|genfbwrite
parameter_list|(
name|genfb_softc_t
modifier|*
name|sc
parameter_list|,
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|genfbioctl
parameter_list|(
name|genfb_softc_t
modifier|*
name|sc
parameter_list|,
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|arg
parameter_list|,
name|int
name|flag
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|genfbmmap
parameter_list|(
name|genfb_softc_t
modifier|*
name|sc
parameter_list|,
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|vm_offset_t
name|offset
parameter_list|,
name|vm_offset_t
modifier|*
name|paddr
parameter_list|,
name|int
name|prot
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FB_INSTALL_CDEV */
end_comment

begin_comment
comment|/* generic low-level driver functions */
end_comment

begin_function_decl
name|void
name|fb_dump_adp_info
parameter_list|(
name|char
modifier|*
name|driver
parameter_list|,
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fb_dump_mode_info
parameter_list|(
name|char
modifier|*
name|driver
parameter_list|,
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|video_info_t
modifier|*
name|info
parameter_list|,
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fb_type
parameter_list|(
name|int
name|adp_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fb_commonioctl
parameter_list|(
name|video_adapter_t
modifier|*
name|adp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_FB_FBREG_H_ */
end_comment

end_unit

