begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright 2003 Tungsten Graphics, Inc., Cedar Park, Texas.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the  * "Software"), to deal in the Software without restriction, including  * without limitation the rights to use, copy, modify, merge, publish,  * distribute, sub license, and/or sell copies of the Software, and to  * permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.  * IN NO EVENT SHALL TUNGSTEN GRAPHICS AND/OR ITS SUPPLIERS BE LIABLE FOR  * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE  * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|_I915_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_I915_REG_H_
end_define

begin_define
define|#
directive|define
name|_PIPE
parameter_list|(
name|pipe
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) + (pipe)*((b)-(a)))
end_define

begin_comment
comment|/*  * The Bridge device's PCI config space has information about the  * fb aperture size and the amount of pre-reserved memory.  * This is all handled in the intel-gtt.ko module. i915.ko only  * cares about the vga bit for the vga rbiter.  */
end_comment

begin_define
define|#
directive|define
name|INTEL_GMCH_CTRL
value|0x52
end_define

begin_define
define|#
directive|define
name|INTEL_GMCH_VGA_DISABLE
value|(1<< 1)
end_define

begin_comment
comment|/* PCI config space */
end_comment

begin_define
define|#
directive|define
name|HPLLCC
value|0xc0
end_define

begin_comment
comment|/* 855 only */
end_comment

begin_define
define|#
directive|define
name|GC_CLOCK_CONTROL_MASK
value|(0xf<< 0)
end_define

begin_define
define|#
directive|define
name|GC_CLOCK_133_200
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|GC_CLOCK_100_200
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GC_CLOCK_100_133
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|GC_CLOCK_166_250
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|GCFGC2
value|0xda
end_define

begin_define
define|#
directive|define
name|GCFGC
value|0xf0
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|GC_LOW_FREQUENCY_ENABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|GC_DISPLAY_CLOCK_190_200_MHZ
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|GC_DISPLAY_CLOCK_333_MHZ
value|(4<< 4)
end_define

begin_define
define|#
directive|define
name|GC_DISPLAY_CLOCK_MASK
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|GM45_GC_RENDER_CLOCK_MASK
value|(0xf<< 0)
end_define

begin_define
define|#
directive|define
name|GM45_GC_RENDER_CLOCK_266_MHZ
value|(8<< 0)
end_define

begin_define
define|#
directive|define
name|GM45_GC_RENDER_CLOCK_320_MHZ
value|(9<< 0)
end_define

begin_define
define|#
directive|define
name|GM45_GC_RENDER_CLOCK_400_MHZ
value|(0xb<< 0)
end_define

begin_define
define|#
directive|define
name|GM45_GC_RENDER_CLOCK_533_MHZ
value|(0xc<< 0)
end_define

begin_define
define|#
directive|define
name|I965_GC_RENDER_CLOCK_MASK
value|(0xf<< 0)
end_define

begin_define
define|#
directive|define
name|I965_GC_RENDER_CLOCK_267_MHZ
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|I965_GC_RENDER_CLOCK_333_MHZ
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|I965_GC_RENDER_CLOCK_444_MHZ
value|(4<< 0)
end_define

begin_define
define|#
directive|define
name|I965_GC_RENDER_CLOCK_533_MHZ
value|(5<< 0)
end_define

begin_define
define|#
directive|define
name|I945_GC_RENDER_CLOCK_MASK
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|I945_GC_RENDER_CLOCK_166_MHZ
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|I945_GC_RENDER_CLOCK_200_MHZ
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|I945_GC_RENDER_CLOCK_250_MHZ
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|I945_GC_RENDER_CLOCK_400_MHZ
value|(5<< 0)
end_define

begin_define
define|#
directive|define
name|I915_GC_RENDER_CLOCK_MASK
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|I915_GC_RENDER_CLOCK_166_MHZ
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|I915_GC_RENDER_CLOCK_200_MHZ
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|I915_GC_RENDER_CLOCK_333_MHZ
value|(4<< 0)
end_define

begin_define
define|#
directive|define
name|LBB
value|0xf4
end_define

begin_comment
comment|/* Graphics reset regs */
end_comment

begin_define
define|#
directive|define
name|I965_GDRST
value|0xc0
end_define

begin_comment
comment|/* PCI config register */
end_comment

begin_define
define|#
directive|define
name|ILK_GDSR
value|0x2ca4
end_define

begin_comment
comment|/* MCHBAR offset */
end_comment

begin_define
define|#
directive|define
name|GRDOM_FULL
value|(0<<2)
end_define

begin_define
define|#
directive|define
name|GRDOM_RENDER
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|GRDOM_MEDIA
value|(3<<2)
end_define

begin_define
define|#
directive|define
name|GRDOM_RESET_ENABLE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|GEN6_MBCUNIT_SNPCR
value|0x900c
end_define

begin_comment
comment|/* for LLC config */
end_comment

begin_define
define|#
directive|define
name|GEN6_MBC_SNPCR_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|GEN6_MBC_SNPCR_MASK
value|(3<<21)
end_define

begin_define
define|#
directive|define
name|GEN6_MBC_SNPCR_MAX
value|(0<<21)
end_define

begin_define
define|#
directive|define
name|GEN6_MBC_SNPCR_MED
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|GEN6_MBC_SNPCR_LOW
value|(2<<21)
end_define

begin_define
define|#
directive|define
name|GEN6_MBC_SNPCR_MIN
value|(3<<21)
end_define

begin_comment
comment|/* only 1/16th of the cache is shared */
end_comment

begin_define
define|#
directive|define
name|GEN6_MBCTL
value|0x0907c
end_define

begin_define
define|#
directive|define
name|GEN6_MBCTL_ENABLE_BOOT_FETCH
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|GEN6_MBCTL_CTX_FETCH_NEEDED
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|GEN6_MBCTL_BME_UPDATE_ENABLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|GEN6_MBCTL_MAE_UPDATE_ENABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|GEN6_MBCTL_BOOT_FETCH_MECH
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GEN6_GDRST
value|0x941c
end_define

begin_define
define|#
directive|define
name|GEN6_GRDOM_FULL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GEN6_GRDOM_RENDER
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|GEN6_GRDOM_MEDIA
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|GEN6_GRDOM_BLT
value|(1<< 3)
end_define

begin_comment
comment|/* PPGTT stuff */
end_comment

begin_define
define|#
directive|define
name|GEN6_GTT_ADDR_ENCODE
parameter_list|(
name|addr
parameter_list|)
value|((addr) | (((addr)>> 28)& 0xff0))
end_define

begin_define
define|#
directive|define
name|GEN6_PDE_VALID
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GEN6_PDE_LARGE_PAGE
value|(2<< 0)
end_define

begin_comment
comment|/* use 32kb pages */
end_comment

begin_comment
comment|/* gen6+ has bit 11-4 for physical addr bit 39-32 */
end_comment

begin_define
define|#
directive|define
name|GEN6_PDE_ADDR_ENCODE
parameter_list|(
name|addr
parameter_list|)
value|GEN6_GTT_ADDR_ENCODE(addr)
end_define

begin_define
define|#
directive|define
name|GEN6_PTE_VALID
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GEN6_PTE_UNCACHED
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|GEN6_PTE_CACHE_LLC
value|(2<< 1)
end_define

begin_define
define|#
directive|define
name|GEN6_PTE_CACHE_LLC_MLC
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|GEN6_PTE_CACHE_BITS
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|GEN6_PTE_GFDT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|GEN6_PTE_ADDR_ENCODE
parameter_list|(
name|addr
parameter_list|)
value|GEN6_GTT_ADDR_ENCODE(addr)
end_define

begin_define
define|#
directive|define
name|RING_PP_DIR_BASE
parameter_list|(
name|ring
parameter_list|)
value|((ring)->mmio_base+0x228)
end_define

begin_define
define|#
directive|define
name|RING_PP_DIR_BASE_READ
parameter_list|(
name|ring
parameter_list|)
value|((ring)->mmio_base+0x518)
end_define

begin_define
define|#
directive|define
name|RING_PP_DIR_DCLV
parameter_list|(
name|ring
parameter_list|)
value|((ring)->mmio_base+0x220)
end_define

begin_define
define|#
directive|define
name|PP_DIR_DCLV_2G
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|GAM_ECOCHK
value|0x4090
end_define

begin_define
define|#
directive|define
name|ECOCHK_SNB_BIT
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|ECOCHK_PPGTT_CACHE64B
value|(0x3<<3)
end_define

begin_define
define|#
directive|define
name|ECOCHK_PPGTT_CACHE4B
value|(0x0<<3)
end_define

begin_comment
comment|/* VGA stuff */
end_comment

begin_define
define|#
directive|define
name|VGA_ST01_MDA
value|0x3ba
end_define

begin_define
define|#
directive|define
name|VGA_ST01_CGA
value|0x3da
end_define

begin_define
define|#
directive|define
name|VGA_MSR_WRITE
value|0x3c2
end_define

begin_define
define|#
directive|define
name|VGA_MSR_READ
value|0x3cc
end_define

begin_define
define|#
directive|define
name|VGA_MSR_MEM_EN
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|VGA_MSR_CGA_MODE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|VGA_SR_INDEX
value|0x3c4
end_define

begin_define
define|#
directive|define
name|VGA_SR_DATA
value|0x3c5
end_define

begin_define
define|#
directive|define
name|VGA_AR_INDEX
value|0x3c0
end_define

begin_define
define|#
directive|define
name|VGA_AR_VID_EN
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|VGA_AR_DATA_WRITE
value|0x3c0
end_define

begin_define
define|#
directive|define
name|VGA_AR_DATA_READ
value|0x3c1
end_define

begin_define
define|#
directive|define
name|VGA_GR_INDEX
value|0x3ce
end_define

begin_define
define|#
directive|define
name|VGA_GR_DATA
value|0x3cf
end_define

begin_comment
comment|/* GR05 */
end_comment

begin_define
define|#
directive|define
name|VGA_GR_MEM_READ_MODE_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|VGA_GR_MEM_READ_MODE_PLANE
value|1
end_define

begin_comment
comment|/* GR06 */
end_comment

begin_define
define|#
directive|define
name|VGA_GR_MEM_MODE_MASK
value|0xc
end_define

begin_define
define|#
directive|define
name|VGA_GR_MEM_MODE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|VGA_GR_MEM_A0000_AFFFF
value|0
end_define

begin_define
define|#
directive|define
name|VGA_GR_MEM_A0000_BFFFF
value|1
end_define

begin_define
define|#
directive|define
name|VGA_GR_MEM_B0000_B7FFF
value|2
end_define

begin_define
define|#
directive|define
name|VGA_GR_MEM_B0000_BFFFF
value|3
end_define

begin_define
define|#
directive|define
name|VGA_DACMASK
value|0x3c6
end_define

begin_define
define|#
directive|define
name|VGA_DACRX
value|0x3c7
end_define

begin_define
define|#
directive|define
name|VGA_DACWX
value|0x3c8
end_define

begin_define
define|#
directive|define
name|VGA_DACDATA
value|0x3c9
end_define

begin_define
define|#
directive|define
name|VGA_CR_INDEX_MDA
value|0x3b4
end_define

begin_define
define|#
directive|define
name|VGA_CR_DATA_MDA
value|0x3b5
end_define

begin_define
define|#
directive|define
name|VGA_CR_INDEX_CGA
value|0x3d4
end_define

begin_define
define|#
directive|define
name|VGA_CR_DATA_CGA
value|0x3d5
end_define

begin_comment
comment|/*  * Memory interface instructions used by the kernel  */
end_comment

begin_define
define|#
directive|define
name|MI_INSTR
parameter_list|(
name|opcode
parameter_list|,
name|flags
parameter_list|)
value|(((opcode)<< 23) | (flags))
end_define

begin_define
define|#
directive|define
name|MI_NOOP
value|MI_INSTR(0, 0)
end_define

begin_define
define|#
directive|define
name|MI_USER_INTERRUPT
value|MI_INSTR(0x02, 0)
end_define

begin_define
define|#
directive|define
name|MI_WAIT_FOR_EVENT
value|MI_INSTR(0x03, 0)
end_define

begin_define
define|#
directive|define
name|MI_WAIT_FOR_OVERLAY_FLIP
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|MI_WAIT_FOR_PLANE_B_FLIP
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|MI_WAIT_FOR_PLANE_A_FLIP
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|MI_WAIT_FOR_PLANE_A_SCANLINES
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|MI_FLUSH
value|MI_INSTR(0x04, 0)
end_define

begin_define
define|#
directive|define
name|MI_READ_FLUSH
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MI_EXE_FLUSH
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MI_NO_WRITE_FLUSH
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MI_SCENE_COUNT
value|(1<< 3)
end_define

begin_comment
comment|/* just increment scene count */
end_comment

begin_define
define|#
directive|define
name|MI_END_SCENE
value|(1<< 4)
end_define

begin_comment
comment|/* flush binner and incr scene count */
end_comment

begin_define
define|#
directive|define
name|MI_INVALIDATE_ISP
value|(1<< 5)
end_define

begin_comment
comment|/* invalidate indirect state pointers */
end_comment

begin_define
define|#
directive|define
name|MI_BATCH_BUFFER_END
value|MI_INSTR(0x0a, 0)
end_define

begin_define
define|#
directive|define
name|MI_SUSPEND_FLUSH
value|MI_INSTR(0x0b, 0)
end_define

begin_define
define|#
directive|define
name|MI_SUSPEND_FLUSH_EN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|MI_REPORT_HEAD
value|MI_INSTR(0x07, 0)
end_define

begin_define
define|#
directive|define
name|MI_OVERLAY_FLIP
value|MI_INSTR(0x11, 0)
end_define

begin_define
define|#
directive|define
name|MI_OVERLAY_CONTINUE
value|(0x0<<21)
end_define

begin_define
define|#
directive|define
name|MI_OVERLAY_ON
value|(0x1<<21)
end_define

begin_define
define|#
directive|define
name|MI_OVERLAY_OFF
value|(0x2<<21)
end_define

begin_define
define|#
directive|define
name|MI_LOAD_SCAN_LINES_INCL
value|MI_INSTR(0x12, 0)
end_define

begin_define
define|#
directive|define
name|MI_DISPLAY_FLIP
value|MI_INSTR(0x14, 2)
end_define

begin_define
define|#
directive|define
name|MI_DISPLAY_FLIP_I915
value|MI_INSTR(0x14, 1)
end_define

begin_define
define|#
directive|define
name|MI_DISPLAY_FLIP_PLANE
parameter_list|(
name|n
parameter_list|)
value|((n)<< 20)
end_define

begin_define
define|#
directive|define
name|MI_ARB_ON_OFF
value|MI_INSTR(0x08, 0)
end_define

begin_define
define|#
directive|define
name|MI_ARB_ENABLE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|MI_ARB_DISABLE
value|(0<<0)
end_define

begin_define
define|#
directive|define
name|MI_SET_CONTEXT
value|MI_INSTR(0x18, 0)
end_define

begin_define
define|#
directive|define
name|MI_MM_SPACE_GTT
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|MI_MM_SPACE_PHYSICAL
value|(0<<8)
end_define

begin_define
define|#
directive|define
name|MI_SAVE_EXT_STATE_EN
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|MI_RESTORE_EXT_STATE_EN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|MI_FORCE_RESTORE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|MI_RESTORE_INHIBIT
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|MI_STORE_DWORD_IMM
value|MI_INSTR(0x20, 1)
end_define

begin_define
define|#
directive|define
name|MI_MEM_VIRTUAL
value|(1<< 22)
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_define
define|#
directive|define
name|MI_STORE_DWORD_INDEX
value|MI_INSTR(0x21, 1)
end_define

begin_define
define|#
directive|define
name|MI_STORE_DWORD_INDEX_SHIFT
value|2
end_define

begin_comment
comment|/* Official intel docs are somewhat sloppy concerning MI_LOAD_REGISTER_IMM:  * - Always issue a MI_NOOP _before_ the MI_LOAD_REGISTER_IMM - otherwise hw  *   simply ignores the register load under certain conditions.  * - One can actually load arbitrary many arbitrary registers: Simply issue x  *   address/value pairs. Don't overdue it, though, x<= 2^4 must hold!  */
end_comment

begin_define
define|#
directive|define
name|MI_LOAD_REGISTER_IMM
parameter_list|(
name|x
parameter_list|)
value|MI_INSTR(0x22, 2*x-1)
end_define

begin_define
define|#
directive|define
name|MI_FLUSH_DW
value|MI_INSTR(0x26, 1)
end_define

begin_comment
comment|/* for GEN6 */
end_comment

begin_define
define|#
directive|define
name|MI_INVALIDATE_TLB
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|MI_INVALIDATE_BSD
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|MI_BATCH_BUFFER
value|MI_INSTR(0x30, 1)
end_define

begin_define
define|#
directive|define
name|MI_BATCH_NON_SECURE
value|(1)
end_define

begin_define
define|#
directive|define
name|MI_BATCH_NON_SECURE_I965
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|MI_BATCH_BUFFER_START
value|MI_INSTR(0x31, 0)
end_define

begin_define
define|#
directive|define
name|MI_SEMAPHORE_MBOX
value|MI_INSTR(0x16, 1)
end_define

begin_comment
comment|/* gen6+ */
end_comment

begin_define
define|#
directive|define
name|MI_SEMAPHORE_GLOBAL_GTT
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|MI_SEMAPHORE_UPDATE
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|MI_SEMAPHORE_COMPARE
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|MI_SEMAPHORE_REGISTER
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|MI_SEMAPHORE_SYNC_RV
value|(2<<16)
end_define

begin_define
define|#
directive|define
name|MI_SEMAPHORE_SYNC_RB
value|(0<<16)
end_define

begin_define
define|#
directive|define
name|MI_SEMAPHORE_SYNC_VR
value|(0<<16)
end_define

begin_define
define|#
directive|define
name|MI_SEMAPHORE_SYNC_VB
value|(2<<16)
end_define

begin_define
define|#
directive|define
name|MI_SEMAPHORE_SYNC_BR
value|(2<<16)
end_define

begin_define
define|#
directive|define
name|MI_SEMAPHORE_SYNC_BV
value|(0<<16)
end_define

begin_define
define|#
directive|define
name|MI_SEMAPHORE_SYNC_INVALID
value|(1<<0)
end_define

begin_comment
comment|/*  * 3D instructions used by the kernel  */
end_comment

begin_define
define|#
directive|define
name|GFX_INSTR
parameter_list|(
name|opcode
parameter_list|,
name|flags
parameter_list|)
value|((0x3<< 29) | ((opcode)<< 24) | (flags))
end_define

begin_define
define|#
directive|define
name|GFX_OP_RASTER_RULES
value|((0x3<<29)|(0x7<<24))
end_define

begin_define
define|#
directive|define
name|GFX_OP_SCISSOR
value|((0x3<<29)|(0x1c<<24)|(0x10<<19))
end_define

begin_define
define|#
directive|define
name|SC_UPDATE_SCISSOR
value|(0x1<<1)
end_define

begin_define
define|#
directive|define
name|SC_ENABLE_MASK
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|SC_ENABLE
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|GFX_OP_LOAD_INDIRECT
value|((0x3<<29)|(0x1d<<24)|(0x7<<16))
end_define

begin_define
define|#
directive|define
name|GFX_OP_SCISSOR_INFO
value|((0x3<<29)|(0x1d<<24)|(0x81<<16)|(0x1))
end_define

begin_define
define|#
directive|define
name|SCI_YMIN_MASK
value|(0xffff<<16)
end_define

begin_define
define|#
directive|define
name|SCI_XMIN_MASK
value|(0xffff<<0)
end_define

begin_define
define|#
directive|define
name|SCI_YMAX_MASK
value|(0xffff<<16)
end_define

begin_define
define|#
directive|define
name|SCI_XMAX_MASK
value|(0xffff<<0)
end_define

begin_define
define|#
directive|define
name|GFX_OP_SCISSOR_ENABLE
value|((0x3<<29)|(0x1c<<24)|(0x10<<19))
end_define

begin_define
define|#
directive|define
name|GFX_OP_SCISSOR_RECT
value|((0x3<<29)|(0x1d<<24)|(0x81<<16)|1)
end_define

begin_define
define|#
directive|define
name|GFX_OP_COLOR_FACTOR
value|((0x3<<29)|(0x1d<<24)|(0x1<<16)|0x0)
end_define

begin_define
define|#
directive|define
name|GFX_OP_STIPPLE
value|((0x3<<29)|(0x1d<<24)|(0x83<<16))
end_define

begin_define
define|#
directive|define
name|GFX_OP_MAP_INFO
value|((0x3<<29)|(0x1d<<24)|0x4)
end_define

begin_define
define|#
directive|define
name|GFX_OP_DESTBUFFER_VARS
value|((0x3<<29)|(0x1d<<24)|(0x85<<16)|0x0)
end_define

begin_define
define|#
directive|define
name|GFX_OP_DESTBUFFER_INFO
value|((0x3<<29)|(0x1d<<24)|(0x8e<<16)|1)
end_define

begin_define
define|#
directive|define
name|GFX_OP_DRAWRECT_INFO
value|((0x3<<29)|(0x1d<<24)|(0x80<<16)|(0x3))
end_define

begin_define
define|#
directive|define
name|GFX_OP_DRAWRECT_INFO_I965
value|((0x7900<<16)|0x2)
end_define

begin_define
define|#
directive|define
name|SRC_COPY_BLT_CMD
value|((2<<29)|(0x43<<22)|4)
end_define

begin_define
define|#
directive|define
name|XY_SRC_COPY_BLT_CMD
value|((2<<29)|(0x53<<22)|6)
end_define

begin_define
define|#
directive|define
name|XY_MONO_SRC_COPY_IMM_BLT
value|((2<<29)|(0x71<<22)|5)
end_define

begin_define
define|#
directive|define
name|XY_SRC_COPY_BLT_WRITE_ALPHA
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|XY_SRC_COPY_BLT_WRITE_RGB
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|BLT_DEPTH_8
value|(0<<24)
end_define

begin_define
define|#
directive|define
name|BLT_DEPTH_16_565
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|BLT_DEPTH_16_1555
value|(2<<24)
end_define

begin_define
define|#
directive|define
name|BLT_DEPTH_32
value|(3<<24)
end_define

begin_define
define|#
directive|define
name|BLT_ROP_GXCOPY
value|(0xcc<<16)
end_define

begin_define
define|#
directive|define
name|XY_SRC_COPY_BLT_SRC_TILED
value|(1<<15)
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_define
define|#
directive|define
name|XY_SRC_COPY_BLT_DST_TILED
value|(1<<11)
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_define
define|#
directive|define
name|CMD_OP_DISPLAYBUFFER_INFO
value|((0x0<<29)|(0x14<<23)|2)
end_define

begin_define
define|#
directive|define
name|ASYNC_FLIP
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|DISPLAY_PLANE_A
value|(0<<20)
end_define

begin_define
define|#
directive|define
name|DISPLAY_PLANE_B
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|GFX_OP_PIPE_CONTROL
parameter_list|(
name|len
parameter_list|)
value|((0x3<<29)|(0x3<<27)|(0x2<<24)|(len-2))
end_define

begin_define
define|#
directive|define
name|PIPE_CONTROL_CS_STALL
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|PIPE_CONTROL_QW_WRITE
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|PIPE_CONTROL_DEPTH_STALL
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|PIPE_CONTROL_WRITE_FLUSH
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|PIPE_CONTROL_RENDER_TARGET_CACHE_FLUSH
value|(1<<12)
end_define

begin_comment
comment|/* gen6+ */
end_comment

begin_define
define|#
directive|define
name|PIPE_CONTROL_INSTRUCTION_CACHE_INVALIDATE
value|(1<<11)
end_define

begin_comment
comment|/* MBZ on Ironlake */
end_comment

begin_define
define|#
directive|define
name|PIPE_CONTROL_TEXTURE_CACHE_INVALIDATE
value|(1<<10)
end_define

begin_comment
comment|/* GM45+ only */
end_comment

begin_define
define|#
directive|define
name|PIPE_CONTROL_INDIRECT_STATE_DISABLE
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|PIPE_CONTROL_NOTIFY
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|PIPE_CONTROL_VF_CACHE_INVALIDATE
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|PIPE_CONTROL_CONST_CACHE_INVALIDATE
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|PIPE_CONTROL_STATE_CACHE_INVALIDATE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|PIPE_CONTROL_STALL_AT_SCOREBOARD
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|PIPE_CONTROL_DEPTH_CACHE_FLUSH
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PIPE_CONTROL_GLOBAL_GTT
value|(1<<2)
end_define

begin_comment
comment|/* in addr dword */
end_comment

begin_comment
comment|/*  * Reset registers  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_RESET_I830
value|0x6070
end_define

begin_define
define|#
directive|define
name|DEBUG_RESET_FULL
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|DEBUG_RESET_RENDER
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|DEBUG_RESET_DISPLAY
value|(1<<9)
end_define

begin_comment
comment|/*  * Fence registers  */
end_comment

begin_define
define|#
directive|define
name|FENCE_REG_830_0
value|0x2000
end_define

begin_define
define|#
directive|define
name|FENCE_REG_945_8
value|0x3000
end_define

begin_define
define|#
directive|define
name|I830_FENCE_START_MASK
value|0x07f80000
end_define

begin_define
define|#
directive|define
name|I830_FENCE_TILING_Y_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I830_FENCE_SIZE_BITS
parameter_list|(
name|size
parameter_list|)
value|((ffs((size)>> 19) - 1)<< 8)
end_define

begin_define
define|#
directive|define
name|I830_FENCE_PITCH_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I830_FENCE_REG_VALID
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|I915_FENCE_MAX_PITCH_VAL
value|4
end_define

begin_define
define|#
directive|define
name|I830_FENCE_MAX_PITCH_VAL
value|6
end_define

begin_define
define|#
directive|define
name|I830_FENCE_MAX_SIZE_VAL
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|I915_FENCE_START_MASK
value|0x0ff00000
end_define

begin_define
define|#
directive|define
name|I915_FENCE_SIZE_BITS
parameter_list|(
name|size
parameter_list|)
value|((ffs((size)>> 20) - 1)<< 8)
end_define

begin_define
define|#
directive|define
name|FENCE_REG_965_0
value|0x03000
end_define

begin_define
define|#
directive|define
name|I965_FENCE_PITCH_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I965_FENCE_TILING_Y_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I965_FENCE_REG_VALID
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|I965_FENCE_MAX_PITCH_VAL
value|0x0400
end_define

begin_define
define|#
directive|define
name|FENCE_REG_SANDYBRIDGE_0
value|0x100000
end_define

begin_define
define|#
directive|define
name|SANDYBRIDGE_FENCE_PITCH_SHIFT
value|32
end_define

begin_comment
comment|/* control register for cpu gtt access */
end_comment

begin_define
define|#
directive|define
name|TILECTL
value|0x101000
end_define

begin_define
define|#
directive|define
name|TILECTL_SWZCTL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|TILECTL_TLB_PREFETCH_DIS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|TILECTL_BACKSNOOP_DIS
value|(1<< 3)
end_define

begin_comment
comment|/*  * Instruction and interrupt control regs  */
end_comment

begin_define
define|#
directive|define
name|PGTBL_ER
value|0x02024
end_define

begin_define
define|#
directive|define
name|RENDER_RING_BASE
value|0x02000
end_define

begin_define
define|#
directive|define
name|BSD_RING_BASE
value|0x04000
end_define

begin_define
define|#
directive|define
name|GEN6_BSD_RING_BASE
value|0x12000
end_define

begin_define
define|#
directive|define
name|BLT_RING_BASE
value|0x22000
end_define

begin_define
define|#
directive|define
name|RING_TAIL
parameter_list|(
name|base
parameter_list|)
value|((base)+0x30)
end_define

begin_define
define|#
directive|define
name|RING_HEAD
parameter_list|(
name|base
parameter_list|)
value|((base)+0x34)
end_define

begin_define
define|#
directive|define
name|RING_START
parameter_list|(
name|base
parameter_list|)
value|((base)+0x38)
end_define

begin_define
define|#
directive|define
name|RING_CTL
parameter_list|(
name|base
parameter_list|)
value|((base)+0x3c)
end_define

begin_define
define|#
directive|define
name|RING_SYNC_0
parameter_list|(
name|base
parameter_list|)
value|((base)+0x40)
end_define

begin_define
define|#
directive|define
name|RING_SYNC_1
parameter_list|(
name|base
parameter_list|)
value|((base)+0x44)
end_define

begin_define
define|#
directive|define
name|GEN6_RVSYNC
value|(RING_SYNC_0(RENDER_RING_BASE))
end_define

begin_define
define|#
directive|define
name|GEN6_RBSYNC
value|(RING_SYNC_1(RENDER_RING_BASE))
end_define

begin_define
define|#
directive|define
name|GEN6_VRSYNC
value|(RING_SYNC_1(GEN6_BSD_RING_BASE))
end_define

begin_define
define|#
directive|define
name|GEN6_VBSYNC
value|(RING_SYNC_0(GEN6_BSD_RING_BASE))
end_define

begin_define
define|#
directive|define
name|GEN6_BRSYNC
value|(RING_SYNC_0(BLT_RING_BASE))
end_define

begin_define
define|#
directive|define
name|GEN6_BVSYNC
value|(RING_SYNC_1(BLT_RING_BASE))
end_define

begin_define
define|#
directive|define
name|RING_MAX_IDLE
parameter_list|(
name|base
parameter_list|)
value|((base)+0x54)
end_define

begin_define
define|#
directive|define
name|RING_HWS_PGA
parameter_list|(
name|base
parameter_list|)
value|((base)+0x80)
end_define

begin_define
define|#
directive|define
name|RING_HWS_PGA_GEN6
parameter_list|(
name|base
parameter_list|)
value|((base)+0x2080)
end_define

begin_define
define|#
directive|define
name|ARB_MODE
value|0x04030
end_define

begin_define
define|#
directive|define
name|ARB_MODE_SWIZZLE_SNB
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|ARB_MODE_SWIZZLE_IVB
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|ARB_MODE_ENABLE
parameter_list|(
name|x
parameter_list|)
value|GFX_MODE_ENABLE(x)
end_define

begin_define
define|#
directive|define
name|ARB_MODE_DISABLE
parameter_list|(
name|x
parameter_list|)
value|GFX_MODE_DISABLE(x)
end_define

begin_define
define|#
directive|define
name|RENDER_HWS_PGA_GEN7
value|(0x04080)
end_define

begin_define
define|#
directive|define
name|RING_FAULT_REG
parameter_list|(
name|ring
parameter_list|)
value|(0x4094 + 0x100*(ring)->id)
end_define

begin_define
define|#
directive|define
name|DONE_REG
value|0x40b0
end_define

begin_define
define|#
directive|define
name|BSD_HWS_PGA_GEN7
value|(0x04180)
end_define

begin_define
define|#
directive|define
name|BLT_HWS_PGA_GEN7
value|(0x04280)
end_define

begin_define
define|#
directive|define
name|RING_ACTHD
parameter_list|(
name|base
parameter_list|)
value|((base)+0x74)
end_define

begin_define
define|#
directive|define
name|RING_NOPID
parameter_list|(
name|base
parameter_list|)
value|((base)+0x94)
end_define

begin_define
define|#
directive|define
name|RING_IMR
parameter_list|(
name|base
parameter_list|)
value|((base)+0xa8)
end_define

begin_define
define|#
directive|define
name|TAIL_ADDR
value|0x001FFFF8
end_define

begin_define
define|#
directive|define
name|HEAD_WRAP_COUNT
value|0xFFE00000
end_define

begin_define
define|#
directive|define
name|HEAD_WRAP_ONE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|HEAD_ADDR
value|0x001FFFFC
end_define

begin_define
define|#
directive|define
name|RING_NR_PAGES
value|0x001FF000
end_define

begin_define
define|#
directive|define
name|RING_REPORT_MASK
value|0x00000006
end_define

begin_define
define|#
directive|define
name|RING_REPORT_64K
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RING_REPORT_128K
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RING_NO_REPORT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RING_VALID_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RING_VALID
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RING_INVALID
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RING_WAIT_I8XX
value|(1<<0)
end_define

begin_comment
comment|/* gen2, PRBx_HEAD */
end_comment

begin_define
define|#
directive|define
name|RING_WAIT
value|(1<<11)
end_define

begin_comment
comment|/* gen3+, PRBx_CTL */
end_comment

begin_define
define|#
directive|define
name|RING_WAIT_SEMAPHORE
value|(1<<10)
end_define

begin_comment
comment|/* gen6+ */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|PRB0_TAIL
value|0x02030
end_define

begin_define
define|#
directive|define
name|PRB0_HEAD
value|0x02034
end_define

begin_define
define|#
directive|define
name|PRB0_START
value|0x02038
end_define

begin_define
define|#
directive|define
name|PRB0_CTL
value|0x0203c
end_define

begin_define
define|#
directive|define
name|PRB1_TAIL
value|0x02040
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|PRB1_HEAD
value|0x02044
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|PRB1_START
value|0x02048
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|PRB1_CTL
value|0x0204c
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IPEIR_I965
value|0x02064
end_define

begin_define
define|#
directive|define
name|IPEHR_I965
value|0x02068
end_define

begin_define
define|#
directive|define
name|INSTDONE_I965
value|0x0206c
end_define

begin_define
define|#
directive|define
name|RING_IPEIR
parameter_list|(
name|base
parameter_list|)
value|((base)+0x64)
end_define

begin_define
define|#
directive|define
name|RING_IPEHR
parameter_list|(
name|base
parameter_list|)
value|((base)+0x68)
end_define

begin_define
define|#
directive|define
name|RING_INSTDONE
parameter_list|(
name|base
parameter_list|)
value|((base)+0x6c)
end_define

begin_define
define|#
directive|define
name|RING_INSTPS
parameter_list|(
name|base
parameter_list|)
value|((base)+0x70)
end_define

begin_define
define|#
directive|define
name|RING_DMA_FADD
parameter_list|(
name|base
parameter_list|)
value|((base)+0x78)
end_define

begin_define
define|#
directive|define
name|RING_INSTPM
parameter_list|(
name|base
parameter_list|)
value|((base)+0xc0)
end_define

begin_define
define|#
directive|define
name|INSTPS
value|0x02070
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_define
define|#
directive|define
name|INSTDONE1
value|0x0207c
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_define
define|#
directive|define
name|ACTHD_I965
value|0x02074
end_define

begin_define
define|#
directive|define
name|HWS_PGA
value|0x02080
end_define

begin_define
define|#
directive|define
name|HWS_ADDRESS_MASK
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|HWS_START_ADDRESS_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|PWRCTXA
value|0x2088
end_define

begin_comment
comment|/* 965GM+ only */
end_comment

begin_define
define|#
directive|define
name|PWRCTX_EN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|IPEIR
value|0x02088
end_define

begin_define
define|#
directive|define
name|IPEHR
value|0x0208c
end_define

begin_define
define|#
directive|define
name|INSTDONE
value|0x02090
end_define

begin_define
define|#
directive|define
name|NOPID
value|0x02094
end_define

begin_define
define|#
directive|define
name|HWSTAM
value|0x02098
end_define

begin_define
define|#
directive|define
name|ERROR_GEN6
value|0x040a0
end_define

begin_comment
comment|/* GM45+ chicken bits -- debug workaround bits that may be required  * for various sorts of correct behavior.  The top 16 bits of each are  * the enables for writing to the corresponding low bit.  */
end_comment

begin_define
define|#
directive|define
name|_3D_CHICKEN
value|0x02084
end_define

begin_define
define|#
directive|define
name|_3D_CHICKEN2
value|0x0208c
end_define

begin_comment
comment|/* Disables pipelining of read flushes past the SF-WIZ interface.  * Required on all Ironlake steppings according to the B-Spec, but the  * particular danger of not doing so is not specified.  */
end_comment

begin_define
define|#
directive|define
name|_3D_CHICKEN2_WM_READ_PIPELINED
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|_3D_CHICKEN3
value|0x02090
end_define

begin_define
define|#
directive|define
name|MI_MODE
value|0x0209c
end_define

begin_define
define|#
directive|define
name|VS_TIMER_DISPATCH
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MI_FLUSH_ENABLE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|GFX_MODE
value|0x02520
end_define

begin_define
define|#
directive|define
name|GFX_MODE_GEN7
value|0x0229c
end_define

begin_define
define|#
directive|define
name|RING_MODE_GEN7
parameter_list|(
name|ring
parameter_list|)
value|((ring)->mmio_base+0x29c)
end_define

begin_define
define|#
directive|define
name|GFX_RUN_LIST_ENABLE
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|GFX_TLB_INVALIDATE_ALWAYS
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|GFX_SURFACE_FAULT_ENABLE
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|GFX_REPLAY_MODE
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|GFX_PSMI_GRANULARITY
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|GFX_PPGTT_ENABLE
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|GFX_MODE_ENABLE
parameter_list|(
name|bit
parameter_list|)
value|(((bit)<< 16) | (bit))
end_define

begin_define
define|#
directive|define
name|GFX_MODE_DISABLE
parameter_list|(
name|bit
parameter_list|)
value|(((bit)<< 16) | (0))
end_define

begin_define
define|#
directive|define
name|SCPD0
value|0x0209c
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|IER
value|0x020a0
end_define

begin_define
define|#
directive|define
name|IIR
value|0x020a4
end_define

begin_define
define|#
directive|define
name|IMR
value|0x020a8
end_define

begin_define
define|#
directive|define
name|ISR
value|0x020ac
end_define

begin_define
define|#
directive|define
name|I915_PIPE_CONTROL_NOTIFY_INTERRUPT
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_PORT_INTERRUPT
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|I915_RENDER_COMMAND_PARSER_ERROR_INTERRUPT
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|I915_GMCH_THERMAL_SENSOR_EVENT_INTERRUPT
value|(1<<14)
end_define

begin_comment
comment|/* p-state */
end_comment

begin_define
define|#
directive|define
name|I915_HWB_OOM_INTERRUPT
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|I915_SYNC_STATUS_INTERRUPT
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_PLANE_A_FLIP_PENDING_INTERRUPT
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_PLANE_B_FLIP_PENDING_INTERRUPT
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|I915_OVERLAY_PLANE_FLIP_PENDING_INTERRUPT
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_PLANE_C_FLIP_PENDING_INTERRUPT
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_PIPE_A_VBLANK_INTERRUPT
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_PIPE_A_EVENT_INTERRUPT
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_PIPE_B_VBLANK_INTERRUPT
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|I915_DISPLAY_PIPE_B_EVENT_INTERRUPT
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|I915_DEBUG_INTERRUPT
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|I915_USER_INTERRUPT
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|I915_ASLE_INTERRUPT
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|I915_BSD_USER_INTERRUPT
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|EIR
value|0x020b0
end_define

begin_define
define|#
directive|define
name|EMR
value|0x020b4
end_define

begin_define
define|#
directive|define
name|ESR
value|0x020b8
end_define

begin_define
define|#
directive|define
name|GM45_ERROR_PAGE_TABLE
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|GM45_ERROR_MEM_PRIV
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|I915_ERROR_PAGE_TABLE
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|GM45_ERROR_CP_PRIV
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|I915_ERROR_MEMORY_REFRESH
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|I915_ERROR_INSTRUCTION
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|INSTPM
value|0x020c0
end_define

begin_define
define|#
directive|define
name|INSTPM_SELF_EN
value|(1<<12)
end_define

begin_comment
comment|/* 915GM only */
end_comment

begin_define
define|#
directive|define
name|INSTPM_AGPBUSY_DIS
value|(1<<11)
end_define

begin_comment
comment|/* gen3: when disabled, pending interrupts 					will not assert AGPBUSY# and will only 					be delivered when out of C3. */
end_comment

begin_define
define|#
directive|define
name|INSTPM_FORCE_ORDERING
value|(1<<7)
end_define

begin_comment
comment|/* GEN6+ */
end_comment

begin_define
define|#
directive|define
name|ACTHD
value|0x020c8
end_define

begin_define
define|#
directive|define
name|FW_BLC
value|0x020d8
end_define

begin_define
define|#
directive|define
name|FW_BLC2
value|0x020dc
end_define

begin_define
define|#
directive|define
name|FW_BLC_SELF
value|0x020e0
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|FW_BLC_SELF_EN_MASK
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|FW_BLC_SELF_FIFO_MASK
value|(1<<16)
end_define

begin_comment
comment|/* 945 only */
end_comment

begin_define
define|#
directive|define
name|FW_BLC_SELF_EN
value|(1<<15)
end_define

begin_comment
comment|/* 945 only */
end_comment

begin_define
define|#
directive|define
name|MM_BURST_LENGTH
value|0x00700000
end_define

begin_define
define|#
directive|define
name|MM_FIFO_WATERMARK
value|0x0001F000
end_define

begin_define
define|#
directive|define
name|LM_BURST_LENGTH
value|0x00000700
end_define

begin_define
define|#
directive|define
name|LM_FIFO_WATERMARK
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|MI_ARB_STATE
value|0x020e4
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_MASK_SHIFT
value|16
end_define

begin_comment
comment|/* shift for enable bits */
end_comment

begin_comment
comment|/* Make render/texture TLB fetches lower priorty than associated data  *   fetches. This is not turned on by default  */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_RENDER_TLB_LOW_PRIORITY
value|(1<< 15)
end_define

begin_comment
comment|/* Isoch request wait on GTT enable (Display A/B/C streams).  * Make isoch requests stall on the TLB update. May cause  * display underruns (test mode only)  */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_ISOCH_WAIT_GTT
value|(1<< 14)
end_define

begin_comment
comment|/* Block grant count for isoch requests when block count is  * set to a finite value.  */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_BLOCK_GRANT_MASK
value|(3<< 12)
end_define

begin_define
define|#
directive|define
name|MI_ARB_BLOCK_GRANT_8
value|(0<< 12)
end_define

begin_comment
comment|/* for 3 display planes */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_BLOCK_GRANT_4
value|(1<< 12)
end_define

begin_comment
comment|/* for 2 display planes */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_BLOCK_GRANT_2
value|(2<< 12)
end_define

begin_comment
comment|/* for 1 display plane */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_BLOCK_GRANT_0
value|(3<< 12)
end_define

begin_comment
comment|/* don't use */
end_comment

begin_comment
comment|/* Enable render writes to complete in C2/C3/C4 power states.  * If this isn't enabled, render writes are prevented in low  * power states. That seems bad to me.  */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_C3_LP_WRITE_ENABLE
value|(1<< 11)
end_define

begin_comment
comment|/* This acknowledges an async flip immediately instead  * of waiting for 2TLB fetches.  */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_ASYNC_FLIP_ACK_IMMEDIATE
value|(1<< 10)
end_define

begin_comment
comment|/* Enables non-sequential data reads through arbiter  */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_DUAL_DATA_PHASE_DISABLE
value|(1<< 9)
end_define

begin_comment
comment|/* Disable FSB snooping of cacheable write cycles from binner/render  * command stream  */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_CACHE_SNOOP_DISABLE
value|(1<< 8)
end_define

begin_comment
comment|/* Arbiter time slice for non-isoch streams */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_TIME_SLICE_MASK
value|(7<< 5)
end_define

begin_define
define|#
directive|define
name|MI_ARB_TIME_SLICE_1
value|(0<< 5)
end_define

begin_define
define|#
directive|define
name|MI_ARB_TIME_SLICE_2
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MI_ARB_TIME_SLICE_4
value|(2<< 5)
end_define

begin_define
define|#
directive|define
name|MI_ARB_TIME_SLICE_6
value|(3<< 5)
end_define

begin_define
define|#
directive|define
name|MI_ARB_TIME_SLICE_8
value|(4<< 5)
end_define

begin_define
define|#
directive|define
name|MI_ARB_TIME_SLICE_10
value|(5<< 5)
end_define

begin_define
define|#
directive|define
name|MI_ARB_TIME_SLICE_14
value|(6<< 5)
end_define

begin_define
define|#
directive|define
name|MI_ARB_TIME_SLICE_16
value|(7<< 5)
end_define

begin_comment
comment|/* Low priority grace period page size */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_LOW_PRIORITY_GRACE_4KB
value|(0<< 4)
end_define

begin_comment
comment|/* default */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_LOW_PRIORITY_GRACE_8KB
value|(1<< 4)
end_define

begin_comment
comment|/* Disable display A/B trickle feed */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_DISPLAY_TRICKLE_FEED_DISABLE
value|(1<< 2)
end_define

begin_comment
comment|/* Set display plane priority */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_DISPLAY_PRIORITY_A_B
value|(0<< 0)
end_define

begin_comment
comment|/* display A> display B */
end_comment

begin_define
define|#
directive|define
name|MI_ARB_DISPLAY_PRIORITY_B_A
value|(1<< 0)
end_define

begin_comment
comment|/* display B> display A */
end_comment

begin_define
define|#
directive|define
name|CACHE_MODE_0
value|0x02120
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|CM0_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CM0_IZ_OPT_DISABLE
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|CM0_ZR_OPT_DISABLE
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|CM0_STC_EVICT_DISABLE_LRA_SNB
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|CM0_DEPTH_EVICT_DISABLE
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|CM0_COLOR_EVICT_DISABLE
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|CM0_DEPTH_WRITE_DISABLE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|CM0_RC_OP_FLUSH_DISABLE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|BB_ADDR
value|0x02140
end_define

begin_comment
comment|/* 8 bytes */
end_comment

begin_define
define|#
directive|define
name|GFX_FLSH_CNTL
value|0x02170
end_define

begin_comment
comment|/* 915+ only */
end_comment

begin_define
define|#
directive|define
name|ECOSKPD
value|0x021d0
end_define

begin_define
define|#
directive|define
name|ECO_GATING_CX_ONLY
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ECO_FLIP_DONE
value|(1<<0)
end_define

begin_comment
comment|/* GEN6 interrupt control */
end_comment

begin_define
define|#
directive|define
name|GEN6_RENDER_HWSTAM
value|0x2098
end_define

begin_define
define|#
directive|define
name|GEN6_RENDER_IMR
value|0x20a8
end_define

begin_define
define|#
directive|define
name|GEN6_RENDER_CONTEXT_SWITCH_INTERRUPT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|GEN6_RENDER_PPGTT_PAGE_FAULT
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|GEN6_RENDER_TIMEOUT_COUNTER_EXPIRED
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|GEN6_RENDER_L3_PARITY_ERROR
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|GEN6_RENDER_PIPE_CONTROL_NOTIFY_INTERRUPT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|GEN6_RENDER_COMMAND_PARSER_MASTER_ERROR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|GEN6_RENDER_SYNC_STATUS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|GEN6_RENDER_DEBUG_INTERRUPT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|GEN6_RENDER_USER_INTERRUPT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GEN6_BLITTER_HWSTAM
value|0x22098
end_define

begin_define
define|#
directive|define
name|GEN6_BLITTER_IMR
value|0x220a8
end_define

begin_define
define|#
directive|define
name|GEN6_BLITTER_MI_FLUSH_DW_NOTIFY_INTERRUPT
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|GEN6_BLITTER_COMMAND_PARSER_MASTER_ERROR
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|GEN6_BLITTER_SYNC_STATUS
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|GEN6_BLITTER_USER_INTERRUPT
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|GEN6_BLITTER_ECOSKPD
value|0x221d0
end_define

begin_define
define|#
directive|define
name|GEN6_BLITTER_LOCK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GEN6_BLITTER_FBC_NOTIFY
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|GEN6_BSD_SLEEP_PSMI_CONTROL
value|0x12050
end_define

begin_define
define|#
directive|define
name|GEN6_BSD_SLEEP_PSMI_CONTROL_RC_ILDL_MESSAGE_MODIFY_MASK
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|GEN6_BSD_SLEEP_PSMI_CONTROL_RC_ILDL_MESSAGE_DISABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GEN6_BSD_SLEEP_PSMI_CONTROL_RC_ILDL_MESSAGE_ENABLE
value|0
end_define

begin_define
define|#
directive|define
name|GEN6_BSD_SLEEP_PSMI_CONTROL_IDLE_INDICATOR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|GEN6_BSD_HWSTAM
value|0x12098
end_define

begin_define
define|#
directive|define
name|GEN6_BSD_IMR
value|0x120a8
end_define

begin_define
define|#
directive|define
name|GEN6_BSD_USER_INTERRUPT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|GEN6_BSD_RNCID
value|0x12198
end_define

begin_comment
comment|/*  * Framebuffer compression (915+ only)  */
end_comment

begin_define
define|#
directive|define
name|FBC_CFB_BASE
value|0x03200
end_define

begin_comment
comment|/* 4k page aligned */
end_comment

begin_define
define|#
directive|define
name|FBC_LL_BASE
value|0x03204
end_define

begin_comment
comment|/* 4k page aligned */
end_comment

begin_define
define|#
directive|define
name|FBC_CONTROL
value|0x03208
end_define

begin_define
define|#
directive|define
name|FBC_CTL_EN
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_PERIODIC
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_INTERVAL_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_UNCOMPRESSIBLE
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_C3_IDLE
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_STRIDE_SHIFT
value|(5)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_FENCENO
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|FBC_COMMAND
value|0x0320c
end_define

begin_define
define|#
directive|define
name|FBC_CMD_COMPRESS
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|FBC_STATUS
value|0x03210
end_define

begin_define
define|#
directive|define
name|FBC_STAT_COMPRESSING
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|FBC_STAT_COMPRESSED
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|FBC_STAT_MODIFIED
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|FBC_STAT_CURRENT_LINE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|FBC_CONTROL2
value|0x03214
end_define

begin_define
define|#
directive|define
name|FBC_CTL_FENCE_DBL
value|(0<<4)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_IDLE_IMM
value|(0<<2)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_IDLE_FULL
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_IDLE_LINE
value|(2<<2)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_IDLE_DEBUG
value|(3<<2)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_CPU_FENCE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_PLANEA
value|(0<<0)
end_define

begin_define
define|#
directive|define
name|FBC_CTL_PLANEB
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|FBC_FENCE_OFF
value|0x0321b
end_define

begin_define
define|#
directive|define
name|FBC_TAG
value|0x03300
end_define

begin_define
define|#
directive|define
name|FBC_LL_SIZE
value|(1536)
end_define

begin_comment
comment|/* Framebuffer compression for GM45+ */
end_comment

begin_define
define|#
directive|define
name|DPFC_CB_BASE
value|0x3200
end_define

begin_define
define|#
directive|define
name|DPFC_CONTROL
value|0x3208
end_define

begin_define
define|#
directive|define
name|DPFC_CTL_EN
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|DPFC_CTL_PLANEA
value|(0<<30)
end_define

begin_define
define|#
directive|define
name|DPFC_CTL_PLANEB
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|DPFC_CTL_FENCE_EN
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|DPFC_CTL_PERSISTENT_MODE
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|DPFC_SR_EN
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|DPFC_CTL_LIMIT_1X
value|(0<<6)
end_define

begin_define
define|#
directive|define
name|DPFC_CTL_LIMIT_2X
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|DPFC_CTL_LIMIT_4X
value|(2<<6)
end_define

begin_define
define|#
directive|define
name|DPFC_RECOMP_CTL
value|0x320c
end_define

begin_define
define|#
directive|define
name|DPFC_RECOMP_STALL_EN
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|DPFC_RECOMP_STALL_WM_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|DPFC_RECOMP_STALL_WM_MASK
value|(0x07ff0000)
end_define

begin_define
define|#
directive|define
name|DPFC_RECOMP_TIMER_COUNT_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|DPFC_RECOMP_TIMER_COUNT_MASK
value|(0x0000003f)
end_define

begin_define
define|#
directive|define
name|DPFC_STATUS
value|0x3210
end_define

begin_define
define|#
directive|define
name|DPFC_INVAL_SEG_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|DPFC_INVAL_SEG_MASK
value|(0x07ff0000)
end_define

begin_define
define|#
directive|define
name|DPFC_COMP_SEG_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|DPFC_COMP_SEG_MASK
value|(0x000003ff)
end_define

begin_define
define|#
directive|define
name|DPFC_STATUS2
value|0x3214
end_define

begin_define
define|#
directive|define
name|DPFC_FENCE_YOFF
value|0x3218
end_define

begin_define
define|#
directive|define
name|DPFC_CHICKEN
value|0x3224
end_define

begin_define
define|#
directive|define
name|DPFC_HT_MODIFY
value|(1<<31)
end_define

begin_comment
comment|/* Framebuffer compression for Ironlake */
end_comment

begin_define
define|#
directive|define
name|ILK_DPFC_CB_BASE
value|0x43200
end_define

begin_define
define|#
directive|define
name|ILK_DPFC_CONTROL
value|0x43208
end_define

begin_comment
comment|/* The bit 28-8 is reserved */
end_comment

begin_define
define|#
directive|define
name|DPFC_RESERVED
value|(0x1FFFFF00)
end_define

begin_define
define|#
directive|define
name|ILK_DPFC_RECOMP_CTL
value|0x4320c
end_define

begin_define
define|#
directive|define
name|ILK_DPFC_STATUS
value|0x43210
end_define

begin_define
define|#
directive|define
name|ILK_DPFC_FENCE_YOFF
value|0x43218
end_define

begin_define
define|#
directive|define
name|ILK_DPFC_CHICKEN
value|0x43224
end_define

begin_define
define|#
directive|define
name|ILK_FBC_RT_BASE
value|0x2128
end_define

begin_define
define|#
directive|define
name|ILK_FBC_RT_VALID
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|ILK_DISPLAY_CHICKEN1
value|0x42000
end_define

begin_define
define|#
directive|define
name|ILK_FBCQ_DIS
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|ILK_PABSTRETCH_DIS
value|(1<<21)
end_define

begin_comment
comment|/*  * Framebuffer compression for Sandybridge  *  * The following two registers are of type GTTMMADR  */
end_comment

begin_define
define|#
directive|define
name|SNB_DPFC_CTL_SA
value|0x100100
end_define

begin_define
define|#
directive|define
name|SNB_CPU_FENCE_ENABLE
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|DPFC_CPU_FENCE_OFFSET
value|0x100104
end_define

begin_comment
comment|/*  * GPIO regs  */
end_comment

begin_define
define|#
directive|define
name|GPIOA
value|0x5010
end_define

begin_define
define|#
directive|define
name|GPIOB
value|0x5014
end_define

begin_define
define|#
directive|define
name|GPIOC
value|0x5018
end_define

begin_define
define|#
directive|define
name|GPIOD
value|0x501c
end_define

begin_define
define|#
directive|define
name|GPIOE
value|0x5020
end_define

begin_define
define|#
directive|define
name|GPIOF
value|0x5024
end_define

begin_define
define|#
directive|define
name|GPIOG
value|0x5028
end_define

begin_define
define|#
directive|define
name|GPIOH
value|0x502c
end_define

begin_define
define|#
directive|define
name|GPIO_CLOCK_DIR_MASK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GPIO_CLOCK_DIR_IN
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|GPIO_CLOCK_DIR_OUT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|GPIO_CLOCK_VAL_MASK
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|GPIO_CLOCK_VAL_OUT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|GPIO_CLOCK_VAL_IN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|GPIO_CLOCK_PULLUP_DISABLE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_DIR_MASK
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_DIR_IN
value|(0<< 9)
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_DIR_OUT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_VAL_MASK
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_VAL_OUT
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_VAL_IN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_PULLUP_DISABLE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|GMBUS0
value|0x5100
end_define

begin_comment
comment|/* clock/port select */
end_comment

begin_define
define|#
directive|define
name|GMBUS_RATE_100KHZ
value|(0<<8)
end_define

begin_define
define|#
directive|define
name|GMBUS_RATE_50KHZ
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|GMBUS_RATE_400KHZ
value|(2<<8)
end_define

begin_comment
comment|/* reserved on Pineview */
end_comment

begin_define
define|#
directive|define
name|GMBUS_RATE_1MHZ
value|(3<<8)
end_define

begin_comment
comment|/* reserved on Pineview */
end_comment

begin_define
define|#
directive|define
name|GMBUS_HOLD_EXT
value|(1<<7)
end_define

begin_comment
comment|/* 300ns hold time, rsvd on Pineview */
end_comment

begin_define
define|#
directive|define
name|GMBUS_PORT_DISABLED
value|0
end_define

begin_define
define|#
directive|define
name|GMBUS_PORT_SSC
value|1
end_define

begin_define
define|#
directive|define
name|GMBUS_PORT_VGADDC
value|2
end_define

begin_define
define|#
directive|define
name|GMBUS_PORT_PANEL
value|3
end_define

begin_define
define|#
directive|define
name|GMBUS_PORT_DPC
value|4
end_define

begin_comment
comment|/* HDMIC */
end_comment

begin_define
define|#
directive|define
name|GMBUS_PORT_DPB
value|5
end_define

begin_comment
comment|/* SDVO, HDMIB */
end_comment

begin_comment
comment|/* 6 reserved */
end_comment

begin_define
define|#
directive|define
name|GMBUS_PORT_DPD
value|7
end_define

begin_comment
comment|/* HDMID */
end_comment

begin_define
define|#
directive|define
name|GMBUS_NUM_PORTS
value|8
end_define

begin_define
define|#
directive|define
name|GMBUS1
value|0x5104
end_define

begin_comment
comment|/* command/status */
end_comment

begin_define
define|#
directive|define
name|GMBUS_SW_CLR_INT
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|GMBUS_SW_RDY
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|GMBUS_ENT
value|(1<<29)
end_define

begin_comment
comment|/* enable timeout */
end_comment

begin_define
define|#
directive|define
name|GMBUS_CYCLE_NONE
value|(0<<25)
end_define

begin_define
define|#
directive|define
name|GMBUS_CYCLE_WAIT
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|GMBUS_CYCLE_INDEX
value|(2<<25)
end_define

begin_define
define|#
directive|define
name|GMBUS_CYCLE_STOP
value|(4<<25)
end_define

begin_define
define|#
directive|define
name|GMBUS_BYTE_COUNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GMBUS_SLAVE_INDEX_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|GMBUS_SLAVE_ADDR_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|GMBUS_SLAVE_READ
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|GMBUS_SLAVE_WRITE
value|(0<<0)
end_define

begin_define
define|#
directive|define
name|GMBUS2
value|0x5108
end_define

begin_comment
comment|/* status */
end_comment

begin_define
define|#
directive|define
name|GMBUS_INUSE
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|GMBUS_HW_WAIT_PHASE
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|GMBUS_STALL_TIMEOUT
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|GMBUS_INT
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|GMBUS_HW_RDY
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|GMBUS_SATOER
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|GMBUS_ACTIVE
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|GMBUS3
value|0x510c
end_define

begin_comment
comment|/* data buffer bytes 3-0 */
end_comment

begin_define
define|#
directive|define
name|GMBUS4
value|0x5110
end_define

begin_comment
comment|/* interrupt mask (Pineview+) */
end_comment

begin_define
define|#
directive|define
name|GMBUS_SLAVE_TIMEOUT_EN
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|GMBUS_NAK_EN
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|GMBUS_IDLE_EN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|GMBUS_HW_WAIT_EN
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|GMBUS_HW_RDY_EN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|GMBUS5
value|0x5120
end_define

begin_comment
comment|/* byte index */
end_comment

begin_define
define|#
directive|define
name|GMBUS_2BYTE_INDEX_EN
value|(1<<31)
end_define

begin_comment
comment|/*  * Clock control& power management  */
end_comment

begin_define
define|#
directive|define
name|VGA0
value|0x6000
end_define

begin_define
define|#
directive|define
name|VGA1
value|0x6004
end_define

begin_define
define|#
directive|define
name|VGA_PD
value|0x6010
end_define

begin_define
define|#
directive|define
name|VGA0_PD_P2_DIV_4
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|VGA0_PD_P1_DIV_2
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|VGA0_PD_P1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|VGA0_PD_P1_MASK
value|(0x1f<< 0)
end_define

begin_define
define|#
directive|define
name|VGA1_PD_P2_DIV_4
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|VGA1_PD_P1_DIV_2
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|VGA1_PD_P1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|VGA1_PD_P1_MASK
value|(0x1f<< 8)
end_define

begin_define
define|#
directive|define
name|_DPLL_A
value|0x06014
end_define

begin_define
define|#
directive|define
name|_DPLL_B
value|0x06018
end_define

begin_define
define|#
directive|define
name|DPLL
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _DPLL_A, _DPLL_B)
end_define

begin_define
define|#
directive|define
name|DPLL_VCO_ENABLE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|DPLL_DVO_HIGH_SPEED
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|DPLL_SYNCLOCK_ENABLE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|DPLL_VGA_MODE_DIS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|DPLLB_MODE_DAC_SERIAL
value|(1<< 26)
end_define

begin_comment
comment|/* i915 */
end_comment

begin_define
define|#
directive|define
name|DPLLB_MODE_LVDS
value|(2<< 26)
end_define

begin_comment
comment|/* i915 */
end_comment

begin_define
define|#
directive|define
name|DPLL_MODE_MASK
value|(3<< 26)
end_define

begin_define
define|#
directive|define
name|DPLL_DAC_SERIAL_P2_CLOCK_DIV_10
value|(0<< 24)
end_define

begin_comment
comment|/* i915 */
end_comment

begin_define
define|#
directive|define
name|DPLL_DAC_SERIAL_P2_CLOCK_DIV_5
value|(1<< 24)
end_define

begin_comment
comment|/* i915 */
end_comment

begin_define
define|#
directive|define
name|DPLLB_LVDS_P2_CLOCK_DIV_14
value|(0<< 24)
end_define

begin_comment
comment|/* i915 */
end_comment

begin_define
define|#
directive|define
name|DPLLB_LVDS_P2_CLOCK_DIV_7
value|(1<< 24)
end_define

begin_comment
comment|/* i915 */
end_comment

begin_define
define|#
directive|define
name|DPLL_P2_CLOCK_DIV_MASK
value|0x03000000
end_define

begin_comment
comment|/* i915 */
end_comment

begin_define
define|#
directive|define
name|DPLL_FPA01_P1_POST_DIV_MASK
value|0x00ff0000
end_define

begin_comment
comment|/* i915 */
end_comment

begin_define
define|#
directive|define
name|DPLL_FPA01_P1_POST_DIV_MASK_PINEVIEW
value|0x00ff8000
end_define

begin_comment
comment|/* Pineview */
end_comment

begin_define
define|#
directive|define
name|SRX_INDEX
value|0x3c4
end_define

begin_define
define|#
directive|define
name|SRX_DATA
value|0x3c5
end_define

begin_define
define|#
directive|define
name|SR01
value|1
end_define

begin_define
define|#
directive|define
name|SR01_SCREEN_OFF
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|PPCR
value|0x61204
end_define

begin_define
define|#
directive|define
name|PPCR_ON
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DVOB
value|0x61140
end_define

begin_define
define|#
directive|define
name|DVOB_ON
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|DVOC
value|0x61160
end_define

begin_define
define|#
directive|define
name|DVOC_ON
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|LVDS
value|0x61180
end_define

begin_define
define|#
directive|define
name|LVDS_ON
value|(1<<31)
end_define

begin_comment
comment|/* Scratch pad debug 0 reg:  */
end_comment

begin_define
define|#
directive|define
name|DPLL_FPA01_P1_POST_DIV_MASK_I830
value|0x001f0000
end_define

begin_comment
comment|/*  * The i830 generation, in LVDS mode, defines P1 as the bit number set within  * this field (only one bit may be set).  */
end_comment

begin_define
define|#
directive|define
name|DPLL_FPA01_P1_POST_DIV_MASK_I830_LVDS
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|DPLL_FPA01_P1_POST_DIV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DPLL_FPA01_P1_POST_DIV_SHIFT_PINEVIEW
value|15
end_define

begin_comment
comment|/* i830, required in DVO non-gang */
end_comment

begin_define
define|#
directive|define
name|PLL_P2_DIVIDE_BY_4
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|PLL_P1_DIVIDE_BY_TWO
value|(1<< 21)
end_define

begin_comment
comment|/* i830 */
end_comment

begin_define
define|#
directive|define
name|PLL_REF_INPUT_DREFCLK
value|(0<< 13)
end_define

begin_define
define|#
directive|define
name|PLL_REF_INPUT_TVCLKINA
value|(1<< 13)
end_define

begin_comment
comment|/* i830 */
end_comment

begin_define
define|#
directive|define
name|PLL_REF_INPUT_TVCLKINBC
value|(2<< 13)
end_define

begin_comment
comment|/* SDVO TVCLKIN */
end_comment

begin_define
define|#
directive|define
name|PLLB_REF_INPUT_SPREADSPECTRUMIN
value|(3<< 13)
end_define

begin_define
define|#
directive|define
name|PLL_REF_INPUT_MASK
value|(3<< 13)
end_define

begin_define
define|#
directive|define
name|PLL_LOAD_PULSE_PHASE_SHIFT
value|9
end_define

begin_comment
comment|/* Ironlake */
end_comment

begin_define
define|#
directive|define
name|PLL_REF_SDVO_HDMI_MULTIPLIER_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|PLL_REF_SDVO_HDMI_MULTIPLIER_MASK
value|(7<< 9)
end_define

begin_define
define|#
directive|define
name|PLL_REF_SDVO_HDMI_MULTIPLIER
parameter_list|(
name|x
parameter_list|)
value|(((x)-1)<< 9)
end_define

begin_define
define|#
directive|define
name|DPLL_FPA1_P1_POST_DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DPLL_FPA1_P1_POST_DIV_MASK
value|0xff
end_define

begin_comment
comment|/*  * Parallel to Serial Load Pulse phase selection.  * Selects the phase for the 10X DPLL clock for the PCIe  * digital display port. The range is 4 to 13; 10 or more  * is just a flip delay. The default is 6  */
end_comment

begin_define
define|#
directive|define
name|PLL_LOAD_PULSE_PHASE_MASK
value|(0xf<< PLL_LOAD_PULSE_PHASE_SHIFT)
end_define

begin_define
define|#
directive|define
name|DISPLAY_RATE_SELECT_FPA1
value|(1<< 8)
end_define

begin_comment
comment|/*  * SDVO multiplier for 945G/GM. Not used on 965.  */
end_comment

begin_define
define|#
directive|define
name|SDVO_MULTIPLIER_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|SDVO_MULTIPLIER_SHIFT_HIRES
value|4
end_define

begin_define
define|#
directive|define
name|SDVO_MULTIPLIER_SHIFT_VGA
value|0
end_define

begin_define
define|#
directive|define
name|_DPLL_A_MD
value|0x0601c
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_comment
comment|/*  * UDI pixel divider, controlling how many pixels are stuffed into a packet.  *  * Value is pixels minus 1.  Must be set to 1 pixel for SDVO.  */
end_comment

begin_define
define|#
directive|define
name|DPLL_MD_UDI_DIVIDER_MASK
value|0x3f000000
end_define

begin_define
define|#
directive|define
name|DPLL_MD_UDI_DIVIDER_SHIFT
value|24
end_define

begin_comment
comment|/* UDI pixel divider for VGA, same as DPLL_MD_UDI_DIVIDER_MASK. */
end_comment

begin_define
define|#
directive|define
name|DPLL_MD_VGA_UDI_DIVIDER_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|DPLL_MD_VGA_UDI_DIVIDER_SHIFT
value|16
end_define

begin_comment
comment|/*  * SDVO/UDI pixel multiplier.  *  * SDVO requires that the bus clock rate be between 1 and 2 Ghz, and the bus  * clock rate is 10 times the DPLL clock.  At low resolution/refresh rate  * modes, the bus rate would be below the limits, so SDVO allows for stuffing  * dummy bytes in the datastream at an increased clock rate, with both sides of  * the link knowing how many bytes are fill.  *  * So, for a mode with a dotclock of 65Mhz, we would want to double the clock  * rate to 130Mhz to get a bus rate of 1.30Ghz.  The DPLL clock rate would be  * set to 130Mhz, and the SDVO multiplier set to 2x in this register and  * through an SDVO command.  *  * This register field has values of multiplication factor minus 1, with  * a maximum multiplier of 5 for SDVO.  */
end_comment

begin_define
define|#
directive|define
name|DPLL_MD_UDI_MULTIPLIER_MASK
value|0x00003f00
end_define

begin_define
define|#
directive|define
name|DPLL_MD_UDI_MULTIPLIER_SHIFT
value|8
end_define

begin_comment
comment|/*  * SDVO/UDI pixel multiplier for VGA, same as DPLL_MD_UDI_MULTIPLIER_MASK.  * This best be set to the default value (3) or the CRT won't work. No,  * I don't entirely understand what this does...  */
end_comment

begin_define
define|#
directive|define
name|DPLL_MD_VGA_UDI_MULTIPLIER_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|DPLL_MD_VGA_UDI_MULTIPLIER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|_DPLL_B_MD
value|0x06020
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_define
define|#
directive|define
name|DPLL_MD
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _DPLL_A_MD, _DPLL_B_MD)
end_define

begin_define
define|#
directive|define
name|_FPA0
value|0x06040
end_define

begin_define
define|#
directive|define
name|_FPA1
value|0x06044
end_define

begin_define
define|#
directive|define
name|_FPB0
value|0x06048
end_define

begin_define
define|#
directive|define
name|_FPB1
value|0x0604c
end_define

begin_define
define|#
directive|define
name|FP0
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _FPA0, _FPB0)
end_define

begin_define
define|#
directive|define
name|FP1
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _FPA1, _FPB1)
end_define

begin_define
define|#
directive|define
name|FP_N_DIV_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|FP_N_PINEVIEW_DIV_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|FP_N_DIV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FP_M1_DIV_MASK
value|0x00003f00
end_define

begin_define
define|#
directive|define
name|FP_M1_DIV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|FP_M2_DIV_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|FP_M2_PINEVIEW_DIV_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|FP_M2_DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DPLL_TEST
value|0x606c
end_define

begin_define
define|#
directive|define
name|DPLLB_TEST_SDVO_DIV_1
value|(0<< 22)
end_define

begin_define
define|#
directive|define
name|DPLLB_TEST_SDVO_DIV_2
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|DPLLB_TEST_SDVO_DIV_4
value|(2<< 22)
end_define

begin_define
define|#
directive|define
name|DPLLB_TEST_SDVO_DIV_MASK
value|(3<< 22)
end_define

begin_define
define|#
directive|define
name|DPLLB_TEST_N_BYPASS
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|DPLLB_TEST_M_BYPASS
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|DPLLB_INPUT_BUFFER_ENABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|DPLLA_TEST_N_BYPASS
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DPLLA_TEST_M_BYPASS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DPLLA_INPUT_BUFFER_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|D_STATE
value|0x6104
end_define

begin_define
define|#
directive|define
name|DSTATE_GFX_RESET_I830
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|DSTATE_PLL_D3_OFF
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|DSTATE_GFX_CLOCK_GATING
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|DSTATE_DOT_CLOCK_GATING
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DSPCLK_GATE_D
value|0x6200
end_define

begin_define
define|#
directive|define
name|DPUNIT_B_CLOCK_GATE_DISABLE
value|(1<< 30)
end_define

begin_comment
comment|/* 965 */
end_comment

begin_define
define|#
directive|define
name|VSUNIT_CLOCK_GATE_DISABLE
value|(1<< 29)
end_define

begin_comment
comment|/* 965 */
end_comment

begin_define
define|#
directive|define
name|VRHUNIT_CLOCK_GATE_DISABLE
value|(1<< 28)
end_define

begin_comment
comment|/* 965 */
end_comment

begin_define
define|#
directive|define
name|VRDUNIT_CLOCK_GATE_DISABLE
value|(1<< 27)
end_define

begin_comment
comment|/* 965 */
end_comment

begin_define
define|#
directive|define
name|AUDUNIT_CLOCK_GATE_DISABLE
value|(1<< 26)
end_define

begin_comment
comment|/* 965 */
end_comment

begin_define
define|#
directive|define
name|DPUNIT_A_CLOCK_GATE_DISABLE
value|(1<< 25)
end_define

begin_comment
comment|/* 965 */
end_comment

begin_define
define|#
directive|define
name|DPCUNIT_CLOCK_GATE_DISABLE
value|(1<< 24)
end_define

begin_comment
comment|/* 965 */
end_comment

begin_define
define|#
directive|define
name|TVRUNIT_CLOCK_GATE_DISABLE
value|(1<< 23)
end_define

begin_comment
comment|/* 915-945 */
end_comment

begin_define
define|#
directive|define
name|TVCUNIT_CLOCK_GATE_DISABLE
value|(1<< 22)
end_define

begin_comment
comment|/* 915-945 */
end_comment

begin_define
define|#
directive|define
name|TVFUNIT_CLOCK_GATE_DISABLE
value|(1<< 21)
end_define

begin_comment
comment|/* 915-945 */
end_comment

begin_define
define|#
directive|define
name|TVEUNIT_CLOCK_GATE_DISABLE
value|(1<< 20)
end_define

begin_comment
comment|/* 915-945 */
end_comment

begin_define
define|#
directive|define
name|DVSUNIT_CLOCK_GATE_DISABLE
value|(1<< 19)
end_define

begin_comment
comment|/* 915-945 */
end_comment

begin_define
define|#
directive|define
name|DSSUNIT_CLOCK_GATE_DISABLE
value|(1<< 18)
end_define

begin_comment
comment|/* 915-945 */
end_comment

begin_define
define|#
directive|define
name|DDBUNIT_CLOCK_GATE_DISABLE
value|(1<< 17)
end_define

begin_comment
comment|/* 915-945 */
end_comment

begin_define
define|#
directive|define
name|DPRUNIT_CLOCK_GATE_DISABLE
value|(1<< 16)
end_define

begin_comment
comment|/* 915-945 */
end_comment

begin_define
define|#
directive|define
name|DPFUNIT_CLOCK_GATE_DISABLE
value|(1<< 15)
end_define

begin_comment
comment|/* 915-945 */
end_comment

begin_define
define|#
directive|define
name|DPBMUNIT_CLOCK_GATE_DISABLE
value|(1<< 14)
end_define

begin_comment
comment|/* 915-945 */
end_comment

begin_define
define|#
directive|define
name|DPLSUNIT_CLOCK_GATE_DISABLE
value|(1<< 13)
end_define

begin_comment
comment|/* 915-945 */
end_comment

begin_define
define|#
directive|define
name|DPLUNIT_CLOCK_GATE_DISABLE
value|(1<< 12)
end_define

begin_comment
comment|/* 915-945 */
end_comment

begin_define
define|#
directive|define
name|DPOUNIT_CLOCK_GATE_DISABLE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|DPBUNIT_CLOCK_GATE_DISABLE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|DCUNIT_CLOCK_GATE_DISABLE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|DPUNIT_CLOCK_GATE_DISABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|VRUNIT_CLOCK_GATE_DISABLE
value|(1<< 7)
end_define

begin_comment
comment|/* 915+: reserved */
end_comment

begin_define
define|#
directive|define
name|OVHUNIT_CLOCK_GATE_DISABLE
value|(1<< 6)
end_define

begin_comment
comment|/* 830-865 */
end_comment

begin_define
define|#
directive|define
name|DPIOUNIT_CLOCK_GATE_DISABLE
value|(1<< 6)
end_define

begin_comment
comment|/* 915-945 */
end_comment

begin_define
define|#
directive|define
name|OVFUNIT_CLOCK_GATE_DISABLE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|OVBUNIT_CLOCK_GATE_DISABLE
value|(1<< 4)
end_define

begin_comment
comment|/**  * This bit must be set on the 830 to prevent hangs when turning off the  * overlay scaler.  */
end_comment

begin_define
define|#
directive|define
name|OVRUNIT_CLOCK_GATE_DISABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|OVCUNIT_CLOCK_GATE_DISABLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|OVUUNIT_CLOCK_GATE_DISABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|ZVUNIT_CLOCK_GATE_DISABLE
value|(1<< 0)
end_define

begin_comment
comment|/* 830 */
end_comment

begin_define
define|#
directive|define
name|OVLUNIT_CLOCK_GATE_DISABLE
value|(1<< 0)
end_define

begin_comment
comment|/* 845,865 */
end_comment

begin_define
define|#
directive|define
name|RENCLK_GATE_D1
value|0x6204
end_define

begin_define
define|#
directive|define
name|BLITTER_CLOCK_GATE_DISABLE
value|(1<< 13)
end_define

begin_comment
comment|/* 945GM only */
end_comment

begin_define
define|#
directive|define
name|MPEG_CLOCK_GATE_DISABLE
value|(1<< 12)
end_define

begin_comment
comment|/* 945GM only */
end_comment

begin_define
define|#
directive|define
name|PC_FE_CLOCK_GATE_DISABLE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|PC_BE_CLOCK_GATE_DISABLE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|WINDOWER_CLOCK_GATE_DISABLE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|INTERPOLATOR_CLOCK_GATE_DISABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|COLOR_CALCULATOR_CLOCK_GATE_DISABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|MOTION_COMP_CLOCK_GATE_DISABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MAG_CLOCK_GATE_DISABLE
value|(1<< 5)
end_define

begin_comment
comment|/** This bit must be unset on 855,865 */
end_comment

begin_define
define|#
directive|define
name|MECI_CLOCK_GATE_DISABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DCMP_CLOCK_GATE_DISABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MEC_CLOCK_GATE_DISABLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MECO_CLOCK_GATE_DISABLE
value|(1<< 1)
end_define

begin_comment
comment|/** This bit must be set on 855,865. */
end_comment

begin_define
define|#
directive|define
name|SV_CLOCK_GATE_DISABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|I915_MPEG_CLOCK_GATE_DISABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|I915_VLD_IP_PR_CLOCK_GATE_DISABLE
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|I915_MOTION_COMP_CLOCK_GATE_DISABLE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|I915_BD_BF_CLOCK_GATE_DISABLE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|I915_SF_SE_CLOCK_GATE_DISABLE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|I915_WM_CLOCK_GATE_DISABLE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|I915_IZ_CLOCK_GATE_DISABLE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|I915_PI_CLOCK_GATE_DISABLE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|I915_DI_CLOCK_GATE_DISABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|I915_SH_SV_CLOCK_GATE_DISABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|I915_PL_DG_QC_FT_CLOCK_GATE_DISABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|I915_SC_CLOCK_GATE_DISABLE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|I915_FL_CLOCK_GATE_DISABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|I915_DM_CLOCK_GATE_DISABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|I915_PS_CLOCK_GATE_DISABLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|I915_CC_CLOCK_GATE_DISABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|I915_BY_CLOCK_GATE_DISABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|I965_RCZ_CLOCK_GATE_DISABLE
value|(1<< 30)
end_define

begin_comment
comment|/** This bit must always be set on 965G/965GM */
end_comment

begin_define
define|#
directive|define
name|I965_RCC_CLOCK_GATE_DISABLE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|I965_RCPB_CLOCK_GATE_DISABLE
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|I965_DAP_CLOCK_GATE_DISABLE
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|I965_ROC_CLOCK_GATE_DISABLE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|I965_GW_CLOCK_GATE_DISABLE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|I965_TD_CLOCK_GATE_DISABLE
value|(1<< 24)
end_define

begin_comment
comment|/** This bit must always be set on 965G */
end_comment

begin_define
define|#
directive|define
name|I965_ISC_CLOCK_GATE_DISABLE
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|I965_IC_CLOCK_GATE_DISABLE
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|I965_EU_CLOCK_GATE_DISABLE
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|I965_IF_CLOCK_GATE_DISABLE
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|I965_TC_CLOCK_GATE_DISABLE
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|I965_SO_CLOCK_GATE_DISABLE
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|I965_FBC_CLOCK_GATE_DISABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|I965_MARI_CLOCK_GATE_DISABLE
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|I965_MASF_CLOCK_GATE_DISABLE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|I965_MAWB_CLOCK_GATE_DISABLE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|I965_EM_CLOCK_GATE_DISABLE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|I965_UC_CLOCK_GATE_DISABLE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|I965_SI_CLOCK_GATE_DISABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|I965_MT_CLOCK_GATE_DISABLE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|I965_PL_CLOCK_GATE_DISABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|I965_DG_CLOCK_GATE_DISABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|I965_QC_CLOCK_GATE_DISABLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|I965_FT_CLOCK_GATE_DISABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|I965_DM_CLOCK_GATE_DISABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RENCLK_GATE_D2
value|0x6208
end_define

begin_define
define|#
directive|define
name|VF_UNIT_CLOCK_GATE_DISABLE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|GS_UNIT_CLOCK_GATE_DISABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|CL_UNIT_CLOCK_GATE_DISABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RAMCLK_GATE_D
value|0x6210
end_define

begin_comment
comment|/* CRL only */
end_comment

begin_define
define|#
directive|define
name|DEUC
value|0x6214
end_define

begin_comment
comment|/* CRL only */
end_comment

begin_comment
comment|/*  * Palette regs  */
end_comment

begin_define
define|#
directive|define
name|_PALETTE_A
value|0x0a000
end_define

begin_define
define|#
directive|define
name|_PALETTE_B
value|0x0a800
end_define

begin_define
define|#
directive|define
name|PALETTE
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PALETTE_A, _PALETTE_B)
end_define

begin_comment
comment|/* MCH MMIO space */
end_comment

begin_comment
comment|/*  * MCHBAR mirror.  *  * This mirrors the MCHBAR MMIO space whose location is determined by  * device 0 function 0's pci config register 0x44 or 0x48 and matches it in  * every way.  It is not accessible from the CP register read instructions.  *  */
end_comment

begin_define
define|#
directive|define
name|MCHBAR_MIRROR_BASE
value|0x10000
end_define

begin_define
define|#
directive|define
name|MCHBAR_MIRROR_BASE_SNB
value|0x140000
end_define

begin_comment
comment|/** 915-945 and GM965 MCH register controlling DRAM channel access */
end_comment

begin_define
define|#
directive|define
name|DCC
value|0x10200
end_define

begin_define
define|#
directive|define
name|DCC_ADDRESSING_MODE_SINGLE_CHANNEL
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|DCC_ADDRESSING_MODE_DUAL_CHANNEL_ASYMMETRIC
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DCC_ADDRESSING_MODE_DUAL_CHANNEL_INTERLEAVED
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|DCC_ADDRESSING_MODE_MASK
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|DCC_CHANNEL_XOR_DISABLE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|DCC_CHANNEL_XOR_BIT_17
value|(1<< 9)
end_define

begin_comment
comment|/** Pineview MCH register contains DDR3 setting */
end_comment

begin_define
define|#
directive|define
name|CSHRDDR3CTL
value|0x101a8
end_define

begin_define
define|#
directive|define
name|CSHRDDR3CTL_DDR3
value|(1<< 2)
end_define

begin_comment
comment|/** 965 MCH register controlling DRAM channel configuration */
end_comment

begin_define
define|#
directive|define
name|C0DRB3
value|0x10206
end_define

begin_define
define|#
directive|define
name|C1DRB3
value|0x10606
end_define

begin_comment
comment|/** snb MCH registers for reading the DRAM channel configuration */
end_comment

begin_define
define|#
directive|define
name|MAD_DIMM_C0
value|(MCHBAR_MIRROR_BASE_SNB + 0x5004)
end_define

begin_define
define|#
directive|define
name|MAD_DIMM_C1
value|(MCHBAR_MIRROR_BASE_SNB + 0x5008)
end_define

begin_define
define|#
directive|define
name|MAD_DIMM_C2
value|(MCHBAR_MIRROR_BASE_SNB + 0x500C)
end_define

begin_define
define|#
directive|define
name|MAD_DIMM_ECC_MASK
value|(0x3<< 24)
end_define

begin_define
define|#
directive|define
name|MAD_DIMM_ECC_OFF
value|(0x0<< 24)
end_define

begin_define
define|#
directive|define
name|MAD_DIMM_ECC_IO_ON_LOGIC_OFF
value|(0x1<< 24)
end_define

begin_define
define|#
directive|define
name|MAD_DIMM_ECC_IO_OFF_LOGIC_ON
value|(0x2<< 24)
end_define

begin_define
define|#
directive|define
name|MAD_DIMM_ECC_ON
value|(0x3<< 24)
end_define

begin_define
define|#
directive|define
name|MAD_DIMM_ENH_INTERLEAVE
value|(0x1<< 22)
end_define

begin_define
define|#
directive|define
name|MAD_DIMM_RANK_INTERLEAVE
value|(0x1<< 21)
end_define

begin_define
define|#
directive|define
name|MAD_DIMM_B_WIDTH_X16
value|(0x1<< 20)
end_define

begin_comment
comment|/* X8 chips if unset */
end_comment

begin_define
define|#
directive|define
name|MAD_DIMM_A_WIDTH_X16
value|(0x1<< 19)
end_define

begin_comment
comment|/* X8 chips if unset */
end_comment

begin_define
define|#
directive|define
name|MAD_DIMM_B_DUAL_RANK
value|(0x1<< 18)
end_define

begin_define
define|#
directive|define
name|MAD_DIMM_A_DUAL_RANK
value|(0x1<< 17)
end_define

begin_define
define|#
directive|define
name|MAD_DIMM_A_SELECT
value|(0x1<< 16)
end_define

begin_comment
comment|/* DIMM sizes are in multiples of 256mb. */
end_comment

begin_define
define|#
directive|define
name|MAD_DIMM_B_SIZE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MAD_DIMM_B_SIZE_MASK
value|(0xff<< MAD_DIMM_B_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|MAD_DIMM_A_SIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MAD_DIMM_A_SIZE_MASK
value|(0xff<< MAD_DIMM_A_SIZE_SHIFT)
end_define

begin_comment
comment|/* Clocking configuration register */
end_comment

begin_define
define|#
directive|define
name|CLKCFG
value|0x10c00
end_define

begin_define
define|#
directive|define
name|CLKCFG_FSB_400
value|(5<< 0)
end_define

begin_comment
comment|/* hrawclk 100 */
end_comment

begin_define
define|#
directive|define
name|CLKCFG_FSB_533
value|(1<< 0)
end_define

begin_comment
comment|/* hrawclk 133 */
end_comment

begin_define
define|#
directive|define
name|CLKCFG_FSB_667
value|(3<< 0)
end_define

begin_comment
comment|/* hrawclk 166 */
end_comment

begin_define
define|#
directive|define
name|CLKCFG_FSB_800
value|(2<< 0)
end_define

begin_comment
comment|/* hrawclk 200 */
end_comment

begin_define
define|#
directive|define
name|CLKCFG_FSB_1067
value|(6<< 0)
end_define

begin_comment
comment|/* hrawclk 266 */
end_comment

begin_define
define|#
directive|define
name|CLKCFG_FSB_1333
value|(7<< 0)
end_define

begin_comment
comment|/* hrawclk 333 */
end_comment

begin_comment
comment|/* Note, below two are guess */
end_comment

begin_define
define|#
directive|define
name|CLKCFG_FSB_1600
value|(4<< 0)
end_define

begin_comment
comment|/* hrawclk 400 */
end_comment

begin_define
define|#
directive|define
name|CLKCFG_FSB_1600_ALT
value|(0<< 0)
end_define

begin_comment
comment|/* hrawclk 400 */
end_comment

begin_define
define|#
directive|define
name|CLKCFG_FSB_MASK
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|CLKCFG_MEM_533
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|CLKCFG_MEM_667
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|CLKCFG_MEM_800
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|CLKCFG_MEM_MASK
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|TSC1
value|0x11001
end_define

begin_define
define|#
directive|define
name|TSE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|I915_TR1
value|0x11006
end_define

begin_define
define|#
directive|define
name|TSFS
value|0x11020
end_define

begin_define
define|#
directive|define
name|TSFS_SLOPE_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|TSFS_SLOPE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|TSFS_INTR_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|CRSTANDVID
value|0x11100
end_define

begin_define
define|#
directive|define
name|PXVFREQ_BASE
value|0x11110
end_define

begin_comment
comment|/* P[0-15]VIDFREQ (0x1114c) (Ironlake) */
end_comment

begin_define
define|#
directive|define
name|PXVFREQ_PX_MASK
value|0x7f000000
end_define

begin_define
define|#
directive|define
name|PXVFREQ_PX_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|VIDFREQ_BASE
value|0x11110
end_define

begin_define
define|#
directive|define
name|VIDFREQ1
value|0x11110
end_define

begin_comment
comment|/* VIDFREQ1-4 (0x1111c) (Cantiga) */
end_comment

begin_define
define|#
directive|define
name|VIDFREQ2
value|0x11114
end_define

begin_define
define|#
directive|define
name|VIDFREQ3
value|0x11118
end_define

begin_define
define|#
directive|define
name|VIDFREQ4
value|0x1111c
end_define

begin_define
define|#
directive|define
name|VIDFREQ_P0_MASK
value|0x1f000000
end_define

begin_define
define|#
directive|define
name|VIDFREQ_P0_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|VIDFREQ_P0_CSCLK_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|VIDFREQ_P0_CSCLK_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|VIDFREQ_P0_CRCLK_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|VIDFREQ_P0_CRCLK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|VIDFREQ_P1_MASK
value|0x00001f00
end_define

begin_define
define|#
directive|define
name|VIDFREQ_P1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|VIDFREQ_P1_CSCLK_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|VIDFREQ_P1_CSCLK_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|VIDFREQ_P1_CRCLK_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|INTTOEXT_BASE_ILK
value|0x11300
end_define

begin_define
define|#
directive|define
name|INTTOEXT_BASE
value|0x11120
end_define

begin_comment
comment|/* INTTOEXT1-8 (0x1113c) */
end_comment

begin_define
define|#
directive|define
name|INTTOEXT_MAP3_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|INTTOEXT_MAP3_MASK
value|(0x1f<< INTTOEXT_MAP3_SHIFT)
end_define

begin_define
define|#
directive|define
name|INTTOEXT_MAP2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|INTTOEXT_MAP2_MASK
value|(0x1f<< INTTOEXT_MAP2_SHIFT)
end_define

begin_define
define|#
directive|define
name|INTTOEXT_MAP1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|INTTOEXT_MAP1_MASK
value|(0x1f<< INTTOEXT_MAP1_SHIFT)
end_define

begin_define
define|#
directive|define
name|INTTOEXT_MAP0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|INTTOEXT_MAP0_MASK
value|(0x1f<< INTTOEXT_MAP0_SHIFT)
end_define

begin_define
define|#
directive|define
name|MEMSWCTL
value|0x11170
end_define

begin_comment
comment|/* Ironlake only */
end_comment

begin_define
define|#
directive|define
name|MEMCTL_CMD_MASK
value|0xe000
end_define

begin_define
define|#
directive|define
name|MEMCTL_CMD_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|MEMCTL_CMD_RCLK_OFF
value|0
end_define

begin_define
define|#
directive|define
name|MEMCTL_CMD_RCLK_ON
value|1
end_define

begin_define
define|#
directive|define
name|MEMCTL_CMD_CHFREQ
value|2
end_define

begin_define
define|#
directive|define
name|MEMCTL_CMD_CHVID
value|3
end_define

begin_define
define|#
directive|define
name|MEMCTL_CMD_VMMOFF
value|4
end_define

begin_define
define|#
directive|define
name|MEMCTL_CMD_VMMON
value|5
end_define

begin_define
define|#
directive|define
name|MEMCTL_CMD_STS
value|(1<<12)
end_define

begin_comment
comment|/* write 1 triggers command, clears 					   when command complete */
end_comment

begin_define
define|#
directive|define
name|MEMCTL_FREQ_MASK
value|0x0f00
end_define

begin_comment
comment|/* jitter, from 0-15 */
end_comment

begin_define
define|#
directive|define
name|MEMCTL_FREQ_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MEMCTL_SFCAVM
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|MEMCTL_TGT_VID_MASK
value|0x007f
end_define

begin_define
define|#
directive|define
name|MEMIHYST
value|0x1117c
end_define

begin_define
define|#
directive|define
name|MEMINTREN
value|0x11180
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|MEMINT_RSEXIT_EN
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|MEMINT_CX_SUPR_EN
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|MEMINT_CONT_BUSY_EN
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|MEMINT_AVG_BUSY_EN
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|MEMINT_EVAL_CHG_EN
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|MEMINT_MON_IDLE_EN
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|MEMINT_UP_EVAL_EN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|MEMINT_DOWN_EVAL_EN
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|MEMINT_SW_CMD_EN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|MEMINTRSTR
value|0x11182
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|MEM_RSEXIT_MASK
value|0xc000
end_define

begin_define
define|#
directive|define
name|MEM_RSEXIT_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|MEM_CONT_BUSY_MASK
value|0x3000
end_define

begin_define
define|#
directive|define
name|MEM_CONT_BUSY_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MEM_AVG_BUSY_MASK
value|0x0c00
end_define

begin_define
define|#
directive|define
name|MEM_AVG_BUSY_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|MEM_EVAL_CHG_MASK
value|0x0300
end_define

begin_define
define|#
directive|define
name|MEM_EVAL_BUSY_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MEM_MON_IDLE_MASK
value|0x00c0
end_define

begin_define
define|#
directive|define
name|MEM_MON_IDLE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|MEM_UP_EVAL_MASK
value|0x0030
end_define

begin_define
define|#
directive|define
name|MEM_UP_EVAL_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MEM_DOWN_EVAL_MASK
value|0x000c
end_define

begin_define
define|#
directive|define
name|MEM_DOWN_EVAL_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|MEM_SW_CMD_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|MEM_INT_STEER_GFX
value|0
end_define

begin_define
define|#
directive|define
name|MEM_INT_STEER_CMR
value|1
end_define

begin_define
define|#
directive|define
name|MEM_INT_STEER_SMI
value|2
end_define

begin_define
define|#
directive|define
name|MEM_INT_STEER_SCI
value|3
end_define

begin_define
define|#
directive|define
name|MEMINTRSTS
value|0x11184
end_define

begin_define
define|#
directive|define
name|MEMINT_RSEXIT
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|MEMINT_CONT_BUSY
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|MEMINT_AVG_BUSY
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|MEMINT_EVAL_CHG
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|MEMINT_MON_IDLE
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|MEMINT_UP_EVAL
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|MEMINT_DOWN_EVAL
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|MEMINT_SW_CMD
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|MEMMODECTL
value|0x11190
end_define

begin_define
define|#
directive|define
name|MEMMODE_BOOST_EN
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|MEMMODE_BOOST_FREQ_MASK
value|0x0f000000
end_define

begin_comment
comment|/* jitter for boost, 0-15 */
end_comment

begin_define
define|#
directive|define
name|MEMMODE_BOOST_FREQ_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|MEMMODE_IDLE_MODE_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|MEMMODE_IDLE_MODE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MEMMODE_IDLE_MODE_EVAL
value|0
end_define

begin_define
define|#
directive|define
name|MEMMODE_IDLE_MODE_CONT
value|1
end_define

begin_define
define|#
directive|define
name|MEMMODE_HWIDLE_EN
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|MEMMODE_SWMODE_EN
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|MEMMODE_RCLK_GATE
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|MEMMODE_HW_UPDATE
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|MEMMODE_FSTART_MASK
value|0x00000f00
end_define

begin_comment
comment|/* starting jitter, 0-15 */
end_comment

begin_define
define|#
directive|define
name|MEMMODE_FSTART_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MEMMODE_FMAX_MASK
value|0x000000f0
end_define

begin_comment
comment|/* max jitter, 0-15 */
end_comment

begin_define
define|#
directive|define
name|MEMMODE_FMAX_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MEMMODE_FMIN_MASK
value|0x0000000f
end_define

begin_comment
comment|/* min jitter, 0-15 */
end_comment

begin_define
define|#
directive|define
name|RCBMAXAVG
value|0x1119c
end_define

begin_define
define|#
directive|define
name|MEMSWCTL2
value|0x1119e
end_define

begin_comment
comment|/* Cantiga only */
end_comment

begin_define
define|#
directive|define
name|SWMEMCMD_RENDER_OFF
value|(0<< 13)
end_define

begin_define
define|#
directive|define
name|SWMEMCMD_RENDER_ON
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|SWMEMCMD_SWFREQ
value|(2<< 13)
end_define

begin_define
define|#
directive|define
name|SWMEMCMD_TARVID
value|(3<< 13)
end_define

begin_define
define|#
directive|define
name|SWMEMCMD_VRM_OFF
value|(4<< 13)
end_define

begin_define
define|#
directive|define
name|SWMEMCMD_VRM_ON
value|(5<< 13)
end_define

begin_define
define|#
directive|define
name|CMDSTS
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|SFCAVM
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|SWFREQ_MASK
value|0x0380
end_define

begin_comment
comment|/* P0-7 */
end_comment

begin_define
define|#
directive|define
name|SWFREQ_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|TARVID_MASK
value|0x001f
end_define

begin_define
define|#
directive|define
name|MEMSTAT_CTG
value|0x111a0
end_define

begin_define
define|#
directive|define
name|RCBMINAVG
value|0x111a0
end_define

begin_define
define|#
directive|define
name|RCUPEI
value|0x111b0
end_define

begin_define
define|#
directive|define
name|RCDNEI
value|0x111b4
end_define

begin_define
define|#
directive|define
name|RSTDBYCTL
value|0x111b8
end_define

begin_define
define|#
directive|define
name|RS1EN
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|RS2EN
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|RS3EN
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|D3RS3EN
value|(1<<28)
end_define

begin_comment
comment|/* Display D3 imlies RS3 */
end_comment

begin_define
define|#
directive|define
name|SWPROMORSX
value|(1<<27)
end_define

begin_comment
comment|/* RSx promotion timers ignored */
end_comment

begin_define
define|#
directive|define
name|RCWAKERW
value|(1<<26)
end_define

begin_comment
comment|/* Resetwarn from PCH causes wakeup */
end_comment

begin_define
define|#
directive|define
name|DPRSLPVREN
value|(1<<25)
end_define

begin_comment
comment|/* Fast voltage ramp enable */
end_comment

begin_define
define|#
directive|define
name|GFXTGHYST
value|(1<<24)
end_define

begin_comment
comment|/* Hysteresis to allow trunk gating */
end_comment

begin_define
define|#
directive|define
name|RCX_SW_EXIT
value|(1<<23)
end_define

begin_comment
comment|/* Leave RSx and prevent re-entry */
end_comment

begin_define
define|#
directive|define
name|RSX_STATUS_MASK
value|(7<<20)
end_define

begin_define
define|#
directive|define
name|RSX_STATUS_ON
value|(0<<20)
end_define

begin_define
define|#
directive|define
name|RSX_STATUS_RC1
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|RSX_STATUS_RC1E
value|(2<<20)
end_define

begin_define
define|#
directive|define
name|RSX_STATUS_RS1
value|(3<<20)
end_define

begin_define
define|#
directive|define
name|RSX_STATUS_RS2
value|(4<<20)
end_define

begin_comment
comment|/* aka rc6 */
end_comment

begin_define
define|#
directive|define
name|RSX_STATUS_RSVD
value|(5<<20)
end_define

begin_comment
comment|/* deep rc6 unsupported on ilk */
end_comment

begin_define
define|#
directive|define
name|RSX_STATUS_RS3
value|(6<<20)
end_define

begin_comment
comment|/* rs3 unsupported on ilk */
end_comment

begin_define
define|#
directive|define
name|RSX_STATUS_RSVD2
value|(7<<20)
end_define

begin_define
define|#
directive|define
name|UWRCRSXE
value|(1<<19)
end_define

begin_comment
comment|/* wake counter limit prevents rsx */
end_comment

begin_define
define|#
directive|define
name|RSCRP
value|(1<<18)
end_define

begin_comment
comment|/* rs requests control on rs1/2 reqs */
end_comment

begin_define
define|#
directive|define
name|JRSC
value|(1<<17)
end_define

begin_comment
comment|/* rsx coupled to cpu c-state */
end_comment

begin_define
define|#
directive|define
name|RS2INC0
value|(1<<16)
end_define

begin_comment
comment|/* allow rs2 in cpu c0 */
end_comment

begin_define
define|#
directive|define
name|RS1CONTSAV_MASK
value|(3<<14)
end_define

begin_define
define|#
directive|define
name|RS1CONTSAV_NO_RS1
value|(0<<14)
end_define

begin_comment
comment|/* rs1 doesn't save/restore context */
end_comment

begin_define
define|#
directive|define
name|RS1CONTSAV_RSVD
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|RS1CONTSAV_SAVE_RS1
value|(2<<14)
end_define

begin_comment
comment|/* rs1 saves context */
end_comment

begin_define
define|#
directive|define
name|RS1CONTSAV_FULL_RS1
value|(3<<14)
end_define

begin_comment
comment|/* rs1 saves and restores context */
end_comment

begin_define
define|#
directive|define
name|NORMSLEXLAT_MASK
value|(3<<12)
end_define

begin_define
define|#
directive|define
name|SLOW_RS123
value|(0<<12)
end_define

begin_define
define|#
directive|define
name|SLOW_RS23
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|SLOW_RS3
value|(2<<12)
end_define

begin_define
define|#
directive|define
name|NORMAL_RS123
value|(3<<12)
end_define

begin_define
define|#
directive|define
name|RCMODE_TIMEOUT
value|(1<<11)
end_define

begin_comment
comment|/* 0 is eval interval method */
end_comment

begin_define
define|#
directive|define
name|IMPROMOEN
value|(1<<10)
end_define

begin_comment
comment|/* promo is immediate or delayed until next idle interval (only for timeout method above) */
end_comment

begin_define
define|#
directive|define
name|RCENTSYNC
value|(1<<9)
end_define

begin_comment
comment|/* rs coupled to cpu c-state (3/6/7) */
end_comment

begin_define
define|#
directive|define
name|STATELOCK
value|(1<<7)
end_define

begin_comment
comment|/* locked to rs_cstate if 0 */
end_comment

begin_define
define|#
directive|define
name|RS_CSTATE_MASK
value|(3<<4)
end_define

begin_define
define|#
directive|define
name|RS_CSTATE_C367_RS1
value|(0<<4)
end_define

begin_define
define|#
directive|define
name|RS_CSTATE_C36_RS1_C7_RS2
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|RS_CSTATE_RSVD
value|(2<<4)
end_define

begin_define
define|#
directive|define
name|RS_CSTATE_C367_RS2
value|(3<<4)
end_define

begin_define
define|#
directive|define
name|REDSAVES
value|(1<<3)
end_define

begin_comment
comment|/* no context save if was idle during rs0 */
end_comment

begin_define
define|#
directive|define
name|REDRESTORES
value|(1<<2)
end_define

begin_comment
comment|/* no restore if was idle during rs0 */
end_comment

begin_define
define|#
directive|define
name|VIDCTL
value|0x111c0
end_define

begin_define
define|#
directive|define
name|VIDSTS
value|0x111c8
end_define

begin_define
define|#
directive|define
name|VIDSTART
value|0x111cc
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|MEMSTAT_ILK
value|0x111f8
end_define

begin_define
define|#
directive|define
name|MEMSTAT_VID_MASK
value|0x7f00
end_define

begin_define
define|#
directive|define
name|MEMSTAT_VID_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MEMSTAT_PSTATE_MASK
value|0x00f8
end_define

begin_define
define|#
directive|define
name|MEMSTAT_PSTATE_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|MEMSTAT_MON_ACTV
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|MEMSTAT_SRC_CTL_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|MEMSTAT_SRC_CTL_CORE
value|0
end_define

begin_define
define|#
directive|define
name|MEMSTAT_SRC_CTL_TRB
value|1
end_define

begin_define
define|#
directive|define
name|MEMSTAT_SRC_CTL_THM
value|2
end_define

begin_define
define|#
directive|define
name|MEMSTAT_SRC_CTL_STDBY
value|3
end_define

begin_define
define|#
directive|define
name|RCPREVBSYTUPAVG
value|0x113b8
end_define

begin_define
define|#
directive|define
name|RCPREVBSYTDNAVG
value|0x113bc
end_define

begin_define
define|#
directive|define
name|PMMISC
value|0x11214
end_define

begin_define
define|#
directive|define
name|MCPPCE_EN
value|(1<<0)
end_define

begin_comment
comment|/* enable PM_MSG from PCH->MPC */
end_comment

begin_define
define|#
directive|define
name|SDEW
value|0x1124c
end_define

begin_define
define|#
directive|define
name|CSIEW0
value|0x11250
end_define

begin_define
define|#
directive|define
name|CSIEW1
value|0x11254
end_define

begin_define
define|#
directive|define
name|CSIEW2
value|0x11258
end_define

begin_define
define|#
directive|define
name|PEW
value|0x1125c
end_define

begin_define
define|#
directive|define
name|DEW
value|0x11270
end_define

begin_define
define|#
directive|define
name|MCHAFE
value|0x112c0
end_define

begin_define
define|#
directive|define
name|CSIEC
value|0x112e0
end_define

begin_define
define|#
directive|define
name|DMIEC
value|0x112e4
end_define

begin_define
define|#
directive|define
name|DDREC
value|0x112e8
end_define

begin_define
define|#
directive|define
name|PEG0EC
value|0x112ec
end_define

begin_define
define|#
directive|define
name|PEG1EC
value|0x112f0
end_define

begin_define
define|#
directive|define
name|GFXEC
value|0x112f4
end_define

begin_define
define|#
directive|define
name|RPPREVBSYTUPAVG
value|0x113b8
end_define

begin_define
define|#
directive|define
name|RPPREVBSYTDNAVG
value|0x113bc
end_define

begin_define
define|#
directive|define
name|ECR
value|0x11600
end_define

begin_define
define|#
directive|define
name|ECR_GPFE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|ECR_IMONE
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|ECR_CAP_MASK
value|0x0000001f
end_define

begin_comment
comment|/* Event range, 0-31 */
end_comment

begin_define
define|#
directive|define
name|OGW0
value|0x11608
end_define

begin_define
define|#
directive|define
name|OGW1
value|0x1160c
end_define

begin_define
define|#
directive|define
name|EG0
value|0x11610
end_define

begin_define
define|#
directive|define
name|EG1
value|0x11614
end_define

begin_define
define|#
directive|define
name|EG2
value|0x11618
end_define

begin_define
define|#
directive|define
name|EG3
value|0x1161c
end_define

begin_define
define|#
directive|define
name|EG4
value|0x11620
end_define

begin_define
define|#
directive|define
name|EG5
value|0x11624
end_define

begin_define
define|#
directive|define
name|EG6
value|0x11628
end_define

begin_define
define|#
directive|define
name|EG7
value|0x1162c
end_define

begin_define
define|#
directive|define
name|PXW
value|0x11664
end_define

begin_define
define|#
directive|define
name|PXWL
value|0x11680
end_define

begin_define
define|#
directive|define
name|LCFUSE02
value|0x116c0
end_define

begin_define
define|#
directive|define
name|LCFUSE_HIV_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|CSIPLL0
value|0x12c10
end_define

begin_define
define|#
directive|define
name|DDRMPLL1
value|0X12c20
end_define

begin_define
define|#
directive|define
name|PEG_BAND_GAP_DATA
value|0x14d68
end_define

begin_define
define|#
directive|define
name|GEN6_GT_PERF_STATUS
value|0x145948
end_define

begin_define
define|#
directive|define
name|GEN6_RP_STATE_LIMITS
value|0x145994
end_define

begin_define
define|#
directive|define
name|GEN6_RP_STATE_CAP
value|0x145998
end_define

begin_comment
comment|/*  * Logical Context regs  */
end_comment

begin_define
define|#
directive|define
name|CCID
value|0x2180
end_define

begin_define
define|#
directive|define
name|CCID_EN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|CXT_SIZE
value|0x21a0
end_define

begin_define
define|#
directive|define
name|GEN6_CXT_POWER_SIZE
parameter_list|(
name|cxt_reg
parameter_list|)
value|((cxt_reg>> 24)& 0x3f)
end_define

begin_define
define|#
directive|define
name|GEN6_CXT_RING_SIZE
parameter_list|(
name|cxt_reg
parameter_list|)
value|((cxt_reg>> 18)& 0x3f)
end_define

begin_define
define|#
directive|define
name|GEN6_CXT_RENDER_SIZE
parameter_list|(
name|cxt_reg
parameter_list|)
value|((cxt_reg>> 12)& 0x3f)
end_define

begin_define
define|#
directive|define
name|GEN6_CXT_EXTENDED_SIZE
parameter_list|(
name|cxt_reg
parameter_list|)
value|((cxt_reg>> 6)& 0x3f)
end_define

begin_define
define|#
directive|define
name|GEN6_CXT_PIPELINE_SIZE
parameter_list|(
name|cxt_reg
parameter_list|)
value|((cxt_reg>> 0)& 0x3f)
end_define

begin_define
define|#
directive|define
name|GEN6_CXT_TOTAL_SIZE
parameter_list|(
name|cxt_reg
parameter_list|)
value|(GEN6_CXT_POWER_SIZE(cxt_reg) + \ 					GEN6_CXT_RING_SIZE(cxt_reg) + \ 					GEN6_CXT_RENDER_SIZE(cxt_reg) + \ 					GEN6_CXT_EXTENDED_SIZE(cxt_reg) + \ 					GEN6_CXT_PIPELINE_SIZE(cxt_reg))
end_define

begin_define
define|#
directive|define
name|GEN7_CXT_SIZE
value|0x21a8
end_define

begin_define
define|#
directive|define
name|GEN7_CXT_POWER_SIZE
parameter_list|(
name|ctx_reg
parameter_list|)
value|((ctx_reg>> 25)& 0x7f)
end_define

begin_define
define|#
directive|define
name|GEN7_CXT_RING_SIZE
parameter_list|(
name|ctx_reg
parameter_list|)
value|((ctx_reg>> 22)& 0x7)
end_define

begin_define
define|#
directive|define
name|GEN7_CXT_RENDER_SIZE
parameter_list|(
name|ctx_reg
parameter_list|)
value|((ctx_reg>> 16)& 0x3f)
end_define

begin_define
define|#
directive|define
name|GEN7_CXT_EXTENDED_SIZE
parameter_list|(
name|ctx_reg
parameter_list|)
value|((ctx_reg>> 9)& 0x7f)
end_define

begin_define
define|#
directive|define
name|GEN7_CXT_GT1_SIZE
parameter_list|(
name|ctx_reg
parameter_list|)
value|((ctx_reg>> 6)& 0x7)
end_define

begin_define
define|#
directive|define
name|GEN7_CXT_VFSTATE_SIZE
parameter_list|(
name|ctx_reg
parameter_list|)
value|((ctx_reg>> 0)& 0x3f)
end_define

begin_define
define|#
directive|define
name|GEN7_CXT_TOTAL_SIZE
parameter_list|(
name|ctx_reg
parameter_list|)
value|(GEN7_CXT_POWER_SIZE(ctx_reg) + \ 					 GEN7_CXT_RING_SIZE(ctx_reg) + \ 					 GEN7_CXT_RENDER_SIZE(ctx_reg) + \ 					 GEN7_CXT_EXTENDED_SIZE(ctx_reg) + \ 					 GEN7_CXT_GT1_SIZE(ctx_reg) + \ 					 GEN7_CXT_VFSTATE_SIZE(ctx_reg))
end_define

begin_comment
comment|/*  * Overlay regs  */
end_comment

begin_define
define|#
directive|define
name|OVADD
value|0x30000
end_define

begin_define
define|#
directive|define
name|DOVSTA
value|0x30008
end_define

begin_define
define|#
directive|define
name|OC_BUF
value|(0x3<<20)
end_define

begin_define
define|#
directive|define
name|OGAMC5
value|0x30010
end_define

begin_define
define|#
directive|define
name|OGAMC4
value|0x30014
end_define

begin_define
define|#
directive|define
name|OGAMC3
value|0x30018
end_define

begin_define
define|#
directive|define
name|OGAMC2
value|0x3001c
end_define

begin_define
define|#
directive|define
name|OGAMC1
value|0x30020
end_define

begin_define
define|#
directive|define
name|OGAMC0
value|0x30024
end_define

begin_comment
comment|/*  * Display engine regs  */
end_comment

begin_comment
comment|/* Pipe A timing regs */
end_comment

begin_define
define|#
directive|define
name|_HTOTAL_A
value|0x60000
end_define

begin_define
define|#
directive|define
name|_HBLANK_A
value|0x60004
end_define

begin_define
define|#
directive|define
name|_HSYNC_A
value|0x60008
end_define

begin_define
define|#
directive|define
name|_VTOTAL_A
value|0x6000c
end_define

begin_define
define|#
directive|define
name|_VBLANK_A
value|0x60010
end_define

begin_define
define|#
directive|define
name|_VSYNC_A
value|0x60014
end_define

begin_define
define|#
directive|define
name|_PIPEASRC
value|0x6001c
end_define

begin_define
define|#
directive|define
name|_BCLRPAT_A
value|0x60020
end_define

begin_define
define|#
directive|define
name|_VSYNCSHIFT_A
value|0x60028
end_define

begin_comment
comment|/* Pipe B timing regs */
end_comment

begin_define
define|#
directive|define
name|_HTOTAL_B
value|0x61000
end_define

begin_define
define|#
directive|define
name|_HBLANK_B
value|0x61004
end_define

begin_define
define|#
directive|define
name|_HSYNC_B
value|0x61008
end_define

begin_define
define|#
directive|define
name|_VTOTAL_B
value|0x6100c
end_define

begin_define
define|#
directive|define
name|_VBLANK_B
value|0x61010
end_define

begin_define
define|#
directive|define
name|_VSYNC_B
value|0x61014
end_define

begin_define
define|#
directive|define
name|_PIPEBSRC
value|0x6101c
end_define

begin_define
define|#
directive|define
name|_BCLRPAT_B
value|0x61020
end_define

begin_define
define|#
directive|define
name|_VSYNCSHIFT_B
value|0x61028
end_define

begin_define
define|#
directive|define
name|HTOTAL
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _HTOTAL_A, _HTOTAL_B)
end_define

begin_define
define|#
directive|define
name|HBLANK
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _HBLANK_A, _HBLANK_B)
end_define

begin_define
define|#
directive|define
name|HSYNC
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _HSYNC_A, _HSYNC_B)
end_define

begin_define
define|#
directive|define
name|VTOTAL
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _VTOTAL_A, _VTOTAL_B)
end_define

begin_define
define|#
directive|define
name|VBLANK
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _VBLANK_A, _VBLANK_B)
end_define

begin_define
define|#
directive|define
name|VSYNC
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _VSYNC_A, _VSYNC_B)
end_define

begin_define
define|#
directive|define
name|BCLRPAT
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _BCLRPAT_A, _BCLRPAT_B)
end_define

begin_define
define|#
directive|define
name|VSYNCSHIFT
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _VSYNCSHIFT_A, _VSYNCSHIFT_B)
end_define

begin_comment
comment|/* VGA port control */
end_comment

begin_define
define|#
directive|define
name|ADPA
value|0x61100
end_define

begin_define
define|#
directive|define
name|ADPA_DAC_ENABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|ADPA_DAC_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|ADPA_PIPE_SELECT_MASK
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|ADPA_PIPE_A_SELECT
value|0
end_define

begin_define
define|#
directive|define
name|ADPA_PIPE_B_SELECT
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|ADPA_PIPE_SELECT
parameter_list|(
name|pipe
parameter_list|)
value|((pipe)<< 30)
end_define

begin_define
define|#
directive|define
name|ADPA_USE_VGA_HVPOLARITY
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|ADPA_SETS_HVPOLARITY
value|0
end_define

begin_define
define|#
directive|define
name|ADPA_VSYNC_CNTL_DISABLE
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|ADPA_VSYNC_CNTL_ENABLE
value|0
end_define

begin_define
define|#
directive|define
name|ADPA_HSYNC_CNTL_DISABLE
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|ADPA_HSYNC_CNTL_ENABLE
value|0
end_define

begin_define
define|#
directive|define
name|ADPA_VSYNC_ACTIVE_HIGH
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|ADPA_VSYNC_ACTIVE_LOW
value|0
end_define

begin_define
define|#
directive|define
name|ADPA_HSYNC_ACTIVE_HIGH
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|ADPA_HSYNC_ACTIVE_LOW
value|0
end_define

begin_define
define|#
directive|define
name|ADPA_DPMS_MASK
value|(~(3<<10))
end_define

begin_define
define|#
directive|define
name|ADPA_DPMS_ON
value|(0<<10)
end_define

begin_define
define|#
directive|define
name|ADPA_DPMS_SUSPEND
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|ADPA_DPMS_STANDBY
value|(2<<10)
end_define

begin_define
define|#
directive|define
name|ADPA_DPMS_OFF
value|(3<<10)
end_define

begin_comment
comment|/* Hotplug control (945+ only) */
end_comment

begin_define
define|#
directive|define
name|PORT_HOTPLUG_EN
value|0x61110
end_define

begin_define
define|#
directive|define
name|HDMIB_HOTPLUG_INT_EN
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|DPB_HOTPLUG_INT_EN
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|HDMIC_HOTPLUG_INT_EN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|DPC_HOTPLUG_INT_EN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|HDMID_HOTPLUG_INT_EN
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|DPD_HOTPLUG_INT_EN
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|SDVOB_HOTPLUG_INT_EN
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|SDVOC_HOTPLUG_INT_EN
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|TV_HOTPLUG_INT_EN
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_INT_EN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_FORCE_DETECT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_ACTIVATION_PERIOD_32
value|(0<< 8)
end_define

begin_comment
comment|/* must use period 64 on GM45 according to docs */
end_comment

begin_define
define|#
directive|define
name|CRT_HOTPLUG_ACTIVATION_PERIOD_64
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_DAC_ON_TIME_2M
value|(0<< 7)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_DAC_ON_TIME_4M
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_VOLTAGE_COMPARE_40
value|(0<< 5)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_VOLTAGE_COMPARE_50
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_VOLTAGE_COMPARE_60
value|(2<< 5)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_VOLTAGE_COMPARE_70
value|(3<< 5)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_VOLTAGE_COMPARE_MASK
value|(3<< 5)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_DETECT_DELAY_1G
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_DETECT_DELAY_2G
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_DETECT_VOLTAGE_325MV
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_DETECT_VOLTAGE_475MV
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|PORT_HOTPLUG_STAT
value|0x61114
end_define

begin_define
define|#
directive|define
name|HDMIB_HOTPLUG_INT_STATUS
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|DPB_HOTPLUG_INT_STATUS
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|HDMIC_HOTPLUG_INT_STATUS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|DPC_HOTPLUG_INT_STATUS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|HDMID_HOTPLUG_INT_STATUS
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|DPD_HOTPLUG_INT_STATUS
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_INT_STATUS
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|TV_HOTPLUG_INT_STATUS
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_MONITOR_MASK
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_MONITOR_COLOR
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_MONITOR_MONO
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|CRT_HOTPLUG_MONITOR_NONE
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|SDVOC_HOTPLUG_INT_STATUS
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SDVOB_HOTPLUG_INT_STATUS
value|(1<< 6)
end_define

begin_comment
comment|/* SDVO port control */
end_comment

begin_define
define|#
directive|define
name|SDVOB
value|0x61140
end_define

begin_define
define|#
directive|define
name|SDVOC
value|0x61160
end_define

begin_define
define|#
directive|define
name|SDVO_ENABLE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|SDVO_PIPE_B_SELECT
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|SDVO_STALL_SELECT
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|SDVO_INTERRUPT_ENABLE
value|(1<< 26)
end_define

begin_comment
comment|/**  * 915G/GM SDVO pixel multiplier.  *  * Programmed value is multiplier - 1, up to 5x.  *  * \sa DPLL_MD_UDI_MULTIPLIER_MASK  */
end_comment

begin_define
define|#
directive|define
name|SDVO_PORT_MULTIPLY_MASK
value|(7<< 23)
end_define

begin_define
define|#
directive|define
name|SDVO_PORT_MULTIPLY_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|SDVO_PHASE_SELECT_MASK
value|(15<< 19)
end_define

begin_define
define|#
directive|define
name|SDVO_PHASE_SELECT_DEFAULT
value|(6<< 19)
end_define

begin_define
define|#
directive|define
name|SDVO_CLOCK_OUTPUT_INVERT
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|SDVOC_GANG_MODE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|SDVO_ENCODING_SDVO
value|(0x0<< 10)
end_define

begin_define
define|#
directive|define
name|SDVO_ENCODING_HDMI
value|(0x2<< 10)
end_define

begin_comment
comment|/** Requird for HDMI operation */
end_comment

begin_define
define|#
directive|define
name|SDVO_NULL_PACKETS_DURING_VSYNC
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SDVO_COLOR_RANGE_16_235
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SDVO_BORDER_ENABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SDVO_AUDIO_ENABLE
value|(1<< 6)
end_define

begin_comment
comment|/** New with 965, default is to be set */
end_comment

begin_define
define|#
directive|define
name|SDVO_VSYNC_ACTIVE_HIGH
value|(1<< 4)
end_define

begin_comment
comment|/** New with 965, default is to be set */
end_comment

begin_define
define|#
directive|define
name|SDVO_HSYNC_ACTIVE_HIGH
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SDVOB_PCIE_CONCURRENCY
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SDVO_DETECTED
value|(1<< 2)
end_define

begin_comment
comment|/* Bits to be preserved when writing */
end_comment

begin_define
define|#
directive|define
name|SDVOB_PRESERVE_MASK
value|((1<< 17) | (1<< 16) | (1<< 14) | (1<< 26))
end_define

begin_define
define|#
directive|define
name|SDVOC_PRESERVE_MASK
value|((1<< 17) | (1<< 26))
end_define

begin_comment
comment|/* DVO port control */
end_comment

begin_define
define|#
directive|define
name|DVOA
value|0x61120
end_define

begin_define
define|#
directive|define
name|DVOB
value|0x61140
end_define

begin_define
define|#
directive|define
name|DVOC
value|0x61160
end_define

begin_define
define|#
directive|define
name|DVO_ENABLE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|DVO_PIPE_B_SELECT
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|DVO_PIPE_STALL_UNUSED
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|DVO_PIPE_STALL
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|DVO_PIPE_STALL_TV
value|(2<< 28)
end_define

begin_define
define|#
directive|define
name|DVO_PIPE_STALL_MASK
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|DVO_USE_VGA_SYNC
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|DVO_DATA_ORDER_I740
value|(0<< 14)
end_define

begin_define
define|#
directive|define
name|DVO_DATA_ORDER_FP
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|DVO_VSYNC_DISABLE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|DVO_HSYNC_DISABLE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|DVO_VSYNC_TRISTATE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|DVO_HSYNC_TRISTATE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|DVO_BORDER_ENABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|DVO_DATA_ORDER_GBRG
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DVO_DATA_ORDER_RGGB
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|DVO_DATA_ORDER_GBRG_ERRATA
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|DVO_DATA_ORDER_RGGB_ERRATA
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DVO_VSYNC_ACTIVE_HIGH
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DVO_HSYNC_ACTIVE_HIGH
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DVO_BLANK_ACTIVE_HIGH
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DVO_OUTPUT_CSTATE_PIXELS
value|(1<< 1)
end_define

begin_comment
comment|/* SDG only */
end_comment

begin_define
define|#
directive|define
name|DVO_OUTPUT_SOURCE_SIZE_PIXELS
value|(1<< 0)
end_define

begin_comment
comment|/* SDG only */
end_comment

begin_define
define|#
directive|define
name|DVO_PRESERVE_MASK
value|(0x7<<24)
end_define

begin_define
define|#
directive|define
name|DVOA_SRCDIM
value|0x61124
end_define

begin_define
define|#
directive|define
name|DVOB_SRCDIM
value|0x61144
end_define

begin_define
define|#
directive|define
name|DVOC_SRCDIM
value|0x61164
end_define

begin_define
define|#
directive|define
name|DVO_SRCDIM_HORIZONTAL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|DVO_SRCDIM_VERTICAL_SHIFT
value|0
end_define

begin_comment
comment|/* LVDS port control */
end_comment

begin_define
define|#
directive|define
name|LVDS
value|0x61180
end_define

begin_comment
comment|/*  * Enables the LVDS port.  This bit must be set before DPLLs are enabled, as  * the DPLL semantics change when the LVDS is assigned to that pipe.  */
end_comment

begin_define
define|#
directive|define
name|LVDS_PORT_EN
value|(1U<< 31)
end_define

begin_comment
comment|/* Selects pipe B for LVDS data.  Must be set on pre-965. */
end_comment

begin_define
define|#
directive|define
name|LVDS_PIPEB_SELECT
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|LVDS_PIPE_MASK
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|LVDS_PIPE
parameter_list|(
name|pipe
parameter_list|)
value|((pipe)<< 30)
end_define

begin_comment
comment|/* LVDS dithering flag on 965/g4x platform */
end_comment

begin_define
define|#
directive|define
name|LVDS_ENABLE_DITHER
value|(1<< 25)
end_define

begin_comment
comment|/* LVDS sync polarity flags. Set to invert (i.e. negative) */
end_comment

begin_define
define|#
directive|define
name|LVDS_VSYNC_POLARITY
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|LVDS_HSYNC_POLARITY
value|(1<< 20)
end_define

begin_comment
comment|/* Enable border for unscaled (or aspect-scaled) display */
end_comment

begin_define
define|#
directive|define
name|LVDS_BORDER_ENABLE
value|(1<< 15)
end_define

begin_comment
comment|/*  * Enables the A0-A2 data pairs and CLKA, containing 18 bits of color data per  * pixel.  */
end_comment

begin_define
define|#
directive|define
name|LVDS_A0A2_CLKA_POWER_MASK
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|LVDS_A0A2_CLKA_POWER_DOWN
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|LVDS_A0A2_CLKA_POWER_UP
value|(3<< 8)
end_define

begin_comment
comment|/*  * Controls the A3 data pair, which contains the additional LSBs for 24 bit  * mode.  Only enabled if LVDS_A0A2_CLKA_POWER_UP also indicates it should be  * on.  */
end_comment

begin_define
define|#
directive|define
name|LVDS_A3_POWER_MASK
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|LVDS_A3_POWER_DOWN
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|LVDS_A3_POWER_UP
value|(3<< 6)
end_define

begin_comment
comment|/*  * Controls the CLKB pair.  This should only be set when LVDS_B0B3_POWER_UP  * is set.  */
end_comment

begin_define
define|#
directive|define
name|LVDS_CLKB_POWER_MASK
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|LVDS_CLKB_POWER_DOWN
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|LVDS_CLKB_POWER_UP
value|(3<< 4)
end_define

begin_comment
comment|/*  * Controls the B0-B3 data pairs.  This must be set to match the DPLL p2  * setting for whether we are in dual-channel mode.  The B3 pair will  * additionally only be powered up when LVDS_A3_POWER_UP is set.  */
end_comment

begin_define
define|#
directive|define
name|LVDS_B0B3_POWER_MASK
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|LVDS_B0B3_POWER_DOWN
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|LVDS_B0B3_POWER_UP
value|(3<< 2)
end_define

begin_comment
comment|/* Video Data Island Packet control */
end_comment

begin_define
define|#
directive|define
name|VIDEO_DIP_DATA
value|0x61178
end_define

begin_define
define|#
directive|define
name|VIDEO_DIP_CTL
value|0x61170
end_define

begin_define
define|#
directive|define
name|VIDEO_DIP_ENABLE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|VIDEO_DIP_PORT_B
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|VIDEO_DIP_PORT_C
value|(2<< 29)
end_define

begin_define
define|#
directive|define
name|VIDEO_DIP_ENABLE_AVI
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|VIDEO_DIP_ENABLE_VENDOR
value|(2<< 21)
end_define

begin_define
define|#
directive|define
name|VIDEO_DIP_ENABLE_SPD
value|(8<< 21)
end_define

begin_define
define|#
directive|define
name|VIDEO_DIP_SELECT_MASK
value|(3<< 19)
end_define

begin_define
define|#
directive|define
name|VIDEO_DIP_SELECT_AVI
value|(0<< 19)
end_define

begin_define
define|#
directive|define
name|VIDEO_DIP_SELECT_VENDOR
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|VIDEO_DIP_SELECT_SPD
value|(3<< 19)
end_define

begin_define
define|#
directive|define
name|VIDEO_DIP_FREQ_ONCE
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|VIDEO_DIP_FREQ_VSYNC
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|VIDEO_DIP_FREQ_2VSYNC
value|(2<< 16)
end_define

begin_comment
comment|/* Panel power sequencing */
end_comment

begin_define
define|#
directive|define
name|PP_STATUS
value|0x61200
end_define

begin_define
define|#
directive|define
name|PP_ON
value|(1U<< 31)
end_define

begin_comment
comment|/*  * Indicates that all dependencies of the panel are on:  *  * - PLL enabled  * - pipe enabled  * - LVDS/DVOB/DVOC on  */
end_comment

begin_define
define|#
directive|define
name|PP_READY
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_NONE
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_POWER_UP
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_POWER_DOWN
value|(2<< 28)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_MASK
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|PP_CYCLE_DELAY_ACTIVE
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_STATE_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_STATE_OFF_IDLE
value|(0x0<< 0)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_STATE_OFF_S0_1
value|(0x1<< 0)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_STATE_OFF_S0_2
value|(0x2<< 0)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_STATE_OFF_S0_3
value|(0x3<< 0)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_STATE_ON_IDLE
value|(0x8<< 0)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_STATE_ON_S1_0
value|(0x9<< 0)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_STATE_ON_S1_2
value|(0xa<< 0)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_STATE_ON_S1_3
value|(0xb<< 0)
end_define

begin_define
define|#
directive|define
name|PP_SEQUENCE_STATE_RESET
value|(0xf<< 0)
end_define

begin_define
define|#
directive|define
name|PP_CONTROL
value|0x61204
end_define

begin_define
define|#
directive|define
name|POWER_TARGET_ON
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PP_ON_DELAYS
value|0x61208
end_define

begin_define
define|#
directive|define
name|PP_OFF_DELAYS
value|0x6120c
end_define

begin_define
define|#
directive|define
name|PP_DIVISOR
value|0x61210
end_define

begin_comment
comment|/* Panel fitting */
end_comment

begin_define
define|#
directive|define
name|PFIT_CONTROL
value|0x61230
end_define

begin_define
define|#
directive|define
name|PFIT_ENABLE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|PFIT_PIPE_MASK
value|(3<< 29)
end_define

begin_define
define|#
directive|define
name|PFIT_PIPE_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|VERT_INTERP_DISABLE
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|VERT_INTERP_BILINEAR
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|VERT_INTERP_MASK
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|VERT_AUTO_SCALE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|HORIZ_INTERP_DISABLE
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|HORIZ_INTERP_BILINEAR
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|HORIZ_INTERP_MASK
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|HORIZ_AUTO_SCALE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PANEL_8TO6_DITHER_ENABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|PFIT_FILTER_FUZZY
value|(0<< 24)
end_define

begin_define
define|#
directive|define
name|PFIT_SCALING_AUTO
value|(0<< 26)
end_define

begin_define
define|#
directive|define
name|PFIT_SCALING_PROGRAMMED
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|PFIT_SCALING_PILLAR
value|(2<< 26)
end_define

begin_define
define|#
directive|define
name|PFIT_SCALING_LETTER
value|(3<< 26)
end_define

begin_define
define|#
directive|define
name|PFIT_PGM_RATIOS
value|0x61234
end_define

begin_define
define|#
directive|define
name|PFIT_VERT_SCALE_MASK
value|0xfff00000
end_define

begin_define
define|#
directive|define
name|PFIT_HORIZ_SCALE_MASK
value|0x0000fff0
end_define

begin_comment
comment|/* Pre-965 */
end_comment

begin_define
define|#
directive|define
name|PFIT_VERT_SCALE_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|PFIT_VERT_SCALE_MASK
value|0xfff00000
end_define

begin_define
define|#
directive|define
name|PFIT_HORIZ_SCALE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|PFIT_HORIZ_SCALE_MASK
value|0x0000fff0
end_define

begin_comment
comment|/* 965+ */
end_comment

begin_define
define|#
directive|define
name|PFIT_VERT_SCALE_SHIFT_965
value|16
end_define

begin_define
define|#
directive|define
name|PFIT_VERT_SCALE_MASK_965
value|0x1fff0000
end_define

begin_define
define|#
directive|define
name|PFIT_HORIZ_SCALE_SHIFT_965
value|0
end_define

begin_define
define|#
directive|define
name|PFIT_HORIZ_SCALE_MASK_965
value|0x00001fff
end_define

begin_define
define|#
directive|define
name|PFIT_AUTO_RATIOS
value|0x61238
end_define

begin_comment
comment|/* Backlight control */
end_comment

begin_define
define|#
directive|define
name|BLC_PWM_CTL
value|0x61254
end_define

begin_define
define|#
directive|define
name|BACKLIGHT_MODULATION_FREQ_SHIFT
value|(17)
end_define

begin_define
define|#
directive|define
name|BLC_PWM_CTL2
value|0x61250
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_define
define|#
directive|define
name|BLM_COMBINATION_MODE
value|(1<< 30)
end_define

begin_comment
comment|/*  * This is the most significant 15 bits of the number of backlight cycles in a  * complete cycle of the modulated backlight control.  *  * The actual value is this field multiplied by two.  */
end_comment

begin_define
define|#
directive|define
name|BACKLIGHT_MODULATION_FREQ_MASK
value|(0x7fff<< 17)
end_define

begin_define
define|#
directive|define
name|BLM_LEGACY_MODE
value|(1<< 16)
end_define

begin_comment
comment|/*  * This is the number of cycles out of the backlight modulation cycle for which  * the backlight is on.  *  * This field must be no greater than the number of cycles in the complete  * backlight modulation cycle.  */
end_comment

begin_define
define|#
directive|define
name|BACKLIGHT_DUTY_CYCLE_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|BACKLIGHT_DUTY_CYCLE_MASK
value|(0xffff)
end_define

begin_define
define|#
directive|define
name|BLC_HIST_CTL
value|0x61260
end_define

begin_comment
comment|/* TV port control */
end_comment

begin_define
define|#
directive|define
name|TV_CTL
value|0x68000
end_define

begin_comment
comment|/** Enables the TV encoder */
end_comment

begin_define
define|#
directive|define
name|TV_ENC_ENABLE
value|(1U<< 31)
end_define

begin_comment
comment|/** Sources the TV encoder input from pipe B instead of A. */
end_comment

begin_define
define|#
directive|define
name|TV_ENC_PIPEB_SELECT
value|(1<< 30)
end_define

begin_comment
comment|/** Outputs composite video (DAC A only) */
end_comment

begin_define
define|#
directive|define
name|TV_ENC_OUTPUT_COMPOSITE
value|(0<< 28)
end_define

begin_comment
comment|/** Outputs SVideo video (DAC B/C) */
end_comment

begin_define
define|#
directive|define
name|TV_ENC_OUTPUT_SVIDEO
value|(1<< 28)
end_define

begin_comment
comment|/** Outputs Component video (DAC A/B/C) */
end_comment

begin_define
define|#
directive|define
name|TV_ENC_OUTPUT_COMPONENT
value|(2<< 28)
end_define

begin_comment
comment|/** Outputs Composite and SVideo (DAC A/B/C) */
end_comment

begin_define
define|#
directive|define
name|TV_ENC_OUTPUT_SVIDEO_COMPOSITE
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|TV_TRILEVEL_SYNC
value|(1<< 21)
end_define

begin_comment
comment|/** Enables slow sync generation (945GM only) */
end_comment

begin_define
define|#
directive|define
name|TV_SLOW_SYNC
value|(1<< 20)
end_define

begin_comment
comment|/** Selects 4x oversampling for 480i and 576p */
end_comment

begin_define
define|#
directive|define
name|TV_OVERSAMPLE_4X
value|(0<< 18)
end_define

begin_comment
comment|/** Selects 2x oversampling for 720p and 1080i */
end_comment

begin_define
define|#
directive|define
name|TV_OVERSAMPLE_2X
value|(1<< 18)
end_define

begin_comment
comment|/** Selects no oversampling for 1080p */
end_comment

begin_define
define|#
directive|define
name|TV_OVERSAMPLE_NONE
value|(2<< 18)
end_define

begin_comment
comment|/** Selects 8x oversampling */
end_comment

begin_define
define|#
directive|define
name|TV_OVERSAMPLE_8X
value|(3<< 18)
end_define

begin_comment
comment|/** Selects progressive mode rather than interlaced */
end_comment

begin_define
define|#
directive|define
name|TV_PROGRESSIVE
value|(1<< 17)
end_define

begin_comment
comment|/** Sets the colorburst to PAL mode.  Required for non-M PAL modes. */
end_comment

begin_define
define|#
directive|define
name|TV_PAL_BURST
value|(1<< 16)
end_define

begin_comment
comment|/** Field for setting delay of Y compared to C */
end_comment

begin_define
define|#
directive|define
name|TV_YC_SKEW_MASK
value|(7<< 12)
end_define

begin_comment
comment|/** Enables a fix for 480p/576p standard definition modes on the 915GM only */
end_comment

begin_define
define|#
directive|define
name|TV_ENC_SDP_FIX
value|(1<< 11)
end_define

begin_comment
comment|/**  * Enables a fix for the 915GM only.  *  * Not sure what it does.  */
end_comment

begin_define
define|#
directive|define
name|TV_ENC_C0_FIX
value|(1<< 10)
end_define

begin_comment
comment|/** Bits that must be preserved by software */
end_comment

begin_define
define|#
directive|define
name|TV_CTL_SAVE
value|((1<< 11) | (3<< 9) | (7<< 6) | 0xf)
end_define

begin_define
define|#
directive|define
name|TV_FUSE_STATE_MASK
value|(3<< 4)
end_define

begin_comment
comment|/** Read-only state that reports all features enabled */
end_comment

begin_define
define|#
directive|define
name|TV_FUSE_STATE_ENABLED
value|(0<< 4)
end_define

begin_comment
comment|/** Read-only state that reports that Macrovision is disabled in hardware*/
end_comment

begin_define
define|#
directive|define
name|TV_FUSE_STATE_NO_MACROVISION
value|(1<< 4)
end_define

begin_comment
comment|/** Read-only state that reports that TV-out is disabled in hardware. */
end_comment

begin_define
define|#
directive|define
name|TV_FUSE_STATE_DISABLED
value|(2<< 4)
end_define

begin_comment
comment|/** Normal operation */
end_comment

begin_define
define|#
directive|define
name|TV_TEST_MODE_NORMAL
value|(0<< 0)
end_define

begin_comment
comment|/** Encoder test pattern 1 - combo pattern */
end_comment

begin_define
define|#
directive|define
name|TV_TEST_MODE_PATTERN_1
value|(1<< 0)
end_define

begin_comment
comment|/** Encoder test pattern 2 - full screen vertical 75% color bars */
end_comment

begin_define
define|#
directive|define
name|TV_TEST_MODE_PATTERN_2
value|(2<< 0)
end_define

begin_comment
comment|/** Encoder test pattern 3 - full screen horizontal 75% color bars */
end_comment

begin_define
define|#
directive|define
name|TV_TEST_MODE_PATTERN_3
value|(3<< 0)
end_define

begin_comment
comment|/** Encoder test pattern 4 - random noise */
end_comment

begin_define
define|#
directive|define
name|TV_TEST_MODE_PATTERN_4
value|(4<< 0)
end_define

begin_comment
comment|/** Encoder test pattern 5 - linear color ramps */
end_comment

begin_define
define|#
directive|define
name|TV_TEST_MODE_PATTERN_5
value|(5<< 0)
end_define

begin_comment
comment|/**  * This test mode forces the DACs to 50% of full output.  *  * This is used for load detection in combination with TVDAC_SENSE_MASK  */
end_comment

begin_define
define|#
directive|define
name|TV_TEST_MODE_MONITOR_DETECT
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|TV_TEST_MODE_MASK
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|TV_DAC
value|0x68004
end_define

begin_define
define|#
directive|define
name|TV_DAC_SAVE
value|0x00ffff00
end_define

begin_comment
comment|/**  * Reports that DAC state change logic has reported change (RO).  *  * This gets cleared when TV_DAC_STATE_EN is cleared */
end_comment

begin_define
define|#
directive|define
name|TVDAC_STATE_CHG
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|TVDAC_SENSE_MASK
value|(7<< 28)
end_define

begin_comment
comment|/** Reports that DAC A voltage is above the detect threshold */
end_comment

begin_define
define|#
directive|define
name|TVDAC_A_SENSE
value|(1<< 30)
end_define

begin_comment
comment|/** Reports that DAC B voltage is above the detect threshold */
end_comment

begin_define
define|#
directive|define
name|TVDAC_B_SENSE
value|(1<< 29)
end_define

begin_comment
comment|/** Reports that DAC C voltage is above the detect threshold */
end_comment

begin_define
define|#
directive|define
name|TVDAC_C_SENSE
value|(1<< 28)
end_define

begin_comment
comment|/**  * Enables DAC state detection logic, for load-based TV detection.  *  * The PLL of the chosen pipe (in TV_CTL) must be running, and the encoder set  * to off, for load detection to work.  */
end_comment

begin_define
define|#
directive|define
name|TVDAC_STATE_CHG_EN
value|(1<< 27)
end_define

begin_comment
comment|/** Sets the DAC A sense value to high */
end_comment

begin_define
define|#
directive|define
name|TVDAC_A_SENSE_CTL
value|(1<< 26)
end_define

begin_comment
comment|/** Sets the DAC B sense value to high */
end_comment

begin_define
define|#
directive|define
name|TVDAC_B_SENSE_CTL
value|(1<< 25)
end_define

begin_comment
comment|/** Sets the DAC C sense value to high */
end_comment

begin_define
define|#
directive|define
name|TVDAC_C_SENSE_CTL
value|(1<< 24)
end_define

begin_comment
comment|/** Overrides the ENC_ENABLE and DAC voltage levels */
end_comment

begin_define
define|#
directive|define
name|DAC_CTL_OVERRIDE
value|(1<< 7)
end_define

begin_comment
comment|/** Sets the slew rate.  Must be preserved in software */
end_comment

begin_define
define|#
directive|define
name|ENC_TVDAC_SLEW_FAST
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DAC_A_1_3_V
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|DAC_A_1_1_V
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DAC_A_0_7_V
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|DAC_A_MASK
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|DAC_B_1_3_V
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|DAC_B_1_1_V
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DAC_B_0_7_V
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|DAC_B_MASK
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|DAC_C_1_3_V
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|DAC_C_1_1_V
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DAC_C_0_7_V
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|DAC_C_MASK
value|(3<< 0)
end_define

begin_comment
comment|/**  * CSC coefficients are stored in a floating point format with 9 bits of  * mantissa and 2 or 3 bits of exponent.  The exponent is represented as 2**-n,  * where 2-bit exponents are unsigned n, and 3-bit exponents are signed n with  * -1 (0x3) being the only legal negative value.  */
end_comment

begin_define
define|#
directive|define
name|TV_CSC_Y
value|0x68010
end_define

begin_define
define|#
directive|define
name|TV_RY_MASK
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|TV_RY_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TV_GY_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|TV_GY_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CSC_Y2
value|0x68014
end_define

begin_define
define|#
directive|define
name|TV_BY_MASK
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|TV_BY_SHIFT
value|16
end_define

begin_comment
comment|/**  * Y attenuation for component video.  *  * Stored in 1.9 fixed point.  */
end_comment

begin_define
define|#
directive|define
name|TV_AY_MASK
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|TV_AY_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CSC_U
value|0x68018
end_define

begin_define
define|#
directive|define
name|TV_RU_MASK
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|TV_RU_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TV_GU_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|TV_GU_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CSC_U2
value|0x6801c
end_define

begin_define
define|#
directive|define
name|TV_BU_MASK
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|TV_BU_SHIFT
value|16
end_define

begin_comment
comment|/**  * U attenuation for component video.  *  * Stored in 1.9 fixed point.  */
end_comment

begin_define
define|#
directive|define
name|TV_AU_MASK
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|TV_AU_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CSC_V
value|0x68020
end_define

begin_define
define|#
directive|define
name|TV_RV_MASK
value|0x0fff0000
end_define

begin_define
define|#
directive|define
name|TV_RV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TV_GV_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|TV_GV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CSC_V2
value|0x68024
end_define

begin_define
define|#
directive|define
name|TV_BV_MASK
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|TV_BV_SHIFT
value|16
end_define

begin_comment
comment|/**  * V attenuation for component video.  *  * Stored in 1.9 fixed point.  */
end_comment

begin_define
define|#
directive|define
name|TV_AV_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|TV_AV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CLR_KNOBS
value|0x68028
end_define

begin_comment
comment|/** 2s-complement brightness adjustment */
end_comment

begin_define
define|#
directive|define
name|TV_BRIGHTNESS_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|TV_BRIGHTNESS_SHIFT
value|24
end_define

begin_comment
comment|/** Contrast adjustment, as a 2.6 unsigned floating point number */
end_comment

begin_define
define|#
directive|define
name|TV_CONTRAST_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|TV_CONTRAST_SHIFT
value|16
end_define

begin_comment
comment|/** Saturation adjustment, as a 2.6 unsigned floating point number */
end_comment

begin_define
define|#
directive|define
name|TV_SATURATION_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|TV_SATURATION_SHIFT
value|8
end_define

begin_comment
comment|/** Hue adjustment, as an integer phase angle in degrees */
end_comment

begin_define
define|#
directive|define
name|TV_HUE_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|TV_HUE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CLR_LEVEL
value|0x6802c
end_define

begin_comment
comment|/** Controls the DAC level for black */
end_comment

begin_define
define|#
directive|define
name|TV_BLACK_LEVEL_MASK
value|0x01ff0000
end_define

begin_define
define|#
directive|define
name|TV_BLACK_LEVEL_SHIFT
value|16
end_define

begin_comment
comment|/** Controls the DAC level for blanking */
end_comment

begin_define
define|#
directive|define
name|TV_BLANK_LEVEL_MASK
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|TV_BLANK_LEVEL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_H_CTL_1
value|0x68030
end_define

begin_comment
comment|/** Number of pixels in the hsync. */
end_comment

begin_define
define|#
directive|define
name|TV_HSYNC_END_MASK
value|0x1fff0000
end_define

begin_define
define|#
directive|define
name|TV_HSYNC_END_SHIFT
value|16
end_define

begin_comment
comment|/** Total number of pixels minus one in the line (display and blanking). */
end_comment

begin_define
define|#
directive|define
name|TV_HTOTAL_MASK
value|0x00001fff
end_define

begin_define
define|#
directive|define
name|TV_HTOTAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_H_CTL_2
value|0x68034
end_define

begin_comment
comment|/** Enables the colorburst (needed for non-component color) */
end_comment

begin_define
define|#
directive|define
name|TV_BURST_ENA
value|(1U<< 31)
end_define

begin_comment
comment|/** Offset of the colorburst from the start of hsync, in pixels minus one. */
end_comment

begin_define
define|#
directive|define
name|TV_HBURST_START_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TV_HBURST_START_MASK
value|0x1fff0000
end_define

begin_comment
comment|/** Length of the colorburst */
end_comment

begin_define
define|#
directive|define
name|TV_HBURST_LEN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_HBURST_LEN_MASK
value|0x0001fff
end_define

begin_define
define|#
directive|define
name|TV_H_CTL_3
value|0x68038
end_define

begin_comment
comment|/** End of hblank, measured in pixels minus one from start of hsync */
end_comment

begin_define
define|#
directive|define
name|TV_HBLANK_END_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TV_HBLANK_END_MASK
value|0x1fff0000
end_define

begin_comment
comment|/** Start of hblank, measured in pixels minus one from start of hsync */
end_comment

begin_define
define|#
directive|define
name|TV_HBLANK_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_HBLANK_START_MASK
value|0x0001fff
end_define

begin_define
define|#
directive|define
name|TV_V_CTL_1
value|0x6803c
end_define

begin_comment
comment|/** XXX */
end_comment

begin_define
define|#
directive|define
name|TV_NBR_END_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TV_NBR_END_MASK
value|0x07ff0000
end_define

begin_comment
comment|/** XXX */
end_comment

begin_define
define|#
directive|define
name|TV_VI_END_F1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|TV_VI_END_F1_MASK
value|0x00003f00
end_define

begin_comment
comment|/** XXX */
end_comment

begin_define
define|#
directive|define
name|TV_VI_END_F2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_VI_END_F2_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|TV_V_CTL_2
value|0x68040
end_define

begin_comment
comment|/** Length of vsync, in half lines */
end_comment

begin_define
define|#
directive|define
name|TV_VSYNC_LEN_MASK
value|0x07ff0000
end_define

begin_define
define|#
directive|define
name|TV_VSYNC_LEN_SHIFT
value|16
end_define

begin_comment
comment|/** Offset of the start of vsync in field 1, measured in one less than the  * number of half lines.  */
end_comment

begin_define
define|#
directive|define
name|TV_VSYNC_START_F1_MASK
value|0x00007f00
end_define

begin_define
define|#
directive|define
name|TV_VSYNC_START_F1_SHIFT
value|8
end_define

begin_comment
comment|/**  * Offset of the start of vsync in field 2, measured in one less than the  * number of half lines.  */
end_comment

begin_define
define|#
directive|define
name|TV_VSYNC_START_F2_MASK
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|TV_VSYNC_START_F2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_V_CTL_3
value|0x68044
end_define

begin_comment
comment|/** Enables generation of the equalization signal */
end_comment

begin_define
define|#
directive|define
name|TV_EQUAL_ENA
value|(1U<< 31)
end_define

begin_comment
comment|/** Length of vsync, in half lines */
end_comment

begin_define
define|#
directive|define
name|TV_VEQ_LEN_MASK
value|0x007f0000
end_define

begin_define
define|#
directive|define
name|TV_VEQ_LEN_SHIFT
value|16
end_define

begin_comment
comment|/** Offset of the start of equalization in field 1, measured in one less than  * the number of half lines.  */
end_comment

begin_define
define|#
directive|define
name|TV_VEQ_START_F1_MASK
value|0x0007f00
end_define

begin_define
define|#
directive|define
name|TV_VEQ_START_F1_SHIFT
value|8
end_define

begin_comment
comment|/**  * Offset of the start of equalization in field 2, measured in one less than  * the number of half lines.  */
end_comment

begin_define
define|#
directive|define
name|TV_VEQ_START_F2_MASK
value|0x000007f
end_define

begin_define
define|#
directive|define
name|TV_VEQ_START_F2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_V_CTL_4
value|0x68048
end_define

begin_comment
comment|/**  * Offset to start of vertical colorburst, measured in one less than the  * number of lines from vertical start.  */
end_comment

begin_define
define|#
directive|define
name|TV_VBURST_START_F1_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|TV_VBURST_START_F1_SHIFT
value|16
end_define

begin_comment
comment|/**  * Offset to the end of vertical colorburst, measured in one less than the  * number of lines from the start of NBR.  */
end_comment

begin_define
define|#
directive|define
name|TV_VBURST_END_F1_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|TV_VBURST_END_F1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_V_CTL_5
value|0x6804c
end_define

begin_comment
comment|/**  * Offset to start of vertical colorburst, measured in one less than the  * number of lines from vertical start.  */
end_comment

begin_define
define|#
directive|define
name|TV_VBURST_START_F2_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|TV_VBURST_START_F2_SHIFT
value|16
end_define

begin_comment
comment|/**  * Offset to the end of vertical colorburst, measured in one less than the  * number of lines from the start of NBR.  */
end_comment

begin_define
define|#
directive|define
name|TV_VBURST_END_F2_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|TV_VBURST_END_F2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_V_CTL_6
value|0x68050
end_define

begin_comment
comment|/**  * Offset to start of vertical colorburst, measured in one less than the  * number of lines from vertical start.  */
end_comment

begin_define
define|#
directive|define
name|TV_VBURST_START_F3_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|TV_VBURST_START_F3_SHIFT
value|16
end_define

begin_comment
comment|/**  * Offset to the end of vertical colorburst, measured in one less than the  * number of lines from the start of NBR.  */
end_comment

begin_define
define|#
directive|define
name|TV_VBURST_END_F3_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|TV_VBURST_END_F3_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_V_CTL_7
value|0x68054
end_define

begin_comment
comment|/**  * Offset to start of vertical colorburst, measured in one less than the  * number of lines from vertical start.  */
end_comment

begin_define
define|#
directive|define
name|TV_VBURST_START_F4_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|TV_VBURST_START_F4_SHIFT
value|16
end_define

begin_comment
comment|/**  * Offset to the end of vertical colorburst, measured in one less than the  * number of lines from the start of NBR.  */
end_comment

begin_define
define|#
directive|define
name|TV_VBURST_END_F4_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|TV_VBURST_END_F4_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_SC_CTL_1
value|0x68060
end_define

begin_comment
comment|/** Turns on the first subcarrier phase generation DDA */
end_comment

begin_define
define|#
directive|define
name|TV_SC_DDA1_EN
value|(1U<< 31)
end_define

begin_comment
comment|/** Turns on the first subcarrier phase generation DDA */
end_comment

begin_define
define|#
directive|define
name|TV_SC_DDA2_EN
value|(1<< 30)
end_define

begin_comment
comment|/** Turns on the first subcarrier phase generation DDA */
end_comment

begin_define
define|#
directive|define
name|TV_SC_DDA3_EN
value|(1<< 29)
end_define

begin_comment
comment|/** Sets the subcarrier DDA to reset frequency every other field */
end_comment

begin_define
define|#
directive|define
name|TV_SC_RESET_EVERY_2
value|(0<< 24)
end_define

begin_comment
comment|/** Sets the subcarrier DDA to reset frequency every fourth field */
end_comment

begin_define
define|#
directive|define
name|TV_SC_RESET_EVERY_4
value|(1<< 24)
end_define

begin_comment
comment|/** Sets the subcarrier DDA to reset frequency every eighth field */
end_comment

begin_define
define|#
directive|define
name|TV_SC_RESET_EVERY_8
value|(2<< 24)
end_define

begin_comment
comment|/** Sets the subcarrier DDA to never reset the frequency */
end_comment

begin_define
define|#
directive|define
name|TV_SC_RESET_NEVER
value|(3<< 24)
end_define

begin_comment
comment|/** Sets the peak amplitude of the colorburst.*/
end_comment

begin_define
define|#
directive|define
name|TV_BURST_LEVEL_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|TV_BURST_LEVEL_SHIFT
value|16
end_define

begin_comment
comment|/** Sets the increment of the first subcarrier phase generation DDA */
end_comment

begin_define
define|#
directive|define
name|TV_SCDDA1_INC_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|TV_SCDDA1_INC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_SC_CTL_2
value|0x68064
end_define

begin_comment
comment|/** Sets the rollover for the second subcarrier phase generation DDA */
end_comment

begin_define
define|#
directive|define
name|TV_SCDDA2_SIZE_MASK
value|0x7fff0000
end_define

begin_define
define|#
directive|define
name|TV_SCDDA2_SIZE_SHIFT
value|16
end_define

begin_comment
comment|/** Sets the increent of the second subcarrier phase generation DDA */
end_comment

begin_define
define|#
directive|define
name|TV_SCDDA2_INC_MASK
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|TV_SCDDA2_INC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_SC_CTL_3
value|0x68068
end_define

begin_comment
comment|/** Sets the rollover for the third subcarrier phase generation DDA */
end_comment

begin_define
define|#
directive|define
name|TV_SCDDA3_SIZE_MASK
value|0x7fff0000
end_define

begin_define
define|#
directive|define
name|TV_SCDDA3_SIZE_SHIFT
value|16
end_define

begin_comment
comment|/** Sets the increent of the third subcarrier phase generation DDA */
end_comment

begin_define
define|#
directive|define
name|TV_SCDDA3_INC_MASK
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|TV_SCDDA3_INC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_WIN_POS
value|0x68070
end_define

begin_comment
comment|/** X coordinate of the display from the start of horizontal active */
end_comment

begin_define
define|#
directive|define
name|TV_XPOS_MASK
value|0x1fff0000
end_define

begin_define
define|#
directive|define
name|TV_XPOS_SHIFT
value|16
end_define

begin_comment
comment|/** Y coordinate of the display from the start of vertical active (NBR) */
end_comment

begin_define
define|#
directive|define
name|TV_YPOS_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|TV_YPOS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_WIN_SIZE
value|0x68074
end_define

begin_comment
comment|/** Horizontal size of the display window, measured in pixels*/
end_comment

begin_define
define|#
directive|define
name|TV_XSIZE_MASK
value|0x1fff0000
end_define

begin_define
define|#
directive|define
name|TV_XSIZE_SHIFT
value|16
end_define

begin_comment
comment|/**  * Vertical size of the display window, measured in pixels.  *  * Must be even for interlaced modes.  */
end_comment

begin_define
define|#
directive|define
name|TV_YSIZE_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|TV_YSIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_FILTER_CTL_1
value|0x68080
end_define

begin_comment
comment|/**  * Enables automatic scaling calculation.  *  * If set, the rest of the registers are ignored, and the calculated values can  * be read back from the register.  */
end_comment

begin_define
define|#
directive|define
name|TV_AUTO_SCALE
value|(1U<< 31)
end_define

begin_comment
comment|/**  * Disables the vertical filter.  *  * This is required on modes more than 1024 pixels wide */
end_comment

begin_define
define|#
directive|define
name|TV_V_FILTER_BYPASS
value|(1<< 29)
end_define

begin_comment
comment|/** Enables adaptive vertical filtering */
end_comment

begin_define
define|#
directive|define
name|TV_VADAPT
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|TV_VADAPT_MODE_MASK
value|(3<< 26)
end_define

begin_comment
comment|/** Selects the least adaptive vertical filtering mode */
end_comment

begin_define
define|#
directive|define
name|TV_VADAPT_MODE_LEAST
value|(0<< 26)
end_define

begin_comment
comment|/** Selects the moderately adaptive vertical filtering mode */
end_comment

begin_define
define|#
directive|define
name|TV_VADAPT_MODE_MODERATE
value|(1<< 26)
end_define

begin_comment
comment|/** Selects the most adaptive vertical filtering mode */
end_comment

begin_define
define|#
directive|define
name|TV_VADAPT_MODE_MOST
value|(3<< 26)
end_define

begin_comment
comment|/**  * Sets the horizontal scaling factor.  *  * This should be the fractional part of the horizontal scaling factor divided  * by the oversampling rate.  TV_HSCALE should be less than 1, and set to:  *  * (src width - 1) / ((oversample * dest width) - 1)  */
end_comment

begin_define
define|#
directive|define
name|TV_HSCALE_FRAC_MASK
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|TV_HSCALE_FRAC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_FILTER_CTL_2
value|0x68084
end_define

begin_comment
comment|/**  * Sets the integer part of the 3.15 fixed-point vertical scaling factor.  *  * TV_VSCALE should be (src height - 1) / ((interlace * dest height) - 1)  */
end_comment

begin_define
define|#
directive|define
name|TV_VSCALE_INT_MASK
value|0x00038000
end_define

begin_define
define|#
directive|define
name|TV_VSCALE_INT_SHIFT
value|15
end_define

begin_comment
comment|/**  * Sets the fractional part of the 3.15 fixed-point vertical scaling factor.  *  * \sa TV_VSCALE_INT_MASK  */
end_comment

begin_define
define|#
directive|define
name|TV_VSCALE_FRAC_MASK
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|TV_VSCALE_FRAC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_FILTER_CTL_3
value|0x68088
end_define

begin_comment
comment|/**  * Sets the integer part of the 3.15 fixed-point vertical scaling factor.  *  * TV_VSCALE should be (src height - 1) / (1/4 * (dest height - 1))  *  * For progressive modes, TV_VSCALE_IP_INT should be set to zeroes.  */
end_comment

begin_define
define|#
directive|define
name|TV_VSCALE_IP_INT_MASK
value|0x00038000
end_define

begin_define
define|#
directive|define
name|TV_VSCALE_IP_INT_SHIFT
value|15
end_define

begin_comment
comment|/**  * Sets the fractional part of the 3.15 fixed-point vertical scaling factor.  *  * For progressive modes, TV_VSCALE_IP_INT should be set to zeroes.  *  * \sa TV_VSCALE_IP_INT_MASK  */
end_comment

begin_define
define|#
directive|define
name|TV_VSCALE_IP_FRAC_MASK
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|TV_VSCALE_IP_FRAC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CC_CONTROL
value|0x68090
end_define

begin_define
define|#
directive|define
name|TV_CC_ENABLE
value|(1U<< 31)
end_define

begin_comment
comment|/**  * Specifies which field to send the CC data in.  *  * CC data is usually sent in field 0.  */
end_comment

begin_define
define|#
directive|define
name|TV_CC_FID_MASK
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|TV_CC_FID_SHIFT
value|27
end_define

begin_comment
comment|/** Sets the horizontal position of the CC data.  Usually 135. */
end_comment

begin_define
define|#
directive|define
name|TV_CC_HOFF_MASK
value|0x03ff0000
end_define

begin_define
define|#
directive|define
name|TV_CC_HOFF_SHIFT
value|16
end_define

begin_comment
comment|/** Sets the vertical position of the CC data.  Usually 21 */
end_comment

begin_define
define|#
directive|define
name|TV_CC_LINE_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|TV_CC_LINE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_CC_DATA
value|0x68094
end_define

begin_define
define|#
directive|define
name|TV_CC_RDY
value|(1U<< 31)
end_define

begin_comment
comment|/** Second word of CC data to be transmitted. */
end_comment

begin_define
define|#
directive|define
name|TV_CC_DATA_2_MASK
value|0x007f0000
end_define

begin_define
define|#
directive|define
name|TV_CC_DATA_2_SHIFT
value|16
end_define

begin_comment
comment|/** First word of CC data to be transmitted. */
end_comment

begin_define
define|#
directive|define
name|TV_CC_DATA_1_MASK
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|TV_CC_DATA_1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TV_H_LUMA_0
value|0x68100
end_define

begin_define
define|#
directive|define
name|TV_H_LUMA_59
value|0x681ec
end_define

begin_define
define|#
directive|define
name|TV_H_CHROMA_0
value|0x68200
end_define

begin_define
define|#
directive|define
name|TV_H_CHROMA_59
value|0x682ec
end_define

begin_define
define|#
directive|define
name|TV_V_LUMA_0
value|0x68300
end_define

begin_define
define|#
directive|define
name|TV_V_LUMA_42
value|0x683a8
end_define

begin_define
define|#
directive|define
name|TV_V_CHROMA_0
value|0x68400
end_define

begin_define
define|#
directive|define
name|TV_V_CHROMA_42
value|0x684a8
end_define

begin_comment
comment|/* Display Port */
end_comment

begin_define
define|#
directive|define
name|DP_A
value|0x64000
end_define

begin_comment
comment|/* eDP */
end_comment

begin_define
define|#
directive|define
name|DP_B
value|0x64100
end_define

begin_define
define|#
directive|define
name|DP_C
value|0x64200
end_define

begin_define
define|#
directive|define
name|DP_D
value|0x64300
end_define

begin_define
define|#
directive|define
name|DP_PORT_EN
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|DP_PIPEB_SELECT
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|DP_PIPE_MASK
value|(1<< 30)
end_define

begin_comment
comment|/* Link training mode - select a suitable mode for each stage */
end_comment

begin_define
define|#
directive|define
name|DP_LINK_TRAIN_PAT_1
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|DP_LINK_TRAIN_PAT_2
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|DP_LINK_TRAIN_PAT_IDLE
value|(2<< 28)
end_define

begin_define
define|#
directive|define
name|DP_LINK_TRAIN_OFF
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|DP_LINK_TRAIN_MASK
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|DP_LINK_TRAIN_SHIFT
value|28
end_define

begin_comment
comment|/* CPT Link training mode */
end_comment

begin_define
define|#
directive|define
name|DP_LINK_TRAIN_PAT_1_CPT
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|DP_LINK_TRAIN_PAT_2_CPT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|DP_LINK_TRAIN_PAT_IDLE_CPT
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|DP_LINK_TRAIN_OFF_CPT
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|DP_LINK_TRAIN_MASK_CPT
value|(7<< 8)
end_define

begin_define
define|#
directive|define
name|DP_LINK_TRAIN_SHIFT_CPT
value|8
end_define

begin_comment
comment|/* Signal voltages. These are mostly controlled by the other end */
end_comment

begin_define
define|#
directive|define
name|DP_VOLTAGE_0_4
value|(0<< 25)
end_define

begin_define
define|#
directive|define
name|DP_VOLTAGE_0_6
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|DP_VOLTAGE_0_8
value|(2<< 25)
end_define

begin_define
define|#
directive|define
name|DP_VOLTAGE_1_2
value|(3<< 25)
end_define

begin_define
define|#
directive|define
name|DP_VOLTAGE_MASK
value|(7<< 25)
end_define

begin_define
define|#
directive|define
name|DP_VOLTAGE_SHIFT
value|25
end_define

begin_comment
comment|/* Signal pre-emphasis levels, like voltages, the other end tells us what  * they want  */
end_comment

begin_define
define|#
directive|define
name|DP_PRE_EMPHASIS_0
value|(0<< 22)
end_define

begin_define
define|#
directive|define
name|DP_PRE_EMPHASIS_3_5
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|DP_PRE_EMPHASIS_6
value|(2<< 22)
end_define

begin_define
define|#
directive|define
name|DP_PRE_EMPHASIS_9_5
value|(3<< 22)
end_define

begin_define
define|#
directive|define
name|DP_PRE_EMPHASIS_MASK
value|(7<< 22)
end_define

begin_define
define|#
directive|define
name|DP_PRE_EMPHASIS_SHIFT
value|22
end_define

begin_comment
comment|/* How many wires to use. I guess 3 was too hard */
end_comment

begin_define
define|#
directive|define
name|DP_PORT_WIDTH_1
value|(0<< 19)
end_define

begin_define
define|#
directive|define
name|DP_PORT_WIDTH_2
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|DP_PORT_WIDTH_4
value|(3<< 19)
end_define

begin_define
define|#
directive|define
name|DP_PORT_WIDTH_MASK
value|(7<< 19)
end_define

begin_comment
comment|/* Mystic DPCD version 1.1 special mode */
end_comment

begin_define
define|#
directive|define
name|DP_ENHANCED_FRAMING
value|(1<< 18)
end_define

begin_comment
comment|/* eDP */
end_comment

begin_define
define|#
directive|define
name|DP_PLL_FREQ_270MHZ
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|DP_PLL_FREQ_160MHZ
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|DP_PLL_FREQ_MASK
value|(3<< 16)
end_define

begin_comment
comment|/** locked once port is enabled */
end_comment

begin_define
define|#
directive|define
name|DP_PORT_REVERSAL
value|(1<< 15)
end_define

begin_comment
comment|/* eDP */
end_comment

begin_define
define|#
directive|define
name|DP_PLL_ENABLE
value|(1<< 14)
end_define

begin_comment
comment|/** sends the clock on lane 15 of the PEG for debug */
end_comment

begin_define
define|#
directive|define
name|DP_CLOCK_OUTPUT_ENABLE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|DP_SCRAMBLING_DISABLE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|DP_SCRAMBLING_DISABLE_IRONLAKE
value|(1<< 7)
end_define

begin_comment
comment|/** limit RGB values to avoid confusing TVs */
end_comment

begin_define
define|#
directive|define
name|DP_COLOR_RANGE_16_235
value|(1<< 8)
end_define

begin_comment
comment|/** Turn on the audio link */
end_comment

begin_define
define|#
directive|define
name|DP_AUDIO_OUTPUT_ENABLE
value|(1<< 6)
end_define

begin_comment
comment|/** vs and hs sync polarity */
end_comment

begin_define
define|#
directive|define
name|DP_SYNC_VS_HIGH
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DP_SYNC_HS_HIGH
value|(1<< 3)
end_define

begin_comment
comment|/** A fantasy */
end_comment

begin_define
define|#
directive|define
name|DP_DETECTED
value|(1<< 2)
end_define

begin_comment
comment|/** The aux channel provides a way to talk to the  * signal sink for DDC etc. Max packet size supported  * is 20 bytes in each direction, hence the 5 fixed  * data registers  */
end_comment

begin_define
define|#
directive|define
name|DPA_AUX_CH_CTL
value|0x64010
end_define

begin_define
define|#
directive|define
name|DPA_AUX_CH_DATA1
value|0x64014
end_define

begin_define
define|#
directive|define
name|DPA_AUX_CH_DATA2
value|0x64018
end_define

begin_define
define|#
directive|define
name|DPA_AUX_CH_DATA3
value|0x6401c
end_define

begin_define
define|#
directive|define
name|DPA_AUX_CH_DATA4
value|0x64020
end_define

begin_define
define|#
directive|define
name|DPA_AUX_CH_DATA5
value|0x64024
end_define

begin_define
define|#
directive|define
name|DPB_AUX_CH_CTL
value|0x64110
end_define

begin_define
define|#
directive|define
name|DPB_AUX_CH_DATA1
value|0x64114
end_define

begin_define
define|#
directive|define
name|DPB_AUX_CH_DATA2
value|0x64118
end_define

begin_define
define|#
directive|define
name|DPB_AUX_CH_DATA3
value|0x6411c
end_define

begin_define
define|#
directive|define
name|DPB_AUX_CH_DATA4
value|0x64120
end_define

begin_define
define|#
directive|define
name|DPB_AUX_CH_DATA5
value|0x64124
end_define

begin_define
define|#
directive|define
name|DPC_AUX_CH_CTL
value|0x64210
end_define

begin_define
define|#
directive|define
name|DPC_AUX_CH_DATA1
value|0x64214
end_define

begin_define
define|#
directive|define
name|DPC_AUX_CH_DATA2
value|0x64218
end_define

begin_define
define|#
directive|define
name|DPC_AUX_CH_DATA3
value|0x6421c
end_define

begin_define
define|#
directive|define
name|DPC_AUX_CH_DATA4
value|0x64220
end_define

begin_define
define|#
directive|define
name|DPC_AUX_CH_DATA5
value|0x64224
end_define

begin_define
define|#
directive|define
name|DPD_AUX_CH_CTL
value|0x64310
end_define

begin_define
define|#
directive|define
name|DPD_AUX_CH_DATA1
value|0x64314
end_define

begin_define
define|#
directive|define
name|DPD_AUX_CH_DATA2
value|0x64318
end_define

begin_define
define|#
directive|define
name|DPD_AUX_CH_DATA3
value|0x6431c
end_define

begin_define
define|#
directive|define
name|DPD_AUX_CH_DATA4
value|0x64320
end_define

begin_define
define|#
directive|define
name|DPD_AUX_CH_DATA5
value|0x64324
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_SEND_BUSY
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_DONE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_INTERRUPT
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_TIME_OUT_ERROR
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_TIME_OUT_400us
value|(0<< 26)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_TIME_OUT_600us
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_TIME_OUT_800us
value|(2<< 26)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_TIME_OUT_1600us
value|(3<< 26)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_TIME_OUT_MASK
value|(3<< 26)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_RECEIVE_ERROR
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_MESSAGE_SIZE_MASK
value|(0x1f<< 20)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_MESSAGE_SIZE_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_PRECHARGE_2US_MASK
value|(0xf<< 16)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_PRECHARGE_2US_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_AUX_AKSV_SELECT
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_MANCHESTER_TEST
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_SYNC_TEST
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_DEGLITCH_TEST
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_PRECHARGE_TEST
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_BIT_CLOCK_2X_MASK
value|(0x7ff)
end_define

begin_define
define|#
directive|define
name|DP_AUX_CH_CTL_BIT_CLOCK_2X_SHIFT
value|0
end_define

begin_comment
comment|/*  * Computing GMCH M and N values for the Display Port link  *  * GMCH M/N = dot clock * bytes per pixel / ls_clk * # of lanes  *  * ls_clk (we assume) is the DP link clock (1.62 or 2.7 GHz)  *  * The GMCH value is used internally  *  * bytes_per_pixel is the number of bytes coming out of the plane,  * which is after the LUTs, so we want the bytes for our color format.  * For our current usage, this is always 3, one byte for R, G and B.  */
end_comment

begin_define
define|#
directive|define
name|_PIPEA_GMCH_DATA_M
value|0x70050
end_define

begin_define
define|#
directive|define
name|_PIPEB_GMCH_DATA_M
value|0x71050
end_define

begin_comment
comment|/* Transfer unit size for display port - 1, default is 0x3f (for TU size 64) */
end_comment

begin_define
define|#
directive|define
name|PIPE_GMCH_DATA_M_TU_SIZE_MASK
value|(0x3f<< 25)
end_define

begin_define
define|#
directive|define
name|PIPE_GMCH_DATA_M_TU_SIZE_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|PIPE_GMCH_DATA_M_MASK
value|(0xffffff)
end_define

begin_define
define|#
directive|define
name|_PIPEA_GMCH_DATA_N
value|0x70054
end_define

begin_define
define|#
directive|define
name|_PIPEB_GMCH_DATA_N
value|0x71054
end_define

begin_define
define|#
directive|define
name|PIPE_GMCH_DATA_N_MASK
value|(0xffffff)
end_define

begin_comment
comment|/*  * Computing Link M and N values for the Display Port link  *  * Link M / N = pixel_clock / ls_clk  *  * (the DP spec calls pixel_clock the 'strm_clk')  *  * The Link value is transmitted in the Main Stream  * Attributes and VB-ID.  */
end_comment

begin_define
define|#
directive|define
name|_PIPEA_DP_LINK_M
value|0x70060
end_define

begin_define
define|#
directive|define
name|_PIPEB_DP_LINK_M
value|0x71060
end_define

begin_define
define|#
directive|define
name|PIPEA_DP_LINK_M_MASK
value|(0xffffff)
end_define

begin_define
define|#
directive|define
name|_PIPEA_DP_LINK_N
value|0x70064
end_define

begin_define
define|#
directive|define
name|_PIPEB_DP_LINK_N
value|0x71064
end_define

begin_define
define|#
directive|define
name|PIPEA_DP_LINK_N_MASK
value|(0xffffff)
end_define

begin_define
define|#
directive|define
name|PIPE_GMCH_DATA_M
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEA_GMCH_DATA_M, _PIPEB_GMCH_DATA_M)
end_define

begin_define
define|#
directive|define
name|PIPE_GMCH_DATA_N
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEA_GMCH_DATA_N, _PIPEB_GMCH_DATA_N)
end_define

begin_define
define|#
directive|define
name|PIPE_DP_LINK_M
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEA_DP_LINK_M, _PIPEB_DP_LINK_M)
end_define

begin_define
define|#
directive|define
name|PIPE_DP_LINK_N
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEA_DP_LINK_N, _PIPEB_DP_LINK_N)
end_define

begin_comment
comment|/* Display& cursor control */
end_comment

begin_comment
comment|/* Pipe A */
end_comment

begin_define
define|#
directive|define
name|_PIPEADSL
value|0x70000
end_define

begin_define
define|#
directive|define
name|DSL_LINEMASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|_PIPEACONF
value|0x70008
end_define

begin_define
define|#
directive|define
name|PIPECONF_ENABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|PIPECONF_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|PIPECONF_DOUBLE_WIDE
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|I965_PIPECONF_ACTIVE
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|PIPECONF_FRAME_START_DELAY_MASK
value|(3<<27)
end_define

begin_define
define|#
directive|define
name|PIPECONF_SINGLE_WIDE
value|0
end_define

begin_define
define|#
directive|define
name|PIPECONF_PIPE_UNLOCKED
value|0
end_define

begin_define
define|#
directive|define
name|PIPECONF_PIPE_LOCKED
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|PIPECONF_PALETTE
value|0
end_define

begin_define
define|#
directive|define
name|PIPECONF_GAMMA
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|PIPECONF_FORCE_BORDER
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|PIPECONF_INTERLACE_MASK
value|(7<< 21)
end_define

begin_comment
comment|/* Note that pre-gen3 does not support interlaced display directly. Panel  * fitting must be disabled on pre-ilk for interlaced. */
end_comment

begin_define
define|#
directive|define
name|PIPECONF_PROGRESSIVE
value|(0<< 21)
end_define

begin_define
define|#
directive|define
name|PIPECONF_INTERLACE_W_SYNC_SHIFT_PANEL
value|(4<< 21)
end_define

begin_comment
comment|/* gen4 only */
end_comment

begin_define
define|#
directive|define
name|PIPECONF_INTERLACE_W_SYNC_SHIFT
value|(5<< 21)
end_define

begin_comment
comment|/* gen4 only */
end_comment

begin_define
define|#
directive|define
name|PIPECONF_INTERLACE_W_FIELD_INDICATION
value|(6<< 21)
end_define

begin_define
define|#
directive|define
name|PIPECONF_INTERLACE_FIELD_0_ONLY
value|(7<< 21)
end_define

begin_comment
comment|/* gen3 only */
end_comment

begin_comment
comment|/* Ironlake and later have a complete new set of values for interlaced. PFIT  * means panel fitter required, PF means progressive fetch, DBL means power  * saving pixel doubling. */
end_comment

begin_define
define|#
directive|define
name|PIPECONF_PFIT_PF_INTERLACED_ILK
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|PIPECONF_INTERLACED_ILK
value|(3<< 21)
end_define

begin_define
define|#
directive|define
name|PIPECONF_INTERLACED_DBL_ILK
value|(4<< 21)
end_define

begin_comment
comment|/* ilk/snb only */
end_comment

begin_define
define|#
directive|define
name|PIPECONF_PFIT_PF_INTERLACED_DBL_ILK
value|(5<< 21)
end_define

begin_comment
comment|/* ilk/snb only */
end_comment

begin_define
define|#
directive|define
name|PIPECONF_CXSR_DOWNCLOCK
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|PIPECONF_BPP_MASK
value|(0x000000e0)
end_define

begin_define
define|#
directive|define
name|PIPECONF_BPP_8
value|(0<<5)
end_define

begin_define
define|#
directive|define
name|PIPECONF_BPP_10
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|PIPECONF_BPP_6
value|(2<<5)
end_define

begin_define
define|#
directive|define
name|PIPECONF_BPP_12
value|(3<<5)
end_define

begin_define
define|#
directive|define
name|PIPECONF_DITHER_EN
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|PIPECONF_DITHER_TYPE_MASK
value|(0x0000000c)
end_define

begin_define
define|#
directive|define
name|PIPECONF_DITHER_TYPE_SP
value|(0<<2)
end_define

begin_define
define|#
directive|define
name|PIPECONF_DITHER_TYPE_ST1
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|PIPECONF_DITHER_TYPE_ST2
value|(2<<2)
end_define

begin_define
define|#
directive|define
name|PIPECONF_DITHER_TYPE_TEMP
value|(3<<2)
end_define

begin_define
define|#
directive|define
name|_PIPEASTAT
value|0x70024
end_define

begin_define
define|#
directive|define
name|PIPE_FIFO_UNDERRUN_STATUS
value|(1UL<<31)
end_define

begin_define
define|#
directive|define
name|PIPE_CRC_ERROR_ENABLE
value|(1UL<<29)
end_define

begin_define
define|#
directive|define
name|PIPE_CRC_DONE_ENABLE
value|(1UL<<28)
end_define

begin_define
define|#
directive|define
name|PIPE_GMBUS_EVENT_ENABLE
value|(1UL<<27)
end_define

begin_define
define|#
directive|define
name|PIPE_HOTPLUG_INTERRUPT_ENABLE
value|(1UL<<26)
end_define

begin_define
define|#
directive|define
name|PIPE_VSYNC_INTERRUPT_ENABLE
value|(1UL<<25)
end_define

begin_define
define|#
directive|define
name|PIPE_DISPLAY_LINE_COMPARE_ENABLE
value|(1UL<<24)
end_define

begin_define
define|#
directive|define
name|PIPE_DPST_EVENT_ENABLE
value|(1UL<<23)
end_define

begin_define
define|#
directive|define
name|PIPE_LEGACY_BLC_EVENT_ENABLE
value|(1UL<<22)
end_define

begin_define
define|#
directive|define
name|PIPE_ODD_FIELD_INTERRUPT_ENABLE
value|(1UL<<21)
end_define

begin_define
define|#
directive|define
name|PIPE_EVEN_FIELD_INTERRUPT_ENABLE
value|(1UL<<20)
end_define

begin_define
define|#
directive|define
name|PIPE_HOTPLUG_TV_INTERRUPT_ENABLE
value|(1UL<<18)
end_define

begin_comment
comment|/* pre-965 */
end_comment

begin_define
define|#
directive|define
name|PIPE_START_VBLANK_INTERRUPT_ENABLE
value|(1UL<<18)
end_define

begin_comment
comment|/* 965 or later */
end_comment

begin_define
define|#
directive|define
name|PIPE_VBLANK_INTERRUPT_ENABLE
value|(1UL<<17)
end_define

begin_define
define|#
directive|define
name|PIPE_OVERLAY_UPDATED_ENABLE
value|(1UL<<16)
end_define

begin_define
define|#
directive|define
name|PIPE_CRC_ERROR_INTERRUPT_STATUS
value|(1UL<<13)
end_define

begin_define
define|#
directive|define
name|PIPE_CRC_DONE_INTERRUPT_STATUS
value|(1UL<<12)
end_define

begin_define
define|#
directive|define
name|PIPE_GMBUS_INTERRUPT_STATUS
value|(1UL<<11)
end_define

begin_define
define|#
directive|define
name|PIPE_HOTPLUG_INTERRUPT_STATUS
value|(1UL<<10)
end_define

begin_define
define|#
directive|define
name|PIPE_VSYNC_INTERRUPT_STATUS
value|(1UL<<9)
end_define

begin_define
define|#
directive|define
name|PIPE_DISPLAY_LINE_COMPARE_STATUS
value|(1UL<<8)
end_define

begin_define
define|#
directive|define
name|PIPE_DPST_EVENT_STATUS
value|(1UL<<7)
end_define

begin_define
define|#
directive|define
name|PIPE_LEGACY_BLC_EVENT_STATUS
value|(1UL<<6)
end_define

begin_define
define|#
directive|define
name|PIPE_ODD_FIELD_INTERRUPT_STATUS
value|(1UL<<5)
end_define

begin_define
define|#
directive|define
name|PIPE_EVEN_FIELD_INTERRUPT_STATUS
value|(1UL<<4)
end_define

begin_define
define|#
directive|define
name|PIPE_HOTPLUG_TV_INTERRUPT_STATUS
value|(1UL<<2)
end_define

begin_comment
comment|/* pre-965 */
end_comment

begin_define
define|#
directive|define
name|PIPE_START_VBLANK_INTERRUPT_STATUS
value|(1UL<<2)
end_define

begin_comment
comment|/* 965 or later */
end_comment

begin_define
define|#
directive|define
name|PIPE_VBLANK_INTERRUPT_STATUS
value|(1UL<<1)
end_define

begin_define
define|#
directive|define
name|PIPE_OVERLAY_UPDATED_STATUS
value|(1UL<<0)
end_define

begin_define
define|#
directive|define
name|PIPE_BPC_MASK
value|(7<< 5)
end_define

begin_comment
comment|/* Ironlake */
end_comment

begin_define
define|#
directive|define
name|PIPE_8BPC
value|(0<< 5)
end_define

begin_define
define|#
directive|define
name|PIPE_10BPC
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PIPE_6BPC
value|(2<< 5)
end_define

begin_define
define|#
directive|define
name|PIPE_12BPC
value|(3<< 5)
end_define

begin_define
define|#
directive|define
name|PIPESRC
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEASRC, _PIPEBSRC)
end_define

begin_define
define|#
directive|define
name|PIPECONF
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEACONF, _PIPEBCONF)
end_define

begin_define
define|#
directive|define
name|PIPEDSL
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEADSL, _PIPEBDSL)
end_define

begin_define
define|#
directive|define
name|PIPEFRAME
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEAFRAMEHIGH, _PIPEBFRAMEHIGH)
end_define

begin_define
define|#
directive|define
name|PIPEFRAMEPIXEL
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEAFRAMEPIXEL, _PIPEBFRAMEPIXEL)
end_define

begin_define
define|#
directive|define
name|PIPESTAT
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEASTAT, _PIPEBSTAT)
end_define

begin_define
define|#
directive|define
name|DSPARB
value|0x70030
end_define

begin_define
define|#
directive|define
name|DSPARB_CSTART_MASK
value|(0x7f<< 7)
end_define

begin_define
define|#
directive|define
name|DSPARB_CSTART_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|DSPARB_BSTART_MASK
value|(0x7f)
end_define

begin_define
define|#
directive|define
name|DSPARB_BSTART_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DSPARB_BEND_SHIFT
value|9
end_define

begin_comment
comment|/* on 855 */
end_comment

begin_define
define|#
directive|define
name|DSPARB_AEND_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DSPFW1
value|0x70034
end_define

begin_define
define|#
directive|define
name|DSPFW_SR_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|DSPFW_SR_MASK
value|(0x1ff<<23)
end_define

begin_define
define|#
directive|define
name|DSPFW_CURSORB_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DSPFW_CURSORB_MASK
value|(0x3f<<16)
end_define

begin_define
define|#
directive|define
name|DSPFW_PLANEB_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|DSPFW_PLANEB_MASK
value|(0x7f<<8)
end_define

begin_define
define|#
directive|define
name|DSPFW_PLANEA_MASK
value|(0x7f)
end_define

begin_define
define|#
directive|define
name|DSPFW2
value|0x70038
end_define

begin_define
define|#
directive|define
name|DSPFW_CURSORA_MASK
value|0x00003f00
end_define

begin_define
define|#
directive|define
name|DSPFW_CURSORA_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|DSPFW_PLANEC_MASK
value|(0x7f)
end_define

begin_define
define|#
directive|define
name|DSPFW3
value|0x7003c
end_define

begin_define
define|#
directive|define
name|DSPFW_HPLL_SR_EN
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|DSPFW_CURSOR_SR_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|PINEVIEW_SELF_REFRESH_EN
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|DSPFW_CURSOR_SR_MASK
value|(0x3f<<24)
end_define

begin_define
define|#
directive|define
name|DSPFW_HPLL_CURSOR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DSPFW_HPLL_CURSOR_MASK
value|(0x3f<<16)
end_define

begin_define
define|#
directive|define
name|DSPFW_HPLL_SR_MASK
value|(0x1ff)
end_define

begin_comment
comment|/* FIFO watermark sizes etc */
end_comment

begin_define
define|#
directive|define
name|G4X_FIFO_LINE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|I915_FIFO_LINE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|I830_FIFO_LINE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|G4X_FIFO_SIZE
value|127
end_define

begin_define
define|#
directive|define
name|I965_FIFO_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|I945_FIFO_SIZE
value|127
end_define

begin_define
define|#
directive|define
name|I915_FIFO_SIZE
value|95
end_define

begin_define
define|#
directive|define
name|I855GM_FIFO_SIZE
value|127
end_define

begin_comment
comment|/* In cachelines */
end_comment

begin_define
define|#
directive|define
name|I830_FIFO_SIZE
value|95
end_define

begin_define
define|#
directive|define
name|G4X_MAX_WM
value|0x3f
end_define

begin_define
define|#
directive|define
name|I915_MAX_WM
value|0x3f
end_define

begin_define
define|#
directive|define
name|PINEVIEW_DISPLAY_FIFO
value|512
end_define

begin_comment
comment|/* in 64byte unit */
end_comment

begin_define
define|#
directive|define
name|PINEVIEW_FIFO_LINE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|PINEVIEW_MAX_WM
value|0x1ff
end_define

begin_define
define|#
directive|define
name|PINEVIEW_DFT_WM
value|0x3f
end_define

begin_define
define|#
directive|define
name|PINEVIEW_DFT_HPLLOFF_WM
value|0
end_define

begin_define
define|#
directive|define
name|PINEVIEW_GUARD_WM
value|10
end_define

begin_define
define|#
directive|define
name|PINEVIEW_CURSOR_FIFO
value|64
end_define

begin_define
define|#
directive|define
name|PINEVIEW_CURSOR_MAX_WM
value|0x3f
end_define

begin_define
define|#
directive|define
name|PINEVIEW_CURSOR_DFT_WM
value|0
end_define

begin_define
define|#
directive|define
name|PINEVIEW_CURSOR_GUARD_WM
value|5
end_define

begin_define
define|#
directive|define
name|I965_CURSOR_FIFO
value|64
end_define

begin_define
define|#
directive|define
name|I965_CURSOR_MAX_WM
value|32
end_define

begin_define
define|#
directive|define
name|I965_CURSOR_DFT_WM
value|8
end_define

begin_comment
comment|/* define the Watermark register on Ironlake */
end_comment

begin_define
define|#
directive|define
name|WM0_PIPEA_ILK
value|0x45100
end_define

begin_define
define|#
directive|define
name|WM0_PIPE_PLANE_MASK
value|(0x7f<<16)
end_define

begin_define
define|#
directive|define
name|WM0_PIPE_PLANE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|WM0_PIPE_SPRITE_MASK
value|(0x3f<<8)
end_define

begin_define
define|#
directive|define
name|WM0_PIPE_SPRITE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|WM0_PIPE_CURSOR_MASK
value|(0x1f)
end_define

begin_define
define|#
directive|define
name|WM0_PIPEB_ILK
value|0x45104
end_define

begin_define
define|#
directive|define
name|WM0_PIPEC_IVB
value|0x45200
end_define

begin_define
define|#
directive|define
name|WM1_LP_ILK
value|0x45108
end_define

begin_define
define|#
directive|define
name|WM1_LP_SR_EN
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|WM1_LP_LATENCY_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|WM1_LP_LATENCY_MASK
value|(0x7f<<24)
end_define

begin_define
define|#
directive|define
name|WM1_LP_FBC_MASK
value|(0xf<<20)
end_define

begin_define
define|#
directive|define
name|WM1_LP_FBC_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|WM1_LP_SR_MASK
value|(0x1ff<<8)
end_define

begin_define
define|#
directive|define
name|WM1_LP_SR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|WM1_LP_CURSOR_MASK
value|(0x3f)
end_define

begin_define
define|#
directive|define
name|WM2_LP_ILK
value|0x4510c
end_define

begin_define
define|#
directive|define
name|WM2_LP_EN
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|WM3_LP_ILK
value|0x45110
end_define

begin_define
define|#
directive|define
name|WM3_LP_EN
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|WM1S_LP_ILK
value|0x45120
end_define

begin_define
define|#
directive|define
name|WM2S_LP_IVB
value|0x45124
end_define

begin_define
define|#
directive|define
name|WM3S_LP_IVB
value|0x45128
end_define

begin_define
define|#
directive|define
name|WM1S_LP_EN
value|(1<<31)
end_define

begin_comment
comment|/* Memory latency timer register */
end_comment

begin_define
define|#
directive|define
name|MLTR_ILK
value|0x11222
end_define

begin_define
define|#
directive|define
name|MLTR_WM1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MLTR_WM2_SHIFT
value|8
end_define

begin_comment
comment|/* the unit of memory self-refresh latency time is 0.5us */
end_comment

begin_define
define|#
directive|define
name|ILK_SRLT_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|ILK_LATENCY
parameter_list|(
name|shift
parameter_list|)
value|(I915_READ(MLTR_ILK)>> (shift)& ILK_SRLT_MASK)
end_define

begin_define
define|#
directive|define
name|ILK_READ_WM1_LATENCY
parameter_list|()
value|ILK_LATENCY(MLTR_WM1_SHIFT)
end_define

begin_define
define|#
directive|define
name|ILK_READ_WM2_LATENCY
parameter_list|()
value|ILK_LATENCY(MLTR_WM2_SHIFT)
end_define

begin_comment
comment|/* define the fifo size on Ironlake */
end_comment

begin_define
define|#
directive|define
name|ILK_DISPLAY_FIFO
value|128
end_define

begin_define
define|#
directive|define
name|ILK_DISPLAY_MAXWM
value|64
end_define

begin_define
define|#
directive|define
name|ILK_DISPLAY_DFTWM
value|8
end_define

begin_define
define|#
directive|define
name|ILK_CURSOR_FIFO
value|32
end_define

begin_define
define|#
directive|define
name|ILK_CURSOR_MAXWM
value|16
end_define

begin_define
define|#
directive|define
name|ILK_CURSOR_DFTWM
value|8
end_define

begin_define
define|#
directive|define
name|ILK_DISPLAY_SR_FIFO
value|512
end_define

begin_define
define|#
directive|define
name|ILK_DISPLAY_MAX_SRWM
value|0x1ff
end_define

begin_define
define|#
directive|define
name|ILK_DISPLAY_DFT_SRWM
value|0x3f
end_define

begin_define
define|#
directive|define
name|ILK_CURSOR_SR_FIFO
value|64
end_define

begin_define
define|#
directive|define
name|ILK_CURSOR_MAX_SRWM
value|0x3f
end_define

begin_define
define|#
directive|define
name|ILK_CURSOR_DFT_SRWM
value|8
end_define

begin_define
define|#
directive|define
name|ILK_FIFO_LINE_SIZE
value|64
end_define

begin_comment
comment|/* define the WM info on Sandybridge */
end_comment

begin_define
define|#
directive|define
name|SNB_DISPLAY_FIFO
value|128
end_define

begin_define
define|#
directive|define
name|SNB_DISPLAY_MAXWM
value|0x7f
end_define

begin_comment
comment|/* bit 16:22 */
end_comment

begin_define
define|#
directive|define
name|SNB_DISPLAY_DFTWM
value|8
end_define

begin_define
define|#
directive|define
name|SNB_CURSOR_FIFO
value|32
end_define

begin_define
define|#
directive|define
name|SNB_CURSOR_MAXWM
value|0x1f
end_define

begin_comment
comment|/* bit 4:0 */
end_comment

begin_define
define|#
directive|define
name|SNB_CURSOR_DFTWM
value|8
end_define

begin_define
define|#
directive|define
name|SNB_DISPLAY_SR_FIFO
value|512
end_define

begin_define
define|#
directive|define
name|SNB_DISPLAY_MAX_SRWM
value|0x1ff
end_define

begin_comment
comment|/* bit 16:8 */
end_comment

begin_define
define|#
directive|define
name|SNB_DISPLAY_DFT_SRWM
value|0x3f
end_define

begin_define
define|#
directive|define
name|SNB_CURSOR_SR_FIFO
value|64
end_define

begin_define
define|#
directive|define
name|SNB_CURSOR_MAX_SRWM
value|0x3f
end_define

begin_comment
comment|/* bit 5:0 */
end_comment

begin_define
define|#
directive|define
name|SNB_CURSOR_DFT_SRWM
value|8
end_define

begin_define
define|#
directive|define
name|SNB_FBC_MAX_SRWM
value|0xf
end_define

begin_comment
comment|/* bit 23:20 */
end_comment

begin_define
define|#
directive|define
name|SNB_FIFO_LINE_SIZE
value|64
end_define

begin_comment
comment|/* the address where we get all kinds of latency value */
end_comment

begin_define
define|#
directive|define
name|SSKPD
value|0x5d10
end_define

begin_define
define|#
directive|define
name|SSKPD_WM_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|SSKPD_WM0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SSKPD_WM1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SSKPD_WM2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SSKPD_WM3_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|SNB_LATENCY
parameter_list|(
name|shift
parameter_list|)
value|(I915_READ(MCHBAR_MIRROR_BASE_SNB + SSKPD)>> (shift)& SSKPD_WM_MASK)
end_define

begin_define
define|#
directive|define
name|SNB_READ_WM0_LATENCY
parameter_list|()
value|SNB_LATENCY(SSKPD_WM0_SHIFT)
end_define

begin_define
define|#
directive|define
name|SNB_READ_WM1_LATENCY
parameter_list|()
value|SNB_LATENCY(SSKPD_WM1_SHIFT)
end_define

begin_define
define|#
directive|define
name|SNB_READ_WM2_LATENCY
parameter_list|()
value|SNB_LATENCY(SSKPD_WM2_SHIFT)
end_define

begin_define
define|#
directive|define
name|SNB_READ_WM3_LATENCY
parameter_list|()
value|SNB_LATENCY(SSKPD_WM3_SHIFT)
end_define

begin_comment
comment|/*  * The two pipe frame counter registers are not synchronized, so  * reading a stable value is somewhat tricky. The following code  * should work:  *  *  do {  *    high1 = ((INREG(PIPEAFRAMEHIGH)& PIPE_FRAME_HIGH_MASK)>>  *             PIPE_FRAME_HIGH_SHIFT;  *    low1 =  ((INREG(PIPEAFRAMEPIXEL)& PIPE_FRAME_LOW_MASK)>>  *             PIPE_FRAME_LOW_SHIFT);  *    high2 = ((INREG(PIPEAFRAMEHIGH)& PIPE_FRAME_HIGH_MASK)>>  *             PIPE_FRAME_HIGH_SHIFT);  *  } while (high1 != high2);  *  frame = (high1<< 8) | low1;  */
end_comment

begin_define
define|#
directive|define
name|_PIPEAFRAMEHIGH
value|0x70040
end_define

begin_define
define|#
directive|define
name|PIPE_FRAME_HIGH_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|PIPE_FRAME_HIGH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|_PIPEAFRAMEPIXEL
value|0x70044
end_define

begin_define
define|#
directive|define
name|PIPE_FRAME_LOW_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|PIPE_FRAME_LOW_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|PIPE_PIXEL_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|PIPE_PIXEL_SHIFT
value|0
end_define

begin_comment
comment|/* GM45+ just has to be different */
end_comment

begin_define
define|#
directive|define
name|_PIPEA_FRMCOUNT_GM45
value|0x70040
end_define

begin_define
define|#
directive|define
name|_PIPEA_FLIPCOUNT_GM45
value|0x70044
end_define

begin_define
define|#
directive|define
name|PIPE_FRMCOUNT_GM45
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEA_FRMCOUNT_GM45, _PIPEB_FRMCOUNT_GM45)
end_define

begin_comment
comment|/* Cursor A& B regs */
end_comment

begin_define
define|#
directive|define
name|_CURACNTR
value|0x70080
end_define

begin_comment
comment|/* Old style CUR*CNTR flags (desktop 8xx) */
end_comment

begin_define
define|#
directive|define
name|CURSOR_ENABLE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CURSOR_GAMMA_ENABLE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|CURSOR_STRIDE_MASK
value|0x30000000
end_define

begin_define
define|#
directive|define
name|CURSOR_FORMAT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|CURSOR_FORMAT_MASK
value|(0x07<< CURSOR_FORMAT_SHIFT)
end_define

begin_define
define|#
directive|define
name|CURSOR_FORMAT_2C
value|(0x00<< CURSOR_FORMAT_SHIFT)
end_define

begin_define
define|#
directive|define
name|CURSOR_FORMAT_3C
value|(0x01<< CURSOR_FORMAT_SHIFT)
end_define

begin_define
define|#
directive|define
name|CURSOR_FORMAT_4C
value|(0x02<< CURSOR_FORMAT_SHIFT)
end_define

begin_define
define|#
directive|define
name|CURSOR_FORMAT_ARGB
value|(0x04<< CURSOR_FORMAT_SHIFT)
end_define

begin_define
define|#
directive|define
name|CURSOR_FORMAT_XRGB
value|(0x05<< CURSOR_FORMAT_SHIFT)
end_define

begin_comment
comment|/* New style CUR*CNTR flags */
end_comment

begin_define
define|#
directive|define
name|CURSOR_MODE
value|0x27
end_define

begin_define
define|#
directive|define
name|CURSOR_MODE_DISABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|CURSOR_MODE_64_32B_AX
value|0x07
end_define

begin_define
define|#
directive|define
name|CURSOR_MODE_64_ARGB_AX
value|((1<< 5) | CURSOR_MODE_64_32B_AX)
end_define

begin_define
define|#
directive|define
name|MCURSOR_PIPE_SELECT
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|MCURSOR_PIPE_A
value|0x00
end_define

begin_define
define|#
directive|define
name|MCURSOR_PIPE_B
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|MCURSOR_GAMMA_ENABLE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|_CURABASE
value|0x70084
end_define

begin_define
define|#
directive|define
name|_CURAPOS
value|0x70088
end_define

begin_define
define|#
directive|define
name|CURSOR_POS_MASK
value|0x007FF
end_define

begin_define
define|#
directive|define
name|CURSOR_POS_SIGN
value|0x8000
end_define

begin_define
define|#
directive|define
name|CURSOR_X_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CURSOR_Y_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CURSIZE
value|0x700a0
end_define

begin_define
define|#
directive|define
name|_CURBCNTR
value|0x700c0
end_define

begin_define
define|#
directive|define
name|_CURBBASE
value|0x700c4
end_define

begin_define
define|#
directive|define
name|_CURBPOS
value|0x700c8
end_define

begin_define
define|#
directive|define
name|_CURBCNTR_IVB
value|0x71080
end_define

begin_define
define|#
directive|define
name|_CURBBASE_IVB
value|0x71084
end_define

begin_define
define|#
directive|define
name|_CURBPOS_IVB
value|0x71088
end_define

begin_define
define|#
directive|define
name|CURCNTR
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _CURACNTR, _CURBCNTR)
end_define

begin_define
define|#
directive|define
name|CURBASE
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _CURABASE, _CURBBASE)
end_define

begin_define
define|#
directive|define
name|CURPOS
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _CURAPOS, _CURBPOS)
end_define

begin_define
define|#
directive|define
name|CURCNTR_IVB
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _CURACNTR, _CURBCNTR_IVB)
end_define

begin_define
define|#
directive|define
name|CURBASE_IVB
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _CURABASE, _CURBBASE_IVB)
end_define

begin_define
define|#
directive|define
name|CURPOS_IVB
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _CURAPOS, _CURBPOS_IVB)
end_define

begin_comment
comment|/* Display A control */
end_comment

begin_define
define|#
directive|define
name|_DSPACNTR
value|0x70180
end_define

begin_define
define|#
directive|define
name|DISPLAY_PLANE_ENABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|DISPLAY_PLANE_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_GAMMA_ENABLE
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_GAMMA_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_PIXFORMAT_MASK
value|(0xf<<26)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_8BPP
value|(0x2<<26)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_15_16BPP
value|(0x4<<26)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_16BPP
value|(0x5<<26)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_32BPP_NO_ALPHA
value|(0x6<<26)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_32BPP
value|(0x7<<26)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_32BPP_30BIT_NO_ALPHA
value|(0xa<<26)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_STEREO_ENABLE
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_STEREO_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_SEL_PIPE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|DISPPLANE_SEL_PIPE_MASK
value|(3<<DISPPLANE_SEL_PIPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_SEL_PIPE_A
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_SEL_PIPE_B
value|(1<<DISPPLANE_SEL_PIPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_SRC_KEY_ENABLE
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_SRC_KEY_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_LINE_DOUBLE
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_NO_LINE_DOUBLE
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_STEREO_POLARITY_FIRST
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_STEREO_POLARITY_SECOND
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_TRICKLE_FEED_DISABLE
value|(1<<14)
end_define

begin_comment
comment|/* Ironlake */
end_comment

begin_define
define|#
directive|define
name|DISPPLANE_TILED
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|_DSPAADDR
value|0x70184
end_define

begin_define
define|#
directive|define
name|_DSPASTRIDE
value|0x70188
end_define

begin_define
define|#
directive|define
name|_DSPAPOS
value|0x7018C
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|_DSPASIZE
value|0x70190
end_define

begin_define
define|#
directive|define
name|_DSPASURF
value|0x7019C
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_define
define|#
directive|define
name|_DSPATILEOFF
value|0x701A4
end_define

begin_comment
comment|/* 965+ only */
end_comment

begin_define
define|#
directive|define
name|DSPCNTR
parameter_list|(
name|plane
parameter_list|)
value|_PIPE(plane, _DSPACNTR, _DSPBCNTR)
end_define

begin_define
define|#
directive|define
name|DSPADDR
parameter_list|(
name|plane
parameter_list|)
value|_PIPE(plane, _DSPAADDR, _DSPBADDR)
end_define

begin_define
define|#
directive|define
name|DSPSTRIDE
parameter_list|(
name|plane
parameter_list|)
value|_PIPE(plane, _DSPASTRIDE, _DSPBSTRIDE)
end_define

begin_define
define|#
directive|define
name|DSPPOS
parameter_list|(
name|plane
parameter_list|)
value|_PIPE(plane, _DSPAPOS, _DSPBPOS)
end_define

begin_define
define|#
directive|define
name|DSPSIZE
parameter_list|(
name|plane
parameter_list|)
value|_PIPE(plane, _DSPASIZE, _DSPBSIZE)
end_define

begin_define
define|#
directive|define
name|DSPSURF
parameter_list|(
name|plane
parameter_list|)
value|_PIPE(plane, _DSPASURF, _DSPBSURF)
end_define

begin_define
define|#
directive|define
name|DSPTILEOFF
parameter_list|(
name|plane
parameter_list|)
value|_PIPE(plane, _DSPATILEOFF, _DSPBTILEOFF)
end_define

begin_comment
comment|/* VBIOS flags */
end_comment

begin_define
define|#
directive|define
name|SWF00
value|0x71410
end_define

begin_define
define|#
directive|define
name|SWF01
value|0x71414
end_define

begin_define
define|#
directive|define
name|SWF02
value|0x71418
end_define

begin_define
define|#
directive|define
name|SWF03
value|0x7141c
end_define

begin_define
define|#
directive|define
name|SWF04
value|0x71420
end_define

begin_define
define|#
directive|define
name|SWF05
value|0x71424
end_define

begin_define
define|#
directive|define
name|SWF06
value|0x71428
end_define

begin_define
define|#
directive|define
name|SWF10
value|0x70410
end_define

begin_define
define|#
directive|define
name|SWF11
value|0x70414
end_define

begin_define
define|#
directive|define
name|SWF14
value|0x71420
end_define

begin_define
define|#
directive|define
name|SWF30
value|0x72414
end_define

begin_define
define|#
directive|define
name|SWF31
value|0x72418
end_define

begin_define
define|#
directive|define
name|SWF32
value|0x7241c
end_define

begin_comment
comment|/* Pipe B */
end_comment

begin_define
define|#
directive|define
name|_PIPEBDSL
value|0x71000
end_define

begin_define
define|#
directive|define
name|_PIPEBCONF
value|0x71008
end_define

begin_define
define|#
directive|define
name|_PIPEBSTAT
value|0x71024
end_define

begin_define
define|#
directive|define
name|_PIPEBFRAMEHIGH
value|0x71040
end_define

begin_define
define|#
directive|define
name|_PIPEBFRAMEPIXEL
value|0x71044
end_define

begin_define
define|#
directive|define
name|_PIPEB_FRMCOUNT_GM45
value|0x71040
end_define

begin_define
define|#
directive|define
name|_PIPEB_FLIPCOUNT_GM45
value|0x71044
end_define

begin_comment
comment|/* Display B control */
end_comment

begin_define
define|#
directive|define
name|_DSPBCNTR
value|0x71180
end_define

begin_define
define|#
directive|define
name|DISPPLANE_ALPHA_TRANS_ENABLE
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|DISPPLANE_ALPHA_TRANS_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_SPRITE_ABOVE_DISPLAY
value|0
end_define

begin_define
define|#
directive|define
name|DISPPLANE_SPRITE_ABOVE_OVERLAY
value|(1)
end_define

begin_define
define|#
directive|define
name|_DSPBADDR
value|0x71184
end_define

begin_define
define|#
directive|define
name|_DSPBSTRIDE
value|0x71188
end_define

begin_define
define|#
directive|define
name|_DSPBPOS
value|0x7118C
end_define

begin_define
define|#
directive|define
name|_DSPBSIZE
value|0x71190
end_define

begin_define
define|#
directive|define
name|_DSPBSURF
value|0x7119C
end_define

begin_define
define|#
directive|define
name|_DSPBTILEOFF
value|0x711A4
end_define

begin_comment
comment|/* Sprite A control */
end_comment

begin_define
define|#
directive|define
name|_DVSACNTR
value|0x72180
end_define

begin_define
define|#
directive|define
name|DVS_ENABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|DVS_GAMMA_ENABLE
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|DVS_PIXFORMAT_MASK
value|(3<<25)
end_define

begin_define
define|#
directive|define
name|DVS_FORMAT_YUV422
value|(0<<25)
end_define

begin_define
define|#
directive|define
name|DVS_FORMAT_RGBX101010
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|DVS_FORMAT_RGBX888
value|(2<<25)
end_define

begin_define
define|#
directive|define
name|DVS_FORMAT_RGBX161616
value|(3<<25)
end_define

begin_define
define|#
directive|define
name|DVS_SOURCE_KEY
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|DVS_RGB_ORDER_XBGR
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|DVS_YUV_BYTE_ORDER_MASK
value|(3<<16)
end_define

begin_define
define|#
directive|define
name|DVS_YUV_ORDER_YUYV
value|(0<<16)
end_define

begin_define
define|#
directive|define
name|DVS_YUV_ORDER_UYVY
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|DVS_YUV_ORDER_YVYU
value|(2<<16)
end_define

begin_define
define|#
directive|define
name|DVS_YUV_ORDER_VYUY
value|(3<<16)
end_define

begin_define
define|#
directive|define
name|DVS_DEST_KEY
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|DVS_TRICKLE_FEED_DISABLE
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|DVS_TILED
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|_DVSALINOFF
value|0x72184
end_define

begin_define
define|#
directive|define
name|_DVSASTRIDE
value|0x72188
end_define

begin_define
define|#
directive|define
name|_DVSAPOS
value|0x7218c
end_define

begin_define
define|#
directive|define
name|_DVSASIZE
value|0x72190
end_define

begin_define
define|#
directive|define
name|_DVSAKEYVAL
value|0x72194
end_define

begin_define
define|#
directive|define
name|_DVSAKEYMSK
value|0x72198
end_define

begin_define
define|#
directive|define
name|_DVSASURF
value|0x7219c
end_define

begin_define
define|#
directive|define
name|_DVSAKEYMAXVAL
value|0x721a0
end_define

begin_define
define|#
directive|define
name|_DVSATILEOFF
value|0x721a4
end_define

begin_define
define|#
directive|define
name|_DVSASURFLIVE
value|0x721ac
end_define

begin_define
define|#
directive|define
name|_DVSASCALE
value|0x72204
end_define

begin_define
define|#
directive|define
name|DVS_SCALE_ENABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|DVS_FILTER_MASK
value|(3<<29)
end_define

begin_define
define|#
directive|define
name|DVS_FILTER_MEDIUM
value|(0<<29)
end_define

begin_define
define|#
directive|define
name|DVS_FILTER_ENHANCING
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|DVS_FILTER_SOFTENING
value|(2<<29)
end_define

begin_define
define|#
directive|define
name|DVS_VERTICAL_OFFSET_HALF
value|(1<<28)
end_define

begin_comment
comment|/* must be enabled below */
end_comment

begin_define
define|#
directive|define
name|DVS_VERTICAL_OFFSET_ENABLE
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|_DVSAGAMC
value|0x72300
end_define

begin_define
define|#
directive|define
name|_DVSBCNTR
value|0x73180
end_define

begin_define
define|#
directive|define
name|_DVSBLINOFF
value|0x73184
end_define

begin_define
define|#
directive|define
name|_DVSBSTRIDE
value|0x73188
end_define

begin_define
define|#
directive|define
name|_DVSBPOS
value|0x7318c
end_define

begin_define
define|#
directive|define
name|_DVSBSIZE
value|0x73190
end_define

begin_define
define|#
directive|define
name|_DVSBKEYVAL
value|0x73194
end_define

begin_define
define|#
directive|define
name|_DVSBKEYMSK
value|0x73198
end_define

begin_define
define|#
directive|define
name|_DVSBSURF
value|0x7319c
end_define

begin_define
define|#
directive|define
name|_DVSBKEYMAXVAL
value|0x731a0
end_define

begin_define
define|#
directive|define
name|_DVSBTILEOFF
value|0x731a4
end_define

begin_define
define|#
directive|define
name|_DVSBSURFLIVE
value|0x731ac
end_define

begin_define
define|#
directive|define
name|_DVSBSCALE
value|0x73204
end_define

begin_define
define|#
directive|define
name|_DVSBGAMC
value|0x73300
end_define

begin_define
define|#
directive|define
name|DVSCNTR
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _DVSACNTR, _DVSBCNTR)
end_define

begin_define
define|#
directive|define
name|DVSLINOFF
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _DVSALINOFF, _DVSBLINOFF)
end_define

begin_define
define|#
directive|define
name|DVSSTRIDE
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _DVSASTRIDE, _DVSBSTRIDE)
end_define

begin_define
define|#
directive|define
name|DVSPOS
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _DVSAPOS, _DVSBPOS)
end_define

begin_define
define|#
directive|define
name|DVSSURF
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _DVSASURF, _DVSBSURF)
end_define

begin_define
define|#
directive|define
name|DVSKEYMAX
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _DVSAKEYMAXVAL, _DVSBKEYMAXVAL)
end_define

begin_define
define|#
directive|define
name|DVSSIZE
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _DVSASIZE, _DVSBSIZE)
end_define

begin_define
define|#
directive|define
name|DVSSCALE
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _DVSASCALE, _DVSBSCALE)
end_define

begin_define
define|#
directive|define
name|DVSTILEOFF
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _DVSATILEOFF, _DVSBTILEOFF)
end_define

begin_define
define|#
directive|define
name|DVSKEYVAL
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _DVSAKEYVAL, _DVSBKEYVAL)
end_define

begin_define
define|#
directive|define
name|DVSKEYMSK
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _DVSAKEYMSK, _DVSBKEYMSK)
end_define

begin_define
define|#
directive|define
name|_SPRA_CTL
value|0x70280
end_define

begin_define
define|#
directive|define
name|SPRITE_ENABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|SPRITE_GAMMA_ENABLE
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|SPRITE_PIXFORMAT_MASK
value|(7<<25)
end_define

begin_define
define|#
directive|define
name|SPRITE_FORMAT_YUV422
value|(0<<25)
end_define

begin_define
define|#
directive|define
name|SPRITE_FORMAT_RGBX101010
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|SPRITE_FORMAT_RGBX888
value|(2<<25)
end_define

begin_define
define|#
directive|define
name|SPRITE_FORMAT_RGBX161616
value|(3<<25)
end_define

begin_define
define|#
directive|define
name|SPRITE_FORMAT_YUV444
value|(4<<25)
end_define

begin_define
define|#
directive|define
name|SPRITE_FORMAT_XR_BGR101010
value|(5<<25)
end_define

begin_comment
comment|/* Extended range */
end_comment

begin_define
define|#
directive|define
name|SPRITE_CSC_ENABLE
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|SPRITE_SOURCE_KEY
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|SPRITE_RGB_ORDER_RGBX
value|(1<<20)
end_define

begin_comment
comment|/* only for 888 and 161616 */
end_comment

begin_define
define|#
directive|define
name|SPRITE_YUV_TO_RGB_CSC_DISABLE
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|SPRITE_YUV_CSC_FORMAT_BT709
value|(1<<18)
end_define

begin_comment
comment|/* 0 is BT601 */
end_comment

begin_define
define|#
directive|define
name|SPRITE_YUV_BYTE_ORDER_MASK
value|(3<<16)
end_define

begin_define
define|#
directive|define
name|SPRITE_YUV_ORDER_YUYV
value|(0<<16)
end_define

begin_define
define|#
directive|define
name|SPRITE_YUV_ORDER_UYVY
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|SPRITE_YUV_ORDER_YVYU
value|(2<<16)
end_define

begin_define
define|#
directive|define
name|SPRITE_YUV_ORDER_VYUY
value|(3<<16)
end_define

begin_define
define|#
directive|define
name|SPRITE_TRICKLE_FEED_DISABLE
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|SPRITE_INT_GAMMA_ENABLE
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|SPRITE_TILED
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|SPRITE_DEST_KEY
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|_SPRA_LINOFF
value|0x70284
end_define

begin_define
define|#
directive|define
name|_SPRA_STRIDE
value|0x70288
end_define

begin_define
define|#
directive|define
name|_SPRA_POS
value|0x7028c
end_define

begin_define
define|#
directive|define
name|_SPRA_SIZE
value|0x70290
end_define

begin_define
define|#
directive|define
name|_SPRA_KEYVAL
value|0x70294
end_define

begin_define
define|#
directive|define
name|_SPRA_KEYMSK
value|0x70298
end_define

begin_define
define|#
directive|define
name|_SPRA_SURF
value|0x7029c
end_define

begin_define
define|#
directive|define
name|_SPRA_KEYMAX
value|0x702a0
end_define

begin_define
define|#
directive|define
name|_SPRA_TILEOFF
value|0x702a4
end_define

begin_define
define|#
directive|define
name|_SPRA_SCALE
value|0x70304
end_define

begin_define
define|#
directive|define
name|SPRITE_SCALE_ENABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|SPRITE_FILTER_MASK
value|(3<<29)
end_define

begin_define
define|#
directive|define
name|SPRITE_FILTER_MEDIUM
value|(0<<29)
end_define

begin_define
define|#
directive|define
name|SPRITE_FILTER_ENHANCING
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|SPRITE_FILTER_SOFTENING
value|(2<<29)
end_define

begin_define
define|#
directive|define
name|SPRITE_VERTICAL_OFFSET_HALF
value|(1<<28)
end_define

begin_comment
comment|/* must be enabled below */
end_comment

begin_define
define|#
directive|define
name|SPRITE_VERTICAL_OFFSET_ENABLE
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|_SPRA_GAMC
value|0x70400
end_define

begin_define
define|#
directive|define
name|_SPRB_CTL
value|0x71280
end_define

begin_define
define|#
directive|define
name|_SPRB_LINOFF
value|0x71284
end_define

begin_define
define|#
directive|define
name|_SPRB_STRIDE
value|0x71288
end_define

begin_define
define|#
directive|define
name|_SPRB_POS
value|0x7128c
end_define

begin_define
define|#
directive|define
name|_SPRB_SIZE
value|0x71290
end_define

begin_define
define|#
directive|define
name|_SPRB_KEYVAL
value|0x71294
end_define

begin_define
define|#
directive|define
name|_SPRB_KEYMSK
value|0x71298
end_define

begin_define
define|#
directive|define
name|_SPRB_SURF
value|0x7129c
end_define

begin_define
define|#
directive|define
name|_SPRB_KEYMAX
value|0x712a0
end_define

begin_define
define|#
directive|define
name|_SPRB_TILEOFF
value|0x712a4
end_define

begin_define
define|#
directive|define
name|_SPRB_SCALE
value|0x71304
end_define

begin_define
define|#
directive|define
name|_SPRB_GAMC
value|0x71400
end_define

begin_define
define|#
directive|define
name|SPRCTL
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _SPRA_CTL, _SPRB_CTL)
end_define

begin_define
define|#
directive|define
name|SPRLINOFF
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _SPRA_LINOFF, _SPRB_LINOFF)
end_define

begin_define
define|#
directive|define
name|SPRSTRIDE
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _SPRA_STRIDE, _SPRB_STRIDE)
end_define

begin_define
define|#
directive|define
name|SPRPOS
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _SPRA_POS, _SPRB_POS)
end_define

begin_define
define|#
directive|define
name|SPRSIZE
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _SPRA_SIZE, _SPRB_SIZE)
end_define

begin_define
define|#
directive|define
name|SPRKEYVAL
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _SPRA_KEYVAL, _SPRB_KEYVAL)
end_define

begin_define
define|#
directive|define
name|SPRKEYMSK
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _SPRA_KEYMSK, _SPRB_KEYMSK)
end_define

begin_define
define|#
directive|define
name|SPRSURF
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _SPRA_SURF, _SPRB_SURF)
end_define

begin_define
define|#
directive|define
name|SPRKEYMAX
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _SPRA_KEYMAX, _SPRB_KEYMAX)
end_define

begin_define
define|#
directive|define
name|SPRTILEOFF
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _SPRA_TILEOFF, _SPRB_TILEOFF)
end_define

begin_define
define|#
directive|define
name|SPRSCALE
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _SPRA_SCALE, _SPRB_SCALE)
end_define

begin_define
define|#
directive|define
name|SPRGAMC
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _SPRA_GAMC, _SPRB_GAMC)
end_define

begin_comment
comment|/* VBIOS regs */
end_comment

begin_define
define|#
directive|define
name|VGACNTRL
value|0x71400
end_define

begin_define
define|#
directive|define
name|VGA_DISP_DISABLE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|VGA_2X_MODE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|VGA_PIPE_B_SELECT
value|(1<< 29)
end_define

begin_comment
comment|/* Ironlake */
end_comment

begin_define
define|#
directive|define
name|CPU_VGACNTRL
value|0x41000
end_define

begin_define
define|#
directive|define
name|DIGITAL_PORT_HOTPLUG_CNTRL
value|0x44030
end_define

begin_define
define|#
directive|define
name|DIGITAL_PORTA_HOTPLUG_ENABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DIGITAL_PORTA_SHORT_PULSE_2MS
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|DIGITAL_PORTA_SHORT_PULSE_4_5MS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DIGITAL_PORTA_SHORT_PULSE_6MS
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|DIGITAL_PORTA_SHORT_PULSE_100MS
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|DIGITAL_PORTA_NO_DETECT
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|DIGITAL_PORTA_LONG_PULSE_DETECT_MASK
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DIGITAL_PORTA_SHORT_PULSE_DETECT_MASK
value|(1<< 0)
end_define

begin_comment
comment|/* refresh rate hardware control */
end_comment

begin_define
define|#
directive|define
name|RR_HW_CTL
value|0x45300
end_define

begin_define
define|#
directive|define
name|RR_HW_LOW_POWER_FRAMES_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|RR_HW_HIGH_POWER_FRAMES_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|FDI_PLL_BIOS_0
value|0x46000
end_define

begin_define
define|#
directive|define
name|FDI_PLL_FB_CLOCK_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|FDI_PLL_BIOS_1
value|0x46004
end_define

begin_define
define|#
directive|define
name|FDI_PLL_BIOS_2
value|0x46008
end_define

begin_define
define|#
directive|define
name|DISPLAY_PORT_PLL_BIOS_0
value|0x4600c
end_define

begin_define
define|#
directive|define
name|DISPLAY_PORT_PLL_BIOS_1
value|0x46010
end_define

begin_define
define|#
directive|define
name|DISPLAY_PORT_PLL_BIOS_2
value|0x46014
end_define

begin_define
define|#
directive|define
name|PCH_DSPCLK_GATE_D
value|0x42020
end_define

begin_define
define|#
directive|define
name|DPFCUNIT_CLOCK_GATE_DISABLE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|DPFCRUNIT_CLOCK_GATE_DISABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|DPFDUNIT_CLOCK_GATE_DISABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|DPARBUNIT_CLOCK_GATE_DISABLE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PCH_3DCGDIS0
value|0x46020
end_define

begin_define
define|#
directive|define
name|MARIUNIT_CLOCK_GATE_DISABLE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|SVSMUNIT_CLOCK_GATE_DISABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|PCH_3DCGDIS1
value|0x46024
end_define

begin_define
define|#
directive|define
name|VFMUNIT_CLOCK_GATE_DISABLE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|FDI_PLL_FREQ_CTL
value|0x46030
end_define

begin_define
define|#
directive|define
name|FDI_PLL_FREQ_CHANGE_REQUEST
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|FDI_PLL_FREQ_LOCK_LIMIT_MASK
value|0xfff00
end_define

begin_define
define|#
directive|define
name|FDI_PLL_FREQ_DISABLE_COUNT_LIMIT_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|_PIPEA_DATA_M1
value|0x60030
end_define

begin_define
define|#
directive|define
name|TU_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)-1)<< 25)
end_define

begin_comment
comment|/* default size 64 */
end_comment

begin_define
define|#
directive|define
name|TU_SIZE_MASK
value|0x7e000000
end_define

begin_define
define|#
directive|define
name|PIPE_DATA_M1_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|_PIPEA_DATA_N1
value|0x60034
end_define

begin_define
define|#
directive|define
name|PIPE_DATA_N1_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|_PIPEA_DATA_M2
value|0x60038
end_define

begin_define
define|#
directive|define
name|PIPE_DATA_M2_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|_PIPEA_DATA_N2
value|0x6003c
end_define

begin_define
define|#
directive|define
name|PIPE_DATA_N2_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|_PIPEA_LINK_M1
value|0x60040
end_define

begin_define
define|#
directive|define
name|PIPE_LINK_M1_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|_PIPEA_LINK_N1
value|0x60044
end_define

begin_define
define|#
directive|define
name|PIPE_LINK_N1_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|_PIPEA_LINK_M2
value|0x60048
end_define

begin_define
define|#
directive|define
name|PIPE_LINK_M2_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|_PIPEA_LINK_N2
value|0x6004c
end_define

begin_define
define|#
directive|define
name|PIPE_LINK_N2_OFFSET
value|0
end_define

begin_comment
comment|/* PIPEB timing regs are same start from 0x61000 */
end_comment

begin_define
define|#
directive|define
name|_PIPEB_DATA_M1
value|0x61030
end_define

begin_define
define|#
directive|define
name|_PIPEB_DATA_N1
value|0x61034
end_define

begin_define
define|#
directive|define
name|_PIPEB_DATA_M2
value|0x61038
end_define

begin_define
define|#
directive|define
name|_PIPEB_DATA_N2
value|0x6103c
end_define

begin_define
define|#
directive|define
name|_PIPEB_LINK_M1
value|0x61040
end_define

begin_define
define|#
directive|define
name|_PIPEB_LINK_N1
value|0x61044
end_define

begin_define
define|#
directive|define
name|_PIPEB_LINK_M2
value|0x61048
end_define

begin_define
define|#
directive|define
name|_PIPEB_LINK_N2
value|0x6104c
end_define

begin_define
define|#
directive|define
name|PIPE_DATA_M1
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEA_DATA_M1, _PIPEB_DATA_M1)
end_define

begin_define
define|#
directive|define
name|PIPE_DATA_N1
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEA_DATA_N1, _PIPEB_DATA_N1)
end_define

begin_define
define|#
directive|define
name|PIPE_DATA_M2
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEA_DATA_M2, _PIPEB_DATA_M2)
end_define

begin_define
define|#
directive|define
name|PIPE_DATA_N2
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEA_DATA_N2, _PIPEB_DATA_N2)
end_define

begin_define
define|#
directive|define
name|PIPE_LINK_M1
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEA_LINK_M1, _PIPEB_LINK_M1)
end_define

begin_define
define|#
directive|define
name|PIPE_LINK_N1
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEA_LINK_N1, _PIPEB_LINK_N1)
end_define

begin_define
define|#
directive|define
name|PIPE_LINK_M2
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEA_LINK_M2, _PIPEB_LINK_M2)
end_define

begin_define
define|#
directive|define
name|PIPE_LINK_N2
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PIPEA_LINK_N2, _PIPEB_LINK_N2)
end_define

begin_comment
comment|/* CPU panel fitter */
end_comment

begin_comment
comment|/* IVB+ has 3 fitters, 0 is 7x5 capable, the other two only 3x3 */
end_comment

begin_define
define|#
directive|define
name|_PFA_CTL_1
value|0x68080
end_define

begin_define
define|#
directive|define
name|_PFB_CTL_1
value|0x68880
end_define

begin_define
define|#
directive|define
name|PF_ENABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|PF_FILTER_MASK
value|(3<<23)
end_define

begin_define
define|#
directive|define
name|PF_FILTER_PROGRAMMED
value|(0<<23)
end_define

begin_define
define|#
directive|define
name|PF_FILTER_MED_3x3
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|PF_FILTER_EDGE_ENHANCE
value|(2<<23)
end_define

begin_define
define|#
directive|define
name|PF_FILTER_EDGE_SOFTEN
value|(3<<23)
end_define

begin_define
define|#
directive|define
name|_PFA_WIN_SZ
value|0x68074
end_define

begin_define
define|#
directive|define
name|_PFB_WIN_SZ
value|0x68874
end_define

begin_define
define|#
directive|define
name|_PFA_WIN_POS
value|0x68070
end_define

begin_define
define|#
directive|define
name|_PFB_WIN_POS
value|0x68870
end_define

begin_define
define|#
directive|define
name|_PFA_VSCALE
value|0x68084
end_define

begin_define
define|#
directive|define
name|_PFB_VSCALE
value|0x68884
end_define

begin_define
define|#
directive|define
name|_PFA_HSCALE
value|0x68090
end_define

begin_define
define|#
directive|define
name|_PFB_HSCALE
value|0x68890
end_define

begin_define
define|#
directive|define
name|PF_CTL
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PFA_CTL_1, _PFB_CTL_1)
end_define

begin_define
define|#
directive|define
name|PF_WIN_SZ
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PFA_WIN_SZ, _PFB_WIN_SZ)
end_define

begin_define
define|#
directive|define
name|PF_WIN_POS
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PFA_WIN_POS, _PFB_WIN_POS)
end_define

begin_define
define|#
directive|define
name|PF_VSCALE
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PFA_VSCALE, _PFB_VSCALE)
end_define

begin_define
define|#
directive|define
name|PF_HSCALE
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _PFA_HSCALE, _PFB_HSCALE)
end_define

begin_comment
comment|/* legacy palette */
end_comment

begin_define
define|#
directive|define
name|_LGC_PALETTE_A
value|0x4a000
end_define

begin_define
define|#
directive|define
name|_LGC_PALETTE_B
value|0x4a800
end_define

begin_define
define|#
directive|define
name|LGC_PALETTE
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _LGC_PALETTE_A, _LGC_PALETTE_B)
end_define

begin_comment
comment|/* interrupts */
end_comment

begin_define
define|#
directive|define
name|DE_MASTER_IRQ_CONTROL
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|DE_SPRITEB_FLIP_DONE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|DE_SPRITEA_FLIP_DONE
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|DE_PLANEB_FLIP_DONE
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|DE_PLANEA_FLIP_DONE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|DE_PCU_EVENT
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|DE_GTT_FAULT
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|DE_POISON
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|DE_PERFORM_COUNTER
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|DE_PCH_EVENT
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|DE_AUX_CHANNEL_A
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|DE_DP_A_HOTPLUG
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|DE_GSE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|DE_PIPEB_VBLANK
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|DE_PIPEB_EVEN_FIELD
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|DE_PIPEB_ODD_FIELD
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|DE_PIPEB_LINE_COMPARE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|DE_PIPEB_VSYNC
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|DE_PIPEB_FIFO_UNDERRUN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|DE_PIPEA_VBLANK
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|DE_PIPEA_EVEN_FIELD
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DE_PIPEA_ODD_FIELD
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|DE_PIPEA_LINE_COMPARE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DE_PIPEA_VSYNC
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DE_PIPEA_FIFO_UNDERRUN
value|(1<< 0)
end_define

begin_comment
comment|/* More Ivybridge lolz */
end_comment

begin_define
define|#
directive|define
name|DE_ERR_DEBUG_IVB
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|DE_GSE_IVB
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|DE_PCH_EVENT_IVB
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|DE_DP_A_HOTPLUG_IVB
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|DE_AUX_CHANNEL_A_IVB
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|DE_SPRITEB_FLIP_DONE_IVB
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|DE_SPRITEA_FLIP_DONE_IVB
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|DE_PLANEB_FLIP_DONE_IVB
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|DE_PLANEA_FLIP_DONE_IVB
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|DE_PIPEB_VBLANK_IVB
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|DE_PIPEA_VBLANK_IVB
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DEISR
value|0x44000
end_define

begin_define
define|#
directive|define
name|DEIMR
value|0x44004
end_define

begin_define
define|#
directive|define
name|DEIIR
value|0x44008
end_define

begin_define
define|#
directive|define
name|DEIER
value|0x4400c
end_define

begin_comment
comment|/* GT interrupt */
end_comment

begin_define
define|#
directive|define
name|GT_PIPE_NOTIFY
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|GT_RENDER_CS_ERROR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|GT_SYNC_STATUS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|GT_USER_INTERRUPT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GT_BSD_USER_INTERRUPT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|GT_GEN6_BSD_USER_INTERRUPT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|GT_BLT_USER_INTERRUPT
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|GTISR
value|0x44010
end_define

begin_define
define|#
directive|define
name|GTIMR
value|0x44014
end_define

begin_define
define|#
directive|define
name|GTIIR
value|0x44018
end_define

begin_define
define|#
directive|define
name|GTIER
value|0x4401c
end_define

begin_define
define|#
directive|define
name|ILK_DISPLAY_CHICKEN2
value|0x42004
end_define

begin_comment
comment|/* Required on all Ironlake and Sandybridge according to the B-Spec. */
end_comment

begin_define
define|#
directive|define
name|ILK_ELPIN_409_SELECT
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|ILK_DPARB_GATE
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|ILK_VSDPFD_FULL
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|ILK_DISPLAY_CHICKEN_FUSES
value|0x42014
end_define

begin_define
define|#
directive|define
name|ILK_INTERNAL_GRAPHICS_DISABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|ILK_INTERNAL_DISPLAY_DISABLE
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|ILK_DISPLAY_DEBUG_DISABLE
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|ILK_HDCP_DISABLE
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|ILK_eDP_A_DISABLE
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|ILK_DESKTOP
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|ILK_DSPCLK_GATE
value|0x42020
end_define

begin_define
define|#
directive|define
name|IVB_VRHUNIT_CLK_GATE
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|ILK_DPARB_CLK_GATE
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|ILK_DPFD_CLK_GATE
value|(1<<7)
end_define

begin_comment
comment|/* According to spec this bit 7/8/9 of 0x42020 should be set to enable FBC */
end_comment

begin_define
define|#
directive|define
name|ILK_CLK_FBC
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|ILK_DPFC_DIS1
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|ILK_DPFC_DIS2
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|IVB_CHICKEN3
value|0x4200c
end_define

begin_define
define|#
directive|define
name|CHICKEN3_DGMG_REQ_OUT_FIX_DISABLE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|CHICKEN3_DGMG_DONE_FIX_DISABLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DISP_ARB_CTL
value|0x45000
end_define

begin_define
define|#
directive|define
name|DISP_TILE_SURFACE_SWIZZLING
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|DISP_FBC_WM_DIS
value|(1<<15)
end_define

begin_comment
comment|/* GEN7 chicken */
end_comment

begin_define
define|#
directive|define
name|GEN7_COMMON_SLICE_CHICKEN1
value|0x7010
end_define

begin_define
define|#
directive|define
name|GEN7_CSC1_RHWO_OPT_DISABLE_IN_RCC
value|((1<<10) | (1<<26))
end_define

begin_define
define|#
directive|define
name|GEN7_L3CNTLREG1
value|0xB01C
end_define

begin_define
define|#
directive|define
name|GEN7_WA_FOR_GEN7_L3_CONTROL
value|0x3C4FFF8C
end_define

begin_define
define|#
directive|define
name|GEN7_L3_CHICKEN_MODE_REGISTER
value|0xB030
end_define

begin_define
define|#
directive|define
name|GEN7_WA_L3_CHICKEN_MODE
value|0x20000000
end_define

begin_comment
comment|/* WaCatErrorRejectionIssue */
end_comment

begin_define
define|#
directive|define
name|GEN7_SQ_CHICKEN_MBCUNIT_CONFIG
value|0x9030
end_define

begin_define
define|#
directive|define
name|GEN7_SQ_CHICKEN_MBCUNIT_SQINTMOB
value|(1<<11)
end_define

begin_comment
comment|/* PCH */
end_comment

begin_comment
comment|/* south display engine interrupt */
end_comment

begin_define
define|#
directive|define
name|SDE_AUDIO_POWER_D
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|SDE_AUDIO_POWER_C
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|SDE_AUDIO_POWER_B
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|SDE_AUDIO_POWER_SHIFT
value|(25)
end_define

begin_define
define|#
directive|define
name|SDE_AUDIO_POWER_MASK
value|(7<< SDE_AUDIO_POWER_SHIFT)
end_define

begin_define
define|#
directive|define
name|SDE_GMBUS
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|SDE_AUDIO_HDCP_TRANSB
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|SDE_AUDIO_HDCP_TRANSA
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|SDE_AUDIO_HDCP_MASK
value|(3<< 22)
end_define

begin_define
define|#
directive|define
name|SDE_AUDIO_TRANSB
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|SDE_AUDIO_TRANSA
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|SDE_AUDIO_TRANS_MASK
value|(3<< 20)
end_define

begin_define
define|#
directive|define
name|SDE_POISON
value|(1<< 19)
end_define

begin_comment
comment|/* 18 reserved */
end_comment

begin_define
define|#
directive|define
name|SDE_FDI_RXB
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|SDE_FDI_RXA
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|SDE_FDI_MASK
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|SDE_AUXD
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|SDE_AUXC
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|SDE_AUXB
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|SDE_AUX_MASK
value|(7<< 13)
end_define

begin_comment
comment|/* 12 reserved */
end_comment

begin_define
define|#
directive|define
name|SDE_CRT_HOTPLUG
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|SDE_PORTD_HOTPLUG
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|SDE_PORTC_HOTPLUG
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SDE_PORTB_HOTPLUG
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SDE_SDVOB_HOTPLUG
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SDE_HOTPLUG_MASK
value|(0xf<< 8)
end_define

begin_define
define|#
directive|define
name|SDE_TRANSB_CRC_DONE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SDE_TRANSB_CRC_ERR
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SDE_TRANSB_FIFO_UNDER
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SDE_TRANSA_CRC_DONE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SDE_TRANSA_CRC_ERR
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SDE_TRANSA_FIFO_UNDER
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SDE_TRANS_MASK
value|(0x3f)
end_define

begin_comment
comment|/* CPT */
end_comment

begin_define
define|#
directive|define
name|SDE_CRT_HOTPLUG_CPT
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|SDE_PORTD_HOTPLUG_CPT
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|SDE_PORTC_HOTPLUG_CPT
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|SDE_PORTB_HOTPLUG_CPT
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|SDE_HOTPLUG_MASK_CPT
value|(SDE_CRT_HOTPLUG_CPT |		\ 				 SDE_PORTD_HOTPLUG_CPT |	\ 				 SDE_PORTC_HOTPLUG_CPT |	\ 				 SDE_PORTB_HOTPLUG_CPT)
end_define

begin_define
define|#
directive|define
name|SDEISR
value|0xc4000
end_define

begin_define
define|#
directive|define
name|SDEIMR
value|0xc4004
end_define

begin_define
define|#
directive|define
name|SDEIIR
value|0xc4008
end_define

begin_define
define|#
directive|define
name|SDEIER
value|0xc400c
end_define

begin_comment
comment|/* digital port hotplug */
end_comment

begin_define
define|#
directive|define
name|PCH_PORT_HOTPLUG
value|0xc4030
end_define

begin_comment
comment|/* SHOTPLUG_CTL */
end_comment

begin_define
define|#
directive|define
name|PORTD_HOTPLUG_ENABLE
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|PORTD_PULSE_DURATION_2ms
value|(0)
end_define

begin_define
define|#
directive|define
name|PORTD_PULSE_DURATION_4_5ms
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|PORTD_PULSE_DURATION_6ms
value|(2<< 18)
end_define

begin_define
define|#
directive|define
name|PORTD_PULSE_DURATION_100ms
value|(3<< 18)
end_define

begin_define
define|#
directive|define
name|PORTD_PULSE_DURATION_MASK
value|(3<< 18)
end_define

begin_define
define|#
directive|define
name|PORTD_HOTPLUG_NO_DETECT
value|(0)
end_define

begin_define
define|#
directive|define
name|PORTD_HOTPLUG_SHORT_DETECT
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|PORTD_HOTPLUG_LONG_DETECT
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|PORTC_HOTPLUG_ENABLE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|PORTC_PULSE_DURATION_2ms
value|(0)
end_define

begin_define
define|#
directive|define
name|PORTC_PULSE_DURATION_4_5ms
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|PORTC_PULSE_DURATION_6ms
value|(2<< 10)
end_define

begin_define
define|#
directive|define
name|PORTC_PULSE_DURATION_100ms
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|PORTC_PULSE_DURATION_MASK
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|PORTC_HOTPLUG_NO_DETECT
value|(0)
end_define

begin_define
define|#
directive|define
name|PORTC_HOTPLUG_SHORT_DETECT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|PORTC_HOTPLUG_LONG_DETECT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|PORTB_HOTPLUG_ENABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|PORTB_PULSE_DURATION_2ms
value|(0)
end_define

begin_define
define|#
directive|define
name|PORTB_PULSE_DURATION_4_5ms
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|PORTB_PULSE_DURATION_6ms
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|PORTB_PULSE_DURATION_100ms
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|PORTB_PULSE_DURATION_MASK
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|PORTB_HOTPLUG_NO_DETECT
value|(0)
end_define

begin_define
define|#
directive|define
name|PORTB_HOTPLUG_SHORT_DETECT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PORTB_HOTPLUG_LONG_DETECT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|PCH_GPIOA
value|0xc5010
end_define

begin_define
define|#
directive|define
name|PCH_GPIOB
value|0xc5014
end_define

begin_define
define|#
directive|define
name|PCH_GPIOC
value|0xc5018
end_define

begin_define
define|#
directive|define
name|PCH_GPIOD
value|0xc501c
end_define

begin_define
define|#
directive|define
name|PCH_GPIOE
value|0xc5020
end_define

begin_define
define|#
directive|define
name|PCH_GPIOF
value|0xc5024
end_define

begin_define
define|#
directive|define
name|PCH_GMBUS0
value|0xc5100
end_define

begin_define
define|#
directive|define
name|PCH_GMBUS1
value|0xc5104
end_define

begin_define
define|#
directive|define
name|PCH_GMBUS2
value|0xc5108
end_define

begin_define
define|#
directive|define
name|PCH_GMBUS3
value|0xc510c
end_define

begin_define
define|#
directive|define
name|PCH_GMBUS4
value|0xc5110
end_define

begin_define
define|#
directive|define
name|PCH_GMBUS5
value|0xc5120
end_define

begin_define
define|#
directive|define
name|_PCH_DPLL_A
value|0xc6014
end_define

begin_define
define|#
directive|define
name|_PCH_DPLL_B
value|0xc6018
end_define

begin_define
define|#
directive|define
name|PCH_DPLL
parameter_list|(
name|pipe
parameter_list|)
value|(pipe == 0 ?  _PCH_DPLL_A : _PCH_DPLL_B)
end_define

begin_define
define|#
directive|define
name|_PCH_FPA0
value|0xc6040
end_define

begin_define
define|#
directive|define
name|FP_CB_TUNE
value|(0x3<<22)
end_define

begin_define
define|#
directive|define
name|_PCH_FPA1
value|0xc6044
end_define

begin_define
define|#
directive|define
name|_PCH_FPB0
value|0xc6048
end_define

begin_define
define|#
directive|define
name|_PCH_FPB1
value|0xc604c
end_define

begin_define
define|#
directive|define
name|PCH_FP0
parameter_list|(
name|pipe
parameter_list|)
value|(pipe == 0 ? _PCH_FPA0 : _PCH_FPB0)
end_define

begin_define
define|#
directive|define
name|PCH_FP1
parameter_list|(
name|pipe
parameter_list|)
value|(pipe == 0 ? _PCH_FPA1 : _PCH_FPB1)
end_define

begin_define
define|#
directive|define
name|PCH_DPLL_TEST
value|0xc606c
end_define

begin_define
define|#
directive|define
name|PCH_DREF_CONTROL
value|0xC6200
end_define

begin_define
define|#
directive|define
name|DREF_CONTROL_MASK
value|0x7fc3
end_define

begin_define
define|#
directive|define
name|DREF_CPU_SOURCE_OUTPUT_DISABLE
value|(0<<13)
end_define

begin_define
define|#
directive|define
name|DREF_CPU_SOURCE_OUTPUT_DOWNSPREAD
value|(2<<13)
end_define

begin_define
define|#
directive|define
name|DREF_CPU_SOURCE_OUTPUT_NONSPREAD
value|(3<<13)
end_define

begin_define
define|#
directive|define
name|DREF_CPU_SOURCE_OUTPUT_MASK
value|(3<<13)
end_define

begin_define
define|#
directive|define
name|DREF_SSC_SOURCE_DISABLE
value|(0<<11)
end_define

begin_define
define|#
directive|define
name|DREF_SSC_SOURCE_ENABLE
value|(2<<11)
end_define

begin_define
define|#
directive|define
name|DREF_SSC_SOURCE_MASK
value|(3<<11)
end_define

begin_define
define|#
directive|define
name|DREF_NONSPREAD_SOURCE_DISABLE
value|(0<<9)
end_define

begin_define
define|#
directive|define
name|DREF_NONSPREAD_CK505_ENABLE
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|DREF_NONSPREAD_SOURCE_ENABLE
value|(2<<9)
end_define

begin_define
define|#
directive|define
name|DREF_NONSPREAD_SOURCE_MASK
value|(3<<9)
end_define

begin_define
define|#
directive|define
name|DREF_SUPERSPREAD_SOURCE_DISABLE
value|(0<<7)
end_define

begin_define
define|#
directive|define
name|DREF_SUPERSPREAD_SOURCE_ENABLE
value|(2<<7)
end_define

begin_define
define|#
directive|define
name|DREF_SUPERSPREAD_SOURCE_MASK
value|(3<<7)
end_define

begin_define
define|#
directive|define
name|DREF_SSC4_DOWNSPREAD
value|(0<<6)
end_define

begin_define
define|#
directive|define
name|DREF_SSC4_CENTERSPREAD
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|DREF_SSC1_DISABLE
value|(0<<1)
end_define

begin_define
define|#
directive|define
name|DREF_SSC1_ENABLE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|DREF_SSC4_DISABLE
value|(0)
end_define

begin_define
define|#
directive|define
name|DREF_SSC4_ENABLE
value|(1)
end_define

begin_define
define|#
directive|define
name|PCH_RAWCLK_FREQ
value|0xc6204
end_define

begin_define
define|#
directive|define
name|FDL_TP1_TIMER_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|FDL_TP1_TIMER_MASK
value|(3<<12)
end_define

begin_define
define|#
directive|define
name|FDL_TP2_TIMER_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|FDL_TP2_TIMER_MASK
value|(3<<10)
end_define

begin_define
define|#
directive|define
name|RAWCLK_FREQ_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|PCH_DPLL_TMR_CFG
value|0xc6208
end_define

begin_define
define|#
directive|define
name|PCH_SSC4_PARMS
value|0xc6210
end_define

begin_define
define|#
directive|define
name|PCH_SSC4_AUX_PARMS
value|0xc6214
end_define

begin_define
define|#
directive|define
name|PCH_DPLL_SEL
value|0xc7000
end_define

begin_define
define|#
directive|define
name|TRANSA_DPLL_ENABLE
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|TRANSA_DPLLB_SEL
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|TRANSA_DPLLA_SEL
value|0
end_define

begin_define
define|#
directive|define
name|TRANSB_DPLL_ENABLE
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|TRANSB_DPLLB_SEL
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|TRANSB_DPLLA_SEL
value|(0)
end_define

begin_define
define|#
directive|define
name|TRANSC_DPLL_ENABLE
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|TRANSC_DPLLB_SEL
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|TRANSC_DPLLA_SEL
value|(0)
end_define

begin_comment
comment|/* transcoder */
end_comment

begin_define
define|#
directive|define
name|_TRANS_HTOTAL_A
value|0xe0000
end_define

begin_define
define|#
directive|define
name|TRANS_HTOTAL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TRANS_HACTIVE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|_TRANS_HBLANK_A
value|0xe0004
end_define

begin_define
define|#
directive|define
name|TRANS_HBLANK_END_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TRANS_HBLANK_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|_TRANS_HSYNC_A
value|0xe0008
end_define

begin_define
define|#
directive|define
name|TRANS_HSYNC_END_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TRANS_HSYNC_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|_TRANS_VTOTAL_A
value|0xe000c
end_define

begin_define
define|#
directive|define
name|TRANS_VTOTAL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TRANS_VACTIVE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|_TRANS_VBLANK_A
value|0xe0010
end_define

begin_define
define|#
directive|define
name|TRANS_VBLANK_END_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TRANS_VBLANK_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|_TRANS_VSYNC_A
value|0xe0014
end_define

begin_define
define|#
directive|define
name|TRANS_VSYNC_END_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TRANS_VSYNC_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|_TRANS_VSYNCSHIFT_A
value|0xe0028
end_define

begin_define
define|#
directive|define
name|_TRANSA_DATA_M1
value|0xe0030
end_define

begin_define
define|#
directive|define
name|_TRANSA_DATA_N1
value|0xe0034
end_define

begin_define
define|#
directive|define
name|_TRANSA_DATA_M2
value|0xe0038
end_define

begin_define
define|#
directive|define
name|_TRANSA_DATA_N2
value|0xe003c
end_define

begin_define
define|#
directive|define
name|_TRANSA_DP_LINK_M1
value|0xe0040
end_define

begin_define
define|#
directive|define
name|_TRANSA_DP_LINK_N1
value|0xe0044
end_define

begin_define
define|#
directive|define
name|_TRANSA_DP_LINK_M2
value|0xe0048
end_define

begin_define
define|#
directive|define
name|_TRANSA_DP_LINK_N2
value|0xe004c
end_define

begin_comment
comment|/* Per-transcoder DIP controls */
end_comment

begin_define
define|#
directive|define
name|_VIDEO_DIP_CTL_A
value|0xe0200
end_define

begin_define
define|#
directive|define
name|_VIDEO_DIP_DATA_A
value|0xe0208
end_define

begin_define
define|#
directive|define
name|_VIDEO_DIP_GCP_A
value|0xe0210
end_define

begin_define
define|#
directive|define
name|_VIDEO_DIP_CTL_B
value|0xe1200
end_define

begin_define
define|#
directive|define
name|_VIDEO_DIP_DATA_B
value|0xe1208
end_define

begin_define
define|#
directive|define
name|_VIDEO_DIP_GCP_B
value|0xe1210
end_define

begin_define
define|#
directive|define
name|TVIDEO_DIP_CTL
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _VIDEO_DIP_CTL_A, _VIDEO_DIP_CTL_B)
end_define

begin_define
define|#
directive|define
name|TVIDEO_DIP_DATA
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _VIDEO_DIP_DATA_A, _VIDEO_DIP_DATA_B)
end_define

begin_define
define|#
directive|define
name|TVIDEO_DIP_GCP
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _VIDEO_DIP_GCP_A, _VIDEO_DIP_GCP_B)
end_define

begin_define
define|#
directive|define
name|_TRANS_HTOTAL_B
value|0xe1000
end_define

begin_define
define|#
directive|define
name|_TRANS_HBLANK_B
value|0xe1004
end_define

begin_define
define|#
directive|define
name|_TRANS_HSYNC_B
value|0xe1008
end_define

begin_define
define|#
directive|define
name|_TRANS_VTOTAL_B
value|0xe100c
end_define

begin_define
define|#
directive|define
name|_TRANS_VBLANK_B
value|0xe1010
end_define

begin_define
define|#
directive|define
name|_TRANS_VSYNC_B
value|0xe1014
end_define

begin_define
define|#
directive|define
name|_TRANS_VSYNCSHIFT_B
value|0xe1028
end_define

begin_define
define|#
directive|define
name|TRANS_HTOTAL
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _TRANS_HTOTAL_A, _TRANS_HTOTAL_B)
end_define

begin_define
define|#
directive|define
name|TRANS_HBLANK
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _TRANS_HBLANK_A, _TRANS_HBLANK_B)
end_define

begin_define
define|#
directive|define
name|TRANS_HSYNC
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _TRANS_HSYNC_A, _TRANS_HSYNC_B)
end_define

begin_define
define|#
directive|define
name|TRANS_VTOTAL
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _TRANS_VTOTAL_A, _TRANS_VTOTAL_B)
end_define

begin_define
define|#
directive|define
name|TRANS_VBLANK
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _TRANS_VBLANK_A, _TRANS_VBLANK_B)
end_define

begin_define
define|#
directive|define
name|TRANS_VSYNC
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _TRANS_VSYNC_A, _TRANS_VSYNC_B)
end_define

begin_define
define|#
directive|define
name|TRANS_VSYNCSHIFT
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _TRANS_VSYNCSHIFT_A, \ 				     _TRANS_VSYNCSHIFT_B)
end_define

begin_define
define|#
directive|define
name|_TRANSB_DATA_M1
value|0xe1030
end_define

begin_define
define|#
directive|define
name|_TRANSB_DATA_N1
value|0xe1034
end_define

begin_define
define|#
directive|define
name|_TRANSB_DATA_M2
value|0xe1038
end_define

begin_define
define|#
directive|define
name|_TRANSB_DATA_N2
value|0xe103c
end_define

begin_define
define|#
directive|define
name|_TRANSB_DP_LINK_M1
value|0xe1040
end_define

begin_define
define|#
directive|define
name|_TRANSB_DP_LINK_N1
value|0xe1044
end_define

begin_define
define|#
directive|define
name|_TRANSB_DP_LINK_M2
value|0xe1048
end_define

begin_define
define|#
directive|define
name|_TRANSB_DP_LINK_N2
value|0xe104c
end_define

begin_define
define|#
directive|define
name|TRANSDATA_M1
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _TRANSA_DATA_M1, _TRANSB_DATA_M1)
end_define

begin_define
define|#
directive|define
name|TRANSDATA_N1
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _TRANSA_DATA_N1, _TRANSB_DATA_N1)
end_define

begin_define
define|#
directive|define
name|TRANSDATA_M2
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _TRANSA_DATA_M2, _TRANSB_DATA_M2)
end_define

begin_define
define|#
directive|define
name|TRANSDATA_N2
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _TRANSA_DATA_N2, _TRANSB_DATA_N2)
end_define

begin_define
define|#
directive|define
name|TRANSDPLINK_M1
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _TRANSA_DP_LINK_M1, _TRANSB_DP_LINK_M1)
end_define

begin_define
define|#
directive|define
name|TRANSDPLINK_N1
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _TRANSA_DP_LINK_N1, _TRANSB_DP_LINK_N1)
end_define

begin_define
define|#
directive|define
name|TRANSDPLINK_M2
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _TRANSA_DP_LINK_M2, _TRANSB_DP_LINK_M2)
end_define

begin_define
define|#
directive|define
name|TRANSDPLINK_N2
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _TRANSA_DP_LINK_N2, _TRANSB_DP_LINK_N2)
end_define

begin_define
define|#
directive|define
name|_TRANSACONF
value|0xf0008
end_define

begin_define
define|#
directive|define
name|_TRANSBCONF
value|0xf1008
end_define

begin_define
define|#
directive|define
name|TRANSCONF
parameter_list|(
name|plane
parameter_list|)
value|_PIPE(plane, _TRANSACONF, _TRANSBCONF)
end_define

begin_define
define|#
directive|define
name|TRANS_DISABLE
value|(0<<31)
end_define

begin_define
define|#
directive|define
name|TRANS_ENABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|TRANS_STATE_MASK
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|TRANS_STATE_DISABLE
value|(0<<30)
end_define

begin_define
define|#
directive|define
name|TRANS_STATE_ENABLE
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|TRANS_FSYNC_DELAY_HB1
value|(0<<27)
end_define

begin_define
define|#
directive|define
name|TRANS_FSYNC_DELAY_HB2
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|TRANS_FSYNC_DELAY_HB3
value|(2<<27)
end_define

begin_define
define|#
directive|define
name|TRANS_FSYNC_DELAY_HB4
value|(3<<27)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_AUDIO_ONLY
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_VIDEO_AUDIO
value|(0<<26)
end_define

begin_define
define|#
directive|define
name|TRANS_INTERLACE_MASK
value|(7<<21)
end_define

begin_define
define|#
directive|define
name|TRANS_PROGRESSIVE
value|(0<<21)
end_define

begin_define
define|#
directive|define
name|TRANS_INTERLACED
value|(3<<21)
end_define

begin_define
define|#
directive|define
name|TRANS_LEGACY_INTERLACED_ILK
value|(2<<21)
end_define

begin_define
define|#
directive|define
name|TRANS_8BPC
value|(0<<5)
end_define

begin_define
define|#
directive|define
name|TRANS_10BPC
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|TRANS_6BPC
value|(2<<5)
end_define

begin_define
define|#
directive|define
name|TRANS_12BPC
value|(3<<5)
end_define

begin_define
define|#
directive|define
name|_TRANSA_CHICKEN2
value|0xf0064
end_define

begin_define
define|#
directive|define
name|_TRANSB_CHICKEN2
value|0xf1064
end_define

begin_define
define|#
directive|define
name|TRANS_CHICKEN2
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _TRANSA_CHICKEN2, _TRANSB_CHICKEN2)
end_define

begin_define
define|#
directive|define
name|TRANS_AUTOTRAIN_GEN_STALL_DIS
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|SOUTH_CHICKEN1
value|0xc2000
end_define

begin_define
define|#
directive|define
name|FDIA_PHASE_SYNC_SHIFT_OVR
value|19
end_define

begin_define
define|#
directive|define
name|FDIA_PHASE_SYNC_SHIFT_EN
value|18
end_define

begin_define
define|#
directive|define
name|FDI_PHASE_SYNC_OVR
parameter_list|(
name|pipe
parameter_list|)
value|(1<<(FDIA_PHASE_SYNC_SHIFT_OVR - ((pipe) * 2)))
end_define

begin_define
define|#
directive|define
name|FDI_PHASE_SYNC_EN
parameter_list|(
name|pipe
parameter_list|)
value|(1<<(FDIA_PHASE_SYNC_SHIFT_EN - ((pipe) * 2)))
end_define

begin_define
define|#
directive|define
name|SOUTH_CHICKEN2
value|0xc2004
end_define

begin_define
define|#
directive|define
name|DPLS_EDP_PPS_FIX_DIS
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|_FDI_RXA_CHICKEN
value|0xc200c
end_define

begin_define
define|#
directive|define
name|_FDI_RXB_CHICKEN
value|0xc2010
end_define

begin_define
define|#
directive|define
name|FDI_RX_PHASE_SYNC_POINTER_OVR
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|FDI_RX_PHASE_SYNC_POINTER_EN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|FDI_RX_CHICKEN
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _FDI_RXA_CHICKEN, _FDI_RXB_CHICKEN)
end_define

begin_define
define|#
directive|define
name|SOUTH_DSPCLK_GATE_D
value|0xc2020
end_define

begin_define
define|#
directive|define
name|PCH_DPLSUNIT_CLOCK_GATE_DISABLE
value|(1<<29)
end_define

begin_comment
comment|/* CPU: FDI_TX */
end_comment

begin_define
define|#
directive|define
name|_FDI_TXA_CTL
value|0x60100
end_define

begin_define
define|#
directive|define
name|_FDI_TXB_CTL
value|0x61100
end_define

begin_define
define|#
directive|define
name|FDI_TX_CTL
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _FDI_TXA_CTL, _FDI_TXB_CTL)
end_define

begin_define
define|#
directive|define
name|FDI_TX_DISABLE
value|(0<<31)
end_define

begin_define
define|#
directive|define
name|FDI_TX_ENABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_PATTERN_1
value|(0<<28)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_PATTERN_2
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_PATTERN_IDLE
value|(2<<28)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_NONE
value|(3<<28)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_VOLTAGE_0_4V
value|(0<<25)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_VOLTAGE_0_6V
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_VOLTAGE_0_8V
value|(2<<25)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_VOLTAGE_1_2V
value|(3<<25)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_PRE_EMPHASIS_NONE
value|(0<<22)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_PRE_EMPHASIS_1_5X
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_PRE_EMPHASIS_2X
value|(2<<22)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_PRE_EMPHASIS_3X
value|(3<<22)
end_define

begin_comment
comment|/* ILK always use 400mV 0dB for voltage swing and pre-emphasis level.    SNB has different settings. */
end_comment

begin_comment
comment|/* SNB A-stepping */
end_comment

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_400MV_0DB_SNB_A
value|(0x38<<22)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_400MV_6DB_SNB_A
value|(0x02<<22)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_600MV_3_5DB_SNB_A
value|(0x01<<22)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_800MV_0DB_SNB_A
value|(0x0<<22)
end_define

begin_comment
comment|/* SNB B-stepping */
end_comment

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_400MV_0DB_SNB_B
value|(0x0<<22)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_400MV_6DB_SNB_B
value|(0x3a<<22)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_600MV_3_5DB_SNB_B
value|(0x39<<22)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_800MV_0DB_SNB_B
value|(0x38<<22)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_VOL_EMP_MASK
value|(0x3f<<22)
end_define

begin_define
define|#
directive|define
name|FDI_DP_PORT_WIDTH_X1
value|(0<<19)
end_define

begin_define
define|#
directive|define
name|FDI_DP_PORT_WIDTH_X2
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|FDI_DP_PORT_WIDTH_X3
value|(2<<19)
end_define

begin_define
define|#
directive|define
name|FDI_DP_PORT_WIDTH_X4
value|(3<<19)
end_define

begin_define
define|#
directive|define
name|FDI_TX_ENHANCE_FRAME_ENABLE
value|(1<<18)
end_define

begin_comment
comment|/* Ironlake: hardwired to 1 */
end_comment

begin_define
define|#
directive|define
name|FDI_TX_PLL_ENABLE
value|(1<<14)
end_define

begin_comment
comment|/* Ivybridge has different bits for lolz */
end_comment

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_PATTERN_1_IVB
value|(0<<8)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_PATTERN_2_IVB
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_PATTERN_IDLE_IVB
value|(2<<8)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_NONE_IVB
value|(3<<8)
end_define

begin_comment
comment|/* both Tx and Rx */
end_comment

begin_define
define|#
directive|define
name|FDI_COMPOSITE_SYNC
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_AUTO
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|FDI_SCRAMBLING_ENABLE
value|(0<<7)
end_define

begin_define
define|#
directive|define
name|FDI_SCRAMBLING_DISABLE
value|(1<<7)
end_define

begin_comment
comment|/* FDI_RX, FDI_X is hard-wired to Transcoder_X */
end_comment

begin_define
define|#
directive|define
name|_FDI_RXA_CTL
value|0xf000c
end_define

begin_define
define|#
directive|define
name|_FDI_RXB_CTL
value|0xf100c
end_define

begin_define
define|#
directive|define
name|FDI_RX_CTL
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _FDI_RXA_CTL, _FDI_RXB_CTL)
end_define

begin_define
define|#
directive|define
name|FDI_RX_ENABLE
value|(1<<31)
end_define

begin_comment
comment|/* train, dp width same as FDI_TX */
end_comment

begin_define
define|#
directive|define
name|FDI_FS_ERRC_ENABLE
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|FDI_FE_ERRC_ENABLE
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|FDI_DP_PORT_WIDTH_X8
value|(7<<19)
end_define

begin_define
define|#
directive|define
name|FDI_8BPC
value|(0<<16)
end_define

begin_define
define|#
directive|define
name|FDI_10BPC
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|FDI_6BPC
value|(2<<16)
end_define

begin_define
define|#
directive|define
name|FDI_12BPC
value|(3<<16)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_REVERSE_OVERWRITE
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|FDI_DMI_LINK_REVERSE_MASK
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|FDI_RX_PLL_ENABLE
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|FDI_FS_ERR_CORRECT_ENABLE
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|FDI_FE_ERR_CORRECT_ENABLE
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|FDI_FS_ERR_REPORT_ENABLE
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|FDI_FE_ERR_REPORT_ENABLE
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|FDI_RX_ENHANCE_FRAME_ENABLE
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|FDI_PCDCLK
value|(1<<4)
end_define

begin_comment
comment|/* CPT */
end_comment

begin_define
define|#
directive|define
name|FDI_AUTO_TRAINING
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_PATTERN_1_CPT
value|(0<<8)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_PATTERN_2_CPT
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_PATTERN_IDLE_CPT
value|(2<<8)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_NORMAL_CPT
value|(3<<8)
end_define

begin_define
define|#
directive|define
name|FDI_LINK_TRAIN_PATTERN_MASK_CPT
value|(3<<8)
end_define

begin_define
define|#
directive|define
name|_FDI_RXA_MISC
value|0xf0010
end_define

begin_define
define|#
directive|define
name|_FDI_RXB_MISC
value|0xf1010
end_define

begin_define
define|#
directive|define
name|_FDI_RXA_TUSIZE1
value|0xf0030
end_define

begin_define
define|#
directive|define
name|_FDI_RXA_TUSIZE2
value|0xf0038
end_define

begin_define
define|#
directive|define
name|_FDI_RXB_TUSIZE1
value|0xf1030
end_define

begin_define
define|#
directive|define
name|_FDI_RXB_TUSIZE2
value|0xf1038
end_define

begin_define
define|#
directive|define
name|FDI_RX_MISC
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _FDI_RXA_MISC, _FDI_RXB_MISC)
end_define

begin_define
define|#
directive|define
name|FDI_RX_TUSIZE1
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _FDI_RXA_TUSIZE1, _FDI_RXB_TUSIZE1)
end_define

begin_define
define|#
directive|define
name|FDI_RX_TUSIZE2
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _FDI_RXA_TUSIZE2, _FDI_RXB_TUSIZE2)
end_define

begin_comment
comment|/* FDI_RX interrupt register format */
end_comment

begin_define
define|#
directive|define
name|FDI_RX_INTER_LANE_ALIGN
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|FDI_RX_SYMBOL_LOCK
value|(1<<9)
end_define

begin_comment
comment|/* train 2 */
end_comment

begin_define
define|#
directive|define
name|FDI_RX_BIT_LOCK
value|(1<<8)
end_define

begin_comment
comment|/* train 1 */
end_comment

begin_define
define|#
directive|define
name|FDI_RX_TRAIN_PATTERN_2_FAIL
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|FDI_RX_FS_CODE_ERR
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|FDI_RX_FE_CODE_ERR
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|FDI_RX_SYMBOL_ERR_RATE_ABOVE
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|FDI_RX_HDCP_LINK_FAIL
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|FDI_RX_PIXEL_FIFO_OVERFLOW
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|FDI_RX_CROSS_CLOCK_OVERFLOW
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|FDI_RX_SYMBOL_QUEUE_OVERFLOW
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|_FDI_RXA_IIR
value|0xf0014
end_define

begin_define
define|#
directive|define
name|_FDI_RXA_IMR
value|0xf0018
end_define

begin_define
define|#
directive|define
name|_FDI_RXB_IIR
value|0xf1014
end_define

begin_define
define|#
directive|define
name|_FDI_RXB_IMR
value|0xf1018
end_define

begin_define
define|#
directive|define
name|FDI_RX_IIR
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _FDI_RXA_IIR, _FDI_RXB_IIR)
end_define

begin_define
define|#
directive|define
name|FDI_RX_IMR
parameter_list|(
name|pipe
parameter_list|)
value|_PIPE(pipe, _FDI_RXA_IMR, _FDI_RXB_IMR)
end_define

begin_define
define|#
directive|define
name|FDI_PLL_CTL_1
value|0xfe000
end_define

begin_define
define|#
directive|define
name|FDI_PLL_CTL_2
value|0xfe004
end_define

begin_comment
comment|/* CRT */
end_comment

begin_define
define|#
directive|define
name|PCH_ADPA
value|0xe1100
end_define

begin_define
define|#
directive|define
name|ADPA_TRANS_SELECT_MASK
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|ADPA_TRANS_A_SELECT
value|0
end_define

begin_define
define|#
directive|define
name|ADPA_TRANS_B_SELECT
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_MASK
value|0x03ff0000
end_define

begin_comment
comment|/* bit 25-16 */
end_comment

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_MONITOR_NONE
value|(0<<24)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_MONITOR_MASK
value|(3<<24)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_MONITOR_COLOR
value|(3<<24)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_MONITOR_MONO
value|(2<<24)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_ENABLE
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_PERIOD_64
value|(0<<22)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_PERIOD_128
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_WARMUP_5MS
value|(0<<21)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_WARMUP_10MS
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_SAMPLE_2S
value|(0<<20)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_SAMPLE_4S
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_VOLTAGE_40
value|(0<<18)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_VOLTAGE_50
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_VOLTAGE_60
value|(2<<18)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_VOLTAGE_70
value|(3<<18)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_VOLREF_325MV
value|(0<<17)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_VOLREF_475MV
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|ADPA_CRT_HOTPLUG_FORCE_TRIGGER
value|(1<<16)
end_define

begin_comment
comment|/* or SDVOB */
end_comment

begin_define
define|#
directive|define
name|HDMIB
value|0xe1140
end_define

begin_define
define|#
directive|define
name|PORT_ENABLE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|TRANSCODER
parameter_list|(
name|pipe
parameter_list|)
value|((pipe)<< 30)
end_define

begin_define
define|#
directive|define
name|TRANSCODER_CPT
parameter_list|(
name|pipe
parameter_list|)
value|((pipe)<< 29)
end_define

begin_define
define|#
directive|define
name|TRANSCODER_MASK
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|TRANSCODER_MASK_CPT
value|(3<< 29)
end_define

begin_define
define|#
directive|define
name|COLOR_FORMAT_8bpc
value|(0)
end_define

begin_define
define|#
directive|define
name|COLOR_FORMAT_12bpc
value|(3<< 26)
end_define

begin_define
define|#
directive|define
name|SDVOB_HOTPLUG_ENABLE
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|SDVO_ENCODING
value|(0)
end_define

begin_define
define|#
directive|define
name|TMDS_ENCODING
value|(2<< 10)
end_define

begin_define
define|#
directive|define
name|NULL_PACKET_VSYNC_ENABLE
value|(1<< 9)
end_define

begin_comment
comment|/* CPT */
end_comment

begin_define
define|#
directive|define
name|HDMI_MODE_SELECT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|DVI_MODE_SELECT
value|(0)
end_define

begin_define
define|#
directive|define
name|SDVOB_BORDER_ENABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AUDIO_ENABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|VSYNC_ACTIVE_HIGH
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|HSYNC_ACTIVE_HIGH
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|PORT_DETECTED
value|(1<< 2)
end_define

begin_comment
comment|/* PCH SDVOB multiplex with HDMIB */
end_comment

begin_define
define|#
directive|define
name|PCH_SDVOB
value|HDMIB
end_define

begin_define
define|#
directive|define
name|HDMIC
value|0xe1150
end_define

begin_define
define|#
directive|define
name|HDMID
value|0xe1160
end_define

begin_define
define|#
directive|define
name|PCH_LVDS
value|0xe1180
end_define

begin_define
define|#
directive|define
name|LVDS_DETECTED
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|BLC_PWM_CPU_CTL2
value|0x48250
end_define

begin_define
define|#
directive|define
name|PWM_ENABLE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|PWM_PIPE_A
value|(0<< 29)
end_define

begin_define
define|#
directive|define
name|PWM_PIPE_B
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|BLC_PWM_CPU_CTL
value|0x48254
end_define

begin_define
define|#
directive|define
name|BLC_PWM_PCH_CTL1
value|0xc8250
end_define

begin_define
define|#
directive|define
name|PWM_PCH_ENABLE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|PWM_POLARITY_ACTIVE_LOW
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|PWM_POLARITY_ACTIVE_HIGH
value|(0<< 29)
end_define

begin_define
define|#
directive|define
name|PWM_POLARITY_ACTIVE_LOW2
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|PWM_POLARITY_ACTIVE_HIGH2
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|BLC_PWM_PCH_CTL2
value|0xc8254
end_define

begin_define
define|#
directive|define
name|PCH_PP_STATUS
value|0xc7200
end_define

begin_define
define|#
directive|define
name|PCH_PP_CONTROL
value|0xc7204
end_define

begin_define
define|#
directive|define
name|PANEL_UNLOCK_REGS
value|(0xabcd<< 16)
end_define

begin_define
define|#
directive|define
name|PANEL_UNLOCK_MASK
value|(0xffff<< 16)
end_define

begin_define
define|#
directive|define
name|EDP_FORCE_VDD
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|EDP_BLC_ENABLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|PANEL_POWER_RESET
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|PANEL_POWER_OFF
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|PANEL_POWER_ON
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|PCH_PP_ON_DELAYS
value|0xc7208
end_define

begin_define
define|#
directive|define
name|PANEL_PORT_SELECT_MASK
value|(3<< 30)
end_define

begin_define
define|#
directive|define
name|PANEL_PORT_SELECT_LVDS
value|(0<< 30)
end_define

begin_define
define|#
directive|define
name|PANEL_PORT_SELECT_DPA
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|EDP_PANEL
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|PANEL_PORT_SELECT_DPC
value|(2U<< 30)
end_define

begin_define
define|#
directive|define
name|PANEL_PORT_SELECT_DPD
value|(3U<< 30)
end_define

begin_define
define|#
directive|define
name|PANEL_POWER_UP_DELAY_MASK
value|(0x1fff0000)
end_define

begin_define
define|#
directive|define
name|PANEL_POWER_UP_DELAY_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PANEL_LIGHT_ON_DELAY_MASK
value|(0x1fff)
end_define

begin_define
define|#
directive|define
name|PANEL_LIGHT_ON_DELAY_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PCH_PP_OFF_DELAYS
value|0xc720c
end_define

begin_define
define|#
directive|define
name|PANEL_POWER_DOWN_DELAY_MASK
value|(0x1fff0000)
end_define

begin_define
define|#
directive|define
name|PANEL_POWER_DOWN_DELAY_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PANEL_LIGHT_OFF_DELAY_MASK
value|(0x1fff)
end_define

begin_define
define|#
directive|define
name|PANEL_LIGHT_OFF_DELAY_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PCH_PP_DIVISOR
value|0xc7210
end_define

begin_define
define|#
directive|define
name|PP_REFERENCE_DIVIDER_MASK
value|(0xffffff00)
end_define

begin_define
define|#
directive|define
name|PP_REFERENCE_DIVIDER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PANEL_POWER_CYCLE_DELAY_MASK
value|(0x1f)
end_define

begin_define
define|#
directive|define
name|PANEL_POWER_CYCLE_DELAY_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PCH_DP_B
value|0xe4100
end_define

begin_define
define|#
directive|define
name|PCH_DPB_AUX_CH_CTL
value|0xe4110
end_define

begin_define
define|#
directive|define
name|PCH_DPB_AUX_CH_DATA1
value|0xe4114
end_define

begin_define
define|#
directive|define
name|PCH_DPB_AUX_CH_DATA2
value|0xe4118
end_define

begin_define
define|#
directive|define
name|PCH_DPB_AUX_CH_DATA3
value|0xe411c
end_define

begin_define
define|#
directive|define
name|PCH_DPB_AUX_CH_DATA4
value|0xe4120
end_define

begin_define
define|#
directive|define
name|PCH_DPB_AUX_CH_DATA5
value|0xe4124
end_define

begin_define
define|#
directive|define
name|PCH_DP_C
value|0xe4200
end_define

begin_define
define|#
directive|define
name|PCH_DPC_AUX_CH_CTL
value|0xe4210
end_define

begin_define
define|#
directive|define
name|PCH_DPC_AUX_CH_DATA1
value|0xe4214
end_define

begin_define
define|#
directive|define
name|PCH_DPC_AUX_CH_DATA2
value|0xe4218
end_define

begin_define
define|#
directive|define
name|PCH_DPC_AUX_CH_DATA3
value|0xe421c
end_define

begin_define
define|#
directive|define
name|PCH_DPC_AUX_CH_DATA4
value|0xe4220
end_define

begin_define
define|#
directive|define
name|PCH_DPC_AUX_CH_DATA5
value|0xe4224
end_define

begin_define
define|#
directive|define
name|PCH_DP_D
value|0xe4300
end_define

begin_define
define|#
directive|define
name|PCH_DPD_AUX_CH_CTL
value|0xe4310
end_define

begin_define
define|#
directive|define
name|PCH_DPD_AUX_CH_DATA1
value|0xe4314
end_define

begin_define
define|#
directive|define
name|PCH_DPD_AUX_CH_DATA2
value|0xe4318
end_define

begin_define
define|#
directive|define
name|PCH_DPD_AUX_CH_DATA3
value|0xe431c
end_define

begin_define
define|#
directive|define
name|PCH_DPD_AUX_CH_DATA4
value|0xe4320
end_define

begin_define
define|#
directive|define
name|PCH_DPD_AUX_CH_DATA5
value|0xe4324
end_define

begin_comment
comment|/* CPT */
end_comment

begin_define
define|#
directive|define
name|PORT_TRANS_A_SEL_CPT
value|0
end_define

begin_define
define|#
directive|define
name|PORT_TRANS_B_SEL_CPT
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|PORT_TRANS_C_SEL_CPT
value|(2<<29)
end_define

begin_define
define|#
directive|define
name|PORT_TRANS_SEL_MASK
value|(3<<29)
end_define

begin_define
define|#
directive|define
name|PORT_TRANS_SEL_CPT
parameter_list|(
name|pipe
parameter_list|)
value|((pipe)<< 29)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_CTL_A
value|0xe0300
end_define

begin_define
define|#
directive|define
name|TRANS_DP_CTL_B
value|0xe1300
end_define

begin_define
define|#
directive|define
name|TRANS_DP_CTL_C
value|0xe2300
end_define

begin_define
define|#
directive|define
name|TRANS_DP_CTL
parameter_list|(
name|pipe
parameter_list|)
value|(TRANS_DP_CTL_A + (pipe) * 0x01000)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_OUTPUT_ENABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_PORT_SEL_B
value|(0<<29)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_PORT_SEL_C
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_PORT_SEL_D
value|(2<<29)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_PORT_SEL_NONE
value|(3<<29)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_PORT_SEL_MASK
value|(3<<29)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_AUDIO_ONLY
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_ENH_FRAMING
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_8BPC
value|(0<<9)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_10BPC
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_6BPC
value|(2<<9)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_12BPC
value|(3<<9)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_BPC_MASK
value|(3<<9)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_VSYNC_ACTIVE_HIGH
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_VSYNC_ACTIVE_LOW
value|0
end_define

begin_define
define|#
directive|define
name|TRANS_DP_HSYNC_ACTIVE_HIGH
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|TRANS_DP_HSYNC_ACTIVE_LOW
value|0
end_define

begin_define
define|#
directive|define
name|TRANS_DP_SYNC_MASK
value|(3<<3)
end_define

begin_comment
comment|/* SNB eDP training params */
end_comment

begin_comment
comment|/* SNB A-stepping */
end_comment

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_400MV_0DB_SNB_A
value|(0x38<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_400MV_6DB_SNB_A
value|(0x02<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_600MV_3_5DB_SNB_A
value|(0x01<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_800MV_0DB_SNB_A
value|(0x0<<22)
end_define

begin_comment
comment|/* SNB B-stepping */
end_comment

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_400_600MV_0DB_SNB_B
value|(0x0<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_400MV_3_5DB_SNB_B
value|(0x1<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_400_600MV_6DB_SNB_B
value|(0x3a<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_600_800MV_3_5DB_SNB_B
value|(0x39<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_800_1200MV_0DB_SNB_B
value|(0x38<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_VOL_EMP_MASK_SNB
value|(0x3f<<22)
end_define

begin_comment
comment|/* IVB */
end_comment

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_400MV_0DB_IVB
value|(0x24<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_400MV_3_5DB_IVB
value|(0x2a<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_400MV_6DB_IVB
value|(0x2f<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_600MV_0DB_IVB
value|(0x30<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_600MV_3_5DB_IVB
value|(0x36<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_800MV_0DB_IVB
value|(0x38<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_800MV_3_5DB_IVB
value|(0x33<<22)
end_define

begin_comment
comment|/* legacy values */
end_comment

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_500MV_0DB_IVB
value|(0x00<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_1000MV_0DB_IVB
value|(0x20<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_500MV_3_5DB_IVB
value|(0x02<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_1000MV_3_5DB_IVB
value|(0x22<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_1000MV_6DB_IVB
value|(0x23<<22)
end_define

begin_define
define|#
directive|define
name|EDP_LINK_TRAIN_VOL_EMP_MASK_IVB
value|(0x3f<<22)
end_define

begin_define
define|#
directive|define
name|FORCEWAKE
value|0xA18C
end_define

begin_define
define|#
directive|define
name|FORCEWAKE_ACK
value|0x130090
end_define

begin_define
define|#
directive|define
name|FORCEWAKE_MT
value|0xa188
end_define

begin_comment
comment|/* multi-threaded */
end_comment

begin_define
define|#
directive|define
name|FORCEWAKE_MT_ACK
value|0x130040
end_define

begin_define
define|#
directive|define
name|ECOBUS
value|0xa180
end_define

begin_define
define|#
directive|define
name|FORCEWAKE_MT_ENABLE
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|GTFIFODBG
value|0x120000
end_define

begin_define
define|#
directive|define
name|GT_FIFO_CPU_ERROR_MASK
value|7
end_define

begin_define
define|#
directive|define
name|GT_FIFO_OVFERR
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|GT_FIFO_IAWRERR
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|GT_FIFO_IARDERR
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|GT_FIFO_FREE_ENTRIES
value|0x120008
end_define

begin_define
define|#
directive|define
name|GT_FIFO_NUM_RESERVED_ENTRIES
value|20
end_define

begin_define
define|#
directive|define
name|GEN6_UCGCTL1
value|0x9400
end_define

begin_define
define|#
directive|define
name|GEN6_BLBUNIT_CLOCK_GATE_DISABLE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|GEN6_UCGCTL2
value|0x9404
end_define

begin_define
define|#
directive|define
name|GEN6_RCZUNIT_CLOCK_GATE_DISABLE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|GEN6_RCPBUNIT_CLOCK_GATE_DISABLE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|GEN6_RCCUNIT_CLOCK_GATE_DISABLE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|GEN6_RPNSWREQ
value|0xA008
end_define

begin_define
define|#
directive|define
name|GEN6_TURBO_DISABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|GEN6_FREQUENCY
parameter_list|(
name|x
parameter_list|)
value|((x)<<25)
end_define

begin_define
define|#
directive|define
name|GEN6_OFFSET
parameter_list|(
name|x
parameter_list|)
value|((x)<<19)
end_define

begin_define
define|#
directive|define
name|GEN6_AGGRESSIVE_TURBO
value|(0<<15)
end_define

begin_define
define|#
directive|define
name|GEN6_RC_VIDEO_FREQ
value|0xA00C
end_define

begin_define
define|#
directive|define
name|GEN6_RC_CONTROL
value|0xA090
end_define

begin_define
define|#
directive|define
name|GEN6_RC_CTL_RC6pp_ENABLE
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|GEN6_RC_CTL_RC6p_ENABLE
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|GEN6_RC_CTL_RC6_ENABLE
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|GEN6_RC_CTL_RC1e_ENABLE
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|GEN6_RC_CTL_RC7_ENABLE
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|GEN6_RC_CTL_EI_MODE
parameter_list|(
name|x
parameter_list|)
value|((x)<<27)
end_define

begin_define
define|#
directive|define
name|GEN6_RC_CTL_HW_ENABLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|GEN6_RP_DOWN_TIMEOUT
value|0xA010
end_define

begin_define
define|#
directive|define
name|GEN6_RP_INTERRUPT_LIMITS
value|0xA014
end_define

begin_define
define|#
directive|define
name|GEN6_RPSTAT1
value|0xA01C
end_define

begin_define
define|#
directive|define
name|GEN6_CAGF_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|GEN6_CAGF_MASK
value|(0x7f<< GEN6_CAGF_SHIFT)
end_define

begin_define
define|#
directive|define
name|GEN6_RP_CONTROL
value|0xA024
end_define

begin_define
define|#
directive|define
name|GEN6_RP_MEDIA_TURBO
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|GEN6_RP_MEDIA_MODE_MASK
value|(3<<9)
end_define

begin_define
define|#
directive|define
name|GEN6_RP_MEDIA_HW_TURBO_MODE
value|(3<<9)
end_define

begin_define
define|#
directive|define
name|GEN6_RP_MEDIA_HW_NORMAL_MODE
value|(2<<9)
end_define

begin_define
define|#
directive|define
name|GEN6_RP_MEDIA_HW_MODE
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|GEN6_RP_MEDIA_SW_MODE
value|(0<<9)
end_define

begin_define
define|#
directive|define
name|GEN6_RP_MEDIA_IS_GFX
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|GEN6_RP_ENABLE
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|GEN6_RP_UP_IDLE_MIN
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|GEN6_RP_UP_BUSY_AVG
value|(0x2<<3)
end_define

begin_define
define|#
directive|define
name|GEN6_RP_UP_BUSY_CONT
value|(0x4<<3)
end_define

begin_define
define|#
directive|define
name|GEN6_RP_DOWN_IDLE_CONT
value|(0x1<<0)
end_define

begin_define
define|#
directive|define
name|GEN6_RP_UP_THRESHOLD
value|0xA02C
end_define

begin_define
define|#
directive|define
name|GEN6_RP_DOWN_THRESHOLD
value|0xA030
end_define

begin_define
define|#
directive|define
name|GEN6_RP_CUR_UP_EI
value|0xA050
end_define

begin_define
define|#
directive|define
name|GEN6_CURICONT_MASK
value|0xffffff
end_define

begin_define
define|#
directive|define
name|GEN6_RP_CUR_UP
value|0xA054
end_define

begin_define
define|#
directive|define
name|GEN6_CURBSYTAVG_MASK
value|0xffffff
end_define

begin_define
define|#
directive|define
name|GEN6_RP_PREV_UP
value|0xA058
end_define

begin_define
define|#
directive|define
name|GEN6_RP_CUR_DOWN_EI
value|0xA05C
end_define

begin_define
define|#
directive|define
name|GEN6_CURIAVG_MASK
value|0xffffff
end_define

begin_define
define|#
directive|define
name|GEN6_RP_CUR_DOWN
value|0xA060
end_define

begin_define
define|#
directive|define
name|GEN6_RP_PREV_DOWN
value|0xA064
end_define

begin_define
define|#
directive|define
name|GEN6_RP_UP_EI
value|0xA068
end_define

begin_define
define|#
directive|define
name|GEN6_RP_DOWN_EI
value|0xA06C
end_define

begin_define
define|#
directive|define
name|GEN6_RP_IDLE_HYSTERSIS
value|0xA070
end_define

begin_define
define|#
directive|define
name|GEN6_RC_STATE
value|0xA094
end_define

begin_define
define|#
directive|define
name|GEN6_RC1_WAKE_RATE_LIMIT
value|0xA098
end_define

begin_define
define|#
directive|define
name|GEN6_RC6_WAKE_RATE_LIMIT
value|0xA09C
end_define

begin_define
define|#
directive|define
name|GEN6_RC6pp_WAKE_RATE_LIMIT
value|0xA0A0
end_define

begin_define
define|#
directive|define
name|GEN6_RC_EVALUATION_INTERVAL
value|0xA0A8
end_define

begin_define
define|#
directive|define
name|GEN6_RC_IDLE_HYSTERSIS
value|0xA0AC
end_define

begin_define
define|#
directive|define
name|GEN6_RC_SLEEP
value|0xA0B0
end_define

begin_define
define|#
directive|define
name|GEN6_RC1e_THRESHOLD
value|0xA0B4
end_define

begin_define
define|#
directive|define
name|GEN6_RC6_THRESHOLD
value|0xA0B8
end_define

begin_define
define|#
directive|define
name|GEN6_RC6p_THRESHOLD
value|0xA0BC
end_define

begin_define
define|#
directive|define
name|GEN6_RC6pp_THRESHOLD
value|0xA0C0
end_define

begin_define
define|#
directive|define
name|GEN6_PMINTRMSK
value|0xA168
end_define

begin_define
define|#
directive|define
name|GEN6_PMISR
value|0x44020
end_define

begin_define
define|#
directive|define
name|GEN6_PMIMR
value|0x44024
end_define

begin_comment
comment|/* rps_lock */
end_comment

begin_define
define|#
directive|define
name|GEN6_PMIIR
value|0x44028
end_define

begin_define
define|#
directive|define
name|GEN6_PMIER
value|0x4402C
end_define

begin_define
define|#
directive|define
name|GEN6_PM_MBOX_EVENT
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|GEN6_PM_THERMAL_EVENT
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|GEN6_PM_RP_DOWN_TIMEOUT
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|GEN6_PM_RP_UP_THRESHOLD
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|GEN6_PM_RP_DOWN_THRESHOLD
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|GEN6_PM_RP_UP_EI_EXPIRED
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|GEN6_PM_RP_DOWN_EI_EXPIRED
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|GEN6_PM_DEFERRED_EVENTS
value|(GEN6_PM_RP_UP_THRESHOLD | \                   GEN6_PM_RP_DOWN_THRESHOLD | \                   GEN6_PM_RP_DOWN_TIMEOUT)
end_define

begin_define
define|#
directive|define
name|GEN6_PCODE_MAILBOX
value|0x138124
end_define

begin_define
define|#
directive|define
name|GEN6_PCODE_READY
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|GEN6_READ_OC_PARAMS
value|0xc
end_define

begin_define
define|#
directive|define
name|GEN6_PCODE_WRITE_MIN_FREQ_TABLE
value|0x8
end_define

begin_define
define|#
directive|define
name|GEN6_PCODE_READ_MIN_FREQ_TABLE
value|0x9
end_define

begin_define
define|#
directive|define
name|GEN6_PCODE_DATA
value|0x138128
end_define

begin_define
define|#
directive|define
name|GEN6_PCODE_FREQ_IA_RATIO_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|GEN6_GT_CORE_STATUS
value|0x138060
end_define

begin_define
define|#
directive|define
name|GEN6_CORE_CPD_STATE_MASK
value|(7<<4)
end_define

begin_define
define|#
directive|define
name|GEN6_RCn_MASK
value|7
end_define

begin_define
define|#
directive|define
name|GEN6_RC0
value|0
end_define

begin_define
define|#
directive|define
name|GEN6_RC3
value|2
end_define

begin_define
define|#
directive|define
name|GEN6_RC6
value|3
end_define

begin_define
define|#
directive|define
name|GEN6_RC7
value|4
end_define

begin_define
define|#
directive|define
name|G4X_AUD_VID_DID
value|0x62020
end_define

begin_define
define|#
directive|define
name|INTEL_AUDIO_DEVCL
value|0x808629FB
end_define

begin_define
define|#
directive|define
name|INTEL_AUDIO_DEVBLC
value|0x80862801
end_define

begin_define
define|#
directive|define
name|INTEL_AUDIO_DEVCTG
value|0x80862802
end_define

begin_define
define|#
directive|define
name|G4X_AUD_CNTL_ST
value|0x620B4
end_define

begin_define
define|#
directive|define
name|G4X_ELDV_DEVCL_DEVBLC
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|G4X_ELDV_DEVCTG
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|G4X_ELD_ADDR
value|(0xf<< 5)
end_define

begin_define
define|#
directive|define
name|G4X_ELD_ACK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|G4X_HDMIW_HDMIEDID
value|0x6210C
end_define

begin_define
define|#
directive|define
name|IBX_HDMIW_HDMIEDID_A
value|0xE2050
end_define

begin_define
define|#
directive|define
name|IBX_AUD_CNTL_ST_A
value|0xE20B4
end_define

begin_define
define|#
directive|define
name|IBX_ELD_BUFFER_SIZE
value|(0x1f<< 10)
end_define

begin_define
define|#
directive|define
name|IBX_ELD_ADDRESS
value|(0x1f<< 5)
end_define

begin_define
define|#
directive|define
name|IBX_ELD_ACK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|IBX_AUD_CNTL_ST2
value|0xE20C0
end_define

begin_define
define|#
directive|define
name|IBX_ELD_VALIDB
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IBX_CP_READYB
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CPT_HDMIW_HDMIEDID_A
value|0xE5050
end_define

begin_define
define|#
directive|define
name|CPT_AUD_CNTL_ST_A
value|0xE50B4
end_define

begin_define
define|#
directive|define
name|CPT_AUD_CNTRL_ST2
value|0xE50C0
end_define

begin_comment
comment|/* These are the 4 32-bit write offset registers for each stream  * output buffer.  It determines the offset from the  * 3DSTATE_SO_BUFFERs that the next streamed vertex output goes to.  */
end_comment

begin_define
define|#
directive|define
name|GEN7_SO_WRITE_OFFSET
parameter_list|(
name|n
parameter_list|)
value|(0x5280 + (n) * 4)
end_define

begin_define
define|#
directive|define
name|IBX_AUD_CONFIG_A
value|0xe2000
end_define

begin_define
define|#
directive|define
name|CPT_AUD_CONFIG_A
value|0xe5000
end_define

begin_define
define|#
directive|define
name|AUD_CONFIG_N_VALUE_INDEX
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|AUD_CONFIG_N_PROG_ENABLE
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AUD_CONFIG_UPPER_N_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|AUD_CONFIG_UPPER_N_VALUE
value|(0xff<< 20)
end_define

begin_define
define|#
directive|define
name|AUD_CONFIG_LOWER_N_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|AUD_CONFIG_LOWER_N_VALUE
value|(0xfff<< 4)
end_define

begin_define
define|#
directive|define
name|AUD_CONFIG_PIXEL_CLOCK_HDMI_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AUD_CONFIG_PIXEL_CLOCK_HDMI
value|(0xf<< 16)
end_define

begin_define
define|#
directive|define
name|AUD_CONFIG_DISABLE_NCTS
value|(1<< 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I915_REG_H_ */
end_comment

end_unit

