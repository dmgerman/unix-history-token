begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Language-dependent hooks for Objective-C.    Copyright 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.    Contributed by Ziemowit Laski<zlaski@apple.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"c-tree.h"
end_include

begin_include
include|#
directive|include
file|"c-common.h"
end_include

begin_include
include|#
directive|include
file|"ggc.h"
end_include

begin_include
include|#
directive|include
file|"objc-act.h"
end_include

begin_include
include|#
directive|include
file|"langhooks.h"
end_include

begin_include
include|#
directive|include
file|"langhooks-def.h"
end_include

begin_include
include|#
directive|include
file|"diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"c-objc-common.h"
end_include

begin_decl_stmt
name|enum
name|c_language_kind
name|c_language
init|=
name|clk_objc
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|objc_init_ts
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Lang hooks common to C and ObjC are declared in c-objc-common.h;    consequently, there should be very few hooks below.  */
end_comment

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_NAME
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_NAME
value|"GNU Objective-C"
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_INIT
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_INIT
value|objc_init
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_DECL_PRINTABLE_NAME
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_DECL_PRINTABLE_NAME
value|objc_printable_name
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_GIMPLIFY_EXPR
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_GIMPLIFY_EXPR
value|objc_gimplify_expr
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_GET_CALLEE_FNDECL
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_GET_CALLEE_FNDECL
value|objc_get_callee_fndecl
end_define

begin_undef
undef|#
directive|undef
name|LANG_HOOKS_INIT_TS
end_undef

begin_define
define|#
directive|define
name|LANG_HOOKS_INIT_TS
value|objc_init_ts
end_define

begin_comment
comment|/* Each front end provides its own lang hook initializer.  */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|lang_hooks
name|lang_hooks
init|=
name|LANG_HOOKS_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Table indexed by tree code giving a string containing a character    classifying the tree code.  */
end_comment

begin_define
define|#
directive|define
name|DEFTREECODE
parameter_list|(
name|SYM
parameter_list|,
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|LENGTH
parameter_list|)
value|TYPE,
end_define

begin_decl_stmt
specifier|const
name|enum
name|tree_code_class
name|tree_code_type
index|[]
init|=
block|{
include|#
directive|include
file|"tree.def"
name|tcc_exceptional
block|,
include|#
directive|include
file|"c-common.def"
name|tcc_exceptional
block|,
include|#
directive|include
file|"objc-tree.def"
block|}
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|DEFTREECODE
end_undef

begin_comment
comment|/* Table indexed by tree code giving number of expression    operands beyond the fixed part of the node structure.    Not used for types or decls.  */
end_comment

begin_define
define|#
directive|define
name|DEFTREECODE
parameter_list|(
name|SYM
parameter_list|,
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|LENGTH
parameter_list|)
value|LENGTH,
end_define

begin_decl_stmt
specifier|const
name|unsigned
name|char
name|tree_code_length
index|[]
init|=
block|{
include|#
directive|include
file|"tree.def"
literal|0
block|,
include|#
directive|include
file|"c-common.def"
literal|0
block|,
include|#
directive|include
file|"objc-tree.def"
block|}
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|DEFTREECODE
end_undef

begin_comment
comment|/* Names of tree components.    Used for printing out the tree and error messages.  */
end_comment

begin_define
define|#
directive|define
name|DEFTREECODE
parameter_list|(
name|SYM
parameter_list|,
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|LEN
parameter_list|)
value|NAME,
end_define

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|tree_code_name
index|[]
init|=
block|{
include|#
directive|include
file|"tree.def"
literal|"@@dummy"
block|,
include|#
directive|include
file|"c-common.def"
literal|"@@dummy"
block|,
include|#
directive|include
file|"objc-tree.def"
block|}
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|DEFTREECODE
end_undef

begin_comment
comment|/* Lang hook routines common to C and ObjC appear in c-objc-common.c;    there should be very few (if any) routines below.  */
end_comment

begin_function
specifier|static
name|void
name|objc_init_ts
parameter_list|(
name|void
parameter_list|)
block|{
name|tree_contains_struct
index|[
name|CLASS_METHOD_DECL
index|]
index|[
name|TS_DECL_NON_COMMON
index|]
operator|=
literal|1
expr_stmt|;
name|tree_contains_struct
index|[
name|INSTANCE_METHOD_DECL
index|]
index|[
name|TS_DECL_NON_COMMON
index|]
operator|=
literal|1
expr_stmt|;
name|tree_contains_struct
index|[
name|KEYWORD_DECL
index|]
index|[
name|TS_DECL_NON_COMMON
index|]
operator|=
literal|1
expr_stmt|;
name|tree_contains_struct
index|[
name|CLASS_METHOD_DECL
index|]
index|[
name|TS_DECL_WITH_VIS
index|]
operator|=
literal|1
expr_stmt|;
name|tree_contains_struct
index|[
name|INSTANCE_METHOD_DECL
index|]
index|[
name|TS_DECL_WITH_VIS
index|]
operator|=
literal|1
expr_stmt|;
name|tree_contains_struct
index|[
name|KEYWORD_DECL
index|]
index|[
name|TS_DECL_WITH_VIS
index|]
operator|=
literal|1
expr_stmt|;
name|tree_contains_struct
index|[
name|CLASS_METHOD_DECL
index|]
index|[
name|TS_DECL_WRTL
index|]
operator|=
literal|1
expr_stmt|;
name|tree_contains_struct
index|[
name|INSTANCE_METHOD_DECL
index|]
index|[
name|TS_DECL_WRTL
index|]
operator|=
literal|1
expr_stmt|;
name|tree_contains_struct
index|[
name|KEYWORD_DECL
index|]
index|[
name|TS_DECL_WRTL
index|]
operator|=
literal|1
expr_stmt|;
name|tree_contains_struct
index|[
name|CLASS_METHOD_DECL
index|]
index|[
name|TS_DECL_MINIMAL
index|]
operator|=
literal|1
expr_stmt|;
name|tree_contains_struct
index|[
name|INSTANCE_METHOD_DECL
index|]
index|[
name|TS_DECL_MINIMAL
index|]
operator|=
literal|1
expr_stmt|;
name|tree_contains_struct
index|[
name|KEYWORD_DECL
index|]
index|[
name|TS_DECL_MINIMAL
index|]
operator|=
literal|1
expr_stmt|;
name|tree_contains_struct
index|[
name|CLASS_METHOD_DECL
index|]
index|[
name|TS_DECL_COMMON
index|]
operator|=
literal|1
expr_stmt|;
name|tree_contains_struct
index|[
name|INSTANCE_METHOD_DECL
index|]
index|[
name|TS_DECL_COMMON
index|]
operator|=
literal|1
expr_stmt|;
name|tree_contains_struct
index|[
name|KEYWORD_DECL
index|]
index|[
name|TS_DECL_COMMON
index|]
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function
name|void
name|finish_file
parameter_list|(
name|void
parameter_list|)
block|{
name|objc_finish_file
argument_list|()
expr_stmt|;
block|}
end_function

begin_include
include|#
directive|include
file|"gtype-objc.h"
end_include

end_unit

