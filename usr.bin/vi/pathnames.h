begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)pathnames.h.in	8.4 (Berkeley) 6/26/96 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_BSHELL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_BSHELL
value|"/bin/sh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_EXRC
end_ifndef

begin_define
define|#
directive|define
name|_PATH_EXRC
value|".exrc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_MSGCAT
end_ifndef

begin_define
define|#
directive|define
name|_PATH_MSGCAT
value|"/usr/share/vi/catalog/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_NEXRC
end_ifndef

begin_define
define|#
directive|define
name|_PATH_NEXRC
value|".nexrc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_PRESERVE
end_ifndef

begin_define
define|#
directive|define
name|_PATH_PRESERVE
value|"/var/tmp/vi.recover"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SYSV_PTY
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SYSV_PTY
value|"/dev/ptmx"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SENDMAIL
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SENDMAIL
value|"/usr/sbin/sendmail"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_SYSEXRC
end_ifndef

begin_define
define|#
directive|define
name|_PATH_SYSEXRC
value|"/etc/vi.exrc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_TAGS
end_ifndef

begin_define
define|#
directive|define
name|_PATH_TAGS
value|"tags"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_TMP
end_ifndef

begin_define
define|#
directive|define
name|_PATH_TMP
value|"/tmp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_TTY
end_ifndef

begin_define
define|#
directive|define
name|_PATH_TTY
value|"/dev/tty"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

