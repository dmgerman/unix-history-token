begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The -*- C++ -*- null-terminated string header.
end_comment

begin_comment
comment|// This file is part of the GNU ANSI C++ Library.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CSTRING__
end_ifndef

begin_define
define|#
directive|define
name|__CSTRING__
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|// Let's not bother with this just yet.
end_comment

begin_comment
comment|// The ANSI C prototypes for these functions have a const argument type and
end_comment

begin_comment
comment|// non-const return type, so we can't use them.
end_comment

begin_define
define|#
directive|define
name|strchr
value|__hide_strchr
end_define

begin_define
define|#
directive|define
name|strpbrk
value|__hide_strpbrk
end_define

begin_define
define|#
directive|define
name|strrchr
value|__hide_strrchr
end_define

begin_define
define|#
directive|define
name|strstr
value|__hide_strstr
end_define

begin_define
define|#
directive|define
name|memchr
value|__hide_memchr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// 0
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|// Let's not bother with this just yet.
end_comment

begin_undef
undef|#
directive|undef
name|strchr
end_undef

begin_undef
undef|#
directive|undef
name|strpbrk
end_undef

begin_undef
undef|#
directive|undef
name|strrchr
end_undef

begin_undef
undef|#
directive|undef
name|strstr
end_undef

begin_undef
undef|#
directive|undef
name|memchr
end_undef

begin_include
include|#
directive|include
file|<std/cstddef.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
literal|"std/cstring.h"
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|extern "C++" { extern "C" const char *strchr (const char *, int); inline char * strchr (char *s, int c) {   return const_cast<char *> (strchr (static_cast<const char *> (s), c)); }  extern "C" const char *strpbrk (const char *, const char *); inline char * strpbrk (char *s1, const char *s2) {   return const_cast<char *> (strpbrk (static_cast<const char *> (s1), s2)); }  extern "C" const char *strrchr (const char *, int); inline char * strrchr (char *s, int c) {   return const_cast<char *> (strrchr (static_cast<const char *> (s), c)); }  extern "C" const char *strstr (const char *, const char *); inline char * strstr (char *s1, const char *s2) {   return const_cast<char *> (strstr (static_cast<const char *> (s1), s2)); }  extern "C" const void *memchr (const void *, int, size_t); inline void * memchr (void *s, int c, size_t n) {   return const_cast<void *> (memchr (static_cast<const void *> (s), c, n)); } }
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// 0
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined (__CSTRING__)
end_comment

end_unit

