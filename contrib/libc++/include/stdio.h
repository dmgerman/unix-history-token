begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===---------------------------- stdio.h ---------------------------------===//
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
name|__need_FILE
argument_list|)
operator|||
name|defined
argument_list|(
name|__need___FILE
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
empty|#include_next<stdio.h>
end_empty

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|_LIBCPP_STDIO_H
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_LIBCPP_STDIO_H
end_define

begin_comment
comment|/*     stdio.h synopsis  Macros:      BUFSIZ     EOF     FILENAME_MAX     FOPEN_MAX     L_tmpnam     NULL     SEEK_CUR     SEEK_END     SEEK_SET     TMP_MAX     _IOFBF     _IOLBF     _IONBF     stderr     stdin     stdout  Types:  FILE fpos_t size_t  int remove(const char* filename); int rename(const char* old, const char* new); FILE* tmpfile(void); char* tmpnam(char* s); int fclose(FILE* stream); int fflush(FILE* stream); FILE* fopen(const char* restrict filename, const char* restrict mode); FILE* freopen(const char* restrict filename, const char * restrict mode,               FILE * restrict stream); void setbuf(FILE* restrict stream, char* restrict buf); int setvbuf(FILE* restrict stream, char* restrict buf, int mode, size_t size); int fprintf(FILE* restrict stream, const char* restrict format, ...); int fscanf(FILE* restrict stream, const char * restrict format, ...); int printf(const char* restrict format, ...); int scanf(const char* restrict format, ...); int snprintf(char* restrict s, size_t n, const char* restrict format, ...);    // C99 int sprintf(char* restrict s, const char* restrict format, ...); int sscanf(const char* restrict s, const char* restrict format, ...); int vfprintf(FILE* restrict stream, const char* restrict format, va_list arg); int vfscanf(FILE* restrict stream, const char* restrict format, va_list arg);  // C99 int vprintf(const char* restrict format, va_list arg); int vscanf(const char* restrict format, va_list arg);                          // C99 int vsnprintf(char* restrict s, size_t n, const char* restrict format,         // C99               va_list arg); int vsprintf(char* restrict s, const char* restrict format, va_list arg); int vsscanf(const char* restrict s, const char* restrict format, va_list arg); // C99 int fgetc(FILE* stream); char* fgets(char* restrict s, int n, FILE* restrict stream); int fputc(int c, FILE* stream); int fputs(const char* restrict s, FILE* restrict stream); int getc(FILE* stream); int getchar(void); char* gets(char* s);  // removed in C++14 int putc(int c, FILE* stream); int putchar(int c); int puts(const char* s); int ungetc(int c, FILE* stream); size_t fread(void* restrict ptr, size_t size, size_t nmemb,              FILE* restrict stream); size_t fwrite(const void* restrict ptr, size_t size, size_t nmemb,               FILE* restrict stream); int fgetpos(FILE* restrict stream, fpos_t* restrict pos); int fseek(FILE* stream, long offset, int whence); int fsetpos(FILE*stream, const fpos_t* pos); long ftell(FILE* stream); void rewind(FILE* stream); void clearerr(FILE* stream); int feof(FILE* stream); int ferror(FILE* stream); void perror(const char* s); */
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
empty|#include_next<stdio.h>
end_empty

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_comment
comment|// snprintf
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LIBCPP_MSVCRT
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
block|{
name|int
name|vasprintf
parameter_list|(
name|char
modifier|*
modifier|*
name|sptr
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
name|int
name|asprintf
parameter_list|(
name|char
modifier|*
modifier|*
name|sptr
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|getc
end_undef

begin_undef
undef|#
directive|undef
name|putc
end_undef

begin_undef
undef|#
directive|undef
name|clearerr
end_undef

begin_undef
undef|#
directive|undef
name|feof
end_undef

begin_undef
undef|#
directive|undef
name|ferror
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_STDIO_H
end_comment

end_unit

