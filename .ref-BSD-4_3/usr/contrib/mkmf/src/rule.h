begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: rule.h,v 1.1 85/05/02 08:01:11 nicklin Exp $ */
end_comment

begin_comment
comment|/*  * Rule definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Rule table block struct  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ruleblk
block|{
name|char
modifier|*
name|r_rule
decl_stmt|;
comment|/* pointer to rule string */
name|struct
name|_ruleblk
modifier|*
name|r_next
decl_stmt|;
comment|/* ptr to next rule list block */
block|}
name|RULEBLK
typedef|;
end_typedef

end_unit

