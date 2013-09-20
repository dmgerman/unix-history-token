begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: pathnames.h.in,v 8.7 2012/04/23 08:34:52 zy Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Read standard system paths first. */
end_comment

begin_include
include|#
directive|include
file|<paths.h>
end_include

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
value|"/var/tmp/vi.recover/"
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

end_unit

