begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)globals.c	8.1 (Berkeley) 6/6/93"
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

