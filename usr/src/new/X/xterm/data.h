begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Source: /u1/X/xterm/RCS/data.h,v $  *	$Header: data.h,v 10.101 86/12/01 16:57:37 swick Rel $  */
end_comment

begin_comment
comment|/* @(#)data.h       X10/6.6B 12/26/86 */
end_comment

begin_decl_stmt
specifier|extern
name|Pixmap
name|B_Pixmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Pixmap
name|W_Pixmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TekLink
modifier|*
name|TekRefresh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Terminal
name|term
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Vertex
name|T_box2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Vertex
name|T_box3
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Vertex
name|T_boxlarge
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Vertex
name|T_boxsmall
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Vertex
name|T_boxicon
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Vertex
name|VTbox
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Vertex
name|icon_box
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|T_fontsize
name|Tfontsize
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Vertex
name|status_box
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|T_geometry
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Tbptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Tbuffer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Tpushb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Tpushback
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|back_color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|bptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|curs_color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|curs_shape
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|f_b
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|f_n
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|f_i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|f_t
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fore_color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|geo_metry
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|icon_geom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|log_def_name
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mous_color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ptydev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ttydev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|win_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xterm_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|buffer
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|B_Pixel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|L_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Select_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|T_lastx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|T_lasty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Tbcnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Ttoggled
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|W_Pixel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|X_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|am_slave
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bcnt
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|DEBUG
end_endif

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|max_plus1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|n_marginbell
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pty_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|re_verse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|save_lines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|switchfb
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|jmp_buf
name|Tekend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|jmp_buf
name|VTend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dropmenu
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|doonalarmcode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|douniquesuffix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|grayborder
decl_stmt|;
end_decl_stmt

end_unit

