begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2010 Advanced Micro Devices, Inc.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Authors:  *     Alex Deucher<alexander.deucher@amd.com>  */
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
comment|/*  * evergreen cards need to use the 3D engine to blit data which requires  * quite a bit of hw state setup.  Rather than pull the whole 3D driver  * (which normally generates the 3D state) into the DRM, we opt to use  * statically generated state tables.  The regsiter state and shaders  * were hand generated to support blitting functionality.  See the 3D  * driver or documentation for descriptions of the registers and  * shader instructions.  */
end_comment

begin_decl_stmt
specifier|const
name|u32
name|cayman_default_state
index|[]
init|=
block|{
literal|0xc0066900
block|,
literal|0x00000000
block|,
literal|0x00000060
block|,
comment|/* DB_RENDER_CONTROL */
literal|0x00000000
block|,
comment|/* DB_COUNT_CONTROL */
literal|0x00000000
block|,
comment|/* DB_DEPTH_VIEW */
literal|0x0000002a
block|,
comment|/* DB_RENDER_OVERRIDE */
literal|0x00000000
block|,
comment|/* DB_RENDER_OVERRIDE2 */
literal|0x00000000
block|,
comment|/* DB_HTILE_DATA_BASE */
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
literal|0xc0036900
block|,
literal|0x0000000f
block|,
literal|0x00000000
block|,
comment|/* DB_DEPTH_INFO */
literal|0x00000000
block|,
comment|/* DB_Z_INFO */
literal|0x00000000
block|,
comment|/* DB_STENCIL_INFO */
literal|0xc0016900
block|,
literal|0x00000080
block|,
literal|0x00000000
block|,
comment|/* PA_SC_WINDOW_OFFSET */
literal|0xc00d6900
block|,
literal|0x00000083
block|,
literal|0x0000ffff
block|,
comment|/* PA_SC_CLIPRECT_RULE */
literal|0x00000000
block|,
comment|/* PA_SC_CLIPRECT_0_TL */
literal|0x20002000
block|,
comment|/* PA_SC_CLIPRECT_0_BR */
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
literal|0x00000000
block|,
comment|/* PA_SU_HARDWARE_SCREEN_OFFSET */
literal|0x0000000f
block|,
comment|/* CB_TARGET_MASK */
literal|0x0000000f
block|,
comment|/* CB_SHADER_MASK */
literal|0xc0226900
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
comment|/* PA_SC_VPORT_ZMAX_0 */
literal|0xc0016900
block|,
literal|0x000000d4
block|,
literal|0x00000000
block|,
comment|/* SX_MISC */
literal|0xc0026900
block|,
literal|0x000000d9
block|,
literal|0x00000000
block|,
comment|/* CP_RINGID */
literal|0x00000000
block|,
comment|/* CP_VMID */
literal|0xc0096900
block|,
literal|0x00000100
block|,
literal|0x00ffffff
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
comment|/* CB_BLEND_GREEN */
literal|0x00000000
block|,
comment|/* CB_BLEND_BLUE */
literal|0x00000000
block|,
comment|/* CB_BLEND_ALPHA */
literal|0xc0016900
block|,
literal|0x00000187
block|,
literal|0x00000100
block|,
comment|/* SPI_VS_OUT_ID_0 */
literal|0xc0026900
block|,
literal|0x00000191
block|,
literal|0x00000100
block|,
comment|/* SPI_PS_INPUT_CNTL_0 */
literal|0x00000101
block|,
comment|/* SPI_PS_INPUT_CNTL_1 */
literal|0xc0016900
block|,
literal|0x000001b1
block|,
literal|0x00000000
block|,
comment|/* SPI_VS_OUT_CONFIG */
literal|0xc0106900
block|,
literal|0x000001b3
block|,
literal|0x20000001
block|,
comment|/* SPI_PS_IN_CONTROL_0 */
literal|0x00000000
block|,
comment|/* SPI_PS_IN_CONTROL_1 */
literal|0x00000000
block|,
comment|/* SPI_INTERP_CONTROL_0 */
literal|0x00000000
block|,
comment|/* SPI_INPUT_Z */
literal|0x00000000
block|,
comment|/* SPI_FOG_CNTL */
literal|0x00100000
block|,
comment|/* SPI_BARYC_CNTL */
literal|0x00000000
block|,
comment|/* SPI_PS_IN_CONTROL_2 */
literal|0x00000000
block|,
comment|/* SPI_COMPUTE_INPUT_CNTL */
literal|0x00000000
block|,
comment|/* SPI_COMPUTE_NUM_THREAD_X */
literal|0x00000000
block|,
comment|/* SPI_COMPUTE_NUM_THREAD_Y */
literal|0x00000000
block|,
comment|/* SPI_COMPUTE_NUM_THREAD_Z */
literal|0x00000000
block|,
comment|/* SPI_GPR_MGMT */
literal|0x00000000
block|,
comment|/* SPI_LDS_MGMT */
literal|0x00000000
block|,
comment|/* SPI_STACK_MGMT */
literal|0x00000000
block|,
comment|/* SPI_WAVE_MGMT_1 */
literal|0x00000000
block|,
comment|/* SPI_WAVE_MGMT_2 */
literal|0xc0016900
block|,
literal|0x000001e0
block|,
literal|0x00000000
block|,
comment|/* CB_BLEND0_CONTROL */
literal|0xc00e6900
block|,
literal|0x00000200
block|,
literal|0x00000000
block|,
comment|/* DB_DEPTH_CONTROL */
literal|0x00000000
block|,
comment|/* DB_EQAA */
literal|0x00cc0010
block|,
comment|/* CB_COLOR_CONTROL */
literal|0x00000210
block|,
comment|/* DB_SHADER_CONTROL */
literal|0x00010000
block|,
comment|/* PA_CL_CLIP_CNTL */
literal|0x00000004
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
literal|0x00000000
block|,
comment|/* PA_SU_LINE_STIPPLE_CNTL */
literal|0x00000000
block|,
comment|/* PA_SU_LINE_STIPPLE_SCALE */
literal|0x00000000
block|,
comment|/* PA_SU_PRIM_FILTER_CNTL */
literal|0x00000000
block|,
comment|/*  */
literal|0x00000000
block|,
comment|/*  */
literal|0xc0026900
block|,
literal|0x00000229
block|,
literal|0x00000000
block|,
comment|/* SQ_PGM_START_FS */
literal|0x00000000
block|,
literal|0xc0016900
block|,
literal|0x0000023b
block|,
literal|0x00000000
block|,
comment|/* SQ_LDS_ALLOC_PS */
literal|0xc0066900
block|,
literal|0x00000240
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
literal|0xc0046900
block|,
literal|0x00000247
block|,
literal|0x00000000
block|,
comment|/* SQ_GS_VERT_ITEMSIZE */
literal|0x00000000
block|,
literal|0x00000000
block|,
literal|0x00000000
block|,
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
literal|0x00000000
block|,
literal|0x00000000
block|,
comment|/* VGT_GS_MODE */
literal|0xc0026900
block|,
literal|0x00000292
block|,
literal|0x00000000
block|,
comment|/* PA_SC_MODE_CNTL_0 */
literal|0x00000000
block|,
comment|/* PA_SC_MODE_CNTL_1 */
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
comment|/* VGT_MULTI_PRIM_IB_RESET_EN */
literal|0xc0026900
block|,
literal|0x000002a8
block|,
literal|0x00000000
block|,
comment|/* VGT_INSTANCE_STEP_RATE_0 */
literal|0x00000000
block|,
literal|0xc0026900
block|,
literal|0x000002ad
block|,
literal|0x00000000
block|,
comment|/* VGT_REUSE_OFF */
literal|0x00000000
block|,
literal|0xc0016900
block|,
literal|0x000002d5
block|,
literal|0x00000000
block|,
comment|/* VGT_SHADER_STAGES_EN */
literal|0xc0016900
block|,
literal|0x000002dc
block|,
literal|0x0000aa00
block|,
comment|/* DB_ALPHA_TO_MASK */
literal|0xc0066900
block|,
literal|0x000002de
block|,
literal|0x00000000
block|,
comment|/* PA_SU_POLY_OFFSET_DB_FMT_CNTL */
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
literal|0xc0026900
block|,
literal|0x000002e5
block|,
literal|0x00000000
block|,
comment|/* VGT_STRMOUT_CONFIG */
literal|0x00000000
block|,
literal|0xc01b6900
block|,
literal|0x000002f5
block|,
literal|0x76543210
block|,
comment|/* PA_SC_CENTROID_PRIORITY_0 */
literal|0xfedcba98
block|,
comment|/* PA_SC_CENTROID_PRIORITY_1 */
literal|0x00000000
block|,
comment|/* PA_SC_LINE_CNTL */
literal|0x00000000
block|,
comment|/* PA_SC_AA_CONFIG */
literal|0x00000005
block|,
comment|/* PA_SU_VTX_CNTL */
literal|0x3f800000
block|,
comment|/* PA_CL_GB_VERT_CLIP_ADJ */
literal|0x3f800000
block|,
comment|/* PA_CL_GB_VERT_DISC_ADJ */
literal|0x3f800000
block|,
comment|/* PA_CL_GB_HORZ_CLIP_ADJ */
literal|0x3f800000
block|,
comment|/* PA_CL_GB_HORZ_DISC_ADJ */
literal|0x00000000
block|,
comment|/* PA_SC_AA_SAMPLE_LOCS_PIXEL_X0Y0_0 */
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
literal|0xffffffff
block|,
comment|/* PA_SC_AA_MASK_X0Y0_X1Y0 */
literal|0xffffffff
block|,
literal|0xc0026900
block|,
literal|0x00000316
block|,
literal|0x0000000e
block|,
comment|/* VGT_VERTEX_REUSE_BLOCK_CNTL */
literal|0x00000010
block|,
comment|/*  */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|u32
name|cayman_vs
index|[]
init|=
block|{
literal|0x00000004
block|,
literal|0x80400400
block|,
literal|0x0000a03c
block|,
literal|0x95000688
block|,
literal|0x00004000
block|,
literal|0x15000688
block|,
literal|0x00000000
block|,
literal|0x88000000
block|,
literal|0x04000000
block|,
literal|0x67961001
block|,
ifdef|#
directive|ifdef
name|__BIG_ENDIAN
literal|0x00020000
block|,
else|#
directive|else
literal|0x00000000
block|,
endif|#
directive|endif
literal|0x00000000
block|,
literal|0x04000000
block|,
literal|0x67961000
block|,
ifdef|#
directive|ifdef
name|__BIG_ENDIAN
literal|0x00020008
block|,
else|#
directive|else
literal|0x00000008
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
name|cayman_ps
index|[]
init|=
block|{
literal|0x00000004
block|,
literal|0xa00c0000
block|,
literal|0x00000008
block|,
literal|0x80400000
block|,
literal|0x00000000
block|,
literal|0x95000688
block|,
literal|0x00000000
block|,
literal|0x88000000
block|,
literal|0x00380400
block|,
literal|0x00146b10
block|,
literal|0x00380000
block|,
literal|0x20146b10
block|,
literal|0x00380400
block|,
literal|0x40146b00
block|,
literal|0x80380000
block|,
literal|0x60146b00
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
name|cayman_ps_size
init|=
name|DRM_ARRAY_SIZE
argument_list|(
name|cayman_ps
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|u32
name|cayman_vs_size
init|=
name|DRM_ARRAY_SIZE
argument_list|(
name|cayman_vs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|u32
name|cayman_default_size
init|=
name|DRM_ARRAY_SIZE
argument_list|(
name|cayman_default_state
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

