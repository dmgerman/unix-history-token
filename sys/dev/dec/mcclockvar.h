begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: mcclockvar.h,v 1.4 1997/06/22 08:02:19 jonathan Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_struct
struct|struct
name|mcclock_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
specifier|const
name|struct
name|mcclock_busfns
modifier|*
name|sc_busfns
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mcclock_busfns
block|{
name|void
argument_list|(
argument|*mc_bf_write
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mcclock_softc
operator|*
operator|,
name|u_int
operator|,
name|u_int
operator|)
argument_list|)
expr_stmt|;
name|u_int
argument_list|(
argument|*mc_bf_read
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mcclock_softc
operator|*
operator|,
name|u_int
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|mcclock_attach
name|__P
argument_list|(
operator|(
expr|struct
name|mcclock_softc
operator|*
operator|,
specifier|const
expr|struct
name|mcclock_busfns
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

