begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XStoreColor.c,v 10.5 86/04/22 15:25:49 jg Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_include
include|#
directive|include
file|"XlibInternal.h"
end_include

begin_expr_stmt
name|XStoreColor
argument_list|(
name|def
argument_list|)
specifier|register
name|Color
operator|*
name|def
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|Display
modifier|*
name|dpy
decl_stmt|;
specifier|register
name|XReq
modifier|*
name|req
decl_stmt|;
name|ColorDef
name|proto_def
decl_stmt|;
name|GetReq
argument_list|(
name|X_StoreColors
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|req
operator|->
name|params0
operator|=
literal|1
expr_stmt|;
comment|/* just one color to store */
comment|/* Color structure in library uses int for pixel, 	   but protocol's ColorDef wants a short; 	   thus, data must be copied */
name|proto_def
operator|.
name|pixel
operator|=
name|def
operator|->
name|pixel
expr_stmt|;
name|proto_def
operator|.
name|red
operator|=
name|def
operator|->
name|red
expr_stmt|;
name|proto_def
operator|.
name|green
operator|=
name|def
operator|->
name|green
expr_stmt|;
name|proto_def
operator|.
name|blue
operator|=
name|def
operator|->
name|blue
expr_stmt|;
name|Data
argument_list|(
name|dpy
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|proto_def
argument_list|,
sizeof|sizeof
argument_list|(
name|ColorDef
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

