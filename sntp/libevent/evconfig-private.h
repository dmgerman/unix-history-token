begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* evconfig-private.h.  Generated from evconfig-private.h.in by configure.  */
end_comment

begin_comment
comment|/* evconfig-private.h template - see "Configuration Header Templates" */
end_comment

begin_comment
comment|/* in AC manual.  Kevin Bowling<kevin.bowling@kev009.com */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVCONFIG_PRIVATE_H_INCLUDED_
end_ifndef

begin_define
define|#
directive|define
name|EVCONFIG_PRIVATE_H_INCLUDED_
end_define

begin_comment
comment|/* Enable extensions on AIX 3, Interix.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALL_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_ALL_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable GNU extensions on systems that have them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_GNU_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable threading extensions on Solaris.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_PTHREAD_SEMANTICS
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_PTHREAD_SEMANTICS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable extensions on HP NonStop.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TANDEM_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_TANDEM_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable general extensions on Solaris.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EXTENSIONS__
end_ifndef

begin_define
define|#
directive|define
name|__EXTENSIONS__
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in a file offset, on hosts where this is settable. */
end_comment

begin_define
define|#
directive|define
name|_FILE_OFFSET_BITS
value|64
end_define

begin_comment
comment|/* Define for large files, on AIX-style hosts. */
end_comment

begin_comment
comment|/* #undef _LARGE_FILES */
end_comment

begin_comment
comment|/* Define to 1 if on MINIX. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MINIX
end_ifndef

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to 2 if the system does not provide POSIX.1 features except with    this defined. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_1_SOURCE
end_ifndef

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to 1 if you need to in order for `stat' and other things to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

