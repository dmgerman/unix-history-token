begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Xcmsint.h,v 1.17 91/11/05 11:06:51 rws Exp $ */
end_comment

begin_comment
comment|/*  * Code and supporting documentation (c) Copyright 1990 1991 Tektronix, Inc.  * 	All Rights Reserved  *   * This file is a component of an X Window System-specific implementation  * of Xcms based on the TekColor Color Management System.  Permission is  * hereby granted to use, copy, modify, sell, and otherwise distribute this  * software and its documentation for any purpose and without fee, provided  * that this copyright, permission, and disclaimer notice is reproduced in  * all copies of this software and in supporting documentation.  TekColor  * is a trademark of Tektronix, Inc.  *   * Tektronix makes no representation about the suitability of this software  * for any purpose.  It is provided "as is" and with all faults.  *   * TEKTRONIX DISCLAIMS ALL WARRANTIES APPLICABLE TO THIS SOFTWARE,  * INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE.  IN NO EVENT SHALL TEKTRONIX BE LIABLE FOR ANY  * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER  * RESULTING FROM LOSS OF USE, DATA, OR PROFITS, WHETHER IN AN ACTION OF  * CONTRACT, NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR THE PERFORMANCE OF THIS SOFTWARE.  *  *  *	DESCRIPTION  *		Private include file for Color Management System.  *		(i.e., for API internal use only)  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XCMSINT_H_
end_ifndef

begin_define
define|#
directive|define
name|_XCMSINT_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xcms.h>
end_include

begin_comment
comment|/*  *	DEFINES  */
end_comment

begin_comment
comment|/* 	 * Private Status Value 	 */
end_comment

begin_define
define|#
directive|define
name|_XCMS_NEWNAME
value|-1
end_define

begin_comment
comment|/* 	 * Color Space ID's are of XcmsColorFormat type, which is an 	 *	unsigned short (16 bits).   	 * 	 *	bit 15 (most significant bit): 	 *	    0 == Device-Independent 	 *	    1 == Device-Dependent 	 * 	 *	bit 14:          *          0 == Registered with X Consortium          *          1 == Unregistered          */
end_comment

begin_define
define|#
directive|define
name|XCMS_DD_ID
parameter_list|(
name|id
parameter_list|)
value|((id)& (XcmsColorFormat)0x80000000)
end_define

begin_define
define|#
directive|define
name|XCMS_DI_ID
parameter_list|(
name|id
parameter_list|)
value|(!((id)& (XcmsColorFormat)0x80000000))
end_define

begin_define
define|#
directive|define
name|XCMS_UNREG_ID
parameter_list|(
name|id
parameter_list|)
value|((id)& (XcmsColorFormat)0x40000000)
end_define

begin_define
define|#
directive|define
name|XCMS_REG_ID
parameter_list|(
name|id
parameter_list|)
value|(!((id)& (XcmsColorFormat)0x40000000))
end_define

begin_define
define|#
directive|define
name|XCMS_FIRST_REG_DI_ID
value|(XcmsColorFormat)0x00000001
end_define

begin_define
define|#
directive|define
name|XCMS_FIRST_UNREG_DI_ID
value|(XcmsColorFormat)0x40000000
end_define

begin_define
define|#
directive|define
name|XCMS_FIRST_REG_DD_ID
value|(XcmsColorFormat)0x80000000
end_define

begin_define
define|#
directive|define
name|XCMS_FIRST_UNREG_DD_ID
value|(XcmsColorFormat)0xc0000000
end_define

begin_comment
comment|/*  *	TYPEDEFS  */
end_comment

begin_comment
comment|/*      * Structure for caching Colormap info.      *    This is provided for the Xlib modifications to:      *		XAllocNamedColor()      *		XLookupColor()      *		XParseColor()      *		XStoreNamedColor()      */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XcmsCmapRec
block|{
name|Colormap
name|cmapID
decl_stmt|;
name|Display
modifier|*
name|dpy
decl_stmt|;
name|Window
name|windowID
decl_stmt|;
name|Visual
modifier|*
name|visual
decl_stmt|;
name|struct
name|_XcmsCCC
modifier|*
name|ccc
decl_stmt|;
name|struct
name|_XcmsCmapRec
modifier|*
name|pNext
decl_stmt|;
block|}
name|XcmsCmapRec
typedef|;
end_typedef

begin_comment
comment|/*      * Intensity Record (i.e., value / intensity tuple)      */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IntensityRec
block|{
name|unsigned
name|short
name|value
decl_stmt|;
name|XcmsFloat
name|intensity
decl_stmt|;
block|}
name|IntensityRec
typedef|;
end_typedef

begin_comment
comment|/*      * Intensity Table      */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IntensityTbl
block|{
name|IntensityRec
modifier|*
name|pBase
decl_stmt|;
name|unsigned
name|int
name|nEntries
decl_stmt|;
block|}
name|IntensityTbl
typedef|;
end_typedef

begin_comment
comment|/*      * Structure for storing per-Visual Intensity Tables (aka gamma maps).      */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XcmsIntensityMap
block|{
name|VisualID
name|visualID
decl_stmt|;
name|XPointer
name|screenData
decl_stmt|;
comment|/* pointer to corresponding Screen Color*/
comment|/*	Characterization Data		*/
name|void
function_decl|(
modifier|*
name|pFreeScreenData
function_decl|)
parameter_list|()
function_decl|;
comment|/* Function that frees a Screen		*/
comment|/*   structure.				*/
name|struct
name|_XcmsIntensityMap
modifier|*
name|pNext
decl_stmt|;
block|}
name|XcmsIntensityMap
typedef|;
end_typedef

begin_comment
comment|/*      * Structure for storing "registered" color space prefix/ID      */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XcmsRegColorSpaceEntry
block|{
name|char
modifier|*
name|prefix
decl_stmt|;
comment|/* Color Space prefix (e.g., "CIEXYZ:") */
name|XcmsColorFormat
name|id
decl_stmt|;
comment|/* Color Space ID (e.g., XcmsCIEXYZFormat) */
block|}
name|XcmsRegColorSpaceEntry
typedef|;
end_typedef

begin_comment
comment|/*      * Xcms Per Display (i.e. connection) related data      */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XcmsPerDpyInfo
block|{
name|XcmsCCC
name|paDefaultCCC
decl_stmt|;
comment|/* based on default visual of screen */
comment|/* 	     * Pointer to an array of XcmsCCC structures, one for 	     * each screen. 	     */
name|XcmsCmapRec
modifier|*
name|pClientCmaps
decl_stmt|;
comment|/* Pointer to linked list of XcmsCmapRec's */
block|}
name|XcmsPerDpyInfo
operator|,
typedef|*
name|XcmsPerDpyInfoPtr
typedef|;
end_typedef

begin_comment
comment|/*  *	DEFINES  */
end_comment

begin_define
define|#
directive|define
name|XDCCC_NUMBER
value|0x8000000L
end_define

begin_comment
comment|/* 2**27 per XDCCC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GRAY
end_ifdef

begin_define
define|#
directive|define
name|XDCCC_SCREENWHITEPT_ATOM_NAME
value|"XDCCC_GRAY_SCREENWHITEPOINT"
end_define

begin_define
define|#
directive|define
name|XDCCC_GRAY_CORRECT_ATOM_NAME
value|"XDCCC_GRAY_CORRECTION"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GRAY */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ConversionValues
end_ifndef

begin_typedef
typedef|typedef
struct|struct
name|_ConversionValues
block|{
name|IntensityTbl
name|IntensityTbl
decl_stmt|;
block|}
name|ConversionValues
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|GRAY
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
name|IntensityTbl
modifier|*
name|IntensityTbl
decl_stmt|;
block|}
name|GRAY_SCCData
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GRAY */
end_comment

begin_comment
comment|/*  *	DEFINES  */
end_comment

begin_define
define|#
directive|define
name|XDCCC_MATRIX_ATOM_NAME
value|"XDCCC_LINEAR_RGB_MATRICES"
end_define

begin_define
define|#
directive|define
name|XDCCC_CORRECT_ATOM_NAME
value|"XDCCC_LINEAR_RGB_CORRECTION"
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|XcmsFloat
name|XYZtoRGBmatrix
index|[
literal|3
index|]
index|[
literal|3
index|]
decl_stmt|;
name|XcmsFloat
name|RGBtoXYZmatrix
index|[
literal|3
index|]
index|[
literal|3
index|]
decl_stmt|;
name|IntensityTbl
modifier|*
name|pRedTbl
decl_stmt|;
name|IntensityTbl
modifier|*
name|pGreenTbl
decl_stmt|;
name|IntensityTbl
modifier|*
name|pBlueTbl
decl_stmt|;
block|}
name|LINEAR_RGB_SCCData
typedef|;
end_typedef

begin_comment
comment|/*  *	DESCRIPTION  *		Include file for defining the math macros used in the  *		XCMS source.  Instead of using math library routines  *		directly, XCMS uses macros so that based on the  *		definitions here, vendors and sites can specify exactly  *		what routine will be called (those from libm.a or their  *		custom routines).  If not defined to math library routines  *		(e.g., sqrt in libm.a), then the client is not forced to  *		be linked with -lm.  */
end_comment

begin_define
define|#
directive|define
name|XCMS_ATAN
parameter_list|(
name|x
parameter_list|)
value|_XcmsArcTangent(x)
end_define

begin_define
define|#
directive|define
name|XCMS_COS
parameter_list|(
name|x
parameter_list|)
value|_XcmsCosine(x)
end_define

begin_define
define|#
directive|define
name|XCMS_CUBEROOT
parameter_list|(
name|x
parameter_list|)
value|_XcmsCubeRoot(x)
end_define

begin_define
define|#
directive|define
name|XCMS_FABS
parameter_list|(
name|x
parameter_list|)
value|((x)< 0.0 ? -(x) : (x))
end_define

begin_define
define|#
directive|define
name|XCMS_SIN
parameter_list|(
name|x
parameter_list|)
value|_XcmsSine(x)
end_define

begin_define
define|#
directive|define
name|XCMS_SQRT
parameter_list|(
name|x
parameter_list|)
value|_XcmsSquareRoot(x)
end_define

begin_define
define|#
directive|define
name|XCMS_TAN
parameter_list|(
name|x
parameter_list|)
value|(XCMS_SIN(x) / XCMS_COS(x))
end_define

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
name|double
name|_XcmsArcTangent
parameter_list|(
name|double
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|_XcmsCosine
parameter_list|(
name|double
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|_XcmsCubeRoot
parameter_list|(
name|double
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|_XcmsSine
parameter_list|(
name|double
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|_XcmsSquareRoot
parameter_list|(
name|double
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|double
name|_XcmsArcTangent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|_XcmsCosine
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|_XcmsCubeRoot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|_XcmsSine
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|_XcmsSquareRoot
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  DEFINES FOR GAMUT COMPRESSION AND QUERY ROUTINES  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PI
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|M_PI
end_ifdef

begin_define
define|#
directive|define
name|PI
value|M_PI
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PI
value|3.14159265358979323846264338327950
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_PI */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PI */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|degrees
end_ifndef

begin_define
define|#
directive|define
name|degrees
parameter_list|(
name|r
parameter_list|)
value|((XcmsFloat)(r) * 180.0 / PI)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* degrees */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|radians
end_ifndef

begin_define
define|#
directive|define
name|radians
parameter_list|(
name|d
parameter_list|)
value|((XcmsFloat)(d) * PI / 180.0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* radians */
end_comment

begin_define
define|#
directive|define
name|XCMS_CIEUSTAROFHUE
parameter_list|(
name|h
parameter_list|,
name|c
parameter_list|)
define|\
value|((XCMS_COS((h)) == 0.0) ? (XcmsFloat)0.0 : (XcmsFloat) \ ((XcmsFloat)(c) / (XcmsFloat)XCMS_SQRT((XCMS_TAN(h) * XCMS_TAN(h)) + \ (XcmsFloat)1.0)))
end_define

begin_define
define|#
directive|define
name|XCMS_CIEVSTAROFHUE
parameter_list|(
name|h
parameter_list|,
name|c
parameter_list|)
define|\
value|((XCMS_COS((h)) == 0.0) ? (XcmsFloat)0.0 : (XcmsFloat) \ ((XcmsFloat)(c) / (XcmsFloat)XCMS_SQRT(((XcmsFloat)1.0 / \ (XcmsFloat)(XCMS_TAN(h) * XCMS_TAN(h))) + (XcmsFloat)1.0)))
end_define

begin_comment
comment|/* this hue is returned in radians */
end_comment

begin_define
define|#
directive|define
name|XCMS_CIELUV_PMETRIC_HUE
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|(((u) != 0.0) ? XCMS_ATAN( (v) / (u)) : ((v>= 0.0) ? PI / 2 : -(PI / 2)))
end_define

begin_define
define|#
directive|define
name|XCMS_CIELUV_PMETRIC_CHROMA
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|)
value|XCMS_SQRT(((u)*(u)) + ((v)*(v)))
end_define

begin_define
define|#
directive|define
name|XCMS_CIEASTAROFHUE
parameter_list|(
name|h
parameter_list|,
name|c
parameter_list|)
value|XCMS_CIEUSTAROFHUE((h), (c))
end_define

begin_define
define|#
directive|define
name|XCMS_CIEBSTAROFHUE
parameter_list|(
name|h
parameter_list|,
name|c
parameter_list|)
value|XCMS_CIEVSTAROFHUE((h), (c))
end_define

begin_define
define|#
directive|define
name|XCMS_CIELAB_PMETRIC_HUE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XCMS_CIELUV_PMETRIC_HUE((a), (b))
end_define

begin_define
define|#
directive|define
name|XCMS_CIELAB_PMETRIC_CHROMA
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|XCMS_CIELUV_PMETRIC_CHROMA((a), (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XCMSINT_H_ */
end_comment

end_unit

