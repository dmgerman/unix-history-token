begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: handy.h,v $$Revision: 1.2 $$Date: 1995/05/30 05:03:40 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: handy.h,v $  * Revision 1.2  1995/05/30 05:03:40  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1994/09/10  06:27:54  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:30:10  nate  * PERL!  *  * Revision 4.0.1.2  91/06/07  12:15:43  lwall  * patch4: new copyright notice  *  * Revision 4.0.1.1  91/04/12  09:29:08  lwall  * patch1: random cleanup in cpp namespace  *  * Revision 4.0  91/03/20  01:57:45  lwall  * 4.0 baseline.  *  */
end_comment

begin_define
define|#
directive|define
name|Null
parameter_list|(
name|type
parameter_list|)
value|((type)0)
end_define

begin_define
define|#
directive|define
name|Nullch
value|Null(char*)
end_define

begin_define
define|#
directive|define
name|Nullfp
value|Null(FILE*)
end_define

begin_define
define|#
directive|define
name|bool
value|char
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TRUE
end_ifdef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FALSE
end_ifdef

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_define
define|#
directive|define
name|Ctl
parameter_list|(
name|ch
parameter_list|)
value|(ch& 037)
end_define

begin_define
define|#
directive|define
name|strNE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1,s2))
end_define

begin_define
define|#
directive|define
name|strEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(!strcmp(s1,s2))
end_define

begin_define
define|#
directive|define
name|strLT
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1,s2)< 0)
end_define

begin_define
define|#
directive|define
name|strLE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1,s2)<= 0)
end_define

begin_define
define|#
directive|define
name|strGT
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1,s2)> 0)
end_define

begin_define
define|#
directive|define
name|strGE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1,s2)>= 0)
end_define

begin_define
define|#
directive|define
name|strnNE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(strncmp(s1,s2,l))
end_define

begin_define
define|#
directive|define
name|strnEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(!strncmp(s1,s2,l))
end_define

end_unit

