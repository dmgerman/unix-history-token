begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* t4014.c - display on tetronix 4014 terminals */
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
literal|"$Header: /f/osi/others/quipu/photo/RCS/t4014.c,v 7.0 89/11/23 22:01:47 mrose Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/others/quipu/photo/RCS/t4014.c,v 7.0 89/11/23 22:01:47 mrose Rel $  *  *  * $Log:	t4014.c,v $  * Revision 7.0  89/11/23  22:01:47  mrose  * Release 6.0  *   */
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

begin_include
include|#
directive|include
file|"signal.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|NUMLINES
decl_stmt|,
name|PIC_LINESIZE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|position
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Any errors should be written to *stdout* */
end_comment

begin_comment
comment|/* if the process exits, with out giving an error message, quipu may hang */
end_comment

begin_define
define|#
directive|define
name|SCALE
value|5
end_define

begin_define
define|#
directive|define
name|Y_OFFSET
value|2700
end_define

begin_define
define|#
directive|define
name|X_OFFSET
value|3000
end_define

begin_define
define|#
directive|define
name|X_SKIP
value|8
end_define

begin_decl_stmt
name|int
name|y
init|=
name|Y_OFFSET
decl_stmt|;
end_decl_stmt

begin_macro
name|photo_quit
argument_list|()
end_macro

begin_block
block|{
name|putch
argument_list|(
literal|030
argument_list|)
expr_stmt|;
comment|/* Return to non-graphic mode */
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

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
name|putch
argument_list|(
literal|035
argument_list|)
expr_stmt|;
comment|/* Enter graphic mode */
name|openpl
argument_list|()
expr_stmt|;
name|erase
argument_list|()
expr_stmt|;
name|linemod
argument_list|(
literal|"solid"
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGTERM
argument_list|,
name|photo_quit
argument_list|)
expr_stmt|;
comment|/* return 0 if sucessful -1 if not */
return|return
operator|(
literal|0
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
name|move
argument_list|(
literal|0
argument_list|,
name|Y_OFFSET
operator|-
literal|100
argument_list|)
expr_stmt|;
name|closepl
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"\n"
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
comment|/* this is needed for QUIPU */
comment|/* wait until signalled to Terminate */
for|for
control|(
init|;
condition|;
control|)
empty_stmt|;
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
block|{ }
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
name|line
argument_list|(
operator|(
name|position
operator|*
name|SCALE
operator|)
operator|+
name|X_OFFSET
argument_list|,
name|y
argument_list|,
operator|(
operator|(
name|length
operator|+
name|position
operator|-
literal|1
operator|)
operator|*
name|SCALE
operator|)
operator|+
name|X_OFFSET
argument_list|,
name|y
argument_list|)
expr_stmt|;
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
name|y
operator|-=
name|SCALE
expr_stmt|;
block|}
end_block

end_unit

