begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify
end_comment

begin_comment
comment|// rdar://8632525
end_comment

begin_typedef
typedef|typedef
name|struct
name|objc_class
modifier|*
name|Class
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|objc_object
block|{
name|Class
name|isa
decl_stmt|;
block|}
typedef|*
name|id
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|objc_selector
modifier|*
name|SEL
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|id
name|objc_msgSend
parameter_list|(
name|id
name|self
parameter_list|,
name|SEL
name|op
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

end_unit

