begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)diff.h 4.1 %G%" */
end_comment

begin_comment
comment|/*  * diff - common declarations  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_comment
comment|/*  * Output format options  */
end_comment

begin_decl_stmt
name|int
name|opt
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|D_NORMAL
value|0
end_define

begin_comment
comment|/* Normal output */
end_comment

begin_define
define|#
directive|define
name|D_EDIT
value|-1
end_define

begin_comment
comment|/* Editor script out */
end_comment

begin_define
define|#
directive|define
name|D_REVERSE
value|1
end_define

begin_comment
comment|/* Reverse editor script */
end_comment

begin_define
define|#
directive|define
name|D_CONTEXT
value|2
end_define

begin_comment
comment|/* Diff with context */
end_comment

begin_define
define|#
directive|define
name|D_IFDEF
value|3
end_define

begin_comment
comment|/* Diff with merged #ifdef's */
end_comment

begin_comment
comment|/*  * Algorithm related options  */
end_comment

begin_decl_stmt
name|int
name|hflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -h, use halfhearted DIFFH */
end_comment

begin_decl_stmt
name|int
name|bflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ignore blanks in comparisions */
end_comment

begin_comment
comment|/*  * Options on hierarchical diffs.  */
end_comment

begin_decl_stmt
name|int
name|lflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* long output format with header */
end_comment

begin_decl_stmt
name|int
name|rflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* recursively trace directories */
end_comment

begin_decl_stmt
name|int
name|sflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* announce files which are same */
end_comment

begin_decl_stmt
name|char
modifier|*
name|start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do file only if name>= this */
end_comment

begin_comment
comment|/*  * Variables for -I D_IFDEF option.  */
end_comment

begin_decl_stmt
name|int
name|wantelses
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -E */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ifdef1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* String for -1 */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ifdef2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* String for -2 */
end_comment

begin_decl_stmt
name|char
modifier|*
name|endifname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* What we will print on next #endif */
end_comment

begin_decl_stmt
name|int
name|inifdef
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Variables for -c context option.  */
end_comment

begin_decl_stmt
name|int
name|context
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lines of context to be printed */
end_comment

begin_comment
comment|/*  * State for exit status.  */
end_comment

begin_decl_stmt
name|int
name|status
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|anychange
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tempfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used when comparing against std input */
end_comment

begin_comment
comment|/*  * Variables for diffdir.  */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|diffargv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* option list to pass to recursive diffs */
end_comment

begin_comment
comment|/*  * Input file names.  * With diffdir, file1 and file2 are allocated BUFSIZ space,  * and padded with a '/', and then efile0 and efile1 point after  * the '/'.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|file1
decl_stmt|,
modifier|*
name|file2
decl_stmt|,
modifier|*
name|efile1
decl_stmt|,
modifier|*
name|efile2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|stat
name|stb1
decl_stmt|,
name|stb2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|stat
name|stb1
decl_stmt|,
name|stb2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This is allocated early, and used  * to reset the free storage pointer to effect space compaction.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dummy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|talloc
argument_list|()
decl_stmt|,
modifier|*
name|ralloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|savestr
argument_list|()
decl_stmt|,
modifier|*
name|splice
argument_list|()
decl_stmt|,
modifier|*
name|splicen
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|mktemp
argument_list|()
decl_stmt|,
modifier|*
name|copytemp
argument_list|()
decl_stmt|,
modifier|*
name|rindex
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|done
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|diffh
index|[]
decl_stmt|,
name|diff
index|[]
decl_stmt|,
name|pr
index|[]
decl_stmt|;
end_decl_stmt

end_unit

