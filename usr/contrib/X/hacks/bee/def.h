begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * %G% hack (aps) %W%  *  * Defines for hack.  *	aps.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<utmp.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<X/Xlib.h>
end_include

begin_define
define|#
directive|define
name|NOSTR
value|((char *) 0)
end_define

begin_comment
comment|/* Null string pointer */
end_comment

begin_define
define|#
directive|define
name|LINESIZE
value|BUFSIZ
end_define

begin_comment
comment|/* max from stdio.h */
end_comment

begin_define
define|#
directive|define
name|YES
value|1
end_define

begin_comment
comment|/* status return */
end_comment

begin_define
define|#
directive|define
name|NO
value|0
end_define

begin_comment
comment|/* status return */
end_comment

begin_define
define|#
directive|define
name|UTMPNAMSIZ
value|8
end_define

begin_comment
comment|/* utmp, who, login, ls, ... should be fixed */
end_comment

begin_define
define|#
directive|define
name|NAMLEN
value|16
end_define

begin_comment
comment|/* utmp unwisely uses 8 as length of name */
end_comment

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|n
parameter_list|)
value|{ register int N = (n); while (--N> 0); }
end_define

begin_define
define|#
directive|define
name|EVER
value|;;
end_define

begin_define
define|#
directive|define
name|equal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp(a,b)==0)
end_define

begin_comment
comment|/* A nice function to string compare */
end_comment

end_unit

