begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: spat.h,v $$Revision: 1.2 $$Date: 1995/05/30 05:03:18 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: spat.h,v $  * Revision 1.2  1995/05/30 05:03:18  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1994/09/10  06:27:35  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:29:39  nate  * PERL!  *  * Revision 4.0.1.1  91/06/07  11:51:59  lwall  * patch4: new copyright notice  * patch4: added global modifier for pattern matches  *  * Revision 4.0  91/03/20  01:39:36  lwall  * 4.0 baseline.  *  */
end_comment

begin_struct
struct|struct
name|scanpat
block|{
name|SPAT
modifier|*
name|spat_next
decl_stmt|;
comment|/* list of all scanpats */
name|REGEXP
modifier|*
name|spat_regexp
decl_stmt|;
comment|/* compiled expression */
name|ARG
modifier|*
name|spat_repl
decl_stmt|;
comment|/* replacement string for subst */
name|ARG
modifier|*
name|spat_runtime
decl_stmt|;
comment|/* compile pattern at runtime */
name|STR
modifier|*
name|spat_short
decl_stmt|;
comment|/* for a fast bypass of execute() */
name|short
name|spat_flags
decl_stmt|;
name|char
name|spat_slen
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SPAT_USED
value|1
end_define

begin_comment
comment|/* spat has been used once already */
end_comment

begin_define
define|#
directive|define
name|SPAT_ONCE
value|2
end_define

begin_comment
comment|/* use pattern only once per reset */
end_comment

begin_define
define|#
directive|define
name|SPAT_SCANFIRST
value|4
end_define

begin_comment
comment|/* initial constant not anchored */
end_comment

begin_define
define|#
directive|define
name|SPAT_ALL
value|8
end_define

begin_comment
comment|/* initial constant is whole pat */
end_comment

begin_define
define|#
directive|define
name|SPAT_SKIPWHITE
value|16
end_define

begin_comment
comment|/* skip leading whitespace for split */
end_comment

begin_define
define|#
directive|define
name|SPAT_FOLD
value|32
end_define

begin_comment
comment|/* case insensitivity */
end_comment

begin_define
define|#
directive|define
name|SPAT_CONST
value|64
end_define

begin_comment
comment|/* subst replacement is constant */
end_comment

begin_define
define|#
directive|define
name|SPAT_KEEP
value|128
end_define

begin_comment
comment|/* keep 1st runtime pattern forever */
end_comment

begin_define
define|#
directive|define
name|SPAT_GLOBAL
value|256
end_define

begin_comment
comment|/* pattern had a g modifier */
end_comment

begin_decl_stmt
name|EXT
name|SPAT
modifier|*
name|curspat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* what to do \ interps from */
end_comment

begin_decl_stmt
name|EXT
name|SPAT
modifier|*
name|lastspat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* what to use in place of null pattern */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|hint
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* hint from cmd_exec to do_match et al */
end_comment

begin_define
define|#
directive|define
name|Nullspat
value|Null(SPAT*)
end_define

end_unit

