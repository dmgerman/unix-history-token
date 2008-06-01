begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Generate SDB debugging info.    Copyright (C) 2003, 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Note that no configuration uses sdb as its preferred format.  */
end_comment

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
value|1
end_define

begin_comment
comment|/* Forward references to tags are allowed.  */
end_comment

begin_define
define|#
directive|define
name|SDB_ALLOW_FORWARD_REFERENCES
end_define

begin_comment
comment|/* Unknown tags are also allowed.  */
end_comment

begin_define
define|#
directive|define
name|SDB_ALLOW_UNKNOWN_REFERENCES
end_define

begin_comment
comment|/* Block start/end next label #.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sdb_label_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Starting line of current function.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sdb_begin_function_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For block start and end, we create labels, so that    later we can figure out where the correct offset is.    The normal .ent/.end serve well enough for functions,    so those are just commented out.  */
end_comment

begin_define
define|#
directive|define
name|PUT_SDB_BLOCK_START
parameter_list|(
name|LINE
parameter_list|)
define|\
value|do {							\   fprintf (asm_out_file,				\ 	   "%sLb%d:\n\t.begin\t%sLb%d\t%d\n",		\ 	   LOCAL_LABEL_PREFIX,				\ 	   sdb_label_count,				\ 	   LOCAL_LABEL_PREFIX,				\ 	   sdb_label_count,				\ 	   (LINE));					\   sdb_label_count++;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_BLOCK_END
parameter_list|(
name|LINE
parameter_list|)
define|\
value|do {							\   fprintf (asm_out_file,				\ 	   "%sLe%d:\n\t.bend\t%sLe%d\t%d\n",		\ 	   LOCAL_LABEL_PREFIX,				\ 	   sdb_label_count,				\ 	   LOCAL_LABEL_PREFIX,				\ 	   sdb_label_count,				\ 	   (LINE));					\   sdb_label_count++;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_FUNCTION_START
parameter_list|(
name|LINE
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_FUNCTION_END
parameter_list|(
name|LINE
parameter_list|)
define|\
value|do {							\   SDB_OUTPUT_SOURCE_LINE (asm_out_file, LINE + sdb_begin_function_line); \ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_EPILOGUE_END
parameter_list|(
name|NAME
parameter_list|)
end_define

begin_comment
comment|/* We need to use .esize and .etype instead of .size and .type to    avoid conflicting with ELF directives.  */
end_comment

begin_undef
undef|#
directive|undef
name|PUT_SDB_SIZE
end_undef

begin_define
define|#
directive|define
name|PUT_SDB_SIZE
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   fprintf (asm_out_file, "\t.esize\t" HOST_WIDE_INT_PRINT_DEC ";", \  	   (HOST_WIDE_INT) (a));			\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|PUT_SDB_TYPE
end_undef

begin_define
define|#
directive|define
name|PUT_SDB_TYPE
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   fprintf (asm_out_file, "\t.etype\t0x%x;", (a));	\ } while (0)
end_define

end_unit

