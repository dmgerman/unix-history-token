begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Xcms.h,v 1.11 91/01/27 00:31:39 alt Exp  */
end_comment

begin_comment
comment|/*  * Code and supporting documentation (c) Copyright 1990 1991 Tektronix, Inc.  * 	All Rights Reserved  *   * This file is a component of an X Window System-specific implementation  * of Xcms based on the TekColor Color Management System.  Permission is  * hereby granted to use, copy, modify, sell, and otherwise distribute this  * software and its documentation for any purpose and without fee, provided  * that this copyright, permission, and disclaimer notice is reproduced in  * all copies of this software and in supporting documentation.  TekColor  * is a trademark of Tektronix, Inc.  *   * Tektronix makes no representation about the suitability of this software  * for any purpose.  It is provided "as is" and with all faults.  *   * TEKTRONIX DISCLAIMS ALL WARRANTIES APPLICABLE TO THIS SOFTWARE,  * INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE.  IN NO EVENT SHALL TEKTRONIX BE LIABLE FOR ANY  * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER  * RESULTING FROM LOSS OF USE, DATA, OR PROFITS, WHETHER IN AN ACTION OF  * CONTRACT, NEGLIGENCE, OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR THE PERFORMANCE OF THIS SOFTWARE.  *  *  *	DESCRIPTION  *		Public include file for X Color Management System  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XCMS_H_
end_ifndef

begin_define
define|#
directive|define
name|_XCMS_H_
end_define

begin_comment
comment|/*      * XCMS Status Values      */
end_comment

begin_define
define|#
directive|define
name|XcmsFailure
value|0
end_define

begin_define
define|#
directive|define
name|XcmsSuccess
value|1
end_define

begin_define
define|#
directive|define
name|XcmsSuccessWithCompression
value|2
end_define

begin_comment
comment|/*      * Color Space Format ID's      *    Color Space ID's are of XcmsColorFormat type, which is an      *    unsigned short (16 bits).        *      *    bit 15 (most significant bit):      *	    0 == Device-Independent      *	    1 == Device-Dependent      *      *    bit 14:      *	    0 == Registered with X Consortium      *	    1 == Unregistered      */
end_comment

begin_define
define|#
directive|define
name|XcmsUndefinedFormat
value|(XcmsColorFormat)0x00000000
end_define

begin_define
define|#
directive|define
name|XcmsCIEXYZFormat
value|(XcmsColorFormat)0x00000001
end_define

begin_define
define|#
directive|define
name|XcmsCIEuvYFormat
value|(XcmsColorFormat)0x00000002
end_define

begin_define
define|#
directive|define
name|XcmsCIExyYFormat
value|(XcmsColorFormat)0x00000003
end_define

begin_define
define|#
directive|define
name|XcmsCIELabFormat
value|(XcmsColorFormat)0x00000004
end_define

begin_define
define|#
directive|define
name|XcmsCIELuvFormat
value|(XcmsColorFormat)0x00000005
end_define

begin_define
define|#
directive|define
name|XcmsTekHVCFormat
value|(XcmsColorFormat)0x00000006
end_define

begin_define
define|#
directive|define
name|XcmsRGBFormat
value|(XcmsColorFormat)0x80000000
end_define

begin_define
define|#
directive|define
name|XcmsRGBiFormat
value|(XcmsColorFormat)0x80000001
end_define

begin_comment
comment|/*      * State of XcmsPerScrnInfo      */
end_comment

begin_define
define|#
directive|define
name|XcmsInitNone
value|0x00
end_define

begin_comment
comment|/* no initialization attempted */
end_comment

begin_define
define|#
directive|define
name|XcmsInitSuccess
value|0x01
end_define

begin_comment
comment|/* initialization successful */
end_comment

begin_define
define|#
directive|define
name|XcmsInitDefault
value|0xff
end_define

begin_comment
comment|/* initialization failed */
end_comment

begin_define
define|#
directive|define
name|DisplayOfCCC
parameter_list|(
name|ccc
parameter_list|)
value|((ccc)->dpy)
end_define

begin_define
define|#
directive|define
name|ScreenNumberOfCCC
parameter_list|(
name|ccc
parameter_list|)
value|((ccc)->screenNumber)
end_define

begin_define
define|#
directive|define
name|VisualOfCCC
parameter_list|(
name|ccc
parameter_list|)
value|((ccc)->visual)
end_define

begin_define
define|#
directive|define
name|ClientWhitePointOfCCC
parameter_list|(
name|ccc
parameter_list|)
value|(&(ccc)->clientWhitePt)
end_define

begin_define
define|#
directive|define
name|ScreenWhitePointOfCCC
parameter_list|(
name|ccc
parameter_list|)
value|(&(ccc)->pPerScrnInfo->screenWhitePt)
end_define

begin_define
define|#
directive|define
name|FunctionSetOfCCC
parameter_list|(
name|ccc
parameter_list|)
value|((ccc)->pPerScrnInfo->functionSet)
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|XcmsColorFormat
typedef|;
end_typedef

begin_comment
comment|/* Color Space Format ID */
end_comment

begin_typedef
typedef|typedef
name|double
name|XcmsFloat
typedef|;
end_typedef

begin_comment
comment|/*      * Device RGB      */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|red
decl_stmt|;
comment|/* scaled from 0x0000 to 0xffff */
name|unsigned
name|short
name|green
decl_stmt|;
comment|/* scaled from 0x0000 to 0xffff */
name|unsigned
name|short
name|blue
decl_stmt|;
comment|/* scaled from 0x0000 to 0xffff */
block|}
name|XcmsRGB
typedef|;
end_typedef

begin_comment
comment|/*      * RGB Intensity      */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XcmsFloat
name|red
decl_stmt|;
comment|/* 0.0 - 1.0 */
name|XcmsFloat
name|green
decl_stmt|;
comment|/* 0.0 - 1.0 */
name|XcmsFloat
name|blue
decl_stmt|;
comment|/* 0.0 - 1.0 */
block|}
name|XcmsRGBi
typedef|;
end_typedef

begin_comment
comment|/*      * CIE XYZ      */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XcmsFloat
name|X
decl_stmt|;
name|XcmsFloat
name|Y
decl_stmt|;
name|XcmsFloat
name|Z
decl_stmt|;
block|}
name|XcmsCIEXYZ
typedef|;
end_typedef

begin_comment
comment|/*      * CIE u'v'Y      */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XcmsFloat
name|u_prime
decl_stmt|;
comment|/* 0.0 - 1.0 */
name|XcmsFloat
name|v_prime
decl_stmt|;
comment|/* 0.0 - 1.0 */
name|XcmsFloat
name|Y
decl_stmt|;
comment|/* 0.0 - 1.0 */
block|}
name|XcmsCIEuvY
typedef|;
end_typedef

begin_comment
comment|/*      * CIE xyY      */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XcmsFloat
name|x
decl_stmt|;
comment|/* 0.0 - 1.0 */
name|XcmsFloat
name|y
decl_stmt|;
comment|/* 0.0 - 1.0 */
name|XcmsFloat
name|Y
decl_stmt|;
comment|/* 0.0 - 1.0 */
block|}
name|XcmsCIExyY
typedef|;
end_typedef

begin_comment
comment|/*      * CIE L*a*b*      */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XcmsFloat
name|L_star
decl_stmt|;
comment|/* 0.0 - 100.0 */
name|XcmsFloat
name|a_star
decl_stmt|;
name|XcmsFloat
name|b_star
decl_stmt|;
block|}
name|XcmsCIELab
typedef|;
end_typedef

begin_comment
comment|/*      * CIE L*u*v*      */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XcmsFloat
name|L_star
decl_stmt|;
comment|/* 0.0 - 100.0 */
name|XcmsFloat
name|u_star
decl_stmt|;
name|XcmsFloat
name|v_star
decl_stmt|;
block|}
name|XcmsCIELuv
typedef|;
end_typedef

begin_comment
comment|/*      * TekHVC      */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XcmsFloat
name|H
decl_stmt|;
comment|/* 0.0 - 360.0 */
name|XcmsFloat
name|V
decl_stmt|;
comment|/* 0.0 - 100.0 */
name|XcmsFloat
name|C
decl_stmt|;
comment|/* 0.0 - 100.0 */
block|}
name|XcmsTekHVC
typedef|;
end_typedef

begin_comment
comment|/*      * PAD      */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XcmsFloat
name|pad0
decl_stmt|;
name|XcmsFloat
name|pad1
decl_stmt|;
name|XcmsFloat
name|pad2
decl_stmt|;
name|XcmsFloat
name|pad3
decl_stmt|;
block|}
name|XcmsPad
typedef|;
end_typedef

begin_comment
comment|/*      * XCMS Color Structure      */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
union|union
block|{
name|XcmsRGB
name|RGB
decl_stmt|;
name|XcmsRGBi
name|RGBi
decl_stmt|;
name|XcmsCIEXYZ
name|CIEXYZ
decl_stmt|;
name|XcmsCIEuvY
name|CIEuvY
decl_stmt|;
name|XcmsCIExyY
name|CIExyY
decl_stmt|;
name|XcmsCIELab
name|CIELab
decl_stmt|;
name|XcmsCIELuv
name|CIELuv
decl_stmt|;
name|XcmsTekHVC
name|TekHVC
decl_stmt|;
name|XcmsPad
name|Pad
decl_stmt|;
block|}
name|spec
union|;
comment|/* the color specification	*/
name|unsigned
name|long
name|pixel
decl_stmt|;
comment|/* pixel value (as needed)	*/
name|XcmsColorFormat
name|format
decl_stmt|;
comment|/* the specification format	*/
block|}
name|XcmsColor
typedef|;
end_typedef

begin_comment
comment|/*      * XCMS Per Screen related data      */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XcmsPerScrnInfo
block|{
name|XcmsColor
name|screenWhitePt
decl_stmt|;
comment|/* Screen White point */
name|XPointer
name|functionSet
decl_stmt|;
comment|/* pointer to Screen Color Characterization */
comment|/*      Function Set structure		*/
name|XPointer
name|screenData
decl_stmt|;
comment|/* pointer to corresponding Screen Color*/
comment|/*	Characterization Data		*/
name|unsigned
name|char
name|state
decl_stmt|;
comment|/* XcmsInitNone, XcmsInitSuccess, XcmsInitDefault */
name|char
name|pad
index|[
literal|3
index|]
decl_stmt|;
block|}
name|XcmsPerScrnInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XcmsCCC
modifier|*
name|XcmsCCC
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Status
function_decl|(
modifier|*
name|XcmsCompressionProc
function_decl|)
parameter_list|(
comment|/* Gamut Compression Proc */
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors_in_out */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|unsigned
name|int
comment|/* index */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|Status
function_decl|(
modifier|*
name|XcmsWhiteAdjustProc
function_decl|)
parameter_list|(
comment|/* White Point Adjust Proc */
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* initial_white_point*/
parameter_list|,
name|XcmsColor
modifier|*
comment|/* target_white_point*/
parameter_list|,
name|XcmsColorFormat
comment|/* target_format */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors_in_out */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*      * XCMS Color Conversion Context      */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XcmsCCC
block|{
name|Display
modifier|*
name|dpy
decl_stmt|;
comment|/* X Display */
name|int
name|screenNumber
decl_stmt|;
comment|/* X screen number */
name|Visual
modifier|*
name|visual
decl_stmt|;
comment|/* X Visual */
name|XcmsColor
name|clientWhitePt
decl_stmt|;
comment|/* Client White Point */
name|XcmsCompressionProc
name|gamutCompProc
decl_stmt|;
comment|/* Gamut Compression Function */
name|XPointer
name|gamutCompClientData
decl_stmt|;
comment|/* Gamut Comp Func Client Data */
name|XcmsWhiteAdjustProc
name|whitePtAdjProc
decl_stmt|;
comment|/* White Point Adjustment Function */
name|XPointer
name|whitePtAdjClientData
decl_stmt|;
comment|/* White Pt Adj Func Client Data */
name|XcmsPerScrnInfo
modifier|*
name|pPerScrnInfo
decl_stmt|;
comment|/* pointer to per screen information */
comment|/*  associated with the above display */
comment|/*  screenNumber */
block|}
name|XcmsCCCRec
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Status
function_decl|(
modifier|*
name|XcmsScreenInitProc
function_decl|)
parameter_list|(
comment|/* Screen Initialization Proc */
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|int
comment|/* screen_number */
parameter_list|,
name|XcmsPerScrnInfo
modifier|*
comment|/* screen_info */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XcmsScreenFreeProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XPointer
comment|/* screenData */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*      * Function List Pointer -- pointer to an array of function pointers.      *    The end of list is indicated by a NULL pointer.      */
end_comment

begin_typedef
typedef|typedef
name|Status
function_decl|(
modifier|*
name|XcmsConversionProc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|XcmsConversionProc
modifier|*
name|XcmsFuncListPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|XcmsParseStringProc
function_decl|)
parameter_list|(
comment|/* Color String Parsing Proc */
if|#
directive|if
name|NeedFunctionPrototypes
name|char
modifier|*
comment|/* color_string */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*      * Color Space -- per Color Space related data (Device-Independent      *    or Device-Dependent)      */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XcmsColorSpace
block|{
name|char
modifier|*
name|prefix
decl_stmt|;
comment|/* Prefix of string format.		*/
name|XcmsColorFormat
name|id
decl_stmt|;
comment|/* Format ID number.			*/
name|XcmsParseStringProc
name|parseString
decl_stmt|;
comment|/* String format parsing function	*/
name|XcmsFuncListPtr
name|to_CIEXYZ
decl_stmt|;
comment|/* Pointer to an array of function 	*/
comment|/*   pointers such that when the	*/
comment|/*   functions are executed in sequence	*/
comment|/*   will convert a XcmsColor structure	*/
comment|/*   from this color space to CIEXYZ	*/
comment|/*   space.				*/
name|XcmsFuncListPtr
name|from_CIEXYZ
decl_stmt|;
comment|/* Pointer to an array of function 	*/
comment|/*   pointers such that when the	*/
comment|/*   functions are executed in sequence	*/
comment|/*   will convert a XcmsColor structure	*/
comment|/*   from CIEXYZ space to this color	*/
comment|/*   space.				*/
name|int
name|inverse_flag
decl_stmt|;
comment|/* If 1, indicates that for 0<= i< n	*/
comment|/*   where n is the number of function	*/
comment|/*   pointers in the lists to_CIEXYZ	*/
comment|/*   and from_CIEXYZ; for each function */
comment|/*   to_CIEXYZ[i] its inverse function	*/
comment|/*   is from_CIEXYZ[n - i].		*/
block|}
name|XcmsColorSpace
typedef|;
end_typedef

begin_comment
comment|/*      * Screen Color Characterization Function Set -- per device class      *    color space conversion functions.      */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XcmsFunctionSet
block|{
name|XcmsColorSpace
modifier|*
modifier|*
name|DDColorSpaces
decl_stmt|;
comment|/* Pointer to an array of pointers to	*/
comment|/*   Device-DEPENDENT color spaces	*/
comment|/*   understood by this SCCFuncSet.	*/
name|XcmsScreenInitProc
name|screenInitProc
decl_stmt|;
comment|/* Screen initialization function that	*/
comment|/*   reads Screen Color Characterization*/
comment|/*   Data off properties on the screen's*/
comment|/*   root window.			*/
name|XcmsScreenFreeProc
name|screenFreeProc
decl_stmt|;
comment|/* Function that frees the SCCData	*/
comment|/*   structures.			*/
block|}
name|XcmsFunctionSet
typedef|;
end_typedef

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|Status
name|XcmsAddColorSpace
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsColorSpace
modifier|*
comment|/* pColorSpace */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsAddFunctionSett
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsFunctionSet
modifier|*
comment|/* functionSet */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsAllocColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Colormap
comment|/* colormap */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_in_out */
parameter_list|,
name|XcmsColorFormat
comment|/* result_format */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsAllocNamedColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Colormap
comment|/* colormap */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* color_string */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_scrn_return */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_exact_return */
parameter_list|,
name|XcmsColorFormat
comment|/* result_format */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XcmsCCC
name|XcmsCCCOfColormap
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Colormap
comment|/* colormap */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELabClipab
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors_in_out */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|unsigned
name|int
comment|/* index */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELabClipL
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors_in_out */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|unsigned
name|int
comment|/* index */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELabClipLab
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors_in_out */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|unsigned
name|int
comment|/* index */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELabQueryMaxC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsFloat
comment|/* hue_angle */
parameter_list|,
name|XcmsFloat
comment|/* L_star */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELabQueryMaxL
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsFloat
comment|/* hue_angle */
parameter_list|,
name|XcmsFloat
comment|/* chroma */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELabQueryMaxLC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsFloat
comment|/* hue_angle */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELabQueryMinL
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsFloat
comment|/* hue_angle */
parameter_list|,
name|XcmsFloat
comment|/* chroma */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELabToCIEXYZ
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* white_point */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELabWhiteShiftColors
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* initial_white_point*/
parameter_list|,
name|XcmsColor
modifier|*
comment|/* target_white_point*/
parameter_list|,
name|XcmsColorFormat
comment|/* target_format */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors_in_out */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELuvClipL
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors_in_out */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|unsigned
name|int
comment|/* index */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELuvClipLuv
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors_in_out */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|unsigned
name|int
comment|/* index */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELuvClipuv
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors_in_out */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|unsigned
name|int
comment|/* index */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELuvQueryMaxC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsFloat
comment|/* hue_angle */
parameter_list|,
name|XcmsFloat
comment|/* L_star */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELuvQueryMaxL
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsFloat
comment|/* hue_angle */
parameter_list|,
name|XcmsFloat
comment|/* chroma */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELuvQueryMaxLC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsFloat
comment|/* hue_angle */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELuvQueryMinL
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsFloat
comment|/* hue_angle */
parameter_list|,
name|XcmsFloat
comment|/* chroma */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELuvToCIEuvY
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* white_point */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIELuvWhiteShiftColors
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* initial_white_point*/
parameter_list|,
name|XcmsColor
modifier|*
comment|/* target_white_point*/
parameter_list|,
name|XcmsColorFormat
comment|/* target_format */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors_in_out */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIEXYZToCIELab
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* white_point */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIEXYZToCIEuvY
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* white_point */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIEXYZToCIExyY
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* white_point */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIEXYZToRGBi
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIEuvYToCIELuv
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* white_point */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIEuvYToCIEXYZ
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* white_point */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIEuvYToTekHVC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* white_point */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsCIExyYToCIEXYZ
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* white_point */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XcmsColor
modifier|*
name|XcmsClientWhitePointOfCCC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsConvertColors
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colorArry_in_out */
parameter_list|,
name|unsigned
name|int
comment|/* nColors */
parameter_list|,
name|XcmsColorFormat
comment|/* targetFormat */
parameter_list|,
name|Bool
modifier|*
comment|/* compArry_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XcmsCCC
name|XcmsCreateCCC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|int
comment|/* screenNumber */
parameter_list|,
name|Visual
modifier|*
comment|/* visual */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* clientWhitePt */
parameter_list|,
name|XcmsCompressionProc
comment|/* gamutCompProc */
parameter_list|,
name|XPointer
comment|/* gamutCompClientData */
parameter_list|,
name|XcmsWhiteAdjustProc
comment|/* whitePtAdjProc */
parameter_list|,
name|XPointer
comment|/* whitePtAdjClientData */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XcmsCCC
name|XcmsDefaultCCC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|int
comment|/* screenNumber */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Display
modifier|*
name|XcmsDisplayOfCCC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XcmsColorFormat
name|XcmsFormatOfPrefix
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|char
modifier|*
comment|/* prefix */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XcmsFreeCCC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsLookupColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Colormap
comment|/* colormap */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* color_string */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* pColor_exact_in_out */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* pColor_scrn_in_out */
parameter_list|,
name|XcmsColorFormat
comment|/* result_format */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XcmsPrefixOfFormat
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsColorFormat
comment|/* id */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsQueryBlack
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColorFormat
comment|/* target_format */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsQueryBlue
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColorFormat
comment|/* target_format */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsQueryColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Colormap
comment|/* colormap */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* pColor_in_out */
parameter_list|,
name|XcmsColorFormat
comment|/* result_format */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsQueryColors
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Colormap
comment|/* colormap */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colorArry_in_out */
parameter_list|,
name|unsigned
name|int
comment|/* nColors */
parameter_list|,
name|XcmsColorFormat
comment|/* result_format */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsQueryGreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColorFormat
comment|/* target_format */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsQueryRed
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColorFormat
comment|/* target_format */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsQueryWhite
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColorFormat
comment|/* target_format */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsRGBiToCIEXYZ
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsRGBiToRGB
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsRGBToRGBi
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XcmsScreenNumberOfCCC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XcmsColor
modifier|*
name|XcmsScreenWhitePointOfCCC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XcmsCCC
name|XcmsSetCCCOfColormap
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Colormap
comment|/* colormap */
parameter_list|,
name|XcmsCCC
comment|/* ccc */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XcmsCompressionProc
name|XcmsSetCompressionProc
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsCompressionProc
comment|/* compression_proc */
parameter_list|,
name|XPointer
comment|/* client_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XcmsWhiteAdjustProc
name|XcmsSetWhiteAdjustProc
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsWhiteAdjustProc
comment|/* white_adjust_proc */
parameter_list|,
name|XPointer
comment|/* client_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsSetWhitePoint
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsStoreColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Colormap
comment|/* colormap */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* pColor_in */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsStoreColors
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Colormap
comment|/* colormap */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colorArry_in */
parameter_list|,
name|unsigned
name|int
comment|/* nColors */
parameter_list|,
name|Bool
modifier|*
comment|/* compArry_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsTekHVCClipC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors_in_out */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|unsigned
name|int
comment|/* index */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsTekHVCClipV
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors_in_out */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|unsigned
name|int
comment|/* index */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsTekHVCClipVC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors_in_out */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|unsigned
name|int
comment|/* index */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsTekHVCQueryMaxC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsFloat
comment|/* hue */
parameter_list|,
name|XcmsFloat
comment|/* value */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsTekHVCQueryMaxV
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsFloat
comment|/* hue */
parameter_list|,
name|XcmsFloat
comment|/* chroma */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsTekHVCQueryMaxVC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsFloat
comment|/* hue */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsTekHVCQueryMaxVSamples
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsFloat
comment|/* hue */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors_return */
parameter_list|,
name|unsigned
name|int
comment|/* nsamples */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsTekHVCQueryMinV
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsFloat
comment|/* hue */
parameter_list|,
name|XcmsFloat
comment|/* chroma */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* color_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsTekHVCToCIEuvY
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* white_point */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XcmsTekHVCWhiteShiftColors
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* initial_white_point*/
parameter_list|,
name|XcmsColor
modifier|*
comment|/* target_white_point*/
parameter_list|,
name|XcmsColorFormat
comment|/* target_format */
parameter_list|,
name|XcmsColor
modifier|*
comment|/* colors_in_out */
parameter_list|,
name|unsigned
name|int
comment|/* ncolors */
parameter_list|,
name|Bool
modifier|*
comment|/* compression_flags_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Visual
modifier|*
name|XcmsVisualOfCCC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XcmsCCC
comment|/* ccc */
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
comment|/* _XCMS_H_ */
end_comment

end_unit

