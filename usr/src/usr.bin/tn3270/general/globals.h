begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)globals.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_comment
comment|/*  *	This file contains all the globals used by tn3270.  *  *	Since various files may want to reference this file,  *	and since they may only want subsets of the globals,  *	we assume they have #include'd all the other .h files  *	first, and we only give those globals relevant to  *	the #include'd .h files.  *  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEFINING_INSTANCES
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTERN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXTERN
name|int
comment|/* 		 * shell_active ==> 		 *		1.  Don't do input. 		 *		2.  Don't do output. 		 *		3.  Don't block in select. 		 *		4.  When nothing to do, call shell_continue() 		 */
name|shell_active
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INCLUDED_OPTIONS
argument_list|)
end_if

begin_decl_stmt
name|EXTERN
name|int
name|OptHome
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where home should send us */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|OptLeftMargin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where new line should send us */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|OptColTabs
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local tab stops */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|OptAPLmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|OptNullProcessing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* improved null processing */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|OptZonesMode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* zones mode off */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|OptEnterNL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* regular enter/new line keys */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|OptColFieldTab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* regular column/field tab keys */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|OptPacing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do pacing */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|OptAlphaInNumeric
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* allow alpha in numeric fields */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|OptHome
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|OptLeftMargin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|OptWordWrap
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INCLUDED_SCREEN
argument_list|)
end_if

begin_decl_stmt
name|EXTERN
name|ScreenImage
name|Host
index|[
name|MAXSCREENSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* host view of screen */
end_comment

begin_decl_stmt
name|EXTERN
name|char
name|Orders
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Non-zero for orders */
end_comment

begin_comment
comment|/* Run-time screen geometry */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|MaxNumberLines
decl_stmt|,
comment|/* How many rows the 3270 COULD have */
name|MaxNumberColumns
decl_stmt|,
comment|/* How many columns the 3270 COULD have */
name|NumberLines
decl_stmt|,
comment|/* How many lines the 3270 screen contains */
name|NumberColumns
decl_stmt|,
comment|/* How many columns the 3270 screen contains */
name|ScreenSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|CursorAddress
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where cursor is */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|BufferAddress
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where writes are going */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|Lowest
decl_stmt|,
name|Highest
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|CIABuffer
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|UnLocked
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* is the keyboard unlocked */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|AidByte
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INCLUDED_STATE
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INCLUDED_OIA
argument_list|)
end_if

begin_decl_stmt
name|EXTERN
name|OIA
name|OperatorInformationArea
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|oia_modified
decl_stmt|,
comment|/* Has the oia been modified */
name|ps_modified
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Has the presentation space been modified */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(INCLUDED_OIA) */
end_comment

end_unit

