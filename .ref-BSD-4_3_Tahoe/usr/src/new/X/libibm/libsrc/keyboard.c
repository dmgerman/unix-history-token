begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_keyboard_c
init|=
literal|"$Header: keyboard.c,v 10.1 86/11/19 10:42:06 jg Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/* Copyright 1985 Massachusetts Institute of Technology */
end_comment

begin_comment
comment|/* keyboard.c - key code processing routine  *  *	ProcessInput	matches RT/PC keyboard codes to  *			to LK201 (DEC) codes.  *  *	Author:  *  *		Scott Bates  *		Brown University  *		IRIS, Box 1946  *		Providence, RI 02912  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
end_comment

begin_include
include|#
directive|include
file|"private.h"
end_include

begin_include
include|#
directive|include
file|"keymatch.h"
end_include

begin_expr_stmt
name|ProcessInput
argument_list|(
name|ev
argument_list|)
specifier|register
name|vsEvent
operator|*
name|ev
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
name|ev
operator|->
name|vse_device
operator|==
name|VSE_DKB
condition|)
block|{
specifier|register
name|int
name|vse_key
init|=
operator|(
operator|(
name|int
operator|)
name|ev
operator|->
name|vse_key
operator|)
operator|&
literal|0xFF
decl_stmt|;
if|if
condition|(
operator|(
name|vse_key
operator|>=
literal|0
operator|)
operator|&&
operator|(
name|vse_key
operator|<=
name|RTPC_CODES
operator|)
condition|)
name|ev
operator|->
name|vse_key
operator|=
name|keymatch
index|[
name|vse_key
index|]
expr_stmt|;
block|}
name|Deal_with_input
argument_list|(
name|ev
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

end_unit

