begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  * From	$NetBSD: OSFpal.c,v 1.5 1998/06/24 01:33:19 ross Exp $   */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Keith Bostic  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|<machine/prom.h>
end_include

begin_include
include|#
directive|include
file|<machine/rpb.h>
end_include

begin_include
include|#
directive|include
file|<machine/alpha_cpu.h>
end_include

begin_decl_stmt
name|vm_offset_t
name|ptbr_save
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_function
name|void
name|OSFpal
parameter_list|()
block|{
name|struct
name|rpb
modifier|*
name|r
decl_stmt|;
name|struct
name|pcs
modifier|*
name|p
decl_stmt|;
name|r
operator|=
operator|(
expr|struct
name|rpb
operator|*
operator|)
name|HWRPB_ADDR
expr_stmt|;
comment|/* 	 * Note, cpu_number() is a VMS op, can't necessarily call it. 	 * Real fun: PAL_VMS_mfpr_whami == PAL_OSF1_rti... 	 * We might not be rpb_primary_cpu_id, but it is supposed to go 	 * first so the answer should apply to everyone. 	 */
name|p
operator|=
name|LOCATE_PCS
argument_list|(
name|r
argument_list|,
name|r
operator|->
name|rpb_primary_cpu_id
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"VMS PAL rev: 0x%lx\n"
argument_list|,
name|p
operator|->
name|pcs_palrevisions
index|[
name|PALvar_OpenVMS
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"OSF PAL rev: 0x%lx\n"
argument_list|,
name|p
operator|->
name|pcs_palrevisions
index|[
name|PALvar_OSF1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|pcs_pal_type
operator|==
name|PAL_TYPE_OSF1
condition|)
block|{
name|printf
argument_list|(
literal|"OSF PAL code already running.\n"
argument_list|)
expr_stmt|;
name|ptbr_save
operator|=
operator|(
operator|(
expr|struct
name|alpha_pcb
operator|*
operator|)
name|p
operator|)
operator|->
name|apcb_ptbr
expr_stmt|;
name|printf
argument_list|(
literal|"PTBR is:          0x%lx\n"
argument_list|,
name|ptbr_save
argument_list|)
expr_stmt|;
return|return;
block|}
name|switch_palcode
argument_list|()
expr_stmt|;
name|bcopy
argument_list|(
operator|&
name|p
operator|->
name|pcs_palrevisions
index|[
name|PALvar_OSF1
index|]
argument_list|,
operator|&
name|p
operator|->
name|pcs_pal_rev
argument_list|,
sizeof|sizeof
argument_list|(
name|p
operator|->
name|pcs_pal_rev
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Switch to OSF PAL code succeeded.\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

