begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Structures to facilitate option passing in showimg.  */
end_comment

begin_comment
comment|/* main window structures */
end_comment

begin_struct
struct|struct
name|windmain
block|{
name|char
modifier|*
name|display
decl_stmt|;
comment|/* display name */
name|char
name|filegeometry
index|[
literal|30
index|]
decl_stmt|;
comment|/* geometry from file */
name|char
modifier|*
name|geometry
decl_stmt|;
comment|/* geometry from command line, if any */
name|OpaqueFrame
name|frame
decl_stmt|;
comment|/* main window descriptor */
name|WindowInfo
name|winfo
decl_stmt|;
comment|/* main window information struct */
name|Cursor
name|windcursor
decl_stmt|;
comment|/* current main window cursor */
name|Cursor
name|lastcursor
decl_stmt|;
comment|/* previous cursor */
block|}
struct|;
end_struct

begin_comment
comment|/* Color info */
end_comment

begin_struct
struct|struct
name|colorwind
block|{
name|int
name|nplanes
decl_stmt|;
comment|/* number of color planes */
name|int
name|pixels
index|[
literal|1
index|]
decl_stmt|;
comment|/* base for color map */
name|int
name|ncolors
decl_stmt|;
comment|/* number of colors used */
name|int
name|planes
decl_stmt|;
comment|/* planes mask */
name|int
name|shift
decl_stmt|;
comment|/* #left shifts to adjust zero-based */
comment|/*     pixels to pixels[1] */
name|Color
name|cmap
index|[
literal|256
index|]
decl_stmt|;
comment|/* GPX max color map limited to 256 */
block|}
struct|;
end_struct

begin_comment
comment|/* image, image info, options, operational flags */
end_comment

begin_struct
struct|struct
name|imagewind
block|{
name|char
modifier|*
name|filename
decl_stmt|;
name|short
modifier|*
name|header
decl_stmt|;
comment|/* header data from file */
name|short
modifier|*
name|picture
decl_stmt|;
comment|/* 16-bit image */
name|unsigned
name|char
modifier|*
name|image
decl_stmt|;
comment|/* 8-bit (or fewer) displayed image */
name|int
name|nrows
decl_stmt|;
name|int
name|ncols
decl_stmt|;
name|int
name|pmin
decl_stmt|;
comment|/* high min pixel flags not set */
name|int
name|pmax
decl_stmt|;
comment|/* low max pixel flags not set */
name|int
name|headskip
decl_stmt|;
comment|/* bytes to skip before reading */
name|int
name|calibration
decl_stmt|;
comment|/* flag for test pattern */
name|int
name|fitsflag
decl_stmt|;
comment|/* file format indicator */
ifdef|#
directive|ifdef
name|XRAY
comment|/* added by egm */
name|int
name|ein
decl_stmt|;
comment|/* flag for Einstein xray data */
name|int
name|ros
decl_stmt|;
comment|/* flag for Rosat xray data */
name|int
name|iy
decl_stmt|,
name|iz
decl_stmt|,
name|zoom
decl_stmt|,
name|energy
decl_stmt|;
comment|/* parameters on -xray switch */
name|short
name|int
name|ict
index|[
literal|513
index|]
decl_stmt|;
comment|/* image file control table */
name|int
name|muthict
index|[
literal|2400
index|]
decl_stmt|;
comment|/* it's a muther ict table */
name|char
name|poename
index|[
literal|132
index|]
decl_stmt|,
name|hdrname
index|[
literal|132
index|]
decl_stmt|;
comment|/* end of egm code */
endif|#
directive|endif
name|u_short
name|VOP_Flags
decl_stmt|;
name|u_short
name|SOP_Flags
decl_stmt|;
name|u_short
name|COP_Flags
decl_stmt|;
name|u_short
name|FOP_Flags
decl_stmt|;
block|}
struct|;
end_struct

end_unit

