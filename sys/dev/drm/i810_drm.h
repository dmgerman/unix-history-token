begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I810_DRM_H_
end_ifndef

begin_define
define|#
directive|define
name|_I810_DRM_H_
end_define

begin_comment
comment|/* WARNING: These defines must be the same as what the Xserver uses.  * if you change them, you must change the defines in the Xserver.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I810_DEFINES_
end_ifndef

begin_define
define|#
directive|define
name|_I810_DEFINES_
end_define

begin_define
define|#
directive|define
name|I810_DMA_BUF_ORDER
value|12
end_define

begin_define
define|#
directive|define
name|I810_DMA_BUF_SZ
value|(1<<I810_DMA_BUF_ORDER)
end_define

begin_define
define|#
directive|define
name|I810_DMA_BUF_NR
value|256
end_define

begin_define
define|#
directive|define
name|I810_NR_SAREA_CLIPRECTS
value|8
end_define

begin_comment
comment|/* Each region is a minimum of 64k, and there are at most 64 of them.  */
end_comment

begin_define
define|#
directive|define
name|I810_NR_TEX_REGIONS
value|64
end_define

begin_define
define|#
directive|define
name|I810_LOG_MIN_TEX_REGION_SIZE
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|I810_UPLOAD_TEX0IMAGE
value|0x1
end_define

begin_comment
comment|/* handled clientside */
end_comment

begin_define
define|#
directive|define
name|I810_UPLOAD_TEX1IMAGE
value|0x2
end_define

begin_comment
comment|/* handled clientside */
end_comment

begin_define
define|#
directive|define
name|I810_UPLOAD_CTX
value|0x4
end_define

begin_define
define|#
directive|define
name|I810_UPLOAD_BUFFERS
value|0x8
end_define

begin_define
define|#
directive|define
name|I810_UPLOAD_TEX0
value|0x10
end_define

begin_define
define|#
directive|define
name|I810_UPLOAD_TEX1
value|0x20
end_define

begin_define
define|#
directive|define
name|I810_UPLOAD_CLIPRECTS
value|0x40
end_define

begin_comment
comment|/* Indices into buf.Setup where various bits of state are mirrored per  * context and per buffer.  These can be fired at the card as a unit,  * or in a piecewise fashion as required.  */
end_comment

begin_comment
comment|/* Destbuffer state   *    - backbuffer linear offset and pitch -- invarient in the current dri  *    - zbuffer linear offset and pitch -- also invarient  *    - drawing origin in back and depth buffers.  *  * Keep the depth/back buffer state here to acommodate private buffers  * in the future.  */
end_comment

begin_define
define|#
directive|define
name|I810_DESTREG_DI0
value|0
end_define

begin_comment
comment|/* CMD_OP_DESTBUFFER_INFO (2 dwords) */
end_comment

begin_define
define|#
directive|define
name|I810_DESTREG_DI1
value|1
end_define

begin_define
define|#
directive|define
name|I810_DESTREG_DV0
value|2
end_define

begin_comment
comment|/* GFX_OP_DESTBUFFER_VARS (2 dwords) */
end_comment

begin_define
define|#
directive|define
name|I810_DESTREG_DV1
value|3
end_define

begin_define
define|#
directive|define
name|I810_DESTREG_DR0
value|4
end_define

begin_comment
comment|/* GFX_OP_DRAWRECT_INFO (4 dwords) */
end_comment

begin_define
define|#
directive|define
name|I810_DESTREG_DR1
value|5
end_define

begin_define
define|#
directive|define
name|I810_DESTREG_DR2
value|6
end_define

begin_define
define|#
directive|define
name|I810_DESTREG_DR3
value|7
end_define

begin_define
define|#
directive|define
name|I810_DESTREG_DR4
value|8
end_define

begin_define
define|#
directive|define
name|I810_DEST_SETUP_SIZE
value|10
end_define

begin_comment
comment|/* Context state  */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_CF0
value|0
end_define

begin_comment
comment|/* GFX_OP_COLOR_FACTOR */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_CF1
value|1
end_define

begin_define
define|#
directive|define
name|I810_CTXREG_ST0
value|2
end_define

begin_comment
comment|/* GFX_OP_STIPPLE */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_ST1
value|3
end_define

begin_define
define|#
directive|define
name|I810_CTXREG_VF
value|4
end_define

begin_comment
comment|/* GFX_OP_VERTEX_FMT */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_MT
value|5
end_define

begin_comment
comment|/* GFX_OP_MAP_TEXELS */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_MC0
value|6
end_define

begin_comment
comment|/* GFX_OP_MAP_COLOR_STAGES - stage 0 */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_MC1
value|7
end_define

begin_comment
comment|/* GFX_OP_MAP_COLOR_STAGES - stage 1 */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_MC2
value|8
end_define

begin_comment
comment|/* GFX_OP_MAP_COLOR_STAGES - stage 2 */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_MA0
value|9
end_define

begin_comment
comment|/* GFX_OP_MAP_ALPHA_STAGES - stage 0 */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_MA1
value|10
end_define

begin_comment
comment|/* GFX_OP_MAP_ALPHA_STAGES - stage 1 */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_MA2
value|11
end_define

begin_comment
comment|/* GFX_OP_MAP_ALPHA_STAGES - stage 2 */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_SDM
value|12
end_define

begin_comment
comment|/* GFX_OP_SRC_DEST_MONO */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_FOG
value|13
end_define

begin_comment
comment|/* GFX_OP_FOG_COLOR */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_B1
value|14
end_define

begin_comment
comment|/* GFX_OP_BOOL_1 */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_B2
value|15
end_define

begin_comment
comment|/* GFX_OP_BOOL_2 */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_LCS
value|16
end_define

begin_comment
comment|/* GFX_OP_LINEWIDTH_CULL_SHADE_MODE */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_PV
value|17
end_define

begin_comment
comment|/* GFX_OP_PV_RULE -- Invarient! */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_ZA
value|18
end_define

begin_comment
comment|/* GFX_OP_ZBIAS_ALPHAFUNC */
end_comment

begin_define
define|#
directive|define
name|I810_CTXREG_AA
value|19
end_define

begin_comment
comment|/* GFX_OP_ANTIALIAS */
end_comment

begin_define
define|#
directive|define
name|I810_CTX_SETUP_SIZE
value|20
end_define

begin_comment
comment|/* Texture state (per tex unit)  */
end_comment

begin_define
define|#
directive|define
name|I810_TEXREG_MI0
value|0
end_define

begin_comment
comment|/* GFX_OP_MAP_INFO (4 dwords) */
end_comment

begin_define
define|#
directive|define
name|I810_TEXREG_MI1
value|1
end_define

begin_define
define|#
directive|define
name|I810_TEXREG_MI2
value|2
end_define

begin_define
define|#
directive|define
name|I810_TEXREG_MI3
value|3
end_define

begin_define
define|#
directive|define
name|I810_TEXREG_MF
value|4
end_define

begin_comment
comment|/* GFX_OP_MAP_FILTER */
end_comment

begin_define
define|#
directive|define
name|I810_TEXREG_MLC
value|5
end_define

begin_comment
comment|/* GFX_OP_MAP_LOD_CTL */
end_comment

begin_define
define|#
directive|define
name|I810_TEXREG_MLL
value|6
end_define

begin_comment
comment|/* GFX_OP_MAP_LOD_LIMITS */
end_comment

begin_define
define|#
directive|define
name|I810_TEXREG_MCS
value|7
end_define

begin_comment
comment|/* GFX_OP_MAP_COORD_SETS ??? */
end_comment

begin_define
define|#
directive|define
name|I810_TEX_SETUP_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|I810_FRONT
value|0x1
end_define

begin_define
define|#
directive|define
name|I810_BACK
value|0x2
end_define

begin_define
define|#
directive|define
name|I810_DEPTH
value|0x4
end_define

begin_typedef
typedef|typedef
struct|struct
name|_drm_i810_init
block|{
enum|enum
block|{
name|I810_INIT_DMA
init|=
literal|0x01
block|,
name|I810_CLEANUP_DMA
init|=
literal|0x02
block|}
name|func
enum|;
if|#
directive|if
name|CONFIG_XFREE86_VERSION
operator|<
name|XFREE86_VERSION
argument_list|(
literal|4
operator|,
literal|1
operator|,
literal|0
operator|,
literal|0
argument_list|)
name|int
name|ring_map_idx
decl_stmt|;
name|int
name|buffer_map_idx
decl_stmt|;
else|#
directive|else
name|unsigned
name|int
name|mmio_offset
decl_stmt|;
name|unsigned
name|int
name|buffers_offset
decl_stmt|;
endif|#
directive|endif
name|int
name|sarea_priv_offset
decl_stmt|;
name|unsigned
name|int
name|ring_start
decl_stmt|;
name|unsigned
name|int
name|ring_end
decl_stmt|;
name|unsigned
name|int
name|ring_size
decl_stmt|;
name|unsigned
name|int
name|front_offset
decl_stmt|;
name|unsigned
name|int
name|back_offset
decl_stmt|;
name|unsigned
name|int
name|depth_offset
decl_stmt|;
name|unsigned
name|int
name|w
decl_stmt|;
name|unsigned
name|int
name|h
decl_stmt|;
name|unsigned
name|int
name|pitch
decl_stmt|;
name|unsigned
name|int
name|pitch_bits
decl_stmt|;
block|}
name|drm_i810_init_t
typedef|;
end_typedef

begin_comment
comment|/* Warning: If you change the SAREA structure you must change the Xserver  * structure as well */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_drm_i810_tex_region
block|{
name|unsigned
name|char
name|next
decl_stmt|,
name|prev
decl_stmt|;
comment|/* indices to form a circular LRU  */
name|unsigned
name|char
name|in_use
decl_stmt|;
comment|/* owned by a client, or free? */
name|int
name|age
decl_stmt|;
comment|/* tracked by clients to update local LRU's */
block|}
name|drm_i810_tex_region_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_drm_i810_sarea
block|{
name|unsigned
name|int
name|ContextState
index|[
name|I810_CTX_SETUP_SIZE
index|]
decl_stmt|;
name|unsigned
name|int
name|BufferState
index|[
name|I810_DEST_SETUP_SIZE
index|]
decl_stmt|;
name|unsigned
name|int
name|TexState
index|[
literal|2
index|]
index|[
name|I810_TEX_SETUP_SIZE
index|]
decl_stmt|;
name|unsigned
name|int
name|dirty
decl_stmt|;
name|unsigned
name|int
name|nbox
decl_stmt|;
name|drm_clip_rect_t
name|boxes
index|[
name|I810_NR_SAREA_CLIPRECTS
index|]
decl_stmt|;
comment|/* Maintain an LRU of contiguous regions of texture space.  If 	 * you think you own a region of texture memory, and it has an 	 * age different to the one you set, then you are mistaken and 	 * it has been stolen by another client.  If global texAge 	 * hasn't changed, there is no need to walk the list. 	 * 	 * These regions can be used as a proxy for the fine-grained 	 * texture information of other clients - by maintaining them 	 * in the same lru which is used to age their own textures, 	 * clients have an approximate lru for the whole of global 	 * texture space, and can make informed decisions as to which 	 * areas to kick out.  There is no need to choose whether to 	 * kick out your own texture or someone else's - simply eject 	 * them all in LRU order.   	 */
name|drm_i810_tex_region_t
name|texList
index|[
name|I810_NR_TEX_REGIONS
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Last elt is sentinal */
name|int
name|texAge
decl_stmt|;
comment|/* last time texture was uploaded */
name|int
name|last_enqueue
decl_stmt|;
comment|/* last time a buffer was enqueued */
name|int
name|last_dispatch
decl_stmt|;
comment|/* age of the most recently dispatched buffer */
name|int
name|last_quiescent
decl_stmt|;
comment|/*  */
name|int
name|ctxOwner
decl_stmt|;
comment|/* last context to upload state */
name|int
name|vertex_prim
decl_stmt|;
block|}
name|drm_i810_sarea_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_drm_i810_clear
block|{
name|int
name|clear_color
decl_stmt|;
name|int
name|clear_depth
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
name|drm_i810_clear_t
typedef|;
end_typedef

begin_comment
comment|/* These may be placeholders if we have more cliprects than  * I810_NR_SAREA_CLIPRECTS.  In that case, the client sets discard to  * false, indicating that the buffer will be dispatched again with a  * new set of cliprects.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_drm_i810_vertex
block|{
name|int
name|idx
decl_stmt|;
comment|/* buffer index */
name|int
name|used
decl_stmt|;
comment|/* nr bytes in use */
name|int
name|discard
decl_stmt|;
comment|/* client is finished with the buffer? */
block|}
name|drm_i810_vertex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_drm_i810_copy_t
block|{
name|int
name|idx
decl_stmt|;
comment|/* buffer index */
name|int
name|used
decl_stmt|;
comment|/* nr bytes in use */
name|void
modifier|*
name|address
decl_stmt|;
comment|/* Address to copy from */
block|}
name|drm_i810_copy_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_i810_dma
block|{
name|void
modifier|*
name|virtual
decl_stmt|;
name|int
name|request_idx
decl_stmt|;
name|int
name|request_size
decl_stmt|;
name|int
name|granted
decl_stmt|;
block|}
name|drm_i810_dma_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I810_DRM_H_ */
end_comment

end_unit

