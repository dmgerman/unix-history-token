begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-m68kmote.h     Copyright (C) 1987-1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * This file is tp-generic.h and is intended to be a template for  * target processor specific header files.  */
end_comment

begin_define
define|#
directive|define
name|TC_M68K
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TE_SUN3
end_ifdef

begin_comment
comment|/* This variable contains the value to write out at the beginning of    the a.out file.  The 2<<16 means that this is a 68020 file instead    of an old-style 68000 file */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_MAGIC_NUMBER_FOR_OBJECT_FILE
value|(2<<16|OMAGIC);
end_define

begin_comment
comment|/* Magic byte for file header */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TE_SUN3 */
end_comment

begin_define
define|#
directive|define
name|AOUT_MACHTYPE
value|0x2
end_define

begin_define
define|#
directive|define
name|REVERSE_SORT_RELOCS
end_define

begin_comment
comment|/* FIXME-NOW: this line can be removed. */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
end_define

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
comment|/* not used */
end_comment

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
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|tc_aout_pre_write_hook
parameter_list|(
name|x
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|LISTING_WORD_SIZE
value|2
end_define

begin_comment
comment|/* A word is 2 bytes */
end_comment

begin_define
define|#
directive|define
name|LISTING_LHS_WIDTH
value|3
end_define

begin_comment
comment|/* 3 word on the first line */
end_comment

begin_define
define|#
directive|define
name|LISTING_LHS_WIDTH_SECOND
value|3
end_define

begin_comment
comment|/* One word on the second line */
end_comment

begin_define
define|#
directive|define
name|LISTING_LHS_CONT_LINES
value|4
end_define

begin_comment
comment|/* And 4 lines max */
end_comment

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"68K GAS "
end_define

begin_comment
comment|/* Copied from write.c */
end_comment

begin_define
define|#
directive|define
name|M68K_AIM_KLUDGE
parameter_list|(
name|aim
parameter_list|,
name|this_state
parameter_list|,
name|this_type
parameter_list|)
define|\
value|if (aim == 0&& this_state == 4) {
comment|/* hard encoded from tc-m68k.c */
value|\ 					aim=this_type->rlx_forward+1;
comment|/* Force relaxation into word mode */
value|\ 				    }
end_define

begin_define
define|#
directive|define
name|MRI
end_define

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of tc-m68kmote.h */
end_comment

end_unit

