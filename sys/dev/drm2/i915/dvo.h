begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright Â© 2006 Eric Anholt  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that copyright  * notice and this permission notice appear in supporting documentation, and  * that the name of the copyright holders not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  The copyright holders make no representations  * about the suitability of this software for any purpose.  It is provided "as  * is" without express or implied warranty.  *  * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO  * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,  * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER  * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE  * OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INTEL_DVO_H
end_ifndef

begin_define
define|#
directive|define
name|_INTEL_DVO_H
end_define

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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/iicbus/iic.h>
end_include

begin_include
include|#
directive|include
file|<dev/iicbus/iiconf.h>
end_include

begin_include
include|#
directive|include
file|<dev/drm2/drmP.h>
end_include

begin_include
include|#
directive|include
file|<dev/drm2/drm_crtc.h>
end_include

begin_include
include|#
directive|include
file|"intel_drv.h"
end_include

begin_struct
struct|struct
name|intel_dvo_device
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|type
decl_stmt|;
comment|/* DVOA/B/C output register */
name|u32
name|dvo_reg
decl_stmt|;
comment|/* GPIO register used for i2c bus to control this device */
name|u32
name|gpio
decl_stmt|;
name|int
name|slave_addr
decl_stmt|;
specifier|const
name|struct
name|intel_dvo_dev_ops
modifier|*
name|dev_ops
decl_stmt|;
name|void
modifier|*
name|dev_priv
decl_stmt|;
name|device_t
name|i2c_bus
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|intel_dvo_dev_ops
block|{
comment|/* 	 * Initialize the device at startup time. 	 * Returns NULL if the device does not exist. 	 */
name|bool
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|intel_dvo_device
modifier|*
name|dvo
parameter_list|,
name|device_t
name|i2cbus
parameter_list|)
function_decl|;
comment|/* 	 * Called to allow the output a chance to create properties after the 	 * RandR objects have been created. 	 */
name|void
function_decl|(
modifier|*
name|create_resources
function_decl|)
parameter_list|(
name|struct
name|intel_dvo_device
modifier|*
name|dvo
parameter_list|)
function_decl|;
comment|/* 	 * Turn on/off output. 	 * 	 * Because none of our dvo drivers support an intermediate power levels, 	 * we don't expose this in the interfac. 	 */
name|void
function_decl|(
modifier|*
name|dpms
function_decl|)
parameter_list|(
name|struct
name|intel_dvo_device
modifier|*
name|dvo
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
comment|/* 	 * Callback for testing a video mode for a given output. 	 * 	 * This function should only check for cases where a mode can't 	 * be supported on the output specifically, and not represent 	 * generic CRTC limitations. 	 * 	 * \return MODE_OK if the mode is valid, or another MODE_* otherwise. 	 */
name|int
function_decl|(
modifier|*
name|mode_valid
function_decl|)
parameter_list|(
name|struct
name|intel_dvo_device
modifier|*
name|dvo
parameter_list|,
name|struct
name|drm_display_mode
modifier|*
name|mode
parameter_list|)
function_decl|;
comment|/* 	 * Callback to adjust the mode to be set in the CRTC. 	 * 	 * This allows an output to adjust the clock or even the entire set of 	 * timings, which is used for panels with fixed timings or for 	 * buses with clock limitations. 	 */
name|bool
function_decl|(
modifier|*
name|mode_fixup
function_decl|)
parameter_list|(
name|struct
name|intel_dvo_device
modifier|*
name|dvo
parameter_list|,
specifier|const
name|struct
name|drm_display_mode
modifier|*
name|mode
parameter_list|,
name|struct
name|drm_display_mode
modifier|*
name|adjusted_mode
parameter_list|)
function_decl|;
comment|/* 	 * Callback for preparing mode changes on an output 	 */
name|void
function_decl|(
modifier|*
name|prepare
function_decl|)
parameter_list|(
name|struct
name|intel_dvo_device
modifier|*
name|dvo
parameter_list|)
function_decl|;
comment|/* 	 * Callback for committing mode changes on an output 	 */
name|void
function_decl|(
modifier|*
name|commit
function_decl|)
parameter_list|(
name|struct
name|intel_dvo_device
modifier|*
name|dvo
parameter_list|)
function_decl|;
comment|/* 	 * Callback for setting up a video mode after fixups have been made. 	 * 	 * This is only called while the output is disabled.  The dpms callback 	 * must be all that's necessary for the output, to turn the output on 	 * after this function is called. 	 */
name|void
function_decl|(
modifier|*
name|mode_set
function_decl|)
parameter_list|(
name|struct
name|intel_dvo_device
modifier|*
name|dvo
parameter_list|,
name|struct
name|drm_display_mode
modifier|*
name|mode
parameter_list|,
name|struct
name|drm_display_mode
modifier|*
name|adjusted_mode
parameter_list|)
function_decl|;
comment|/* 	 * Probe for a connected output, and return detect_status. 	 */
name|enum
name|drm_connector_status
function_decl|(
modifier|*
name|detect
function_decl|)
parameter_list|(
name|struct
name|intel_dvo_device
modifier|*
name|dvo
parameter_list|)
function_decl|;
comment|/* 	 * Probe the current hw status, returning true if the connected output 	 * is active. 	 */
name|bool
function_decl|(
modifier|*
name|get_hw_state
function_decl|)
parameter_list|(
name|struct
name|intel_dvo_device
modifier|*
name|dev
parameter_list|)
function_decl|;
comment|/** 	 * Query the device for the modes it provides. 	 * 	 * This function may also update MonInfo, mm_width, and mm_height. 	 * 	 * \return singly-linked list of modes or NULL if no modes found. 	 */
name|struct
name|drm_display_mode
modifier|*
function_decl|(
modifier|*
name|get_modes
function_decl|)
parameter_list|(
name|struct
name|intel_dvo_device
modifier|*
name|dvo
parameter_list|)
function_decl|;
comment|/** 	 * Clean up driver-specific bits of the output 	 */
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|struct
name|intel_dvo_device
modifier|*
name|dvo
parameter_list|)
function_decl|;
comment|/** 	 * Debugging hook to dump device registers to log file 	 */
name|void
function_decl|(
modifier|*
name|dump_regs
function_decl|)
parameter_list|(
name|struct
name|intel_dvo_device
modifier|*
name|dvo
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|intel_dvo_dev_ops
name|sil164_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|intel_dvo_dev_ops
name|ch7xxx_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|intel_dvo_dev_ops
name|ivch_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|intel_dvo_dev_ops
name|tfp410_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|intel_dvo_dev_ops
name|ch7017_ops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|intel_dvo_dev_ops
name|ns2501_ops
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _INTEL_DVO_H */
end_comment

end_unit

