begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rst.h	1.1	(Berkeley)	83/08/17  *  *	Definitions for imagen RST files.  */
end_comment

begin_define
define|#
directive|define
name|FMARK
value|8
end_define

begin_comment
comment|/* number of bytes in the filemark */
end_comment

begin_define
define|#
directive|define
name|RES
value|240
end_define

begin_comment
comment|/* number of dots/inch on imagen */
end_comment

begin_define
define|#
directive|define
name|FIX
value|(1.0 / (1<< 20))
end_define

begin_comment
comment|/* points per fix */
end_comment

begin_define
define|#
directive|define
name|POINT
value|(1.0 / 72.27)
end_define

begin_comment
comment|/* inches per point */
end_comment

begin_define
define|#
directive|define
name|FIXIN
value|(POINT * FIX)
end_define

begin_comment
comment|/* inches per fix */
end_comment

begin_define
define|#
directive|define
name|FIXPIX
value|(FIXIN * RES)
end_define

begin_comment
comment|/* pixels per fix */
end_comment

begin_define
define|#
directive|define
name|DIRSIZ
value|256
end_define

begin_comment
comment|/* max size of a glyph directory */
end_comment

begin_decl_stmt
name|char
name|filemark
index|[
name|FMARK
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string to test beginning of file */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* glyph directory entry */
name|short
name|g_height
decl_stmt|;
comment|/* height (pixels) of glyph */
name|short
name|g_width
decl_stmt|;
comment|/* width of glyph */
name|short
name|g_up
decl_stmt|;
comment|/* distance from top to reference point */
name|short
name|g_left
decl_stmt|;
comment|/* distance from left to reference point */
name|int
name|g_pwidth
decl_stmt|;
comment|/* printing width of character (troff width) */
name|int
name|g_bitp
decl_stmt|;
comment|/* pointer to raster data (index to file) */
block|}
name|glyph_dir
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* preamble information entries */
name|short
name|p_size
decl_stmt|;
comment|/* size of preamble (not including this) */
name|char
name|p_version
decl_stmt|;
comment|/* rst format version number (hopefully 0) */
name|int
name|p_glyph
decl_stmt|;
comment|/* pointer to glyph directory */
name|short
name|p_first
decl_stmt|;
comment|/* first glyph in directory */
name|short
name|p_last
decl_stmt|;
comment|/* last glyph in directory */
name|int
name|p_mag
decl_stmt|;
comment|/* magnification (in 1/1000ths) */
name|int
name|p_desiz
decl_stmt|;
comment|/* design size (in FIX units) */
name|int
name|p_linesp
decl_stmt|;
comment|/* spacing 'tween lines (FIX) */
name|int
name|p_wordsp
decl_stmt|;
comment|/* word spacing (FIX) = troff's spacewidth */
name|short
name|p_rot
decl_stmt|;
comment|/* rotation (degrees) */
name|char
name|p_cadv
decl_stmt|;
comment|/* character advance direction (0,1,2,3) = 0 */
name|char
name|p_ladv
decl_stmt|;
comment|/* line advance direction (0,1,2,3) = 1 */
name|int
name|p_id
decl_stmt|;
comment|/* identifying mark */
name|short
name|p_res
decl_stmt|;
comment|/* resolution of font (pixels/inch) = 240 */
block|}
name|preamble
typedef|;
end_typedef

end_unit

