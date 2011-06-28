begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2006, 2007  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: xml.h,v 1.4 2007-06-19 23:47:18 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_XML_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_XML_H
value|1
end_define

begin_comment
comment|/*  * This file is here mostly to make it easy to add additional libxml header  * files as needed across all the users of this file.  Rather than place  * these libxml includes in each file, one include makes it easy to handle  * the ifdef as well as adding the ability to add additional functions  * which may be useful.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIBXML2
end_ifdef

begin_include
include|#
directive|include
file|<libxml/encoding.h>
end_include

begin_include
include|#
directive|include
file|<libxml/xmlwriter.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISC_XMLCHAR
value|(const xmlChar *)
end_define

begin_define
define|#
directive|define
name|ISC_XML_RENDERCONFIG
value|0x00000001
end_define

begin_comment
comment|/* render config data */
end_comment

begin_define
define|#
directive|define
name|ISC_XML_RENDERSTATS
value|0x00000002
end_define

begin_comment
comment|/* render stats */
end_comment

begin_define
define|#
directive|define
name|ISC_XML_RENDERALL
value|0x000000ff
end_define

begin_comment
comment|/* render everything */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_XML_H */
end_comment

end_unit

