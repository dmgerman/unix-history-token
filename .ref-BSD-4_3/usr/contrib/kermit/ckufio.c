begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
modifier|*
name|ckzv
init|=
literal|"Unix file support, 4C(032) 25 Jul 85"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C K U F I O  --  Kermit file system support for Unix systems */
end_comment

begin_comment
comment|/*  Author: Frank da Cruz (SY.FDC@CU20B),  Columbia University Center for Computing Activities, January 1985.  Copyright (C) 1985, Trustees of Columbia University in the City of New York.  Permission is granted to any individual or institution to use, copy, or  redistribute this software so long as it is not sold for profit, provided this  copyright notice is retained.  */
end_comment

begin_comment
comment|/* Includes */
end_comment

begin_include
include|#
directive|include
file|"ckcker.h"
end_include

begin_comment
comment|/* Kermit definitions */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_comment
comment|/* Typedefs, debug formats, etc */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_comment
comment|/* Character types */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Standard i/o */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Data types */
end_comment

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_comment
comment|/* Directory structure */
end_comment

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|/* File status */
end_comment

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_comment
comment|/* Password file for shell name */
end_comment

begin_comment
comment|/* Berkeley Unix Version 4.x */
end_comment

begin_comment
comment|/* 4.1bsd support added by Charles E Brooks, EDN-VAX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MAXNAMLEN
end_ifdef

begin_define
define|#
directive|define
name|BSD42
end_define

begin_decl_stmt
name|char
modifier|*
name|ckzsys
init|=
literal|" 4.2 BSD"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|FT17
end_ifdef

begin_define
define|#
directive|define
name|BSD41
end_define

begin_decl_stmt
name|char
modifier|*
name|ckzsys
init|=
literal|" For:Pro Fortune 1.7"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BSD41
end_define

begin_decl_stmt
name|char
modifier|*
name|ckzsys
init|=
literal|" 4.1 BSD"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 2.9bsd support contributed by Bradley Smith, UCLA */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD29
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckzsys
init|=
literal|" 2.9 BSD"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Version 7 Unix  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckzsys
init|=
literal|" Version 7 Unix"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEC Professional-300 series with Venturcom Venix v1 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROVX1
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckzsys
init|=
literal|" DEC Pro-3xx/Venix v1"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCR Tower support contributed by John Bray, Auburn, AL. */
end_comment

begin_comment
comment|/* Tower OS is like Sys III but with BSD features -- mostly follows BSD. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TOWER1
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckzsys
init|=
literal|" NCR Tower 1632, OS 1.02"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sys III/V, Xenix, PC/IX,... support by Herm Fischer, Litton Data Systems */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UXIII
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|XENIX
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckzsys
init|=
literal|" Xenix/286"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|PCIX
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckzsys
init|=
literal|" PC/IX"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|ISIII
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|ckzsys
init|=
literal|" Interactive Systems Corp, System III"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|ckzsys
init|=
literal|" AT&T System III/System V"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Definitions of some Unix system commands */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DIRCMD
init|=
literal|"ls -l "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For directory listing */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DELCMD
init|=
literal|"rm -f "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For file deletion */
end_comment

begin_decl_stmt
name|char
modifier|*
name|TYPCMD
init|=
literal|"cat "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For typing a file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|PWDCMD
init|=
literal|"pwd "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For saying where I am */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|SPACMD
init|=
literal|"pwd ; quota ; df ."
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Space/quota of current directory */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|SPACMD
init|=
literal|"df "
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|SPACM2
init|=
literal|"df "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For space in specified directory */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|WHOCMD
init|=
literal|"finger "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For seeing who's logged in */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|WHOCMD
init|=
literal|"who "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For seeing who's logged in */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/*   Functions (n is one of the predefined file numbers from ckermi.h):     zopeni(n,name)   -- Opens an existing file for input.    zopeno(n,name)   -- Opens a new file for output.    zclose(n)        -- Closes a file.    zchin(n,&c)      -- Gets the next character from an input file.    zsout(n,s)       -- Write a null-terminated string to output file, buffered.    zsoutl(n,s)      -- Like zsout, but appends a line terminator.    zsoutx(n,s,x)    -- Write x characters to output file, unbuffered.    zchout(n,c)      -- Add a character to an output file, unbuffered.    zchki(name)      -- Check if named file exists and is readable, return size.    zchko(name)      -- Check if named file can be created.    znewn(name,s)    -- Make a new unique file name based on the given name.    zdelet(name)     -- Delete the named file.    zxpand(string)   -- Expands the given wildcard string into a list of files.    znext(string)    -- Returns the next file from the list in "string".    zxcmd(cmd)       -- Execute the command in a lower fork.    zclosf()         -- Close input file associated with zxcmd()'s lower fork.    zrtol(n1,n2)     -- Convert remote filename into local form.    zltor(n1,n2)     -- Convert local filename into remote form.    zchdir(dirnam)   -- Change working directory.    zhome()          -- Return pointer to home directory name string.    zkself()         -- Kill self, log out own job.  */
end_comment

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|FT17
end_ifdef

begin_define
define|#
directive|define
name|PROVX1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PROVX1
end_ifndef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_comment
comment|/* File access */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FT17
end_ifdef

begin_undef
undef|#
directive|undef
name|PROVX1
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some systems define these in include files, others don't... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R_OK
end_ifndef

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_comment
comment|/* For access */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|W_OK
end_ifndef

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PROVX1
end_ifdef

begin_define
define|#
directive|define
name|MAXNAMLEN
value|DIRSIZ
end_define

begin_comment
comment|/* Max file name length */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UXIII
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_define
define|#
directive|define
name|MAXNAMLEN
value|DIRSIZ
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_RDONLY
end_ifndef

begin_define
define|#
directive|define
name|O_RDONLY
value|000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXNAMLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXNAMLEN
value|14
end_define

begin_comment
comment|/* If still not defined... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PROVX1
end_ifdef

begin_define
define|#
directive|define
name|MAXWLD
value|50
end_define

begin_comment
comment|/* Maximum wildcard filenames */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXWLD
value|500
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Declarations */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|fp
index|[
name|ZNFILS
index|]
init|=
block|{
comment|/* File pointers */
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|pid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pid of child fork */
end_comment

begin_decl_stmt
specifier|static
name|int
name|fcount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of files in wild group */
end_comment

begin_decl_stmt
specifier|static
name|char
name|nambuf
index|[
name|MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer for a filename */
end_comment

begin_decl_stmt
name|char
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|getenv
argument_list|()
decl_stmt|,
modifier|*
name|strcpy
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* System functions */
end_comment

begin_extern
extern|extern errno;
end_extern

begin_comment
comment|/* System error code */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|mtchs
index|[
name|MAXWLD
index|]
decl_stmt|,
comment|/* Matches found for filename */
modifier|*
modifier|*
name|mtchptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to current match */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  Z K S E L F  --  Kill Self: log out own job, if possible.  */
end_comment

begin_macro
name|zkself
argument_list|()
end_macro

begin_block
block|{
comment|/* For "bye", but no guarantee! */
ifdef|#
directive|ifdef
name|PROVX1
return|return
operator|(
name|kill
argument_list|(
literal|0
argument_list|,
literal|9
argument_list|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|V7
return|return
operator|(
name|kill
argument_list|(
literal|0
argument_list|,
literal|9
argument_list|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|TOWER1
return|return
operator|(
name|kill
argument_list|(
literal|0
argument_list|,
literal|9
argument_list|)
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|FT17
return|return
operator|(
name|kill
argument_list|(
literal|0
argument_list|,
literal|9
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|kill
argument_list|(
name|getppid
argument_list|()
argument_list|,
literal|1
argument_list|)
operator|)
return|;
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  Z O P E N I  --  Open an existing file for input. */
end_comment

begin_macro
name|zopeni
argument_list|(
argument|n
argument_list|,
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|" zopeni"
argument_list|,
name|name
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"  fp"
argument_list|,
literal|""
argument_list|,
operator|(
name|int
operator|)
name|fp
index|[
name|n
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|chkfn
argument_list|(
name|n
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|n
operator|==
name|ZSYSFN
condition|)
block|{
comment|/* Input from a system function? */
name|debug
argument_list|(
name|F110
argument_list|,
literal|" invoking zxcmd"
argument_list|,
name|name
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|zxcmd
argument_list|(
name|name
argument_list|)
operator|)
return|;
comment|/* Try to fork the command */
block|}
if|if
condition|(
name|n
operator|==
name|ZSTDIO
condition|)
block|{
comment|/* Standard input? */
if|if
condition|(
name|isatty
argument_list|(
literal|0
argument_list|)
condition|)
block|{
name|ermsg
argument_list|(
literal|"Terminal input not allowed"
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zopeni: attempts input from unredirected stdin"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|fp
index|[
name|ZIFILE
index|]
operator|=
name|stdin
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|fp
index|[
name|n
index|]
operator|=
name|fopen
argument_list|(
name|name
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
comment|/* Real file. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|" zopeni"
argument_list|,
name|name
argument_list|,
operator|(
name|int
operator|)
name|fp
index|[
name|n
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|fp
index|[
name|n
index|]
operator|==
name|NULL
condition|)
name|perror
argument_list|(
literal|"zopeni"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|fp
index|[
name|n
index|]
operator|!=
name|NULL
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  Z O P E N O  --  Open a new file for output.  */
end_comment

begin_macro
name|zopeno
argument_list|(
argument|n
argument_list|,
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|" zopeno"
argument_list|,
name|name
argument_list|,
name|n
argument_list|)
expr_stmt|;
if|if
condition|(
name|chkfn
argument_list|(
name|n
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
operator|(
name|n
operator|==
name|ZCTERM
operator|)
operator|||
operator|(
name|n
operator|==
name|ZSTDIO
operator|)
condition|)
block|{
comment|/* Terminal or standard output */
name|fp
index|[
name|ZOFILE
index|]
operator|=
name|stdout
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" fp[]=stdout"
argument_list|,
literal|""
argument_list|,
operator|(
name|int
operator|)
name|fp
index|[
name|n
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|fp
index|[
name|n
index|]
operator|=
name|fopen
argument_list|(
name|name
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
comment|/* A real file, try to open */
if|if
condition|(
name|fp
index|[
name|n
index|]
operator|==
name|NULL
condition|)
block|{
name|perror
argument_list|(
literal|"zopeno can't open"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|chown
argument_list|(
name|name
argument_list|,
name|getuid
argument_list|()
argument_list|,
name|getgid
argument_list|()
argument_list|)
expr_stmt|;
comment|/* In case set[gu]id */
if|if
condition|(
name|n
operator|==
name|ZDFILE
condition|)
name|setbuf
argument_list|(
name|fp
index|[
name|n
index|]
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* Debugging file unbuffered */
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|" fp[n]"
argument_list|,
literal|""
argument_list|,
operator|(
name|int
operator|)
name|fp
index|[
name|n
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|fp
index|[
name|n
index|]
operator|!=
name|NULL
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  Z C L O S E  --  Close the given file.  */
end_comment

begin_comment
comment|/*  Returns 0 if arg out of range, 1 if successful, -1 if close failed.  */
end_comment

begin_macro
name|zclose
argument_list|(
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|x
decl_stmt|;
if|if
condition|(
name|chkfn
argument_list|(
name|n
argument_list|)
operator|<
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* Check range of n */
if|if
condition|(
operator|(
name|n
operator|==
name|ZIFILE
operator|)
operator|&&
name|fp
index|[
name|ZSYSFN
index|]
condition|)
block|{
comment|/* If system function */
name|x
operator|=
name|zclosf
argument_list|()
expr_stmt|;
comment|/* do it specially */
block|}
else|else
block|{
if|if
condition|(
operator|(
name|fp
index|[
name|n
index|]
operator|!=
name|stdout
operator|)
operator|&&
operator|(
name|fp
index|[
name|n
index|]
operator|!=
name|stdin
operator|)
condition|)
name|x
operator|=
name|fclose
argument_list|(
name|fp
index|[
name|n
index|]
argument_list|)
expr_stmt|;
name|fp
index|[
name|n
index|]
operator|=
name|NULL
expr_stmt|;
block|}
return|return
operator|(
operator|(
name|x
operator|==
name|EOF
operator|)
condition|?
operator|-
literal|1
else|:
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  Z C H I N  --  Get a character from the input file.  */
end_comment

begin_comment
comment|/*  Returns -1 if EOF, 0 otherwise with character returned in argument  */
end_comment

begin_macro
name|zchin
argument_list|(
argument|n
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|a
decl_stmt|;
if|if
condition|(
name|chkfn
argument_list|(
name|n
argument_list|)
operator|<
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|a
operator|=
name|getc
argument_list|(
name|fp
index|[
name|n
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|a
operator|==
name|EOF
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
operator|*
name|c
operator|=
name|a
operator|&
literal|0377
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  Z S O U T  --  Write a string to the given file, buffered.  */
end_comment

begin_macro
name|zsout
argument_list|(
argument|n
argument_list|,
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|chkfn
argument_list|(
name|n
argument_list|)
operator|<
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|fputs
argument_list|(
name|s
argument_list|,
name|fp
index|[
name|n
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  Z S O U T L  --  Write string to file, with line terminator, buffered  */
end_comment

begin_macro
name|zsoutl
argument_list|(
argument|n
argument_list|,
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|chkfn
argument_list|(
name|n
argument_list|)
operator|<
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|fputs
argument_list|(
name|s
argument_list|,
name|fp
index|[
name|n
index|]
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\n"
argument_list|,
name|fp
index|[
name|n
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  Z S O U T X  --  Write x characters to file, unbuffered.  */
end_comment

begin_macro
name|zsoutx
argument_list|(
argument|n
argument_list|,
argument|s
argument_list|,
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|int
name|n
decl_stmt|,
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|chkfn
argument_list|(
name|n
argument_list|)
operator|<
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
name|write
argument_list|(
name|fp
index|[
name|n
index|]
operator|->
name|_file
argument_list|,
name|s
argument_list|,
name|x
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  Z C H O U T  --  Add a character to the given file.  */
end_comment

begin_comment
comment|/*  Should return 0 or greater on success, -1 on failure (e.g. disk full)  */
end_comment

begin_macro
name|zchout
argument_list|(
argument|n
argument_list|,
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|chkfn
argument_list|(
name|n
argument_list|)
operator|<
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|n
operator|==
name|ZSFILE
condition|)
return|return
operator|(
name|write
argument_list|(
name|fp
index|[
name|n
index|]
operator|->
name|_file
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
operator|)
return|;
comment|/* Use unbuffered for session log */
else|else
block|{
comment|/* Buffered for everything else */
if|if
condition|(
name|putc
argument_list|(
name|c
argument_list|,
name|fp
index|[
name|n
index|]
argument_list|)
operator|==
name|EOF
condition|)
comment|/* If true, maybe there was an error */
return|return
operator|(
name|ferror
argument_list|(
name|fp
index|[
name|n
index|]
argument_list|)
operator|)
return|;
comment|/* Check to make sure */
else|else
comment|/* Otherwise... */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* There was no error. */
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  C H K F N  --  Internal function to verify file number is ok  */
end_comment

begin_comment
comment|/*  Returns:   -1: File number n is out of range    0: n is in range, but file is not open    1: n in range and file is open */
end_comment

begin_macro
name|chkfn
argument_list|(
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
switch|switch
condition|(
name|n
condition|)
block|{
case|case
name|ZCTERM
case|:
case|case
name|ZSTDIO
case|:
case|case
name|ZIFILE
case|:
case|case
name|ZOFILE
case|:
case|case
name|ZDFILE
case|:
case|case
name|ZTFILE
case|:
case|case
name|ZPFILE
case|:
case|case
name|ZSFILE
case|:
case|case
name|ZSYSFN
case|:
break|break;
default|default:
name|debug
argument_list|(
name|F101
argument_list|,
literal|"chkfn: file number out of range"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"?File number out of range - %d\n"
argument_list|,
name|n
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
return|return
operator|(
operator|(
name|fp
index|[
name|n
index|]
operator|==
name|NULL
operator|)
condition|?
literal|0
else|:
literal|1
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  Z C H K I  --  Check if input file exists and is readable  */
end_comment

begin_comment
comment|/*   Returns:>= 0 if the file can be read (returns the size).      -1 if file doesn't exist or can't be accessed,      -2 if file exists but is not readable (e.g. a directory file).      -3 if file exists but protected against read access. */
end_comment

begin_comment
comment|/*  For Berkeley Unix, a file must be of type "regular" to be readable.  Directory files, special files, and symbolic links are not readable. */
end_comment

begin_function
name|long
name|zchki
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|struct
name|stat
name|buf
decl_stmt|;
name|int
name|x
decl_stmt|;
name|long
name|y
decl_stmt|;
name|x
operator|=
name|stat
argument_list|(
name|name
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zchki stat fails"
argument_list|,
name|name
argument_list|,
name|errno
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|x
operator|=
name|buf
operator|.
name|st_mode
operator|&
name|S_IFMT
expr_stmt|;
comment|/* Isolate file format field */
if|if
condition|(
operator|(
name|x
operator|!=
literal|0
operator|)
operator|&&
operator|(
name|x
operator|!=
name|S_IFREG
operator|)
condition|)
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zchki skipping:"
argument_list|,
name|name
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zchki stat ok:"
argument_list|,
name|name
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|x
operator|=
name|access
argument_list|(
name|name
argument_list|,
name|R_OK
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
comment|/* Is the file accessible? */
name|debug
argument_list|(
name|F111
argument_list|,
literal|" access failed:"
argument_list|,
name|name
argument_list|,
name|x
argument_list|)
expr_stmt|;
comment|/* No */
return|return
operator|(
operator|-
literal|3
operator|)
return|;
block|}
else|else
block|{
name|y
operator|=
name|buf
operator|.
name|st_size
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|" access ok:"
argument_list|,
name|name
argument_list|,
operator|(
name|int
operator|)
name|y
argument_list|)
expr_stmt|;
comment|/* Yes */
return|return
operator|(
operator|(
name|y
operator|>
operator|-
literal|1
operator|)
condition|?
name|y
else|:
literal|0
operator|)
return|;
block|}
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  Z C H K O  --  Check if output file can be created  */
end_comment

begin_comment
comment|/*  Returns -1 if write permission for the file would be denied, 0 otherwise. */
end_comment

begin_macro
name|zchko
argument_list|(
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|,
name|x
decl_stmt|;
name|char
name|s
index|[
literal|50
index|]
decl_stmt|,
modifier|*
name|sp
decl_stmt|;
name|sp
operator|=
name|s
expr_stmt|;
comment|/* Make a copy, get length */
name|x
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
operator|*
name|sp
operator|++
operator|=
operator|*
name|name
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
name|x
operator|++
expr_stmt|;
if|if
condition|(
name|x
operator|==
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* If no filename, fail. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|" length"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|x
init|;
name|i
operator|>
literal|0
condition|;
name|i
operator|--
control|)
comment|/* Strip filename. */
if|if
condition|(
name|s
index|[
name|i
operator|-
literal|1
index|]
operator|==
literal|'/'
condition|)
break|break;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" i"
argument_list|,
literal|""
argument_list|,
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
comment|/* If no path, use current directory */
name|strcpy
argument_list|(
name|s
argument_list|,
literal|"./"
argument_list|)
expr_stmt|;
else|else
comment|/* Otherwise, use given one. */
name|s
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
name|x
operator|=
name|access
argument_list|(
name|s
argument_list|,
name|W_OK
argument_list|)
expr_stmt|;
comment|/* Check access of path. */
if|if
condition|(
name|x
operator|<
literal|0
condition|)
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zchko access failed:"
argument_list|,
name|s
argument_list|,
name|errno
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
else|else
block|{
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zchko access ok:"
argument_list|,
name|s
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  Z D E L E T  --  Delete the named file.  */
end_comment

begin_macro
name|zdelet
argument_list|(
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|unlink
argument_list|(
name|name
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  Z R T O L  --  Convert remote filename into local form  */
end_comment

begin_comment
comment|/*  For UNIX, this means changing uppercase letters to lowercase.  */
end_comment

begin_macro
name|zrtol
argument_list|(
argument|name
argument_list|,
argument|name2
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|,
modifier|*
name|name2
decl_stmt|;
end_decl_stmt

begin_block
block|{
for|for
control|(
init|;
operator|*
name|name
operator|!=
literal|'\0'
condition|;
name|name
operator|++
control|)
block|{
operator|*
name|name2
operator|++
operator|=
name|isupper
argument_list|(
operator|*
name|name
argument_list|)
condition|?
name|tolower
argument_list|(
operator|*
name|name
argument_list|)
else|:
operator|*
name|name
expr_stmt|;
block|}
operator|*
name|name2
operator|=
literal|'\0'
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zrtol:"
argument_list|,
name|name2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  Z L T O R  --  Local TO Remote */
end_comment

begin_comment
comment|/*  Convert filename from local format to common (remote) form.  */
end_comment

begin_macro
name|zltor
argument_list|(
argument|name
argument_list|,
argument|name2
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|,
modifier|*
name|name2
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|work
index|[
literal|100
index|]
decl_stmt|,
modifier|*
name|cp
decl_stmt|,
modifier|*
name|pp
decl_stmt|;
name|int
name|dc
init|=
literal|0
decl_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"zltor"
argument_list|,
name|name
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pp
operator|=
name|work
expr_stmt|;
for|for
control|(
name|cp
operator|=
name|name
init|;
operator|*
name|cp
operator|!=
literal|'\0'
condition|;
name|cp
operator|++
control|)
block|{
comment|/* strip path name */
if|if
condition|(
operator|*
name|cp
operator|==
literal|'/'
condition|)
block|{
name|dc
operator|=
literal|0
expr_stmt|;
name|pp
operator|=
name|work
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|islower
argument_list|(
operator|*
name|cp
argument_list|)
condition|)
operator|*
name|pp
operator|++
operator|=
name|toupper
argument_list|(
operator|*
name|cp
argument_list|)
expr_stmt|;
comment|/* Uppercase letters */
elseif|else
if|if
condition|(
operator|*
name|cp
operator|==
literal|'~'
condition|)
operator|*
name|pp
operator|++
operator|=
literal|'X'
expr_stmt|;
comment|/* Change tilde to 'X' */
elseif|else
if|if
condition|(
operator|*
name|cp
operator|==
literal|'#'
condition|)
operator|*
name|pp
operator|++
operator|=
literal|'X'
expr_stmt|;
comment|/* Change number sign to 'X' */
elseif|else
if|if
condition|(
operator|(
operator|*
name|cp
operator|==
literal|'.'
operator|)
operator|&&
operator|(
operator|++
name|dc
operator|>
literal|1
operator|)
condition|)
operator|*
name|pp
operator|++
operator|=
literal|'X'
expr_stmt|;
comment|/*& extra dots */
else|else
operator|*
name|pp
operator|++
operator|=
operator|*
name|cp
expr_stmt|;
block|}
operator|*
name|pp
operator|=
literal|'\0'
expr_stmt|;
comment|/* Tie it off. */
name|cp
operator|=
name|name2
expr_stmt|;
comment|/* If nothing before dot, */
if|if
condition|(
operator|*
name|work
operator|==
literal|'.'
condition|)
operator|*
name|cp
operator|++
operator|=
literal|'X'
expr_stmt|;
comment|/* insert 'X' */
name|strcpy
argument_list|(
name|cp
argument_list|,
name|work
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|" name2"
argument_list|,
name|name2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  Z C H D I R  --  Change directory  */
end_comment

begin_macro
name|zchdir
argument_list|(
argument|dirnam
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|dirnam
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|hd
decl_stmt|;
if|if
condition|(
operator|*
name|dirnam
operator|==
literal|'\0'
condition|)
name|hd
operator|=
name|getenv
argument_list|(
literal|"HOME"
argument_list|)
expr_stmt|;
else|else
name|hd
operator|=
name|dirnam
expr_stmt|;
return|return
operator|(
operator|(
name|chdir
argument_list|(
name|hd
argument_list|)
operator|==
literal|0
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  Z H O M E  --  Return pointer to user's home directory  */
end_comment

begin_function
name|char
modifier|*
name|zhome
parameter_list|()
block|{
return|return
operator|(
name|getenv
argument_list|(
literal|"HOME"
argument_list|)
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  Z X C M D -- Run a system command so its output can be read like a file */
end_comment

begin_macro
name|zxcmd
argument_list|(
argument|comand
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|comand
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|pipes
index|[
literal|2
index|]
decl_stmt|;
if|if
condition|(
name|pipe
argument_list|(
name|pipes
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* can't make pipe, fail */
if|if
condition|(
operator|(
name|pid
operator|=
name|fork
argument_list|()
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* child */
comment|/*#if BSD4*/
comment|/* Code from Dave Tweten@AMES-NAS */
comment|/* readapted to use getpwuid to find login shell */
comment|/*   -- H. Fischer */
name|char
modifier|*
name|shpath
decl_stmt|,
modifier|*
name|shname
decl_stmt|,
modifier|*
name|shptr
decl_stmt|;
comment|/* to find desired shell */
name|struct
name|passwd
modifier|*
name|p
decl_stmt|;
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|()
function_decl|;
specifier|extern
name|int
name|getuid
parameter_list|()
function_decl|;
name|char
modifier|*
name|defShel
init|=
literal|"/bin/sh"
decl_stmt|;
comment|/* default shell */
comment|/*#endif*/
name|close
argument_list|(
name|pipes
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|/* close input side of pipe */
name|close
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* close stdin */
if|if
condition|(
name|open
argument_list|(
literal|"/dev/null"
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* replace input by null */
ifndef|#
directive|ifndef
name|UXIII
name|dup2
argument_list|(
name|pipes
index|[
literal|1
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* replace stdout& stderr */
name|dup2
argument_list|(
name|pipes
index|[
literal|1
index|]
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|/* by the pipe */
else|#
directive|else
name|close
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* simulate dup2 */
if|if
condition|(
name|dup
argument_list|(
name|pipes
index|[
literal|1
index|]
argument_list|)
operator|!=
literal|1
condition|)
name|conol
argument_list|(
literal|"trouble duping stdout in routine zxcmd\n"
argument_list|)
expr_stmt|;
name|close
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|/* simulate dup2 */
if|if
condition|(
name|dup
argument_list|(
name|pipes
index|[
literal|1
index|]
argument_list|)
operator|!=
literal|2
condition|)
name|conol
argument_list|(
literal|"trouble duping stderr in routine zxcmd\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|close
argument_list|(
name|pipes
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|/* get rid of this copy of the pipe */
comment|/**** 	shptr = shname = shpath = getenv("SHELL");  /* What shell? */
name|p
operator|=
name|getpwuid
argument_list|(
name|getuid
argument_list|()
argument_list|)
expr_stmt|;
comment|/* get login data */
if|if
condition|(
name|p
operator|==
operator|(
expr|struct
name|passwd
operator|*
operator|)
name|NULL
operator|||
operator|!
operator|*
operator|(
name|p
operator|->
name|pw_shell
operator|)
condition|)
name|shpath
operator|=
name|defShel
expr_stmt|;
else|else
name|shpath
operator|=
name|p
operator|->
name|pw_shell
expr_stmt|;
name|shptr
operator|=
name|shname
operator|=
name|shpath
expr_stmt|;
while|while
condition|(
operator|*
name|shptr
operator|!=
literal|'\0'
condition|)
if|if
condition|(
operator|*
name|shptr
operator|++
operator|==
literal|'/'
condition|)
name|shname
operator|=
name|shptr
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"zxcmd..."
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
name|shpath
argument_list|,
name|shname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|execl
argument_list|(
name|shpath
argument_list|,
name|shname
argument_list|,
literal|"-c"
argument_list|,
name|comand
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Execute the command */
comment|/****	execl("/bin/sh","sh","-c",comand,0); /* Execute the command */
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* just punt if it didnt work */
block|}
name|close
argument_list|(
name|pipes
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|/* don't need the output side */
name|fp
index|[
name|ZIFILE
index|]
operator|=
name|fdopen
argument_list|(
name|pipes
index|[
literal|0
index|]
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
comment|/* open a stream for it */
name|fp
index|[
name|ZSYSFN
index|]
operator|=
name|fp
index|[
name|ZIFILE
index|]
expr_stmt|;
comment|/* Remember. */
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  Z C L O S F  - wait for the child fork to terminate and close the pipe. */
end_comment

begin_macro
name|zclosf
argument_list|()
end_macro

begin_block
block|{
name|int
name|wstat
decl_stmt|;
name|fclose
argument_list|(
name|fp
index|[
name|ZIFILE
index|]
argument_list|)
expr_stmt|;
name|fp
index|[
name|ZIFILE
index|]
operator|=
name|fp
index|[
name|ZSYSFN
index|]
operator|=
name|NULL
expr_stmt|;
while|while
condition|(
operator|(
name|wstat
operator|=
name|wait
argument_list|(
literal|0
argument_list|)
operator|)
operator|!=
name|pid
operator|&&
name|wstat
operator|!=
operator|-
literal|1
condition|)
empty_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  Z X P A N D  --  Expand a wildcard string into an array of strings  */
end_comment

begin_comment
comment|/*   Returns the number of files that match fn1, with data structures set up   so that first file (if any) will be returned by the next znext() call. */
end_comment

begin_macro
name|zxpand
argument_list|(
argument|fn
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|fn
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fcount
operator|=
name|fgen
argument_list|(
name|fn
argument_list|,
name|mtchs
argument_list|,
name|MAXWLD
argument_list|)
expr_stmt|;
comment|/* Look up the file. */
if|if
condition|(
name|fcount
operator|>
literal|0
condition|)
block|{
name|mtchptr
operator|=
name|mtchs
expr_stmt|;
comment|/* Save pointer for next. */
block|}
name|debug
argument_list|(
name|F111
argument_list|,
literal|"zxpand"
argument_list|,
name|mtchs
index|[
literal|0
index|]
argument_list|,
name|fcount
argument_list|)
expr_stmt|;
return|return
operator|(
name|fcount
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  Z N E X T  --  Get name of next file from list created by zxpand(). */
end_comment

begin_comment
comment|/*  Returns>0 if there's another file, with its name copied into the arg string,  or 0 if no more files in list. */
end_comment

begin_macro
name|znext
argument_list|(
argument|fn
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|fn
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|fcount
operator|--
operator|>
literal|0
condition|)
name|strcpy
argument_list|(
name|fn
argument_list|,
operator|*
name|mtchptr
operator|++
argument_list|)
expr_stmt|;
else|else
operator|*
name|fn
operator|=
literal|'\0'
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"znext"
argument_list|,
name|fn
argument_list|,
name|fcount
operator|+
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
name|fcount
operator|+
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  Z N E W N  --  Make a new name for the given file  */
end_comment

begin_macro
name|znewn
argument_list|(
argument|fn
argument_list|,
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|fn
decl_stmt|,
modifier|*
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|char
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|char
modifier|*
name|bp
decl_stmt|,
modifier|*
name|xp
decl_stmt|;
name|int
name|len
init|=
literal|0
decl_stmt|,
name|n
init|=
literal|0
decl_stmt|,
name|d
init|=
literal|0
decl_stmt|,
name|t
decl_stmt|;
ifdef|#
directive|ifdef
name|MAXNAMLEN
name|int
name|max
init|=
name|MAXNAMLEN
decl_stmt|;
else|#
directive|else
name|int
name|max
init|=
literal|14
decl_stmt|;
endif|#
directive|endif
name|bp
operator|=
name|buf
expr_stmt|;
while|while
condition|(
operator|*
name|fn
condition|)
block|{
comment|/* Copy name into buf */
operator|*
name|bp
operator|++
operator|=
operator|*
name|fn
operator|++
expr_stmt|;
name|len
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|len
operator|>
name|max
operator|-
literal|3
condition|)
name|bp
operator|-=
literal|3
expr_stmt|;
comment|/* Don't let it get too long */
operator|*
name|bp
operator|++
operator|=
literal|'*'
expr_stmt|;
comment|/* Put a star on the end */
operator|*
name|bp
operator|--
operator|=
literal|'\0'
expr_stmt|;
name|n
operator|=
name|zxpand
argument_list|(
name|buf
argument_list|)
expr_stmt|;
comment|/* Expand the resulting wild name */
while|while
condition|(
name|n
operator|--
operator|>
literal|0
condition|)
block|{
comment|/* Find any existing name~d files */
name|xp
operator|=
operator|*
name|mtchptr
operator|++
expr_stmt|;
name|xp
operator|+=
name|len
expr_stmt|;
if|if
condition|(
operator|*
name|xp
operator|==
literal|'~'
condition|)
block|{
name|t
operator|=
name|atoi
argument_list|(
name|xp
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|>
name|d
condition|)
name|d
operator|=
name|t
expr_stmt|;
comment|/* Get maximum d */
block|}
block|}
name|sprintf
argument_list|(
name|bp
argument_list|,
literal|"~%d"
argument_list|,
name|d
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|/* Make name~(d+1) */
operator|*
name|s
operator|=
name|buf
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* Directory Functions for Unix, written by Jeff Damens, CUCCA, 1984. */
end_comment

begin_comment
comment|/*  * The path structure is used to represent the name to match.  * Each slash-separated segment of the name is kept in one  * such structure, and they are linked together, to make  * traversing the name easier.  */
end_comment

begin_struct
struct|struct
name|path
block|{
name|char
name|npart
index|[
name|MAXNAMLEN
index|]
decl_stmt|;
comment|/* name part of path segment */
name|struct
name|path
modifier|*
name|fwd
decl_stmt|;
comment|/* forward ptr */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|PROVX1
end_ifdef

begin_define
define|#
directive|define
name|SSPACE
value|500
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SSPACE
value|2000
end_define

begin_comment
comment|/* size of string-generating buffer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|char
name|sspace
index|[
name|SSPACE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer to generate names in */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|freeptr
decl_stmt|,
modifier|*
modifier|*
name|resptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* copies of caller's arguments */
end_comment

begin_decl_stmt
specifier|static
name|int
name|remlen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remaining length in caller's array*/
end_comment

begin_decl_stmt
specifier|static
name|int
name|numfnd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of matches found */
end_comment

begin_comment
comment|/*  * splitpath:  *  takes a string and splits the slash-separated portions into  *  a list of path structures.  Returns the head of the list.  The  *  structures are allocated by malloc, so they must be freed.  *  Splitpath is used internally by the filename generator.  *  * Input: A string.  * Returns: A linked list of the slash-separated segments of the input.  */
end_comment

begin_function
name|struct
name|path
modifier|*
name|splitpath
parameter_list|(
name|p
parameter_list|)
name|char
modifier|*
name|p
decl_stmt|;
block|{
name|struct
name|path
modifier|*
name|head
decl_stmt|,
modifier|*
name|cur
decl_stmt|,
modifier|*
name|prv
decl_stmt|;
name|int
name|i
decl_stmt|;
name|head
operator|=
name|prv
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|==
literal|'/'
condition|)
name|p
operator|++
expr_stmt|;
comment|/* skip leading slash */
while|while
condition|(
operator|*
name|p
operator|!=
literal|'\0'
condition|)
block|{
name|cur
operator|=
operator|(
expr|struct
name|path
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|path
argument_list|)
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"splitpath malloc"
argument_list|,
literal|""
argument_list|,
name|cur
argument_list|)
expr_stmt|;
if|if
condition|(
name|cur
operator|==
name|NULL
condition|)
name|fatal
argument_list|(
literal|"malloc fails in splitpath()"
argument_list|)
expr_stmt|;
name|cur
operator|->
name|fwd
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|head
operator|==
name|NULL
condition|)
name|head
operator|=
name|cur
expr_stmt|;
else|else
name|prv
operator|->
name|fwd
operator|=
name|cur
expr_stmt|;
comment|/* link into chain */
name|prv
operator|=
name|cur
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAXNAMLEN
operator|&&
operator|*
name|p
operator|!=
literal|'/'
operator|&&
operator|*
name|p
operator|!=
literal|'\0'
condition|;
name|i
operator|++
control|)
name|cur
operator|->
name|npart
index|[
name|i
index|]
operator|=
operator|*
name|p
operator|++
expr_stmt|;
name|cur
operator|->
name|npart
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* end this segment */
if|if
condition|(
name|i
operator|>=
name|MAXNAMLEN
condition|)
while|while
condition|(
operator|*
name|p
operator|!=
literal|'/'
operator|&&
operator|*
name|p
operator|!=
literal|'\0'
condition|)
name|p
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|==
literal|'/'
condition|)
name|p
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|head
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  * fgen:  *  This is the actual name generator.  It is passed a string,  *  possibly containing wildcards, and an array of character pointers.  *  It finds all the matching filenames and stores them into the array.  *  The returned strings are allocated from a static buffer local to  *  this module (so the caller doesn't have to worry about deallocating  *  them); this means that successive calls to fgen will wipe out  *  the results of previous calls.  This isn't a problem here  *  because we process one wildcard string at a time.  *  * Input: a wildcard string, an array to write names to, the  *        length of the array.  * Returns: the number of matches.  The array is filled with filenames  *          that matched the pattern.  If there wasn't enough room in the  *	    array, -1 is returned.  * By: Jeff Damens, CUCCA, 1984.  */
end_comment

begin_macro
name|fgen
argument_list|(
argument|pat
argument_list|,
argument|resarry
argument_list|,
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|pat
decl_stmt|,
modifier|*
name|resarry
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|path
modifier|*
name|head
decl_stmt|;
name|char
name|scratch
index|[
literal|100
index|]
decl_stmt|,
modifier|*
name|sptr
decl_stmt|;
name|head
operator|=
name|splitpath
argument_list|(
name|pat
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|pat
operator|==
literal|'/'
condition|)
block|{
name|scratch
index|[
literal|0
index|]
operator|=
literal|'/'
expr_stmt|;
name|sptr
operator|=
name|scratch
operator|+
literal|1
expr_stmt|;
block|}
else|else
block|{
name|strcpy
argument_list|(
name|scratch
argument_list|,
literal|"./"
argument_list|)
expr_stmt|;
name|sptr
operator|=
name|scratch
operator|+
literal|2
expr_stmt|;
block|}
comment|/* init buffer correctly */
name|numfnd
operator|=
literal|0
expr_stmt|;
comment|/* none found yet */
name|freeptr
operator|=
name|sspace
expr_stmt|;
comment|/* this is where matches are copied */
name|resptr
operator|=
name|resarry
expr_stmt|;
comment|/* static copies of these so*/
name|remlen
operator|=
name|len
expr_stmt|;
comment|/* recursive calls can alter them */
name|traverse
argument_list|(
name|head
argument_list|,
name|scratch
argument_list|,
name|sptr
argument_list|)
expr_stmt|;
comment|/* go walk the directory tree */
for|for
control|(
init|;
name|head
operator|!=
name|NULL
condition|;
name|head
operator|=
name|head
operator|->
name|fwd
control|)
name|free
argument_list|(
name|head
argument_list|)
expr_stmt|;
comment|/* return the path segments */
return|return
operator|(
name|numfnd
operator|)
return|;
comment|/* and return the number of matches */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* traverse:  *  Walks the directory tree looking for matches to its arguments.  *  The algorithm is, briefly:  *   If the current pattern segment contains no wildcards, that  *   segment is added to what we already have.  If the name so far  *   exists, we call ourselves recursively with the next segment  *   in the pattern string; otherwise, we just return.  *  *   If the current pattern segment contains wildcards, we open the name  *   we've accumulated so far (assuming it is really a directory), then read   *   each filename in it, and, if it matches the wildcard pattern segment, add  *   that filename to what we have so far and call ourselves recursively on the  *   next segment.  *  *   Finally, when no more pattern segments remain, we add what's accumulated  *   so far to the result array and increment the number of matches.  *  * Input: a pattern path list (as generated by splitpath), a string  *	  pointer that points to what we've traversed so far (this  *	  can be initialized to "/" to start the search at the root  *	  directory, or to "./" to start the search at the current  *	  directory), and a string pointer to the end of the string  *	  in the previous argument.  * Returns: nothing.  */
end_comment

begin_macro
name|traverse
argument_list|(
argument|pl
argument_list|,
argument|sofar
argument_list|,
argument|endcur
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|path
modifier|*
name|pl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|sofar
decl_stmt|,
modifier|*
name|endcur
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|BSD42
name|DIR
modifier|*
name|fd
decl_stmt|,
modifier|*
name|opendir
argument_list|()
decl_stmt|;
name|struct
name|direct
modifier|*
name|dirbuf
decl_stmt|;
else|#
directive|else
name|int
name|fd
decl_stmt|;
name|struct
name|direct
name|dir_entry
decl_stmt|;
name|struct
name|direct
modifier|*
name|dirbuf
init|=
operator|&
name|dir_entry
decl_stmt|;
endif|#
directive|endif
name|struct
name|stat
name|statbuf
decl_stmt|;
if|if
condition|(
name|pl
operator|==
name|NULL
condition|)
block|{
operator|*
operator|--
name|endcur
operator|=
literal|'\0'
expr_stmt|;
comment|/* end string, overwrite trailing / */
name|addresult
argument_list|(
name|sofar
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|iswild
argument_list|(
name|pl
operator|->
name|npart
argument_list|)
condition|)
block|{
name|strcpy
argument_list|(
name|endcur
argument_list|,
name|pl
operator|->
name|npart
argument_list|)
expr_stmt|;
name|endcur
operator|+=
name|strlen
argument_list|(
name|pl
operator|->
name|npart
argument_list|)
expr_stmt|;
operator|*
name|endcur
operator|=
literal|'\0'
expr_stmt|;
comment|/* end current string */
if|if
condition|(
name|stat
argument_list|(
name|sofar
argument_list|,
operator|&
name|statbuf
argument_list|)
operator|==
literal|0
condition|)
comment|/* if current piece exists */
block|{
operator|*
name|endcur
operator|++
operator|=
literal|'/'
expr_stmt|;
comment|/* add slash to end */
operator|*
name|endcur
operator|=
literal|'\0'
expr_stmt|;
comment|/* and end the string */
name|traverse
argument_list|(
name|pl
operator|->
name|fwd
argument_list|,
name|sofar
argument_list|,
name|endcur
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
comment|/* cont'd... */
comment|/*...traverse, cont'd */
comment|/* segment contains wildcards, have to search directory */
operator|*
name|endcur
operator|=
literal|'\0'
expr_stmt|;
comment|/* end current string */
if|if
condition|(
name|stat
argument_list|(
name|sofar
argument_list|,
operator|&
name|statbuf
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return;
comment|/* doesn't exist, forget it */
if|if
condition|(
operator|(
name|statbuf
operator|.
name|st_mode
operator|&
name|S_IFDIR
operator|)
operator|==
literal|0
condition|)
return|return;
comment|/* not a directory, skip */
ifdef|#
directive|ifdef
name|BSD42
comment|/* ==BSD4 */
if|if
condition|(
operator|(
name|fd
operator|=
name|opendir
argument_list|(
name|sofar
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return;
comment|/* can't open, forget it */
while|while
condition|(
name|dirbuf
operator|=
name|readdir
argument_list|(
name|fd
argument_list|)
condition|)
else|#
directive|else
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|sofar
argument_list|,
name|O_RDONLY
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return;
comment|/* can't open, forget it */
while|while
condition|(
name|read
argument_list|(
name|fd
argument_list|,
name|dirbuf
argument_list|,
sizeof|sizeof
name|dir_entry
argument_list|)
condition|)
endif|#
directive|endif
block|{
name|strncpy
argument_list|(
name|nambuf
argument_list|,
name|dirbuf
operator|->
name|d_name
argument_list|,
name|MAXNAMLEN
argument_list|)
expr_stmt|;
comment|/* Get a null terminated copy!!! */
name|nambuf
index|[
name|MAXNAMLEN
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|dirbuf
operator|->
name|d_ino
operator|!=
literal|0
operator|&&
name|match
argument_list|(
name|pl
operator|->
name|npart
argument_list|,
name|nambuf
argument_list|)
condition|)
block|{
name|char
modifier|*
name|eos
decl_stmt|;
name|strcpy
argument_list|(
name|endcur
argument_list|,
name|nambuf
argument_list|)
expr_stmt|;
name|eos
operator|=
name|endcur
operator|+
name|strlen
argument_list|(
name|nambuf
argument_list|)
expr_stmt|;
operator|*
name|eos
operator|=
literal|'/'
expr_stmt|;
comment|/* end this segment */
name|traverse
argument_list|(
name|pl
operator|->
name|fwd
argument_list|,
name|sofar
argument_list|,
name|eos
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
ifdef|#
directive|ifdef
name|BSD42
comment|/* ==BSD4 */
name|closedir
argument_list|(
name|fd
argument_list|)
expr_stmt|;
else|#
directive|else
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  * addresult:  *  Adds a result string to the result array.  Increments the number  *  of matches found, copies the found string into our string  *  buffer, and puts a pointer to the buffer into the caller's result  *  array.  Our free buffer pointer is updated.  If there is no  *  more room in the caller's array, the number of matches is set to -1.  * Input: a result string.  * Returns: nothing.  */
end_comment

begin_macro
name|addresult
argument_list|(
argument|str
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|l
decl_stmt|;
if|if
condition|(
name|strncmp
argument_list|(
name|str
argument_list|,
literal|"./"
argument_list|,
literal|2
argument_list|)
operator|==
literal|0
condition|)
name|str
operator|+=
literal|2
expr_stmt|;
if|if
condition|(
operator|--
name|remlen
operator|<
literal|0
condition|)
block|{
name|numfnd
operator|=
operator|-
literal|1
expr_stmt|;
return|return;
block|}
name|l
operator|=
name|strlen
argument_list|(
name|str
argument_list|)
operator|+
literal|1
expr_stmt|;
comment|/* size this will take up */
if|if
condition|(
operator|(
name|freeptr
operator|+
name|l
operator|)
operator|>
operator|&
name|sspace
index|[
name|SSPACE
index|]
condition|)
block|{
name|numfnd
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* do not record if not enough space */
return|return;
block|}
name|strcpy
argument_list|(
name|freeptr
argument_list|,
name|str
argument_list|)
expr_stmt|;
operator|*
name|resptr
operator|++
operator|=
name|freeptr
expr_stmt|;
name|freeptr
operator|+=
name|l
expr_stmt|;
name|numfnd
operator|++
expr_stmt|;
block|}
end_block

begin_macro
name|iswild
argument_list|(
argument|str
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|c
decl_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
operator|*
name|str
operator|++
operator|)
operator|!=
literal|'\0'
condition|)
if|if
condition|(
name|c
operator|==
literal|'*'
operator|||
name|c
operator|==
literal|'?'
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  * match:  *  pattern matcher.  Takes a string and a pattern possibly containing  *  the wildcard characters '*' and '?'.  Returns true if the pattern  *  matches the string, false otherwise.  * by: Jeff Damens, CUCCA  *  * Input: a string and a wildcard pattern.  * Returns: 1 if match, 0 if no match.  */
end_comment

begin_macro
name|match
argument_list|(
argument|pattern
argument_list|,
argument|string
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|pattern
decl_stmt|,
modifier|*
name|string
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|psave
decl_stmt|,
modifier|*
name|ssave
decl_stmt|;
comment|/* back up pointers for failure */
name|psave
operator|=
name|ssave
operator|=
name|NULL
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
for|for
control|(
init|;
operator|*
name|pattern
operator|==
operator|*
name|string
condition|;
name|pattern
operator|++
operator|,
name|string
operator|++
control|)
comment|/* skip first */
if|if
condition|(
operator|*
name|string
operator|==
literal|'\0'
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* end of strings, succeed */
if|if
condition|(
operator|*
name|string
operator|!=
literal|'\0'
operator|&&
operator|*
name|pattern
operator|==
literal|'?'
condition|)
block|{
name|pattern
operator|++
expr_stmt|;
comment|/* '?', let it match */
name|string
operator|++
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|pattern
operator|==
literal|'*'
condition|)
block|{
comment|/* '*' ... */
name|psave
operator|=
operator|++
name|pattern
expr_stmt|;
comment|/* remember where we saw it */
name|ssave
operator|=
name|string
expr_stmt|;
comment|/* let it match 0 chars */
block|}
elseif|else
if|if
condition|(
name|ssave
operator|!=
name|NULL
operator|&&
operator|*
name|ssave
operator|!=
literal|'\0'
condition|)
block|{
comment|/* if not at end  */
comment|/* ...have seen a star */
name|string
operator|=
operator|++
name|ssave
expr_stmt|;
comment|/* skip 1 char from string */
name|pattern
operator|=
name|psave
expr_stmt|;
comment|/* and back up pattern */
block|}
else|else
return|return
operator|(
literal|0
operator|)
return|;
comment|/* otherwise just fail */
block|}
block|}
end_block

end_unit

