begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b1val.h,v 1.4 85/08/22 16:42:19 timo Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INTEGRATION
end_ifndef

begin_comment
comment|/* Private definitions for grabbing and ref count scheme */
end_comment

begin_function_decl
name|value
name|grab_tlt
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* literal type, it; */
end_comment

begin_function_decl
name|btreeptr
name|grabbtreenode
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* literal flag, it */
end_comment

begin_function_decl
name|btreeptr
name|copybtree
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr pnode */
end_comment

begin_comment
comment|/* Procedure uniqlbtreenode(); */
end_comment

begin_comment
comment|/* btreeptr *pptr; literal it */
end_comment

begin_function_decl
name|btreeptr
name|ccopybtreenode
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr pnode; literal it */
end_comment

begin_function_decl
name|btreeptr
name|mknewroot
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* btreeptr ptr0, itemptr pitm0, btreeptr ptr1, literal it */
end_comment

begin_comment
comment|/* Procedure relbtree(); */
end_comment

begin_comment
comment|/* btreeptr pnode; literal it */
end_comment

begin_comment
comment|/* Procedure freebtreenode(); */
end_comment

begin_comment
comment|/* btreeptr pnode; */
end_comment

begin_endif
endif|#
directive|endif
endif|!INTEGRATION
end_endif

end_unit

