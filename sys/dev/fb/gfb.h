begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * Copyright (c) 2000 Andrew Miklic  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FB_GFB_H_
end_ifndef

begin_define
define|#
directive|define
name|_FB_GFB_H_
end_define

begin_define
define|#
directive|define
name|MAX_NUM_GFB_CARDS
value|16
end_define

begin_define
define|#
directive|define
name|GFB_UNIT
parameter_list|(
name|dev
parameter_list|)
value|minor(dev)
end_define

begin_define
define|#
directive|define
name|GFB_MKMINOR
parameter_list|(
name|unit
parameter_list|)
value|(unit)
end_define

begin_define
define|#
directive|define
name|BIT_REVERSE
parameter_list|(
name|byte
parameter_list|)
define|\
value|((((byte)& 0x01)<< 7) |	\ 	 (((byte)& 0x02)<< 5) |	\ 	 (((byte)& 0x04)<< 3) |	\ 	 (((byte)& 0x08)<< 1) |	\ 	 (((byte)& 0x10)>> 1) |	\ 	 (((byte)& 0x20)>> 3) |	\ 	 (((byte)& 0x40)>> 5) |	\ 	 (((byte)& 0x80)>> 7))
end_define

begin_define
define|#
directive|define
name|probe_done
parameter_list|(
name|adp
parameter_list|)
value|((adp)->va_flags& V_ADP_PROBED)
end_define

begin_define
define|#
directive|define
name|init_done
parameter_list|(
name|adp
parameter_list|)
value|((adp)->va_flags& V_ADP_INITIALIZED)
end_define

begin_define
define|#
directive|define
name|config_done
parameter_list|(
name|adp
parameter_list|)
value|((adp)->va_flags& V_ADP_REGISTERED)
end_define

begin_struct_decl
struct_decl|struct
name|gfb_softc
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|gfb_error
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|vi_probe_t
name|gfb_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_init_t
name|gfb_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_get_info_t
name|gfb_get_info
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*vi_query_mode_t gfb_query_mode;*/
end_comment

begin_decl_stmt
name|vi_set_mode_t
name|gfb_set_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_save_font_t
name|gfb_save_font
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_load_font_t
name|gfb_load_font
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_show_font_t
name|gfb_show_font
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_save_palette_t
name|gfb_save_palette
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_load_palette_t
name|gfb_load_palette
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_save_state_t
name|gfb_save_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_load_state_t
name|gfb_load_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_read_hw_cursor_t
name|gfb_read_hw_cursor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_set_hw_cursor_t
name|gfb_set_hw_cursor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_set_hw_cursor_shape_t
name|gfb_set_hw_cursor_shape
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_mmap_t
name|gfb_mmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_ioctl_t
name|gfb_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_set_border_t
name|gfb_set_border
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_set_win_org_t
name|gfb_set_win_org
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_fill_rect_t
name|gfb_fill_rect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_bitblt_t
name|gfb_bitblt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_clear_t
name|gfb_clear
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_diag_t
name|gfb_diag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_save_cursor_palette_t
name|gfb_save_cursor_palette
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_load_cursor_palette_t
name|gfb_load_cursor_palette
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_copy_t
name|gfb_copy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_putp_t
name|gfb_putp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_putc_t
name|gfb_putc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_puts_t
name|gfb_puts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vi_putm_t
name|gfb_putm
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
name|gfb_ramdac_init_t
parameter_list|(
name|struct
name|gfb_softc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|u_int8_t
name|gfb_ramdac_rd_t
parameter_list|(
name|struct
name|gfb_softc
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|gfb_ramdac_wr_t
parameter_list|(
name|struct
name|gfb_softc
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|gfb_ramdac_intr_t
parameter_list|(
name|struct
name|gfb_softc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gfb_ramdac_save_palette_t
parameter_list|(
name|video_adapter_t
modifier|*
parameter_list|,
name|video_color_palette_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gfb_ramdac_load_palette_t
parameter_list|(
name|video_adapter_t
modifier|*
parameter_list|,
name|video_color_palette_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gfb_ramdac_save_cursor_palette_t
parameter_list|(
name|video_adapter_t
modifier|*
parameter_list|,
name|struct
name|fbcmap
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gfb_ramdac_load_cursor_palette_t
parameter_list|(
name|video_adapter_t
modifier|*
parameter_list|,
name|struct
name|fbcmap
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gfb_ramdac_read_hw_cursor_t
parameter_list|(
name|video_adapter_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gfb_ramdac_set_hw_cursor_t
parameter_list|(
name|video_adapter_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gfb_ramdac_set_hw_cursor_shape_t
parameter_list|(
name|video_adapter_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gfb_builtin_save_palette_t
parameter_list|(
name|video_adapter_t
modifier|*
parameter_list|,
name|video_color_palette_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gfb_builtin_load_palette_t
parameter_list|(
name|video_adapter_t
modifier|*
parameter_list|,
name|video_color_palette_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gfb_builtin_save_cursor_palette_t
parameter_list|(
name|video_adapter_t
modifier|*
parameter_list|,
name|struct
name|fbcmap
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gfb_builtin_load_cursor_palette_t
parameter_list|(
name|video_adapter_t
modifier|*
parameter_list|,
name|struct
name|fbcmap
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gfb_builtin_read_hw_cursor_t
parameter_list|(
name|video_adapter_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gfb_builtin_set_hw_cursor_t
parameter_list|(
name|video_adapter_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gfb_builtin_set_hw_cursor_shape_t
parameter_list|(
name|video_adapter_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|monitor
block|{
name|u_int16_t
name|cols
decl_stmt|;
comment|/* Columns */
name|u_int16_t
name|hfp
decl_stmt|;
comment|/* Horizontal Front Porch */
name|u_int16_t
name|hsync
decl_stmt|;
comment|/* Horizontal Sync */
name|u_int16_t
name|hbp
decl_stmt|;
comment|/* Horizontal Back Porch */
name|u_int16_t
name|rows
decl_stmt|;
comment|/* Rows */
name|u_int16_t
name|vfp
decl_stmt|;
comment|/* Vertical Front Porch */
name|u_int16_t
name|vsync
decl_stmt|;
comment|/* Vertical Sync */
name|u_int16_t
name|vbp
decl_stmt|;
comment|/* Vertical Back Porch */
name|u_int32_t
name|dotclock
decl_stmt|;
comment|/* Dot Clock */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gfb_font
block|{
name|int
name|width
decl_stmt|;
name|int
name|height
decl_stmt|;
name|u_char
name|data
index|[
literal|256
operator|*
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gfb_conf
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name for this board type */
name|char
modifier|*
name|ramdac_name
decl_stmt|;
comment|/* name for this RAMDAC */
name|u_char
modifier|*
name|font
decl_stmt|;
name|struct
name|gfb_font
name|fonts
index|[
literal|4
index|]
decl_stmt|;
name|video_color_palette_t
name|palette
decl_stmt|;
name|struct
name|fbcmap
name|cursor_palette
decl_stmt|;
name|gfb_ramdac_init_t
modifier|*
name|ramdac_init
decl_stmt|;
name|gfb_ramdac_rd_t
modifier|*
name|ramdac_rd
decl_stmt|;
name|gfb_ramdac_wr_t
modifier|*
name|ramdac_wr
decl_stmt|;
name|gfb_ramdac_intr_t
modifier|*
name|ramdac_intr
decl_stmt|;
name|gfb_ramdac_save_palette_t
modifier|*
name|ramdac_save_palette
decl_stmt|;
name|gfb_ramdac_load_palette_t
modifier|*
name|ramdac_load_palette
decl_stmt|;
name|gfb_ramdac_save_cursor_palette_t
modifier|*
name|ramdac_save_cursor_palette
decl_stmt|;
name|gfb_ramdac_load_cursor_palette_t
modifier|*
name|ramdac_load_cursor_palette
decl_stmt|;
name|gfb_ramdac_read_hw_cursor_t
modifier|*
name|ramdac_read_hw_cursor
decl_stmt|;
name|gfb_ramdac_set_hw_cursor_t
modifier|*
name|ramdac_set_hw_cursor
decl_stmt|;
name|gfb_ramdac_set_hw_cursor_shape_t
modifier|*
name|ramdac_set_hw_cursor_shape
decl_stmt|;
name|gfb_builtin_save_palette_t
modifier|*
name|builtin_save_palette
decl_stmt|;
name|gfb_builtin_load_palette_t
modifier|*
name|builtin_load_palette
decl_stmt|;
name|gfb_builtin_save_cursor_palette_t
modifier|*
name|builtin_save_cursor_palette
decl_stmt|;
name|gfb_builtin_load_cursor_palette_t
modifier|*
name|builtin_load_cursor_palette
decl_stmt|;
name|gfb_builtin_read_hw_cursor_t
modifier|*
name|builtin_read_hw_cursor
decl_stmt|;
name|gfb_builtin_set_hw_cursor_t
modifier|*
name|builtin_set_hw_cursor
decl_stmt|;
name|gfb_builtin_set_hw_cursor_shape_t
modifier|*
name|builtin_set_hw_cursor_shape
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|video_adapter
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|genfb_softc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|gfb_softc
block|{
name|char
modifier|*
name|driver_name
decl_stmt|;
comment|/* name for this driver */
name|struct
name|video_adapter
modifier|*
name|adp
decl_stmt|;
name|struct
name|genfb_softc
modifier|*
name|gensc
decl_stmt|;
name|struct
name|gfb_conf
modifier|*
name|gfbc
decl_stmt|;
name|bus_space_handle_t
name|bhandle
decl_stmt|;
name|bus_space_tag_t
name|btag
decl_stmt|;
name|bus_space_handle_t
name|regs
decl_stmt|;
name|void
modifier|*
name|intrhand
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|u_int8_t
name|rev
decl_stmt|;
comment|/* GFB revision */
name|int
name|type
decl_stmt|;
name|int
name|model
decl_stmt|;
name|struct
name|cdevsw
modifier|*
name|cdevsw
decl_stmt|;
name|dev_t
name|devt
decl_stmt|;
block|}
typedef|*
name|gfb_softc_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FB_GFB_H_ */
end_comment

end_unit

