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

begin_function_decl
name|char
modifier|*
name|ioasic_lance_ether_address
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Interrupt establishment/disestablishment functions  */
end_comment

begin_function_decl
name|void
name|ioasic_intr_establish
parameter_list|(
name|device_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|tc_intrlevel_t
parameter_list|,
name|void
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
name|ioasic_intr_disestablish
parameter_list|(
name|device_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

