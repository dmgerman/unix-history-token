begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)paths.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PATHS_H_
end_ifndef

begin_define
define|#
directive|define
name|_PATHS_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* Default search path. */
end_comment

begin_define
define|#
directive|define
name|_PATH_DEFPATH
value|"/usr/bin:/bin"
end_define

begin_comment
comment|/* All standard utilities path. */
end_comment

begin_define
define|#
directive|define
name|_PATH_STDPATH
define|\
value|"/usr/bin:/bin:/usr/sbin:/sbin:"
end_define

begin_comment
comment|/* Locate system binaries */
end_comment

begin_define
define|#
directive|define
name|_PATH_SYSPATH
define|\
value|"/sbin:/usr/sbin"
end_define

begin_define
define|#
directive|define
name|_PATH_AUTHCONF
value|"/etc/auth.conf"
end_define

begin_define
define|#
directive|define
name|_PATH_BSHELL
value|"/bin/sh"
end_define

begin_define
define|#
directive|define
name|_PATH_CAPABILITY
value|"/etc/capability"
end_define

begin_define
define|#
directive|define
name|_PATH_CAPABILITY_DB
value|"/etc/capability.db"
end_define

begin_define
define|#
directive|define
name|_PATH_CONSOLE
value|"/dev/console"
end_define

begin_define
define|#
directive|define
name|_PATH_CP
value|"/bin/cp"
end_define

begin_define
define|#
directive|define
name|_PATH_CSHELL
value|"/bin/csh"
end_define

begin_define
define|#
directive|define
name|_PATH_DEFTAPE
value|"/dev/sa0"
end_define

begin_define
define|#
directive|define
name|_PATH_DEVNULL
value|"/dev/null"
end_define

begin_define
define|#
directive|define
name|_PATH_DEVZERO
value|"/dev/zero"
end_define

begin_define
define|#
directive|define
name|_PATH_DRUM
value|"/dev/drum"
end_define

begin_define
define|#
directive|define
name|_PATH_ETC
value|"/etc"
end_define

begin_define
define|#
directive|define
name|_PATH_FTPUSERS
value|"/etc/ftpusers"
end_define

begin_define
define|#
directive|define
name|_PATH_FWMEM
value|"/dev/fwmem"
end_define

begin_define
define|#
directive|define
name|_PATH_HALT
value|"/sbin/halt"
end_define

begin_define
define|#
directive|define
name|_PATH_IFCONFIG
value|"/sbin/ifconfig"
end_define

begin_define
define|#
directive|define
name|_PATH_KMEM
value|"/dev/kmem"
end_define

begin_define
define|#
directive|define
name|_PATH_LIBMAP_CONF
value|"/etc/libmap.conf"
end_define

begin_define
define|#
directive|define
name|_PATH_LOCALE
value|"/usr/share/locale"
end_define

begin_define
define|#
directive|define
name|_PATH_LOGIN
value|"/usr/bin/login"
end_define

begin_define
define|#
directive|define
name|_PATH_MAILDIR
value|"/var/mail"
end_define

begin_define
define|#
directive|define
name|_PATH_MAN
value|"/usr/share/man"
end_define

begin_define
define|#
directive|define
name|_PATH_MDCONFIG
value|"/sbin/mdconfig"
end_define

begin_define
define|#
directive|define
name|_PATH_MEM
value|"/dev/mem"
end_define

begin_define
define|#
directive|define
name|_PATH_MKSNAP_FFS
value|"/sbin/mksnap_ffs"
end_define

begin_define
define|#
directive|define
name|_PATH_MOUNT
value|"/sbin/mount"
end_define

begin_define
define|#
directive|define
name|_PATH_NEWFS
value|"/sbin/newfs"
end_define

begin_define
define|#
directive|define
name|_PATH_NOLOGIN
value|"/var/run/nologin"
end_define

begin_define
define|#
directive|define
name|_PATH_RCP
value|"/bin/rcp"
end_define

begin_define
define|#
directive|define
name|_PATH_REBOOT
value|"/sbin/reboot"
end_define

begin_define
define|#
directive|define
name|_PATH_RLOGIN
value|"/usr/bin/rlogin"
end_define

begin_define
define|#
directive|define
name|_PATH_RM
value|"/bin/rm"
end_define

begin_define
define|#
directive|define
name|_PATH_RSH
value|"/usr/bin/rsh"
end_define

begin_define
define|#
directive|define
name|_PATH_SENDMAIL
value|"/usr/sbin/sendmail"
end_define

begin_define
define|#
directive|define
name|_PATH_SHELLS
value|"/etc/shells"
end_define

begin_define
define|#
directive|define
name|_PATH_TTY
value|"/dev/tty"
end_define

begin_define
define|#
directive|define
name|_PATH_UNIX
value|"don't use _PATH_UNIX"
end_define

begin_define
define|#
directive|define
name|_PATH_VI
value|"/usr/bin/vi"
end_define

begin_define
define|#
directive|define
name|_PATH_WALL
value|"/usr/bin/wall"
end_define

begin_comment
comment|/* Provide trailing slash, since mostly used for building pathnames. */
end_comment

begin_define
define|#
directive|define
name|_PATH_DEV
value|"/dev/"
end_define

begin_define
define|#
directive|define
name|_PATH_TMP
value|"/tmp/"
end_define

begin_define
define|#
directive|define
name|_PATH_VARDB
value|"/var/db/"
end_define

begin_define
define|#
directive|define
name|_PATH_VARRUN
value|"/var/run/"
end_define

begin_define
define|#
directive|define
name|_PATH_VARTMP
value|"/var/tmp/"
end_define

begin_define
define|#
directive|define
name|_PATH_YP
value|"/var/yp/"
end_define

begin_define
define|#
directive|define
name|_PATH_UUCPLOCK
value|"/var/spool/lock/"
end_define

begin_comment
comment|/* How to get the correct name of the kernel. */
end_comment

begin_function_decl
name|__BEGIN_DECLS
specifier|const
name|char
modifier|*
name|getbootfile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|RESCUE
end_ifdef

begin_undef
undef|#
directive|undef
name|_PATH_DEFPATH
end_undef

begin_define
define|#
directive|define
name|_PATH_DEFPATH
value|"/rescue:/usr/bin:/bin"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_STDPATH
end_undef

begin_define
define|#
directive|define
name|_PATH_STDPATH
value|"/rescue:/usr/bin:/bin:/usr/sbin:/sbin"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_SYSPATH
end_undef

begin_define
define|#
directive|define
name|_PATH_SYSPATH
value|"/rescue:/sbin:/usr/sbin"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_BSHELL
end_undef

begin_define
define|#
directive|define
name|_PATH_BSHELL
value|"/rescue/sh"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_CP
end_undef

begin_define
define|#
directive|define
name|_PATH_CP
value|"/rescue/cp"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_CSHELL
end_undef

begin_define
define|#
directive|define
name|_PATH_CSHELL
value|"/rescue/csh"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_HALT
end_undef

begin_define
define|#
directive|define
name|_PATH_HALT
value|"/rescue/halt"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_IFCONFIG
end_undef

begin_define
define|#
directive|define
name|_PATH_IFCONFIG
value|"/rescue/ifconfig"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_MDCONFIG
end_undef

begin_define
define|#
directive|define
name|_PATH_MDCONFIG
value|"/rescue/mdconfig"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_MOUNT
end_undef

begin_define
define|#
directive|define
name|_PATH_MOUNT
value|"/rescue/mount"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_NEWFS
end_undef

begin_define
define|#
directive|define
name|_PATH_NEWFS
value|"/rescue/newfs"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_RCP
end_undef

begin_define
define|#
directive|define
name|_PATH_RCP
value|"/rescue/rcp"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_REBOOT
end_undef

begin_define
define|#
directive|define
name|_PATH_REBOOT
value|"/rescue/reboot"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_RM
end_undef

begin_define
define|#
directive|define
name|_PATH_RM
value|"/rescue/rm"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_VI
end_undef

begin_define
define|#
directive|define
name|_PATH_VI
value|"/rescue/vi"
end_define

begin_undef
undef|#
directive|undef
name|_PATH_WALL
end_undef

begin_define
define|#
directive|define
name|_PATH_WALL
value|"/rescue/wall"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RESCUE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PATHS_H_ */
end_comment

end_unit

