begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1996, 1997, 1998, 1999, 2000 John D. Polstra.  * Copyright 2003 Alexander Kabaev<kan@FreeBSD.ORG>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PATHS_H
end_ifndef

begin_define
define|#
directive|define
name|PATHS_H
end_define

begin_undef
undef|#
directive|undef
name|_PATH_ELF_HINTS
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_32BIT
end_ifdef

begin_define
define|#
directive|define
name|_PATH_ELF_HINTS
value|"/var/run/ld-elf32.so.hints"
end_define

begin_define
define|#
directive|define
name|_PATH_LIBMAP_CONF
value|"/etc/libmap32.conf"
end_define

begin_define
define|#
directive|define
name|_PATH_RTLD
value|"/libexec/ld-elf32.so.1"
end_define

begin_define
define|#
directive|define
name|STANDARD_LIBRARY_PATH
value|"/lib32:/usr/lib32"
end_define

begin_define
define|#
directive|define
name|LD_
value|"LD_32_"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_ELF_HINTS
end_ifndef

begin_define
define|#
directive|define
name|_PATH_ELF_HINTS
value|"/var/run/ld-elf.so.hints"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_LIBMAP_CONF
end_ifndef

begin_define
define|#
directive|define
name|_PATH_LIBMAP_CONF
value|"/etc/libmap.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_RTLD
end_ifndef

begin_define
define|#
directive|define
name|_PATH_RTLD
value|"/libexec/ld-elf.so.1"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STANDARD_LIBRARY_PATH
end_ifndef

begin_define
define|#
directive|define
name|STANDARD_LIBRARY_PATH
value|"/lib/casper:/lib:/usr/lib"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LD_
end_ifndef

begin_define
define|#
directive|define
name|LD_
value|"LD_"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_PATH_SOFT_ELF_HINTS
value|"/var/run/ld-elf-soft.so.hints"
end_define

begin_define
define|#
directive|define
name|_PATH_SOFT_LIBMAP_CONF
value|"/etc/libmap-soft.conf"
end_define

begin_define
define|#
directive|define
name|_PATH_SOFT_RTLD
value|"/libexec/ld-elf.so.1"
end_define

begin_define
define|#
directive|define
name|SOFT_STANDARD_LIBRARY_PATH
value|"/usr/libsoft"
end_define

begin_define
define|#
directive|define
name|LD_SOFT_
value|"LD_SOFT_"
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ld_elf_hints_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ld_path_libmap_conf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ld_path_rtld
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ld_standard_library_path
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ld_env_prefix
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PATHS_H */
end_comment

end_unit

