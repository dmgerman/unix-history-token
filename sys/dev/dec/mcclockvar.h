begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: mcclockvar.h,v 1.4 1997/06/22 08:02:19 jonathan Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_include
include|#
directive|include
file|"mcclock_if.h"
end_include

begin_function_decl
name|void
name|mcclock_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mcclock_init
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mcclock_get
parameter_list|(
name|device_t
parameter_list|,
name|time_t
parameter_list|,
name|struct
name|clocktime
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mcclock_set
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|clocktime
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mcclock_getsecs
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
modifier|*
name|secp
parameter_list|)
function_decl|;
end_function_decl

end_unit

