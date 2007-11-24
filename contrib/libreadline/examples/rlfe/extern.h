begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1993-2002  *      Juergen Weigert (jnweiger@immd4.informatik.uni-erlangen.de)  *      Michael Schroeder (mlschroe@immd4.informatik.uni-erlangen.de)  * Copyright (c) 1987 Oliver Laumann  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2, or (at your option)  * any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program (see the file COPYING); if not, write to the  * Free Software Foundation, Inc.,  * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA  *  ****************************************************************  * $Id: extern.h,v 1.18 1994/05/31 12:31:57 mlschroe Exp $ FAU  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|__GNUC__
operator|<
literal|2
end_if

begin_undef
undef|#
directive|undef
name|__attribute__
end_undef

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pty.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|OpenPTY
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|InitPTY
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

