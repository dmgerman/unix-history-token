begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ps.c - fax to postscript */
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
name|rcsid
init|=
literal|"$Header: /f/osi/others/quipu/photo/RCS/ps.c,v 7.1 91/02/22 09:29:24 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/others/quipu/photo/RCS/ps.c,v 7.1 91/02/22 09:29:24 mrose Interim $  *  *  * $Log:	ps.c,v $  * Revision 7.1  91/02/22  09:29:24  mrose  * Interim 6.8  *   * Revision 7.0  91/01/25  11:47:45  mrose  * *** empty log message ***  *   * Revision 1.1  91/01/24  17:03:35  kej  * Initial revision  *   * Revision 1.1  91/01/02  21:36:47  kej  * Initial revision  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<quipu/photo.h>
end_include

begin_define
define|#
directive|define
name|HEIGHT
value|2200
end_define

begin_decl_stmt
specifier|static
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|two_passes
decl_stmt|;
end_decl_stmt

begin_macro
name|photo_start
argument_list|(
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|x
operator|=
literal|0
expr_stmt|;
name|y
operator|=
name|HEIGHT
expr_stmt|;
name|two_passes
operator|=
literal|0
expr_stmt|;
name|puts
argument_list|(
literal|"%!\n0 setlinewidth 72 200 div 72 200 div scale"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|photo_end
argument_list|(
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Decoding has finished - display the image */
if|if
condition|(
name|y
operator|<
name|HEIGHT
condition|)
name|puts
argument_list|(
literal|"showpage"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|photo_black
argument_list|(
argument|length
argument_list|)
end_macro

begin_decl_stmt
name|int
name|length
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|length
operator|>
literal|0
condition|)
name|printf
argument_list|(
literal|"%d %d moveto %d %d lineto stroke\n"
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|x
operator|+
name|length
operator|-
literal|1
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|x
operator|+=
name|length
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|photo_white
argument_list|(
argument|length
argument_list|)
end_macro

begin_decl_stmt
name|int
name|length
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|x
operator|+=
name|length
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|photo_line_end
argument_list|(
argument|line
argument_list|)
end_macro

begin_decl_stmt
name|bit_string
modifier|*
name|line
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|x
operator|=
literal|0
expr_stmt|;
operator|--
name|y
expr_stmt|;
if|if
condition|(
name|y
operator|<
literal|0
condition|)
block|{
name|puts
argument_list|(
literal|"showpage"
argument_list|)
expr_stmt|;
name|y
operator|=
name|HEIGHT
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_block

end_unit

