begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1992-2015 Michal Meloun  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TEGRA_DRM_H_
end_ifndef

begin_define
define|#
directive|define
name|_TEGRA_DRM_H_
end_define

begin_include
include|#
directive|include
file|<dev/gpio/gpiobusvar.h>
end_include

begin_struct
struct|struct
name|tegra_bo
block|{
name|struct
name|drm_gem_object
name|gem_obj
decl_stmt|;
comment|/* mapped memory buffer */
name|vm_paddr_t
name|pbase
decl_stmt|;
name|vm_offset_t
name|vbase
decl_stmt|;
name|size_t
name|npages
decl_stmt|;
name|vm_page_t
modifier|*
name|m
decl_stmt|;
name|vm_object_t
name|cdev_pager
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tegra_plane
block|{
name|struct
name|drm_plane
name|drm_plane
decl_stmt|;
name|int
name|index
decl_stmt|;
comment|/* Window index */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tegra_fb
block|{
name|struct
name|drm_framebuffer
name|drm_fb
decl_stmt|;
name|struct
name|drm_fb_helper
name|fb_helper
decl_stmt|;
name|struct
name|tegra_bo
modifier|*
modifier|*
name|planes
decl_stmt|;
comment|/* Attached planes */
name|int
name|nplanes
decl_stmt|;
comment|/* Surface and display geometry */
name|bool
name|block_linear
decl_stmt|;
comment|/* Surface_kind */
name|uint32_t
name|block_height
decl_stmt|;
name|int
name|rotation
decl_stmt|;
comment|/* In degrees */
name|bool
name|flip_x
decl_stmt|;
comment|/* Inverted X-axis */
name|bool
name|flip_y
decl_stmt|;
comment|/* Inverted Y-axis */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tegra_crtc
block|{
name|struct
name|drm_crtc
name|drm_crtc
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|int
name|nvidia_head
decl_stmt|;
name|vm_paddr_t
name|cursor_pbase
decl_stmt|;
comment|/* Cursor buffer */
name|vm_offset_t
name|cursor_vbase
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tegra_drm_encoder
block|{
name|device_t
name|dev
decl_stmt|;
name|void
modifier|*
name|panel
decl_stmt|;
comment|/* XXX For LVDS panel */
name|device_t
name|ddc
decl_stmt|;
name|struct
name|edid
modifier|*
name|edid
decl_stmt|;
name|gpio_pin_t
name|gpio_hpd
decl_stmt|;
name|struct
name|drm_encoder
name|encoder
decl_stmt|;
name|struct
name|drm_connector
name|connector
decl_stmt|;
name|int
function_decl|(
modifier|*
name|setup_clock
function_decl|)
parameter_list|(
name|struct
name|tegra_drm_encoder
modifier|*
name|output
parameter_list|,
name|clk_t
name|clk
parameter_list|,
name|uint64_t
name|pclk
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tegra_drm
block|{
name|struct
name|drm_device
name|drm_dev
decl_stmt|;
name|struct
name|tegra_fb
modifier|*
name|fb
decl_stmt|;
comment|/* Prime framebuffer */
name|int
name|pitch_align
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* tegra_drm_subr.c */
end_comment

begin_function_decl
name|int
name|tegra_drm_encoder_attach
parameter_list|(
name|struct
name|tegra_drm_encoder
modifier|*
name|output
parameter_list|,
name|phandle_t
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tegra_drm_encoder_init
parameter_list|(
name|struct
name|tegra_drm_encoder
modifier|*
name|output
parameter_list|,
name|struct
name|tegra_drm
modifier|*
name|drm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tegra_drm_encoder_exit
parameter_list|(
name|struct
name|tegra_drm_encoder
modifier|*
name|output
parameter_list|,
name|struct
name|tegra_drm
modifier|*
name|drm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|drm_connector_status
name|tegra_drm_connector_detect
parameter_list|(
name|struct
name|drm_connector
modifier|*
name|connector
parameter_list|,
name|bool
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tegra_drm_connector_get_modes
parameter_list|(
name|struct
name|drm_connector
modifier|*
name|connector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|drm_encoder
modifier|*
name|tegra_drm_connector_best_encoder
parameter_list|(
name|struct
name|drm_connector
modifier|*
name|connector
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* tegra_dc.c */
end_comment

begin_function_decl
name|void
name|tegra_dc_cancel_page_flip
parameter_list|(
name|struct
name|drm_crtc
modifier|*
name|drm_crtc
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tegra_dc_enable_vblank
parameter_list|(
name|struct
name|drm_crtc
modifier|*
name|drm_crtc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tegra_dc_disable_vblank
parameter_list|(
name|struct
name|drm_crtc
modifier|*
name|drm_crtc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tegra_dc_get_pipe
parameter_list|(
name|struct
name|drm_crtc
modifier|*
name|drm_crtc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* tegra_fb.c */
end_comment

begin_function_decl
name|struct
name|fb_info
modifier|*
name|tegra_drm_fb_getinfo
parameter_list|(
name|struct
name|drm_device
modifier|*
name|drm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tegra_bo
modifier|*
name|tegra_fb_get_plane
parameter_list|(
name|struct
name|tegra_fb
modifier|*
name|fb
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tegra_drm_fb_create
parameter_list|(
name|struct
name|drm_device
modifier|*
name|drm
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file
parameter_list|,
name|struct
name|drm_mode_fb_cmd2
modifier|*
name|cmd
parameter_list|,
name|struct
name|drm_framebuffer
modifier|*
modifier|*
name|fb_res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tegra_drm_fb_init
parameter_list|(
name|struct
name|drm_device
modifier|*
name|drm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tegra_drm_fb_destroy
parameter_list|(
name|struct
name|drm_device
modifier|*
name|drm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* tegra_bo.c */
end_comment

begin_struct_decl
struct_decl|struct
name|tegra_bo
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|tegra_bo_create
parameter_list|(
name|struct
name|drm_device
modifier|*
name|drm
parameter_list|,
name|size_t
name|size
parameter_list|,
name|struct
name|tegra_bo
modifier|*
modifier|*
name|res_bo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tegra_bo_driver_register
parameter_list|(
name|struct
name|drm_driver
modifier|*
name|drm_drv
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TEGRA_DRM_H_ */
end_comment

end_unit

