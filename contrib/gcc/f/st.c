begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* st.c -- Implementation File (module.c template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Related Modules:       None     Description:       The high-level input level to statement handling for the rest of the       FFE.  ffest_first is the first state for the lexer to invoke to start       a statement.  A statement normally starts with a NUMBER token (to indicate       a label def) followed by a NAME token (to indicate what kind of statement       it is), though of course the NUMBER token may be omitted.	 ffest_first       gathers the first NAME token and returns a state of ffest_second_,       where the trailing underscore means "internal to ffest" and thus outside       users should not depend on this.	ffest_second_ then looks at the second       token in conjunction with the first, decides what possible statements are       meant, and tries each possible statement in turn, from most likely to       least likely.  A successful attempt currently is recorded, and further       successful attempts by other possibilities raise an assertion error in       ffest_confirmed (this is to detect ambiguities).	A failure in an       attempt is signaled by calling ffest_ffebad_start; this results in the       next token sent by ffest_save_ (the intermediary when more than one       possible statement exists) being EOS to shut down processing and the next       possibility tried.        When all possibilities have been tried, the successful one is retried with       inhibition turned off (FALSE) as reported by ffest_is_inhibited().  If       there is no successful one, the first one is retried so the user gets to       see the error messages.        In the future, after syntactic bugs have been reasonably shaken out and       ambiguities thus detected, the first successful possibility will be       enabled (inhibited goes FALSE) as soon as it confirms success by calling       ffest_confirmed, thus retrying the possibility will not be necessary.        The only complication in all this is that expression handling is       happening while possibilities are inhibited.  It is up to the expression       handler, conceptually, to not make any changes to its knowledge base for       variable names and so on when inhibited that cannot be undone if       the current possibility fails (shuts down via ffest_ffebad_start).  In       fact, this business is handled not be ffeexpr, but by lower levels.        ffesta functions serve only to provide information used in syntactic       processing of possible statements, and thus may not make changes to the       knowledge base for variables and such.        ffestb functions perform the syntactic analysis for possible statements,       and thus again may not make changes to the knowledge base except under the       auspices of ffeexpr and its subordinates, changes which can be undone when       necessary.        ffestc functions perform the semantic analysis for the chosen statement,       and thus may change the knowledge base as necessary since they are invoked       by ffestb functions only after a given statement is confirmed and       enabled.	Note, however, that a few ffestc functions (identified by       their statement names rather than grammar numbers) indicate valid forms       that are, outside of any context, ambiguous, such as ELSE WHERE and       PRIVATE; these functions should make a quick decision as to what is       intended and dispatch to the appropriate specific ffestc function.        ffestd functions actually implement statements.  When called, the       statement is considered valid and is either an executable statement or       a nonexecutable statement with direct-output results.  For example, CALL,       GOTO, and assignment statements pass through ffestd because they are       executable; DATA statements pass through because they map directly to the       output file (or at least might so map); ENTRY statements also pass through       because they essentially affect code generation in an immediate way;       whereas INTEGER, SAVE, and SUBROUTINE statements do not go through       ffestd functions because they merely update the knowledge base.     Modifications: */
end_comment

begin_comment
comment|/* Include files. */
end_comment

begin_include
include|#
directive|include
file|"proj.h"
end_include

begin_include
include|#
directive|include
file|"st.h"
end_include

begin_include
include|#
directive|include
file|"bad.h"
end_include

begin_include
include|#
directive|include
file|"lex.h"
end_include

begin_include
include|#
directive|include
file|"sta.h"
end_include

begin_include
include|#
directive|include
file|"stb.h"
end_include

begin_include
include|#
directive|include
file|"stc.h"
end_include

begin_include
include|#
directive|include
file|"std.h"
end_include

begin_include
include|#
directive|include
file|"ste.h"
end_include

begin_include
include|#
directive|include
file|"stp.h"
end_include

begin_include
include|#
directive|include
file|"str.h"
end_include

begin_include
include|#
directive|include
file|"sts.h"
end_include

begin_include
include|#
directive|include
file|"stt.h"
end_include

begin_include
include|#
directive|include
file|"stu.h"
end_include

begin_include
include|#
directive|include
file|"stv.h"
end_include

begin_include
include|#
directive|include
file|"stw.h"
end_include

begin_comment
comment|/* Externals defined here. */
end_comment

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_comment
comment|/* Internal typedefs. */
end_comment

begin_comment
comment|/* Private include files. */
end_comment

begin_comment
comment|/* Internal structure definitions. */
end_comment

begin_comment
comment|/* Static objects accessed by functions in this module. */
end_comment

begin_comment
comment|/* Static functions (internal). */
end_comment

begin_comment
comment|/* Internal macros. */
end_comment

begin_escape
end_escape

begin_comment
comment|/* ffest_confirmed -- Confirm current possibility as only one     ffest_confirmed();     Sets the confirmation flag.	During debugging for ambiguous constructs,    asserts that the confirmation flag for a previous possibility has not    yet been set.  */
end_comment

begin_function
name|void
name|ffest_confirmed
parameter_list|()
block|{
name|ffesta_confirmed
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ffest_eof -- End of (non-INCLUDEd) source file     ffest_eof();     Call after piping tokens through ffest_first, where the most recent    token sent through must be EOS.     20-Feb-91  JCB  1.1       Put new EOF token in ffesta_tokens[0], not NULL, because too much       code expects something there for error reporting and the like.  Also,       do basically the same things ffest_second and ffesta_zero do for       processing a statement (make and destroy pools, et cetera).  */
end_comment

begin_function
name|void
name|ffest_eof
parameter_list|()
block|{
name|ffesta_eof
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ffest_ffebad_here_current_stmt -- ffebad_here with ptr to current stmt     ffest_ffebad_here_current_stmt(0);     Outsiders can call this fn if they have no more convenient place to    point to (via a token or pair of ffewhere objects) and they know a    current, useful statement is being evaluted by ffest (i.e. they are    being called from ffestb, ffestc, ffestd, ... functions).  */
end_comment

begin_function
name|void
name|ffest_ffebad_here_current_stmt
parameter_list|(
name|ffebadIndex
name|i
parameter_list|)
block|{
name|ffesta_ffebad_here_current_stmt
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ffest_ffebad_here_doiter -- Calls ffebad_here with ptr to DO iter var     ffesymbol s;    // call ffebad_start first, of course.    ffest_ffebad_here_doiter(0,s);    // call ffebad_finish afterwards, naturally.     Searches the stack of blocks backwards for a DO loop that has s    as its iteration variable, then calls ffebad_here with pointers to    that particular reference to the variable.  Crashes if the DO loop    can't be found.  */
end_comment

begin_function
name|void
name|ffest_ffebad_here_doiter
parameter_list|(
name|ffebadIndex
name|i
parameter_list|,
name|ffesymbol
name|s
parameter_list|)
block|{
name|ffestc_ffebad_here_doiter
argument_list|(
name|i
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ffest_ffebad_start -- Start a possibly inhibited error report     if (ffest_ffebad_start(FFEBAD_SOME_ERROR))        {        ffebad_here, ffebad_string ...;        ffebad_finish();        }     Call if the error might indicate that ffest is evaluating the wrong    statement form, instead of calling ffebad_start directly.  If ffest    is choosing between forms, it will return FALSE, send an EOS/SEMICOLON    token through as the next token (if the current one isn't already one    of those), and try another possible form.  Otherwise, ffebad_start is    called with the argument and TRUE returned.	*/
end_comment

begin_function
name|bool
name|ffest_ffebad_start
parameter_list|(
name|ffebad
name|errnum
parameter_list|)
block|{
return|return
name|ffesta_ffebad_start
argument_list|(
name|errnum
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* ffest_first -- Parse the first token in a statement     return ffest_first;	// to lexer.  */
end_comment

begin_function
name|ffelexHandler
name|ffest_first
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
block|{
return|return
name|ffesta_first
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* ffest_init_0 -- Initialize for entire image invocation     ffest_init_0();     Call just once per invocation of the compiler (not once per invocation    of the front end).     Gets memory for the list of possibles once and for all, since this    list never gets larger than a certain size (FFEST_maxPOSSIBLES_)    and is not particularly large.  Initializes the array of pointers to    this list.  Initializes the executable and nonexecutable lists.  */
end_comment

begin_function
name|void
name|ffest_init_0
parameter_list|()
block|{
name|ffesta_init_0
argument_list|()
expr_stmt|;
name|ffestb_init_0
argument_list|()
expr_stmt|;
name|ffestc_init_0
argument_list|()
expr_stmt|;
name|ffestd_init_0
argument_list|()
expr_stmt|;
name|ffeste_init_0
argument_list|()
expr_stmt|;
name|ffestp_init_0
argument_list|()
expr_stmt|;
name|ffestr_init_0
argument_list|()
expr_stmt|;
name|ffests_init_0
argument_list|()
expr_stmt|;
name|ffestt_init_0
argument_list|()
expr_stmt|;
name|ffestu_init_0
argument_list|()
expr_stmt|;
name|ffestv_init_0
argument_list|()
expr_stmt|;
name|ffestw_init_0
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ffest_init_1 -- Initialize for entire image invocation     ffest_init_1();     Call just once per invocation of the compiler (not once per invocation    of the front end).     Gets memory for the list of possibles once and for all, since this    list never gets larger than a certain size (FFEST_maxPOSSIBLES_)    and is not particularly large.  Initializes the array of pointers to    this list.  Initializes the executable and nonexecutable lists.  */
end_comment

begin_function
name|void
name|ffest_init_1
parameter_list|()
block|{
name|ffesta_init_1
argument_list|()
expr_stmt|;
name|ffestb_init_1
argument_list|()
expr_stmt|;
name|ffestc_init_1
argument_list|()
expr_stmt|;
name|ffestd_init_1
argument_list|()
expr_stmt|;
name|ffeste_init_1
argument_list|()
expr_stmt|;
name|ffestp_init_1
argument_list|()
expr_stmt|;
name|ffestr_init_1
argument_list|()
expr_stmt|;
name|ffests_init_1
argument_list|()
expr_stmt|;
name|ffestt_init_1
argument_list|()
expr_stmt|;
name|ffestu_init_1
argument_list|()
expr_stmt|;
name|ffestv_init_1
argument_list|()
expr_stmt|;
name|ffestw_init_1
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ffest_init_2 -- Initialize for entire image invocation     ffest_init_2();     Call just once per invocation of the compiler (not once per invocation    of the front end).     Gets memory for the list of possibles once and for all, since this    list never gets larger than a certain size (FFEST_maxPOSSIBLES_)    and is not particularly large.  Initializes the array of pointers to    this list.  Initializes the executable and nonexecutable lists.  */
end_comment

begin_function
name|void
name|ffest_init_2
parameter_list|()
block|{
name|ffesta_init_2
argument_list|()
expr_stmt|;
name|ffestb_init_2
argument_list|()
expr_stmt|;
name|ffestc_init_2
argument_list|()
expr_stmt|;
name|ffestd_init_2
argument_list|()
expr_stmt|;
name|ffeste_init_2
argument_list|()
expr_stmt|;
name|ffestp_init_2
argument_list|()
expr_stmt|;
name|ffestr_init_2
argument_list|()
expr_stmt|;
name|ffests_init_2
argument_list|()
expr_stmt|;
name|ffestt_init_2
argument_list|()
expr_stmt|;
name|ffestu_init_2
argument_list|()
expr_stmt|;
name|ffestv_init_2
argument_list|()
expr_stmt|;
name|ffestw_init_2
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ffest_init_3 -- Initialize for any program unit     ffest_init_3();  */
end_comment

begin_function
name|void
name|ffest_init_3
parameter_list|()
block|{
name|ffesta_init_3
argument_list|()
expr_stmt|;
name|ffestb_init_3
argument_list|()
expr_stmt|;
name|ffestc_init_3
argument_list|()
expr_stmt|;
name|ffestd_init_3
argument_list|()
expr_stmt|;
name|ffeste_init_3
argument_list|()
expr_stmt|;
name|ffestp_init_3
argument_list|()
expr_stmt|;
name|ffestr_init_3
argument_list|()
expr_stmt|;
name|ffests_init_3
argument_list|()
expr_stmt|;
name|ffestt_init_3
argument_list|()
expr_stmt|;
name|ffestu_init_3
argument_list|()
expr_stmt|;
name|ffestv_init_3
argument_list|()
expr_stmt|;
name|ffestw_init_3
argument_list|()
expr_stmt|;
name|ffestw_display_state
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ffest_init_4 -- Initialize for statement functions     ffest_init_4();  */
end_comment

begin_function
name|void
name|ffest_init_4
parameter_list|()
block|{
name|ffesta_init_4
argument_list|()
expr_stmt|;
name|ffestb_init_4
argument_list|()
expr_stmt|;
name|ffestc_init_4
argument_list|()
expr_stmt|;
name|ffestd_init_4
argument_list|()
expr_stmt|;
name|ffeste_init_4
argument_list|()
expr_stmt|;
name|ffestp_init_4
argument_list|()
expr_stmt|;
name|ffestr_init_4
argument_list|()
expr_stmt|;
name|ffests_init_4
argument_list|()
expr_stmt|;
name|ffestt_init_4
argument_list|()
expr_stmt|;
name|ffestu_init_4
argument_list|()
expr_stmt|;
name|ffestv_init_4
argument_list|()
expr_stmt|;
name|ffestw_init_4
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Test whether ENTRY statement is valid.     Returns TRUE if current program unit is known to be FUNCTION or SUBROUTINE.    Else returns FALSE.  */
end_comment

begin_function
name|bool
name|ffest_is_entry_valid
parameter_list|()
block|{
return|return
name|ffesta_is_entry_valid
return|;
block|}
end_function

begin_comment
comment|/* ffest_is_inhibited -- Test whether the current possibility is inhibited     if (!ffest_is_inhibited())        // implement the statement.     Just make sure the current possibility has been confirmed.  If anyone    really needs to test whether the current possibility is inhibited prior    to confirming it, that indicates a need to begin statement processing    before it is certain that the given possibility is indeed the statement    to be processed.  As of this writing, there does not appear to be such    a need.  If there is, then when confirming a statement would normally    immediately disable the inhibition (whereas currently we leave the    confirmed statement disabled until we've tried the other possibilities,    to check for ambiguities), we must check to see if the possibility has    already tested for inhibition prior to confirmation and, if so, maintain    inhibition until the end of the statement (which may be forced right    away) and then rerun the entire statement from the beginning.  Otherwise,    initial calls to ffestb functions won't have been made, but subsequent    calls (after confirmation) will, which is wrong.  Of course, this all    applies only to those statements implemented via multiple calls to    ffestb, although if a statement requiring only a single ffestb call    tested for inhibition prior to confirmation, it would likely mean that    the ffestb call would be completely dropped without this mechanism.	*/
end_comment

begin_function
name|bool
name|ffest_is_inhibited
parameter_list|()
block|{
return|return
name|ffesta_is_inhibited
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/* ffest_seen_first_exec -- Test whether first executable stmt has been seen     if (ffest_seen_first_exec())        // No more spec stmts can be seen.     In a case where, say, the first statement is PARAMETER(A)=B, FALSE    will be returned while the PARAMETER statement is being run, and TRUE    will be returned if it doesn't confirm and the assignment statement    is being run.  */
end_comment

begin_function
name|bool
name|ffest_seen_first_exec
parameter_list|()
block|{
return|return
name|ffesta_seen_first_exec
return|;
block|}
end_function

begin_comment
comment|/* Shut down current parsing possibility, but without bothering the    user with a diagnostic if we're not inhibited.  */
end_comment

begin_function
name|void
name|ffest_shutdown
parameter_list|()
block|{
name|ffesta_shutdown
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ffest_sym_end_transition -- Update symbol info just before end of unit     ffesymbol s;    ffest_sym_end_transition(s);	 */
end_comment

begin_function
name|ffesymbol
name|ffest_sym_end_transition
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
block|{
return|return
name|ffestu_sym_end_transition
argument_list|(
name|s
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* ffest_sym_exec_transition -- Update symbol just before first exec stmt     ffesymbol s;    ffest_sym_exec_transition(s);  */
end_comment

begin_function
name|ffesymbol
name|ffest_sym_exec_transition
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
block|{
return|return
name|ffestu_sym_exec_transition
argument_list|(
name|s
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* ffest_terminate_0 -- Terminate for entire image invocation     ffest_terminate_0();	 */
end_comment

begin_function
name|void
name|ffest_terminate_0
parameter_list|()
block|{
name|ffesta_terminate_0
argument_list|()
expr_stmt|;
name|ffestb_terminate_0
argument_list|()
expr_stmt|;
name|ffestc_terminate_0
argument_list|()
expr_stmt|;
name|ffestd_terminate_0
argument_list|()
expr_stmt|;
name|ffeste_terminate_0
argument_list|()
expr_stmt|;
name|ffestp_terminate_0
argument_list|()
expr_stmt|;
name|ffestr_terminate_0
argument_list|()
expr_stmt|;
name|ffests_terminate_0
argument_list|()
expr_stmt|;
name|ffestt_terminate_0
argument_list|()
expr_stmt|;
name|ffestu_terminate_0
argument_list|()
expr_stmt|;
name|ffestv_terminate_0
argument_list|()
expr_stmt|;
name|ffestw_terminate_0
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ffest_terminate_1 -- Terminate for source file     ffest_terminate_1();	 */
end_comment

begin_function
name|void
name|ffest_terminate_1
parameter_list|()
block|{
name|ffesta_terminate_1
argument_list|()
expr_stmt|;
name|ffestb_terminate_1
argument_list|()
expr_stmt|;
name|ffestc_terminate_1
argument_list|()
expr_stmt|;
name|ffestd_terminate_1
argument_list|()
expr_stmt|;
name|ffeste_terminate_1
argument_list|()
expr_stmt|;
name|ffestp_terminate_1
argument_list|()
expr_stmt|;
name|ffestr_terminate_1
argument_list|()
expr_stmt|;
name|ffests_terminate_1
argument_list|()
expr_stmt|;
name|ffestt_terminate_1
argument_list|()
expr_stmt|;
name|ffestu_terminate_1
argument_list|()
expr_stmt|;
name|ffestv_terminate_1
argument_list|()
expr_stmt|;
name|ffestw_terminate_1
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ffest_terminate_2 -- Terminate for outer program unit     ffest_terminate_2();	 */
end_comment

begin_function
name|void
name|ffest_terminate_2
parameter_list|()
block|{
name|ffesta_terminate_2
argument_list|()
expr_stmt|;
name|ffestb_terminate_2
argument_list|()
expr_stmt|;
name|ffestc_terminate_2
argument_list|()
expr_stmt|;
name|ffestd_terminate_2
argument_list|()
expr_stmt|;
name|ffeste_terminate_2
argument_list|()
expr_stmt|;
name|ffestp_terminate_2
argument_list|()
expr_stmt|;
name|ffestr_terminate_2
argument_list|()
expr_stmt|;
name|ffests_terminate_2
argument_list|()
expr_stmt|;
name|ffestt_terminate_2
argument_list|()
expr_stmt|;
name|ffestu_terminate_2
argument_list|()
expr_stmt|;
name|ffestv_terminate_2
argument_list|()
expr_stmt|;
name|ffestw_terminate_2
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ffest_terminate_3 -- Terminate for any program unit     ffest_terminate_3();	 */
end_comment

begin_function
name|void
name|ffest_terminate_3
parameter_list|()
block|{
name|ffesta_terminate_3
argument_list|()
expr_stmt|;
name|ffestb_terminate_3
argument_list|()
expr_stmt|;
name|ffestc_terminate_3
argument_list|()
expr_stmt|;
name|ffestd_terminate_3
argument_list|()
expr_stmt|;
name|ffeste_terminate_3
argument_list|()
expr_stmt|;
name|ffestp_terminate_3
argument_list|()
expr_stmt|;
name|ffestr_terminate_3
argument_list|()
expr_stmt|;
name|ffests_terminate_3
argument_list|()
expr_stmt|;
name|ffestt_terminate_3
argument_list|()
expr_stmt|;
name|ffestu_terminate_3
argument_list|()
expr_stmt|;
name|ffestv_terminate_3
argument_list|()
expr_stmt|;
name|ffestw_terminate_3
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ffest_terminate_4 -- Terminate for statement functions     ffest_terminate_4();	 */
end_comment

begin_function
name|void
name|ffest_terminate_4
parameter_list|()
block|{
name|ffesta_terminate_4
argument_list|()
expr_stmt|;
name|ffestb_terminate_4
argument_list|()
expr_stmt|;
name|ffestc_terminate_4
argument_list|()
expr_stmt|;
name|ffestd_terminate_4
argument_list|()
expr_stmt|;
name|ffeste_terminate_4
argument_list|()
expr_stmt|;
name|ffestp_terminate_4
argument_list|()
expr_stmt|;
name|ffestr_terminate_4
argument_list|()
expr_stmt|;
name|ffests_terminate_4
argument_list|()
expr_stmt|;
name|ffestt_terminate_4
argument_list|()
expr_stmt|;
name|ffestu_terminate_4
argument_list|()
expr_stmt|;
name|ffestv_terminate_4
argument_list|()
expr_stmt|;
name|ffestw_terminate_4
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

