begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      *	make sure you are editing      *		CONFIG.c      *	editing config.c won't work      */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)CONFIG.c	2.1 (Berkeley) 82/03/31"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	the version of translator      */
end_comment

begin_decl_stmt
name|char
modifier|*
name|version
init|=
literal|"2.1 (VERSION %G%)"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	the location of the error strings      *	and the length of the path to it      *	(in case of execution of pc0 as a.out)      */
end_comment

begin_decl_stmt
name|char
modifier|*
name|err_file
init|=
literal|"LIBDIR/ERRORSTRINGS"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|err_pathlen
init|=
sizeof|sizeof
argument_list|(
literal|"LIBDIR/"
argument_list|)
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
literal|"LIBDIR/HOWFILE\0"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|how_pathlen
init|=
sizeof|sizeof
argument_list|(
literal|"LIBDIR/"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|px_header
init|=
literal|"LIBDIR/px_header"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* px_header's name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|pi_comp
init|=
literal|"INTERPDIR/pi"
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
literal|"INTERPDIR/px"
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
literal|"INTERPDIR/pdx"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the debugger's name */
end_comment

end_unit

