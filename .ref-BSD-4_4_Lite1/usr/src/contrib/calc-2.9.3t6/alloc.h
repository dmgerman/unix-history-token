begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  *  * Allocator definitions (fast malloc and free)  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CALC_MALLOC
argument_list|)
end_if

begin_include
include|#
directive|include
file|"have_malloc.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_MALLOC_H
end_ifdef

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"have_string.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRING_H
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|OLD_BSD
end_ifdef

begin_function_decl
specifier|extern
name|void
name|bcopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bfill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* OLD_BSD */
end_comment

begin_function_decl
specifier|extern
name|void
name|memcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|memset
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_function_decl
specifier|extern
name|void
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OLD_BSD */
end_comment

begin_function_decl
specifier|extern
name|void
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|strncpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|strcmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|strlen
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* should be size_t, but old systems don't have it */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OLD_BSD
end_ifdef

begin_undef
undef|#
directive|undef
name|memcpy
end_undef

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
value|bcopy(s2, s1, n)
end_define

begin_undef
undef|#
directive|undef
name|memset
end_undef

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
value|bfill(s, n, c)
end_define

begin_undef
undef|#
directive|undef
name|strchr
end_undef

begin_define
define|#
directive|define
name|strchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|index(s, c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DONT_HAVE_VSPRINTF
end_ifdef

begin_comment
comment|/*  * Hack aleart!!!  *  * Systems that do not have vsprintf() need something.  In some cases  * the sprintf function will deal correctly with the va_alist 3rd arg.  * Hope for the best!  */
end_comment

begin_define
define|#
directive|define
name|vsprintf
value|sprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|mem_alloc
value|malloc
end_define

begin_define
define|#
directive|define
name|mem_realloc
value|realloc
end_define

begin_define
define|#
directive|define
name|mem_free
value|free
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*!CALC_MALLOC*/
end_comment

begin_define
define|#
directive|define
name|malloc
parameter_list|(
name|a
parameter_list|)
value|mem_alloc((long) a)
end_define

begin_define
define|#
directive|define
name|realloc
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|mem_realloc((char *) a, (long) b)
end_define

begin_define
define|#
directive|define
name|free
parameter_list|(
name|a
parameter_list|)
value|mem_free((char *) a)
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|mem_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|mem_realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mem_free
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* MUST be int even though no return value */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!CALC_MALLOC*/
end_comment

begin_comment
comment|/*  * An item to be placed on a free list.  * These items are overlayed on top of the actual item being managed.  * Therefore, the managed items must be at least this size!  * Also, all items on a single free list must be the same size.  */
end_comment

begin_struct
struct|struct
name|free_item
block|{
name|struct
name|free_item
modifier|*
name|next
decl_stmt|;
comment|/* next item on free list */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|free_item
name|FREEITEM
typedef|;
end_typedef

begin_comment
comment|/*  * The actual free list header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|itemsize
decl_stmt|;
comment|/* size of an item being managed */
name|long
name|maxfree
decl_stmt|;
comment|/* maximum number of free items */
name|long
name|curfree
decl_stmt|;
comment|/* current number of free items */
name|FREEITEM
modifier|*
name|freelist
decl_stmt|;
comment|/* the free list */
block|}
name|FREELIST
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|void
name|ALLOCITEM
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
name|ALLOCITEM
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|ALLOCITEM
modifier|*
name|allocitem
parameter_list|(
comment|/* FREELIST * */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|freeitem
parameter_list|(
comment|/* FREELIST *, char * */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mem_stats
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* END CODE */
end_comment

end_unit

