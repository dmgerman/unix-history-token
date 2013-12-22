begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -emit-llvm-only %s -o %t
end_comment

begin_comment
comment|/* Testcase for PR15826 - clang hits assert in clang::ASTContext::getASTRecordLayout */
end_comment

begin_struct
struct|struct
name|sysctl_req
block|{
name|struct
name|aiocblist
modifier|*
name|p_aio
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sysctl_oid
block|{
name|int
function_decl|(
modifier|*
name|oid_handler
function_decl|)
parameter_list|(
name|struct
name|sysctl_req
modifier|*
name|req
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|sysctl_oid
name|sysctl___kern_features_aio
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
specifier|const
modifier|*
specifier|const
name|__set_sysctl_set_sym_sysctl___kern_features_aio
name|__attribute__
argument_list|(
operator|(
name|__used__
operator|)
argument_list|)
init|=
operator|&
name|sysctl___kern_features_aio
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|aiocblist
block|{
name|struct
name|aiocb
name|uaiocb
decl_stmt|;
comment|// expected-error {{field has incomplete type}} expected-note {{forward declaration}}
block|}
struct|;
end_struct

end_unit

