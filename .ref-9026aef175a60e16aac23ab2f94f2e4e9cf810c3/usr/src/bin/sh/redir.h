begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)redir.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* flags passed to redirect */
end_comment

begin_define
define|#
directive|define
name|REDIR_PUSH
value|01
end_define

begin_comment
comment|/* save previous values of file descriptors */
end_comment

begin_define
define|#
directive|define
name|REDIR_BACKQ
value|02
end_define

begin_comment
comment|/* save the command output in memory */
end_comment

begin_union_decl
union_decl|union
name|node
union_decl|;
end_union_decl

begin_decl_stmt
name|void
name|redirect
name|__P
argument_list|(
operator|(
expr|union
name|node
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|popredir
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
name|fd0_redirected_p
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
name|clearredir
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
name|copyfd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

