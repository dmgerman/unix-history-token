begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* flexdef - definitions file for flex */
end_comment

begin_comment
comment|/*  Copyright (c) 1990 The Regents of the University of California. */
end_comment

begin_comment
comment|/*  All rights reserved. */
end_comment

begin_comment
comment|/*  This code is derived from software contributed to Berkeley by */
end_comment

begin_comment
comment|/*  Vern Paxson. */
end_comment

begin_comment
comment|/*  The United States Government has rights in this work pursuant */
end_comment

begin_comment
comment|/*  to contract no. DE-AC03-76SF00098 between the United States */
end_comment

begin_comment
comment|/*  Department of Energy and the University of California. */
end_comment

begin_comment
comment|/*  This file is part of flex. */
end_comment

begin_comment
comment|/*  Redistribution and use in source and binary forms, with or without */
end_comment

begin_comment
comment|/*  modification, are permitted provided that the following conditions */
end_comment

begin_comment
comment|/*  are met: */
end_comment

begin_comment
comment|/*  1. Redistributions of source code must retain the above copyright */
end_comment

begin_comment
comment|/*     notice, this list of conditions and the following disclaimer. */
end_comment

begin_comment
comment|/*  2. Redistributions in binary form must reproduce the above copyright */
end_comment

begin_comment
comment|/*     notice, this list of conditions and the following disclaimer in the */
end_comment

begin_comment
comment|/*     documentation and/or other materials provided with the distribution. */
end_comment

begin_comment
comment|/*  Neither the name of the University nor the names of its contributors */
end_comment

begin_comment
comment|/*  may be used to endorse or promote products derived from this software */
end_comment

begin_comment
comment|/*  without specific prior written permission. */
end_comment

begin_comment
comment|/*  THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR */
end_comment

begin_comment
comment|/*  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED */
end_comment

begin_comment
comment|/*  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR */
end_comment

begin_comment
comment|/*  PURPOSE. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FLEXDEF_H
end_ifndef

begin_define
define|#
directive|define
name|FLEXDEF_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIX requires this to be the first thing in the file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_if
if|#
directive|if
name|HAVE_ALLOCA_H
end_if

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|alloca
end_pragma

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_comment
comment|/* predefined by HP cc +Olibcalls */
end_comment

begin_function_decl
name|char
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

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

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ASSERT_H
end_ifdef

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|Pred
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIMITS_H
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAMS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/params.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_WAIT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDBOOL_H
end_ifdef

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|bool
value|int
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_REGEX_H
end_ifdef

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"flexint.h"
end_include

begin_comment
comment|/* We use gettext. So, when we write strings which should be translated, we mark them with _() */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_NLS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LOCALE_H
end_ifdef

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_LOCALE_H */
end_comment

begin_include
include|#
directive|include
file|"gettext.h"
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|gettext (String)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_
parameter_list|(
name|STRING
parameter_list|)
value|STRING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENABLE_NLS */
end_comment

begin_comment
comment|/* Always be prepared to generate an 8-bit scanner. */
end_comment

begin_define
define|#
directive|define
name|CSIZE
value|256
end_define

begin_define
define|#
directive|define
name|Char
value|unsigned char
end_define

begin_comment
comment|/* Size of input alphabet - should be size of ASCII set. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_CSIZE
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_CSIZE
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PROTO
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|proto
parameter_list|)
value|proto
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|proto
parameter_list|)
value|()
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
name|VMS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__VMS_POSIX
end_ifndef

begin_define
define|#
directive|define
name|unlink
value|remove
end_define

begin_define
define|#
directive|define
name|SHORT_FILE_NAMES
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
name|MS_DOS
end_ifdef

begin_define
define|#
directive|define
name|SHORT_FILE_NAMES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Maximum line length we'll have to deal with. */
end_comment

begin_define
define|#
directive|define
name|MAXLINE
value|2048
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)< (y) ? (x) : (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)> (y) ? (x) : (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ABS
end_ifndef

begin_define
define|#
directive|define
name|ABS
parameter_list|(
name|x
parameter_list|)
value|((x)< 0 ? -(x) : (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANSI C does not guarantee that isascii() is defined */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|isascii
end_ifndef

begin_define
define|#
directive|define
name|isascii
parameter_list|(
name|c
parameter_list|)
value|((c)<= 0177)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|unspecified
value|-1
end_define

begin_comment
comment|/* Special chk[] values marking the slots taking by end-of-buffer and action  * numbers.  */
end_comment

begin_define
define|#
directive|define
name|EOB_POSITION
value|-1
end_define

begin_define
define|#
directive|define
name|ACTION_POSITION
value|-2
end_define

begin_comment
comment|/* Number of data items per line for -f output. */
end_comment

begin_define
define|#
directive|define
name|NUMDATAITEMS
value|10
end_define

begin_comment
comment|/* Number of lines of data in -f output before inserting a blank line for  * readability.  */
end_comment

begin_define
define|#
directive|define
name|NUMDATALINES
value|10
end_define

begin_comment
comment|/* Number of characters to print a line number, i.e., 1 + log10(INT_MAX) */
end_comment

begin_define
define|#
directive|define
name|NUMCHARLINES
value|10
end_define

begin_comment
comment|/* transition_struct_out() definitions. */
end_comment

begin_define
define|#
directive|define
name|TRANS_STRUCT_PRINT_LENGTH
value|14
end_define

begin_comment
comment|/* Returns true if an nfa state has an epsilon out-transition slot  * that can be used.  This definition is currently not used.  */
end_comment

begin_define
define|#
directive|define
name|FREE_EPSILON
parameter_list|(
name|state
parameter_list|)
define|\
value|(transchar[state] == SYM_EPSILON&& \ 	 trans2[state] == NO_TRANSITION&& \ 	 finalst[state] != state)
end_define

begin_comment
comment|/* Returns true if an nfa state has an epsilon out-transition character  * and both slots are free  */
end_comment

begin_define
define|#
directive|define
name|SUPER_FREE_EPSILON
parameter_list|(
name|state
parameter_list|)
define|\
value|(transchar[state] == SYM_EPSILON&& \ 	 trans1[state] == NO_TRANSITION)
end_define

begin_comment
unit|\
comment|/* Maximum number of NFA states that can comprise a DFA state.  It's real  * big because if there's a lot of rules, the initial state will have a  * huge epsilon closure.  */
end_comment

begin_define
define|#
directive|define
name|INITIAL_MAX_DFA_SIZE
value|750
end_define

begin_define
define|#
directive|define
name|MAX_DFA_SIZE_INCREMENT
value|750
end_define

begin_comment
comment|/* A note on the following masks.  They are used to mark accepting numbers  * as being special.  As such, they implicitly limit the number of accepting  * numbers (i.e., rules) because if there are too many rules the rule numbers  * will overload the mask bits.  Fortunately, this limit is \large/ (0x2000 ==  * 8192) so unlikely to actually cause any problems.  A check is made in  * new_rule() to ensure that this limit is not reached.  */
end_comment

begin_comment
comment|/* Mask to mark a trailing context accepting number. */
end_comment

begin_define
define|#
directive|define
name|YY_TRAILING_MASK
value|0x2000
end_define

begin_comment
comment|/* Mask to mark the accepting number of the "head" of a trailing context  * rule.  */
end_comment

begin_define
define|#
directive|define
name|YY_TRAILING_HEAD_MASK
value|0x4000
end_define

begin_comment
comment|/* Maximum number of rules, as outlined in the above note. */
end_comment

begin_define
define|#
directive|define
name|MAX_RULE
value|(YY_TRAILING_MASK - 1)
end_define

begin_comment
comment|/* NIL must be 0.  If not, its special meaning when making equivalence classes  * (it marks the representative of a given e.c.) will be unidentifiable.  */
end_comment

begin_define
define|#
directive|define
name|NIL
value|0
end_define

begin_define
define|#
directive|define
name|JAM
value|-1
end_define

begin_comment
comment|/* to mark a missing DFA transition */
end_comment

begin_define
define|#
directive|define
name|NO_TRANSITION
value|NIL
end_define

begin_define
define|#
directive|define
name|UNIQUE
value|-1
end_define

begin_comment
comment|/* marks a symbol as an e.c. representative */
end_comment

begin_define
define|#
directive|define
name|INFINITE_REPEAT
value|-1
end_define

begin_comment
comment|/* for x{5,} constructions */
end_comment

begin_define
define|#
directive|define
name|INITIAL_MAX_CCLS
value|100
end_define

begin_comment
comment|/* max number of unique character classes */
end_comment

begin_define
define|#
directive|define
name|MAX_CCLS_INCREMENT
value|100
end_define

begin_comment
comment|/* Size of table holding members of character classes. */
end_comment

begin_define
define|#
directive|define
name|INITIAL_MAX_CCL_TBL_SIZE
value|500
end_define

begin_define
define|#
directive|define
name|MAX_CCL_TBL_SIZE_INCREMENT
value|250
end_define

begin_define
define|#
directive|define
name|INITIAL_MAX_RULES
value|100
end_define

begin_comment
comment|/* default maximum number of rules */
end_comment

begin_define
define|#
directive|define
name|MAX_RULES_INCREMENT
value|100
end_define

begin_define
define|#
directive|define
name|INITIAL_MNS
value|2000
end_define

begin_comment
comment|/* default maximum number of nfa states */
end_comment

begin_define
define|#
directive|define
name|MNS_INCREMENT
value|1000
end_define

begin_comment
comment|/* amount to bump above by if it's not enough */
end_comment

begin_define
define|#
directive|define
name|INITIAL_MAX_DFAS
value|1000
end_define

begin_comment
comment|/* default maximum number of dfa states */
end_comment

begin_define
define|#
directive|define
name|MAX_DFAS_INCREMENT
value|1000
end_define

begin_define
define|#
directive|define
name|JAMSTATE
value|-32766
end_define

begin_comment
comment|/* marks a reference to the state that always jams */
end_comment

begin_comment
comment|/* Maximum number of NFA states. */
end_comment

begin_define
define|#
directive|define
name|MAXIMUM_MNS
value|31999
end_define

begin_define
define|#
directive|define
name|MAXIMUM_MNS_LONG
value|1999999999
end_define

begin_comment
comment|/* Enough so that if it's subtracted from an NFA state number, the result  * is guaranteed to be negative.  */
end_comment

begin_define
define|#
directive|define
name|MARKER_DIFFERENCE
value|(maximum_mns+2)
end_define

begin_comment
comment|/* Maximum number of nxt/chk pairs for non-templates. */
end_comment

begin_define
define|#
directive|define
name|INITIAL_MAX_XPAIRS
value|2000
end_define

begin_define
define|#
directive|define
name|MAX_XPAIRS_INCREMENT
value|2000
end_define

begin_comment
comment|/* Maximum number of nxt/chk pairs needed for templates. */
end_comment

begin_define
define|#
directive|define
name|INITIAL_MAX_TEMPLATE_XPAIRS
value|2500
end_define

begin_define
define|#
directive|define
name|MAX_TEMPLATE_XPAIRS_INCREMENT
value|2500
end_define

begin_define
define|#
directive|define
name|SYM_EPSILON
value|(CSIZE + 1)
end_define

begin_comment
comment|/* to mark transitions on the symbol epsilon */
end_comment

begin_define
define|#
directive|define
name|INITIAL_MAX_SCS
value|40
end_define

begin_comment
comment|/* maximum number of start conditions */
end_comment

begin_define
define|#
directive|define
name|MAX_SCS_INCREMENT
value|40
end_define

begin_comment
comment|/* amount to bump by if it's not enough */
end_comment

begin_define
define|#
directive|define
name|ONE_STACK_SIZE
value|500
end_define

begin_comment
comment|/* stack of states with only one out-transition */
end_comment

begin_define
define|#
directive|define
name|SAME_TRANS
value|-1
end_define

begin_comment
comment|/* transition is the same as "default" entry for state */
end_comment

begin_comment
comment|/* The following percentages are used to tune table compression:   * The percentage the number of out-transitions a state must be of the  * number of equivalence classes in order to be considered for table  * compaction by using protos.  */
end_comment

begin_define
define|#
directive|define
name|PROTO_SIZE_PERCENTAGE
value|15
end_define

begin_comment
comment|/* The percentage the number of homogeneous out-transitions of a state  * must be of the number of total out-transitions of the state in order  * that the state's transition table is first compared with a potential  * template of the most common out-transition instead of with the first  * proto in the proto queue.  */
end_comment

begin_define
define|#
directive|define
name|CHECK_COM_PERCENTAGE
value|50
end_define

begin_comment
comment|/* The percentage the number of differences between a state's transition  * table and the proto it was first compared with must be of the total  * number of out-transitions of the state in order to keep the first  * proto as a good match and not search any further.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_MATCH_DIFF_PERCENTAGE
value|10
end_define

begin_comment
comment|/* The percentage the number of differences between a state's transition  * table and the most similar proto must be of the state's total number  * of out-transitions to use the proto as an acceptable close match.  */
end_comment

begin_define
define|#
directive|define
name|ACCEPTABLE_DIFF_PERCENTAGE
value|50
end_define

begin_comment
comment|/* The percentage the number of homogeneous out-transitions of a state  * must be of the number of total out-transitions of the state in order  * to consider making a template from the state.  */
end_comment

begin_define
define|#
directive|define
name|TEMPLATE_SAME_PERCENTAGE
value|60
end_define

begin_comment
comment|/* The percentage the number of differences between a state's transition  * table and the most similar proto must be of the state's total number  * of out-transitions to create a new proto from the state.  */
end_comment

begin_define
define|#
directive|define
name|NEW_PROTO_DIFF_PERCENTAGE
value|20
end_define

begin_comment
comment|/* The percentage the total number of out-transitions of a state must be  * of the number of equivalence classes in order to consider trying to  * fit the transition table into "holes" inside the nxt/chk table.  */
end_comment

begin_define
define|#
directive|define
name|INTERIOR_FIT_PERCENTAGE
value|15
end_define

begin_comment
comment|/* Size of region set aside to cache the complete transition table of  * protos on the proto queue to enable quick comparisons.  */
end_comment

begin_define
define|#
directive|define
name|PROT_SAVE_SIZE
value|2000
end_define

begin_define
define|#
directive|define
name|MSP
value|50
end_define

begin_comment
comment|/* maximum number of saved protos (protos on the proto queue) */
end_comment

begin_comment
comment|/* Maximum number of out-transitions a state can have that we'll rummage  * around through the interior of the internal fast table looking for a  * spot for it.  */
end_comment

begin_define
define|#
directive|define
name|MAX_XTIONS_FULL_INTERIOR_FIT
value|4
end_define

begin_comment
comment|/* Maximum number of rules which will be reported as being associated  * with a DFA state.  */
end_comment

begin_define
define|#
directive|define
name|MAX_ASSOC_RULES
value|100
end_define

begin_comment
comment|/* Number that, if used to subscript an array, has a good chance of producing  * an error; should be small enough to fit into a short.  */
end_comment

begin_define
define|#
directive|define
name|BAD_SUBSCRIPT
value|-32767
end_define

begin_comment
comment|/* Absolute value of largest number that can be stored in a short, with a  * bit of slop thrown in for general paranoia.  */
end_comment

begin_define
define|#
directive|define
name|MAX_SHORT
value|32700
end_define

begin_comment
comment|/* Declarations for global variables. */
end_comment

begin_comment
comment|/* Variables for flags:  * printstats - if true (-v), dump statistics  * syntaxerror - true if a syntax error has been found  * eofseen - true if we've seen an eof in the input file  * ddebug - if true (-d), make a "debug" scanner  * trace - if true (-T), trace processing  * nowarn - if true (-w), do not generate warnings  * spprdflt - if true (-s), suppress the default rule  * interactive - if true (-I), generate an interactive scanner  * lex_compat - if true (-l), maximize compatibility with AT&T lex  * posix_compat - if true (-X), maximize compatibility with POSIX lex  * do_yylineno - if true, generate code to maintain yylineno  * useecs - if true (-Ce flag), use equivalence classes  * fulltbl - if true (-Cf flag), don't compress the DFA state table  * usemecs - if true (-Cm flag), use meta-equivalence classes  * fullspd - if true (-F flag), use Jacobson method of table representation  * gen_line_dirs - if true (i.e., no -L flag), generate #line directives  * performance_report - if> 0 (i.e., -p flag), generate a report relating  *   to scanner performance; if> 1 (-p -p), report on minor performance  *   problems, too  * backing_up_report - if true (i.e., -b flag), generate "lex.backup" file  *   listing backing-up states  * C_plus_plus - if true (i.e., -+ flag), generate a C++ scanner class;  *   otherwise, a standard C scanner  * reentrant - if true (-R), generate a reentrant C scanner.  * bison_bridge_lval - if true (--bison-bridge), bison pure calling convention.  * bison_bridge_lloc - if true (--bison-locations), bison yylloc.  * long_align - if true (-Ca flag), favor long-word alignment.  * use_read - if true (-f, -F, or -Cr) then use read() for scanner input;  *   otherwise, use fread().  * yytext_is_array - if true (i.e., %array directive), then declare  *   yytext as an array instead of a character pointer.  Nice and inefficient.  * do_yywrap - do yywrap() processing on EOF.  If false, EOF treated as  *   "no more files".  * csize - size of character set for the scanner we're generating;  *   128 for 7-bit chars and 256 for 8-bit  * yymore_used - if true, yymore() is used in input rules  * reject - if true, generate back-up tables for REJECT macro  * real_reject - if true, scanner really uses REJECT (as opposed to just  *   having "reject" set for variable trailing context)  * continued_action - true if this rule's action is to "fall through" to  *   the next rule's action (i.e., the '|' action)  * in_rule - true if we're inside an individual rule, false if not.  * yymore_really_used - whether to treat yymore() as really used, regardless  *   of what we think based on references to it in the user's actions.  * reject_really_used - same for REJECT  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|printstats
decl_stmt|,
name|syntaxerror
decl_stmt|,
name|eofseen
decl_stmt|,
name|ddebug
decl_stmt|,
name|trace
decl_stmt|,
name|nowarn
decl_stmt|,
name|spprdflt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|interactive
decl_stmt|,
name|lex_compat
decl_stmt|,
name|posix_compat
decl_stmt|,
name|do_yylineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|useecs
decl_stmt|,
name|fulltbl
decl_stmt|,
name|usemecs
decl_stmt|,
name|fullspd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gen_line_dirs
decl_stmt|,
name|performance_report
decl_stmt|,
name|backing_up_report
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reentrant
decl_stmt|,
name|bison_bridge_lval
decl_stmt|,
name|bison_bridge_lloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ansi_func_defs
decl_stmt|,
name|ansi_func_protos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|C_plus_plus
decl_stmt|,
name|long_align
decl_stmt|,
name|use_read
decl_stmt|,
name|yytext_is_array
decl_stmt|,
name|do_yywrap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|csize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yymore_used
decl_stmt|,
name|reject
decl_stmt|,
name|real_reject
decl_stmt|,
name|continued_action
decl_stmt|,
name|in_rule
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yymore_really_used
decl_stmt|,
name|reject_really_used
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables used in the flex input routines:  * datapos - characters on current output line  * dataline - number of contiguous lines of data in current data  * 	statement.  Used to generate readable -f output  * linenum - current input line number  * skelfile - the skeleton file  * skel - compiled-in skeleton array  * skel_ind - index into "skel" array, if skelfile is nil  * yyin - input file  * backing_up_file - file to summarize backing-up states to  * infilename - name of input file  * outfilename - name of output file  * headerfilename - name of the .h file to generate  * did_outfilename - whether outfilename was explicitly set  * prefix - the prefix used for externally visible names ("yy" by default)  * yyclass - yyFlexLexer subclass to use for YY_DECL  * do_stdinit - whether to initialize yyin/yyout to stdin/stdout  * use_stdout - the -t flag  * input_files - array holding names of input files  * num_input_files - size of input_files array  * program_name - name with which program was invoked  *  * action_array - array to hold the rule actions  * action_size - size of action_array  * defs1_offset - index where the user's section 1 definitions start  *	in action_array  * prolog_offset - index where the prolog starts in action_array  * action_offset - index where the non-prolog starts in action_array  * action_index - index where the next action should go, with respect  * 	to "action_array"  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|datapos
decl_stmt|,
name|dataline
decl_stmt|,
name|linenum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|skelfile
decl_stmt|,
modifier|*
name|yyin
decl_stmt|,
modifier|*
name|backing_up_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|skel
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|skel_ind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|infilename
decl_stmt|,
modifier|*
name|outfilename
decl_stmt|,
modifier|*
name|headerfilename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|did_outfilename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|prefix
decl_stmt|,
modifier|*
name|yyclass
decl_stmt|,
modifier|*
name|extra_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|do_stdinit
decl_stmt|,
name|use_stdout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|input_files
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num_input_files
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|action_array
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|action_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|defs1_offset
decl_stmt|,
name|prolog_offset
decl_stmt|,
name|action_offset
decl_stmt|,
name|action_index
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables for stack of states having only one out-transition:  * onestate - state number  * onesym - transition symbol  * onenext - target state  * onedef - default base entry  * onesp - stack pointer  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|onestate
index|[
name|ONE_STACK_SIZE
index|]
decl_stmt|,
name|onesym
index|[
name|ONE_STACK_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|onenext
index|[
name|ONE_STACK_SIZE
index|]
decl_stmt|,
name|onedef
index|[
name|ONE_STACK_SIZE
index|]
decl_stmt|,
name|onesp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables for nfa machine data:  * maximum_mns - maximal number of NFA states supported by tables  * current_mns - current maximum on number of NFA states  * num_rules - number of the last accepting state; also is number of  * 	rules created so far  * num_eof_rules - number of<<EOF>> rules  * default_rule - number of the default rule  * current_max_rules - current maximum number of rules  * lastnfa - last nfa state number created  * firstst - physically the first state of a fragment  * lastst - last physical state of fragment  * finalst - last logical state of fragment  * transchar - transition character  * trans1 - transition state  * trans2 - 2nd transition state for epsilons  * accptnum - accepting number  * assoc_rule - rule associated with this NFA state (or 0 if none)  * state_type - a STATE_xxx type identifying whether the state is part  * 	of a normal rule, the leading state in a trailing context  * 	rule (i.e., the state which marks the transition from  * 	recognizing the text-to-be-matched to the beginning of  * 	the trailing context), or a subsequent state in a trailing  * 	context rule  * rule_type - a RULE_xxx type identifying whether this a ho-hum  * 	normal rule or one which has variable head& trailing  * 	context  * rule_linenum - line number associated with rule  * rule_useful - true if we've determined that the rule can be matched  * rule_has_nl - true if rule could possibly match a newline  * ccl_has_nl - true if current ccl could match a newline  * nlch - default eol char  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maximum_mns
decl_stmt|,
name|current_mns
decl_stmt|,
name|current_max_rules
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num_rules
decl_stmt|,
name|num_eof_rules
decl_stmt|,
name|default_rule
decl_stmt|,
name|lastnfa
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|firstst
decl_stmt|,
modifier|*
name|lastst
decl_stmt|,
modifier|*
name|finalst
decl_stmt|,
modifier|*
name|transchar
decl_stmt|,
modifier|*
name|trans1
decl_stmt|,
modifier|*
name|trans2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|accptnum
decl_stmt|,
modifier|*
name|assoc_rule
decl_stmt|,
modifier|*
name|state_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|rule_type
decl_stmt|,
modifier|*
name|rule_linenum
decl_stmt|,
modifier|*
name|rule_useful
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
modifier|*
name|rule_has_nl
decl_stmt|,
modifier|*
name|ccl_has_nl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nlch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Different types of states; values are useful as masks, as well, for  * routines like check_trailing_context().  */
end_comment

begin_define
define|#
directive|define
name|STATE_NORMAL
value|0x1
end_define

begin_define
define|#
directive|define
name|STATE_TRAILING_CONTEXT
value|0x2
end_define

begin_comment
comment|/* Global holding current type of state we're making. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_state_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Different types of rules. */
end_comment

begin_define
define|#
directive|define
name|RULE_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|RULE_VARIABLE
value|1
end_define

begin_comment
comment|/* True if the input rules include a rule with both variable-length head  * and trailing context, false otherwise.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|variable_trailing_context_rules
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables for protos:  * numtemps - number of templates created  * numprots - number of protos created  * protprev - backlink to a more-recently used proto  * protnext - forward link to a less-recently used proto  * prottbl - base/def table entry for proto  * protcomst - common state of proto  * firstprot - number of the most recently used proto  * lastprot - number of the least recently used proto  * protsave contains the entire state array for protos  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|numtemps
decl_stmt|,
name|numprots
decl_stmt|,
name|protprev
index|[
name|MSP
index|]
decl_stmt|,
name|protnext
index|[
name|MSP
index|]
decl_stmt|,
name|prottbl
index|[
name|MSP
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|protcomst
index|[
name|MSP
index|]
decl_stmt|,
name|firstprot
decl_stmt|,
name|lastprot
decl_stmt|,
name|protsave
index|[
name|PROT_SAVE_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables for managing equivalence classes:  * numecs - number of equivalence classes  * nextecm - forward link of Equivalence Class members  * ecgroup - class number or backward link of EC members  * nummecs - number of meta-equivalence classes (used to compress  *   templates)  * tecfwd - forward link of meta-equivalence classes members  * tecbck - backward link of MEC's  */
end_comment

begin_comment
comment|/* Reserve enough room in the equivalence class arrays so that we  * can use the CSIZE'th element to hold equivalence class information  * for the NUL character.  Later we'll move this information into  * the 0th element.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|numecs
decl_stmt|,
name|nextecm
index|[
name|CSIZE
operator|+
literal|1
index|]
decl_stmt|,
name|ecgroup
index|[
name|CSIZE
operator|+
literal|1
index|]
decl_stmt|,
name|nummecs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Meta-equivalence classes are indexed starting at 1, so it's possible  * that they will require positions from 1 .. CSIZE, i.e., CSIZE + 1  * slots total (since the arrays are 0-based).  nextecm[] and ecgroup[]  * don't require the extra position since they're indexed from 1 .. CSIZE - 1.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tecfwd
index|[
name|CSIZE
operator|+
literal|1
index|]
decl_stmt|,
name|tecbck
index|[
name|CSIZE
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables for start conditions:  * lastsc - last start condition created  * current_max_scs - current limit on number of start conditions  * scset - set of rules active in start condition  * scbol - set of rules active only at the beginning of line in a s.c.  * scxclu - true if start condition is exclusive  * sceof - true if start condition has EOF rule  * scname - start condition name  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lastsc
decl_stmt|,
modifier|*
name|scset
decl_stmt|,
modifier|*
name|scbol
decl_stmt|,
modifier|*
name|scxclu
decl_stmt|,
modifier|*
name|sceof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_max_scs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|scname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables for dfa machine data:  * current_max_dfa_size - current maximum number of NFA states in DFA  * current_max_xpairs - current maximum number of non-template xtion pairs  * current_max_template_xpairs - current maximum number of template pairs  * current_max_dfas - current maximum number DFA states  * lastdfa - last dfa state number created  * nxt - state to enter upon reading character  * chk - check value to see if "nxt" applies  * tnxt - internal nxt table for templates  * base - offset into "nxt" for given state  * def - where to go if "chk" disallows "nxt" entry  * nultrans - NUL transition for each state  * NUL_ec - equivalence class of the NUL character  * tblend - last "nxt/chk" table entry being used  * firstfree - first empty entry in "nxt/chk" table  * dss - nfa state set for each dfa  * dfasiz - size of nfa state set for each dfa  * dfaacc - accepting set for each dfa state (if using REJECT), or accepting  *	number, if not  * accsiz - size of accepting set for each dfa state  * dhash - dfa state hash value  * numas - number of DFA accepting states created; note that this  *	is not necessarily the same value as num_rules, which is the analogous  *	value for the NFA  * numsnpairs - number of state/nextstate transition pairs  * jambase - position in base/def where the default jam table starts  * jamstate - state number corresponding to "jam" state  * end_of_buffer_state - end-of-buffer dfa state number  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_max_dfa_size
decl_stmt|,
name|current_max_xpairs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_max_template_xpairs
decl_stmt|,
name|current_max_dfas
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lastdfa
decl_stmt|,
modifier|*
name|nxt
decl_stmt|,
modifier|*
name|chk
decl_stmt|,
modifier|*
name|tnxt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|base
decl_stmt|,
modifier|*
name|def
decl_stmt|,
modifier|*
name|nultrans
decl_stmt|,
name|NUL_ec
decl_stmt|,
name|tblend
decl_stmt|,
name|firstfree
decl_stmt|,
modifier|*
modifier|*
name|dss
decl_stmt|,
modifier|*
name|dfasiz
decl_stmt|;
end_decl_stmt

begin_union
specifier|extern
union|union
name|dfaacc_union
block|{
name|int
modifier|*
name|dfaacc_set
decl_stmt|;
name|int
name|dfaacc_state
decl_stmt|;
block|}
modifier|*
name|dfaacc
union|;
end_union

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|accsiz
decl_stmt|,
modifier|*
name|dhash
decl_stmt|,
name|numas
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|numsnpairs
decl_stmt|,
name|jambase
decl_stmt|,
name|jamstate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|end_of_buffer_state
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables for ccl information:  * lastccl - ccl index of the last created ccl  * current_maxccls - current limit on the maximum number of unique ccl's  * cclmap - maps a ccl index to its set pointer  * ccllen - gives the length of a ccl  * cclng - true for a given ccl if the ccl is negated  * cclreuse - counts how many times a ccl is re-used  * current_max_ccl_tbl_size - current limit on number of characters needed  *	to represent the unique ccl's  * ccltbl - holds the characters in each ccl - indexed by cclmap  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lastccl
decl_stmt|,
modifier|*
name|cclmap
decl_stmt|,
modifier|*
name|ccllen
decl_stmt|,
modifier|*
name|cclng
decl_stmt|,
name|cclreuse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_maxccls
decl_stmt|,
name|current_max_ccl_tbl_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Char
modifier|*
name|ccltbl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Variables for miscellaneous information:  * nmstr - last NAME scanned by the scanner  * sectnum - section number currently being parsed  * nummt - number of empty nxt/chk table entries  * hshcol - number of hash collisions detected by snstods  * dfaeql - number of times a newly created dfa was equal to an old one  * numeps - number of epsilon NFA states created  * eps2 - number of epsilon states which have 2 out-transitions  * num_reallocs - number of times it was necessary to realloc() a group  *	  of arrays  * tmpuses - number of DFA states that chain to templates  * totnst - total number of NFA states used to make DFA states  * peakpairs - peak number of transition pairs we had to store internally  * numuniq - number of unique transitions  * numdup - number of duplicate transitions  * hshsave - number of hash collisions saved by checking number of states  * num_backing_up - number of DFA states requiring backing up  * bol_needed - whether scanner needs beginning-of-line recognition  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|nmstr
index|[
name|MAXLINE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sectnum
decl_stmt|,
name|nummt
decl_stmt|,
name|hshcol
decl_stmt|,
name|dfaeql
decl_stmt|,
name|numeps
decl_stmt|,
name|eps2
decl_stmt|,
name|num_reallocs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tmpuses
decl_stmt|,
name|totnst
decl_stmt|,
name|peakpairs
decl_stmt|,
name|numuniq
decl_stmt|,
name|numdup
decl_stmt|,
name|hshsave
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num_backing_up
decl_stmt|,
name|bol_needed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|allocate_array
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|reallocate_array
name|PROTO
argument_list|(
operator|(
name|void
operator|*
operator|,
name|int
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|flex_alloc
name|PROTO
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|flex_realloc
name|PROTO
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|flex_free
name|PROTO
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|allocate_integer_array
parameter_list|(
name|size
parameter_list|)
define|\
value|(int *) allocate_array( size, sizeof( int ) )
end_define

begin_define
define|#
directive|define
name|reallocate_integer_array
parameter_list|(
name|array
parameter_list|,
name|size
parameter_list|)
define|\
value|(int *) reallocate_array( (void *) array, size, sizeof( int ) )
end_define

begin_define
define|#
directive|define
name|allocate_bool_array
parameter_list|(
name|size
parameter_list|)
define|\
value|(bool *) allocate_array( size, sizeof( bool ) )
end_define

begin_define
define|#
directive|define
name|reallocate_bool_array
parameter_list|(
name|array
parameter_list|,
name|size
parameter_list|)
define|\
value|(bool *) reallocate_array( (void *) array, size, sizeof( bool ) )
end_define

begin_define
define|#
directive|define
name|allocate_int_ptr_array
parameter_list|(
name|size
parameter_list|)
define|\
value|(int **) allocate_array( size, sizeof( int * ) )
end_define

begin_define
define|#
directive|define
name|allocate_char_ptr_array
parameter_list|(
name|size
parameter_list|)
define|\
value|(char **) allocate_array( size, sizeof( char * ) )
end_define

begin_define
define|#
directive|define
name|allocate_dfaacc_union
parameter_list|(
name|size
parameter_list|)
define|\
value|(union dfaacc_union *) \ 		allocate_array( size, sizeof( union dfaacc_union ) )
end_define

begin_define
define|#
directive|define
name|reallocate_int_ptr_array
parameter_list|(
name|array
parameter_list|,
name|size
parameter_list|)
define|\
value|(int **) reallocate_array( (void *) array, size, sizeof( int * ) )
end_define

begin_define
define|#
directive|define
name|reallocate_char_ptr_array
parameter_list|(
name|array
parameter_list|,
name|size
parameter_list|)
define|\
value|(char **) reallocate_array( (void *) array, size, sizeof( char * ) )
end_define

begin_define
define|#
directive|define
name|reallocate_dfaacc_union
parameter_list|(
name|array
parameter_list|,
name|size
parameter_list|)
define|\
value|(union dfaacc_union *) \ 	reallocate_array( (void *) array, size, sizeof( union dfaacc_union ) )
end_define

begin_define
define|#
directive|define
name|allocate_character_array
parameter_list|(
name|size
parameter_list|)
define|\
value|(char *) allocate_array( size, sizeof( char ) )
end_define

begin_define
define|#
directive|define
name|reallocate_character_array
parameter_list|(
name|array
parameter_list|,
name|size
parameter_list|)
define|\
value|(char *) reallocate_array( (void *) array, size, sizeof( char ) )
end_define

begin_define
define|#
directive|define
name|allocate_Character_array
parameter_list|(
name|size
parameter_list|)
define|\
value|(Char *) allocate_array( size, sizeof( Char ) )
end_define

begin_define
define|#
directive|define
name|reallocate_Character_array
parameter_list|(
name|array
parameter_list|,
name|size
parameter_list|)
define|\
value|(Char *) reallocate_array( (void *) array, size, sizeof( Char ) )
end_define

begin_comment
comment|/* Used to communicate between scanner and parser.  The type should really  * be YYSTYPE, but we can't easily get our hands on it.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yylval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* External functions that are cross-referenced among the flex source files. */
end_comment

begin_comment
comment|/* from file ccl.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ccladd
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* add a single character to a ccl */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cclinit
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* make an empty ccl */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cclnegate
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* negate a ccl */
end_comment

begin_function_decl
specifier|extern
name|int
name|ccl_set_diff
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set difference of two ccls. */
end_comment

begin_function_decl
specifier|extern
name|int
name|ccl_set_union
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set union of two ccls. */
end_comment

begin_comment
comment|/* List the members of a set of characters in CCL form. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|list_character_set
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* from file dfa.c */
end_comment

begin_comment
comment|/* Check a DFA state for backing up. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|check_for_backing_up
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check to see if NFA state set constitutes "dangerous" trailing context. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|check_trailing_context
name|PROTO
argument_list|(
operator|(
name|int
operator|*
operator|,
name|int
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Construct the epsilon closure of a set of ndfa states. */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|epsclosure
name|PROTO
argument_list|(
operator|(
name|int
operator|*
operator|,
name|int
operator|*
operator|,
name|int
index|[]
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Increase the maximum number of dfas. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|increase_max_dfas
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ntod
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* convert a ndfa to a dfa */
end_comment

begin_comment
comment|/* Converts a set of ndfa states into a dfa state. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|snstods
name|PROTO
argument_list|(
operator|(
name|int
index|[]
operator|,
name|int
operator|,
name|int
index|[]
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* from file ecs.c */
end_comment

begin_comment
comment|/* Convert character classes to set of equivalence classes. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ccl2ecl
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Associate equivalence class numbers with class members. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cre8ecs
name|PROTO
argument_list|(
operator|(
name|int
index|[]
operator|,
name|int
index|[]
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Update equivalence classes based on character class transitions. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mkeccl
name|PROTO
argument_list|(
operator|(
name|Char
index|[]
operator|,
name|int
operator|,
name|int
index|[]
operator|,
name|int
index|[]
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create equivalence class for single character. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mkechar
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
index|[]
operator|,
name|int
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* from file gen.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|do_indent
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* indent to the current level */
end_comment

begin_comment
comment|/* Generate the code to keep backing-up information. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gen_backing_up
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate the code to perform the backing up. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gen_bu_action
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate full speed compressed transition table. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|genctbl
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate the code to find the action number. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gen_find_action
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|genftbl
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* generate full transition table */
end_comment

begin_comment
comment|/* Generate the code to find the next compressed-table state. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gen_next_compressed_state
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate the code to find the next match. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gen_next_match
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate the code to find the next state. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gen_next_state
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate the code to make a NUL transition. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gen_NUL_trans
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate the code to find the start state. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gen_start_state
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate data statements for the transition tables. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gentabs
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write out a formatted string at the current indentation level. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|indent_put2s
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write out a string + newline at the current indentation level. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|indent_puts
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|make_tables
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* generate transition tables */
end_comment

begin_comment
comment|/* from file main.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|check_options
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|flexend
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|usage
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* from file misc.c */
end_comment

begin_comment
comment|/* Add a #define to the action file. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|action_define
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|defname
operator|,
name|int
name|value
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add the given text to the stored actions. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|add_action
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|new_text
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if a string is all lower case. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|all_lower
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if a string is all upper case. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|all_upper
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Compare two integers for use by qsort. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|intcmp
name|PROTO
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check a character to make sure it's in the expected range. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|check_char
name|PROTO
argument_list|(
operator|(
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Replace upper-case letter to lower-case. */
end_comment

begin_decl_stmt
specifier|extern
name|Char
name|clower
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Returns a dynamically allocated copy of a string. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|copy_string
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Returns a dynamically allocated copy of a (potentially) unsigned string. */
end_comment

begin_decl_stmt
specifier|extern
name|Char
modifier|*
name|copy_unsigned_string
name|PROTO
argument_list|(
operator|(
name|Char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Compare two characters for use by qsort with '\0' sorting last. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cclcmp
name|PROTO
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Finish up a block of data declarations. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dataend
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flush generated data statements. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dataflush
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Report an error message and terminate. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|flexerror
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Report a fatal error message and terminate. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|flexfatal
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Report a fatal error with a pinpoint, and terminate */
end_comment

begin_if
if|#
directive|if
name|HAVE_DECL___FUNC__
end_if

begin_define
define|#
directive|define
name|flex_die
parameter_list|(
name|msg
parameter_list|)
define|\
value|do{ \         fprintf (stderr,\                 _("%s: fatal internal error at %s:%d (%s): %s\n"),\                 program_name, __FILE__, (int)__LINE__,\                 __func__,msg);\         FLEX_EXIT(1);\     }while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! HAVE_DECL___FUNC__ */
end_comment

begin_define
define|#
directive|define
name|flex_die
parameter_list|(
name|msg
parameter_list|)
define|\
value|do{ \         fprintf (stderr,\                 _("%s: fatal internal error at %s:%d %s\n"),\                 program_name, __FILE__, (int)__LINE__,\                 msg);\         FLEX_EXIT(1);\     }while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! HAVE_DECL___func__ */
end_comment

begin_comment
comment|/* Convert a hexadecimal digit string to an integer value. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|htoi
name|PROTO
argument_list|(
operator|(
name|Char
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Report an error message formatted with one integer argument. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|lerrif
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Report an error message formatted with one string argument. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|lerrsf
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Like lerrsf, but also exit after displaying message. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|lerrsf_fatal
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Spit out a "#line" statement. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|line_directive_out
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mark the current position in the action array as the end of the section 1  * user defs.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mark_defs1
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mark the current position in the action array as the end of the prolog. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mark_prolog
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate a data statement for a two-dimensional array. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mk2data
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mkdata
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* generate a data statement */
end_comment

begin_comment
comment|/* Return the integer represented by a string of digits. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|myctoi
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return character corresponding to escape sequence. */
end_comment

begin_decl_stmt
specifier|extern
name|Char
name|myesc
name|PROTO
argument_list|(
operator|(
name|Char
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Convert an octal digit string to an integer value. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|otoi
name|PROTO
argument_list|(
operator|(
name|Char
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a (possibly-formatted) string to the generated scanner. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|out
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|out_dec
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|out_dec2
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|out_hex
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|out_str
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|out_str3
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|out_str_dec
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|outc
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|outn
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|out_m4_define
parameter_list|(
specifier|const
name|char
modifier|*
name|def
parameter_list|,
specifier|const
name|char
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a printable version of the given character, which might be  * 8-bit.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|readable_form
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write out one section of the skeleton file. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|skelout
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a yy_trans_info structure. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|transition_struct_out
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Only needed when using certain broken versions of bison to build parse.c. */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|yy_flex_xmalloc
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set a region of memory to 0. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|zero_out
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* from file nfa.c */
end_comment

begin_comment
comment|/* Add an accepting state to a machine. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|add_accept
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a given number of copies of a singleton machine. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|copysingl
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debugging routine to write out an nfa. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dumpnfa
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Finish up the processing for a rule. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|finish_rule
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Connect two machines together. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|link_machines
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mark each "beginning" state in a machine as being a "normal" (i.e.,  * not trailing context associated) state.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mark_beginning_as_normal
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a machine that branches to two machines. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mkbranch
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mkclos
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* convert a machine into a closure */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mkopt
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* make a machine optional */
end_comment

begin_comment
comment|/* Make a machine that matches either one of two machines. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mkor
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Convert a machine into a positive closure. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mkposcl
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mkrep
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* make a replicated machine */
end_comment

begin_comment
comment|/* Create a state with a transition on a given symbol. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mkstate
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|new_rule
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initialize for a new rule */
end_comment

begin_comment
comment|/* from file parse.y */
end_comment

begin_comment
comment|/* Build the "<<EOF>>" action for the active start conditions. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|build_eof_action
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write out a message formatted with one string, pinpointing its location. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|format_pinpoint_message
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write out a message, pinpointing its location. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|pinpoint_message
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write out a warning, pinpointing it at the given line. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|line_warning
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write out a message, pinpointing it at the given line. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|line_pinpoint
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Report a formatted syntax error. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|format_synerr
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|synerr
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* report a syntax error */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|format_warn
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|warn
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* report a warning */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|yyerror
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* report a parse error */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yyparse
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the YACC parser */
end_comment

begin_comment
comment|/* from file scan.l */
end_comment

begin_comment
comment|/* The Flex-generated scanner for flex. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flexscan
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Open the given file (if NULL, stdin) for scanning. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|set_input_file
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Wrapup a file in the lexical analyzer. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yywrap
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* from file sym.c */
end_comment

begin_comment
comment|/* Save the text of a character class. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cclinstal
name|PROTO
argument_list|(
operator|(
name|Char
index|[]
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lookup the number associated with character class. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ccllookup
name|PROTO
argument_list|(
operator|(
name|Char
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ndinstal
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|Char
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* install a name definition */
end_comment

begin_decl_stmt
specifier|extern
name|Char
modifier|*
name|ndlookup
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lookup a name definition */
end_comment

begin_comment
comment|/* Increase maximum number of SC's. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|scextend
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|scinstal
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* make a start condition */
end_comment

begin_comment
comment|/* Lookup the number associated with a start condition. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sclookup
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* from file tblcmp.c */
end_comment

begin_comment
comment|/* Build table entries for dfa state. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bldtbl
name|PROTO
argument_list|(
operator|(
name|int
index|[]
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cmptmps
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* compress template table entries */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|expand_nxt_chk
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* increase nxt/chk arrays */
end_comment

begin_comment
comment|/* Finds a space in the table for a state to be placed. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|find_table_space
name|PROTO
argument_list|(
operator|(
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|inittbl
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initialize transition tables */
end_comment

begin_comment
comment|/* Make the default, "jam" table entries. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mkdeftbl
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create table entries for a state (or state fragment) which has  * only one out-transition.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mk1tbl
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Place a state into full speed transition table. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|place_state
name|PROTO
argument_list|(
operator|(
name|int
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save states with only one out-transition to be processed later. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|stack1
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* from file yylex.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yylex
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A growable array. See buf.c. */
end_comment

begin_struct
struct|struct
name|Buf
block|{
name|void
modifier|*
name|elts
decl_stmt|;
comment|/* elements. */
name|int
name|nelts
decl_stmt|;
comment|/* number of elements. */
name|size_t
name|elt_size
decl_stmt|;
comment|/* in bytes. */
name|int
name|nmax
decl_stmt|;
comment|/* max capacity of elements. */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|void
name|buf_init
name|PROTO
argument_list|(
operator|(
expr|struct
name|Buf
operator|*
name|buf
operator|,
name|size_t
name|elem_size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|buf_destroy
name|PROTO
argument_list|(
operator|(
expr|struct
name|Buf
operator|*
name|buf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Buf
modifier|*
name|buf_append
name|PROTO
argument_list|(
operator|(
expr|struct
name|Buf
operator|*
name|buf
operator|,
specifier|const
name|void
operator|*
name|ptr
operator|,
name|int
name|n_elem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Buf
modifier|*
name|buf_concat
name|PROTO
argument_list|(
operator|(
expr|struct
name|Buf
operator|*
name|dest
operator|,
specifier|const
expr|struct
name|Buf
operator|*
name|src
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Buf
modifier|*
name|buf_strappend
name|PROTO
argument_list|(
operator|(
expr|struct
name|Buf
operator|*
operator|,
specifier|const
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Buf
modifier|*
name|buf_strnappend
name|PROTO
argument_list|(
operator|(
expr|struct
name|Buf
operator|*
operator|,
specifier|const
name|char
operator|*
name|str
operator|,
name|int
name|nchars
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Buf
modifier|*
name|buf_strdefine
name|PROTO
argument_list|(
operator|(
expr|struct
name|Buf
operator|*
name|buf
operator|,
specifier|const
name|char
operator|*
name|str
operator|,
specifier|const
name|char
operator|*
name|def
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Buf
modifier|*
name|buf_prints
name|PROTO
argument_list|(
operator|(
expr|struct
name|Buf
operator|*
name|buf
operator|,
specifier|const
name|char
operator|*
name|fmt
operator|,
specifier|const
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Buf
modifier|*
name|buf_m4_define
name|PROTO
argument_list|(
operator|(
expr|struct
name|Buf
operator|*
name|buf
operator|,
specifier|const
name|char
operator|*
name|def
operator|,
specifier|const
name|char
operator|*
name|val
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Buf
modifier|*
name|buf_m4_undefine
name|PROTO
argument_list|(
operator|(
expr|struct
name|Buf
operator|*
name|buf
operator|,
specifier|const
name|char
operator|*
name|def
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Buf
modifier|*
name|buf_print_strings
name|PROTO
argument_list|(
operator|(
expr|struct
name|Buf
operator|*
name|buf
operator|,
name|FILE
operator|*
name|out
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Buf
modifier|*
name|buf_linedir
name|PROTO
argument_list|(
operator|(
expr|struct
name|Buf
operator|*
name|buf
operator|,
specifier|const
name|char
operator|*
name|filename
operator|,
name|int
name|lineno
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Buf
name|userdef_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a string buffer for #define's generated by user-options on cmd line. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Buf
name|defs_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a char* buffer to save #define'd some symbols generated by flex. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Buf
name|yydmap_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a string buffer to hold yydmap elements */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Buf
name|m4defs_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Holds m4 definitions. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Buf
name|top_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* contains %top code. String buffer. */
end_comment

begin_comment
comment|/* For blocking out code from the header file. */
end_comment

begin_define
define|#
directive|define
name|OUT_BEGIN_CODE
parameter_list|()
value|outn("m4_ifdef( [[M4_YY_IN_HEADER]],,[[")
end_define

begin_define
define|#
directive|define
name|OUT_END_CODE
parameter_list|()
value|outn("]])")
end_define

begin_comment
comment|/* For setjmp/longjmp (instead of calling exit(2)). Linkage in main.c */
end_comment

begin_decl_stmt
specifier|extern
name|jmp_buf
name|flex_main_jmp_buf
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FLEX_EXIT
parameter_list|(
name|status
parameter_list|)
value|longjmp(flex_main_jmp_buf,(status)+1)
end_define

begin_comment
comment|/* Removes all \n and \r chars from tail of str. returns str. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|chomp
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ctype functions forced to return boolean */
end_comment

begin_define
define|#
directive|define
name|b_isalnum
parameter_list|(
name|c
parameter_list|)
value|(isalnum(c)?true:false)
end_define

begin_define
define|#
directive|define
name|b_isalpha
parameter_list|(
name|c
parameter_list|)
value|(isalpha(c)?true:false)
end_define

begin_define
define|#
directive|define
name|b_isascii
parameter_list|(
name|c
parameter_list|)
value|(isascii(c)?true:false)
end_define

begin_define
define|#
directive|define
name|b_isblank
parameter_list|(
name|c
parameter_list|)
value|(isblank(c)?true:false)
end_define

begin_define
define|#
directive|define
name|b_iscntrl
parameter_list|(
name|c
parameter_list|)
value|(iscntrl(c)?true:false)
end_define

begin_define
define|#
directive|define
name|b_isdigit
parameter_list|(
name|c
parameter_list|)
value|(isdigit(c)?true:false)
end_define

begin_define
define|#
directive|define
name|b_isgraph
parameter_list|(
name|c
parameter_list|)
value|(isgraph(c)?true:false)
end_define

begin_define
define|#
directive|define
name|b_islower
parameter_list|(
name|c
parameter_list|)
value|(islower(c)?true:false)
end_define

begin_define
define|#
directive|define
name|b_isprint
parameter_list|(
name|c
parameter_list|)
value|(isprint(c)?true:false)
end_define

begin_define
define|#
directive|define
name|b_ispunct
parameter_list|(
name|c
parameter_list|)
value|(ispunct(c)?true:false)
end_define

begin_define
define|#
directive|define
name|b_isspace
parameter_list|(
name|c
parameter_list|)
value|(isspace(c)?true:false)
end_define

begin_define
define|#
directive|define
name|b_isupper
parameter_list|(
name|c
parameter_list|)
value|(isupper(c)?true:false)
end_define

begin_define
define|#
directive|define
name|b_isxdigit
parameter_list|(
name|c
parameter_list|)
value|(isxdigit(c)?true:false)
end_define

begin_comment
comment|/* return true if char is uppercase or lowercase. */
end_comment

begin_function_decl
name|bool
name|has_case
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Change case of character if possible. */
end_comment

begin_function_decl
name|int
name|reverse_case
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return false if [c1-c2] is ambiguous for a caseless scanner. */
end_comment

begin_function_decl
name|bool
name|range_covers_case
parameter_list|(
name|int
name|c1
parameter_list|,
name|int
name|c2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  From "filter.c"  */
end_comment

begin_comment
comment|/** A single stdio filter to execute.  *  The filter may be external, such as "sed", or it  *  may be internal, as a function call.  */
end_comment

begin_struct
struct|struct
name|filter
block|{
name|int
function_decl|(
modifier|*
name|filter_func
function_decl|)
parameter_list|(
name|struct
name|filter
modifier|*
parameter_list|)
function_decl|;
comment|/**< internal filter function */
name|void
modifier|*
name|extra
decl_stmt|;
comment|/**< extra data passed to filter_func */
name|int
name|argc
decl_stmt|;
comment|/**< arg count */
specifier|const
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
comment|/**< arg vector, \0-terminated */
name|struct
name|filter
modifier|*
name|next
decl_stmt|;
comment|/**< next filter or NULL */
block|}
struct|;
end_struct

begin_comment
comment|/* output filter chain */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|filter
modifier|*
name|output_chain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|filter
modifier|*
name|filter_create_ext
name|PROTO
argument_list|(
operator|(
expr|struct
name|filter
operator|*
name|chain
operator|,
specifier|const
name|char
operator|*
name|cmd
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|filter
modifier|*
name|filter_create_int
name|PROTO
argument_list|(
operator|(
expr|struct
name|filter
operator|*
name|chain
operator|,
name|int
argument_list|(
operator|*
name|filter_func
argument_list|)
argument_list|(
expr|struct
name|filter
operator|*
argument_list|)
operator|,
name|void
operator|*
name|extra
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|filter_apply_chain
name|PROTO
argument_list|(
operator|(
expr|struct
name|filter
operator|*
name|chain
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|filter_truncate
parameter_list|(
name|struct
name|filter
modifier|*
name|chain
parameter_list|,
name|int
name|max_len
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|filter_tee_header
name|PROTO
argument_list|(
operator|(
expr|struct
name|filter
operator|*
name|chain
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|filter_fix_linedirs
name|PROTO
argument_list|(
operator|(
expr|struct
name|filter
operator|*
name|chain
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * From "regex.c"  */
end_comment

begin_decl_stmt
specifier|extern
name|regex_t
name|regex_linedir
decl_stmt|,
name|regex_blank_line
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|flex_init_regex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flex_regcomp
parameter_list|(
name|regex_t
modifier|*
name|preg
parameter_list|,
specifier|const
name|char
modifier|*
name|regex
parameter_list|,
name|int
name|cflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|regmatch_dup
parameter_list|(
name|regmatch_t
modifier|*
name|m
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|regmatch_cpy
parameter_list|(
name|regmatch_t
modifier|*
name|m
parameter_list|,
name|char
modifier|*
name|dest
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regmatch_len
parameter_list|(
name|regmatch_t
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regmatch_strtol
parameter_list|(
name|regmatch_t
modifier|*
name|m
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|char
modifier|*
modifier|*
name|endptr
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|regmatch_empty
parameter_list|(
name|regmatch_t
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From "scanflags.h" */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|scanflags_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|scanflags_t
modifier|*
name|_sf_stk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|_sf_top_ix
decl_stmt|,
name|_sf_max
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**< stack of scanner flags. */
end_comment

begin_define
define|#
directive|define
name|_SF_CASE_INS
value|0x0001
end_define

begin_define
define|#
directive|define
name|_SF_DOT_ALL
value|0x0002
end_define

begin_define
define|#
directive|define
name|_SF_SKIP_WS
value|0x0004
end_define

begin_define
define|#
directive|define
name|sf_top
parameter_list|()
value|(_sf_stk[_sf_top_ix])
end_define

begin_define
define|#
directive|define
name|sf_case_ins
parameter_list|()
value|(sf_top()& _SF_CASE_INS)
end_define

begin_define
define|#
directive|define
name|sf_dot_all
parameter_list|()
value|(sf_top()& _SF_DOT_ALL)
end_define

begin_define
define|#
directive|define
name|sf_skip_ws
parameter_list|()
value|(sf_top()& _SF_SKIP_WS)
end_define

begin_define
define|#
directive|define
name|sf_set_case_ins
parameter_list|(
name|X
parameter_list|)
value|((X) ? (sf_top() |= _SF_CASE_INS) : (sf_top()&= ~_SF_CASE_INS))
end_define

begin_define
define|#
directive|define
name|sf_set_dot_all
parameter_list|(
name|X
parameter_list|)
value|((X) ? (sf_top() |= _SF_DOT_ALL)  : (sf_top()&= ~_SF_DOT_ALL))
end_define

begin_define
define|#
directive|define
name|sf_set_skip_ws
parameter_list|(
name|X
parameter_list|)
value|((X) ? (sf_top() |= _SF_SKIP_WS)  : (sf_top()&= ~_SF_SKIP_WS))
end_define

begin_function_decl
specifier|extern
name|void
name|sf_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sf_push
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sf_pop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not defined FLEXDEF_H */
end_comment

end_unit

