begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: result.c,v 1.56.2.2.8.9 2005/06/09 23:54:30 marka Exp $ */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<isc/lib.h>
end_include

begin_include
include|#
directive|include
file|<isc/msgs.h>
end_include

begin_include
include|#
directive|include
file|<isc/mutex.h>
end_include

begin_include
include|#
directive|include
file|<isc/once.h>
end_include

begin_include
include|#
directive|include
file|<isc/resultclass.h>
end_include

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|resulttable
block|{
name|unsigned
name|int
name|base
decl_stmt|;
name|unsigned
name|int
name|last
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|text
decl_stmt|;
name|isc_msgcat_t
modifier|*
name|msgcat
decl_stmt|;
name|int
name|set
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|struct resulttable
argument_list|)
name|link
expr_stmt|;
block|}
name|resulttable
typedef|;
end_typedef

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|text
index|[
name|ISC_R_NRESULTS
index|]
init|=
block|{
literal|"success"
block|,
comment|/*  0 */
literal|"out of memory"
block|,
comment|/*  1 */
literal|"timed out"
block|,
comment|/*  2 */
literal|"no available threads"
block|,
comment|/*  3 */
literal|"address not available"
block|,
comment|/*  4 */
literal|"address in use"
block|,
comment|/*  5 */
literal|"permission denied"
block|,
comment|/*  6 */
literal|"no pending connections"
block|,
comment|/*  7 */
literal|"network unreachable"
block|,
comment|/*  8 */
literal|"host unreachable"
block|,
comment|/*  9 */
literal|"network down"
block|,
comment|/* 10 */
literal|"host down"
block|,
comment|/* 11 */
literal|"connection refused"
block|,
comment|/* 12 */
literal|"not enough free resources"
block|,
comment|/* 13 */
literal|"end of file"
block|,
comment|/* 14 */
literal|"socket already bound"
block|,
comment|/* 15 */
literal|"reload"
block|,
comment|/* 16 */
literal|"lock busy"
block|,
comment|/* 17 */
literal|"already exists"
block|,
comment|/* 18 */
literal|"ran out of space"
block|,
comment|/* 19 */
literal|"operation canceled"
block|,
comment|/* 20 */
literal|"socket is not bound"
block|,
comment|/* 21 */
literal|"shutting down"
block|,
comment|/* 22 */
literal|"not found"
block|,
comment|/* 23 */
literal|"unexpected end of input"
block|,
comment|/* 24 */
literal|"failure"
block|,
comment|/* 25 */
literal|"I/O error"
block|,
comment|/* 26 */
literal|"not implemented"
block|,
comment|/* 27 */
literal|"unbalanced parentheses"
block|,
comment|/* 28 */
literal|"no more"
block|,
comment|/* 29 */
literal|"invalid file"
block|,
comment|/* 30 */
literal|"bad base64 encoding"
block|,
comment|/* 31 */
literal|"unexpected token"
block|,
comment|/* 32 */
literal|"quota reached"
block|,
comment|/* 33 */
literal|"unexpected error"
block|,
comment|/* 34 */
literal|"already running"
block|,
comment|/* 35 */
literal|"ignore"
block|,
comment|/* 36 */
literal|"address mask not contiguous"
block|,
comment|/* 37 */
literal|"file not found"
block|,
comment|/* 38 */
literal|"file already exists"
block|,
comment|/* 39 */
literal|"socket is not connected"
block|,
comment|/* 40 */
literal|"out of range"
block|,
comment|/* 41 */
literal|"out of entropy"
block|,
comment|/* 42 */
literal|"invalid use of multicast address"
block|,
comment|/* 43 */
literal|"not a file"
block|,
comment|/* 44 */
literal|"not a directory"
block|,
comment|/* 45 */
literal|"queue is full"
block|,
comment|/* 46 */
literal|"address family mismatch"
block|,
comment|/* 47 */
literal|"address family not supported"
block|,
comment|/* 48 */
literal|"bad hex encoding"
block|,
comment|/* 49 */
literal|"too many open files"
block|,
comment|/* 50 */
literal|"not blocking"
block|,
comment|/* 51 */
literal|"unbalanced quotes"
block|,
comment|/* 52 */
literal|"operation in progress"
block|,
comment|/* 53 */
literal|"connection reset"
block|,
comment|/* 54 */
literal|"soft quota reached"
block|,
comment|/* 55 */
literal|"not a valid number"
block|,
comment|/* 56 */
literal|"disabled"
block|,
comment|/* 57 */
literal|"max size"
block|,
comment|/* 58 */
literal|"invalid address format"
comment|/* 59 */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ISC_RESULT_RESULTSET
value|2
end_define

begin_define
define|#
directive|define
name|ISC_RESULT_UNAVAILABLESET
value|3
end_define

begin_decl_stmt
specifier|static
name|isc_once_t
name|once
init|=
name|ISC_ONCE_INIT
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|ISC_LIST
argument_list|(
argument|resulttable
argument_list|)
name|tables
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|isc_mutex_t
name|lock
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|isc_result_t
name|register_table
parameter_list|(
name|unsigned
name|int
name|base
parameter_list|,
name|unsigned
name|int
name|nresults
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|text
parameter_list|,
name|isc_msgcat_t
modifier|*
name|msgcat
parameter_list|,
name|int
name|set
parameter_list|)
block|{
name|resulttable
modifier|*
name|table
decl_stmt|;
name|REQUIRE
argument_list|(
name|base
operator|%
name|ISC_RESULTCLASS_SIZE
operator|==
literal|0
argument_list|)
expr_stmt|;
name|REQUIRE
argument_list|(
name|nresults
operator|<=
name|ISC_RESULTCLASS_SIZE
argument_list|)
expr_stmt|;
name|REQUIRE
argument_list|(
name|text
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|/* 	 * We use malloc() here because we we want to be able to use 	 * isc_result_totext() even if there is no memory context. 	 */
name|table
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|table
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|table
operator|==
name|NULL
condition|)
return|return
operator|(
name|ISC_R_NOMEMORY
operator|)
return|;
name|table
operator|->
name|base
operator|=
name|base
expr_stmt|;
name|table
operator|->
name|last
operator|=
name|base
operator|+
name|nresults
operator|-
literal|1
expr_stmt|;
name|table
operator|->
name|text
operator|=
name|text
expr_stmt|;
name|table
operator|->
name|msgcat
operator|=
name|msgcat
expr_stmt|;
name|table
operator|->
name|set
operator|=
name|set
expr_stmt|;
name|ISC_LINK_INIT
argument_list|(
name|table
argument_list|,
name|link
argument_list|)
expr_stmt|;
name|LOCK
argument_list|(
operator|&
name|lock
argument_list|)
expr_stmt|;
name|ISC_LIST_APPEND
argument_list|(
name|tables
argument_list|,
name|table
argument_list|,
name|link
argument_list|)
expr_stmt|;
name|UNLOCK
argument_list|(
operator|&
name|lock
argument_list|)
expr_stmt|;
return|return
operator|(
name|ISC_R_SUCCESS
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|initialize_action
parameter_list|(
name|void
parameter_list|)
block|{
name|isc_result_t
name|result
decl_stmt|;
name|RUNTIME_CHECK
argument_list|(
name|isc_mutex_init
argument_list|(
operator|&
name|lock
argument_list|)
operator|==
name|ISC_R_SUCCESS
argument_list|)
expr_stmt|;
name|ISC_LIST_INIT
argument_list|(
name|tables
argument_list|)
expr_stmt|;
name|result
operator|=
name|register_table
argument_list|(
name|ISC_RESULTCLASS_ISC
argument_list|,
name|ISC_R_NRESULTS
argument_list|,
name|text
argument_list|,
name|isc_msgcat
argument_list|,
name|ISC_RESULT_RESULTSET
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|!=
name|ISC_R_SUCCESS
condition|)
name|UNEXPECTED_ERROR
argument_list|(
name|__FILE__
argument_list|,
name|__LINE__
argument_list|,
literal|"register_table() %s: %u"
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
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|initialize
parameter_list|(
name|void
parameter_list|)
block|{
name|isc_lib_initmsgcat
argument_list|()
expr_stmt|;
name|RUNTIME_CHECK
argument_list|(
name|isc_once_do
argument_list|(
operator|&
name|once
argument_list|,
name|initialize_action
argument_list|)
operator|==
name|ISC_R_SUCCESS
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|isc_result_totext
parameter_list|(
name|isc_result_t
name|result
parameter_list|)
block|{
name|resulttable
modifier|*
name|table
decl_stmt|;
specifier|const
name|char
modifier|*
name|text
decl_stmt|,
modifier|*
name|default_text
decl_stmt|;
name|int
name|index
decl_stmt|;
name|initialize
argument_list|()
expr_stmt|;
name|LOCK
argument_list|(
operator|&
name|lock
argument_list|)
expr_stmt|;
name|text
operator|=
name|NULL
expr_stmt|;
for|for
control|(
name|table
operator|=
name|ISC_LIST_HEAD
argument_list|(
name|tables
argument_list|)
init|;
name|table
operator|!=
name|NULL
condition|;
name|table
operator|=
name|ISC_LIST_NEXT
argument_list|(
name|table
argument_list|,
name|link
argument_list|)
control|)
block|{
if|if
condition|(
name|result
operator|>=
name|table
operator|->
name|base
operator|&&
name|result
operator|<=
name|table
operator|->
name|last
condition|)
block|{
name|index
operator|=
call|(
name|int
call|)
argument_list|(
name|result
operator|-
name|table
operator|->
name|base
argument_list|)
expr_stmt|;
name|default_text
operator|=
name|table
operator|->
name|text
index|[
name|index
index|]
expr_stmt|;
comment|/* 			 * Note: we use 'index + 1' as the message number 			 * instead of index because isc_msgcat_get() requires 			 * the message number to be> 0. 			 */
name|text
operator|=
name|isc_msgcat_get
argument_list|(
name|table
operator|->
name|msgcat
argument_list|,
name|table
operator|->
name|set
argument_list|,
name|index
operator|+
literal|1
argument_list|,
name|default_text
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|text
operator|==
name|NULL
condition|)
name|text
operator|=
name|isc_msgcat_get
argument_list|(
name|isc_msgcat
argument_list|,
name|ISC_RESULT_UNAVAILABLESET
argument_list|,
literal|1
argument_list|,
literal|"(result code text not available)"
argument_list|)
expr_stmt|;
name|UNLOCK
argument_list|(
operator|&
name|lock
argument_list|)
expr_stmt|;
return|return
operator|(
name|text
operator|)
return|;
block|}
end_function

begin_function
name|isc_result_t
name|isc_result_register
parameter_list|(
name|unsigned
name|int
name|base
parameter_list|,
name|unsigned
name|int
name|nresults
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|text
parameter_list|,
name|isc_msgcat_t
modifier|*
name|msgcat
parameter_list|,
name|int
name|set
parameter_list|)
block|{
name|initialize
argument_list|()
expr_stmt|;
return|return
operator|(
name|register_table
argument_list|(
name|base
argument_list|,
name|nresults
argument_list|,
name|text
argument_list|,
name|msgcat
argument_list|,
name|set
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

