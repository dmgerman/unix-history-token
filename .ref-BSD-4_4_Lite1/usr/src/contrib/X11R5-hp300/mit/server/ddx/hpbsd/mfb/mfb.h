begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Combined Purdue/PurduePlus patches, level 2.0, 1/17/89 */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/* $XConsortium: mfb.h,v 5.15 91/04/10 11:43:42 keith Exp $ */
end_comment

begin_comment
comment|/* Monochrome Frame Buffer definitions     written by drewry, september 1986 */
end_comment

begin_include
include|#
directive|include
file|"pixmap.h"
end_include

begin_include
include|#
directive|include
file|"region.h"
end_include

begin_include
include|#
directive|include
file|"gc.h"
end_include

begin_include
include|#
directive|include
file|"colormap.h"
end_include

begin_include
include|#
directive|include
file|"miscstruct.h"
end_include

begin_include
include|#
directive|include
file|"mibstore.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|InverseAlu
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Bool
name|mfbScreenInit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|mfbCloseScreen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|mfbCreateDefColormap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbQueryBestSize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|mfbCreateWindow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|mfbPositionWindow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|mfbChangeWindowAttributes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|mfbMapWindow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|mfbUnmapWindow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|mfbDestroyWindow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|mfbRealizeFont
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|mfbUnrealizeFont
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|mfbScreenSaver
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|mfbCreateGC
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mfbReduceRop
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|mfbValidateGC
argument_list|()
decl_stmt|,
name|mfbChangeGC
argument_list|()
decl_stmt|,
name|mfbCopyGC
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|mfbDestroyGC
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|mfbChangeClip
argument_list|()
decl_stmt|,
name|mfbDestroyClip
argument_list|()
decl_stmt|,
name|mfbCopyClip
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|PixmapPtr
name|mfbCreatePixmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|mfbDestroyPixmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbCopyWindow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbSaveAreas
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbRestoreAreas
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* window painter */
end_comment

begin_function_decl
specifier|extern
name|void
name|mfbPaintWindow
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* rectangle painters */
end_comment

begin_function_decl
specifier|extern
name|void
name|mfbSolidWhiteArea
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbStippleWhiteArea
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbSolidBlackArea
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbStippleBlackArea
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbSolidInvertArea
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbStippleInvertArea
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbTileArea32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbPolyFillRect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|RegionPtr
name|mfbCopyArea
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbPolyPoint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|RegionPtr
name|mfbCopyPlane
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbPolyFillArcSolid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbSetSpans
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbGetSpans
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbWhiteSolidFS
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbBlackSolidFS
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbInvertSolidFS
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbWhiteStippleFS
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbBlackStippleFS
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbInvertStippleFS
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbTileFS
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbUnnaturalTileFS
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbUnnaturalStippleFS
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbGetImage
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbPutImage
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbLineSS
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* solid single-pixel wide line */
end_comment

begin_comment
comment|/* calls mfb{Bres|Horz|Vert}S() */
end_comment

begin_function_decl
specifier|extern
name|void
name|mfbLineSD
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbSegmentSS
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbSegmentSD
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbZeroPolyArcSS
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbImageText8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbImageText16
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mfbPolyText16
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mfbPolyText8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|PixmapPtr
name|mfbCopyPixmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|RegionPtr
name|mfbPixmapToRegion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbSolidPP
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbPushPixels
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* text for glyphs<= 32 bits wide */
end_comment

begin_function_decl
specifier|extern
name|void
name|mfbImageGlyphBltWhite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbImageGlyphBltBlack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbPolyGlyphBltWhite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbPolyGlyphBltBlack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbPolyGlyphBltInvert
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* text for terminal emulator fonts */
end_comment

begin_function_decl
specifier|extern
name|void
name|mfbTEGlyphBltWhite
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* fg = 1, bg = 0 */
end_comment

begin_function_decl
specifier|extern
name|void
name|mfbTEGlyphBltBlack
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* fg = 0, bg = 1 */
end_comment

begin_function_decl
specifier|extern
name|int
name|mfbListInstalledColormaps
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbInstallColormap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbUninstallColormap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|mfbCreateColormap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbDestroyColormap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbResolveColor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbCopyGCDest
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbCopyRotatePixmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbYRotatePixmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbXRotatePixmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfbPadPixmap
parameter_list|()
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"../include/hppriv.h"
end_include

begin_comment
comment|/*    private filed of pixmap    pixmap.devPrivate = (unsigned int *)pointer_to_bits    pixmap.devKind = width_of_pixmap_in_bytes     private field of screen    a pixmap, for which we allocate storage.  devPrivate is a pointer to the bits in the hardware framebuffer.  note that devKind can be poked to make the code work for framebuffers that are wider than their displayable screen (e.g. the early vsII, which displayed 960 pixels across, but was 1024 in the hardware.)     private field of GC  	Freeing pCompositeClip is done based on the value of freeCompClip; if freeCompClip is not carefully maintained, we will end up losing storage or freeing something that isn't ours. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|rop
decl_stmt|;
comment|/* reduction of rasterop to 1 of 3 */
name|unsigned
name|char
name|ropOpStip
decl_stmt|;
comment|/* rop for opaque stipple */
name|unsigned
name|char
name|ropFillArea
decl_stmt|;
comment|/*  == alu, rop, or ropOpStip */
name|unsigned
name|fExpose
range|:
literal|1
decl_stmt|;
comment|/* callexposure handling ? */
name|unsigned
name|freeCompClip
range|:
literal|1
decl_stmt|;
name|PixmapPtr
name|pRotatedPixmap
decl_stmt|;
comment|/* tile/stipple rotated to align */
name|RegionPtr
name|pCompositeClip
decl_stmt|;
comment|/* free this based on freeCompClip 					   flag rather than NULLness */
name|void
function_decl|(
modifier|*
name|FillArea
function_decl|)
parameter_list|()
function_decl|;
comment|/* fills regions; look at the code */
block|}
name|mfbPrivGC
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|mfbPrivGC
modifier|*
name|mfbPrivGCPtr
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|mfbGCPrivateIndex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index into GC private array */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mfbWindowPrivateIndex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index into Window private array */
end_comment

begin_comment
comment|/* private field of window */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|fastBorder
decl_stmt|;
comment|/* non-zero if border tile is 32 bits wide */
name|unsigned
name|char
name|fastBackground
decl_stmt|;
name|unsigned
name|short
name|unused
decl_stmt|;
comment|/* pad for alignment with Sun compiler */
name|DDXPointRec
name|oldRotate
decl_stmt|;
name|PixmapPtr
name|pRotatedBackground
decl_stmt|;
name|PixmapPtr
name|pRotatedBorder
decl_stmt|;
block|}
name|mfbPrivWin
typedef|;
end_typedef

begin_comment
comment|/* Common macros for extracting drawing information */
end_comment

begin_define
define|#
directive|define
name|mfbGetTypedWidth
parameter_list|(
name|pDrawable
parameter_list|,
name|type
parameter_list|)
value|(\     (((pDrawable)->type == DRAWABLE_WINDOW) ? \      (int) (((PixmapPtr)((pDrawable)->pScreen->devPrivate))->devKind) : \      (int)(((PixmapPtr)pDrawable)->devKind)) / sizeof (type))
end_define

begin_define
define|#
directive|define
name|mfbGetByteWidth
parameter_list|(
name|pDrawable
parameter_list|)
value|cbGetTypedWidth(pDrawable, char)
end_define

begin_define
define|#
directive|define
name|mfbGetLongWidth
parameter_list|(
name|pDrawable
parameter_list|)
value|cbGetTypedWidth(pDrawable, long)
end_define

begin_define
define|#
directive|define
name|mfbGetTypedWidthAndPointer
parameter_list|(
name|pDrawable
parameter_list|,
name|width
parameter_list|,
name|pointer
parameter_list|,
name|wtype
parameter_list|,
name|ptype
parameter_list|)
value|{\     PixmapPtr   _pPix; \     if ((pDrawable)->type == DRAWABLE_WINDOW) \ 	_pPix = (PixmapPtr) (pDrawable)->pScreen->devPrivate; \     else \ 	_pPix = (PixmapPtr) (pDrawable); \     (pointer) = (ptype *) _pPix->devPrivate.ptr; \     (width) = ((int) _pPix->devKind) / sizeof (wtype); \ }
end_define

begin_define
define|#
directive|define
name|mfbGetByteWidthAndPointer
parameter_list|(
name|pDrawable
parameter_list|,
name|width
parameter_list|,
name|pointer
parameter_list|)
define|\
value|mfbGetTypedWidthAndPointer(pDrawable, width, pointer, char, char)
end_define

begin_define
define|#
directive|define
name|mfbGetLongWidthAndPointer
parameter_list|(
name|pDrawable
parameter_list|,
name|width
parameter_list|,
name|pointer
parameter_list|)
define|\
value|mfbGetTypedWidthAndPointer(pDrawable, width, pointer, unsigned long, unsigned long)
end_define

begin_define
define|#
directive|define
name|mfbGetWindowTypedWidthAndPointer
parameter_list|(
name|pWin
parameter_list|,
name|width
parameter_list|,
name|pointer
parameter_list|,
name|wtype
parameter_list|,
name|ptype
parameter_list|)
value|{\     PixmapPtr	_pPix = (PixmapPtr) (pWin)->drawable.pScreen->devPrivate; \     (pointer) = (ptype *) _pPix->devPrivate.ptr; \     (width) = ((int) _pPix->devKind) / sizeof (wtype); \ }
end_define

begin_define
define|#
directive|define
name|mfbGetWindowLongWidthAndPointer
parameter_list|(
name|pWin
parameter_list|,
name|width
parameter_list|,
name|pointer
parameter_list|)
define|\
value|mfbGetWindowTypedWidthAndPointer(pWin, width, pointer, unsigned long, unsigned long)
end_define

begin_define
define|#
directive|define
name|mfbGetWindowByteWidthAndPointer
parameter_list|(
name|pWin
parameter_list|,
name|width
parameter_list|,
name|pointer
parameter_list|)
define|\
value|mfbGetWindowTypedWidthAndPointer(pWin, width, pointer, char, char)
end_define

begin_comment
comment|/* precomputed information about each glyph for GlyphBlt code.    this saves recalculating the per glyph information for each box. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_pos
block|{
name|int
name|xpos
decl_stmt|;
comment|/* xposition of glyph's origin */
name|int
name|xchar
decl_stmt|;
comment|/* x position mod 32 */
name|int
name|leftEdge
decl_stmt|;
name|int
name|rightEdge
decl_stmt|;
name|int
name|topEdge
decl_stmt|;
name|int
name|bottomEdge
decl_stmt|;
name|unsigned
name|int
modifier|*
name|pdstBase
decl_stmt|;
comment|/* longword with character origin */
name|int
name|widthGlyph
decl_stmt|;
comment|/* width in bytes of this glyph */
block|}
name|TEXTPOS
typedef|;
end_typedef

begin_comment
comment|/* reduced raster ops for mfb */
end_comment

begin_define
define|#
directive|define
name|RROP_BLACK
value|GXclear
end_define

begin_define
define|#
directive|define
name|RROP_WHITE
value|GXset
end_define

begin_define
define|#
directive|define
name|RROP_NOP
value|GXnoop
end_define

begin_define
define|#
directive|define
name|RROP_INVERT
value|GXinvert
end_define

begin_comment
comment|/* out of clip region codes */
end_comment

begin_define
define|#
directive|define
name|OUT_LEFT
value|0x08
end_define

begin_define
define|#
directive|define
name|OUT_RIGHT
value|0x04
end_define

begin_define
define|#
directive|define
name|OUT_ABOVE
value|0x02
end_define

begin_define
define|#
directive|define
name|OUT_BELOW
value|0x01
end_define

begin_comment
comment|/* major axis for bresenham's line */
end_comment

begin_define
define|#
directive|define
name|X_AXIS
value|0
end_define

begin_define
define|#
directive|define
name|Y_AXIS
value|1
end_define

begin_comment
comment|/* macros for mfbbitblt.c, mfbfillsp.c    these let the code do one switch on the rop per call, rather than a switch on the rop per item (span or rectangle.) */
end_comment

begin_define
define|#
directive|define
name|fnCLEAR
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|fnAND
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(src& dst)
end_define

begin_define
define|#
directive|define
name|fnANDREVERSE
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(src& ~dst)
end_define

begin_define
define|#
directive|define
name|fnCOPY
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(src)
end_define

begin_define
define|#
directive|define
name|fnANDINVERTED
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(~src& dst)
end_define

begin_define
define|#
directive|define
name|fnNOOP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(dst)
end_define

begin_define
define|#
directive|define
name|fnXOR
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(src ^ dst)
end_define

begin_define
define|#
directive|define
name|fnOR
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(src | dst)
end_define

begin_define
define|#
directive|define
name|fnNOR
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(~(src | dst))
end_define

begin_define
define|#
directive|define
name|fnEQUIV
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(~src ^ dst)
end_define

begin_define
define|#
directive|define
name|fnINVERT
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(~dst)
end_define

begin_define
define|#
directive|define
name|fnORREVERSE
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(src | ~dst)
end_define

begin_define
define|#
directive|define
name|fnCOPYINVERTED
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(~src)
end_define

begin_define
define|#
directive|define
name|fnORINVERTED
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(~src | dst)
end_define

begin_define
define|#
directive|define
name|fnNAND
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(~(src& dst))
end_define

begin_define
define|#
directive|define
name|fnSET
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|(~0)
end_define

begin_comment
comment|/*  Using a "switch" statement is much faster in most cases  *  since the compiler can do a look-up table or multi-way branch  *  instruction, depending on the architecture.  The result on  *  A Sun 3/50 is at least 2.5 times faster, assuming a uniform  *  distribution of RasterOp operation types.  *  *  However, doing some profiling on a running system reveals  *  GXcopy is the operation over 99.5% of the time and  *  GXxor is the next most frequent (about .4%), so we make special  *  checks for those first.  *  *  Note that this requires a change to the "calling sequence"  *  since we can't engineer a "switch" statement to have an lvalue.  */
end_comment

begin_define
define|#
directive|define
name|DoRop
parameter_list|(
name|result
parameter_list|,
name|alu
parameter_list|,
name|src
parameter_list|,
name|dst
parameter_list|)
define|\
value|{ \     if (alu == GXcopy) \ 	result = fnCOPY (src, dst); \     else if (alu == GXxor) \         result = fnXOR (src, dst); \     else \ 	switch (alu) \ 	{ \ 	  case GXclear: \ 	    result = fnCLEAR (src, dst); \ 	    break; \ 	  case GXand: \ 	    result = fnAND (src, dst); \ 	    break; \ 	  case GXandReverse: \ 	    result = fnANDREVERSE (src, dst); \ 	    break; \ 	  case GXandInverted: \ 	    result = fnANDINVERTED (src, dst); \ 	    break; \ 	  case GXnoop: \ 	    result = fnNOOP (src, dst); \ 	    break; \ 	  case GXor: \ 	    result = fnOR (src, dst); \ 	    break; \ 	  case GXnor: \ 	    result = fnNOR (src, dst); \ 	    break; \ 	  case GXequiv: \ 	    result = fnEQUIV (src, dst); \ 	    break; \ 	  case GXinvert: \ 	    result = fnINVERT (src, dst); \ 	    break; \ 	  case GXorReverse: \ 	    result = fnORREVERSE (src, dst); \ 	    break; \ 	  case GXcopyInverted: \ 	    result = fnCOPYINVERTED (src, dst); \ 	    break; \ 	  case GXorInverted: \ 	    result = fnORINVERTED (src, dst); \ 	    break; \ 	  case GXnand: \ 	    result = fnNAND (src, dst); \ 	    break; \ 	  case GXset: \ 	    result = fnSET (src, dst); \ 	    break; \ 	} \ }
end_define

end_unit

