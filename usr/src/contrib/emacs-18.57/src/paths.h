begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* The default search path for Lisp function "load".    This sets load-path.  */
end_comment

begin_define
define|#
directive|define
name|PATH_LOADSEARCH
value|"/usr/contrib/lib/emacs/lisp"
end_define

begin_comment
comment|/* the extra search path for programs to invoke.  This is appended to whatever the PATH environment variable says  to set the Lisp variable exec-path and the first file namein it   sets the Lisp variable exec-directory.  */
end_comment

begin_define
define|#
directive|define
name|PATH_EXEC
value|"/usr/contrib/lib/emacs/etc"
end_define

begin_comment
comment|/* the name of the directory that contains lock files  with which we record what files are being modified in Emacs.  This directory should be writable by everyone.  THE STRING MUST END WITH A SLASH!!!  */
end_comment

begin_define
define|#
directive|define
name|PATH_LOCK
value|"/var/emacs/lock/"
end_define

begin_comment
comment|/* the name of the file !!!SuperLock!!! in the directory  specified by PATH_LOCK.  Yes, this is redundant.  */
end_comment

begin_define
define|#
directive|define
name|PATH_SUPERLOCK
value|"/var/emacs/lock/!!!SuperLock!!!"
end_define

end_unit

