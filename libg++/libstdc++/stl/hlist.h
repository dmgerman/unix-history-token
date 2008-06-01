begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HLIST_H
end_ifndef

begin_define
define|#
directive|define
name|HLIST_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LIST_H
end_ifdef

begin_undef
undef|#
directive|undef
name|LIST_H
end_undef

begin_define
define|#
directive|define
name|__LIST_WAS_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|Allocator
value|huge_allocator
end_define

begin_define
define|#
directive|define
name|list
value|huge_list
end_define

begin_include
include|#
directive|include
file|<hugalloc.h>
end_include

begin_include
include|#
directive|include
file|<list.h>
end_include

begin_undef
undef|#
directive|undef
name|LIST_H
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__LIST_WAS_DEFINED
end_ifdef

begin_define
define|#
directive|define
name|LIST_H
end_define

begin_undef
undef|#
directive|undef
name|__LIST_WAS_DEFINED
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|Allocator
end_undef

begin_undef
undef|#
directive|undef
name|list
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

