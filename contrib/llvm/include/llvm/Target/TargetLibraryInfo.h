begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetLibraryInfo.h - Library information ---*- C++ -*-===//
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
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TARGET_TARGETLIBRARYINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETLIBRARYINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Triple
decl_stmt|;
name|namespace
name|LibFunc
block|{
enum|enum
name|Func
block|{
comment|/// int _IO_getc(_IO_FILE * __fp);
name|under_IO_getc
block|,
comment|/// int _IO_putc(int __c, _IO_FILE * __fp);
name|under_IO_putc
block|,
comment|/// void operator delete[](void*);
name|ZdaPv
block|,
comment|/// void operator delete[](void*, nothrow);
name|ZdaPvRKSt9nothrow_t
block|,
comment|/// void operator delete(void*);
name|ZdlPv
block|,
comment|/// void operator delete(void*, nothrow);
name|ZdlPvRKSt9nothrow_t
block|,
comment|/// void *new[](unsigned int);
name|Znaj
block|,
comment|/// void *new[](unsigned int, nothrow);
name|ZnajRKSt9nothrow_t
block|,
comment|/// void *new[](unsigned long);
name|Znam
block|,
comment|/// void *new[](unsigned long, nothrow);
name|ZnamRKSt9nothrow_t
block|,
comment|/// void *new(unsigned int);
name|Znwj
block|,
comment|/// void *new(unsigned int, nothrow);
name|ZnwjRKSt9nothrow_t
block|,
comment|/// void *new(unsigned long);
name|Znwm
block|,
comment|/// void *new(unsigned long, nothrow);
name|ZnwmRKSt9nothrow_t
block|,
comment|/// double __cospi(double x);
name|cospi
block|,
comment|/// float __cospif(float x);
name|cospif
block|,
comment|/// int __cxa_atexit(void (*f)(void *), void *p, void *d);
name|cxa_atexit
block|,
comment|/// void __cxa_guard_abort(guard_t *guard);
comment|/// guard_t is int64_t in Itanium ABI or int32_t on ARM eabi.
name|cxa_guard_abort
block|,
comment|/// int __cxa_guard_acquire(guard_t *guard);
name|cxa_guard_acquire
block|,
comment|/// void __cxa_guard_release(guard_t *guard);
name|cxa_guard_release
block|,
comment|/// int __isoc99_scanf (const char *format, ...)
name|dunder_isoc99_scanf
block|,
comment|/// int __isoc99_sscanf(const char *s, const char *format, ...)
name|dunder_isoc99_sscanf
block|,
comment|/// void *__memcpy_chk(void *s1, const void *s2, size_t n, size_t s1size);
name|memcpy_chk
block|,
comment|/// double __sincospi_stret(double x);
name|sincospi_stret
block|,
comment|/// float __sincospi_stretf(float x);
name|sincospi_stretf
block|,
comment|/// double __sinpi(double x);
name|sinpi
block|,
comment|/// float __sinpif(float x);
name|sinpif
block|,
comment|/// double __sqrt_finite(double x);
name|sqrt_finite
block|,
comment|/// float __sqrt_finite(float x);
name|sqrtf_finite
block|,
comment|/// long double __sqrt_finite(long double x);
name|sqrtl_finite
block|,
comment|/// char * __strdup(const char *s);
name|dunder_strdup
block|,
comment|/// char *__strndup(const char *s, size_t n);
name|dunder_strndup
block|,
comment|/// char * __strtok_r(char *s, const char *delim, char **save_ptr);
name|dunder_strtok_r
block|,
comment|/// int abs(int j);
name|abs
block|,
comment|/// int access(const char *path, int amode);
name|access
block|,
comment|/// double acos(double x);
name|acos
block|,
comment|/// float acosf(float x);
name|acosf
block|,
comment|/// double acosh(double x);
name|acosh
block|,
comment|/// float acoshf(float x);
name|acoshf
block|,
comment|/// long double acoshl(long double x);
name|acoshl
block|,
comment|/// long double acosl(long double x);
name|acosl
block|,
comment|/// double asin(double x);
name|asin
block|,
comment|/// float asinf(float x);
name|asinf
block|,
comment|/// double asinh(double x);
name|asinh
block|,
comment|/// float asinhf(float x);
name|asinhf
block|,
comment|/// long double asinhl(long double x);
name|asinhl
block|,
comment|/// long double asinl(long double x);
name|asinl
block|,
comment|/// double atan(double x);
name|atan
block|,
comment|/// double atan2(double y, double x);
name|atan2
block|,
comment|/// float atan2f(float y, float x);
name|atan2f
block|,
comment|/// long double atan2l(long double y, long double x);
name|atan2l
block|,
comment|/// float atanf(float x);
name|atanf
block|,
comment|/// double atanh(double x);
name|atanh
block|,
comment|/// float atanhf(float x);
name|atanhf
block|,
comment|/// long double atanhl(long double x);
name|atanhl
block|,
comment|/// long double atanl(long double x);
name|atanl
block|,
comment|/// double atof(const char *str);
name|atof
block|,
comment|/// int atoi(const char *str);
name|atoi
block|,
comment|/// long atol(const char *str);
name|atol
block|,
comment|/// long long atoll(const char *nptr);
name|atoll
block|,
comment|/// int bcmp(const void *s1, const void *s2, size_t n);
name|bcmp
block|,
comment|/// void bcopy(const void *s1, void *s2, size_t n);
name|bcopy
block|,
comment|/// void bzero(void *s, size_t n);
name|bzero
block|,
comment|/// void *calloc(size_t count, size_t size);
name|calloc
block|,
comment|/// double cbrt(double x);
name|cbrt
block|,
comment|/// float cbrtf(float x);
name|cbrtf
block|,
comment|/// long double cbrtl(long double x);
name|cbrtl
block|,
comment|/// double ceil(double x);
name|ceil
block|,
comment|/// float ceilf(float x);
name|ceilf
block|,
comment|/// long double ceill(long double x);
name|ceill
block|,
comment|/// int chmod(const char *path, mode_t mode);
name|chmod
block|,
comment|/// int chown(const char *path, uid_t owner, gid_t group);
name|chown
block|,
comment|/// void clearerr(FILE *stream);
name|clearerr
block|,
comment|/// int closedir(DIR *dirp);
name|closedir
block|,
comment|/// double copysign(double x, double y);
name|copysign
block|,
comment|/// float copysignf(float x, float y);
name|copysignf
block|,
comment|/// long double copysignl(long double x, long double y);
name|copysignl
block|,
comment|/// double cos(double x);
name|cos
block|,
comment|/// float cosf(float x);
name|cosf
block|,
comment|/// double cosh(double x);
name|cosh
block|,
comment|/// float coshf(float x);
name|coshf
block|,
comment|/// long double coshl(long double x);
name|coshl
block|,
comment|/// long double cosl(long double x);
name|cosl
block|,
comment|/// char *ctermid(char *s);
name|ctermid
block|,
comment|/// double exp(double x);
name|exp
block|,
comment|/// double exp10(double x);
name|exp10
block|,
comment|/// float exp10f(float x);
name|exp10f
block|,
comment|/// long double exp10l(long double x);
name|exp10l
block|,
comment|/// double exp2(double x);
name|exp2
block|,
comment|/// float exp2f(float x);
name|exp2f
block|,
comment|/// long double exp2l(long double x);
name|exp2l
block|,
comment|/// float expf(float x);
name|expf
block|,
comment|/// long double expl(long double x);
name|expl
block|,
comment|/// double expm1(double x);
name|expm1
block|,
comment|/// float expm1f(float x);
name|expm1f
block|,
comment|/// long double expm1l(long double x);
name|expm1l
block|,
comment|/// double fabs(double x);
name|fabs
block|,
comment|/// float fabsf(float x);
name|fabsf
block|,
comment|/// long double fabsl(long double x);
name|fabsl
block|,
comment|/// int fclose(FILE *stream);
name|fclose
block|,
comment|/// FILE *fdopen(int fildes, const char *mode);
name|fdopen
block|,
comment|/// int feof(FILE *stream);
name|feof
block|,
comment|/// int ferror(FILE *stream);
name|ferror
block|,
comment|/// int fflush(FILE *stream);
name|fflush
block|,
comment|/// int ffs(int i);
name|ffs
block|,
comment|/// int ffsl(long int i);
name|ffsl
block|,
comment|/// int ffsll(long long int i);
name|ffsll
block|,
comment|/// int fgetc(FILE *stream);
name|fgetc
block|,
comment|/// int fgetpos(FILE *stream, fpos_t *pos);
name|fgetpos
block|,
comment|/// char *fgets(char *s, int n, FILE *stream);
name|fgets
block|,
comment|/// int fileno(FILE *stream);
name|fileno
block|,
comment|/// int fiprintf(FILE *stream, const char *format, ...);
name|fiprintf
block|,
comment|/// void flockfile(FILE *file);
name|flockfile
block|,
comment|/// double floor(double x);
name|floor
block|,
comment|/// float floorf(float x);
name|floorf
block|,
comment|/// long double floorl(long double x);
name|floorl
block|,
comment|/// double fmod(double x, double y);
name|fmod
block|,
comment|/// float fmodf(float x, float y);
name|fmodf
block|,
comment|/// long double fmodl(long double x, long double y);
name|fmodl
block|,
comment|/// FILE *fopen(const char *filename, const char *mode);
name|fopen
block|,
comment|/// FILE *fopen64(const char *filename, const char *opentype)
name|fopen64
block|,
comment|/// int fprintf(FILE *stream, const char *format, ...);
name|fprintf
block|,
comment|/// int fputc(int c, FILE *stream);
name|fputc
block|,
comment|/// int fputs(const char *s, FILE *stream);
name|fputs
block|,
comment|/// size_t fread(void *ptr, size_t size, size_t nitems, FILE *stream);
name|fread
block|,
comment|/// void free(void *ptr);
name|free
block|,
comment|/// double frexp(double num, int *exp);
name|frexp
block|,
comment|/// float frexpf(float num, int *exp);
name|frexpf
block|,
comment|/// long double frexpl(long double num, int *exp);
name|frexpl
block|,
comment|/// int fscanf(FILE *stream, const char *format, ... );
name|fscanf
block|,
comment|/// int fseek(FILE *stream, long offset, int whence);
name|fseek
block|,
comment|/// int fseeko(FILE *stream, off_t offset, int whence);
name|fseeko
block|,
comment|/// int fseeko64(FILE *stream, off64_t offset, int whence)
name|fseeko64
block|,
comment|/// int fsetpos(FILE *stream, const fpos_t *pos);
name|fsetpos
block|,
comment|/// int fstat(int fildes, struct stat *buf);
name|fstat
block|,
comment|/// int fstat64(int filedes, struct stat64 *buf)
name|fstat64
block|,
comment|/// int fstatvfs(int fildes, struct statvfs *buf);
name|fstatvfs
block|,
comment|/// int fstatvfs64(int fildes, struct statvfs64 *buf);
name|fstatvfs64
block|,
comment|/// long ftell(FILE *stream);
name|ftell
block|,
comment|/// off_t ftello(FILE *stream);
name|ftello
block|,
comment|/// off64_t ftello64(FILE *stream)
name|ftello64
block|,
comment|/// int ftrylockfile(FILE *file);
name|ftrylockfile
block|,
comment|/// void funlockfile(FILE *file);
name|funlockfile
block|,
comment|/// size_t fwrite(const void *ptr, size_t size, size_t nitems,
comment|/// FILE *stream);
name|fwrite
block|,
comment|/// int getc(FILE *stream);
name|getc
block|,
comment|/// int getc_unlocked(FILE *stream);
name|getc_unlocked
block|,
comment|/// int getchar(void);
name|getchar
block|,
comment|/// char *getenv(const char *name);
name|getenv
block|,
comment|/// int getitimer(int which, struct itimerval *value);
name|getitimer
block|,
comment|/// int getlogin_r(char *name, size_t namesize);
name|getlogin_r
block|,
comment|/// struct passwd *getpwnam(const char *name);
name|getpwnam
block|,
comment|/// char *gets(char *s);
name|gets
block|,
comment|/// int gettimeofday(struct timeval *tp, void *tzp);
name|gettimeofday
block|,
comment|/// uint32_t htonl(uint32_t hostlong);
name|htonl
block|,
comment|/// uint16_t htons(uint16_t hostshort);
name|htons
block|,
comment|/// int iprintf(const char *format, ...);
name|iprintf
block|,
comment|/// int isascii(int c);
name|isascii
block|,
comment|/// int isdigit(int c);
name|isdigit
block|,
comment|/// long int labs(long int j);
name|labs
block|,
comment|/// int lchown(const char *path, uid_t owner, gid_t group);
name|lchown
block|,
comment|/// long long int llabs(long long int j);
name|llabs
block|,
comment|/// double log(double x);
name|log
block|,
comment|/// double log10(double x);
name|log10
block|,
comment|/// float log10f(float x);
name|log10f
block|,
comment|/// long double log10l(long double x);
name|log10l
block|,
comment|/// double log1p(double x);
name|log1p
block|,
comment|/// float log1pf(float x);
name|log1pf
block|,
comment|/// long double log1pl(long double x);
name|log1pl
block|,
comment|/// double log2(double x);
name|log2
block|,
comment|/// float log2f(float x);
name|log2f
block|,
comment|/// double long double log2l(long double x);
name|log2l
block|,
comment|/// double logb(double x);
name|logb
block|,
comment|/// float logbf(float x);
name|logbf
block|,
comment|/// long double logbl(long double x);
name|logbl
block|,
comment|/// float logf(float x);
name|logf
block|,
comment|/// long double logl(long double x);
name|logl
block|,
comment|/// int lstat(const char *path, struct stat *buf);
name|lstat
block|,
comment|/// int lstat64(const char *path, struct stat64 *buf);
name|lstat64
block|,
comment|/// void *malloc(size_t size);
name|malloc
block|,
comment|/// void *memalign(size_t boundary, size_t size);
name|memalign
block|,
comment|/// void *memccpy(void *s1, const void *s2, int c, size_t n);
name|memccpy
block|,
comment|/// void *memchr(const void *s, int c, size_t n);
name|memchr
block|,
comment|/// int memcmp(const void *s1, const void *s2, size_t n);
name|memcmp
block|,
comment|/// void *memcpy(void *s1, const void *s2, size_t n);
name|memcpy
block|,
comment|/// void *memmove(void *s1, const void *s2, size_t n);
name|memmove
block|,
comment|// void *memrchr(const void *s, int c, size_t n);
name|memrchr
block|,
comment|/// void *memset(void *b, int c, size_t len);
name|memset
block|,
comment|/// void memset_pattern16(void *b, const void *pattern16, size_t len);
name|memset_pattern16
block|,
comment|/// int mkdir(const char *path, mode_t mode);
name|mkdir
block|,
comment|/// time_t mktime(struct tm *timeptr);
name|mktime
block|,
comment|/// double modf(double x, double *iptr);
name|modf
block|,
comment|/// float modff(float, float *iptr);
name|modff
block|,
comment|/// long double modfl(long double value, long double *iptr);
name|modfl
block|,
comment|/// double nearbyint(double x);
name|nearbyint
block|,
comment|/// float nearbyintf(float x);
name|nearbyintf
block|,
comment|/// long double nearbyintl(long double x);
name|nearbyintl
block|,
comment|/// uint32_t ntohl(uint32_t netlong);
name|ntohl
block|,
comment|/// uint16_t ntohs(uint16_t netshort);
name|ntohs
block|,
comment|/// int open(const char *path, int oflag, ... );
name|open
block|,
comment|/// int open64(const char *filename, int flags[, mode_t mode])
name|open64
block|,
comment|/// DIR *opendir(const char *dirname);
name|opendir
block|,
comment|/// int pclose(FILE *stream);
name|pclose
block|,
comment|/// void perror(const char *s);
name|perror
block|,
comment|/// FILE *popen(const char *command, const char *mode);
name|popen
block|,
comment|/// int posix_memalign(void **memptr, size_t alignment, size_t size);
name|posix_memalign
block|,
comment|/// double pow(double x, double y);
name|pow
block|,
comment|/// float powf(float x, float y);
name|powf
block|,
comment|/// long double powl(long double x, long double y);
name|powl
block|,
comment|/// ssize_t pread(int fildes, void *buf, size_t nbyte, off_t offset);
name|pread
block|,
comment|/// int printf(const char *format, ...);
name|printf
block|,
comment|/// int putc(int c, FILE *stream);
name|putc
block|,
comment|/// int putchar(int c);
name|putchar
block|,
comment|/// int puts(const char *s);
name|puts
block|,
comment|/// ssize_t pwrite(int fildes, const void *buf, size_t nbyte,
comment|///                off_t offset);
name|pwrite
block|,
comment|/// void qsort(void *base, size_t nel, size_t width,
comment|///            int (*compar)(const void *, const void *));
name|qsort
block|,
comment|/// ssize_t read(int fildes, void *buf, size_t nbyte);
name|read
block|,
comment|/// ssize_t readlink(const char *path, char *buf, size_t bufsize);
name|readlink
block|,
comment|/// void *realloc(void *ptr, size_t size);
name|realloc
block|,
comment|/// void *reallocf(void *ptr, size_t size);
name|reallocf
block|,
comment|/// char *realpath(const char *file_name, char *resolved_name);
name|realpath
block|,
comment|/// int remove(const char *path);
name|remove
block|,
comment|/// int rename(const char *old, const char *new);
name|rename
block|,
comment|/// void rewind(FILE *stream);
name|rewind
block|,
comment|/// double rint(double x);
name|rint
block|,
comment|/// float rintf(float x);
name|rintf
block|,
comment|/// long double rintl(long double x);
name|rintl
block|,
comment|/// int rmdir(const char *path);
name|rmdir
block|,
comment|/// double round(double x);
name|round
block|,
comment|/// float roundf(float x);
name|roundf
block|,
comment|/// long double roundl(long double x);
name|roundl
block|,
comment|/// int scanf(const char *restrict format, ... );
name|scanf
block|,
comment|/// void setbuf(FILE *stream, char *buf);
name|setbuf
block|,
comment|/// int setitimer(int which, const struct itimerval *value,
comment|///               struct itimerval *ovalue);
name|setitimer
block|,
comment|/// int setvbuf(FILE *stream, char *buf, int type, size_t size);
name|setvbuf
block|,
comment|/// double sin(double x);
name|sin
block|,
comment|/// float sinf(float x);
name|sinf
block|,
comment|/// double sinh(double x);
name|sinh
block|,
comment|/// float sinhf(float x);
name|sinhf
block|,
comment|/// long double sinhl(long double x);
name|sinhl
block|,
comment|/// long double sinl(long double x);
name|sinl
block|,
comment|/// int siprintf(char *str, const char *format, ...);
name|siprintf
block|,
comment|/// int snprintf(char *s, size_t n, const char *format, ...);
name|snprintf
block|,
comment|/// int sprintf(char *str, const char *format, ...);
name|sprintf
block|,
comment|/// double sqrt(double x);
name|sqrt
block|,
comment|/// float sqrtf(float x);
name|sqrtf
block|,
comment|/// long double sqrtl(long double x);
name|sqrtl
block|,
comment|/// int sscanf(const char *s, const char *format, ... );
name|sscanf
block|,
comment|/// int stat(const char *path, struct stat *buf);
name|stat
block|,
comment|/// int stat64(const char *path, struct stat64 *buf);
name|stat64
block|,
comment|/// int statvfs(const char *path, struct statvfs *buf);
name|statvfs
block|,
comment|/// int statvfs64(const char *path, struct statvfs64 *buf)
name|statvfs64
block|,
comment|/// char *stpcpy(char *s1, const char *s2);
name|stpcpy
block|,
comment|/// char *stpncpy(char *s1, const char *s2, size_t n);
name|stpncpy
block|,
comment|/// int strcasecmp(const char *s1, const char *s2);
name|strcasecmp
block|,
comment|/// char *strcat(char *s1, const char *s2);
name|strcat
block|,
comment|/// char *strchr(const char *s, int c);
name|strchr
block|,
comment|/// int strcmp(const char *s1, const char *s2);
name|strcmp
block|,
comment|/// int strcoll(const char *s1, const char *s2);
name|strcoll
block|,
comment|/// char *strcpy(char *s1, const char *s2);
name|strcpy
block|,
comment|/// size_t strcspn(const char *s1, const char *s2);
name|strcspn
block|,
comment|/// char *strdup(const char *s1);
name|strdup
block|,
comment|/// size_t strlen(const char *s);
name|strlen
block|,
comment|/// int strncasecmp(const char *s1, const char *s2, size_t n);
name|strncasecmp
block|,
comment|/// char *strncat(char *s1, const char *s2, size_t n);
name|strncat
block|,
comment|/// int strncmp(const char *s1, const char *s2, size_t n);
name|strncmp
block|,
comment|/// char *strncpy(char *s1, const char *s2, size_t n);
name|strncpy
block|,
comment|/// char *strndup(const char *s1, size_t n);
name|strndup
block|,
comment|/// size_t strnlen(const char *s, size_t maxlen);
name|strnlen
block|,
comment|/// char *strpbrk(const char *s1, const char *s2);
name|strpbrk
block|,
comment|/// char *strrchr(const char *s, int c);
name|strrchr
block|,
comment|/// size_t strspn(const char *s1, const char *s2);
name|strspn
block|,
comment|/// char *strstr(const char *s1, const char *s2);
name|strstr
block|,
comment|/// double strtod(const char *nptr, char **endptr);
name|strtod
block|,
comment|/// float strtof(const char *nptr, char **endptr);
name|strtof
block|,
comment|// char *strtok(char *s1, const char *s2);
name|strtok
block|,
comment|// char *strtok_r(char *s, const char *sep, char **lasts);
name|strtok_r
block|,
comment|/// long int strtol(const char *nptr, char **endptr, int base);
name|strtol
block|,
comment|/// long double strtold(const char *nptr, char **endptr);
name|strtold
block|,
comment|/// long long int strtoll(const char *nptr, char **endptr, int base);
name|strtoll
block|,
comment|/// unsigned long int strtoul(const char *nptr, char **endptr, int base);
name|strtoul
block|,
comment|/// unsigned long long int strtoull(const char *nptr, char **endptr,
comment|///                                 int base);
name|strtoull
block|,
comment|/// size_t strxfrm(char *s1, const char *s2, size_t n);
name|strxfrm
block|,
comment|/// int system(const char *command);
name|system
block|,
comment|/// double tan(double x);
name|tan
block|,
comment|/// float tanf(float x);
name|tanf
block|,
comment|/// double tanh(double x);
name|tanh
block|,
comment|/// float tanhf(float x);
name|tanhf
block|,
comment|/// long double tanhl(long double x);
name|tanhl
block|,
comment|/// long double tanl(long double x);
name|tanl
block|,
comment|/// clock_t times(struct tms *buffer);
name|times
block|,
comment|/// FILE *tmpfile(void);
name|tmpfile
block|,
comment|/// FILE *tmpfile64(void)
name|tmpfile64
block|,
comment|/// int toascii(int c);
name|toascii
block|,
comment|/// double trunc(double x);
name|trunc
block|,
comment|/// float truncf(float x);
name|truncf
block|,
comment|/// long double truncl(long double x);
name|truncl
block|,
comment|/// int uname(struct utsname *name);
name|uname
block|,
comment|/// int ungetc(int c, FILE *stream);
name|ungetc
block|,
comment|/// int unlink(const char *path);
name|unlink
block|,
comment|/// int unsetenv(const char *name);
name|unsetenv
block|,
comment|/// int utime(const char *path, const struct utimbuf *times);
name|utime
block|,
comment|/// int utimes(const char *path, const struct timeval times[2]);
name|utimes
block|,
comment|/// void *valloc(size_t size);
name|valloc
block|,
comment|/// int vfprintf(FILE *stream, const char *format, va_list ap);
name|vfprintf
block|,
comment|/// int vfscanf(FILE *stream, const char *format, va_list arg);
name|vfscanf
block|,
comment|/// int vprintf(const char *restrict format, va_list ap);
name|vprintf
block|,
comment|/// int vscanf(const char *format, va_list arg);
name|vscanf
block|,
comment|/// int vsnprintf(char *s, size_t n, const char *format, va_list ap);
name|vsnprintf
block|,
comment|/// int vsprintf(char *s, const char *format, va_list ap);
name|vsprintf
block|,
comment|/// int vsscanf(const char *s, const char *format, va_list arg);
name|vsscanf
block|,
comment|/// ssize_t write(int fildes, const void *buf, size_t nbyte);
name|write
block|,
name|NumLibFuncs
block|}
enum|;
block|}
comment|/// TargetLibraryInfo - This immutable pass captures information about what
comment|/// library functions are available for the current target, and allows a
comment|/// frontend to disable optimizations through -fno-builtin etc.
name|class
name|TargetLibraryInfo
range|:
name|public
name|ImmutablePass
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|unsigned
name|char
name|AvailableArray
index|[
operator|(
name|LibFunc
operator|::
name|NumLibFuncs
operator|+
literal|3
operator|)
operator|/
literal|4
index|]
block|;
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
block|,
name|std
operator|::
name|string
operator|>
name|CustomNames
block|;
specifier|static
specifier|const
name|char
operator|*
name|StandardNames
index|[
name|LibFunc
operator|::
name|NumLibFuncs
index|]
block|;    enum
name|AvailabilityState
block|{
name|StandardName
operator|=
literal|3
block|,
comment|// (memset to all ones)
name|CustomName
operator|=
literal|1
block|,
name|Unavailable
operator|=
literal|0
comment|// (memset to all zeros)
block|}
block|;
name|void
name|setState
argument_list|(
argument|LibFunc::Func F
argument_list|,
argument|AvailabilityState State
argument_list|)
block|{
name|AvailableArray
index|[
name|F
operator|/
literal|4
index|]
operator|&=
operator|~
operator|(
literal|3
operator|<<
literal|2
operator|*
operator|(
name|F
operator|&
literal|3
operator|)
operator|)
block|;
name|AvailableArray
index|[
name|F
operator|/
literal|4
index|]
operator||=
name|State
operator|<<
literal|2
operator|*
operator|(
name|F
operator|&
literal|3
operator|)
block|;   }
name|AvailabilityState
name|getState
argument_list|(
argument|LibFunc::Func F
argument_list|)
specifier|const
block|{
return|return
name|static_cast
operator|<
name|AvailabilityState
operator|>
operator|(
operator|(
name|AvailableArray
index|[
name|F
operator|/
literal|4
index|]
operator|>>
literal|2
operator|*
operator|(
name|F
operator|&
literal|3
operator|)
operator|)
operator|&
literal|3
operator|)
return|;
block|}
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|TargetLibraryInfo
argument_list|()
block|;
name|TargetLibraryInfo
argument_list|(
specifier|const
name|Triple
operator|&
name|T
argument_list|)
block|;
name|explicit
name|TargetLibraryInfo
argument_list|(
specifier|const
name|TargetLibraryInfo
operator|&
name|TLI
argument_list|)
block|;
comment|/// getLibFunc - Search for a particular function name.  If it is one of the
comment|/// known library functions, return true and set F to the corresponding value.
name|bool
name|getLibFunc
argument_list|(
argument|StringRef funcName
argument_list|,
argument|LibFunc::Func&F
argument_list|)
specifier|const
block|;
comment|/// has - This function is used by optimizations that want to match on or form
comment|/// a given library function.
name|bool
name|has
argument_list|(
argument|LibFunc::Func F
argument_list|)
specifier|const
block|{
return|return
name|getState
argument_list|(
name|F
argument_list|)
operator|!=
name|Unavailable
return|;
block|}
comment|/// hasOptimizedCodeGen - Return true if the function is both available as
comment|/// a builtin and a candidate for optimized code generation.
name|bool
name|hasOptimizedCodeGen
argument_list|(
argument|LibFunc::Func F
argument_list|)
specifier|const
block|{
if|if
condition|(
name|getState
argument_list|(
name|F
argument_list|)
operator|==
name|Unavailable
condition|)
return|return
name|false
return|;
switch|switch
condition|(
name|F
condition|)
block|{
default|default:
break|break;
case|case
name|LibFunc
operator|::
name|copysign
case|:
case|case
name|LibFunc
operator|::
name|copysignf
case|:
case|case
name|LibFunc
operator|::
name|copysignl
case|:
case|case
name|LibFunc
operator|::
name|fabs
case|:
case|case
name|LibFunc
operator|::
name|fabsf
case|:
case|case
name|LibFunc
operator|::
name|fabsl
case|:
case|case
name|LibFunc
operator|::
name|sin
case|:
case|case
name|LibFunc
operator|::
name|sinf
case|:
case|case
name|LibFunc
operator|::
name|sinl
case|:
case|case
name|LibFunc
operator|::
name|cos
case|:
case|case
name|LibFunc
operator|::
name|cosf
case|:
case|case
name|LibFunc
operator|::
name|cosl
case|:
case|case
name|LibFunc
operator|::
name|sqrt
case|:
case|case
name|LibFunc
operator|::
name|sqrtf
case|:
case|case
name|LibFunc
operator|::
name|sqrtl
case|:
case|case
name|LibFunc
operator|::
name|sqrt_finite
case|:
case|case
name|LibFunc
operator|::
name|sqrtf_finite
case|:
case|case
name|LibFunc
operator|::
name|sqrtl_finite
case|:
case|case
name|LibFunc
operator|::
name|floor
case|:
case|case
name|LibFunc
operator|::
name|floorf
case|:
case|case
name|LibFunc
operator|::
name|floorl
case|:
case|case
name|LibFunc
operator|::
name|nearbyint
case|:
case|case
name|LibFunc
operator|::
name|nearbyintf
case|:
case|case
name|LibFunc
operator|::
name|nearbyintl
case|:
case|case
name|LibFunc
operator|::
name|ceil
case|:
case|case
name|LibFunc
operator|::
name|ceilf
case|:
case|case
name|LibFunc
operator|::
name|ceill
case|:
case|case
name|LibFunc
operator|::
name|rint
case|:
case|case
name|LibFunc
operator|::
name|rintf
case|:
case|case
name|LibFunc
operator|::
name|rintl
case|:
case|case
name|LibFunc
operator|::
name|round
case|:
case|case
name|LibFunc
operator|::
name|roundf
case|:
case|case
name|LibFunc
operator|::
name|roundl
case|:
case|case
name|LibFunc
operator|::
name|trunc
case|:
case|case
name|LibFunc
operator|::
name|truncf
case|:
case|case
name|LibFunc
operator|::
name|truncl
case|:
case|case
name|LibFunc
operator|::
name|log2
case|:
case|case
name|LibFunc
operator|::
name|log2f
case|:
case|case
name|LibFunc
operator|::
name|log2l
case|:
case|case
name|LibFunc
operator|::
name|exp2
case|:
case|case
name|LibFunc
operator|::
name|exp2f
case|:
case|case
name|LibFunc
operator|::
name|exp2l
case|:
case|case
name|LibFunc
operator|::
name|memcmp
case|:
case|case
name|LibFunc
operator|::
name|strcmp
case|:
case|case
name|LibFunc
operator|::
name|strcpy
case|:
case|case
name|LibFunc
operator|::
name|stpcpy
case|:
case|case
name|LibFunc
operator|::
name|strlen
case|:
case|case
name|LibFunc
operator|::
name|strnlen
case|:
case|case
name|LibFunc
operator|::
name|memchr
case|:
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|StringRef
name|getName
argument_list|(
argument|LibFunc::Func F
argument_list|)
specifier|const
block|{
name|AvailabilityState
name|State
operator|=
name|getState
argument_list|(
name|F
argument_list|)
block|;
if|if
condition|(
name|State
operator|==
name|Unavailable
condition|)
return|return
name|StringRef
argument_list|()
return|;
if|if
condition|(
name|State
operator|==
name|StandardName
condition|)
return|return
name|StandardNames
index|[
name|F
index|]
return|;
name|assert
argument_list|(
name|State
operator|==
name|CustomName
argument_list|)
expr_stmt|;
return|return
name|CustomNames
operator|.
name|find
argument_list|(
name|F
argument_list|)
operator|->
name|second
return|;
block|}
end_decl_stmt

begin_comment
comment|/// setUnavailable - this can be used by whatever sets up TargetLibraryInfo to
end_comment

begin_comment
comment|/// ban use of specific library functions.
end_comment

begin_decl_stmt
name|void
name|setUnavailable
argument_list|(
name|LibFunc
operator|::
name|Func
name|F
argument_list|)
block|{
name|setState
argument_list|(
name|F
argument_list|,
name|Unavailable
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|setAvailable
argument_list|(
name|LibFunc
operator|::
name|Func
name|F
argument_list|)
block|{
name|setState
argument_list|(
name|F
argument_list|,
name|StandardName
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|setAvailableWithName
argument_list|(
name|LibFunc
operator|::
name|Func
name|F
argument_list|,
name|StringRef
name|Name
argument_list|)
block|{
if|if
condition|(
name|StandardNames
index|[
name|F
index|]
operator|!=
name|Name
condition|)
block|{
name|setState
argument_list|(
name|F
argument_list|,
name|CustomName
argument_list|)
expr_stmt|;
name|CustomNames
index|[
name|F
index|]
operator|=
name|Name
expr_stmt|;
name|assert
argument_list|(
name|CustomNames
operator|.
name|find
argument_list|(
name|F
argument_list|)
operator|!=
name|CustomNames
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|setState
argument_list|(
name|F
argument_list|,
name|StandardName
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|/// disableAllFunctions - This disables all builtins, which is used for
end_comment

begin_comment
comment|/// options like -fno-builtin.
end_comment

begin_function_decl
name|void
name|disableAllFunctions
parameter_list|()
function_decl|;
end_function_decl

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

