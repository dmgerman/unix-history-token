begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_Xct_h
end_ifndef

begin_define
define|#
directive|define
name|_Xct_h
end_define

begin_comment
comment|/*   * $XConsortium: Xct.h,v 1.6 91/07/22 23:46:25 converse Exp $  * Copyright 1989 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided   * that the above copyright notice appear in all copies and that both that   * copyright notice and this permission notice appear in supporting   * documentation, and that the name of M.I.T. not be used in advertising  * or publicity pertaining to distribution of the software without specific,   * written prior permission. M.I.T. makes no representations about the   * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  */
end_comment

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_define
define|#
directive|define
name|XctVersion
value|1
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
modifier|*
name|XctString
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XctUnspecified
block|,
name|XctLeftToRight
block|,
name|XctRightToLeft
block|}
name|XctHDirection
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|XctFlags
typedef|;
end_typedef

begin_comment
comment|/* These are bits in XctFlags. */
end_comment

begin_define
define|#
directive|define
name|XctSingleSetSegments
value|0x0001
end_define

begin_comment
comment|/* This means that returned segments should contain characters from only     * one set (C0, C1, GL, GR).  When this is requested, XctSegment is never     * returned, instead XctC0Segment, XctC1Segment, XctGlSegment, and     * XctGRSegment are returned.  C0 and C1 segments are always returned as     * singleton characters.     */
end_comment

begin_define
define|#
directive|define
name|XctProvideExtensions
value|0x0002
end_define

begin_comment
comment|/* This means that if the Compound Text string is from a higher version     * than this code is implemented to, then syntactically correct but unknown     * control sequences should be returned as XctExtension items.  If this     * flag is not set, and the Compound Text string version indicates that     * extensions cannot be ignored, then each unknown control sequence will be     * reported as an XctError.     */
end_comment

begin_define
define|#
directive|define
name|XctAcceptC0Extensions
value|0x0004
end_define

begin_comment
comment|/* This means that if the Compound Text string is from a higher version     * than this code is implemented to, then unknown C0 characters should be     * treated as if they were legal, and returned as C0 characters (regardless     * of how XctProvideExtensions is set).  If this flag is not set, then all     * unknown C0 characters are treated according to XctProvideExtensions.     */
end_comment

begin_define
define|#
directive|define
name|XctAcceptC1Extensions
value|0x0008
end_define

begin_comment
comment|/* This means that if the Compound Text string is from a higher version     * than this code is implemented to, then unknown C0 characters should be     * treated as if they were legal, and returned as C0 characters (regardless     * of how XctProvideExtensions is set).  If this flag is not set, then all     * unknown C0 characters are treated according to XctProvideExtensions.     */
end_comment

begin_define
define|#
directive|define
name|XctHideDirection
value|0x0010
end_define

begin_comment
comment|/* This means that horizontal direction changes should be reported as     * XctHorizontal items.  If this flag is not set, then direction changes are     * not returned as items, but the current direction is still maintained and     * reported for other items.     */
end_comment

begin_define
define|#
directive|define
name|XctFreeString
value|0x0020
end_define

begin_comment
comment|/* This means that XctFree should free the Compound Text string (that was     * passed to XctCreate.  If this flag is not set, the string is not freed.     */
end_comment

begin_define
define|#
directive|define
name|XctShiftMultiGRToGL
value|0x0040
end_define

begin_comment
comment|/* Translate GR segments on-the-fly into GL segments for the GR sets:     * GB2312.1980-1, JISX0208.1983-1, and KSC5601.1987-1.     */
end_comment

begin_comment
comment|/* This is the return type for XctNextItem. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|XctSegment
block|,
comment|/* used when XctSingleSetSegments is not requested */
name|XctC0Segment
block|,
comment|/* used when XctSingleSetSegments is requested */
name|XctGLSegment
block|,
comment|/* used when XctSingleSetSegments is requested */
name|XctC1Segment
block|,
comment|/* used when XctSingleSetSegments is requested */
name|XctGRSegment
block|,
comment|/* used when XctSingleSetSegments is requested */
name|XctExtendedSegment
block|,
comment|/* an extended segment */
name|XctExtension
block|,
comment|/* used when XctProvideExtensions is requested */
name|XctHorizontal
block|,
comment|/* horizontal direction or depth change */
name|XctEndOfText
block|,
comment|/* end of text string */
name|XctError
comment|/* syntactic or semantic error */
block|}
name|XctResult
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XctRec
block|{
name|XctString
name|total_string
decl_stmt|;
comment|/* as given to XctCreate */
name|int
name|total_length
decl_stmt|;
comment|/* as given to XctCreate */
name|XctFlags
name|flags
decl_stmt|;
comment|/* as given to XctCreate */
name|int
name|version
decl_stmt|;
comment|/* indicates the version of the CT spec 					 * the string was produced from */
name|int
name|can_ignore_exts
decl_stmt|;
comment|/* non-zero if ignoring extensions is 					 * acceptable, else zero */
name|XctString
name|item
decl_stmt|;
comment|/* item returned from XctNextItem */
name|int
name|item_length
decl_stmt|;
comment|/* length of item in bytes */
name|int
name|char_size
decl_stmt|;
comment|/* number of bytes per character in 					 * item, with zero meaning variable */
name|char
modifier|*
name|encoding
decl_stmt|;
comment|/* Encoding name for item */
name|XctHDirection
name|horizontal
decl_stmt|;
comment|/* direction of item */
name|int
name|horz_depth
decl_stmt|;
comment|/* current direction nesting depth */
name|char
modifier|*
name|GL
decl_stmt|;
comment|/* "{I} F" string for current GL */
name|char
modifier|*
name|GL_encoding
decl_stmt|;
comment|/* Encoding name for current GL */
name|int
name|GL_set_size
decl_stmt|;
comment|/* 94 or 96 */
name|int
name|GL_char_size
decl_stmt|;
comment|/* number of bytes per GL character */
name|char
modifier|*
name|GR
decl_stmt|;
comment|/* "{I} F" string for current GR */
name|char
modifier|*
name|GR_encoding
decl_stmt|;
comment|/* Encoding name for current GR */
name|int
name|GR_set_size
decl_stmt|;
comment|/* 94 or 96 */
name|int
name|GR_char_size
decl_stmt|;
comment|/* number of bytes per GR character */
name|char
modifier|*
name|GLGR_encoding
decl_stmt|;
comment|/* Encoding name for current GL+GR, 					 * if known */
name|struct
name|_XctPriv
modifier|*
name|priv
decl_stmt|;
comment|/* private to parser, don't peek */
block|}
typedef|*
name|XctData
typedef|;
end_typedef

begin_comment
comment|/* these are the external routines */
end_comment

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|XctData
name|XctCreate
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|unsigned
name|char
modifier|*
comment|/* string */
parameter_list|,
name|int
comment|/* length */
parameter_list|,
name|XctFlags
comment|/* flags */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XctResult
name|XctNextItem
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XctData
comment|/* data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XctFree
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XctData
comment|/* data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XctReset
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XctData
comment|/* data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _Xct_h */
end_comment

end_unit

