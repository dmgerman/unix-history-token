begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: DviP.h,v 1.5 89/07/22 19:44:08 keith Exp $  */
end_comment

begin_comment
comment|/*   * DviP.h - Private definitions for Dvi widget  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtDviP_h
end_ifndef

begin_define
define|#
directive|define
name|_XtDviP_h
end_define

begin_include
include|#
directive|include
file|"Dvi.h"
end_include

begin_include
include|#
directive|include
file|"DviChar.h"
end_include

begin_comment
comment|/***********************************************************************  *  * Dvi Widget Private Data  *  ***********************************************************************/
end_comment

begin_comment
comment|/************************************  *  *  Class structure  *  ***********************************/
end_comment

begin_comment
comment|/*  * New fields for the Dvi widget class record  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DviClass
block|{
name|int
name|makes_compiler_happy
decl_stmt|;
comment|/* not used */
block|}
name|DviClassPart
typedef|;
end_typedef

begin_comment
comment|/*  * Full class record declaration  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DviClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|DviClassPart
name|command_class
decl_stmt|;
block|}
name|DviClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|DviClassRec
name|dviClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***************************************  *  *  Instance (widget) structure   *  **************************************/
end_comment

begin_comment
comment|/*  * a list of fonts we've used for this widget  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_dviFontSizeList
block|{
name|struct
name|_dviFontSizeList
modifier|*
name|next
decl_stmt|;
name|int
name|size
decl_stmt|;
name|char
modifier|*
name|x_name
decl_stmt|;
name|XFontStruct
modifier|*
name|font
decl_stmt|;
name|int
name|doesnt_exist
decl_stmt|;
block|}
name|DviFontSizeList
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_dviFontList
block|{
name|struct
name|_dviFontList
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|dvi_name
decl_stmt|;
name|char
modifier|*
name|x_name
decl_stmt|;
name|int
name|dvi_number
decl_stmt|;
name|DviFontSizeList
modifier|*
name|sizes
decl_stmt|;
name|DviCharNameMap
modifier|*
name|char_map
decl_stmt|;
block|}
name|DviFontList
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_dviFontMap
block|{
name|struct
name|_dviFontMap
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|dvi_name
decl_stmt|;
name|char
modifier|*
name|x_name
decl_stmt|;
block|}
name|DviFontMap
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DVI_TEXT_CACHE_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|DVI_CHAR_CACHE_SIZE
value|1024
end_define

begin_typedef
typedef|typedef
struct|struct
name|_dviCharCache
block|{
name|XTextItem
name|cache
index|[
name|DVI_TEXT_CACHE_SIZE
index|]
decl_stmt|;
name|char
name|char_cache
index|[
name|DVI_CHAR_CACHE_SIZE
index|]
decl_stmt|;
name|int
name|index
decl_stmt|;
name|int
name|max
decl_stmt|;
name|int
name|char_index
decl_stmt|;
name|int
name|font_size
decl_stmt|;
name|int
name|font_number
decl_stmt|;
name|XFontStruct
modifier|*
name|font
decl_stmt|;
name|int
name|start_x
decl_stmt|,
name|start_y
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|DviCharCache
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_dviState
block|{
name|struct
name|_dviState
modifier|*
name|next
decl_stmt|;
name|int
name|font_size
decl_stmt|;
name|int
name|font_number
decl_stmt|;
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
name|DviState
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_dviFileMap
block|{
name|struct
name|_dviFileMap
modifier|*
name|next
decl_stmt|;
name|long
name|position
decl_stmt|;
name|int
name|page_number
decl_stmt|;
block|}
name|DviFileMap
typedef|;
end_typedef

begin_comment
comment|/*  * New fields for the Dvi widget record  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 	 * resource specifiable items 	 */
name|char
modifier|*
name|font_map_string
decl_stmt|;
name|unsigned
name|long
name|foreground
decl_stmt|;
name|unsigned
name|long
name|background
decl_stmt|;
name|int
name|requested_page
decl_stmt|;
name|int
name|last_page
decl_stmt|;
name|XFontStruct
modifier|*
name|default_font
decl_stmt|;
name|FILE
modifier|*
name|file
decl_stmt|;
name|Boolean
name|noPolyText
decl_stmt|;
name|Boolean
name|seek
decl_stmt|;
comment|/* file is "seekable" */
comment|/*  	 * private state  	 */
name|FILE
modifier|*
name|tmpFile
decl_stmt|;
comment|/* used when reading stdin */
name|char
name|readingTmp
decl_stmt|;
comment|/* reading now from tmp */
name|char
name|ungot
decl_stmt|;
comment|/* have ungetc'd a char */
name|GC
name|normal_GC
decl_stmt|;
name|GC
name|fill_GC
decl_stmt|;
name|DviFileMap
modifier|*
name|file_map
decl_stmt|;
name|DviFontList
modifier|*
name|fonts
decl_stmt|;
name|DviFontMap
modifier|*
name|font_map
decl_stmt|;
name|int
name|current_page
decl_stmt|;
name|int
name|font_size
decl_stmt|;
name|int
name|font_number
decl_stmt|;
name|int
name|device_resolution
decl_stmt|;
name|int
name|line_thickness
decl_stmt|;
name|int
name|line_width
decl_stmt|;
define|#
directive|define
name|DVI_FILL_MAX
value|1000
name|int
name|fill
decl_stmt|;
define|#
directive|define
name|DVI_FILL_WHITE
value|0
define|#
directive|define
name|DVI_FILL_GRAY
value|1
define|#
directive|define
name|DVI_FILL_BLACK
value|2
name|int
name|fill_type
decl_stmt|;
name|Pixmap
name|gray
decl_stmt|;
name|int
name|backing_store
decl_stmt|;
name|XFontStruct
modifier|*
name|font
decl_stmt|;
name|int
name|display_enable
decl_stmt|;
struct|struct
name|ExposedExtents
block|{
name|int
name|x1
decl_stmt|,
name|y1
decl_stmt|,
name|x2
decl_stmt|,
name|y2
decl_stmt|;
block|}
name|extents
struct|;
name|DviState
modifier|*
name|state
decl_stmt|;
name|DviCharCache
name|cache
decl_stmt|;
block|}
name|DviPart
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DviGetIn
parameter_list|(
name|dw
parameter_list|,
name|cp
parameter_list|)
define|\
value|(dw->dvi.tmpFile ? (\ 	DviGetAndPut (dw, cp) \     ) :\ 	(*cp = getc (dw->dvi.file))\ )
end_define

begin_define
define|#
directive|define
name|DviGetC
parameter_list|(
name|dw
parameter_list|,
name|cp
parameter_list|)
define|\
value|(dw->dvi.readingTmp ? (\ 	((*cp = getc (dw->dvi.tmpFile)) == EOF) ? (\ 	    fseek (dw->dvi.tmpFile, 0l, 2),\ 	    (dw->dvi.readingTmp = 0),\ 	    DviGetIn (dw,cp)\ 	) : (\ 	    *cp\ 	)\     ) : (\ 	DviGetIn(dw,cp)\     )\ )
end_define

begin_define
define|#
directive|define
name|DviUngetC
parameter_list|(
name|dw
parameter_list|,
name|c
parameter_list|)
define|\
value|(dw->dvi.readingTmp ? (\ 	ungetc (c, dw->dvi.tmpFile)\     ) : ( \ 	(dw->dvi.ungot = 1),\ 	ungetc (c, dw->dvi.file)))
end_define

begin_comment
comment|/*  * Full widget declaration  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DviRec
block|{
name|CorePart
name|core
decl_stmt|;
name|DviPart
name|dvi
decl_stmt|;
block|}
name|DviRec
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|XFontStruct
modifier|*
name|QueryFont
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DviCharNameMap
modifier|*
name|QueryFontMap
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XtDviP_h */
end_comment

end_unit

