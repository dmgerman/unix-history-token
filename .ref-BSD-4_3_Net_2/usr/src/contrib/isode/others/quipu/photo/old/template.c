begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* template.c - template for display processes */
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
literal|"$Header: /f/osi/others/quipu/photo/RCS/template.c,v 7.0 89/11/23 22:01:48 mrose Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/others/quipu/photo/RCS/template.c,v 7.0 89/11/23 22:01:48 mrose Rel $  *  *  * $Log:	template.c,v $  * Revision 7.0  89/11/23  22:01:48  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_include
include|#
directive|include
file|"quipu/photo.h"
end_include

begin_comment
comment|/* Any errors should be written to *stdout* */
end_comment

begin_comment
comment|/* if the process exits, with out giving an error message, quipu may hang */
end_comment

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
comment|/* Initialise a window to recieve a photo of 'name' */
comment|/* return 0 if sucessful -1 if not */
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"PHOTO: not implemented yet"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
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
comment|/* Decoding has finished - display the photo */
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"done it"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|close
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* this is needed for QUIPU if the process does not exit */
comment|/* return 0 if sucessful -1 if not */
return|return
operator|(
operator|-
literal|1
operator|)
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
comment|/* draw a black line of 'length' pixels */
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
comment|/* draw a white line of 'length' pixels */
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
comment|/* the end of a line has been reached */
comment|/* A bit string is stored in line->dbuf_top */
block|}
end_block

end_unit

