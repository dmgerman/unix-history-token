begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * config.h  *  * If you haven't read the README file, now might be a good time.  *  * This file is edited by configure, so you shouldn't have to.  * If that doesn't work, edit this file to match your site.  *  * Sorry it's so long, but there are lots of things you might want to  * customize for your site.  *  * Copyright (c) 1990, 1991, John W. Eaton.  *  * You may distribute under the terms of the GNU General Public  * License as specified in the file COPYING that comes with the man  * distribution.    *  * John W. Eaton  * jwe@che.utexas.edu  * Department of Chemical Engineering  * The University of Texas at Austin  * Austin, Texas  78712  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMPRESS
end_ifdef

begin_define
define|#
directive|define
name|DO_COMPRESS
end_define

begin_define
define|#
directive|define
name|DO_UNCOMPRESS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is the size of a number of internal buffers.  It should  * probably not be less than 512.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUFSIZ
end_ifndef

begin_define
define|#
directive|define
name|BUFSIZ
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This should be at least the size of the longest path.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is the maximum number of directories expected in the manpath.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXDIRS
end_ifndef

begin_define
define|#
directive|define
name|MAXDIRS
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is the name of the group that owns the preformatted man pages.  * If you are running man as a setgid program, you should make sure  * that all of the preformatted man pages and the directories that  * they live in are readable and writeable and owned by this group.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SECURE_MAN_UID
end_ifdef

begin_define
define|#
directive|define
name|MAN_USER
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * It's probably best to define absolute paths to all of these.  If  * you don't, you'll be depending on the user's path to be correct  * when system () is called.  This can result in weird behavior that's  * hard to track down, especially after you forget how this program  * works...  If you don't have some of these programs, simply define  * them to be empty strings (i.e. "").  As a minimum, you must have  * nroff installed.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APROPOS
end_ifndef

begin_define
define|#
directive|define
name|APROPOS
value|"/usr/bin/apropos"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WHATIS
end_ifndef

begin_define
define|#
directive|define
name|WHATIS
value|"/usr/bin/whatis"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PAGER
end_ifndef

begin_define
define|#
directive|define
name|PAGER
value|"/usr/gnu/bin/less -sC"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_TROFF
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|TROFF
end_ifndef

begin_define
define|#
directive|define
name|TROFF
value|"/usr/bin/groff -Tps -man"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NROFF
end_ifndef

begin_define
define|#
directive|define
name|NROFF
value|"/usr/bin/groff -Tascii -man"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EQN
end_ifndef

begin_define
define|#
directive|define
name|EQN
value|"/usr/bin/eqn -Tps"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NEQN
end_ifndef

begin_define
define|#
directive|define
name|NEQN
value|"/usr/bin/eqn -Tascii"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TBL
end_ifndef

begin_define
define|#
directive|define
name|TBL
value|"/usr/bin/tbl"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|COL
end_ifndef

begin_define
define|#
directive|define
name|COL
value|"/usr/bin/col"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VGRIND
end_ifndef

begin_define
define|#
directive|define
name|VGRIND
value|"/usr/bin/vgrind"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|REFER
end_ifndef

begin_define
define|#
directive|define
name|REFER
value|"/usr/bin/refer"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GRAP
end_ifndef

begin_define
define|#
directive|define
name|GRAP
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PIC
end_ifndef

begin_define
define|#
directive|define
name|PIC
value|"/usr/bin/pic"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define the absolute path to the configuration file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAN_MAIN
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|config_file
index|[]
init|=
literal|"/etc/manpath.config"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define the uncompression program(s) to use for those preformatted  * pages that end in the given character.  If you add extras here, you  * may need to change man.c.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DO_UNCOMPRESS
end_ifdef

begin_comment
comment|/* .F files */
end_comment

begin_define
define|#
directive|define
name|FCAT
value|""
end_define

begin_comment
comment|/* .Y files */
end_comment

begin_define
define|#
directive|define
name|YCAT
value|""
end_define

begin_comment
comment|/* .Z files */
end_comment

begin_define
define|#
directive|define
name|ZCAT
value|"/usr/bin/zcat"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is the standard program to use on this system for compressing  * pages once they have been formatted, and the character to tack on  * to the end of those files.  The program listed is expected to read  * from the standard input and write compressed output to the standard  * output.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DO_COMPRESS
end_ifdef

begin_define
define|#
directive|define
name|COMPRESSOR
value|""
end_define

begin_define
define|#
directive|define
name|COMPRESS_EXT
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Define the standard manual sections.  For example, if your man  * directory tree has subdirectories man1, man2, man3, mann,  * and man3foo, std_sections[] would have "1", "2", "3", "n", and  * "3foo".  Directories are searched in the order they appear.  Having  * extras isn't fatal, it just slows things down a bit.  *  * Note that this is just for directories to search.  If you have  * files like .../man3/foobar.3Xtc, you don't need to have "3Xtc" in  * the list below -- this is handled separately, so that `man 3Xtc foobar',  * `man 3 foobar', and `man foobar' should find the file .../man3/foo.3Xtc,  * (assuming, of course, that there isn't a .../man1/foo.1 or somesuch  * that we would find first).  *  * Note that this list should be in the order that you want the  * directories to be searched.  Is there a standard for this?  What is  * the normal order?  If anyone knows, please tell me!  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MANPATH_MAIN
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|std_sections
index|[]
init|=
block|{
literal|"1"
block|,
literal|"n"
block|,
literal|"l"
block|,
literal|"6"
block|,
literal|"8"
block|,
literal|"2"
block|,
literal|"3"
block|,
literal|"4"
block|,
literal|"5"
block|,
literal|"7"
block|,
literal|"p"
block|,
literal|"o"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Not all systems define these in stat.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IRUSR
value|00400
end_define

begin_comment
comment|/*  read permission: owner */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWUSR
end_ifndef

begin_define
define|#
directive|define
name|S_IWUSR
value|00200
end_define

begin_comment
comment|/*  write permission: owner */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IRGRP
value|00040
end_define

begin_comment
comment|/*  read permission: group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWGRP
end_ifndef

begin_define
define|#
directive|define
name|S_IWGRP
value|00020
end_define

begin_comment
comment|/*  write permission: group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IROTH
end_ifndef

begin_define
define|#
directive|define
name|S_IROTH
value|00004
end_define

begin_comment
comment|/*  read permission: other */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWOTH
end_ifndef

begin_define
define|#
directive|define
name|S_IWOTH
value|00002
end_define

begin_comment
comment|/*  write permission: other */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is the mode used for formatted pages that we create.  If you  * are using the setgid option, you should use 664.  If you are not,  * you should use 666 and make the cat* directories mode 777.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CATMODE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SECURE_MAN_UID
end_ifdef

begin_define
define|#
directive|define
name|CATMODE
value|S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CATMODE
value|S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

