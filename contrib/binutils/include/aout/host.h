begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* host.h - Parameters about the a.out format, based on the host system    on which the program is compiled.      Copyright 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Address of data segment in memory after it is loaded.    It is up to you to define SEGMENT_SIZE on machines not listed here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SEGMENT_SIZE
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hp300
argument_list|)
operator|||
name|defined
argument_list|(
name|pyr
argument_list|)
end_if

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|page_size
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sony
end_ifdef

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|0x1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sony.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|is68k
end_ifdef

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|0x20000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|m68k
argument_list|)
operator|&&
name|defined
argument_list|(
name|PORTAR
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_PAGE_SIZE
value|0x400
end_define

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|TARGET_PAGE_SIZE
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
comment|/*!defined(SEGMENT_SIZE)*/
end_comment

end_unit

