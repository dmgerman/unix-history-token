begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: tcvar.h,v 1.13 1998/05/22 21:15:48 thorpej Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DEV_TC_TCVAR_H__
end_ifndef

begin_define
define|#
directive|define
name|__DEV_TC_TCVAR_H__
end_define

begin_comment
comment|/*  * Definitions for TurboChannel autoconfiguration.  */
end_comment

begin_comment
comment|/*  * In the long run, the following block will go completely away.  * For now, the MI TC code still uses the old TC_IPL_ names  * and not the new IPL_ names.  */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|/*  * Map the new definitions to the old.  */
end_comment

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_define
define|#
directive|define
name|tc_intrlevel_t
value|int
end_define

begin_define
define|#
directive|define
name|TC_IPL_NONE
value|IPL_NONE
end_define

begin_define
define|#
directive|define
name|TC_IPL_BIO
value|IPL_BIO
end_define

begin_define
define|#
directive|define
name|TC_IPL_NET
value|IPL_NET
end_define

begin_define
define|#
directive|define
name|TC_IPL_TTY
value|IPL_TTY
end_define

begin_define
define|#
directive|define
name|TC_IPL_CLOCK
value|IPL_CLOCK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 1 */
end_comment

begin_typedef
typedef|typedef
name|u_int64_t
name|tc_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|tc_offset_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|tc_mb
parameter_list|()
value|alpha_mb()
end_define

begin_define
define|#
directive|define
name|tc_wmb
parameter_list|()
value|alpha_wmb()
end_define

begin_comment
comment|/*  * A junk address to read from, to make sure writes are complete.  See  * System Programmer's Manual, section 9.3 (p. 9-4), and sacrifice a  * chicken.  */
end_comment

begin_define
define|#
directive|define
name|tc_syncbus
parameter_list|()
define|\
value|do {                                                                \         volatile u_int32_t no_optimize;                                 \         no_optimize =                                                   \             *(volatile u_int32_t *)ALPHA_PHYS_TO_K0SEG(0x00000001f0080220); \     } while (0)
end_define

begin_define
define|#
directive|define
name|tc_badaddr
parameter_list|(
name|tcaddr
parameter_list|)
define|\
value|badaddr((void *)(tcaddr), sizeof (u_int32_t))
end_define

begin_define
define|#
directive|define
name|TC_SPACE_IND
value|0xffffffffe0000003
end_define

begin_define
define|#
directive|define
name|TC_SPACE_DENSE
value|0x0000000000000000
end_define

begin_define
define|#
directive|define
name|TC_SPACE_DENSE_OFFSET
value|0x0000000007fffffc
end_define

begin_define
define|#
directive|define
name|TC_SPACE_SPARSE
value|0x0000000010000000
end_define

begin_define
define|#
directive|define
name|TC_SPACE_SPARSE_OFFSET
value|0x000000000ffffff8
end_define

begin_define
define|#
directive|define
name|TC_DENSE_TO_SPARSE
parameter_list|(
name|addr
parameter_list|)
define|\
value|(((addr)& TC_SPACE_IND) | TC_SPACE_SPARSE |                        \         (((addr)& TC_SPACE_DENSE_OFFSET)<< 1))
end_define

begin_define
define|#
directive|define
name|TC_PHYS_TO_UNCACHED
parameter_list|(
name|addr
parameter_list|)
define|\
value|(addr)
end_define

begin_comment
comment|/*  * These functions are private, and may not be called by  * machine-independent code.  */
end_comment

begin_decl_stmt
name|void
name|tc_dma_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Address of scatter/gather SRAM on the 3000/500-series.  *  * There is room for 32K entries, yielding 256M of sgva space.  * The page table is readable in both dense and sparse space.  * The page table is writable only in sparse space.  *  * In sparse space, the 32-bit PTEs are followed by 32-bits  * of pad.  */
end_comment

begin_define
define|#
directive|define
name|TC_SGSRAM_DENSE
value|0x0000001c2800000UL
end_define

begin_define
define|#
directive|define
name|TC_SGSRAM_SPARSE
value|0x0000001d5000000UL
end_define

begin_comment
comment|/*  * Description of TurboChannel slots, provided by machine-dependent  * code to the TurboChannel bus driver.  */
end_comment

begin_struct
struct|struct
name|tc_slotdesc
block|{
name|tc_addr_t
name|tcs_addr
decl_stmt|;
name|void
modifier|*
name|tcs_cookie
decl_stmt|;
name|int
name|tcs_used
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Description of built-in TurboChannel devices, provided by  * machine-dependent code to the TurboChannel bus driver.  */
end_comment

begin_struct
struct|struct
name|tc_builtin
block|{
name|char
modifier|*
name|tcb_modname
decl_stmt|;
name|u_int
name|tcb_slot
decl_stmt|;
name|tc_offset_t
name|tcb_offset
decl_stmt|;
name|void
modifier|*
name|tcb_cookie
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Arguments used to attach TurboChannel busses.  */
end_comment

begin_struct
struct|struct
name|tcbus_attach_args
block|{
name|char
modifier|*
name|tba_busname
decl_stmt|;
comment|/* XXX should be common */
comment|/*        bus_space_tag_t tba_memt;*/
comment|/* Bus information */
name|u_int
name|tba_speed
decl_stmt|;
comment|/* see TC_SPEED_* below */
name|u_int
name|tba_nslots
decl_stmt|;
name|struct
name|tc_slotdesc
modifier|*
name|tba_slots
decl_stmt|;
name|u_int
name|tba_nbuiltins
decl_stmt|;
specifier|const
name|struct
name|tc_builtin
modifier|*
name|tba_builtins
decl_stmt|;
comment|/* TC bus resource management; XXX will move elsewhere eventually. */
comment|/*         void    (*tba_intr_establish) __P((device_t, void *,                     tc_intrlevel_t, int (*)(void *), void *));         void    (*tba_intr_disestablish) __P((device_t, void *)); */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Arguments used to attach TurboChannel devices.  */
end_comment

begin_struct
struct|struct
name|tc_attach_args
block|{
comment|/*         bus_space_tag_t ta_memt;         bus_dma_tag_t   ta_dmat; */
name|char
name|ta_modname
index|[
name|TC_ROM_LLEN
operator|+
literal|1
index|]
decl_stmt|;
name|u_int
name|ta_slot
decl_stmt|;
name|tc_offset_t
name|ta_offset
decl_stmt|;
name|tc_addr_t
name|ta_addr
decl_stmt|;
name|void
modifier|*
name|ta_cookie
decl_stmt|;
name|u_int
name|ta_busspeed
decl_stmt|;
comment|/* see TC_SPEED_* below */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interrupt establishment functions.  */
end_comment

begin_decl_stmt
name|void
name|tc_intr_establish
name|__P
argument_list|(
operator|(
name|device_t
operator|,
name|void
operator|*
operator|,
name|tc_intrlevel_t
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tc_intr_disestablish
name|__P
argument_list|(
operator|(
name|device_t
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|"locators.h"
end_include

begin_comment
comment|/*  * Easy to remember names for TurboChannel device locators.  */
end_comment

begin_define
define|#
directive|define
name|tccf_slot
value|cf_loc[TCCF_SLOT]
end_define

begin_comment
comment|/* slot */
end_comment

begin_define
define|#
directive|define
name|tccf_offset
value|cf_loc[TCCF_OFFSET]
end_define

begin_comment
comment|/* offset */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TCCF_SLOT_UNKNOWN
value|TCCF_SLOT_DEFAULT
end_define

begin_define
define|#
directive|define
name|TCCF_OFFSET_UNKNOWN
value|TCCF_OFFSET_DEFAULT
end_define

begin_comment
comment|/*  * Miscellaneous definitions.  */
end_comment

begin_define
define|#
directive|define
name|TC_SPEED_12_5_MHZ
value|0
end_define

begin_comment
comment|/* 12.5MHz TC bus */
end_comment

begin_define
define|#
directive|define
name|TC_SPEED_25_MHZ
value|1
end_define

begin_comment
comment|/* 25MHz TC bus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DEV_TC_TCVAR_H__ */
end_comment

end_unit

