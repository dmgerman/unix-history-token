begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hp specific additions to standard mfb.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HPPRIV_H_
end_ifndef

begin_define
define|#
directive|define
name|_HPPRIV_H_
end_define

begin_include
include|#
directive|include
file|"hpOScrnBuf.h"
end_include

begin_comment
comment|/* Pixmap stuff */
end_comment

begin_define
define|#
directive|define
name|PIXMAP_HOST_MEMORY
value|1
end_define

begin_define
define|#
directive|define
name|PIXMAP_FRAME_BUFFER
value|2
end_define

begin_comment
comment|/* private field of pixmap */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|pointer
name|bits
decl_stmt|;
name|short
name|stride
decl_stmt|;
comment|/* width of the pixmap in bytes */
name|hpChunk
modifier|*
name|pChunk
decl_stmt|;
comment|/* description of off-screen memory (if used) */
block|}
name|hpPrivPixmap
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|hpPrivPixmap
modifier|*
name|hpPrivPixmapPtr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|getPrivPixmapPtr
parameter_list|(
name|pSrc
parameter_list|)
define|\
value|((hpPrivPixmapPtr)(((PixmapPtr)pSrc)->devPrivate.ptr))
end_define

begin_comment
comment|/* private field of screen. */
end_comment

begin_comment
comment|/*  * Parameters for the two functions in the structure are as  * follows:  *   (*MaskConfig)(pScreen, writeEnableMask, replacementRule);  *   (*MoveBits)(pScreen, planeMask, replacementRule, sourceX, sourceY,  *   		destX, destY, width, height);  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|pointer
name|bits
decl_stmt|;
name|short
name|stride
decl_stmt|;
name|DrawablePtr
name|pDrawable
decl_stmt|;
name|pointer
name|pHardwareScreen
decl_stmt|;
name|void
function_decl|(
modifier|*
name|MoveBits
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|MaskConfig
function_decl|)
parameter_list|()
function_decl|;
comment|/* cursor stuff */
name|void
argument_list|(
operator|*
name|MoveMouse
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|CursorOff
argument_list|)
argument_list|()
decl_stmt|;
name|short
name|int
name|hoffX
decl_stmt|,
name|hoffY
decl_stmt|,
comment|/* offset of hot spot in cursor rectangle */
name|width
decl_stmt|,
name|height
decl_stmt|,
comment|/* of cursor rectangle */
name|ssaveX
decl_stmt|,
name|ssaveY
decl_stmt|,
comment|/* where to save screen covered by cursor */
name|srcX
decl_stmt|,
name|srcY
decl_stmt|,
comment|/* cursor source */
name|maskX
decl_stmt|,
name|maskY
decl_stmt|,
comment|/* cursor mask */
name|w
decl_stmt|,
name|h
decl_stmt|;
comment|/* chunk of cursor thats on screen */
name|BoxRec
name|saved
decl_stmt|;
comment|/* coords of cursor rectangle */
name|unsigned
name|char
name|cstate
decl_stmt|;
comment|/* cursor state */
define|#
directive|define
name|CURSOR_OFF
value|0
define|#
directive|define
name|CURSOR_ON
value|1
name|Bool
function_decl|(
modifier|*
name|CloseScreen
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|GetImage
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|GetSpans
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|SourceValidate
function_decl|)
parameter_list|()
function_decl|;
name|Bool
function_decl|(
modifier|*
name|CreateGC
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|InstallColormap
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|StoreColors
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|PaintWindowBackground
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|PaintWindowBorder
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|CopyWindow
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|ClearToBackground
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|SaveDoomedAreas
function_decl|)
parameter_list|()
function_decl|;
name|RegionPtr
function_decl|(
modifier|*
name|RestoreAreas
function_decl|)
parameter_list|()
function_decl|;
name|ColormapPtr
name|pInstalledMap
decl_stmt|;
comment|/* end of cursor stuff */
name|unsigned
name|char
name|planesMask
decl_stmt|;
comment|/* allow two heads to work on same hardware (e.g. da Vinci) */
name|void
function_decl|(
modifier|*
name|ChangeScreen
function_decl|)
parameter_list|()
function_decl|;
name|Bool
name|isBlank
decl_stmt|,
name|isSaved
decl_stmt|;
name|pointer
name|pBufAllocInfo
decl_stmt|;
name|pointer
name|pTmpPixmap
decl_stmt|;
comment|/* scratch off-screen Pixmap used by cfb code */
name|void
function_decl|(
modifier|*
name|WholeGlyph
function_decl|)
parameter_list|()
function_decl|;
comment|/* output entire glyph to offscreen mem */
name|short
name|memHeight
decl_stmt|;
name|short
name|memWidth
decl_stmt|;
name|short
name|fd
decl_stmt|;
name|short
name|gcid
decl_stmt|;
name|unsigned
name|long
name|minor_num
decl_stmt|;
name|int
name|fbOffset
decl_stmt|;
name|Bool
name|screenBlanked
decl_stmt|;
block|}
name|hpPrivScreen
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|hpPrivScreen
modifier|*
name|hpPrivScreenPtr
typedef|;
end_typedef

begin_comment
comment|/* size of scratch pixmap in off-screen memory. */
end_comment

begin_define
define|#
directive|define
name|PRIV_PIX_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|PRIV_PIX_HEIGHT
value|32
end_define

begin_define
define|#
directive|define
name|getPrivScreenPtr
parameter_list|(
name|pScreen
parameter_list|)
define|\
value|((hpPrivScreenPtr)((pScreen)->devPrivate))
end_define

begin_define
define|#
directive|define
name|getPlanesMask
parameter_list|(
name|pScreen
parameter_list|)
value|(getPrivScreenPtr(pScreen)->planesMask)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|WAIT_READY_TO_RENDER
end_ifndef

begin_define
define|#
directive|define
name|WAIT_READY_TO_RENDER
parameter_list|(
name|pScreen
parameter_list|)
define|\
value|(*(getPrivScreenPtr(pScreen)->MoveBits)) \         (pScreen, 0, GXnoop, 0, 0, 0, 0, 0, 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SET_REGISTERS_FOR_WRITING
end_ifndef

begin_define
define|#
directive|define
name|SET_REGISTERS_FOR_WRITING
parameter_list|(
name|pScreen
parameter_list|,
name|writeEnableMask
parameter_list|,
name|replacementRule
parameter_list|)
define|\
value|(*(getPrivScreenPtr(pScreen)->MaskConfig)) \         ((pScreen), (writeEnableMask), (replacementRule))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _HPPRIV_H_ */
end_comment

end_unit

