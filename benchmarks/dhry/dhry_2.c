begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *************************************************************************   *   *                   "DHRYSTONE" Benchmark Program   *                   -----------------------------   *   *  Version:    C, Version 2.1   *   *  File:       dhry_2.c (part 3 of 3)   *   *  Date:       May 25, 1988   *   *  Author:     Reinhold P. Weicker   *   *************************************************************************   */
end_comment

begin_include
include|#
directive|include
file|"dhry.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|REG
end_ifndef

begin_define
define|#
directive|define
name|REG
end_define

begin_comment
comment|/* REG becomes defined as empty */
end_comment

begin_comment
comment|/* i.e. no register variables   */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REG
value|register
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|Int_Glob
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|Ch_1_Glob
decl_stmt|;
end_decl_stmt

begin_function_decl
name|Boolean
name|Func_3
parameter_list|(
name|Enumeration
name|Enum_Par_Val
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|Proc_6
parameter_list|(
name|Enumeration
name|Enum_Val_Par
parameter_list|,
name|Enumeration
modifier|*
name|Enum_Ref_Par
parameter_list|)
comment|/*********************************/
comment|/* executed once */
comment|/* Enum_Val_Par == Ident_3, Enum_Ref_Par becomes Ident_2 */
block|{
operator|*
name|Enum_Ref_Par
operator|=
name|Enum_Val_Par
expr_stmt|;
if|if
condition|(
operator|!
name|Func_3
argument_list|(
name|Enum_Val_Par
argument_list|)
condition|)
comment|/* then, not executed */
operator|*
name|Enum_Ref_Par
operator|=
name|Ident_4
expr_stmt|;
switch|switch
condition|(
name|Enum_Val_Par
condition|)
block|{
case|case
name|Ident_1
case|:
operator|*
name|Enum_Ref_Par
operator|=
name|Ident_1
expr_stmt|;
break|break;
case|case
name|Ident_2
case|:
if|if
condition|(
name|Int_Glob
operator|>
literal|100
condition|)
comment|/* then */
operator|*
name|Enum_Ref_Par
operator|=
name|Ident_1
expr_stmt|;
else|else
operator|*
name|Enum_Ref_Par
operator|=
name|Ident_4
expr_stmt|;
break|break;
case|case
name|Ident_3
case|:
comment|/* executed */
operator|*
name|Enum_Ref_Par
operator|=
name|Ident_2
expr_stmt|;
break|break;
case|case
name|Ident_4
case|:
break|break;
case|case
name|Ident_5
case|:
operator|*
name|Enum_Ref_Par
operator|=
name|Ident_3
expr_stmt|;
break|break;
block|}
comment|/* switch */
block|}
end_function

begin_comment
comment|/* Proc_6 */
end_comment

begin_function
name|void
name|Proc_7
parameter_list|(
name|One_Fifty
name|Int_1_Par_Val
parameter_list|,
name|One_Fifty
name|Int_2_Par_Val
parameter_list|,
name|One_Fifty
modifier|*
name|Int_Par_Ref
parameter_list|)
comment|/**********************************************/
comment|/* executed three times                                      */
comment|/* first call:      Int_1_Par_Val == 2, Int_2_Par_Val == 3,  */
comment|/*                  Int_Par_Ref becomes 7                    */
comment|/* second call:     Int_1_Par_Val == 10, Int_2_Par_Val == 5, */
comment|/*                  Int_Par_Ref becomes 17                   */
comment|/* third call:      Int_1_Par_Val == 6, Int_2_Par_Val == 10, */
comment|/*                  Int_Par_Ref becomes 18                   */
block|{
name|One_Fifty
name|Int_Loc
decl_stmt|;
name|Int_Loc
operator|=
name|Int_1_Par_Val
operator|+
literal|2
expr_stmt|;
operator|*
name|Int_Par_Ref
operator|=
name|Int_2_Par_Val
operator|+
name|Int_Loc
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Proc_7 */
end_comment

begin_function
name|void
name|Proc_8
parameter_list|(
name|Arr_1_Dim
name|Arr_1_Par_Ref
parameter_list|,
name|Arr_2_Dim
name|Arr_2_Par_Ref
parameter_list|,
name|int
name|Int_1_Par_Val
parameter_list|,
name|int
name|Int_2_Par_Val
parameter_list|)
comment|/*********************************************************************/
comment|/* executed once      */
comment|/* Int_Par_Val_1 == 3 */
comment|/* Int_Par_Val_2 == 7 */
block|{
name|REG
name|One_Fifty
name|Int_Index
decl_stmt|;
name|REG
name|One_Fifty
name|Int_Loc
decl_stmt|;
name|Int_Loc
operator|=
name|Int_1_Par_Val
operator|+
literal|5
expr_stmt|;
name|Arr_1_Par_Ref
index|[
name|Int_Loc
index|]
operator|=
name|Int_2_Par_Val
expr_stmt|;
name|Arr_1_Par_Ref
index|[
name|Int_Loc
operator|+
literal|1
index|]
operator|=
name|Arr_1_Par_Ref
index|[
name|Int_Loc
index|]
expr_stmt|;
name|Arr_1_Par_Ref
index|[
name|Int_Loc
operator|+
literal|30
index|]
operator|=
name|Int_Loc
expr_stmt|;
for|for
control|(
name|Int_Index
operator|=
name|Int_Loc
init|;
name|Int_Index
operator|<=
name|Int_Loc
operator|+
literal|1
condition|;
operator|++
name|Int_Index
control|)
name|Arr_2_Par_Ref
index|[
name|Int_Loc
index|]
index|[
name|Int_Index
index|]
operator|=
name|Int_Loc
expr_stmt|;
name|Arr_2_Par_Ref
index|[
name|Int_Loc
index|]
index|[
name|Int_Loc
operator|-
literal|1
index|]
operator|+=
literal|1
expr_stmt|;
name|Arr_2_Par_Ref
index|[
name|Int_Loc
operator|+
literal|20
index|]
index|[
name|Int_Loc
index|]
operator|=
name|Arr_1_Par_Ref
index|[
name|Int_Loc
index|]
expr_stmt|;
name|Int_Glob
operator|=
literal|5
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Proc_8 */
end_comment

begin_function
name|Enumeration
name|Func_1
parameter_list|(
name|Capital_Letter
name|Ch_1_Par_Val
parameter_list|,
name|Capital_Letter
name|Ch_2_Par_Val
parameter_list|)
comment|/*************************************************/
comment|/* executed three times                                         */
comment|/* first call:      Ch_1_Par_Val == 'H', Ch_2_Par_Val == 'R'    */
comment|/* second call:     Ch_1_Par_Val == 'A', Ch_2_Par_Val == 'C'    */
comment|/* third call:      Ch_1_Par_Val == 'B', Ch_2_Par_Val == 'C'    */
block|{
name|Capital_Letter
name|Ch_1_Loc
decl_stmt|;
name|Capital_Letter
name|Ch_2_Loc
decl_stmt|;
name|Ch_1_Loc
operator|=
name|Ch_1_Par_Val
expr_stmt|;
name|Ch_2_Loc
operator|=
name|Ch_1_Loc
expr_stmt|;
if|if
condition|(
name|Ch_2_Loc
operator|!=
name|Ch_2_Par_Val
condition|)
comment|/* then, executed */
return|return
operator|(
name|Ident_1
operator|)
return|;
else|else
comment|/* not executed */
block|{
name|Ch_1_Glob
operator|=
name|Ch_1_Loc
expr_stmt|;
return|return
operator|(
name|Ident_2
operator|)
return|;
block|}
block|}
end_function

begin_comment
comment|/* Func_1 */
end_comment

begin_function
name|Boolean
name|Func_2
parameter_list|(
name|Str_30
name|Str_1_Par_Ref
parameter_list|,
name|Str_30
name|Str_2_Par_Ref
parameter_list|)
comment|/*************************************************/
comment|/* executed once */
comment|/* Str_1_Par_Ref == "DHRYSTONE PROGRAM, 1'ST STRING" */
comment|/* Str_2_Par_Ref == "DHRYSTONE PROGRAM, 2'ND STRING" */
block|{
name|REG
name|One_Thirty
name|Int_Loc
decl_stmt|;
name|Capital_Letter
name|Ch_Loc
decl_stmt|;
name|Int_Loc
operator|=
literal|2
expr_stmt|;
while|while
condition|(
name|Int_Loc
operator|<=
literal|2
condition|)
comment|/* loop body executed once */
if|if
condition|(
name|Func_1
argument_list|(
name|Str_1_Par_Ref
index|[
name|Int_Loc
index|]
argument_list|,
name|Str_2_Par_Ref
index|[
name|Int_Loc
operator|+
literal|1
index|]
argument_list|)
operator|==
name|Ident_1
condition|)
comment|/* then, executed */
block|{
name|Ch_Loc
operator|=
literal|'A'
expr_stmt|;
name|Int_Loc
operator|+=
literal|1
expr_stmt|;
block|}
comment|/* if, while */
if|if
condition|(
name|Ch_Loc
operator|>=
literal|'W'
operator|&&
name|Ch_Loc
operator|<
literal|'Z'
condition|)
comment|/* then, not executed */
name|Int_Loc
operator|=
literal|7
expr_stmt|;
if|if
condition|(
name|Ch_Loc
operator|==
literal|'R'
condition|)
comment|/* then, not executed */
return|return
operator|(
name|true
operator|)
return|;
else|else
comment|/* executed */
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|Str_1_Par_Ref
argument_list|,
name|Str_2_Par_Ref
argument_list|)
operator|>
literal|0
condition|)
comment|/* then, not executed */
block|{
name|Int_Loc
operator|+=
literal|7
expr_stmt|;
name|Int_Glob
operator|=
name|Int_Loc
expr_stmt|;
return|return
operator|(
name|true
operator|)
return|;
block|}
else|else
comment|/* executed */
return|return
operator|(
name|false
operator|)
return|;
block|}
comment|/* if Ch_Loc */
block|}
end_function

begin_comment
comment|/* Func_2 */
end_comment

begin_function
name|Boolean
name|Func_3
parameter_list|(
name|Enumeration
name|Enum_Par_Val
parameter_list|)
comment|/***************************/
comment|/* executed once        */
comment|/* Enum_Par_Val == Ident_3 */
block|{
name|Enumeration
name|Enum_Loc
decl_stmt|;
name|Enum_Loc
operator|=
name|Enum_Par_Val
expr_stmt|;
if|if
condition|(
name|Enum_Loc
operator|==
name|Ident_3
condition|)
comment|/* then, executed */
return|return
operator|(
name|true
operator|)
return|;
else|else
comment|/* not executed */
return|return
operator|(
name|false
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Func_3 */
end_comment

end_unit

