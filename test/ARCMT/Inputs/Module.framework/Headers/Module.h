begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// expected-warning 0-1 {{umbrella header}}
end_comment

begin_comment
comment|// FIXME: The "umbrella header" warning should be moved to a separate test.
end_comment

begin_comment
comment|// This "0-1" is only here because the warning is only emitted when the
end_comment

begin_comment
comment|// module is (otherwise) successfully included.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MODULE_H
end_ifndef

begin_define
define|#
directive|define
name|MODULE_H
end_define

begin_function_decl
specifier|const
name|char
modifier|*
name|getModuleVersion
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FOO
end_ifdef

begin_error
error|#
directive|error
error|Module should have been built without -DFOO
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|@
name|interface
name|Module
operator|+
operator|(
specifier|const
name|char
operator|*
operator|)
name|version
expr_stmt|;
end_expr_stmt

begin_comment
comment|// retrieve module version
end_comment

begin_expr_stmt
operator|+
name|alloc
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

begin_define
define|#
directive|define
name|MODULE_H_MACRO
value|1
end_define

begin_empty
empty|#__private_macro MODULE_H_MACRO
end_empty

begin_include
include|#
directive|include
file|<Module/Sub.h>
end_include

begin_include
include|#
directive|include
file|<Module/Buried/Treasure.h>
end_include

begin_asm
asm|__asm("foo");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// MODULE_H
end_comment

end_unit

