begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)acconfig.h	8.18 (Berkeley) 7/2/96 */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_undef
undef|#
directive|undef
name|ssize_t
end_undef

begin_comment
comment|/* Define if you want a debugging version. */
end_comment

begin_undef
undef|#
directive|undef
name|DEBUG
end_undef

begin_comment
comment|/* Define if you have a System V-style (broken) gettimeofday. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_BROKEN_GETTIMEOFDAY
end_undef

begin_comment
comment|/* Define if you have a Ultrix-style (broken) vdisable. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_BROKEN_VDISABLE
end_undef

begin_comment
comment|/* Define if you have a BSD version of curses. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_BSD_CURSES
end_undef

begin_comment
comment|/* Define if you have the curses(3) addnstr function. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_CURSES_ADDNSTR
end_undef

begin_comment
comment|/* Define if you have the curses(3) beep function. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_CURSES_BEEP
end_undef

begin_comment
comment|/* Define if you have the curses(3) flash function. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_CURSES_FLASH
end_undef

begin_comment
comment|/* Define if you have the curses(3) idlok function. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_CURSES_IDLOK
end_undef

begin_comment
comment|/* Define if you have the curses(3) keypad function. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_CURSES_KEYPAD
end_undef

begin_comment
comment|/* Define if you have the curses(3) newterm function. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_CURSES_NEWTERM
end_undef

begin_comment
comment|/* Define if you have the curses(3) setupterm function. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_CURSES_SETUPTERM
end_undef

begin_comment
comment|/* Define if you have the curses(3) tigetstr/tigetnum functions. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_CURSES_TIGETSTR
end_undef

begin_comment
comment|/* Define if you have the DB __hash_open call in the C library. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_DB_HASH_OPEN
end_undef

begin_comment
comment|/* Define if you have the chsize(2) system call. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_FTRUNCATE_CHSIZE
end_undef

begin_comment
comment|/* Define if you have the ftruncate(2) system call. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_FTRUNCATE_FTRUNCATE
end_undef

begin_comment
comment|/* Define if you have fcntl(2) style locking. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_LOCK_FCNTL
end_undef

begin_comment
comment|/* Define if you have flock(2) style locking. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_LOCK_FLOCK
end_undef

begin_comment
comment|/* Define if you want to compile in the Perl interpreter. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PERL_INTERP
end_undef

begin_comment
comment|/* Define if your Perl is at least 5.003_01. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PERL_5_003_01
end_undef

begin_comment
comment|/* Define if you have the Berkeley style revoke(2) system call. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_REVOKE
end_undef

begin_comment
comment|/* Define if you have the Berkeley style strsep(3) function. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_STRSEP
end_undef

begin_comment
comment|/* Define if you have<sys/mman.h> */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SYS_MMAN_H
end_undef

begin_comment
comment|/* Define if you have<sys/select.h> */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SYS_SELECT_H
end_undef

begin_comment
comment|/* Define if you have the System V style pty calls. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SYS5_PTY
end_undef

begin_comment
comment|/* Define if you want to compile in the Tcl interpreter. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_TCL_INTERP
end_undef

begin_comment
comment|/* Define if your sprintf returns a pointer, not a length. */
end_comment

begin_undef
undef|#
directive|undef
name|SPRINTF_RET_CHARPNT
end_undef

end_unit

