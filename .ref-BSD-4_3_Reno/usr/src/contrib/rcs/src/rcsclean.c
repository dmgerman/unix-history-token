begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *                     RCS rcsclean operation  */
end_comment

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Header $ Purdue CS"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*****************************************************************************  *                       remove unneded working files  *****************************************************************************  */
end_comment

begin_comment
comment|/* Copyright (C) 1982, 1988, 1989 Walter Tichy  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Walter Tichy.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * Report all problems and direct all questions to:  *   rcs-bugs@cs.purdue.edu  *         */
end_comment

begin_comment
comment|/* $Log:	rcsclean.c,v $  * Revision 4.4  89/05/01  15:12:21  narten  * changed copyright header to reflect current distribution rules  *   * Revision 4.3  88/11/08  15:59:54  narten  * removed reference to TARGETDIR  *   * Revision 4.2  87/10/18  10:30:43  narten  * Updating version numbers. Changes relative to 1.1 are actually  * relative to 4.1  *   * Revision 1.2  87/09/24  13:59:13  narten  * Sources now pass through lint (if you ignore printf/sprintf/fprintf   * warnings)  *   * Revision 1.1  84/01/23  14:50:16  kcs  * Initial revision  *   * Revision 4.1  83/12/15  12:26:18  wft  * Initial revision.  *   */
end_comment

begin_include
include|#
directive|include
file|"rcsbase.h"
end_include

begin_define
define|#
directive|define
name|ERRCODE
value|2
end_define

begin_comment
comment|/*error code for exit status            */
end_comment

begin_decl_stmt
specifier|static
name|char
name|rcsbaseid
index|[]
init|=
name|RCSBASE
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|cleanup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* cleanup after signals                */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|mktempfile
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*temporary file name generator         */
end_comment

begin_function_decl
specifier|extern
name|int
name|fterror
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*forward for special fatal error func. */
end_comment

begin_function_decl
specifier|extern
name|struct
name|hshentry
modifier|*
name|genrevs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*generate delta numbers                */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nerror
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*counter for errors                    */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|quietflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*suppresses diagnostics                */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|finptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RCS input file                       */
end_comment

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|fopen
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|RCSfilename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|workfilename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tempfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|file1
decl_stmt|,
modifier|*
name|file2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*file descriptors for comparison       */
end_comment

begin_function
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
name|char
modifier|*
name|cmdusage
decl_stmt|;
name|char
name|command
index|[
name|NCPPN
operator|+
name|revlength
operator|+
literal|40
index|]
decl_stmt|;
name|char
modifier|*
name|rev
decl_stmt|;
comment|/* revision number from command line  */
name|char
name|numericrev
index|[
name|revlength
index|]
decl_stmt|;
comment|/* holds expanded revision number     */
name|int
name|revnums
decl_stmt|;
comment|/* number of -r options               */
name|struct
name|hshentry
modifier|*
name|gendeltas
index|[
name|hshsize
index|]
decl_stmt|;
comment|/*stores deltas to be generated*/
name|struct
name|hshentry
modifier|*
name|target
decl_stmt|;
name|int
name|filecounter
decl_stmt|;
specifier|register
name|int
name|c1
decl_stmt|;
comment|/* reading input                      */
name|int
name|result
decl_stmt|;
comment|/* result of comparison               */
name|int
name|pairresult
decl_stmt|;
comment|/* reulst of pairfilenames            */
name|catchints
argument_list|()
expr_stmt|;
name|cmdid
operator|=
literal|"rcsclean"
expr_stmt|;
name|cmdusage
operator|=
literal|"command format:\n    rcsclean [-rrev] file"
expr_stmt|;
name|filecounter
operator|=
name|revnums
operator|=
literal|0
expr_stmt|;
name|quietflag
operator|=
name|true
expr_stmt|;
comment|/* default no diagnostics */
while|while
condition|(
operator|--
name|argc
operator|,
operator|++
name|argv
operator|,
name|argc
operator|>=
literal|1
operator|&&
operator|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|0
index|]
operator|==
literal|'-'
operator|)
condition|)
block|{
switch|switch
condition|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|1
index|]
condition|)
block|{
case|case
literal|'r'
case|:
name|revno
label|:
if|if
condition|(
operator|(
operator|*
name|argv
operator|)
index|[
literal|2
index|]
operator|!=
literal|'\0'
condition|)
block|{
if|if
condition|(
name|revnums
operator|==
literal|0
condition|)
block|{
name|rev
operator|=
operator|*
name|argv
operator|+
literal|2
expr_stmt|;
name|revnums
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|fterror
argument_list|(
literal|"too many revision numbers"
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* do nothing for empty -r */
break|break;
case|case
literal|'D'
case|:
comment|/* debug option */
name|quietflag
operator|=
name|false
expr_stmt|;
break|break;
default|default:
name|fterror
argument_list|(
literal|"unknown option: %s\n%s"
argument_list|,
operator|*
name|argv
argument_list|,
name|cmdusage
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|/* end of option processing */
if|if
condition|(
name|argc
operator|<
literal|1
condition|)
name|fterror
argument_list|(
literal|"No input file\n%s"
argument_list|,
name|cmdusage
argument_list|)
expr_stmt|;
comment|/* now handle all filenames */
do|do
block|{
name|finptr
operator|=
name|NULL
expr_stmt|;
name|pairresult
operator|=
name|pairfilenames
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|false
argument_list|,
name|false
argument_list|)
expr_stmt|;
if|if
condition|(
name|pairresult
operator|==
literal|0
condition|)
continue|continue;
comment|/* error */
if|if
condition|(
operator|!
operator|(
name|access
argument_list|(
name|workfilename
argument_list|,
literal|4
argument_list|)
operator|==
literal|0
operator|)
condition|)
block|{
name|diagnose
argument_list|(
literal|"Can't open %s"
argument_list|,
name|workfilename
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|elsif
argument_list|(
argument|pairresult == -
literal|1
argument_list|)
block|{
name|warn
argument_list|(
literal|"Can't find RCS file for %s"
argument_list|,
name|workfilename
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|diagnose
argument_list|(
literal|"RCS file: %s"
argument_list|,
name|RCSfilename
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|trysema
argument_list|(
name|RCSfilename
argument_list|,
name|false
argument_list|)
condition|)
continue|continue;
comment|/* give up */
name|gettree
argument_list|()
expr_stmt|;
comment|/* reads in the delta tree */
if|if
condition|(
name|Head
operator|==
name|nil
condition|)
block|{
name|error
argument_list|(
literal|"no revisions present"
argument_list|)
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|revnums
operator|==
literal|0
condition|)
name|rev
operator|=
operator|(
name|Dbranch
operator|!=
name|nil
condition|?
name|Dbranch
operator|->
name|num
else|:
name|Head
operator|->
name|num
operator|)
expr_stmt|;
comment|/* default rev1 */
if|if
condition|(
operator|!
name|expandsym
argument_list|(
name|rev
argument_list|,
name|numericrev
argument_list|)
condition|)
continue|continue;
if|if
condition|(
operator|!
operator|(
name|target
operator|=
name|genrevs
argument_list|(
name|numericrev
argument_list|,
name|nil
argument_list|,
name|nil
argument_list|,
name|nil
argument_list|,
name|gendeltas
argument_list|)
operator|)
condition|)
continue|continue;
name|tempfile
operator|=
name|mktempfile
argument_list|(
literal|"/tmp/"
argument_list|,
name|TMPFILE1
argument_list|)
expr_stmt|;
name|diagnose
argument_list|(
literal|"retrieving revision %s"
argument_list|,
name|target
operator|->
name|num
argument_list|)
expr_stmt|;
name|VOID
name|sprintf
argument_list|(
name|command
argument_list|,
literal|"%s -q -p%s %s> %s\n"
argument_list|,
name|CO
argument_list|,
name|target
operator|->
name|num
argument_list|,
name|RCSfilename
argument_list|,
name|tempfile
argument_list|)
decl_stmt|;
if|if
condition|(
name|system
argument_list|(
name|command
argument_list|)
condition|)
block|{
name|error
argument_list|(
literal|"co failed"
argument_list|)
expr_stmt|;
continue|continue;
block|}
comment|/* now do comparison */
if|if
condition|(
operator|(
name|file1
operator|=
name|fopen
argument_list|(
name|tempfile
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|error
argument_list|(
literal|"Can't open checked out file %s"
argument_list|,
name|tempfile
argument_list|)
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
operator|(
name|file2
operator|=
name|fopen
argument_list|(
name|workfilename
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|error
argument_list|(
literal|"Can't open %s"
argument_list|,
name|workfilename
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|result
operator|=
literal|1
expr_stmt|;
while|while
condition|(
operator|(
name|c1
operator|=
name|getc
argument_list|(
name|file1
argument_list|)
operator|)
operator|==
name|getc
argument_list|(
name|file2
argument_list|)
condition|)
block|{
if|if
condition|(
name|c1
operator|==
name|EOF
condition|)
block|{
comment|/* identical files; can remove working file */
name|result
operator|=
literal|0
expr_stmt|;
name|diagnose
argument_list|(
literal|"files identical; %s removed"
argument_list|,
name|workfilename
argument_list|)
expr_stmt|;
if|if
condition|(
name|unlink
argument_list|(
name|workfilename
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|error
argument_list|(
literal|"Can't unlink %s"
argument_list|,
name|workfilename
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
block|}
name|fclose
argument_list|(
name|file1
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|file2
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|==
literal|1
condition|)
name|diagnose
argument_list|(
literal|"files different"
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|cleanup
argument_list|()
operator|,
operator|++
name|argv
operator|,
operator|--
name|argc
operator|>=
literal|1
condition|)
do|;
if|if
condition|(
name|nerror
operator|>
literal|0
condition|)
block|{
name|exit
argument_list|(
name|ERRCODE
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|exit
argument_list|(
name|result
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_macro
name|fterror
argument_list|(
argument|e
argument_list|,
argument|e1
argument_list|,
argument|e2
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|e
decl_stmt|,
modifier|*
name|e1
decl_stmt|,
modifier|*
name|e2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prints error message and terminates program with ERRCODE */
end_comment

begin_block
block|{
name|nerror
operator|++
expr_stmt|;
name|VOID
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s error: "
argument_list|,
name|cmdid
argument_list|)
decl_stmt|;
name|VOID
name|fprintf
parameter_list|(
name|stderr
parameter_list|,
name|e
parameter_list|,
name|e1
parameter_list|,
name|e2
parameter_list|)
function_decl|;
name|VOID
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n%s aborted\n"
argument_list|,
name|cmdid
argument_list|)
decl_stmt|;
name|VOID
name|cleanup
parameter_list|()
function_decl|;
name|exit
argument_list|(
name|ERRCODE
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

