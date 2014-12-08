begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1986, Larry Wall  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following condition is met:  * 1. Redistributions of source code must retain the above copyright notice,  * this condition and the following disclaimer.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * patch - a program to apply diffs to original files  *  * -C option added in 1998, original code by Marc Espie, based on FreeBSD  * behaviour  *  * $OpenBSD: common.h,v 1.26 2006/03/11 19:41:30 otto Exp $  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_define
define|#
directive|define
name|DEBUGGING
end_define

begin_comment
comment|/* constants */
end_comment

begin_define
define|#
directive|define
name|MAXHUNKSIZE
value|200000
end_define

begin_comment
comment|/* is this enough lines? */
end_comment

begin_define
define|#
directive|define
name|INITHUNKMAX
value|125
end_define

begin_comment
comment|/* initial dynamic allocation size */
end_comment

begin_define
define|#
directive|define
name|INITLINELEN
value|4096
end_define

begin_define
define|#
directive|define
name|BUFFERSIZE
value|4096
end_define

begin_define
define|#
directive|define
name|LINENUM_MAX
value|LONG_MAX
end_define

begin_define
define|#
directive|define
name|SCCSPREFIX
value|"s."
end_define

begin_define
define|#
directive|define
name|GET
value|"get -e %s"
end_define

begin_define
define|#
directive|define
name|SCCSDIFF
value|"get -p %s | diff - %s>/dev/null"
end_define

begin_define
define|#
directive|define
name|RCSSUFFIX
value|",v"
end_define

begin_define
define|#
directive|define
name|CHECKOUT
value|"co -l %s"
end_define

begin_define
define|#
directive|define
name|RCSDIFF
value|"rcsdiff %s> /dev/null"
end_define

begin_define
define|#
directive|define
name|ORIGEXT
value|".orig"
end_define

begin_define
define|#
directive|define
name|REJEXT
value|".rej"
end_define

begin_comment
comment|/* handy definitions */
end_comment

begin_define
define|#
directive|define
name|strNE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1, s2))
end_define

begin_define
define|#
directive|define
name|strEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(!strcmp(s1, s2))
end_define

begin_define
define|#
directive|define
name|strnNE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(strncmp(s1, s2, l))
end_define

begin_define
define|#
directive|define
name|strnEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(!strncmp(s1, s2, l))
end_define

begin_comment
comment|/* typedefs */
end_comment

begin_typedef
typedef|typedef
name|long
name|LINENUM
typedef|;
end_typedef

begin_comment
comment|/* must be signed */
end_comment

begin_comment
comment|/* globals */
end_comment

begin_decl_stmt
specifier|extern
name|mode_t
name|filemode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* general purpose buffer */
end_comment

begin_decl_stmt
specifier|extern
name|size_t
name|buf_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of general purpose buffer */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|using_plan_a
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* try to keep everything in memory */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|out_of_mem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ran out of memory in plan a */
end_comment

begin_define
define|#
directive|define
name|MAXFILEC
value|2
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|filearg
index|[
name|MAXFILEC
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ok_to_create_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|outname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|origprae
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|TMPOUTNAME
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|TMPINNAME
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|TMPREJNAME
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|TMPPATNAME
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|toutkeep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|trejkeep
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|bool
name|force
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|batch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|verbose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|reverse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|noreverse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|skip_rest_of_patch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|strippath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|canonicalize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if -C was specified on command line.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|check_only
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|warn_on_invalid_line
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|last_line_missing_eol
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CONTEXT_DIFF
value|1
end_define

begin_define
define|#
directive|define
name|NORMAL_DIFF
value|2
end_define

begin_define
define|#
directive|define
name|ED_DIFF
value|3
end_define

begin_define
define|#
directive|define
name|NEW_CONTEXT_DIFF
value|4
end_define

begin_define
define|#
directive|define
name|UNI_DIFF
value|5
end_define

begin_decl_stmt
specifier|extern
name|int
name|diff_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|revision
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prerequisite revision, if any */
end_comment

begin_decl_stmt
specifier|extern
name|LINENUM
name|input_lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how long is input file in lines */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|posix
decl_stmt|;
end_decl_stmt

end_unit

