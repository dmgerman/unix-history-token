begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)gdpriv.c	4.3	(Melbourne)	82/07/17	*/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/quota.h>
end_include

begin_include
include|#
directive|include
file|<udata.h>
end_include

begin_include
include|#
directive|include
file|<lpdquota.h>
end_include

begin_include
include|#
directive|include
file|<mushmuck.h>
end_include

begin_decl_stmt
specifier|static
name|char
name|dpprefix
index|[]
init|=
literal|"/usr/adm/defprivs/"
decl_stmt|;
end_decl_stmt

begin_macro
name|gdpriv
argument_list|(
argument|name
argument_list|,
argument|mp
argument_list|,
argument|lp
argument_list|,
argument|dp
argument_list|,
argument|dnp
argument_list|,
argument|up
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mushmuck
modifier|*
name|mp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|lpquota
modifier|*
name|lp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|dquot
modifier|*
name|dp
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|char
argument_list|(
operator|*
name|dnp
argument_list|)
index|[
literal|32
index|]
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|udata
modifier|*
name|up
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|dpfile
index|[
sizeof|sizeof
name|dpprefix
operator|+
literal|128
operator|+
literal|1
index|]
decl_stmt|;
name|strcpy
argument_list|(
name|dpfile
argument_list|,
name|dpprefix
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|dpfile
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return
operator|(
name|rdprivf
argument_list|(
name|dpfile
argument_list|,
name|mp
argument_list|,
name|lp
argument_list|,
name|dp
argument_list|,
name|dnp
argument_list|,
name|up
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

