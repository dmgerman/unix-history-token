begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Generic relocation support for BFD.    Copyright 1998, 1999, 2000 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* These macros are used by the various *.h target specific header    files to either generate an enum containing all the known relocations    for that target, or if RELOC_MACROS_GEN_FUNC is defined, a recognition    function is generated instead.  (This is used by binutils/readelf.c)     Given a header file like this:     	START_RELOC_NUMBERS (foo)    	    RELOC_NUMBER (R_foo_NONE,    0)    	    RELOC_NUMBER (R_foo_32,      1)    	    EMPTY_RELOC  (R_foo_good)    	    FAKE_RELOC   (R_foo_illegal, 9)    	END_RELOC_NUMBERS (R_foo_count)     Then the following will be produced by default (ie if    RELOC_MACROS_GEN_FUNC is *not* defined).     	enum foo 	{    	  R_foo_NONE = 0,    	  R_foo_32 = 1, 	  R_foo_good,    	  R_foo_illegal = 9,    	  R_foo_count    	};     If RELOC_MACROS_GEN_FUNC *is* defined, then instead the    following function will be generated:     	static const char * foo PARAMS ((unsigned long rtype));    	static const char *    	foo (rtype)    	    unsigned long rtype;    	{    	   switch (rtype)    	   {    	   case 0: return "R_foo_NONE";    	   case 1: return "R_foo_32";    	   default: return NULL;    	   }    	}    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RELOC_MACROS_H
end_ifndef

begin_define
define|#
directive|define
name|_RELOC_MACROS_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|RELOC_MACROS_GEN_FUNC
end_ifdef

begin_comment
comment|/* This function takes the relocation number and returns the    string version name of the name of that relocation.  If    the relocation is not recognised, NULL is returned.  */
end_comment

begin_define
define|#
directive|define
name|START_RELOC_NUMBERS
parameter_list|(
name|name
parameter_list|)
define|\
value|static const char * name    PARAMS ((unsigned long rtype)); 	\ static const char *						\ name (rtype)							\ 	unsigned long rtype;					\ {								\   switch (rtype)						\   {
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
end_if

begin_define
define|#
directive|define
name|RELOC_NUMBER
parameter_list|(
name|name
parameter_list|,
name|number
parameter_list|)
value|case number : return #name ;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RELOC_NUMBER
parameter_list|(
name|name
parameter_list|,
name|number
parameter_list|)
value|case number : return "name" ;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FAKE_RELOC
parameter_list|(
name|name
parameter_list|,
name|number
parameter_list|)
end_define

begin_define
define|#
directive|define
name|EMPTY_RELOC
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|END_RELOC_NUMBERS
parameter_list|(
name|name
parameter_list|)
define|\
value|default: return NULL;	\   }				\ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Default to generating enum.  */
end_comment

begin_define
define|#
directive|define
name|START_RELOC_NUMBERS
parameter_list|(
name|name
parameter_list|)
value|enum name {
end_define

begin_define
define|#
directive|define
name|RELOC_NUMBER
parameter_list|(
name|name
parameter_list|,
name|number
parameter_list|)
value|name = number,
end_define

begin_define
define|#
directive|define
name|FAKE_RELOC
parameter_list|(
name|name
parameter_list|,
name|number
parameter_list|)
value|name = number,
end_define

begin_define
define|#
directive|define
name|EMPTY_RELOC
parameter_list|(
name|name
parameter_list|)
value|name,
end_define

begin_define
define|#
directive|define
name|END_RELOC_NUMBERS
parameter_list|(
name|name
parameter_list|)
value|name };
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RELOC_MACROS_H */
end_comment

end_unit

