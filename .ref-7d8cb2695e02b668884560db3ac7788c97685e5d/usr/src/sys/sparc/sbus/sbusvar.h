begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)sbusvar.h	7.3 (Berkeley) %G%  *  * from: $Header: sbusvar.h,v 1.6 92/11/26 02:28:14 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * S-bus variables.  */
end_comment

begin_struct
struct|struct
name|sbusdev
block|{
name|struct
name|device
modifier|*
name|sd_dev
decl_stmt|;
comment|/* backpointer to generic */
name|struct
name|sbusdev
modifier|*
name|sd_bchain
decl_stmt|;
comment|/* forward link in bus chain */
name|void
argument_list|(
argument|*sd_reset
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Sbus driver attach arguments.  */
end_comment

begin_struct
struct|struct
name|sbus_attach_args
block|{
name|struct
name|romaux
name|sa_ra
decl_stmt|;
comment|/* name, node, addr, etc */
name|int
name|sa_slot
decl_stmt|;
comment|/* Sbus slot number */
name|int
name|sa_offset
decl_stmt|;
comment|/* offset within slot */
block|}
struct|;
end_struct

begin_comment
comment|/* variables per Sbus */
end_comment

begin_struct
struct|struct
name|sbus_softc
block|{
name|struct
name|device
name|sc_dev
decl_stmt|;
comment|/* base device */
name|int
name|sc_clockfreq
decl_stmt|;
comment|/* clock frequency (in Hz) */
name|struct
name|sbusdev
modifier|*
name|sc_sbdev
decl_stmt|;
comment|/* list of all children */
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|sbusdev_match
name|__P
argument_list|(
operator|(
expr|struct
name|cfdata
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sbus_establish
name|__P
argument_list|(
operator|(
expr|struct
name|sbusdev
operator|*
operator|,
expr|struct
name|device
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

