begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  *  *	globals	--	global variables used by the ditroff to interpress   *			conversion routines  *  *	John Mellor-Crummey (Xerox Corp)  *	  *	Copyright (c) 1985 Xerox Corporation  *  ******************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_comment
comment|/* constant and macro declarations */
end_comment

begin_include
include|#
directive|include
file|"types.h"
end_include

begin_comment
comment|/* data type declarations */
end_comment

begin_include
include|#
directive|include
file|"deviceinfo.h"
end_include

begin_comment
comment|/*-----------------------------------------------------------------------------  *  *	global variables used by the ditroff to interpress conversion routines  *  *---------------------------------------------------------------------------*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|tempfilename
init|=
literal|"/tmp/dipXXXXXb"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to form names of output files */
end_comment

begin_decl_stmt
name|int
name|outputfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output file */
end_comment

begin_decl_stmt
name|int
name|pagebodyfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temporary to hold page bodies */
end_comment

begin_decl_stmt
name|int
name|outputflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output this page? */
end_comment

begin_decl_stmt
name|int
name|nPageRanges
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output page list if> 0 */
end_comment

begin_decl_stmt
name|int
name|pagerange
index|[
name|MAXPAGESPEC
index|]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pairs of page numbers */
end_comment

begin_comment
comment|/* font tables */
end_comment

begin_decl_stmt
name|char
modifier|*
name|fontdirectory
init|=
literal|"/usr/local/export/ip/lib/font"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|devicename
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|device_entry
name|device
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|font_entry
modifier|*
name|fontPtr
index|[
name|MAX_NUM_FONTS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
modifier|*
name|pointsizeTab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|specFontPos
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* position of first special font */
end_comment

begin_decl_stmt
name|char
modifier|*
name|specCharStrTab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
modifier|*
name|specCharTab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
modifier|*
name|fontIndexTab
index|[
name|MAX_NUM_FONTS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|charCodeTab
index|[
name|MAX_NUM_FONTS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* character codes for device */
end_comment

begin_decl_stmt
name|unsigned
name|char
modifier|*
name|charWidthTab
index|[
name|MAX_NUM_FONTS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* char widths for fonts */
end_comment

begin_decl_stmt
name|int
name|dbg
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|linenumber
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for error reporting */
end_comment

begin_decl_stmt
name|int
name|spotsPerInch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input uses this resolution */
end_comment

begin_decl_stmt
name|int
name|size
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current size */
end_comment

begin_decl_stmt
name|int
name|font
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current font */
end_comment

begin_decl_stmt
name|long
name|ftsz
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* combination of size and font */
end_comment

begin_decl_stmt
name|long
name|oldftsz
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* former value of ftsz */
end_comment

begin_decl_stmt
name|int
name|hor_pos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next horizontal position (= 0, left of page) */
end_comment

begin_decl_stmt
name|int
name|old_hor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* previous horizontal position */
end_comment

begin_decl_stmt
name|int
name|ver_pos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current vertical position (> 0, down page) */
end_comment

begin_decl_stmt
name|int
name|old_ver
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* previous vertical position */
end_comment

begin_decl_stmt
name|int
name|hor_orig
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* horizontal origin of current block */
end_comment

begin_decl_stmt
name|int
name|ver_orig
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vertical origin of current block */
end_comment

begin_comment
comment|/* interpress stuff */
end_comment

begin_decl_stmt
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

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|struct
name|ifont
modifier|*
name|inactfonts
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|frameindex
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current frame index */
end_comment

begin_decl_stmt
name|int
name|mapcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of names in troff to ip map */
end_comment

begin_decl_stmt
name|int
name|charw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current character's troff width */
end_comment

begin_decl_stmt
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
name|char
modifier|*
name|timap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer holds strings for font mapping */
end_comment

begin_decl_stmt
name|char
name|in_correct
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true when inside a "correct" body */
end_comment

begin_decl_stmt
name|char
name|virgin_line
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if line untouched (character not yet shown) */
end_comment

begin_decl_stmt
name|double
name|scale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scale used in translating troff to ip co-ords */
end_comment

begin_comment
comment|/* this is for the bitmap interface */
end_comment

begin_decl_stmt
name|int
name|drawidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* width of the drawing pen */
end_comment

begin_decl_stmt
name|double
name|drawscale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scaling factor for drawing points */
end_comment

begin_comment
comment|/* for saving environments with push,pop */
end_comment

begin_decl_stmt
name|struct
name|state
name|state
index|[
name|MAXSTATE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|state
modifier|*
name|statep
init|=
name|state
decl_stmt|;
end_decl_stmt

end_unit

