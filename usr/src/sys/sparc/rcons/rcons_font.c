begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)rcons_font.c	7.4 (Berkeley) %G%  *  * from: $Header: rcons_font.c,v 1.10 93/04/20 11:15:38 torek Exp $  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/fbio.h>
end_include

begin_include
include|#
directive|include
file|<sys/device.h>
end_include

begin_include
include|#
directive|include
file|<machine/fbvar.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"myfbdevice.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sparc/rcons/raster.h>
end_include

begin_include
include|#
directive|include
file|<sparc/rcons/gallant19.h>
end_include

begin_function
name|void
name|rcons_font
parameter_list|(
name|fb
parameter_list|)
specifier|register
name|struct
name|fbdevice
modifier|*
name|fb
decl_stmt|;
block|{
comment|/* XXX really rather get this from the prom */
name|fb
operator|->
name|fb_font
operator|=
operator|&
name|gallant19
expr_stmt|;
comment|/* Get distance to top and bottom of font from font origin */
name|fb
operator|->
name|fb_font_ascent
operator|=
operator|-
operator|(
name|fb
operator|->
name|fb_font
operator|->
name|chars
operator|)
index|[
literal|'a'
index|]
operator|.
name|homey
expr_stmt|;
block|}
end_function

end_unit

