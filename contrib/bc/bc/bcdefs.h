begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bcdefs.h:  The single file to include all constants and type definitions. */
end_comment

begin_comment
comment|/*  This file is part of GNU bc.     Copyright (C) 1991, 1992, 1993, 1994, 1997 Free Software Foundation, Inc.      This program is free software; you can redistribute it and/or modify     it under the terms of the GNU General Public License as published by     the Free Software Foundation; either version 2 of the License , or     (at your option) any later version.      This program is distributed in the hope that it will be useful,     but WITHOUT ANY WARRANTY; without even the implied warranty of     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     GNU General Public License for more details.      You should have received a copy of the GNU General Public License     along with this program; see the file COPYING.  If not, write to       The Free Software Foundation, Inc.       59 Temple Place, Suite 330       Boston, MA 02111 USA      You may contact the author by:        e-mail:  philnelson@acm.org       us-mail:  Philip A. Nelson                 Computer Science Department, 9062                 Western Washington University                 Bellingham, WA 98226-9062         *************************************************************************/
end_comment

begin_comment
comment|/* Include the configuration file. */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_comment
comment|/* Standard includes for all files. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRINGS_H
end_ifdef

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIMITS_H
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBEDIT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<histedit.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|READLINE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<readline/readline.h>
end_include

begin_include
include|#
directive|include
file|<readline/history.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include the other definitions. */
end_comment

begin_include
include|#
directive|include
file|"const.h"
end_include

begin_include
include|#
directive|include
file|"number.h"
end_include

begin_comment
comment|/* These definitions define all the structures used in    code and data storage.  This includes the representation of    labels.   The "guiding" principle is to make structures that    take a minimum of space when unused but can be built to contain    the full structures.  */
end_comment

begin_comment
comment|/* Labels are first.  Labels are generated sequentially in functions    and full code.  They just "point" to a single bye in the code.  The    "address" is the byte number.  The byte number is used to get an    actual character pointer. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bc_label_group
block|{
name|long
name|l_adrs
index|[
name|BC_LABEL_GROUP
index|]
decl_stmt|;
name|struct
name|bc_label_group
modifier|*
name|l_next
decl_stmt|;
block|}
name|bc_label_group
typedef|;
end_typedef

begin_comment
comment|/* Argument list.  Recorded in the function so arguments can    be checked at call time. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|arg_list
block|{
name|int
name|av_name
decl_stmt|;
name|int
name|arg_is_var
decl_stmt|;
comment|/* Extension ... variable parameters. */
name|struct
name|arg_list
modifier|*
name|next
decl_stmt|;
block|}
name|arg_list
typedef|;
end_typedef

begin_comment
comment|/* Each function has its own code segments and labels.  There can be    no jumps between functions so labels are unique to a function. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|f_defined
decl_stmt|;
comment|/* Is this function defined yet. */
name|char
modifier|*
name|f_body
decl_stmt|;
name|int
name|f_body_size
decl_stmt|;
comment|/* Size of body.  Power of 2. */
name|int
name|f_code_size
decl_stmt|;
name|bc_label_group
modifier|*
name|f_label
decl_stmt|;
name|arg_list
modifier|*
name|f_params
decl_stmt|;
name|arg_list
modifier|*
name|f_autos
decl_stmt|;
block|}
name|bc_function
typedef|;
end_typedef

begin_comment
comment|/* Code addresses. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|pc_func
decl_stmt|;
name|int
name|pc_addr
decl_stmt|;
block|}
name|program_counter
typedef|;
end_typedef

begin_comment
comment|/* Variables are "pushable" (auto) and thus we need a stack mechanism.    This is built into the variable record. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bc_var
block|{
name|bc_num
name|v_value
decl_stmt|;
name|struct
name|bc_var
modifier|*
name|v_next
decl_stmt|;
block|}
name|bc_var
typedef|;
end_typedef

begin_comment
comment|/* bc arrays can also be "auto" variables and thus need the same    kind of stacking mechanisms. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bc_array_node
block|{
union|union
block|{
name|bc_num
name|n_num
index|[
name|NODE_SIZE
index|]
decl_stmt|;
name|struct
name|bc_array_node
modifier|*
name|n_down
index|[
name|NODE_SIZE
index|]
decl_stmt|;
block|}
name|n_items
union|;
block|}
name|bc_array_node
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bc_array
block|{
name|bc_array_node
modifier|*
name|a_tree
decl_stmt|;
name|short
name|a_depth
decl_stmt|;
block|}
name|bc_array
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bc_var_array
block|{
name|bc_array
modifier|*
name|a_value
decl_stmt|;
name|char
name|a_param
decl_stmt|;
name|struct
name|bc_var_array
modifier|*
name|a_next
decl_stmt|;
block|}
name|bc_var_array
typedef|;
end_typedef

begin_comment
comment|/* For the stacks, execution and function, we need records to allow    for arbitrary size. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|estack_rec
block|{
name|bc_num
name|s_num
decl_stmt|;
name|struct
name|estack_rec
modifier|*
name|s_next
decl_stmt|;
block|}
name|estack_rec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|fstack_rec
block|{
name|int
name|s_val
decl_stmt|;
name|struct
name|fstack_rec
modifier|*
name|s_next
decl_stmt|;
block|}
name|fstack_rec
typedef|;
end_typedef

begin_comment
comment|/* The following are for the name tree. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|id_rec
block|{
name|char
modifier|*
name|id
decl_stmt|;
comment|/* The program name. */
comment|/* A name == 0 => nothing assigned yet. */
name|int
name|a_name
decl_stmt|;
comment|/* The array variable name (number). */
name|int
name|f_name
decl_stmt|;
comment|/* The function name (number).  */
name|int
name|v_name
decl_stmt|;
comment|/* The variable name (number).  */
name|short
name|balance
decl_stmt|;
comment|/* For the balanced tree. */
name|struct
name|id_rec
modifier|*
name|left
decl_stmt|,
modifier|*
name|right
decl_stmt|;
comment|/* Tree pointers. */
block|}
name|id_rec
typedef|;
end_typedef

begin_comment
comment|/* A list of files to process. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|file_node
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|file_node
modifier|*
name|next
decl_stmt|;
block|}
name|file_node
typedef|;
end_typedef

begin_comment
comment|/* Macro Definitions */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBEDIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|HISTORY_SIZE
parameter_list|(
name|n
parameter_list|)
value|history(hist,&histev, H_SETSIZE, n)
end_define

begin_define
define|#
directive|define
name|UNLIMIT_HISTORY
value|history(hist,&histev, H_SETSIZE, INT_MAX)
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
name|READLINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|HISTORY_SIZE
parameter_list|(
name|n
parameter_list|)
value|stifle_history(n)
end_define

begin_define
define|#
directive|define
name|UNLIMIT_HISTORY
value|unstifle_history()
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

