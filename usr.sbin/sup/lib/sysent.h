begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator   or   Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the rights  * to redistribute these changes.  */
end_comment

begin_comment
comment|/*  **********************************************************************  * HISTORY  * $Log: sysent.h,v $  * Revision 1.1.1.1  1993/08/21  00:46:35  jkh  * Current sup with compression support.  *  * Revision 1.1.1.1  1993/05/21  14:52:19  cgd  * initial import of CMU's SUP to NetBSD  *  * Revision 2.4  89/12/05  16:02:00  mrt  * 	Removed include of sys/features.h as it is no longer  * 	exported or needed.  * 	[89/12/05            mrt]  *   * Revision 2.3  89/01/20  15:44:24  gm0w  * 	Added externs to the non-STDC case for functions that do not  * 	have int return values.  * 	[88/12/17            gm0w]  *   * Revision 2.2  88/12/14  23:35:52  mja  * 	Created.  * 	[88/01/06            jjk]  *   **********************************************************************  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYSENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYSENT_H_
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifndef
unit|extern int access(const char *, int); extern int acct(const char *); extern int brk(void *); extern int sbrk(int); extern int chdir(const char *); extern int chmod(const char *, int); extern int fchmod(int, int); extern int chown(const char *, int, int); extern int fchown(int, int, int); extern int chroot(const char *); extern int close(int); extern int creat(const char *, int); extern int dup(int); extern int dup2(int, int); extern int execve(const char *, const char **, const char **); extern void _exit(int); extern int fcntl(int, int, int); extern int flock(int, int); extern int fork(void); extern int fsync(int); extern int getdtablesize(void); extern gid_t getgid(void); extern gid_t getegid(void); extern int getgroups(int, int *); extern long gethostid(void); extern int sethostid(long); extern int gethostname(char *, int); extern int sethostname(const char *, int); extern int getpagesize(void); extern int getpgrp(int); extern int getpid(void); extern int getppid(void); extern uid_t getuid(void); extern uid_t geteuid(void); extern int ioctl(int, unsigned long, void *); extern int kill(int, int); extern int killpg(int, int); extern int link(const char *, const char *); extern off_t lseek(int, off_t, int); extern int mkdir(const char *, int); extern int mknod(const char *, int, int); extern int mount(const char *, const char *, int); extern int umount(const char *); extern int open(const char *, int, int); extern int pipe(int *); extern int profil(void *, int, int, int); extern int ptrace(int, int, int *, int); extern int quota(int, int, int, void *); extern int read(int, void *, int); extern int readlink(const char *, void *, int); extern int reboot(int); extern int rename(const char *, const char *); extern int rmdir(const char *); extern int select(int, fd_set *, fd_set *, fd_set *, struct timeval *); extern int setgroups(int, int *); extern int setpgrp(int, int); extern int setquota(const char *, const char *); extern int setregid(gid_t, gid_t); extern int setreuid(uid_t, uid_t); extern int swapon(const char *); extern int symlink(const char *, const char *); extern void sync(void); extern int syscall(int, ...); extern int truncate(const char *, off_t); extern int ftruncate(int, off_t); extern int umask(int); extern int unlink(const char *); extern int vfork(void); extern void vhangup(void); extern int write(int, void *, int);
ifndef|#
directive|ifndef
name|_VICEIOCTL
end_ifndef

begin_include
include|#
directive|include
file|<sys/viceioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _VICEIOCTL */
end_comment

begin_endif
unit|extern int icreate(int, int, int, int, int, int); extern int iinc(int, int, long); extern int idec(int, int, long); extern int iopen(int, int, int); extern int iread(int, int, int, int, void *, int); extern int iwrite(int, int, int, int, void *, int); extern int pioctl(const char *, unsigned long, struct ViceIoctl *, int); extern int setpag(void);
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
else|defined(__STDC__)
end_else

begin_function_decl
specifier|extern
name|gid_t
name|getgid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|gid_t
name|getegid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|gethostid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uid_t
name|getuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uid_t
name|geteuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|off_t
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _SYSENT_H_ */
end_comment

end_unit

