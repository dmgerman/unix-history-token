begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-sparc.h - Macros and type defines for the sparc.    Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2,    or (at your option) any later version.     GAS is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See    the GNU General Public License for more details.     You should have received a copy of the GNU General Public    License along with GAS; see the file COPYING.  If not, write    to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|TC_SPARC
value|1
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
end_define

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|AOUT_MACHTYPE
value|138
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_define
define|#
directive|define
name|AOUT_MACHTYPE
value|3
end_define

begin_define
define|#
directive|define
name|AOUT_VERSION
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|tc_headers_hook
parameter_list|(
name|a
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* don't need it. */
end_comment

begin_define
define|#
directive|define
name|tc_crawl_symbol_chain
parameter_list|(
name|a
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* don't need it. */
end_comment

begin_function_decl
name|void
name|tc_aout_pre_write_hook
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"SPARC GAS "
end_define

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of tc-sparc.h */
end_comment

end_unit

