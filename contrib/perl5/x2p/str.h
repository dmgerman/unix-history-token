begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: str.h,v $$Revision: 4.1 $$Date: 92/08/07 18:29:27 $  *  *    Copyright (c) 1991-2001, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log:	str.h,v $  */
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
name|double
name|str_2num
parameter_list|(
name|STR
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_2ptr
parameter_list|(
name|STR
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_append_till
parameter_list|(
name|STR
modifier|*
name|str
parameter_list|,
name|char
modifier|*
name|from
parameter_list|,
name|int
name|delim
parameter_list|,
name|char
modifier|*
name|keeplist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_cat
parameter_list|(
name|STR
modifier|*
name|str
parameter_list|,
name|char
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_chop
parameter_list|(
name|STR
modifier|*
name|str
parameter_list|,
name|char
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_dec
parameter_list|(
name|STR
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_free
parameter_list|(
name|STR
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_gets
parameter_list|(
name|STR
modifier|*
name|str
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_grow
parameter_list|(
name|STR
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_inc
parameter_list|(
name|STR
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|str_len
parameter_list|(
name|STR
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|str_make
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|str_mortal
parameter_list|(
name|STR
modifier|*
name|oldstr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_ncat
parameter_list|(
name|STR
modifier|*
name|str
parameter_list|,
name|char
modifier|*
name|ptr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|str_new
parameter_list|(
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|str_nmake
parameter_list|(
name|double
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_nset
parameter_list|(
name|STR
modifier|*
name|str
parameter_list|,
name|char
modifier|*
name|ptr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_numset
parameter_list|(
name|STR
modifier|*
name|str
parameter_list|,
name|double
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_replace
parameter_list|(
name|STR
modifier|*
name|str
parameter_list|,
name|STR
modifier|*
name|nstr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_scat
parameter_list|(
name|STR
modifier|*
name|dstr
parameter_list|,
name|STR
modifier|*
name|sstr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_set
parameter_list|(
name|STR
modifier|*
name|str
parameter_list|,
name|char
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|str_sset
parameter_list|(
name|STR
modifier|*
name|dstr
parameter_list|,
name|STR
modifier|*
name|sstr
parameter_list|)
function_decl|;
end_function_decl

end_unit

