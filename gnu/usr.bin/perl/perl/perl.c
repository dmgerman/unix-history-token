begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
name|rcsid
index|[]
init|=
literal|"$RCSfile: perl.c,v $$Revision: 1.7 $$Date: 1996/06/30 09:47:56 $\nPatch level: ###\n"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: perl.c,v $  * Revision 1.7  1996/06/30 09:47:56  joerg  * Back out Nate's changes from rev. 1.6; our Perl has not been  * vulnerable since it used setreuid() as opposed to Posix saved IDs.  * The change broke setuid scripts.  *  * Revision 1.5  1996/06/02 19:59:24  gpalmer  * Use setreuid instead of seteuid for permissions management  *  * Revision 1.4  1995/05/30 05:03:10  rgrimes  * Remove trailing whitespace.  *  * Revision 1.3  1995/05/28  19:21:54  ache  * Fix $] variable value (version number), close PR 449  * Submitted by: Bill Fenner<fenner@parc.xerox.com>  *  * Revision 1.2  1994/10/27  23:16:54  wollman  * Convince Perl to that is is part of the system, as /usr/bin/perl (binary)  * and /usr/share/perl (library).  The latter was chosen as analogous to other  * directories already present in /usr/share, like /usr/share/groff_font and  * (particularly) /usr/share/mk.  *  * Revision 1.1.1.1  1994/09/10  06:27:33  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:29:37  nate  * PERL!  *  * Revision 4.0.1.8  1993/02/05  19:39:30  lwall  * patch36: the taintanyway code wasn't tainting anyway  * patch36: Malformed cmd links core dump apparently fixed  *  * Revision 4.0.1.7  92/06/08  14:50:39  lwall  * patch20: PERLLIB now supports multiple directories  * patch20: running taintperl explicitly now does checks even if $< == $>  * patch20: -e 'cmd' no longer fails silently if /tmp runs out of space  * patch20: perl -P now uses location of sed determined by Configure  * patch20: form feed for formats is now specifiable via $^L  * patch20: paragraph mode now skips extra newlines automatically  * patch20: eval "1 #comment" didn't work  * patch20: couldn't require . files  * patch20: semantic compilation errors didn't abort execution  *  * Revision 4.0.1.6  91/11/11  16:38:45  lwall  * patch19: default arg for shift was wrong after first subroutine definition  * patch19: op/regexp.t failed from missing arg to bcmp()  *  * Revision 4.0.1.5  91/11/05  18:03:32  lwall  * patch11: random cleanup  * patch11: $0 was being truncated at times  * patch11: cppstdin now installed outside of source directory  * patch11: -P didn't allow use of #elif or #undef  * patch11: prepared for ctype implementations that don't define isascii()  * patch11: added eval {}  * patch11: eval confused by string containing null  *  * Revision 4.0.1.4  91/06/10  01:23:07  lwall  * patch10: perl -v printed incorrect copyright notice  *  * Revision 4.0.1.3  91/06/07  11:40:18  lwall  * patch4: changed old $^P to $^X  *  * Revision 4.0.1.2  91/06/07  11:26:16  lwall  * patch4: new copyright notice  * patch4: added $^P variable to control calling of perldb routines  * patch4: added $^F variable to specify maximum system fd, default 2  * patch4: debugger lost track of lines in eval  *  * Revision 4.0.1.1  91/04/11  17:49:05  lwall  * patch1: fixed undefined environ problem  *  * Revision 4.0  91/03/20  01:37:44  lwall  * 4.0 baseline.  *  */
end_comment

begin_comment
comment|/*SUPPRESS 560*/
end_comment

begin_include
include|#
directive|include
file|"EXTERN.h"
end_include

begin_include
include|#
directive|include
file|"perl.h"
end_include

begin_include
include|#
directive|include
file|"perly.h"
end_include

begin_include
include|#
directive|include
file|"patchlevel.h"
end_include

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|IAMSUID
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|DOSUID
end_ifndef

begin_define
define|#
directive|define
name|DOSUID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SETUID_SCRIPTS_ARE_SECURE_NOW
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|DOSUID
end_ifdef

begin_undef
undef|#
directive|undef
name|DOSUID
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|char
modifier|*
name|moreswitches
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|incpush
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|char
modifier|*
name|cddir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|minus_c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|patchlevel
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|nrs
init|=
literal|"\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|nrschar
init|=
literal|'\n'
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* final char of rs, or 0777 if none */
end_comment

begin_decl_stmt
specifier|static
name|int
name|nrslen
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|,
name|env
parameter_list|)
specifier|register
name|int
name|argc
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|env
decl_stmt|;
block|{
specifier|register
name|STR
modifier|*
name|str
decl_stmt|;
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
name|char
modifier|*
name|scriptname
decl_stmt|;
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
name|bool
name|dosearch
init|=
name|FALSE
decl_stmt|;
ifdef|#
directive|ifdef
name|DOSUID
name|char
modifier|*
name|validarg
init|=
literal|""
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SETUID_SCRIPTS_ARE_SECURE_NOW
ifdef|#
directive|ifdef
name|IAMSUID
undef|#
directive|undef
name|IAMSUID
name|fatal
argument_list|(
literal|"suidperl is no longer needed since the kernel can now execute\n\ setuid perl scripts securely.\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|origargv
operator|=
name|argv
expr_stmt|;
name|origargc
operator|=
name|argc
expr_stmt|;
name|origenviron
operator|=
name|environ
expr_stmt|;
name|uid
operator|=
operator|(
name|int
operator|)
name|getuid
argument_list|()
expr_stmt|;
name|euid
operator|=
operator|(
name|int
operator|)
name|geteuid
argument_list|()
expr_stmt|;
name|gid
operator|=
operator|(
name|int
operator|)
name|getgid
argument_list|()
expr_stmt|;
name|egid
operator|=
operator|(
name|int
operator|)
name|getegid
argument_list|()
expr_stmt|;
name|sprintf
argument_list|(
name|patchlevel
argument_list|,
literal|"%3.3s%2.2d"
argument_list|,
literal|"4.0"
argument_list|,
name|PATCHLEVEL
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MSDOS
comment|/*      * There is no way we can refer to them from Perl so close them to save      * space.  The other alternative would be to provide STDAUX and STDPRN      * filehandles.      */
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|stdaux
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|stdprn
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|do_undump
condition|)
block|{
name|origfilename
operator|=
name|savestr
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|do_undump
operator|=
literal|0
expr_stmt|;
name|loop_ptr
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* start label stack again */
goto|goto
name|just_doit
goto|;
block|}
ifdef|#
directive|ifdef
name|TAINT
ifndef|#
directive|ifndef
name|DOSUID
if|if
condition|(
name|uid
operator|==
name|euid
operator|&&
name|gid
operator|==
name|egid
condition|)
name|taintanyway
operator|=
name|TRUE
expr_stmt|;
comment|/* running taintperl explicitly */
endif|#
directive|endif
endif|#
directive|endif
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|index
argument_list|(
name|rcsid
argument_list|,
literal|'#'
argument_list|)
argument_list|,
literal|"%d\n"
argument_list|,
name|PATCHLEVEL
argument_list|)
expr_stmt|;
name|linestr
operator|=
name|Str_new
argument_list|(
literal|65
argument_list|,
literal|80
argument_list|)
expr_stmt|;
name|str_nset
argument_list|(
name|linestr
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|str
operator|=
name|str_make
argument_list|(
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* first used for -I flags */
name|curstash
operator|=
name|defstash
operator|=
name|hnew
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|curstname
operator|=
name|str_make
argument_list|(
literal|"main"
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|stab_xhash
argument_list|(
name|stabent
argument_list|(
literal|"_main"
argument_list|,
name|TRUE
argument_list|)
argument_list|)
operator|=
name|defstash
expr_stmt|;
name|defstash
operator|->
name|tbl_name
operator|=
literal|"main"
expr_stmt|;
name|incstab
operator|=
name|hadd
argument_list|(
name|aadd
argument_list|(
name|stabent
argument_list|(
literal|"INC"
argument_list|,
name|TRUE
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|incstab
operator|->
name|str_pok
operator||=
name|SP_MULTI
expr_stmt|;
for|for
control|(
name|argc
operator|--
operator|,
name|argv
operator|++
init|;
name|argc
operator|>
literal|0
condition|;
name|argc
operator|--
operator|,
name|argv
operator|++
control|)
block|{
if|if
condition|(
name|argv
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|!=
literal|'-'
operator|||
operator|!
name|argv
index|[
literal|0
index|]
index|[
literal|1
index|]
condition|)
break|break;
ifdef|#
directive|ifdef
name|DOSUID
if|if
condition|(
operator|*
name|validarg
condition|)
name|validarg
operator|=
literal|" PHOOEY "
expr_stmt|;
else|else
name|validarg
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
endif|#
directive|endif
name|s
operator|=
name|argv
index|[
literal|0
index|]
operator|+
literal|1
expr_stmt|;
name|reswitch
label|:
switch|switch
condition|(
operator|*
name|s
condition|)
block|{
case|case
literal|'0'
case|:
case|case
literal|'a'
case|:
case|case
literal|'c'
case|:
case|case
literal|'d'
case|:
case|case
literal|'D'
case|:
case|case
literal|'i'
case|:
case|case
literal|'l'
case|:
case|case
literal|'n'
case|:
case|case
literal|'p'
case|:
case|case
literal|'u'
case|:
case|case
literal|'U'
case|:
case|case
literal|'v'
case|:
case|case
literal|'w'
case|:
if|if
condition|(
name|s
operator|=
name|moreswitches
argument_list|(
name|s
argument_list|)
condition|)
goto|goto
name|reswitch
goto|;
break|break;
case|case
literal|'e'
case|:
ifdef|#
directive|ifdef
name|TAINT
if|if
condition|(
name|euid
operator|!=
name|uid
operator|||
name|egid
operator|!=
name|gid
condition|)
name|fatal
argument_list|(
literal|"No -e allowed in setuid scripts"
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|e_fp
condition|)
block|{
name|e_tmpname
operator|=
name|savestr
argument_list|(
name|TMPPATH
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|mktemp
argument_list|(
name|e_tmpname
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|*
name|e_tmpname
condition|)
name|fatal
argument_list|(
literal|"Can't mktemp()"
argument_list|)
expr_stmt|;
name|e_fp
operator|=
name|fopen
argument_list|(
name|e_tmpname
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|e_fp
condition|)
name|fatal
argument_list|(
literal|"Cannot open temporary file"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|argv
index|[
literal|1
index|]
condition|)
block|{
name|fputs
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
name|e_fp
argument_list|)
expr_stmt|;
name|argc
operator|--
operator|,
name|argv
operator|++
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|e_fp
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'I'
case|:
ifdef|#
directive|ifdef
name|TAINT
if|if
condition|(
name|euid
operator|!=
name|uid
operator|||
name|egid
operator|!=
name|gid
condition|)
name|fatal
argument_list|(
literal|"No -I allowed in setuid scripts"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|str_cat
argument_list|(
name|str
argument_list|,
literal|"-"
argument_list|)
expr_stmt|;
name|str_cat
argument_list|(
name|str
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|str_cat
argument_list|(
name|str
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
operator|++
name|s
condition|)
block|{
operator|(
name|void
operator|)
name|apush
argument_list|(
name|stab_array
argument_list|(
name|incstab
argument_list|)
argument_list|,
name|str_make
argument_list|(
name|s
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|argv
index|[
literal|1
index|]
condition|)
block|{
operator|(
name|void
operator|)
name|apush
argument_list|(
name|stab_array
argument_list|(
name|incstab
argument_list|)
argument_list|,
name|str_make
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|str_cat
argument_list|(
name|str
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|argc
operator|--
operator|,
name|argv
operator|++
expr_stmt|;
name|str_cat
argument_list|(
name|str
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|'P'
case|:
ifdef|#
directive|ifdef
name|TAINT
if|if
condition|(
name|euid
operator|!=
name|uid
operator|||
name|egid
operator|!=
name|gid
condition|)
name|fatal
argument_list|(
literal|"No -P allowed in setuid scripts"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|preprocess
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
goto|goto
name|reswitch
goto|;
case|case
literal|'s'
case|:
ifdef|#
directive|ifdef
name|TAINT
if|if
condition|(
name|euid
operator|!=
name|uid
operator|||
name|egid
operator|!=
name|gid
condition|)
name|fatal
argument_list|(
literal|"No -s allowed in setuid scripts"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|doswitches
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
goto|goto
name|reswitch
goto|;
case|case
literal|'S'
case|:
ifdef|#
directive|ifdef
name|TAINT
if|if
condition|(
name|euid
operator|!=
name|uid
operator|||
name|egid
operator|!=
name|gid
condition|)
name|fatal
argument_list|(
literal|"No -S allowed in setuid scripts"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|dosearch
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
goto|goto
name|reswitch
goto|;
case|case
literal|'x'
case|:
name|doextract
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|s
condition|)
name|cddir
operator|=
name|savestr
argument_list|(
name|s
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'-'
case|:
name|argc
operator|--
operator|,
name|argv
operator|++
expr_stmt|;
goto|goto
name|switch_end
goto|;
case|case
literal|0
case|:
break|break;
default|default:
name|fatal
argument_list|(
literal|"Unrecognized switch: -%s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
block|}
name|switch_end
label|:
name|scriptname
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
name|e_fp
condition|)
block|{
if|if
condition|(
name|fflush
argument_list|(
name|e_fp
argument_list|)
operator|||
name|ferror
argument_list|(
name|e_fp
argument_list|)
operator|||
name|fclose
argument_list|(
name|e_fp
argument_list|)
condition|)
name|fatal
argument_list|(
literal|"Can't write to temp file for -e: %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
name|argc
operator|++
operator|,
name|argv
operator|--
expr_stmt|;
name|scriptname
operator|=
name|e_tmpname
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|DOSISH
define|#
directive|define
name|PERLLIB_SEP
value|';'
else|#
directive|else
define|#
directive|define
name|PERLLIB_SEP
value|':'
endif|#
directive|endif
ifndef|#
directive|ifndef
name|TAINT
comment|/* Can't allow arbitrary PERLLIB in setuid script */
name|incpush
argument_list|(
name|getenv
argument_list|(
literal|"PERLLIB"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* TAINT */
ifndef|#
directive|ifndef
name|PRIVLIB
define|#
directive|define
name|PRIVLIB
value|"/usr/share/perl"
endif|#
directive|endif
name|incpush
argument_list|(
name|PRIVLIB
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|apush
argument_list|(
name|stab_array
argument_list|(
name|incstab
argument_list|)
argument_list|,
name|str_make
argument_list|(
literal|"."
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|str_set
argument_list|(
operator|&
name|str_no
argument_list|,
name|No
argument_list|)
expr_stmt|;
name|str_set
argument_list|(
operator|&
name|str_yes
argument_list|,
name|Yes
argument_list|)
expr_stmt|;
comment|/* open script */
if|if
condition|(
name|scriptname
operator|==
name|Nullch
condition|)
ifdef|#
directive|ifdef
name|MSDOS
block|{
if|if
condition|(
name|isatty
argument_list|(
name|fileno
argument_list|(
name|stdin
argument_list|)
argument_list|)
condition|)
name|moreswitches
argument_list|(
literal|"v"
argument_list|)
expr_stmt|;
name|scriptname
operator|=
literal|"-"
expr_stmt|;
block|}
else|#
directive|else
name|scriptname
operator|=
literal|"-"
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|dosearch
operator|&&
operator|!
name|index
argument_list|(
name|scriptname
argument_list|,
literal|'/'
argument_list|)
operator|&&
operator|(
name|s
operator|=
name|getenv
argument_list|(
literal|"PATH"
argument_list|)
operator|)
condition|)
block|{
name|char
modifier|*
name|xfound
init|=
name|Nullch
decl_stmt|,
modifier|*
name|xfailed
init|=
name|Nullch
decl_stmt|;
name|int
name|len
decl_stmt|;
name|bufend
operator|=
name|s
operator|+
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|s
condition|)
block|{
ifndef|#
directive|ifndef
name|DOSISH
name|s
operator|=
name|cpytill
argument_list|(
name|tokenbuf
argument_list|,
name|s
argument_list|,
name|bufend
argument_list|,
literal|':'
argument_list|,
operator|&
name|len
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|atarist
for|for
control|(
name|len
operator|=
literal|0
init|;
operator|*
name|s
operator|&&
operator|*
name|s
operator|!=
literal|','
operator|&&
operator|*
name|s
operator|!=
literal|';'
condition|;
name|tokenbuf
index|[
name|len
operator|++
index|]
operator|=
operator|*
name|s
operator|++
control|)
empty_stmt|;
name|tokenbuf
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
else|#
directive|else
for|for
control|(
name|len
operator|=
literal|0
init|;
operator|*
name|s
operator|&&
operator|*
name|s
operator|!=
literal|';'
condition|;
name|tokenbuf
index|[
name|len
operator|++
index|]
operator|=
operator|*
name|s
operator|++
control|)
empty_stmt|;
name|tokenbuf
index|[
name|len
index|]
operator|=
literal|'\0'
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
if|if
condition|(
operator|*
name|s
condition|)
name|s
operator|++
expr_stmt|;
ifndef|#
directive|ifndef
name|DOSISH
if|if
condition|(
name|len
operator|&&
name|tokenbuf
index|[
name|len
operator|-
literal|1
index|]
operator|!=
literal|'/'
condition|)
else|#
directive|else
ifdef|#
directive|ifdef
name|atarist
if|if
condition|(
name|len
operator|&&
operator|(
operator|(
name|tokenbuf
index|[
name|len
operator|-
literal|1
index|]
operator|!=
literal|'\\'
operator|)
operator|&&
operator|(
name|tokenbuf
index|[
name|len
operator|-
literal|1
index|]
operator|!=
literal|'/'
operator|)
operator|)
condition|)
else|#
directive|else
if|if
condition|(
name|len
operator|&&
name|tokenbuf
index|[
name|len
operator|-
literal|1
index|]
operator|!=
literal|'\\'
condition|)
endif|#
directive|endif
endif|#
directive|endif
operator|(
name|void
operator|)
name|strcat
argument_list|(
name|tokenbuf
operator|+
name|len
argument_list|,
literal|"/"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcat
argument_list|(
name|tokenbuf
operator|+
name|len
argument_list|,
name|scriptname
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUGGING
if|if
condition|(
name|debug
operator|&
literal|1
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Looking for %s\n"
argument_list|,
name|tokenbuf
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|stat
argument_list|(
name|tokenbuf
argument_list|,
operator|&
name|statbuf
argument_list|)
operator|<
literal|0
condition|)
comment|/* not there? */
continue|continue;
if|if
condition|(
name|S_ISREG
argument_list|(
name|statbuf
operator|.
name|st_mode
argument_list|)
operator|&&
name|cando
argument_list|(
name|S_IRUSR
argument_list|,
name|TRUE
argument_list|,
operator|&
name|statbuf
argument_list|)
operator|&&
name|cando
argument_list|(
name|S_IXUSR
argument_list|,
name|TRUE
argument_list|,
operator|&
name|statbuf
argument_list|)
condition|)
block|{
name|xfound
operator|=
name|tokenbuf
expr_stmt|;
comment|/* bingo! */
break|break;
block|}
if|if
condition|(
operator|!
name|xfailed
condition|)
name|xfailed
operator|=
name|savestr
argument_list|(
name|tokenbuf
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|xfound
condition|)
name|fatal
argument_list|(
literal|"Can't execute %s"
argument_list|,
name|xfailed
condition|?
name|xfailed
else|:
name|scriptname
argument_list|)
expr_stmt|;
if|if
condition|(
name|xfailed
condition|)
name|Safefree
argument_list|(
name|xfailed
argument_list|)
expr_stmt|;
name|scriptname
operator|=
name|savestr
argument_list|(
name|xfound
argument_list|)
expr_stmt|;
block|}
name|fdpid
operator|=
name|anew
argument_list|(
name|Nullstab
argument_list|)
expr_stmt|;
comment|/* for remembering popen pids by fd */
name|pidstatus
operator|=
name|hnew
argument_list|(
name|COEFFSIZE
argument_list|)
expr_stmt|;
comment|/* for remembering status of dead pids */
name|origfilename
operator|=
name|savestr
argument_list|(
name|scriptname
argument_list|)
expr_stmt|;
name|curcmd
operator|->
name|c_filestab
operator|=
name|fstab
argument_list|(
name|origfilename
argument_list|)
expr_stmt|;
if|if
condition|(
name|strEQ
argument_list|(
name|origfilename
argument_list|,
literal|"-"
argument_list|)
condition|)
name|scriptname
operator|=
literal|""
expr_stmt|;
if|if
condition|(
name|preprocess
condition|)
block|{
name|char
modifier|*
name|cpp
init|=
name|CPPSTDIN
decl_stmt|;
if|if
condition|(
name|strEQ
argument_list|(
name|cpp
argument_list|,
literal|"cppstdin"
argument_list|)
condition|)
name|sprintf
argument_list|(
name|tokenbuf
argument_list|,
literal|"%s/%s"
argument_list|,
name|SCRIPTDIR
argument_list|,
name|cpp
argument_list|)
expr_stmt|;
else|else
name|sprintf
argument_list|(
name|tokenbuf
argument_list|,
literal|"%s"
argument_list|,
name|cpp
argument_list|)
expr_stmt|;
name|str_cat
argument_list|(
name|str
argument_list|,
literal|"-I"
argument_list|)
expr_stmt|;
name|str_cat
argument_list|(
name|str
argument_list|,
name|PRIVLIB
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MSDOS
operator|(
name|void
operator|)
name|sprintf
argument_list|(
argument|buf
argument_list|,
literal|"\ sed %s -e \"/^[^#]/b\" \  -e \"/^#[ 	]*include[ 	]/b\" \  -e \"/^#[ 	]*define[ 	]/b\" \  -e \"/^#[ 	]*if[ 	]/b\" \  -e \"/^#[ 	]*ifdef[ 	]/b\" \  -e \"/^#[ 	]*ifndef[ 	]/b\" \  -e \"/^#[ 	]*else/b\" \  -e \"/^#[ 	]*elif[ 	]/b\" \  -e \"/^#[ 	]*undef[ 	]/b\" \  -e \"/^#[ 	]*endif/b\" \  -e \"s/^#.*//\" \  %s | %s -C %s %s"
argument_list|,
argument|(doextract ?
literal|"-e \"1,/^#/d\n\""
argument|:
literal|""
argument|)
argument_list|,
else|#
directive|else
argument|(void)sprintf(buf,
literal|"\ %s %s -e '/^[^#]/b' \  -e '/^#[ 	]*include[ 	]/b' \  -e '/^#[ 	]*define[ 	]/b' \  -e '/^#[ 	]*if[ 	]/b' \  -e '/^#[ 	]*ifdef[ 	]/b' \  -e '/^#[ 	]*ifndef[ 	]/b' \  -e '/^#[ 	]*else/b' \  -e '/^#[ 	]*elif[ 	]/b' \  -e '/^#[ 	]*undef[ 	]/b' \  -e '/^#[ 	]*endif/b' \  -e 's/^[ 	]*#.*//' \  %s | %s -C %s %s"
argument|,
ifdef|#
directive|ifdef
name|LOC_SED
argument|LOC_SED,
else|#
directive|else
literal|"sed"
argument|,
endif|#
directive|endif
argument|(doextract ?
literal|"-e '1,/^#/d\n'"
argument|:
literal|""
argument|),
endif|#
directive|endif
argument|scriptname, tokenbuf, str_get(str), CPPMINUS);
ifdef|#
directive|ifdef
name|DEBUGGING
argument|if (debug&
literal|64
argument|) { 	    fputs(buf,stderr); 	    fputs(
literal|"\n"
argument|,stderr); 	}
endif|#
directive|endif
argument|doextract = FALSE;
ifdef|#
directive|ifdef
name|IAMSUID
comment|/* actually, this is caught earlier */
argument|if (euid != uid&& !euid) {
comment|/* if running suidperl */
ifdef|#
directive|ifdef
name|HAS_SETEUID
argument|(void)seteuid(uid);
comment|/* musn't stay setuid root */
else|#
directive|else
ifdef|#
directive|ifdef
name|HAS_SETREUID
argument|(void)setreuid(-
literal|1
argument|, uid);
else|#
directive|else
argument|setuid(uid);
endif|#
directive|endif
endif|#
directive|endif
argument|if (geteuid() != uid) 		fatal(
literal|"Can't do seteuid!\n"
argument|); 	}
endif|#
directive|endif
comment|/* IAMSUID */
argument|rsfp = mypopen(buf,
literal|"r"
argument|);     }     else if (!*scriptname) {
ifdef|#
directive|ifdef
name|TAINT
argument|if (euid != uid || egid != gid) 	    fatal(
literal|"Can't take set-id script from stdin"
argument|);
endif|#
directive|endif
argument|rsfp = stdin;     }     else 	rsfp = fopen(scriptname,
literal|"r"
argument|);     if ((FILE*)rsfp == Nullfp) {
ifdef|#
directive|ifdef
name|DOSUID
ifndef|#
directive|ifndef
name|IAMSUID
comment|/* in case script is not readable before setuid */
argument|if (euid&& stat(stab_val(curcmd->c_filestab)->str_ptr,&statbuf)>=
literal|0
argument|&& 	  statbuf.st_mode& (S_ISUID|S_ISGID)) { 	    (void)sprintf(buf,
literal|"%s/sperl%s"
argument|, BIN, patchlevel); 	    execv(buf, origargv);
comment|/* try again */
argument|fatal(
literal|"Can't do setuid\n"
argument|); 	}
endif|#
directive|endif
endif|#
directive|endif
argument|fatal(
literal|"Can't open perl script \"%s\": %s\n"
argument|, 	  stab_val(curcmd->c_filestab)->str_ptr, strerror(errno));     }     str_free(str);
comment|/* free -I directories */
argument|str = Nullstr;
comment|/* do we need to emulate setuid on scripts? */
comment|/* This code is for those BSD systems that have setuid #! scripts disabled      * in the kernel because of a security problem.  Merely defining DOSUID      * in perl will not fix that problem, but if you have disabled setuid      * scripts in the kernel, this will attempt to emulate setuid and setgid      * on scripts that have those now-otherwise-useless bits set.  The setuid      * root version must be called suidperl or sperlN.NNN.  If regular perl      * discovers that it has opened a setuid script, it calls suidperl with      * the same argv that it had.  If suidperl finds that the script it has      * just opened is NOT setuid root, it sets the effective uid back to the      * uid.  We don't just make perl setuid root because that loses the      * effective uid we had before invoking perl, if it was different from the      * uid.      *      * DOSUID must be defined in both perl and suidperl, and IAMSUID must      * be defined in suidperl only.  suidperl must be setuid root.  The      * Configure script will set this up for you if you want it.      *      * There is also the possibility of have a script which is running      * set-id due to a C wrapper.  We want to do the TAINT checks      * on these set-id scripts, but don't want to have the overhead of      * them in normal perl, and can't use suidperl because it will lose      * the effective uid info, so we have an additional non-setuid root      * version called taintperl or tperlN.NNN that just does the TAINT checks.      */
ifdef|#
directive|ifdef
name|DOSUID
argument|if (fstat(fileno(rsfp),&statbuf)<
literal|0
argument|)
comment|/* normal stat is insecure */
argument|fatal(
literal|"Can't stat script \"%s\""
argument|,origfilename);
ifdef|#
directive|ifdef
name|IAMSUID
argument|{ 	struct statfs stfs;  	if (fstatfs(fileno(rsfp),&stfs)<
literal|0
argument|) 	    fatal(
literal|"Can't statfs filesystem of script \"%s\""
argument|,origfilename);  	if (stfs.f_flags& MNT_NOSUID) 	    fatal(
literal|"Permission denied"
argument|);     }
endif|#
directive|endif
comment|/* IAMSUID */
argument|if (statbuf.st_mode& (S_ISUID|S_ISGID)) { 	int len;
ifdef|#
directive|ifdef
name|IAMSUID
ifndef|#
directive|ifndef
name|HAS_SETREUID
comment|/* On this access check to make sure the directories are readable, 	 * there is actually a small window that the user could use to make 	 * filename point to an accessible directory.  So there is a faint 	 * chance that someone could execute a setuid script down in a 	 * non-accessible directory.  I don't know what to do about that. 	 * But I don't think it's too important.  The manual lies when 	 * it says access() is useful in setuid programs. 	 */
argument|if (access(stab_val(curcmd->c_filestab)->str_ptr,
literal|1
argument|))
comment|/*double check*/
argument|fatal(
literal|"Permission denied"
argument|);
else|#
directive|else
comment|/* If we can swap euid and uid, then we can determine access rights 	 * with a simple stat of the file, and then compare device and 	 * inode to make sure we did stat() on the same file we opened. 	 * Then we just have to make sure he or she can execute it. 	 */
argument|{ 	    struct stat tmpstatbuf;  	    if (setreuid(euid,uid)<
literal|0
argument||| getuid() != euid || geteuid() != uid) 		fatal(
literal|"Can't swap uid and euid"
argument|);
comment|/* really paranoid */
argument|if (stat(stab_val(curcmd->c_filestab)->str_ptr,&tmpstatbuf)<
literal|0
argument|) 		fatal(
literal|"Permission denied"
argument|);
comment|/* testing full pathname here */
argument|if (tmpstatbuf.st_dev != statbuf.st_dev || 		tmpstatbuf.st_ino != statbuf.st_ino) { 		(void)fclose(rsfp); 		if (rsfp = mypopen(
literal|"/bin/mail root"
argument|,
literal|"w"
argument|)) {
comment|/* heh, heh */
argument|fprintf(rsfp,
literal|"User %d tried to run dev %d ino %d in place of dev %d ino %d!\n\ (Filename of set-id script was %s, uid %d gid %d.)\n\nSincerely,\nperl\n"
argument|, 			uid,tmpstatbuf.st_dev, tmpstatbuf.st_ino, 			statbuf.st_dev, statbuf.st_ino, 			stab_val(curcmd->c_filestab)->str_ptr, 			statbuf.st_uid, statbuf.st_gid); 		    (void)mypclose(rsfp); 		} 		fatal(
literal|"Permission denied\n"
argument|); 	    } 	    if (setreuid(uid,euid)<
literal|0
argument||| getuid() != uid || geteuid() != euid) 		fatal(
literal|"Can't reswap uid and euid"
argument|); 	    if (!cando(S_IXUSR,FALSE,&statbuf))
comment|/* can real uid exec? */
argument|fatal(
literal|"Permission denied\n"
argument|); 	}
endif|#
directive|endif
comment|/* HAS_SETREUID */
endif|#
directive|endif
comment|/* IAMSUID */
argument|if (!S_ISREG(statbuf.st_mode)) 	    fatal(
literal|"Permission denied"
argument|); 	if (statbuf.st_mode& S_IWOTH) 	    fatal(
literal|"Setuid/gid script is writable by world"
argument|); 	doswitches = FALSE;
comment|/* -s is insecure in suid */
argument|curcmd->c_line++; 	if (fgets(tokenbuf,sizeof tokenbuf, rsfp) == Nullch || 	  strnNE(tokenbuf,
literal|"#!"
argument|,
literal|2
argument|) )
comment|/* required even on Sys V */
argument|fatal(
literal|"No #! line"
argument|); 	s = tokenbuf+
literal|2
argument|; 	if (*s ==
literal|' '
argument|) s++; 	while (!isSPACE(*s)) s++; 	if (strnNE(s-
literal|4
argument|,
literal|"perl"
argument|,
literal|4
argument|)&& strnNE(s-
literal|9
argument|,
literal|"perl"
argument|,
literal|4
argument|))
comment|/* sanity check */
argument|fatal(
literal|"Not a perl script"
argument|); 	while (*s ==
literal|' '
argument||| *s ==
literal|'\t'
argument|) s++;
comment|/* 	 * #! arg must be what we saw above.  They can invoke it by 	 * mentioning suidperl explicitly, but they may not add any strange 	 * arguments beyond what #! says if they do invoke suidperl that way. 	 */
argument|len = strlen(validarg); 	if (strEQ(validarg,
literal|" PHOOEY "
argument|) || 	    strnNE(s,validarg,len) || !isSPACE(s[len])) 	    fatal(
literal|"Args must match #! line"
argument|);
ifndef|#
directive|ifndef
name|IAMSUID
argument|if (euid != uid&& (statbuf.st_mode& S_ISUID)&& 	    euid == statbuf.st_uid) 	    if (!do_undump) 		fatal(
literal|"YOU HAVEN'T DISABLED SET-ID SCRIPTS IN THE KERNEL YET!\n\ FIX YOUR KERNEL, PUT A C WRAPPER AROUND THIS SCRIPT, OR USE -u AND UNDUMP!\n"
argument|);
endif|#
directive|endif
comment|/* IAMSUID */
argument|if (euid) {
comment|/* oops, we're not the setuid root perl */
argument|(void)fclose(rsfp);
ifndef|#
directive|ifndef
name|IAMSUID
argument|(void)sprintf(buf,
literal|"%s/sperl%s"
argument|, BIN, patchlevel); 	    execv(buf, origargv);
comment|/* try again */
endif|#
directive|endif
argument|fatal(
literal|"Can't do setuid\n"
argument|); 	}  	if (statbuf.st_mode& S_ISGID&& statbuf.st_gid != egid) {
ifdef|#
directive|ifdef
name|HAS_SETEGID
argument|(void)setegid(statbuf.st_gid);
else|#
directive|else
ifdef|#
directive|ifdef
name|HAS_SETREGID
argument|(void)setregid((GIDTYPE)gid,statbuf.st_gid);
else|#
directive|else
argument|setgid(statbuf.st_gid);
endif|#
directive|endif
endif|#
directive|endif
argument|if (getegid() != statbuf.st_gid) 		fatal(
literal|"Can't do setegid!\n"
argument|); 	} 	if (statbuf.st_mode& S_ISUID) { 	    if (statbuf.st_uid != euid)
ifdef|#
directive|ifdef
name|HAS_SETEUID
argument|(void)seteuid(statbuf.st_uid);
comment|/* all that for this */
else|#
directive|else
ifdef|#
directive|ifdef
name|HAS_SETREUID
argument|(void)setreuid((UIDTYPE)uid,statbuf.st_uid);
else|#
directive|else
argument|setuid(statbuf.st_uid);
endif|#
directive|endif
endif|#
directive|endif
argument|if (geteuid() != statbuf.st_uid) 		fatal(
literal|"Can't do seteuid!\n"
argument|); 	} 	else if (uid) {
comment|/* oops, mustn't run as root */
ifdef|#
directive|ifdef
name|HAS_SETEUID
argument|(void)seteuid((UIDTYPE)uid);
else|#
directive|else
ifdef|#
directive|ifdef
name|HAS_SETREUID
argument|(void)setreuid((UIDTYPE)uid,(UIDTYPE)uid);
else|#
directive|else
argument|setuid((UIDTYPE)uid);
endif|#
directive|endif
endif|#
directive|endif
argument|if (geteuid() != uid) 		fatal(
literal|"Can't do seteuid!\n"
argument|); 	} 	uid = (int)getuid(); 	euid = (int)geteuid(); 	gid = (int)getgid(); 	egid = (int)getegid(); 	if (!cando(S_IXUSR,TRUE,&statbuf)) 	    fatal(
literal|"Permission denied\n"
argument|);
comment|/* they can't do this */
argument|}
ifdef|#
directive|ifdef
name|IAMSUID
argument|else if (preprocess) 	fatal(
literal|"-P not allowed for setuid/setgid script\n"
argument|);     else 	fatal(
literal|"Script is not setuid/setgid in suidperl\n"
argument|);
else|#
directive|else
ifndef|#
directive|ifndef
name|TAINT
comment|/* we aren't taintperl or suidperl */
comment|/* script has a wrapper--can't run suidperl or we lose euid */
argument|else if (euid != uid || egid != gid) { 	(void)fclose(rsfp); 	(void)sprintf(buf,
literal|"%s/tperl%s"
argument|, BIN, patchlevel); 	execv(buf, origargv);
comment|/* try again */
argument|fatal(
literal|"Can't run setuid script with taint checks"
argument|);     }
endif|#
directive|endif
comment|/* TAINT */
endif|#
directive|endif
comment|/* IAMSUID */
else|#
directive|else
comment|/* !DOSUID */
ifndef|#
directive|ifndef
name|TAINT
comment|/* we aren't taintperl or suidperl */
argument|if (euid != uid || egid != gid) {
comment|/* (suidperl doesn't exist, in fact) */
ifndef|#
directive|ifndef
name|SETUID_SCRIPTS_ARE_SECURE_NOW
argument|fstat(fileno(rsfp),&statbuf);
comment|/* may be either wrapped or real suid */
argument|if ((euid != uid&& euid == statbuf.st_uid&& statbuf.st_mode& S_ISUID) 	    || 	    (egid != gid&& egid == statbuf.st_gid&& statbuf.st_mode& S_ISGID) 	   ) 	    if (!do_undump) 		fatal(
literal|"YOU HAVEN'T DISABLED SET-ID SCRIPTS IN THE KERNEL YET!\n\ FIX YOUR KERNEL, PUT A C WRAPPER AROUND THIS SCRIPT, OR USE -u AND UNDUMP!\n"
argument|);
endif|#
directive|endif
comment|/* SETUID_SCRIPTS_ARE_SECURE_NOW */
comment|/* not set-id, must be wrapped */
argument|(void)fclose(rsfp); 	(void)sprintf(buf,
literal|"%s/tperl%s"
argument|, BIN, patchlevel); 	execv(buf, origargv);
comment|/* try again */
argument|fatal(
literal|"Can't run setuid script with taint checks"
argument|);     }
endif|#
directive|endif
comment|/* TAINT */
endif|#
directive|endif
comment|/* DOSUID */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IAMSUID
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|TAINT
argument_list|)
comment|/* skip forward in input to the real script? */
argument|while (doextract) { 	if ((s = str_gets(linestr, rsfp,
literal|0
argument|)) == Nullch) 	    fatal(
literal|"No Perl script found in input\n"
argument|); 	if (*s ==
literal|'#'
argument|&& s[
literal|1
argument|] ==
literal|'!'
argument|&& instr(s,
literal|"perl"
argument|)) { 	    ungetc(
literal|'\n'
argument|,rsfp);
comment|/* to keep line count right */
argument|doextract = FALSE; 	    if (s = instr(s,
literal|"perl -"
argument|)) { 		s +=
literal|6
argument|;
comment|/*SUPPRESS 530*/
argument|while (s = moreswitches(s)) ; 	    } 	    if (cddir&& chdir(cddir)<
literal|0
argument|) 		fatal(
literal|"Can't chdir to %s"
argument|,cddir); 	}     }
endif|#
directive|endif
comment|/* !defined(IAMSUID)&& !defined(TAINT) */
argument|defstab = stabent(
literal|"_"
argument|,TRUE);      subname = str_make(
literal|"main"
argument|,
literal|4
argument|);     if (perldb) { 	debstash = hnew(
literal|0
argument|); 	stab_xhash(stabent(
literal|"_DB"
argument|,TRUE)) = debstash; 	curstash = debstash; 	dbargs = stab_xarray(aadd((tmpstab = stabent(
literal|"args"
argument|,TRUE)))); 	tmpstab->str_pok |= SP_MULTI; 	dbargs->ary_flags =
literal|0
argument|; 	DBstab = stabent(
literal|"DB"
argument|,TRUE); 	DBstab->str_pok |= SP_MULTI; 	DBline = stabent(
literal|"dbline"
argument|,TRUE); 	DBline->str_pok |= SP_MULTI; 	DBsub = hadd(tmpstab = stabent(
literal|"sub"
argument|,TRUE)); 	tmpstab->str_pok |= SP_MULTI; 	DBsingle = stab_val((tmpstab = stabent(
literal|"single"
argument|,TRUE))); 	tmpstab->str_pok |= SP_MULTI; 	DBtrace = stab_val((tmpstab = stabent(
literal|"trace"
argument|,TRUE))); 	tmpstab->str_pok |= SP_MULTI; 	DBsignal = stab_val((tmpstab = stabent(
literal|"signal"
argument|,TRUE))); 	tmpstab->str_pok |= SP_MULTI; 	curstash = defstash;     }
comment|/* init tokener */
argument|bufend = bufptr = str_get(linestr);      savestack = anew(Nullstab);
comment|/* for saving non-local values */
argument|stack = anew(Nullstab);
comment|/* for saving non-local values */
argument|stack->ary_flags =
literal|0
argument|;
comment|/* not a real array */
argument|afill(stack,
literal|63
argument|); afill(stack,-
literal|1
argument|);
comment|/* preextend stack */
argument|afill(savestack,
literal|63
argument|); afill(savestack,-
literal|1
argument|);
comment|/* now parse the script */
argument|error_count =
literal|0
argument|;     if (yyparse() || error_count) { 	if (minus_c) 	    fatal(
literal|"%s had compilation errors.\n"
argument|, origfilename); 	else { 	    fatal(
literal|"Execution of %s aborted due to compilation errors.\n"
argument|, 		origfilename); 	}     }      New(
literal|50
argument|,loop_stack,
literal|128
argument|,struct loop);
ifdef|#
directive|ifdef
name|DEBUGGING
argument|if (debug) { 	New(
literal|51
argument|,debname,
literal|128
argument|,char); 	New(
literal|52
argument|,debdelim,
literal|128
argument|,char);     }
endif|#
directive|endif
argument|curstash = defstash;      preprocess = FALSE;     if (e_fp) { 	e_fp = Nullfp; 	(void)UNLINK(e_tmpname);     }
comment|/* initialize everything that won't change if we undump */
argument|if (sigstab = stabent(
literal|"SIG"
argument|,allstabs)) { 	sigstab->str_pok |= SP_MULTI; 	(void)hadd(sigstab);     }      magicalize(
literal|"!#?^~=-%.+&*()<>,\\/[|`':\004\t\020\024\027\006"
argument|);     userinit();
comment|/* in case linked C routines want magical variables */
argument|amperstab = stabent(
literal|"&"
argument|,allstabs);     leftstab = stabent(
literal|"`"
argument|,allstabs);     rightstab = stabent(
literal|"'"
argument|,allstabs);     sawampersand = (amperstab || leftstab || rightstab);     if (tmpstab = stabent(
literal|":"
argument|,allstabs)) 	str_set(stab_val(tmpstab),chopset);     if (tmpstab = stabent(
literal|"\024"
argument|,allstabs)) 	time(&basetime);
comment|/* these aren't necessarily magical */
argument|if (tmpstab = stabent(
literal|"\014"
argument|,allstabs)) { 	str_set(stab_val(tmpstab),
literal|"\f"
argument|); 	formfeed = stab_val(tmpstab);     }     if (tmpstab = stabent(
literal|";"
argument|,allstabs)) 	str_set(STAB_STR(tmpstab),
literal|"\034"
argument|);     if (tmpstab = stabent(
literal|"]"
argument|,allstabs)) { 	str = STAB_STR(tmpstab); 	str_set(str,rcsid); 	str->str_u.str_nval = atof(patchlevel); 	str->str_nok =
literal|1
argument|;     }     str_nset(stab_val(stabent(
literal|"\""
argument|, TRUE)),
literal|" "
argument|,
literal|1
argument|);      stdinstab = stabent(
literal|"STDIN"
argument|,TRUE);     stdinstab->str_pok |= SP_MULTI;     if (!stab_io(stdinstab)) 	stab_io(stdinstab) = stio_new();     stab_io(stdinstab)->ifp = stdin;     tmpstab = stabent(
literal|"stdin"
argument|,TRUE);     stab_io(tmpstab) = stab_io(stdinstab);     tmpstab->str_pok |= SP_MULTI;      tmpstab = stabent(
literal|"STDOUT"
argument|,TRUE);     tmpstab->str_pok |= SP_MULTI;     if (!stab_io(tmpstab)) 	stab_io(tmpstab) = stio_new();     stab_io(tmpstab)->ofp = stab_io(tmpstab)->ifp = stdout;     defoutstab = tmpstab;     tmpstab = stabent(
literal|"stdout"
argument|,TRUE);     stab_io(tmpstab) = stab_io(defoutstab);     tmpstab->str_pok |= SP_MULTI;      curoutstab = stabent(
literal|"STDERR"
argument|,TRUE);     curoutstab->str_pok |= SP_MULTI;     if (!stab_io(curoutstab)) 	stab_io(curoutstab) = stio_new();     stab_io(curoutstab)->ofp = stab_io(curoutstab)->ifp = stderr;     tmpstab = stabent(
literal|"stderr"
argument|,TRUE);     stab_io(tmpstab) = stab_io(curoutstab);     tmpstab->str_pok |= SP_MULTI;     curoutstab = defoutstab;
comment|/* switch back to STDOUT */
argument|statname = Str_new(
literal|66
argument|,
literal|0
argument|);
comment|/* last filename we did stat on */
comment|/* now that script is parsed, we can modify record separator */
argument|rs = nrs;     rslen = nrslen;     rschar = nrschar;     rspara = (nrslen ==
literal|2
argument|);     str_nset(stab_val(stabent(
literal|"/"
argument|, TRUE)), rs, rslen);      if (do_undump) 	my_unexec();    just_doit:
comment|/* come here if running an undumped a.out */
argument|argc--
argument_list|,
argument|argv++;
comment|/* skip name of script */
argument|if (doswitches) { 	for (; argc>
literal|0
argument|&& **argv ==
literal|'-'
argument|; argc--,argv++) { 	    if (argv[
literal|0
argument|][
literal|1
argument|] ==
literal|'-'
argument|) { 		argc--
argument_list|,
argument|argv++; 		break; 	    } 	    if (s = index(argv[
literal|0
argument|],
literal|'='
argument|)) { 		*s++ =
literal|'\0'
argument|; 		str_set(stab_val(stabent(argv[
literal|0
argument|]+
literal|1
argument|,TRUE)),s); 	    } 	    else 		str_numset(stab_val(stabent(argv[
literal|0
argument|]+
literal|1
argument|,TRUE)),(double)
literal|1.0
argument|); 	}     }
ifdef|#
directive|ifdef
name|TAINT
argument|tainted =
literal|1
argument|;
endif|#
directive|endif
argument|if (tmpstab = stabent(
literal|"0"
argument|,allstabs)) { 	str_set(stab_val(tmpstab),origfilename); 	magicname(
literal|"0"
argument|, Nullch,
literal|0
argument|);     }     if (tmpstab = stabent(
literal|"\030"
argument|,allstabs)) 	str_set(stab_val(tmpstab),origargv[
literal|0
argument|]);     if (argvstab = stabent(
literal|"ARGV"
argument|,allstabs)) { 	argvstab->str_pok |= SP_MULTI; 	(void)aadd(argvstab); 	aclear(stab_array(argvstab)); 	for (; argc>
literal|0
argument|; argc--,argv++) { 	    (void)apush(stab_array(argvstab),str_make(argv[
literal|0
argument|],
literal|0
argument|)); 	}     }
ifdef|#
directive|ifdef
name|TAINT
argument|(void) stabent(
literal|"ENV"
argument|,TRUE);
comment|/* must test PATH and IFS */
endif|#
directive|endif
argument|if (envstab = stabent(
literal|"ENV"
argument|,allstabs)) { 	envstab->str_pok |= SP_MULTI; 	(void)hadd(envstab); 	hclear(stab_hash(envstab), FALSE); 	if (env != environ) 	    environ[
literal|0
argument|] = Nullch; 	for (; *env; env++) { 	    if (!(s = index(*env,
literal|'='
argument|))) 		continue; 	    *s++ =
literal|'\0'
argument|; 	    str = str_make(s--,
literal|0
argument|); 	    str_magic(str, envstab,
literal|'E'
argument|, *env, s - *env); 	    (void)hstore(stab_hash(envstab), *env, s - *env, str,
literal|0
argument|); 	    *s =
literal|'='
argument|; 	}     }
ifdef|#
directive|ifdef
name|TAINT
argument|tainted =
literal|0
argument|;
endif|#
directive|endif
argument|if (tmpstab = stabent(
literal|"$"
argument|,allstabs)) 	str_numset(STAB_STR(tmpstab),(double)getpid());      if (dowarn) { 	stab_check(
literal|'A'
argument|,
literal|'Z'
argument|); 	stab_check(
literal|'a'
argument|,
literal|'z'
argument|);     }      if (setjmp(top_env))
comment|/* sets goto_targ on longjump */
argument|loop_ptr = -
literal|1
argument|;
comment|/* start label stack again */
ifdef|#
directive|ifdef
name|DEBUGGING
argument|if (debug&
literal|1024
argument|) 	dump_all();     if (debug) 	fprintf(stderr,
literal|"\nEXECUTING...\n\n"
argument|);
endif|#
directive|endif
argument|if (minus_c) { 	fprintf(stderr,
literal|"%s syntax OK\n"
argument|, origfilename); 	exit(
literal|0
argument|);     }
comment|/* do it */
argument|(void) cmd_exec(main_root,G_SCALAR,-
literal|1
argument|);      if (goto_targ) 	fatal(
literal|"Can't find label \"%s\"--aborting"
argument|,goto_targ);     exit(
literal|0
argument|);
comment|/* NOTREACHED */
argument|}  void magicalize(list) register char *list; {     char sym[
literal|2
argument|];      sym[
literal|1
argument|] =
literal|'\0'
argument|;     while (*sym = *list++) 	magicname(sym, Nullch,
literal|0
argument|); }  void magicname(sym,name,namlen) char *sym; char *name; int namlen; {     register STAB *stab;      if (stab = stabent(sym,allstabs)) { 	stab_flags(stab) = SF_VMAGIC; 	str_magic(stab_val(stab), stab,
literal|0
argument|, name, namlen);     } }  static void incpush(p) char *p; {     char *s;      if (!p) 	return;
comment|/* Break at all separators */
argument|while (*p) {
comment|/* First, skip any consecutive separators */
argument|while ( *p == PERLLIB_SEP ) {
comment|/* Uncomment the next line for PATH semantics */
comment|/* (void)apush(stab_array(incstab), str_make(".", 1)); */
argument|p++; 	} 	if ( (s = index(p, PERLLIB_SEP)) != Nullch ) { 	    (void)apush(stab_array(incstab), str_make(p, (int)(s - p))); 	    p = s +
literal|1
argument|; 	} else { 	    (void)apush(stab_array(incstab), str_make(p,
literal|0
argument|)); 	    break; 	}     } }  void savelines(array, str) ARRAY *array; STR *str; {     register char *s = str->str_ptr;     register char *send = str->str_ptr + str->str_cur;     register char *t;     register int line =
literal|1
argument|;      while (s&& s< send) { 	STR *tmpstr = Str_new(
literal|85
argument|,
literal|0
argument|);  	t = index(s,
literal|'\n'
argument|); 	if (t) 	    t++; 	else 	    t = send;  	str_nset(tmpstr, s, t - s); 	astore(array, line++, tmpstr); 	s = t;     } }
comment|/* this routine is in perl.c by virtue of being sort of an alternate main() */
argument|int do_eval(str,optype,stash,savecmd,gimme,arglast) STR *str; int optype; HASH *stash; int savecmd; int gimme; int *arglast; {     STR **st = stack->ary_array;     int retval;     CMD *myroot = Nullcmd;     ARRAY *ar;     int i;     CMD * VOLATILE oldcurcmd = curcmd;     VOLATILE int oldtmps_base = tmps_base;     VOLATILE int oldsave = savestack->ary_fill;     VOLATILE int oldperldb = perldb;     SPAT * VOLATILE oldspat = curspat;     SPAT * VOLATILE oldlspat = lastspat;     static char *last_eval = Nullch;     static long last_elen =
literal|0
argument|;     static CMD *last_root = Nullcmd;     VOLATILE int sp = arglast[
literal|0
argument|];     char *specfilename;     char *tmpfilename;     int parsing =
literal|1
argument|;      tmps_base = tmps_max;     if (curstash != stash) { 	(void)savehptr(&curstash); 	curstash = stash;     }     str_set(stab_val(stabent(
literal|"@"
argument|,TRUE)),
literal|""
argument|);     if (curcmd->c_line ==
literal|0
argument|)
comment|/* don't debug debugger... */
argument|perldb = FALSE;     curcmd =&compiling;     if (optype == O_EVAL) {
comment|/* normal eval */
argument|curcmd->c_filestab = fstab(
literal|"(eval)"
argument|); 	curcmd->c_line =
literal|1
argument|; 	str_sset(linestr,str); 	str_cat(linestr,
literal|";\n;\n"
argument|);
comment|/* be kind to them */
argument|if (perldb) 	    savelines(stab_xarray(curcmd->c_filestab), linestr);     }     else { 	if (last_root&& !in_eval) { 	    Safefree(last_eval); 	    last_eval = Nullch; 	    cmd_free(last_root); 	    last_root = Nullcmd; 	} 	specfilename = str_get(str); 	str_set(linestr,
literal|""
argument|); 	if (optype == O_REQUIRE&&&str_undef != 	  hfetch(stab_hash(incstab), specfilename, strlen(specfilename),
literal|0
argument|)) { 	    curcmd = oldcurcmd; 	    tmps_base = oldtmps_base; 	    st[++sp] =&str_yes; 	    perldb = oldperldb; 	    return sp; 	} 	tmpfilename = savestr(specfilename); 	if (*tmpfilename ==
literal|'/'
argument||| 	    (*tmpfilename ==
literal|'.'
argument|&& 		(tmpfilename[
literal|1
argument|] ==
literal|'/'
argument||| 		 (tmpfilename[
literal|1
argument|] ==
literal|'.'
argument|&& tmpfilename[
literal|2
argument|] ==
literal|'/'
argument|)))) 	{ 	    rsfp = fopen(tmpfilename,
literal|"r"
argument|); 	} 	else { 	    ar = stab_array(incstab); 	    for (i =
literal|0
argument|; i<= ar->ary_fill; i++) { 		(void)sprintf(buf,
literal|"%s/%s"
argument|, 		  str_get(afetch(ar,i,TRUE)), specfilename); 		rsfp = fopen(buf,
literal|"r"
argument|); 		if (rsfp) { 		    char *s = buf;  		    if (*s ==
literal|'.'
argument|&& s[
literal|1
argument|] ==
literal|'/'
argument|) 			s +=
literal|2
argument|; 		    Safefree(tmpfilename); 		    tmpfilename = savestr(s); 		    break; 		} 	    } 	} 	curcmd->c_filestab = fstab(tmpfilename); 	Safefree(tmpfilename); 	tmpfilename = Nullch; 	if (!rsfp) { 	    curcmd = oldcurcmd; 	    tmps_base = oldtmps_base; 	    if (optype == O_REQUIRE) { 		sprintf(tokenbuf,
literal|"Can't locate %s in @INC"
argument|, specfilename); 		if (instr(tokenbuf,
literal|".h "
argument|)) 		    strcat(tokenbuf,
literal|" (change .h to .ph maybe?)"
argument|); 		if (instr(tokenbuf,
literal|".ph "
argument|)) 		    strcat(tokenbuf,
literal|" (did you run h2ph?)"
argument|); 		fatal(
literal|"%s"
argument|,tokenbuf); 	    } 	    if (gimme != G_ARRAY) 		st[++sp] =&str_undef; 	    perldb = oldperldb; 	    return sp; 	} 	curcmd->c_line =
literal|0
argument|;     }     in_eval++;     oldoldbufptr = oldbufptr = bufptr = str_get(linestr);     bufend = bufptr + linestr->str_cur;     if (++loop_ptr>= loop_max) { 	loop_max +=
literal|128
argument|; 	Renew(loop_stack, loop_max, struct loop);     }     loop_stack[loop_ptr].loop_label =
literal|"_EVAL_"
argument|;     loop_stack[loop_ptr].loop_sp = sp;
ifdef|#
directive|ifdef
name|DEBUGGING
argument|if (debug&
literal|4
argument|) { 	deb(
literal|"(Pushing label #%d _EVAL_)\n"
argument|, loop_ptr);     }
endif|#
directive|endif
argument|eval_root = Nullcmd;     if (setjmp(loop_stack[loop_ptr].loop_env)) { 	retval =
literal|1
argument|;     }     else { 	error_count =
literal|0
argument|; 	if (rsfp) { 	    retval = yyparse(); 	    retval |= error_count; 	} 	else if (last_root&& last_elen == bufend - bufptr&& *bufptr == *last_eval&& !bcmp(bufptr,last_eval,last_elen)){ 	    retval =
literal|0
argument|; 	    eval_root = last_root;
comment|/* no point in reparsing */
argument|} 	else if (in_eval ==
literal|1
argument|&& !savecmd) { 	    if (last_root) { 		Safefree(last_eval); 		last_eval = Nullch; 		cmd_free(last_root); 	    } 	    last_root = Nullcmd; 	    last_elen = bufend - bufptr; 	    last_eval = nsavestr(bufptr, last_elen); 	    retval = yyparse(); 	    retval |= error_count; 	    if (!retval) 		last_root = eval_root; 	    if (!last_root) { 		Safefree(last_eval); 		last_eval = Nullch; 	    } 	} 	else 	    retval = yyparse();     }     myroot = eval_root;
comment|/* in case cmd_exec does another eval! */
argument|if (retval || error_count) { 	st = stack->ary_array; 	sp = arglast[
literal|0
argument|]; 	if (gimme != G_ARRAY) 	    st[++sp] =&str_undef; 	if (parsing) {
ifndef|#
directive|ifndef
name|MANGLEDPARSE
ifdef|#
directive|ifdef
name|DEBUGGING
argument|if (debug&
literal|128
argument|) 		fprintf(stderr,
literal|"Freeing eval_root %lx\n"
argument|,(long)eval_root);
endif|#
directive|endif
argument|cmd_free(eval_root);
endif|#
directive|endif
comment|/*SUPPRESS 29*/
comment|/*SUPPRESS 30*/
argument|if ((CMD*)eval_root == last_root) 		last_root = Nullcmd; 	    eval_root = myroot = Nullcmd; 	} 	if (rsfp) { 	    fclose(rsfp); 	    rsfp =
literal|0
argument|; 	}     }     else { 	parsing =
literal|0
argument|; 	sp = cmd_exec(eval_root,gimme,sp); 	st = stack->ary_array; 	for (i = arglast[
literal|0
argument|] +
literal|1
argument|; i<= sp; i++) 	    st[i] = str_mortal(st[i]);
comment|/* if we don't save result, free zaps it */
argument|if (savecmd) 	    eval_root = myroot; 	else if (in_eval !=
literal|1
argument|&& myroot != last_root) 	    cmd_free(myroot); 	    if (eval_root == myroot) 		eval_root = Nullcmd;     }      perldb = oldperldb;     in_eval--;
ifdef|#
directive|ifdef
name|DEBUGGING
argument|if (debug&
literal|4
argument|) { 	char *tmps = loop_stack[loop_ptr].loop_label; 	deb(
literal|"(Popping label #%d %s)\n"
argument|,loop_ptr, 	    tmps ? tmps :
literal|""
argument|);     }
endif|#
directive|endif
argument|loop_ptr--;     tmps_base = oldtmps_base;     curspat = oldspat;     lastspat = oldlspat;     if (savestack->ary_fill> oldsave)
comment|/* let them use local() */
argument|restorelist(oldsave);      if (optype != O_EVAL) { 	if (retval) { 	    if (optype == O_REQUIRE) 		fatal(
literal|"%s"
argument|, str_get(stab_val(stabent(
literal|"@"
argument|,TRUE)))); 	} 	else { 	    curcmd = oldcurcmd; 	    if (gimme == G_SCALAR ? str_true(st[sp]) : sp> arglast[
literal|0
argument|]) { 		(void)hstore(stab_hash(incstab), specfilename, 		  strlen(specfilename), str_smake(stab_val(curcmd->c_filestab)),
literal|0
argument|); 	    } 	    else if (optype == O_REQUIRE) 		fatal(
literal|"%s did not return a true value"
argument|, specfilename); 	}     }     curcmd = oldcurcmd;     return sp; }  int do_try(cmd,gimme,arglast) CMD *cmd; int gimme; int *arglast; {     STR **st = stack->ary_array;      CMD * VOLATILE oldcurcmd = curcmd;     VOLATILE int oldtmps_base = tmps_base;     VOLATILE int oldsave = savestack->ary_fill;     SPAT * VOLATILE oldspat = curspat;     SPAT * VOLATILE oldlspat = lastspat;     VOLATILE int sp = arglast[
literal|0
argument|];      tmps_base = tmps_max;     str_set(stab_val(stabent(
literal|"@"
argument|,TRUE)),
literal|""
argument|);     in_eval++;     if (++loop_ptr>= loop_max) { 	loop_max +=
literal|128
argument|; 	Renew(loop_stack, loop_max, struct loop);     }     loop_stack[loop_ptr].loop_label =
literal|"_EVAL_"
argument|;     loop_stack[loop_ptr].loop_sp = sp;
ifdef|#
directive|ifdef
name|DEBUGGING
argument|if (debug&
literal|4
argument|) { 	deb(
literal|"(Pushing label #%d _EVAL_)\n"
argument|, loop_ptr);     }
endif|#
directive|endif
argument|if (setjmp(loop_stack[loop_ptr].loop_env)) { 	st = stack->ary_array; 	sp = arglast[
literal|0
argument|]; 	if (gimme != G_ARRAY) 	    st[++sp] =&str_undef;     }     else { 	sp = cmd_exec(cmd,gimme,sp); 	st = stack->ary_array;
comment|/*	for (i = arglast[0] + 1; i<= sp; i++) 	    st[i] = str_mortal(st[i]);  not needed, I think */
comment|/* if we don't save result, free zaps it */
argument|}      in_eval--;
ifdef|#
directive|ifdef
name|DEBUGGING
argument|if (debug&
literal|4
argument|) { 	char *tmps = loop_stack[loop_ptr].loop_label; 	deb(
literal|"(Popping label #%d %s)\n"
argument|,loop_ptr, 	    tmps ? tmps :
literal|""
argument|);     }
endif|#
directive|endif
argument|loop_ptr--;     tmps_base = oldtmps_base;     curspat = oldspat;     lastspat = oldlspat;     curcmd = oldcurcmd;     if (savestack->ary_fill> oldsave)
comment|/* let them use local() */
argument|restorelist(oldsave);      return sp; }
comment|/* This routine handles any switches that can be given during run */
argument|static char * moreswitches(s) char *s; {     int numlen;      switch (*s) {     case
literal|'0'
argument|: 	nrschar = scanoct(s,
literal|4
argument|,&numlen); 	nrs = nsavestr(
literal|"\n"
argument|,
literal|1
argument|); 	*nrs = nrschar; 	if (nrschar>
literal|0377
argument|) { 	    nrslen =
literal|0
argument|; 	    nrs =
literal|""
argument|; 	} 	else if (!nrschar&& numlen>=
literal|2
argument|) { 	    nrslen =
literal|2
argument|; 	    nrs =
literal|"\n\n"
argument|; 	    nrschar =
literal|'\n'
argument|; 	} 	return s + numlen;     case
literal|'a'
argument|: 	minus_a = TRUE; 	s++; 	return s;     case
literal|'c'
argument|: 	minus_c = TRUE; 	s++; 	return s;     case
literal|'d'
argument|:
ifdef|#
directive|ifdef
name|TAINT
argument|if (euid != uid || egid != gid) 	    fatal(
literal|"No -d allowed in setuid scripts"
argument|);
endif|#
directive|endif
argument|perldb = TRUE; 	s++; 	return s;     case
literal|'D'
argument|:
ifdef|#
directive|ifdef
name|DEBUGGING
ifdef|#
directive|ifdef
name|TAINT
argument|if (euid != uid || egid != gid) 	    fatal(
literal|"No -D allowed in setuid scripts"
argument|);
endif|#
directive|endif
argument|debug = atoi(s+
literal|1
argument|) |
literal|32768
argument|;
else|#
directive|else
argument|warn(
literal|"Recompile perl with -DDEBUGGING to use -D switch\n"
argument|);
endif|#
directive|endif
comment|/*SUPPRESS 530*/
argument|for (s++; isDIGIT(*s); s++) ; 	return s;     case
literal|'i'
argument|: 	inplace = savestr(s+
literal|1
argument|);
comment|/*SUPPRESS 530*/
argument|for (s = inplace; *s&& !isSPACE(*s); s++) ; 	*s =
literal|'\0'
argument|; 	break;     case
literal|'I'
argument|:
ifdef|#
directive|ifdef
name|TAINT
argument|if (euid != uid || egid != gid) 	    fatal(
literal|"No -I allowed in setuid scripts"
argument|);
endif|#
directive|endif
argument|if (*++s) { 	    (void)apush(stab_array(incstab),str_make(s,
literal|0
argument|)); 	} 	else 	    fatal(
literal|"No space allowed after -I"
argument|); 	break;     case
literal|'l'
argument|: 	minus_l = TRUE; 	s++; 	if (isDIGIT(*s)) { 	    ors = savestr(
literal|"\n"
argument|); 	    orslen =
literal|1
argument|; 	    *ors = scanoct(s,
literal|3
argument|+ (*s ==
literal|'0'
argument|),&numlen); 	    s += numlen; 	} 	else { 	    ors = nsavestr(nrs,nrslen); 	    orslen = nrslen; 	} 	return s;     case
literal|'n'
argument|: 	minus_n = TRUE; 	s++; 	return s;     case
literal|'p'
argument|: 	minus_p = TRUE; 	s++; 	return s;     case
literal|'u'
argument|: 	do_undump = TRUE; 	s++; 	return s;     case
literal|'U'
argument|: 	unsafe = TRUE; 	s++; 	return s;     case
literal|'v'
argument|: 	fputs(
literal|"\nThis is perl, version 4.0\n\n"
argument|,stdout); 	fputs(rcsid,stdout); 	fputs(
literal|"\nCopyright (c) 1989, 1990, 1991, Larry Wall\n"
argument|,stdout);
ifdef|#
directive|ifdef
name|MSDOS
argument|fputs(
literal|"MS-DOS port Copyright (c) 1989, 1990, Diomidis Spinellis\n"
argument|, 	stdout);
ifdef|#
directive|ifdef
name|OS2
argument|fputs(
literal|"OS/2 port Copyright (c) 1990, 1991, Raymond Chen, Kai Uwe Rommel\n"
argument|,         stdout);
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|atarist
argument|fputs(
literal|"atariST series port, ++jrb  bammi@cadence.com\n"
argument|, stdout);
endif|#
directive|endif
argument|fputs(
literal|"\n\ Perl may be copied only under the terms of either the Artistic License or the\n\ GNU General Public License, which may be found in the Perl 4.0 source kit.\n"
argument|,stdout);
ifdef|#
directive|ifdef
name|MSDOS
argument|usage(origargv[
literal|0
argument|]);
endif|#
directive|endif
argument|exit(
literal|0
argument|);     case
literal|'w'
argument|: 	dowarn = TRUE; 	s++; 	return s;     case
literal|' '
argument|:     case
literal|'\n'
argument|:     case
literal|'\t'
argument|: 	break;     default: 	fatal(
literal|"Switch meaningless after -x: -%s"
argument|,s);     }     return Nullch; }
comment|/* compliments of Tom Christiansen */
comment|/* unexec() can be found in the Gnu emacs distribution */
argument|void my_unexec() {
ifdef|#
directive|ifdef
name|UNEXEC
argument|int    status;     extern int etext;     static char dumpname[BUFSIZ];     static char perlpath[
literal|256
argument|];      sprintf (dumpname,
literal|"%s.perldump"
argument|, origfilename);     sprintf (perlpath,
literal|"%s/perl"
argument|, BIN);      status = unexec(dumpname, perlpath,&etext, sbrk(
literal|0
argument|),
literal|0
argument|);     if (status) 	fprintf(stderr,
literal|"unexec of %s into %s failed!\n"
argument|, perlpath, dumpname);     exit(status);
else|#
directive|else
ifdef|#
directive|ifdef
name|DOSISH
argument|abort();
comment|/* nothing else to do */
else|#
directive|else
comment|/* ! MSDOS */
ifndef|#
directive|ifndef
name|SIGABRT
define|#
directive|define
name|SIGABRT
value|SIGILL
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SIGILL
define|#
directive|define
name|SIGILL
value|6
comment|/* blech */
endif|#
directive|endif
argument|kill(getpid(),SIGABRT);
comment|/* for use with undump */
endif|#
directive|endif
comment|/* ! MSDOS */
endif|#
directive|endif
argument|}
end_function

end_unit

