begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
modifier|*
name|cmdv
init|=
literal|"Unix cmd package V1A(021), 19 Jun 85"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  C K U C M D  --  Interactive command package for Unix  */
end_comment

begin_comment
comment|/*  Modelled after the DECSYSTEM-20 command parser (the COMND JSYS)   Features:  . parses and verifies keywords, text strings, numbers, and other data  . displays appropriate menu or help message when user types "?"  . does keyword and filename completion when user types ESC  . accepts any unique abbreviation for a keyword  . allows keywords to have attributes, like "invisible"  . can supply defaults for fields omitted by user  . provides command line editing (character, word, and line deletion)  . accepts input from keyboard, command files, or redirected stdin  . allows for full or half duplex operation, character or line input  . settable prompt, protected from deletion   Functions:   cmsetp - Set prompt (cmprom is prompt string, cmerrp is error msg prefix)   cmsavp - Save current prompt   prompt - Issue prompt    cmini  - Clear the command buffer (before parsing a new command)   cmres  - Reset command buffer pointers (before reparsing)   cmkey  - Parse a keyword   cmnum  - Parse a number   cmifi  - Parse an input file name   cmofi  - Parse an output file name   cmfld  - Parse an arbitrary field   cmtxt  - Parse a text string   cmcfm  - Parse command confirmation (end of line)   stripq - Strip out backslash quotes from a string.   Return codes:   -3: no input provided when required   -2: input was invalid   -1: reparse required (user deleted into a preceding field)    0 or greater: success   See individual functions for greater detail.   Before using these routines, the caller should #include ckucmd.h, and  set the program's prompt by calling cmsetp().  If the file parsing  functions cmifi and cmofi are to be used, this module must be linked  with a ck?fio file system support module for the appropriate system,  e.g. ckufio for Unix.  If the caller puts the terminal in  character wakeup ("cbreak") mode with no echo, then these functions will  provide line editing -- character, word, and line deletion, as well as  keyword and filename completion upon ESC and help strings, keyword, or  file menus upon '?'.  If the caller puts the terminal into character  wakeup/noecho mode, care should be taken to restore it before exit from  or interruption of the program.  If the character wakeup mode is not  set, the system's own line editor may be used.   Author: Frank da Cruz (SY.FDC@CU20B),  Columbia University Center for Computing Activities, January 1985.  Copyright (C) 1985, Trustees of Columbia University in the City of New York.  Permission is granted to any individual or institution to use, copy, or  redistribute this software so long as it is not sold for profit, provided this  copyright notice is retained.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Includes */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Standard C I/O package */
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
file|"ckucmd.h"
end_include

begin_comment
comment|/* Command parsing definitions */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_comment
comment|/* Formats for debug() */
end_comment

begin_comment
comment|/* Local variables */
end_comment

begin_decl_stmt
name|int
name|psetf
init|=
literal|0
decl_stmt|,
comment|/* Flag that prompt has been set */
name|cc
init|=
literal|0
decl_stmt|,
comment|/* Character count */
name|dpx
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Duplex (0 = full) */
end_comment

begin_decl_stmt
name|int
name|hw
init|=
name|HLPLW
decl_stmt|,
comment|/* Help line width */
name|hc
init|=
name|HLPCW
decl_stmt|,
comment|/* Help line column width */
name|hh
decl_stmt|,
comment|/* Current help column number */
name|hx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current help line position */
end_comment

begin_define
define|#
directive|define
name|PROML
value|60
end_define

begin_comment
comment|/* Maximum length for prompt */
end_comment

begin_decl_stmt
name|char
name|cmprom
index|[
name|PROML
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Program's prompt */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dfprom
init|=
literal|"Command? "
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default prompt */
end_comment

begin_decl_stmt
name|char
name|cmerrp
index|[
name|PROML
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Program's error message prefix */
end_comment

begin_decl_stmt
name|int
name|cmflgs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command flags */
end_comment

begin_decl_stmt
name|char
name|cmdbuf
index|[
name|CMDBL
operator|+
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command buffer */
end_comment

begin_decl_stmt
name|char
name|hlpbuf
index|[
name|HLPBL
operator|+
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Help string buffer */
end_comment

begin_decl_stmt
name|char
name|atmbuf
index|[
name|ATMBL
operator|+
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Atom buffer */
end_comment

begin_decl_stmt
name|char
name|filbuf
index|[
name|ATMBL
operator|+
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File name buffer */
end_comment

begin_comment
comment|/* Command buffer pointers */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|bp
decl_stmt|,
comment|/* Current command buffer position */
modifier|*
name|pp
decl_stmt|,
comment|/* Start of current field */
modifier|*
name|np
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Start of next field */
end_comment

begin_function_decl
name|long
name|zchki
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* From ck?fio.c. */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  C M S E T P  --  Set the program prompt.  */
end_comment

begin_macro
name|cmsetp
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|sx
decl_stmt|,
modifier|*
name|sy
decl_stmt|,
modifier|*
name|strncpy
argument_list|()
decl_stmt|;
name|psetf
operator|=
literal|1
expr_stmt|;
comment|/* Flag that prompt has been set. */
name|strncpy
argument_list|(
name|cmprom
argument_list|,
name|s
argument_list|,
name|PROML
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* Copy the string. */
name|cmprom
index|[
name|PROML
index|]
operator|=
name|NUL
expr_stmt|;
comment|/* Ensure null terminator. */
name|sx
operator|=
name|cmprom
expr_stmt|;
name|sy
operator|=
name|cmerrp
expr_stmt|;
comment|/* Also use as error message prefix. */
while|while
condition|(
operator|*
name|sy
operator|++
operator|=
operator|*
name|sx
operator|++
condition|)
empty_stmt|;
comment|/* Copy. */
name|sy
operator|-=
literal|2
expr_stmt|;
if|if
condition|(
operator|*
name|sy
operator|==
literal|'>'
condition|)
operator|*
name|sy
operator|=
name|NUL
expr_stmt|;
comment|/* Delete any final '>'. */
block|}
end_block

begin_comment
comment|/*  C M S A V P  --  Save a copy of the current prompt.  */
end_comment

begin_macro
name|cmsavp
argument_list|(
argument|s
argument_list|,
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|s
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|char
modifier|*
name|strncpy
parameter_list|()
function_decl|;
comment|/* +1	*/
name|strncpy
argument_list|(
name|s
argument_list|,
name|cmprom
argument_list|,
name|n
operator|-
literal|1
argument_list|)
expr_stmt|;
name|s
index|[
name|n
index|]
operator|=
name|NUL
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  P R O M P T  --  Issue the program prompt.  */
end_comment

begin_macro
name|prompt
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|psetf
operator|==
literal|0
condition|)
name|cmsetp
argument_list|(
name|dfprom
argument_list|)
expr_stmt|;
comment|/* If no prompt set, set default. */
name|printf
argument_list|(
literal|"\r%s"
argument_list|,
name|cmprom
argument_list|)
expr_stmt|;
comment|/* Print the prompt. */
block|}
end_block

begin_comment
comment|/*  C M R E S  --  Reset pointers to beginning of command buffer.  */
end_comment

begin_macro
name|cmres
argument_list|()
end_macro

begin_block
block|{
name|cc
operator|=
literal|0
expr_stmt|;
comment|/* Reset character counter. */
name|pp
operator|=
name|np
operator|=
name|bp
operator|=
name|cmdbuf
expr_stmt|;
comment|/* Point to command buffer. */
name|cmflgs
operator|=
operator|-
literal|5
expr_stmt|;
comment|/* Parse not yet started. */
block|}
end_block

begin_comment
comment|/*  C M I N I  --  Clear the command and atom buffers, reset pointers.  */
end_comment

begin_comment
comment|/* The argument specifies who is to echo the user's typein --   1 means the cmd package echoes   0 somebody else (system, front end, terminal) echoes */
end_comment

begin_macro
name|cmini
argument_list|(
argument|d
argument_list|)
end_macro

begin_decl_stmt
name|int
name|d
decl_stmt|;
end_decl_stmt

begin_block
block|{
for|for
control|(
name|bp
operator|=
name|cmdbuf
init|;
name|bp
operator|<
name|cmdbuf
operator|+
name|CMDBL
condition|;
name|bp
operator|++
control|)
operator|*
name|bp
operator|=
name|NUL
expr_stmt|;
operator|*
name|atmbuf
operator|=
name|NUL
expr_stmt|;
name|dpx
operator|=
name|d
expr_stmt|;
name|cmres
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|stripq
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Function to strip '\' quotes */
name|char
modifier|*
name|t
decl_stmt|;
while|while
condition|(
operator|*
name|s
condition|)
block|{
if|if
condition|(
operator|*
name|s
operator|==
literal|'\\'
condition|)
block|{
for|for
control|(
name|t
operator|=
name|s
init|;
operator|*
name|t
operator|!=
literal|'\0'
condition|;
name|t
operator|++
control|)
operator|*
name|t
operator|=
operator|*
operator|(
name|t
operator|+
literal|1
operator|)
expr_stmt|;
block|}
name|s
operator|++
expr_stmt|;
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  C M N U M  --  Parse a number in the indicated radix  */
end_comment

begin_comment
comment|/*  For now, only works for positive numbers in base 10.  */
end_comment

begin_comment
comment|/*  Returns    -3 if no input present when required,    -2 if user typed an illegal number,    -1 if reparse needed,     0 otherwise, with n set to number that was parsed */
end_comment

begin_macro
name|cmnum
argument_list|(
argument|xhlp
argument_list|,
argument|xdef
argument_list|,
argument|radix
argument_list|,
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|xhlp
decl_stmt|,
modifier|*
name|xdef
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|radix
decl_stmt|,
modifier|*
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|x
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
if|if
condition|(
name|radix
operator|!=
literal|10
condition|)
block|{
comment|/* Just do base 10 for now */
name|printf
argument_list|(
literal|"cmnum: illegal radix - %d\n"
argument_list|,
name|radix
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
name|cmfld
argument_list|(
name|xhlp
argument_list|,
name|xdef
argument_list|,
operator|&
name|s
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"cmnum: cmfld"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
return|return
operator|(
name|x
operator|)
return|;
comment|/* Parse a field */
if|if
condition|(
name|digits
argument_list|(
name|atmbuf
argument_list|)
condition|)
block|{
comment|/* Convert to number */
operator|*
name|n
operator|=
name|atoi
argument_list|(
name|atmbuf
argument_list|)
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"\n?not a number - %s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  C M O F I  --  Parse the name of an output file  */
end_comment

begin_comment
comment|/*  Depends on the external function zchko(); if zchko() not available, use  cmfld() to parse output file names.   Returns    -3 if no input present when required,    -2 if permission would be denied to create the file,    -1 if reparse needed,     0 or 1 otherwise, with xp pointing to name. */
end_comment

begin_macro
name|cmofi
argument_list|(
argument|xhlp
argument_list|,
argument|xdef
argument_list|,
argument|xp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|xhlp
decl_stmt|,
modifier|*
name|xdef
decl_stmt|,
modifier|*
modifier|*
name|xp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|x
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
if|if
condition|(
operator|*
name|xhlp
operator|==
name|NUL
condition|)
name|xhlp
operator|=
literal|"Output file"
expr_stmt|;
operator|*
name|xp
operator|=
literal|""
expr_stmt|;
if|if
condition|(
operator|(
name|x
operator|=
name|cmfld
argument_list|(
name|xhlp
argument_list|,
name|xdef
argument_list|,
operator|&
name|s
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
name|x
operator|)
return|;
if|if
condition|(
name|chkwld
argument_list|(
name|s
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"\n?Wildcards not allowed - %s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
if|if
condition|(
name|zchko
argument_list|(
name|s
argument_list|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n?Write permission denied - %s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
else|else
block|{
operator|*
name|xp
operator|=
name|s
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  C M I F I  --  Parse the name of an existing file  */
end_comment

begin_comment
comment|/*  This function depends on the external functions:    zchki()  - Check if input file exists and is readable.    zxpand() - Expand a wild file specification into a list.    znext()  - Return next file name from list.  If these functions aren't available, then use cmfld() to parse filenames. */
end_comment

begin_comment
comment|/*  Returns    -4 EOF    -3 if no input present when required,    -2 if file does not exist or is not readable,    -1 if reparse needed,     0 or 1 otherwise, with: 	xp pointing to name,     	wild = 1 if name contains '*' or '?', 0 otherwise. */
end_comment

begin_macro
name|cmifi
argument_list|(
argument|xhlp
argument_list|,
argument|xdef
argument_list|,
argument|xp
argument_list|,
argument|wild
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|xhlp
decl_stmt|,
modifier|*
name|xdef
decl_stmt|,
modifier|*
modifier|*
name|xp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|wild
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|,
name|x
decl_stmt|,
name|xc
decl_stmt|;
name|long
name|y
decl_stmt|;
name|char
modifier|*
name|sp
decl_stmt|;
name|cc
operator|=
name|xc
operator|=
literal|0
expr_stmt|;
comment|/* Initialize counts& pointers */
operator|*
name|xp
operator|=
literal|""
expr_stmt|;
if|if
condition|(
operator|(
name|x
operator|=
name|cmflgs
operator|)
operator|!=
literal|1
condition|)
block|{
comment|/* Already confirmed? */
name|x
operator|=
name|getwd
argument_list|()
expr_stmt|;
comment|/* No, get a word */
block|}
else|else
block|{
name|cc
operator|=
name|setatm
argument_list|(
name|xdef
argument_list|)
expr_stmt|;
comment|/* If so, use default, if any. */
block|}
operator|*
name|xp
operator|=
name|atmbuf
expr_stmt|;
comment|/* Point to result. */
operator|*
name|wild
operator|=
name|chkwld
argument_list|(
operator|*
name|xp
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|xc
operator|+=
name|cc
expr_stmt|;
comment|/* Count the characters. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"cmifi: getwd"
argument_list|,
name|atmbuf
argument_list|,
name|xc
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|x
condition|)
block|{
case|case
operator|-
literal|4
case|:
comment|/* EOF */
case|case
operator|-
literal|2
case|:
comment|/* Out of space. */
case|case
operator|-
literal|1
case|:
comment|/* Reparse needed */
return|return
operator|(
name|x
operator|)
return|;
comment|/* cont'd... */
comment|/* ...cmifi(), cont'd */
case|case
literal|0
case|:
comment|/* SP or NL */
case|case
literal|1
case|:
if|if
condition|(
name|xc
operator|==
literal|0
condition|)
operator|*
name|xp
operator|=
name|xdef
expr_stmt|;
comment|/* If no input, return default. */
else|else
operator|*
name|xp
operator|=
name|atmbuf
expr_stmt|;
if|if
condition|(
operator|*
operator|*
name|xp
operator|==
name|NUL
condition|)
return|return
operator|(
operator|-
literal|3
operator|)
return|;
comment|/* If field empty, return -3. */
comment|/* If filespec is wild, see if there are any matches */
operator|*
name|wild
operator|=
name|chkwld
argument_list|(
operator|*
name|xp
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" *wild"
argument_list|,
literal|""
argument_list|,
operator|*
name|wild
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|wild
operator|!=
literal|0
condition|)
block|{
name|y
operator|=
name|zxpand
argument_list|(
operator|*
name|xp
argument_list|)
expr_stmt|;
if|if
condition|(
name|y
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n?No files match - %s\n"
argument_list|,
operator|*
name|xp
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|y
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n?Too many files match - %s\n"
argument_list|,
operator|*
name|xp
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
else|else
return|return
operator|(
name|x
operator|)
return|;
block|}
comment|/* If not wild, see if it exists and is readable. */
name|y
operator|=
name|zchki
argument_list|(
operator|*
name|xp
argument_list|)
expr_stmt|;
if|if
condition|(
name|y
operator|==
operator|-
literal|3
condition|)
block|{
name|printf
argument_list|(
literal|"\n?Read permission denied - %s\n"
argument_list|,
operator|*
name|xp
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|y
operator|==
operator|-
literal|2
condition|)
block|{
name|printf
argument_list|(
literal|"\n?File not readable - %s\n"
argument_list|,
operator|*
name|xp
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|y
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n?File not found - %s\n"
argument_list|,
operator|*
name|xp
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
return|return
operator|(
name|x
operator|)
return|;
comment|/* cont'd... */
comment|/* ...cmifi(), cont'd */
case|case
literal|2
case|:
comment|/* ESC */
if|if
condition|(
name|xc
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|*
name|xdef
operator|!=
literal|'\0'
condition|)
block|{
name|printf
argument_list|(
literal|"%s "
argument_list|,
name|xdef
argument_list|)
expr_stmt|;
comment|/* If at beginning of field, */
name|addbuf
argument_list|(
name|xdef
argument_list|)
expr_stmt|;
comment|/* supply default. */
name|cc
operator|=
name|setatm
argument_list|(
name|xdef
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* No default */
name|putchar
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
if|if
condition|(
operator|*
name|wild
operator|=
name|chkwld
argument_list|(
operator|*
name|xp
argument_list|)
condition|)
block|{
comment|/* No completion if wild */
name|putchar
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
break|break;
block|}
name|sp
operator|=
name|atmbuf
operator|+
name|cc
expr_stmt|;
operator|*
name|sp
operator|++
operator|=
literal|'*'
expr_stmt|;
operator|*
name|sp
operator|--
operator|=
literal|'\0'
expr_stmt|;
name|y
operator|=
name|zxpand
argument_list|(
name|atmbuf
argument_list|)
expr_stmt|;
comment|/* Add * and expand list. */
operator|*
name|sp
operator|=
literal|'\0'
expr_stmt|;
comment|/* Remove *. */
if|if
condition|(
name|y
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n?No files match - %s\n"
argument_list|,
name|atmbuf
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|y
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n?Too many files match - %s\n"
argument_list|,
name|atmbuf
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|y
operator|>
literal|1
condition|)
block|{
comment|/* Not unique, just beep. */
name|putchar
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Unique, complete it.  */
name|znext
argument_list|(
name|filbuf
argument_list|)
expr_stmt|;
comment|/* Get whole name of file. */
name|sp
operator|=
name|filbuf
operator|+
name|cc
expr_stmt|;
comment|/* Point past what user typed. */
name|printf
argument_list|(
literal|"%s "
argument_list|,
name|sp
argument_list|)
expr_stmt|;
comment|/* Complete the name. */
name|addbuf
argument_list|(
name|sp
argument_list|)
expr_stmt|;
comment|/* Add the characters to cmdbuf. */
name|setatm
argument_list|(
name|pp
argument_list|)
expr_stmt|;
comment|/* And to atmbuf. */
operator|*
name|xp
operator|=
name|atmbuf
expr_stmt|;
comment|/* Return pointer to atmbuf. */
return|return
operator|(
name|cmflgs
operator|=
literal|0
operator|)
return|;
block|}
break|break;
comment|/* cont'd... */
comment|/* ...cmifi(), cont'd */
case|case
literal|3
case|:
comment|/* Question mark */
if|if
condition|(
operator|*
name|xhlp
operator|==
name|NUL
condition|)
name|printf
argument_list|(
literal|" Input file specification"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" %s"
argument_list|,
name|xhlp
argument_list|)
expr_stmt|;
if|if
condition|(
name|xc
operator|>
literal|0
condition|)
block|{
name|sp
operator|=
name|atmbuf
operator|+
name|cc
expr_stmt|;
comment|/* Insert * at end */
operator|*
name|sp
operator|++
operator|=
literal|'*'
expr_stmt|;
operator|*
name|sp
operator|--
operator|=
literal|'\0'
expr_stmt|;
name|y
operator|=
name|zxpand
argument_list|(
name|atmbuf
argument_list|)
expr_stmt|;
operator|*
name|sp
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|y
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n?No files match - %s\n"
argument_list|,
name|atmbuf
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|y
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n?Too many file match - %s\n"
argument_list|,
name|atmbuf
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|", one of the following:\n"
argument_list|)
expr_stmt|;
name|clrhlp
argument_list|()
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|y
condition|;
name|i
operator|++
control|)
block|{
name|znext
argument_list|(
name|filbuf
argument_list|)
expr_stmt|;
name|addhlp
argument_list|(
name|filbuf
argument_list|)
expr_stmt|;
block|}
name|dmphlp
argument_list|()
expr_stmt|;
block|}
block|}
else|else
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s%s"
argument_list|,
name|cmprom
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
break|break;
block|}
name|x
operator|=
name|getwd
argument_list|()
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  C H K W L D  --  Check for wildcard characters '*' or '?'  */
end_comment

begin_macro
name|chkwld
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
for|for
control|(
init|;
operator|*
name|s
operator|!=
literal|'\0'
condition|;
name|s
operator|++
control|)
block|{
if|if
condition|(
operator|(
operator|*
name|s
operator|==
literal|'*'
operator|)
operator|||
operator|(
operator|*
name|s
operator|==
literal|'?'
operator|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
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
comment|/*  C M F L D  --  Parse an arbitrary field  */
end_comment

begin_comment
comment|/*  Returns    -3 if no input present when required,    -2 if field too big for buffer,    -1 if reparse needed,     0 otherwise, xp pointing to string result. */
end_comment

begin_macro
name|cmfld
argument_list|(
argument|xhlp
argument_list|,
argument|xdef
argument_list|,
argument|xp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|xhlp
decl_stmt|,
modifier|*
name|xdef
decl_stmt|,
modifier|*
modifier|*
name|xp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|x
decl_stmt|,
name|xc
decl_stmt|;
name|cc
operator|=
name|xc
operator|=
literal|0
expr_stmt|;
comment|/* Initialize counts& pointers */
operator|*
name|xp
operator|=
literal|""
expr_stmt|;
if|if
condition|(
operator|(
name|x
operator|=
name|cmflgs
operator|)
operator|!=
literal|1
condition|)
block|{
comment|/* Already confirmed? */
name|x
operator|=
name|getwd
argument_list|()
expr_stmt|;
comment|/* No, get a word */
block|}
else|else
block|{
name|cc
operator|=
name|setatm
argument_list|(
name|xdef
argument_list|)
expr_stmt|;
comment|/* If so, use default, if any. */
block|}
operator|*
name|xp
operator|=
name|atmbuf
expr_stmt|;
comment|/* Point to result. */
while|while
condition|(
literal|1
condition|)
block|{
name|xc
operator|+=
name|cc
expr_stmt|;
comment|/* Count the characters. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"cmfld: getwd"
argument_list|,
name|atmbuf
argument_list|,
name|xc
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" x"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|x
condition|)
block|{
case|case
operator|-
literal|4
case|:
comment|/* EOF */
case|case
operator|-
literal|2
case|:
comment|/* Out of space. */
case|case
operator|-
literal|1
case|:
comment|/* Reparse needed */
return|return
operator|(
name|x
operator|)
return|;
case|case
literal|0
case|:
comment|/* SP or NL */
case|case
literal|1
case|:
if|if
condition|(
name|xc
operator|==
literal|0
condition|)
operator|*
name|xp
operator|=
name|xdef
expr_stmt|;
comment|/* If no input, return default. */
else|else
operator|*
name|xp
operator|=
name|atmbuf
expr_stmt|;
if|if
condition|(
operator|*
operator|*
name|xp
operator|==
name|NUL
condition|)
name|x
operator|=
operator|-
literal|3
expr_stmt|;
comment|/* If field empty, return -3. */
return|return
operator|(
name|x
operator|)
return|;
case|case
literal|2
case|:
comment|/* ESC */
if|if
condition|(
name|xc
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"%s "
argument_list|,
name|xdef
argument_list|)
expr_stmt|;
comment|/* If at beginning of field, */
name|addbuf
argument_list|(
name|xdef
argument_list|)
expr_stmt|;
comment|/* supply default. */
name|cc
operator|=
name|setatm
argument_list|(
name|xdef
argument_list|)
expr_stmt|;
comment|/* Return as if whole field */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* typed, followed by space. */
block|}
else|else
block|{
name|putchar
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
comment|/* Beep if already into field. */
block|}
break|break;
case|case
literal|3
case|:
comment|/* Question mark */
if|if
condition|(
operator|*
name|xhlp
operator|==
name|NUL
condition|)
name|printf
argument_list|(
literal|" Please complete this field"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" %s"
argument_list|,
name|xhlp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n%s%s"
argument_list|,
name|cmprom
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
break|break;
block|}
name|x
operator|=
name|getwd
argument_list|()
expr_stmt|;
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  C M T X T  --  Get a text string, including confirmation  */
end_comment

begin_comment
comment|/*   Print help message 'xhlp' if ? typed, supply default 'xdef' if null   string typed.  Returns     -1 if reparse needed or buffer overflows.     1 otherwise.    with cmflgs set to return code, and xp pointing to result string. */
end_comment

begin_macro
name|cmtxt
argument_list|(
argument|xhlp
argument_list|,
argument|xdef
argument_list|,
argument|xp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|xhlp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|xdef
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|xp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|x
decl_stmt|;
specifier|static
name|int
name|xc
decl_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"cmtxt, cmflgs"
argument_list|,
literal|""
argument_list|,
name|cmflgs
argument_list|)
expr_stmt|;
name|cc
operator|=
literal|0
expr_stmt|;
comment|/* Start atmbuf counter off at 0 */
if|if
condition|(
name|cmflgs
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* If reparsing, */
name|xc
operator|=
name|strlen
argument_list|(
operator|*
name|xp
argument_list|)
expr_stmt|;
comment|/* get back the total text length, */
block|}
else|else
block|{
comment|/* otherwise, */
operator|*
name|xp
operator|=
literal|""
expr_stmt|;
comment|/* start fresh. */
name|xc
operator|=
literal|0
expr_stmt|;
block|}
operator|*
name|atmbuf
operator|=
name|NUL
expr_stmt|;
comment|/* And empty atom buffer. */
if|if
condition|(
operator|(
name|x
operator|=
name|cmflgs
operator|)
operator|!=
literal|1
condition|)
block|{
name|x
operator|=
name|getwd
argument_list|()
expr_stmt|;
comment|/* Get first word. */
operator|*
name|xp
operator|=
name|pp
expr_stmt|;
comment|/* Save pointer to it. */
block|}
while|while
condition|(
literal|1
condition|)
block|{
name|xc
operator|+=
name|cc
expr_stmt|;
comment|/* Char count for all words. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"cmtxt: getwd"
argument_list|,
name|atmbuf
argument_list|,
name|xc
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" x"
argument_list|,
literal|""
argument_list|,
name|x
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|x
condition|)
block|{
case|case
operator|-
literal|4
case|:
comment|/* EOF */
case|case
operator|-
literal|2
case|:
comment|/* Overflow */
case|case
operator|-
literal|1
case|:
comment|/* Deletion */
return|return
operator|(
name|x
operator|)
return|;
case|case
literal|0
case|:
comment|/* Space */
name|xc
operator|++
expr_stmt|;
comment|/* Just count it */
break|break;
case|case
literal|1
case|:
comment|/* CR or LF */
if|if
condition|(
name|xc
operator|==
literal|0
condition|)
operator|*
name|xp
operator|=
name|xdef
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
case|case
literal|2
case|:
comment|/* ESC */
if|if
condition|(
name|xc
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"%s "
argument_list|,
name|xdef
argument_list|)
expr_stmt|;
name|cc
operator|=
name|addbuf
argument_list|(
name|xdef
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|putchar
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|3
case|:
comment|/* Question Mark */
if|if
condition|(
operator|*
name|xhlp
operator|==
name|NUL
condition|)
name|printf
argument_list|(
literal|" Text string"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" %s"
argument_list|,
name|xhlp
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n%s%s"
argument_list|,
name|cmprom
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"\n?Unexpected return code from getwd() - %d\n"
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
name|x
operator|=
name|getwd
argument_list|()
expr_stmt|;
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  C M K E Y  --  Parse a keyword  */
end_comment

begin_comment
comment|/*  Call with:    table    --  keyword table, in 'struct keytab' format;    n        --  number of entries in table;    xhlp     --  pointer to help string;    xdef     --  pointer to default keyword;   Returns:    -3       --  no input supplied and no default available    -2       --  input doesn't uniquely match a keyword in the table    -1       --  user deleted too much, command reparse required     n>= 0  --  value associated with keyword */
end_comment

begin_macro
name|cmkey
argument_list|(
argument|table
argument_list|,
argument|n
argument_list|,
argument|xhlp
argument_list|,
argument|xdef
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|keytab
name|table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|xhlp
decl_stmt|,
modifier|*
name|xdef
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|,
name|zz
decl_stmt|,
name|xc
decl_stmt|;
name|char
modifier|*
name|xp
decl_stmt|;
name|xc
operator|=
name|cc
operator|=
literal|0
expr_stmt|;
comment|/* Clear character counters. */
if|if
condition|(
operator|(
name|zz
operator|=
name|cmflgs
operator|)
operator|==
literal|1
condition|)
comment|/* Command already entered? */
name|setatm
argument_list|(
name|xdef
argument_list|)
expr_stmt|;
else|else
name|zz
operator|=
name|getwd
argument_list|()
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"cmkey: table length"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" cmflgs"
argument_list|,
literal|""
argument_list|,
name|cmflgs
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" zz"
argument_list|,
literal|""
argument_list|,
name|zz
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|xc
operator|+=
name|cc
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"cmkey: getwd"
argument_list|,
name|atmbuf
argument_list|,
name|xc
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|zz
condition|)
block|{
case|case
operator|-
literal|4
case|:
comment|/* EOF */
case|case
operator|-
literal|2
case|:
comment|/* Buffer overflow */
case|case
operator|-
literal|1
case|:
comment|/* Or user did some deleting. */
return|return
operator|(
name|zz
operator|)
return|;
case|case
literal|0
case|:
comment|/* User terminated word with space */
case|case
literal|1
case|:
comment|/* or newline */
if|if
condition|(
name|cc
operator|==
literal|0
condition|)
name|setatm
argument_list|(
name|xdef
argument_list|)
expr_stmt|;
name|y
operator|=
name|lookup
argument_list|(
name|table
argument_list|,
name|atmbuf
argument_list|,
name|n
argument_list|,
operator|&
name|z
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|y
condition|)
block|{
case|case
operator|-
literal|2
case|:
name|printf
argument_list|(
literal|"\n?Ambiguous - %s\n"
argument_list|,
name|atmbuf
argument_list|)
expr_stmt|;
return|return
operator|(
name|cmflgs
operator|=
operator|-
literal|2
operator|)
return|;
case|case
operator|-
literal|1
case|:
name|printf
argument_list|(
literal|"\n?Invalid - %s\n"
argument_list|,
name|atmbuf
argument_list|)
expr_stmt|;
return|return
operator|(
name|cmflgs
operator|=
operator|-
literal|2
operator|)
return|;
default|default:
break|break;
block|}
return|return
operator|(
name|y
operator|)
return|;
comment|/* cont'd... */
comment|/* ...cmkey(), cont'd */
case|case
literal|2
case|:
comment|/* User terminated word with ESC */
if|if
condition|(
name|cc
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|*
name|xdef
operator|!=
name|NUL
condition|)
block|{
comment|/* Nothing in atmbuf */
name|printf
argument_list|(
literal|"%s "
argument_list|,
name|xdef
argument_list|)
expr_stmt|;
comment|/* Supply default if any */
name|addbuf
argument_list|(
name|xdef
argument_list|)
expr_stmt|;
name|cc
operator|=
name|setatm
argument_list|(
name|xdef
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"cmkey: default"
argument_list|,
name|atmbuf
argument_list|,
name|cc
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|putchar
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
comment|/* No default, just beep */
break|break;
block|}
block|}
name|y
operator|=
name|lookup
argument_list|(
name|table
argument_list|,
name|atmbuf
argument_list|,
name|n
argument_list|,
operator|&
name|z
argument_list|)
expr_stmt|;
comment|/* Something in atmbuf */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"cmkey: esc"
argument_list|,
name|atmbuf
argument_list|,
name|y
argument_list|)
expr_stmt|;
if|if
condition|(
name|y
operator|==
operator|-
literal|2
condition|)
block|{
name|putchar
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|y
operator|==
operator|-
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"\n?Invalid - %s\n"
argument_list|,
name|atmbuf
argument_list|)
expr_stmt|;
return|return
operator|(
name|cmflgs
operator|=
operator|-
literal|2
operator|)
return|;
block|}
name|xp
operator|=
name|table
index|[
name|z
index|]
operator|.
name|kwd
operator|+
name|cc
expr_stmt|;
name|printf
argument_list|(
literal|"%s "
argument_list|,
name|xp
argument_list|)
expr_stmt|;
name|addbuf
argument_list|(
name|xp
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"cmkey: addbuf"
argument_list|,
name|cmdbuf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|y
operator|)
return|;
comment|/* cont'd... */
comment|/* ...cmkey(), cont'd */
case|case
literal|3
case|:
comment|/* User terminated word with "?" */
name|y
operator|=
name|lookup
argument_list|(
name|table
argument_list|,
name|atmbuf
argument_list|,
name|n
argument_list|,
operator|&
name|z
argument_list|)
expr_stmt|;
if|if
condition|(
name|y
operator|>
operator|-
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|" %s\n%s%s"
argument_list|,
name|table
index|[
name|z
index|]
operator|.
name|kwd
argument_list|,
name|cmprom
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
break|break;
block|}
elseif|else
if|if
condition|(
name|y
operator|==
operator|-
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"\n?Invalid\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|cmflgs
operator|=
operator|-
literal|2
operator|)
return|;
block|}
if|if
condition|(
operator|*
name|xhlp
operator|==
name|NUL
condition|)
name|printf
argument_list|(
literal|" One of the following:\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|" %s, one of the following:\n"
argument_list|,
name|xhlp
argument_list|)
expr_stmt|;
name|clrhlp
argument_list|()
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|table
index|[
name|i
index|]
operator|.
name|kwd
argument_list|,
name|atmbuf
argument_list|,
name|cc
argument_list|)
operator|&&
operator|!
name|test
argument_list|(
name|table
index|[
name|i
index|]
operator|.
name|flgs
argument_list|,
name|CM_INV
argument_list|)
condition|)
name|addhlp
argument_list|(
name|table
index|[
name|i
index|]
operator|.
name|kwd
argument_list|)
expr_stmt|;
block|}
name|dmphlp
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"%s%s"
argument_list|,
name|cmprom
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"\n%d - Unexpected return code from getwd\n"
argument_list|,
name|zz
argument_list|)
expr_stmt|;
return|return
operator|(
name|cmflgs
operator|=
operator|-
literal|2
operator|)
return|;
block|}
name|zz
operator|=
name|getwd
argument_list|()
expr_stmt|;
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  C M C F M  --  Parse command confirmation (end of line)  */
end_comment

begin_comment
comment|/*  Returns    -2: User typed anything but whitespace or newline    -1: Reparse needed     0: Confirmation was received */
end_comment

begin_macro
name|cmcfm
argument_list|()
end_macro

begin_block
block|{
name|int
name|x
decl_stmt|,
name|xc
decl_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"cmcfm: cmflgs"
argument_list|,
literal|""
argument_list|,
name|cmflgs
argument_list|)
expr_stmt|;
name|xc
operator|=
name|cc
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|cmflgs
operator|==
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
while|while
condition|(
literal|1
condition|)
block|{
name|x
operator|=
name|getwd
argument_list|()
expr_stmt|;
name|xc
operator|+=
name|cc
expr_stmt|;
name|debug
argument_list|(
name|F111
argument_list|,
literal|"cmcfm: getwd"
argument_list|,
name|atmbuf
argument_list|,
name|xc
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|x
condition|)
block|{
case|case
operator|-
literal|4
case|:
comment|/* EOF */
case|case
operator|-
literal|2
case|:
case|case
operator|-
literal|1
case|:
return|return
operator|(
name|x
operator|)
return|;
case|case
literal|0
case|:
comment|/* Space */
continue|continue;
case|case
literal|1
case|:
comment|/* End of line */
if|if
condition|(
name|xc
operator|>
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"?Not confirmed - %s\n"
argument_list|,
name|atmbuf
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
else|else
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|2
case|:
name|putchar
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
continue|continue;
case|case
literal|3
case|:
if|if
condition|(
name|xc
operator|>
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n?Not confirmed - %s\n"
argument_list|,
name|atmbuf
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
name|printf
argument_list|(
literal|"\n Type a carriage return to confirm the command\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s%s"
argument_list|,
name|cmprom
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
continue|continue;
block|}
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* Keyword help routines */
end_comment

begin_comment
comment|/*  C L R H L P -- Initialize/Clear the help line buffer  */
end_comment

begin_macro
name|clrhlp
argument_list|()
end_macro

begin_block
block|{
comment|/* Clear the help buffer */
name|hlpbuf
index|[
literal|0
index|]
operator|=
name|NUL
expr_stmt|;
name|hh
operator|=
name|hx
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  A D D H L P  --  Add a string to the help line buffer  */
end_comment

begin_macro
name|addhlp
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Add a word to the help buffer */
name|int
name|j
decl_stmt|;
name|hh
operator|++
expr_stmt|;
comment|/* Count this column */
for|for
control|(
name|j
operator|=
literal|0
init|;
operator|(
name|j
operator|<
name|hc
operator|)
operator|&&
operator|(
operator|*
name|s
operator|!=
name|NUL
operator|)
condition|;
name|j
operator|++
control|)
block|{
comment|/* Fill the column */
name|hlpbuf
index|[
name|hx
operator|++
index|]
operator|=
operator|*
name|s
operator|++
expr_stmt|;
block|}
if|if
condition|(
operator|*
name|s
operator|!=
name|NUL
condition|)
comment|/* Still some chars left in string? */
name|hlpbuf
index|[
name|hx
operator|-
literal|1
index|]
operator|=
literal|'+'
expr_stmt|;
comment|/* Mark as too long for column. */
if|if
condition|(
name|hh
operator|<
operator|(
name|hw
operator|/
name|hc
operator|)
condition|)
block|{
comment|/* Pad col with spaces if necessary */
for|for
control|(
init|;
name|j
operator|<
name|hc
condition|;
name|j
operator|++
control|)
block|{
name|hlpbuf
index|[
name|hx
operator|++
index|]
operator|=
name|SP
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* If last column, */
name|hlpbuf
index|[
name|hx
operator|++
index|]
operator|=
name|NUL
expr_stmt|;
comment|/* no spaces. */
name|dmphlp
argument_list|()
expr_stmt|;
comment|/* Print it. */
return|return;
block|}
block|}
end_block

begin_comment
comment|/*  D M P H L P  --  Dump the help line buffer  */
end_comment

begin_macro
name|dmphlp
argument_list|()
end_macro

begin_block
block|{
comment|/* Print the help buffer */
name|hlpbuf
index|[
name|hx
operator|++
index|]
operator|=
name|NUL
expr_stmt|;
name|printf
argument_list|(
literal|" %s\n"
argument_list|,
name|hlpbuf
argument_list|)
expr_stmt|;
name|clrhlp
argument_list|()
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  L O O K U P  --  Lookup the string in the given array of strings  */
end_comment

begin_comment
comment|/*  Call this way:  v = lookup(table,word,n,&x);     table - a 'struct keytab' table.    word  - the target string to look up in the table.    n     - the number of elements in the table.    x     - address of an integer for returning the table array index.   The keyword table must be arranged in ascending alphabetical order, and  all letters must be lowercase.   Returns the keyword's associated value ( zero or greater ) if found,  with the variable x set to the array index, or:    -3 if nothing to look up (target was null),   -2 if ambiguous,   -1 if not found.   A match is successful if the target matches a keyword exactly, or if  the target is a prefix of exactly one keyword.  It is ambiguous if the  target matches two or more keywords from the table. */
end_comment

begin_macro
name|lookup
argument_list|(
argument|table
argument_list|,
argument|cmd
argument_list|,
argument|n
argument_list|,
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|keytab
name|table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|n
decl_stmt|,
modifier|*
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|,
name|v
decl_stmt|,
name|cmdlen
decl_stmt|;
comment|/* Lowercase& get length of target, if it's null return code -3. */
if|if
condition|(
operator|(
operator|(
operator|(
name|cmdlen
operator|=
name|lower
argument_list|(
name|cmd
argument_list|)
operator|)
operator|)
operator|==
literal|0
operator|)
operator|||
operator|(
name|n
operator|<
literal|1
operator|)
condition|)
return|return
operator|(
operator|-
literal|3
operator|)
return|;
comment|/* Not null, look it up */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|n
operator|-
literal|1
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|table
index|[
name|i
index|]
operator|.
name|kwd
argument_list|,
name|cmd
argument_list|)
operator|||
operator|(
operator|(
name|v
operator|=
operator|!
name|strncmp
argument_list|(
name|table
index|[
name|i
index|]
operator|.
name|kwd
argument_list|,
name|cmd
argument_list|,
name|cmdlen
argument_list|)
operator|)
operator|&&
name|strncmp
argument_list|(
name|table
index|[
name|i
operator|+
literal|1
index|]
operator|.
name|kwd
argument_list|,
name|cmd
argument_list|,
name|cmdlen
argument_list|)
operator|)
condition|)
block|{
operator|*
name|x
operator|=
name|i
expr_stmt|;
return|return
operator|(
name|table
index|[
name|i
index|]
operator|.
name|val
operator|)
return|;
block|}
if|if
condition|(
name|v
condition|)
return|return
operator|(
operator|-
literal|2
operator|)
return|;
block|}
comment|/* Last (or only) element */
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|table
index|[
name|n
operator|-
literal|1
index|]
operator|.
name|kwd
argument_list|,
name|cmd
argument_list|,
name|cmdlen
argument_list|)
condition|)
block|{
operator|*
name|x
operator|=
name|n
operator|-
literal|1
expr_stmt|;
return|return
operator|(
name|table
index|[
name|n
operator|-
literal|1
index|]
operator|.
name|val
operator|)
return|;
block|}
else|else
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*  G E T W D  --  Gets a "word" from the command input stream  */
end_comment

begin_comment
comment|/* Usage: retcode = getwd();  Returns:  -4 if end of file (e.g. pipe broken)  -2 if command buffer overflows  -1 if user did some deleting   0 if word terminates with SP or tab   1 if ... CR   2 if ... ESC   3 if ... ?  With:   pp pointing to beginning of word in buffer   bp pointing to after current position   atmbuf containing a copy of the word   cc containing the number of characters in the word copied to atmbuf */
end_comment

begin_macro
name|getwd
argument_list|()
end_macro

begin_block
block|{
name|int
name|c
decl_stmt|;
comment|/* Current char */
specifier|static
name|int
name|inword
init|=
literal|0
decl_stmt|;
comment|/* Flag for start of word found */
name|int
name|quote
init|=
literal|0
decl_stmt|;
comment|/* Flag for quote character */
name|int
name|echof
init|=
literal|0
decl_stmt|;
comment|/* Flag for whether to echo */
name|int
name|ignore
init|=
literal|0
decl_stmt|;
name|pp
operator|=
name|np
expr_stmt|;
comment|/* Start of current field */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"getwd: cmdbuf"
argument_list|,
literal|""
argument_list|,
operator|(
name|int
operator|)
name|cmdbuf
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" bp"
argument_list|,
literal|""
argument_list|,
operator|(
name|int
operator|)
name|bp
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|" pp"
argument_list|,
literal|""
argument_list|,
operator|(
name|int
operator|)
name|pp
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|" cmdbuf"
argument_list|,
name|cmdbuf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
while|while
condition|(
name|bp
operator|<
name|cmdbuf
operator|+
name|CMDBL
condition|)
block|{
comment|/* Loop */
name|ignore
operator|=
name|echof
operator|=
literal|0
expr_stmt|;
comment|/* Flag for whether to echo */
if|if
condition|(
operator|(
name|c
operator|=
operator|*
name|bp
operator|)
operator|==
name|NUL
condition|)
block|{
comment|/* Get next character */
if|if
condition|(
name|dpx
condition|)
name|echof
operator|=
literal|1
expr_stmt|;
comment|/* from reparse buffer */
name|c
operator|=
name|getchar
argument_list|()
expr_stmt|;
comment|/* or from tty. */
if|if
condition|(
name|c
operator|==
name|EOF
condition|)
return|return
operator|(
operator|-
literal|4
operator|)
return|;
block|}
else|else
name|ignore
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|quote
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|!
name|ignore
operator|&&
operator|(
name|c
operator|==
literal|'\\'
operator|)
condition|)
block|{
comment|/* Quote character */
name|quote
operator|=
literal|1
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|c
operator|==
name|FF
condition|)
block|{
comment|/* Formfeed. */
name|c
operator|=
name|NL
expr_stmt|;
comment|/* Replace with newline */
name|system
argument_list|(
literal|"clear"
argument_list|)
expr_stmt|;
comment|/* and clear the screen. */
block|}
if|if
condition|(
name|c
operator|==
name|HT
condition|)
name|c
operator|=
name|SP
expr_stmt|;
comment|/* Substitute space for tab. */
comment|/* cont'd... */
comment|/* ...getwd(), cont'd */
if|if
condition|(
name|c
operator|==
name|SP
condition|)
block|{
comment|/* If space */
operator|*
name|bp
operator|++
operator|=
name|c
expr_stmt|;
comment|/* deposit it in buffer. */
if|if
condition|(
name|echof
condition|)
name|putchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* echo it. */
if|if
condition|(
name|inword
operator|==
literal|0
condition|)
block|{
comment|/* If leading, gobble it. */
name|pp
operator|++
expr_stmt|;
continue|continue;
block|}
else|else
block|{
comment|/* If terminating, return. */
name|np
operator|=
name|bp
expr_stmt|;
name|setatm
argument_list|(
name|pp
argument_list|)
expr_stmt|;
name|inword
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|cmflgs
operator|=
literal|0
operator|)
return|;
block|}
block|}
if|if
condition|(
name|c
operator|==
name|NL
operator|||
name|c
operator|==
name|CR
condition|)
block|{
comment|/* CR, LF */
operator|*
name|bp
operator|=
name|NUL
expr_stmt|;
comment|/* End the string */
if|if
condition|(
name|echof
condition|)
block|{
comment|/* If echoing, */
name|putchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* echo the typein */
ifdef|#
directive|ifdef
name|aegis
if|if
condition|(
name|c
operator|==
name|CR
condition|)
name|putchar
argument_list|(
name|NL
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|np
operator|=
name|bp
expr_stmt|;
comment|/* Where to start next field. */
name|setatm
argument_list|(
name|pp
argument_list|)
expr_stmt|;
comment|/* Copy this field to atom buffer. */
name|inword
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|cmflgs
operator|=
literal|1
operator|)
return|;
block|}
if|if
condition|(
operator|!
name|ignore
operator|&&
operator|(
name|c
operator|==
literal|'?'
operator|)
condition|)
block|{
comment|/* Question mark */
name|putchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
operator|*
name|bp
operator|=
name|NUL
expr_stmt|;
name|setatm
argument_list|(
name|pp
argument_list|)
expr_stmt|;
return|return
operator|(
name|cmflgs
operator|=
literal|3
operator|)
return|;
block|}
if|if
condition|(
name|c
operator|==
name|ESC
condition|)
block|{
comment|/* ESC */
operator|*
name|bp
operator|=
name|NUL
expr_stmt|;
name|setatm
argument_list|(
name|pp
argument_list|)
expr_stmt|;
return|return
operator|(
name|cmflgs
operator|=
literal|2
operator|)
return|;
block|}
if|if
condition|(
name|c
operator|==
name|BS
operator|||
name|c
operator|==
name|RUB
condition|)
block|{
comment|/* Character deletion */
if|if
condition|(
name|bp
operator|>
name|cmdbuf
condition|)
block|{
comment|/* If still in buffer... */
name|printf
argument_list|(
literal|"\b \b"
argument_list|)
expr_stmt|;
comment|/* erase character from screen, */
name|bp
operator|--
expr_stmt|;
comment|/* point behind it, */
if|if
condition|(
operator|*
name|bp
operator|==
name|SP
condition|)
name|inword
operator|=
literal|0
expr_stmt|;
comment|/* Flag if current field gone */
operator|*
name|bp
operator|=
name|NUL
expr_stmt|;
comment|/* Erase character from buffer. */
block|}
else|else
block|{
comment|/* Otherwise, */
name|putchar
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
comment|/* beep, */
name|cmres
argument_list|()
expr_stmt|;
comment|/* and start parsing a new command. */
block|}
if|if
condition|(
name|pp
operator|<
name|bp
condition|)
continue|continue;
else|else
return|return
operator|(
name|cmflgs
operator|=
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|c
operator|==
name|LDEL
condition|)
block|{
comment|/* ^U, line deletion */
while|while
condition|(
operator|(
name|bp
operator|--
operator|)
operator|>
name|cmdbuf
condition|)
block|{
name|printf
argument_list|(
literal|"\b \b"
argument_list|)
expr_stmt|;
operator|*
name|bp
operator|=
name|NUL
expr_stmt|;
block|}
name|cmres
argument_list|()
expr_stmt|;
comment|/* Restart the command. */
name|inword
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|cmflgs
operator|=
operator|-
literal|1
operator|)
return|;
block|}
comment|/* cont'd... */
comment|/* ...getwd(), cont'd */
if|if
condition|(
name|c
operator|==
name|WDEL
condition|)
block|{
comment|/* ^W, word deletion */
if|if
condition|(
name|bp
operator|<=
name|cmdbuf
condition|)
block|{
comment|/* Beep if nothing to delete */
name|putchar
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
name|cmres
argument_list|()
expr_stmt|;
return|return
operator|(
name|cmflgs
operator|=
operator|-
literal|1
operator|)
return|;
block|}
name|bp
operator|--
expr_stmt|;
for|for
control|(
init|;
operator|(
name|bp
operator|>=
name|cmdbuf
operator|)
operator|&&
operator|(
operator|*
name|bp
operator|==
name|SP
operator|)
condition|;
name|bp
operator|--
control|)
block|{
name|printf
argument_list|(
literal|"\b \b"
argument_list|)
expr_stmt|;
operator|*
name|bp
operator|=
name|NUL
expr_stmt|;
block|}
for|for
control|(
init|;
operator|(
name|bp
operator|>=
name|cmdbuf
operator|)
operator|&&
operator|(
operator|*
name|bp
operator|!=
name|SP
operator|)
condition|;
name|bp
operator|--
control|)
block|{
name|printf
argument_list|(
literal|"\b \b"
argument_list|)
expr_stmt|;
operator|*
name|bp
operator|=
name|NUL
expr_stmt|;
block|}
name|bp
operator|++
expr_stmt|;
name|inword
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|cmflgs
operator|=
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|c
operator|==
name|RDIS
condition|)
block|{
comment|/* ^R, redisplay */
operator|*
name|bp
operator|=
name|NUL
expr_stmt|;
name|printf
argument_list|(
literal|"\n%s%s"
argument_list|,
name|cmprom
argument_list|,
name|cmdbuf
argument_list|)
expr_stmt|;
continue|continue;
block|}
block|}
if|if
condition|(
name|echof
condition|)
name|putchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* If tty input, echo. */
name|inword
operator|=
literal|1
expr_stmt|;
comment|/* Flag we're in a word. */
if|if
condition|(
name|quote
operator|==
literal|0
operator|||
name|c
operator|!=
name|NL
condition|)
operator|*
name|bp
operator|++
operator|=
name|c
expr_stmt|;
comment|/* And deposit it. */
name|quote
operator|=
literal|0
expr_stmt|;
comment|/* Turn off quote. */
block|}
comment|/* end of big while */
name|putchar
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
comment|/* Get here if... */
name|printf
argument_list|(
literal|"\n?Buffer full\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|cmflgs
operator|=
operator|-
literal|2
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* Utility functions */
end_comment

begin_comment
comment|/* A D D B U F  -- Add the string pointed to by cp to the command buffer  */
end_comment

begin_macro
name|addbuf
argument_list|(
argument|cp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|len
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|(
operator|*
name|cp
operator|!=
name|NUL
operator|)
operator|&&
operator|(
name|bp
operator|<
name|cmdbuf
operator|+
name|CMDBL
operator|)
condition|)
block|{
operator|*
name|bp
operator|++
operator|=
operator|*
name|cp
operator|++
expr_stmt|;
comment|/* Copy and */
name|len
operator|++
expr_stmt|;
comment|/* count the characters. */
block|}
operator|*
name|bp
operator|++
operator|=
name|SP
expr_stmt|;
comment|/* Put a space at the end */
operator|*
name|bp
operator|=
name|NUL
expr_stmt|;
comment|/* Terminate with a null */
name|np
operator|=
name|bp
expr_stmt|;
comment|/* Update the next-field pointer */
return|return
operator|(
name|len
operator|)
return|;
comment|/* Return the length */
block|}
end_block

begin_comment
comment|/*  S E T A T M  --  Deposit a string in the atom buffer  */
end_comment

begin_macro
name|setatm
argument_list|(
argument|cp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|ap
decl_stmt|;
name|cc
operator|=
literal|0
expr_stmt|;
name|ap
operator|=
name|atmbuf
expr_stmt|;
operator|*
name|ap
operator|=
name|NUL
expr_stmt|;
while|while
condition|(
operator|*
name|cp
operator|==
name|SP
condition|)
name|cp
operator|++
expr_stmt|;
while|while
condition|(
operator|(
operator|*
name|cp
operator|!=
name|SP
operator|)
operator|&&
operator|(
operator|*
name|cp
operator|!=
name|NL
operator|)
operator|&&
operator|(
operator|*
name|cp
operator|!=
name|NUL
operator|)
operator|&&
operator|(
operator|*
name|cp
operator|!=
name|CR
operator|)
condition|)
block|{
operator|*
name|ap
operator|++
operator|=
operator|*
name|cp
operator|++
expr_stmt|;
name|cc
operator|++
expr_stmt|;
block|}
operator|*
name|ap
operator|++
operator|=
name|NUL
expr_stmt|;
return|return
operator|(
name|cc
operator|)
return|;
comment|/* Return length */
block|}
end_block

begin_comment
comment|/*  D I G I T S  -- Verify that all the characters in line are digits  */
end_comment

begin_macro
name|digits
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
operator|*
name|s
condition|)
block|{
if|if
condition|(
operator|!
name|isdigit
argument_list|(
operator|*
name|s
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|s
operator|++
expr_stmt|;
block|}
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  L O W E R  --  Lowercase a string  */
end_comment

begin_macro
name|lower
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|n
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|*
name|s
condition|)
block|{
if|if
condition|(
name|isupper
argument_list|(
operator|*
name|s
argument_list|)
condition|)
operator|*
name|s
operator|=
name|tolower
argument_list|(
operator|*
name|s
argument_list|)
expr_stmt|;
name|s
operator|++
operator|,
name|n
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|n
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  T E S T  --  Bit test  */
end_comment

begin_macro
name|test
argument_list|(
argument|x
argument_list|,
argument|m
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x
decl_stmt|,
name|m
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/*  Returns 1 if any bits from m are on in x, else 0  */
return|return
operator|(
operator|(
name|x
operator|&
name|m
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_block

end_unit

