begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_comment
comment|/* $XConsortium: PEX.h,v 1.7 92/08/26 15:16:05 mor Exp $ */
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

begin_comment
comment|/*  * PEX extension name  */
end_comment

begin_define
define|#
directive|define
name|PEX_NAME_STRING
value|"X3D-PEX"
end_define

begin_comment
comment|/*  * PEX protocol major and minor numbers  */
end_comment

begin_define
define|#
directive|define
name|PEX_PROTO_MAJOR
value|5
end_define

begin_comment
comment|/* 5.1 protocol */
end_comment

begin_define
define|#
directive|define
name|PEX_PROTO_MINOR
value|1
end_define

begin_comment
comment|/* 5.1 protocol */
end_comment

begin_comment
comment|/*  * PEX standard subsets  */
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
name|PEXImmediateMode
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXWorkstationOnly
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXStructureMode
value|(1L<<2)
end_define

begin_comment
comment|/*  * enumerated type information  */
end_comment

begin_define
define|#
directive|define
name|PEXETCounts
value|0
end_define

begin_define
define|#
directive|define
name|PEXETIndex
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXETMnemonic
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXETAll
value|(PEXETIndex | PEXETMnemonic)
end_define

begin_comment
comment|/* enumerated types */
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
name|PEXETColorType
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
name|PEXETHLHSRMode
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
name|PEXETColorApproxType
value|20
end_define

begin_define
define|#
directive|define
name|PEXETColorApproxModel
value|21
end_define

begin_define
define|#
directive|define
name|PEXETGDP2D
value|22
end_define

begin_define
define|#
directive|define
name|PEXETGDP
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
name|PEXETRenderingColorModel
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
comment|/* enumerated type values */
end_comment

begin_comment
comment|/* marker types */
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
comment|/* marker type mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMMarkerDot
value|"Dot"
end_define

begin_define
define|#
directive|define
name|PEXETMMarkerCross
value|"Cross"
end_define

begin_define
define|#
directive|define
name|PEXETMMarkerAsterisk
value|"Asterisk"
end_define

begin_define
define|#
directive|define
name|PEXETMMarkerCircle
value|"Circle"
end_define

begin_define
define|#
directive|define
name|PEXETMMarkerX
value|"X"
end_define

begin_comment
comment|/* annotation text styles */
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
comment|/* annotation text style mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMATextNotConnected
value|"NotConnected"
end_define

begin_define
define|#
directive|define
name|PEXETMATextConnected
value|"Connected"
end_define

begin_comment
comment|/* interior styles */
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
comment|/* interior style mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMInteriorStyleHollow
value|"Hollow"
end_define

begin_define
define|#
directive|define
name|PEXETMInteriorStyleSolid
value|"Solid"
end_define

begin_define
define|#
directive|define
name|PEXETMInteriorStylePattern
value|"Pattern"
end_define

begin_define
define|#
directive|define
name|PEXETMInteriorStyleHatch
value|"Hatch"
end_define

begin_define
define|#
directive|define
name|PEXETMInteriorStyleEmpty
value|"Empty"
end_define

begin_comment
comment|/* hatch style */
end_comment

begin_comment
comment|/* line types */
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
comment|/* line type mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMLineTypeSolid
value|"Solid"
end_define

begin_define
define|#
directive|define
name|PEXETMLineTypeDashed
value|"Dashed"
end_define

begin_define
define|#
directive|define
name|PEXETMLineTypeDotted
value|"Dotted"
end_define

begin_define
define|#
directive|define
name|PEXETMLineTypeDashDot
value|"DashDot"
end_define

begin_comment
comment|/* surface edge types */
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
comment|/* surface edge type mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMSurfaceEdgeSolid
value|"Solid"
end_define

begin_define
define|#
directive|define
name|PEXETMSurfaceEdgeDashed
value|"Dashed"
end_define

begin_define
define|#
directive|define
name|PEXETMSurfaceEdgeDotted
value|"Dotted"
end_define

begin_define
define|#
directive|define
name|PEXETMSurfaceEdgeDashDot
value|"DashDot"
end_define

begin_comment
comment|/* pick device types */
end_comment

begin_define
define|#
directive|define
name|PEXPickDeviceDCHitBox
value|1
end_define

begin_define
define|#
directive|define
name|PEXPickDeviceNPCHitVolume
value|2
end_define

begin_comment
comment|/* pick device type mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMPickDeviceDCHitBox
value|"DC_HitBox"
end_define

begin_define
define|#
directive|define
name|PEXETMPickDeviceNPCHitVolume
value|"NPC_HitVolume"
end_define

begin_comment
comment|/* polyline interpolation methods */
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
name|PEXPolylineInterpColor
value|2
end_define

begin_comment
comment|/* polyline interpolation method mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMPolylineInterpNone
value|"None"
end_define

begin_define
define|#
directive|define
name|PEXETMPolylineInterpColor
value|"Color"
end_define

begin_comment
comment|/* curve, surface and trim curve approximation methods */
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
name|PEXApproxWCChordalSize
value|3
end_define

begin_define
define|#
directive|define
name|PEXApproxNPCChordalSize
value|4
end_define

begin_define
define|#
directive|define
name|PEXApproxDCChordalSize
value|5
end_define

begin_define
define|#
directive|define
name|PEXCurveApproxWCChordalDev
value|6
end_define

begin_define
define|#
directive|define
name|PEXCurveApproxNPCChordalDev
value|7
end_define

begin_define
define|#
directive|define
name|PEXCurveApproxDCChordalDev
value|8
end_define

begin_define
define|#
directive|define
name|PEXSurfaceApproxWCPlanarDev
value|6
end_define

begin_define
define|#
directive|define
name|PEXSurfaceApproxNPCPlanarDev
value|7
end_define

begin_define
define|#
directive|define
name|PEXSurfaceApproxDCPlanarDev
value|8
end_define

begin_define
define|#
directive|define
name|PEXApproxWCRelative
value|9
end_define

begin_define
define|#
directive|define
name|PEXApproxNPCRelative
value|10
end_define

begin_define
define|#
directive|define
name|PEXApproxDCRelative
value|11
end_define

begin_comment
comment|/* curve, surface and trim curve approximation method mnemonics */
end_comment

begin_comment
comment|/* PEXApproxImpDep                 is an implementation-dependent string */
end_comment

begin_define
define|#
directive|define
name|PEXETMApproxConstantBetweenKnots
value|"ConstantBetweenKnots"
end_define

begin_define
define|#
directive|define
name|PEXETMApproxWCChordalSize
value|"WCS_ChordalSize"
end_define

begin_define
define|#
directive|define
name|PEXETMApproxNPCChordalSize
value|"NPC_ChordalSize"
end_define

begin_define
define|#
directive|define
name|PEXETMApproxDCChordalSize
value|"DC_ChordalSize"
end_define

begin_define
define|#
directive|define
name|PEXETMCurveApproxWCChordalDev
value|"WCS_ChordalDev"
end_define

begin_define
define|#
directive|define
name|PEXETMCurveApproxNPCChordalDev
value|"NPC_ChordalDev"
end_define

begin_define
define|#
directive|define
name|PEXETMCurveApproxDCChordalDev
value|"DC_ChordalDev"
end_define

begin_define
define|#
directive|define
name|PEXETMSurfaceApproxWCPlanarDev
value|"WCS_PlanarDev"
end_define

begin_define
define|#
directive|define
name|PEXETMSurfaceApproxNPCPlanarDev
value|"NPC_PlanarDev"
end_define

begin_define
define|#
directive|define
name|PEXETMSurfaceApproxDCPlanarDev
value|"DC_PlanarDev"
end_define

begin_define
define|#
directive|define
name|PEXETMApproxWCRelative
value|"WCS_Relative"
end_define

begin_define
define|#
directive|define
name|PEXETMApproxNPCRelative
value|"NPC_Relative"
end_define

begin_define
define|#
directive|define
name|PEXETMApproxDCRelative
value|"DC_Relative"
end_define

begin_comment
comment|/* reflection models */
end_comment

begin_define
define|#
directive|define
name|PEXReflectionNone
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
comment|/* reflection model mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMReflectionNone
value|"NoShading"
end_define

begin_define
define|#
directive|define
name|PEXETMReflectionAmbient
value|"Ambient"
end_define

begin_define
define|#
directive|define
name|PEXETMReflectionDiffuse
value|"Diffuse"
end_define

begin_define
define|#
directive|define
name|PEXETMReflectionSpecular
value|"Specular"
end_define

begin_comment
comment|/* surface interpolation methods */
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
name|PEXSurfaceInterpColor
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
comment|/* surface interpolation method mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMSurfaceInterpNone
value|"None"
end_define

begin_define
define|#
directive|define
name|PEXETMSurfaceInterpColor
value|"Color"
end_define

begin_define
define|#
directive|define
name|PEXETMSurfaceInterpDotProduct
value|"DotProduct"
end_define

begin_define
define|#
directive|define
name|PEXETMSurfaceInterpNormal
value|"Normal"
end_define

begin_comment
comment|/* model clip operators */
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
comment|/* model clip operator mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMModelClipReplace
value|"Replace"
end_define

begin_define
define|#
directive|define
name|PEXETMModelClipIntersection
value|"Intersection"
end_define

begin_comment
comment|/* light types */
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
name|PEXLightWCVector
value|2
end_define

begin_define
define|#
directive|define
name|PEXLightWCPoint
value|3
end_define

begin_define
define|#
directive|define
name|PEXLightWCSpot
value|4
end_define

begin_comment
comment|/* light type mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMLightAmbient
value|"Ambient"
end_define

begin_define
define|#
directive|define
name|PEXETMLightWCVector
value|"WCS_Vector"
end_define

begin_define
define|#
directive|define
name|PEXETMLightWCPoint
value|"WCS_Point"
end_define

begin_define
define|#
directive|define
name|PEXETMLightWCSpot
value|"WCS_Spot"
end_define

begin_comment
comment|/* color types */
end_comment

begin_define
define|#
directive|define
name|PEXColorTypeIndexed
value|0
end_define

begin_define
define|#
directive|define
name|PEXColorTypeRGB
value|1
end_define

begin_define
define|#
directive|define
name|PEXColorTypeCIE
value|2
end_define

begin_define
define|#
directive|define
name|PEXColorTypeHSV
value|3
end_define

begin_define
define|#
directive|define
name|PEXColorTypeHLS
value|4
end_define

begin_define
define|#
directive|define
name|PEXColorTypeRGB8
value|5
end_define

begin_define
define|#
directive|define
name|PEXColorTypeRGB16
value|6
end_define

begin_comment
comment|/* color type mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMColorTypeIndexed
value|"Indexed"
end_define

begin_define
define|#
directive|define
name|PEXETMColorTypeRGB
value|"RGBFloat"
end_define

begin_define
define|#
directive|define
name|PEXETMColorTypeCIE
value|"CIEFloat"
end_define

begin_define
define|#
directive|define
name|PEXETMColorTypeHSV
value|"HSVFloat"
end_define

begin_define
define|#
directive|define
name|PEXETMColorTypeHLS
value|"HLSFloat"
end_define

begin_define
define|#
directive|define
name|PEXETMColorTypeRGB8
value|"RGBInt8"
end_define

begin_define
define|#
directive|define
name|PEXETMColorTypeRGB16
value|"RGBInt16"
end_define

begin_comment
comment|/* float formats */
end_comment

begin_define
define|#
directive|define
name|PEXIEEE_754_32
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
name|PEXIEEE_754_64
value|3
end_define

begin_define
define|#
directive|define
name|PEXDEC_D_Floating
value|4
end_define

begin_comment
comment|/* float format mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMIEEE_754_32
value|"IEEE_754_32"
end_define

begin_define
define|#
directive|define
name|PEXETMDEC_F_Floating
value|"DEC_F_Floating"
end_define

begin_define
define|#
directive|define
name|PEXETMIEEE_754_64
value|"IEEE_754_64"
end_define

begin_define
define|#
directive|define
name|PEXETMDEC_D_Floating
value|"DEC_D_Floating"
end_define

begin_comment
comment|/* HLHSR modes */
end_comment

begin_define
define|#
directive|define
name|PEXHLHSROff
value|1
end_define

begin_define
define|#
directive|define
name|PEXHLHSRZBuffer
value|2
end_define

begin_define
define|#
directive|define
name|PEXHLHSRPainters
value|3
end_define

begin_define
define|#
directive|define
name|PEXHLHSRScanline
value|4
end_define

begin_define
define|#
directive|define
name|PEXHLHSRHiddenLineOnly
value|5
end_define

begin_define
define|#
directive|define
name|PEXHLHSRZBufferID
value|6
end_define

begin_comment
comment|/* HLHSR mode mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMHLHSROff
value|"Off"
end_define

begin_define
define|#
directive|define
name|PEXETMHLHSRZBuffer
value|"ZBuffer"
end_define

begin_define
define|#
directive|define
name|PEXETMHLHSRPainters
value|"Painters"
end_define

begin_define
define|#
directive|define
name|PEXETMHLHSRScanline
value|"Scanline"
end_define

begin_define
define|#
directive|define
name|PEXETMHLHSRHiddenLineOnly
value|"HiddenLineOnly"
end_define

begin_define
define|#
directive|define
name|PEXETMHLHSRZBufferID
value|"ZBufferId"
end_define

begin_comment
comment|/* prompt echo types */
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
comment|/* prompt echo type mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMEchoPrimitive
value|"EchoPrimitive"
end_define

begin_define
define|#
directive|define
name|PEXETMEchoStructure
value|"EchoStructure"
end_define

begin_define
define|#
directive|define
name|PEXETMEchoNetwork
value|"EchoNetwork"
end_define

begin_comment
comment|/* display update methods */
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
comment|/* display update method mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMVisualizeEach
value|"VisualizeEach"
end_define

begin_define
define|#
directive|define
name|PEXETMVisualizeEasy
value|"VisualizeEasy"
end_define

begin_define
define|#
directive|define
name|PEXETMVisualizeNone
value|"VisualizeNone"
end_define

begin_define
define|#
directive|define
name|PEXETMSimulateSome
value|"SimulateSome"
end_define

begin_define
define|#
directive|define
name|PEXETMVisualizeWhenever
value|"VisualizeWhenever"
end_define

begin_comment
comment|/* color approximation types */
end_comment

begin_define
define|#
directive|define
name|PEXColorSpace
value|1
end_define

begin_define
define|#
directive|define
name|PEXColorRange
value|2
end_define

begin_comment
comment|/* color approximation type mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMColorSpace
value|"ColorSpace"
end_define

begin_define
define|#
directive|define
name|PEXETMColorRange
value|"ColorRange"
end_define

begin_comment
comment|/* color approximation models */
end_comment

begin_define
define|#
directive|define
name|PEXColorApproxRGB
value|1
end_define

begin_define
define|#
directive|define
name|PEXColorApproxCIE
value|2
end_define

begin_define
define|#
directive|define
name|PEXColorApproxHSV
value|3
end_define

begin_define
define|#
directive|define
name|PEXColorApproxHLS
value|4
end_define

begin_define
define|#
directive|define
name|PEXColorApproxYIQ
value|5
end_define

begin_comment
comment|/* color approximation model mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMColorApproxRGB
value|"RGB"
end_define

begin_define
define|#
directive|define
name|PEXETMColorApproxCIE
value|"CIE"
end_define

begin_define
define|#
directive|define
name|PEXETMColorApproxHSV
value|"HSV"
end_define

begin_define
define|#
directive|define
name|PEXETMColorApproxHLS
value|"HLS"
end_define

begin_define
define|#
directive|define
name|PEXETMColorApproxYIQ
value|"YIQ"
end_define

begin_comment
comment|/* rendering color models */
end_comment

begin_define
define|#
directive|define
name|PEXRenderingColorModelImpDep
value|0
end_define

begin_define
define|#
directive|define
name|PEXRenderingColorModelRGB
value|1
end_define

begin_define
define|#
directive|define
name|PEXRenderingColorModelCIE
value|2
end_define

begin_define
define|#
directive|define
name|PEXRenderingColorModelHSV
value|3
end_define

begin_define
define|#
directive|define
name|PEXRenderingColorModelHLS
value|4
end_define

begin_comment
comment|/* rendering color model mnemonics */
end_comment

begin_comment
comment|/* PEXETMRenderingColorModelImpDep is an implementation-dependent string */
end_comment

begin_define
define|#
directive|define
name|PEXETMRenderingColorModelRGB
value|"RGB"
end_define

begin_define
define|#
directive|define
name|PEXETMRenderingColorModelCIE
value|"CIE"
end_define

begin_define
define|#
directive|define
name|PEXETMRenderingColorModelHSV
value|"HSV"
end_define

begin_define
define|#
directive|define
name|PEXETMRenderingColorModelHLS
value|"HLS"
end_define

begin_comment
comment|/* parametric surface characteristics */
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
name|PEXPSCMCLevelCurves
value|4
end_define

begin_define
define|#
directive|define
name|PEXPSCWCLevelCurves
value|5
end_define

begin_comment
comment|/* parametric surface characteristic mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMPSCNone
value|"None"
end_define

begin_comment
comment|/* PEXETMPSCImpDep                 is an implementation-dependent string */
end_comment

begin_define
define|#
directive|define
name|PEXETMPSCIsoCurves
value|"IsoparametricCurves"
end_define

begin_define
define|#
directive|define
name|PEXETMPSCMCLevelCurves
value|"MC_LevelCurves"
end_define

begin_define
define|#
directive|define
name|PEXETMPSCWCLevelCurves
value|"WC_LevelCurves"
end_define

begin_comment
comment|/* standard escape identifiers */
end_comment

begin_define
define|#
directive|define
name|PEXEscapeSetEchoColor
value|1
end_define

begin_comment
comment|/* standard escape identifier mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMEscapeSetEchoColor
value|"SetEchoColor"
end_define

begin_comment
comment|/* pick one methods */
end_comment

begin_define
define|#
directive|define
name|PEXPickLast
value|1
end_define

begin_define
define|#
directive|define
name|PEXPickClosestZ
value|2
end_define

begin_define
define|#
directive|define
name|PEXPickVisibleAny
value|3
end_define

begin_define
define|#
directive|define
name|PEXPickVisibleClosest
value|4
end_define

begin_comment
comment|/* pick one method mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMPickLast
value|"Last"
end_define

begin_define
define|#
directive|define
name|PEXETMPickClosestZ
value|"ClosestZ"
end_define

begin_define
define|#
directive|define
name|PEXETMPickVisibleAny
value|"VisibleAny"
end_define

begin_define
define|#
directive|define
name|PEXETMPickVisibleClosest
value|"VisibleClosest"
end_define

begin_comment
comment|/* pick all methods */
end_comment

begin_define
define|#
directive|define
name|PEXPickAllAll
value|1
end_define

begin_define
define|#
directive|define
name|PEXPickAllVisible
value|2
end_define

begin_comment
comment|/* pick all method mnemonics */
end_comment

begin_define
define|#
directive|define
name|PEXETMPickAllAll
value|"All"
end_define

begin_define
define|#
directive|define
name|PEXETMPickAllVisible
value|"Visible"
end_define

begin_comment
comment|/*  * implementation dependent constants  */
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
name|PEXIDBestColorApprox
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

begin_define
define|#
directive|define
name|PEXIDMaxHitsEventSupported
value|34
end_define

begin_comment
comment|/* values for PEXIDBestColorApprox */
end_comment

begin_define
define|#
directive|define
name|PEXColorApproxAnyValues
value|0
end_define

begin_define
define|#
directive|define
name|PEXColorApproxPowersOf2
value|1
end_define

begin_comment
comment|/*  * match rendering targets  */
end_comment

begin_define
define|#
directive|define
name|PEXAnyDrawable
value|0
end_define

begin_define
define|#
directive|define
name|PEXWindowDrawable
value|1
end_define

begin_define
define|#
directive|define
name|PEXPixmapDrawable
value|2
end_define

begin_define
define|#
directive|define
name|PEXBufferDrawable
value|3
end_define

begin_comment
comment|/*  * output primitive and attribute values  */
end_comment

begin_comment
comment|/* shape hints */
end_comment

begin_define
define|#
directive|define
name|PEXShapeComplex
value|0
end_define

begin_define
define|#
directive|define
name|PEXShapeNonConvex
value|1
end_define

begin_define
define|#
directive|define
name|PEXShapeConvex
value|2
end_define

begin_define
define|#
directive|define
name|PEXShapeUnknown
value|3
end_define

begin_comment
comment|/* contour hints */
end_comment

begin_define
define|#
directive|define
name|PEXContourDisjoint
value|0
end_define

begin_define
define|#
directive|define
name|PEXContourNested
value|1
end_define

begin_define
define|#
directive|define
name|PEXContourIntersecting
value|2
end_define

begin_define
define|#
directive|define
name|PEXContourUnknown
value|3
end_define

begin_comment
comment|/* facet and vertex attributes bitmask */
end_comment

begin_define
define|#
directive|define
name|PEXGANone
value|0
end_define

begin_define
define|#
directive|define
name|PEXGAColor
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXGANormal
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXGAEdges
value|(1L<<2)
end_define

begin_comment
comment|/* flags (e.g., switches, visibility, and edges) */
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
comment|/* HLHSR identifier for PEXHLHSRZBufferID HLHSR mode */
end_comment

begin_define
define|#
directive|define
name|PEXHLHSRIDDisable
value|0
end_define

begin_define
define|#
directive|define
name|PEXHLHSRIDEnable
value|1
end_define

begin_comment
comment|/* text path direction */
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

begin_comment
comment|/* text vertical alignment */
end_comment

begin_define
define|#
directive|define
name|PEXVAlignNormal
value|0
end_define

begin_define
define|#
directive|define
name|PEXVAlignTop
value|1
end_define

begin_define
define|#
directive|define
name|PEXVAlignCap
value|2
end_define

begin_define
define|#
directive|define
name|PEXVAlignHalf
value|3
end_define

begin_define
define|#
directive|define
name|PEXVAlignBase
value|4
end_define

begin_define
define|#
directive|define
name|PEXVAlignBottom
value|5
end_define

begin_comment
comment|/* text horizontal alignment */
end_comment

begin_define
define|#
directive|define
name|PEXHAlignNormal
value|0
end_define

begin_define
define|#
directive|define
name|PEXHAlignLeft
value|1
end_define

begin_define
define|#
directive|define
name|PEXHAlignCenter
value|2
end_define

begin_define
define|#
directive|define
name|PEXHAlignRight
value|3
end_define

begin_comment
comment|/* text precision */
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
comment|/* character set width */
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
comment|/* curve and surface types */
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
comment|/* clipping */
end_comment

begin_define
define|#
directive|define
name|PEXClipXY
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXClipBack
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXClipFront
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|PEXClippingAll
value|(PEXClipXY | PEXClipBack | PEXClipFront)
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
comment|/* cull modes */
end_comment

begin_define
define|#
directive|define
name|PEXNone
value|0
end_define

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
comment|/* local transform composition types */
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
comment|/* isoparametric curves placement types */
end_comment

begin_define
define|#
directive|define
name|PEXUniformPlacement
value|0
end_define

begin_define
define|#
directive|define
name|PEXNonUniformPlacement
value|1
end_define

begin_comment
comment|/* aspect source flags (ASFs) */
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
comment|/* mask values for setting ASFs */
end_comment

begin_define
define|#
directive|define
name|PEXASFMarkerType
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXASFMarkerScale
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXASFMarkerColor
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|PEXASFTextFontIndex
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|PEXASFTextPrec
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|PEXASFCharExpansion
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|PEXASFCharSpacing
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|PEXASFTextColor
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|PEXASFLineType
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|PEXASFLineWidth
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|PEXASFLineColor
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|PEXASFCurveApprox
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|PEXASFPolylineInterp
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|PEXASFInteriorStyle
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|PEXASFInteriorStyleIndex
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|PEXASFSurfaceColor
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|PEXASFSurfaceInterp
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|PEXASFReflectionModel
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|PEXASFReflectionAttr
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|PEXASFBFInteriorStyle
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|PEXASFBFInteriorStyleIndex
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|PEXASFBFSurfaceColor
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|PEXASFBFSurfaceInterp
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|PEXASFBFReflectionModel
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|PEXASFBFReflectionAttr
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|PEXASFSurfaceApprox
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|PEXASFSurfaceEdges
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|PEXASFSurfaceEdgeType
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|PEXASFSurfaceEdgeWidth
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|PEXASFSurfaceEdgeColor
value|(1L<<29)
end_define

begin_comment
comment|/*  * resource identifier value when resource is referenced, but freed  */
end_comment

begin_define
define|#
directive|define
name|PEXAlreadyFreed
value|1
end_define

begin_comment
comment|/*  * pipeline context  */
end_comment

begin_comment
comment|/* pipeline context attributes bitmask shift values */
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
name|PEXPCMarkerColor
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
name|PEXPCTextColor
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
name|PEXPCATextHeight
value|13
end_define

begin_define
define|#
directive|define
name|PEXPCATextUpVector
value|14
end_define

begin_define
define|#
directive|define
name|PEXPCATextPath
value|15
end_define

begin_define
define|#
directive|define
name|PEXPCATextAlignment
value|16
end_define

begin_define
define|#
directive|define
name|PEXPCATextStyle
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
name|PEXPCLineColor
value|21
end_define

begin_define
define|#
directive|define
name|PEXPCCurveApprox
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
name|PEXPCSurfaceColor
value|27
end_define

begin_define
define|#
directive|define
name|PEXPCReflectionAttr
value|28
end_define

begin_define
define|#
directive|define
name|PEXPCReflectionModel
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
name|PEXPCBFInteriorStyle
value|31
end_define

begin_define
define|#
directive|define
name|PEXPCBFInteriorStyleIndex
value|32
end_define

begin_define
define|#
directive|define
name|PEXPCBFSurfaceColor
value|33
end_define

begin_define
define|#
directive|define
name|PEXPCBFReflectionAttr
value|34
end_define

begin_define
define|#
directive|define
name|PEXPCBFReflectionModel
value|35
end_define

begin_define
define|#
directive|define
name|PEXPCBFSurfaceInterp
value|36
end_define

begin_define
define|#
directive|define
name|PEXPCSurfaceApprox
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
name|PEXPCPatternRefPoint
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
name|PEXPCSurfaceEdgeColor
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
name|PEXPCASFValues
value|57
end_define

begin_define
define|#
directive|define
name|PEXPCPickID
value|58
end_define

begin_define
define|#
directive|define
name|PEXPCHLHSRIdentifier
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
name|PEXPCColorApproxIndex
value|61
end_define

begin_define
define|#
directive|define
name|PEXPCRenderingColorModel
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
name|PEXPCMaxShift
value|63
end_define

begin_comment
comment|/*  * renderer and renderer picking  */
end_comment

begin_comment
comment|/* renderer state */
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
comment|/* renderer dynamics */
end_comment

begin_define
define|#
directive|define
name|PEXDynamic
value|0
end_define

begin_define
define|#
directive|define
name|PEXNotDynamic
value|1
end_define

begin_comment
comment|/* renderer echo modes */
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
comment|/* renderer attributes bitmask */
end_comment

begin_define
define|#
directive|define
name|PEXRAPipelineContext
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXRACurrentPath
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXRAMarkerBundle
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|PEXRATextBundle
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|PEXRALineBundle
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|PEXRAInteriorBundle
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|PEXRAEdgeBundle
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|PEXRAViewTable
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|PEXRAColorTable
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|PEXRADepthCueTable
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|PEXRALightTable
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|PEXRAColorApproxTable
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|PEXRAPatternTable
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|PEXRATextFontTable
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|PEXRAHighlightIncl
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|PEXRAHighlightExcl
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|PEXRAInvisibilityIncl
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|PEXRAInvisibilityExcl
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|PEXRARendererState
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|PEXRAHLHSRMode
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|PEXRANPCSubVolume
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|PEXRAViewport
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|PEXRAClipList
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|PEXRAPickIncl
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|PEXRAPickExcl
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|PEXRAPickStartPath
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|PEXRABackgroundColor
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|PEXRAClearImage
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|PEXRAClearZ
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|PEXRAEchoMode
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|PEXRAMaxShift
value|29
end_define

begin_comment
comment|/* renderer dynamics bitmask */
end_comment

begin_comment
comment|/*      tables                */
end_comment

begin_define
define|#
directive|define
name|PEXRDTMarkerBundle
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXRDTTextBundle
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXRDTLineBundle
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|PEXRDTInteriorBundle
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|PEXRDTEdgeBundle
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|PEXRDTViewTable
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|PEXRDTColorTable
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|PEXRDTDepthCueTable
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|PEXRDTLightTable
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|PEXRDTColorApproxTable
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|PEXRDTPatternTable
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|PEXRDTTextFontTable
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|PEXRDTMarkerBundleContents
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|PEXRDTTextBundleContents
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|PEXRDTLineBundleContents
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|PEXRDTInteriorBundleContents
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|PEXRDTEdgeBundleContents
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|PEXRDTViewTableContents
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|PEXRDTColorTableContents
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|PEXRDTDepthCueTableContents
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|PEXRDTLightTableContents
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|PEXRDTColorApproxContents
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|PEXRDTPatternTableContents
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|PEXRDTTextFontTableContents
value|(1L<<27)
end_define

begin_comment
comment|/*      name sets              */
end_comment

begin_define
define|#
directive|define
name|PEXRDNHighlightNameSet
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXRDNInvisibilityNameSet
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXRDNPickNameSet
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|PEXRDNHighlightNameSetContents
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|PEXRDNInvisibilityNameSetContents
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|PEXRDNPickNameSetContents
value|(1L<<18)
end_define

begin_comment
comment|/*      attributes            */
end_comment

begin_define
define|#
directive|define
name|PEXRDAHLHSRMode
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXRDANPCSubVolume
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXRDAViewport
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|PEXRDAClipList
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|PEXRDAEchoMode
value|(1L<<4)
end_define

begin_comment
comment|/* renderer pick status */
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
name|PEXPick
value|1
end_define

begin_define
define|#
directive|define
name|PEXAbortedPick
value|2
end_define

begin_comment
comment|/*  * name set  */
end_comment

begin_comment
comment|/* name set changes */
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
comment|/*  * look up table  */
end_comment

begin_comment
comment|/* table types */
end_comment

begin_define
define|#
directive|define
name|PEXLUTLineBundle
value|1
end_define

begin_define
define|#
directive|define
name|PEXLUTMarkerBundle
value|2
end_define

begin_define
define|#
directive|define
name|PEXLUTTextBundle
value|3
end_define

begin_define
define|#
directive|define
name|PEXLUTInteriorBundle
value|4
end_define

begin_define
define|#
directive|define
name|PEXLUTEdgeBundle
value|5
end_define

begin_define
define|#
directive|define
name|PEXLUTPattern
value|6
end_define

begin_define
define|#
directive|define
name|PEXLUTTextFont
value|7
end_define

begin_define
define|#
directive|define
name|PEXLUTColor
value|8
end_define

begin_define
define|#
directive|define
name|PEXLUTView
value|9
end_define

begin_define
define|#
directive|define
name|PEXLUTLight
value|10
end_define

begin_define
define|#
directive|define
name|PEXLUTDepthCue
value|11
end_define

begin_define
define|#
directive|define
name|PEXLUTColorApprox
value|12
end_define

begin_comment
comment|/* status in PEXGetTableEntry */
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
comment|/* return type in PEXGetTableEntry and PEXGetTableEntries */
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
comment|/*  * structure  */
end_comment

begin_comment
comment|/* structure editing mode */
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
comment|/* whence in structure element ranges */
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
comment|/* structure info */
end_comment

begin_define
define|#
directive|define
name|PEXElementPtr
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|PEXNumElements
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|PEXLengthStructure
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|PEXHasRefs
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|PEXEditMode
value|(1L<<4)
end_define

begin_comment
comment|/* structures in network */
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
comment|/* ancestors and descendents*/
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
comment|/* element search */
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
comment|/* element info bitmask */
end_comment

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
comment|/*  * search context  */
end_comment

begin_comment
comment|/* element search status */
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
comment|/* search context attributes bitmask */
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

begin_define
define|#
directive|define
name|PEXSCMaxShift
value|6
end_define

begin_comment
comment|/*  * PHIGS workstation  */
end_comment

begin_comment
comment|/* workstation update state */
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
comment|/* workstation visual state */
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
comment|/* workstation display state */
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
comment|/* workstation buffer mode */
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
comment|/* workstation dynamics */
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
comment|/* workstation structure posting priorities */
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
comment|/* workstation attributes bitmask shift values */
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
name|PEXPWWorkstationUpdate
value|5
end_define

begin_define
define|#
directive|define
name|PEXPWReqNPCSubVolume
value|6
end_define

begin_define
define|#
directive|define
name|PEXPWCurNPCSubVolume
value|7
end_define

begin_define
define|#
directive|define
name|PEXPWReqViewport
value|8
end_define

begin_define
define|#
directive|define
name|PEXPWCurViewport
value|9
end_define

begin_define
define|#
directive|define
name|PEXPWHLHSRUpdate
value|10
end_define

begin_define
define|#
directive|define
name|PEXPWReqHLHSRMode
value|11
end_define

begin_define
define|#
directive|define
name|PEXPWCurHLHSRMode
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
name|PEXPWColorTable
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
name|PEXPWColorApproxTable
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
name|PEXPWMaxShift
value|33
end_define

begin_comment
comment|/* values for indices to returned workstation dynamics */
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
name|PEXPWDColorTable
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
name|PEXPWDWorkstationTransform
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
name|PEXPWDHLHSRMode
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
name|PEXPWDColorApproxTable
value|20
end_define

begin_comment
comment|/*  * workstation picking  */
end_comment

begin_comment
comment|/* workstation pick status */
end_comment

begin_comment
comment|/* PEXNoPick                       defined the same as for renderer pick */
end_comment

begin_comment
comment|/* PEXPick                         defined the same as for renderer pick */
end_comment

begin_comment
comment|/* pick echo modes */
end_comment

begin_comment
comment|/* PEXNoEcho                       defined the same as for renderer echo */
end_comment

begin_comment
comment|/* PEXEcho                         defined the same as for renderer echo */
end_comment

begin_comment
comment|/* pick path order */
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
comment|/* pick all, more hits flag */
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
comment|/* workstation pick device attributes bitmask */
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
name|PEXPDPromptEchoType
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|PEXPDEchoVolume
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|PEXPDEchoSwitch
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|PEXPDMaxShift
value|8
end_define

begin_comment
comment|/* workstation pick measure attributes bitmask */
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

begin_define
define|#
directive|define
name|PEXPMMaxShift
value|1
end_define

begin_comment
comment|/*  * events  */
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
name|PEXMaxEvent
value|0
end_define

begin_comment
comment|/*  * errors  */
end_comment

begin_define
define|#
directive|define
name|BadPEXColorType
value|0
end_define

begin_define
define|#
directive|define
name|BadPEXRendererState
value|1
end_define

begin_define
define|#
directive|define
name|BadPEXFloatingPointFormat
value|2
end_define

begin_define
define|#
directive|define
name|BadPEXLabel
value|3
end_define

begin_define
define|#
directive|define
name|BadPEXLookupTable
value|4
end_define

begin_define
define|#
directive|define
name|BadPEXNameSet
value|5
end_define

begin_define
define|#
directive|define
name|BadPEXPath
value|6
end_define

begin_define
define|#
directive|define
name|BadPEXFont
value|7
end_define

begin_define
define|#
directive|define
name|BadPEXWorkstation
value|8
end_define

begin_define
define|#
directive|define
name|BadPEXPickMeasure
value|9
end_define

begin_define
define|#
directive|define
name|BadPEXPipelineContext
value|10
end_define

begin_define
define|#
directive|define
name|BadPEXRenderer
value|11
end_define

begin_define
define|#
directive|define
name|BadPEXSearchContext
value|12
end_define

begin_define
define|#
directive|define
name|BadPEXStructure
value|13
end_define

begin_define
define|#
directive|define
name|BadPEXOutputCommand
value|14
end_define

begin_define
define|#
directive|define
name|PEXMaxError
value|14
end_define

begin_comment
comment|/*  * protocol output command codes  */
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
name|PEXOCMarkerColorIndex
value|3
end_define

begin_define
define|#
directive|define
name|PEXOCMarkerColor
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
name|PEXOCTextColorIndex
value|10
end_define

begin_define
define|#
directive|define
name|PEXOCTextColor
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
name|PEXOCATextHeight
value|16
end_define

begin_define
define|#
directive|define
name|PEXOCATextUpVector
value|17
end_define

begin_define
define|#
directive|define
name|PEXOCATextPath
value|18
end_define

begin_define
define|#
directive|define
name|PEXOCATextAlignment
value|19
end_define

begin_define
define|#
directive|define
name|PEXOCATextStyle
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
name|PEXOCLineColorIndex
value|24
end_define

begin_define
define|#
directive|define
name|PEXOCLineColor
value|25
end_define

begin_define
define|#
directive|define
name|PEXOCCurveApprox
value|26
end_define

begin_define
define|#
directive|define
name|PEXOCPolylineInterpMethod
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
name|PEXOCSurfaceColorIndex
value|31
end_define

begin_define
define|#
directive|define
name|PEXOCSurfaceColor
value|32
end_define

begin_define
define|#
directive|define
name|PEXOCReflectionAttributes
value|33
end_define

begin_define
define|#
directive|define
name|PEXOCReflectionModel
value|34
end_define

begin_define
define|#
directive|define
name|PEXOCSurfaceInterpMethod
value|35
end_define

begin_define
define|#
directive|define
name|PEXOCBFInteriorStyle
value|36
end_define

begin_define
define|#
directive|define
name|PEXOCBFInteriorStyleIndex
value|37
end_define

begin_define
define|#
directive|define
name|PEXOCBFSurfaceColorIndex
value|38
end_define

begin_define
define|#
directive|define
name|PEXOCBFSurfaceColor
value|39
end_define

begin_define
define|#
directive|define
name|PEXOCBFReflectionAttributes
value|40
end_define

begin_define
define|#
directive|define
name|PEXOCBFReflectionModel
value|41
end_define

begin_define
define|#
directive|define
name|PEXOCBFSurfaceInterpMethod
value|42
end_define

begin_define
define|#
directive|define
name|PEXOCSurfaceApprox
value|43
end_define

begin_define
define|#
directive|define
name|PEXOCFacetCullingMode
value|44
end_define

begin_define
define|#
directive|define
name|PEXOCFacetDistinguishFlag
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
name|PEXOCPatternAttributes2D
value|47
end_define

begin_define
define|#
directive|define
name|PEXOCPatternAttributes
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
name|PEXOCSurfaceEdgeColorIndex
value|53
end_define

begin_define
define|#
directive|define
name|PEXOCSurfaceEdgeColor
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
name|PEXOCIndividualASF
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
name|PEXOCModelClipFlag
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
name|PEXOCRestoreModelClipVolume
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
name|PEXOCLightSourceState
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
name|PEXOCPickID
value|68
end_define

begin_define
define|#
directive|define
name|PEXOCHLHSRID
value|69
end_define

begin_define
define|#
directive|define
name|PEXOCColorApproxIndex
value|70
end_define

begin_define
define|#
directive|define
name|PEXOCRenderingColorModel
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
name|PEXOCGSE
value|78
end_define

begin_define
define|#
directive|define
name|PEXOCMarkers
value|79
end_define

begin_define
define|#
directive|define
name|PEXOCMarkers2D
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
name|PEXOCPolylineSetWithData
value|87
end_define

begin_define
define|#
directive|define
name|PEXOCNURBCurve
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
name|PEXOCFillAreaWithData
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
name|PEXOCFillAreaSetWithData
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
name|PEXOCSetOfFillAreaSets
value|97
end_define

begin_define
define|#
directive|define
name|PEXOCNURBSurface
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
name|PEXOCExtendedCellArray
value|101
end_define

begin_define
define|#
directive|define
name|PEXOCGDP
value|102
end_define

begin_define
define|#
directive|define
name|PEXOCGDP2D
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
name|PEXOCNil
value|0xffff
end_define

begin_comment
comment|/*  * protocol request codes  */
end_comment

begin_define
define|#
directive|define
name|PEXRCGetExtensionInfo
value|1
end_define

begin_define
define|#
directive|define
name|PEXRCGetEnumTypeInfo
value|2
end_define

begin_define
define|#
directive|define
name|PEXRCGetImpDepConstants
value|3
end_define

begin_define
define|#
directive|define
name|PEXRCCreateLookupTable
value|4
end_define

begin_define
define|#
directive|define
name|PEXRCCopyLookupTable
value|5
end_define

begin_define
define|#
directive|define
name|PEXRCFreeLookupTable
value|6
end_define

begin_define
define|#
directive|define
name|PEXRCGetTableInfo
value|7
end_define

begin_define
define|#
directive|define
name|PEXRCGetPredefinedEntries
value|8
end_define

begin_define
define|#
directive|define
name|PEXRCGetDefinedIndices
value|9
end_define

begin_define
define|#
directive|define
name|PEXRCGetTableEntry
value|10
end_define

begin_define
define|#
directive|define
name|PEXRCGetTableEntries
value|11
end_define

begin_define
define|#
directive|define
name|PEXRCSetTableEntries
value|12
end_define

begin_define
define|#
directive|define
name|PEXRCDeleteTableEntries
value|13
end_define

begin_define
define|#
directive|define
name|PEXRCCreatePipelineContext
value|14
end_define

begin_define
define|#
directive|define
name|PEXRCCopyPipelineContext
value|15
end_define

begin_define
define|#
directive|define
name|PEXRCFreePipelineContext
value|16
end_define

begin_define
define|#
directive|define
name|PEXRCGetPipelineContext
value|17
end_define

begin_define
define|#
directive|define
name|PEXRCChangePipelineContext
value|18
end_define

begin_define
define|#
directive|define
name|PEXRCCreateRenderer
value|19
end_define

begin_define
define|#
directive|define
name|PEXRCFreeRenderer
value|20
end_define

begin_define
define|#
directive|define
name|PEXRCChangeRenderer
value|21
end_define

begin_define
define|#
directive|define
name|PEXRCGetRendererAttributes
value|22
end_define

begin_define
define|#
directive|define
name|PEXRCGetRendererDynamics
value|23
end_define

begin_define
define|#
directive|define
name|PEXRCBeginRendering
value|24
end_define

begin_define
define|#
directive|define
name|PEXRCEndRendering
value|25
end_define

begin_define
define|#
directive|define
name|PEXRCBeginStructure
value|26
end_define

begin_define
define|#
directive|define
name|PEXRCEndStructure
value|27
end_define

begin_define
define|#
directive|define
name|PEXRCRenderOutputCommands
value|28
end_define

begin_define
define|#
directive|define
name|PEXRCRenderNetwork
value|29
end_define

begin_define
define|#
directive|define
name|PEXRCCreateStructure
value|30
end_define

begin_define
define|#
directive|define
name|PEXRCCopyStructure
value|31
end_define

begin_define
define|#
directive|define
name|PEXRCDestroyStructures
value|32
end_define

begin_define
define|#
directive|define
name|PEXRCGetStructureInfo
value|33
end_define

begin_define
define|#
directive|define
name|PEXRCGetElementInfo
value|34
end_define

begin_define
define|#
directive|define
name|PEXRCGetStructuresInNetwork
value|35
end_define

begin_define
define|#
directive|define
name|PEXRCGetAncestors
value|36
end_define

begin_define
define|#
directive|define
name|PEXRCGetDescendants
value|37
end_define

begin_define
define|#
directive|define
name|PEXRCFetchElements
value|38
end_define

begin_define
define|#
directive|define
name|PEXRCSetEditingMode
value|39
end_define

begin_define
define|#
directive|define
name|PEXRCSetElementPointer
value|40
end_define

begin_define
define|#
directive|define
name|PEXRCSetElementPointerAtLabel
value|41
end_define

begin_define
define|#
directive|define
name|PEXRCElementSearch
value|42
end_define

begin_define
define|#
directive|define
name|PEXRCStoreElements
value|43
end_define

begin_define
define|#
directive|define
name|PEXRCDeleteElements
value|44
end_define

begin_define
define|#
directive|define
name|PEXRCDeleteElementsToLabel
value|45
end_define

begin_define
define|#
directive|define
name|PEXRCDeleteBetweenLabels
value|46
end_define

begin_define
define|#
directive|define
name|PEXRCCopyElements
value|47
end_define

begin_define
define|#
directive|define
name|PEXRCChangeStructureRefs
value|48
end_define

begin_define
define|#
directive|define
name|PEXRCCreateNameSet
value|49
end_define

begin_define
define|#
directive|define
name|PEXRCCopyNameSet
value|50
end_define

begin_define
define|#
directive|define
name|PEXRCFreeNameSet
value|51
end_define

begin_define
define|#
directive|define
name|PEXRCGetNameSet
value|52
end_define

begin_define
define|#
directive|define
name|PEXRCChangeNameSet
value|53
end_define

begin_define
define|#
directive|define
name|PEXRCCreateSearchContext
value|54
end_define

begin_define
define|#
directive|define
name|PEXRCCopySearchContext
value|55
end_define

begin_define
define|#
directive|define
name|PEXRCFreeSearchContext
value|56
end_define

begin_define
define|#
directive|define
name|PEXRCGetSearchContext
value|57
end_define

begin_define
define|#
directive|define
name|PEXRCChangeSearchContext
value|58
end_define

begin_define
define|#
directive|define
name|PEXRCSearchNetwork
value|59
end_define

begin_define
define|#
directive|define
name|PEXRCCreateWorkstation
value|60
end_define

begin_define
define|#
directive|define
name|PEXRCFreeWorkstation
value|61
end_define

begin_define
define|#
directive|define
name|PEXRCGetWorkstationAttributes
value|62
end_define

begin_define
define|#
directive|define
name|PEXRCGetWorkstationDynamics
value|63
end_define

begin_define
define|#
directive|define
name|PEXRCGetWorkstationViewRep
value|64
end_define

begin_define
define|#
directive|define
name|PEXRCRedrawAllStructures
value|65
end_define

begin_define
define|#
directive|define
name|PEXRCUpdateWorkstation
value|66
end_define

begin_define
define|#
directive|define
name|PEXRCRedrawClipRegion
value|67
end_define

begin_define
define|#
directive|define
name|PEXRCExecuteDeferredActions
value|68
end_define

begin_define
define|#
directive|define
name|PEXRCSetWorkstationViewPriority
value|69
end_define

begin_define
define|#
directive|define
name|PEXRCSetWorkstationDisplayUpdateMode
value|70
end_define

begin_define
define|#
directive|define
name|PEXRCMapDCtoWC
value|71
end_define

begin_define
define|#
directive|define
name|PEXRCMapWCtoDC
value|72
end_define

begin_define
define|#
directive|define
name|PEXRCSetWorkstationViewRep
value|73
end_define

begin_define
define|#
directive|define
name|PEXRCSetWorkstationWindow
value|74
end_define

begin_define
define|#
directive|define
name|PEXRCSetWorkstationViewport
value|75
end_define

begin_define
define|#
directive|define
name|PEXRCSetWorkstationHLHSRMode
value|76
end_define

begin_define
define|#
directive|define
name|PEXRCSetWorkstationBufferMode
value|77
end_define

begin_define
define|#
directive|define
name|PEXRCPostStructure
value|78
end_define

begin_define
define|#
directive|define
name|PEXRCUnpostStructure
value|79
end_define

begin_define
define|#
directive|define
name|PEXRCUnpostAllStructures
value|80
end_define

begin_define
define|#
directive|define
name|PEXRCGetWorkstationPostings
value|81
end_define

begin_define
define|#
directive|define
name|PEXRCGetPickDevice
value|82
end_define

begin_define
define|#
directive|define
name|PEXRCChangePickDevice
value|83
end_define

begin_define
define|#
directive|define
name|PEXRCCreatePickMeasure
value|84
end_define

begin_define
define|#
directive|define
name|PEXRCFreePickMeasure
value|85
end_define

begin_define
define|#
directive|define
name|PEXRCGetPickMeasure
value|86
end_define

begin_define
define|#
directive|define
name|PEXRCUpdatePickMeasure
value|87
end_define

begin_define
define|#
directive|define
name|PEXRCLoadFont
value|88
end_define

begin_define
define|#
directive|define
name|PEXRCUnloadFont
value|89
end_define

begin_define
define|#
directive|define
name|PEXRCQueryFont
value|90
end_define

begin_define
define|#
directive|define
name|PEXRCListFonts
value|91
end_define

begin_define
define|#
directive|define
name|PEXRCListFontsWithInfo
value|92
end_define

begin_define
define|#
directive|define
name|PEXRCQueryTextExtents
value|93
end_define

begin_define
define|#
directive|define
name|PEXRCMatchRenderingTargets
value|94
end_define

begin_define
define|#
directive|define
name|PEXRCEscape
value|95
end_define

begin_define
define|#
directive|define
name|PEXRCEscapeWithReply
value|96
end_define

begin_define
define|#
directive|define
name|PEXRCRenderElements
value|97
end_define

begin_define
define|#
directive|define
name|PEXRCAccumulateState
value|98
end_define

begin_define
define|#
directive|define
name|PEXRCBeginPickOne
value|99
end_define

begin_define
define|#
directive|define
name|PEXRCEndPickOne
value|100
end_define

begin_define
define|#
directive|define
name|PEXRCPickOne
value|101
end_define

begin_define
define|#
directive|define
name|PEXRCBeginPickAll
value|102
end_define

begin_define
define|#
directive|define
name|PEXRCEndPickAll
value|103
end_define

begin_define
define|#
directive|define
name|PEXRCPickAll
value|104
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PEX_H */
end_comment

end_unit

