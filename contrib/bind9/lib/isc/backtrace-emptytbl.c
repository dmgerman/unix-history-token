begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2009  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: backtrace-emptytbl.c,v 1.3 2009/09/01 20:13:44 each Exp $ */
end_comment

begin_comment
comment|/*! \file */
end_comment

begin_comment
comment|/*  * This file defines an empty (default) symbol table used in backtrace.c  * If the application wants to have a complete symbol table, it should redefine  * isc__backtrace_symtable with the complete table in some way, and link the  * version of the library not including this definition  * (e.g. libisc-nosymbol.a).  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<isc/backtrace.h>
end_include

begin_decl_stmt
specifier|const
name|int
name|isc__backtrace_nsymbols
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|isc_backtrace_symmap_t
name|isc__backtrace_symtable
index|[]
init|=
block|{
block|{
name|NULL
block|,
literal|""
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

