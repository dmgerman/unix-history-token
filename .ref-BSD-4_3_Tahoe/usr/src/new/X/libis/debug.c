begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$Source: /u1/X/libis/RCS/debug.c,v $  *	$Header: debug.c,v 1.1 86/11/17 14:33:35 swick Rel $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_debug_c
init|=
literal|"$Header: debug.c,v 1.1 86/11/17 14:33:35 swick Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_decl_stmt
name|int
name|isi_debug_jnk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* shuts up ranlib complaints*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_include
include|#
directive|include
file|"is-copyright.h"
end_include

begin_comment
comment|/*  *	debug.c		various debugging printf's  *  *	printf_pixmap  *	printf_bitmap  *	printf_clip  *  *	Copyright (c) 1986, Integrated Solutions, Inc.  */
end_comment

begin_include
include|#
directive|include
file|"Xis.h"
end_include

begin_comment
comment|/* debug is used to indicate which debug printf's are turned on. */
end_comment

begin_decl_stmt
name|unsigned
name|long
name|debug
init|=
operator|(
comment|/* enabled printf's */
name|D_None
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* disabled printf's 		    D_Color		| 		    D_PixFill		| 		    D_Pixmaps		| 		    D_TileFill		| 		    D_Bitmaps		| 		    D_CopyArea		| 		    D_Cursor		| 		    D_DrawCurve		| 		    D_Font		| 		    D_FontPixmap	| 		    D_PixFill_data	| 		    D_Text		| 		    D_TileFill_data	|  */
end_comment

begin_macro
name|printf_pixmap
argument_list|(
argument|name
argument_list|,
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PIXMAP
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"%s=0x%x: width=%d, height=%d, refcnt=%d, tile=%d, kind=0x%x, data=0x%x\n"
argument_list|,
name|name
argument_list|,
name|p
argument_list|,
name|p
operator|->
name|width
argument_list|,
name|p
operator|->
name|height
argument_list|,
name|p
operator|->
name|refcnt
argument_list|,
name|p
operator|->
name|tile
argument_list|,
name|p
operator|->
name|kind
argument_list|,
name|p
operator|->
name|data
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|printf_bitmap
argument_list|(
argument|name
argument_list|,
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BITMAP
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"%s=0x%x: width=%d, height=%d, refcnt=%d, kind=0x%x, data=0x%x\n"
argument_list|,
name|name
argument_list|,
name|p
argument_list|,
name|p
operator|->
name|width
argument_list|,
name|p
operator|->
name|height
argument_list|,
name|p
operator|->
name|refcnt
argument_list|,
name|p
operator|->
name|kind
argument_list|,
name|p
operator|->
name|data
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|printf_clip
argument_list|(
argument|name
argument_list|,
argument|clip
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CLIP
name|clip
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"%s left=%d, top=%d, width=%d, height=%d\n"
argument_list|,
name|name
argument_list|,
name|clip
operator|.
name|left
argument_list|,
name|clip
operator|.
name|top
argument_list|,
name|clip
operator|.
name|width
argument_list|,
name|clip
operator|.
name|height
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
endif|DEBUG
end_endif

end_unit

