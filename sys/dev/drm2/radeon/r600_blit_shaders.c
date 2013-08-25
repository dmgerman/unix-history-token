begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009 Advanced Micro Devices, Inc.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Authors:  *     Alex Deucher<alexander.deucher@amd.com>  */
end_comment

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
file|<dev/drm2/drmP.h>
end_include

begin_comment
comment|/*  * R6xx+ cards need to use the 3D engine to blit data which requires  * quite a bit of hw state setup.  Rather than pull the whole 3D driver  * (which normally generates the 3D state) into the DRM, we opt to use  * statically generated state tables.  The regsiter state and shaders  * were hand generated to support blitting functionality.  See the 3D  * driver or documentation for descriptions of the registers and  * shader instructions.  */
end_comment

begin_decl_stmt
specifier|const
name|u32
name|r6xx_default_state
index|[]
init|=
block|{
literal|0xc0002400
block|,
comment|/* START_3D_CMDBUF */
literal|0x00000000
block|,
literal|0xc0012800
block|,
comment|/* CONTEXT_CONTROL */
literal|0x80000000
block|,
literal|0x80000000
block|,
literal|0xc0016800
block|,
literal|0x00000010
block|,
literal|0x00008000
block|,
comment|/* WAIT_UNTIL */
literal|0xc0016800
block|,
literal|0x00000542
block|,
literal|0x07000003
block|,
comment|/* TA_CNTL_AUX */
literal|0xc0016800
block|,
literal|0x000005c5
block|,
literal|0x00000000
block|,
comment|/* VC_ENHANCE */
literal|0xc0016800
block|,
literal|0x00000363
block|,
literal|0x00000000
block|,
comment|/* SQ_DYN_GPR_CNTL_PS_FLUSH_REQ */
literal|0xc0016800
block|,
literal|0x0000060c
block|,
literal|0x82000000
block|,
comment|/* DB_DEBUG */
literal|0xc0016800
block|,
literal|0x0000060e
block|,
literal|0x01020204
block|,
comment|/* DB_WATERMARKS */
literal|0xc0026f00
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
comment|/* SQ_VTX_BASE_VTX_LOC */
literal|0x00000000
block|,
comment|/* SQ_VTX_START_INST_LOC */
literal|0xc0096900
block|,
literal|0x0000022a
block|,
literal|0x00000000
block|,
comment|/* SQ_ESGS_RING_ITEMSIZE */
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0xc0016900
block|,
literal|0x00000004
block|,
literal|0x00000000
block|,
comment|/* DB_DEPTH_INFO */
literal|0xc0026900
block|,
literal|0x0000000a
block|,
literal|0x00000000
block|,
comment|/* DB_STENCIL_CLEAR */
literal|0x00000000
block|,
comment|/* DB_DEPTH_CLEAR */
literal|0xc0016900
block|,
literal|0x00000200
block|,
literal|0x00000000
block|,
comment|/* DB_DEPTH_CONTROL */
literal|0xc0026900
block|,
literal|0x00000343
block|,
literal|0x00000060
block|,
comment|/* DB_RENDER_CONTROL */
literal|0x00000040
block|,
comment|/* DB_RENDER_OVERRIDE */
literal|0xc0016900
block|,
literal|0x00000351
block|,
literal|0x0000aa00
block|,
comment|/* DB_ALPHA_TO_MASK */
literal|0xc00f6900
block|,
literal|0x00000100
block|,
literal|0x00000800
block|,
comment|/* VGT_MAX_VTX_INDX */
literal|0x00000000
block|,
comment|/* VGT_MIN_VTX_INDX */
literal|0x00000000
block|,
comment|/* VGT_INDX_OFFSET */
literal|0x00000000
block|,
comment|/* VGT_MULTI_PRIM_IB_RESET_INDX */
literal|0x00000000
block|,
comment|/* SX_ALPHA_TEST_CONTROL */
literal|0x00000000
block|,
comment|/* CB_BLEND_RED */
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
comment|/* CB_FOG_RED */
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
comment|/* DB_STENCILREFMASK */
literal|0x00000000
block|,
comment|/* DB_STENCILREFMASK_BF */
literal|0x00000000
block|,
comment|/* SX_ALPHA_REF */
literal|0xc0046900
block|,
literal|0x0000030c
block|,
literal|0x01000000
block|,
comment|/* CB_CLRCMP_CNTL */
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0xc0046900
block|,
literal|0x00000048
block|,
literal|0x3f800000
block|,
comment|/* CB_CLEAR_RED */
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x3f800000
block|,
literal|0xc0016900
block|,
literal|0x00000080
block|,
literal|0x00000000
block|,
comment|/* PA_SC_WINDOW_OFFSET */
literal|0xc00a6900
block|,
literal|0x00000083
block|,
literal|0x0000ffff
block|,
comment|/* PA_SC_CLIP_RECT_RULE */
literal|0x00000000
block|,
comment|/* PA_SC_CLIPRECT_0_TL */
literal|0x20002000
block|,
literal|0x00000000
block|,
literal|0x20002000
block|,
literal|0x00000000
block|,
literal|0x20002000
block|,
literal|0x00000000
block|,
literal|0x20002000
block|,
literal|0x00000000
block|,
comment|/* PA_SC_EDGERULE */
literal|0xc0406900
block|,
literal|0x00000094
block|,
literal|0x80000000
block|,
comment|/* PA_SC_VPORT_SCISSOR_0_TL */
literal|0x20002000
block|,
comment|/* PA_SC_VPORT_SCISSOR_0_BR */
literal|0x80000000
block|,
comment|/* PA_SC_VPORT_SCISSOR_1_TL */
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x00000000
block|,
comment|/* PA_SC_VPORT_ZMIN_0 */
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0xc0026900
block|,
literal|0x00000292
block|,
literal|0x00000000
block|,
comment|/* PA_SC_MPASS_PS_CNTL */
literal|0x00004010
block|,
comment|/* PA_SC_MODE_CNTL */
literal|0xc0096900
block|,
literal|0x00000300
block|,
literal|0x00000000
block|,
comment|/* PA_SC_LINE_CNTL */
literal|0x00000000
block|,
comment|/* PA_SC_AA_CONFIG */
literal|0x0000002d
block|,
comment|/* PA_SU_VTX_CNTL */
literal|0x3f800000
block|,
comment|/* PA_CL_GB_VERT_CLIP_ADJ */
literal|0x3f800000
block|,
literal|0x3f800000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
comment|/* PA_SC_SAMPLE_LOCS_MCTX */
literal|0x00000000
block|,
literal|0xc0016900
block|,
literal|0x00000312
block|,
literal|0xffffffff
block|,
comment|/* PA_SC_AA_MASK */
literal|0xc0066900
block|,
literal|0x0000037e
block|,
literal|0x00000000
block|,
comment|/* PA_SU_POLY_OFFSET_DB_FMT_CNTL */
literal|0x00000000
block|,
comment|/* PA_SU_POLY_OFFSET_CLAMP */
literal|0x00000000
block|,
comment|/* PA_SU_POLY_OFFSET_FRONT_SCALE */
literal|0x00000000
block|,
comment|/* PA_SU_POLY_OFFSET_FRONT_OFFSET */
literal|0x00000000
block|,
comment|/* PA_SU_POLY_OFFSET_BACK_SCALE */
literal|0x00000000
block|,
comment|/* PA_SU_POLY_OFFSET_BACK_OFFSET */
literal|0xc0046900
block|,
literal|0x000001b6
block|,
literal|0x00000000
block|,
comment|/* SPI_INPUT_Z */
literal|0x00000000
block|,
comment|/* SPI_FOG_CNTL */
literal|0x00000000
block|,
comment|/* SPI_FOG_FUNC_SCALE */
literal|0x00000000
block|,
comment|/* SPI_FOG_FUNC_BIAS */
literal|0xc0016900
block|,
literal|0x00000225
block|,
literal|0x00000000
block|,
comment|/* SQ_PGM_START_FS */
literal|0xc0016900
block|,
literal|0x00000229
block|,
literal|0x00000000
block|,
comment|/* SQ_PGM_RESOURCES_FS */
literal|0xc0016900
block|,
literal|0x00000237
block|,
literal|0x00000000
block|,
comment|/* SQ_PGM_CF_OFFSET_FS */
literal|0xc0026900
block|,
literal|0x000002a8
block|,
literal|0x00000000
block|,
comment|/* VGT_INSTANCE_STEP_RATE_0 */
literal|0x00000000
block|,
comment|/* VGT_INSTANCE_STEP_RATE_1 */
literal|0xc0116900
block|,
literal|0x00000280
block|,
literal|0x00000000
block|,
comment|/* PA_SU_POINT_SIZE */
literal|0x00000000
block|,
comment|/* PA_SU_POINT_MINMAX */
literal|0x00000008
block|,
comment|/* PA_SU_LINE_CNTL */
literal|0x00000000
block|,
comment|/* PA_SC_LINE_STIPPLE */
literal|0x00000000
block|,
comment|/* VGT_OUTPUT_PATH_CNTL */
literal|0x00000000
block|,
comment|/* VGT_HOS_CNTL */
literal|0x00000000
block|,
comment|/* VGT_HOS_MAX_TESS_LEVEL */
literal|0x00000000
block|,
comment|/* VGT_HOS_MIN_TESS_LEVEL */
literal|0x00000000
block|,
comment|/* VGT_HOS_REUSE_DEPTH */
literal|0x00000000
block|,
comment|/* VGT_GROUP_PRIM_TYPE */
literal|0x00000000
block|,
comment|/* VGT_GROUP_FIRST_DECR */
literal|0x00000000
block|,
comment|/* VGT_GROUP_DECR */
literal|0x00000000
block|,
comment|/* VGT_GROUP_VECT_0_CNTL */
literal|0x00000000
block|,
comment|/* VGT_GROUP_VECT_1_CNTL */
literal|0x00000000
block|,
comment|/* VGT_GROUP_VECT_0_FMT_CNTL */
literal|0x00000000
block|,
comment|/* VGT_GROUP_VECT_1_FMT_CNTL */
literal|0x00000000
block|,
comment|/* VGT_GS_MODE */
literal|0xc0016900
block|,
literal|0x000002a1
block|,
literal|0x00000000
block|,
comment|/* VGT_PRIMITIVEID_EN */
literal|0xc0016900
block|,
literal|0x000002a5
block|,
literal|0x00000000
block|,
comment|/* VGT_MULTI_PRIM_ID_RESET_EN */
literal|0xc0036900
block|,
literal|0x000002ac
block|,
literal|0x00000000
block|,
comment|/* VGT_STRMOUT_EN */
literal|0x00000000
block|,
comment|/* VGT_REUSE_OFF */
literal|0x00000000
block|,
comment|/* VGT_VTX_CNT_EN */
literal|0xc0016900
block|,
literal|0x000000d4
block|,
literal|0x00000000
block|,
comment|/* SX_MISC */
literal|0xc0016900
block|,
literal|0x000002c8
block|,
literal|0x00000000
block|,
comment|/* VGT_STRMOUT_BUFFER_EN */
literal|0xc0076900
block|,
literal|0x00000202
block|,
literal|0x00cc0000
block|,
comment|/* CB_COLOR_CONTROL */
literal|0x00000210
block|,
comment|/* DB_SHADER_CNTL */
literal|0x00010000
block|,
comment|/* PA_CL_CLIP_CNTL */
literal|0x00000244
block|,
comment|/* PA_SU_SC_MODE_CNTL */
literal|0x00000100
block|,
comment|/* PA_CL_VTE_CNTL */
literal|0x00000000
block|,
comment|/* PA_CL_VS_OUT_CNTL */
literal|0x00000000
block|,
comment|/* PA_CL_NANINF_CNTL */
literal|0xc0026900
block|,
literal|0x0000008e
block|,
literal|0x0000000f
block|,
comment|/* CB_TARGET_MASK */
literal|0x0000000f
block|,
comment|/* CB_SHADER_MASK */
literal|0xc0016900
block|,
literal|0x000001e8
block|,
literal|0x00000001
block|,
comment|/* CB_SHADER_CONTROL */
literal|0xc0016900
block|,
literal|0x00000185
block|,
literal|0x00000000
block|,
comment|/* SPI_VS_OUT_ID_0 */
literal|0xc0016900
block|,
literal|0x00000191
block|,
literal|0x00000b00
block|,
comment|/* SPI_PS_INPUT_CNTL_0 */
literal|0xc0056900
block|,
literal|0x000001b1
block|,
literal|0x00000000
block|,
comment|/* SPI_VS_OUT_CONFIG */
literal|0x00000000
block|,
comment|/* SPI_THREAD_GROUPING */
literal|0x00000001
block|,
comment|/* SPI_PS_IN_CONTROL_0 */
literal|0x00000000
block|,
comment|/* SPI_PS_IN_CONTROL_1 */
literal|0x00000000
block|,
comment|/* SPI_INTERP_CONTROL_0 */
literal|0xc0036e00
block|,
comment|/* SET_SAMPLER */
literal|0x00000000
block|,
literal|0x00000012
block|,
literal|0x00000000
block|,
literal|0x00000000
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|u32
name|r7xx_default_state
index|[]
init|=
block|{
literal|0xc0012800
block|,
comment|/* CONTEXT_CONTROL */
literal|0x80000000
block|,
literal|0x80000000
block|,
literal|0xc0016800
block|,
literal|0x00000010
block|,
literal|0x00008000
block|,
comment|/* WAIT_UNTIL */
literal|0xc0016800
block|,
literal|0x00000542
block|,
literal|0x07000002
block|,
comment|/* TA_CNTL_AUX */
literal|0xc0016800
block|,
literal|0x000005c5
block|,
literal|0x00000000
block|,
comment|/* VC_ENHANCE */
literal|0xc0016800
block|,
literal|0x00000363
block|,
literal|0x00004000
block|,
comment|/* SQ_DYN_GPR_CNTL_PS_FLUSH_REQ */
literal|0xc0016800
block|,
literal|0x0000060c
block|,
literal|0x00000000
block|,
comment|/* DB_DEBUG */
literal|0xc0016800
block|,
literal|0x0000060e
block|,
literal|0x00420204
block|,
comment|/* DB_WATERMARKS */
literal|0xc0026f00
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
comment|/* SQ_VTX_BASE_VTX_LOC */
literal|0x00000000
block|,
comment|/* SQ_VTX_START_INST_LOC */
literal|0xc0096900
block|,
literal|0x0000022a
block|,
literal|0x00000000
block|,
comment|/* SQ_ESGS_RING_ITEMSIZE */
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0xc0016900
block|,
literal|0x00000004
block|,
literal|0x00000000
block|,
comment|/* DB_DEPTH_INFO */
literal|0xc0026900
block|,
literal|0x0000000a
block|,
literal|0x00000000
block|,
comment|/* DB_STENCIL_CLEAR */
literal|0x00000000
block|,
comment|/* DB_DEPTH_CLEAR */
literal|0xc0016900
block|,
literal|0x00000200
block|,
literal|0x00000000
block|,
comment|/* DB_DEPTH_CONTROL */
literal|0xc0026900
block|,
literal|0x00000343
block|,
literal|0x00000060
block|,
comment|/* DB_RENDER_CONTROL */
literal|0x00000000
block|,
comment|/* DB_RENDER_OVERRIDE */
literal|0xc0016900
block|,
literal|0x00000351
block|,
literal|0x0000aa00
block|,
comment|/* DB_ALPHA_TO_MASK */
literal|0xc0096900
block|,
literal|0x00000100
block|,
literal|0x00000800
block|,
comment|/* VGT_MAX_VTX_INDX */
literal|0x00000000
block|,
comment|/* VGT_MIN_VTX_INDX */
literal|0x00000000
block|,
comment|/* VGT_INDX_OFFSET */
literal|0x00000000
block|,
comment|/* VGT_MULTI_PRIM_IB_RESET_INDX */
literal|0x00000000
block|,
comment|/* SX_ALPHA_TEST_CONTROL */
literal|0x00000000
block|,
comment|/* CB_BLEND_RED */
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0xc0036900
block|,
literal|0x0000010c
block|,
literal|0x00000000
block|,
comment|/* DB_STENCILREFMASK */
literal|0x00000000
block|,
comment|/* DB_STENCILREFMASK_BF */
literal|0x00000000
block|,
comment|/* SX_ALPHA_REF */
literal|0xc0046900
block|,
literal|0x0000030c
block|,
comment|/* CB_CLRCMP_CNTL */
literal|0x01000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0xc0016900
block|,
literal|0x00000080
block|,
literal|0x00000000
block|,
comment|/* PA_SC_WINDOW_OFFSET */
literal|0xc00a6900
block|,
literal|0x00000083
block|,
literal|0x0000ffff
block|,
comment|/* PA_SC_CLIP_RECT_RULE */
literal|0x00000000
block|,
comment|/* PA_SC_CLIPRECT_0_TL */
literal|0x20002000
block|,
literal|0x00000000
block|,
literal|0x20002000
block|,
literal|0x00000000
block|,
literal|0x20002000
block|,
literal|0x00000000
block|,
literal|0x20002000
block|,
literal|0xaaaaaaaa
block|,
comment|/* PA_SC_EDGERULE */
literal|0xc0406900
block|,
literal|0x00000094
block|,
literal|0x80000000
block|,
comment|/* PA_SC_VPORT_SCISSOR_0_TL */
literal|0x20002000
block|,
comment|/* PA_SC_VPORT_SCISSOR_0_BR */
literal|0x80000000
block|,
comment|/* PA_SC_VPORT_SCISSOR_1_TL */
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x80000000
block|,
literal|0x20002000
block|,
literal|0x00000000
block|,
comment|/* PA_SC_VPORT_ZMIN_0 */
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
literal|0x3f800000
block|,
literal|0xc0026900
block|,
literal|0x00000292
block|,
literal|0x00000000
block|,
comment|/* PA_SC_MPASS_PS_CNTL */
literal|0x00514000
block|,
comment|/* PA_SC_MODE_CNTL */
literal|0xc0096900
block|,
literal|0x00000300
block|,
literal|0x00000000
block|,
comment|/* PA_SC_LINE_CNTL */
literal|0x00000000
block|,
comment|/* PA_SC_AA_CONFIG */
literal|0x0000002d
block|,
comment|/* PA_SU_VTX_CNTL */
literal|0x3f800000
block|,
comment|/* PA_CL_GB_VERT_CLIP_ADJ */
literal|0x3f800000
block|,
literal|0x3f800000
block|,
literal|0x3f800000
block|,
literal|0x00000000
block|,
comment|/* PA_SC_SAMPLE_LOCS_MCTX */
literal|0x00000000
block|,
literal|0xc0016900
block|,
literal|0x00000312
block|,
literal|0xffffffff
block|,
comment|/* PA_SC_AA_MASK */
literal|0xc0066900
block|,
literal|0x0000037e
block|,
literal|0x00000000
block|,
comment|/* PA_SU_POLY_OFFSET_DB_FMT_CNTL */
literal|0x00000000
block|,
comment|/* PA_SU_POLY_OFFSET_CLAMP */
literal|0x00000000
block|,
comment|/* PA_SU_POLY_OFFSET_FRONT_SCALE */
literal|0x00000000
block|,
comment|/* PA_SU_POLY_OFFSET_FRONT_OFFSET */
literal|0x00000000
block|,
comment|/* PA_SU_POLY_OFFSET_BACK_SCALE */
literal|0x00000000
block|,
comment|/* PA_SU_POLY_OFFSET_BACK_OFFSET */
literal|0xc0046900
block|,
literal|0x000001b6
block|,
literal|0x00000000
block|,
comment|/* SPI_INPUT_Z */
literal|0x00000000
block|,
comment|/* SPI_FOG_CNTL */
literal|0x00000000
block|,
comment|/* SPI_FOG_FUNC_SCALE */
literal|0x00000000
block|,
comment|/* SPI_FOG_FUNC_BIAS */
literal|0xc0016900
block|,
literal|0x00000225
block|,
literal|0x00000000
block|,
comment|/* SQ_PGM_START_FS */
literal|0xc0016900
block|,
literal|0x00000229
block|,
literal|0x00000000
block|,
comment|/* SQ_PGM_RESOURCES_FS */
literal|0xc0016900
block|,
literal|0x00000237
block|,
literal|0x00000000
block|,
comment|/* SQ_PGM_CF_OFFSET_FS */
literal|0xc0026900
block|,
literal|0x000002a8
block|,
literal|0x00000000
block|,
comment|/* VGT_INSTANCE_STEP_RATE_0 */
literal|0x00000000
block|,
comment|/* VGT_INSTANCE_STEP_RATE_1 */
literal|0xc0116900
block|,
literal|0x00000280
block|,
literal|0x00000000
block|,
comment|/* PA_SU_POINT_SIZE */
literal|0x00000000
block|,
comment|/* PA_SU_POINT_MINMAX */
literal|0x00000008
block|,
comment|/* PA_SU_LINE_CNTL */
literal|0x00000000
block|,
comment|/* PA_SC_LINE_STIPPLE */
literal|0x00000000
block|,
comment|/* VGT_OUTPUT_PATH_CNTL */
literal|0x00000000
block|,
comment|/* VGT_HOS_CNTL */
literal|0x00000000
block|,
comment|/* VGT_HOS_MAX_TESS_LEVEL */
literal|0x00000000
block|,
comment|/* VGT_HOS_MIN_TESS_LEVEL */
literal|0x00000000
block|,
comment|/* VGT_HOS_REUSE_DEPTH */
literal|0x00000000
block|,
comment|/* VGT_GROUP_PRIM_TYPE */
literal|0x00000000
block|,
comment|/* VGT_GROUP_FIRST_DECR */
literal|0x00000000
block|,
comment|/* VGT_GROUP_DECR */
literal|0x00000000
block|,
comment|/* VGT_GROUP_VECT_0_CNTL */
literal|0x00000000
block|,
comment|/* VGT_GROUP_VECT_1_CNTL */
literal|0x00000000
block|,
comment|/* VGT_GROUP_VECT_0_FMT_CNTL */
literal|0x00000000
block|,
comment|/* VGT_GROUP_VECT_1_FMT_CNTL */
literal|0x00000000
block|,
comment|/* VGT_GS_MODE */
literal|0xc0016900
block|,
literal|0x000002a1
block|,
literal|0x00000000
block|,
comment|/* VGT_PRIMITIVEID_EN */
literal|0xc0016900
block|,
literal|0x000002a5
block|,
literal|0x00000000
block|,
comment|/* VGT_MULTI_PRIM_ID_RESET_EN */
literal|0xc0036900
block|,
literal|0x000002ac
block|,
literal|0x00000000
block|,
comment|/* VGT_STRMOUT_EN */
literal|0x00000000
block|,
comment|/* VGT_REUSE_OFF */
literal|0x00000000
block|,
comment|/* VGT_VTX_CNT_EN */
literal|0xc0016900
block|,
literal|0x000000d4
block|,
literal|0x00000000
block|,
comment|/* SX_MISC */
literal|0xc0016900
block|,
literal|0x000002c8
block|,
literal|0x00000000
block|,
comment|/* VGT_STRMOUT_BUFFER_EN */
literal|0xc0076900
block|,
literal|0x00000202
block|,
literal|0x00cc0000
block|,
comment|/* CB_COLOR_CONTROL */
literal|0x00000210
block|,
comment|/* DB_SHADER_CNTL */
literal|0x00010000
block|,
comment|/* PA_CL_CLIP_CNTL */
literal|0x00000244
block|,
comment|/* PA_SU_SC_MODE_CNTL */
literal|0x00000100
block|,
comment|/* PA_CL_VTE_CNTL */
literal|0x00000000
block|,
comment|/* PA_CL_VS_OUT_CNTL */
literal|0x00000000
block|,
comment|/* PA_CL_NANINF_CNTL */
literal|0xc0026900
block|,
literal|0x0000008e
block|,
literal|0x0000000f
block|,
comment|/* CB_TARGET_MASK */
literal|0x0000000f
block|,
comment|/* CB_SHADER_MASK */
literal|0xc0016900
block|,
literal|0x000001e8
block|,
literal|0x00000001
block|,
comment|/* CB_SHADER_CONTROL */
literal|0xc0016900
block|,
literal|0x00000185
block|,
literal|0x00000000
block|,
comment|/* SPI_VS_OUT_ID_0 */
literal|0xc0016900
block|,
literal|0x00000191
block|,
literal|0x00000b00
block|,
comment|/* SPI_PS_INPUT_CNTL_0 */
literal|0xc0056900
block|,
literal|0x000001b1
block|,
literal|0x00000000
block|,
comment|/* SPI_VS_OUT_CONFIG */
literal|0x00000001
block|,
comment|/* SPI_THREAD_GROUPING */
literal|0x00000001
block|,
comment|/* SPI_PS_IN_CONTROL_0 */
literal|0x00000000
block|,
comment|/* SPI_PS_IN_CONTROL_1 */
literal|0x00000000
block|,
comment|/* SPI_INTERP_CONTROL_0 */
literal|0xc0036e00
block|,
comment|/* SET_SAMPLER */
literal|0x00000000
block|,
literal|0x00000012
block|,
literal|0x00000000
block|,
literal|0x00000000
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* same for r6xx/r7xx */
end_comment

begin_decl_stmt
specifier|const
name|u32
name|r6xx_vs
index|[]
init|=
block|{
literal|0x00000004
block|,
literal|0x81000000
block|,
literal|0x0000203c
block|,
literal|0x94000b08
block|,
literal|0x00004000
block|,
literal|0x14200b1a
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x3c000000
block|,
literal|0x68cd1000
block|,
ifdef|#
directive|ifdef
name|__BIG_ENDIAN
literal|0x000a0000
block|,
else|#
directive|else
literal|0x00080000
block|,
endif|#
directive|endif
literal|0x00000000
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|u32
name|r6xx_ps
index|[]
init|=
block|{
literal|0x00000002
block|,
literal|0x80800000
block|,
literal|0x00000000
block|,
literal|0x94200688
block|,
literal|0x00000010
block|,
literal|0x000d1000
block|,
literal|0xb0800000
block|,
literal|0x00000000
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|u32
name|r6xx_ps_size
init|=
name|DRM_ARRAY_SIZE
argument_list|(
name|r6xx_ps
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|u32
name|r6xx_vs_size
init|=
name|DRM_ARRAY_SIZE
argument_list|(
name|r6xx_vs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|u32
name|r6xx_default_size
init|=
name|DRM_ARRAY_SIZE
argument_list|(
name|r6xx_default_state
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|u32
name|r7xx_default_size
init|=
name|DRM_ARRAY_SIZE
argument_list|(
name|r7xx_default_state
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

