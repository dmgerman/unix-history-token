begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: PEXprotost.h,v 1.4 92/08/26 13:05:20 mor Exp $ */
end_comment

begin_comment
comment|/****************************************************************************** Copyright 1989, 1990, 1991 by Sun Microsystems, Inc. Copyright 1992 by the Massachusetts Institute of Technology                          All Rights Reserved  Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of Sun Microsystems or M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  Sun Microsystems and M.I.T. make no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty.  SUN MICROSYSTEMS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT  SHALL SUN MICROSYSTEMS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL  DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. ******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PEXPROTOSTR_H
end_ifndef

begin_define
define|#
directive|define
name|PEXPROTOSTR_H
end_define

begin_comment
comment|/* Matches revision 5.1C */
end_comment

begin_include
include|#
directive|include
file|<X11/Xmd.h>
end_include

begin_comment
comment|/* defines things like CARD32 */
end_comment

begin_comment
comment|/* This is FLOAT as defined and used by the Protocol Encoding */
end_comment

begin_typedef
typedef|typedef
name|float
name|PEXFLOAT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CARD32
name|pexAsfAttribute
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CARD8
name|pexAsfValue
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CARD32
name|pexBitmask
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CARD16
name|pexBitmaskShort
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CARD16
name|pexCoordType
typedef|;
end_typedef

begin_comment
comment|/* rational, nonrational */
end_comment

begin_typedef
typedef|typedef
name|CARD16
name|pexComposition
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CARD16
name|pexCullMode
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|BYTE
name|pexDynamicType
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|INT16
name|pexEnumTypeIndex
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|pexLookupTable
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CARD32
name|pexName
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|pexNameSet
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|pexPC
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|pexFont
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|PEXFLOAT
name|pexMatrix
index|[
literal|4
index|]
index|[
literal|4
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|PEXFLOAT
name|pexMatrix3X3
index|[
literal|3
index|]
index|[
literal|3
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|pexPhigsWks
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|pexPickMeasure
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|pexRenderer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|pexSC
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|pexStructure
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CARD8
name|pexSwitch
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CARD16
name|pexTableIndex
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CARD16
name|pexTableType
typedef|;
end_typedef

begin_comment
comment|/* could be smaller if it ever helps */
end_comment

begin_typedef
typedef|typedef
name|CARD16
name|pexTextHAlignment
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CARD16
name|pexTextVAlignment
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CARD16
name|pexTypeOrTableIndex
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pexEnumTypeIndex
name|pexColorType
typedef|;
end_typedef

begin_comment
comment|/* ColorType */
end_comment

begin_comment
comment|/* included in others */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD16
name|length
name|B16
decl_stmt|;
comment|/* list of CARD8 -- don't swap */
block|}
name|pexString
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexStructure
name|sid
name|B32
decl_stmt|;
name|PEXFLOAT
name|priority
decl_stmt|;
block|}
name|pexStructureInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|PEXFLOAT
name|x
decl_stmt|;
name|PEXFLOAT
name|y
decl_stmt|;
block|}
name|pexVector2D
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|PEXFLOAT
name|x
decl_stmt|;
name|PEXFLOAT
name|y
decl_stmt|;
name|PEXFLOAT
name|z
decl_stmt|;
block|}
name|pexVector3D
typedef|;
end_typedef

begin_comment
comment|/* Coord structures */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|PEXFLOAT
name|x
decl_stmt|;
name|PEXFLOAT
name|y
decl_stmt|;
block|}
name|pexCoord2D
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|PEXFLOAT
name|x
decl_stmt|;
name|PEXFLOAT
name|y
decl_stmt|;
name|PEXFLOAT
name|z
decl_stmt|;
block|}
name|pexCoord3D
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|PEXFLOAT
name|x
decl_stmt|;
name|PEXFLOAT
name|y
decl_stmt|;
name|PEXFLOAT
name|z
decl_stmt|;
name|PEXFLOAT
name|w
decl_stmt|;
block|}
name|pexCoord4D
typedef|;
end_typedef

begin_comment
comment|/* Color structures */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|PEXFLOAT
name|red
decl_stmt|;
name|PEXFLOAT
name|green
decl_stmt|;
name|PEXFLOAT
name|blue
decl_stmt|;
block|}
name|pexRgbFloatColor
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|PEXFLOAT
name|hue
decl_stmt|;
name|PEXFLOAT
name|saturation
decl_stmt|;
name|PEXFLOAT
name|value
decl_stmt|;
block|}
name|pexHsvColor
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|PEXFLOAT
name|hue
decl_stmt|;
name|PEXFLOAT
name|lightness
decl_stmt|;
name|PEXFLOAT
name|saturation
decl_stmt|;
block|}
name|pexHlsColor
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|PEXFLOAT
name|x
decl_stmt|;
name|PEXFLOAT
name|y
decl_stmt|;
name|PEXFLOAT
name|z
decl_stmt|;
block|}
name|pexCieColor
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|red
decl_stmt|;
name|CARD8
name|green
decl_stmt|;
name|CARD8
name|blue
decl_stmt|;
name|CARD8
name|pad
decl_stmt|;
block|}
name|pexRgb8Color
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD16
name|red
name|B16
decl_stmt|;
name|CARD16
name|green
name|B16
decl_stmt|;
name|CARD16
name|blue
name|B16
decl_stmt|;
name|CARD16
name|pad
name|B16
decl_stmt|;
block|}
name|pexRgb16Color
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexTableIndex
name|index
name|B16
decl_stmt|;
name|CARD16
name|pad
name|B16
decl_stmt|;
block|}
name|pexIndexedColor
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
union|union
block|{
name|pexIndexedColor
name|indexed
decl_stmt|;
name|pexRgb8Color
name|rgb8
decl_stmt|;
name|pexRgb16Color
name|rgb16
decl_stmt|;
name|pexRgbFloatColor
name|rgbFloat
decl_stmt|;
name|pexHsvColor
name|hsvFloat
decl_stmt|;
name|pexHlsColor
name|hlsFloat
decl_stmt|;
name|pexCieColor
name|cieFloat
decl_stmt|;
block|}
name|format
union|;
block|}
name|pexColor
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|PEXFLOAT
name|first
decl_stmt|;
name|PEXFLOAT
name|second
decl_stmt|;
name|PEXFLOAT
name|third
decl_stmt|;
block|}
name|pexFloatColor
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexColorType
name|colorType
name|B16
decl_stmt|;
comment|/* ColorType enumerated type */
name|CARD16
name|unused
name|B16
decl_stmt|;
comment|/* SINGLE COLOR(colorType) */
block|}
name|pexColorSpecifier
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexEnumTypeIndex
name|approxMethod
name|B16
decl_stmt|;
name|CARD16
name|unused
name|B16
decl_stmt|;
name|PEXFLOAT
name|tolerance
decl_stmt|;
block|}
name|pexCurveApprox
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|INT16
name|x
name|B16
decl_stmt|;
name|INT16
name|y
name|B16
decl_stmt|;
name|PEXFLOAT
name|z
decl_stmt|;
block|}
name|pexDeviceCoord
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|INT16
name|x
name|B16
decl_stmt|;
name|INT16
name|y
name|B16
decl_stmt|;
block|}
name|pexDeviceCoord2D
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|INT16
name|xmin
name|B16
decl_stmt|;
name|INT16
name|ymin
name|B16
decl_stmt|;
name|INT16
name|xmax
name|B16
decl_stmt|;
name|INT16
name|ymax
name|B16
decl_stmt|;
block|}
name|pexDeviceRect
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD16
name|elementType
name|B16
decl_stmt|;
name|CARD16
name|length
name|B16
decl_stmt|;
block|}
name|pexElementInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD16
name|whence
name|B16
decl_stmt|;
name|CARD16
name|unused
name|B16
decl_stmt|;
name|INT32
name|offset
name|B32
decl_stmt|;
block|}
name|pexElementPos
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexElementPos
name|position1
decl_stmt|;
name|pexElementPos
name|position2
decl_stmt|;
block|}
name|pexElementRange
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexStructure
name|structure
name|B32
decl_stmt|;
name|CARD32
name|offset
name|B32
decl_stmt|;
block|}
name|pexElementRef
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexCoord2D
name|lowerLeft
decl_stmt|;
name|pexCoord2D
name|upperRight
decl_stmt|;
name|pexCoord2D
name|concatpoint
decl_stmt|;
block|}
name|pexExtentInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexEnumTypeIndex
name|index
name|B16
decl_stmt|;
name|pexString
name|descriptor
decl_stmt|;
block|}
name|pexEnumTypeDesc
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexCoord3D
name|point
decl_stmt|;
name|pexVector3D
name|vector
decl_stmt|;
block|}
name|pexHalfSpace
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexNameSet
name|incl
decl_stmt|;
name|pexNameSet
name|excl
decl_stmt|;
block|}
name|pexNameSetPair
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexCoord2D
name|point
decl_stmt|;
name|pexVector2D
name|vector
decl_stmt|;
block|}
name|pexHalfSpace2D
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD16
name|composition
name|B16
decl_stmt|;
name|CARD16
name|unused
name|B16
decl_stmt|;
name|pexMatrix
name|matrix
decl_stmt|;
block|}
name|pexLocalTransform3DData
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD16
name|composition
name|B16
decl_stmt|;
name|CARD16
name|unused
name|B16
decl_stmt|;
name|pexMatrix3X3
name|matrix
decl_stmt|;
block|}
name|pexLocalTransform2DData
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexCoord3D
name|minval
decl_stmt|;
name|pexCoord3D
name|maxval
decl_stmt|;
block|}
name|pexNpcSubvolume
typedef|;
end_typedef

begin_comment
comment|/*  an OPT_DATA  structure cannot be defined because it has variable content  *  and size.  An union structure could be used to define a template for  *  the data. However, since unions pad to a fixed amount of space and the  *  protocol uses variable lengths, this is not appropriate for protocol  *  data types.  The most correct way of defining this data is to define  *  one data structure for every possible combination of color, normal and  *  edge data that could be given with a vertex or facet.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexStructure
name|sid
name|B32
decl_stmt|;
name|CARD32
name|offset
name|B32
decl_stmt|;
name|CARD32
name|pickid
name|B32
decl_stmt|;
block|}
name|pexPickElementRef
typedef|;
end_typedef

begin_comment
comment|/* pexPickPath is the old name of the above strucutre.    This is wrong, since the above is a Pick Element Ref    a Pick Path is a list of Pick Element Refs so naming    this structure pexPickPath was wrong, but it can't just    be changed without effecting lots of other code....... */
end_comment

begin_typedef
typedef|typedef
name|pexPickElementRef
name|pexPickPath
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexTextVAlignment
name|vertical
name|B16
decl_stmt|;
name|pexTextHAlignment
name|horizontal
name|B16
decl_stmt|;
block|}
name|pexTextAlignmentData
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexSwitch
name|visibility
decl_stmt|;
name|CARD8
name|unused
decl_stmt|;
name|CARD16
name|order
name|B16
decl_stmt|;
name|pexCoordType
name|type
name|B16
decl_stmt|;
name|INT16
name|approxMethod
name|B16
decl_stmt|;
name|PEXFLOAT
name|tolerance
decl_stmt|;
name|PEXFLOAT
name|tMin
decl_stmt|;
name|PEXFLOAT
name|tMax
decl_stmt|;
name|CARD32
name|numKnots
name|B32
decl_stmt|;
name|CARD32
name|numCoord
name|B32
decl_stmt|;
comment|/* LISTof FLOAT(numKnots) -- length = order + number of coords */
comment|/* LISTof {pexCoord3D|pexCoord4D}(numCoord) */
block|}
name|pexTrimCurve
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|depth
decl_stmt|;
name|CARD8
name|unused
decl_stmt|;
name|CARD16
name|type
name|B16
decl_stmt|;
name|CARD32
name|visualID
name|B32
decl_stmt|;
block|}
name|pexRendererTarget
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexEnumTypeIndex
name|pickType
name|B16
decl_stmt|;
name|CARD16
name|unused
decl_stmt|;
comment|/* SINGLE HITBOX() */
block|}
name|pexPickRecord
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|PEXFLOAT
name|ambient
decl_stmt|;
name|PEXFLOAT
name|diffuse
decl_stmt|;
name|PEXFLOAT
name|specular
decl_stmt|;
name|PEXFLOAT
name|specularConc
decl_stmt|;
name|PEXFLOAT
name|transmission
decl_stmt|;
comment|/* 0.0 = opaque, 1.0 = transparent */
name|pexColorSpecifier
name|specularColor
decl_stmt|;
comment|/* SINGLE COLOR() */
block|}
name|pexReflectionAttr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexEnumTypeIndex
name|approxMethod
name|B16
decl_stmt|;
name|CARD16
name|unused
name|B16
decl_stmt|;
name|PEXFLOAT
name|uTolerance
decl_stmt|;
name|PEXFLOAT
name|vTolerance
decl_stmt|;
block|}
name|pexSurfaceApprox
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexCoord3D
name|point
decl_stmt|;
comment|/* SINGLE OPT_DATA() */
block|}
name|pexVertex
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexDeviceCoord
name|minval
decl_stmt|;
name|pexDeviceCoord
name|maxval
decl_stmt|;
name|pexSwitch
name|useDrawable
decl_stmt|;
name|BYTE
name|pad
index|[
literal|3
index|]
decl_stmt|;
block|}
name|pexViewport
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD16
name|clipFlags
name|B16
decl_stmt|;
name|CARD16
name|unused
name|B16
decl_stmt|;
name|pexNpcSubvolume
name|clipLimits
decl_stmt|;
name|pexMatrix
name|orientation
decl_stmt|;
name|pexMatrix
name|mapping
decl_stmt|;
block|}
name|pexViewEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexTableIndex
name|index
name|B16
decl_stmt|;
name|CARD16
name|unused
name|B16
decl_stmt|;
name|pexViewEntry
name|view
decl_stmt|;
block|}
name|pexViewRep
typedef|;
end_typedef

begin_comment
comment|/*  * typedefs for lookup tables  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD16
name|definableEntries
name|B16
decl_stmt|;
name|CARD16
name|numPredefined
name|B16
decl_stmt|;
name|CARD16
name|predefinedMin
name|B16
decl_stmt|;
name|CARD16
name|predefinedMax
name|B16
decl_stmt|;
block|}
name|pexTableInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexEnumTypeIndex
name|lineType
name|B16
decl_stmt|;
name|pexEnumTypeIndex
name|polylineInterp
name|B16
decl_stmt|;
name|pexCurveApprox
name|curveApprox
decl_stmt|;
name|PEXFLOAT
name|lineWidth
decl_stmt|;
name|pexColorSpecifier
name|lineColor
decl_stmt|;
comment|/* SINGLE COLOR() */
block|}
name|pexLineBundleEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexEnumTypeIndex
name|markerType
name|B16
decl_stmt|;
name|INT16
name|unused
name|B16
decl_stmt|;
name|PEXFLOAT
name|markerScale
decl_stmt|;
name|pexColorSpecifier
name|markerColor
decl_stmt|;
comment|/* SINGLE COLOR() */
block|}
name|pexMarkerBundleEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD16
name|textFontIndex
name|B16
decl_stmt|;
name|CARD16
name|textPrecision
name|B16
decl_stmt|;
name|PEXFLOAT
name|charExpansion
decl_stmt|;
name|PEXFLOAT
name|charSpacing
decl_stmt|;
name|pexColorSpecifier
name|textColor
decl_stmt|;
comment|/* SINGLE COLOR() */
block|}
name|pexTextBundleEntry
typedef|;
end_typedef

begin_comment
comment|/*     Note that since an InteriorBundleEntry contains 4 embedded instances of      pexColorSpecifier, a variable-sized item, a data structure cannot be     defined for it. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexEnumTypeIndex
name|interiorStyle
name|B16
decl_stmt|;
name|INT16
name|interiorStyleIndex
name|B16
decl_stmt|;
name|pexEnumTypeIndex
name|reflectionModel
name|B16
decl_stmt|;
name|pexEnumTypeIndex
name|surfaceInterp
name|B16
decl_stmt|;
name|pexEnumTypeIndex
name|bfInteriorStyle
name|B16
decl_stmt|;
name|INT16
name|bfInteriorStyleIndex
name|B16
decl_stmt|;
name|pexEnumTypeIndex
name|bfReflectionModel
name|B16
decl_stmt|;
name|pexEnumTypeIndex
name|bfSurfaceInterp
name|B16
decl_stmt|;
name|pexSurfaceApprox
name|surfaceApprox
decl_stmt|;
comment|/* SINGLE pexColorSpecifier		surfaceColor    */
comment|/* SINGLE pexReflectionAttr		reflectionAttr   */
comment|/* SINGLE pexColorSpecifier		bfSurfaceColor  */
comment|/* SINGLE pexReflectionAttr		bfReflectionAttr */
block|}
name|pexInteriorBundleEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexSwitch
name|edges
decl_stmt|;
name|CARD8
name|unused
decl_stmt|;
name|pexEnumTypeIndex
name|edgeType
name|B16
decl_stmt|;
name|PEXFLOAT
name|edgeWidth
decl_stmt|;
name|pexColorSpecifier
name|edgeColor
decl_stmt|;
comment|/* SINGLE COLOR() */
block|}
name|pexEdgeBundleEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexColorType
name|colorType
name|B16
decl_stmt|;
name|CARD16
name|numx
name|B16
decl_stmt|;
name|CARD16
name|numy
name|B16
decl_stmt|;
name|CARD16
name|unused
name|B16
decl_stmt|;
comment|/* LISTof Color(numx, numy) 2D array of colors */
block|}
name|pexPatternEntry
typedef|;
end_typedef

begin_comment
comment|/* a pexColorEntry is just a pexColorSpecifier */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD32
name|numFonts
name|B32
decl_stmt|;
comment|/* LISTof pexFont( numFonts ) */
block|}
name|pexTextFontEntry
typedef|;
end_typedef

begin_comment
comment|/* a pexViewEntry is defined above */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexEnumTypeIndex
name|lightType
name|B16
decl_stmt|;
name|INT16
name|unused
name|B16
decl_stmt|;
name|pexVector3D
name|direction
decl_stmt|;
name|pexCoord3D
name|point
decl_stmt|;
name|PEXFLOAT
name|concentration
decl_stmt|;
name|PEXFLOAT
name|spreadAngle
decl_stmt|;
name|PEXFLOAT
name|attenuation1
decl_stmt|;
name|PEXFLOAT
name|attenuation2
decl_stmt|;
name|pexColorSpecifier
name|lightColor
decl_stmt|;
comment|/* SINGLE COLOR() */
block|}
name|pexLightEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexSwitch
name|mode
decl_stmt|;
name|CARD8
name|unused
decl_stmt|;
name|CARD16
name|unused2
name|B16
decl_stmt|;
name|PEXFLOAT
name|frontPlane
decl_stmt|;
name|PEXFLOAT
name|backPlane
decl_stmt|;
name|PEXFLOAT
name|frontScaling
decl_stmt|;
name|PEXFLOAT
name|backScaling
decl_stmt|;
name|pexColorSpecifier
name|depthCueColor
decl_stmt|;
comment|/* SINGLE COLOR() */
block|}
name|pexDepthCueEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|INT16
name|approxType
decl_stmt|;
name|INT16
name|approxModel
decl_stmt|;
name|CARD16
name|max1
name|B16
decl_stmt|;
name|CARD16
name|max2
name|B16
decl_stmt|;
name|CARD16
name|max3
name|B16
decl_stmt|;
name|CARD8
name|dither
decl_stmt|;
name|CARD8
name|unused
decl_stmt|;
name|CARD32
name|mult1
name|B32
decl_stmt|;
name|CARD32
name|mult2
name|B32
decl_stmt|;
name|CARD32
name|mult3
name|B32
decl_stmt|;
name|PEXFLOAT
name|weight1
decl_stmt|;
name|PEXFLOAT
name|weight2
decl_stmt|;
name|PEXFLOAT
name|weight3
decl_stmt|;
name|CARD32
name|basePixel
name|B32
decl_stmt|;
block|}
name|pexColorApproxEntry
typedef|;
end_typedef

begin_comment
comment|/*  Font structures */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Atom
name|name
name|B32
decl_stmt|;
name|CARD32
name|value
name|B32
decl_stmt|;
block|}
name|pexFontProp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD32
name|firstGlyph
name|B32
decl_stmt|;
name|CARD32
name|lastGlyph
name|B32
decl_stmt|;
name|CARD32
name|defaultGlyph
name|B32
decl_stmt|;
name|pexSwitch
name|allExist
decl_stmt|;
name|pexSwitch
name|strokeFont
decl_stmt|;
name|CARD16
name|unused
name|B16
decl_stmt|;
name|CARD32
name|numProps
name|B32
decl_stmt|;
comment|/* LISTof pexFontProp(numProps) */
block|}
name|pexFontInfo
typedef|;
end_typedef

begin_comment
comment|/* Text Structures */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|INT16
name|characterSet
name|B16
decl_stmt|;
name|CARD8
name|characterSetWidth
decl_stmt|;
name|CARD8
name|encodingState
decl_stmt|;
name|CARD16
name|unused
name|B16
decl_stmt|;
name|CARD16
name|numChars
decl_stmt|;
comment|/* LISTof CHARACTER( numChars ) */
comment|/* pad */
block|}
name|pexMonoEncoding
typedef|;
end_typedef

begin_comment
comment|/* CHARACTER is either a CARD8, a CARD16, or a CARD32 */
end_comment

begin_comment
comment|/* Parametric Surface Characteristics types */
end_comment

begin_comment
comment|/* type 1 None */
end_comment

begin_comment
comment|/* type 2 Implementation Dependent */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD16
name|placementType
name|B16
decl_stmt|;
name|CARD16
name|unused
name|B16
decl_stmt|;
name|CARD16
name|numUcurves
name|B16
decl_stmt|;
name|CARD16
name|numVcurves
name|B16
decl_stmt|;
block|}
name|pexPSC_IsoparametricCurves
typedef|;
end_typedef

begin_comment
comment|/* type 3 */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexCoord3D
name|origin
decl_stmt|;
name|pexVector3D
name|direction
decl_stmt|;
name|CARD16
name|numberIntersections
name|B16
decl_stmt|;
name|CARD16
name|pad
name|B16
decl_stmt|;
comment|/* LISTof pexCoord3D( numIntersections ) */
block|}
name|pexPSC_LevelCurves
typedef|;
end_typedef

begin_comment
comment|/*  type 4: MC 					    type 5: WC */
end_comment

begin_comment
comment|/* Pick Device data records */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|pexDeviceCoord2D
name|position
decl_stmt|;
name|PEXFLOAT
name|distance
decl_stmt|;
block|}
name|pexPD_DC_HitBox
typedef|;
end_typedef

begin_comment
comment|/* pick device 1 */
end_comment

begin_typedef
typedef|typedef
name|pexNpcSubvolume
name|pexPD_NPC_HitVolume
typedef|;
end_typedef

begin_comment
comment|/* pick device 2 */
end_comment

begin_comment
comment|/* Output Command errors */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|type
decl_stmt|;
comment|/*  0 */
name|CARD8
name|errorCode
decl_stmt|;
comment|/* 14 */
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|resourceId
name|B32
decl_stmt|;
comment|/* renderer or structure */
name|CARD16
name|minorCode
name|B16
decl_stmt|;
name|CARD8
name|majorCode
decl_stmt|;
name|CARD8
name|unused
decl_stmt|;
name|CARD16
name|opcode
name|B16
decl_stmt|;
comment|/* opcode of failed output command */
name|CARD16
name|numCommands
name|B16
decl_stmt|;
comment|/* number successfully done before error */
name|BYTE
name|pad
index|[
literal|16
index|]
decl_stmt|;
block|}
name|pexOutputCommandError
typedef|;
end_typedef

begin_comment
comment|/* Registered PEX Escapes */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|INT16
name|fpFormat
name|B16
decl_stmt|;
name|CARD8
name|unused
index|[
literal|2
index|]
decl_stmt|;
name|CARD32
name|rdr
name|B32
decl_stmt|;
comment|/* renderer ID */
comment|/* SINGLE ColorSpecifier()  */
block|}
name|pexEscapeSetEchoColorData
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PEXPROTOSTR_H */
end_comment

end_unit

