begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  *	externs	--	external declarations for global variables and   *			external functions used by the ditroff to   *			interpress conversion routines  *  *	John Mellor-Crummey (Xerox Corp)  *  *	Copyright (c) 1985 Xerox Corporation  *  *****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"types.h"
end_include

begin_comment
comment|/* data type declarations */
end_comment

begin_comment
comment|/*-----------------------------------------------------------------------------  *  *	external declarations for  *	global variables used by the ditroff to interpress conversion routines  *  *---------------------------------------------------------------------------*/
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tempfilename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to form names of output files */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|outputfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output file descriptor */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pagebodyfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temporary file to hold page bodies */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|outputflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output this page? */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nPageRanges
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output page list if> 0 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pagerange
index|[]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pairs of page numbers */
end_comment

begin_comment
comment|/* font tables  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fontdirectory
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|devicename
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|device_entry
name|device
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|font_entry
modifier|*
name|fontPtr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|pointsizeTab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|specFontPos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* position of first special font */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|specCharStrTab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|specCharTab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|fontIndexTab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|charCodeTab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* character codes for device */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|charWidthTab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* contains width info for fonts */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dbg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|spotsPerInch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input uses this resolution */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current size */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|font
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current font */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|ftsz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* combination of size and font */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|oldftsz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* former value of ftsz */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hor_pos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next horizontal position (= 0, left of page ) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|old_hor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* previous horizontal position */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ver_pos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current vertical position (> 0, down page) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|old_ver
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* previous vertical position */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hor_orig
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* horizontal origin of current block */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ver_orig
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vertical origin of current block */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|linenumber
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number for error reporting */
end_comment

begin_comment
comment|/* hooks for reporting system errors */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interpress stuff */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ifont
modifier|*
name|currfonts
index|[
name|MAX_NUM_FONTS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ifont
modifier|*
name|inactfonts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|frameindex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current frame index */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mapcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of names in troff to ip map */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|charw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current character's troff width */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|trname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* troff name pointers (into timap) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|ipname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interpress name pointers (into timap) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|timap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer holds strings for font mapping */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|in_correct
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true when inside a "correct" body */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|virgin_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if line untouched (char not yet shown) */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|scale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scale used to trans troff to ip co-ords */
end_comment

begin_comment
comment|/* this is for the bitmap interface */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|drawidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* width of the drawing pen */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|drawscale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scaling factor for drawing points */
end_comment

begin_comment
comment|/* external function declarations */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* for saving environments with push, pop */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|state
name|state
index|[
name|MAXSTATE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|state
modifier|*
name|statep
decl_stmt|;
end_decl_stmt

end_unit

