begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: form.h,v $$Revision: 1.2 $$Date: 1995/05/30 05:03:05 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: form.h,v $  * Revision 1.2  1995/05/30 05:03:05  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1994/09/10  06:27:34  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:29:36  nate  * PERL!  *  * Revision 4.0.1.1  91/06/07  11:08:20  lwall  * patch4: new copyright notice  *  * Revision 4.0  91/03/20  01:19:37  lwall  * 4.0 baseline.  *  */
end_comment

begin_define
define|#
directive|define
name|F_NULL
value|0
end_define

begin_define
define|#
directive|define
name|F_LEFT
value|1
end_define

begin_define
define|#
directive|define
name|F_RIGHT
value|2
end_define

begin_define
define|#
directive|define
name|F_CENTER
value|3
end_define

begin_define
define|#
directive|define
name|F_LINES
value|4
end_define

begin_define
define|#
directive|define
name|F_DECIMAL
value|5
end_define

begin_struct
struct|struct
name|formcmd
block|{
name|struct
name|formcmd
modifier|*
name|f_next
decl_stmt|;
name|ARG
modifier|*
name|f_expr
decl_stmt|;
name|STR
modifier|*
name|f_unparsed
decl_stmt|;
name|line_t
name|f_line
decl_stmt|;
name|char
modifier|*
name|f_pre
decl_stmt|;
name|short
name|f_presize
decl_stmt|;
name|short
name|f_size
decl_stmt|;
name|short
name|f_decimals
decl_stmt|;
name|char
name|f_type
decl_stmt|;
name|char
name|f_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FC_CHOP
value|1
end_define

begin_define
define|#
directive|define
name|FC_NOBLANK
value|2
end_define

begin_define
define|#
directive|define
name|FC_MORE
value|4
end_define

begin_define
define|#
directive|define
name|FC_REPEAT
value|8
end_define

begin_define
define|#
directive|define
name|FC_DP
value|16
end_define

begin_define
define|#
directive|define
name|Nullfcmd
value|Null(FCMD*)
end_define

begin_decl_stmt
name|EXT
name|char
modifier|*
name|chopset
name|INIT
argument_list|(
literal|" \n-"
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

