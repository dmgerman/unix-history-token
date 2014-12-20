begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * libntp local override of isc/mem.h to stub it out.  *  * include/isc is searched before any of the lib/isc include  * directories and should be used only for replacement NTP headers  * overriding headers of the same name under lib/isc.  *  * NOTE: this assumes the system malloc is thread-safe and does  *	 not use any normal lib/isc locking.  */
end_comment

begin_comment
comment|/*  * Copyright (C) 2004-2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1997-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: mem.h,v 1.78.120.3 2009/02/11 03:07:01 jinmei Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_MEM_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_MEM_H
value|1
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/mutex.h>
end_include

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isc/xml.h>
end_include

begin_include
include|#
directive|include
file|<ntp_stdlib.h>
end_include

begin_define
define|#
directive|define
name|ISC_MEM_UNUSED_ARG
parameter_list|(
name|a
parameter_list|)
value|((void)(a))
end_define

begin_define
define|#
directive|define
name|isc_mem_allocate
parameter_list|(
name|c
parameter_list|,
name|cnt
parameter_list|)
value|isc_mem_get(c, cnt)
end_define

begin_define
define|#
directive|define
name|isc_mem_get
parameter_list|(
name|c
parameter_list|,
name|cnt
parameter_list|)
define|\
value|( ISC_MEM_UNUSED_ARG(c),	emalloc(cnt) )
end_define

begin_define
define|#
directive|define
name|isc_mem_reallocate
parameter_list|(
name|c
parameter_list|,
name|mem
parameter_list|,
name|cnt
parameter_list|)
define|\
value|( ISC_MEM_UNUSED_ARG(c),	erealloc((mem), cnt) )
end_define

begin_define
define|#
directive|define
name|isc_mem_put
parameter_list|(
name|c
parameter_list|,
name|mem
parameter_list|,
name|cnt
parameter_list|)
define|\
value|( ISC_MEM_UNUSED_ARG(cnt),	isc_mem_free(c, (mem)) )
end_define

begin_define
define|#
directive|define
name|isc_mem_free
parameter_list|(
name|c
parameter_list|,
name|mem
parameter_list|)
define|\
value|( ISC_MEM_UNUSED_ARG(c),	free(mem) )
end_define

begin_define
define|#
directive|define
name|isc_mem_strdup
parameter_list|(
name|c
parameter_list|,
name|str
parameter_list|)
define|\
value|( ISC_MEM_UNUSED_ARG(c),	estrdup(str) )
end_define

begin_define
define|#
directive|define
name|isc__mem_attach
parameter_list|(
name|src
parameter_list|,
name|ptgt
parameter_list|)
value|do { *(ptgt) = (src); } while (0)
end_define

begin_define
define|#
directive|define
name|isc__mem_detach
parameter_list|(
name|c
parameter_list|)
value|ISC_MEM_UNUSED_ARG(c)
end_define

begin_define
define|#
directive|define
name|isc__mem_printallactive
parameter_list|(
name|s
parameter_list|)
value|fprintf((s), \ 					"isc_mem_printallactive() stubbed.\n")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_MEM_H */
end_comment

end_unit

