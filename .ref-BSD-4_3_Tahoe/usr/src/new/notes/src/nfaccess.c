begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|MAINLINE
end_define

begin_include
include|#
directive|include
file|"parms.h"
end_include

begin_include
include|#
directive|include
file|"structs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RCSIDENT
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Header: nfaccess.c,v 1.7 85/01/18 15:40:27 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	This program works sort of chmod by adding/deleting  *	permissions to the specified access lists.  *  *	Any normal user can run this program. It only allows changes  *	to notesfiles the user is a director in.  *  *	Ray Essick		February 1984  */
end_comment

begin_define
define|#
directive|define
name|MAXADD
value|1
end_define

begin_comment
comment|/* simultaneous adds */
end_comment

begin_decl_stmt
name|struct
name|perm_f
name|Newmodes
index|[
name|MAXADD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* inserted modes */
end_comment

begin_decl_stmt
specifier|static
name|int
name|nmodes
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* active slots */
end_comment

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_function_decl
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwnam
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|group
modifier|*
name|getgrnam
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|struct
name|io_f
name|io
decl_stmt|;
name|int
name|argn
decl_stmt|;
name|struct
name|nflist_f
modifier|*
name|nfptr
decl_stmt|;
name|startup
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
comment|/* common init code */
if|if
condition|(
name|parsemode
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
operator|&
name|Newmodes
index|[
name|nmodes
operator|++
index|]
argument_list|,
literal|1
argument_list|)
condition|)
comment|/* grab a mode */
block|{
name|usage
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|/* incorrect */
block|}
for|for
control|(
name|argn
operator|=
literal|2
init|;
name|argn
operator|<
name|argc
condition|;
name|argn
operator|++
control|)
block|{
name|expand
argument_list|(
name|argv
index|[
name|argn
index|]
argument_list|)
expr_stmt|;
comment|/* load it */
block|}
while|while
condition|(
operator|(
name|nfptr
operator|=
name|nextgroup
argument_list|()
operator|)
operator|!=
operator|(
expr|struct
name|nflist_f
operator|*
operator|)
name|NULL
condition|)
block|{
if|if
condition|(
name|init
argument_list|(
operator|&
name|io
argument_list|,
name|nfptr
operator|->
name|nf_name
argument_list|)
operator|<
literal|0
condition|)
comment|/* open */
block|{
name|printf
argument_list|(
literal|"%s:	couldn't open\n"
argument_list|,
name|nfptr
operator|->
name|nf_name
argument_list|)
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
operator|!
name|allow
argument_list|(
operator|&
name|io
argument_list|,
name|DRCTOK
argument_list|)
condition|)
comment|/* a director? */
block|{
name|printf
argument_list|(
literal|"%s:	Not a director\n"
argument_list|,
name|nfptr
operator|->
name|nf_name
argument_list|)
expr_stmt|;
name|closenf
argument_list|(
operator|&
name|io
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|addmodes
argument_list|(
operator|&
name|io
argument_list|,
name|nmodes
argument_list|,
operator|&
name|Newmodes
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* add permissions */
name|closenf
argument_list|(
operator|&
name|io
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* all done */
block|}
end_function

begin_macro
name|usage
argument_list|(
argument|name
argument_list|)
end_macro

begin_comment
comment|/* how to invoke */
end_comment

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Usage: %s<permission><notesfile> [<notesfile>...]\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

