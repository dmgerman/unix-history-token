begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: PEX.h,v 5.10 92/04/23 17:43:16 hersh Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1989, 1990, 1991 by Sun Microsystems, Inc. and the X Consortium.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Sun Microsystems, the X Consortium, and MIT not be used in advertising or publicity  pertaining to distribution of the software without specific, written  prior permission.    SUN MICROSYSTEMS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT  SHALL SUN MICROSYSTEMS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL  DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PEX_H
end_ifndef

begin_define
define|#
directive|define
name|PEX_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LOCAL_PEX_NAME
end_ifdef

begin_define
define|#
directive|define
name|PEX_NAME_STRING
value|LOCAL_PEX_NAME
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PEX_NAME_STRING
value|"X3D-PEX"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Matches revision 5.1C */
end_comment

begin_define
define|#
directive|define
name|PEX_PROTO_MAJOR
value|5
end_define

begin_comment
comment|/* current protocol version */
end_comment

begin_define
define|#
directive|define
name|PEX_PROTO_MINOR
value|1
end_define

begin_comment
comment|/* current minor version */
end_comment

begin_comment
comment|/* Events */
end_comment

begin_define
define|#
directive|define
name|PEXMaxHitsReached
value|0
end_define

begin_define
define|#
directive|define
name|PEXNumberEvents
value|1
end_define

begin_comment
comment|/* Subsets */
end_comment

begin_define
define|#
directive|define
name|PEXCompleteImplementation
value|0
end_define

begin_define
define|#
directive|define
name|PEXImmediateModeOnly
value|1
end_define

begin_define
define|#
directive|define
name|PEXPhigsWksOnly
value|2
end_define

begin_define
define|#
directive|define
name|PEXStructureModeOnly
value|4
end_define

begin_comment
comment|/* Resources */
end_comment

begin_define
define|#
directive|define
name|PEXAlreadyFreed
value|1
end_define

begin_comment
comment|/* Asf Attributes */
end_comment

begin_comment
comment|/* Masks for setting Asf's */
end_comment

begin_define
define|#
directive|define
name|PEXMarkerTypeAsf
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXMarkerScaleAsf
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXMarkerColourAsf
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|PEXTextFontIndexAsf
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|PEXTextPrecAsf
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|PEXCharExpansionAsf
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|PEXCharSpacingAsf
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|PEXTextColourAsf
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|PEXLineTypeAsf
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|PEXLineWidthAsf
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|PEXLineColourAsf
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|PEXCurveApproxAsf
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|PEXPolylineInterpAsf
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|PEXInteriorStyleAsf
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|PEXInteriorStyleIndexAsf
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|PEXSurfaceColourAsf
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|PEXSurfaceInterpAsf
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|PEXReflectionModelAsf
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|PEXReflectionAttrAsf
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|PEXBfInteriorStyleAsf
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|PEXBfInteriorStyleIndexAsf
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|PEXBfSurfaceColourAsf
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|PEXBfSurfaceInterpAsf
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|PEXBfReflectionModelAsf
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|PEXBfReflectionAttrAsf
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|PEXSurfaceApproxAsf
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|PEXSurfaceEdgesAsf
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|PEXSurfaceEdgeTypeAsf
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|PEXSurfaceEdgeWidthAsf
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|PEXSurfaceEdgeColourAsf
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|PEXMaxAsfShift
value|29
end_define

begin_comment
comment|/* Asf Values */
end_comment

begin_define
define|#
directive|define
name|PEXBundled
value|0
end_define

begin_define
define|#
directive|define
name|PEXIndividual
value|1
end_define

begin_comment
comment|/* Composition */
end_comment

begin_define
define|#
directive|define
name|PEXPreConcatenate
value|0
end_define

begin_define
define|#
directive|define
name|PEXPostConcatenate
value|1
end_define

begin_define
define|#
directive|define
name|PEXReplace
value|2
end_define

begin_comment
comment|/* Cull mode */
end_comment

begin_comment
comment|/* 0 None */
end_comment

begin_define
define|#
directive|define
name|PEXBackFaces
value|1
end_define

begin_define
define|#
directive|define
name|PEXFrontFaces
value|2
end_define

begin_comment
comment|/* Curve Type  and Surface Type */
end_comment

begin_define
define|#
directive|define
name|PEXRational
value|0
end_define

begin_define
define|#
directive|define
name|PEXNonRational
value|1
end_define

begin_comment
comment|/* Edit Mode */
end_comment

begin_define
define|#
directive|define
name|PEXStructureInsert
value|0
end_define

begin_define
define|#
directive|define
name|PEXStructureReplace
value|1
end_define

begin_comment
comment|/* Whence values */
end_comment

begin_define
define|#
directive|define
name|PEXBeginning
value|0
end_define

begin_define
define|#
directive|define
name|PEXCurrent
value|1
end_define

begin_define
define|#
directive|define
name|PEXEnd
value|2
end_define

begin_comment
comment|/* Match Draw Type */
end_comment

begin_define
define|#
directive|define
name|PEXDontCare
value|0
end_define

begin_define
define|#
directive|define
name|PEXWindow
value|1
end_define

begin_define
define|#
directive|define
name|PEXPixmap
value|2
end_define

begin_define
define|#
directive|define
name|PEXBuffer
value|3
end_define

begin_comment
comment|/* Pick All State */
end_comment

begin_define
define|#
directive|define
name|PEXMoreHits
value|0
end_define

begin_define
define|#
directive|define
name|PEXNoMoreHits
value|1
end_define

begin_define
define|#
directive|define
name|PEXMayBeMoreHits
value|2
end_define

begin_comment
comment|/* PickOne Methods */
end_comment

begin_define
define|#
directive|define
name|PEXLast
value|1
end_define

begin_define
define|#
directive|define
name|PEXClosestZ
value|2
end_define

begin_define
define|#
directive|define
name|PEXVisibleAny
value|3
end_define

begin_define
define|#
directive|define
name|PEXVisibleClosest
value|4
end_define

begin_comment
comment|/* PickAll Methods */
end_comment

begin_define
define|#
directive|define
name|PEXAllPicks
value|1
end_define

begin_define
define|#
directive|define
name|PEXVisible
value|2
end_define

begin_comment
comment|/* Element Search */
end_comment

begin_define
define|#
directive|define
name|PEXNotFound
value|1
end_define

begin_define
define|#
directive|define
name|PEXFound
value|2
end_define

begin_comment
comment|/* GetEnumeratedType return format */
end_comment

begin_define
define|#
directive|define
name|PEXETIndex
value|1
end_define

begin_define
define|#
directive|define
name|PEXETMnemonic
value|2
end_define

begin_define
define|#
directive|define
name|PEXETBoth
value|3
end_define

begin_comment
comment|/* Enum Types */
end_comment

begin_define
define|#
directive|define
name|PEXETMarkerType
value|1
end_define

begin_define
define|#
directive|define
name|PEXETATextStyle
value|2
end_define

begin_define
define|#
directive|define
name|PEXETInteriorStyle
value|3
end_define

begin_define
define|#
directive|define
name|PEXETHatchStyle
value|4
end_define

begin_define
define|#
directive|define
name|PEXETLineType
value|5
end_define

begin_define
define|#
directive|define
name|PEXETSurfaceEdgeType
value|6
end_define

begin_define
define|#
directive|define
name|PEXETPickDeviceType
value|7
end_define

begin_define
define|#
directive|define
name|PEXETPolylineInterpMethod
value|8
end_define

begin_define
define|#
directive|define
name|PEXETCurveApproxMethod
value|9
end_define

begin_define
define|#
directive|define
name|PEXETReflectionModel
value|10
end_define

begin_define
define|#
directive|define
name|PEXETSurfaceInterpMethod
value|11
end_define

begin_define
define|#
directive|define
name|PEXETSurfaceApproxMethod
value|12
end_define

begin_define
define|#
directive|define
name|PEXETModelClipOperator
value|13
end_define

begin_define
define|#
directive|define
name|PEXETLightType
value|14
end_define

begin_define
define|#
directive|define
name|PEXETColourType
value|15
end_define

begin_define
define|#
directive|define
name|PEXETFloatFormat
value|16
end_define

begin_define
define|#
directive|define
name|PEXETHlhsrMode
value|17
end_define

begin_define
define|#
directive|define
name|PEXETPromptEchoType
value|18
end_define

begin_define
define|#
directive|define
name|PEXETDisplayUpdateMode
value|19
end_define

begin_define
define|#
directive|define
name|PEXETColourApproxType
value|20
end_define

begin_define
define|#
directive|define
name|PEXETColourApproxModel
value|21
end_define

begin_define
define|#
directive|define
name|PEXETGDP
value|22
end_define

begin_define
define|#
directive|define
name|PEXETGDP3
value|23
end_define

begin_define
define|#
directive|define
name|PEXETGSE
value|24
end_define

begin_define
define|#
directive|define
name|PEXETTrimCurveApproxMethod
value|25
end_define

begin_define
define|#
directive|define
name|PEXETRenderingColourModel
value|26
end_define

begin_define
define|#
directive|define
name|PEXETParaSurfCharacteristics
value|27
end_define

begin_define
define|#
directive|define
name|PEXETEscape
value|28
end_define

begin_define
define|#
directive|define
name|PEXETPickOneMethod
value|29
end_define

begin_define
define|#
directive|define
name|PEXETPickAllMethod
value|30
end_define

begin_comment
comment|/* Renderer State */
end_comment

begin_define
define|#
directive|define
name|PEXIdle
value|0
end_define

begin_define
define|#
directive|define
name|PEXRendering
value|1
end_define

begin_define
define|#
directive|define
name|PEXPicking
value|2
end_define

begin_comment
comment|/* Flags (e.g., Switches, Visibility, and Edges) */
end_comment

begin_define
define|#
directive|define
name|PEXOff
value|0
end_define

begin_define
define|#
directive|define
name|PEXOn
value|1
end_define

begin_comment
comment|/* Shape hints */
end_comment

begin_comment
comment|/* Complex, Nonconvex, Convex, are defined  as 0, 1, 2 in X.h */
end_comment

begin_define
define|#
directive|define
name|PEXComplex
value|0
end_define

begin_define
define|#
directive|define
name|PEXNonconvex
value|1
end_define

begin_define
define|#
directive|define
name|PEXConvex
value|2
end_define

begin_define
define|#
directive|define
name|PEXUnknownShape
value|3
end_define

begin_comment
comment|/* Contour hints */
end_comment

begin_define
define|#
directive|define
name|PEXDisjoint
value|0
end_define

begin_define
define|#
directive|define
name|PEXNested
value|1
end_define

begin_define
define|#
directive|define
name|PEXIntersecting
value|2
end_define

begin_define
define|#
directive|define
name|PEXUnknownContour
value|3
end_define

begin_comment
comment|/* Table Type */
end_comment

begin_define
define|#
directive|define
name|PEXLineBundleLUT
value|1
end_define

begin_define
define|#
directive|define
name|PEXMarkerBundleLUT
value|2
end_define

begin_define
define|#
directive|define
name|PEXTextBundleLUT
value|3
end_define

begin_define
define|#
directive|define
name|PEXInteriorBundleLUT
value|4
end_define

begin_define
define|#
directive|define
name|PEXEdgeBundleLUT
value|5
end_define

begin_define
define|#
directive|define
name|PEXPatternLUT
value|6
end_define

begin_define
define|#
directive|define
name|PEXTextFontLUT
value|7
end_define

begin_define
define|#
directive|define
name|PEXColourLUT
value|8
end_define

begin_define
define|#
directive|define
name|PEXViewLUT
value|9
end_define

begin_define
define|#
directive|define
name|PEXLightLUT
value|10
end_define

begin_define
define|#
directive|define
name|PEXDepthCueLUT
value|11
end_define

begin_define
define|#
directive|define
name|PEXColourApproxLUT
value|12
end_define

begin_define
define|#
directive|define
name|PEXMaxTableType
value|12
end_define

begin_comment
comment|/* Status in GetTableEntry */
end_comment

begin_define
define|#
directive|define
name|PEXDefaultEntry
value|0
end_define

begin_define
define|#
directive|define
name|PEXDefinedEntry
value|1
end_define

begin_comment
comment|/* ValueType in GetTableEntr{y|ies} */
end_comment

begin_define
define|#
directive|define
name|PEXSetValue
value|0
end_define

begin_define
define|#
directive|define
name|PEXRealizedValue
value|1
end_define

begin_comment
comment|/* Constants for Path and Vertical and Horizontal alignment */
end_comment

begin_define
define|#
directive|define
name|PEXPathRight
value|0
end_define

begin_define
define|#
directive|define
name|PEXPathLeft
value|1
end_define

begin_define
define|#
directive|define
name|PEXPathUp
value|2
end_define

begin_define
define|#
directive|define
name|PEXPathDown
value|3
end_define

begin_define
define|#
directive|define
name|PEXValignNormal
value|0
end_define

begin_define
define|#
directive|define
name|PEXValignTop
value|1
end_define

begin_define
define|#
directive|define
name|PEXValignCap
value|2
end_define

begin_define
define|#
directive|define
name|PEXValignHalf
value|3
end_define

begin_define
define|#
directive|define
name|PEXValignBase
value|4
end_define

begin_define
define|#
directive|define
name|PEXValignBottom
value|5
end_define

begin_define
define|#
directive|define
name|PEXHalignNormal
value|0
end_define

begin_define
define|#
directive|define
name|PEXHalignLeft
value|1
end_define

begin_define
define|#
directive|define
name|PEXHalignCenter
value|2
end_define

begin_define
define|#
directive|define
name|PEXHalignRight
value|3
end_define

begin_comment
comment|/* Text precision */
end_comment

begin_define
define|#
directive|define
name|PEXStringPrecision
value|0
end_define

begin_define
define|#
directive|define
name|PEXCharPrecision
value|1
end_define

begin_define
define|#
directive|define
name|PEXStrokePrecision
value|2
end_define

begin_comment
comment|/* Character Set Widths */
end_comment

begin_define
define|#
directive|define
name|PEXCSByte
value|0
end_define

begin_define
define|#
directive|define
name|PEXCSShort
value|1
end_define

begin_define
define|#
directive|define
name|PEXCSLong
value|2
end_define

begin_comment
comment|/* Update State */
end_comment

begin_define
define|#
directive|define
name|PEXNotPending
value|0
end_define

begin_define
define|#
directive|define
name|PEXPending
value|1
end_define

begin_comment
comment|/* Visual State */
end_comment

begin_define
define|#
directive|define
name|PEXCorrect
value|0
end_define

begin_define
define|#
directive|define
name|PEXDeferred
value|1
end_define

begin_define
define|#
directive|define
name|PEXSimulated
value|2
end_define

begin_comment
comment|/* Display State */
end_comment

begin_define
define|#
directive|define
name|PEXEmpty
value|0
end_define

begin_define
define|#
directive|define
name|PEXNotEmpty
value|1
end_define

begin_comment
comment|/* Buffer Mode */
end_comment

begin_define
define|#
directive|define
name|PEXSingleBuffered
value|0
end_define

begin_define
define|#
directive|define
name|PEXDoubleBuffered
value|1
end_define

begin_comment
comment|/* Dynamic types */
end_comment

begin_define
define|#
directive|define
name|PEXIMM
value|0
end_define

begin_define
define|#
directive|define
name|PEXIRG
value|1
end_define

begin_define
define|#
directive|define
name|PEXCBS
value|2
end_define

begin_comment
comment|/* Geometric attributes (Vertex, Facet) */
end_comment

begin_define
define|#
directive|define
name|PEXGAColour
value|0x0001
end_define

begin_define
define|#
directive|define
name|PEXGANormal
value|0x0002
end_define

begin_define
define|#
directive|define
name|PEXGAEdges
value|0x0004
end_define

begin_comment
comment|/* Pick Status */
end_comment

begin_define
define|#
directive|define
name|PEXNoPick
value|0
end_define

begin_define
define|#
directive|define
name|PEXOk
value|1
end_define

begin_define
define|#
directive|define
name|PEXAborted
value|2
end_define

begin_comment
comment|/* Pick Echo Switch */
end_comment

begin_define
define|#
directive|define
name|PEXNoEcho
value|0
end_define

begin_define
define|#
directive|define
name|PEXEcho
value|1
end_define

begin_define
define|#
directive|define
name|PEXUnEcho
value|2
end_define

begin_comment
comment|/* Pick Path Order */
end_comment

begin_define
define|#
directive|define
name|PEXTopFirst
value|0
end_define

begin_define
define|#
directive|define
name|PEXBottomFirst
value|1
end_define

begin_comment
comment|/* Items for GetStructureInfo */
end_comment

begin_define
define|#
directive|define
name|PEXElementPtr
value|0x0001
end_define

begin_define
define|#
directive|define
name|PEXNumElements
value|0x0002
end_define

begin_define
define|#
directive|define
name|PEXLengthStructure
value|0x0004
end_define

begin_define
define|#
directive|define
name|PEXHasRefs
value|0x0008
end_define

begin_define
define|#
directive|define
name|PEXEditMode
value|0x0010
end_define

begin_comment
comment|/* Flags for GetStructuresInNetwork */
end_comment

begin_define
define|#
directive|define
name|PEXAll
value|0
end_define

begin_define
define|#
directive|define
name|PEXOrphans
value|1
end_define

begin_comment
comment|/* Path part for GetAncestors */
end_comment

begin_define
define|#
directive|define
name|PEXTopPart
value|0
end_define

begin_define
define|#
directive|define
name|PEXBottomPart
value|1
end_define

begin_comment
comment|/* Direction for ElementSearch */
end_comment

begin_define
define|#
directive|define
name|PEXForward
value|0
end_define

begin_define
define|#
directive|define
name|PEXBackward
value|1
end_define

begin_comment
comment|/* Nameset changes */
end_comment

begin_define
define|#
directive|define
name|PEXNSAdd
value|0
end_define

begin_define
define|#
directive|define
name|PEXNSRemove
value|1
end_define

begin_define
define|#
directive|define
name|PEXNSReplace
value|2
end_define

begin_comment
comment|/* Priorities */
end_comment

begin_define
define|#
directive|define
name|PEXHigher
value|0
end_define

begin_define
define|#
directive|define
name|PEXLower
value|1
end_define

begin_comment
comment|/* Enumerated Type Descriptors */
end_comment

begin_comment
comment|/* Marker Type */
end_comment

begin_define
define|#
directive|define
name|PEXMarkerDot
value|1
end_define

begin_define
define|#
directive|define
name|PEXMarkerCross
value|2
end_define

begin_define
define|#
directive|define
name|PEXMarkerAsterisk
value|3
end_define

begin_define
define|#
directive|define
name|PEXMarkerCircle
value|4
end_define

begin_define
define|#
directive|define
name|PEXMarkerX
value|5
end_define

begin_comment
comment|/* ATextStyle */
end_comment

begin_define
define|#
directive|define
name|PEXATextNotConnected
value|1
end_define

begin_define
define|#
directive|define
name|PEXATextConnected
value|2
end_define

begin_comment
comment|/* InteriorStyle */
end_comment

begin_define
define|#
directive|define
name|PEXInteriorStyleHollow
value|1
end_define

begin_define
define|#
directive|define
name|PEXInteriorStyleSolid
value|2
end_define

begin_define
define|#
directive|define
name|PEXInteriorStylePattern
value|3
end_define

begin_define
define|#
directive|define
name|PEXInteriorStyleHatch
value|4
end_define

begin_define
define|#
directive|define
name|PEXInteriorStyleEmpty
value|5
end_define

begin_comment
comment|/* HatchStyle */
end_comment

begin_comment
comment|/* LineType */
end_comment

begin_define
define|#
directive|define
name|PEXLineTypeSolid
value|1
end_define

begin_define
define|#
directive|define
name|PEXLineTypeDashed
value|2
end_define

begin_define
define|#
directive|define
name|PEXLineTypeDotted
value|3
end_define

begin_define
define|#
directive|define
name|PEXLineTypeDashDot
value|4
end_define

begin_comment
comment|/* SurfaceEdgeType */
end_comment

begin_define
define|#
directive|define
name|PEXSurfaceEdgeSolid
value|1
end_define

begin_define
define|#
directive|define
name|PEXSurfaceEdgeDashed
value|2
end_define

begin_define
define|#
directive|define
name|PEXSurfaceEdgeDotted
value|3
end_define

begin_define
define|#
directive|define
name|PEXSurfaceEdgeDashDot
value|4
end_define

begin_comment
comment|/* PickDeviceType */
end_comment

begin_define
define|#
directive|define
name|PEXPickDeviceDC_HitBox
value|1
end_define

begin_define
define|#
directive|define
name|PEXPickDeviceNPC_HitVolume
value|2
end_define

begin_comment
comment|/* PolylineInterpMethod */
end_comment

begin_define
define|#
directive|define
name|PEXPolylineInterpNone
value|1
end_define

begin_define
define|#
directive|define
name|PEXPolylineInterpColour
value|2
end_define

begin_comment
comment|/* Curve(and Surface)(and Trim Curve)ApproxMethods */
end_comment

begin_define
define|#
directive|define
name|PEXApproxImpDep
value|1
end_define

begin_define
define|#
directive|define
name|PEXApproxConstantBetweenKnots
value|2
end_define

begin_define
define|#
directive|define
name|PEXApproxWcsChordalSize
value|3
end_define

begin_define
define|#
directive|define
name|PEXApproxNpcChordalSize
value|4
end_define

begin_define
define|#
directive|define
name|PEXApproxDcChordalSize
value|5
end_define

begin_define
define|#
directive|define
name|PEXCurveApproxWcsChordalDev
value|6
end_define

begin_define
define|#
directive|define
name|PEXCurveApproxNpcChordalDev
value|7
end_define

begin_define
define|#
directive|define
name|PEXCurveApproxDcChordalDev
value|8
end_define

begin_define
define|#
directive|define
name|PEXSurfaceApproxWcsPlanarDev
value|6
end_define

begin_define
define|#
directive|define
name|PEXSurfaceApproxNpcPlanarDev
value|7
end_define

begin_define
define|#
directive|define
name|PEXSurfaceApproxDcPlanarDev
value|8
end_define

begin_define
define|#
directive|define
name|PEXApproxWcsRelative
value|9
end_define

begin_define
define|#
directive|define
name|PEXApproxNpcRelative
value|10
end_define

begin_define
define|#
directive|define
name|PEXApproxDcRelative
value|11
end_define

begin_comment
comment|/* ReflectionModel */
end_comment

begin_define
define|#
directive|define
name|PEXReflectionNoShading
value|1
end_define

begin_define
define|#
directive|define
name|PEXReflectionAmbient
value|2
end_define

begin_define
define|#
directive|define
name|PEXReflectionDiffuse
value|3
end_define

begin_define
define|#
directive|define
name|PEXReflectionSpecular
value|4
end_define

begin_comment
comment|/* SurfaceInterpMethod */
end_comment

begin_define
define|#
directive|define
name|PEXSurfaceInterpNone
value|1
end_define

begin_define
define|#
directive|define
name|PEXSurfaceInterpColour
value|2
end_define

begin_define
define|#
directive|define
name|PEXSurfaceInterpDotProduct
value|3
end_define

begin_define
define|#
directive|define
name|PEXSurfaceInterpNormal
value|4
end_define

begin_comment
comment|/* ModelClipOperator */
end_comment

begin_define
define|#
directive|define
name|PEXModelClipReplace
value|1
end_define

begin_define
define|#
directive|define
name|PEXModelClipIntersection
value|2
end_define

begin_comment
comment|/* LightType */
end_comment

begin_define
define|#
directive|define
name|PEXLightAmbient
value|1
end_define

begin_define
define|#
directive|define
name|PEXLightWcsVector
value|2
end_define

begin_define
define|#
directive|define
name|PEXLightWcsPoint
value|3
end_define

begin_define
define|#
directive|define
name|PEXLightWcsSpot
value|4
end_define

begin_comment
comment|/* ColourType */
end_comment

begin_define
define|#
directive|define
name|PEXIndexedColour
value|0
end_define

begin_define
define|#
directive|define
name|PEXRgbFloatColour
value|1
end_define

begin_define
define|#
directive|define
name|PEXCieFloatColour
value|2
end_define

begin_define
define|#
directive|define
name|PEXHsvFloatColour
value|3
end_define

begin_define
define|#
directive|define
name|PEXHlsFloatColour
value|4
end_define

begin_define
define|#
directive|define
name|PEXRgb8Colour
value|5
end_define

begin_define
define|#
directive|define
name|PEXRgb16Colour
value|6
end_define

begin_define
define|#
directive|define
name|PEXMaxColour
value|6
end_define

begin_comment
comment|/* FloatFormat */
end_comment

begin_define
define|#
directive|define
name|PEXIeee_754_32
value|1
end_define

begin_define
define|#
directive|define
name|PEXDEC_F_Floating
value|2
end_define

begin_define
define|#
directive|define
name|PEXIeee_754_64
value|3
end_define

begin_define
define|#
directive|define
name|PEXDEC_D_Floating
value|4
end_define

begin_comment
comment|/* HlhsrMode */
end_comment

begin_define
define|#
directive|define
name|PEXHlhsrOff
value|1
end_define

begin_define
define|#
directive|define
name|PEXHlhsrZBuffer
value|2
end_define

begin_define
define|#
directive|define
name|PEXHlhsrPainters
value|3
end_define

begin_define
define|#
directive|define
name|PEXHlhsrScanline
value|4
end_define

begin_define
define|#
directive|define
name|PEXHlhsrHiddenLineOnly
value|5
end_define

begin_define
define|#
directive|define
name|PEXHlhsrZBufferId
value|6
end_define

begin_comment
comment|/* PromptEchoType */
end_comment

begin_define
define|#
directive|define
name|PEXEchoPrimitive
value|1
end_define

begin_define
define|#
directive|define
name|PEXEchoStructure
value|2
end_define

begin_define
define|#
directive|define
name|PEXEchoNetwork
value|3
end_define

begin_comment
comment|/* DisplayUpdateMethod */
end_comment

begin_define
define|#
directive|define
name|PEXVisualizeEach
value|1
end_define

begin_define
define|#
directive|define
name|PEXVisualizeEasy
value|2
end_define

begin_define
define|#
directive|define
name|PEXVisualizeNone
value|3
end_define

begin_define
define|#
directive|define
name|PEXSimulateSome
value|4
end_define

begin_define
define|#
directive|define
name|PEXVisualizeWhenever
value|5
end_define

begin_comment
comment|/* ColourApproxType */
end_comment

begin_define
define|#
directive|define
name|PEXColourSpace
value|1
end_define

begin_define
define|#
directive|define
name|PEXColourRange
value|2
end_define

begin_comment
comment|/* ColourApproxMethod */
end_comment

begin_define
define|#
directive|define
name|PEXColourApproxRGB
value|1
end_define

begin_define
define|#
directive|define
name|PEXColourApproxCIE
value|2
end_define

begin_define
define|#
directive|define
name|PEXColourApproxHSV
value|3
end_define

begin_define
define|#
directive|define
name|PEXColourApproxHLS
value|4
end_define

begin_define
define|#
directive|define
name|PEXColourApproxYIQ
value|5
end_define

begin_comment
comment|/* Escape */
end_comment

begin_define
define|#
directive|define
name|PEXEscapeSetEchoColour
value|1
end_define

begin_comment
comment|/* RenderingColourModel	*/
end_comment

begin_define
define|#
directive|define
name|PEXRdrColourModelImpDep
value|0
end_define

begin_define
define|#
directive|define
name|PEXRdrColourModelRGB
value|1
end_define

begin_define
define|#
directive|define
name|PEXRdrColourModelCIE
value|2
end_define

begin_define
define|#
directive|define
name|PEXRdrColourModelHSV
value|3
end_define

begin_define
define|#
directive|define
name|PEXRdrColourModelHLS
value|4
end_define

begin_comment
comment|/* ParametricSurfaceCharacteristics */
end_comment

begin_define
define|#
directive|define
name|PEXPSCNone
value|1
end_define

begin_define
define|#
directive|define
name|PEXPSCImpDep
value|2
end_define

begin_define
define|#
directive|define
name|PEXPSCIsoCurves
value|3
end_define

begin_define
define|#
directive|define
name|PEXPSCMcLevelCurves
value|4
end_define

begin_define
define|#
directive|define
name|PEXPSCWcLevelCurves
value|5
end_define

begin_comment
comment|/* Isoparametric Curves */
end_comment

begin_define
define|#
directive|define
name|PEXICUniformPlacement
value|0
end_define

begin_define
define|#
directive|define
name|PEXICNonuniformPlacement
value|1
end_define

begin_comment
comment|/* Clipping */
end_comment

begin_define
define|#
directive|define
name|PEXClipXY
value|0x0001
end_define

begin_define
define|#
directive|define
name|PEXClipBack
value|0x0002
end_define

begin_define
define|#
directive|define
name|PEXClipFront
value|0x0004
end_define

begin_define
define|#
directive|define
name|PEXClip
value|0
end_define

begin_define
define|#
directive|define
name|PEXNoClip
value|1
end_define

begin_comment
comment|/* Implementation Dependent Constant Names */
end_comment

begin_define
define|#
directive|define
name|PEXIDDitheringSupported
value|1
end_define

begin_define
define|#
directive|define
name|PEXIDMaxEdgeWidth
value|2
end_define

begin_define
define|#
directive|define
name|PEXIDMaxLineWidth
value|3
end_define

begin_define
define|#
directive|define
name|PEXIDMaxMarkerSize
value|4
end_define

begin_define
define|#
directive|define
name|PEXIDMaxModelClipPlanes
value|5
end_define

begin_define
define|#
directive|define
name|PEXIDMaxNameSetNames
value|6
end_define

begin_define
define|#
directive|define
name|PEXIDMaxNonAmbientLights
value|7
end_define

begin_define
define|#
directive|define
name|PEXIDMaxNURBOrder
value|8
end_define

begin_define
define|#
directive|define
name|PEXIDMaxTrimCurveOrder
value|9
end_define

begin_define
define|#
directive|define
name|PEXIDMinEdgeWidth
value|10
end_define

begin_define
define|#
directive|define
name|PEXIDMinLineWidth
value|11
end_define

begin_define
define|#
directive|define
name|PEXIDMinMarkerSize
value|12
end_define

begin_define
define|#
directive|define
name|PEXIDNominalEdgeWidth
value|13
end_define

begin_define
define|#
directive|define
name|PEXIDNominalLineWidth
value|14
end_define

begin_define
define|#
directive|define
name|PEXIDNominalMarkerSize
value|15
end_define

begin_define
define|#
directive|define
name|PEXIDNumSupportedEdgeWidths
value|16
end_define

begin_define
define|#
directive|define
name|PEXIDNumSupportedLineWidths
value|17
end_define

begin_define
define|#
directive|define
name|PEXIDNumSupportedMarkerSizes
value|18
end_define

begin_define
define|#
directive|define
name|PEXIDBestColourApproximation
value|19
end_define

begin_define
define|#
directive|define
name|PEXIDTransparencySupported
value|20
end_define

begin_define
define|#
directive|define
name|PEXIDDoubleBufferingSupported
value|21
end_define

begin_define
define|#
directive|define
name|PEXIDChromaticityRedU
value|22
end_define

begin_define
define|#
directive|define
name|PEXIDChromaticityRedV
value|23
end_define

begin_define
define|#
directive|define
name|PEXIDLuminanceRed
value|24
end_define

begin_define
define|#
directive|define
name|PEXIDChromaticityGreenU
value|25
end_define

begin_define
define|#
directive|define
name|PEXIDChromaticityGreenV
value|26
end_define

begin_define
define|#
directive|define
name|PEXIDLuminanceGreen
value|27
end_define

begin_define
define|#
directive|define
name|PEXIDChromaticityBlueU
value|28
end_define

begin_define
define|#
directive|define
name|PEXIDChromaticityBlueV
value|29
end_define

begin_define
define|#
directive|define
name|PEXIDLuminanceBlue
value|30
end_define

begin_define
define|#
directive|define
name|PEXIDChromaticityWhiteU
value|31
end_define

begin_define
define|#
directive|define
name|PEXIDChromaticityWhiteV
value|32
end_define

begin_define
define|#
directive|define
name|PEXIDLuminanceWhite
value|33
end_define

begin_comment
comment|/* have to stick this here since others are not in order */
end_comment

begin_define
define|#
directive|define
name|PEXIDMaxHitsEventSupported
value|34
end_define

begin_comment
comment|/* Constants for IDRgbBestApproximation */
end_comment

begin_define
define|#
directive|define
name|PEXColourApproxAnyValues
value|0
end_define

begin_define
define|#
directive|define
name|PEXColourApproxPowersOf2
value|1
end_define

begin_comment
comment|/** To convert a bit index to a mask number and a mask value, assuming  ** 32 bit wide words.  For example, a bitIndex of 5 will return   ** maskNum == 0 and maskValue == (1<< 5) = 32, while a bitIndex of 39  ** will return maskNum == 1 and maskValue == (1<< 7) == 128   **/
end_comment

begin_define
define|#
directive|define
name|PEX_BITNUM_TO_BITMASK
parameter_list|(
name|bitIndex
parameter_list|,
name|maskNum
parameter_list|,
name|maskValue
parameter_list|)
define|\
value|maskNum	= (bitIndex) / 32; \     maskValue	= ((unsigned)1L<< ((bitIndex) % 32));
end_define

begin_define
define|#
directive|define
name|CHECK_BITMASK_ARRAY
parameter_list|(
name|mask
parameter_list|,
name|bitIndex
parameter_list|)
define|\
value|if (mask[((bitIndex)/32)]& ((unsigned)1L<< ((bitIndex) % 32)))
end_define

begin_define
define|#
directive|define
name|PEX_BITMASK
parameter_list|(
name|i
parameter_list|)
value|((unsigned)1<< ((i)& 31))
end_define

begin_define
define|#
directive|define
name|PEX_MASKIDX
parameter_list|(
name|i
parameter_list|)
value|((i)>> 5)
end_define

begin_define
define|#
directive|define
name|PEX_MASKWORD
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|buf[PEX_MASKIDX(i)]
end_define

begin_define
define|#
directive|define
name|PEX_BITSET
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|PEX_MASKWORD(buf, i) |= PEX_BITMASK(i)
end_define

begin_define
define|#
directive|define
name|PEX_BITCLEAR
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|PEX_MASKWORD(buf, i)&= ~PEX_BITMASK(i)
end_define

begin_define
define|#
directive|define
name|PEX_GETBIT
parameter_list|(
name|buf
parameter_list|,
name|i
parameter_list|)
value|(PEX_MASKWORD(buf, i)& PEX_BITMASK(i))
end_define

begin_define
define|#
directive|define
name|PEXMSGetWksInfo
value|2
end_define

begin_define
define|#
directive|define
name|PEXMSPipeline
value|3
end_define

begin_comment
comment|/* Pipeline Context */
end_comment

begin_define
define|#
directive|define
name|PEXPCMarkerType
value|0
end_define

begin_define
define|#
directive|define
name|PEXPCMarkerScale
value|1
end_define

begin_define
define|#
directive|define
name|PEXPCMarkerColour
value|2
end_define

begin_define
define|#
directive|define
name|PEXPCMarkerBundleIndex
value|3
end_define

begin_define
define|#
directive|define
name|PEXPCTextFont
value|4
end_define

begin_define
define|#
directive|define
name|PEXPCTextPrecision
value|5
end_define

begin_define
define|#
directive|define
name|PEXPCCharExpansion
value|6
end_define

begin_define
define|#
directive|define
name|PEXPCCharSpacing
value|7
end_define

begin_define
define|#
directive|define
name|PEXPCTextColour
value|8
end_define

begin_define
define|#
directive|define
name|PEXPCCharHeight
value|9
end_define

begin_define
define|#
directive|define
name|PEXPCCharUpVector
value|10
end_define

begin_define
define|#
directive|define
name|PEXPCTextPath
value|11
end_define

begin_define
define|#
directive|define
name|PEXPCTextAlignment
value|12
end_define

begin_define
define|#
directive|define
name|PEXPCAtextHeight
value|13
end_define

begin_define
define|#
directive|define
name|PEXPCAtextUpVector
value|14
end_define

begin_define
define|#
directive|define
name|PEXPCAtextPath
value|15
end_define

begin_define
define|#
directive|define
name|PEXPCAtextAlignment
value|16
end_define

begin_define
define|#
directive|define
name|PEXPCAtextStyle
value|17
end_define

begin_define
define|#
directive|define
name|PEXPCTextBundleIndex
value|18
end_define

begin_define
define|#
directive|define
name|PEXPCLineType
value|19
end_define

begin_define
define|#
directive|define
name|PEXPCLineWidth
value|20
end_define

begin_define
define|#
directive|define
name|PEXPCLineColour
value|21
end_define

begin_define
define|#
directive|define
name|PEXPCCurveApproximation
value|22
end_define

begin_define
define|#
directive|define
name|PEXPCPolylineInterp
value|23
end_define

begin_define
define|#
directive|define
name|PEXPCLineBundleIndex
value|24
end_define

begin_define
define|#
directive|define
name|PEXPCInteriorStyle
value|25
end_define

begin_define
define|#
directive|define
name|PEXPCInteriorStyleIndex
value|26
end_define

begin_define
define|#
directive|define
name|PEXPCSurfaceColour
value|27
end_define

begin_define
define|#
directive|define
name|PEXPCSurfaceReflAttr
value|28
end_define

begin_define
define|#
directive|define
name|PEXPCSurfaceReflModel
value|29
end_define

begin_define
define|#
directive|define
name|PEXPCSurfaceInterp
value|30
end_define

begin_define
define|#
directive|define
name|PEXPCBfInteriorStyle
value|31
end_define

begin_define
define|#
directive|define
name|PEXPCBfInteriorStyleIndex
value|32
end_define

begin_define
define|#
directive|define
name|PEXPCBfSurfaceColour
value|33
end_define

begin_define
define|#
directive|define
name|PEXPCBfSurfaceReflAttr
value|34
end_define

begin_define
define|#
directive|define
name|PEXPCBfSurfaceReflModel
value|35
end_define

begin_define
define|#
directive|define
name|PEXPCBfSurfaceInterp
value|36
end_define

begin_define
define|#
directive|define
name|PEXPCSurfaceApproximation
value|37
end_define

begin_define
define|#
directive|define
name|PEXPCCullingMode
value|38
end_define

begin_define
define|#
directive|define
name|PEXPCDistinguishFlag
value|39
end_define

begin_define
define|#
directive|define
name|PEXPCPatternSize
value|40
end_define

begin_define
define|#
directive|define
name|PEXPCPatternRefPt
value|41
end_define

begin_define
define|#
directive|define
name|PEXPCPatternRefVec1
value|42
end_define

begin_define
define|#
directive|define
name|PEXPCPatternRefVec2
value|43
end_define

begin_define
define|#
directive|define
name|PEXPCInteriorBundleIndex
value|44
end_define

begin_define
define|#
directive|define
name|PEXPCSurfaceEdgeFlag
value|45
end_define

begin_define
define|#
directive|define
name|PEXPCSurfaceEdgeType
value|46
end_define

begin_define
define|#
directive|define
name|PEXPCSurfaceEdgeWidth
value|47
end_define

begin_define
define|#
directive|define
name|PEXPCSurfaceEdgeColour
value|48
end_define

begin_define
define|#
directive|define
name|PEXPCEdgeBundleIndex
value|49
end_define

begin_define
define|#
directive|define
name|PEXPCLocalTransform
value|50
end_define

begin_define
define|#
directive|define
name|PEXPCGlobalTransform
value|51
end_define

begin_define
define|#
directive|define
name|PEXPCModelClip
value|52
end_define

begin_define
define|#
directive|define
name|PEXPCModelClipVolume
value|53
end_define

begin_define
define|#
directive|define
name|PEXPCViewIndex
value|54
end_define

begin_define
define|#
directive|define
name|PEXPCLightState
value|55
end_define

begin_define
define|#
directive|define
name|PEXPCDepthCueIndex
value|56
end_define

begin_define
define|#
directive|define
name|PEXPCSetAsfValues
value|57
end_define

begin_define
define|#
directive|define
name|PEXPCPickId
value|58
end_define

begin_define
define|#
directive|define
name|PEXPCHlhsrIdentifier
value|59
end_define

begin_define
define|#
directive|define
name|PEXPCNameSet
value|60
end_define

begin_define
define|#
directive|define
name|PEXPCColourApproxIndex
value|61
end_define

begin_define
define|#
directive|define
name|PEXPCRenderingColourModel
value|62
end_define

begin_define
define|#
directive|define
name|PEXPCParaSurfCharacteristics
value|63
end_define

begin_define
define|#
directive|define
name|PEXMaxPCIndex
value|63
end_define

begin_comment
comment|/* Renderer Bitmasks */
end_comment

begin_define
define|#
directive|define
name|PEXRDPipelineContext
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXRDCurrentPath
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXRDMarkerBundle
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|PEXRDTextBundle
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|PEXRDLineBundle
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|PEXRDInteriorBundle
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|PEXRDEdgeBundle
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|PEXRDViewTable
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|PEXRDColourTable
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|PEXRDDepthCueTable
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|PEXRDLightTable
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|PEXRDColourApproxTable
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|PEXRDPatternTable
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|PEXRDTextFontTable
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|PEXRDHighlightIncl
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|PEXRDHighlightExcl
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|PEXRDInvisibilityIncl
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|PEXRDInvisibilityExcl
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|PEXRDRendererState
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|PEXRDHlhsrMode
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|PEXRDNpcSubvolume
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|PEXRDViewport
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|PEXRDClipList
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|PEXRDPickInclusion
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|PEXRDPickExclusion
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|PEXRDPickStartPath
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|PEXRDBackgroundColour
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|PEXRDClearI
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|PEXRDClearZ
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|PEXRDEchoMode
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|PEXMaxRDShift
value|29
end_define

begin_comment
comment|/* Renderer Dynamics Bitmasks */
end_comment

begin_comment
comment|/*	tables		      */
end_comment

begin_define
define|#
directive|define
name|PEXDynMarkerBundle
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXDynTextBundle
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXDynLineBundle
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|PEXDynInteriorBundle
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|PEXDynEdgeBundle
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|PEXDynViewTable
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|PEXDynColourTable
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|PEXDynDepthCueTable
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|PEXDynLightTable
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|PEXDynColourApproxTable
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|PEXDynPatternTable
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|PEXDynTextFontTable
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|PEXDynMarkerBundleContents
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|PEXDynTextBundleContents
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|PEXDynLineBundleContents
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|PEXDynInteriorBundleContents
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|PEXDynEdgeBundleContents
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|PEXDynViewTableContents
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|PEXDynColourTableContents
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|PEXDynDepthCueTableContents
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|PEXDynLightTableContents
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|PEXDynColourApproxContents
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|PEXDynPatternTableContents
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|PEXDynTextFontTableContents
value|(1L<<27)
end_define

begin_comment
comment|/*	namesets	      */
end_comment

begin_define
define|#
directive|define
name|PEXDynHighlightNameset
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXDynInvisibilityNameset
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXDynPickNameset
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|PEXDynHighlightNamesetContents
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|PEXDynInvisibilityNamesetContents
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|PEXDynPickNamesetContents
value|(1L<<18)
end_define

begin_comment
comment|/*	attributes	      */
end_comment

begin_define
define|#
directive|define
name|PEXDynHlhsrMode
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXDynNpcSubvolume
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXDynViewport
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|PEXDynClipList
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|PEXDynEchoMode
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|PEXElementType
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXElementSize
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXElementData
value|(1L<<2)
end_define

begin_comment
comment|/* Search Context Bitmasks */
end_comment

begin_define
define|#
directive|define
name|PEXSCPosition
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXSCDistance
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXSCCeiling
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|PEXSCModelClipFlag
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|PEXSCStartPath
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|PEXSCNormalList
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|PEXSCInvertedList
value|(1L<<6)
end_define

begin_comment
comment|/* Phigs Workstation Attribute Bitmasks */
end_comment

begin_define
define|#
directive|define
name|PEXPWDisplayUpdate
value|0
end_define

begin_define
define|#
directive|define
name|PEXPWVisualState
value|1
end_define

begin_define
define|#
directive|define
name|PEXPWDisplaySurface
value|2
end_define

begin_define
define|#
directive|define
name|PEXPWViewUpdate
value|3
end_define

begin_define
define|#
directive|define
name|PEXPWDefinedViews
value|4
end_define

begin_define
define|#
directive|define
name|PEXPWWksUpdate
value|5
end_define

begin_define
define|#
directive|define
name|PEXPWReqNpcSubvolume
value|6
end_define

begin_define
define|#
directive|define
name|PEXPWCurNpcSubvolume
value|7
end_define

begin_define
define|#
directive|define
name|PEXPWReqWksViewport
value|8
end_define

begin_define
define|#
directive|define
name|PEXPWCurWksViewport
value|9
end_define

begin_define
define|#
directive|define
name|PEXPWHlhsrUpdate
value|10
end_define

begin_define
define|#
directive|define
name|PEXPWReqHlhsrMode
value|11
end_define

begin_define
define|#
directive|define
name|PEXPWCurHlhsrMode
value|12
end_define

begin_define
define|#
directive|define
name|PEXPWDrawable
value|13
end_define

begin_define
define|#
directive|define
name|PEXPWMarkerBundle
value|14
end_define

begin_define
define|#
directive|define
name|PEXPWTextBundle
value|15
end_define

begin_define
define|#
directive|define
name|PEXPWLineBundle
value|16
end_define

begin_define
define|#
directive|define
name|PEXPWInteriorBundle
value|17
end_define

begin_define
define|#
directive|define
name|PEXPWEdgeBundle
value|18
end_define

begin_define
define|#
directive|define
name|PEXPWColourTable
value|19
end_define

begin_define
define|#
directive|define
name|PEXPWDepthCueTable
value|20
end_define

begin_define
define|#
directive|define
name|PEXPWLightTable
value|21
end_define

begin_define
define|#
directive|define
name|PEXPWColourApproxTable
value|22
end_define

begin_define
define|#
directive|define
name|PEXPWPatternTable
value|23
end_define

begin_define
define|#
directive|define
name|PEXPWTextFontTable
value|24
end_define

begin_define
define|#
directive|define
name|PEXPWHighlightIncl
value|25
end_define

begin_define
define|#
directive|define
name|PEXPWHighlightExcl
value|26
end_define

begin_define
define|#
directive|define
name|PEXPWInvisibilityIncl
value|27
end_define

begin_define
define|#
directive|define
name|PEXPWInvisibilityExcl
value|28
end_define

begin_define
define|#
directive|define
name|PEXPWPostedStructures
value|29
end_define

begin_define
define|#
directive|define
name|PEXPWNumPriorities
value|30
end_define

begin_define
define|#
directive|define
name|PEXPWBufferUpdate
value|31
end_define

begin_define
define|#
directive|define
name|PEXPWReqBufferMode
value|32
end_define

begin_define
define|#
directive|define
name|PEXPWCurBufferMode
value|33
end_define

begin_define
define|#
directive|define
name|PEXMaxPWIndex
value|33
end_define

begin_comment
comment|/* Indices for GetDynamics */
end_comment

begin_define
define|#
directive|define
name|PEXPWDViewRep
value|0
end_define

begin_define
define|#
directive|define
name|PEXPWDMarkerBundle
value|1
end_define

begin_define
define|#
directive|define
name|PEXPWDTextBundle
value|2
end_define

begin_define
define|#
directive|define
name|PEXPWDLineBundle
value|3
end_define

begin_define
define|#
directive|define
name|PEXPWDInteriorBundle
value|4
end_define

begin_define
define|#
directive|define
name|PEXPWDEdgeBundle
value|5
end_define

begin_define
define|#
directive|define
name|PEXPWDColourTable
value|6
end_define

begin_define
define|#
directive|define
name|PEXPWDPatternTable
value|7
end_define

begin_define
define|#
directive|define
name|PEXPWDWksTransform
value|8
end_define

begin_define
define|#
directive|define
name|PEXPWDHighlightFilter
value|9
end_define

begin_define
define|#
directive|define
name|PEXPWDInvisibilityFilter
value|10
end_define

begin_define
define|#
directive|define
name|PEXPWDHlhsrMode
value|11
end_define

begin_define
define|#
directive|define
name|PEXPWDStructureModify
value|12
end_define

begin_define
define|#
directive|define
name|PEXPWDPostStructure
value|13
end_define

begin_define
define|#
directive|define
name|PEXPWDUnpostStructure
value|14
end_define

begin_define
define|#
directive|define
name|PEXPWDDeleteStructure
value|15
end_define

begin_define
define|#
directive|define
name|PEXPWDReferenceModify
value|16
end_define

begin_define
define|#
directive|define
name|PEXPWDBufferModify
value|17
end_define

begin_define
define|#
directive|define
name|PEXPWDLightTable
value|18
end_define

begin_define
define|#
directive|define
name|PEXPWDDepthCueTable
value|19
end_define

begin_define
define|#
directive|define
name|PEXPWDColourApproxTable
value|20
end_define

begin_comment
comment|/* Pick Device Bitmasks */
end_comment

begin_define
define|#
directive|define
name|PEXPDPickStatus
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXPDPickPath
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXPDPickPathOrder
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|PEXPDPickIncl
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|PEXPDPickExcl
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|PEXPDPickDataRec
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|PEXPDPickPromptEchoType
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|PEXPDPickEchoVolume
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|PEXPDPickEchoSwitch
value|(1L<<8)
end_define

begin_comment
comment|/* Pick Measure Bitmasks */
end_comment

begin_define
define|#
directive|define
name|PEXPMStatus
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXPMPath
value|(1L<<1)
end_define

begin_comment
comment|/* Errors */
end_comment

begin_define
define|#
directive|define
name|PEXColourTypeError
value|0
end_define

begin_define
define|#
directive|define
name|PEXRendererStateError
value|1
end_define

begin_define
define|#
directive|define
name|PEXFloatingPointFormatError
value|2
end_define

begin_define
define|#
directive|define
name|PEXLabelError
value|3
end_define

begin_define
define|#
directive|define
name|PEXLookupTableError
value|4
end_define

begin_define
define|#
directive|define
name|PEXNameSetError
value|5
end_define

begin_define
define|#
directive|define
name|PEXPathError
value|6
end_define

begin_define
define|#
directive|define
name|PEXFontError
value|7
end_define

begin_define
define|#
directive|define
name|PEXPhigsWksError
value|8
end_define

begin_define
define|#
directive|define
name|PEXPickMeasureError
value|9
end_define

begin_define
define|#
directive|define
name|PEXPipelineContextError
value|10
end_define

begin_define
define|#
directive|define
name|PEXRendererError
value|11
end_define

begin_define
define|#
directive|define
name|PEXSearchContextError
value|12
end_define

begin_define
define|#
directive|define
name|PEXStructureError
value|13
end_define

begin_define
define|#
directive|define
name|PEXOutputCommandError
value|14
end_define

begin_define
define|#
directive|define
name|PEXMaxError
value|14
end_define

begin_comment
comment|/* Requests */
end_comment

begin_define
define|#
directive|define
name|PEX_GetExtensionInfo
value|1
end_define

begin_define
define|#
directive|define
name|PEX_GetEnumeratedTypeInfo
value|2
end_define

begin_define
define|#
directive|define
name|PEX_GetImpDepConstants
value|3
end_define

begin_define
define|#
directive|define
name|PEX_CreateLookupTable
value|4
end_define

begin_define
define|#
directive|define
name|PEX_CopyLookupTable
value|5
end_define

begin_define
define|#
directive|define
name|PEX_FreeLookupTable
value|6
end_define

begin_define
define|#
directive|define
name|PEX_GetTableInfo
value|7
end_define

begin_define
define|#
directive|define
name|PEX_GetPredefinedEntries
value|8
end_define

begin_define
define|#
directive|define
name|PEX_GetDefinedIndices
value|9
end_define

begin_define
define|#
directive|define
name|PEX_GetTableEntry
value|10
end_define

begin_define
define|#
directive|define
name|PEX_GetTableEntries
value|11
end_define

begin_define
define|#
directive|define
name|PEX_SetTableEntries
value|12
end_define

begin_define
define|#
directive|define
name|PEX_DeleteTableEntries
value|13
end_define

begin_define
define|#
directive|define
name|PEX_CreatePipelineContext
value|14
end_define

begin_define
define|#
directive|define
name|PEX_CopyPipelineContext
value|15
end_define

begin_define
define|#
directive|define
name|PEX_FreePipelineContext
value|16
end_define

begin_define
define|#
directive|define
name|PEX_GetPipelineContext
value|17
end_define

begin_define
define|#
directive|define
name|PEX_ChangePipelineContext
value|18
end_define

begin_define
define|#
directive|define
name|PEX_CreateRenderer
value|19
end_define

begin_define
define|#
directive|define
name|PEX_FreeRenderer
value|20
end_define

begin_define
define|#
directive|define
name|PEX_ChangeRenderer
value|21
end_define

begin_define
define|#
directive|define
name|PEX_GetRendererAttributes
value|22
end_define

begin_define
define|#
directive|define
name|PEX_GetRendererDynamics
value|23
end_define

begin_define
define|#
directive|define
name|PEX_BeginRendering
value|24
end_define

begin_define
define|#
directive|define
name|PEX_EndRendering
value|25
end_define

begin_define
define|#
directive|define
name|PEX_BeginStructure
value|26
end_define

begin_define
define|#
directive|define
name|PEX_EndStructure
value|27
end_define

begin_define
define|#
directive|define
name|PEX_RenderOutputCommands
value|28
end_define

begin_define
define|#
directive|define
name|PEX_RenderNetwork
value|29
end_define

begin_define
define|#
directive|define
name|PEX_CreateStructure
value|30
end_define

begin_define
define|#
directive|define
name|PEX_CopyStructure
value|31
end_define

begin_define
define|#
directive|define
name|PEX_DestroyStructures
value|32
end_define

begin_define
define|#
directive|define
name|PEX_GetStructureInfo
value|33
end_define

begin_define
define|#
directive|define
name|PEX_GetElementInfo
value|34
end_define

begin_define
define|#
directive|define
name|PEX_GetStructuresInNetwork
value|35
end_define

begin_define
define|#
directive|define
name|PEX_GetAncestors
value|36
end_define

begin_define
define|#
directive|define
name|PEX_GetDescendants
value|37
end_define

begin_define
define|#
directive|define
name|PEX_FetchElements
value|38
end_define

begin_define
define|#
directive|define
name|PEX_SetEditingMode
value|39
end_define

begin_define
define|#
directive|define
name|PEX_SetElementPointer
value|40
end_define

begin_define
define|#
directive|define
name|PEX_SetElementPointerAtLabel
value|41
end_define

begin_define
define|#
directive|define
name|PEX_ElementSearch
value|42
end_define

begin_define
define|#
directive|define
name|PEX_StoreElements
value|43
end_define

begin_define
define|#
directive|define
name|PEX_DeleteElements
value|44
end_define

begin_define
define|#
directive|define
name|PEX_DeleteElementsToLabel
value|45
end_define

begin_define
define|#
directive|define
name|PEX_DeleteBetweenLabels
value|46
end_define

begin_define
define|#
directive|define
name|PEX_CopyElements
value|47
end_define

begin_define
define|#
directive|define
name|PEX_ChangeStructureRefs
value|48
end_define

begin_define
define|#
directive|define
name|PEX_CreateNameSet
value|49
end_define

begin_define
define|#
directive|define
name|PEX_CopyNameSet
value|50
end_define

begin_define
define|#
directive|define
name|PEX_FreeNameSet
value|51
end_define

begin_define
define|#
directive|define
name|PEX_GetNameSet
value|52
end_define

begin_define
define|#
directive|define
name|PEX_ChangeNameSet
value|53
end_define

begin_define
define|#
directive|define
name|PEX_CreateSearchContext
value|54
end_define

begin_define
define|#
directive|define
name|PEX_CopySearchContext
value|55
end_define

begin_define
define|#
directive|define
name|PEX_FreeSearchContext
value|56
end_define

begin_define
define|#
directive|define
name|PEX_GetSearchContext
value|57
end_define

begin_define
define|#
directive|define
name|PEX_ChangeSearchContext
value|58
end_define

begin_define
define|#
directive|define
name|PEX_SearchNetwork
value|59
end_define

begin_define
define|#
directive|define
name|PEX_CreatePhigsWks
value|60
end_define

begin_define
define|#
directive|define
name|PEX_FreePhigsWks
value|61
end_define

begin_define
define|#
directive|define
name|PEX_GetWksInfo
value|62
end_define

begin_define
define|#
directive|define
name|PEX_GetDynamics
value|63
end_define

begin_define
define|#
directive|define
name|PEX_GetViewRep
value|64
end_define

begin_define
define|#
directive|define
name|PEX_RedrawAllStructures
value|65
end_define

begin_define
define|#
directive|define
name|PEX_UpdateWorkstation
value|66
end_define

begin_define
define|#
directive|define
name|PEX_RedrawClipRegion
value|67
end_define

begin_define
define|#
directive|define
name|PEX_ExecuteDeferredActions
value|68
end_define

begin_define
define|#
directive|define
name|PEX_SetViewPriority
value|69
end_define

begin_define
define|#
directive|define
name|PEX_SetDisplayUpdateMode
value|70
end_define

begin_define
define|#
directive|define
name|PEX_MapDCtoWC
value|71
end_define

begin_define
define|#
directive|define
name|PEX_MapWCtoDC
value|72
end_define

begin_define
define|#
directive|define
name|PEX_SetViewRep
value|73
end_define

begin_define
define|#
directive|define
name|PEX_SetWksWindow
value|74
end_define

begin_define
define|#
directive|define
name|PEX_SetWksViewport
value|75
end_define

begin_define
define|#
directive|define
name|PEX_SetHlhsrMode
value|76
end_define

begin_define
define|#
directive|define
name|PEX_SetWksBufferMode
value|77
end_define

begin_define
define|#
directive|define
name|PEX_PostStructure
value|78
end_define

begin_define
define|#
directive|define
name|PEX_UnpostStructure
value|79
end_define

begin_define
define|#
directive|define
name|PEX_UnpostAllStructures
value|80
end_define

begin_define
define|#
directive|define
name|PEX_GetWksPostings
value|81
end_define

begin_define
define|#
directive|define
name|PEX_GetPickDevice
value|82
end_define

begin_define
define|#
directive|define
name|PEX_ChangePickDevice
value|83
end_define

begin_define
define|#
directive|define
name|PEX_CreatePickMeasure
value|84
end_define

begin_define
define|#
directive|define
name|PEX_FreePickMeasure
value|85
end_define

begin_define
define|#
directive|define
name|PEX_GetPickMeasure
value|86
end_define

begin_define
define|#
directive|define
name|PEX_UpdatePickMeasure
value|87
end_define

begin_define
define|#
directive|define
name|PEX_OpenFont
value|88
end_define

begin_define
define|#
directive|define
name|PEX_CloseFont
value|89
end_define

begin_define
define|#
directive|define
name|PEX_QueryFont
value|90
end_define

begin_define
define|#
directive|define
name|PEX_ListFonts
value|91
end_define

begin_define
define|#
directive|define
name|PEX_ListFontsWithInfo
value|92
end_define

begin_define
define|#
directive|define
name|PEX_QueryTextExtents
value|93
end_define

begin_define
define|#
directive|define
name|PEX_MatchRendererTargets
value|94
end_define

begin_define
define|#
directive|define
name|PEX_Escape
value|95
end_define

begin_define
define|#
directive|define
name|PEX_EscapeWithReply
value|96
end_define

begin_define
define|#
directive|define
name|PEX_RenderElements
value|97
end_define

begin_define
define|#
directive|define
name|PEX_AccumulateState
value|98
end_define

begin_define
define|#
directive|define
name|PEX_BeginPickOne
value|99
end_define

begin_define
define|#
directive|define
name|PEX_EndPickOne
value|100
end_define

begin_define
define|#
directive|define
name|PEX_PickOne
value|101
end_define

begin_define
define|#
directive|define
name|PEX_BeginPickAll
value|102
end_define

begin_define
define|#
directive|define
name|PEX_EndPickAll
value|103
end_define

begin_define
define|#
directive|define
name|PEX_PickAll
value|104
end_define

begin_define
define|#
directive|define
name|PEXMaxRequest
value|104
end_define

begin_comment
comment|/* Output Commands */
end_comment

begin_define
define|#
directive|define
name|PEXOCAll
value|0
end_define

begin_define
define|#
directive|define
name|PEXOCMarkerType
value|1
end_define

begin_define
define|#
directive|define
name|PEXOCMarkerScale
value|2
end_define

begin_define
define|#
directive|define
name|PEXOCMarkerColourIndex
value|3
end_define

begin_define
define|#
directive|define
name|PEXOCMarkerColour
value|4
end_define

begin_define
define|#
directive|define
name|PEXOCMarkerBundleIndex
value|5
end_define

begin_define
define|#
directive|define
name|PEXOCTextFontIndex
value|6
end_define

begin_define
define|#
directive|define
name|PEXOCTextPrecision
value|7
end_define

begin_define
define|#
directive|define
name|PEXOCCharExpansion
value|8
end_define

begin_define
define|#
directive|define
name|PEXOCCharSpacing
value|9
end_define

begin_define
define|#
directive|define
name|PEXOCTextColourIndex
value|10
end_define

begin_define
define|#
directive|define
name|PEXOCTextColour
value|11
end_define

begin_define
define|#
directive|define
name|PEXOCCharHeight
value|12
end_define

begin_define
define|#
directive|define
name|PEXOCCharUpVector
value|13
end_define

begin_define
define|#
directive|define
name|PEXOCTextPath
value|14
end_define

begin_define
define|#
directive|define
name|PEXOCTextAlignment
value|15
end_define

begin_define
define|#
directive|define
name|PEXOCAtextHeight
value|16
end_define

begin_define
define|#
directive|define
name|PEXOCAtextUpVector
value|17
end_define

begin_define
define|#
directive|define
name|PEXOCAtextPath
value|18
end_define

begin_define
define|#
directive|define
name|PEXOCAtextAlignment
value|19
end_define

begin_define
define|#
directive|define
name|PEXOCAtextStyle
value|20
end_define

begin_define
define|#
directive|define
name|PEXOCTextBundleIndex
value|21
end_define

begin_define
define|#
directive|define
name|PEXOCLineType
value|22
end_define

begin_define
define|#
directive|define
name|PEXOCLineWidth
value|23
end_define

begin_define
define|#
directive|define
name|PEXOCLineColourIndex
value|24
end_define

begin_define
define|#
directive|define
name|PEXOCLineColour
value|25
end_define

begin_define
define|#
directive|define
name|PEXOCCurveApproximation
value|26
end_define

begin_define
define|#
directive|define
name|PEXOCPolylineInterp
value|27
end_define

begin_define
define|#
directive|define
name|PEXOCLineBundleIndex
value|28
end_define

begin_define
define|#
directive|define
name|PEXOCInteriorStyle
value|29
end_define

begin_define
define|#
directive|define
name|PEXOCInteriorStyleIndex
value|30
end_define

begin_define
define|#
directive|define
name|PEXOCSurfaceColourIndex
value|31
end_define

begin_define
define|#
directive|define
name|PEXOCSurfaceColour
value|32
end_define

begin_define
define|#
directive|define
name|PEXOCSurfaceReflAttr
value|33
end_define

begin_define
define|#
directive|define
name|PEXOCSurfaceReflModel
value|34
end_define

begin_define
define|#
directive|define
name|PEXOCSurfaceInterp
value|35
end_define

begin_define
define|#
directive|define
name|PEXOCBfInteriorStyle
value|36
end_define

begin_define
define|#
directive|define
name|PEXOCBfInteriorStyleIndex
value|37
end_define

begin_define
define|#
directive|define
name|PEXOCBfSurfaceColourIndex
value|38
end_define

begin_define
define|#
directive|define
name|PEXOCBfSurfaceColour
value|39
end_define

begin_define
define|#
directive|define
name|PEXOCBfSurfaceReflAttr
value|40
end_define

begin_define
define|#
directive|define
name|PEXOCBfSurfaceReflModel
value|41
end_define

begin_define
define|#
directive|define
name|PEXOCBfSurfaceInterp
value|42
end_define

begin_define
define|#
directive|define
name|PEXOCSurfaceApproximation
value|43
end_define

begin_define
define|#
directive|define
name|PEXOCCullingMode
value|44
end_define

begin_define
define|#
directive|define
name|PEXOCDistinguishFlag
value|45
end_define

begin_define
define|#
directive|define
name|PEXOCPatternSize
value|46
end_define

begin_define
define|#
directive|define
name|PEXOCPatternRefPt
value|47
end_define

begin_define
define|#
directive|define
name|PEXOCPatternAttr
value|48
end_define

begin_define
define|#
directive|define
name|PEXOCInteriorBundleIndex
value|49
end_define

begin_define
define|#
directive|define
name|PEXOCSurfaceEdgeFlag
value|50
end_define

begin_define
define|#
directive|define
name|PEXOCSurfaceEdgeType
value|51
end_define

begin_define
define|#
directive|define
name|PEXOCSurfaceEdgeWidth
value|52
end_define

begin_define
define|#
directive|define
name|PEXOCSurfaceEdgeColourIndex
value|53
end_define

begin_define
define|#
directive|define
name|PEXOCSurfaceEdgeColour
value|54
end_define

begin_define
define|#
directive|define
name|PEXOCEdgeBundleIndex
value|55
end_define

begin_define
define|#
directive|define
name|PEXOCSetAsfValues
value|56
end_define

begin_define
define|#
directive|define
name|PEXOCLocalTransform
value|57
end_define

begin_define
define|#
directive|define
name|PEXOCLocalTransform2D
value|58
end_define

begin_define
define|#
directive|define
name|PEXOCGlobalTransform
value|59
end_define

begin_define
define|#
directive|define
name|PEXOCGlobalTransform2D
value|60
end_define

begin_define
define|#
directive|define
name|PEXOCModelClip
value|61
end_define

begin_define
define|#
directive|define
name|PEXOCModelClipVolume
value|62
end_define

begin_define
define|#
directive|define
name|PEXOCModelClipVolume2D
value|63
end_define

begin_define
define|#
directive|define
name|PEXOCRestoreModelClip
value|64
end_define

begin_define
define|#
directive|define
name|PEXOCViewIndex
value|65
end_define

begin_define
define|#
directive|define
name|PEXOCLightState
value|66
end_define

begin_define
define|#
directive|define
name|PEXOCDepthCueIndex
value|67
end_define

begin_define
define|#
directive|define
name|PEXOCPickId
value|68
end_define

begin_define
define|#
directive|define
name|PEXOCHlhsrIdentifier
value|69
end_define

begin_define
define|#
directive|define
name|PEXOCColourApproxIndex
value|70
end_define

begin_define
define|#
directive|define
name|PEXOCRenderingColourModel
value|71
end_define

begin_define
define|#
directive|define
name|PEXOCParaSurfCharacteristics
value|72
end_define

begin_define
define|#
directive|define
name|PEXOCAddToNameSet
value|73
end_define

begin_define
define|#
directive|define
name|PEXOCRemoveFromNameSet
value|74
end_define

begin_define
define|#
directive|define
name|PEXOCExecuteStructure
value|75
end_define

begin_define
define|#
directive|define
name|PEXOCLabel
value|76
end_define

begin_define
define|#
directive|define
name|PEXOCApplicationData
value|77
end_define

begin_define
define|#
directive|define
name|PEXOCGse
value|78
end_define

begin_define
define|#
directive|define
name|PEXOCMarker
value|79
end_define

begin_define
define|#
directive|define
name|PEXOCMarker2D
value|80
end_define

begin_define
define|#
directive|define
name|PEXOCText
value|81
end_define

begin_define
define|#
directive|define
name|PEXOCText2D
value|82
end_define

begin_define
define|#
directive|define
name|PEXOCAnnotationText
value|83
end_define

begin_define
define|#
directive|define
name|PEXOCAnnotationText2D
value|84
end_define

begin_define
define|#
directive|define
name|PEXOCPolyline
value|85
end_define

begin_define
define|#
directive|define
name|PEXOCPolyline2D
value|86
end_define

begin_define
define|#
directive|define
name|PEXOCPolylineSet
value|87
end_define

begin_define
define|#
directive|define
name|PEXOCNurbCurve
value|88
end_define

begin_define
define|#
directive|define
name|PEXOCFillArea
value|89
end_define

begin_define
define|#
directive|define
name|PEXOCFillArea2D
value|90
end_define

begin_define
define|#
directive|define
name|PEXOCExtFillArea
value|91
end_define

begin_define
define|#
directive|define
name|PEXOCFillAreaSet
value|92
end_define

begin_define
define|#
directive|define
name|PEXOCFillAreaSet2D
value|93
end_define

begin_define
define|#
directive|define
name|PEXOCExtFillAreaSet
value|94
end_define

begin_define
define|#
directive|define
name|PEXOCTriangleStrip
value|95
end_define

begin_define
define|#
directive|define
name|PEXOCQuadrilateralMesh
value|96
end_define

begin_define
define|#
directive|define
name|PEXOCSOFAS
value|97
end_define

begin_define
define|#
directive|define
name|PEXOCNurbSurface
value|98
end_define

begin_define
define|#
directive|define
name|PEXOCCellArray
value|99
end_define

begin_define
define|#
directive|define
name|PEXOCCellArray2D
value|100
end_define

begin_define
define|#
directive|define
name|PEXOCExtCellArray
value|101
end_define

begin_define
define|#
directive|define
name|PEXOCGdp
value|102
end_define

begin_define
define|#
directive|define
name|PEXOCGdp2D
value|103
end_define

begin_define
define|#
directive|define
name|PEXOCNoop
value|104
end_define

begin_define
define|#
directive|define
name|PEXMaxOC
value|104
end_define

begin_define
define|#
directive|define
name|PEXOCNil
value|0xffff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PEX.h */
end_comment

end_unit

