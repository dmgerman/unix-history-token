begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* fini.c    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|USE_HCONFIG
end_define

begin_include
include|#
directive|include
file|"proj.h"
end_include

begin_include
include|#
directive|include
file|"malloc.h"
end_include

begin_undef
undef|#
directive|undef
name|MAXNAMELEN
end_undef

begin_define
define|#
directive|define
name|MAXNAMELEN
value|100
end_define

begin_typedef
typedef|typedef
name|struct
name|_name_
modifier|*
name|name
typedef|;
end_typedef

begin_struct
struct|struct
name|_name_
block|{
name|name
name|next
decl_stmt|;
name|name
name|previous
decl_stmt|;
name|name
name|next_alpha
decl_stmt|;
name|name
name|previous_alpha
decl_stmt|;
name|int
name|namelen
decl_stmt|;
name|int
name|kwlen
decl_stmt|;
name|char
name|kwname
index|[
name|MAXNAMELEN
index|]
decl_stmt|;
name|char
name|name_uc
index|[
name|MAXNAMELEN
index|]
decl_stmt|;
name|char
name|name_lc
index|[
name|MAXNAMELEN
index|]
decl_stmt|;
name|char
name|name_ic
index|[
name|MAXNAMELEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_name_root_
block|{
name|name
name|first
decl_stmt|;
name|name
name|last
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_name_alpha_
block|{
name|name
name|ign1
decl_stmt|;
name|name
name|ign2
decl_stmt|;
name|name
name|first
decl_stmt|;
name|name
name|last
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|FILE
modifier|*
name|in
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|FILE
modifier|*
name|out
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|prefix
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|postfix
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|storage
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|xspaces
index|[]
init|=
block|{
literal|""
block|,
comment|/* 0 */
literal|" "
block|,
comment|/* 1 */
literal|"  "
block|,
comment|/* 2 */
literal|"   "
block|,
comment|/* 3 */
literal|"    "
block|,
comment|/* 4 */
literal|"     "
block|,
comment|/* 5 */
literal|"      "
block|,
comment|/* 6 */
literal|"       "
block|,
comment|/* 7 */
literal|"\t"
block|,
comment|/* 8 */
literal|"\t "
block|,
comment|/* 9 */
literal|"\t  "
block|,
comment|/* 10 */
literal|"\t   "
block|,
comment|/* 11 */
literal|"\t    "
block|,
comment|/* 12 */
literal|"\t     "
block|,
comment|/* 13 */
literal|"\t      "
block|,
comment|/* 14 */
literal|"\t       "
block|,
comment|/* 15 */
literal|"\t\t"
block|,
comment|/* 16 */
literal|"\t\t "
block|,
comment|/* 17 */
literal|"\t\t  "
block|,
comment|/* 18 */
literal|"\t\t   "
block|,
comment|/* 19 */
literal|"\t\t    "
block|,
comment|/* 20 */
literal|"\t\t     "
block|,
comment|/* 21 */
literal|"\t\t      "
block|,
comment|/* 22 */
literal|"\t\t       "
block|,
comment|/* 23 */
literal|"\t\t\t"
block|,
comment|/* 24 */
literal|"\t\t\t "
block|,
comment|/* 25 */
literal|"\t\t\t  "
block|,
comment|/* 26 */
literal|"\t\t\t   "
block|,
comment|/* 27 */
literal|"\t\t\t    "
block|,
comment|/* 28 */
literal|"\t\t\t     "
block|,
comment|/* 29 */
literal|"\t\t\t      "
block|,
comment|/* 30 */
literal|"\t\t\t       "
block|,
comment|/* 31 */
literal|"\t\t\t\t"
block|,
comment|/* 32 */
literal|"\t\t\t\t "
block|,
comment|/* 33 */
literal|"\t\t\t\t  "
block|,
comment|/* 34 */
literal|"\t\t\t\t   "
block|,
comment|/* 35 */
literal|"\t\t\t\t    "
block|,
comment|/* 36 */
literal|"\t\t\t\t     "
block|,
comment|/* 37 */
literal|"\t\t\t\t      "
block|,
comment|/* 38 */
literal|"\t\t\t\t       "
block|,
comment|/* 39 */
literal|"\t\t\t\t\t"
block|,
comment|/* 40 */
literal|"\t\t\t\t\t "
block|,
comment|/* 41 */
literal|"\t\t\t\t\t  "
block|,
comment|/* 42 */
literal|"\t\t\t\t\t   "
block|,
comment|/* 43 */
literal|"\t\t\t\t\t    "
block|,
comment|/* 44 */
literal|"\t\t\t\t\t     "
block|,
comment|/* 45 */
literal|"\t\t\t\t\t      "
block|,
comment|/* 46 */
literal|"\t\t\t\t\t       "
block|,
comment|/* 47 */
literal|"\t\t\t\t\t\t"
block|,
comment|/* 48 */
literal|"\t\t\t\t\t\t "
block|,
comment|/* 49 */
literal|"\t\t\t\t\t\t  "
block|,
comment|/* 50 */
literal|"\t\t\t\t\t\t   "
block|,
comment|/* 51 */
literal|"\t\t\t\t\t\t    "
block|,
comment|/* 52 */
literal|"\t\t\t\t\t\t     "
block|,
comment|/* 53 */
literal|"\t\t\t\t\t\t      "
block|,
comment|/* 54 */
literal|"\t\t\t\t\t\t       "
block|,
comment|/* 55 */
literal|"\t\t\t\t\t\t\t"
block|,
comment|/* 56 */
literal|"\t\t\t\t\t\t\t "
block|,
comment|/* 57 */
literal|"\t\t\t\t\t\t\t  "
block|,
comment|/* 58 */
literal|"\t\t\t\t\t\t\t   "
block|,
comment|/* 59 */
literal|"\t\t\t\t\t\t\t    "
block|,
comment|/* 60 */
literal|"\t\t\t\t\t\t\t     "
block|,
comment|/* 61 */
literal|"\t\t\t\t\t\t\t      "
block|,
comment|/* 62 */
literal|"\t\t\t\t\t\t\t       "
block|,
comment|/* 63 */
literal|"\t\t\t\t\t\t\t\t"
block|,
comment|/* 64 */
literal|"\t\t\t\t\t\t\t\t "
block|,
comment|/* 65 */
literal|"\t\t\t\t\t\t\t\t  "
block|,
comment|/* 66 */
literal|"\t\t\t\t\t\t\t\t   "
block|,
comment|/* 67 */
literal|"\t\t\t\t\t\t\t\t    "
block|,
comment|/* 68 */
literal|"\t\t\t\t\t\t\t\t     "
block|,
comment|/* 69 */
literal|"\t\t\t\t\t\t\t\t      "
block|,
comment|/* 70 */
literal|"\t\t\t\t\t\t\t\t       "
block|,
comment|/* 71 */
literal|"\t\t\t\t\t\t\t\t\t"
block|,
comment|/* 72 */
literal|"\t\t\t\t\t\t\t\t\t "
block|,
comment|/* 73 */
literal|"\t\t\t\t\t\t\t\t\t  "
block|,
comment|/* 74 */
literal|"\t\t\t\t\t\t\t\t\t   "
block|,
comment|/* 75 */
literal|"\t\t\t\t\t\t\t\t\t    "
block|,
comment|/* 76 */
literal|"\t\t\t\t\t\t\t\t\t     "
block|,
comment|/* 77 */
literal|"\t\t\t\t\t\t\t\t\t      "
block|,
comment|/* 78 */
literal|"\t\t\t\t\t\t\t\t\t       "
block|,
comment|/* 79 */
literal|"\t\t\t\t\t\t\t\t\t\t"
block|,
comment|/* 80 */
literal|"\t\t\t\t\t\t\t\t\t\t "
block|,
comment|/* 81 */
literal|"\t\t\t\t\t\t\t\t\t\t  "
block|,
comment|/* 82 */
literal|"\t\t\t\t\t\t\t\t\t\t   "
block|,
comment|/* 83 */
literal|"\t\t\t\t\t\t\t\t\t\t    "
block|,
comment|/* 84 */
literal|"\t\t\t\t\t\t\t\t\t\t     "
block|,
comment|/* 85 */
literal|"\t\t\t\t\t\t\t\t\t\t      "
block|,
comment|/* 86 */
literal|"\t\t\t\t\t\t\t\t\t\t       "
block|,
comment|/* 87 */
literal|"\t\t\t\t\t\t\t\t\t\t\t"
block|,
comment|/* 88 */
literal|"\t\t\t\t\t\t\t\t\t\t\t "
block|,
comment|/* 89 */
literal|"\t\t\t\t\t\t\t\t\t\t\t  "
block|,
comment|/* 90 */
literal|"\t\t\t\t\t\t\t\t\t\t\t   "
block|,
comment|/* 91 */
literal|"\t\t\t\t\t\t\t\t\t\t\t    "
block|,
comment|/* 92 */
literal|"\t\t\t\t\t\t\t\t\t\t\t     "
block|,
comment|/* 93 */
literal|"\t\t\t\t\t\t\t\t\t\t\t      "
block|,
comment|/* 94 */
literal|"\t\t\t\t\t\t\t\t\t\t\t       "
block|,
comment|/* 95 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t"
block|,
comment|/* 96 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t "
block|,
comment|/* 97 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t  "
block|,
comment|/* 98 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t   "
block|,
comment|/* 99 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t    "
block|,
comment|/* 100 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t     "
block|,
comment|/* 101 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t      "
block|,
comment|/* 102 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t       "
block|,
comment|/* 103 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t"
block|,
comment|/* 104 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t "
block|,
comment|/* 105 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t  "
block|,
comment|/* 106 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t   "
block|,
comment|/* 107 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t    "
block|,
comment|/* 108 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t     "
block|,
comment|/* 109 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t      "
block|,
comment|/* 110 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t       "
block|,
comment|/* 111 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
block|,
comment|/* 112 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t "
block|,
comment|/* 113 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t  "
block|,
comment|/* 114 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t   "
block|,
comment|/* 115 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t    "
block|,
comment|/* 116 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t     "
block|,
comment|/* 117 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t      "
block|,
comment|/* 118 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t       "
block|,
comment|/* 119 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
block|,
comment|/* 120 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t "
block|,
comment|/* 121 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  "
block|,
comment|/* 122 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   "
block|,
comment|/* 123 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    "
block|,
comment|/* 124 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t     "
block|,
comment|/* 125 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t      "
block|,
comment|/* 126 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       "
block|,
comment|/* 127 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
block|,
comment|/* 128 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t "
block|,
comment|/* 129 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  "
block|,
comment|/* 130 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   "
block|,
comment|/* 131 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    "
block|,
comment|/* 132 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t     "
block|,
comment|/* 133 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t      "
block|,
comment|/* 134 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       "
block|,
comment|/* 135 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
block|,
comment|/* 136 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t "
block|,
comment|/* 137 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  "
block|,
comment|/* 138 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   "
block|,
comment|/* 139 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    "
block|,
comment|/* 140 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t     "
block|,
comment|/* 141 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t      "
block|,
comment|/* 142 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       "
block|,
comment|/* 143 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
block|,
comment|/* 144 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t "
block|,
comment|/* 145 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  "
block|,
comment|/* 146 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   "
block|,
comment|/* 147 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    "
block|,
comment|/* 148 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t     "
block|,
comment|/* 149 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t      "
block|,
comment|/* 150 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       "
block|,
comment|/* 151 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
block|,
comment|/* 152 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t "
block|,
comment|/* 153 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  "
block|,
comment|/* 154 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   "
block|,
comment|/* 155 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    "
block|,
comment|/* 156 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t     "
block|,
comment|/* 157 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t      "
block|,
comment|/* 158 */
literal|"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t       "
block|,
comment|/* 159 */
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|testname
parameter_list|(
name|bool
name|nested
parameter_list|,
name|int
name|indent
parameter_list|,
name|name
name|first
parameter_list|,
name|name
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|testnames
parameter_list|(
name|bool
name|nested
parameter_list|,
name|int
name|indent
parameter_list|,
name|int
name|len
parameter_list|,
name|name
name|first
parameter_list|,
name|name
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|char
name|buf
index|[
name|MAXNAMELEN
index|]
decl_stmt|;
name|char
name|last_buf
index|[
name|MAXNAMELEN
index|]
decl_stmt|;
name|char
name|kwname
index|[
name|MAXNAMELEN
index|]
decl_stmt|;
name|char
name|routine
index|[
literal|32
index|]
decl_stmt|;
name|char
name|type
index|[
literal|32
index|]
decl_stmt|;
name|int
name|i
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|len
decl_stmt|;
name|struct
name|_name_root_
name|names
index|[
literal|200
index|]
decl_stmt|;
name|struct
name|_name_alpha_
name|names_alpha
decl_stmt|;
name|name
name|n
decl_stmt|;
name|name
name|newname
decl_stmt|;
name|char
modifier|*
name|input_name
decl_stmt|;
name|char
modifier|*
name|output_name
decl_stmt|;
name|char
modifier|*
name|include_name
decl_stmt|;
name|FILE
modifier|*
name|incl
decl_stmt|;
name|int
name|fixlengths
decl_stmt|;
name|int
name|total_length
decl_stmt|;
name|int
name|do_name
decl_stmt|;
comment|/* TRUE if token may be NAME. */
name|int
name|do_names
decl_stmt|;
comment|/* TRUE if token may be NAMES. */
name|int
name|cc
decl_stmt|;
name|bool
name|do_exit
init|=
name|FALSE
decl_stmt|;
name|last_buf
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
operator|(
operator|(
name|size_t
operator|)
name|i
operator|)
operator|<
name|ARRAY_SIZE
argument_list|(
name|names
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
comment|/* Initialize length/name ordered list roots. */
name|names
index|[
name|i
index|]
operator|.
name|first
operator|=
operator|(
name|name
operator|)
operator|&
name|names
index|[
name|i
index|]
expr_stmt|;
name|names
index|[
name|i
index|]
operator|.
name|last
operator|=
operator|(
name|name
operator|)
operator|&
name|names
index|[
name|i
index|]
expr_stmt|;
block|}
name|names_alpha
operator|.
name|first
operator|=
operator|(
name|name
operator|)
operator|&
name|names_alpha
expr_stmt|;
comment|/* Initialize name order. */
name|names_alpha
operator|.
name|last
operator|=
operator|(
name|name
operator|)
operator|&
name|names_alpha
expr_stmt|;
if|if
condition|(
name|argc
operator|!=
literal|4
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Command form: fini input output-code output-include\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|input_name
operator|=
name|argv
index|[
literal|1
index|]
expr_stmt|;
name|output_name
operator|=
name|argv
index|[
literal|2
index|]
expr_stmt|;
name|include_name
operator|=
name|argv
index|[
literal|3
index|]
expr_stmt|;
name|in
operator|=
name|fopen
argument_list|(
name|input_name
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
if|if
condition|(
name|in
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Cannot open \"%s\"\n"
argument_list|,
name|input_name
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|out
operator|=
name|fopen
argument_list|(
name|output_name
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
if|if
condition|(
name|out
operator|==
name|NULL
condition|)
block|{
name|fclose
argument_list|(
name|in
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Cannot open \"%s\"\n"
argument_list|,
name|output_name
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|incl
operator|=
name|fopen
argument_list|(
name|include_name
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
if|if
condition|(
name|incl
operator|==
name|NULL
condition|)
block|{
name|fclose
argument_list|(
name|in
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Cannot open \"%s\"\n"
argument_list|,
name|include_name
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
comment|/* Get past the initial block-style comment (man, this parsing code is just      _so_ lame, but I'm too lazy to improve it).  */
for|for
control|(
init|;
condition|;
control|)
block|{
name|cc
operator|=
name|getc
argument_list|(
name|in
argument_list|)
expr_stmt|;
if|if
condition|(
name|cc
operator|==
literal|'{'
condition|)
block|{
while|while
condition|(
operator|(
operator|(
name|cc
operator|=
name|getc
argument_list|(
name|in
argument_list|)
operator|)
operator|!=
literal|'}'
operator|)
operator|&&
operator|(
name|cc
operator|!=
name|EOF
operator|)
condition|)
empty_stmt|;
block|}
elseif|else
if|if
condition|(
name|cc
operator|!=
name|EOF
condition|)
block|{
while|while
condition|(
operator|(
operator|(
name|cc
operator|=
name|getc
argument_list|(
name|in
argument_list|)
operator|)
operator|!=
name|EOF
operator|)
operator|&&
operator|(
operator|!
name|ISALNUM
argument_list|(
name|cc
argument_list|)
operator|)
condition|)
empty_stmt|;
name|ungetc
argument_list|(
name|cc
argument_list|,
name|in
argument_list|)
expr_stmt|;
break|break;
block|}
else|else
block|{
name|assert
argument_list|(
literal|"EOF too soon!"
operator|==
name|NULL
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
name|fscanf
argument_list|(
name|in
argument_list|,
literal|"%s %s %s %s %s %d %d"
argument_list|,
name|prefix
argument_list|,
name|postfix
argument_list|,
name|storage
argument_list|,
name|type
argument_list|,
name|routine
argument_list|,
operator|&
name|do_name
argument_list|,
operator|&
name|do_names
argument_list|)
expr_stmt|;
if|if
condition|(
name|storage
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
name|storage
index|[
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
else|else
comment|/* Assume string is quoted somehow, replace ending quote with space. */
block|{
if|if
condition|(
name|storage
index|[
literal|2
index|]
operator|==
literal|'\0'
condition|)
name|storage
index|[
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
else|else
name|storage
index|[
name|strlen
argument_list|(
name|storage
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|' '
expr_stmt|;
block|}
if|if
condition|(
name|postfix
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
name|postfix
index|[
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
else|else
comment|/* Assume string is quoted somehow, strip off 				   ending quote. */
name|postfix
index|[
name|strlen
argument_list|(
name|postfix
argument_list|)
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|storage
index|[
name|i
index|]
operator|!=
literal|'\0'
condition|;
operator|++
name|i
control|)
name|storage
index|[
name|i
operator|-
literal|1
index|]
operator|=
name|storage
index|[
name|i
index|]
expr_stmt|;
name|storage
index|[
name|i
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|postfix
index|[
name|i
index|]
operator|!=
literal|'\0'
condition|;
operator|++
name|i
control|)
name|postfix
index|[
name|i
operator|-
literal|1
index|]
operator|=
name|postfix
index|[
name|i
index|]
expr_stmt|;
name|postfix
index|[
name|i
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
name|fixlengths
operator|=
name|strlen
argument_list|(
name|prefix
argument_list|)
operator|+
name|strlen
argument_list|(
name|postfix
argument_list|)
expr_stmt|;
while|while
condition|(
name|TRUE
condition|)
block|{
name|count
operator|=
name|fscanf
argument_list|(
name|in
argument_list|,
literal|"%s %s"
argument_list|,
name|buf
argument_list|,
name|kwname
argument_list|)
expr_stmt|;
if|if
condition|(
name|count
operator|==
name|EOF
condition|)
break|break;
name|len
operator|=
name|strlen
argument_list|(
name|buf
argument_list|)
expr_stmt|;
if|if
condition|(
name|len
operator|==
literal|0
condition|)
continue|continue;
comment|/* Skip empty lines. */
if|if
condition|(
name|buf
index|[
literal|0
index|]
operator|==
literal|';'
condition|)
continue|continue;
comment|/* Skip commented-out lines. */
for|for
control|(
name|i
operator|=
name|strlen
argument_list|(
name|buf
argument_list|)
operator|-
literal|1
init|;
name|i
operator|>
literal|0
condition|;
operator|--
name|i
control|)
name|cc
operator|=
name|buf
index|[
name|i
index|]
expr_stmt|;
comment|/* Make new name object to store name and its keyword. */
name|newname
operator|=
operator|(
name|name
operator|)
name|xmalloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|newname
argument_list|)
argument_list|)
expr_stmt|;
name|newname
operator|->
name|namelen
operator|=
name|strlen
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|newname
operator|->
name|kwlen
operator|=
name|strlen
argument_list|(
name|kwname
argument_list|)
expr_stmt|;
name|total_length
operator|=
name|newname
operator|->
name|kwlen
operator|+
name|fixlengths
expr_stmt|;
if|if
condition|(
name|total_length
operator|>=
literal|32
condition|)
comment|/* Else resulting keyword name too long. */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s%s%s is 31+%d chars long\n"
argument_list|,
name|input_name
argument_list|,
name|prefix
argument_list|,
name|kwname
argument_list|,
name|postfix
argument_list|,
name|total_length
operator|-
literal|31
argument_list|)
expr_stmt|;
name|do_exit
operator|=
name|TRUE
expr_stmt|;
block|}
name|strcpy
argument_list|(
name|newname
operator|->
name|kwname
argument_list|,
name|kwname
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|newname
operator|->
name|namelen
condition|;
operator|++
name|i
control|)
block|{
name|cc
operator|=
name|buf
index|[
name|i
index|]
expr_stmt|;
name|newname
operator|->
name|name_uc
index|[
name|i
index|]
operator|=
name|TOUPPER
argument_list|(
name|cc
argument_list|)
expr_stmt|;
name|newname
operator|->
name|name_lc
index|[
name|i
index|]
operator|=
name|TOLOWER
argument_list|(
name|cc
argument_list|)
expr_stmt|;
name|newname
operator|->
name|name_ic
index|[
name|i
index|]
operator|=
name|cc
expr_stmt|;
block|}
name|newname
operator|->
name|name_uc
index|[
name|i
index|]
operator|=
name|newname
operator|->
name|name_lc
index|[
name|i
index|]
operator|=
name|newname
operator|->
name|name_ic
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* Warn user if names aren't alphabetically ordered. */
if|if
condition|(
operator|(
name|last_buf
index|[
literal|0
index|]
operator|!=
literal|'\0'
operator|)
operator|&&
operator|(
name|strcmp
argument_list|(
name|last_buf
argument_list|,
name|newname
operator|->
name|name_uc
argument_list|)
operator|>=
literal|0
operator|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: \"%s\" precedes \"%s\"\n"
argument_list|,
name|input_name
argument_list|,
name|last_buf
argument_list|,
name|newname
operator|->
name|name_uc
argument_list|)
expr_stmt|;
name|do_exit
operator|=
name|TRUE
expr_stmt|;
block|}
name|strcpy
argument_list|(
name|last_buf
argument_list|,
name|newname
operator|->
name|name_uc
argument_list|)
expr_stmt|;
comment|/* Append name to end of alpha-sorted list (assumes names entered in 	 alpha order wrt name, not kwname, even though kwname is output from 	 this list). */
name|n
operator|=
name|names_alpha
operator|.
name|last
expr_stmt|;
name|newname
operator|->
name|next_alpha
operator|=
name|n
operator|->
name|next_alpha
expr_stmt|;
name|newname
operator|->
name|previous_alpha
operator|=
name|n
expr_stmt|;
name|n
operator|->
name|next_alpha
operator|->
name|previous_alpha
operator|=
name|newname
expr_stmt|;
name|n
operator|->
name|next_alpha
operator|=
name|newname
expr_stmt|;
comment|/* Insert name in appropriate length/name ordered list. */
name|n
operator|=
operator|(
name|name
operator|)
operator|&
name|names
index|[
name|len
index|]
expr_stmt|;
while|while
condition|(
operator|(
name|n
operator|->
name|next
operator|!=
operator|(
name|name
operator|)
operator|&
name|names
index|[
name|len
index|]
operator|)
operator|&&
operator|(
name|strcmp
argument_list|(
name|buf
argument_list|,
name|n
operator|->
name|next
operator|->
name|name_uc
argument_list|)
operator|>
literal|0
operator|)
condition|)
name|n
operator|=
name|n
operator|->
name|next
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|buf
argument_list|,
name|n
operator|->
name|next
operator|->
name|name_uc
argument_list|)
operator|==
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: extraneous \"%s\"\n"
argument_list|,
name|input_name
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|do_exit
operator|=
name|TRUE
expr_stmt|;
block|}
name|newname
operator|->
name|next
operator|=
name|n
operator|->
name|next
expr_stmt|;
name|newname
operator|->
name|previous
operator|=
name|n
expr_stmt|;
name|n
operator|->
name|next
operator|->
name|previous
operator|=
name|newname
expr_stmt|;
name|n
operator|->
name|next
operator|=
name|newname
expr_stmt|;
block|}
if|#
directive|if
literal|0
block|for (len = 0; len< ARRAY_SIZE (name); ++len)     {       if (names[len].first == (name)&names[len]) 	continue;       printf ("Length %d:\n", len);       for (n = names[len].first; n != (name)&names[len]; n = n->next) 	printf ("    %s %s %s\n", n->name_uc, n->name_lc, n->name_ic);     }
endif|#
directive|endif
if|if
condition|(
name|do_exit
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* First output the #include file. */
for|for
control|(
name|n
operator|=
name|names_alpha
operator|.
name|first
init|;
name|n
operator|!=
operator|(
name|name
operator|)
operator|&
name|names_alpha
condition|;
name|n
operator|=
name|n
operator|->
name|next_alpha
control|)
block|{
name|fprintf
argument_list|(
name|incl
argument_list|,
literal|"#define %sl%s%s %d\n"
argument_list|,
name|prefix
argument_list|,
name|n
operator|->
name|kwname
argument_list|,
name|postfix
argument_list|,
name|n
operator|->
name|namelen
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|incl
argument_list|,
literal|"\ \n\ enum %s_\n\ {\n\ %sNone%s,\n\ "
argument_list|,
name|type
argument_list|,
name|prefix
argument_list|,
name|postfix
argument_list|)
expr_stmt|;
for|for
control|(
name|n
operator|=
name|names_alpha
operator|.
name|first
init|;
name|n
operator|!=
operator|(
name|name
operator|)
operator|&
name|names_alpha
condition|;
name|n
operator|=
name|n
operator|->
name|next_alpha
control|)
block|{
name|fprintf
argument_list|(
name|incl
argument_list|,
literal|"\ %s%s%s,\n\ "
argument_list|,
name|prefix
argument_list|,
name|n
operator|->
name|kwname
argument_list|,
name|postfix
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|incl
argument_list|,
literal|"\ %s%s\n\ };\n\ typedef enum %s_ %s;\n\ "
argument_list|,
name|prefix
argument_list|,
name|postfix
argument_list|,
name|type
argument_list|,
name|type
argument_list|)
expr_stmt|;
comment|/* Now output the C program. */
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\ %s%s\n\ %s (ffelexToken t)\n\ %c\n\   char *p;\n\   int c;\n\ \n\   p = ffelex_token_text (t);\n\ \n\ "
argument_list|,
name|storage
argument_list|,
name|type
argument_list|,
name|routine
argument_list|,
literal|'{'
argument_list|)
expr_stmt|;
if|if
condition|(
name|do_name
condition|)
block|{
if|if
condition|(
name|do_names
condition|)
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\   if (ffelex_token_type (t) == FFELEX_typeNAME)\n\     {\n\       switch (ffelex_token_length (t))\n\ \t{\n\ "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\   assert (ffelex_token_type (t) == FFELEX_typeNAME);\n\ \n\   switch (ffelex_token_length (t))\n\     {\n\ "
argument_list|)
expr_stmt|;
comment|/* Now output the length as a case, followed by the binary search within that length.  */
for|for
control|(
name|len
operator|=
literal|0
init|;
operator|(
operator|(
name|size_t
operator|)
name|len
operator|)
operator|<
name|ARRAY_SIZE
argument_list|(
name|names
argument_list|)
condition|;
operator|++
name|len
control|)
block|{
if|if
condition|(
name|names
index|[
name|len
index|]
operator|.
name|first
operator|!=
operator|(
name|name
operator|)
operator|&
name|names
index|[
name|len
index|]
condition|)
block|{
if|if
condition|(
name|do_names
condition|)
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\ \tcase %d:\n\ "
argument_list|,
name|len
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\     case %d:\n\ "
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|testname
argument_list|(
name|FALSE
argument_list|,
name|do_names
condition|?
literal|10
else|:
literal|6
argument_list|,
name|names
index|[
name|len
index|]
operator|.
name|first
argument_list|,
name|names
index|[
name|len
index|]
operator|.
name|last
argument_list|)
expr_stmt|;
if|if
condition|(
name|do_names
condition|)
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\ \t  break;\n\ "
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\       break;\n\ "
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|do_names
condition|)
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\ \t}\n\       return %sNone%s;\n\     }\n\ \n\ "
argument_list|,
name|prefix
argument_list|,
name|postfix
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\     }\n\ \n\   return %sNone%s;\n\ }\n\ "
argument_list|,
name|prefix
argument_list|,
name|postfix
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|do_names
condition|)
block|{
name|fputs
argument_list|(
literal|"\   assert (ffelex_token_type (t) == FFELEX_typeNAMES);\n\ \n\   switch (ffelex_token_length (t))\n\     {\n\     default:\n\ "
argument_list|,
name|out
argument_list|)
expr_stmt|;
comment|/* Find greatest non-empty length list. */
for|for
control|(
name|len
operator|=
name|ARRAY_SIZE
argument_list|(
name|names
argument_list|)
operator|-
literal|1
init|;
name|names
index|[
name|len
index|]
operator|.
name|first
operator|==
operator|(
name|name
operator|)
operator|&
name|names
index|[
name|len
index|]
condition|;
operator|--
name|len
control|)
empty_stmt|;
comment|/* Now output the length as a case, followed by the binary search within that length. */
if|if
condition|(
name|len
operator|>
literal|0
condition|)
block|{
for|for
control|(
init|;
name|len
operator|!=
literal|0
condition|;
operator|--
name|len
control|)
block|{
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\     case %d:\n\ "
argument_list|,
name|len
argument_list|)
expr_stmt|;
if|if
condition|(
name|names
index|[
name|len
index|]
operator|.
name|first
operator|!=
operator|(
name|name
operator|)
operator|&
name|names
index|[
name|len
index|]
condition|)
name|testnames
argument_list|(
name|FALSE
argument_list|,
literal|6
argument_list|,
name|len
argument_list|,
name|names
index|[
name|len
index|]
operator|.
name|first
argument_list|,
name|names
index|[
name|len
index|]
operator|.
name|last
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|names
index|[
literal|1
index|]
operator|.
name|first
operator|==
operator|(
name|name
operator|)
operator|&
name|names
index|[
literal|1
index|]
condition|)
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\       ;\n\ "
argument_list|)
expr_stmt|;
comment|/* Need empty statement after an empty case 				   1:  */
block|}
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\     }\n\ \n\   return %sNone%s;\n\ }\n\ "
argument_list|,
name|prefix
argument_list|,
name|postfix
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|out
operator|!=
name|stdout
condition|)
name|fclose
argument_list|(
name|out
argument_list|)
expr_stmt|;
if|if
condition|(
name|incl
operator|!=
name|stdout
condition|)
name|fclose
argument_list|(
name|incl
argument_list|)
expr_stmt|;
if|if
condition|(
name|in
operator|!=
name|stdin
condition|)
name|fclose
argument_list|(
name|in
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|testname
parameter_list|(
name|bool
name|nested
parameter_list|,
name|int
name|indent
parameter_list|,
name|name
name|first
parameter_list|,
name|name
name|last
parameter_list|)
block|{
name|name
name|n
decl_stmt|;
name|name
name|nhalf
decl_stmt|;
name|int
name|num
decl_stmt|;
name|int
name|numhalf
decl_stmt|;
name|assert
argument_list|(
operator|!
name|nested
operator|||
name|indent
operator|>=
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
operator|(
name|size_t
operator|)
name|indent
operator|)
operator|+
literal|4
operator|<
name|ARRAY_SIZE
argument_list|(
name|xspaces
argument_list|)
argument_list|)
expr_stmt|;
name|num
operator|=
literal|0
expr_stmt|;
name|numhalf
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|n
operator|=
name|first
operator|,
name|nhalf
operator|=
name|first
init|;
name|n
operator|!=
name|last
operator|->
name|next
condition|;
name|n
operator|=
name|n
operator|->
name|next
control|)
block|{
if|if
condition|(
operator|(
operator|++
name|num
operator|&
literal|1
operator|)
operator|==
literal|0
condition|)
block|{
name|nhalf
operator|=
name|nhalf
operator|->
name|next
expr_stmt|;
operator|++
name|numhalf
expr_stmt|;
block|}
block|}
if|if
condition|(
name|nested
condition|)
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\ %s{\n\ "
argument_list|,
name|xspaces
index|[
name|indent
operator|-
literal|2
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\ %sif ((c = ffesrc_strcmp_2c (ffe_case_match (), p, \"%s\", \"%s\", \"%s\")) == 0)\n\ %sreturn %s%s%s;\n\ "
argument_list|,
name|xspaces
index|[
name|indent
index|]
argument_list|,
name|nhalf
operator|->
name|name_uc
argument_list|,
name|nhalf
operator|->
name|name_lc
argument_list|,
name|nhalf
operator|->
name|name_ic
argument_list|,
name|xspaces
index|[
name|indent
operator|+
literal|2
index|]
argument_list|,
name|prefix
argument_list|,
name|nhalf
operator|->
name|kwname
argument_list|,
name|postfix
argument_list|)
expr_stmt|;
if|if
condition|(
name|num
operator|!=
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\ %selse if (c< 0)\n\ "
argument_list|,
name|xspaces
index|[
name|indent
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|numhalf
operator|==
literal|0
condition|)
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\ %s;\n\ "
argument_list|,
name|xspaces
index|[
name|indent
operator|+
literal|2
index|]
argument_list|)
expr_stmt|;
else|else
name|testname
argument_list|(
name|TRUE
argument_list|,
name|indent
operator|+
literal|4
argument_list|,
name|first
argument_list|,
name|nhalf
operator|->
name|previous
argument_list|)
expr_stmt|;
if|if
condition|(
name|num
operator|-
name|numhalf
operator|>
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\ %selse\n\ "
argument_list|,
name|xspaces
index|[
name|indent
index|]
argument_list|)
expr_stmt|;
name|testname
argument_list|(
name|TRUE
argument_list|,
name|indent
operator|+
literal|4
argument_list|,
name|nhalf
operator|->
name|next
argument_list|,
name|last
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|nested
condition|)
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\ %s}\n\ "
argument_list|,
name|xspaces
index|[
name|indent
operator|-
literal|2
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|testnames
parameter_list|(
name|bool
name|nested
parameter_list|,
name|int
name|indent
parameter_list|,
name|int
name|len
parameter_list|,
name|name
name|first
parameter_list|,
name|name
name|last
parameter_list|)
block|{
name|name
name|n
decl_stmt|;
name|name
name|nhalf
decl_stmt|;
name|int
name|num
decl_stmt|;
name|int
name|numhalf
decl_stmt|;
name|assert
argument_list|(
operator|!
name|nested
operator|||
name|indent
operator|>=
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
operator|(
name|size_t
operator|)
name|indent
operator|)
operator|+
literal|4
operator|<
name|ARRAY_SIZE
argument_list|(
name|xspaces
argument_list|)
argument_list|)
expr_stmt|;
name|num
operator|=
literal|0
expr_stmt|;
name|numhalf
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|n
operator|=
name|first
operator|,
name|nhalf
operator|=
name|first
init|;
name|n
operator|!=
name|last
operator|->
name|next
condition|;
name|n
operator|=
name|n
operator|->
name|next
control|)
block|{
if|if
condition|(
operator|(
operator|++
name|num
operator|&
literal|1
operator|)
operator|==
literal|0
condition|)
block|{
name|nhalf
operator|=
name|nhalf
operator|->
name|next
expr_stmt|;
operator|++
name|numhalf
expr_stmt|;
block|}
block|}
if|if
condition|(
name|nested
condition|)
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\ %s{\n\ "
argument_list|,
name|xspaces
index|[
name|indent
operator|-
literal|2
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\ %sif ((c = ffesrc_strncmp_2c (ffe_case_match (), p, \"%s\", \"%s\", \"%s\", %d)) == 0)\n\ %sreturn %s%s%s;\n\ "
argument_list|,
name|xspaces
index|[
name|indent
index|]
argument_list|,
name|nhalf
operator|->
name|name_uc
argument_list|,
name|nhalf
operator|->
name|name_lc
argument_list|,
name|nhalf
operator|->
name|name_ic
argument_list|,
name|len
argument_list|,
name|xspaces
index|[
name|indent
operator|+
literal|2
index|]
argument_list|,
name|prefix
argument_list|,
name|nhalf
operator|->
name|kwname
argument_list|,
name|postfix
argument_list|)
expr_stmt|;
if|if
condition|(
name|num
operator|!=
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\ %selse if (c< 0)\n\ "
argument_list|,
name|xspaces
index|[
name|indent
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|numhalf
operator|==
literal|0
condition|)
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\ %s;\n\ "
argument_list|,
name|xspaces
index|[
name|indent
operator|+
literal|2
index|]
argument_list|)
expr_stmt|;
else|else
name|testnames
argument_list|(
name|TRUE
argument_list|,
name|indent
operator|+
literal|4
argument_list|,
name|len
argument_list|,
name|first
argument_list|,
name|nhalf
operator|->
name|previous
argument_list|)
expr_stmt|;
if|if
condition|(
name|num
operator|-
name|numhalf
operator|>
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\ %selse\n\ "
argument_list|,
name|xspaces
index|[
name|indent
index|]
argument_list|)
expr_stmt|;
name|testnames
argument_list|(
name|TRUE
argument_list|,
name|indent
operator|+
literal|4
argument_list|,
name|len
argument_list|,
name|nhalf
operator|->
name|next
argument_list|,
name|last
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|nested
condition|)
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"\ %s}\n\ "
argument_list|,
name|xspaces
index|[
name|indent
operator|-
literal|2
index|]
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

