begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: ioasicvar.h,v 1.5 1998/01/19 02:50:19 thorpej Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * IOASIC subdevice attachment information.  */
end_comment

begin_comment
comment|/* Attachment arguments. */
end_comment

begin_struct
struct|struct
name|ioasicdev_attach_args
block|{
name|char
name|iada_modname
index|[
name|TC_ROM_LLEN
index|]
decl_stmt|;
name|tc_offset_t
name|iada_offset
decl_stmt|;
name|tc_addr_t
name|iada_addr
decl_stmt|;
name|void
modifier|*
name|iada_cookie
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ioasic_dev
block|{
name|char
modifier|*
name|iad_modname
decl_stmt|;
name|tc_offset_t
name|iad_offset
decl_stmt|;
name|tc_addr_t
name|iada_addr
decl_stmt|;
name|void
modifier|*
name|iad_cookie
decl_stmt|;
name|u_int32_t
name|iad_intrbits
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|char
modifier|*
name|ioasic_lance_ether_address
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Interrupt establishment/disestablishment functions  */
end_comment

begin_decl_stmt
name|void
name|ioasic_intr_establish
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
name|void
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
name|ioasic_intr_disestablish
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

end_unit

