begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005, 2007, 2009, 2014  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: lib.c,v 1.16 2009/09/02 23:48:02 tbox Exp $ */
end_comment

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<isc/app.h>
end_include

begin_include
include|#
directive|include
file|<isc/lib.h>
end_include

begin_include
include|#
directive|include
file|<isc/mem.h>
end_include

begin_include
include|#
directive|include
file|<isc/msgs.h>
end_include

begin_include
include|#
directive|include
file|<isc/once.h>
end_include

begin_include
include|#
directive|include
file|<isc/socket.h>
end_include

begin_include
include|#
directive|include
file|<isc/task.h>
end_include

begin_include
include|#
directive|include
file|<isc/timer.h>
end_include

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_comment
comment|/***  *** Globals  ***/
end_comment

begin_decl_stmt
name|LIBISC_EXTERNAL_DATA
name|isc_msgcat_t
modifier|*
name|isc_msgcat
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***  *** Private  ***/
end_comment

begin_decl_stmt
specifier|static
name|isc_once_t
name|msgcat_once
init|=
name|ISC_ONCE_INIT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function
specifier|static
name|void
name|open_msgcat
parameter_list|(
name|void
parameter_list|)
block|{
name|isc_msgcat_open
argument_list|(
literal|"libisc.cat"
argument_list|,
operator|&
name|isc_msgcat
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|isc_lib_initmsgcat
parameter_list|(
name|void
parameter_list|)
block|{
name|isc_result_t
name|result
decl_stmt|;
comment|/*! 	 * Initialize the ISC library's message catalog, isc_msgcat, if it 	 * has not already been initialized. 	 */
name|result
operator|=
name|isc_once_do
argument_list|(
operator|&
name|msgcat_once
argument_list|,
name|open_msgcat
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|!=
name|ISC_R_SUCCESS
condition|)
block|{
comment|/* 		 * Normally we'd use RUNTIME_CHECK() or FATAL_ERROR(), but 		 * we can't do that here, since they might call us! 		 * (Note that the catalog might be open anyway, so we might 		 * as well try to  provide an internationalized message.) 		 */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s:%d: %s: isc_once_do() %s.\n"
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|,
name|isc_msgcat_get
argument_list|(
name|isc_msgcat
argument_list|,
name|ISC_MSGSET_GENERAL
argument_list|,
name|ISC_MSG_FATALERROR
argument_list|,
literal|"fatal error"
argument_list|)
argument_list|,
name|isc_msgcat_get
argument_list|(
name|isc_msgcat
argument_list|,
name|ISC_MSGSET_GENERAL
argument_list|,
name|ISC_MSG_FAILED
argument_list|,
literal|"failed"
argument_list|)
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|BIND9
end_ifndef

begin_decl_stmt
specifier|static
name|isc_once_t
name|register_once
init|=
name|ISC_ONCE_INIT
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|do_register
parameter_list|(
name|void
parameter_list|)
block|{
name|RUNTIME_CHECK
argument_list|(
name|isc__mem_register
argument_list|()
operator|==
name|ISC_R_SUCCESS
argument_list|)
expr_stmt|;
name|RUNTIME_CHECK
argument_list|(
name|isc__app_register
argument_list|()
operator|==
name|ISC_R_SUCCESS
argument_list|)
expr_stmt|;
name|RUNTIME_CHECK
argument_list|(
name|isc__task_register
argument_list|()
operator|==
name|ISC_R_SUCCESS
argument_list|)
expr_stmt|;
name|RUNTIME_CHECK
argument_list|(
name|isc__socket_register
argument_list|()
operator|==
name|ISC_R_SUCCESS
argument_list|)
expr_stmt|;
name|RUNTIME_CHECK
argument_list|(
name|isc__timer_register
argument_list|()
operator|==
name|ISC_R_SUCCESS
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|isc_lib_register
parameter_list|(
name|void
parameter_list|)
block|{
name|RUNTIME_CHECK
argument_list|(
name|isc_once_do
argument_list|(
operator|&
name|register_once
argument_list|,
name|do_register
argument_list|)
operator|==
name|ISC_R_SUCCESS
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

