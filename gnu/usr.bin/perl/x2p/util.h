begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: util.h,v $$Revision: 1.2.6.1 $$Date: 1997/02/23 11:46:32 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: util.h,v $  * Revision 1.2.6.1  1997/02/23 11:46:32  joerg  * YAMFC (rev 1.3: remove bogus redeclaration of getenv())  *  * Revision 1.2  1995/05/30 05:03:46  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1994/09/10  06:27:55  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:30:10  nate  * PERL!  *  * Revision 4.0.1.2  91/11/05  19:21:20  lwall  * patch11: various portability fixes  *  * Revision 4.0.1.1  91/06/07  12:20:43  lwall  * patch4: new copyright notice  *  * Revision 4.0  91/03/20  01:58:29  lwall  * 4.0 baseline.  *  */
end_comment

begin_comment
comment|/* is the string for makedir a directory name or a filename? */
end_comment

begin_define
define|#
directive|define
name|fatal
value|Myfatal
end_define

begin_define
define|#
directive|define
name|MD_DIR
value|0
end_define

begin_define
define|#
directive|define
name|MD_FILE
value|1
end_define

begin_function_decl
name|void
name|util_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|doshell
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|safemalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|saferealloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|safecpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|safecat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cpytill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cpy2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|instr
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SETUIDGID
end_ifdef

begin_function_decl
name|int
name|eaccess
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|getwd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prexit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_a_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|savestr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|makedir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|envix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|notincl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|growstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setdef
parameter_list|()
function_decl|;
end_function_decl

end_unit

