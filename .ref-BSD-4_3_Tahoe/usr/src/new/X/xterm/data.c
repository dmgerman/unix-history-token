begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Source: /u1/X/xterm/RCS/data.c,v $  *	$Header: data.c,v 10.102 86/12/01 17:12:39 swick Rel $  */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<X/Xlib.h>
end_include

begin_include
include|#
directive|include
file|"scrollbar.h"
end_include

begin_include
include|#
directive|include
file|"ptyx.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccs_id
index|[]
init|=
literal|"@(#)data.c\tX10/6.6B\t12/26/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_decl_stmt
name|Vertex
name|T_boxlarge
index|[
name|NBOX
index|]
init|=
block|{
block|{
literal|0
block|,
literal|0
block|,
name|VertexDontDraw
block|}
block|,
block|{
literal|8
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
literal|14
block|,
name|VertexRelative
block|}
block|,
block|{
operator|-
literal|8
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
operator|-
literal|14
block|,
name|VertexRelative
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Vertex
name|T_box2
index|[
name|NBOX
index|]
init|=
block|{
block|{
literal|0
block|,
literal|0
block|,
name|VertexDontDraw
block|}
block|,
block|{
literal|7
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
literal|12
block|,
name|VertexRelative
block|}
block|,
block|{
operator|-
literal|7
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
operator|-
literal|12
block|,
name|VertexRelative
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Vertex
name|T_box3
index|[
name|NBOX
index|]
init|=
block|{
block|{
literal|0
block|,
literal|0
block|,
name|VertexDontDraw
block|}
block|,
block|{
literal|5
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
literal|12
block|,
name|VertexRelative
block|}
block|,
block|{
operator|-
literal|5
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
operator|-
literal|12
block|,
name|VertexRelative
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Vertex
name|T_boxsmall
index|[
name|NBOX
index|]
init|=
block|{
block|{
literal|0
block|,
literal|0
block|,
name|VertexDontDraw
block|}
block|,
block|{
literal|5
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
literal|9
block|,
name|VertexRelative
block|}
block|,
block|{
operator|-
literal|5
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
operator|-
literal|9
block|,
name|VertexRelative
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Vertex
name|T_boxicon
index|[
name|NBOX
index|]
init|=
block|{
comment|/* is filled-in in TekInit() */
block|{
literal|0
block|,
literal|0
block|,
name|VertexDontDraw
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
name|VertexRelative
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|jmp_buf
name|Tekend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Tbcnt
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Tbuffer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Tbptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TekLink
modifier|*
name|TekRefresh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Tpushb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Tpushback
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Ttoggled
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bcnt
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|buffer
index|[
name|BUF_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|bptr
init|=
name|buffer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|jmp_buf
name|VTend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Vertex
name|VTbox
index|[
name|NBOX
index|]
init|=
block|{
block|{
literal|0
block|,
literal|0
block|,
name|VertexDontDraw
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
name|VertexRelative
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Vertex
name|status_box
index|[
name|NBOX
index|]
init|=
block|{
block|{
literal|0
block|,
literal|0
block|,
name|VertexDontDraw
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
name|VertexRelative
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Vertex
name|icon_box
index|[
name|NBOX
index|]
init|=
block|{
block|{
literal|0
block|,
literal|0
block|,
name|VertexDontDraw
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
name|VertexRelative
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
name|VertexRelative
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|T_fontsize
name|Tfontsize
index|[
name|TEKNUMFONTS
index|]
init|=
block|{
block|{
literal|9
block|,
literal|15
block|}
block|,
comment|/* large */
block|{
literal|8
block|,
literal|13
block|}
block|,
comment|/* #2 */
block|{
literal|6
block|,
literal|13
block|}
block|,
comment|/* #3 */
block|{
literal|6
block|,
literal|10
block|}
block|,
comment|/* small */
block|{
literal|0
block|,
literal|0
block|}
block|,
comment|/* icon is filled-in later */
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|int
name|debug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true causes error messages to be displayed */
end_comment

begin_endif
endif|#
directive|endif
endif|DEBUG
end_endif

begin_decl_stmt
name|Terminal
name|term
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* master data structure for client */
end_comment

begin_decl_stmt
name|char
modifier|*
name|xterm_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* argv[0] */
end_comment

begin_decl_stmt
name|int
name|am_slave
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 if running as a slave process */
end_comment

begin_decl_stmt
name|char
modifier|*
name|icon_geom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|B_Pixel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Pixmap
name|B_Pixmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|L_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|max_plus1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|n_marginbell
init|=
name|N_MARGINBELL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pty_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|re_verse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|save_lines
init|=
name|SAVELINES
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Select_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|W_Pixel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Pixmap
name|W_Pixmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|win_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|X_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|back_color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|curs_color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|curs_shape
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|f_b
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|f_n
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|f_t
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|f_i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fore_color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|geo_metry
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mous_color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|T_geometry
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ptydev
init|=
literal|"/dev/ptyxx"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ttydev
init|=
literal|"/dev/ttyxx"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|log_def_name
index|[]
init|=
literal|"XtermLog.XXXXX"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|T_lastx
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|T_lasty
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dropmenu
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|doonalarmcode
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|douniquesuffix
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|grayborder
init|=
name|TRUE
decl_stmt|;
end_decl_stmt

end_unit

