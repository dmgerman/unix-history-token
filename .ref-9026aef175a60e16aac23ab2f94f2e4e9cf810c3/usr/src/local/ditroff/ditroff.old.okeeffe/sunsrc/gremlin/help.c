begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#)help.c	1.2	%G%  *  * Routines to provide help screens for the SUN Gremlin picture editor.  *  * Mark Opperman (opcode@monet.BERKELEY)  *  */
end_comment

begin_include
include|#
directive|include
file|<suntool/tool_hs.h>
end_include

begin_include
include|#
directive|include
file|"gremlin.h"
end_include

begin_include
include|#
directive|include
file|"icondata.h"
end_include

begin_comment
comment|/* imports from main.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pixwin
modifier|*
name|pix_pw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rect
name|pix_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pixrect
modifier|*
name|scratch_pr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pixfont
modifier|*
name|text_pf
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern pix_fd;
end_extern

begin_extern
extern|extern menu_fd;
end_extern

begin_extern
extern|extern text_fd;
end_extern

begin_extern
extern|extern tool_fd;
end_extern

begin_comment
comment|/* imports from sun.c */
end_comment

begin_extern
extern|extern get_any_button(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* locals */
end_comment

begin_expr_stmt
specifier|static
name|help_x
operator|,
name|help_y
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* current position on help screen */
end_comment

begin_define
define|#
directive|define
name|help_dy
value|(text_pf->pf_defaultsize.y)
end_define

begin_define
define|#
directive|define
name|HELP_LEFT
value|8
end_define

begin_define
define|#
directive|define
name|HELP_SKIP
value|16
end_define

begin_comment
comment|/*  * Display a help screen consisting of a pixrect, a title and some text.  * The current picture is saved in the scratch pixrect before displaying  * the help screen.  After the user presses a mouse button, the picture  * is restored and processing continues.  */
end_comment

begin_expr_stmt
specifier|static
name|help_screen
argument_list|(
argument|icon_pr
argument_list|,
argument|title
argument_list|,
argument|text
argument_list|)
expr|struct
name|pixrect
operator|*
name|icon_pr
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|title
decl_stmt|,
modifier|*
name|text
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* save current display */
name|pw_read
argument_list|(
name|scratch_pr
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|pix_size
operator|.
name|r_width
argument_list|,
name|pix_size
operator|.
name|r_height
argument_list|,
name|PIX_SRC
argument_list|,
name|pix_pw
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* clear picture subwindow before help screen display */
name|pw_writebackground
argument_list|(
name|pix_pw
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|2000
argument_list|,
literal|2000
argument_list|,
name|PIX_SRC
argument_list|)
expr_stmt|;
name|help_x
operator|=
name|HELP_LEFT
expr_stmt|;
name|help_y
operator|=
literal|8
expr_stmt|;
comment|/* display icon if not a NULL pointer */
if|if
condition|(
name|icon_pr
operator|!=
name|NULL
condition|)
block|{
name|pw_write
argument_list|(
name|pix_pw
argument_list|,
name|help_x
argument_list|,
name|help_y
argument_list|,
name|icon_pr
operator|->
name|pr_size
operator|.
name|x
argument_list|,
name|icon_pr
operator|->
name|pr_size
operator|.
name|y
argument_list|,
name|PIX_SRC
argument_list|,
name|icon_pr
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|help_x
operator|+=
name|icon_pr
operator|->
name|pr_size
operator|.
name|x
operator|+
name|HELP_SKIP
expr_stmt|;
name|help_message
argument_list|(
name|title
argument_list|)
expr_stmt|;
name|help_y
operator|+=
name|icon_pr
operator|->
name|pr_size
operator|.
name|y
operator|+
name|HELP_SKIP
expr_stmt|;
block|}
else|else
block|{
name|help_message
argument_list|(
name|title
argument_list|)
expr_stmt|;
name|help_y
operator|+=
name|help_dy
operator|+
name|HELP_SKIP
expr_stmt|;
block|}
name|help_x
operator|=
name|HELP_LEFT
expr_stmt|;
name|help_message
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|help_y
operator|+=
name|HELP_SKIP
expr_stmt|;
name|help_x
operator|=
name|HELP_LEFT
expr_stmt|;
name|help_message
argument_list|(
literal|"Press a mouse button to continue."
argument_list|)
expr_stmt|;
comment|/* wait for mouse button in any subwindow or tool border */
name|get_any_button
argument_list|()
expr_stmt|;
comment|/* restore picture subwindow */
name|pw_write
argument_list|(
name|pix_pw
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|pix_size
operator|.
name|r_width
argument_list|,
name|pix_size
operator|.
name|r_height
argument_list|,
name|PIX_SRC
argument_list|,
name|scratch_pr
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * A simple text display tool for help messages.  * Text is displayed at the current help location (help_x, help_y).  * Newlines within the text string are handled appropriately.  * Maximum line length (between newlines) is 80 characters, although   * only about 64 can be displayed on the default Gremlin screen.  */
end_comment

begin_expr_stmt
specifier|static
name|help_message
argument_list|(
argument|text
argument_list|)
name|char
operator|*
name|text
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|char
name|buf
index|[
literal|80
index|]
decl_stmt|;
specifier|register
name|i
expr_stmt|;
while|while
condition|(
operator|*
name|text
operator|!=
literal|'\0'
condition|)
block|{
name|i
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
operator|*
name|text
operator|!=
literal|'\n'
operator|)
operator|&&
operator|(
operator|*
name|text
operator|!=
literal|'\0'
operator|)
condition|)
name|buf
index|[
name|i
operator|++
index|]
operator|=
operator|*
name|text
operator|++
expr_stmt|;
name|buf
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
operator|*
name|text
operator|==
literal|'\n'
condition|)
name|text
operator|++
expr_stmt|;
name|pw_text
argument_list|(
name|pix_pw
argument_list|,
name|help_x
argument_list|,
name|help_y
operator|+
name|TEXT_BASELINE
operator|+
literal|2
argument_list|,
name|PIX_SRC
argument_list|,
name|text_pf
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|help_y
operator|+=
name|help_dy
expr_stmt|;
block|}
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|help_HELP
index|[]
init|=
literal|"\ The three subwindows in Gremlin are used for text entry,\n\ menu display and command selection, and picture display.\n\ In addition, the normal tool manager pop-up menu is available\n\ from the tool borders.\n\ \n\ In the menu subwindow, the left mouse button is used to\n\ invoke commands after selecting the appropriate icon, the\n\ middle mouse button is used to effect the same command on\n\ only the current set (where appropriate), and the right mouse\n\ button provides a help screen for the icon.\n\ \n\ In the picture subwindow, the left mouse button is used to\n\ lay down points, the middle mouse button erases points in the\n\ opposite order from which they were layed down, and the right\n\ mouse button provides a help screen.\n\ \n\ In the text subwindow, command arguments (when required)\n\ are entered from the keyboard.  Arguments must be entered\n\ before the command is selected.  Simple editing commands\n\ (backspace, line and word delete) can be used to modify the\n\ argument.  Again, the right mouse button provides a help\n\ screen display."
decl_stmt|;
end_decl_stmt

begin_macro
name|help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|question_pr
argument_list|,
literal|"Help ('?')"
argument_list|,
name|help_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|justify_HELP
index|[]
init|=
literal|"\ Select text justification by moving marker to one of nine\n\ positioning points within the JUSTIFY icon and pressing the\n\ left mouse button.\n\ \n\ Modify justification of text in the current set by moving the\n\ marker as above and then pressing the middle mouse button.\n\ \n\ When text is displayed in the current set, its justification\n\ mode is indicated by a small dot."
decl_stmt|;
end_decl_stmt

begin_macro
name|justify_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|justify_pr
argument_list|,
literal|"Text Justification"
argument_list|,
name|justify_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|size1_HELP
index|[]
init|=
literal|"\n\ Set the default font size to one with the left mouse button.\n\ \n\ Modify text in the current set to size one with the middle\n\ mouse button."
decl_stmt|;
end_decl_stmt

begin_macro
name|size1_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|size1_pr
argument_list|,
literal|"Set Text Size One"
argument_list|,
name|size1_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|roman_HELP
index|[]
init|=
literal|"\ Set the default font to Roman with the left mouse button.\n\ \n\ Modify text in the current set to Roman font with the middle\n\ mouse button."
decl_stmt|;
end_decl_stmt

begin_macro
name|roman_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|roman_pr
argument_list|,
literal|"Set Roman Text Font"
argument_list|,
name|roman_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|scale_HELP
index|[]
init|=
literal|"\ Scaling uses three points to define a transformation.\n\ The current set is scaled by the ratio of the distances\n\ between the first and second and the first and third points."
decl_stmt|;
end_decl_stmt

begin_macro
name|scale_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|scale_pr
argument_list|,
literal|"Scale Current Set ('s')"
argument_list|,
name|scale_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|move_HELP
index|[]
init|=
literal|"\ Translation uses two points to define a transformation.\n\ The current set is translated through the relative distance\n\ between the two points."
decl_stmt|;
end_decl_stmt

begin_macro
name|move_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|move_pr
argument_list|,
literal|"Translate Current Set ('t')"
argument_list|,
name|move_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|hmirror_HELP
index|[]
init|=
literal|"\ Mirroring uses one point to define a transformation.\n\ The current set is reflected about the horizontal line\n\ containing the point."
decl_stmt|;
end_decl_stmt

begin_macro
name|hmirror_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|hmirror_pr
argument_list|,
literal|"Horizontal Mirror"
argument_list|,
name|hmirror_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|vmirror_HELP
index|[]
init|=
literal|"\ Mirroring uses one point to define a transformation.\n\ The current set is reflected about the vertical line\n\ containing the point."
decl_stmt|;
end_decl_stmt

begin_macro
name|vmirror_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|vmirror_pr
argument_list|,
literal|"Vertical Mirror"
argument_list|,
name|vmirror_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|include_HELP
index|[]
init|=
literal|"\ The current set is selected by points.  Using the left mouse\n\ button, the current set will include ONLY those elements near\n\ the points.  With the middle mouse button, those elements near\n\ the points will be ADDED to the current set."
decl_stmt|;
end_decl_stmt

begin_macro
name|include_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|include_pr
argument_list|,
literal|"Define Current Set ('d')"
argument_list|,
name|include_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|put_HELP
index|[]
init|=
literal|"\ The current set is copied into the specified set buffer for\n\ possible later retrieval.  An optional positioning point may\n\ be specified for use in positioning the set when it is later\n\ copied into a picture.  With no positioning point specified,\n\ a point is selected from among the reference points of the\n\ current set."
decl_stmt|;
end_decl_stmt

begin_macro
name|put1_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|put1_pr
argument_list|,
literal|"Save Current Set in Buffer One ('1')"
argument_list|,
name|put_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|put2_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|put2_pr
argument_list|,
literal|"Save Current Set in Buffer Two ('2')"
argument_list|,
name|put_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|put3_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|put3_pr
argument_list|,
literal|"Save Current Set in Buffer Three ('3')"
argument_list|,
name|put_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|put4_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|put4_pr
argument_list|,
literal|"Save Current Set in Buffer Four ('4')"
argument_list|,
name|put_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|horizontal_HELP
index|[]
init|=
literal|"\ Horizontal adjustment forces each point laid down to lie on\n\ a horizontal line from the previous point.  The left mouse\n\ button toggles this drawing mode."
decl_stmt|;
end_decl_stmt

begin_macro
name|horizontal_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|horizontal_pr
argument_list|,
literal|"Horizontal Adjustment"
argument_list|,
name|horizontal_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|vertical_HELP
index|[]
init|=
literal|"\ Vertical adjustment forces each point laid down to lie on a\n\ vertical line from the previous point.  The left mouse button\n\ toggles this drawing mode."
decl_stmt|;
end_decl_stmt

begin_macro
name|vertical_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|vertical_pr
argument_list|,
literal|"Vertical Adjustment"
argument_list|,
name|vertical_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|stipple_HELP
index|[]
init|=
literal|"\ Select the stipple pattern used for drawing polygons with\n\ the left mouse button.\n\ \n\ Modify polygons in the current set to the specified stipple\n\ pattern with the middle mouse button."
decl_stmt|;
end_decl_stmt

begin_macro
name|stipple1_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|white_pr
argument_list|,
literal|"Set Stipple Pattern One"
argument_list|,
name|stipple_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|stipple2_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|gray_pr
argument_list|,
literal|"Set Stipple Pattern Two"
argument_list|,
name|stipple_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|stipple3_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|_50_pr
argument_list|,
literal|"Set Stipple Pattern Three"
argument_list|,
name|stipple_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|stipple4_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|black_pr
argument_list|,
literal|"Set Stipple Pattern Four"
argument_list|,
name|stipple_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|stipple5_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|stipple5_pr
argument_list|,
literal|"Set Stipple Pattern Five"
argument_list|,
name|stipple_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|stipple6_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|stipple6_pr
argument_list|,
literal|"Set Stipple Pattern Six"
argument_list|,
name|stipple_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|stipple7_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|stipple7_pr
argument_list|,
literal|"Set Stipple Pattern Seven"
argument_list|,
name|stipple_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|stipple8_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|stipple8_pr
argument_list|,
literal|"Set Stipple Pattern Eight"
argument_list|,
name|stipple_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|size2_HELP
index|[]
init|=
literal|"\n\ Set the default font size to two with the left mouse button.\n\ \n\ Modify text in the current set to size two with the middle\n\ mouse button."
decl_stmt|;
end_decl_stmt

begin_macro
name|size2_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|size2_pr
argument_list|,
literal|"Set Text Size Two"
argument_list|,
name|size2_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|italics_HELP
index|[]
init|=
literal|"\ Set the default font to Italics with the left mouse button.\n\ \n\ Modify text in the current set to Italics font with the middle\n\ mouse button."
decl_stmt|;
end_decl_stmt

begin_macro
name|italics_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|italics_pr
argument_list|,
literal|"Set Italics Text Font"
argument_list|,
name|italics_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|copy_HELP
index|[]
init|=
literal|"\ Copying uses two or more points.  A copy of the current set\n\ is made and translated by a relative distance between the\n\ first and each additional point.  The last copy becomes\n\ the new current set."
decl_stmt|;
end_decl_stmt

begin_macro
name|copy_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|copy_pr
argument_list|,
literal|"Copy Current Set ('c')"
argument_list|,
name|copy_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|erase_HELP
index|[]
init|=
literal|"\ The current set is erased.  See also the undo command."
decl_stmt|;
end_decl_stmt

begin_macro
name|erase_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|erase_pr
argument_list|,
literal|"Erase Current Set ('e')"
argument_list|,
name|erase_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|movepoint_HELP
index|[]
init|=
literal|"\ This command uses one or more points.  The element of the\n\ current set which contains the point closest to the first of\n\ these points is redrawn with that point replaced by the\n\ remaining points, or deleted if there is only one point."
decl_stmt|;
end_decl_stmt

begin_macro
name|movepoint_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|movepoint_pr
argument_list|,
literal|"Move Point"
argument_list|,
name|movepoint_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|rotate_HELP
index|[]
init|=
literal|"\ Three points are used to define a rotation.  The rotation is\n\ performed relative to the first point, through an angle formed\n\ by the lines between points one and two and points one and\n\ three, respectively."
decl_stmt|;
end_decl_stmt

begin_macro
name|rotate_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|rotate_pr
argument_list|,
literal|"Rotate Current Set ('r')"
argument_list|,
name|rotate_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|filecabinet_HELP
index|[]
init|=
literal|"\ This icon produces a pop-up menu to select commands for\n\ manipulating files: Edit, Path, Read, Write and Save Set.\n\ With each command, parameters should be specified in the\n\ text subwindow before invocation.\n\ \n\ The Edit command causes a new file to be opened for editing.\n\ Picture sets saved in the buffers are preserved across edits.\n\ The file name will be displayed in the Gremlin tool border.\n\ \n\ The Path command is used to set the directory search path\n\ for the Edit and Read commands.  Directory names should be\n\ separated by colons and may include the ~ notation.  If a file\n\ cannot be found using any of the paths, a final check will be\n\ made in the Gremlin library, /usr/local/lib/gremlin.\n\ \n\ The Read command is used to add elements from the specified\n\ file into the current picture.  The new elements become the\n\ current set.  A point may be specified to position the file\n\ in the picture.\n\ \n\ The Write command saves the entire picture in a file.  If no\n\ file name is specified in the text subwindow, the current Edit\n\ file name is used.  An optional point may be specified to aid\n\ in Reading the picture later.\n\ \n\ The Save Set command is similar to the Write command with two\n\ exceptions: only the current set is written, and a file name\n\ must be specified."
decl_stmt|;
end_decl_stmt

begin_macro
name|filecabinet_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|filecabinet_pr
argument_list|,
literal|"File Commands"
argument_list|,
name|filecabinet_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|boxinc_HELP
index|[]
init|=
literal|"\ Two points must be placed that define a rectangular area\n\ (the endpoints of the diagonal of the rectangle).\n\ \n\ With the left mouse button, all elements contained within the\n\ the rectangle become the current set.\n\ \n\ With the middle mouse button, those same elements are ADDED\n\ to the current set."
decl_stmt|;
end_decl_stmt

begin_macro
name|boxinc_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|boxinc_pr
argument_list|,
literal|"Select Area for Current Set ('f')"
argument_list|,
name|boxinc_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|manhattan_HELP
index|[]
init|=
literal|"\ Manhattan adjustment forces each point laid down to be either\n\ directly horizontal or vertical with respect to the previous\n\ point, whichever it is closer to.  The left mouse button\n\ toggles this drawing mode."
decl_stmt|;
end_decl_stmt

begin_macro
name|manhattan_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|horvert_pr
argument_list|,
literal|"Manhattan Adjustment ('z')"
argument_list|,
name|manhattan_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|gravity_HELP
index|[]
init|=
literal|"\ This command toggles each time it is selected.  When on,\n\ gravity forces a point to coincide with the nearest existing\n\ point or reference point.  It will only take affect, however,\n\ if the point is near enough to an element to be gravitiated\n\ to it."
decl_stmt|;
end_decl_stmt

begin_macro
name|gravity_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|gravity_pr
argument_list|,
literal|"Set Gravity ('g')"
argument_list|,
name|gravity_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|size3_HELP
index|[]
init|=
literal|"\n\ Set the default font size to three with the left mouse button.\n\ \n\ Modify text in the current set to size three with the middle\n\ mouse button."
decl_stmt|;
end_decl_stmt

begin_macro
name|size3_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|size3_pr
argument_list|,
literal|"Set Text Size Three"
argument_list|,
name|size3_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|bold_HELP
index|[]
init|=
literal|"\ Set the default font to Bold with the left mouse button.\n\ \n\ Modify text in the current set to Bold font with the middle\n\ mouse button."
decl_stmt|;
end_decl_stmt

begin_macro
name|bold_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|bold_pr
argument_list|,
literal|"Set Bold Text Font"
argument_list|,
name|bold_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|brush_HELP
index|[]
init|=
literal|"\ The left mouse button sets the current brush style.\n\ \n\ The middle mouse button modifies all elements in the current\n\ set (except text) to the selected brush style."
decl_stmt|;
end_decl_stmt

begin_macro
name|brush1_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|dotted_pr
argument_list|,
literal|"Set Dotted Line Style"
argument_list|,
name|brush_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|brush2_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|broken_pr
argument_list|,
literal|"Set Broken Line Style"
argument_list|,
name|brush_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|brush3_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|thick_pr
argument_list|,
literal|"Set Thick Line Style"
argument_list|,
name|brush_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|brush4_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|dashed_pr
argument_list|,
literal|"Set Dashed Line Style"
argument_list|,
name|brush_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|brush5_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|narrow_pr
argument_list|,
literal|"Set Narrow Line Style"
argument_list|,
name|brush_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|brush6_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|medium_pr
argument_list|,
literal|"Set Medium Line Style"
argument_list|,
name|brush_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|arrow_HELP
index|[]
init|=
literal|"\ This command requires two points.  The first point indicates\n\ the tip of the arrow.  The second point indicates the\n\ direction from which the arrow points."
decl_stmt|;
end_decl_stmt

begin_macro
name|arrow_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|arrow_pr
argument_list|,
literal|"Draw Arrowhead ('w')"
argument_list|,
name|arrow_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|text_HELP
index|[]
init|=
literal|"\ Text is positioned using one or two points.  If two points\n\ are used, the text is positioned relative to their locus.\n\ The text specified in the text subwindow is displayed using\n\ the current font, size and justification.\n\ \n\ See the text subwindow help display for an explanation of\n\ quick text entry."
decl_stmt|;
end_decl_stmt

begin_macro
name|text_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|text_pr
argument_list|,
literal|"Display Text"
argument_list|,
name|text_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|misc_HELP
index|[]
init|=
literal|"\ This command invokes a pop-up menu of infrequently used\n\ commands: Clear Points, Show Points, Gripe (rarely used)\n\ and Point.\n\ \n\ Clear Points will clear all positioning points and reference\n\ points from the display.\n\ \n\ Show Points will display the reference points of those\n\ elements in the current set.\n\ \n\ Gripe displays a message indicating the mail address of\n\ the current Gremlin maintainer.\n\ \n\ Point can be used to lay down a point at a specific location.\n\ The coordinates of the point must first be entered in the\n\ text subwindow."
decl_stmt|;
end_decl_stmt

begin_macro
name|misc_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|misc_pr
argument_list|,
literal|"Miscellaneous Commands"
argument_list|,
name|misc_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|get_HELP
index|[]
init|=
literal|"\ This command retrieves a set from the specified buffer and\n\ copies it into the picture.  At least one point must be\n\ specified, indicating the position(s) in the picture where\n\ the set is to be copied."
decl_stmt|;
end_decl_stmt

begin_macro
name|get1_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|get1_pr
argument_list|,
literal|"Add Buffer One To Picture"
argument_list|,
name|get_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|get3_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|get3_pr
argument_list|,
literal|"Add Buffer Three To Picture"
argument_list|,
name|get_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|get2_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|get2_pr
argument_list|,
literal|"Add Buffer Two To Picture"
argument_list|,
name|get_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|get4_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|get4_pr
argument_list|,
literal|"Add Buffer Four To Picture"
argument_list|,
name|get_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|linestyle_HELP
index|[]
init|=
literal|"\ This command toggles symbolic line display.  When highlighted,\n\ this icon indicates that elements will be drawn using their\n\ true line style (or brush).  When not highlighted, all\n\ elements are drawn using the narrow brush, decreasing display\n\ times."
decl_stmt|;
end_decl_stmt

begin_macro
name|linestyle_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|linestyle_pr
argument_list|,
literal|"Toggle Line Style Mode"
argument_list|,
name|linestyle_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|align_HELP
index|[]
init|=
literal|"\ This command forces points to be aligned on pixel boundaries\n\ as specified in the icon.  Alignment occurs in powers of two.\n\ To select the next alignment value use the left mouse button,\n\ and to select the previous value use the middle mouse button.\n\ \n\ The precedence of point positioning modifiers is as follows:\n\ gravity will override alignment, and adjustment (vertical,\n\ horizontal or manhattan) will be applied to the point to which\n\ the point has been gravitated."
decl_stmt|;
end_decl_stmt

begin_macro
name|align_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|align_pr
argument_list|,
literal|"Set Point Alignment"
argument_list|,
name|align_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|size4_HELP
index|[]
init|=
literal|"\n\ Set the default font size to four with the left mouse button.\n\ \n\ Modify text in the current set to size four with the middle\n\ mouse button."
decl_stmt|;
end_decl_stmt

begin_macro
name|size4_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|size4_pr
argument_list|,
literal|"Set Text Size Four"
argument_list|,
name|size4_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|special_HELP
index|[]
init|=
literal|"\ Set the default font to Special with the left mouse button.\n\ \n\ Modify text in the current set to Special font with the middle\n\ mouse button."
decl_stmt|;
end_decl_stmt

begin_macro
name|special_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|special_pr
argument_list|,
literal|"Set Special Text Font"
argument_list|,
name|special_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|arc_HELP
index|[]
init|=
literal|"\ This command requires two points to draw a full circle or\n\ three points to draw an arc.  The first point determines the\n\ center of a circle.  The second is a point on the circle,\n\ thus defining the radius.  An optional third point determines\n\ a counter-clockwise angle from the second point which is the\n\ extent of the arc."
decl_stmt|;
end_decl_stmt

begin_macro
name|arc_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|arc_pr
argument_list|,
literal|"Draw Circle or Arc ('a')"
argument_list|,
name|arc_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|curve_HELP
index|[]
init|=
literal|"\ A curve is determined by a number of points distributed along\n\ its trajectory.  Two points yield a straight line.  If the\n\ first and last points of a spline are the same, a smooth\n\ closed figure will be drawn.  Curves are drawn with the left\n\ mouse button using the current brush style.\n\ \n\ With the middle mouse button, vectors and polygons in the\n\ current set are modified to become curves."
decl_stmt|;
end_decl_stmt

begin_macro
name|curve_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|curve_pr
argument_list|,
literal|"Draw Curve ('b')"
argument_list|,
name|curve_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|vector_HELP
index|[]
init|=
literal|"\ With the left mouse button, a line is drawn connecting each\n\ of the points layed down in order.  The current brush (narrow,\n\ dotted, etc) is used.\n\ \n\ With the middle mouse button, curves and polygons in the\n\ current set are modified to become vectors."
decl_stmt|;
end_decl_stmt

begin_macro
name|vector_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|vector_pr
argument_list|,
literal|"Draw Vector ('v')"
argument_list|,
name|vector_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|box_HELP
index|[]
init|=
literal|"\ Two points are used to define the endpoints of the diagonal\n\ of a rectangle.  A box is drawn in the current brush which\n\ forms the rectangle."
decl_stmt|;
end_decl_stmt

begin_macro
name|box_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|box_pr
argument_list|,
literal|"Draw Box ('x')"
argument_list|,
name|box_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|grid_HELP
index|[]
init|=
literal|"\ This command toggles the display of a grid used to aid in\n\ laying down points.  The grid is displayed on 32 pixel\n\ boundaries."
decl_stmt|;
end_decl_stmt

begin_macro
name|grid_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|grid_pr
argument_list|,
literal|"Toggle Grid Display ('q')"
argument_list|,
name|grid_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|littlepoint_HELP
index|[]
init|=
literal|"\ This command toggles the style of points displayed.  When the\n\ icon is highlighted, points are indicated by a small circle\n\ and are numbered from zero.  When the icon is unhighlighted,\n\ points are displayed as a small diamond."
decl_stmt|;
end_decl_stmt

begin_macro
name|littlepoint_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|littlepoint_pr
argument_list|,
literal|"Toggle Point Style"
argument_list|,
name|littlepoint_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|undo_HELP
index|[]
init|=
literal|"\ This command undoes the last command which modified the\n\ picture contents."
decl_stmt|;
end_decl_stmt

begin_macro
name|undo_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|undo_pr
argument_list|,
literal|"Undo Last Command"
argument_list|,
name|undo_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|pan_HELP
index|[]
init|=
literal|"\ With the left mouse button this command requires one point.\n\ The entire picture and current set are translated such that\n\ the specified point is located at the center of the display.\n\ \n\ With the middle mouse button no point is required.  The\n\ picture is translated such that its absolute center is\n\ brought to the center of the display."
decl_stmt|;
end_decl_stmt

begin_macro
name|pan_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|pan_pr
argument_list|,
literal|"Panning"
argument_list|,
name|pan_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|polygon_HELP
index|[]
init|=
literal|"\ Polygons can be drawn either bordered or unbordered.  At\n\ least three points are required to draw a polygon.  If the\n\ first and the last points are not the same, that line\n\ segment will be added automatically.  With the left mouse\n\ button, a filled polygon will be added to the display in the\n\ current stipple style.  If a border is to be drawn, this\n\ will be added in the current line style.\n\ \n\ The middle mouse button is used to modify curves, vectors and\n\ other polygons in the current set to be polygons of the\n\ selected type (bordered or unbordered)."
decl_stmt|;
end_decl_stmt

begin_macro
name|bpolygon_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|bpolygon_pr
argument_list|,
literal|"Fill Bordered Polygon"
argument_list|,
name|polygon_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|polygon_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
operator|&
name|polygon_pr
argument_list|,
literal|"Fill Polygon"
argument_list|,
name|polygon_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|textsw_HELP
index|[]
init|=
literal|"\ Command arguments (when required) are entered here from the\n\ keyboard.  Arguments must be entered before the command is\n\ selected.  Simple editing commands (backspace, line and word\n\ delete) can be used to modify the argument.  The middle mouse\n\ button is used to display the previous text string.\n\ \n\ The quick form of the TEXT command is invoked by pressing\n\ RETURN after entering a string to be displayed in the picture.\n\ The string is displayed at the LAST point layed down (using\n\ the current justification mode), and this point is removed\n\ from the display."
decl_stmt|;
end_decl_stmt

begin_macro
name|textsw_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
name|NULL
argument_list|,
literal|"Text Subwindow Help"
argument_list|,
name|textsw_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|static
name|char
name|pixsw_HELP
index|[]
init|=
literal|"\ The left mouse button is used to lay down points.  The middle\n\ mouse button erases points in the opposite order from which\n\ they were layed down."
decl_stmt|;
end_decl_stmt

begin_macro
name|pixsw_help
argument_list|()
end_macro

begin_block
block|{
name|help_screen
argument_list|(
name|NULL
argument_list|,
literal|"Picture Subwindow Help"
argument_list|,
name|pixsw_HELP
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|menusw_help
argument_list|()
end_macro

begin_block
block|{
comment|/* keeps getting invoked by mistake - not useful anyway */
block|}
end_block

end_unit

