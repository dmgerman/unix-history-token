begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2013 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FSL_FMAN_H
end_ifndef

begin_define
define|#
directive|define
name|__FSL_FMAN_H
end_define

begin_include
include|#
directive|include
file|"common/general.h"
end_include

begin_struct
struct|struct
name|fman_ext_pool_params
block|{
name|uint8_t
name|id
decl_stmt|;
comment|/**< External buffer pool id */
name|uint16_t
name|size
decl_stmt|;
comment|/**< External buffer pool buffer size */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fman_ext_pools
block|{
name|uint8_t
name|num_pools_used
decl_stmt|;
comment|/**< Number of pools use by this port */
name|struct
name|fman_ext_pool_params
modifier|*
name|ext_buf_pool
decl_stmt|;
comment|/**< Parameters for each port */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fman_backup_bm_pools
block|{
name|uint8_t
name|num_backup_pools
decl_stmt|;
comment|/**< Number of BM backup pools - 					must be smaller than the total number 					of pools defined for the specified 					port.*/
name|uint8_t
modifier|*
name|pool_ids
decl_stmt|;
comment|/**< numOfBackupPools pool id's, 					specifying which pools should be used 					only as backup. Pool id's specified 					here must be a subset of the pools 					used by the specified port.*/
block|}
struct|;
end_struct

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   A structure for defining BM pool depletion criteria */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_struct
struct|struct
name|fman_buf_pool_depletion
block|{
name|bool
name|buf_pool_depletion_enabled
decl_stmt|;
name|bool
name|pools_grp_mode_enable
decl_stmt|;
comment|/**< select mode in which pause frames 					will be sent after a number of pools 					(all together!) are depleted */
name|uint8_t
name|num_pools
decl_stmt|;
comment|/**< the number of depleted pools that 					will invoke pause frames transmission. 					*/
name|bool
modifier|*
name|pools_to_consider
decl_stmt|;
comment|/**< For each pool, TRUE if it should be 					considered for depletion (Note - this 					pool must be used by this port!). */
name|bool
name|single_pool_mode_enable
decl_stmt|;
comment|/**< select mode in which pause frames 					will be sent after a single-pool 					is depleted; */
name|bool
modifier|*
name|pools_to_consider_for_single_mode
decl_stmt|;
comment|/**< For each pool, TRUE if it should be 					considered for depletion (Note - this 					pool must be used by this port!) */
name|bool
name|has_pfc_priorities
decl_stmt|;
name|bool
modifier|*
name|pfc_priorities_en
decl_stmt|;
comment|/**< This field is used by the MAC as 					the Priority Enable Vector in the PFC 					frame which is transmitted */
block|}
struct|;
end_struct

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enum for defining port DMA swap mode */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_enum
enum|enum
name|fman_dma_swap_option
block|{
name|FMAN_DMA_NO_SWP
block|,
comment|/**< No swap, transfer data as is.*/
name|FMAN_DMA_SWP_PPC_LE
block|,
comment|/**< The transferred data should be swapped 					in PowerPc Little Endian mode. */
name|FMAN_DMA_SWP_BE
comment|/**< The transferred data should be swapped 					in Big Endian mode */
block|}
enum|;
end_enum

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enum for defining port DMA cache attributes */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_enum
enum|enum
name|fman_dma_cache_option
block|{
name|FMAN_DMA_NO_STASH
init|=
literal|0
block|,
comment|/**< Cacheable, no Allocate (No Stashing) */
name|FMAN_DMA_STASH
init|=
literal|1
comment|/**< Cacheable and Allocate (Stashing on) */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|struct
name|t_FmPrsResult
name|fm_prs_result_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|e_EnetMode
name|enet_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|t_Handle
name|handle_t
typedef|;
end_typedef

begin_struct
struct|struct
name|fman_revision_info
block|{
name|uint8_t
name|majorRev
decl_stmt|;
comment|/**< Major revision */
name|uint8_t
name|minorRev
decl_stmt|;
comment|/**< Minor revision */
block|}
struct|;
end_struct

begin_comment
comment|/* sizes */
end_comment

begin_define
define|#
directive|define
name|CAPWAP_FRAG_EXTRA_SPACE
value|32
end_define

begin_define
define|#
directive|define
name|OFFSET_UNITS
value|16
end_define

begin_define
define|#
directive|define
name|MAX_INT_OFFSET
value|240
end_define

begin_define
define|#
directive|define
name|MAX_IC_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|MAX_EXT_OFFSET
value|496
end_define

begin_define
define|#
directive|define
name|MAX_EXT_BUFFER_OFFSET
value|511
end_define

begin_comment
comment|/**************************************************************************  @Description       Memory Mapped Registers ***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FMAN_LIODN_TBL
value|64
end_define

begin_comment
comment|/* size of LIODN table */
end_comment

begin_struct
struct|struct
name|fman_fpm_regs
block|{
name|uint32_t
name|fmfp_tnc
decl_stmt|;
comment|/**< FPM TNUM Control 0x00 */
name|uint32_t
name|fmfp_prc
decl_stmt|;
comment|/**< FPM Port_ID FmCtl Association 0x04 */
name|uint32_t
name|fmfp_brkc
decl_stmt|;
comment|/**< FPM Breakpoint Control 0x08 */
name|uint32_t
name|fmfp_mxd
decl_stmt|;
comment|/**< FPM Flush Control 0x0c */
name|uint32_t
name|fmfp_dist1
decl_stmt|;
comment|/**< FPM Dispatch Thresholds1 0x10 */
name|uint32_t
name|fmfp_dist2
decl_stmt|;
comment|/**< FPM Dispatch Thresholds2 0x14 */
name|uint32_t
name|fm_epi
decl_stmt|;
comment|/**< FM Error Pending Interrupts 0x18 */
name|uint32_t
name|fm_rie
decl_stmt|;
comment|/**< FM Error Interrupt Enable 0x1c */
name|uint32_t
name|fmfp_fcev
index|[
literal|4
index|]
decl_stmt|;
comment|/**< FPM FMan-Controller Event 1-4 0x20-0x2f */
name|uint32_t
name|res0030
index|[
literal|4
index|]
decl_stmt|;
comment|/**< res 0x30 - 0x3f */
name|uint32_t
name|fmfp_cee
index|[
literal|4
index|]
decl_stmt|;
comment|/**< PM FMan-Controller Event 1-4 0x40-0x4f */
name|uint32_t
name|res0050
index|[
literal|4
index|]
decl_stmt|;
comment|/**< res 0x50-0x5f */
name|uint32_t
name|fmfp_tsc1
decl_stmt|;
comment|/**< FPM TimeStamp Control1 0x60 */
name|uint32_t
name|fmfp_tsc2
decl_stmt|;
comment|/**< FPM TimeStamp Control2 0x64 */
name|uint32_t
name|fmfp_tsp
decl_stmt|;
comment|/**< FPM Time Stamp 0x68 */
name|uint32_t
name|fmfp_tsf
decl_stmt|;
comment|/**< FPM Time Stamp Fraction 0x6c */
name|uint32_t
name|fm_rcr
decl_stmt|;
comment|/**< FM Rams Control 0x70 */
name|uint32_t
name|fmfp_extc
decl_stmt|;
comment|/**< FPM External Requests Control 0x74 */
name|uint32_t
name|fmfp_ext1
decl_stmt|;
comment|/**< FPM External Requests Config1 0x78 */
name|uint32_t
name|fmfp_ext2
decl_stmt|;
comment|/**< FPM External Requests Config2 0x7c */
name|uint32_t
name|fmfp_drd
index|[
literal|16
index|]
decl_stmt|;
comment|/**< FPM Data_Ram Data 0-15 0x80 - 0xbf */
name|uint32_t
name|fmfp_dra
decl_stmt|;
comment|/**< FPM Data Ram Access 0xc0 */
name|uint32_t
name|fm_ip_rev_1
decl_stmt|;
comment|/**< FM IP Block Revision 1 0xc4 */
name|uint32_t
name|fm_ip_rev_2
decl_stmt|;
comment|/**< FM IP Block Revision 2 0xc8 */
name|uint32_t
name|fm_rstc
decl_stmt|;
comment|/**< FM Reset Command 0xcc */
name|uint32_t
name|fm_cld
decl_stmt|;
comment|/**< FM Classifier Debug 0xd0 */
name|uint32_t
name|fm_npi
decl_stmt|;
comment|/**< FM Normal Pending Interrupts 0xd4 */
name|uint32_t
name|fmfp_exte
decl_stmt|;
comment|/**< FPM External Requests Enable 0xd8 */
name|uint32_t
name|fmfp_ee
decl_stmt|;
comment|/**< FPM Event& Mask 0xdc */
name|uint32_t
name|fmfp_cev
index|[
literal|4
index|]
decl_stmt|;
comment|/**< FPM CPU Event 1-4 0xe0-0xef */
name|uint32_t
name|res00f0
index|[
literal|4
index|]
decl_stmt|;
comment|/**< res 0xf0-0xff */
name|uint32_t
name|fmfp_ps
index|[
literal|64
index|]
decl_stmt|;
comment|/**< FPM Port Status 0x100-0x1ff */
name|uint32_t
name|fmfp_clfabc
decl_stmt|;
comment|/**< FPM CLFABC 0x200 */
name|uint32_t
name|fmfp_clfcc
decl_stmt|;
comment|/**< FPM CLFCC 0x204 */
name|uint32_t
name|fmfp_clfaval
decl_stmt|;
comment|/**< FPM CLFAVAL 0x208 */
name|uint32_t
name|fmfp_clfbval
decl_stmt|;
comment|/**< FPM CLFBVAL 0x20c */
name|uint32_t
name|fmfp_clfcval
decl_stmt|;
comment|/**< FPM CLFCVAL 0x210 */
name|uint32_t
name|fmfp_clfamsk
decl_stmt|;
comment|/**< FPM CLFAMSK 0x214 */
name|uint32_t
name|fmfp_clfbmsk
decl_stmt|;
comment|/**< FPM CLFBMSK 0x218 */
name|uint32_t
name|fmfp_clfcmsk
decl_stmt|;
comment|/**< FPM CLFCMSK 0x21c */
name|uint32_t
name|fmfp_clfamc
decl_stmt|;
comment|/**< FPM CLFAMC 0x220 */
name|uint32_t
name|fmfp_clfbmc
decl_stmt|;
comment|/**< FPM CLFBMC 0x224 */
name|uint32_t
name|fmfp_clfcmc
decl_stmt|;
comment|/**< FPM CLFCMC 0x228 */
name|uint32_t
name|fmfp_decceh
decl_stmt|;
comment|/**< FPM DECCEH 0x22c */
name|uint32_t
name|res0230
index|[
literal|116
index|]
decl_stmt|;
comment|/**< res 0x230 - 0x3ff */
name|uint32_t
name|fmfp_ts
index|[
literal|128
index|]
decl_stmt|;
comment|/**< 0x400: FPM Task Status 0x400 - 0x5ff */
name|uint32_t
name|res0600
index|[
literal|0x400
operator|-
literal|384
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fman_bmi_regs
block|{
name|uint32_t
name|fmbm_init
decl_stmt|;
comment|/**< BMI Initialization 0x00 */
name|uint32_t
name|fmbm_cfg1
decl_stmt|;
comment|/**< BMI Configuration 1 0x04 */
name|uint32_t
name|fmbm_cfg2
decl_stmt|;
comment|/**< BMI Configuration 2 0x08 */
name|uint32_t
name|res000c
index|[
literal|5
index|]
decl_stmt|;
comment|/**< 0x0c - 0x1f */
name|uint32_t
name|fmbm_ievr
decl_stmt|;
comment|/**< Interrupt Event Register 0x20 */
name|uint32_t
name|fmbm_ier
decl_stmt|;
comment|/**< Interrupt Enable Register 0x24 */
name|uint32_t
name|fmbm_ifr
decl_stmt|;
comment|/**< Interrupt Force Register 0x28 */
name|uint32_t
name|res002c
index|[
literal|5
index|]
decl_stmt|;
comment|/**< 0x2c - 0x3f */
name|uint32_t
name|fmbm_arb
index|[
literal|8
index|]
decl_stmt|;
comment|/**< BMI Arbitration 0x40 - 0x5f */
name|uint32_t
name|res0060
index|[
literal|12
index|]
decl_stmt|;
comment|/**<0x60 - 0x8f */
name|uint32_t
name|fmbm_dtc
index|[
literal|3
index|]
decl_stmt|;
comment|/**< Debug Trap Counter 0x90 - 0x9b */
name|uint32_t
name|res009c
decl_stmt|;
comment|/**< 0x9c */
name|uint32_t
name|fmbm_dcv
index|[
literal|3
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/**< Debug Compare val 0xa0-0xcf */
name|uint32_t
name|fmbm_dcm
index|[
literal|3
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/**< Debug Compare Mask 0xd0-0xff */
name|uint32_t
name|fmbm_gde
decl_stmt|;
comment|/**< BMI Global Debug Enable 0x100 */
name|uint32_t
name|fmbm_pp
index|[
literal|63
index|]
decl_stmt|;
comment|/**< BMI Port Parameters 0x104 - 0x1ff */
name|uint32_t
name|res0200
decl_stmt|;
comment|/**< 0x200 */
name|uint32_t
name|fmbm_pfs
index|[
literal|63
index|]
decl_stmt|;
comment|/**< BMI Port FIFO Size 0x204 - 0x2ff */
name|uint32_t
name|res0300
decl_stmt|;
comment|/**< 0x300 */
name|uint32_t
name|fmbm_spliodn
index|[
literal|63
index|]
decl_stmt|;
comment|/**< Port Partition ID 0x304 - 0x3ff */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fman_qmi_regs
block|{
name|uint32_t
name|fmqm_gc
decl_stmt|;
comment|/**< General Configuration Register 0x00 */
name|uint32_t
name|res0004
decl_stmt|;
comment|/**< 0x04 */
name|uint32_t
name|fmqm_eie
decl_stmt|;
comment|/**< Error Interrupt Event Register 0x08 */
name|uint32_t
name|fmqm_eien
decl_stmt|;
comment|/**< Error Interrupt Enable Register 0x0c */
name|uint32_t
name|fmqm_eif
decl_stmt|;
comment|/**< Error Interrupt Force Register 0x10 */
name|uint32_t
name|fmqm_ie
decl_stmt|;
comment|/**< Interrupt Event Register 0x14 */
name|uint32_t
name|fmqm_ien
decl_stmt|;
comment|/**< Interrupt Enable Register 0x18 */
name|uint32_t
name|fmqm_if
decl_stmt|;
comment|/**< Interrupt Force Register 0x1c */
name|uint32_t
name|fmqm_gs
decl_stmt|;
comment|/**< Global Status Register 0x20 */
name|uint32_t
name|fmqm_ts
decl_stmt|;
comment|/**< Task Status Register 0x24 */
name|uint32_t
name|fmqm_etfc
decl_stmt|;
comment|/**< Enqueue Total Frame Counter 0x28 */
name|uint32_t
name|fmqm_dtfc
decl_stmt|;
comment|/**< Dequeue Total Frame Counter 0x2c */
name|uint32_t
name|fmqm_dc0
decl_stmt|;
comment|/**< Dequeue Counter 0 0x30 */
name|uint32_t
name|fmqm_dc1
decl_stmt|;
comment|/**< Dequeue Counter 1 0x34 */
name|uint32_t
name|fmqm_dc2
decl_stmt|;
comment|/**< Dequeue Counter 2 0x38 */
name|uint32_t
name|fmqm_dc3
decl_stmt|;
comment|/**< Dequeue Counter 3 0x3c */
name|uint32_t
name|fmqm_dfdc
decl_stmt|;
comment|/**< Dequeue FQID from Default Counter 0x40 */
name|uint32_t
name|fmqm_dfcc
decl_stmt|;
comment|/**< Dequeue FQID from Context Counter 0x44 */
name|uint32_t
name|fmqm_dffc
decl_stmt|;
comment|/**< Dequeue FQID from FD Counter 0x48 */
name|uint32_t
name|fmqm_dcc
decl_stmt|;
comment|/**< Dequeue Confirm Counter 0x4c */
name|uint32_t
name|res0050
index|[
literal|7
index|]
decl_stmt|;
comment|/**< 0x50 - 0x6b */
name|uint32_t
name|fmqm_tapc
decl_stmt|;
comment|/**< Tnum Aging Period Control 0x6c */
name|uint32_t
name|fmqm_dmcvc
decl_stmt|;
comment|/**< Dequeue MAC Command Valid Counter 0x70 */
name|uint32_t
name|fmqm_difdcc
decl_stmt|;
comment|/**< Dequeue Invalid FD Command Counter 0x74 */
name|uint32_t
name|fmqm_da1v
decl_stmt|;
comment|/**< Dequeue A1 Valid Counter 0x78 */
name|uint32_t
name|res007c
decl_stmt|;
comment|/**< 0x7c */
name|uint32_t
name|fmqm_dtc
decl_stmt|;
comment|/**< 0x80 Debug Trap Counter 0x80 */
name|uint32_t
name|fmqm_efddd
decl_stmt|;
comment|/**< 0x84 Enqueue Frame desc Dynamic dbg 0x84 */
name|uint32_t
name|res0088
index|[
literal|2
index|]
decl_stmt|;
comment|/**< 0x88 - 0x8f */
struct|struct
block|{
name|uint32_t
name|fmqm_dtcfg1
decl_stmt|;
comment|/**< 0x90 dbg trap cfg 1 Register 0x00 */
name|uint32_t
name|fmqm_dtval1
decl_stmt|;
comment|/**< Debug Trap Value 1 Register 0x04 */
name|uint32_t
name|fmqm_dtm1
decl_stmt|;
comment|/**< Debug Trap Mask 1 Register 0x08 */
name|uint32_t
name|fmqm_dtc1
decl_stmt|;
comment|/**< Debug Trap Counter 1 Register 0x0c */
name|uint32_t
name|fmqm_dtcfg2
decl_stmt|;
comment|/**< dbg Trap cfg 2 Register 0x10 */
name|uint32_t
name|fmqm_dtval2
decl_stmt|;
comment|/**< Debug Trap Value 2 Register 0x14 */
name|uint32_t
name|fmqm_dtm2
decl_stmt|;
comment|/**< Debug Trap Mask 2 Register 0x18 */
name|uint32_t
name|res001c
decl_stmt|;
comment|/**< 0x1c */
block|}
name|dbg_traps
index|[
literal|3
index|]
struct|;
comment|/**< 0x90 - 0xef */
name|uint8_t
name|res00f0
index|[
literal|0x400
operator|-
literal|0xf0
index|]
decl_stmt|;
comment|/**< 0xf0 - 0x3ff */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fman_dma_regs
block|{
name|uint32_t
name|fmdmsr
decl_stmt|;
comment|/**< FM DMA status register 0x00 */
name|uint32_t
name|fmdmmr
decl_stmt|;
comment|/**< FM DMA mode register 0x04 */
name|uint32_t
name|fmdmtr
decl_stmt|;
comment|/**< FM DMA bus threshold register 0x08 */
name|uint32_t
name|fmdmhy
decl_stmt|;
comment|/**< FM DMA bus hysteresis register 0x0c */
name|uint32_t
name|fmdmsetr
decl_stmt|;
comment|/**< FM DMA SOS emergency Threshold Register 0x10 */
name|uint32_t
name|fmdmtah
decl_stmt|;
comment|/**< FM DMA transfer bus address high reg 0x14 */
name|uint32_t
name|fmdmtal
decl_stmt|;
comment|/**< FM DMA transfer bus address low reg 0x18 */
name|uint32_t
name|fmdmtcid
decl_stmt|;
comment|/**< FM DMA transfer bus communication ID reg 0x1c */
name|uint32_t
name|fmdmra
decl_stmt|;
comment|/**< FM DMA bus internal ram address register 0x20 */
name|uint32_t
name|fmdmrd
decl_stmt|;
comment|/**< FM DMA bus internal ram data register 0x24 */
name|uint32_t
name|fmdmwcr
decl_stmt|;
comment|/**< FM DMA CAM watchdog counter value 0x28 */
name|uint32_t
name|fmdmebcr
decl_stmt|;
comment|/**< FM DMA CAM base in MURAM register 0x2c */
name|uint32_t
name|fmdmccqdr
decl_stmt|;
comment|/**< FM DMA CAM and CMD Queue Debug reg 0x30 */
name|uint32_t
name|fmdmccqvr1
decl_stmt|;
comment|/**< FM DMA CAM and CMD Queue Value reg #1 0x34 */
name|uint32_t
name|fmdmccqvr2
decl_stmt|;
comment|/**< FM DMA CAM and CMD Queue Value reg #2 0x38 */
name|uint32_t
name|fmdmcqvr3
decl_stmt|;
comment|/**< FM DMA CMD Queue Value register #3 0x3c */
name|uint32_t
name|fmdmcqvr4
decl_stmt|;
comment|/**< FM DMA CMD Queue Value register #4 0x40 */
name|uint32_t
name|fmdmcqvr5
decl_stmt|;
comment|/**< FM DMA CMD Queue Value register #5 0x44 */
name|uint32_t
name|fmdmsefrc
decl_stmt|;
comment|/**< FM DMA Semaphore Entry Full Reject Cntr 0x48 */
name|uint32_t
name|fmdmsqfrc
decl_stmt|;
comment|/**< FM DMA Semaphore Queue Full Reject Cntr 0x4c */
name|uint32_t
name|fmdmssrc
decl_stmt|;
comment|/**< FM DMA Semaphore SYNC Reject Counter 0x50 */
name|uint32_t
name|fmdmdcr
decl_stmt|;
comment|/**< FM DMA Debug Counter 0x54 */
name|uint32_t
name|fmdmemsr
decl_stmt|;
comment|/**< FM DMA Emergency Smoother Register 0x58 */
name|uint32_t
name|res005c
decl_stmt|;
comment|/**< 0x5c */
name|uint32_t
name|fmdmplr
index|[
name|FMAN_LIODN_TBL
operator|/
literal|2
index|]
decl_stmt|;
comment|/**< DMA LIODN regs 0x60-0xdf */
name|uint32_t
name|res00e0
index|[
literal|0x400
operator|-
literal|56
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fman_rg
block|{
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
decl_stmt|;
name|struct
name|fman_dma_regs
modifier|*
name|dma_rg
decl_stmt|;
name|struct
name|fman_bmi_regs
modifier|*
name|bmi_rg
decl_stmt|;
name|struct
name|fman_qmi_regs
modifier|*
name|qmi_rg
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|fman_dma_cache_override
block|{
name|E_FMAN_DMA_NO_CACHE_OR
init|=
literal|0
block|,
comment|/**< No override of the Cache field */
name|E_FMAN_DMA_NO_STASH_DATA
block|,
comment|/**< No data stashing in system level cache */
name|E_FMAN_DMA_MAY_STASH_DATA
block|,
comment|/**< Stashing allowed in sys level cache */
name|E_FMAN_DMA_STASH_DATA
comment|/**< Stashing performed in system level cache */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fman_dma_aid_mode
block|{
name|E_FMAN_DMA_AID_OUT_PORT_ID
init|=
literal|0
block|,
comment|/**< 4 LSB of PORT_ID */
name|E_FMAN_DMA_AID_OUT_TNUM
comment|/**< 4 LSB of TNUM */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fman_dma_dbg_cnt_mode
block|{
name|E_FMAN_DMA_DBG_NO_CNT
init|=
literal|0
block|,
comment|/**< No counting */
name|E_FMAN_DMA_DBG_CNT_DONE
block|,
comment|/**< Count DONE commands */
name|E_FMAN_DMA_DBG_CNT_COMM_Q_EM
block|,
comment|/**< command Q emergency signal */
name|E_FMAN_DMA_DBG_CNT_INT_READ_EM
block|,
comment|/**< Read buf emergency signal */
name|E_FMAN_DMA_DBG_CNT_INT_WRITE_EM
block|,
comment|/**< Write buf emergency signal */
name|E_FMAN_DMA_DBG_CNT_FPM_WAIT
block|,
comment|/**< FPM WAIT signal */
name|E_FMAN_DMA_DBG_CNT_SIGLE_BIT_ECC
block|,
comment|/**< Single bit ECC errors */
name|E_FMAN_DMA_DBG_CNT_RAW_WAR_PROT
comment|/**< RAW& WAR protection counter */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fman_dma_emergency_level
block|{
name|E_FMAN_DMA_EM_EBS
init|=
literal|0
block|,
comment|/**< EBS emergency */
name|E_FMAN_DMA_EM_SOS
comment|/**< SOS emergency */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fman_catastrophic_err
block|{
name|E_FMAN_CATAST_ERR_STALL_PORT
init|=
literal|0
block|,
comment|/**< Port_ID stalled reset required */
name|E_FMAN_CATAST_ERR_STALL_TASK
comment|/**< Only erroneous task is stalled */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fman_dma_err
block|{
name|E_FMAN_DMA_ERR_CATASTROPHIC
init|=
literal|0
block|,
comment|/**< Catastrophic DMA error */
name|E_FMAN_DMA_ERR_REPORT
comment|/**< Reported DMA error */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|fman_cfg
block|{
name|uint16_t
name|liodn_bs_pr_port
index|[
name|FMAN_LIODN_TBL
index|]
decl_stmt|;
comment|/* base per port */
name|bool
name|en_counters
decl_stmt|;
name|uint8_t
name|disp_limit_tsh
decl_stmt|;
name|uint8_t
name|prs_disp_tsh
decl_stmt|;
name|uint8_t
name|plcr_disp_tsh
decl_stmt|;
name|uint8_t
name|kg_disp_tsh
decl_stmt|;
name|uint8_t
name|bmi_disp_tsh
decl_stmt|;
name|uint8_t
name|qmi_enq_disp_tsh
decl_stmt|;
name|uint8_t
name|qmi_deq_disp_tsh
decl_stmt|;
name|uint8_t
name|fm_ctl1_disp_tsh
decl_stmt|;
name|uint8_t
name|fm_ctl2_disp_tsh
decl_stmt|;
name|enum
name|fman_dma_cache_override
name|dma_cache_override
decl_stmt|;
name|enum
name|fman_dma_aid_mode
name|dma_aid_mode
decl_stmt|;
name|bool
name|dma_aid_override
decl_stmt|;
name|uint8_t
name|dma_axi_dbg_num_of_beats
decl_stmt|;
name|uint8_t
name|dma_cam_num_of_entries
decl_stmt|;
name|uint32_t
name|dma_watchdog
decl_stmt|;
name|uint8_t
name|dma_comm_qtsh_asrt_emer
decl_stmt|;
name|uint8_t
name|dma_write_buf_tsh_asrt_emer
decl_stmt|;
name|uint8_t
name|dma_read_buf_tsh_asrt_emer
decl_stmt|;
name|uint8_t
name|dma_comm_qtsh_clr_emer
decl_stmt|;
name|uint8_t
name|dma_write_buf_tsh_clr_emer
decl_stmt|;
name|uint8_t
name|dma_read_buf_tsh_clr_emer
decl_stmt|;
name|uint32_t
name|dma_sos_emergency
decl_stmt|;
name|enum
name|fman_dma_dbg_cnt_mode
name|dma_dbg_cnt_mode
decl_stmt|;
name|bool
name|dma_stop_on_bus_error
decl_stmt|;
name|bool
name|dma_en_emergency
decl_stmt|;
name|uint32_t
name|dma_emergency_bus_select
decl_stmt|;
name|enum
name|fman_dma_emergency_level
name|dma_emergency_level
decl_stmt|;
name|bool
name|dma_en_emergency_smoother
decl_stmt|;
name|uint32_t
name|dma_emergency_switch_counter
decl_stmt|;
name|bool
name|halt_on_external_activ
decl_stmt|;
name|bool
name|halt_on_unrecov_ecc_err
decl_stmt|;
name|enum
name|fman_catastrophic_err
name|catastrophic_err
decl_stmt|;
name|enum
name|fman_dma_err
name|dma_err
decl_stmt|;
name|bool
name|en_muram_test_mode
decl_stmt|;
name|bool
name|en_iram_test_mode
decl_stmt|;
name|bool
name|external_ecc_rams_enable
decl_stmt|;
name|uint16_t
name|tnum_aging_period
decl_stmt|;
name|uint32_t
name|exceptions
decl_stmt|;
name|uint16_t
name|clk_freq
decl_stmt|;
name|bool
name|pedantic_dma
decl_stmt|;
name|uint32_t
name|cam_base_addr
decl_stmt|;
name|uint32_t
name|fifo_base_addr
decl_stmt|;
name|uint32_t
name|total_fifo_size
decl_stmt|;
name|uint8_t
name|total_num_of_tasks
decl_stmt|;
name|bool
name|qmi_deq_option_support
decl_stmt|;
name|uint32_t
name|qmi_def_tnums_thresh
decl_stmt|;
name|bool
name|fman_partition_array
decl_stmt|;
name|uint8_t
name|num_of_fman_ctrl_evnt_regs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       Exceptions */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FMAN_EX_DMA_BUS_ERROR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FMAN_EX_DMA_READ_ECC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FMAN_EX_DMA_SYSTEM_WRITE_ECC
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FMAN_EX_DMA_FM_WRITE_ECC
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FMAN_EX_FPM_STALL_ON_TASKS
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FMAN_EX_FPM_SINGLE_ECC
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FMAN_EX_FPM_DOUBLE_ECC
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FMAN_EX_QMI_SINGLE_ECC
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FMAN_EX_QMI_DEQ_FROM_UNKNOWN_PORTID
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FMAN_EX_QMI_DOUBLE_ECC
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FMAN_EX_BMI_LIST_RAM_ECC
value|0x00200000
end_define

begin_define
define|#
directive|define
name|FMAN_EX_BMI_PIPELINE_ECC
value|0x00100000
end_define

begin_define
define|#
directive|define
name|FMAN_EX_BMI_STATISTICS_RAM_ECC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|FMAN_EX_IRAM_ECC
value|0x00040000
end_define

begin_define
define|#
directive|define
name|FMAN_EX_NURAM_ECC
value|0x00020000
end_define

begin_define
define|#
directive|define
name|FMAN_EX_BMI_DISPATCH_RAM_ECC
value|0x00010000
end_define

begin_enum
enum|enum
name|fman_exceptions
block|{
name|E_FMAN_EX_DMA_BUS_ERROR
init|=
literal|0
block|,
comment|/**< DMA bus error. */
name|E_FMAN_EX_DMA_READ_ECC
block|,
comment|/**< Read Buffer ECC error */
name|E_FMAN_EX_DMA_SYSTEM_WRITE_ECC
block|,
comment|/**< Write Buffer ECC err on sys side */
name|E_FMAN_EX_DMA_FM_WRITE_ECC
block|,
comment|/**< Write Buffer ECC error on FM side */
name|E_FMAN_EX_FPM_STALL_ON_TASKS
block|,
comment|/**< Stall of tasks on FPM */
name|E_FMAN_EX_FPM_SINGLE_ECC
block|,
comment|/**< Single ECC on FPM. */
name|E_FMAN_EX_FPM_DOUBLE_ECC
block|,
comment|/**< Double ECC error on FPM ram access */
name|E_FMAN_EX_QMI_SINGLE_ECC
block|,
comment|/**< Single ECC on QMI. */
name|E_FMAN_EX_QMI_DOUBLE_ECC
block|,
comment|/**< Double bit ECC occurred on QMI */
name|E_FMAN_EX_QMI_DEQ_FROM_UNKNOWN_PORTID
block|,
comment|/**< DeQ from unknown port id */
name|E_FMAN_EX_BMI_LIST_RAM_ECC
block|,
comment|/**< Linked List RAM ECC error */
name|E_FMAN_EX_BMI_STORAGE_PROFILE_ECC
block|,
comment|/**< storage profile */
name|E_FMAN_EX_BMI_STATISTICS_RAM_ECC
block|,
comment|/**< Statistics RAM ECC Err Enable */
name|E_FMAN_EX_BMI_DISPATCH_RAM_ECC
block|,
comment|/**< Dispatch RAM ECC Error Enable */
name|E_FMAN_EX_IRAM_ECC
block|,
comment|/**< Double bit ECC occurred on IRAM*/
name|E_FMAN_EX_MURAM_ECC
comment|/**< Double bit ECC occurred on MURAM*/
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fman_counters
block|{
name|E_FMAN_COUNTERS_ENQ_TOTAL_FRAME
init|=
literal|0
block|,
comment|/**< QMI tot enQ frames counter */
name|E_FMAN_COUNTERS_DEQ_TOTAL_FRAME
block|,
comment|/**< QMI tot deQ frames counter */
name|E_FMAN_COUNTERS_DEQ_0
block|,
comment|/**< QMI 0 frames from QMan counter */
name|E_FMAN_COUNTERS_DEQ_1
block|,
comment|/**< QMI 1 frames from QMan counter */
name|E_FMAN_COUNTERS_DEQ_2
block|,
comment|/**< QMI 2 frames from QMan counter */
name|E_FMAN_COUNTERS_DEQ_3
block|,
comment|/**< QMI 3 frames from QMan counter */
name|E_FMAN_COUNTERS_DEQ_FROM_DEFAULT
block|,
comment|/**< QMI deQ from dflt queue cntr */
name|E_FMAN_COUNTERS_DEQ_FROM_CONTEXT
block|,
comment|/**< QMI deQ from FQ context cntr */
name|E_FMAN_COUNTERS_DEQ_FROM_FD
block|,
comment|/**< QMI deQ from FD command field cntr */
name|E_FMAN_COUNTERS_DEQ_CONFIRM
block|,
comment|/**< QMI dequeue confirm counter */
name|E_FMAN_COUNTERS_SEMAPHOR_ENTRY_FULL_REJECT
block|,
comment|/**< DMA full entry cntr */
name|E_FMAN_COUNTERS_SEMAPHOR_QUEUE_FULL_REJECT
block|,
comment|/**< DMA full CAM Q cntr */
name|E_FMAN_COUNTERS_SEMAPHOR_SYNC_REJECT
comment|/**< DMA sync counter */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|FPM_PRT_FM_CTL1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|FPM_PRT_FM_CTL2
value|0x00000002
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       DMA definitions */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|DMA_MODE_AID_OR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|DMA_MODE_SBER
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DMA_MODE_BER
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DMA_MODE_EB
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DMA_MODE_ECC
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DMA_MODE_PRIVILEGE_PROT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DMA_MODE_SECURE_PROT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DMA_MODE_EMER_READ
value|0x00080000
end_define

begin_define
define|#
directive|define
name|DMA_MODE_EMER_WRITE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|DMA_MODE_CACHE_OR_MASK
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|DMA_MODE_CEN_MASK
value|0x0000E000
end_define

begin_define
define|#
directive|define
name|DMA_MODE_DBG_MASK
value|0x00000380
end_define

begin_define
define|#
directive|define
name|DMA_MODE_AXI_DBG_MASK
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|DMA_EMSR_EMSTR_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|DMA_TRANSFER_PORTID_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|DMA_TRANSFER_TNUM_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|DMA_TRANSFER_LIODN_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|DMA_HIGH_LIODN_MASK
value|0x0FFF0000
end_define

begin_define
define|#
directive|define
name|DMA_LOW_LIODN_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_CMD_QUEUE_NOT_EMPTY
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_BUS_ERR
value|0x08000000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_READ_ECC
value|0x04000000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_SYSTEM_WRITE_ECC
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_FM_WRITE_ECC
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_SYSTEM_DPEXT_ECC
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_FM_DPEXT_ECC
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_SYSTEM_DPDAT_ECC
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_FM_DPDAT_ECC
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DMA_STATUS_FM_SPDAT_ECC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|FM_LIODN_BASE_MASK
value|0x00000FFF
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|DMA_MODE_CACHE_OR_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|DMA_MODE_BUS_PRI_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DMA_MODE_AXI_DBG_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|DMA_MODE_CEN_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|DMA_MODE_BUS_PROT_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|DMA_MODE_DBG_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|DMA_MODE_EMER_LVL_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|DMA_MODE_AID_MODE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|DMA_MODE_MAX_AXI_DBG_NUM_OF_BEATS
value|16
end_define

begin_define
define|#
directive|define
name|DMA_MODE_MAX_CAM_NUM_OF_ENTRIES
value|32
end_define

begin_define
define|#
directive|define
name|DMA_THRESH_COMMQ_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|DMA_THRESH_READ_INT_BUF_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DMA_LIODN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DMA_TRANSFER_PORTID_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|DMA_TRANSFER_TNUM_SHIFT
value|16
end_define

begin_comment
comment|/* sizes */
end_comment

begin_define
define|#
directive|define
name|DMA_MAX_WATCHDOG
value|0xffffffff
end_define

begin_comment
comment|/* others */
end_comment

begin_define
define|#
directive|define
name|DMA_CAM_SIZEOF_ENTRY
value|0x40
end_define

begin_define
define|#
directive|define
name|DMA_CAM_ALIGN
value|0x1000
end_define

begin_define
define|#
directive|define
name|DMA_CAM_UNITS
value|8
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       General defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_DEBUG_STATUS_REGISTER_OFFSET
value|0x000d1084UL
end_define

begin_define
define|#
directive|define
name|FM_UCODE_DEBUG_INSTRUCTION
value|0x6ffff805UL
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       FPM defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|FPM_EV_MASK_DOUBLE_ECC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_STALL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_SINGLE_ECC
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_RELEASE_FM
value|0x00010000
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_DOUBLE_ECC_EN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_STALL_EN
value|0x00004000
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_SINGLE_ECC_EN
value|0x00002000
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_EXTERNAL_HALT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_ECC_ERR_HALT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|FPM_RAM_RAMS_ECC_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FPM_RAM_IRAM_ECC_EN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FPM_RAM_MURAM_ECC
value|0x00008000
end_define

begin_define
define|#
directive|define
name|FPM_RAM_IRAM_ECC
value|0x00004000
end_define

begin_define
define|#
directive|define
name|FPM_RAM_MURAM_TEST_ECC
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FPM_RAM_IRAM_TEST_ECC
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FPM_RAM_RAMS_ECC_EN_SRC_SEL
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FPM_IRAM_ECC_ERR_EX_EN
value|0x00020000
end_define

begin_define
define|#
directive|define
name|FPM_MURAM_ECC_ERR_EX_EN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|FPM_REV1_MAJOR_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|FPM_REV1_MINOR_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|FPM_REV2_INTEG_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|FPM_REV2_ERR_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|FPM_REV2_CFG_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|FPM_TS_FRACTION_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|FPM_TS_CTL_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FPM_PRC_REALSE_STALLED
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FPM_PS_STALLED
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FPM_PS_FM_CTL1_SEL
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FPM_PS_FM_CTL2_SEL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FPM_PS_FM_CTL_SEL_MASK
value|(FPM_PS_FM_CTL1_SEL | FPM_PS_FM_CTL2_SEL)
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_FM_RESET
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_10G0_RESET
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G0_RESET
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G1_RESET
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G2_RESET
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G3_RESET
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G4_RESET
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FPM_DISP_LIMIT_MASK
value|0x1F000000
end_define

begin_define
define|#
directive|define
name|FPM_THR1_PRS_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|FPM_THR1_KG_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|FPM_THR1_PLCR_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|FPM_THR1_BMI_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|FPM_THR2_QMI_ENQ_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|FPM_THR2_QMI_DEQ_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|FPM_THR2_FM_CTL1_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|FPM_THR2_FM_CTL2_MASK
value|0x0000FF00
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|FPM_DISP_LIMIT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FPM_THR1_PRS_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FPM_THR1_KG_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FPM_THR1_PLCR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|FPM_THR1_BMI_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FPM_THR2_QMI_ENQ_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FPM_THR2_QMI_DEQ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FPM_THR2_FM_CTL1_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FPM_THR2_FM_CTL2_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_CAT_ERR_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|FPM_EV_MASK_DMA_ERR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FPM_REV1_MAJOR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|FPM_REV1_MINOR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FPM_REV2_INTEG_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FPM_REV2_ERR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|FPM_REV2_CFG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|FPM_TS_INT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FPM_PORT_FM_CTL_PORTID_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|FPM_PS_FM_CTL_SEL_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|FPM_PRC_ORA_FM_CTL_SEL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FPM_DISP_LIMIT_SHIFT
value|24
end_define

begin_comment
comment|/* Interrupts defines */
end_comment

begin_define
define|#
directive|define
name|FPM_EVENT_FM_CTL_0
value|0x00008000
end_define

begin_define
define|#
directive|define
name|FPM_EVENT_FM_CTL
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|FPM_EVENT_FM_CTL_BRK
value|0x00000080
end_define

begin_comment
comment|/* others */
end_comment

begin_define
define|#
directive|define
name|FPM_MAX_DISP_LIMIT
value|31
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_FM_RESET
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G0_RESET
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G1_RESET
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G2_RESET
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G3_RESET
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_10G0_RESET
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G4_RESET
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G5_RESET
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G6_RESET
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_1G7_RESET
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FPM_RSTC_10G1_RESET
value|0x00200000
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       BMI defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|BMI_INIT_START
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BMI_ERR_INTR_EN_STORAGE_PROFILE_ECC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BMI_ERR_INTR_EN_LIST_RAM_ECC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BMI_ERR_INTR_EN_STATISTICS_RAM_ECC
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BMI_ERR_INTR_EN_DISPATCH_RAM_ECC
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BMI_NUM_OF_TASKS_MASK
value|0x3F000000
end_define

begin_define
define|#
directive|define
name|BMI_NUM_OF_EXTRA_TASKS_MASK
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|BMI_NUM_OF_DMAS_MASK
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|BMI_NUM_OF_EXTRA_DMAS_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|BMI_FIFO_SIZE_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|BMI_EXTRA_FIFO_SIZE_MASK
value|0x03FF0000
end_define

begin_define
define|#
directive|define
name|BMI_CFG2_DMAS_MASK
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|BMI_TOTAL_FIFO_SIZE_MASK
value|0x07FF0000
end_define

begin_define
define|#
directive|define
name|BMI_TOTAL_NUM_OF_TASKS_MASK
value|0x007F0000
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|BMI_CFG2_TASKS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_CFG2_DMAS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BMI_CFG1_FIFO_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_FIFO_SIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BMI_EXTRA_FIFO_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_NUM_OF_TASKS_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BMI_EXTRA_NUM_OF_TASKS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BMI_NUM_OF_DMAS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BMI_EXTRA_NUM_OF_DMAS_SHIFT
value|0
end_define

begin_comment
comment|/* others */
end_comment

begin_define
define|#
directive|define
name|BMI_FIFO_ALIGN
value|0x100
end_define

begin_define
define|#
directive|define
name|FMAN_BMI_FIFO_UNITS
value|0x100
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       QMI defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|QMI_CFG_ENQ_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|QMI_CFG_DEQ_EN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|QMI_CFG_EN_COUNTERS
value|0x10000000
end_define

begin_define
define|#
directive|define
name|QMI_CFG_SOFT_RESET
value|0x01000000
end_define

begin_define
define|#
directive|define
name|QMI_CFG_DEQ_MASK
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|QMI_CFG_ENQ_MASK
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|QMI_ERR_INTR_EN_DOUBLE_ECC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|QMI_ERR_INTR_EN_DEQ_FROM_DEF
value|0x40000000
end_define

begin_define
define|#
directive|define
name|QMI_INTR_EN_SINGLE_ECC
value|0x80000000
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|QMI_CFG_ENQ_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|QMI_TAPC_TAP
value|22
end_define

begin_define
define|#
directive|define
name|QMI_GS_HALT_NOT_BUSY
value|0x00000002
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       IRAM defines */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|IRAM_IADD_AIE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IRAM_READY
value|0x80000000
end_define

begin_function_decl
name|uint32_t
name|fman_get_bmi_err_event
parameter_list|(
name|struct
name|fman_bmi_regs
modifier|*
name|bmi_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_get_qmi_err_event
parameter_list|(
name|struct
name|fman_qmi_regs
modifier|*
name|qmi_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_get_dma_com_id
parameter_list|(
name|struct
name|fman_dma_regs
modifier|*
name|dma_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|fman_get_dma_addr
parameter_list|(
name|struct
name|fman_dma_regs
modifier|*
name|dma_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_get_dma_err_event
parameter_list|(
name|struct
name|fman_dma_regs
modifier|*
name|dma_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_get_fpm_err_event
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_get_muram_err_event
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_get_iram_err_event
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_get_qmi_event
parameter_list|(
name|struct
name|fman_qmi_regs
modifier|*
name|qmi_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_get_fpm_error_interrupts
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_get_ctrl_intr
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|,
name|uint8_t
name|event_reg_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|fman_get_qmi_deq_th
parameter_list|(
name|struct
name|fman_qmi_regs
modifier|*
name|qmi_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|fman_get_qmi_enq_th
parameter_list|(
name|struct
name|fman_qmi_regs
modifier|*
name|qmi_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|fman_get_size_of_fifo
parameter_list|(
name|struct
name|fman_bmi_regs
modifier|*
name|bmi_rg
parameter_list|,
name|uint8_t
name|port_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_get_total_fifo_size
parameter_list|(
name|struct
name|fman_bmi_regs
modifier|*
name|bmi_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|fman_get_size_of_extra_fifo
parameter_list|(
name|struct
name|fman_bmi_regs
modifier|*
name|bmi_rg
parameter_list|,
name|uint8_t
name|port_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|fman_get_num_of_tasks
parameter_list|(
name|struct
name|fman_bmi_regs
modifier|*
name|bmi_rg
parameter_list|,
name|uint8_t
name|port_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|fman_get_num_extra_tasks
parameter_list|(
name|struct
name|fman_bmi_regs
modifier|*
name|bmi_rg
parameter_list|,
name|uint8_t
name|port_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|fman_get_num_of_dmas
parameter_list|(
name|struct
name|fman_bmi_regs
modifier|*
name|bmi_rg
parameter_list|,
name|uint8_t
name|port_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|fman_get_num_extra_dmas
parameter_list|(
name|struct
name|fman_bmi_regs
modifier|*
name|bmi_rg
parameter_list|,
name|uint8_t
name|port_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_get_normal_pending
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_get_controller_event
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|,
name|uint8_t
name|reg_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_get_error_pending
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_get_revision
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|,
name|uint8_t
modifier|*
name|major
parameter_list|,
name|uint8_t
modifier|*
name|minor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_get_counter
parameter_list|(
name|struct
name|fman_rg
modifier|*
name|fman_rg
parameter_list|,
name|enum
name|fman_counters
name|reg_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_get_dma_status
parameter_list|(
name|struct
name|fman_dma_regs
modifier|*
name|dma_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_set_erratum_10gmac_a004_wa
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_set_ctrl_intr
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|,
name|uint8_t
name|event_reg_id
parameter_list|,
name|uint32_t
name|enable_events
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_set_num_of_riscs_per_port
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|,
name|uint8_t
name|port_id
parameter_list|,
name|uint8_t
name|num_fman_ctrls
parameter_list|,
name|uint32_t
name|or_fman_ctrl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_set_order_restoration_per_port
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|,
name|uint8_t
name|port_id
parameter_list|,
name|bool
name|independent_mode
parameter_list|,
name|bool
name|is_rx_port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_set_qmi_enq_th
parameter_list|(
name|struct
name|fman_qmi_regs
modifier|*
name|qmi_rg
parameter_list|,
name|uint8_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_set_qmi_deq_th
parameter_list|(
name|struct
name|fman_qmi_regs
modifier|*
name|qmi_rg
parameter_list|,
name|uint8_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_set_liodn_per_port
parameter_list|(
name|struct
name|fman_rg
modifier|*
name|fman_rg
parameter_list|,
name|uint8_t
name|port_id
parameter_list|,
name|uint16_t
name|liodn_base
parameter_list|,
name|uint16_t
name|liodn_offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_set_size_of_fifo
parameter_list|(
name|struct
name|fman_bmi_regs
modifier|*
name|bmi_rg
parameter_list|,
name|uint8_t
name|port_id
parameter_list|,
name|uint32_t
name|size_of_fifo
parameter_list|,
name|uint32_t
name|extra_size_of_fifo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_set_num_of_tasks
parameter_list|(
name|struct
name|fman_bmi_regs
modifier|*
name|bmi_rg
parameter_list|,
name|uint8_t
name|port_id
parameter_list|,
name|uint8_t
name|num_of_tasks
parameter_list|,
name|uint8_t
name|num_of_extra_tasks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_set_num_of_open_dmas
parameter_list|(
name|struct
name|fman_bmi_regs
modifier|*
name|bmi_rg
parameter_list|,
name|uint8_t
name|port_id
parameter_list|,
name|uint8_t
name|num_of_open_dmas
parameter_list|,
name|uint8_t
name|num_of_extra_open_dmas
parameter_list|,
name|uint8_t
name|total_num_of_dmas
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_set_ports_bandwidth
parameter_list|(
name|struct
name|fman_bmi_regs
modifier|*
name|bmi_rg
parameter_list|,
name|uint8_t
modifier|*
name|weights
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_set_exception
parameter_list|(
name|struct
name|fman_rg
modifier|*
name|fman_rg
parameter_list|,
name|enum
name|fman_exceptions
name|exception
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_set_dma_emergency
parameter_list|(
name|struct
name|fman_dma_regs
modifier|*
name|dma_rg
parameter_list|,
name|bool
name|is_write
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_set_dma_ext_bus_pri
parameter_list|(
name|struct
name|fman_dma_regs
modifier|*
name|dma_rg
parameter_list|,
name|uint32_t
name|pri
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_set_congestion_group_pfc_priority
parameter_list|(
name|uint32_t
modifier|*
name|cpg_rg
parameter_list|,
name|uint32_t
name|congestion_group_id
parameter_list|,
name|uint8_t
name|piority_bit_map
parameter_list|,
name|uint32_t
name|reg_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_defconfig
parameter_list|(
name|struct
name|fman_cfg
modifier|*
name|cfg
parameter_list|,
name|bool
name|is_master
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_regconfig
parameter_list|(
name|struct
name|fman_rg
modifier|*
name|fman_rg
parameter_list|,
name|struct
name|fman_cfg
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_fpm_init
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|,
name|struct
name|fman_cfg
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_bmi_init
parameter_list|(
name|struct
name|fman_bmi_regs
modifier|*
name|bmi_rg
parameter_list|,
name|struct
name|fman_cfg
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_qmi_init
parameter_list|(
name|struct
name|fman_qmi_regs
modifier|*
name|qmi_rg
parameter_list|,
name|struct
name|fman_cfg
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_dma_init
parameter_list|(
name|struct
name|fman_dma_regs
modifier|*
name|dma_rg
parameter_list|,
name|struct
name|fman_cfg
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_free_resources
parameter_list|(
name|struct
name|fman_rg
modifier|*
name|fman_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_enable
parameter_list|(
name|struct
name|fman_rg
modifier|*
name|fman_rg
parameter_list|,
name|struct
name|fman_cfg
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_reset
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_resume
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_enable_time_stamp
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|,
name|uint8_t
name|count1ubit
parameter_list|,
name|uint16_t
name|fm_clk_freq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_enable_rams_ecc
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_qmi_disable_dispatch_limit
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_disable_rams_ecc
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_resume_stalled_port
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|,
name|uint8_t
name|port_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_reset_mac
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|,
name|uint8_t
name|macId
parameter_list|,
name|bool
name|is_10g
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|fman_is_port_stalled
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|,
name|uint8_t
name|port_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|fman_rams_ecc_is_external_ctl
parameter_list|(
name|struct
name|fman_fpm_regs
modifier|*
name|fpm_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|fman_is_qmi_halt_not_busy_state
parameter_list|(
name|struct
name|fman_qmi_regs
modifier|*
name|qmi_rg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_modify_counter
parameter_list|(
name|struct
name|fman_rg
modifier|*
name|fman_rg
parameter_list|,
name|enum
name|fman_counters
name|reg_name
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_force_intr
parameter_list|(
name|struct
name|fman_rg
modifier|*
name|fman_rg
parameter_list|,
name|enum
name|fman_exceptions
name|exception
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_set_vsp_window
parameter_list|(
name|struct
name|fman_bmi_regs
modifier|*
name|bmi_rg
parameter_list|,
name|uint8_t
name|port_id
parameter_list|,
name|uint8_t
name|base_storage_profile
parameter_list|,
name|uint8_t
name|log2_num_of_profiles
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description       default values */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DEFAULT_CATASTROPHIC_ERR
value|E_FMAN_CATAST_ERR_STALL_PORT
end_define

begin_define
define|#
directive|define
name|DEFAULT_DMA_ERR
value|E_FMAN_DMA_ERR_CATASTROPHIC
end_define

begin_define
define|#
directive|define
name|DEFAULT_HALT_ON_EXTERNAL_ACTIVATION
value|FALSE
end_define

begin_comment
comment|/* do not change! if changed, must be disabled for rev1 ! */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_HALT_ON_UNRECOVERABLE_ECC_ERROR
value|FALSE
end_define

begin_comment
comment|/* do not change! if changed, must be disabled for rev1 ! */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_EXTERNAL_ECC_RAMS_ENABLE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_AID_OVERRIDE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_AID_MODE
value|E_FMAN_DMA_AID_OUT_TNUM
end_define

begin_define
define|#
directive|define
name|DEFAULT_DMA_COMM_Q_LOW
value|0x2A
end_define

begin_define
define|#
directive|define
name|DEFAULT_DMA_COMM_Q_HIGH
value|0x3F
end_define

begin_define
define|#
directive|define
name|DEFAULT_CACHE_OVERRIDE
value|E_FMAN_DMA_NO_CACHE_OR
end_define

begin_define
define|#
directive|define
name|DEFAULT_DMA_CAM_NUM_OF_ENTRIES
value|64
end_define

begin_define
define|#
directive|define
name|DEFAULT_DMA_DBG_CNT_MODE
value|E_FMAN_DMA_DBG_NO_CNT
end_define

begin_define
define|#
directive|define
name|DEFAULT_DMA_EN_EMERGENCY
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_DMA_SOS_EMERGENCY
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_DMA_WATCHDOG
value|0
end_define

begin_comment
comment|/* disabled */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_DMA_EN_EMERGENCY_SMOOTHER
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_DMA_EMERGENCY_SWITCH_COUNTER
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_DISP_LIMIT
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_PRS_DISP_TH
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_PLCR_DISP_TH
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_KG_DISP_TH
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_BMI_DISP_TH
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_QMI_ENQ_DISP_TH
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_QMI_DEQ_DISP_TH
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_FM_CTL1_DISP_TH
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_FM_CTL2_DISP_TH
value|16
end_define

begin_define
define|#
directive|define
name|DEFAULT_TNUM_AGING_PERIOD
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FSL_FMAN_H */
end_comment

end_unit

