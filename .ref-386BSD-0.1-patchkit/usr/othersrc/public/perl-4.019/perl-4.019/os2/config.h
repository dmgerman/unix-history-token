begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h  * This file was hand tailored for compiling under MS-DOS and MSC 5.1.  * Diomidis Spinellis, March 1990.  *  * Then it got mangled again for compiling under OS/2 and MSC 6.0.  * Raymond Chen, June 1990.  */
end_comment

begin_define
define|#
directive|define
name|OS2
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* OS/2 supports some additional things MS-DOS doesn't.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_define
define|#
directive|define
name|PIPE
end_define

begin_define
define|#
directive|define
name|GETPPID
end_define

begin_define
define|#
directive|define
name|HAS_GETPRIORITY
end_define

begin_define
define|#
directive|define
name|HAS_SETPRIORITY
end_define

begin_define
define|#
directive|define
name|KILL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_comment
comment|/* SUFFIX:  *      This symbol, if defined, indicates that the function add_suffix has  *      been supplied in a system-dependent .c file.  This function is  *      recommended for operating systems whose filenaming conventions  *      do not permit arbitrary strings as filenames.  */
end_comment

begin_define
define|#
directive|define
name|SUFFIX
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* EUNICE:  *	This symbol, if defined, indicates that the program is being compiled  *	under the EUNICE package under VMS.  The program will need to handle  *	things like files that don't go away the first time you unlink them,  *	due to version numbering.  It will also need to compensate for lack  *	of a respectable link() command.  */
end_comment

begin_comment
comment|/* VMS:  *	This symbol, if defined, indicates that the program is running under  *	VMS.  It is currently only set in conjunction with the EUNICE symbol.  */
end_comment

begin_comment
comment|/*#undef	EUNICE		/**/
end_comment

begin_comment
comment|/*#undef	VMS		/**/
end_comment

begin_comment
comment|/* BIN:  *	This symbol holds the name of the directory in which the user wants  *	to put publicly executable images for the package in question.  It  *	is most often a local directory such as /usr/local/bin.  */
end_comment

begin_define
define|#
directive|define
name|BIN
value|"/usr/local/bin"
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* BYTEORDER:  *	This symbol contains an encoding of the order of bytes in a long.  *	Usual values (in octal) are 01234, 04321, 02143, 03412...  */
end_comment

begin_comment
comment|/* CHECK */
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
comment|/* CPPSTDIN:  *	This symbol contains the first part of the string which will invoke  *	the C preprocessor on the standard input and produce to standard  *	output.	 Typical value of "cc -{" or "/lib/cpp".  */
end_comment

begin_comment
comment|/* CPPMINUS:  *	This symbol contains the second part of the string which will invoke  *	the C preprocessor on the standard input and produce to standard  *	output.  This symbol will have the value "-" if CPPSTDIN needs a minus  *	to specify standard input, otherwise the value is "".  */
end_comment

begin_comment
comment|/* TODO */
end_comment

begin_define
define|#
directive|define
name|CPPSTDIN
value|"cc -{"
end_define

begin_define
define|#
directive|define
name|CPPMINUS
value|""
end_define

begin_comment
comment|/* HAS_BCMP:  *	This symbol, if defined, indicates that the bcmp routine is available  *	to compare blocks of memory.  If undefined, use memcmp.  If that's  *	not available, roll your own.  */
end_comment

begin_comment
comment|/*#define	HAS_BCMP		/**/
end_comment

begin_comment
comment|/* HAS_BCOPY:  *	This symbol, if defined, indicates that the bcopy routine is available  *	to copy blocks of memory.  Otherwise you should probably use memcpy().  */
end_comment

begin_comment
comment|/*#define	HAS_BCOPY		/**/
end_comment

begin_comment
comment|/* CHARSPRINTF:  *	This symbol is defined if this system declares "char *sprintf()" in  *	stdio.h.  The trend seems to be to declare it as "int sprintf()".  It  *	is up to the package author to declare sprintf correctly based on the  *	symbol.  */
end_comment

begin_comment
comment|/*#define	CHARSPRINTF 	/**/
end_comment

begin_comment
comment|/* HAS_CRYPT:  *	This symbol, if defined, indicates that the crypt routine is available  *	to encrypt passwords and the like.  */
end_comment

begin_comment
comment|/* TODO */
end_comment

begin_comment
comment|/*#define	HAS_CRYPT		/**/
end_comment

begin_comment
comment|/* DOSUID:  *	This symbol, if defined, indicates that the C program should  *	check the script that it is executing for setuid/setgid bits, and  *	attempt to emulate setuid/setgid on systems that have disabled  *	setuid #! scripts because the kernel can't do it securely.  *	It is up to the package designer to make sure that this emulation  *	is done securely.  Among other things, it should do an fstat on  *	the script it just opened to make sure it really is a setuid/setgid  *	script, it should make sure the arguments passed correspond exactly  *	to the argument on the #! line, and it should not trust any  *	subprocesses to which it must pass the filename rather than the  *	file descriptor of the script to be executed.  */
end_comment

begin_comment
comment|/*#define DOSUID		/**/
end_comment

begin_comment
comment|/* HAS_DUP2:  *	This symbol, if defined, indicates that the dup2 routine is available  *	to dup file descriptors.  Otherwise you should use dup().  */
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
comment|/* HAS_FCHMOD:  *	This symbol, if defined, indicates that the fchmod routine is available  *	to change mode of opened files.  If unavailable, use chmod().  */
end_comment

begin_comment
comment|/*#define	HAS_FCHMOD		/**/
end_comment

begin_comment
comment|/* HAS_FCHOWN:  *	This symbol, if defined, indicates that the fchown routine is available  *	to change ownership of opened files.  If unavailable, use chown().  */
end_comment

begin_comment
comment|/*#define	HAS_FCHOWN		/**/
end_comment

begin_comment
comment|/* I_FCNTL:  *	This symbol, if defined, indicates to the C program that it should  *	include fcntl.h.  */
end_comment

begin_comment
comment|/*#define	I_FCNTL		/**/
end_comment

begin_comment
comment|/* HAS_FLOCK:  *	This symbol, if defined, indicates that the flock() routine is  *	available to do file locking.  */
end_comment

begin_comment
comment|/*#define	HAS_FLOCK		/**/
end_comment

begin_comment
comment|/* HAS_GETGROUPS:  *	This symbol, if defined, indicates that the getgroups() routine is  *	available to get the list of process groups.  If unavailable, multiple  *	groups are probably not supported.  */
end_comment

begin_comment
comment|/*#define	HAS_GETGROUPS		/**/
end_comment

begin_comment
comment|/* HAS_GETHOSTENT:  *	This symbol, if defined, indicates that the gethostent() routine is  *	available to lookup host names in some data base or other.  */
end_comment

begin_comment
comment|/*#define	HAS_GETHOSTENT		/**/
end_comment

begin_comment
comment|/* HAS_GETPGRP:  *	This symbol, if defined, indicates that the getpgrp() routine is  *	available to get the current process group.  */
end_comment

begin_comment
comment|/*#define	HAS_GETPGRP		/**/
end_comment

begin_comment
comment|/* HAS_GETPRIORITY:  *	This symbol, if defined, indicates that the getpriority() routine is  *	available to get a process's priority.  */
end_comment

begin_comment
comment|/*#define	HAS_GETPRIORITY		/**/
end_comment

begin_comment
comment|/* HAS_HTONS:  *	This symbol, if defined, indicates that the htons routine (and friends)  *	are available to do network order byte swapping.  */
end_comment

begin_comment
comment|/* HAS_HTONL:  *	This symbol, if defined, indicates that the htonl routine (and friends)  *	are available to do network order byte swapping.  */
end_comment

begin_comment
comment|/* HAS_NTOHS:  *	This symbol, if defined, indicates that the ntohs routine (and friends)  *	are available to do network order byte swapping.  */
end_comment

begin_comment
comment|/* HAS_NTOHL:  *	This symbol, if defined, indicates that the ntohl routine (and friends)  *	are available to do network order byte swapping.  */
end_comment

begin_comment
comment|/*#define	HAS_HTONS		/**/
end_comment

begin_comment
comment|/*#define	HAS_HTONL		/**/
end_comment

begin_comment
comment|/*#define	HAS_NTOHS		/**/
end_comment

begin_comment
comment|/*#define	HAS_NTOHL		/**/
end_comment

begin_comment
comment|/* index:  *	This preprocessor symbol is defined, along with rindex, if the system  *	uses the strchr and strrchr routines instead.  */
end_comment

begin_comment
comment|/* rindex:  *	This preprocessor symbol is defined, along with index, if the system  *	uses the strchr and strrchr routines instead.  */
end_comment

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_comment
comment|/* cultural */
end_comment

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_comment
comment|/*  differences? */
end_comment

begin_comment
comment|/* I_SYSIOCTL:  *	This symbol, if defined, indicates that sys/ioctl.h exists and should  *	be included.  */
end_comment

begin_comment
comment|/*#define	I_SYSIOCTL		/**/
end_comment

begin_comment
comment|/* HAS_KILLPG:  *	This symbol, if defined, indicates that the killpg routine is available  *	to kill process groups.  If unavailable, you probably should use kill  *	with a negative process number.  */
end_comment

begin_comment
comment|/*#define	HAS_KILLPG		/**/
end_comment

begin_comment
comment|/* HAS_MEMCMP:  *	This symbol, if defined, indicates that the memcmp routine is available  *	to compare blocks of memory.  If undefined, roll your own.  */
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
comment|/* HAS_MEMCPY:  *	This symbol, if defined, indicates that the memcpy routine is available  *	to copy blocks of memory.  Otherwise you should probably use bcopy().  *	If neither is defined, roll your own.  */
end_comment

begin_define
define|#
directive|define
name|HAS_MEMCPY
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_MKDIR:  *	This symbol, if defined, indicates that the mkdir routine is available  *	to create directories.  Otherwise you should fork off a new process to  *	exec /bin/mkdir.  */
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
comment|/* HAS_NDBM:  *	This symbol, if defined, indicates that ndbm.h exists and should  *	be included.  */
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
comment|/* HAS_ODBM:  *	This symbol, if defined, indicates that dbm.h exists and should  *	be included.  */
end_comment

begin_comment
comment|/*#define	HAS_ODBM		/**/
end_comment

begin_comment
comment|/* HAS_READDIR:  *	This symbol, if defined, indicates that the readdir routine is available  *	from the C library to create directories.  */
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
comment|/* HAS_RENAME:  *	This symbol, if defined, indicates that the rename routine is available  *	to rename files.  Otherwise you should do the unlink(), link(), unlink()  *	trick.  */
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
comment|/* HAS_RMDIR:  *	This symbol, if defined, indicates that the rmdir routine is available  *	to remove directories.  Otherwise you should fork off a new process to  *	exec /bin/rmdir.  */
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
comment|/* HAS_SETEGID:  *	This symbol, if defined, indicates that the setegid routine is available  *	to change the effective gid of the current program.  */
end_comment

begin_comment
comment|/*#define	HAS_SETEGID		/**/
end_comment

begin_comment
comment|/* HAS_SETEUID:  *	This symbol, if defined, indicates that the seteuid routine is available  *	to change the effective uid of the current program.  */
end_comment

begin_comment
comment|/*#define	HAS_SETEUID		/**/
end_comment

begin_comment
comment|/* HAS_SETPGRP:  *	This symbol, if defined, indicates that the setpgrp() routine is  *	available to set the current process group.  */
end_comment

begin_comment
comment|/*#define	HAS_SETPGRP		/**/
end_comment

begin_comment
comment|/* HAS_SETPRIORITY:  *	This symbol, if defined, indicates that the setpriority() routine is  *	available to set a process's priority.  */
end_comment

begin_comment
comment|/*#define	HAS_SETPRIORITY		/**/
end_comment

begin_comment
comment|/* HAS_SETREGID:  *	This symbol, if defined, indicates that the setregid routine is available  *	to change the real and effective gid of the current program.  */
end_comment

begin_comment
comment|/*#define	HAS_SETREGID		/**/
end_comment

begin_comment
comment|/* HAS_SETREUID:  *	This symbol, if defined, indicates that the setreuid routine is available  *	to change the real and effective uid of the current program.  */
end_comment

begin_comment
comment|/*#define	HAS_SETREUID		/**/
end_comment

begin_comment
comment|/* HAS_SETRGID:  *	This symbol, if defined, indicates that the setrgid routine is available  *	to change the real gid of the current program.  */
end_comment

begin_comment
comment|/*#define	HAS_SETRGID		/**/
end_comment

begin_comment
comment|/* HAS_SETRUID:  *	This symbol, if defined, indicates that the setruid routine is available  *	to change the real uid of the current program.  */
end_comment

begin_comment
comment|/*#define	HAS_SETRUID		/**/
end_comment

begin_comment
comment|/* HAS_SOCKET:  *      This symbol, if defined, indicates that the BSD socket interface is  *      supported.  */
end_comment

begin_comment
comment|/* HAS_SOCKETPAIR:  *      This symbol, if defined, indicates that the BSD socketpair call is  *      supported.  */
end_comment

begin_comment
comment|/* OLDSOCKET:  *      This symbol, if defined, indicates that the 4.1c BSD socket interface  *      is supported instead of the 4.2/4.3 BSD socket interface.  */
end_comment

begin_comment
comment|/*#undef HAS_SOCKET          /**/
end_comment

begin_comment
comment|/*#undef HAS_SOCKETPAIR      /**/
end_comment

begin_comment
comment|/*#undef        OLDSOCKET       /**/
end_comment

begin_comment
comment|/* STATBLOCKS:  *	This symbol is defined if this system has a stat structure declaring  *	st_blksize and st_blocks.  */
end_comment

begin_comment
comment|/*#define	STATBLOCKS 	/**/
end_comment

begin_comment
comment|/* STDSTDIO:  *	This symbol is defined if this system has a FILE structure declaring  *	_ptr and _cnt in stdio.h.  */
end_comment

begin_define
define|#
directive|define
name|STDSTDIO
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* STRUCTCOPY:  *	This symbol, if defined, indicates that this C compiler knows how  *	to copy structures.  If undefined, you'll need to use a block copy  *	routine of some sort instead.  */
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
comment|/* HAS_SYMLINK:  *	This symbol, if defined, indicates that the symlink routine is available  *	to create symbolic links.  */
end_comment

begin_comment
comment|/*#define	HAS_SYMLINK		/**/
end_comment

begin_comment
comment|/* HAS_SYSCALL:  *	This symbol, if defined, indicates that the syscall routine is available  *	to call arbitrary system calls.  If undefined, that's tough.  */
end_comment

begin_comment
comment|/*#define	HAS_SYSCALL		/**/
end_comment

begin_comment
comment|/* s_tm:  *	This symbol is defined if this system declares "struct tm" in  *	in<sys/time.h> rather than<time.h>.  We can't just say  *	-I/usr/include/sys because some systems have both time files, and  *	the -I trick gets the wrong one.  */
end_comment

begin_comment
comment|/* I_SYS_TIME:  *	This symbol is defined if this system has the file<sys/time.h>.  */
end_comment

begin_comment
comment|/*  * I_TIME:  *	This symbol is defined if time this  system has the file<time.h>.  */
end_comment

begin_comment
comment|/*#undef	s_tm 	/**/
end_comment

begin_comment
comment|/*#define	I_SYS_TIME 	/**/
end_comment

begin_define
define|#
directive|define
name|I_TIME
end_define

begin_comment
comment|/* VARARGS:  *	This symbol, if defined, indicates to the C program that it should  *	include varargs.h.  */
end_comment

begin_define
define|#
directive|define
name|VARARGS
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* vfork:  *	This symbol, if defined, remaps the vfork routine to fork if the  *	vfork() routine isn't supported here.  */
end_comment

begin_comment
comment|/*#undef	vfork fork	/**/
end_comment

begin_comment
comment|/* VOIDSIG:  *	This symbol is defined if this system declares "void (*signal())()" in  *	signal.h.  The old way was to declare it as "int (*signal())()".  It  *	is up to the package author to declare things correctly based on the  *	symbol.  */
end_comment

begin_define
define|#
directive|define
name|VOIDSIG
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* HAS_VPRINTF:  *	This symbol, if defined, indicates that the vprintf routine is available  *	to printf with a pointer to an argument list.  If unavailable, you  *	may need to write your own, probably in terms of _doprnt().  */
end_comment

begin_comment
comment|/* CHARVSPRINTF:  *	This symbol is defined if this system has vsprintf() returning type  *	(char*).  The trend seems to be to declare it as "int vsprintf()".  It  *	is up to the package author to declare vsprintf correctly based on the  *	symbol.  */
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
comment|/*#undef	CHARVSPRINTF 	/**/
end_comment

begin_comment
comment|/* GIDTYPE:  *	This symbol has a value like gid_t, int, ushort, or whatever type is  *	used to declare group ids in the kernel.  */
end_comment

begin_comment
comment|/* TODO */
end_comment

begin_define
define|#
directive|define
name|GIDTYPE
value|int
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* I_DIRENT:  *	This symbol, if defined, indicates to the C program that it should  *	include dirent.h.  */
end_comment

begin_comment
comment|/* DIRNAMLEN:  *	This symbol, if defined, indicates to the C program that the length  *	of directory entry names is provided by a d_namlen field.  Otherwise  *	you need to do strlen() on the d_name field.  */
end_comment

begin_comment
comment|/*#undef	I_DIRENT		/**/
end_comment

begin_define
define|#
directive|define
name|DIRNAMLEN
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* I_FCNTL:  *	This symbol, if defined, indicates to the C program that it should  *	include fcntl.h.  */
end_comment

begin_comment
comment|/*#define	I_FCNTL		/**/
end_comment

begin_comment
comment|/* I_GRP:  *	This symbol, if defined, indicates to the C program that it should  *	include grp.h.  */
end_comment

begin_comment
comment|/*#define	I_GRP		/**/
end_comment

begin_comment
comment|/* I_PWD:  *	This symbol, if defined, indicates to the C program that it should  *	include pwd.h.  */
end_comment

begin_comment
comment|/* PWQUOTA:  *	This symbol, if defined, indicates to the C program that struct passwd  *	contains pw_quota.  */
end_comment

begin_comment
comment|/* PWAGE:  *	This symbol, if defined, indicates to the C program that struct passwd  *	contains pw_age.  */
end_comment

begin_comment
comment|/*#define	I_PWD		/**/
end_comment

begin_comment
comment|/*#define	PWQUOTA		/**/
end_comment

begin_comment
comment|/*#undef	PWAGE		/**/
end_comment

begin_comment
comment|/* I_SYS_DIR:  *	This symbol, if defined, indicates to the C program that it should  *	include sys/dir.h.  */
end_comment

begin_define
define|#
directive|define
name|I_SYS_DIR
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* I_SYSIOCTL:  *	This symbol, if defined, indicates that sys/ioctl.h exists and should  *	be included.  */
end_comment

begin_comment
comment|/*#define	I_SYSIOCTL		/**/
end_comment

begin_comment
comment|/* I_VARARGS:  *	This symbol, if defined, indicates to the C program that it should  *	include varargs.h.  */
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
comment|/* INTSIZE:  *	This symbol contains the size of an int, so that the C preprocessor  *	can make decisions based on it.  */
end_comment

begin_define
define|#
directive|define
name|INTSIZE
value|2
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* RANDBITS:  *	This symbol contains the number of bits of random number the rand()  *	function produces.  Usual values are 15, 16, and 31.  */
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
comment|/* SIG_NAME:  *	This symbol contains an list of signal names in order.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_define
define|#
directive|define
name|SIG_NAME
value|"ZERO","HUP","INT","QUIT","ILL","TRAP","IOT","EMT","FPE",\
comment|/*      0      1     2     3      4      5     6     7    8 */
value|\    "KILL","BUS","SEGV","SYS","PIPE","UALRM","TERM","ALRM","USR2","CLD",\
comment|/* 9     10     11    12    13     14     15     16     17    18 */
value|\    "PWR","USR3","BREAK","ABRT"
end_define

begin_comment
comment|/*19     20     21    22   */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIG_NAME
value|"ZERO","HUP","INT","QUIT","ILL","TRAP","IOT","EMT","FPE","KILL","BUS","SEGV","SYS","PIPE","ALRM","TERM","URG","STOP","TSTP","CONT","CHLD","TTIN","TTOU","IO","XCPU","XFSZ","VTALRM","PROF","WINCH","USR1","USR2"
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_comment
comment|/* STDCHAR:  *	This symbol is defined to be the type of char used in stdio.h.  *	It has the values "unsigned char" or "char".  */
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
comment|/* UIDTYPE:  *	This symbol has a value like uid_t, int, ushort, or whatever type is  *	used to declare user ids in the kernel.  */
end_comment

begin_define
define|#
directive|define
name|UIDTYPE
value|int
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* VOIDFLAGS:  *	This symbol indicates how much support of the void type is given by this  *	compiler.  What various bits mean:  *  *	    1 = supports declaration of void  *	    2 = supports arrays of pointers to functions returning void  *	    4 = supports comparisons between pointers to void functions and  *		    addresses of void functions  *  *	The package designer should define VOIDUSED to indicate the requirements  *	of the package.  This can be done either by #defining VOIDUSED before  *	including config.h, or by defining defvoidused in Myinit.U.  If the  *	latter approach is taken, only those flags will be tested.  If the  *	level of void support necessary is not present, defines void to int.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VOIDUSED
end_ifndef

begin_define
define|#
directive|define
name|VOIDUSED
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VOIDFLAGS
value|7
end_define

begin_if
if|#
directive|if
operator|(
name|VOIDFLAGS
operator|&
name|VOIDUSED
operator|)
operator|!=
name|VOIDUSED
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
name|M_VOID
end_define

begin_comment
comment|/* Xenix strikes again */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PRIVLIB:  *	This symbol contains the name of the private library for this package.  *	The library is private in the sense that it needn't be in anyone's  *	execution path, but it should be accessible by the world.  The program  *	should be prepared to do ^ expansion.  */
end_comment

begin_define
define|#
directive|define
name|PRIVLIB
value|"c:/bin/perl"
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*  * BUGGY_MSC:  *	This symbol is defined if you are the unfortunate owner of a buggy  *	Microsoft C compiler and want to use intrinsic functions.  Versions  *	up to 5.1 are known conform to this definition.  */
end_comment

begin_comment
comment|/*#define BUGGY_MSC			/**/
end_comment

begin_comment
comment|/*  * BINARY:  *	This symbol is defined if you run under an operating system that  *	distinguishes between binary and text files.  If so the function  *	setmode will be used to set the file into binary mode.  */
end_comment

begin_define
define|#
directive|define
name|BINARY
end_define

begin_define
define|#
directive|define
name|S_ISUID
value|0
end_define

begin_define
define|#
directive|define
name|S_ISGID
value|0
end_define

begin_define
define|#
directive|define
name|CASTNEGFLOAT
end_define

end_unit

