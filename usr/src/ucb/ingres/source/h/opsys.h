begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/* **  OPSYS.H -- operating system dependent definitions. ** **	This header file contains everything that we at Berkeley **	think might vary from system to system.  Before **	compiling INGRES you should eyeball this file to see **	if your system is consistant with us. ** **	Version: **		%W%	%G% */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USERINGRES
end_ifndef

begin_comment
comment|/* **  UNIX version flags. **	The following flags define what version of UNIX is being run. **	They should be set as follows: ** **	Bell-style version six UNIX, with 8-bit user id's and 8-bit **	group id's, fetched with calls to getuid() and getgid() **	respectively, and stored in the passwd file as two separate **	eight-bit fields: **		Set the xV6_UNIX flag only. ** **	Berkeley-style version 6/7x-05a UNIX, with a single 16-bit **	user id and no group id (and no getgid() or setgid() calls), **	and stored in the passwd file as two separate eight-bit fields, **	combined to make a single 16-bit field: **		Set the xB_UNIX flag only. ** **	Bell-style version seven UNIX, with 16-bit user id's and **	16-bit group id's, fetched with calls to getuid() and **	getgid() respectively, and stored in the passwd file as **	two separate 16-bit fields: **		Set the xV7_UNIX flag only. */
end_comment

begin_comment
comment|/* set for version six */
end_comment

begin_comment
comment|/* # define	xV6_UNIX	/* Bell v6 UNIX flag */
end_comment

begin_define
define|#
directive|define
name|xV7_UNIX
end_define

begin_comment
comment|/* Bell v7 UNIX flag */
end_comment

begin_comment
comment|/* # define	xB_UNIX		/* Berkeley UNIX flag */
end_comment

begin_comment
comment|/* **  Maximum number of open files per process. **  Must match 'NOFILE' entry in /usr/sys/param.h */
end_comment

begin_comment
comment|/* ** if xV7_UNIX is defined, we include<sys/param.h>, which will ** define NOFILE, so we avoid defining it here. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|xV7_UNIX
end_ifndef

begin_define
define|#
directive|define
name|NOFILE
value|20
end_define

begin_endif
endif|#
directive|endif
endif|xV7_UNIX
end_endif

begin_comment
comment|/* **	USERINGRES is the UNIX login name of the INGRES superuser, **		normally "ingres" of course.  The root of this persons **		subtree as listed in /etc/passwd becomes the root of **		the INGRES subtree. */
end_comment

begin_define
define|#
directive|define
name|USERINGRES
value|"ingres"
end_define

begin_comment
comment|/* **  Structure for 'gtty' and 'stty' */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|xV7_UNIX
end_ifndef

begin_struct
struct|struct
name|sgttyb
block|{
name|char
name|sg_ispeed
decl_stmt|;
name|char
name|sg_ospeed
decl_stmt|;
name|char
name|sg_erase
decl_stmt|;
name|char
name|sg_kill
decl_stmt|;
name|int
name|sg_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_endif
endif|#
directive|endif
endif|xV7_UNIX
end_endif

begin_comment
comment|/* **  Structure for 'fstat' and 'stat' system calls. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|xV7_UNIX
end_ifndef

begin_struct
struct|struct
name|stat
block|{
name|short
name|st_dev
decl_stmt|;
comment|/* +0: device of i-node */
name|short
name|st_ino
decl_stmt|;
comment|/* +2 */
name|short
name|st_mode
decl_stmt|;
comment|/* +4: see below */
name|char
name|st_nlink
decl_stmt|;
comment|/* +6: number of links to file */
name|char
name|st_uid
decl_stmt|;
comment|/* +7: user ID of owner */
name|char
name|st_gid
decl_stmt|;
comment|/* +8: group ID of owner */
name|char
name|st_sz0
decl_stmt|;
comment|/* +9: high byte of 24-bit size */
name|int
name|st_sz1
decl_stmt|;
comment|/* +10: low word of 24-bit size */
name|int
name|st_addr
index|[
literal|8
index|]
decl_stmt|;
comment|/* +12: block numbers or device number */
name|int
name|st_atime
index|[
literal|2
index|]
decl_stmt|;
comment|/* +28: time of last access */
name|int
name|st_mtime
index|[
literal|2
index|]
decl_stmt|;
comment|/* +32: time of last modification */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IALLOC
value|0100000
end_define

begin_define
define|#
directive|define
name|S_IFMT
value|060000
end_define

begin_define
define|#
directive|define
name|S_IFDIR
value|040000
end_define

begin_define
define|#
directive|define
name|IFCHR
value|020000
end_define

begin_define
define|#
directive|define
name|IFBLK
value|060000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|xV7_UNIX
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|bitset
end_ifdef

begin_undef
undef|#
directive|undef
name|bitset
end_undef

begin_undef
undef|#
directive|undef
name|setbit
end_undef

begin_undef
undef|#
directive|undef
name|clrbit
end_undef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_undef
undef|#
directive|undef
name|bitset
end_undef

begin_undef
undef|#
directive|undef
name|setbit
end_undef

begin_undef
undef|#
directive|undef
name|clrbit
end_undef

begin_define
define|#
directive|define
name|bitset
parameter_list|(
name|bit
parameter_list|,
name|word
parameter_list|)
value|((bit)& (word))
end_define

begin_define
define|#
directive|define
name|setbit
parameter_list|(
name|bit
parameter_list|,
name|word
parameter_list|)
value|word |= bit
end_define

begin_define
define|#
directive|define
name|clrbit
parameter_list|(
name|bit
parameter_list|,
name|word
parameter_list|)
value|word&= ~bit
end_define

begin_else
else|#
directive|else
else|bitset
end_else

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_undef
undef|#
directive|undef
name|bitset
end_undef

begin_undef
undef|#
directive|undef
name|setbit
end_undef

begin_undef
undef|#
directive|undef
name|clrbit
end_undef

begin_endif
endif|#
directive|endif
endif|bitset
end_endif

begin_endif
endif|#
directive|endif
endif|xV7_UNIX
end_endif

begin_endif
endif|#
directive|endif
endif|USERINGRES
end_endif

end_unit

