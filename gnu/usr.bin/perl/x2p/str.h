begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: str.h,v $$Revision: 1.2 $$Date: 1995/05/30 05:03:45 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: str.h,v $  * Revision 1.2  1995/05/30 05:03:45  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1994/09/10  06:27:55  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:30:10  nate  * PERL!  *  * Revision 4.0.1.1  91/06/07  12:20:22  lwall  * patch4: new copyright notice  *  * Revision 4.0  91/03/20  01:58:21  lwall  * 4.0 baseline.  *  */
end_comment

begin_struct
struct|struct
name|string
block|{
name|char
modifier|*
name|str_ptr
decl_stmt|;
comment|/* pointer to malloced string */
name|double
name|str_nval
decl_stmt|;
comment|/* numeric value, if any */
name|int
name|str_len
decl_stmt|;
comment|/* allocated size */
name|int
name|str_cur
decl_stmt|;
comment|/* length of str_ptr as a C string */
union|union
block|{
name|STR
modifier|*
name|str_next
decl_stmt|;
comment|/* while free, link to next free str */
block|}
name|str_link
union|;
name|char
name|str_pok
decl_stmt|;
comment|/* state of str_ptr */
name|char
name|str_nok
decl_stmt|;
comment|/* state of str_nval */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|Nullstr
value|Null(STR*)
end_define

begin_comment
comment|/* the following macro updates any magic values this str is associated with */
end_comment

begin_define
define|#
directive|define
name|STABSET
parameter_list|(
name|x
parameter_list|)
value|(x->str_link.str_magic&& stabset(x->str_link.str_magic,x))
end_define

begin_decl_stmt
name|EXT
name|STR
modifier|*
modifier|*
name|tmps_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|long
name|tmps_max
name|INIT
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|str_2ptr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|str_2num
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|str_mortal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|str_make
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|str_nmake
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_gets
parameter_list|()
function_decl|;
end_function_decl

end_unit

