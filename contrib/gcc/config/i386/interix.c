begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Subroutines for insn-output.c for Windows NT.    Copyright (C) 1998, 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"rtl.h"
end_include

begin_include
include|#
directive|include
file|"regs.h"
end_include

begin_include
include|#
directive|include
file|"hard-reg-set.h"
end_include

begin_include
include|#
directive|include
file|"output.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"flags.h"
end_include

begin_comment
comment|/* Return string which is the former assembler name modified with a     suffix consisting of an atsign (@) followed by the number of bytes of     arguments */
end_comment

begin_function
name|char
modifier|*
name|gen_stdcall_suffix
parameter_list|(
name|decl
parameter_list|)
name|tree
name|decl
decl_stmt|;
block|{
name|int
name|total
init|=
literal|0
decl_stmt|;
comment|/* ??? This probably should use XSTR (XEXP (DECL_RTL (decl), 0), 0) instead      of DECL_ASSEMBLER_NAME.  */
name|char
modifier|*
name|asmname
init|=
name|IDENTIFIER_POINTER
argument_list|(
name|DECL_ASSEMBLER_NAME
argument_list|(
name|decl
argument_list|)
argument_list|)
decl_stmt|;
name|char
modifier|*
name|newsym
decl_stmt|;
if|if
condition|(
name|TYPE_ARG_TYPES
argument_list|(
name|TREE_TYPE
argument_list|(
name|decl
argument_list|)
argument_list|)
condition|)
if|if
condition|(
name|TREE_VALUE
argument_list|(
name|tree_last
argument_list|(
name|TYPE_ARG_TYPES
argument_list|(
name|TREE_TYPE
argument_list|(
name|decl
argument_list|)
argument_list|)
argument_list|)
argument_list|)
operator|==
name|void_type_node
condition|)
block|{
name|tree
name|formal_type
init|=
name|TYPE_ARG_TYPES
argument_list|(
name|TREE_TYPE
argument_list|(
name|decl
argument_list|)
argument_list|)
decl_stmt|;
while|while
condition|(
name|TREE_VALUE
argument_list|(
name|formal_type
argument_list|)
operator|!=
name|void_type_node
condition|)
block|{
name|int
name|parm_size
init|=
name|TREE_INT_CST_LOW
argument_list|(
name|TYPE_SIZE
argument_list|(
name|TREE_VALUE
argument_list|(
name|formal_type
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
comment|/* Must round up to include padding.  This is done the same 	       way as in store_one_arg.  */
name|parm_size
operator|=
operator|(
operator|(
name|parm_size
operator|+
name|PARM_BOUNDARY
operator|-
literal|1
operator|)
operator|/
name|PARM_BOUNDARY
operator|*
name|PARM_BOUNDARY
operator|)
expr_stmt|;
name|total
operator|+=
name|parm_size
expr_stmt|;
name|formal_type
operator|=
name|TREE_CHAIN
argument_list|(
name|formal_type
argument_list|)
expr_stmt|;
block|}
block|}
name|newsym
operator|=
name|xmalloc
argument_list|(
name|strlen
argument_list|(
name|asmname
argument_list|)
operator|+
literal|10
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|newsym
argument_list|,
literal|"%s@%d"
argument_list|,
name|asmname
argument_list|,
name|total
operator|/
name|BITS_PER_UNIT
argument_list|)
expr_stmt|;
return|return
name|IDENTIFIER_POINTER
argument_list|(
name|get_identifier
argument_list|(
name|newsym
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Turn this back on when the linker is updated to handle grouped    .data$ sections correctly. See corresponding note in i386/interix.h.     MK. */
end_comment

begin_comment
comment|/* Cover function for UNIQUE_SECTION.  */
end_comment

begin_comment
unit|void i386_pe_unique_section (decl, reloc)      tree decl;      int reloc; {   int len;   char *name,*string,*prefix;    name = IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (decl));
comment|/* Strip off any encoding in fnname.  */
end_comment

begin_comment
unit|STRIP_NAME_ENCODING (name, name);
comment|/* The object is put in, for example, section .text$foo.      The linker will then ultimately place them in .text      (everything from the $ on is stripped). Don't put      read-only data in .rdata section to avoid a PE linker       bug when .rdata$* grouped sections are used in code      without a .rdata section.  */
end_comment

begin_ifdef
unit|if (TREE_CODE (decl) == FUNCTION_DECL)     prefix = ".text$";   else if (DECL_READONLY_SECTION (decl, reloc))
ifdef|#
directive|ifdef
name|READONLY_DATA_SECTION
end_ifdef

begin_else
unit|prefix = ".rdata$";
else|#
directive|else
end_else

begin_endif
unit|prefix = ".text$";
endif|#
directive|endif
end_endif

begin_endif
unit|else     prefix = ".data$";   len = strlen (name) + strlen (prefix);   string = alloca (len + 1);   sprintf (string, "%s%s", prefix, name);    DECL_SECTION_NAME (decl) = build_string (len, string); }
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

end_unit

