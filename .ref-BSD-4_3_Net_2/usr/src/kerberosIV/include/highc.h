begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /mit/kerberos/src/include/RCS/highc.h,v $  * $Author: jtkohl $  * $Header: highc.h,v 4.0 89/01/23 09:59:15 jtkohl Exp $  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * Known breakage in the version of Metaware's High C compiler that  * we've got available....  */
end_comment

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/*#define volatile*/
end_comment

begin_comment
comment|/*  * Some builtin functions we can take advantage of for inlining....  */
end_comment

begin_define
define|#
directive|define
name|abs
value|_abs
end_define

begin_comment
comment|/* the _max and _min builtins accept any number of arguments */
end_comment

begin_undef
undef|#
directive|undef
name|MAX
end_undef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|_max(x,y)
end_define

begin_undef
undef|#
directive|undef
name|MIN
end_undef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|_min(x,y)
end_define

begin_comment
comment|/*  * I'm not sure if 65535 is a limit for this builtin, but it's  * reasonable for a string length.  Or is it?  */
end_comment

begin_comment
comment|/*#define strlen(s)		_find_char(s,65535,0)*/
end_comment

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|ptr
parameter_list|,
name|len
parameter_list|)
value|_fill_char(ptr,len,'\0')
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|len
parameter_list|)
value|_compare(b1,b2,len)
end_define

end_unit

