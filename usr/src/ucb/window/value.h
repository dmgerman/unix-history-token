begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#)value.h	3.5 4/24/85  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California,  * All rights reserved.  Redistribution permitted subject to  * the terms of the Berkeley Software License Agreement.  */
end_comment

begin_struct
struct|struct
name|value
block|{
name|char
name|v_type
decl_stmt|;
union|union
block|{
name|int
name|V_num
decl_stmt|;
name|char
modifier|*
name|V_str
decl_stmt|;
block|}
name|v_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|v_num
value|v_un.V_num
end_define

begin_define
define|#
directive|define
name|v_str
value|v_un.V_str
end_define

begin_define
define|#
directive|define
name|V_NUM
value|1
end_define

begin_define
define|#
directive|define
name|V_STR
value|2
end_define

begin_define
define|#
directive|define
name|V_ERR
value|3
end_define

begin_define
define|#
directive|define
name|val_free
parameter_list|(
name|v
parameter_list|)
value|((v).v_type == V_STR ? str_free((v).v_str) : 0)
end_define

end_unit

