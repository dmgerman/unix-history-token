begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|NEWSTRUCT
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|geometry
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|filegeometry
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* created from file unless overridden */
end_comment

begin_decl_stmt
name|char
modifier|*
name|display
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|border_color
decl_stmt|,
modifier|*
name|back_color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OpaqueFrame
name|frame
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|border_width
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Pixmap
name|border_pixmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Color
name|cdef
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|VOP_Flags
init|=
name|VOP_GrayScale
operator||
name|VOP_Initialize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|SOP_Flags
init|=
name|SOP_Linear
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|COP_Flags
init|=
literal|0
decl_stmt|,
name|COP_OldFlags
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|FOP_Flags
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|option
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nplanes
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of planes to allocate */
end_comment

begin_decl_stmt
name|int
name|ncolors
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pixels
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* color cell from allocation */
end_comment

begin_decl_stmt
name|int
name|planes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* plane mask */
end_comment

begin_decl_stmt
name|Color
name|cmap
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* much larger than can be on CAYLITH */
end_comment

begin_decl_stmt
name|char
modifier|*
name|filename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
modifier|*
name|image
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* written to display */
end_comment

begin_decl_stmt
name|short
modifier|*
name|header
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* header of real image */
end_comment

begin_decl_stmt
name|short
modifier|*
name|pict
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* real image */
end_comment

begin_decl_stmt
name|int
name|pmax
init|=
operator|-
literal|3000
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pmin
init|=
literal|70000
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* will be 16-bite max, min values (approx.)*/
end_comment

begin_decl_stmt
name|int
name|shift
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fitsflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* indicator to read in FITS images */
end_comment

begin_comment
comment|/* 1=true FITS, 2=disk FITS (swapped bytes)*/
end_comment

begin_decl_stmt
name|int
name|calibration
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|headskip
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of header bytes to skip */
end_comment

begin_decl_stmt
name|int
name|nrows
init|=
literal|0
decl_stmt|,
name|ncols
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

