begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Functions cannot have parameters of type __fp16.
end_comment

begin_function_decl
specifier|extern
name|void
name|f
parameter_list|(
name|__fp16
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{parameters cannot have __fp16 type; did you forget * ?}}
end_comment

begin_function_decl
specifier|extern
name|void
name|g
parameter_list|(
name|__fp16
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|pf
function_decl|)
parameter_list|(
name|__fp16
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{parameters cannot have __fp16 type; did you forget * ?}}
end_comment

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|pg
function_decl|)
parameter_list|(
name|__fp16
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|tf
function_decl|)
parameter_list|(
name|__fp16
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// expected-error {{parameters cannot have __fp16 type; did you forget * ?}}
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|tg
function_decl|)
parameter_list|(
name|__fp16
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function
name|void
name|kf
parameter_list|(
name|a
parameter_list|)
name|__fp16
name|a
decl_stmt|;
block|{
comment|// expected-error {{parameters cannot have __fp16 type; did you forget * ?}}
block|}
end_function

begin_function
name|void
name|kg
parameter_list|(
name|a
parameter_list|)
name|__fp16
modifier|*
name|a
decl_stmt|;
block|{ }
end_function

begin_comment
comment|// Functions cannot return type __fp16.
end_comment

begin_function_decl
specifier|extern
name|__fp16
name|f1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{function return value cannot have __fp16 type; did you forget * ?}}
end_comment

begin_function_decl
specifier|extern
name|__fp16
modifier|*
name|g1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|__fp16
function_decl|(
modifier|*
name|pf1
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{function return value cannot have __fp16 type; did you forget * ?}}
end_comment

begin_function_decl
specifier|extern
name|__fp16
modifier|*
function_decl|(
modifier|*
name|gf1
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|__fp16
function_decl|(
modifier|*
name|tf1
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// expected-error {{function return value cannot have __fp16 type; did you forget * ?}}
end_comment

begin_typedef
typedef|typedef
name|__fp16
modifier|*
function_decl|(
modifier|*
name|tg1
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

end_unit

