begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988 Free Software Foundation     written by Doug Lea (dl@rocky.oswego.edu)  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|generic_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|generic_h
value|1
end_define

begin_comment
comment|/*  *	See the CPP manual, argument prescan section for explanation  */
end_comment

begin_define
define|#
directive|define
name|name2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|gEnErIc2(a,b)
end_define

begin_define
define|#
directive|define
name|gEnErIc2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a ## b
end_define

begin_define
define|#
directive|define
name|name3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|gEnErIc3(a,b,c)
end_define

begin_define
define|#
directive|define
name|gEnErIc3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|a ## b ## c
end_define

begin_define
define|#
directive|define
name|name4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|gEnErIc4(a,b,c,d)
end_define

begin_define
define|#
directive|define
name|gEnErIc4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|a ## b ## c ## d
end_define

begin_define
define|#
directive|define
name|GENERIC_STRING
parameter_list|(
name|a
parameter_list|)
value|gEnErIcStRiNg(a)
end_define

begin_define
define|#
directive|define
name|gEnErIcStRiNg
parameter_list|(
name|a
parameter_list|)
value|#a
end_define

begin_define
define|#
directive|define
name|declare
parameter_list|(
name|clas
parameter_list|,
name|t
parameter_list|)
value|name2(clas,declare)(t)
end_define

begin_define
define|#
directive|define
name|declare2
parameter_list|(
name|clas
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|)
value|name2(clas,declare2)(t1,t2)
end_define

begin_define
define|#
directive|define
name|implement
parameter_list|(
name|clas
parameter_list|,
name|t
parameter_list|)
value|name2(clas,implement)(t)
end_define

begin_define
define|#
directive|define
name|implement2
parameter_list|(
name|clas
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|)
value|name2(clas,implement2)(t1,t2)
end_define

begin_extern
extern|extern genericerror(int
operator|,
extern|char*
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|GPT
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|set_handler
parameter_list|(
name|gen
parameter_list|,
name|type
parameter_list|,
name|x
parameter_list|)
value|name4(set_,type,gen,_handler)(x)
end_define

begin_define
define|#
directive|define
name|errorhandler
parameter_list|(
name|gen
parameter_list|,
name|type
parameter_list|)
value|name3(type,gen,handler)
end_define

begin_define
define|#
directive|define
name|callerror
parameter_list|(
name|gen
parameter_list|,
name|type
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|(*errorhandler(gen,type))(a,b)
end_define

begin_endif
endif|#
directive|endif
endif|generic_h
end_endif

end_unit

