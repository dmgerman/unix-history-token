begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)getdev.h	5.1 (Berkeley) %G%  */
end_comment

begin_decl_stmt
name|void
name|getdev
name|__P
argument_list|(
operator|(
name|u_long
name|alldevs
operator|,
name|int
argument_list|(
operator|*
name|match
argument_list|)
argument_list|(
expr|struct
name|device
operator|*
argument_list|)
operator|,
name|void
argument_list|(
operator|*
name|add
argument_list|)
argument_list|(
name|u_long
argument_list|,
expr|struct
name|device
operator|*
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

