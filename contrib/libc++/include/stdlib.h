begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===--------------------------- stdlib.h ---------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__need_malloc_and_calloc
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#include_next<stdlib.h>
end_empty

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|_LIBCPP_STDLIB_H
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_LIBCPP_STDLIB_H
end_define

begin_comment
comment|/*     stdlib.h synopsis  Macros:      EXIT_FAILURE     EXIT_SUCCESS     MB_CUR_MAX     NULL     RAND_MAX  Types:      size_t     div_t     ldiv_t     lldiv_t                                                               // C99  double    atof (const char* nptr); int       atoi (const char* nptr); long      atol (const char* nptr); long long atoll(const char* nptr);                                        // C99 double             strtod  (const char* restrict nptr, char** restrict endptr); float              strtof  (const char* restrict nptr, char** restrict endptr); // C99 long double        strtold (const char* restrict nptr, char** restrict endptr); // C99 long               strtol  (const char* restrict nptr, char** restrict endptr, int base); long long          strtoll (const char* restrict nptr, char** restrict endptr, int base); // C99 unsigned long      strtoul (const char* restrict nptr, char** restrict endptr, int base); unsigned long long strtoull(const char* restrict nptr, char** restrict endptr, int base); // C99 int rand(void); void srand(unsigned int seed); void* calloc(size_t nmemb, size_t size); void free(void* ptr); void* malloc(size_t size); void* realloc(void* ptr, size_t size); void abort(void); int atexit(void (*func)(void)); void exit(int status); void _Exit(int status); char* getenv(const char* name); int system(const char* string); void* bsearch(const void* key, const void* base, size_t nmemb, size_t size,               int (*compar)(const void *, const void *)); void qsort(void* base, size_t nmemb, size_t size,            int (*compar)(const void *, const void *)); int         abs(      int j); long        abs(     long j); long long   abs(long long j);                                             // C++0X long       labs(     long j); long long llabs(long long j);                                             // C99 div_t     div(      int numer,       int denom); ldiv_t    div(     long numer,      long denom); lldiv_t   div(long long numer, long long denom);                          // C++0X ldiv_t   ldiv(     long numer,      long denom); lldiv_t lldiv(long long numer, long long denom);                          // C99 int mblen(const char* s, size_t n); int mbtowc(wchar_t* restrict pwc, const char* restrict s, size_t n); int wctomb(char* s, wchar_t wchar); size_t mbstowcs(wchar_t* restrict pwcs, const char* restrict s, size_t n); size_t wcstombs(char* restrict s, const wchar_t* restrict pwcs, size_t n); int at_quick_exit(void (*func)(void))                                     // C++11 void quick_exit(int status);                                              // C++11 void *aligned_alloc(size_t alignment, size_t size);                       // C11  */
end_comment

begin_include
include|#
directive|include
file|<__config>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#include_next<stdlib.h>
end_empty

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C++"
block|{
undef|#
directive|undef
name|abs
undef|#
directive|undef
name|div
undef|#
directive|undef
name|labs
undef|#
directive|undef
name|ldiv
ifndef|#
directive|ifndef
name|_LIBCPP_HAS_NO_LONG_LONG
undef|#
directive|undef
name|llabs
undef|#
directive|undef
name|lldiv
endif|#
directive|endif
comment|// MSVCRT already has the correct prototype in<stdlib.h> if __cplusplus is defined
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_LIBCPP_MSVCRT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__sun__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_AIX
argument_list|)
specifier|inline
name|_LIBCPP_INLINE_VISIBILITY
name|long
name|abs
parameter_list|(
name|long
name|__x
parameter_list|)
function|_NOEXCEPT
block|{
return|return
name|labs
argument_list|(
name|__x
argument_list|)
return|;
block|}
ifndef|#
directive|ifndef
name|_LIBCPP_HAS_NO_LONG_LONG
specifier|inline
name|_LIBCPP_INLINE_VISIBILITY
name|long
name|long
name|abs
parameter_list|(
name|long
name|long
name|__x
parameter_list|)
function|_NOEXCEPT
block|{
return|return
name|llabs
argument_list|(
name|__x
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|// _LIBCPP_HAS_NO_LONG_LONG
specifier|inline
name|_LIBCPP_INLINE_VISIBILITY
name|ldiv_t
name|div
parameter_list|(
name|long
name|__x
parameter_list|,
name|long
name|__y
parameter_list|)
function|_NOEXCEPT
block|{
return|return
name|ldiv
argument_list|(
name|__x
argument_list|,
name|__y
argument_list|)
return|;
block|}
ifndef|#
directive|ifndef
name|_LIBCPP_HAS_NO_LONG_LONG
specifier|inline
name|_LIBCPP_INLINE_VISIBILITY
name|lldiv_t
name|div
parameter_list|(
name|long
name|long
name|__x
parameter_list|,
name|long
name|long
name|__y
parameter_list|)
function|_NOEXCEPT
block|{
return|return
name|lldiv
argument_list|(
name|__x
argument_list|,
name|__y
argument_list|)
return|;
block|}
endif|#
directive|endif
comment|// _LIBCPP_HAS_NO_LONG_LONG
endif|#
directive|endif
comment|// _LIBCPP_MSVCRT / __sun__ / _AIX
block|}
end_extern

begin_comment
comment|// extern "C++"
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_STDLIB_H
end_comment

end_unit

