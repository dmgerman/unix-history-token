begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Assembler Support.    Copyright (C) 2000 Free Software Foundation, Inc.    Contributed by Red Hat, Inc.       This file is part of GNU CC.       GNU CC is free software ; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation * either version 2, or (at your option)    any later version.       GNU CC is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY ; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.       You should have received a copy of the GNU General Public License    along with GNU CC; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* P(INSN): Emit INSN.P for VLIW machines, otherwise emit plain INSN.    P2(INSN): Emit INSN.P on the FR500 and above, otherwise emit plain INSN.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FRV_VLIW__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|A
parameter_list|)
value|A##.p
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|A
parameter_list|)
value|A
comment|/**/
value|.p
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__FRV_VLIW__
operator|>
literal|2
end_if

begin_define
define|#
directive|define
name|P2
parameter_list|(
name|A
parameter_list|)
value|P(A)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P2
parameter_list|(
name|A
parameter_list|)
value|A
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|A
parameter_list|)
value|A
end_define

begin_define
define|#
directive|define
name|P2
parameter_list|(
name|A
parameter_list|)
value|A
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Add underscore if necessary to external name.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FRV_UNDERSCORE__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|EXT
parameter_list|(
name|NAME
parameter_list|)
value|_##NAME
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXT
parameter_list|(
name|NAME
parameter_list|)
value|_
comment|/**/
value|NAME
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXT
parameter_list|(
name|NAME
parameter_list|)
value|NAME
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

