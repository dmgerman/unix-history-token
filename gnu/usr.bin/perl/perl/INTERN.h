begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: INTERN.h,v $$Revision: 1.1.1.1 $$Date: 1994/09/10 06:27:34 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: INTERN.h,v $  * Revision 1.1.1.1  1994/09/10  06:27:34  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:29:33  nate  * PERL!  *  * Revision 4.0.1.1  91/06/07  10:10:42  lwall  * patch4: new copyright notice  *  * Revision 4.0  91/03/20  00:58:35  lwall  * 4.0 baseline.  *  */
end_comment

begin_undef
undef|#
directive|undef
name|EXT
end_undef

begin_define
define|#
directive|define
name|EXT
end_define

begin_undef
undef|#
directive|undef
name|INIT
end_undef

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|x
parameter_list|)
value|= x
end_define

begin_define
define|#
directive|define
name|DOINIT
end_define

end_unit

