begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  init_main.c:     Static Constructor Initialization for Dynamically  *                    Linked Libraries  *  Author:           James Kempf  *  Created On:       Fri Dec 21 08:31:07 1990  *  Last Modified By: James Kempf  *  Last Modified On: Wed Apr 24 10:41:25 1991  *  Update Count:     46 */
end_comment

begin_include
include|#
directive|include
file|"dldefs.h"
end_include

begin_comment
comment|/* This global is used to communicate the ctor/dtor list address to   * dynamically linked libraries. Some static linkers may have trouble  * with initialized data in PIC code. gcc can generate initialization  * functions for any user data, but the ctor/dtor lists are generated  * by the linker. So we use this ruse to make sure the address gets  * to the initialization function. This code should *always* run single  * threaded. */
end_comment

begin_decl_stmt
name|int
modifier|*
name|__function_list_addr
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__CTOR_LIST__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__DTOR_LIST__
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|__main
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|INIT_FUN
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FINI_FUN
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_initialize_dynamic_libs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_finalize_dynamic_libs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|exit
parameter_list|(
comment|/*int*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_exit
parameter_list|(
comment|/*int*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_cleanup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*************************************************************************  * Main initialization and finalization  ************************************************************************/
end_comment

begin_comment
comment|/* __main-Initialize dynamically linked libraries, then main. */
end_comment

begin_function
name|int
name|__main
parameter_list|()
block|{
name|_initialize_dynamic_libs
argument_list|()
expr_stmt|;
name|__function_list_addr
operator|=
operator|&
name|__CTOR_LIST__
expr_stmt|;
name|INIT_FUN
argument_list|()
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
name|exit
parameter_list|(
name|int
name|status
parameter_list|)
block|{
name|__function_list_addr
operator|=
operator|&
name|__DTOR_LIST__
expr_stmt|;
name|FINI_FUN
argument_list|()
expr_stmt|;
name|_finalize_dynamic_libs
argument_list|()
expr_stmt|;
name|_cleanup
argument_list|()
expr_stmt|;
name|_exit
argument_list|(
name|status
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

