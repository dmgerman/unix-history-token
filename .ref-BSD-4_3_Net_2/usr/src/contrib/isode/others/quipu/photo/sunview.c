begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sunview.c - sunview display process */
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
literal|"$Header: /f/osi/others/quipu/photo/RCS/sunview.c,v 7.2 91/02/22 09:29:25 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/others/quipu/photo/RCS/sunview.c,v 7.2 91/02/22 09:29:25 mrose Interim $  *  *  * $Log:	sunview.c,v $  * Revision 7.2  91/02/22  09:29:25  mrose  * Interim 6.8  *   * Revision 7.1  90/07/09  14:40:30  mrose  * sync  *   * Revision 7.0  89/11/23  22:01:47  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/* sunview display process */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"quipu/photo.h"
end_include

begin_include
include|#
directive|include
file|<suntool/tool_hs.h>
end_include

begin_include
include|#
directive|include
file|<suntool/panel.h>
end_include

begin_include
include|#
directive|include
file|<suntool/gfxsw.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_decl_stmt
specifier|static
name|struct
name|gfxsubwindow
modifier|*
name|gfx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|tool
modifier|*
name|tool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|toolsw
modifier|*
name|gfx_sw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|sx
init|=
literal|20
decl_stmt|,
name|sy
init|=
literal|20
decl_stmt|,
name|x
decl_stmt|,
name|y
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|PIC_LINESIZE
decl_stmt|;
end_decl_stmt

begin_macro
name|sigwinched
argument_list|()
end_macro

begin_block
block|{
name|tool_sigwinch
argument_list|(
name|tool
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
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
comment|/* Initialise a window to recieve a photo of 'name' */
if|if
condition|(
name|getenv
argument_list|(
literal|"WINDOW_PARENT"
argument_list|)
operator|==
operator|(
name|char
operator|*
operator|)
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"PHOTO: Must be running suntools on the console"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
operator|(
name|tool
operator|=
name|tool_make
argument_list|(
name|WIN_LABEL
argument_list|,
name|name
argument_list|,
name|WIN_TOP
argument_list|,
name|sx
argument_list|,
name|WIN_LEFT
argument_list|,
name|sy
argument_list|,
literal|0
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"PHOTO: can't create window"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|signal
argument_list|(
name|SIGWINCH
argument_list|,
name|sigwinched
argument_list|)
expr_stmt|;
name|gfx_sw
operator|=
name|gfxsw_createtoolsubwindow
argument_list|(
name|tool
argument_list|,
literal|""
argument_list|,
name|TOOL_SWEXTENDTOEDGE
argument_list|,
name|TOOL_SWEXTENDTOEDGE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|gfx
operator|=
operator|(
expr|struct
name|gfxsubwindow
operator|*
operator|)
name|gfx_sw
operator|->
name|ts_data
expr_stmt|;
name|gfxsw_getretained
argument_list|(
name|gfx
argument_list|)
expr_stmt|;
name|tool_install
argument_list|(
name|tool
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
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"(See sunview window)"
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
comment|/* return 0 if sucessful -1 if not */
name|tool_set_attributes
argument_list|(
name|tool
argument_list|,
name|WIN_WIDTH
argument_list|,
name|PIC_LINESIZE
operator|+
literal|40
argument_list|,
name|WIN_HEIGHT
argument_list|,
name|sy
operator|+
literal|40
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|tool_select
argument_list|(
name|tool
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
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
name|struct
name|pixrect
modifier|*
name|pix
decl_stmt|;
comment|/* the end of a line has been reached */
comment|/* A bit string is stored in line->dbuf_top */
name|pix
operator|=
name|mem_point
argument_list|(
name|PIC_LINESIZE
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
name|line
operator|->
name|dbuf_top
argument_list|)
expr_stmt|;
name|pw_write
argument_list|(
name|gfx
operator|->
name|gfx_pixwin
argument_list|,
name|sx
argument_list|,
name|sy
argument_list|,
name|PIC_LINESIZE
operator|-
name|sx
argument_list|,
literal|1
argument_list|,
name|PIX_SRC
argument_list|,
name|pix
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sy
operator|++
expr_stmt|;
block|}
end_block

end_unit

