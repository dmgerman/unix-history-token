begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)error.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_typedef
typedef|typedef
name|int
name|boolean
typedef|;
end_typedef

begin_define
define|#
directive|define
name|reg
value|register
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_comment
comment|/*  *	Descriptors for the various languages we know about.  *	If you touch these, also touch lang_table  */
end_comment

begin_define
define|#
directive|define
name|INUNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|INCPP
value|1
end_define

begin_define
define|#
directive|define
name|INCC
value|2
end_define

begin_define
define|#
directive|define
name|INAS
value|3
end_define

begin_define
define|#
directive|define
name|INLD
value|4
end_define

begin_define
define|#
directive|define
name|INLINT
value|5
end_define

begin_define
define|#
directive|define
name|INF77
value|6
end_define

begin_define
define|#
directive|define
name|INPI
value|7
end_define

begin_define
define|#
directive|define
name|INPC
value|8
end_define

begin_define
define|#
directive|define
name|INFRANZ
value|9
end_define

begin_define
define|#
directive|define
name|INLISP
value|10
end_define

begin_define
define|#
directive|define
name|INVAXIMA
value|11
end_define

begin_define
define|#
directive|define
name|INRATFOR
value|12
end_define

begin_define
define|#
directive|define
name|INLEX
value|13
end_define

begin_define
define|#
directive|define
name|INYACC
value|14
end_define

begin_define
define|#
directive|define
name|INAPL
value|15
end_define

begin_define
define|#
directive|define
name|INMAKE
value|16
end_define

begin_define
define|#
directive|define
name|INRI
value|17
end_define

begin_define
define|#
directive|define
name|INTROFF
value|18
end_define

begin_define
define|#
directive|define
name|INMOD2
value|19
end_define

begin_decl_stmt
specifier|extern
name|int
name|language
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	We analyze each line in the error message file, and  *	attempt to categorize it by type, as well as language.  *	Here are the type descriptors.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|Errorclass
typedef|;
end_typedef

begin_define
define|#
directive|define
name|C_FIRST
value|0
end_define

begin_comment
comment|/* first error category */
end_comment

begin_define
define|#
directive|define
name|C_UNKNOWN
value|0
end_define

begin_comment
comment|/* must be zero */
end_comment

begin_define
define|#
directive|define
name|C_IGNORE
value|1
end_define

begin_comment
comment|/* ignore the message; used for pi */
end_comment

begin_define
define|#
directive|define
name|C_SYNC
value|2
end_define

begin_comment
comment|/* synchronization errors */
end_comment

begin_define
define|#
directive|define
name|C_DISCARD
value|3
end_define

begin_comment
comment|/* touches dangerous files, so discard */
end_comment

begin_define
define|#
directive|define
name|C_NONSPEC
value|4
end_define

begin_comment
comment|/* not specific to any file */
end_comment

begin_define
define|#
directive|define
name|C_THISFILE
value|5
end_define

begin_comment
comment|/* specific to this file, but at no line */
end_comment

begin_define
define|#
directive|define
name|C_NULLED
value|6
end_define

begin_comment
comment|/* refers to special func; so null */
end_comment

begin_define
define|#
directive|define
name|C_TRUE
value|7
end_define

begin_comment
comment|/* fits into true error format */
end_comment

begin_define
define|#
directive|define
name|C_DUPL
value|8
end_define

begin_comment
comment|/* sub class only; duplicated error message */
end_comment

begin_define
define|#
directive|define
name|C_LAST
value|9
end_define

begin_comment
comment|/* last error category */
end_comment

begin_define
define|#
directive|define
name|SORTABLE
parameter_list|(
name|x
parameter_list|)
value|(!(NOTSORTABLE(x)))
end_define

begin_define
define|#
directive|define
name|NOTSORTABLE
parameter_list|(
name|x
parameter_list|)
value|(x<= C_NONSPEC)
end_define

begin_comment
comment|/*  *	Resources to count and print out the error categories  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|class_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|class_count
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|nunknown
value|class_count[C_UNKNOWN]
end_define

begin_define
define|#
directive|define
name|nignore
value|class_count[C_IGNORE]
end_define

begin_define
define|#
directive|define
name|nsyncerrors
value|class_count[C_SYNC]
end_define

begin_define
define|#
directive|define
name|ndiscard
value|class_count[C_DISCARD]
end_define

begin_define
define|#
directive|define
name|nnonspec
value|class_count[C_NONSPEC]
end_define

begin_define
define|#
directive|define
name|nthisfile
value|class_count[C_THISFILE]
end_define

begin_define
define|#
directive|define
name|nnulled
value|class_count[C_NULLED]
end_define

begin_define
define|#
directive|define
name|ntrue
value|class_count[C_TRUE]
end_define

begin_define
define|#
directive|define
name|ndupl
value|class_count[C_DUPL]
end_define

begin_comment
comment|/* places to put the error complaints */
end_comment

begin_define
define|#
directive|define
name|TOTHEFILE
value|1
end_define

begin_comment
comment|/* touch the file */
end_comment

begin_define
define|#
directive|define
name|TOSTDOUT
value|2
end_define

begin_comment
comment|/* just print them out (ho-hum) */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|errorfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where error file comes from */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|queryfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where the query responses from the user come from*/
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|currentfilename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|scriptname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|query
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|terse
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|inquire
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* inquire for yes/no */
end_comment

begin_comment
comment|/*  *	codes for inquire() to return  */
end_comment

begin_define
define|#
directive|define
name|Q_NO
value|1
end_define

begin_comment
comment|/* 'N' */
end_comment

begin_define
define|#
directive|define
name|Q_no
value|2
end_define

begin_comment
comment|/* 'n' */
end_comment

begin_define
define|#
directive|define
name|Q_YES
value|3
end_define

begin_comment
comment|/* 'Y' */
end_comment

begin_define
define|#
directive|define
name|Q_yes
value|4
end_define

begin_comment
comment|/* 'y' */
end_comment

begin_function_decl
name|int
name|probethisfile
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  *	codes for probethisfile to return  */
end_comment

begin_define
define|#
directive|define
name|F_NOTEXIST
value|1
end_define

begin_define
define|#
directive|define
name|F_NOTREAD
value|2
end_define

begin_define
define|#
directive|define
name|F_NOTWRITE
value|3
end_define

begin_define
define|#
directive|define
name|F_TOUCHIT
value|4
end_define

begin_comment
comment|/*  *	Describes attributes about a language  */
end_comment

begin_struct
struct|struct
name|lang_desc
block|{
name|char
modifier|*
name|lang_name
decl_stmt|;
name|char
modifier|*
name|lang_incomment
decl_stmt|;
comment|/* one of the following defines */
name|char
modifier|*
name|lang_outcomment
decl_stmt|;
comment|/* one of the following defines */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|lang_desc
name|lang_table
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CINCOMMENT
value|"/*###"
end_define

begin_define
define|#
directive|define
name|COUTCOMMENT
value|"%%%*/\n"
end_define

begin_define
define|#
directive|define
name|FINCOMMENT
value|"C###"
end_define

begin_define
define|#
directive|define
name|FOUTCOMMENT
value|"%%%\n"
end_define

begin_define
define|#
directive|define
name|NEWLINE
value|"%%%\n"
end_define

begin_define
define|#
directive|define
name|PIINCOMMENT
value|"(*###"
end_define

begin_define
define|#
directive|define
name|PIOUTCOMMENT
value|"%%%*)\n"
end_define

begin_define
define|#
directive|define
name|LISPINCOMMENT
value|";###"
end_define

begin_define
define|#
directive|define
name|ASINCOMMENT
value|"####"
end_define

begin_define
define|#
directive|define
name|RIINCOMMENT
value|CINCOMMENT
end_define

begin_define
define|#
directive|define
name|RIOUTCOMMENT
value|COUTCOMMENT
end_define

begin_define
define|#
directive|define
name|TROFFINCOMMENT
value|".\\\"###"
end_define

begin_define
define|#
directive|define
name|TROFFOUTCOMMENT
value|NEWLINE
end_define

begin_define
define|#
directive|define
name|MOD2INCOMMENT
value|"(*###"
end_define

begin_define
define|#
directive|define
name|MOD2OUTCOMMENT
value|"%%%*)\n"
end_define

begin_comment
comment|/*  *	Defines and resources for determing if a given line  *	is to be discarded because it refers to a file not to  *	be touched, or if the function reference is to a  *	function the user doesn't want recorded.  */
end_comment

begin_define
define|#
directive|define
name|ERRORNAME
value|"/.errorrc"
end_define

begin_decl_stmt
name|int
name|nignored
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|names_ignored
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Structure definition for a full error  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|edesc
name|Edesc
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Edesc
modifier|*
name|Eptr
typedef|;
end_typedef

begin_struct
struct|struct
name|edesc
block|{
name|Eptr
name|error_next
decl_stmt|;
comment|/*linked together*/
name|int
name|error_lgtext
decl_stmt|;
comment|/* how many on the right hand side*/
name|char
modifier|*
modifier|*
name|error_text
decl_stmt|;
comment|/* the right hand side proper*/
name|Errorclass
name|error_e_class
decl_stmt|;
comment|/* error category of this error*/
name|Errorclass
name|error_s_class
decl_stmt|;
comment|/* sub descriptor of error_e_class*/
name|int
name|error_language
decl_stmt|;
comment|/* the language for this error*/
name|int
name|error_position
decl_stmt|;
comment|/* oridinal position */
name|int
name|error_line
decl_stmt|;
comment|/* discovered line number*/
name|int
name|error_no
decl_stmt|;
comment|/* sequence number on input */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Resources for the true errors  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nerrors
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Eptr
name|er_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Eptr
modifier|*
name|errors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Resources for each of the files mentioned  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nfiles
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Eptr
modifier|*
modifier|*
name|files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* array of pointers into errors*/
end_comment

begin_decl_stmt
name|boolean
modifier|*
name|touchedfiles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* which files we touched */
end_comment

begin_comment
comment|/*  *	The langauge the compilation is in, as intuited from  *	the flavor of error messages analyzed.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|langauge
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|currentfilename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Functional forwards  */
end_comment

begin_function_decl
name|char
modifier|*
name|Calloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strsave
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|clobberfirst
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|lastchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|firstchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
name|next_lastchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|wordvsplice
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wordvcmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|boolean
name|persperdexplode
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  *	Printing hacks  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|plural
argument_list|()
decl_stmt|,
modifier|*
name|verbform
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|arrayify
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|Eptr
operator|*
operator|*
operator|,
name|Eptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|clob_last
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Errorclass
name|discardit
name|__P
argument_list|(
operator|(
name|Eptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|eaterrors
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|Eptr
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|erroradd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|Errorclass
operator|,
name|Errorclass
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|filenames
name|__P
argument_list|(
operator|(
name|int
operator|,
name|Eptr
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|findfiles
name|__P
argument_list|(
operator|(
name|int
operator|,
name|Eptr
operator|*
operator|,
name|int
operator|*
operator|,
name|Eptr
operator|*
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|getignored
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|onintr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|position
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|printerrors
name|__P
argument_list|(
operator|(
name|boolean
operator|,
name|int
operator|,
name|Eptr
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|substitute
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|,
name|char
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|touchfiles
name|__P
argument_list|(
operator|(
name|int
operator|,
name|Eptr
operator|*
operator|*
operator|,
name|int
operator|*
operator|,
name|char
operator|*
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wordvbuild
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|*
operator|,
name|char
operator|*
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|wordvprint
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|,
name|char
operator|*
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

