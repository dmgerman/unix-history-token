begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|config_h
end_ifndef

begin_define
define|#
directive|define
name|config_h
end_define

begin_comment
comment|/* config.h  * This file was produced by running the config.h.SH script, which  * gets its values from config.sh, which is generally produced by  * running Configure.  *  * Feel free to modify any of this as the need arises.  Note, however,  * that running config.h.SH again will wipe out any changes you've made.  * For a more permanent change edit config.sh and rerun config.h.SH.  */
end_comment

begin_comment
comment|/*SUPPRESS 460*/
end_comment

begin_comment
comment|/*#undef	EUNICE		*/
end_comment

begin_comment
comment|/*#undef	VMS		*/
end_comment

begin_comment
comment|/* LOC_SED  *     This symbol holds the complete pathname to the sed program.  */
end_comment

begin_define
define|#
directive|define
name|LOC_SED
value|"/usr/bin/sed"
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* ALIGN_BYTES  *	This symbol contains the number of bytes required to align a double.  *	Usual values are 2, 4, and 8.  */
end_comment

begin_define
define|#
directive|define
name|ALIGN_BYTES
value|4
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* BIN  *	This symbol holds the name of the directory in which the user wants  *	to keep publicly executable images for the package in question.  It  *	is most often a local directory such as /usr/local/bin.  */
end_comment

begin_define
define|#
directive|define
name|BIN
value|"/usr/bin"
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* BYTEORDER  *	This symbol contains an encoding of the order of bytes in a long.  *	Usual values (in hex) are 0x1234, 0x4321, 0x2143, 0x3412...  */
end_comment

begin_define
define|#
directive|define
name|BYTEORDER
value|0x1234
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* CPPSTDIN  *	This symbol contains the first part of the string which will invoke  *	the C preprocessor on the standard input and produce to standard  *	output.	 Typical value of "cc -E" or "/lib/cpp".  */
end_comment

begin_comment
comment|/* CPPMINUS  *	This symbol contains the second part of the string which will invoke  *	the C preprocessor on the standard input and produce to standard  *	output.  This symbol will have the value "-" if CPPSTDIN needs a minus  *	to specify standard input, otherwise the value is "".  */
end_comment

begin_define
define|#
directive|define
name|CPPSTDIN
value|"cc -E"
end_define

begin_define
define|#
directive|define
name|CPPMINUS
value|"-"
end_define

begin_comment
comment|/* HAS_BCMP  *	This symbol, if defined, indicates that the bcmp routine is available  *	to compare blocks of memory.  If undefined, use memcmp.  If that's  *	not available, roll your own.  */
end_comment

begin_define
define|#
directive|define
name|HAS_BCMP
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_BCOPY  *	This symbol, if defined, indicates that the bcopy routine is available  *	to copy blocks of memory.  Otherwise you should probably use memcpy().  *	If neither is defined, roll your own.  */
end_comment

begin_comment
comment|/* SAFE_BCOPY  *	This symbol, if defined, indicates that the bcopy routine is available  *	to copy potentially overlapping copy blocks of bcopy.  Otherwise you  *	should probably use memmove() or memcpy().  If neither is defined,  *	roll your own.  */
end_comment

begin_define
define|#
directive|define
name|HAS_BCOPY
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|SAFE_BCOPY
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_BZERO  *	This symbol, if defined, indicates that the bzero routine is available  *	to zero blocks of memory.  Otherwise you should probably use memset()  *	or roll your own.  */
end_comment

begin_define
define|#
directive|define
name|HAS_BZERO
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* CASTNEGFLOAT  *	This symbol, if defined, indicates that this C compiler knows how to  *	cast negative or large floating point numbers to unsigned longs, ints  *	and shorts.  */
end_comment

begin_comment
comment|/* CASTFLAGS  *	This symbol contains flags that say what difficulties the compiler  *	has casting odd floating values to unsigned long:  *		1 = couldn't cast< 0  *		2 = couldn't cast>= 0x80000000  */
end_comment

begin_define
define|#
directive|define
name|CASTNEGFLOAT
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|CASTFLAGS
value|0
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* CHARSPRINTF  *	This symbol is defined if this system declares "char *sprintf()" in  *	stdio.h.  The trend seems to be to declare it as "int sprintf()".  It  *	is up to the package author to declare sprintf correctly based on the  *	symbol.  */
end_comment

begin_comment
comment|/*#undef	CHARSPRINTF 	*/
end_comment

begin_comment
comment|/* HAS_CHSIZE  *	This symbol, if defined, indicates that the chsize routine is available  *	to truncate files.  You might need a -lx to get this routine.  */
end_comment

begin_comment
comment|/*#undef	HAS_CHSIZE		*/
end_comment

begin_comment
comment|/* HAS_CRYPT  *	This symbol, if defined, indicates that the crypt routine is available  *	to encrypt passwords and the like.  */
end_comment

begin_define
define|#
directive|define
name|HAS_CRYPT
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* CSH  *	This symbol, if defined, indicates that the C-shell exists.  *	If defined, contains the full pathname of csh.  */
end_comment

begin_define
define|#
directive|define
name|CSH
value|"/bin/csh"
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* DOSUID  *	This symbol, if defined, indicates that the C program should  *	check the script that it is executing for setuid/setgid bits, and  *	attempt to emulate setuid/setgid on systems that have disabled  *	setuid #! scripts because the kernel can't do it securely.  *	It is up to the package designer to make sure that this emulation  *	is done securely.  Among other things, it should do an fstat on  *	the script it just opened to make sure it really is a setuid/setgid  *	script, it should make sure the arguments passed correspond exactly  *	to the argument on the #! line, and it should not trust any  *	subprocesses to which it must pass the filename rather than the  *	file descriptor of the script to be executed.  */
end_comment

begin_comment
comment|/*#undef DOSUID		*/
end_comment

begin_comment
comment|/* HAS_DUP2  *	This symbol, if defined, indicates that the dup2 routine is available  *	to dup file descriptors.  Otherwise you should use dup().  */
end_comment

begin_define
define|#
directive|define
name|HAS_DUP2
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_FCHMOD  *	This symbol, if defined, indicates that the fchmod routine is available  *	to change mode of opened files.  If unavailable, use chmod().  */
end_comment

begin_define
define|#
directive|define
name|HAS_FCHMOD
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_FCHOWN  *	This symbol, if defined, indicates that the fchown routine is available  *	to change ownership of opened files.  If unavailable, use chown().  */
end_comment

begin_define
define|#
directive|define
name|HAS_FCHOWN
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_FCNTL  *	This symbol, if defined, indicates to the C program that  *	the fcntl() function exists.  */
end_comment

begin_define
define|#
directive|define
name|HAS_FCNTL
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* FLEXFILENAMES  *	This symbol, if defined, indicates that the system supports filenames  *	longer than 14 characters.  */
end_comment

begin_define
define|#
directive|define
name|FLEXFILENAMES
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_FLOCK  *	This symbol, if defined, indicates that the flock() routine is  *	available to do file locking.  */
end_comment

begin_define
define|#
directive|define
name|HAS_FLOCK
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_GETGROUPS  *	This symbol, if defined, indicates that the getgroups() routine is  *	available to get the list of process groups.  If unavailable, multiple  *	groups are probably not supported.  */
end_comment

begin_define
define|#
directive|define
name|HAS_GETGROUPS
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_GETHOSTENT  *	This symbol, if defined, indicates that the gethostent() routine is  *	available to lookup host names in some data base or other.  */
end_comment

begin_comment
comment|/*#undef	HAS_GETHOSTENT		*/
end_comment

begin_comment
comment|/* HAS_GETPGRP  *	This symbol, if defined, indicates that the getpgrp() routine is  *	available to get the current process group.  */
end_comment

begin_define
define|#
directive|define
name|HAS_GETPGRP
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_GETPGRP2  *	This symbol, if defined, indicates that the getpgrp2() (as in DG/UX)  *	routine is available to get the current process group.  */
end_comment

begin_comment
comment|/*#undef	HAS_GETPGRP2		*/
end_comment

begin_comment
comment|/* HAS_GETPRIORITY  *	This symbol, if defined, indicates that the getpriority() routine is  *	available to get a process's priority.  */
end_comment

begin_define
define|#
directive|define
name|HAS_GETPRIORITY
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_HTONS  *	This symbol, if defined, indicates that the htons routine (and friends)  *	are available to do network order byte swapping.  */
end_comment

begin_comment
comment|/* HAS_HTONL  *	This symbol, if defined, indicates that the htonl routine (and friends)  *	are available to do network order byte swapping.  */
end_comment

begin_comment
comment|/* HAS_NTOHS  *	This symbol, if defined, indicates that the ntohs routine (and friends)  *	are available to do network order byte swapping.  */
end_comment

begin_comment
comment|/* HAS_NTOHL  *	This symbol, if defined, indicates that the ntohl routine (and friends)  *	are available to do network order byte swapping.  */
end_comment

begin_define
define|#
directive|define
name|HAS_HTONS
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|HAS_HTONL
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|HAS_NTOHS
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|HAS_NTOHL
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* index  *	This preprocessor symbol is defined, along with rindex, if the system  *	uses the strchr and strrchr routines instead.  */
end_comment

begin_comment
comment|/* rindex  *	This preprocessor symbol is defined, along with index, if the system  *	uses the strchr and strrchr routines instead.  */
end_comment

begin_comment
comment|/* HAS_ISASCII  *	This symbol, if defined, indicates that the isascii routine is available  *	to test characters for asciiness.  */
end_comment

begin_define
define|#
directive|define
name|HAS_ISASCII
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_KILLPG  *	This symbol, if defined, indicates that the killpg routine is available  *	to kill process groups.  If unavailable, you probably should use kill  *	with a negative process number.  */
end_comment

begin_define
define|#
directive|define
name|HAS_KILLPG
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_LSTAT  *	This symbol, if defined, indicates that the lstat() routine is  *	available to stat symbolic links.  */
end_comment

begin_define
define|#
directive|define
name|HAS_LSTAT
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_MEMCMP  *	This symbol, if defined, indicates that the memcmp routine is available  *	to compare blocks of memory.  If undefined, roll your own.  */
end_comment

begin_define
define|#
directive|define
name|HAS_MEMCMP
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_MEMCPY  *	This symbol, if defined, indicates that the memcpy routine is available  *	to copy blocks of memory.  Otherwise you should probably use bcopy().  *	If neither is defined, roll your own.  */
end_comment

begin_comment
comment|/* SAFE_MEMCPY  *	This symbol, if defined, indicates that the memcpy routine is available  *	to copy potentially overlapping copy blocks of memory.  Otherwise you  *	should probably use memmove() or bcopy().  If neither is defined,  *	roll your own.  */
end_comment

begin_define
define|#
directive|define
name|HAS_MEMCPY
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|SAFE_MEMCPY
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_MEMMOVE  *	This symbol, if defined, indicates that the memmove routine is available  *	to move potentially overlapping blocks of memory.  Otherwise you  *	should use bcopy() or roll your own.  */
end_comment

begin_define
define|#
directive|define
name|HAS_MEMMOVE
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_MEMSET  *	This symbol, if defined, indicates that the memset routine is available  *	to set a block of memory to a character.  If undefined, roll your own.  */
end_comment

begin_define
define|#
directive|define
name|HAS_MEMSET
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_MKDIR  *	This symbol, if defined, indicates that the mkdir routine is available  *	to create directories.  Otherwise you should fork off a new process to  *	exec /bin/mkdir.  */
end_comment

begin_define
define|#
directive|define
name|HAS_MKDIR
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_NDBM  *	This symbol, if defined, indicates that ndbm.h exists and should  *	be included.  */
end_comment

begin_define
define|#
directive|define
name|HAS_NDBM
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_ODBM  *	This symbol, if defined, indicates that dbm.h exists and should  *	be included.  */
end_comment

begin_comment
comment|/* HAS_OPEN3  *	This manifest constant lets the C program know that the three  *	argument form of open(2) is available.  */
end_comment

begin_define
define|#
directive|define
name|HAS_OPEN3
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_READDIR  *	This symbol, if defined, indicates that the readdir routine is available  *	from the C library to read directories.  */
end_comment

begin_define
define|#
directive|define
name|HAS_READDIR
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_RENAME  *	This symbol, if defined, indicates that the rename routine is available  *	to rename files.  Otherwise you should do the unlink(), link(), unlink()  *	trick.  */
end_comment

begin_define
define|#
directive|define
name|HAS_RENAME
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_REWINDDIR  *	This symbol, if defined, indicates that the rewindir routine is  *	available to rewind directories.  */
end_comment

begin_define
define|#
directive|define
name|HAS_REWINDDIR
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_RMDIR  *	This symbol, if defined, indicates that the rmdir routine is available  *	to remove directories.  Otherwise you should fork off a new process to  *	exec /bin/rmdir.  */
end_comment

begin_define
define|#
directive|define
name|HAS_RMDIR
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_SEEKDIR  *	This symbol, if defined, indicates that the seekdir routine is  *	available to seek into directories.  */
end_comment

begin_define
define|#
directive|define
name|HAS_SEEKDIR
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_SELECT  *	This symbol, if defined, indicates that the select() subroutine  *	exists.  */
end_comment

begin_define
define|#
directive|define
name|HAS_SELECT
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_SETEGID  *	This symbol, if defined, indicates that the setegid routine is available  *	to change the effective gid of the current program.  *	Do not use on systems with _POSIX_SAVED_IDS support.  */
end_comment

begin_comment
comment|/*#undef	HAS_SETEGID		/**/
end_comment

begin_comment
comment|/* HAS_SETEUID  *	This symbol, if defined, indicates that the seteuid routine is available  *	to change the effective uid of the current program.  *	Do not use on systems with _POSIX_SAVED_IDS support.  */
end_comment

begin_comment
comment|/*#undef	HAS_SETEUID		/**/
end_comment

begin_comment
comment|/* HAS_SETPGRP  *	This symbol, if defined, indicates that the setpgrp() routine is  *	available to set the current process group.  */
end_comment

begin_define
define|#
directive|define
name|HAS_SETPGRP
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_SETPGRP2  *	This symbol, if defined, indicates that the setpgrp2() (as in DG/UX)  *	routine is available to set the current process group.  */
end_comment

begin_comment
comment|/* HAS_SETPRIORITY  *	This symbol, if defined, indicates that the setpriority() routine is  *	available to set a process's priority.  */
end_comment

begin_define
define|#
directive|define
name|HAS_SETPRIORITY
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_SETREGID  *	This symbol, if defined, indicates that the setregid routine is  *	available to change the real and effective gid of the current program.  */
end_comment

begin_comment
comment|/* HAS_SETRESGID  *	This symbol, if defined, indicates that the setresgid routine is  *	available to change the real, effective and saved gid of the current  *	program.  */
end_comment

begin_define
define|#
directive|define
name|HAS_SETREGID
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_SETREUID  *	This symbol, if defined, indicates that the setreuid routine is  *	available to change the real and effective uid of the current program.  */
end_comment

begin_comment
comment|/* HAS_SETRESUID  *	This symbol, if defined, indicates that the setresuid routine is  *	available to change the real, effective and saved uid of the current  *	program.  */
end_comment

begin_define
define|#
directive|define
name|HAS_SETREUID
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_SETRGID  *	This symbol, if defined, indicates that the setrgid routine is available  *	to change the real gid of the current program.  */
end_comment

begin_define
define|#
directive|define
name|HAS_SETRGID
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_SETRUID  *	This symbol, if defined, indicates that the setruid routine is available  *	to change the real uid of the current program.  */
end_comment

begin_define
define|#
directive|define
name|HAS_SETRUID
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_SOCKET  *	This symbol, if defined, indicates that the BSD socket interface is  *	supported.  */
end_comment

begin_comment
comment|/* HAS_SOCKETPAIR  *	This symbol, if defined, indicates that the BSD socketpair call is  *	supported.  */
end_comment

begin_comment
comment|/* OLDSOCKET  *	This symbol, if defined, indicates that the 4.1c BSD socket interface  *	is supported instead of the 4.2/4.3 BSD socket interface.  */
end_comment

begin_define
define|#
directive|define
name|HAS_SOCKET
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|HAS_SOCKETPAIR
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* STATBLOCKS  *	This symbol is defined if this system has a stat structure declaring  *	st_blksize and st_blocks.  */
end_comment

begin_define
define|#
directive|define
name|STATBLOCKS
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* STDSTDIO  *	This symbol is defined if this system has a FILE structure declaring  *	_ptr and _cnt in stdio.h.  */
end_comment

begin_comment
comment|/* STRUCTCOPY  *	This symbol, if defined, indicates that this C compiler knows how  *	to copy structures.  If undefined, you'll need to use a block copy  *	routine of some sort instead.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTCOPY
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_STRERROR  *	This symbol, if defined, indicates that the strerror() routine is  *	available to translate error numbers to strings.  */
end_comment

begin_define
define|#
directive|define
name|HAS_STRERROR
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_SYMLINK  *	This symbol, if defined, indicates that the symlink routine is available  *	to create symbolic links.  */
end_comment

begin_define
define|#
directive|define
name|HAS_SYMLINK
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_SYSCALL  *	This symbol, if defined, indicates that the syscall routine is available  *	to call arbitrary system calls.  If undefined, that's tough.  */
end_comment

begin_define
define|#
directive|define
name|HAS_SYSCALL
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_TELLDIR  *	This symbol, if defined, indicates that the telldir routine is  *	available to tell your location in directories.  */
end_comment

begin_define
define|#
directive|define
name|HAS_TELLDIR
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_TRUNCATE  *	This symbol, if defined, indicates that the truncate routine is  *	available to truncate files.  */
end_comment

begin_define
define|#
directive|define
name|HAS_TRUNCATE
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_VFORK  *	This symbol, if defined, indicates that vfork() exists.  */
end_comment

begin_define
define|#
directive|define
name|HAS_VFORK
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* VOIDSIG  *	This symbol is defined if this system declares "void (*signal())()" in  *	signal.h.  The old way was to declare it as "int (*signal())()".  It  *	is up to the package author to declare things correctly based on the  *	symbol.  */
end_comment

begin_comment
comment|/* TO_SIGNAL  *	This symbol's value is either "void" or "int", corresponding to the  *	appropriate return "type" of a signal handler.  Thus, one can declare  *	a signal handler using "TO_SIGNAL (*handler())()", and define the  *	handler using "TO_SIGNAL handler(sig)".  */
end_comment

begin_define
define|#
directive|define
name|VOIDSIG
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|TO_SIGNAL
value|int
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HASVOLATILE  *	This symbol, if defined, indicates that this C compiler knows about  *	the volatile declaration.  */
end_comment

begin_define
define|#
directive|define
name|HASVOLATILE
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_VPRINTF  *	This symbol, if defined, indicates that the vprintf routine is available  *	to printf with a pointer to an argument list.  If unavailable, you  *	may need to write your own, probably in terms of _doprnt().  */
end_comment

begin_comment
comment|/* CHARVSPRINTF  *	This symbol is defined if this system has vsprintf() returning type  *	(char*).  The trend seems to be to declare it as "int vsprintf()".  It  *	is up to the package author to declare vsprintf correctly based on the  *	symbol.  */
end_comment

begin_define
define|#
directive|define
name|HAS_VPRINTF
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_WAIT4  *	This symbol, if defined, indicates that wait4() exists.  */
end_comment

begin_define
define|#
directive|define
name|HAS_WAIT4
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_WAITPID  *	This symbol, if defined, indicates that waitpid() exists.  */
end_comment

begin_define
define|#
directive|define
name|HAS_WAITPID
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* GIDTYPE  *	This symbol has a value like gid_t, int, ushort, or whatever type is  *	used to declare group ids in the kernel.  */
end_comment

begin_define
define|#
directive|define
name|GIDTYPE
value|gid_t
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* GROUPSTYPE  *	This symbol has a value like gid_t, int, ushort, or whatever type is  *	used in the return value of getgroups().  */
end_comment

begin_define
define|#
directive|define
name|GROUPSTYPE
value|gid_t
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* I_FCNTL  *	This manifest constant tells the C program to include<fcntl.h>.  */
end_comment

begin_comment
comment|/* I_GDBM  *	This symbol, if defined, indicates that gdbm.h exists and should  *	be included.  */
end_comment

begin_comment
comment|/* I_GRP  *	This symbol, if defined, indicates to the C program that it should  *	include grp.h.  */
end_comment

begin_define
define|#
directive|define
name|I_GRP
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* I_NETINET_IN  *	This symbol, if defined, indicates to the C program that it should  *	include netinet/in.h.  */
end_comment

begin_comment
comment|/* I_SYS_IN  *	This symbol, if defined, indicates to the C program that it should  *	include sys/in.h.  */
end_comment

begin_define
define|#
directive|define
name|I_NETINET_IN
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* I_PWD  *	This symbol, if defined, indicates to the C program that it should  *	include pwd.h.  */
end_comment

begin_comment
comment|/* PWQUOTA  *	This symbol, if defined, indicates to the C program that struct passwd  *	contains pw_quota.  */
end_comment

begin_comment
comment|/* PWAGE  *	This symbol, if defined, indicates to the C program that struct passwd  *	contains pw_age.  */
end_comment

begin_comment
comment|/* PWCHANGE  *	This symbol, if defined, indicates to the C program that struct passwd  *	contains pw_change.  */
end_comment

begin_comment
comment|/* PWCLASS  *	This symbol, if defined, indicates to the C program that struct passwd  *	contains pw_class.  */
end_comment

begin_comment
comment|/* PWEXPIRE  *	This symbol, if defined, indicates to the C program that struct passwd  *	contains pw_expire.  */
end_comment

begin_comment
comment|/* PWCOMMENT  *	This symbol, if defined, indicates to the C program that struct passwd  *	contains pw_comment.  */
end_comment

begin_define
define|#
directive|define
name|I_PWD
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|PWCHANGE
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|PWCLASS
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|PWEXPIRE
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* I_SYS_FILE  *	This manifest constant tells the C program to include<sys/file.h>.  */
end_comment

begin_define
define|#
directive|define
name|I_SYS_FILE
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* I_SYSIOCTL  *	This symbol, if defined, indicates that sys/ioctl.h exists and should  *	be included.  */
end_comment

begin_define
define|#
directive|define
name|I_SYSIOCTL
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* I_TIME  *	This symbol is defined if the program should include<time.h>.  */
end_comment

begin_comment
comment|/* I_SYS_TIME  *	This symbol is defined if the program should include<sys/time.h>.  */
end_comment

begin_comment
comment|/* SYSTIMEKERNEL  *	This symbol is defined if the program should include<sys/time.h>  *	with KERNEL defined.  */
end_comment

begin_comment
comment|/* I_SYS_SELECT  *	This symbol is defined if the program should include<sys/select.h>.  */
end_comment

begin_define
define|#
directive|define
name|I_SYS_TIME
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* I_UTIME  *	This symbol, if defined, indicates to the C program that it should  *	include utime.h.  */
end_comment

begin_define
define|#
directive|define
name|I_UTIME
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* I_VARARGS  *	This symbol, if defined, indicates to the C program that it should  *	include varargs.h.  */
end_comment

begin_define
define|#
directive|define
name|I_VARARGS
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* I_VFORK  *	This symbol, if defined, indicates to the C program that it should  *	include vfork.h.  */
end_comment

begin_comment
comment|/* INTSIZE  *	This symbol contains the size of an int, so that the C preprocessor  *	can make decisions based on it.  */
end_comment

begin_define
define|#
directive|define
name|INTSIZE
value|4
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* I_DIRENT  *	This symbol, if defined, indicates that the program should use the  *	P1003-style directory routines, and include<dirent.h>.  */
end_comment

begin_comment
comment|/* I_SYS_DIR  *	This symbol, if defined, indicates that the program should use the  *	directory functions by including<sys/dir.h>.  */
end_comment

begin_comment
comment|/* I_NDIR  *	This symbol, if defined, indicates that the program should include the  *	system's version of ndir.h, rather than the one with this package.  */
end_comment

begin_comment
comment|/* I_SYS_NDIR  *	This symbol, if defined, indicates that the program should include the  *	system's version of sys/ndir.h, rather than the one with this package.  */
end_comment

begin_comment
comment|/* I_MY_DIR  *	This symbol, if defined, indicates that the program should compile  *	the ndir.c code provided with the package.  */
end_comment

begin_comment
comment|/* DIRNAMLEN  *	This symbol, if defined, indicates to the C program that the length  *	of directory entry names is provided by a d_namlen field.  Otherwise  *	you need to do strlen() on the d_name field.  */
end_comment

begin_define
define|#
directive|define
name|I_DIRENT
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* MYMALLOC  *	This symbol, if defined, indicates that we're using our own malloc.  */
end_comment

begin_comment
comment|/* MALLOCPTRTYPE  *	This symbol defines the kind of ptr returned by malloc and realloc.  */
end_comment

begin_define
define|#
directive|define
name|MYMALLOC
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|MALLOCPTRTYPE
value|void
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* RANDBITS  *	This symbol contains the number of bits of random number the rand()  *	function produces.  Usual values are 15, 16, and 31.  */
end_comment

begin_define
define|#
directive|define
name|RANDBITS
value|31
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* SCRIPTDIR  *	This symbol holds the name of the directory in which the user wants  *	to keep publicly executable scripts for the package in question.  It  *	is often a directory that is mounted across diverse architectures.  */
end_comment

begin_define
define|#
directive|define
name|SCRIPTDIR
value|"/usr/bin"
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* SIG_NAME  *	This symbol contains an list of signal names in order.  */
end_comment

begin_define
define|#
directive|define
name|SIG_NAME
value|"ZERO","HUP","INT","QUIT","ILL","TRAP","ABRT","EMT","FPE","KILL","BUS","SEGV","SYS","PIPE","ALRM","TERM","URG","STOP","TSTP","CONT","CHLD","TTIN","TTOU","IO","XCPU","XFSZ","VTALRM","PROF","WINCH","INFO","USR1","USR2"
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* STDCHAR  *	This symbol is defined to be the type of char used in stdio.h.  *	It has the values "unsigned char" or "char".  */
end_comment

begin_define
define|#
directive|define
name|STDCHAR
value|char
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* UIDTYPE  *	This symbol has a value like uid_t, int, ushort, or whatever type is  *	used to declare user ids in the kernel.  */
end_comment

begin_define
define|#
directive|define
name|UIDTYPE
value|uid_t
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* VOIDHAVE  *	This symbol indicates how much support of the void type is given by this  *	compiler.  What various bits mean:  *  *	    1 = supports declaration of void  *	    2 = supports arrays of pointers to functions returning void  *	    4 = supports comparisons between pointers to void functions and  *		    addresses of void functions  *  *	The package designer should define VOIDWANT to indicate the requirements  *	of the package.  This can be done either by #defining VOIDWANT before  *	including config.h, or by defining voidwant in Myinit.U.  If the level  *	of void support necessary is not present, config.h defines void to "int",  *	VOID to the empty string, and VOIDP to "char *".  */
end_comment

begin_comment
comment|/* void  *	This symbol is used for void casts.  On implementations which support  *	void appropriately, its value is "void".  Otherwise, its value maps  *	to "int".  */
end_comment

begin_comment
comment|/* VOID  *	This symbol's value is "void" if the implementation supports void  *	appropriately.  Otherwise, its value is the empty string.  The primary  *	use of this symbol is in specifying void parameter lists for function  *	prototypes.  */
end_comment

begin_comment
comment|/* VOIDP  *	This symbol is used for casting generic pointers.  On implementations  *	which support void appropriately, its value is "void *".  Otherwise,  *	its value is "char *".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VOIDWANT
end_ifndef

begin_define
define|#
directive|define
name|VOIDWANT
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VOIDHAVE
value|7
end_define

begin_if
if|#
directive|if
operator|(
name|VOIDHAVE
operator|&
name|VOIDWANT
operator|)
operator|!=
name|VOIDWANT
end_if

begin_define
define|#
directive|define
name|void
value|int
end_define

begin_comment
comment|/* is void to be avoided? */
end_comment

begin_define
define|#
directive|define
name|VOID
end_define

begin_define
define|#
directive|define
name|VOIDP
value|(char *)
end_define

begin_define
define|#
directive|define
name|M_VOID
end_define

begin_comment
comment|/* Xenix strikes again */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VOID
value|void
end_define

begin_define
define|#
directive|define
name|VOIDP
value|(void *)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PRIVLIB  *	This symbol contains the name of the private library for this package.  *	The library is private in the sense that it needn't be in anyone's  *	execution path, but it should be accessible by the world.  The program  *	should be prepared to do ~ expansion.  */
end_comment

begin_define
define|#
directive|define
name|PRIVLIB
value|"/usr/share/perl"
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

