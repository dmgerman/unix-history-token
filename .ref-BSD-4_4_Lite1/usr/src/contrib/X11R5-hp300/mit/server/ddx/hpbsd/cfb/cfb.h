begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************ Copyright 1987 by Sun Microsystems, Inc. Mountain View, CA.                      All Rights Reserved  Permission  to  use,  copy,  modify,  and  distribute   this software  and  its documentation for any purpose and without fee is hereby granted, provided that the above copyright no- tice  appear  in all copies and that both that copyright no- tice and this permission notice appear in  supporting  docu- mentation,  and  that the names of Sun or MIT not be used in advertising or publicity pertaining to distribution  of  the software  without specific prior written permission. Sun and M.I.T. make no representations about the suitability of this software for any purpose. It is provided "as is" without any express or implied warranty.  SUN DISCLAIMS ALL WARRANTIES WITH REGARD TO  THIS  SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FIT- NESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL SUN BE  LI- ABLE  FOR  ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,  DATA  OR PROFITS,  WHETHER  IN  AN  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ********************************************************/
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
file|"servermd.h"
end_include

begin_include
include|#
directive|include
file|"mfb.h"
end_include

begin_function_decl
specifier|extern
name|Bool
name|cfbScreenInit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbQueryBestSize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|cfbCreateWindow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|cfbPositionWindow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|cfbChangeWindowAttributes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|cfbMapWindow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|cfbUnmapWindow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|cfbDestroyWindow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|cfbRealizeFont
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|cfbUnrealizeFont
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|cfbRealizeCursor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|cfbUnrealizeCursor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|cfbScreenSaver
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|cfbCreateGC
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|PixmapPtr
name|cfbCreatePixmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|cfbDestroyPixmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbCopyWindow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbPaintWindow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|miPolyFillRect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbPolyFillRect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|miPolyFillArc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|cfbZeroPolyArcSS8Copy
argument_list|()
decl_stmt|,
name|cfbZeroPolyArcSS8Xor
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|cfbZeroPolyArcSS8General
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|cfbLineSS
argument_list|()
decl_stmt|,
name|cfbLineSD
argument_list|()
decl_stmt|,
name|cfbSegmentSS
argument_list|()
decl_stmt|,
name|cfbSegmentSD
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cfb8LineSS1Rect
argument_list|()
decl_stmt|,
name|cfb8SegmentSS1Rect
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|RegionPtr
name|cfbCopyPlane
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|cfbPolyFillArcSolidCopy
argument_list|()
decl_stmt|,
name|cfbPolyFillArcSolidXor
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|cfbPolyFillArcSolidGeneral
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|RegionPtr
name|cfbCopyArea
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|cfbFillPoly1RectCopy
argument_list|()
decl_stmt|,
name|cfbFillPoly1RectGeneral
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|cfbPushPixels8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbSetSpans
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbGetSpans
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|cfbSolidSpansCopy
argument_list|()
decl_stmt|,
name|cfbSolidSpansXor
argument_list|()
decl_stmt|,
name|cfbSolidSpansGeneral
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|cfbUnnaturalTileFS
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbUnnaturalStippleFS
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|cfbTile32FSCopy
argument_list|()
decl_stmt|,
name|cfbTile32FSGeneral
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cfb8Stipple32FS
argument_list|()
decl_stmt|,
name|cfb8OpaqueStipple32FS
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|cfbFillBoxTileOdd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbFillBoxTile32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbFillBoxSolid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbTEGlyphBlt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbTEGlyphBlt8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbPolyGlyphBlt8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbPolyGlyphRop8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbImageGlyphBlt8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbSaveAreas
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbRestoreAreas
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* included from mfb.h; we can't include mfb.h directly because of other   * conflicts */
end_comment

begin_function_decl
specifier|extern
name|void
name|mfbPushPixels
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
name|void
name|mfbQueryBestSize
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
name|mfbCopyRotatePixmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|PixmapPtr
name|cfbCopyPixmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbConvertRects
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|miPolyArc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|miFillPolyArc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbPutImage
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbGetImage
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|RegionPtr
name|miCopyArea
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|RegionPtr
name|miCopyPlane
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbPolyPoint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|miPushPixels
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|STATIC_COLOR
end_ifdef

begin_function_decl
specifier|extern
name|void
name|cfbInstallColormap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbUninstallColormap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cfbListInstalledColormaps
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|cfbResolveColor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|cfbInitializeColormap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|cfbCreateDefColormap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbCopyRotatePixmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbYRotatePixmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbXRotatePixmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cfbPadPixmap
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*    private filed of pixmap    pixmap.devPrivate = (unsigned int *)pointer_to_bits    pixmap.devKind = width_of_pixmap_in_bytes */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cfbGCPrivateIndex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cfbWindowPrivateIndex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* private field of GC */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|rop
decl_stmt|;
comment|/* special case rop values */
comment|/* next two values unused in cfb, included for compatibility with mfb */
name|unsigned
name|char
name|ropOpStip
decl_stmt|;
comment|/* rop for opaque stipple */
comment|/* this value is ropFillArea in mfb, usurped for cfb */
name|unsigned
name|char
name|oneRect
decl_stmt|;
comment|/*  drawable has one clip rect */
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
name|RegionPtr
name|pCompositeClip
decl_stmt|;
comment|/* FREE_CC or REPLACE_CC */
name|unsigned
name|long
name|xor
decl_stmt|,
name|and
decl_stmt|;
comment|/* reduced rop values */
block|}
name|cfbPrivGC
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cfbPrivGC
modifier|*
name|cfbPrivGCPtr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|cfbGetGCPrivate
parameter_list|(
name|pGC
parameter_list|)
value|((cfbPrivGCPtr)\ 	(pGC)->devPrivates[cfbGCPrivateIndex].ptr)
end_define

begin_comment
comment|/* way to carry RROP info around */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|rop
decl_stmt|;
name|unsigned
name|long
name|xor
decl_stmt|,
name|and
decl_stmt|;
block|}
name|cfbRRopRec
operator|,
typedef|*
name|cfbRRopPtr
typedef|;
end_typedef

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
comment|/* non-zero if border is 32 bits wide */
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
name|cfbPrivWin
typedef|;
end_typedef

begin_comment
comment|/* Common macros for extracting drawing information */
end_comment

begin_define
define|#
directive|define
name|cfbGetTypedWidth
parameter_list|(
name|pDrawable
parameter_list|,
name|wtype
parameter_list|)
value|(\     (((pDrawable)->type == DRAWABLE_WINDOW) ? \      (int) getPrivScreenPtr((pDrawable)->pScreen)->stride : \      (int) getPrivPixmapPtr(pDrawable)->stride / sizeof (wtype))
end_define

begin_define
define|#
directive|define
name|cfbGetByteWidth
parameter_list|(
name|pDrawable
parameter_list|)
value|cfbGetTypedWidth(pDrawable, unsigned char)
end_define

begin_define
define|#
directive|define
name|cfbGetLongWidth
parameter_list|(
name|pDrawable
parameter_list|)
value|cfbGetTypedWidth(pDrawable, unsigned long)
end_define

begin_define
define|#
directive|define
name|cfbGetTypedWidthAndPointer
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
value|{\     if ((pDrawable)->type == DRAWABLE_WINDOW) \     {\ 	(pointer) = (ptype *) getPrivScreenPtr((pDrawable)->pScreen)->bits; \ 	(width) = ((int) getPrivScreenPtr((pDrawable)->pScreen)->stride) / sizeof (wtype); \     }\     else \     {\ 	(pointer) = (ptype *) getPrivPixmapPtr(pDrawable)->bits; \ 	(width) = ((int) getPrivPixmapPtr(pDrawable)->stride) / sizeof (wtype); \     }\ }
end_define

begin_define
define|#
directive|define
name|cfbGetByteWidthAndPointer
parameter_list|(
name|pDrawable
parameter_list|,
name|width
parameter_list|,
name|pointer
parameter_list|)
define|\
value|cfbGetTypedWidthAndPointer(pDrawable, width, pointer, unsigned char, unsigned char)
end_define

begin_define
define|#
directive|define
name|cfbGetLongWidthAndPointer
parameter_list|(
name|pDrawable
parameter_list|,
name|width
parameter_list|,
name|pointer
parameter_list|)
define|\
value|cfbGetTypedWidthAndPointer(pDrawable, width, pointer, unsigned long, unsigned long)
end_define

begin_define
define|#
directive|define
name|cfbGetWindowTypedWidthAndPointer
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
value|{\     hpPrivScreenPtr	_pPix = (hpPrivScreenPtr) (pWin)->drawable.pScreen->devPrivate; \     (pointer) = (ptype *) _pPix->bits; \     (width) = ((int) _pPix->stride) / sizeof (wtype); \ }
end_define

begin_define
define|#
directive|define
name|cfbGetWindowLongWidthAndPointer
parameter_list|(
name|pWin
parameter_list|,
name|width
parameter_list|,
name|pointer
parameter_list|)
define|\
value|cfbGetWindowTypedWidthAndPointer(pWin, width, pointer, unsigned long, unsigned long)
end_define

begin_define
define|#
directive|define
name|cfbGetWindowByteWidthAndPointer
parameter_list|(
name|pWin
parameter_list|,
name|width
parameter_list|,
name|pointer
parameter_list|)
define|\
value|cfbGetWindowTypedWidthAndPointer(pWin, width, pointer, unsigned char, unsigned char)
end_define

begin_comment
comment|/* Macros which handle a coordinate in a single register */
end_comment

begin_comment
comment|/* Most compilers will convert divide by 65536 into a shift, if signed  * shifts exist.  If your machine does arithmetic shifts and your compiler  * can't get it right, add to this line.  */
end_comment

begin_comment
comment|/* mips compiler - what a joke - it CSEs the 65536 constant into a reg  * forcing as to use div instead of shift.  Let's be explicit.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|mips
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
end_if

begin_define
define|#
directive|define
name|GetHighWord
parameter_list|(
name|x
parameter_list|)
value|(((int) (x))>> 16)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GetHighWord
parameter_list|(
name|x
parameter_list|)
value|(((int) (x)) / 65536)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|IMAGE_BYTE_ORDER
operator|==
name|MSBFirst
end_if

begin_define
define|#
directive|define
name|intToCoord
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x) = GetHighWord(i)), ((y) = (int) ((short) (i))))
end_define

begin_define
define|#
directive|define
name|coordToInt
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)<< 16) | (y))
end_define

begin_define
define|#
directive|define
name|intToX
parameter_list|(
name|i
parameter_list|)
value|(GetHighWord(i))
end_define

begin_define
define|#
directive|define
name|intToY
parameter_list|(
name|i
parameter_list|)
value|((int) ((short) i))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|intToCoord
parameter_list|(
name|i
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x) = (int) ((short) (i))), ((y) = GetHighWord(i)))
end_define

begin_define
define|#
directive|define
name|coordToInt
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((y)<< 16) | (x))
end_define

begin_define
define|#
directive|define
name|intToX
parameter_list|(
name|i
parameter_list|)
value|((int) ((short) (i)))
end_define

begin_define
define|#
directive|define
name|intToY
parameter_list|(
name|i
parameter_list|)
value|(GetHighWord(i))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

