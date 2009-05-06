begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Symbol concatenation utilities.     Copyright (C) 1998, 2000 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.      You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation, Inc.,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYM_CAT_H
end_ifndef

begin_define
define|#
directive|define
name|SYM_CAT_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|ALMOST_STDC
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_STRINGIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|CONCAT2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a##b
end_define

begin_define
define|#
directive|define
name|CONCAT3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|a##b##c
end_define

begin_define
define|#
directive|define
name|CONCAT4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|a##b##c##d
end_define

begin_define
define|#
directive|define
name|STRINGX
parameter_list|(
name|s
parameter_list|)
value|#s
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Note one should never pass extra whitespace to the CONCATn macros,    e.g. CONCAT2(foo, bar) because traditonal C will keep the space between    the two labels instead of concatenating them.  Instead, make sure to    write CONCAT2(foo,bar).  */
end_comment

begin_define
define|#
directive|define
name|CONCAT2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a
comment|/**/
value|b
end_define

begin_define
define|#
directive|define
name|CONCAT3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|a
comment|/**/
value|b
comment|/**/
value|c
end_define

begin_define
define|#
directive|define
name|CONCAT4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|a
comment|/**/
value|b
comment|/**/
value|c
comment|/**/
value|d
end_define

begin_define
define|#
directive|define
name|STRINGX
parameter_list|(
name|s
parameter_list|)
value|"s"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XCONCAT2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|CONCAT2(a,b)
end_define

begin_define
define|#
directive|define
name|XCONCAT3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|CONCAT3(a,b,c)
end_define

begin_define
define|#
directive|define
name|XCONCAT4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|CONCAT4(a,b,c,d)
end_define

begin_comment
comment|/* Note the layer of indirection here is typically used to allow    stringification of the expansion of macros.  I.e. "#define foo    bar", "XSTRING(foo)", to yield "bar".  Be aware that this only    works for __STDC__, not for traditional C which will still resolve    to "foo".  */
end_comment

begin_define
define|#
directive|define
name|XSTRING
parameter_list|(
name|s
parameter_list|)
value|STRINGX(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYM_CAT_H */
end_comment

end_unit

