begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: array.h,v $$Revision: 1.2 $$Date: 1995/05/30 05:02:51 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: array.h,v $  * Revision 1.2  1995/05/30 05:02:51  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1994/09/10  06:27:34  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:29:34  nate  * PERL!  *  * Revision 4.0.1.2  92/06/08  11:45:57  lwall  * patch20: removed implicit int declarations on funcions  *  * Revision 4.0.1.1  91/06/07  10:19:20  lwall  * patch4: new copyright notice  *  * Revision 4.0  91/03/20  01:03:44  lwall  * 4.0 baseline.  *  */
end_comment

begin_struct
struct|struct
name|atbl
block|{
name|STR
modifier|*
modifier|*
name|ary_array
decl_stmt|;
name|STR
modifier|*
modifier|*
name|ary_alloc
decl_stmt|;
name|STR
modifier|*
name|ary_magic
decl_stmt|;
name|int
name|ary_max
decl_stmt|;
name|int
name|ary_fill
decl_stmt|;
name|char
name|ary_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ARF_REAL
value|1
end_define

begin_comment
comment|/* free old entries */
end_comment

begin_function_decl
name|STR
modifier|*
name|afetch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|astore
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|apop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|ashift
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|afree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aclear
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|apush
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|alen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARRAY
modifier|*
name|anew
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ARRAY
modifier|*
name|afake
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aunshift
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|afill
parameter_list|()
function_decl|;
end_function_decl

end_unit

