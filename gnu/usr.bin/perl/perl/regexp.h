begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions etc. for regexp(3) routines.  *  * Caveat:  this is V8 regexp(3) [actually, a reimplementation thereof],  * not the System V one.  */
end_comment

begin_comment
comment|/* $RCSfile: regexp.h,v $$Revision: 1.2 $$Date: 1995/05/30 05:03:17 $  *  * $Log: regexp.h,v $  * Revision 1.2  1995/05/30 05:03:17  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1994/09/10  06:27:35  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:29:39  nate  * PERL!  *  * Revision 4.0.1.2  91/11/05  18:24:31  lwall  * patch11: minimum match length calculation in regexp is now cumulative  * patch11: initial .* in pattern had dependency on value of $*  *  * Revision 4.0.1.1  91/06/07  11:51:18  lwall  * patch4: new copyright notice  * patch4: // wouldn't use previous pattern if it started with a null character  * patch4: $` was busted inside s///  *  * Revision 4.0  91/03/20  01:39:23  lwall  * 4.0 baseline.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|regexp
block|{
name|char
modifier|*
modifier|*
name|startp
decl_stmt|;
name|char
modifier|*
modifier|*
name|endp
decl_stmt|;
name|STR
modifier|*
name|regstart
decl_stmt|;
comment|/* Internal use only. */
name|char
modifier|*
name|regstclass
decl_stmt|;
name|STR
modifier|*
name|regmust
decl_stmt|;
comment|/* Internal use only. */
name|int
name|regback
decl_stmt|;
comment|/* Can regmust locate first try? */
name|int
name|minlen
decl_stmt|;
comment|/* mininum possible length of $& */
name|int
name|prelen
decl_stmt|;
comment|/* length of precomp */
name|char
modifier|*
name|precomp
decl_stmt|;
comment|/* pre-compilation regular expression */
name|char
modifier|*
name|subbase
decl_stmt|;
comment|/* saved string so \digit works forever */
name|char
modifier|*
name|subbeg
decl_stmt|;
comment|/* same, but not responsible for allocation */
name|char
modifier|*
name|subend
decl_stmt|;
comment|/* end of subbase */
name|char
name|reganch
decl_stmt|;
comment|/* Internal use only. */
name|char
name|do_folding
decl_stmt|;
comment|/* do case-insensitive match? */
name|char
name|lastparen
decl_stmt|;
comment|/* last paren matched */
name|char
name|nparens
decl_stmt|;
comment|/* number of parentheses */
name|char
name|program
index|[
literal|1
index|]
decl_stmt|;
comment|/* Unwarranted chumminess with compiler. */
block|}
name|regexp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ROPT_ANCH
value|1
end_define

begin_define
define|#
directive|define
name|ROPT_SKIP
value|2
end_define

begin_define
define|#
directive|define
name|ROPT_IMPLICIT
value|4
end_define

begin_function_decl
name|regexp
modifier|*
name|regcomp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|regexec
parameter_list|()
function_decl|;
end_function_decl

end_unit

