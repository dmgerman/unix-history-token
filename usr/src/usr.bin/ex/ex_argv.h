begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1980 Regents of the University of California */
end_comment

begin_comment
comment|/* sccs id:	@(#)ex_argv.h	4.2 %G%  */
end_comment

begin_comment
comment|/*  * The current implementation of the argument list is poor,  * using an argv even for internally done "next" commands.  * It is not hard to see that this is restrictive and a waste of  * space.  The statically allocated glob structure could be replaced  * by a dynamically allocated argument area space.  */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|args
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|args0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|argc0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|morargc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used with "More files to edit..." */
end_comment

begin_decl_stmt
name|int
name|firstln
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From +lineno */
end_comment

begin_decl_stmt
name|char
modifier|*
name|firstpat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* From +/pat	*/
end_comment

begin_comment
comment|/* Yech... */
end_comment

begin_struct
struct|struct
name|glob
block|{
name|short
name|argc
decl_stmt|;
comment|/* Index of current file in argv */
name|short
name|argc0
decl_stmt|;
comment|/* Number of arguments in argv */
name|char
modifier|*
name|argv
index|[
name|NARGS
operator|+
literal|1
index|]
decl_stmt|;
comment|/* WHAT A WASTE! */
name|char
name|argspac
index|[
name|NCARGS
operator|+
sizeof|sizeof
argument_list|(
name|int
argument_list|)
index|]
decl_stmt|;
block|}
name|frob
struct|;
end_struct

end_unit

