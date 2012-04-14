begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<Module/Module.h>
end_include

begin_comment
comment|//expected-warning{{treating #include as an import of module 'Module'}}
end_comment

begin_define
define|#
directive|define
name|DEPENDS_ON_MODULE
value|1
end_define

begin_empty
empty|#__private_macro DEPENDS_ON_MODULE
end_empty

end_unit

