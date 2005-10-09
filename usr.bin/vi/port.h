begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)port.h.in	8.13 (Berkeley) 6/12/96 */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Declare the basic types, if they aren't already declared.  Named and  * some system's db.h files protect them with __BIT_TYPES_DEFINED__.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BIT_TYPES_DEFINED__
end_ifndef

begin_define
define|#
directive|define
name|__BIT_TYPES_DEFINED__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX  * Some versions of System V changed the number of arguments to gettimeofday  * without changing the name.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BROKEN_GETTIMEOFDAY
end_ifdef

begin_define
define|#
directive|define
name|gettimeofday
parameter_list|(
name|tv
parameter_list|,
name|tz
parameter_list|)
value|gettimeofday(tv)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * XXX  * If we don't have mmap, we fake it with read and write, but we'll  * still need the header information.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SYS_MMAN_H
end_ifndef

begin_define
define|#
directive|define
name|MAP_SHARED
value|1
end_define

begin_comment
comment|/* share changes */
end_comment

begin_define
define|#
directive|define
name|MAP_PRIVATE
value|2
end_define

begin_comment
comment|/* changes are private */
end_comment

begin_define
define|#
directive|define
name|PROT_READ
value|0x1
end_define

begin_comment
comment|/* pages can be read */
end_comment

begin_define
define|#
directive|define
name|PROT_WRITE
value|0x2
end_define

begin_comment
comment|/* pages can be written */
end_comment

begin_define
define|#
directive|define
name|PROT_EXEC
value|0x4
end_define

begin_comment
comment|/* pages can be executed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX  * POSIX 1003.1 names for file descriptors.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STDERR_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_comment
comment|/* ANSI C #defines */
end_comment

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX  * POSIX 1003.1 names for seek settings.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_END
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_comment
comment|/* POSIX 1003.1 seek values */
end_comment

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Hack _POSIX_VDISABLE to \377 since Ultrix doesn't honor _POSIX_VDISABLE  * (treats it as ^@).  The symptom is that the ^@ keystroke immediately  * drops core.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BROKEN_VDISABLE
end_ifdef

begin_undef
undef|#
directive|undef
name|_POSIX_VDISABLE
end_undef

begin_define
define|#
directive|define
name|_POSIX_VDISABLE
value|((unsigned char)'\377')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX  * POSIX 1003.1 tty disabling character.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_VDISABLE
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_VDISABLE
value|0
end_define

begin_comment
comment|/* Some systems used 0. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX  * 4.4BSD extension to only set the software termios bits.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TCSASOFT
end_ifndef

begin_comment
comment|/* 4.4BSD extension. */
end_comment

begin_define
define|#
directive|define
name|TCSASOFT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX  * POSIX 1003.1 maximum path length.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PATH_MAX
end_ifdef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATH_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXPATHLEN
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX  * MIN, MAX, historically in<sys/param.h>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|)
value|((_a)<(_b)?(_b):(_a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|)
value|((_a)<(_b)?(_a):(_b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX  * "DB" isn't always portable, and we want the private information.  */
end_comment

begin_define
define|#
directive|define
name|DB
value|L__DB
end_define

begin_undef
undef|#
directive|undef
name|pgno_t
end_undef

begin_comment
comment|/* IRIX has its own version. */
end_comment

begin_define
define|#
directive|define
name|pgno_t
value|L__db_pgno_t
end_define

begin_comment
comment|/*  * XXX  * 4.4BSD extension to provide lock values in the open(2) call.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|O_EXLOCK
end_ifndef

begin_define
define|#
directive|define
name|O_EXLOCK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_SHLOCK
end_ifndef

begin_define
define|#
directive|define
name|O_SHLOCK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX  * POSIX 1003.1 bad file format errno.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EFTYPE
end_ifndef

begin_define
define|#
directive|define
name|EFTYPE
value|EINVAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX  * POSIX 1003.2 RE length limit.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX2_RE_DUP_MAX
end_ifndef

begin_define
define|#
directive|define
name|_POSIX2_RE_DUP_MAX
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX  * 4.4BSD extension to determine if a program dropped core from the exit  * status.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WCOREDUMP
end_ifndef

begin_define
define|#
directive|define
name|WCOREDUMP
parameter_list|(
name|a
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX  * Endian-ness of the machine.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LITTLE_ENDIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BIG_ENDIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
end_if

begin_if
if|#
directive|if
name|WORDS_BIGENDIAN
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

