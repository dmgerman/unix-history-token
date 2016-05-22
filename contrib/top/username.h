begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Top users/processes display for Unix  *  Version 3  *  *  This program may be freely redistributed,  *  but this entire comment MUST remain intact.  *  *  Copyright (c) 1984, 1989, William LeFebvre, Rice University  *  Copyright (c) 1989, 1990, 1992, William LeFebvre, Northwestern University  *  Copyright (c) 2016, Randy Westlund  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USERNAME_H
end_ifndef

begin_define
define|#
directive|define
name|USERNAME_H
end_define

begin_function_decl
name|int
name|enter_user
parameter_list|(
name|int
name|uid
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|wecare
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_user
parameter_list|(
name|int
name|uid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_hash
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|username
parameter_list|(
name|int
name|uid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|userid
parameter_list|(
name|char
modifier|*
name|username
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USERNAME_H */
end_comment

end_unit

