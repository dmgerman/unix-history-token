begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)setwarp.c	5.3 (Berkeley) 6/18/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"trek.h"
end_include

begin_include
include|#
directive|include
file|"getpar.h"
end_include

begin_comment
comment|/* **  SET WARP FACTOR ** **	The warp factor is set for future move commands.  It is **	checked for consistancy. */
end_comment

begin_macro
name|setwarp
argument_list|()
end_macro

begin_block
block|{
name|double
name|warpfac
decl_stmt|;
name|warpfac
operator|=
name|getfltpar
argument_list|(
literal|"Warp factor"
argument_list|)
expr_stmt|;
if|if
condition|(
name|warpfac
operator|<
literal|0.0
condition|)
return|return;
if|if
condition|(
name|warpfac
operator|<
literal|1.0
condition|)
return|return
operator|(
name|printf
argument_list|(
literal|"Minimum warp speed is 1.0\n"
argument_list|)
operator|)
return|;
if|if
condition|(
name|warpfac
operator|>
literal|10.0
condition|)
return|return
operator|(
name|printf
argument_list|(
literal|"Maximum speed is warp 10.0\n"
argument_list|)
operator|)
return|;
if|if
condition|(
name|warpfac
operator|>
literal|6.0
condition|)
name|printf
argument_list|(
literal|"Damage to warp engines may occur above warp 6.0\n"
argument_list|)
expr_stmt|;
name|Ship
operator|.
name|warp
operator|=
name|warpfac
expr_stmt|;
name|Ship
operator|.
name|warp2
operator|=
name|Ship
operator|.
name|warp
operator|*
name|warpfac
expr_stmt|;
name|Ship
operator|.
name|warp3
operator|=
name|Ship
operator|.
name|warp2
operator|*
name|warpfac
expr_stmt|;
block|}
end_block

end_unit

