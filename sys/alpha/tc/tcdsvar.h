begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: tcdsvar.h,v 1.3.4.1 1996/09/10 17:28:20 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_struct
struct|struct
name|tcds_slotconfig
block|{
comment|/* 	 * Bookkeeping information 	 */
name|int
name|sc_slot
decl_stmt|;
name|struct
name|tcds_softc
modifier|*
name|sc_tcds
decl_stmt|;
comment|/* to frob TCDS regs */
name|struct
name|esp_softc
modifier|*
name|sc_esp
decl_stmt|;
comment|/* to frob child's regs */
name|void
function_decl|(
modifier|*
name|sc_intrhand
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* intr. handler */
name|void
modifier|*
name|sc_intrarg
decl_stmt|;
comment|/* intr. handler arg. */
comment|/* 	 * Sets of bits in TCDS CIR and IMER that enable/check 	 * various things. 	 */
name|u_int32_t
name|sc_resetbits
decl_stmt|;
name|u_int32_t
name|sc_intrmaskbits
decl_stmt|;
name|u_int32_t
name|sc_intrbits
decl_stmt|;
name|u_int32_t
name|sc_dmabits
decl_stmt|;
name|u_int32_t
name|sc_errorbits
decl_stmt|;
comment|/* 	 * Pointers to slot-specific DMA resources. 	 */
specifier|volatile
name|u_int32_t
modifier|*
name|sc_sda
decl_stmt|;
specifier|volatile
name|u_int32_t
modifier|*
name|sc_dic
decl_stmt|;
specifier|volatile
name|u_int32_t
modifier|*
name|sc_dud0
decl_stmt|;
specifier|volatile
name|u_int32_t
modifier|*
name|sc_dud1
decl_stmt|;
comment|/* 	 * DMA bookkeeping information. 	 */
name|int
name|sc_active
decl_stmt|;
comment|/* DMA active ? */
name|int
name|sc_iswrite
decl_stmt|;
comment|/* DMA into main memory? */
name|size_t
name|sc_dmasize
decl_stmt|;
name|caddr_t
modifier|*
name|sc_dmaaddr
decl_stmt|;
name|size_t
modifier|*
name|sc_dmalen
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tcdsdev_attach_args
block|{
name|struct
name|tc_attach_args
name|tcdsda_ta
decl_stmt|;
name|struct
name|tcds_slotconfig
modifier|*
name|tcdsda_sc
decl_stmt|;
name|u_int
name|tcdsda_id
decl_stmt|;
name|u_int
name|tcdsda_freq
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tcdsda_modname
value|tcdsda_ta.ta_modname
end_define

begin_define
define|#
directive|define
name|tcdsda_slot
value|tcdsda_ta.ta_slot
end_define

begin_define
define|#
directive|define
name|tcdsda_offset
value|tcdsda_ta.ta_offset
end_define

begin_define
define|#
directive|define
name|tcdsda_addr
value|tcdsda_ta.ta_addr
end_define

begin_define
define|#
directive|define
name|tcdsda_cookie
value|tcdsda_ta.ta_cookie
end_define

begin_define
define|#
directive|define
name|TCDS_REG
parameter_list|(
name|base
parameter_list|,
name|off
parameter_list|)
define|\
value|(volatile u_int32_t *)TC_DENSE_TO_SPARSE((base) + (off))
end_define

begin_comment
comment|/*  * TCDS functions.  */
end_comment

begin_function_decl
name|void
name|tcds_intr_establish
parameter_list|(
name|device_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|tc_intrlevel_t
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcds_intr_disestablish
parameter_list|(
name|device_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcds_dma_enable
parameter_list|(
name|struct
name|tcds_slotconfig
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcds_scsi_enable
parameter_list|(
name|struct
name|tcds_slotconfig
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcds_scsi_isintr
parameter_list|(
name|struct
name|tcds_slotconfig
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcds_scsi_reset
parameter_list|(
name|struct
name|tcds_slotconfig
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcds_scsi_iserr
parameter_list|(
name|struct
name|tcds_slotconfig
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * TCDS DMA functions (used the the 53c94 driver)  */
end_comment

begin_function_decl
name|int
name|tcds_dma_isintr
parameter_list|(
name|struct
name|tcds_slotconfig
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcds_dma_reset
parameter_list|(
name|struct
name|tcds_slotconfig
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcds_dma_intr
parameter_list|(
name|struct
name|tcds_slotconfig
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcds_dma_setup
parameter_list|(
name|struct
name|tcds_slotconfig
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcds_dma_go
parameter_list|(
name|struct
name|tcds_slotconfig
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcds_dma_isactive
parameter_list|(
name|struct
name|tcds_slotconfig
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The TCDS (bus) cfdriver, so that subdevices can more  * easily tell what bus they're on.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cfdriver
name|tcds_cd
decl_stmt|;
end_decl_stmt

end_unit

