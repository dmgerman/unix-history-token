begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	everything that should (or must) be declared in the main body  *	of a notefile program. Not all of these get used in all  *	applications, but I thought it good to put them here just in  *	case.  *  *	Ray Essick	December 1981  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|myhome
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mymailer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|myterm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|myeditor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|myshell
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mywrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mypager
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nrows
init|=
literal|24
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of rows on screen */
end_comment

begin_decl_stmt
name|int
name|ncols
init|=
literal|80
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* width of screen */
end_comment

begin_decl_stmt
name|int
name|intflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DEL hit recently */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SYSTEM
init|=
name|Sysname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system name */
end_comment

begin_decl_stmt
name|int
name|msk
init|=
name|NOTESUMASK
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|globuid
init|=
name|ANONUID
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* his true user id */
end_comment

begin_decl_stmt
name|char
modifier|*
name|notesrc
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* users notesrc file */
end_comment

begin_decl_stmt
name|int
name|nindex
init|=
name|NINDEX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of index lines */
end_comment

begin_decl_stmt
name|struct
name|grp
name|group
index|[
name|MAXGROUPS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|last_group
decl_stmt|;
end_decl_stmt

end_unit

