begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005, 2007  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: version.c,v 1.15 2007-06-19 23:47:16 tbox Exp $ */
end_comment

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<dns/version.h>
end_include

begin_decl_stmt
specifier|const
name|char
name|dns_version
index|[]
init|=
name|VERSION
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|unsigned
name|int
name|dns_libinterface
init|=
name|LIBINTERFACE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|unsigned
name|int
name|dns_librevision
init|=
name|LIBREVISION
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|unsigned
name|int
name|dns_libage
init|=
name|LIBAGE
decl_stmt|;
end_decl_stmt

end_unit

