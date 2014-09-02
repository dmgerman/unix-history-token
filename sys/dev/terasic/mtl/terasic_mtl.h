begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_TERASIC_MTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_TERASIC_MTL_H_
end_define

begin_struct
struct|struct
name|terasic_mtl_softc
block|{
comment|/* 	 * syscons requires that its video_adapter_t be at the front of the 	 * softc, so place syscons fields first, which we otherwise would 	 * probably not do. 	 */
name|video_adapter_t
name|mtl_va
decl_stmt|;
comment|/* 	 * Bus-related fields. 	 */
name|device_t
name|mtl_dev
decl_stmt|;
name|int
name|mtl_unit
decl_stmt|;
comment|/* 	 * The MTL driver doesn't require a lot of synchronisation; however, 	 * the lock is used to protect read-modify-write operations on MTL 	 * registers. 	 */
name|struct
name|mtx
name|mtl_lock
decl_stmt|;
comment|/* 	 * Control register device -- mappable from userspace. 	 */
name|struct
name|cdev
modifier|*
name|mtl_reg_cdev
decl_stmt|;
name|struct
name|resource
modifier|*
name|mtl_reg_res
decl_stmt|;
name|int
name|mtl_reg_rid
decl_stmt|;
comment|/* 	 * Graphics frame buffer device -- mappable from userspace. 	 */
name|struct
name|cdev
modifier|*
name|mtl_pixel_cdev
decl_stmt|;
name|struct
name|resource
modifier|*
name|mtl_pixel_res
decl_stmt|;
name|int
name|mtl_pixel_rid
decl_stmt|;
comment|/* 	 * Text frame buffer device -- mappable from userspace, and syscons 	 * hookup. 	 */
name|struct
name|cdev
modifier|*
name|mtl_text_cdev
decl_stmt|;
name|struct
name|resource
modifier|*
name|mtl_text_res
decl_stmt|;
name|int
name|mtl_text_rid
decl_stmt|;
name|uint16_t
modifier|*
name|mtl_text_soft
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TERASIC_MTL_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->mtl_lock)
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->mtl_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|mtx_destroy(&(sc)->mtl_lock)
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
value|mtx_init(&(sc)->mtl_lock,	\ 					    "terasic_mtl", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->mtl_lock)
end_define

begin_comment
comment|/*  * Constant properties of the MTL text frame buffer.  */
end_comment

begin_define
define|#
directive|define
name|TERASIC_MTL_COLS
value|100
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_ROWS
value|40
end_define

begin_comment
comment|/*  * MTL control register offsets.  */
end_comment

begin_define
define|#
directive|define
name|TERASIC_MTL_OFF_BLEND
value|0
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_OFF_TEXTCURSOR
value|4
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_OFF_TEXTFRAMEBUFADDR
value|8
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_OFF_TOUCHPOINT_X1
value|12
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_OFF_TOUCHPOINT_Y1
value|16
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_OFF_TOUCHPOINT_X2
value|20
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_OFF_TOUCHPOINT_Y2
value|24
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_OFF_TOUCHGESTURE
value|28
end_define

begin_comment
comment|/*  * Constants to help interpret various control registers.  */
end_comment

begin_define
define|#
directive|define
name|TERASIC_MTL_BLEND_DEFAULT_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_BLEND_DEFAULT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_BLEND_PIXEL_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_BLEND_PIXEL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_BLEND_TEXTFG_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_BLEND_TEXTFG_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_BLEND_TEXTBG_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_BLEND_TEXTBG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_TEXTCURSOR_COL_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_TEXTCURSOR_COL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_TEXTCURSOR_ROW_MASK
value|0xff
end_define

begin_comment
comment|/*  * Colours used both by VGA-like text rendering, and for the default display  * colour.  */
end_comment

begin_define
define|#
directive|define
name|TERASIC_MTL_COLOR_BLACK
value|0
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_COLOR_DARKBLUE
value|1
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_COLOR_DARKGREEN
value|2
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_COLOR_DARKCYAN
value|3
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_COLOR_DARKRED
value|4
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_COLOR_DARKMAGENTA
value|5
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_COLOR_BROWN
value|6
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_COLOR_LIGHTGREY
value|7
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_COLOR_DARKGREY
value|8
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_COLOR_LIGHTBLUE
value|9
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_COLOR_LIGHTGREEN
value|10
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_COLOR_LIGHTCYAN
value|11
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_COLOR_LIGHTRED
value|12
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_COLOR_LIGHTMAGENTA
value|13
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_COLOR_LIGHTYELLOW
value|14
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_COLOR_WHITE
value|15
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_COLORMASK_BLINK
value|0x80
end_define

begin_comment
comment|/*  * Constants to help interpret the text frame buffer.  */
end_comment

begin_define
define|#
directive|define
name|TERASIC_MTL_TEXTFRAMEBUF_EXPECTED_ADDR
value|0x0177000
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_TEXTFRAMEBUF_CHAR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_TEXTFRAMEBUF_ATTR_SHIFT
value|8
end_define

begin_comment
comment|/*  * Alpha-blending constants.  */
end_comment

begin_define
define|#
directive|define
name|TERASIC_MTL_ALPHA_TRANSPARENT
value|0
end_define

begin_define
define|#
directive|define
name|TERASIC_MTL_ALPHA_OPAQUE
value|255
end_define

begin_comment
comment|/*  * Driver setup routines from the bus attachment/teardown.  */
end_comment

begin_function_decl
name|int
name|terasic_mtl_attach
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terasic_mtl_detach
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|terasic_mtl_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Sub-driver setup routines.  */
end_comment

begin_function_decl
name|int
name|terasic_mtl_pixel_attach
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terasic_mtl_pixel_detach
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|terasic_mtl_reg_attach
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terasic_mtl_reg_detach
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|terasic_mtl_syscons_attach
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terasic_mtl_syscons_detach
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|terasic_mtl_text_attach
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terasic_mtl_text_detach
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Control register I/O routines.  */
end_comment

begin_function_decl
name|void
name|terasic_mtl_reg_blank
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terasic_mtl_reg_blend_get
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
modifier|*
name|blendp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terasic_mtl_reg_blend_set
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|blend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terasic_mtl_reg_textcursor_get
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
modifier|*
name|colp
parameter_list|,
name|uint8_t
modifier|*
name|rowp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terasic_mtl_reg_textcursor_set
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|col
parameter_list|,
name|uint8_t
name|row
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terasic_mtl_reg_textframebufaddr_get
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
modifier|*
name|addrp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terasic_mtl_reg_textframebufaddr_set
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Read-modify-write updates of sub-bytes of the blend register.  */
end_comment

begin_function_decl
name|void
name|terasic_mtl_blend_default_set
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|colour
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terasic_mtl_blend_pixel_set
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|alpha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terasic_mtl_blend_textfg_set
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|alpha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terasic_mtl_blend_textbg_set
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|alpha
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Text frame buffer I/O routines.  */
end_comment

begin_function_decl
name|void
name|terasic_mtl_text_putc
parameter_list|(
name|struct
name|terasic_mtl_softc
modifier|*
name|sc
parameter_list|,
name|u_int
name|x
parameter_list|,
name|u_int
name|y
parameter_list|,
name|uint8_t
name|c
parameter_list|,
name|uint8_t
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_TERASIC_MTL_H_ */
end_comment

end_unit

