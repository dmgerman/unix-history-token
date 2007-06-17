begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.    Written by Bruno Haible<haible@clisp.cons.org>, 2001.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STDBOOL_H
end_ifndef

begin_define
define|#
directive|define
name|_STDBOOL_H
end_define

begin_comment
comment|/* ISO C 99<stdbool.h> for platforms that lack it.  */
end_comment

begin_comment
comment|/* Usage suggestions:     Programs that use<stdbool.h> should be aware of some limitations    and standards compliance issues.     Standards compliance:         -<stdbool.h> must be #included before 'bool', 'false', 'true'          can be used.         - You cannot assume that sizeof (bool) == 1.         - Programs should not undefine the macros bool, true, and false,          as C99 lists that as an "obsolescent feature".     Limitations of this substitute, when used in a C89 environment:         -<stdbool.h> must be #included before the '_Bool' type can be used.         - You cannot assume that _Bool is a typedef; it might be a macro.         - In C99, casts and automatic conversions to '_Bool' or 'bool' are          performed in such a way that every nonzero value gets converted          to 'true', and zero gets converted to 'false'.  This doesn't work          with this substitute.  With this substitute, only the values 0 and 1          give the expected result when converted to _Bool' or 'bool'.     Also, it is suggested that programs use 'bool' rather than '_Bool';    this isn't required, but 'bool' is more common.  */
end_comment

begin_comment
comment|/* 7.16. Boolean type and values */
end_comment

begin_comment
comment|/* BeOS<sys/socket.h> already #defines false 0, true 1.  We use the same    definitions below, but temporarily we have to #undef them.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__BEOS__
end_ifdef

begin_include
include|#
directive|include
file|<OS.h>
end_include

begin_comment
comment|/* defines bool but not _Bool */
end_comment

begin_undef
undef|#
directive|undef
name|false
end_undef

begin_undef
undef|#
directive|undef
name|true
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For the sake of symbolic names in gdb, we define true and false as    enum constants, not only as macros.    It is tempting to write       typedef enum { false = 0, true = 1 } _Bool;    so that gdb prints values of type 'bool' symbolically. But if we do    this, values of type '_Bool' may promote to 'int' or 'unsigned int'    (see ISO C 99 6.7.2.2.(4)); however, '_Bool' must promote to 'int'    (see ISO C 99 6.3.1.1.(2)).  So we add a negative value to the    enum; this ensures that '_Bool' promotes to 'int'.  */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
name|__cplusplus
operator|||
name|defined
name|__BEOS__
operator|)
end_if

begin_if
if|#
directive|if
operator|!
expr|@
name|HAVE__BOOL
expr|@
end_if

begin_if
if|#
directive|if
name|defined
name|__SUNPRO_C
operator|&&
operator|(
name|__SUNPRO_C
operator|<
literal|0x550
operator|||
name|__STDC__
operator|==
literal|1
operator|)
end_if

begin_comment
comment|/* Avoid stupid "warning: _Bool is a keyword in ISO C99".  */
end_comment

begin_define
define|#
directive|define
name|_Bool
value|signed char
end_define

begin_enum
enum|enum
block|{
name|false
init|=
literal|0
block|,
name|true
init|=
literal|1
block|}
enum|;
end_enum

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
enum|enum
block|{
name|_Bool_must_promote_to_int
init|=
operator|-
literal|1
block|,
name|false
init|=
literal|0
block|,
name|true
init|=
literal|1
block|}
name|_Bool
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|bool
name|_Bool
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bool
value|_Bool
end_define

begin_comment
comment|/* The other macros must be usable in preprocessor directives.  */
end_comment

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_define
define|#
directive|define
name|__bool_true_false_are_defined
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDBOOL_H */
end_comment

end_unit

