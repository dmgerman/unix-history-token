begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      *	make sure you are editing      *		CONFIG.c      *	editing config.c won't work      */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)CONFIG.c	2.7 (Berkeley) 84/02/08"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*      *	the version of translator      */
end_comment

begin_decl_stmt
name|char
modifier|*
name|version
init|=
literal|"3.1 (2/8/84)"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	the location of the error strings      *	and the length of the path to it      *	(in case of execution as a.something)      */
end_comment

begin_decl_stmt
name|char
modifier|*
name|err_file
init|=
literal|"/usr/lib/pi3.1strings"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|err_pathlen
init|=
sizeof|sizeof
argument_list|(
literal|"/usr/lib/"
argument_list|)
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	the location of the short explanation      *	and the length of the path to it      *	the null at the end is so pix can change it to pi'x' from pi.      */
end_comment

begin_decl_stmt
name|char
modifier|*
name|how_file
init|=
literal|"/usr/lib/how_pi\0"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|how_pathlen
init|=
sizeof|sizeof
argument_list|(
literal|"/usr/lib/"
argument_list|)
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	things about the interpreter.      *	these are not used by the compiler.      */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PC
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|px_header
init|=
literal|"/usr/lib/px_header"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* px_header's name */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PXP
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|pi_comp
init|=
literal|"/usr/ucb/pi"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the compiler's name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|px_intrp
init|=
literal|"/usr/ucb/px"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the interpreter's name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|px_debug
init|=
literal|"/usr/ucb/pdx"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the debugger's name */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

