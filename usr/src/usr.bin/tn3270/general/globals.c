begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)globals.c	3.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  *	Do the defining instances for the globals of tn3270.  */
end_comment

begin_include
include|#
directive|include
file|"../ctlr/hostctlr.h"
end_include

begin_include
include|#
directive|include
file|"../ctlr/oia.h"
end_include

begin_include
include|#
directive|include
file|"../ctlr/options.h"
end_include

begin_include
include|#
directive|include
file|"../ctlr/screen.h"
end_include

begin_define
define|#
directive|define
name|DEFINING_INSTANCES
end_define

begin_include
include|#
directive|include
file|"globals.h"
end_include

begin_include
include|#
directive|include
file|"../general/general.h"
end_include

begin_comment
comment|/*  * init_system()  *  * Initialize the global values in case of a restart.  */
end_comment

begin_function
name|void
name|init_system
parameter_list|()
block|{
name|OptHome
operator|=
name|OptLeftMargin
operator|=
name|OptAPLmode
operator|=
name|OptNullProcessing
operator|=
literal|0
expr_stmt|;
name|OptZonesMode
operator|=
name|OptEnterNL
operator|=
name|OptColFieldTab
operator|=
name|OptPacing
operator|=
literal|0
expr_stmt|;
name|OptAlphaInNumeric
operator|=
name|OptHome
operator|=
name|OptLeftMargin
operator|=
name|OptWordWrap
operator|=
literal|0
expr_stmt|;
name|ClearArray
argument_list|(
name|Host
argument_list|)
expr_stmt|;
name|CursorAddress
operator|=
name|BufferAddress
operator|=
literal|0
expr_stmt|;
name|Lowest
operator|=
name|Highest
operator|=
literal|0
expr_stmt|;
name|UnLocked
operator|=
name|AidByte
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

