begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* as.c - GAS main program.    Copyright (C) 1987, 1990, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_comment
comment|/*  * Main program for AS; a 32-bit assembler of GNU.  * Understands command arguments.  * Has a few routines that don't fit in other modules because they  * are shared.  *  *  *			bugs  *  * : initialisers  *	Since no-one else says they will support them in future: I  * don't support them now.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_SOURCE
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* For pid_t in signal.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_define
define|#
directive|define
name|COMMON
end_define

begin_include
include|#
directive|include
file|"as.h"
end_include

begin_include
include|#
directive|include
file|"subsegs.h"
end_include

begin_if
if|#
directive|if
name|__STDC__
operator|==
literal|1
end_if

begin_comment
comment|/* This prototype for got_sig() is ansi.  If you want    anything else, then your compiler is lying to you when    it says that it is __STDC__.  If you want to change it,    #ifdef protect it from those of us with real ansi    compilers. */
end_comment

begin_define
define|#
directive|define
name|SIGTY
value|void
end_define

begin_function_decl
specifier|static
name|void
name|got_sig
parameter_list|(
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|char
modifier|*
name|stralloc
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|perform_an_assembly_pass
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIGTY
end_ifndef

begin_define
define|#
directive|define
name|SIGTY
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|SIGTY
name|got_sig
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|char
modifier|*
name|stralloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Make a (safe) copy of a string. */
end_comment

begin_function_decl
specifier|static
name|void
name|perform_an_assembly_pass
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DONTDEF
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|gdb_symbol_file_name
decl_stmt|;
end_decl_stmt

begin_function_decl
name|long
name|gdb_begin
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|listing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if a listing is wanted */
end_comment

begin_decl_stmt
name|char
modifier|*
name|myname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* argv[0] */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|version_string
index|[]
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|int
name|work_argc
decl_stmt|;
comment|/* variable copy of argc */
name|char
modifier|*
modifier|*
name|work_argv
decl_stmt|;
comment|/* variable copy of argv */
name|char
modifier|*
name|arg
decl_stmt|;
comment|/* an arg to program */
name|char
name|a
decl_stmt|;
comment|/* an arg flag (after -) */
specifier|static
specifier|const
name|int
name|sig
index|[]
init|=
block|{
name|SIGHUP
block|,
name|SIGINT
block|,
name|SIGPIPE
block|,
name|SIGTERM
block|,
literal|0
block|}
decl_stmt|;
for|for
control|(
name|a
operator|=
literal|0
init|;
name|sig
index|[
name|a
index|]
operator|!=
literal|0
condition|;
name|a
operator|++
control|)
if|if
condition|(
name|signal
argument_list|(
name|sig
index|[
name|a
index|]
argument_list|,
name|SIG_IGN
argument_list|)
operator|!=
name|SIG_IGN
condition|)
name|signal
argument_list|(
name|sig
index|[
name|a
index|]
argument_list|,
name|got_sig
argument_list|)
expr_stmt|;
name|myname
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
name|memset
argument_list|(
name|flagseen
argument_list|,
literal|'\0'
argument_list|,
sizeof|sizeof
argument_list|(
name|flagseen
argument_list|)
argument_list|)
expr_stmt|;
comment|/* aint seen nothing yet */
ifndef|#
directive|ifndef
name|OBJ_DEFAULT_OUTPUT_FILE_NAME
define|#
directive|define
name|OBJ_DEFAULT_OUTPUT_FILE_NAME
value|"a.out"
endif|#
directive|endif
comment|/* OBJ_DEFAULT_OUTPUT_FILE_NAME */
name|out_file_name
operator|=
name|OBJ_DEFAULT_OUTPUT_FILE_NAME
expr_stmt|;
name|symbol_begin
argument_list|()
expr_stmt|;
comment|/* symbols.c */
name|subsegs_begin
argument_list|()
expr_stmt|;
comment|/* subsegs.c */
name|read_begin
argument_list|()
expr_stmt|;
comment|/* read.c */
name|md_begin
argument_list|()
expr_stmt|;
comment|/* MACHINE.c */
name|input_scrub_begin
argument_list|()
expr_stmt|;
comment|/* input_scrub.c */
ifdef|#
directive|ifdef
name|DONTDEF
name|gdb_symbol_file_name
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Parse arguments, but we are only interested in flags. 	 * When we find a flag, we process it then make it's argv[] NULL. 	 * This helps any future argv[] scanners avoid what we processed. 	 * Since it is easy to do here we interpret the special arg "-" 	 * to mean "use stdin" and we set that argv[] pointing to "". 	 * After we have munged argv[], the only things left are source file 	 * name(s) and ""(s) denoting stdin. These file names are used 	 * (perhaps more than once) later. 	 */
comment|/* FIXME-SOMEDAY this should use getopt. */
name|work_argc
operator|=
name|argc
operator|-
literal|1
expr_stmt|;
comment|/* don't count argv[0] */
name|work_argv
operator|=
name|argv
operator|+
literal|1
expr_stmt|;
comment|/* skip argv[0] */
for|for
control|(
init|;
name|work_argc
operator|--
condition|;
name|work_argv
operator|++
control|)
block|{
name|arg
operator|=
operator|*
name|work_argv
expr_stmt|;
comment|/* work_argv points to this argument */
if|if
condition|(
operator|*
name|arg
operator|!=
literal|'-'
condition|)
comment|/* Filename. We need it later. */
continue|continue;
comment|/* Keep scanning args looking for flags. */
if|if
condition|(
name|arg
index|[
literal|1
index|]
operator|==
literal|'-'
operator|&&
name|arg
index|[
literal|2
index|]
operator|==
literal|0
condition|)
block|{
comment|/* "--" as an argument means read STDIN */
comment|/* on this scan, we don't want to think about filenames */
operator|*
name|work_argv
operator|=
literal|""
expr_stmt|;
comment|/* Code that means 'use stdin'. */
continue|continue;
block|}
comment|/* This better be a switch. */
name|arg
operator|++
expr_stmt|;
comment|/*->letter. */
while|while
condition|(
operator|(
name|a
operator|=
operator|*
name|arg
operator|)
operator|!=
literal|'\0'
condition|)
block|{
comment|/* scan all the 1-char flags */
name|arg
operator|++
expr_stmt|;
comment|/* arg->after letter. */
name|a
operator|&=
literal|0x7F
expr_stmt|;
comment|/* ascii only please */
comment|/* if (flagseen[a]) 			   as_tsktsk("%s: Flag option - %c has already been seen.", myname, a); */
name|flagseen
index|[
name|a
index|]
operator|=
literal|1
expr_stmt|;
switch|switch
condition|(
name|a
condition|)
block|{
case|case
literal|'a'
case|:
block|{
name|int
name|loop
init|=
literal|1
decl_stmt|;
while|while
condition|(
name|loop
condition|)
block|{
switch|switch
condition|(
operator|*
name|arg
condition|)
block|{
case|case
literal|'l'
case|:
name|listing
operator||=
name|LISTING_LISTING
expr_stmt|;
name|arg
operator|++
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
name|listing
operator||=
name|LISTING_SYMBOLS
expr_stmt|;
name|arg
operator|++
expr_stmt|;
break|break;
case|case
literal|'h'
case|:
name|listing
operator||=
name|LISTING_HLL
expr_stmt|;
name|arg
operator|++
expr_stmt|;
break|break;
case|case
literal|'n'
case|:
name|listing
operator||=
name|LISTING_NOFORM
expr_stmt|;
name|arg
operator|++
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
name|listing
operator||=
name|LISTING_NODEBUG
expr_stmt|;
name|arg
operator|++
expr_stmt|;
break|break;
default|default:
if|if
condition|(
operator|!
name|listing
condition|)
name|listing
operator|=
name|LISTING_DEFAULT
expr_stmt|;
name|loop
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
block|}
break|break;
case|case
literal|'f'
case|:
break|break;
comment|/* -f means fast - no need for "app" preprocessor. */
case|case
literal|'D'
case|:
comment|/* DEBUG is implemented: it debugs different */
comment|/* things to other people's assemblers. */
break|break;
ifdef|#
directive|ifdef
name|DONTDEF
case|case
literal|'G'
case|:
comment|/* GNU AS switch: include gdbsyms. */
if|if
condition|(
operator|*
name|arg
condition|)
comment|/* Rest of argument is file-name. */
name|gdb_symbol_file_name
operator|=
name|stralloc
argument_list|(
name|arg
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|work_argc
condition|)
block|{
comment|/* Next argument is file-name. */
name|work_argc
operator|--
expr_stmt|;
operator|*
name|work_argv
operator|=
name|NULL
expr_stmt|;
comment|/* Not a source file-name. */
name|gdb_symbol_file_name
operator|=
operator|*
operator|++
name|work_argv
expr_stmt|;
block|}
else|else
name|as_warn
argument_list|(
literal|"%s: I expected a filename after -G"
argument_list|,
name|myname
argument_list|)
expr_stmt|;
name|arg
operator|=
literal|""
expr_stmt|;
comment|/* Finished with this arg. */
break|break;
endif|#
directive|endif
case|case
literal|'I'
case|:
block|{
comment|/* Include file directory */
name|char
modifier|*
name|temp
init|=
name|NULL
decl_stmt|;
if|if
condition|(
operator|*
name|arg
condition|)
name|temp
operator|=
name|stralloc
argument_list|(
name|arg
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|work_argc
condition|)
block|{
operator|*
name|work_argv
operator|=
name|NULL
expr_stmt|;
name|work_argc
operator|--
expr_stmt|;
name|temp
operator|=
operator|*
operator|++
name|work_argv
expr_stmt|;
block|}
else|else
name|as_warn
argument_list|(
literal|"%s: I expected a filename after -I"
argument_list|,
name|myname
argument_list|)
expr_stmt|;
name|add_include_dir
argument_list|(
name|temp
argument_list|)
expr_stmt|;
name|arg
operator|=
literal|""
expr_stmt|;
comment|/* Finished with this arg. */
break|break;
block|}
case|case
literal|'L'
case|:
comment|/* -L means keep L* symbols */
break|break;
case|case
literal|'o'
case|:
if|if
condition|(
operator|*
name|arg
condition|)
comment|/* Rest of argument is object file-name. */
name|out_file_name
operator|=
name|stralloc
argument_list|(
name|arg
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|work_argc
condition|)
block|{
comment|/* Want next arg for a file-name. */
operator|*
name|work_argv
operator|=
name|NULL
expr_stmt|;
comment|/* This is not a file-name. */
name|work_argc
operator|--
expr_stmt|;
name|out_file_name
operator|=
operator|*
operator|++
name|work_argv
expr_stmt|;
block|}
else|else
name|as_warn
argument_list|(
literal|"%s: I expected a filename after -o. \"%s\" assumed."
argument_list|,
name|myname
argument_list|,
name|out_file_name
argument_list|)
expr_stmt|;
name|arg
operator|=
literal|""
expr_stmt|;
comment|/* Finished with this arg. */
break|break;
case|case
literal|'R'
case|:
comment|/* -R means put data into text segment */
break|break;
case|case
literal|'v'
case|:
ifdef|#
directive|ifdef
name|OBJ_VMS
block|{
specifier|extern
name|char
modifier|*
name|compiler_version_string
decl_stmt|;
name|compiler_version_string
operator|=
name|arg
expr_stmt|;
block|}
else|#
directive|else
comment|/* not OBJ_VMS */
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|version_string
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|arg
operator|&&
name|strcmp
argument_list|(
name|arg
argument_list|,
literal|"ersion"
argument_list|)
condition|)
name|as_warn
argument_list|(
literal|"Unknown -v option ignored"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* not OBJ_VMS */
while|while
condition|(
operator|*
name|arg
condition|)
name|arg
operator|++
expr_stmt|;
comment|/* Skip the rest */
break|break;
case|case
literal|'W'
case|:
comment|/* -W means don't warn about things */
case|case
literal|'X'
case|:
comment|/* -X means treat warnings as errors */
case|case
literal|'Z'
case|:
comment|/* -Z means attempt to generate object file even after errors. */
break|break;
default|default:
operator|--
name|arg
expr_stmt|;
if|if
condition|(
name|md_parse_option
argument_list|(
operator|&
name|arg
argument_list|,
operator|&
name|work_argc
argument_list|,
operator|&
name|work_argv
argument_list|)
operator|==
literal|0
condition|)
name|as_warn
argument_list|(
literal|"%s: I don't understand '%c' flag."
argument_list|,
name|myname
argument_list|,
name|a
argument_list|)
expr_stmt|;
if|if
condition|(
name|arg
operator|&&
operator|*
name|arg
condition|)
name|arg
operator|++
expr_stmt|;
break|break;
block|}
block|}
comment|/* 		 * We have just processed a "-..." arg, which was not a 		 * file-name. Smash it so the 		 * things that look for filenames won't ever see it. 		 * 		 * Whatever work_argv points to, it has already been used 		 * as part of a flag, so DON'T re-use it as a filename. 		 */
operator|*
name|work_argv
operator|=
name|NULL
expr_stmt|;
comment|/* NULL means 'not a file-name' */
block|}
ifdef|#
directive|ifdef
name|PIC
if|if
condition|(
name|flagseen
index|[
literal|'K'
index|]
operator|||
name|flagseen
index|[
literal|'k'
index|]
condition|)
name|picmode
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DONTDEF
if|if
condition|(
name|gdb_begin
argument_list|(
name|gdb_symbol_file_name
argument_list|)
operator|==
literal|0
condition|)
name|flagseen
index|[
literal|'G'
index|]
operator|=
literal|0
expr_stmt|;
comment|/* Don't do any gdbsym stuff. */
endif|#
directive|endif
comment|/* Here with flags set up in flagseen[]. */
name|perform_an_assembly_pass
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
comment|/* Assemble it. */
ifdef|#
directive|ifdef
name|TC_I960
name|brtab_emit
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|seen_at_least_1_file
argument_list|()
operator|&&
operator|!
operator|(
operator|(
name|had_warnings
argument_list|()
operator|&&
name|flagseen
index|[
literal|'Z'
index|]
operator|)
operator|||
name|had_errors
argument_list|()
operator|>
literal|0
operator|)
condition|)
block|{
name|write_object_file
argument_list|()
expr_stmt|;
comment|/* relax() addresses then emit object file */
block|}
comment|/* we also check in write_object_file() just before emit. */
name|input_scrub_end
argument_list|()
expr_stmt|;
name|md_end
argument_list|()
expr_stmt|;
comment|/* MACHINE.c */
ifndef|#
directive|ifndef
name|NO_LISTING
name|listing_print
argument_list|(
literal|""
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HO_VMS
return|return
operator|(
operator|(
name|had_warnings
argument_list|()
operator|&&
name|flagseen
index|[
literal|'Z'
index|]
operator|)
operator|||
name|had_errors
argument_list|()
operator|>
literal|0
operator|)
return|;
comment|/* WIN */
else|#
directive|else
comment|/* HO_VMS */
return|return
operator|(
operator|!
operator|(
operator|(
name|had_warnings
argument_list|()
operator|&&
name|flagseen
index|[
literal|'Z'
index|]
operator|)
operator|||
name|had_errors
argument_list|()
operator|>
literal|0
operator|)
operator|)
return|;
comment|/* WIN */
endif|#
directive|endif
comment|/* HO_VMS */
block|}
end_function

begin_comment
comment|/* main() */
end_comment

begin_escape
end_escape

begin_comment
comment|/*			perform_an_assembly_pass()  *  * Here to attempt 1 pass over each input file.  * We scan argv[*] looking for filenames or exactly "" which is  * shorthand for stdin. Any argv that is NULL is not a file-name.  * We set need_pass_2 TRUE if, after this, we still have unresolved  * expressions of the form (unknown value)+-(unknown value).  *  * Note the un*x semantics: there is only 1 logical input file, but it  * may be a catenation of many 'physical' input files.  */
end_comment

begin_function
specifier|static
name|void
name|perform_an_assembly_pass
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|int
name|saw_a_file
init|=
literal|0
decl_stmt|;
name|need_pass_2
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|MANY_SEGMENTS
name|unsigned
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
name|SEG_E0
init|;
name|i
operator|<
name|SEG_UNKNOWN
condition|;
name|i
operator|++
control|)
block|{
name|segment_info
index|[
name|i
index|]
operator|.
name|fix_root
operator|=
literal|0
expr_stmt|;
block|}
comment|/* Create the three fixed ones */
name|subseg_new
argument_list|(
name|SEG_E0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|subseg_new
argument_list|(
name|SEG_E1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|subseg_new
argument_list|(
name|SEG_E2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|segment_info
index|[
name|SEG_E0
index|]
operator|.
name|scnhdr
operator|.
name|s_name
argument_list|,
literal|".text"
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|segment_info
index|[
name|SEG_E1
index|]
operator|.
name|scnhdr
operator|.
name|s_name
argument_list|,
literal|".data"
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|segment_info
index|[
name|SEG_E2
index|]
operator|.
name|scnhdr
operator|.
name|s_name
argument_list|,
literal|".bss"
argument_list|)
expr_stmt|;
name|subseg_new
argument_list|(
name|SEG_E0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* not MANY_SEGMENTS */
name|text_fix_root
operator|=
name|NULL
expr_stmt|;
name|data_fix_root
operator|=
name|NULL
expr_stmt|;
name|bss_fix_root
operator|=
name|NULL
expr_stmt|;
name|subseg_new
argument_list|(
name|SEG_TEXT
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* not MANY_SEGMENTS */
name|argv
operator|++
expr_stmt|;
comment|/* skip argv[0] */
name|argc
operator|--
expr_stmt|;
comment|/* skip argv[0] */
while|while
condition|(
name|argc
operator|--
condition|)
block|{
if|if
condition|(
operator|*
name|argv
condition|)
block|{
comment|/* Is it a file-name argument? */
name|saw_a_file
operator|++
expr_stmt|;
comment|/* argv->"" if stdin desired, else->filename */
name|read_a_source_file
argument_list|(
operator|*
name|argv
argument_list|)
expr_stmt|;
block|}
name|argv
operator|++
expr_stmt|;
comment|/* completed that argv */
block|}
if|if
condition|(
operator|!
name|saw_a_file
condition|)
name|read_a_source_file
argument_list|(
literal|""
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* perform_an_assembly_pass() */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  *			stralloc()  *  * Allocate memory for a new copy of a string. Copy the string.  * Return the address of the new string. Die if there is any error.  */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|stralloc
parameter_list|(
name|str
parameter_list|)
name|char
modifier|*
name|str
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|retval
decl_stmt|;
specifier|register
name|long
name|len
decl_stmt|;
name|len
operator|=
name|strlen
argument_list|(
name|str
argument_list|)
operator|+
literal|1
expr_stmt|;
name|retval
operator|=
name|xmalloc
argument_list|(
name|len
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|retval
argument_list|,
name|str
argument_list|)
expr_stmt|;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|comment
end_ifdef

begin_function
specifier|static
name|void
name|lose
parameter_list|()
block|{
name|as_fatal
argument_list|(
literal|"%s: 2nd pass not implemented - get your code from random(3)"
argument_list|,
name|myname
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/* lose() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* comment */
end_comment

begin_function
specifier|static
name|SIGTY
name|got_sig
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
specifier|static
name|here_before
operator|=
literal|0
expr_stmt|;
name|as_bad
argument_list|(
literal|"Interrupted by signal %d"
argument_list|,
name|sig
argument_list|)
expr_stmt|;
if|if
condition|(
name|here_before
operator|++
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|SIGTY
operator|)
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of as.c */
end_comment

end_unit

