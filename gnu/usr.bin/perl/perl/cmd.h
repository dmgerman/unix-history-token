begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: cmd.h,v $$Revision: 1.2 $$Date: 1995/05/30 05:02:54 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: cmd.h,v $  * Revision 1.2  1995/05/30 05:02:54  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1994/09/10  06:27:34  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:29:35  nate  * PERL!  *  * Revision 4.0.1.2  92/06/08  12:01:02  lwall  * patch20: removed implicit int declarations on funcions  *  * Revision 4.0.1.1  91/06/07  10:28:50  lwall  * patch4: new copyright notice  * patch4: length($`), length($&), length($') now optimized to avoid string copy  *  * Revision 4.0  91/03/20  01:04:34  lwall  * 4.0 baseline.  *  */
end_comment

begin_define
define|#
directive|define
name|C_NULL
value|0
end_define

begin_define
define|#
directive|define
name|C_IF
value|1
end_define

begin_define
define|#
directive|define
name|C_ELSE
value|2
end_define

begin_define
define|#
directive|define
name|C_WHILE
value|3
end_define

begin_define
define|#
directive|define
name|C_BLOCK
value|4
end_define

begin_define
define|#
directive|define
name|C_EXPR
value|5
end_define

begin_define
define|#
directive|define
name|C_NEXT
value|6
end_define

begin_define
define|#
directive|define
name|C_ELSIF
value|7
end_define

begin_comment
comment|/* temporary--turns into an IF + ELSE */
end_comment

begin_define
define|#
directive|define
name|C_CSWITCH
value|8
end_define

begin_comment
comment|/* created by switch optimization in block_head() */
end_comment

begin_define
define|#
directive|define
name|C_NSWITCH
value|9
end_define

begin_comment
comment|/* likewise */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|DOINIT
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cmdname
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|cmdname
index|[]
init|=
block|{
literal|"NULL"
block|,
literal|"IF"
block|,
literal|"ELSE"
block|,
literal|"WHILE"
block|,
literal|"BLOCK"
block|,
literal|"EXPR"
block|,
literal|"NEXT"
block|,
literal|"ELSIF"
block|,
literal|"CSWITCH"
block|,
literal|"NSWITCH"
block|,
literal|"10"
block|}
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

begin_comment
comment|/* DEBUGGING */
end_comment

begin_define
define|#
directive|define
name|CF_OPTIMIZE
value|077
end_define

begin_comment
comment|/* type of optimization */
end_comment

begin_define
define|#
directive|define
name|CF_FIRSTNEG
value|0100
end_define

begin_comment
comment|/* conditional is ($register NE 'string') */
end_comment

begin_define
define|#
directive|define
name|CF_NESURE
value|0200
end_define

begin_comment
comment|/* if short doesn't match we're sure */
end_comment

begin_define
define|#
directive|define
name|CF_EQSURE
value|0400
end_define

begin_comment
comment|/* if short does match we're sure */
end_comment

begin_define
define|#
directive|define
name|CF_COND
value|01000
end_define

begin_comment
comment|/* test c_expr as conditional first, if not null. */
end_comment

begin_comment
comment|/* Set for everything except do {} while currently */
end_comment

begin_define
define|#
directive|define
name|CF_LOOP
value|02000
end_define

begin_comment
comment|/* loop on the c_expr conditional (loop modifiers) */
end_comment

begin_define
define|#
directive|define
name|CF_INVERT
value|04000
end_define

begin_comment
comment|/* it's an "unless" or an "until" */
end_comment

begin_define
define|#
directive|define
name|CF_ONCE
value|010000
end_define

begin_comment
comment|/* we've already pushed the label on the stack */
end_comment

begin_define
define|#
directive|define
name|CF_FLIP
value|020000
end_define

begin_comment
comment|/* on a match do flipflop */
end_comment

begin_define
define|#
directive|define
name|CF_TERM
value|040000
end_define

begin_comment
comment|/* value of this cmd might be returned */
end_comment

begin_define
define|#
directive|define
name|CF_DBSUB
value|0100000
end_define

begin_comment
comment|/* this is an inserted cmd for debugging */
end_comment

begin_define
define|#
directive|define
name|CFT_FALSE
value|0
end_define

begin_comment
comment|/* c_expr is always false */
end_comment

begin_define
define|#
directive|define
name|CFT_TRUE
value|1
end_define

begin_comment
comment|/* c_expr is always true */
end_comment

begin_define
define|#
directive|define
name|CFT_REG
value|2
end_define

begin_comment
comment|/* c_expr is a simple register */
end_comment

begin_define
define|#
directive|define
name|CFT_ANCHOR
value|3
end_define

begin_comment
comment|/* c_expr is an anchored search /^.../ */
end_comment

begin_define
define|#
directive|define
name|CFT_STROP
value|4
end_define

begin_comment
comment|/* c_expr is a string comparison */
end_comment

begin_define
define|#
directive|define
name|CFT_SCAN
value|5
end_define

begin_comment
comment|/* c_expr is an unanchored search /.../ */
end_comment

begin_define
define|#
directive|define
name|CFT_GETS
value|6
end_define

begin_comment
comment|/* c_expr is<filehandle> */
end_comment

begin_define
define|#
directive|define
name|CFT_EVAL
value|7
end_define

begin_comment
comment|/* c_expr is not optimized, so call eval() */
end_comment

begin_define
define|#
directive|define
name|CFT_UNFLIP
value|8
end_define

begin_comment
comment|/* 2nd half of range not optimized */
end_comment

begin_define
define|#
directive|define
name|CFT_CHOP
value|9
end_define

begin_comment
comment|/* c_expr is a chop on a register */
end_comment

begin_define
define|#
directive|define
name|CFT_ARRAY
value|10
end_define

begin_comment
comment|/* this is a foreach loop */
end_comment

begin_define
define|#
directive|define
name|CFT_INDGETS
value|11
end_define

begin_comment
comment|/* c_expr is<$variable> */
end_comment

begin_define
define|#
directive|define
name|CFT_NUMOP
value|12
end_define

begin_comment
comment|/* c_expr is a numeric comparison */
end_comment

begin_define
define|#
directive|define
name|CFT_CCLASS
value|13
end_define

begin_comment
comment|/* c_expr must start with one of these characters */
end_comment

begin_define
define|#
directive|define
name|CFT_D0
value|14
end_define

begin_comment
comment|/* no special breakpoint at this line */
end_comment

begin_define
define|#
directive|define
name|CFT_D1
value|15
end_define

begin_comment
comment|/* possible special breakpoint at this line */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|DOINIT
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cmdopt
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|cmdopt
index|[]
init|=
block|{
literal|"FALSE"
block|,
literal|"TRUE"
block|,
literal|"REG"
block|,
literal|"ANCHOR"
block|,
literal|"STROP"
block|,
literal|"SCAN"
block|,
literal|"GETS"
block|,
literal|"EVAL"
block|,
literal|"UNFLIP"
block|,
literal|"CHOP"
block|,
literal|"ARRAY"
block|,
literal|"INDGETS"
block|,
literal|"NUMOP"
block|,
literal|"CCLASS"
block|,
literal|"14"
block|}
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

begin_comment
comment|/* DEBUGGING */
end_comment

begin_struct
struct|struct
name|acmd
block|{
name|STAB
modifier|*
name|ac_stab
decl_stmt|;
comment|/* a symbol table entry */
name|ARG
modifier|*
name|ac_expr
decl_stmt|;
comment|/* any associated expression */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ccmd
block|{
name|CMD
modifier|*
name|cc_true
decl_stmt|;
comment|/* normal code to do on if and while */
name|CMD
modifier|*
name|cc_alt
decl_stmt|;
comment|/* else cmd ptr or continue code */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scmd
block|{
name|CMD
modifier|*
modifier|*
name|sc_next
decl_stmt|;
comment|/* array of pointers to commands */
name|short
name|sc_offset
decl_stmt|;
comment|/* first value - 1 */
name|short
name|sc_max
decl_stmt|;
comment|/* last value + 1 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cmd
block|{
name|CMD
modifier|*
name|c_next
decl_stmt|;
comment|/* the next command at this level */
name|ARG
modifier|*
name|c_expr
decl_stmt|;
comment|/* conditional expression */
name|CMD
modifier|*
name|c_head
decl_stmt|;
comment|/* head of this command list */
name|STR
modifier|*
name|c_short
decl_stmt|;
comment|/* string to match as shortcut */
name|STAB
modifier|*
name|c_stab
decl_stmt|;
comment|/* a symbol table entry, mostly for fp */
name|SPAT
modifier|*
name|c_spat
decl_stmt|;
comment|/* pattern used by optimization */
name|char
modifier|*
name|c_label
decl_stmt|;
comment|/* label for this construct */
union|union
name|ucmd
block|{
name|struct
name|acmd
name|acmd
decl_stmt|;
comment|/* normal command */
name|struct
name|ccmd
name|ccmd
decl_stmt|;
comment|/* compound command */
name|struct
name|scmd
name|scmd
decl_stmt|;
comment|/* switch command */
block|}
name|ucmd
union|;
name|short
name|c_slen
decl_stmt|;
comment|/* len of c_short, if not null */
name|VOLATILE
name|short
name|c_flags
decl_stmt|;
comment|/* optimization flags--see above */
name|HASH
modifier|*
name|c_stash
decl_stmt|;
comment|/* package line was compiled in */
name|STAB
modifier|*
name|c_filestab
decl_stmt|;
comment|/* file the following line # is from */
name|line_t
name|c_line
decl_stmt|;
comment|/* line # of this command */
name|char
name|c_type
decl_stmt|;
comment|/* what this command does */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|Nullcmd
value|Null(CMD*)
end_define

begin_define
define|#
directive|define
name|Nullcsv
value|Null(CSV*)
end_define

begin_function_decl
name|EXT
name|CMD
modifier|*
name|VOLATILE
name|main_root
name|INIT
parameter_list|(
name|Nullcmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|CMD
modifier|*
name|VOLATILE
name|eval_root
name|INIT
parameter_list|(
name|Nullcmd
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|CMD
name|compiling
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|CMD
modifier|*
name|VOLATILE
name|curcmd
name|INIT
argument_list|(
operator|&
name|compiling
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|CSV
modifier|*
name|VOLATILE
name|curcsv
name|INIT
parameter_list|(
name|Nullcsv
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|callsave
block|{
name|SUBR
modifier|*
name|sub
decl_stmt|;
name|STAB
modifier|*
name|stab
decl_stmt|;
name|CSV
modifier|*
name|curcsv
decl_stmt|;
name|CMD
modifier|*
name|curcmd
decl_stmt|;
name|ARRAY
modifier|*
name|savearray
decl_stmt|;
name|ARRAY
modifier|*
name|argarray
decl_stmt|;
name|long
name|depth
decl_stmt|;
name|int
name|wantarray
decl_stmt|;
name|char
name|hasargs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|compcmd
block|{
name|CMD
modifier|*
name|comp_true
decl_stmt|;
name|CMD
modifier|*
name|comp_alt
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|opt_arg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARG
modifier|*
name|evalstatic
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmd_exec
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_function_decl
name|void
name|deb
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|copyopt
parameter_list|()
function_decl|;
end_function_decl

end_unit

