begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)tprintf.h	8.1 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|session
modifier|*
name|tpr_t
typedef|;
end_typedef

begin_decl_stmt
name|tpr_t
name|tprintf_open
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tprintf_close
name|__P
argument_list|(
operator|(
name|tpr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tprintf
name|__P
argument_list|(
operator|(
name|tpr_t
operator|,
specifier|const
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

