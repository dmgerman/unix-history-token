begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_PEXLIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_PEXLIB_H_
end_define

begin_comment
comment|/* $XConsortium: PEXlib.h,v 1.10 92/10/27 15:42:37 mor Exp $ */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_comment
comment|/*  Copyright 1987,1991 by Digital Equipment Corporation, Maynard, Mass.      */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*  (c) Copyright Hewlett-Packard Company, 1992,  Fort Collins, Colorado      */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*                            All Rights Reserved                             */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*  Permission to use, copy, modify, and distribute this software and its     */
end_comment

begin_comment
comment|/*  documentation for any purpose and without fee is hereby granted,          */
end_comment

begin_comment
comment|/*  provided that the above copyright notices appear in all copies and that   */
end_comment

begin_comment
comment|/*  both the copyright notices and this permission notice appear in           */
end_comment

begin_comment
comment|/*  supporting documentation, and that the names of Digital or                */
end_comment

begin_comment
comment|/*  Hewlett-Packard not be used in advertising or publicity pertaining to     */
end_comment

begin_comment
comment|/*  distribution of the software without specific, written prior permission.  */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*  DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING  */
end_comment

begin_comment
comment|/*  ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL  */
end_comment

begin_comment
comment|/*  DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR   */
end_comment

begin_comment
comment|/*  ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,       */
end_comment

begin_comment
comment|/*  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,    */
end_comment

begin_comment
comment|/*  ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS       */
end_comment

begin_comment
comment|/*  SOFTWARE.                                                                 */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*  HEWLETT-PACKARD MAKES NO WARRANTY OF ANY KIND WITH REGARD TO THIS         */
end_comment

begin_comment
comment|/*  SOFTWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF        */
end_comment

begin_comment
comment|/*  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  Hewlett-Packard    */
end_comment

begin_comment
comment|/*  shall not be liable for errors contained herein or direct, indirect,      */
end_comment

begin_comment
comment|/*  special, incidental or consequential damages in connection with the       */
end_comment

begin_comment
comment|/*  furnishing, performance or use of this software.                          */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include

begin_include
include|#
directive|include
file|<X11/PEX5/PEX.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NeedFunctionPrototypes
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FUNCPROTO
argument_list|)
operator|||
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|c_plusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|NeedFunctionPrototypes
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NeedFunctionPrototypes
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FUNCPROTO, __STDC__, __cplusplus, c_plusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NeedFunctionPrototypes */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_comment
comment|/* do not leave open across includes */
end_comment

begin_extern
extern|extern
literal|"C"
block|{
comment|/* for C++ V2.0 */
endif|#
directive|endif
comment|/*  * floating point min and max values  */
define|#
directive|define
name|PEXMinFloatIeee_754_32
value|1.40129846432481707e-45
define|#
directive|define
name|PEXMaxFloatIeee_754_32
value|3.40282346638528860e+38
define|#
directive|define
name|PEXMinFloatIeee_754_64
value|4.94065645841246544e-324
define|#
directive|define
name|PEXMaxFloatIeee_754_64
value|1.797693134862315708e+308
comment|/*  * constants for PEXInitiliaze - failure return values and error string length  */
define|#
directive|define
name|PEXBadExtension
value|1
define|#
directive|define
name|PEXBadProtocolVersion
value|2
define|#
directive|define
name|PEXBadFloatConversion
value|3
define|#
directive|define
name|PEXBadLocalAlloc
value|4
define|#
directive|define
name|PEXErrorStringLength
value|80
comment|/*  * type definitions  */
typedef|typedef
name|XID
name|PEXFont
typedef|;
typedef|typedef
name|XID
name|PEXLookupTable
typedef|;
typedef|typedef
name|XID
name|PEXNameSet
typedef|;
typedef|typedef
name|XID
name|PEXPickMeasure
typedef|;
typedef|typedef
name|XID
name|PEXPipelineContext
typedef|;
typedef|typedef
name|XID
name|PEXRenderer
typedef|;
typedef|typedef
name|XID
name|PEXSearchContext
typedef|;
typedef|typedef
name|XID
name|PEXStructure
typedef|;
typedef|typedef
name|XID
name|PEXWorkstation
typedef|;
typedef|typedef
name|unsigned
name|long
name|PEXBitmask
typedef|;
typedef|typedef
name|unsigned
name|short
name|PEXBitmaskShort
typedef|;
typedef|typedef
name|short
name|PEXColorType
typedef|;
typedef|typedef
name|unsigned
name|char
name|PEXContourHint
typedef|;
typedef|typedef
name|unsigned
name|short
name|PEXCoordType
typedef|;
typedef|typedef
name|short
name|PEXComposition
typedef|;
typedef|typedef
name|unsigned
name|short
name|PEXCullMode
typedef|;
typedef|typedef
name|unsigned
name|char
name|PEXDynamicType
typedef|;
typedef|typedef
name|short
name|PEXEnumTypeIndex
typedef|;
typedef|typedef
name|float
name|PEXMatrix
index|[
literal|4
index|]
index|[
literal|4
index|]
typedef|;
typedef|typedef
name|float
name|PEXMatrix3x3
index|[
literal|3
index|]
index|[
literal|3
index|]
typedef|;
typedef|typedef
name|unsigned
name|long
name|PEXName
typedef|;
typedef|typedef
name|int
name|PEXOCRequestType
typedef|;
typedef|typedef
name|unsigned
name|short
name|PEXShapeHint
typedef|;
typedef|typedef
name|unsigned
name|char
name|PEXSwitch
typedef|;
typedef|typedef
name|unsigned
name|short
name|PEXTableIndex
typedef|;
typedef|typedef
name|unsigned
name|short
name|PEXTypeOrTableIndex
typedef|;
if|#
directive|if
name|NeedFunctionPrototypes
typedef|typedef
name|void
modifier|*
name|PEXPointer
typedef|;
else|#
directive|else
typedef|typedef
name|char
modifier|*
name|PEXPointer
typedef|;
endif|#
directive|endif
comment|/*  * PEX extension information  */
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|major_version
decl_stmt|;
name|unsigned
name|short
name|minor_version
decl_stmt|;
name|unsigned
name|long
name|release
decl_stmt|;
name|unsigned
name|long
name|subset_info
decl_stmt|;
name|char
modifier|*
name|vendor_name
decl_stmt|;
name|int
name|major_opcode
decl_stmt|;
name|int
name|first_event
decl_stmt|;
name|int
name|first_error
decl_stmt|;
block|}
name|PEXExtensionInfo
typedef|;
comment|/*  * enumerated type information  */
typedef|typedef
struct|struct
block|{
name|PEXEnumTypeIndex
name|index
decl_stmt|;
name|char
modifier|*
name|descriptor
decl_stmt|;
comment|/* null terminated string */
block|}
name|PEXEnumTypeDesc
typedef|;
comment|/*  * implementation dependent constants  */
typedef|typedef
union|union
block|{
name|unsigned
name|long
name|integer
decl_stmt|;
name|float
name|flt_point
decl_stmt|;
block|}
name|PEXImpDepConstant
typedef|;
comment|/*  * match rendering targets  */
typedef|typedef
struct|struct
block|{
name|int
name|depth
decl_stmt|;
name|int
name|type
decl_stmt|;
name|Visual
modifier|*
name|visual
decl_stmt|;
block|}
name|PEXRenderingTarget
typedef|;
comment|/*  * output primitive and attribute  */
comment|/* output command request types */
define|#
directive|define
name|PEXOCRender
value|0
define|#
directive|define
name|PEXOCStore
value|1
define|#
directive|define
name|PEXOCRenderSingle
value|2
define|#
directive|define
name|PEXOCStoreSingle
value|3
comment|/* coordinates */
typedef|typedef
struct|struct
block|{
name|float
name|x
decl_stmt|;
name|float
name|y
decl_stmt|;
name|float
name|z
decl_stmt|;
block|}
name|PEXCoord
typedef|;
typedef|typedef
struct|struct
block|{
name|float
name|x
decl_stmt|;
name|float
name|y
decl_stmt|;
block|}
name|PEXCoord2D
typedef|;
typedef|typedef
struct|struct
block|{
name|float
name|x
decl_stmt|;
name|float
name|y
decl_stmt|;
name|float
name|z
decl_stmt|;
name|float
name|w
decl_stmt|;
block|}
name|PEXCoord4D
typedef|;
comment|/* coordinate lists without data */
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|count
decl_stmt|;
comment|/* number of points */
name|PEXCoord2D
modifier|*
name|points
decl_stmt|;
block|}
name|PEXListOfCoord2D
typedef|;
comment|/* Pointer to an array of 2D points */
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|count
decl_stmt|;
comment|/* number of points */
name|PEXCoord
modifier|*
name|points
decl_stmt|;
block|}
name|PEXListOfCoord
typedef|;
comment|/* Pointer to an array of 3D points */
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|count
decl_stmt|;
comment|/* number of points */
name|PEXCoord4D
modifier|*
name|points
decl_stmt|;
block|}
name|PEXListOfCoord4D
typedef|;
comment|/* Pointer to an array of 4D points */
typedef|typedef
union|union
block|{
name|PEXCoord2D
modifier|*
name|point_2d
decl_stmt|;
name|PEXCoord
modifier|*
name|point
decl_stmt|;
name|PEXCoord4D
modifier|*
name|point_4d
decl_stmt|;
block|}
name|PEXArrayOfCoord
typedef|;
comment|/* Pointer to array of points */
comment|/* colors */
typedef|typedef
struct|struct
block|{
name|float
name|red
decl_stmt|;
name|float
name|green
decl_stmt|;
name|float
name|blue
decl_stmt|;
block|}
name|PEXColorRGB
typedef|;
typedef|typedef
struct|struct
block|{
name|float
name|hue
decl_stmt|;
name|float
name|saturation
decl_stmt|;
name|float
name|value
decl_stmt|;
block|}
name|PEXColorHSV
typedef|;
typedef|typedef
struct|struct
block|{
name|float
name|hue
decl_stmt|;
name|float
name|lightness
decl_stmt|;
name|float
name|saturation
decl_stmt|;
block|}
name|PEXColorHLS
typedef|;
typedef|typedef
struct|struct
block|{
name|float
name|x
decl_stmt|;
name|float
name|y
decl_stmt|;
name|float
name|z
decl_stmt|;
block|}
name|PEXColorCIE
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|red
decl_stmt|;
name|unsigned
name|char
name|green
decl_stmt|;
name|unsigned
name|char
name|blue
decl_stmt|;
name|unsigned
name|char
name|reserved
decl_stmt|;
block|}
name|PEXColorRGB8
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|red
decl_stmt|;
name|unsigned
name|short
name|green
decl_stmt|;
name|unsigned
name|short
name|blue
decl_stmt|;
name|unsigned
name|short
name|reserved
decl_stmt|;
block|}
name|PEXColorRGB16
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXTableIndex
name|index
decl_stmt|;
name|unsigned
name|short
name|reserved
decl_stmt|;
block|}
name|PEXColorIndexed
typedef|;
typedef|typedef
union|union
block|{
name|PEXColorIndexed
name|indexed
decl_stmt|;
name|PEXColorRGB
name|rgb
decl_stmt|;
name|PEXColorHSV
name|hsv
decl_stmt|;
name|PEXColorHLS
name|hls
decl_stmt|;
name|PEXColorCIE
name|cie
decl_stmt|;
name|PEXColorRGB8
name|rgb8
decl_stmt|;
name|PEXColorRGB16
name|rgb16
decl_stmt|;
block|}
name|PEXColor
typedef|;
typedef|typedef
union|union
block|{
name|PEXColorIndexed
modifier|*
name|indexed
decl_stmt|;
name|PEXColorRGB
modifier|*
name|rgb
decl_stmt|;
name|PEXColorHSV
modifier|*
name|hsv
decl_stmt|;
name|PEXColorHLS
modifier|*
name|hls
decl_stmt|;
name|PEXColorCIE
modifier|*
name|cie
decl_stmt|;
name|PEXColorRGB8
modifier|*
name|rgb8
decl_stmt|;
name|PEXColorRGB16
modifier|*
name|rgb16
decl_stmt|;
block|}
name|PEXArrayOfColor
typedef|;
comment|/* vectors */
typedef|typedef
struct|struct
block|{
name|float
name|x
decl_stmt|;
name|float
name|y
decl_stmt|;
name|float
name|z
decl_stmt|;
block|}
name|PEXVector
typedef|;
typedef|typedef
struct|struct
block|{
name|float
name|x
decl_stmt|;
name|float
name|y
decl_stmt|;
block|}
name|PEXVector2D
typedef|;
comment|/* facet data */
typedef|typedef
struct|struct
block|{
name|PEXColorIndexed
name|index
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
block|}
name|PEXColorIndexedNormal
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXColorRGB
name|rgb
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
block|}
name|PEXColorRGBNormal
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXColorCIE
name|cie
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
block|}
name|PEXColorCIENormal
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXColorHSV
name|hsv
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
block|}
name|PEXColorHSVNormal
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXColorHLS
name|hls
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
block|}
name|PEXColorHLSNormal
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXColorRGB8
name|rgb8
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
block|}
name|PEXColorRGB8Normal
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXColorRGB16
name|rgb16
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
block|}
name|PEXColorRGB16Normal
typedef|;
typedef|typedef
union|union
block|{
name|PEXColorIndexed
name|index
decl_stmt|;
name|PEXColorRGB
name|rgb
decl_stmt|;
name|PEXColorHSV
name|hsv
decl_stmt|;
name|PEXColorHLS
name|hls
decl_stmt|;
name|PEXColorCIE
name|cie
decl_stmt|;
name|PEXColorRGB8
name|rgb8
decl_stmt|;
name|PEXColorRGB16
name|rgb16
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
name|PEXColorIndexedNormal
name|index_normal
decl_stmt|;
name|PEXColorRGBNormal
name|rgb_normal
decl_stmt|;
name|PEXColorHSVNormal
name|hsv_normal
decl_stmt|;
name|PEXColorHLSNormal
name|hls_normal
decl_stmt|;
name|PEXColorCIENormal
name|cie_normal
decl_stmt|;
name|PEXColorRGB8Normal
name|rgb8_normal
decl_stmt|;
name|PEXColorRGB16Normal
name|rgb16_normal
decl_stmt|;
block|}
name|PEXFacetData
typedef|;
typedef|typedef
union|union
block|{
name|PEXColorIndexed
modifier|*
name|index
decl_stmt|;
name|PEXColorRGB
modifier|*
name|rgb
decl_stmt|;
name|PEXColorHSV
modifier|*
name|hsv
decl_stmt|;
name|PEXColorHLS
modifier|*
name|hls
decl_stmt|;
name|PEXColorCIE
modifier|*
name|cie
decl_stmt|;
name|PEXColorRGB8
modifier|*
name|rgb8
decl_stmt|;
name|PEXColorRGB16
modifier|*
name|rgb16
decl_stmt|;
name|PEXVector
modifier|*
name|normal
decl_stmt|;
name|PEXColorIndexedNormal
modifier|*
name|index_normal
decl_stmt|;
name|PEXColorRGBNormal
modifier|*
name|rgb_normal
decl_stmt|;
name|PEXColorCIENormal
modifier|*
name|cie_normal
decl_stmt|;
name|PEXColorHSVNormal
modifier|*
name|hsv_normal
decl_stmt|;
name|PEXColorHLSNormal
modifier|*
name|hls_normal
decl_stmt|;
name|PEXColorRGB8Normal
modifier|*
name|rgb8_normal
decl_stmt|;
name|PEXColorRGB16Normal
modifier|*
name|rgb16_normal
decl_stmt|;
block|}
name|PEXArrayOfFacetData
typedef|;
comment|/* vertex data */
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorIndexed
name|index
decl_stmt|;
block|}
name|PEXVertexIndexed
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorRGB
name|rgb
decl_stmt|;
block|}
name|PEXVertexRGB
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorHSV
name|hsv
decl_stmt|;
block|}
name|PEXVertexHSV
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorHLS
name|hls
decl_stmt|;
block|}
name|PEXVertexHLS
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorCIE
name|cie
decl_stmt|;
block|}
name|PEXVertexCIE
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorRGB8
name|rgb8
decl_stmt|;
block|}
name|PEXVertexRGB8
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorRGB16
name|rgb16
decl_stmt|;
block|}
name|PEXVertexRGB16
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
block|}
name|PEXVertexNormal
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|unsigned
name|int
name|edge
decl_stmt|;
block|}
name|PEXVertexEdge
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorIndexed
name|index
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
block|}
name|PEXVertexIndexedNormal
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorRGB
name|rgb
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
block|}
name|PEXVertexRGBNormal
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorHSV
name|hsv
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
block|}
name|PEXVertexHSVNormal
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorHLS
name|hls
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
block|}
name|PEXVertexHLSNormal
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorCIE
name|cie
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
block|}
name|PEXVertexCIENormal
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorRGB8
name|rgb8
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
block|}
name|PEXVertexRGB8Normal
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorRGB16
name|rgb16
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
block|}
name|PEXVertexRGB16Normal
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorIndexed
name|index
decl_stmt|;
name|unsigned
name|int
name|edge
decl_stmt|;
block|}
name|PEXVertexIndexedEdge
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorRGB
name|rgb
decl_stmt|;
name|unsigned
name|int
name|edge
decl_stmt|;
block|}
name|PEXVertexRGBEdge
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorHSV
name|hsv
decl_stmt|;
name|unsigned
name|int
name|edge
decl_stmt|;
block|}
name|PEXVertexHSVEdge
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorHLS
name|hls
decl_stmt|;
name|unsigned
name|int
name|edge
decl_stmt|;
block|}
name|PEXVertexHLSEdge
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorCIE
name|cie
decl_stmt|;
name|unsigned
name|int
name|edge
decl_stmt|;
block|}
name|PEXVertexCIEEdge
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorRGB8
name|rgb8
decl_stmt|;
name|unsigned
name|int
name|edge
decl_stmt|;
block|}
name|PEXVertexRGB8Edge
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorRGB16
name|rgb16
decl_stmt|;
name|unsigned
name|int
name|edge
decl_stmt|;
block|}
name|PEXVertexRGB16Edge
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
name|unsigned
name|int
name|edge
decl_stmt|;
block|}
name|PEXVertexNormalEdge
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorIndexed
name|index
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
name|unsigned
name|int
name|edge
decl_stmt|;
block|}
name|PEXVertexIndexedNormalEdge
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorRGB
name|rgb
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
name|unsigned
name|int
name|edge
decl_stmt|;
block|}
name|PEXVertexRGBNormalEdge
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorHSV
name|hsv
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
name|unsigned
name|int
name|edge
decl_stmt|;
block|}
name|PEXVertexHSVNormalEdge
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorHLS
name|hls
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
name|unsigned
name|int
name|edge
decl_stmt|;
block|}
name|PEXVertexHLSNormalEdge
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorCIE
name|cie
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
name|unsigned
name|int
name|edge
decl_stmt|;
block|}
name|PEXVertexCIENormalEdge
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorRGB8
name|rgb8
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
name|unsigned
name|int
name|edge
decl_stmt|;
block|}
name|PEXVertexRGB8NormalEdge
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXColorRGB16
name|rgb16
decl_stmt|;
name|PEXVector
name|normal
decl_stmt|;
name|unsigned
name|int
name|edge
decl_stmt|;
block|}
name|PEXVertexRGB16NormalEdge
typedef|;
typedef|typedef
union|union
block|{
name|PEXCoord
modifier|*
name|no_data
decl_stmt|;
name|PEXVertexIndexed
modifier|*
name|index
decl_stmt|;
name|PEXVertexRGB
modifier|*
name|rgb
decl_stmt|;
name|PEXVertexHSV
modifier|*
name|hsv
decl_stmt|;
name|PEXVertexHLS
modifier|*
name|hls
decl_stmt|;
name|PEXVertexCIE
modifier|*
name|cie
decl_stmt|;
name|PEXVertexRGB8
modifier|*
name|rgb8
decl_stmt|;
name|PEXVertexRGB16
modifier|*
name|rgb16
decl_stmt|;
name|PEXVertexNormal
modifier|*
name|normal
decl_stmt|;
name|PEXVertexEdge
modifier|*
name|edge
decl_stmt|;
name|PEXVertexIndexedNormal
modifier|*
name|index_normal
decl_stmt|;
name|PEXVertexRGBNormal
modifier|*
name|rgb_normal
decl_stmt|;
name|PEXVertexHSVNormal
modifier|*
name|hsv_normal
decl_stmt|;
name|PEXVertexHLSNormal
modifier|*
name|hls_normal
decl_stmt|;
name|PEXVertexCIENormal
modifier|*
name|cie_normal
decl_stmt|;
name|PEXVertexRGB8Normal
modifier|*
name|rgb8_normal
decl_stmt|;
name|PEXVertexRGB16Normal
modifier|*
name|rgb16_normal
decl_stmt|;
name|PEXVertexIndexedEdge
modifier|*
name|index_edge
decl_stmt|;
name|PEXVertexRGBEdge
modifier|*
name|rgb_edge
decl_stmt|;
name|PEXVertexHSVEdge
modifier|*
name|hsv_edge
decl_stmt|;
name|PEXVertexHLSEdge
modifier|*
name|hls_edge
decl_stmt|;
name|PEXVertexCIEEdge
modifier|*
name|cie_edge
decl_stmt|;
name|PEXVertexRGB8Edge
modifier|*
name|rgb8_edge
decl_stmt|;
name|PEXVertexRGB16Edge
modifier|*
name|rgb16_edge
decl_stmt|;
name|PEXVertexNormalEdge
modifier|*
name|normal_edge
decl_stmt|;
name|PEXVertexIndexedNormalEdge
modifier|*
name|index_normal_edge
decl_stmt|;
name|PEXVertexRGBNormalEdge
modifier|*
name|rgb_normal_edge
decl_stmt|;
name|PEXVertexHSVNormalEdge
modifier|*
name|hsv_normal_edge
decl_stmt|;
name|PEXVertexHLSNormalEdge
modifier|*
name|hls_normal_edge
decl_stmt|;
name|PEXVertexCIENormalEdge
modifier|*
name|cie_normal_edge
decl_stmt|;
name|PEXVertexRGB8NormalEdge
modifier|*
name|rgb8_normal_edge
decl_stmt|;
name|PEXVertexRGB16NormalEdge
modifier|*
name|rgb16_normal_edge
decl_stmt|;
block|}
name|PEXArrayOfVertex
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|count
decl_stmt|;
comment|/* number of vertices */
name|PEXArrayOfVertex
name|vertices
decl_stmt|;
comment|/* pointer to vertices */
block|}
name|PEXListOfVertex
typedef|;
comment|/* connectivity list for set of fill area sets */
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of shorts */
name|unsigned
name|short
modifier|*
name|shorts
decl_stmt|;
block|}
name|PEXListOfUShort
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of lists */
name|PEXListOfUShort
modifier|*
name|lists
decl_stmt|;
block|}
name|PEXConnectivityData
typedef|;
comment|/* encoded text */
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|character_set
decl_stmt|;
name|unsigned
name|char
name|character_set_width
decl_stmt|;
name|unsigned
name|char
name|encoding_state
decl_stmt|;
name|unsigned
name|short
name|reserved
decl_stmt|;
name|unsigned
name|short
name|length
decl_stmt|;
name|char
modifier|*
name|ch
decl_stmt|;
block|}
name|PEXEncodedTextData
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of encodings */
name|PEXEncodedTextData
modifier|*
name|encoded_text
decl_stmt|;
block|}
name|PEXListOfEncodedText
typedef|;
comment|/* trimming curves */
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of floats */
name|float
modifier|*
name|floats
decl_stmt|;
block|}
name|PEXListOfFloat
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXSwitch
name|visibility
decl_stmt|;
name|unsigned
name|char
name|reserved
decl_stmt|;
name|unsigned
name|short
name|order
decl_stmt|;
name|PEXCoordType
name|rationality
decl_stmt|;
name|PEXEnumTypeIndex
name|approx_method
decl_stmt|;
name|float
name|tolerance
decl_stmt|;
name|float
name|tmin
decl_stmt|,
name|tmax
decl_stmt|;
name|PEXListOfFloat
name|knots
decl_stmt|;
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of control points */
name|PEXArrayOfCoord
name|control_points
decl_stmt|;
block|}
name|PEXTrimCurve
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of curves */
name|PEXTrimCurve
modifier|*
name|curves
decl_stmt|;
block|}
name|PEXListOfTrimCurve
typedef|;
comment|/* half spaces */
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|point
decl_stmt|;
name|PEXVector
name|vector
decl_stmt|;
block|}
name|PEXHalfSpace
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord2D
name|point
decl_stmt|;
name|PEXVector2D
name|vector
decl_stmt|;
block|}
name|PEXHalfSpace2D
typedef|;
comment|/* parametric surface characteristics */
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|placement_type
decl_stmt|;
name|unsigned
name|short
name|reserved
decl_stmt|;
name|unsigned
name|short
name|u_count
decl_stmt|;
name|unsigned
name|short
name|v_count
decl_stmt|;
block|}
name|PEXPSCIsoparametricCurves
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|origin
decl_stmt|;
name|PEXVector
name|direction
decl_stmt|;
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of parameters */
name|unsigned
name|short
name|reserved
decl_stmt|;
name|float
modifier|*
name|parameters
decl_stmt|;
block|}
name|PEXPSCLevelCurves
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|length
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|PEXPSCImpDepData
typedef|;
typedef|typedef
union|union
block|{
name|PEXPSCIsoparametricCurves
name|iso_curves
decl_stmt|;
name|PEXPSCLevelCurves
name|level_curves
decl_stmt|;
name|PEXPSCImpDepData
name|imp_dep
decl_stmt|;
block|}
name|PEXPSCData
typedef|;
comment|/*  * pipeline context  */
typedef|typedef
struct|struct
block|{
name|PEXColorType
name|type
decl_stmt|;
name|unsigned
name|short
name|reserved
decl_stmt|;
name|PEXColor
name|value
decl_stmt|;
block|}
name|PEXColorSpecifier
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|vertical
decl_stmt|;
name|unsigned
name|short
name|horizontal
decl_stmt|;
block|}
name|PEXTextAlignment
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXEnumTypeIndex
name|method
decl_stmt|;
name|unsigned
name|short
name|reserved
decl_stmt|;
name|float
name|tolerance
decl_stmt|;
block|}
name|PEXCurveApprox
typedef|;
typedef|typedef
struct|struct
block|{
name|float
name|ambient
decl_stmt|;
name|float
name|diffuse
decl_stmt|;
name|float
name|specular
decl_stmt|;
name|float
name|specular_conc
decl_stmt|;
name|float
name|transmission
decl_stmt|;
name|PEXColorSpecifier
name|specular_color
decl_stmt|;
block|}
name|PEXReflectionAttributes
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXEnumTypeIndex
name|method
decl_stmt|;
name|unsigned
name|short
name|reserved
decl_stmt|;
name|float
name|u_tolerance
decl_stmt|;
name|float
name|v_tolerance
decl_stmt|;
block|}
name|PEXSurfaceApprox
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of half spaces */
name|PEXHalfSpace
modifier|*
name|half_spaces
decl_stmt|;
block|}
name|PEXModelClipVolume
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of lights */
name|PEXTableIndex
modifier|*
name|indices
decl_stmt|;
block|}
name|PEXListOfLight
typedef|;
typedef|typedef
struct|struct
block|{
name|short
name|type
decl_stmt|;
name|PEXPSCData
name|psc
decl_stmt|;
block|}
name|PEXPSCSpecifier
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXEnumTypeIndex
name|marker_type
decl_stmt|;
name|float
name|marker_scale
decl_stmt|;
name|PEXColorSpecifier
name|marker_color
decl_stmt|;
name|PEXTableIndex
name|marker_bundle_index
decl_stmt|;
name|PEXTableIndex
name|text_font
decl_stmt|;
name|unsigned
name|short
name|text_precision
decl_stmt|;
name|float
name|char_expansion
decl_stmt|;
name|float
name|char_spacing
decl_stmt|;
name|PEXColorSpecifier
name|text_color
decl_stmt|;
name|float
name|char_height
decl_stmt|;
name|PEXVector2D
name|char_up_vector
decl_stmt|;
name|unsigned
name|short
name|text_path
decl_stmt|;
name|PEXTextAlignment
name|text_alignment
decl_stmt|;
name|float
name|atext_height
decl_stmt|;
name|PEXVector2D
name|atext_up_vector
decl_stmt|;
name|unsigned
name|short
name|atext_path
decl_stmt|;
name|PEXTextAlignment
name|atext_alignment
decl_stmt|;
name|PEXEnumTypeIndex
name|atext_style
decl_stmt|;
name|PEXTableIndex
name|text_bundle_index
decl_stmt|;
name|PEXEnumTypeIndex
name|line_type
decl_stmt|;
name|float
name|line_width
decl_stmt|;
name|PEXColorSpecifier
name|line_color
decl_stmt|;
name|PEXCurveApprox
name|curve_approx
decl_stmt|;
name|PEXEnumTypeIndex
name|polyline_interp
decl_stmt|;
name|PEXTableIndex
name|line_bundle_index
decl_stmt|;
name|PEXEnumTypeIndex
name|interior_style
decl_stmt|;
name|PEXTypeOrTableIndex
name|interior_style_index
decl_stmt|;
name|PEXColorSpecifier
name|surface_color
decl_stmt|;
name|PEXReflectionAttributes
name|reflection_attr
decl_stmt|;
name|PEXEnumTypeIndex
name|reflection_model
decl_stmt|;
name|PEXEnumTypeIndex
name|surface_interp
decl_stmt|;
name|PEXEnumTypeIndex
name|bf_interior_style
decl_stmt|;
name|PEXTypeOrTableIndex
name|bf_interior_style_index
decl_stmt|;
name|PEXColorSpecifier
name|bf_surface_color
decl_stmt|;
name|PEXReflectionAttributes
name|bf_reflection_attr
decl_stmt|;
name|PEXEnumTypeIndex
name|bf_reflection_model
decl_stmt|;
name|PEXEnumTypeIndex
name|bf_surface_interp
decl_stmt|;
name|PEXSurfaceApprox
name|surface_approx
decl_stmt|;
name|unsigned
name|short
name|culling_mode
decl_stmt|;
name|Bool
name|distinguish
decl_stmt|;
name|PEXCoord2D
name|pattern_size
decl_stmt|;
name|PEXCoord
name|pattern_ref_point
decl_stmt|;
name|PEXVector
name|pattern_ref_vec1
decl_stmt|;
name|PEXVector
name|pattern_ref_vec2
decl_stmt|;
name|PEXTableIndex
name|interior_bundle_index
decl_stmt|;
name|PEXSwitch
name|surface_edges
decl_stmt|;
name|PEXEnumTypeIndex
name|surface_edge_type
decl_stmt|;
name|float
name|surface_edge_width
decl_stmt|;
name|PEXColorSpecifier
name|surface_edge_color
decl_stmt|;
name|PEXTableIndex
name|edge_bundle_index
decl_stmt|;
name|PEXMatrix
name|local_transform
decl_stmt|;
name|PEXMatrix
name|global_transform
decl_stmt|;
name|unsigned
name|short
name|model_clip
decl_stmt|;
name|PEXModelClipVolume
name|model_clip_volume
decl_stmt|;
name|PEXTableIndex
name|view_index
decl_stmt|;
name|PEXListOfLight
name|light_state
decl_stmt|;
name|PEXTableIndex
name|depth_cue_index
decl_stmt|;
name|PEXBitmask
name|asf_enables
decl_stmt|;
name|PEXBitmask
name|asf_values
decl_stmt|;
name|long
name|pick_id
decl_stmt|;
name|unsigned
name|long
name|hlhsr_id
decl_stmt|;
name|PEXNameSet
name|name_set
decl_stmt|;
name|PEXTableIndex
name|color_approx_index
decl_stmt|;
name|PEXEnumTypeIndex
name|rendering_color_model
decl_stmt|;
name|PEXPSCSpecifier
name|para_surf_char
decl_stmt|;
block|}
name|PEXPCAttributes
typedef|;
comment|/* macros for setting bits in a PC attribute bitmask */
define|#
directive|define
name|PEXSetPCAttributeMask
parameter_list|(
name|mask
parameter_list|,
name|attr
parameter_list|)
define|\
value|mask[((attr))>> 5] |= (unsigned long) 1<< ( ((attr))& 0x1f)
define|#
directive|define
name|PEXSetPCAttributeMaskAll
parameter_list|(
name|mask
parameter_list|)
define|\
value|mask[0] = 0xffffffff;              \     mask[1] = 0xffffffff;              \     mask[2] = 0x0
comment|/*  * renderer  */
typedef|typedef
struct|struct
block|{
name|short
name|xmin
decl_stmt|;
name|short
name|ymin
decl_stmt|;
name|short
name|xmax
decl_stmt|;
name|short
name|ymax
decl_stmt|;
block|}
name|PEXDeviceRect
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of device rectangles */
name|PEXDeviceRect
modifier|*
name|rectangles
decl_stmt|;
block|}
name|PEXListOfClipRect
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|min
decl_stmt|;
name|PEXCoord
name|max
decl_stmt|;
block|}
name|PEXNPCSubVolume
typedef|;
typedef|typedef
struct|struct
block|{
name|short
name|x
decl_stmt|;
name|short
name|y
decl_stmt|;
name|float
name|z
decl_stmt|;
block|}
name|PEXDeviceCoord
typedef|;
typedef|typedef
struct|struct
block|{
name|short
name|x
decl_stmt|;
name|short
name|y
decl_stmt|;
block|}
name|PEXDeviceCoord2D
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXDeviceCoord
name|min
decl_stmt|;
name|PEXDeviceCoord
name|max
decl_stmt|;
name|PEXSwitch
name|use_drawable
decl_stmt|;
name|unsigned
name|char
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|PEXViewport
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXStructure
name|structure
decl_stmt|;
name|unsigned
name|long
name|offset
decl_stmt|;
block|}
name|PEXElementRef
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|count
decl_stmt|;
comment|/* number of elements */
name|PEXElementRef
modifier|*
name|elements
decl_stmt|;
block|}
name|PEXStructurePath
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXStructure
name|sid
decl_stmt|;
name|unsigned
name|long
name|offset
decl_stmt|;
name|unsigned
name|long
name|pick_id
decl_stmt|;
block|}
name|PEXPickElementRef
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|count
decl_stmt|;
comment|/* number of elements */
name|PEXPickElementRef
modifier|*
name|elements
decl_stmt|;
block|}
name|PEXPickPath
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXPipelineContext
name|pipeline_context
decl_stmt|;
name|PEXStructurePath
name|current_path
decl_stmt|;
name|PEXLookupTable
name|marker_bundle
decl_stmt|;
name|PEXLookupTable
name|text_bundle
decl_stmt|;
name|PEXLookupTable
name|line_bundle
decl_stmt|;
name|PEXLookupTable
name|interior_bundle
decl_stmt|;
name|PEXLookupTable
name|edge_bundle
decl_stmt|;
name|PEXLookupTable
name|view_table
decl_stmt|;
name|PEXLookupTable
name|color_table
decl_stmt|;
name|PEXLookupTable
name|depth_cue_table
decl_stmt|;
name|PEXLookupTable
name|light_table
decl_stmt|;
name|PEXLookupTable
name|color_approx_table
decl_stmt|;
name|PEXLookupTable
name|pattern_table
decl_stmt|;
name|PEXLookupTable
name|text_font_table
decl_stmt|;
name|PEXNameSet
name|highlight_incl
decl_stmt|;
name|PEXNameSet
name|highlight_excl
decl_stmt|;
name|PEXNameSet
name|invisibility_incl
decl_stmt|;
name|PEXNameSet
name|invisibility_excl
decl_stmt|;
name|int
name|renderer_state
decl_stmt|;
name|PEXEnumTypeIndex
name|hlhsr_mode
decl_stmt|;
name|PEXNPCSubVolume
name|npc_subvolume
decl_stmt|;
name|PEXViewport
name|viewport
decl_stmt|;
name|PEXListOfClipRect
name|clip_list
decl_stmt|;
name|PEXNameSet
name|pick_incl
decl_stmt|;
name|PEXNameSet
name|pick_excl
decl_stmt|;
name|PEXStructurePath
name|pick_start_path
decl_stmt|;
name|PEXColorSpecifier
name|background_color
decl_stmt|;
name|Bool
name|clear_image
decl_stmt|;
name|Bool
name|clear_z
decl_stmt|;
name|int
name|echo_mode
decl_stmt|;
block|}
name|PEXRendererAttributes
typedef|;
comment|/* renderer picking */
typedef|typedef
name|PEXNPCSubVolume
name|PEXPDNPCHitVolume
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXDeviceCoord2D
name|position
decl_stmt|;
name|float
name|distance
decl_stmt|;
block|}
name|PEXPDDCHitBox
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|length
decl_stmt|;
comment|/* number of bytes in record */
name|char
modifier|*
name|record
decl_stmt|;
block|}
name|PEXPickDataRecord
typedef|;
typedef|typedef
union|union
block|{
name|PEXPDNPCHitVolume
name|volume
decl_stmt|;
name|PEXPDDCHitBox
name|box
decl_stmt|;
name|PEXPickDataRecord
name|data
decl_stmt|;
block|}
name|PEXPickRecord
typedef|;
comment|/*  * name set  */
typedef|typedef
struct|struct
block|{
name|PEXNameSet
name|inclusion
decl_stmt|;
name|PEXNameSet
name|exclusion
decl_stmt|;
block|}
name|PEXNameSetPair
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of pairs */
name|PEXNameSetPair
modifier|*
name|pairs
decl_stmt|;
block|}
name|PEXListOfNameSetPair
typedef|;
comment|/*  * font  */
typedef|typedef
struct|struct
block|{
name|Atom
name|name
decl_stmt|;
name|unsigned
name|long
name|value
decl_stmt|;
block|}
name|PEXFontProp
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|first_glyph
decl_stmt|;
name|unsigned
name|long
name|last_glyph
decl_stmt|;
name|unsigned
name|long
name|default_glyph
decl_stmt|;
name|Bool
name|all_exist
decl_stmt|;
name|Bool
name|stroke
decl_stmt|;
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of properties */
name|PEXFontProp
modifier|*
name|props
decl_stmt|;
block|}
name|PEXFontInfo
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|length
decl_stmt|;
name|char
modifier|*
name|ch
decl_stmt|;
block|}
name|PEXStringData
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXCoord2D
name|lower_left
decl_stmt|;
name|PEXCoord2D
name|upper_right
decl_stmt|;
name|PEXCoord2D
name|concat_point
decl_stmt|;
block|}
name|PEXTextExtent
typedef|;
comment|/*  * look up table  */
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|definable_entries
decl_stmt|;
name|unsigned
name|short
name|predefined_count
decl_stmt|;
name|unsigned
name|short
name|predefined_min
decl_stmt|;
name|unsigned
name|short
name|predefined_max
decl_stmt|;
block|}
name|PEXTableInfo
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXEnumTypeIndex
name|type
decl_stmt|;
name|PEXEnumTypeIndex
name|interp_method
decl_stmt|;
name|PEXCurveApprox
name|curve_approx
decl_stmt|;
name|float
name|width
decl_stmt|;
name|PEXColorSpecifier
name|color
decl_stmt|;
block|}
name|PEXLineBundleEntry
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXEnumTypeIndex
name|type
decl_stmt|;
name|short
name|reserved
decl_stmt|;
name|float
name|scale
decl_stmt|;
name|PEXColorSpecifier
name|color
decl_stmt|;
block|}
name|PEXMarkerBundleEntry
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXTableIndex
name|font_index
decl_stmt|;
name|PEXEnumTypeIndex
name|precision
decl_stmt|;
name|float
name|char_expansion
decl_stmt|;
name|float
name|char_spacing
decl_stmt|;
name|PEXColorSpecifier
name|color
decl_stmt|;
block|}
name|PEXTextBundleEntry
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXEnumTypeIndex
name|style
decl_stmt|;
name|PEXTypeOrTableIndex
name|style_index
decl_stmt|;
name|PEXEnumTypeIndex
name|reflection_model
decl_stmt|;
name|PEXEnumTypeIndex
name|interp_method
decl_stmt|;
name|PEXEnumTypeIndex
name|bf_style
decl_stmt|;
name|PEXTypeOrTableIndex
name|bf_style_index
decl_stmt|;
name|PEXEnumTypeIndex
name|bf_reflection_model
decl_stmt|;
name|PEXEnumTypeIndex
name|bf_interp_method
decl_stmt|;
name|PEXSurfaceApprox
name|surface_approx
decl_stmt|;
name|PEXColorSpecifier
name|color
decl_stmt|;
name|PEXReflectionAttributes
name|reflection_attr
decl_stmt|;
name|PEXColorSpecifier
name|bf_color
decl_stmt|;
name|PEXReflectionAttributes
name|bf_reflection_attr
decl_stmt|;
block|}
name|PEXInteriorBundleEntry
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXSwitch
name|edge_flag
decl_stmt|;
name|unsigned
name|char
name|reserved
decl_stmt|;
name|PEXEnumTypeIndex
name|type
decl_stmt|;
name|float
name|width
decl_stmt|;
name|PEXColorSpecifier
name|color
decl_stmt|;
block|}
name|PEXEdgeBundleEntry
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXColorType
name|color_type
decl_stmt|;
name|unsigned
name|short
name|row_count
decl_stmt|;
name|unsigned
name|short
name|col_count
decl_stmt|;
name|PEXArrayOfColor
name|colors
decl_stmt|;
comment|/* pointer to 2D array of colors */
block|}
name|PEXPatternEntry
typedef|;
typedef|typedef
name|PEXColorSpecifier
name|PEXColorEntry
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of fonts */
name|PEXFont
modifier|*
name|fonts
decl_stmt|;
block|}
name|PEXTextFontEntry
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXEnumTypeIndex
name|type
decl_stmt|;
name|unsigned
name|short
name|reserved
decl_stmt|;
name|PEXVector
name|direction
decl_stmt|;
name|PEXCoord
name|point
decl_stmt|;
name|float
name|concentration
decl_stmt|;
name|float
name|spread_angle
decl_stmt|;
name|float
name|attenuation1
decl_stmt|;
name|float
name|attenuation2
decl_stmt|;
name|PEXColorSpecifier
name|color
decl_stmt|;
block|}
name|PEXLightEntry
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXSwitch
name|mode
decl_stmt|;
name|unsigned
name|char
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|float
name|front_plane
decl_stmt|;
name|float
name|back_plane
decl_stmt|;
name|float
name|front_scaling
decl_stmt|;
name|float
name|back_scaling
decl_stmt|;
name|PEXColorSpecifier
name|color
decl_stmt|;
block|}
name|PEXDepthCueEntry
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXEnumTypeIndex
name|type
decl_stmt|;
name|PEXEnumTypeIndex
name|model
decl_stmt|;
name|unsigned
name|short
name|max1
decl_stmt|;
name|unsigned
name|short
name|max2
decl_stmt|;
name|unsigned
name|short
name|max3
decl_stmt|;
name|PEXSwitch
name|dither
decl_stmt|;
name|unsigned
name|char
name|reserved
decl_stmt|;
name|unsigned
name|long
name|mult1
decl_stmt|;
name|unsigned
name|long
name|mult2
decl_stmt|;
name|unsigned
name|long
name|mult3
decl_stmt|;
name|float
name|weight1
decl_stmt|;
name|float
name|weight2
decl_stmt|;
name|float
name|weight3
decl_stmt|;
name|unsigned
name|long
name|base_pixel
decl_stmt|;
block|}
name|PEXColorApproxEntry
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|clip_flags
decl_stmt|;
name|unsigned
name|short
name|reserved
decl_stmt|;
name|PEXNPCSubVolume
name|clip_limits
decl_stmt|;
name|PEXMatrix
name|orientation
decl_stmt|;
name|PEXMatrix
name|mapping
decl_stmt|;
block|}
name|PEXViewEntry
typedef|;
comment|/*  * structure  */
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|element_count
decl_stmt|;
name|unsigned
name|long
name|size
decl_stmt|;
name|Bool
name|has_refs
decl_stmt|;
name|unsigned
name|short
name|edit_mode
decl_stmt|;
name|unsigned
name|long
name|element_pointer
decl_stmt|;
block|}
name|PEXStructureInfo
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|type
decl_stmt|;
name|unsigned
name|short
name|length
decl_stmt|;
block|}
name|PEXElementInfo
typedef|;
comment|/*  * search context  */
typedef|typedef
struct|struct
block|{
name|PEXCoord
name|position
decl_stmt|;
name|float
name|distance
decl_stmt|;
name|unsigned
name|short
name|ceiling
decl_stmt|;
name|Bool
name|model_clip_flag
decl_stmt|;
name|PEXStructurePath
name|start_path
decl_stmt|;
name|PEXListOfNameSetPair
name|normal
decl_stmt|;
name|PEXListOfNameSetPair
name|inverted
decl_stmt|;
block|}
name|PEXSCAttributes
typedef|;
comment|/*  * PHIGS workstation  */
typedef|typedef
struct|struct
block|{
name|PEXTableIndex
name|index
decl_stmt|;
name|unsigned
name|short
name|reserved
decl_stmt|;
name|PEXViewEntry
name|view
decl_stmt|;
block|}
name|PEXViewRep
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of views */
name|PEXTableIndex
modifier|*
name|views
decl_stmt|;
block|}
name|PEXListOfView
typedef|;
typedef|typedef
struct|struct
block|{
name|PEXStructure
name|sid
decl_stmt|;
name|float
name|priority
decl_stmt|;
block|}
name|PEXPostedStructure
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|count
decl_stmt|;
comment|/* number of posted structures*/
name|PEXPostedStructure
modifier|*
name|structures
decl_stmt|;
block|}
name|PEXListOfPostedStructure
typedef|;
typedef|typedef
struct|struct
block|{
name|short
name|drawable_update
decl_stmt|;
name|int
name|visual_state
decl_stmt|;
name|int
name|drawable_surface
decl_stmt|;
name|int
name|view_update
decl_stmt|;
name|PEXListOfView
name|defined_views
decl_stmt|;
name|int
name|wks_update
decl_stmt|;
name|PEXNPCSubVolume
name|req_npc_subvolume
decl_stmt|;
name|PEXNPCSubVolume
name|cur_npc_subvolume
decl_stmt|;
name|PEXViewport
name|req_workstation_viewport
decl_stmt|;
name|PEXViewport
name|cur_workstation_viewport
decl_stmt|;
name|int
name|hlhsr_update
decl_stmt|;
name|PEXEnumTypeIndex
name|req_hlhsr_mode
decl_stmt|;
name|PEXEnumTypeIndex
name|cur_hlhsr_mode
decl_stmt|;
name|Drawable
name|drawable
decl_stmt|;
name|PEXLookupTable
name|marker_bundle
decl_stmt|;
name|PEXLookupTable
name|text_bundle
decl_stmt|;
name|PEXLookupTable
name|line_bundle
decl_stmt|;
name|PEXLookupTable
name|interior_bundle
decl_stmt|;
name|PEXLookupTable
name|edge_bundle
decl_stmt|;
name|PEXLookupTable
name|color_table
decl_stmt|;
name|PEXLookupTable
name|depth_cue_table
decl_stmt|;
name|PEXLookupTable
name|light_table
decl_stmt|;
name|PEXLookupTable
name|color_approx_table
decl_stmt|;
name|PEXLookupTable
name|pattern_table
decl_stmt|;
name|PEXLookupTable
name|text_font_table
decl_stmt|;
name|PEXNameSet
name|highlight_incl
decl_stmt|;
name|PEXNameSet
name|highlight_excl
decl_stmt|;
name|PEXNameSet
name|invisibility_incl
decl_stmt|;
name|PEXNameSet
name|invisibility_excl
decl_stmt|;
name|PEXListOfPostedStructure
name|posted_structures
decl_stmt|;
name|unsigned
name|long
name|count_priorities
decl_stmt|;
name|int
name|buffer_update
decl_stmt|;
name|int
name|req_buffer_mode
decl_stmt|;
name|int
name|cur_buffer_mode
decl_stmt|;
block|}
name|PEXWorkstationAttributes
typedef|;
comment|/* macros for setting bits in a workstation attribute bitmask */
define|#
directive|define
name|PEXSetPWAttributeMask
parameter_list|(
name|mask
parameter_list|,
name|attr
parameter_list|)
define|\
value|mask[((attr))>> 5] |= (unsigned long) 1<< ( ((attr))& 0x1f)
define|#
directive|define
name|PEXSetPWAttributeMaskAll
parameter_list|(
name|mask
parameter_list|)
define|\
value|mask[0] = 0xffffffff;              \     mask[1] = 0x00000003
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|view_rep
decl_stmt|;
name|unsigned
name|char
name|marker_bundle
decl_stmt|;
name|unsigned
name|char
name|text_bundle
decl_stmt|;
name|unsigned
name|char
name|line_bundle
decl_stmt|;
name|unsigned
name|char
name|interior_bundle
decl_stmt|;
name|unsigned
name|char
name|edge_bundle
decl_stmt|;
name|unsigned
name|char
name|color_table
decl_stmt|;
name|unsigned
name|char
name|pattern_table
decl_stmt|;
name|unsigned
name|char
name|wks_transform
decl_stmt|;
name|unsigned
name|char
name|highlight_filter
decl_stmt|;
name|unsigned
name|char
name|invisibility_filter
decl_stmt|;
name|unsigned
name|char
name|hlhsr_mode
decl_stmt|;
name|unsigned
name|char
name|structure_modify
decl_stmt|;
name|unsigned
name|char
name|post_structure
decl_stmt|;
name|unsigned
name|char
name|unpost_structure
decl_stmt|;
name|unsigned
name|char
name|delete_structure
decl_stmt|;
name|unsigned
name|char
name|reference_modify
decl_stmt|;
name|unsigned
name|char
name|buffer_modify
decl_stmt|;
name|unsigned
name|char
name|light_table
decl_stmt|;
name|unsigned
name|char
name|depth_cue_table
decl_stmt|;
name|unsigned
name|char
name|color_approx_table
decl_stmt|;
block|}
name|PEXWorkstationDynamics
typedef|;
comment|/*  * workstation picking  */
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|status
decl_stmt|;
name|PEXPickPath
name|pick_path
decl_stmt|;
block|}
name|PEXPMAttributes
typedef|;
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|status
decl_stmt|;
name|PEXPickPath
name|path
decl_stmt|;
name|int
name|path_order
decl_stmt|;
name|PEXNameSet
name|inclusion
decl_stmt|;
name|PEXNameSet
name|exclusion
decl_stmt|;
name|PEXPickRecord
name|pick_record
decl_stmt|;
name|PEXEnumTypeIndex
name|prompt_echo_type
decl_stmt|;
name|PEXViewport
name|echo_volume
decl_stmt|;
name|int
name|echo_switch
decl_stmt|;
block|}
name|PEXPDAttributes
typedef|;
comment|/*  * errors  */
comment|/* similar to XErrorEvent - use to access additional info in OC error */
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|XID
name|resourceid
decl_stmt|;
comment|/* resource id of renderer or structure */
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* serial number of failed request */
name|unsigned
name|char
name|error_code
decl_stmt|;
comment|/* error code of failed request */
name|unsigned
name|char
name|request_code
decl_stmt|;
comment|/* Major op-code of failed request */
name|unsigned
name|char
name|minor_code
decl_stmt|;
comment|/* Minor op-code of failed request */
name|unsigned
name|short
name|op_code
decl_stmt|;
comment|/* op-code of failed output command */
name|unsigned
name|short
name|count
decl_stmt|;
comment|/* number of output commands successfully */
comment|/* executed before error */
block|}
name|PEXOCErrorEvent
typedef|;
comment|/*  * events  */
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|PEXRenderer
name|renderer
decl_stmt|;
block|}
name|PEXMaxHitsReachedEvent
typedef|;
comment|/*  * encode and decode  */
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|oc_type
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|unsigned
name|long
name|count
decl_stmt|;
name|PEXName
modifier|*
name|names
decl_stmt|;
block|}
name|AddToNameSet
struct|;
struct|struct
block|{
name|int
name|length
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|ApplicationData
struct|;
struct|struct
block|{
name|PEXCoord
name|point1
decl_stmt|;
name|PEXCoord
name|point2
decl_stmt|;
name|PEXCoord
name|point3
decl_stmt|;
name|unsigned
name|int
name|col_count
decl_stmt|;
name|unsigned
name|int
name|row_count
decl_stmt|;
name|PEXTableIndex
modifier|*
name|color_indices
decl_stmt|;
block|}
name|CellArray
struct|;
struct|struct
block|{
name|PEXCoord2D
name|point1
decl_stmt|;
name|PEXCoord2D
name|point2
decl_stmt|;
name|unsigned
name|int
name|col_count
decl_stmt|;
name|unsigned
name|int
name|row_count
decl_stmt|;
name|PEXTableIndex
modifier|*
name|color_indices
decl_stmt|;
block|}
name|CellArray2D
struct|;
struct|struct
block|{
name|PEXCoord
name|origin
decl_stmt|;
name|PEXCoord
name|offset
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXEncodedTextData
modifier|*
name|encoded_text
decl_stmt|;
block|}
name|EncodedAnnoText
struct|;
struct|struct
block|{
name|PEXCoord2D
name|origin
decl_stmt|;
name|PEXCoord2D
name|offset
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXEncodedTextData
modifier|*
name|encoded_text
decl_stmt|;
block|}
name|EncodedAnnoText2D
struct|;
struct|struct
block|{
name|PEXCoord
name|origin
decl_stmt|;
name|PEXVector
name|vector1
decl_stmt|;
name|PEXVector
name|vector2
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXEncodedTextData
modifier|*
name|encoded_text
decl_stmt|;
block|}
name|EncodedText
struct|;
struct|struct
block|{
name|PEXCoord2D
name|origin
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXEncodedTextData
modifier|*
name|encoded_text
decl_stmt|;
block|}
name|EncodedText2D
struct|;
struct|struct
block|{
name|PEXStructure
name|structure
decl_stmt|;
block|}
name|ExecuteStructure
struct|;
struct|struct
block|{
name|PEXCoord
name|point1
decl_stmt|;
name|PEXCoord
name|point2
decl_stmt|;
name|PEXCoord
name|point3
decl_stmt|;
name|unsigned
name|int
name|col_count
decl_stmt|;
name|unsigned
name|int
name|row_count
decl_stmt|;
name|int
name|color_type
decl_stmt|;
name|PEXArrayOfColor
name|colors
decl_stmt|;
block|}
name|ExtendedCellArray
struct|;
struct|struct
block|{
name|int
name|shape_hint
decl_stmt|;
name|int
name|ignore_edges
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXCoord
modifier|*
name|points
decl_stmt|;
block|}
name|FillArea
struct|;
struct|struct
block|{
name|int
name|shape_hint
decl_stmt|;
name|int
name|ignore_edges
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXCoord2D
modifier|*
name|points
decl_stmt|;
block|}
name|FillArea2D
struct|;
struct|struct
block|{
name|int
name|shape_hint
decl_stmt|;
name|int
name|ignore_edges
decl_stmt|;
name|int
name|contour_hint
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXListOfCoord
modifier|*
name|point_lists
decl_stmt|;
block|}
name|FillAreaSet
struct|;
struct|struct
block|{
name|int
name|shape_hint
decl_stmt|;
name|int
name|ignore_edges
decl_stmt|;
name|int
name|contour_hint
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXListOfCoord2D
modifier|*
name|point_lists
decl_stmt|;
block|}
name|FillAreaSet2D
struct|;
struct|struct
block|{
name|int
name|shape_hint
decl_stmt|;
name|int
name|ignore_edges
decl_stmt|;
name|int
name|contour_hint
decl_stmt|;
name|unsigned
name|int
name|facet_attributes
decl_stmt|;
name|unsigned
name|int
name|vertex_attributes
decl_stmt|;
name|int
name|color_type
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXFacetData
name|facet_data
decl_stmt|;
name|PEXListOfVertex
modifier|*
name|vertex_lists
decl_stmt|;
block|}
name|FillAreaSetWithData
struct|;
struct|struct
block|{
name|int
name|shape_hint
decl_stmt|;
name|int
name|ignore_edges
decl_stmt|;
name|unsigned
name|int
name|facet_attributes
decl_stmt|;
name|unsigned
name|int
name|vertex_attributes
decl_stmt|;
name|int
name|color_type
decl_stmt|;
name|PEXFacetData
name|facet_data
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXArrayOfVertex
name|vertices
decl_stmt|;
block|}
name|FillAreaWithData
struct|;
struct|struct
block|{
name|long
name|gdp_id
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXCoord
modifier|*
name|points
decl_stmt|;
name|unsigned
name|long
name|length
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|GDP
struct|;
struct|struct
block|{
name|long
name|gdp_id
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXCoord2D
modifier|*
name|points
decl_stmt|;
name|unsigned
name|long
name|length
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|GDP2D
struct|;
struct|struct
block|{
name|long
name|id
decl_stmt|;
name|int
name|length
decl_stmt|;
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|GSE
struct|;
struct|struct
block|{
name|long
name|label
decl_stmt|;
block|}
name|Label
struct|;
struct|struct
block|{
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXCoord
modifier|*
name|points
decl_stmt|;
block|}
name|Markers
struct|;
struct|struct
block|{
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXCoord2D
modifier|*
name|points
decl_stmt|;
block|}
name|Markers2D
struct|;
struct|struct
block|{
name|int
name|rationality
decl_stmt|;
name|int
name|order
decl_stmt|;
name|float
modifier|*
name|knots
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXArrayOfCoord
name|points
decl_stmt|;
name|double
name|tmin
decl_stmt|;
name|double
name|tmax
decl_stmt|;
block|}
name|NURBCurve
struct|;
struct|struct
block|{
name|int
name|rationality
decl_stmt|;
name|int
name|uorder
decl_stmt|;
name|int
name|vorder
decl_stmt|;
name|float
modifier|*
name|uknots
decl_stmt|;
name|float
modifier|*
name|vknots
decl_stmt|;
name|unsigned
name|int
name|col_count
decl_stmt|;
name|unsigned
name|int
name|row_count
decl_stmt|;
name|PEXArrayOfCoord
name|points
decl_stmt|;
name|unsigned
name|int
name|curve_count
decl_stmt|;
name|PEXListOfTrimCurve
modifier|*
name|trim_curves
decl_stmt|;
block|}
name|NURBSurface
struct|;
struct|struct
block|{
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXCoord
modifier|*
name|points
decl_stmt|;
block|}
name|Polyline
struct|;
struct|struct
block|{
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXCoord2D
modifier|*
name|points
decl_stmt|;
block|}
name|Polyline2D
struct|;
struct|struct
block|{
name|unsigned
name|int
name|vertex_attributes
decl_stmt|;
name|int
name|color_type
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXListOfVertex
modifier|*
name|vertex_lists
decl_stmt|;
block|}
name|PolylineSetWithData
struct|;
struct|struct
block|{
name|int
name|shape_hint
decl_stmt|;
name|unsigned
name|int
name|facet_attributes
decl_stmt|;
name|unsigned
name|int
name|vertex_attributes
decl_stmt|;
name|int
name|color_type
decl_stmt|;
name|PEXArrayOfFacetData
name|facet_data
decl_stmt|;
name|unsigned
name|int
name|col_count
decl_stmt|;
name|unsigned
name|int
name|row_count
decl_stmt|;
name|PEXArrayOfVertex
name|vertices
decl_stmt|;
block|}
name|QuadrilateralMesh
struct|;
struct|struct
block|{
name|unsigned
name|long
name|count
decl_stmt|;
name|PEXName
modifier|*
name|names
decl_stmt|;
block|}
name|RemoveFromNameSet
struct|;
struct|struct
block|{
name|int
name|halignment
decl_stmt|;
name|int
name|valignment
decl_stmt|;
block|}
name|SetATextAlignment
struct|;
struct|struct
block|{
name|double
name|height
decl_stmt|;
block|}
name|SetATextHeight
struct|;
struct|struct
block|{
name|int
name|path
decl_stmt|;
block|}
name|SetATextPath
struct|;
struct|struct
block|{
name|int
name|style
decl_stmt|;
block|}
name|SetATextStyle
struct|;
struct|struct
block|{
name|PEXVector2D
name|vector
decl_stmt|;
block|}
name|SetATextUpVector
struct|;
struct|struct
block|{
name|int
name|style
decl_stmt|;
block|}
name|SetBFInteriorStyle
struct|;
struct|struct
block|{
name|int
name|index
decl_stmt|;
block|}
name|SetBFInteriorStyleIndex
struct|;
struct|struct
block|{
name|PEXReflectionAttributes
name|attributes
decl_stmt|;
block|}
name|SetBFReflectionAttributes
struct|;
struct|struct
block|{
name|int
name|model
decl_stmt|;
block|}
name|SetBFReflectionModel
struct|;
struct|struct
block|{
name|int
name|color_type
decl_stmt|;
name|PEXColor
name|color
decl_stmt|;
block|}
name|SetBFSurfaceColor
struct|;
struct|struct
block|{
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|SetBFSurfaceColorIndex
struct|;
struct|struct
block|{
name|int
name|method
decl_stmt|;
block|}
name|SetBFSurfaceInterpMethod
struct|;
struct|struct
block|{
name|double
name|expansion
decl_stmt|;
block|}
name|SetCharExpansion
struct|;
struct|struct
block|{
name|double
name|height
decl_stmt|;
block|}
name|SetCharHeight
struct|;
struct|struct
block|{
name|double
name|spacing
decl_stmt|;
block|}
name|SetCharSpacing
struct|;
struct|struct
block|{
name|PEXVector2D
name|vector
decl_stmt|;
block|}
name|SetCharUpVector
struct|;
struct|struct
block|{
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|SetColorApproxIndex
struct|;
struct|struct
block|{
name|int
name|method
decl_stmt|;
name|double
name|tolerance
decl_stmt|;
block|}
name|SetCurveApprox
struct|;
struct|struct
block|{
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|SetDepthCueIndex
struct|;
struct|struct
block|{
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|SetEdgeBundleIndex
struct|;
struct|struct
block|{
name|int
name|mode
decl_stmt|;
block|}
name|SetFacetCullingMode
struct|;
struct|struct
block|{
name|int
name|flag
decl_stmt|;
block|}
name|SetFacetDistinguishFlag
struct|;
struct|struct
block|{
name|PEXMatrix
name|transform
decl_stmt|;
block|}
name|SetGlobalTransform
struct|;
struct|struct
block|{
name|PEXMatrix3x3
name|transform
decl_stmt|;
block|}
name|SetGlobalTransform2D
struct|;
struct|struct
block|{
name|unsigned
name|long
name|hlhsr_id
decl_stmt|;
block|}
name|SetHLHSRID
struct|;
struct|struct
block|{
name|unsigned
name|long
name|attribute
decl_stmt|;
name|int
name|asf
decl_stmt|;
block|}
name|SetIndividualASF
struct|;
struct|struct
block|{
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|SetInteriorBundleIndex
struct|;
struct|struct
block|{
name|int
name|style
decl_stmt|;
block|}
name|SetInteriorStyle
struct|;
struct|struct
block|{
name|int
name|index
decl_stmt|;
block|}
name|SetInteriorStyleIndex
struct|;
struct|struct
block|{
name|unsigned
name|int
name|enable_count
decl_stmt|;
name|PEXTableIndex
modifier|*
name|enable
decl_stmt|;
name|unsigned
name|int
name|disable_count
decl_stmt|;
name|PEXTableIndex
modifier|*
name|disable
decl_stmt|;
block|}
name|SetLightSourceState
struct|;
struct|struct
block|{
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|SetLineBundleIndex
struct|;
struct|struct
block|{
name|int
name|color_type
decl_stmt|;
name|PEXColor
name|color
decl_stmt|;
block|}
name|SetLineColor
struct|;
struct|struct
block|{
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|SetLineColorIndex
struct|;
struct|struct
block|{
name|int
name|line_type
decl_stmt|;
block|}
name|SetLineType
struct|;
struct|struct
block|{
name|double
name|width
decl_stmt|;
block|}
name|SetLineWidth
struct|;
struct|struct
block|{
name|int
name|composition
decl_stmt|;
name|PEXMatrix
name|transform
decl_stmt|;
block|}
name|SetLocalTransform
struct|;
struct|struct
block|{
name|int
name|composition
decl_stmt|;
name|PEXMatrix3x3
name|transform
decl_stmt|;
block|}
name|SetLocalTransform2D
struct|;
struct|struct
block|{
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|SetMarkerBundleIndex
struct|;
struct|struct
block|{
name|int
name|color_type
decl_stmt|;
name|PEXColor
name|color
decl_stmt|;
block|}
name|SetMarkerColor
struct|;
struct|struct
block|{
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|SetMarkerColorIndex
struct|;
struct|struct
block|{
name|double
name|scale
decl_stmt|;
block|}
name|SetMarkerScale
struct|;
struct|struct
block|{
name|int
name|marker_type
decl_stmt|;
block|}
name|SetMarkerType
struct|;
struct|struct
block|{
name|int
name|flag
decl_stmt|;
block|}
name|SetModelClipFlag
struct|;
struct|struct
block|{
name|int
name|op
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXHalfSpace
modifier|*
name|half_spaces
decl_stmt|;
block|}
name|SetModelClipVolume
struct|;
struct|struct
block|{
name|int
name|op
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXHalfSpace2D
modifier|*
name|half_spaces
decl_stmt|;
block|}
name|SetModelClipVolume2D
struct|;
struct|struct
block|{
name|int
name|shape_hint
decl_stmt|;
name|unsigned
name|int
name|facet_attributes
decl_stmt|;
name|unsigned
name|int
name|vertex_attributes
decl_stmt|;
name|unsigned
name|int
name|edge_attributes
decl_stmt|;
name|int
name|contour_hint
decl_stmt|;
name|int
name|contours_all_one
decl_stmt|;
name|int
name|color_type
decl_stmt|;
name|unsigned
name|int
name|set_count
decl_stmt|;
name|PEXArrayOfFacetData
name|facet_data
decl_stmt|;
name|unsigned
name|int
name|vertex_count
decl_stmt|;
name|PEXArrayOfVertex
name|vertices
decl_stmt|;
name|unsigned
name|int
name|index_count
decl_stmt|;
name|PEXSwitch
modifier|*
name|edge_flags
decl_stmt|;
name|PEXConnectivityData
modifier|*
name|connectivity
decl_stmt|;
block|}
name|SetOfFillAreaSets
struct|;
struct|struct
block|{
name|int
name|psc_type
decl_stmt|;
name|PEXPSCData
name|characteristics
decl_stmt|;
block|}
name|SetParaSurfCharacteristics
struct|;
struct|struct
block|{
name|PEXCoord
name|ref_point
decl_stmt|;
name|PEXVector
name|vector1
decl_stmt|;
name|PEXVector
name|vector2
decl_stmt|;
block|}
name|SetPatternAttributes
struct|;
struct|struct
block|{
name|PEXCoord2D
name|ref_point
decl_stmt|;
block|}
name|SetPatternAttributes2D
struct|;
struct|struct
block|{
name|double
name|width
decl_stmt|;
name|double
name|height
decl_stmt|;
block|}
name|SetPatternSize
struct|;
struct|struct
block|{
name|unsigned
name|long
name|pick_id
decl_stmt|;
block|}
name|SetPickID
struct|;
struct|struct
block|{
name|int
name|method
decl_stmt|;
block|}
name|SetPolylineInterpMethod
struct|;
struct|struct
block|{
name|PEXReflectionAttributes
name|attributes
decl_stmt|;
block|}
name|SetReflectionAttributes
struct|;
struct|struct
block|{
name|int
name|model
decl_stmt|;
block|}
name|SetReflectionModel
struct|;
struct|struct
block|{
name|int
name|model
decl_stmt|;
block|}
name|SetRenderingColorModel
struct|;
struct|struct
block|{
name|int
name|method
decl_stmt|;
name|double
name|utolerance
decl_stmt|;
name|double
name|vtolerance
decl_stmt|;
block|}
name|SetSurfaceApprox
struct|;
struct|struct
block|{
name|int
name|color_type
decl_stmt|;
name|PEXColor
name|color
decl_stmt|;
block|}
name|SetSurfaceColor
struct|;
struct|struct
block|{
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|SetSurfaceColorIndex
struct|;
struct|struct
block|{
name|int
name|color_type
decl_stmt|;
name|PEXColor
name|color
decl_stmt|;
block|}
name|SetSurfaceEdgeColor
struct|;
struct|struct
block|{
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|SetSurfaceEdgeColorIndex
struct|;
struct|struct
block|{
name|int
name|flag
decl_stmt|;
block|}
name|SetSurfaceEdgeFlag
struct|;
struct|struct
block|{
name|int
name|edge_type
decl_stmt|;
block|}
name|SetSurfaceEdgeType
struct|;
struct|struct
block|{
name|double
name|width
decl_stmt|;
block|}
name|SetSurfaceEdgeWidth
struct|;
struct|struct
block|{
name|int
name|method
decl_stmt|;
block|}
name|SetSurfaceInterpMethod
struct|;
struct|struct
block|{
name|int
name|halignment
decl_stmt|;
name|int
name|valignment
decl_stmt|;
block|}
name|SetTextAlignment
struct|;
struct|struct
block|{
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|SetTextBundleIndex
struct|;
struct|struct
block|{
name|int
name|color_type
decl_stmt|;
name|PEXColor
name|color
decl_stmt|;
block|}
name|SetTextColor
struct|;
struct|struct
block|{
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|SetTextColorIndex
struct|;
struct|struct
block|{
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|SetTextFontIndex
struct|;
struct|struct
block|{
name|int
name|path
decl_stmt|;
block|}
name|SetTextPath
struct|;
struct|struct
block|{
name|int
name|precision
decl_stmt|;
block|}
name|SetTextPrecision
struct|;
struct|struct
block|{
name|unsigned
name|int
name|index
decl_stmt|;
block|}
name|SetViewIndex
struct|;
struct|struct
block|{
name|unsigned
name|int
name|facet_attributes
decl_stmt|;
name|unsigned
name|int
name|vertex_attributes
decl_stmt|;
name|int
name|color_type
decl_stmt|;
name|PEXArrayOfFacetData
name|facet_data
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|PEXArrayOfVertex
name|vertices
decl_stmt|;
block|}
name|TriangleStrip
struct|;
block|}
name|data
union|;
block|}
name|PEXOCData
typedef|;
comment|/*  * encoded output commands  */
comment|/* macro for inquiring max length for PEXGetOCAddr */
define|#
directive|define
name|PEXGetOCAddrMaxSize
parameter_list|(
name|_display
parameter_list|)
define|\
value|((_display)->bufmax - (_display)->buffer)
comment|/* this macro returns the     */
comment|/* maximum allowable size (in */
comment|/* bytes) for PEXGetOCAddr    */
comment|/* individual implementations */
comment|/* can modify the value, but  */
comment|/* the minimum allowed is 1024*/
comment|/*  * constants for utilities  */
comment|/* constants for PEXRotate */
define|#
directive|define
name|PEXXAxis
value|1
define|#
directive|define
name|PEXYAxis
value|2
define|#
directive|define
name|PEXZAxis
value|3
comment|/* constants for utilities error return status */
define|#
directive|define
name|PEXBadVector
value|1
define|#
directive|define
name|PEXBadVectors
value|2
define|#
directive|define
name|PEXBadLimits
value|3
define|#
directive|define
name|PEXBadViewport
value|4
define|#
directive|define
name|PEXBadPlanes
value|5
define|#
directive|define
name|PEXBadPRP
value|6
define|#
directive|define
name|PEXBadMatrix
value|7
define|#
directive|define
name|PEXBadPrimitive
value|8
define|#
directive|define
name|PEXBadDistance
value|9
define|#
directive|define
name|PEXBadAxis
value|10
define|#
directive|define
name|PEXBadHomoCoord
value|11
define|#
directive|define
name|PEXBadSubVolume
value|12
comment|/*  * function declarations  */
specifier|extern
name|void
name|PEXAccumulateState
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
parameter_list|,
name|unsigned
name|long
comment|/* count */
parameter_list|,
name|PEXElementRef
modifier|*
comment|/* elements */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXAddToNameSet
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|long
comment|/* count */
parameter_list|,
name|PEXName
modifier|*
comment|/* names */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXAnnotationText
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* origin */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* offset */
parameter_list|,
name|int
comment|/* length */
parameter_list|,
name|char
modifier|*
comment|/* string */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXAnnotationText2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* origin */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* offset */
parameter_list|,
name|int
comment|/* length */
parameter_list|,
name|char
modifier|*
comment|/* string */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXApplicationData
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* length */
parameter_list|,
name|char
modifier|*
comment|/* data */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXBeginPickAll
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* drawable */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
parameter_list|,
name|long
comment|/* structure_id */
parameter_list|,
name|int
comment|/* method */
parameter_list|,
name|int
comment|/* send_event */
parameter_list|,
name|int
comment|/* max_hits */
parameter_list|,
name|int
comment|/* pick_device_type */
parameter_list|,
name|PEXPickRecord
modifier|*
comment|/* pick_record */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXBeginPickOne
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* drawable */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
parameter_list|,
name|long
comment|/* structure_id */
parameter_list|,
name|int
comment|/* method */
parameter_list|,
name|int
comment|/* pick_device_type */
parameter_list|,
name|PEXPickRecord
modifier|*
comment|/* pick_record */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXBeginRendering
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* drawable */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXBeginStructure
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
parameter_list|,
name|long
comment|/* structure_id */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXBuildTransform
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXCoord
modifier|*
comment|/* fixed_point */
parameter_list|,
name|PEXVector
modifier|*
comment|/* trans_vector */
parameter_list|,
name|double
comment|/* angle_x */
parameter_list|,
name|double
comment|/* angle_y */
parameter_list|,
name|double
comment|/* angle_z */
parameter_list|,
name|PEXVector
modifier|*
comment|/* scale_vector */
parameter_list|,
name|PEXMatrix
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXBuildTransform2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXCoord2D
modifier|*
comment|/* fixed_point */
parameter_list|,
name|PEXVector2D
modifier|*
comment|/* trans_vector */
parameter_list|,
name|double
comment|/* angle_z */
parameter_list|,
name|PEXVector2D
modifier|*
comment|/* scale_vector */
parameter_list|,
name|PEXMatrix3x3
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXCellArray
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* point1 */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* point2 */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* point3 */
parameter_list|,
name|unsigned
name|int
comment|/* col_count */
parameter_list|,
name|unsigned
name|int
comment|/* row_count */
parameter_list|,
name|PEXTableIndex
modifier|*
comment|/* color_indices */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXCellArray2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* point1 */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* point2 */
parameter_list|,
name|unsigned
name|int
comment|/* col_count */
parameter_list|,
name|unsigned
name|int
comment|/* row_count */
parameter_list|,
name|PEXTableIndex
modifier|*
comment|/* color_indices */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXChangeNameSet
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXNameSet
comment|/* nameset */
parameter_list|,
name|int
comment|/* action */
parameter_list|,
name|unsigned
name|long
comment|/* count */
parameter_list|,
name|PEXName
modifier|*
comment|/* names */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXChangePickDevice
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|int
comment|/* pick_device_type */
parameter_list|,
name|unsigned
name|long
comment|/* value_mask */
parameter_list|,
name|PEXPDAttributes
modifier|*
comment|/* values */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXChangePipelineContext
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXPipelineContext
comment|/* context */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* value_mask */
parameter_list|,
name|PEXPCAttributes
modifier|*
comment|/* values */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXChangeRenderer
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
parameter_list|,
name|unsigned
name|long
comment|/* value_mask */
parameter_list|,
name|PEXRendererAttributes
modifier|*
comment|/* values */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXChangeSearchContext
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXSearchContext
comment|/* context */
parameter_list|,
name|unsigned
name|long
comment|/* value_mask */
parameter_list|,
name|PEXSCAttributes
modifier|*
comment|/* values */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXChangeStructureRefs
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* old_structure */
parameter_list|,
name|PEXStructure
comment|/* new_structure */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXCopyBytesToOC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|int
comment|/* length */
parameter_list|,
name|char
modifier|*
comment|/* data */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXCopyElements
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* src_structure */
parameter_list|,
name|int
comment|/* src_whence1 */
parameter_list|,
name|long
comment|/* src_offset1 */
parameter_list|,
name|int
comment|/* src_whence2 */
parameter_list|,
name|long
comment|/* src_offset2 */
parameter_list|,
name|PEXStructure
comment|/* dst_structure */
parameter_list|,
name|int
comment|/* dst_whence */
parameter_list|,
name|long
comment|/* dst_offset */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXCopyLookupTable
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXLookupTable
comment|/* src_table */
parameter_list|,
name|PEXLookupTable
comment|/* dst_table */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXCopyNameSet
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXNameSet
comment|/* src_nameset */
parameter_list|,
name|PEXNameSet
comment|/* dst_nameset */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXCopyPipelineContext
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* value_mask */
parameter_list|,
name|PEXPipelineContext
comment|/* src_context */
parameter_list|,
name|PEXPipelineContext
comment|/* dst_context */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXCopySearchContext
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|unsigned
name|long
comment|/* value_mask */
parameter_list|,
name|PEXSearchContext
comment|/* src_context */
parameter_list|,
name|PEXSearchContext
comment|/* dst_context */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXCopyStructure
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* src_structure */
parameter_list|,
name|PEXStructure
comment|/* dst_structure */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXLookupTable
name|PEXCreateLookupTable
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* drawable */
parameter_list|,
name|int
comment|/* table_type */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXNameSet
name|PEXCreateNameSet
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXPickMeasure
name|PEXCreatePickMeasure
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|int
comment|/* pick_device_type */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXPipelineContext
name|PEXCreatePipelineContext
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* value_mask */
parameter_list|,
name|PEXPCAttributes
modifier|*
comment|/* values */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXRenderer
name|PEXCreateRenderer
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* drawable */
parameter_list|,
name|unsigned
name|long
comment|/* value_mask */
parameter_list|,
name|PEXRendererAttributes
modifier|*
comment|/* values */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXSearchContext
name|PEXCreateSearchContext
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|unsigned
name|long
comment|/* value_mask */
parameter_list|,
name|PEXSCAttributes
modifier|*
comment|/* values */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXStructure
name|PEXCreateStructure
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXWorkstation
name|PEXCreateWorkstation
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* drawable */
parameter_list|,
name|PEXLookupTable
comment|/* line_bundle */
parameter_list|,
name|PEXLookupTable
comment|/* marker_bundle */
parameter_list|,
name|PEXLookupTable
comment|/* text_bundle */
parameter_list|,
name|PEXLookupTable
comment|/* interior_bundle */
parameter_list|,
name|PEXLookupTable
comment|/* edge_bundle */
parameter_list|,
name|PEXLookupTable
comment|/* color_table */
parameter_list|,
name|PEXLookupTable
comment|/* pattern_table */
parameter_list|,
name|PEXLookupTable
comment|/* font_table */
parameter_list|,
name|PEXLookupTable
comment|/* depth_cue_table */
parameter_list|,
name|PEXLookupTable
comment|/* light_table */
parameter_list|,
name|PEXLookupTable
comment|/* color_approx_table */
parameter_list|,
name|PEXNameSet
comment|/* highlight_incl */
parameter_list|,
name|PEXNameSet
comment|/* highlight_excl */
parameter_list|,
name|PEXNameSet
comment|/* invisibility_incl */
parameter_list|,
name|PEXNameSet
comment|/* invisibility_excl */
parameter_list|,
name|int
comment|/* buffer_mode */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXOCData
modifier|*
name|PEXDecodeOCs
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|int
comment|/* float_format */
parameter_list|,
name|unsigned
name|long
comment|/* oc_count */
parameter_list|,
name|unsigned
name|long
comment|/* length */
parameter_list|,
name|char
modifier|*
comment|/* encoded_ocs */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXDeleteBetweenLabels
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|long
comment|/* label1 */
parameter_list|,
name|long
comment|/* label2 */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXDeleteElements
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|int
comment|/* whence1 */
parameter_list|,
name|long
comment|/* offset1 */
parameter_list|,
name|int
comment|/* whence2 */
parameter_list|,
name|long
comment|/* offset2 */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXDeleteTableEntries
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXLookupTable
comment|/* table */
parameter_list|,
name|unsigned
name|int
comment|/* start */
parameter_list|,
name|unsigned
name|int
comment|/* count */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXDeleteToLabel
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|int
comment|/* whence */
parameter_list|,
name|long
comment|/* offset */
parameter_list|,
name|long
comment|/* label */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXDestroyStructures
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|unsigned
name|long
comment|/* count */
parameter_list|,
name|PEXStructure
modifier|*
comment|/* structures */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXElementSearch
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|int
comment|/* whence */
parameter_list|,
name|long
comment|/* offset */
parameter_list|,
name|int
comment|/* direction */
parameter_list|,
name|unsigned
name|long
comment|/* incl_count */
parameter_list|,
name|unsigned
name|short
modifier|*
comment|/* incl_list */
parameter_list|,
name|unsigned
name|long
comment|/* excl_count */
parameter_list|,
name|unsigned
name|short
modifier|*
comment|/* excl_list */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* elem_offset_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
name|PEXEncodeOCs
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|int
comment|/* float_format */
parameter_list|,
name|unsigned
name|long
comment|/* oc_count */
parameter_list|,
name|PEXOCData
modifier|*
comment|/* oc_data */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* length_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXEncodedAnnoText
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* origin */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* offset */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXEncodedTextData
modifier|*
comment|/* encoded_text */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXEncodedAnnoText2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* origin */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* offset */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXEncodedTextData
modifier|*
comment|/* encoded_text */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXEncodedText
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* origin */
parameter_list|,
name|PEXVector
modifier|*
comment|/* vector1 */
parameter_list|,
name|PEXVector
modifier|*
comment|/* vector2 */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXEncodedTextData
modifier|*
comment|/* encoded_text */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXEncodedText2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* origin */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXEncodedTextData
modifier|*
comment|/* encoded_text */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXPickPath
modifier|*
name|PEXEndPickAll
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
parameter_list|,
name|int
modifier|*
comment|/* status_return */
parameter_list|,
name|int
modifier|*
comment|/* more_return */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* count_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXPickPath
modifier|*
name|PEXEndPickOne
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
parameter_list|,
name|int
modifier|*
comment|/* status_return */
parameter_list|,
name|int
modifier|*
comment|/* undetectable_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXEndRendering
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
parameter_list|,
name|int
comment|/* flush */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXEndStructure
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXEscape
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|unsigned
name|long
comment|/* escape_id */
parameter_list|,
name|int
comment|/* length */
parameter_list|,
name|char
modifier|*
comment|/* escape_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
name|PEXEscapeWithReply
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|unsigned
name|long
comment|/* escape_id */
parameter_list|,
name|int
comment|/* length */
parameter_list|,
name|char
modifier|*
comment|/* escape_data */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* reply_length_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXExecuteDeferredActions
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXExecuteStructure
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXStructure
comment|/* structure */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXExtendedCellArray
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* point1 */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* point2 */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* point3 */
parameter_list|,
name|unsigned
name|int
comment|/* col_count */
parameter_list|,
name|unsigned
name|int
comment|/* row_count */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|PEXArrayOfColor
comment|/* colors */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXFetchElements
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|int
comment|/* whence1 */
parameter_list|,
name|long
comment|/* offset1 */
parameter_list|,
name|int
comment|/* whence2 */
parameter_list|,
name|long
comment|/* offset2 */
parameter_list|,
name|int
comment|/* float_format */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* count_return */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* length_return */
parameter_list|,
name|char
modifier|*
modifier|*
comment|/* ocs_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXFetchElementsAndSend
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* src_display */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|int
comment|/* whence1 */
parameter_list|,
name|long
comment|/* offset1 */
parameter_list|,
name|int
comment|/* whence2 */
parameter_list|,
name|long
comment|/* offset2 */
parameter_list|,
name|Display
modifier|*
comment|/* dst_display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFillArea
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* shape_hint */
parameter_list|,
name|int
comment|/* ignore_edges */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* points */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFillArea2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* shape_hint */
parameter_list|,
name|int
comment|/* ignore_edges */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* points */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFillAreaSet
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* shape_hint */
parameter_list|,
name|int
comment|/* ignore_edges */
parameter_list|,
name|int
comment|/* contour_hint */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXListOfCoord
modifier|*
comment|/* point_lists */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFillAreaSet2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* shape_hint */
parameter_list|,
name|int
comment|/* ignore_edges */
parameter_list|,
name|int
comment|/* contour_hint */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXListOfCoord2D
modifier|*
comment|/* point_lists */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFillAreaSetWithData
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* shape_hint */
parameter_list|,
name|int
comment|/* ignore_edges */
parameter_list|,
name|int
comment|/* contour_hint */
parameter_list|,
name|unsigned
name|int
comment|/* facet_attributes */
parameter_list|,
name|unsigned
name|int
comment|/* vertex_attributes */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXFacetData
modifier|*
comment|/* facet_data */
parameter_list|,
name|PEXListOfVertex
modifier|*
comment|/* vertex_lists */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFillAreaWithData
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* shape_hint */
parameter_list|,
name|int
comment|/* ignore_edges */
parameter_list|,
name|unsigned
name|int
comment|/* facet_attributes */
parameter_list|,
name|unsigned
name|int
comment|/* vertex_attributes */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|PEXFacetData
modifier|*
comment|/* facet_data */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXArrayOfVertex
comment|/* vertices */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFinishOCs
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreeEnumInfo
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|unsigned
name|long
comment|/* count */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* info_count */
parameter_list|,
name|PEXEnumTypeDesc
modifier|*
comment|/* enum_info */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreeFontInfo
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|unsigned
name|long
comment|/* count */
parameter_list|,
name|PEXFontInfo
modifier|*
comment|/* font_info */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreeFontNames
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|unsigned
name|long
comment|/* count */
parameter_list|,
name|char
modifier|*
modifier|*
comment|/* font_names */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreeLookupTable
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXLookupTable
comment|/* table */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreeNameSet
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXNameSet
comment|/* nameset */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreeOCData
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|unsigned
name|long
comment|/* count */
parameter_list|,
name|PEXOCData
modifier|*
comment|/* oc_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreePCAttributes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXPCAttributes
modifier|*
comment|/* values */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreePDAttributes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXPDAttributes
modifier|*
comment|/* values */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreePMAttributes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXPMAttributes
modifier|*
comment|/* values */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreePickMeasure
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXPickMeasure
comment|/* pick_measure */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreePickPaths
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|unsigned
name|long
comment|/* count */
parameter_list|,
name|PEXPickPath
modifier|*
comment|/* pick_paths */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreePipelineContext
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXPipelineContext
comment|/* context */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreeRenderer
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreeRendererAttributes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXRendererAttributes
modifier|*
comment|/* values */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreeSCAttributes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXSCAttributes
modifier|*
comment|/* values */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreeSearchContext
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXSearchContext
comment|/* context */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreeStructurePaths
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|unsigned
name|long
comment|/* count */
parameter_list|,
name|PEXStructurePath
modifier|*
comment|/* paths */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreeTableEntries
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|int
comment|/* table_type */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXPointer
comment|/* entries */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreeWorkstation
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXFreeWorkstationAttributes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXWorkstationAttributes
modifier|*
comment|/* values */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXGDP
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|long
comment|/* gdp_id */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* points */
parameter_list|,
name|unsigned
name|long
comment|/* length */
parameter_list|,
name|char
modifier|*
comment|/* data */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXGDP2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|long
comment|/* gdp_id */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* points */
parameter_list|,
name|unsigned
name|long
comment|/* length */
parameter_list|,
name|char
modifier|*
comment|/* data */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXGSE
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|long
comment|/* id */
parameter_list|,
name|int
comment|/* length */
parameter_list|,
name|char
modifier|*
comment|/* data */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXGeoNormFillArea
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|unsigned
name|int
comment|/* facet_attributes */
parameter_list|,
name|unsigned
name|int
comment|/* vertex_attributes */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|PEXFacetData
modifier|*
comment|/* facet_data */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXArrayOfVertex
comment|/* vertices */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXGeoNormFillAreaSet
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|unsigned
name|int
comment|/* facet_attributes */
parameter_list|,
name|unsigned
name|int
comment|/* vertex_attributes */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXFacetData
modifier|*
comment|/* facet_data */
parameter_list|,
name|PEXListOfVertex
modifier|*
comment|/* vertex_lists */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXGeoNormQuadrilateralMesh
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|unsigned
name|int
comment|/* facet_attributes */
parameter_list|,
name|unsigned
name|int
comment|/* vertex_attributes */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|PEXArrayOfFacetData
comment|/* facet_data */
parameter_list|,
name|unsigned
name|int
comment|/* col_count */
parameter_list|,
name|unsigned
name|int
comment|/* row_count */
parameter_list|,
name|PEXArrayOfVertex
comment|/* vertices */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXGeoNormSetOfFillAreaSets
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|unsigned
name|int
comment|/* facet_attributes */
parameter_list|,
name|unsigned
name|int
comment|/* vertex_attributes */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|unsigned
name|int
comment|/* set_count */
parameter_list|,
name|PEXArrayOfFacetData
comment|/* facet_data */
parameter_list|,
name|unsigned
name|int
comment|/* vertex_count */
parameter_list|,
name|PEXArrayOfVertex
comment|/* vertices */
parameter_list|,
name|unsigned
name|int
comment|/* index_count */
parameter_list|,
name|PEXConnectivityData
modifier|*
comment|/* connectivity */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXGeoNormTriangleStrip
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|unsigned
name|int
comment|/* facet_attributes */
parameter_list|,
name|unsigned
name|int
comment|/* vertex_attributes */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|PEXArrayOfFacetData
comment|/* facet_data */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXArrayOfVertex
comment|/* vertices */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXStructurePath
modifier|*
name|PEXGetAncestors
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|int
comment|/* path_part */
parameter_list|,
name|unsigned
name|long
comment|/* path_depth */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* count_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXGetDefinedIndices
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXLookupTable
comment|/* table */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* count_return */
parameter_list|,
name|PEXTableIndex
modifier|*
modifier|*
comment|/* indices_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXStructurePath
modifier|*
name|PEXGetDescendants
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|int
comment|/* path_part */
parameter_list|,
name|unsigned
name|long
comment|/* path_depth */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* count_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXGetElementInfo
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|int
comment|/* whence1 */
parameter_list|,
name|long
comment|/* offset1 */
parameter_list|,
name|int
comment|/* whence2 */
parameter_list|,
name|long
comment|/* offset2 */
parameter_list|,
name|int
comment|/* float_format */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* count_return */
parameter_list|,
name|PEXElementInfo
modifier|*
modifier|*
comment|/* info_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXGetEnumTypeInfo
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* drawable */
parameter_list|,
name|unsigned
name|long
comment|/* count */
parameter_list|,
name|int
modifier|*
comment|/* enum_types */
parameter_list|,
name|unsigned
name|long
comment|/* item_mask */
parameter_list|,
name|unsigned
name|long
modifier|*
modifier|*
comment|/* info_count_return */
parameter_list|,
name|PEXEnumTypeDesc
modifier|*
modifier|*
comment|/* enum_info_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXExtensionInfo
modifier|*
name|PEXGetExtensionInfo
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXGetImpDepConstants
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* drawable */
parameter_list|,
name|unsigned
name|long
comment|/* count */
parameter_list|,
name|unsigned
name|short
modifier|*
comment|/* names */
parameter_list|,
name|PEXImpDepConstant
modifier|*
modifier|*
comment|/* constants_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXGetNameSet
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXNameSet
comment|/* nameset */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* count_return */
parameter_list|,
name|PEXName
modifier|*
modifier|*
comment|/* names_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
name|PEXGetOCAddr
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|int
comment|/* length */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXPDAttributes
modifier|*
name|PEXGetPickDevice
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|int
comment|/* pick_device_type */
parameter_list|,
name|unsigned
name|long
comment|/* value_mask */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXPMAttributes
modifier|*
name|PEXGetPickMeasure
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXPickMeasure
comment|/* pick_measure */
parameter_list|,
name|unsigned
name|long
comment|/* value_mask */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXPCAttributes
modifier|*
name|PEXGetPipelineContext
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXPipelineContext
comment|/* context */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* value_mask */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXGetPredefinedEntries
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* drawable */
parameter_list|,
name|int
comment|/* table_type */
parameter_list|,
name|unsigned
name|int
comment|/* start */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXPointer
modifier|*
comment|/* entries_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXGetProtocolFloatFormat
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXRendererAttributes
modifier|*
name|PEXGetRendererAttributes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
parameter_list|,
name|unsigned
name|long
comment|/* value_mask */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXGetRendererDynamics
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* tables_return */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* name_sets_return */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* attributes_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXSCAttributes
modifier|*
name|PEXGetSearchContext
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXSearchContext
comment|/* context */
parameter_list|,
name|unsigned
name|long
comment|/* value_mask */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXGetSizeOCs
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|int
comment|/* float_format */
parameter_list|,
name|int
comment|/* oc_count */
parameter_list|,
name|PEXOCData
modifier|*
comment|/* oc_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXGetStructureInfo
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|int
comment|/* float_format */
parameter_list|,
name|unsigned
name|long
comment|/* value_mask */
parameter_list|,
name|PEXStructureInfo
modifier|*
comment|/* info_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXStructure
modifier|*
name|PEXGetStructuresInNetwork
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|int
comment|/* which */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* count_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXGetTableEntries
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXLookupTable
comment|/* table */
parameter_list|,
name|unsigned
name|int
comment|/* start */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|int
comment|/* value_type */
parameter_list|,
name|int
modifier|*
comment|/* table_type_return */
parameter_list|,
name|PEXPointer
modifier|*
comment|/* entries_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXPointer
name|PEXGetTableEntry
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXLookupTable
comment|/* table */
parameter_list|,
name|unsigned
name|int
comment|/* index */
parameter_list|,
name|int
comment|/* value_type */
parameter_list|,
name|int
modifier|*
comment|/* status_return */
parameter_list|,
name|int
modifier|*
comment|/* table_type_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXGetTableInfo
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* drawable */
parameter_list|,
name|int
comment|/* table_type */
parameter_list|,
name|PEXTableInfo
modifier|*
comment|/* info_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXWorkstationAttributes
modifier|*
name|PEXGetWorkstationAttributes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* value_mask */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXGetWorkstationDynamics
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* drawable */
parameter_list|,
name|PEXWorkstationDynamics
modifier|*
comment|/* dynamics_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXGetWorkstationPostings
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* count_return */
parameter_list|,
name|PEXWorkstation
modifier|*
modifier|*
comment|/* postings_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXGetWorkstationViewRep
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|unsigned
name|int
comment|/* index */
parameter_list|,
name|int
modifier|*
comment|/* update_return */
parameter_list|,
name|PEXViewRep
modifier|*
comment|/* req_view_return */
parameter_list|,
name|PEXViewRep
modifier|*
comment|/* cur_view_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXIdentityMatrix
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXMatrix
comment|/* transform_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXIdentityMatrix2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXMatrix3x3
comment|/* transform_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXInitialize
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXExtensionInfo
modifier|*
modifier|*
comment|/* info_return */
parameter_list|,
name|int
comment|/* length */
parameter_list|,
name|char
modifier|*
comment|/* error_string */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXInvertMatrix
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXMatrix
comment|/* transform */
parameter_list|,
name|PEXMatrix
comment|/* transform_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXInvertMatrix2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXMatrix3x3
comment|/* transform */
parameter_list|,
name|PEXMatrix3x3
comment|/* transform_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXLabel
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|long
comment|/* label */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
modifier|*
name|PEXListFonts
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|char
modifier|*
comment|/* pattern */
parameter_list|,
name|unsigned
name|int
comment|/* max_names */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* count_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|*
modifier|*
name|PEXListFontsWithInfo
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|char
modifier|*
comment|/* pattern */
parameter_list|,
name|unsigned
name|int
comment|/* max_names */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* count_return */
parameter_list|,
name|PEXFontInfo
modifier|*
modifier|*
comment|/* info_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXFont
name|PEXLoadFont
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|char
modifier|*
comment|/* font_name */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXLookAtViewMatrix
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXCoord
modifier|*
comment|/* from */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* to */
parameter_list|,
name|PEXVector
modifier|*
comment|/* up */
parameter_list|,
name|PEXMatrix
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXMapDCToWC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|unsigned
name|long
comment|/* dc_count */
parameter_list|,
name|PEXDeviceCoord
modifier|*
comment|/* dc_points */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* view_index_return */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* wc_count_return */
parameter_list|,
name|PEXCoord
modifier|*
modifier|*
comment|/* wc_points_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXMapWCToDC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|unsigned
name|long
comment|/* wc_count */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* wc_points */
parameter_list|,
name|unsigned
name|int
comment|/* view_index */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* dc_count_return */
parameter_list|,
name|PEXDeviceCoord
modifier|*
modifier|*
comment|/* dc_points_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXMapXCToNPC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|int
comment|/* point_count */
parameter_list|,
name|PEXDeviceCoord2D
modifier|*
comment|/* points */
parameter_list|,
name|unsigned
name|int
comment|/* window_height */
parameter_list|,
name|double
comment|/* z_dc */
parameter_list|,
name|PEXDeviceCoord
modifier|*
comment|/* viewport */
parameter_list|,
name|PEXNPCSubVolume
modifier|*
comment|/* npc_sub_volume */
parameter_list|,
name|int
comment|/* view_count */
parameter_list|,
name|PEXViewEntry
modifier|*
comment|/* views */
parameter_list|,
name|int
modifier|*
comment|/* view_return */
parameter_list|,
name|int
modifier|*
comment|/* count_return */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* points_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXMapXCToNPC2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|int
comment|/* point_count */
parameter_list|,
name|PEXDeviceCoord2D
modifier|*
comment|/* points */
parameter_list|,
name|unsigned
name|int
comment|/* window_height */
parameter_list|,
name|PEXDeviceCoord2D
modifier|*
comment|/* viewport */
parameter_list|,
name|PEXNPCSubVolume
modifier|*
comment|/* npc_sub_volume */
parameter_list|,
name|int
comment|/* view_count */
parameter_list|,
name|PEXViewEntry
modifier|*
comment|/* views */
parameter_list|,
name|int
modifier|*
comment|/* view_return */
parameter_list|,
name|int
modifier|*
comment|/* count_return */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* points_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXMarkers
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* points */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXMarkers2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* points */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXMatchRenderingTargets
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* drawable */
parameter_list|,
name|int
comment|/* depth */
parameter_list|,
name|int
comment|/* type */
parameter_list|,
name|Visual
modifier|*
comment|/* visual */
parameter_list|,
name|unsigned
name|long
comment|/* max_targets */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* count_return */
parameter_list|,
name|PEXRenderingTarget
modifier|*
modifier|*
comment|/* targets_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXMatrixMult
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXMatrix
comment|/* matrix1 */
parameter_list|,
name|PEXMatrix
comment|/* matrix2 */
parameter_list|,
name|PEXMatrix
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXMatrixMult2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXMatrix3x3
comment|/* matrix1 */
parameter_list|,
name|PEXMatrix3x3
comment|/* matrix2 */
parameter_list|,
name|PEXMatrix3x3
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXNPCToXCTransform
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXNPCSubVolume
modifier|*
comment|/* npc_sub_volume */
parameter_list|,
name|PEXDeviceCoord
modifier|*
comment|/* viewport */
parameter_list|,
name|unsigned
name|int
comment|/* window_height */
parameter_list|,
name|PEXMatrix
comment|/* transform_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXNPCToXCTransform2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXNPCSubVolume
modifier|*
comment|/* npc_sub_volume */
parameter_list|,
name|PEXDeviceCoord2D
modifier|*
comment|/* viewport */
parameter_list|,
name|unsigned
name|int
comment|/* window_height */
parameter_list|,
name|PEXMatrix3x3
comment|/* transform_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXNURBCurve
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* rationality */
parameter_list|,
name|int
comment|/* order */
parameter_list|,
name|float
modifier|*
comment|/* knots */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXArrayOfCoord
comment|/* points */
parameter_list|,
name|double
comment|/* tmin */
parameter_list|,
name|double
comment|/* tmax */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXNURBSurface
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* rationality */
parameter_list|,
name|int
comment|/* uorder */
parameter_list|,
name|int
comment|/* vorder */
parameter_list|,
name|float
modifier|*
comment|/* uknots */
parameter_list|,
name|float
modifier|*
comment|/* vknots */
parameter_list|,
name|unsigned
name|int
comment|/* col_count */
parameter_list|,
name|unsigned
name|int
comment|/* row_count */
parameter_list|,
name|PEXArrayOfCoord
comment|/* points */
parameter_list|,
name|unsigned
name|int
comment|/* curve_count */
parameter_list|,
name|PEXListOfTrimCurve
modifier|*
comment|/* trim_curves */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXNoop
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXNormalizeVectors
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|int
comment|/* count */
parameter_list|,
name|PEXVector
modifier|*
comment|/* vectors */
parameter_list|,
name|PEXVector
modifier|*
comment|/* vectors_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXNormalizeVectors2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|int
comment|/* count */
parameter_list|,
name|PEXVector2D
modifier|*
comment|/* vectors */
parameter_list|,
name|PEXVector2D
modifier|*
comment|/* vectors_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXOrthoProjMatrix
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|double
comment|/* height */
parameter_list|,
name|double
comment|/* aspect */
parameter_list|,
name|double
comment|/* near */
parameter_list|,
name|double
comment|/* far */
parameter_list|,
name|PEXMatrix
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXPerspProjMatrix
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|double
comment|/* fovy */
parameter_list|,
name|double
comment|/* distance */
parameter_list|,
name|double
comment|/* aspect */
parameter_list|,
name|double
comment|/* near */
parameter_list|,
name|double
comment|/* far */
parameter_list|,
name|PEXMatrix
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXPickPath
modifier|*
name|PEXPickAll
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* drawable */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
parameter_list|,
name|int
comment|/* method */
parameter_list|,
name|int
comment|/* max_hits */
parameter_list|,
name|int
comment|/* pick_device_type */
parameter_list|,
name|PEXPickRecord
modifier|*
comment|/* pick_record */
parameter_list|,
name|int
modifier|*
comment|/* status_return */
parameter_list|,
name|int
modifier|*
comment|/* more_return */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* count_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXPickPath
modifier|*
name|PEXPickOne
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* drawable */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|int
comment|/* method */
parameter_list|,
name|int
comment|/* pick_device_type */
parameter_list|,
name|PEXPickRecord
modifier|*
comment|/* pick_record */
parameter_list|,
name|int
modifier|*
comment|/* status_return */
parameter_list|,
name|int
modifier|*
comment|/* undetectable_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXPolarViewMatrix
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXCoord
modifier|*
comment|/* from */
parameter_list|,
name|double
comment|/* distance */
parameter_list|,
name|double
comment|/* azimuth */
parameter_list|,
name|double
comment|/* altitude */
parameter_list|,
name|double
comment|/* twist */
parameter_list|,
name|PEXMatrix
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXPolyline
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* points */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXPolyline2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* points */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXPolylineSetWithData
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* vertex_attributes */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXListOfVertex
modifier|*
comment|/* vertex_lists */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXPostStructure
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|double
comment|/* priority */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXQuadrilateralMesh
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* shape_hint */
parameter_list|,
name|unsigned
name|int
comment|/* facet_attributes */
parameter_list|,
name|unsigned
name|int
comment|/* vertex_attributes */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|PEXArrayOfFacetData
comment|/* facet_data */
parameter_list|,
name|unsigned
name|int
comment|/* col_count */
parameter_list|,
name|unsigned
name|int
comment|/* row_count */
parameter_list|,
name|PEXArrayOfVertex
comment|/* vertices */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXTextExtent
modifier|*
name|PEXQueryEncodedTextExtents
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|unsigned
name|int
comment|/* font_table_index */
parameter_list|,
name|int
comment|/* path */
parameter_list|,
name|double
comment|/* expansion */
parameter_list|,
name|double
comment|/* spacing */
parameter_list|,
name|double
comment|/* height */
parameter_list|,
name|int
comment|/* halign */
parameter_list|,
name|int
comment|/* valign */
parameter_list|,
name|unsigned
name|long
comment|/* count */
parameter_list|,
name|PEXListOfEncodedText
modifier|*
comment|/* encoded_text */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXFontInfo
modifier|*
name|PEXQueryFont
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXFont
comment|/* font */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|PEXTextExtent
modifier|*
name|PEXQueryTextExtents
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|unsigned
name|int
comment|/* font_table_index */
parameter_list|,
name|int
comment|/* path */
parameter_list|,
name|double
comment|/* expansion */
parameter_list|,
name|double
comment|/* spacing */
parameter_list|,
name|double
comment|/* height */
parameter_list|,
name|int
comment|/* halign */
parameter_list|,
name|int
comment|/* valign */
parameter_list|,
name|unsigned
name|long
comment|/* count */
parameter_list|,
name|PEXStringData
modifier|*
comment|/* text */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXRedrawAllStructures
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXRedrawClipRegion
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|unsigned
name|long
comment|/* count */
parameter_list|,
name|PEXDeviceRect
modifier|*
comment|/* clip_rectangles */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXRemoveFromNameSet
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|long
comment|/* count */
parameter_list|,
name|PEXName
modifier|*
comment|/* names */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXRenderElements
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|int
comment|/* whence1 */
parameter_list|,
name|long
comment|/* offset1 */
parameter_list|,
name|int
comment|/* whence2 */
parameter_list|,
name|long
comment|/* offset2 */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXRenderNetwork
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* drawable */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
parameter_list|,
name|PEXStructure
comment|/* structure */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXRestoreModelClipVolume
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXRotate
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|int
comment|/* axis */
parameter_list|,
name|double
comment|/* angle */
parameter_list|,
name|PEXMatrix
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXRotate2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|double
comment|/* angle */
parameter_list|,
name|PEXMatrix3x3
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXRotateGeneral
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXCoord
modifier|*
comment|/* point1 */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* point2 */
parameter_list|,
name|double
comment|/* angle */
parameter_list|,
name|PEXMatrix
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXScale
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXVector
modifier|*
comment|/* scale_vector */
parameter_list|,
name|PEXMatrix
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXScale2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXVector2D
modifier|*
comment|/* scale_vector */
parameter_list|,
name|PEXMatrix3x3
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXSearchNetwork
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXSearchContext
comment|/* context */
parameter_list|,
name|PEXStructurePath
modifier|*
modifier|*
comment|/* path_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSendOCs
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* float_format */
parameter_list|,
name|unsigned
name|long
comment|/* oc_count */
parameter_list|,
name|unsigned
name|int
comment|/* length */
parameter_list|,
name|char
modifier|*
comment|/* encoded_ocs */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetATextAlignment
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* halignment */
parameter_list|,
name|int
comment|/* valignment */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetATextHeight
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|double
comment|/* height */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetATextPath
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* path */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetATextStyle
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* style */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetATextUpVector
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXVector2D
modifier|*
comment|/* vector */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetBFInteriorStyle
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* style */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetBFInteriorStyleIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetBFReflectionAttributes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXReflectionAttributes
modifier|*
comment|/* attributes */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetBFReflectionModel
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* model */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetBFSurfaceColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|PEXColor
modifier|*
comment|/* color */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetBFSurfaceColorIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetBFSurfaceInterpMethod
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* method */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetCharExpansion
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|double
comment|/* expansion */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetCharHeight
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|double
comment|/* height */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetCharSpacing
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|double
comment|/* spacing */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetCharUpVector
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXVector2D
modifier|*
comment|/* vector */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetColorApproxIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetCurveApprox
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* method */
parameter_list|,
name|double
comment|/* tolerance */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetDepthCueIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetEchoColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXRenderer
comment|/* renderer */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|PEXColor
modifier|*
comment|/* color */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetEdgeBundleIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetEditingMode
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|int
comment|/* mode */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetElementPtr
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|int
comment|/* whence */
parameter_list|,
name|long
comment|/* offset */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetElementPtrAtLabel
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXStructure
comment|/* structure */
parameter_list|,
name|long
comment|/* label */
parameter_list|,
name|long
comment|/* offset */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetFacetCullingMode
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* mode */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetFacetDistinguishFlag
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* flag */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetGlobalTransform
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXMatrix
comment|/* transform */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetGlobalTransform2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXMatrix3x3
comment|/* transform */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetHLHSRID
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|long
comment|/* hlhsr_id */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetIndividualASF
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|long
comment|/* attribute */
parameter_list|,
name|int
comment|/* asf */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetInteriorBundleIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetInteriorStyle
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* style */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetInteriorStyleIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetLightSourceState
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* enable_count */
parameter_list|,
name|PEXTableIndex
modifier|*
comment|/* enable */
parameter_list|,
name|unsigned
name|int
comment|/* disable_count */
parameter_list|,
name|PEXTableIndex
modifier|*
comment|/* disable */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetLineBundleIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetLineColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|PEXColor
modifier|*
comment|/* color */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetLineColorIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetLineType
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* line_type */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetLineWidth
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|double
comment|/* width */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetLocalTransform
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* composition */
parameter_list|,
name|PEXMatrix
comment|/* transform */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetLocalTransform2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* composition */
parameter_list|,
name|PEXMatrix3x3
comment|/* transform */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetMarkerBundleIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetMarkerColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|PEXColor
modifier|*
comment|/* color */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetMarkerColorIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetMarkerScale
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|double
comment|/* scale */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetMarkerType
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* marker_type */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetModelClipFlag
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* flag */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetModelClipVolume
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* op */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXHalfSpace
modifier|*
comment|/* half_spaces */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetModelClipVolume2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* op */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXHalfSpace2D
modifier|*
comment|/* half_spaces */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetOfFillAreaSets
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* shape_hint */
parameter_list|,
name|unsigned
name|int
comment|/* facet_attributes */
parameter_list|,
name|unsigned
name|int
comment|/* vertex_attributes */
parameter_list|,
name|unsigned
name|int
comment|/* edge_attributes */
parameter_list|,
name|int
comment|/* contour_hint */
parameter_list|,
name|int
comment|/* contours_all_one */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|unsigned
name|int
comment|/* set_count */
parameter_list|,
name|PEXArrayOfFacetData
comment|/* facet_data */
parameter_list|,
name|unsigned
name|int
comment|/* vertex_count */
parameter_list|,
name|PEXArrayOfVertex
comment|/* vertices */
parameter_list|,
name|unsigned
name|int
comment|/* index_count */
parameter_list|,
name|PEXSwitch
modifier|*
comment|/* edge_flags */
parameter_list|,
name|PEXConnectivityData
modifier|*
comment|/* connectivity */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetParaSurfCharacteristics
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* psc_type */
parameter_list|,
name|PEXPSCData
modifier|*
comment|/* characteristics */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetPatternAttributes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* ref_point */
parameter_list|,
name|PEXVector
modifier|*
comment|/* vector1 */
parameter_list|,
name|PEXVector
modifier|*
comment|/* vector2 */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetPatternAttributes2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* ref_point */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetPatternSize
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|double
comment|/* width */
parameter_list|,
name|double
comment|/* height */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetPickID
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|long
comment|/* pick_id */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetPolylineInterpMethod
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* method */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetReflectionAttributes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXReflectionAttributes
modifier|*
comment|/* attributes */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetReflectionModel
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* model */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetRenderingColorModel
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* model */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetSurfaceApprox
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* method */
parameter_list|,
name|double
comment|/* utolerance */
parameter_list|,
name|double
comment|/* vtolerance */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetSurfaceColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|PEXColor
modifier|*
comment|/* color */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetSurfaceColorIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetSurfaceEdgeColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|PEXColor
modifier|*
comment|/* color */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetSurfaceEdgeColorIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetSurfaceEdgeFlag
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* flag */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetSurfaceEdgeType
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* edge_type */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetSurfaceEdgeWidth
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|double
comment|/* width */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetSurfaceInterpMethod
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* method */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetTableEntries
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXLookupTable
comment|/* table */
parameter_list|,
name|unsigned
name|int
comment|/* start */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|int
comment|/* table_type */
parameter_list|,
name|PEXPointer
comment|/* entries */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetTextAlignment
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* halignment */
parameter_list|,
name|int
comment|/* valignment */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetTextBundleIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetTextColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|PEXColor
modifier|*
comment|/* color */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetTextColorIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetTextFontIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetTextPath
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* path */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetTextPrecision
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* precision */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetViewIndex
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetWorkstationBufferMode
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|int
comment|/* buffer_mode */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetWorkstationDisplayUpdateMode
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|int
comment|/* update_mode */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetWorkstationHLHSRMode
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|int
comment|/* hlhsr_mode */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetWorkstationViewPriority
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|unsigned
name|int
comment|/* index1 */
parameter_list|,
name|unsigned
name|int
comment|/* index2 */
parameter_list|,
name|int
comment|/* priority */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetWorkstationViewRep
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|unsigned
name|int
comment|/* view_index */
parameter_list|,
name|PEXViewEntry
modifier|*
comment|/* values */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetWorkstationViewport
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|PEXViewport
modifier|*
comment|/* viewport */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXSetWorkstationWindow
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|PEXNPCSubVolume
modifier|*
comment|/* workstation_window */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|Status
name|PEXStartOCs
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|int
comment|/* float_format */
parameter_list|,
name|int
comment|/* oc_count */
parameter_list|,
name|int
comment|/* word_count */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXText
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* origin */
parameter_list|,
name|PEXVector
modifier|*
comment|/* vector1 */
parameter_list|,
name|PEXVector
modifier|*
comment|/* vector2 */
parameter_list|,
name|int
comment|/* length */
parameter_list|,
name|char
modifier|*
comment|/* string */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXText2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* origin */
parameter_list|,
name|int
comment|/* length */
parameter_list|,
name|char
modifier|*
comment|/* string */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXTransformPoints
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXMatrix
comment|/* transform */
parameter_list|,
name|int
comment|/* count */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* points */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* points_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXTransformPoints2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXMatrix3x3
comment|/* transform */
parameter_list|,
name|int
comment|/* count */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* points */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* points_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXTransformPoints2DH
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXMatrix3x3
comment|/* transform */
parameter_list|,
name|int
comment|/* count */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* points */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* points_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXTransformPoints4D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXMatrix
comment|/* transform */
parameter_list|,
name|int
comment|/* count */
parameter_list|,
name|PEXCoord4D
modifier|*
comment|/* points */
parameter_list|,
name|PEXCoord4D
modifier|*
comment|/* points_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXTransformVectors
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXMatrix
comment|/* transform */
parameter_list|,
name|int
comment|/* count */
parameter_list|,
name|PEXVector
modifier|*
comment|/* vectors */
parameter_list|,
name|PEXVector
modifier|*
comment|/* vectors_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXTransformVectors2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXMatrix3x3
comment|/* transform */
parameter_list|,
name|int
comment|/* count */
parameter_list|,
name|PEXVector2D
modifier|*
comment|/* vectors */
parameter_list|,
name|PEXVector2D
modifier|*
comment|/* vectors_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXTranslate
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXVector
modifier|*
comment|/* trans_vector */
parameter_list|,
name|PEXMatrix
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXTranslate2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXVector2D
modifier|*
comment|/* trans_vector */
parameter_list|,
name|PEXMatrix3x3
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXTriangleStrip
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* resource_id */
parameter_list|,
name|PEXOCRequestType
comment|/* req_type */
parameter_list|,
name|unsigned
name|int
comment|/* facet_attributes */
parameter_list|,
name|unsigned
name|int
comment|/* vertex_attributes */
parameter_list|,
name|int
comment|/* color_type */
parameter_list|,
name|PEXArrayOfFacetData
comment|/* facet_data */
parameter_list|,
name|unsigned
name|int
comment|/* count */
parameter_list|,
name|PEXArrayOfVertex
comment|/* vertices */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXUnloadFont
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXFont
comment|/* font */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXUnpostAllStructures
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXUnpostStructure
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
parameter_list|,
name|PEXStructure
comment|/* structure */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXUpdatePickMeasure
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXPickMeasure
comment|/* pick_measure */
parameter_list|,
name|int
comment|/* pick_device_type */
parameter_list|,
name|PEXPickRecord
modifier|*
comment|/* pick_record */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|void
name|PEXUpdateWorkstation
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|PEXWorkstation
comment|/* workstation */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXViewMappingMatrix
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXCoord2D
modifier|*
comment|/* frame */
parameter_list|,
name|PEXNPCSubVolume
modifier|*
comment|/* viewport */
parameter_list|,
name|int
comment|/* perspective */
parameter_list|,
name|PEXCoord
modifier|*
comment|/* prp */
parameter_list|,
name|double
comment|/* view_plane */
parameter_list|,
name|double
comment|/* back_plane */
parameter_list|,
name|double
comment|/* front_plane */
parameter_list|,
name|PEXMatrix
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXViewMappingMatrix2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXCoord2D
modifier|*
comment|/* frame */
parameter_list|,
name|PEXCoord2D
modifier|*
comment|/* viewport */
parameter_list|,
name|PEXMatrix3x3
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXViewOrientationMatrix
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXCoord
modifier|*
comment|/* vrp */
parameter_list|,
name|PEXVector
modifier|*
comment|/* vpn */
parameter_list|,
name|PEXVector
modifier|*
comment|/* vup */
parameter_list|,
name|PEXMatrix
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXViewOrientationMatrix2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXCoord2D
modifier|*
comment|/* vrp */
parameter_list|,
name|PEXVector2D
modifier|*
comment|/* vup */
parameter_list|,
name|PEXMatrix3x3
comment|/* matrix_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXXCToNPCTransform
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXNPCSubVolume
modifier|*
comment|/* npc_sub_volume */
parameter_list|,
name|PEXDeviceCoord
modifier|*
comment|/* viewport */
parameter_list|,
name|unsigned
name|int
comment|/* window_height */
parameter_list|,
name|PEXMatrix
comment|/* transform_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|int
name|PEXXCToNPCTransform2D
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|PEXNPCSubVolume
modifier|*
comment|/* npc_sub_volume */
parameter_list|,
name|PEXDeviceCoord2D
modifier|*
comment|/* viewport */
parameter_list|,
name|unsigned
name|int
comment|/* window_height */
parameter_list|,
name|PEXMatrix3x3
comment|/* transform_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
specifier|extern
name|unsigned
name|long
name|PEXCountOCs
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|int
comment|/* float_format */
parameter_list|,
name|unsigned
name|long
comment|/* length */
parameter_list|,
name|char
modifier|*
comment|/* encoded_ocs */
endif|#
directive|endif
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_comment
comment|/* for C++ V2.0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PEXLIB_H_ */
end_comment

end_unit

