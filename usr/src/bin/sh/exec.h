begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)exec.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* values of cmdtype */
end_comment

begin_define
define|#
directive|define
name|CMDUNKNOWN
value|-1
end_define

begin_comment
comment|/* no entry in table for command */
end_comment

begin_define
define|#
directive|define
name|CMDNORMAL
value|0
end_define

begin_comment
comment|/* command is an executable program */
end_comment

begin_define
define|#
directive|define
name|CMDBUILTIN
value|1
end_define

begin_comment
comment|/* command is a shell builtin */
end_comment

begin_define
define|#
directive|define
name|CMDFUNCTION
value|2
end_define

begin_comment
comment|/* command is a shell function */
end_comment

begin_struct
struct|struct
name|cmdentry
block|{
name|int
name|cmdtype
decl_stmt|;
union|union
name|param
block|{
name|int
name|index
decl_stmt|;
name|union
name|node
modifier|*
name|func
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pathopt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set by padvance */
end_comment

begin_decl_stmt
name|void
name|shellexec
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|padvance
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hashcmd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|find_command
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|cmdentry
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|find_builtin
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|hashcd
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
name|changepath
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|deletefuncs
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
name|getcmdentry
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|cmdentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|addcmdentry
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|cmdentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|defun
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|union
name|node
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unsetfunc
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

