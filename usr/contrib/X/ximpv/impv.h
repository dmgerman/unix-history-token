begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header* */
end_comment

begin_struct
struct|struct
name|glyph
block|{
name|int
name|advance
decl_stmt|;
comment|/* advance size */
name|int
name|width
decl_stmt|;
comment|/* width */
name|int
name|left
decl_stmt|;
comment|/* left offset */
name|int
name|height
decl_stmt|;
comment|/* height of glyph */
name|int
name|top
decl_stmt|;
comment|/* top offset */
name|unsigned
name|char
modifier|*
name|bits
decl_stmt|;
comment|/* pointer to actual bitmap */
block|}
name|font0
index|[
literal|128
index|]
struct|;
end_struct

begin_decl_stmt
name|struct
name|glyph
modifier|*
name|family
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|fam
decl_stmt|,
name|member
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|fam_rot
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* macro structure and variables*/
end_comment

begin_struct
struct|struct
name|macro_struct
block|{
name|int
name|length
decl_stmt|;
name|unsigned
name|char
modifier|*
name|pointer
decl_stmt|;
block|}
name|macro
index|[
literal|256
index|]
struct|;
end_struct

begin_decl_stmt
name|int
name|macro_length
decl_stmt|,
name|macro_on
decl_stmt|,
name|macro_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
modifier|*
name|mp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current state of the imagen */
end_comment

begin_decl_stmt
name|int
name|push_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|advance_dir
decl_stmt|,
name|orient
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|horigin
decl_stmt|,
name|vorigin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|HPos
decl_stmt|,
name|VPos
decl_stmt|,
name|xpos
decl_stmt|,
name|ypos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SpaceSize
decl_stmt|,
name|BeginOfLine
decl_stmt|,
name|InterLine
decl_stmt|,
name|CurFamily
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|diameter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|operation
decl_stmt|,
name|texture
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|finish
decl_stmt|,
name|page
decl_stmt|,
name|start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|pages
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set how many pages of document to save*/
end_comment

begin_decl_stmt
name|short
name|magnification
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|originlh
decl_stmt|,
name|originlv
decl_stmt|,
name|hvangle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|big
decl_stmt|,
name|little
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|state
block|{
name|int
name|diameter
decl_stmt|,
name|texture
decl_stmt|,
name|SpaceSize
decl_stmt|,
name|InterLine
decl_stmt|,
name|BeginOfLine
decl_stmt|,
name|fam
decl_stmt|;
name|int
name|HPos
decl_stmt|,
name|VPos
decl_stmt|,
name|advance_dir
decl_stmt|,
name|horigin
decl_stmt|,
name|vorigin
decl_stmt|,
name|orient
decl_stmt|,
name|push_mask
decl_stmt|;
block|}
name|pstack
struct|;
end_struct

begin_decl_stmt
name|struct
name|state
modifier|*
name|push_stack
index|[
literal|128
index|]
decl_stmt|,
modifier|*
name|stap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pushed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|fam_in
decl_stmt|,
name|map_name
decl_stmt|,
name|ntuples
decl_stmt|,
name|vertex_count
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|path
block|{
name|short
name|hor
decl_stmt|;
name|short
name|vert
decl_stmt|;
block|}
modifier|*
name|path_point
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
name|map8_4
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|backcolor
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|XWIND
end_ifdef

begin_decl_stmt
name|unsigned
name|char
name|pscreen
index|[
name|SCREENSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
else|XWIND
end_else

begin_decl_stmt
name|struct
name|pixrect
modifier|*
name|pscreen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|slide
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|COLOR
end_ifdef

begin_struct
struct|struct
name|colors
block|{
name|float
name|red
decl_stmt|,
name|green
decl_stmt|,
name|blue
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|colors
name|bc
decl_stmt|,
name|cc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|COLOR
end_endif

begin_endif
endif|#
directive|endif
endif|XWIND
end_endif

begin_decl_stmt
name|int
name|scr_x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wide
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* width of line in pixrect for page */
end_comment

begin_decl_stmt
name|int
name|scr_y
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scr_d
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scr_size
decl_stmt|;
end_decl_stmt

end_unit

