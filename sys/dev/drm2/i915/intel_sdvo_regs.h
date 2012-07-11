begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright Â© 2006-2007 Intel Corporation  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Authors:  *	Eric Anholt<eric@anholt.net>  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * @file SDVO command definitions and structures.  */
end_comment

begin_define
define|#
directive|define
name|SDVO_OUTPUT_FIRST
value|(0)
end_define

begin_define
define|#
directive|define
name|SDVO_OUTPUT_TMDS0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SDVO_OUTPUT_RGB0
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SDVO_OUTPUT_CVBS0
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SDVO_OUTPUT_SVID0
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SDVO_OUTPUT_YPRPB0
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SDVO_OUTPUT_SCART0
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SDVO_OUTPUT_LVDS0
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SDVO_OUTPUT_TMDS1
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SDVO_OUTPUT_RGB1
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SDVO_OUTPUT_CVBS1
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|SDVO_OUTPUT_SVID1
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|SDVO_OUTPUT_YPRPB1
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|SDVO_OUTPUT_SCART1
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|SDVO_OUTPUT_LVDS1
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|SDVO_OUTPUT_LAST
value|(14)
end_define

begin_struct
struct|struct
name|intel_sdvo_caps
block|{
name|u8
name|vendor_id
decl_stmt|;
name|u8
name|device_id
decl_stmt|;
name|u8
name|device_rev_id
decl_stmt|;
name|u8
name|sdvo_version_major
decl_stmt|;
name|u8
name|sdvo_version_minor
decl_stmt|;
name|unsigned
name|int
name|sdvo_inputs_mask
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|smooth_scaling
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|sharp_scaling
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|up_scaling
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|down_scaling
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|stall_support
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pad
range|:
literal|1
decl_stmt|;
name|u16
name|output_flags
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/** This matches the EDID DTD structure, more or less */
end_comment

begin_struct
struct|struct
name|intel_sdvo_dtd
block|{
struct|struct
block|{
name|u16
name|clock
decl_stmt|;
comment|/**< pixel clock, in 10kHz units */
name|u8
name|h_active
decl_stmt|;
comment|/**< lower 8 bits (pixels) */
name|u8
name|h_blank
decl_stmt|;
comment|/**< lower 8 bits (pixels) */
name|u8
name|h_high
decl_stmt|;
comment|/**< upper 4 bits each h_active, h_blank */
name|u8
name|v_active
decl_stmt|;
comment|/**< lower 8 bits (lines) */
name|u8
name|v_blank
decl_stmt|;
comment|/**< lower 8 bits (lines) */
name|u8
name|v_high
decl_stmt|;
comment|/**< upper 4 bits each v_active, v_blank */
block|}
name|part1
struct|;
struct|struct
block|{
name|u8
name|h_sync_off
decl_stmt|;
comment|/**< lower 8 bits, from hblank start */
name|u8
name|h_sync_width
decl_stmt|;
comment|/**< lower 8 bits (pixels) */
comment|/** lower 4 bits each vsync offset, vsync width */
name|u8
name|v_sync_off_width
decl_stmt|;
comment|/** 		* 2 high bits of hsync offset, 2 high bits of hsync width, 		* bits 4-5 of vsync offset, and 2 high bits of vsync width. 		*/
name|u8
name|sync_off_width_high
decl_stmt|;
name|u8
name|dtd_flags
decl_stmt|;
name|u8
name|sdvo_flags
decl_stmt|;
comment|/** bits 6-7 of vsync offset at bits 6-7 */
name|u8
name|v_sync_off_high
decl_stmt|;
name|u8
name|reserved
decl_stmt|;
block|}
name|part2
struct|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|intel_sdvo_pixel_clock_range
block|{
name|u16
name|min
decl_stmt|;
comment|/**< pixel clock, in 10kHz units */
name|u16
name|max
decl_stmt|;
comment|/**< pixel clock, in 10kHz units */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|intel_sdvo_preferred_input_timing_args
block|{
name|u16
name|clock
decl_stmt|;
name|u16
name|width
decl_stmt|;
name|u16
name|height
decl_stmt|;
name|u8
name|interlace
range|:
literal|1
decl_stmt|;
name|u8
name|scaled
range|:
literal|1
decl_stmt|;
name|u8
name|pad
range|:
literal|6
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* I2C registers for SDVO */
end_comment

begin_define
define|#
directive|define
name|SDVO_I2C_ARG_0
value|0x07
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_ARG_1
value|0x06
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_ARG_2
value|0x05
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_ARG_3
value|0x04
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_ARG_4
value|0x03
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_ARG_5
value|0x02
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_ARG_6
value|0x01
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_ARG_7
value|0x00
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_OPCODE
value|0x08
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_CMD_STATUS
value|0x09
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_RETURN_0
value|0x0a
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_RETURN_1
value|0x0b
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_RETURN_2
value|0x0c
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_RETURN_3
value|0x0d
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_RETURN_4
value|0x0e
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_RETURN_5
value|0x0f
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_RETURN_6
value|0x10
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_RETURN_7
value|0x11
end_define

begin_define
define|#
directive|define
name|SDVO_I2C_VENDOR_BEGIN
value|0x20
end_define

begin_comment
comment|/* Status results */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_STATUS_POWER_ON
value|0x0
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_STATUS_SUCCESS
value|0x1
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_STATUS_NOTSUPP
value|0x2
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_STATUS_INVALID_ARG
value|0x3
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_STATUS_PENDING
value|0x4
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_STATUS_TARGET_NOT_SPECIFIED
value|0x5
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_STATUS_SCALING_NOT_SUPP
value|0x6
end_define

begin_comment
comment|/* SDVO commands, argument/result registers */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_RESET
value|0x01
end_define

begin_comment
comment|/** Returns a struct intel_sdvo_caps */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_DEVICE_CAPS
value|0x02
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_FIRMWARE_REV
value|0x86
end_define

begin_define
define|#
directive|define
name|SDVO_DEVICE_FIRMWARE_MINOR
value|SDVO_I2C_RETURN_0
end_define

begin_define
define|#
directive|define
name|SDVO_DEVICE_FIRMWARE_MAJOR
value|SDVO_I2C_RETURN_1
end_define

begin_define
define|#
directive|define
name|SDVO_DEVICE_FIRMWARE_PATCH
value|SDVO_I2C_RETURN_2
end_define

begin_comment
comment|/**  * Reports which inputs are trained (managed to sync).  *  * Devices must have trained within 2 vsyncs of a mode change.  */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_TRAINED_INPUTS
value|0x03
end_define

begin_struct
struct|struct
name|intel_sdvo_get_trained_inputs_response
block|{
name|unsigned
name|int
name|input0_trained
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|input1_trained
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pad
range|:
literal|6
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/** Returns a struct intel_sdvo_output_flags of active outputs. */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_ACTIVE_OUTPUTS
value|0x04
end_define

begin_comment
comment|/**  * Sets the current set of active outputs.  *  * Takes a struct intel_sdvo_output_flags.  Must be preceded by a SET_IN_OUT_MAP  * on multi-output devices.  */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_SET_ACTIVE_OUTPUTS
value|0x05
end_define

begin_comment
comment|/**  * Returns the current mapping of SDVO inputs to outputs on the device.  *  * Returns two struct intel_sdvo_output_flags structures.  */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_IN_OUT_MAP
value|0x06
end_define

begin_struct
struct|struct
name|intel_sdvo_in_out_map
block|{
name|u16
name|in0
decl_stmt|,
name|in1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Sets the current mapping of SDVO inputs to outputs on the device.  *  * Takes two struct i380_sdvo_output_flags structures.  */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_SET_IN_OUT_MAP
value|0x07
end_define

begin_comment
comment|/**  * Returns a struct intel_sdvo_output_flags of attached displays.  */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_ATTACHED_DISPLAYS
value|0x0b
end_define

begin_comment
comment|/**  * Returns a struct intel_sdvo_ouptut_flags of displays supporting hot plugging.  */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_HOT_PLUG_SUPPORT
value|0x0c
end_define

begin_comment
comment|/**  * Takes a struct intel_sdvo_output_flags.  */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_SET_ACTIVE_HOT_PLUG
value|0x0d
end_define

begin_comment
comment|/**  * Returns a struct intel_sdvo_output_flags of displays with hot plug  * interrupts enabled.  */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_ACTIVE_HOT_PLUG
value|0x0e
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_INTERRUPT_EVENT_SOURCE
value|0x0f
end_define

begin_struct
struct|struct
name|intel_sdvo_get_interrupt_event_source_response
block|{
name|u16
name|interrupt_status
decl_stmt|;
name|unsigned
name|int
name|ambient_light_interrupt
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdmi_audio_encrypt_change
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pad
range|:
literal|6
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/**  * Selects which input is affected by future input commands.  *  * Commands affected include SET_INPUT_TIMINGS_PART[12],  * GET_INPUT_TIMINGS_PART[12], GET_PREFERRED_INPUT_TIMINGS_PART[12],  * GET_INPUT_PIXEL_CLOCK_RANGE, and CREATE_PREFERRED_INPUT_TIMINGS.  */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_SET_TARGET_INPUT
value|0x10
end_define

begin_struct
struct|struct
name|intel_sdvo_set_target_input_args
block|{
name|unsigned
name|int
name|target_1
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pad
range|:
literal|7
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/**  * Takes a struct intel_sdvo_output_flags of which outputs are targeted by  * future output commands.  *  * Affected commands inclue SET_OUTPUT_TIMINGS_PART[12],  * GET_OUTPUT_TIMINGS_PART[12], and GET_OUTPUT_PIXEL_CLOCK_RANGE.  */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_SET_TARGET_OUTPUT
value|0x11
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_INPUT_TIMINGS_PART1
value|0x12
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_INPUT_TIMINGS_PART2
value|0x13
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_INPUT_TIMINGS_PART1
value|0x14
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_INPUT_TIMINGS_PART2
value|0x15
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_OUTPUT_TIMINGS_PART1
value|0x16
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_OUTPUT_TIMINGS_PART2
value|0x17
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_OUTPUT_TIMINGS_PART1
value|0x18
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_OUTPUT_TIMINGS_PART2
value|0x19
end_define

begin_comment
comment|/* Part 1 */
end_comment

begin_define
define|#
directive|define
name|SDVO_DTD_CLOCK_LOW
value|SDVO_I2C_ARG_0
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_CLOCK_HIGH
value|SDVO_I2C_ARG_1
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_H_ACTIVE
value|SDVO_I2C_ARG_2
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_H_BLANK
value|SDVO_I2C_ARG_3
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_H_HIGH
value|SDVO_I2C_ARG_4
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_V_ACTIVE
value|SDVO_I2C_ARG_5
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_V_BLANK
value|SDVO_I2C_ARG_6
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_V_HIGH
value|SDVO_I2C_ARG_7
end_define

begin_comment
comment|/* Part 2 */
end_comment

begin_define
define|#
directive|define
name|SDVO_DTD_HSYNC_OFF
value|SDVO_I2C_ARG_0
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_HSYNC_WIDTH
value|SDVO_I2C_ARG_1
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_VSYNC_OFF_WIDTH
value|SDVO_I2C_ARG_2
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_SYNC_OFF_WIDTH_HIGH
value|SDVO_I2C_ARG_3
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_DTD_FLAGS
value|SDVO_I2C_ARG_4
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_DTD_FLAG_INTERLACED
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_DTD_FLAG_STEREO_MASK
value|(3<< 5)
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_DTD_FLAG_INPUT_MASK
value|(3<< 3)
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_DTD_FLAG_SYNC_MASK
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_SDVO_FLAS
value|SDVO_I2C_ARG_5
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_SDVO_FLAG_STALL
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_SDVO_FLAG_CENTERED
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_SDVO_FLAG_UPPER_LEFT
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_SDVO_FLAG_SCALING_MASK
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_SDVO_FLAG_SCALING_NONE
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_SDVO_FLAG_SCALING_SHARP
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_SDVO_FLAG_SCALING_SMOOTH
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|SDVO_DTD_VSYNC_OFF_HIGH
value|SDVO_I2C_ARG_6
end_define

begin_comment
comment|/**  * Generates a DTD based on the given width, height, and flags.  *  * This will be supported by any device supporting scaling or interlaced  * modes.  */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_CREATE_PREFERRED_INPUT_TIMING
value|0x1a
end_define

begin_define
define|#
directive|define
name|SDVO_PREFERRED_INPUT_TIMING_CLOCK_LOW
value|SDVO_I2C_ARG_0
end_define

begin_define
define|#
directive|define
name|SDVO_PREFERRED_INPUT_TIMING_CLOCK_HIGH
value|SDVO_I2C_ARG_1
end_define

begin_define
define|#
directive|define
name|SDVO_PREFERRED_INPUT_TIMING_WIDTH_LOW
value|SDVO_I2C_ARG_2
end_define

begin_define
define|#
directive|define
name|SDVO_PREFERRED_INPUT_TIMING_WIDTH_HIGH
value|SDVO_I2C_ARG_3
end_define

begin_define
define|#
directive|define
name|SDVO_PREFERRED_INPUT_TIMING_HEIGHT_LOW
value|SDVO_I2C_ARG_4
end_define

begin_define
define|#
directive|define
name|SDVO_PREFERRED_INPUT_TIMING_HEIGHT_HIGH
value|SDVO_I2C_ARG_5
end_define

begin_define
define|#
directive|define
name|SDVO_PREFERRED_INPUT_TIMING_FLAGS
value|SDVO_I2C_ARG_6
end_define

begin_define
define|#
directive|define
name|SDVO_PREFERRED_INPUT_TIMING_FLAGS_INTERLACED
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SDVO_PREFERRED_INPUT_TIMING_FLAGS_SCALED
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_PREFERRED_INPUT_TIMING_PART1
value|0x1b
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_PREFERRED_INPUT_TIMING_PART2
value|0x1c
end_define

begin_comment
comment|/** Returns a struct intel_sdvo_pixel_clock_range */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_INPUT_PIXEL_CLOCK_RANGE
value|0x1d
end_define

begin_comment
comment|/** Returns a struct intel_sdvo_pixel_clock_range */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_OUTPUT_PIXEL_CLOCK_RANGE
value|0x1e
end_define

begin_comment
comment|/** Returns a byte bitfield containing SDVO_CLOCK_RATE_MULT_* flags */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_SUPPORTED_CLOCK_RATE_MULTS
value|0x1f
end_define

begin_comment
comment|/** Returns a byte containing a SDVO_CLOCK_RATE_MULT_* flag */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_CLOCK_RATE_MULT
value|0x20
end_define

begin_comment
comment|/** Takes a byte containing a SDVO_CLOCK_RATE_MULT_* flag */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_SET_CLOCK_RATE_MULT
value|0x21
end_define

begin_define
define|#
directive|define
name|SDVO_CLOCK_RATE_MULT_1X
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SDVO_CLOCK_RATE_MULT_2X
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SDVO_CLOCK_RATE_MULT_4X
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_SUPPORTED_TV_FORMATS
value|0x27
end_define

begin_comment
comment|/** 6 bytes of bit flags for TV formats shared by all TV format functions */
end_comment

begin_struct
struct|struct
name|intel_sdvo_tv_format
block|{
name|unsigned
name|int
name|ntsc_m
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|ntsc_j
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|ntsc_443
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_b
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_d
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_g
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_h
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_i
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_m
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_n
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_nc
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|secam_b
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|secam_d
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|secam_g
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|secam_k
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|secam_k1
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|secam_l
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|secam_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_240m_1080i_59
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_240m_1080i_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_260m_1080i_59
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_260m_1080i_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080i_50
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080i_59
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080i_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080p_23
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080p_24
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080p_25
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080p_29
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080p_30
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080p_50
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080p_59
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080p_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_295m_1080i_50
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_295m_1080p_50
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_296m_720p_59
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_296m_720p_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_296m_720p_50
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_293m_480p_59
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_170m_480i_59
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_iturbt601_576i_50
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_iturbt601_576p_50
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_eia_7702a_480i_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_eia_7702a_480p_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pad
range|:
literal|3
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|SDVO_CMD_GET_TV_FORMAT
value|0x28
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_TV_FORMAT
value|0x29
end_define

begin_comment
comment|/** Returns the resolutiosn that can be used with the given TV format */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_SDTV_RESOLUTION_SUPPORT
value|0x83
end_define

begin_struct
struct|struct
name|intel_sdvo_sdtv_resolution_request
block|{
name|unsigned
name|int
name|ntsc_m
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|ntsc_j
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|ntsc_443
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_b
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_d
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_g
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_h
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_i
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_m
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_n
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_nc
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pal_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|secam_b
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|secam_d
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|secam_g
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|secam_k
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|secam_k1
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|secam_l
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|secam_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pad
range|:
literal|5
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|intel_sdvo_sdtv_resolution_reply
block|{
name|unsigned
name|int
name|res_320x200
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_320x240
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_400x300
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_640x350
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_640x400
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_640x480
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_704x480
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_704x576
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_720x350
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_720x400
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_720x480
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_720x540
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_720x576
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_768x576
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_800x600
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_832x624
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_920x766
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1024x768
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1280x1024
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pad
range|:
literal|5
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Get supported resolution with squire pixel aspect ratio that can be    scaled for the requested HDTV format */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_SCALED_HDTV_RESOLUTION_SUPPORT
value|0x85
end_define

begin_struct
struct|struct
name|intel_sdvo_hdtv_resolution_request
block|{
name|unsigned
name|int
name|hdtv_std_smpte_240m_1080i_59
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_240m_1080i_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_260m_1080i_59
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_260m_1080i_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080i_50
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080i_59
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080i_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080p_23
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080p_24
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080p_25
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080p_29
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080p_30
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080p_50
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080p_59
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_274m_1080p_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_295m_1080i_50
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_295m_1080p_50
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_296m_720p_59
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_296m_720p_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_296m_720p_50
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_293m_480p_59
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_smpte_170m_480i_59
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_iturbt601_576i_50
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_iturbt601_576p_50
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_eia_7702a_480i_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hdtv_std_eia_7702a_480p_60
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pad
range|:
literal|6
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|intel_sdvo_hdtv_resolution_reply
block|{
name|unsigned
name|int
name|res_640x480
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_800x600
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1024x768
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1280x960
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1400x1050
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1600x1200
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1920x1440
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_2048x1536
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_2560x1920
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_3200x2400
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_3840x2880
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pad1
range|:
literal|5
decl_stmt|;
name|unsigned
name|int
name|res_848x480
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1064x600
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1280x720
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1360x768
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1704x960
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1864x1050
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1920x1080
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_2128x1200
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_2560x1400
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_2728x1536
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_3408x1920
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_4264x2400
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_5120x2880
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pad2
range|:
literal|3
decl_stmt|;
name|unsigned
name|int
name|res_768x480
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_960x600
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1152x720
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1124x768
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1536x960
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1680x1050
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1728x1080
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_1920x1200
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_2304x1440
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_2456x1536
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_3072x1920
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_3840x2400
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|res_4608x2880
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pad3
range|:
literal|3
decl_stmt|;
name|unsigned
name|int
name|res_1280x1024
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pad4
range|:
literal|7
decl_stmt|;
name|unsigned
name|int
name|res_1280x768
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pad5
range|:
literal|7
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Get supported power state returns info for encoder and monitor, rely on    last SetTargetInput and SetTargetOutput calls */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_SUPPORTED_POWER_STATES
value|0x2a
end_define

begin_comment
comment|/* Get power state returns info for encoder and monitor, rely on last    SetTargetInput and SetTargetOutput calls */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_POWER_STATE
value|0x2b
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_ENCODER_POWER_STATE
value|0x2b
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_ENCODER_POWER_STATE
value|0x2c
end_define

begin_define
define|#
directive|define
name|SDVO_ENCODER_STATE_ON
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SDVO_ENCODER_STATE_STANDBY
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SDVO_ENCODER_STATE_SUSPEND
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SDVO_ENCODER_STATE_OFF
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SDVO_MONITOR_STATE_ON
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SDVO_MONITOR_STATE_STANDBY
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SDVO_MONITOR_STATE_SUSPEND
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SDVO_MONITOR_STATE_OFF
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_MAX_PANEL_POWER_SEQUENCING
value|0x2d
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_PANEL_POWER_SEQUENCING
value|0x2e
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_PANEL_POWER_SEQUENCING
value|0x2f
end_define

begin_comment
comment|/**  * The panel power sequencing parameters are in units of milliseconds.  * The high fields are bits 8:9 of the 10-bit values.  */
end_comment

begin_struct
struct|struct
name|sdvo_panel_power_sequencing
block|{
name|u8
name|t0
decl_stmt|;
name|u8
name|t1
decl_stmt|;
name|u8
name|t2
decl_stmt|;
name|u8
name|t3
decl_stmt|;
name|u8
name|t4
decl_stmt|;
name|unsigned
name|int
name|t0_high
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|t1_high
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|t2_high
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|t3_high
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|t4_high
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|pad
range|:
literal|6
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|SDVO_CMD_GET_MAX_BACKLIGHT_LEVEL
value|0x30
end_define

begin_struct
struct|struct
name|sdvo_max_backlight_reply
block|{
name|u8
name|max_value
decl_stmt|;
name|u8
name|default_value
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|SDVO_CMD_GET_BACKLIGHT_LEVEL
value|0x31
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_BACKLIGHT_LEVEL
value|0x32
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_AMBIENT_LIGHT
value|0x33
end_define

begin_struct
struct|struct
name|sdvo_get_ambient_light_reply
block|{
name|u16
name|trip_low
decl_stmt|;
name|u16
name|trip_high
decl_stmt|;
name|u16
name|value
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|SDVO_CMD_SET_AMBIENT_LIGHT
value|0x34
end_define

begin_struct
struct|struct
name|sdvo_set_ambient_light_reply
block|{
name|u16
name|trip_low
decl_stmt|;
name|u16
name|trip_high
decl_stmt|;
name|unsigned
name|int
name|enable
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|pad
range|:
literal|7
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Set display power state */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_SET_DISPLAY_POWER_STATE
value|0x7d
end_define

begin_define
define|#
directive|define
name|SDVO_DISPLAY_STATE_ON
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SDVO_DISPLAY_STATE_STANDBY
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SDVO_DISPLAY_STATE_SUSPEND
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SDVO_DISPLAY_STATE_OFF
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_SUPPORTED_ENHANCEMENTS
value|0x84
end_define

begin_struct
struct|struct
name|intel_sdvo_enhancements_reply
block|{
name|unsigned
name|int
name|flicker_filter
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|flicker_filter_adaptive
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|flicker_filter_2d
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|saturation
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hue
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|brightness
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|contrast
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|overscan_h
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|overscan_v
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|hpos
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|vpos
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|sharpness
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|dot_crawl
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|dither
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|tv_chroma_filter
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|tv_luma_filter
range|:
literal|1
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* Picture enhancement limits below are dependent on the current TV format,  * and thus need to be queried and set after it.  */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_MAX_FLICKER_FILTER
value|0x4d
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_MAX_FLICKER_FILTER_ADAPTIVE
value|0x7b
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_MAX_FLICKER_FILTER_2D
value|0x52
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_MAX_SATURATION
value|0x55
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_MAX_HUE
value|0x58
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_MAX_BRIGHTNESS
value|0x5b
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_MAX_CONTRAST
value|0x5e
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_MAX_OVERSCAN_H
value|0x61
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_MAX_OVERSCAN_V
value|0x64
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_MAX_HPOS
value|0x67
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_MAX_VPOS
value|0x6a
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_MAX_SHARPNESS
value|0x6d
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_MAX_TV_CHROMA_FILTER
value|0x74
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_MAX_TV_LUMA_FILTER
value|0x77
end_define

begin_struct
struct|struct
name|intel_sdvo_enhancement_limits_reply
block|{
name|u16
name|max_value
decl_stmt|;
name|u16
name|default_value
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|SDVO_CMD_GET_LVDS_PANEL_INFORMATION
value|0x7f
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_LVDS_PANEL_INFORMATION
value|0x80
end_define

begin_define
define|#
directive|define
name|SDVO_LVDS_COLOR_DEPTH_18
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|SDVO_LVDS_COLOR_DEPTH_24
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SDVO_LVDS_CONNECTOR_SPWG
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|SDVO_LVDS_CONNECTOR_OPENLDI
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SDVO_LVDS_SINGLE_CHANNEL
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|SDVO_LVDS_DUAL_CHANNEL
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_FLICKER_FILTER
value|0x4e
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_FLICKER_FILTER
value|0x4f
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_FLICKER_FILTER_ADAPTIVE
value|0x50
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_FLICKER_FILTER_ADAPTIVE
value|0x51
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_FLICKER_FILTER_2D
value|0x53
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_FLICKER_FILTER_2D
value|0x54
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_SATURATION
value|0x56
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_SATURATION
value|0x57
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_HUE
value|0x59
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_HUE
value|0x5a
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_BRIGHTNESS
value|0x5c
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_BRIGHTNESS
value|0x5d
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_CONTRAST
value|0x5f
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_CONTRAST
value|0x60
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_OVERSCAN_H
value|0x62
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_OVERSCAN_H
value|0x63
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_OVERSCAN_V
value|0x65
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_OVERSCAN_V
value|0x66
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_HPOS
value|0x68
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_HPOS
value|0x69
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_VPOS
value|0x6b
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_VPOS
value|0x6c
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_SHARPNESS
value|0x6e
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_SHARPNESS
value|0x6f
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_TV_CHROMA_FILTER
value|0x75
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_TV_CHROMA_FILTER
value|0x76
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_TV_LUMA_FILTER
value|0x78
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_TV_LUMA_FILTER
value|0x79
end_define

begin_struct
struct|struct
name|intel_sdvo_enhancements_arg
block|{
name|u16
name|value
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|SDVO_CMD_GET_DOT_CRAWL
value|0x70
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_DOT_CRAWL
value|0x71
end_define

begin_define
define|#
directive|define
name|SDVO_DOT_CRAWL_ON
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SDVO_DOT_CRAWL_DEFAULT_ON
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_DITHER
value|0x72
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_DITHER
value|0x73
end_define

begin_define
define|#
directive|define
name|SDVO_DITHER_ON
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SDVO_DITHER_DEFAULT_ON
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_CONTROL_BUS_SWITCH
value|0x7a
end_define

begin_define
define|#
directive|define
name|SDVO_CONTROL_BUS_PROM
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SDVO_CONTROL_BUS_DDC1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SDVO_CONTROL_BUS_DDC2
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SDVO_CONTROL_BUS_DDC3
value|(1<< 3)
end_define

begin_comment
comment|/* HDMI op codes */
end_comment

begin_define
define|#
directive|define
name|SDVO_CMD_GET_SUPP_ENCODE
value|0x9d
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_ENCODE
value|0x9e
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_ENCODE
value|0x9f
end_define

begin_define
define|#
directive|define
name|SDVO_ENCODE_DVI
value|0x0
end_define

begin_define
define|#
directive|define
name|SDVO_ENCODE_HDMI
value|0x1
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_PIXEL_REPLI
value|0x8b
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_PIXEL_REPLI
value|0x8c
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_COLORIMETRY_CAP
value|0x8d
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_COLORIMETRY
value|0x8e
end_define

begin_define
define|#
directive|define
name|SDVO_COLORIMETRY_RGB256
value|0x0
end_define

begin_define
define|#
directive|define
name|SDVO_COLORIMETRY_RGB220
value|0x1
end_define

begin_define
define|#
directive|define
name|SDVO_COLORIMETRY_YCrCb422
value|0x3
end_define

begin_define
define|#
directive|define
name|SDVO_COLORIMETRY_YCrCb444
value|0x4
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_COLORIMETRY
value|0x8f
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_AUDIO_ENCRYPT_PREFER
value|0x90
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_AUDIO_STAT
value|0x91
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_AUDIO_STAT
value|0x92
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_HBUF_INDEX
value|0x93
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_HBUF_INDEX
value|0x94
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_HBUF_INFO
value|0x95
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_HBUF_AV_SPLIT
value|0x96
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_HBUF_AV_SPLIT
value|0x97
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_HBUF_DATA
value|0x98
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_HBUF_DATA
value|0x99
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_SET_HBUF_TXRATE
value|0x9a
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_HBUF_TXRATE
value|0x9b
end_define

begin_define
define|#
directive|define
name|SDVO_HBUF_TX_DISABLED
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|SDVO_HBUF_TX_ONCE
value|(2<< 6)
end_define

begin_define
define|#
directive|define
name|SDVO_HBUF_TX_VSYNC
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|SDVO_CMD_GET_AUDIO_TX_INFO
value|0x9c
end_define

begin_define
define|#
directive|define
name|SDVO_NEED_TO_STALL
value|(1<< 7)
end_define

begin_struct
struct|struct
name|intel_sdvo_encode
block|{
name|u8
name|dvi_rev
decl_stmt|;
name|u8
name|hdmi_rev
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

end_unit

