begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)tftpsubs.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Prototypes for read-ahead/write-behind subroutines for tftp user and  * server.  */
end_comment

begin_decl_stmt
name|struct
name|tftphdr
modifier|*
name|r_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_ahead
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|readit
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
expr|struct
name|tftphdr
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|synchnet
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tftphdr
modifier|*
name|w_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|write_behind
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|writeit
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
expr|struct
name|tftphdr
operator|*
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

