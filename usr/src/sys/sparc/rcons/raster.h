begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to the Computer Systems  * Engineering Group at Lawrence Berkeley Laboratory and to the University  * of California at Berkeley by Jef Poskanzer.  *  * %sccs.include.redist.c%  *  *	@(#)raster.h	7.1 (Berkeley) %G%  *  * from: $Header: raster.h,v 1.14 92/06/17 08:14:43 torek Exp $  */
end_comment

begin_comment
comment|/*  * Simple raster and frame buffer routines.  *  * Currently this set of routines is fairly minimal.  It's enough to  * implement a console terminal emulator on monochrome and pseudocolor  * screens, and that's about it.  *  * Future additions might be other kinds of frame buffers (direct color?),  * lines, dashed lines, three-operand blits (stipples/stencils), etc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RASTER_H_
end_ifndef

begin_define
define|#
directive|define
name|_RASTER_H_
end_define

begin_comment
comment|/* Configurable definitions. */
end_comment

begin_comment
comment|/* CONFIGURE: define or undef for your machine's byte order */
end_comment

begin_define
define|#
directive|define
name|MSBYTE_FIRST
end_define

begin_comment
comment|/* CONFIGURE: define or under for your frame buffer's bit order */
end_comment

begin_define
define|#
directive|define
name|MSBIT_FIRST
end_define

begin_comment
comment|/* CONFIGURE: The text routines can optionally keep a cache of 8-bit ** characters.  This uses about 30K, but makes text on a color screen ** go 3.2 times faster. */
end_comment

begin_undef
undef|#
directive|undef
name|COLORFONT_CACHE
end_undef

begin_comment
comment|/* Definitions. */
end_comment

begin_comment
comment|/* ANSI prototype conditionalizer.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARGS
end_ifndef

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_define
define|#
directive|define
name|ARGS
parameter_list|(
name|alist
parameter_list|)
value|alist
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*__STDC__*/
end_comment

begin_define
define|#
directive|define
name|ARGS
parameter_list|(
name|alist
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__STDC__*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*ARGS*/
end_comment

begin_comment
comment|/* Raster struct. */
end_comment

begin_struct
struct|struct
name|raster
block|{
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* size in pixels */
name|int
name|depth
decl_stmt|;
comment|/* bits per pixel - 1 or 8 */
name|int
name|linelongs
decl_stmt|;
comment|/* longs from one line to the next - for padding */
name|u_long
modifier|*
name|pixels
decl_stmt|;
comment|/* pointer to the actual bits */
name|caddr_t
name|data
decl_stmt|;
comment|/* special pointer for frame buffers and subregions */
block|}
struct|;
end_struct

begin_comment
comment|/* Colormap struct. */
end_comment

begin_struct
struct|struct
name|raster_colormap
block|{
name|int
name|length
decl_stmt|;
name|u_char
modifier|*
name|red
decl_stmt|;
name|u_char
modifier|*
name|grn
decl_stmt|;
name|u_char
modifier|*
name|blu
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Font character struct. */
end_comment

begin_struct
struct|struct
name|raster_char
block|{
name|struct
name|raster
modifier|*
name|r
decl_stmt|;
name|int
name|homex
decl_stmt|,
name|homey
decl_stmt|;
name|int
name|nextx
decl_stmt|,
name|nexty
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|COLORFONT_CACHE
end_ifdef

begin_struct
struct|struct
name|raster_fontcache
block|{
name|struct
name|raster
modifier|*
name|cr
index|[
literal|256
index|]
decl_stmt|;
name|u_char
name|color
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*COLORFONT_CACHE*/
end_comment

begin_comment
comment|/* Font struct. */
end_comment

begin_struct
struct|struct
name|raster_font
block|{
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* nominal character size */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|RASFONT_FIXEDWIDTH
value|0x1
define|#
directive|define
name|RASFONT_NOVERTICALMOVEMENT
value|0x2
name|struct
name|raster_char
name|chars
index|[
literal|256
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|COLORFONT_CACHE
name|struct
name|raster_fontcache
modifier|*
name|cache
decl_stmt|;
endif|#
directive|endif
comment|/*COLORFONT_CACHE*/
block|}
struct|;
end_struct

begin_comment
comment|/* Defines for the raster_op() and raster_text() rop parameter - the bitblit ** operation.  A rop can be some Boolean combination of RAS_SRC and ** RAS_DST.  For instance, just RAS_SRC means copy the source to the ** destination without modification.  RAS_SRC|RAS_DST means "or" the source ** and destination together, while "xor" would be RAS_SRC^RAS_DST.  The ** RAS_NOT macro should be used to express negation - RAS_NOT(RAS_SRC)&RAS_DST ** would "and" the complement of the source with the destination. ** ** Or, you can just use one of the pre-defined ops.  There are only 16 ** possible combinations, so all 16 are defined here. ** ** For color rasters, you specify the color of the operation by simply ** oring RAS_COLOR(color) into the rop. */
end_comment

begin_define
define|#
directive|define
name|RAS_NOT
parameter_list|(
name|op
parameter_list|)
value|( 0xf& ( ~ (op) ) )
end_define

begin_define
define|#
directive|define
name|RAS_CLEAR
value|0x0
end_define

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|RAS_NOTOR
value|0x1
end_define

begin_comment
comment|/* !( src | dst ) */
end_comment

begin_define
define|#
directive|define
name|RAS_NOTSRC_AND_DST
value|0x2
end_define

begin_comment
comment|/* !src& dst */
end_comment

begin_define
define|#
directive|define
name|RAS_INVERTSRC
value|0x3
end_define

begin_comment
comment|/* !src */
end_comment

begin_define
define|#
directive|define
name|RAS_SRC_AND_NOTDST
value|0x4
end_define

begin_comment
comment|/* src& !dst */
end_comment

begin_define
define|#
directive|define
name|RAS_INVERT
value|0x5
end_define

begin_comment
comment|/* !dst */
end_comment

begin_define
define|#
directive|define
name|RAS_XOR
value|0x6
end_define

begin_comment
comment|/* src ^ dst */
end_comment

begin_define
define|#
directive|define
name|RAS_NOTAND
value|0x7
end_define

begin_comment
comment|/* !( src& dst ) */
end_comment

begin_define
define|#
directive|define
name|RAS_AND
value|0x8
end_define

begin_comment
comment|/* src& dst */
end_comment

begin_define
define|#
directive|define
name|RAS_NOTXOR
value|0x9
end_define

begin_comment
comment|/* !( src ^ dst ) */
end_comment

begin_define
define|#
directive|define
name|RAS_DST
value|0xa
end_define

begin_comment
comment|/* dst */
end_comment

begin_define
define|#
directive|define
name|RAS_NOTSRC_OR_DST
value|0xb
end_define

begin_comment
comment|/* !src | dst */
end_comment

begin_define
define|#
directive|define
name|RAS_SRC
value|0xc
end_define

begin_comment
comment|/* src */
end_comment

begin_define
define|#
directive|define
name|RAS_SRC_OR_NOTDST
value|0xd
end_define

begin_comment
comment|/* src | !dst */
end_comment

begin_define
define|#
directive|define
name|RAS_OR
value|0xe
end_define

begin_comment
comment|/* src | dst */
end_comment

begin_define
define|#
directive|define
name|RAS_SET
value|0xf
end_define

begin_comment
comment|/* 1 */
end_comment

begin_define
define|#
directive|define
name|RAS_COLOR
parameter_list|(
name|color
parameter_list|)
value|( ( (color)& 0xff )<< 4 )
end_define

begin_comment
comment|/* Get the op from a rop. */
end_comment

begin_define
define|#
directive|define
name|RAS_GETOP
parameter_list|(
name|op
parameter_list|)
value|( (op)& 0xf )
end_define

begin_comment
comment|/* Get the color from a rop. */
end_comment

begin_define
define|#
directive|define
name|RAS_GETCOLOR
parameter_list|(
name|op
parameter_list|)
value|( ( (op)>> 4 )& 0xff )
end_define

begin_comment
comment|/* Get the longword address of a pixel. */
end_comment

begin_define
define|#
directive|define
name|RAS_ADDR
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|( (r)->pixels + (y) * (r)->linelongs + (x) * (r)->depth / 32 )
end_define

begin_comment
comment|/* Raster routines. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|raster
modifier|*
name|raster_alloc
name|ARGS
argument_list|(
operator|(
name|int
name|width
operator|,
name|int
name|height
operator|,
name|int
name|depth
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocates a raster.  Returns (struct raster*) 0 on failure. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|raster_free
name|ARGS
argument_list|(
operator|(
expr|struct
name|raster
operator|*
name|r
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Frees/closes a raster. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|raster_get
name|ARGS
argument_list|(
operator|(
expr|struct
name|raster
operator|*
name|r
operator|,
name|int
name|x
operator|,
name|int
name|y
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Gets a single pixel from a raster. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|raster_put
name|ARGS
argument_list|(
operator|(
expr|struct
name|raster
operator|*
name|r
operator|,
name|int
name|x
operator|,
name|int
name|y
operator|,
name|int
name|v
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Puts a single pixel into a raster. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|raster
modifier|*
name|raster_subregion
name|ARGS
argument_list|(
operator|(
expr|struct
name|raster
operator|*
name|r
operator|,
name|int
name|x
operator|,
name|int
name|y
operator|,
name|int
name|width
operator|,
name|int
name|height
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Makes a raster that points to a region of another.  Returns ** (struct raster*) 0 on failure. */
end_comment

begin_comment
comment|/* Raster operations.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|raster_op
name|ARGS
argument_list|(
operator|(
expr|struct
name|raster
operator|*
name|dst
operator|,
name|int
name|dx
operator|,
name|int
name|dy
operator|,
name|int
name|w
operator|,
name|int
name|h
operator|,
name|int
name|rop
operator|,
expr|struct
name|raster
operator|*
name|src
operator|,
name|int
name|sx
operator|,
name|int
name|sy
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Performs a bitblit.  Returns 0 on success, -1 on failure.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|raster_op_noclip
name|ARGS
argument_list|(
operator|(
expr|struct
name|raster
operator|*
name|dst
operator|,
name|int
name|dx
operator|,
name|int
name|dy
operator|,
name|int
name|w
operator|,
name|int
name|h
operator|,
name|int
name|rop
operator|,
expr|struct
name|raster
operator|*
name|src
operator|,
name|int
name|sx
operator|,
name|int
name|sy
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bitblit without clipping.  Returns 0 on success, -1 on failure. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|raster_op_nosrc_noclip
name|ARGS
argument_list|(
operator|(
expr|struct
name|raster
operator|*
name|dst
operator|,
name|int
name|dx
operator|,
name|int
name|dy
operator|,
name|int
name|w
operator|,
name|int
name|h
operator|,
name|int
name|rop
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* No-src bitblit without clipping.  Returns 0 on success, -1 on failure. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|raster_replsrc
name|ARGS
argument_list|(
operator|(
expr|struct
name|raster
operator|*
name|dst
operator|,
name|int
name|dx
operator|,
name|int
name|dy
operator|,
name|int
name|w
operator|,
name|int
name|h
operator|,
name|int
name|rop
operator|,
expr|struct
name|raster
operator|*
name|src
operator|,
name|int
name|sx
operator|,
name|int
name|sy
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tiles the src to fit the dst.  Returns 0 on success, -1 on failure.  Only ** implements RAS_SRC. */
end_comment

begin_comment
comment|/* Raster text routines */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|raster_font
modifier|*
name|raster_fontopen
name|ARGS
argument_list|(
operator|(
name|char
operator|*
name|fontname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Opens a font. Returns (struct raster_font*) 0 on failure. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|raster_text
name|ARGS
argument_list|(
operator|(
expr|struct
name|raster
operator|*
name|r
operator|,
name|int
name|x
operator|,
name|int
name|y
operator|,
name|int
name|rop
operator|,
expr|struct
name|raster_font
operator|*
name|rf
operator|,
name|char
operator|*
name|text
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Draws text.  Returns 0 on success, -1 on failure. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|raster_textn
name|ARGS
argument_list|(
operator|(
expr|struct
name|raster
operator|*
name|r
operator|,
name|int
name|x
operator|,
name|int
name|y
operator|,
name|int
name|rop
operator|,
expr|struct
name|raster_font
operator|*
name|rf
operator|,
name|char
operator|*
name|text
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Draws n characters of text.  Returns 0 on success, -1 on failure. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|raster_fontclose
name|ARGS
argument_list|(
operator|(
expr|struct
name|raster_font
operator|*
name|rf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Closes a font. */
end_comment

begin_comment
comment|/* Frame buffer routines. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|raster
modifier|*
name|raster_open
name|ARGS
argument_list|(
operator|(
name|char
operator|*
name|fbname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Opens a frame buffer as a raster.  Returns (struct raster*) 0 on failure. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|raster
modifier|*
name|raster_coloropen
name|ARGS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Opens a color frame buffer if there is one.  Returns (struct raster*) 0 on ** failure. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|raster_video_off
name|ARGS
argument_list|(
operator|(
expr|struct
name|raster
operator|*
name|r
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Blanks the screen.  Returns 0 on success, -1 on failure.  This might ** be implemented as actual video blanking, or it might just load black ** into all colormap entries (and disable further colormap changes). */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|raster_video_on
name|ARGS
argument_list|(
operator|(
expr|struct
name|raster
operator|*
name|r
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Re-enables video.  Returns 0 on success, -1 on failure. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|raster_colormap
modifier|*
name|raster_colormap_alloc
name|ARGS
argument_list|(
operator|(
name|int
name|length
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocates a colormap structure, returns 0 on failure. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|raster_colormap
modifier|*
name|raster_colormap_get
name|ARGS
argument_list|(
operator|(
expr|struct
name|raster
operator|*
name|r
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocates a colormap structure and returns the frame buffer's ** current colormap, or (struct raster_colormap*) 0 on failure.  The raster ** must be one returned by raster_open(), not raster_alloc(). */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|raster_colormap_set
name|ARGS
argument_list|(
operator|(
expr|struct
name|raster
operator|*
name|r
operator|,
expr|struct
name|raster_colormap
operator|*
name|cm
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sets a frame buffer's colormap.  The raster must be one returned ** by raster_open(), not raster_alloc().  Returns 0 on success, -1 on ** failure. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|raster_colormap_free
name|ARGS
argument_list|(
operator|(
expr|struct
name|raster_colormap
operator|*
name|cm
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Frees a colormap. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_RASTER_H_*/
end_comment

end_unit

