begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* the default search path for Lisp function "load" */
end_comment

begin_define
define|#
directive|define
name|PATH_LOADSEARCH
value|":/usr/new/lib/emacs/lisp"
end_define

begin_comment
comment|/* the extra search path for programs to invoke.  This is appended to whatever the PATH environment variable says. */
end_comment

begin_define
define|#
directive|define
name|PATH_EXEC
value|"/usr/new/lib/emacs/etc"
end_define

begin_comment
comment|/* the name of the directory that contains lock files  with which we record what files are being modified in Emacs.  This directory should be writable by everyone.  THE STRING MUST END WITH A SLASH!!!  */
end_comment

begin_define
define|#
directive|define
name|PATH_LOCK
value|"/usr/new/lib/emacs/lock/"
end_define

begin_comment
comment|/* the name of the file !!!SuperLock!!! in the directory  specified by PATH_LOCK.  Yes, this is redundant.  */
end_comment

begin_define
define|#
directive|define
name|PATH_SUPERLOCK
value|"/usr/new/lib/emacs/lock/!!!SuperLock!!!"
end_define

end_unit

