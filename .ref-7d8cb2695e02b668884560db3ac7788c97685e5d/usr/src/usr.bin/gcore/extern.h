begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)extern.h	5.1 (Berkeley) %G%  */
end_comment

begin_decl_stmt
name|void
name|err
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|md_core
name|__P
argument_list|(
operator|(
name|kvm_t
operator|*
operator|,
name|int
operator|,
expr|struct
name|kinfo_proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

