begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)select.h	8.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SELECT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SELECT_H_
end_define

begin_comment
comment|/*  * Used to maintain information about processes that wish to be  * notified when I/O becomes possible.  */
end_comment

begin_struct
struct|struct
name|selinfo
block|{
name|pid_t
name|si_pid
decl_stmt|;
comment|/* process to be notified */
name|short
name|si_flags
decl_stmt|;
comment|/* see below */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SI_COLL
value|0x0001
end_define

begin_comment
comment|/* collision occurred */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|selrecord
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|selector
operator|,
expr|struct
name|selinfo
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|selwakeup
name|__P
argument_list|(
operator|(
expr|struct
name|selinfo
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SELECT_H_ */
end_comment

end_unit

