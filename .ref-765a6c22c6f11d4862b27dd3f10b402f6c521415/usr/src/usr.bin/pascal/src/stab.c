begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1980 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)stab.c 1.9 %G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	procedures to put out sdb symbol table information.      *	and stabs for separate compilation type checking.      *	these use the new .stabs, .stabn, and .stabd directives      */
end_comment

begin_include
include|#
directive|include
file|"whoami.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PC
end_ifdef

begin_comment
comment|/*	and the rest of the file */
end_comment

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_include
include|#
directive|include
file|"objfmt.h"
end_include

begin_include
include|#
directive|include
file|"yy.h"
end_include

begin_include
include|#
directive|include
file|<stab.h>
end_include

begin_comment
comment|/*      *  additional symbol definition for<stab.h>      *	that is used by the separate compilation facility --      *	eventually,<stab.h> should be updated to include this       */
end_comment

begin_include
include|#
directive|include
file|"pstab.h"
end_include

begin_include
include|#
directive|include
file|"pc.h"
end_include

begin_comment
comment|/*      *	absolute value: line numbers are negative if error recovery.      */
end_comment

begin_define
define|#
directive|define
name|ABS
parameter_list|(
name|x
parameter_list|)
value|( x< 0 ? -x : x )
end_define

begin_comment
comment|/*      *	global variables      */
end_comment

begin_macro
name|stabgvar
argument_list|(
argument|name
argument_list|,
argument|type
argument_list|,
argument|offset
argument_list|,
argument|length
argument_list|,
argument|line
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|length
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	     *	for separate compilation 	     */
name|putprintf
argument_list|(
literal|"	.stabs	\"%s\",0x%x,0,0x%x,0x%x"
argument_list|,
literal|0
argument_list|,
name|name
argument_list|,
name|N_PC
argument_list|,
name|N_PGVAR
argument_list|,
name|ABS
argument_list|(
name|line
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	     *	for sdb 	     */
if|if
condition|(
operator|!
name|opt
argument_list|(
literal|'g'
argument_list|)
condition|)
block|{
return|return;
block|}
name|putprintf
argument_list|(
literal|"	.stabs	\""
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
name|NAMEFORMAT
argument_list|,
literal|1
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|"\",0x%x,0,0x%x,0"
argument_list|,
literal|0
argument_list|,
name|N_GSYM
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|"	.stabs	\""
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
name|NAMEFORMAT
argument_list|,
literal|1
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|"\",0x%x,0,0,0x%x"
argument_list|,
literal|0
argument_list|,
name|N_LENG
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*      *	local variables      */
end_comment

begin_macro
name|stablvar
argument_list|(
argument|name
argument_list|,
argument|type
argument_list|,
argument|level
argument_list|,
argument|offset
argument_list|,
argument|length
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|length
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|opt
argument_list|(
literal|'g'
argument_list|)
condition|)
block|{
return|return;
block|}
name|putprintf
argument_list|(
literal|"	.stabs	\""
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
name|NAMEFORMAT
argument_list|,
literal|1
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|"\",0x%x,0,0x%x,0x%x"
argument_list|,
literal|0
argument_list|,
name|N_LSYM
argument_list|,
name|type
argument_list|,
operator|-
name|offset
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|"	.stabs	\""
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
name|NAMEFORMAT
argument_list|,
literal|1
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|"\",0x%x,0,0,0x%x"
argument_list|,
literal|0
argument_list|,
name|N_LENG
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*      *	parameters      */
end_comment

begin_macro
name|stabparam
argument_list|(
argument|name
argument_list|,
argument|type
argument_list|,
argument|offset
argument_list|,
argument|length
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|length
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|opt
argument_list|(
literal|'g'
argument_list|)
condition|)
block|{
return|return;
block|}
name|putprintf
argument_list|(
literal|"	.stabs	\""
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
name|NAMEFORMAT
argument_list|,
literal|1
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|"\",0x%x,0,0x%x,0x%x"
argument_list|,
literal|0
argument_list|,
name|N_PSYM
argument_list|,
name|type
argument_list|,
name|offset
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|"	.stabs	\""
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
name|NAMEFORMAT
argument_list|,
literal|1
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|"\",0x%x,0,0,0x%x"
argument_list|,
literal|0
argument_list|,
name|N_LENG
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*      *	fields      */
end_comment

begin_macro
name|stabfield
argument_list|(
argument|name
argument_list|,
argument|type
argument_list|,
argument|offset
argument_list|,
argument|length
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|length
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|opt
argument_list|(
literal|'g'
argument_list|)
condition|)
block|{
return|return;
block|}
name|putprintf
argument_list|(
literal|"	.stabs	\""
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
name|NAMEFORMAT
argument_list|,
literal|1
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|"\",0x%x,0,0x%x,0x%x"
argument_list|,
literal|0
argument_list|,
name|N_SSYM
argument_list|,
name|type
argument_list|,
name|offset
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|"	.stabs	\""
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
name|NAMEFORMAT
argument_list|,
literal|1
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|"\",0x%x,0,0,0x%x"
argument_list|,
literal|0
argument_list|,
name|N_LENG
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*      *	left brackets      */
end_comment

begin_macro
name|stablbrac
argument_list|(
argument|level
argument_list|)
end_macro

begin_decl_stmt
name|int
name|level
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|opt
argument_list|(
literal|'g'
argument_list|)
condition|)
block|{
return|return;
block|}
name|putprintf
argument_list|(
literal|"	.stabd	0x%x,0,0x%x"
argument_list|,
literal|0
argument_list|,
name|N_LBRAC
argument_list|,
name|level
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*      *	right brackets      */
end_comment

begin_macro
name|stabrbrac
argument_list|(
argument|level
argument_list|)
end_macro

begin_decl_stmt
name|int
name|level
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|opt
argument_list|(
literal|'g'
argument_list|)
condition|)
block|{
return|return;
block|}
name|putprintf
argument_list|(
literal|"	.stabd	0x%x,0,0x%x"
argument_list|,
literal|0
argument_list|,
name|N_RBRAC
argument_list|,
name|level
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*      *	functions      */
end_comment

begin_macro
name|stabfunc
argument_list|(
argument|name
argument_list|,
argument|typeclass
argument_list|,
argument|line
argument_list|,
argument|level
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|typeclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|level
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|type
decl_stmt|;
name|long
name|i
decl_stmt|;
name|char
name|extname
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* 	     *	for separate compilation 	     */
if|if
condition|(
name|level
operator|==
literal|1
condition|)
block|{
if|if
condition|(
name|typeclass
operator|==
name|FUNC
condition|)
block|{
name|putprintf
argument_list|(
literal|"	.stabs	\"%s\",0x%x,0,0x%x,0x%x"
argument_list|,
literal|0
argument_list|,
name|name
argument_list|,
name|N_PC
argument_list|,
name|N_PGFUNC
argument_list|,
name|ABS
argument_list|(
name|line
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|typeclass
operator|==
name|PROC
condition|)
block|{
name|putprintf
argument_list|(
literal|"	.stabs	\"%s\",0x%x,0,0x%x,0x%x"
argument_list|,
literal|0
argument_list|,
name|name
argument_list|,
name|N_PC
argument_list|,
name|N_PGPROC
argument_list|,
name|ABS
argument_list|(
name|line
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* 	     *	for sdb 	     */
if|if
condition|(
operator|!
name|opt
argument_list|(
literal|'g'
argument_list|)
condition|)
block|{
return|return;
block|}
name|putprintf
argument_list|(
literal|"	.stabs	\""
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
name|NAMEFORMAT
argument_list|,
literal|1
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|sextname
argument_list|(
name|extname
argument_list|,
name|name
argument_list|,
name|level
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|"\",0x%x,0,0x%x,%s"
argument_list|,
literal|0
argument_list|,
name|N_FUN
argument_list|,
name|line
argument_list|,
name|extname
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*      *	source line numbers      */
end_comment

begin_macro
name|stabline
argument_list|(
argument|line
argument_list|)
end_macro

begin_decl_stmt
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|opt
argument_list|(
literal|'g'
argument_list|)
condition|)
block|{
return|return;
block|}
name|putprintf
argument_list|(
literal|"	.stabd	0x%x,0,0x%x"
argument_list|,
literal|0
argument_list|,
name|N_SLINE
argument_list|,
name|ABS
argument_list|(
name|line
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*      *	source files      */
end_comment

begin_macro
name|stabsource
argument_list|(
argument|filename
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|filename
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|label
decl_stmt|;
comment|/* 	 *	for separate compilation 	 */
name|putprintf
argument_list|(
literal|"	.stabs	\"%s\",0x%x,0,0x%x,0x%x"
argument_list|,
literal|0
argument_list|,
name|filename
argument_list|,
name|N_PC
argument_list|,
name|N_PSO
argument_list|,
name|N_FLAGCHECKSUM
argument_list|)
expr_stmt|;
comment|/* 	 *	for sdb 	 */
if|if
condition|(
operator|!
name|opt
argument_list|(
literal|'g'
argument_list|)
condition|)
block|{
return|return;
block|}
name|label
operator|=
name|getlab
argument_list|()
expr_stmt|;
name|putprintf
argument_list|(
literal|"	.stabs	\""
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
name|NAMEFORMAT
argument_list|,
literal|1
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|"\",0x%x,0,0,"
argument_list|,
literal|1
argument_list|,
name|N_SO
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
name|PREFIXFORMAT
argument_list|,
literal|0
argument_list|,
name|LLABELPREFIX
argument_list|,
name|label
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
name|PREFIXFORMAT
argument_list|,
literal|1
argument_list|,
name|LLABELPREFIX
argument_list|,
name|label
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|":"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*      *	included files get one or more of these:      *	one as they are entered by a #include,      *	and one every time they are returned to from nested #includes.      */
end_comment

begin_macro
name|stabinclude
argument_list|(
argument|filename
argument_list|,
argument|firsttime
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|filename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|firsttime
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|label
decl_stmt|;
name|long
name|check
decl_stmt|;
comment|/* 	 *	for separate compilation 	 */
if|if
condition|(
name|firsttime
condition|)
block|{
name|check
operator|=
name|checksum
argument_list|(
name|filename
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|check
operator|=
name|N_FLAGCHECKSUM
expr_stmt|;
block|}
name|putprintf
argument_list|(
literal|"	.stabs	\"%s\",0x%x,0,0x%x,0x%x"
argument_list|,
literal|0
argument_list|,
name|filename
argument_list|,
name|N_PC
argument_list|,
name|N_PSOL
argument_list|,
name|check
argument_list|)
expr_stmt|;
comment|/* 	 *	for sdb 	 */
if|if
condition|(
operator|!
name|opt
argument_list|(
literal|'g'
argument_list|)
condition|)
block|{
return|return;
block|}
name|label
operator|=
name|getlab
argument_list|()
expr_stmt|;
name|putprintf
argument_list|(
literal|"	.stabs	\""
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
name|NAMEFORMAT
argument_list|,
literal|1
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|"\",0x%x,0,0,"
argument_list|,
literal|1
argument_list|,
name|N_SOL
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
name|PREFIXFORMAT
argument_list|,
literal|0
argument_list|,
name|LLABELPREFIX
argument_list|,
name|label
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
name|PREFIXFORMAT
argument_list|,
literal|1
argument_list|,
name|LLABELPREFIX
argument_list|,
name|label
argument_list|)
expr_stmt|;
name|putprintf
argument_list|(
literal|":"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*      *	anyone know a good checksum for ascii files?      *	this does a rotate-left and then exclusive-or's in the character.      *	also, it avoids returning checksums of 0.      *	The rotate is implemented by shifting and adding back the      *	sign bit when negative.      */
end_comment

begin_function
name|long
name|checksum
parameter_list|(
name|filename
parameter_list|)
name|char
modifier|*
name|filename
decl_stmt|;
block|{
name|FILE
modifier|*
name|filep
decl_stmt|;
specifier|register
name|int
name|input
decl_stmt|;
specifier|register
name|long
name|check
decl_stmt|;
name|filep
operator|=
name|fopen
argument_list|(
name|filename
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
if|if
condition|(
name|filep
operator|==
name|NULL
condition|)
block|{
name|perror
argument_list|(
name|filename
argument_list|)
expr_stmt|;
name|pexit
argument_list|(
name|DIED
argument_list|)
expr_stmt|;
block|}
name|check
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|input
operator|=
name|getc
argument_list|(
name|filep
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
block|{
if|if
condition|(
name|check
operator|<
literal|0
condition|)
block|{
name|check
operator|<<=
literal|1
expr_stmt|;
name|check
operator|+=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|check
operator|<<=
literal|1
expr_stmt|;
block|}
name|check
operator|^=
name|input
expr_stmt|;
block|}
name|fclose
argument_list|(
name|filep
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|unsigned
operator|)
name|check
operator|<=
name|N_FLAGCHECKSUM
condition|)
block|{
return|return
name|N_FLAGCHECKSUM
operator|+
literal|1
return|;
block|}
else|else
block|{
return|return
name|check
return|;
block|}
block|}
end_function

begin_comment
comment|/*  * global Pascal symbols :  *   labels, types, constants, and external procedure and function names:  *   These are used by the separate compilation facility  *   to be able to check for disjoint header files.  */
end_comment

begin_comment
comment|/*      *	global labels      */
end_comment

begin_macro
name|stabglabel
argument_list|(
argument|label
argument_list|,
argument|line
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|label
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|putprintf
argument_list|(
literal|"	.stabs	\"%s\",0x%x,0,0x%x,0x%x"
argument_list|,
literal|0
argument_list|,
name|label
argument_list|,
name|N_PC
argument_list|,
name|N_PGLABEL
argument_list|,
name|ABS
argument_list|(
name|line
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*      *	global constants      */
end_comment

begin_macro
name|stabgconst
argument_list|(
argument|const
argument_list|,
argument|line
argument_list|)
end_macro

begin_expr_stmt
name|char
operator|*
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|putprintf
argument_list|(
literal|"	.stabs	\"%s\",0x%x,0,0x%x,0x%x"
argument_list|,
literal|0
argument_list|,
specifier|const
argument_list|,
name|N_PC
argument_list|,
name|N_PGCONST
argument_list|,
name|ABS
argument_list|(
name|line
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*      *	global types      */
end_comment

begin_macro
name|stabgtype
argument_list|(
argument|type
argument_list|,
argument|line
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|putprintf
argument_list|(
literal|"	.stabs	\"%s\",0x%x,0,0x%x,0x%x"
argument_list|,
literal|0
argument_list|,
name|type
argument_list|,
name|N_PC
argument_list|,
name|N_PGTYPE
argument_list|,
name|ABS
argument_list|(
name|line
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*      *	external functions and procedures      */
end_comment

begin_macro
name|stabefunc
argument_list|(
argument|name
argument_list|,
argument|typeclass
argument_list|,
argument|line
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|typeclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|type
decl_stmt|;
if|if
condition|(
name|typeclass
operator|==
name|FUNC
condition|)
block|{
name|type
operator|=
name|N_PEFUNC
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|typeclass
operator|==
name|PROC
condition|)
block|{
name|type
operator|=
name|N_PEPROC
expr_stmt|;
block|}
else|else
block|{
return|return;
block|}
name|putprintf
argument_list|(
literal|"	.stabs	\"%s\",0x%x,0,0x%x,0x%x"
argument_list|,
literal|0
argument_list|,
name|name
argument_list|,
name|N_PC
argument_list|,
name|type
argument_list|,
name|ABS
argument_list|(
name|line
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
endif|PC
end_endif

end_unit

