begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NEARALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|NEARALLOC_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FARALLOC_H
end_ifdef

begin_undef
undef|#
directive|undef
name|FARALLOC_H
end_undef

begin_define
define|#
directive|define
name|__FARALLOC_WAS_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__far
value|__near
end_define

begin_define
define|#
directive|define
name|far_allocator
value|near_allocator
end_define

begin_include
include|#
directive|include
file|<faralloc.h>
end_include

begin_undef
undef|#
directive|undef
name|__far
end_undef

begin_undef
undef|#
directive|undef
name|far_allocator
end_undef

begin_undef
undef|#
directive|undef
name|FARALLOC_H
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__FARALLOC_WAS_DEFINED
end_ifdef

begin_define
define|#
directive|define
name|FARALLOC_H
end_define

begin_undef
undef|#
directive|undef
name|__FARALLOC_WAS_DEFINED
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

